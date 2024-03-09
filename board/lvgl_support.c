/*
 * Copyright 2019-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
// lvgl
#include "lvgl_support.h"
#include "lvgl.h"
// freertos
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif
// driver & config
#include "board.h"
#include "fsl_gpio.h"
#include "fsl_lpspi.h"
#include "fsl_lpspi_edma.h"
#include "fsl_edma.h"
#include "fsl_dmamux.h"
// bsp
#include "st7735s.h"        // 屏幕
#include "xpt2046ts.h"          // 触摸
#include "ec11.h"               // 旋转编码器
// debug
#include "fsl_debug_console.h"
#include "stdio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_LPSPI_MASTER_BASEADDR   (LPSPI4)
#define EXAMPLE_LPSPI_MASTER_IRQN       LPSPI4_IRQn
#define EXAMPLE_LPSPI_MASTER_IRQHandler LPSPI4_IRQHandler

#define EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE          (DMAMUX)
#define EXAMPLE_LPSPI_MASTER_DMA_RX_REQUEST_SOURCE kDmaRequestMuxLPSPI4Rx
#define EXAMPLE_LPSPI_MASTER_DMA_TX_REQUEST_SOURCE kDmaRequestMuxLPSPI4Tx
#define EXAMPLE_LPSPI_MASTER_DMA_BASE              (DMA0)
#define EXAMPLE_LPSPI_MASTER_DMA_RX_CHANNEL        0U
#define EXAMPLE_LPSPI_MASTER_DMA_TX_CHANNEL        1U
#define BOARD_SCREEN_MASTER_DMA_RX_IRQ             DMA0_DMA16_IRQn
#define BOARD_SCREEN_MASTER_DMA_TX_IRQ             DMA1_DMA17_IRQn

#define EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT     (kLPSPI_Pcs0)
#define EXAMPLE_LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

#define LPSPI_MASTER_CLK_FREQ (CLOCK_GetFreq(kCLOCK_SysPllClk) / (LPSPI_CLOCK_SOURCE_DIVIDER + 1U))
#define LCD_TRANSFER_BAUDRATE     50000000U  // 50M bsp
#define TOUCH_TRANSFER_BAUDRATE   1000000U   // 1M bps
/* Port Me, End. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_InitLcd(void);
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
static void DEMO_ReadEncoder(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static void DEMO_ReadTouch(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static void BOARD_SCREEN_SPI_eDMA_Init(void);
static void LPSPI4_MasterUserCallback(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, status_t status, void *userData);
static void LPSPI4_WaitEvent(void);
static void DEMO_SPI_LCD_WriteCmd(uint8_t Data);
static void DEMO_SPI_LCD_WriteData(uint8_t Data);
static void DEMO_SPI_LCD_WriteMultiData(const uint8_t *pData, int NumItems);
/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(SDK_OS_FREE_RTOS)
static SemaphoreHandle_t s_transferDone;
#else
static volatile bool s_transferDone;
#endif
AT_NONCACHEABLE_SECTION_ALIGN(static uint8_t s_frameBuffer[1][LCD_VIRTUAL_BUF_SIZE * LCD_FB_BYTE_PER_PIXEL], 4);
AT_NONCACHEABLE_SECTION_INIT(lpspi_master_edma_handle_t g_m_edma_handle) = {0};
edma_handle_t lpspiEdmaMasterRxRegToRxDataHandle;
edma_handle_t lpspiEdmaMasterTxDataToTxRegHandle;
lpspi_master_config_t masterConfig;
extern uint8_t spi_txbuf[64];
extern uint8_t spi_rxbuf[64];

lv_indev_t *indev_touchpad;
lv_indev_t *indev_encoder;
lv_group_t *group;
/* For Debug */
extern uint8_t str_buf[50];
/*******************************************************************************
 * Code
 ******************************************************************************/
void lv_port_pre_init(void)
{
}


static void DEMO_InitLcd(void)
{
    /* Define the init structure for the data/command output pin */
    gpio_pin_config_t dc_config = {    
        kGPIO_DigitalOutput,
        1,
        kGPIO_NoIntmode,
    };

    gpio_pin_config_t reset_config = {  // RESET引脚
        kGPIO_DigitalOutput,
        1,
        kGPIO_NoIntmode,
    };
    // gpio_pin_config_t led_config = {    // LED 引脚
    //     kGPIO_DigitalOutput,
    //     1,
    //     kGPIO_NoIntmode,        
    // };

    /* Init data/command GPIO output . */
    GPIO_PinInit(BOARD_LCD_DC_GPIO, BOARD_LCD_DC_GPIO_PIN, &dc_config);
    /* Init reset GPIO output . */
    GPIO_PinInit(BOARD_LCD_RESET_GPIO, BOARD_LCD_RESET_GPIO_PIN, &reset_config);
    // /* LCD LED GPIO */
    // GPIO_PinInit(BOARD_LCD_LED_GPIO, BOARD_LCD_LED_GPIO_PIN, &led_config);
    
#if defined(SDK_OS_FREE_RTOS)
    s_transferDone = xSemaphoreCreateBinary();
    if (NULL == s_transferDone)
    {
        PRINTF("Semaphore create failed\r\n");
        assert(0);
    }
#else
    s_transferDone = false;
#endif

#if defined(SDK_OS_FREE_RTOS)
    /* FreeRTOS kernel API is used in SPI ISR, so need to set proper IRQ priority. */
    NVIC_SetPriority(EXAMPLE_LPSPI_MASTER_IRQN, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
    NVIC_SetPriority(BOARD_SCREEN_MASTER_DMA_TX_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
    NVIC_SetPriority(BOARD_SCREEN_MASTER_DMA_RX_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
#endif
    /* LPSPI eDMA Driver Init  */
    BOARD_SCREEN_SPI_eDMA_Init();
    
    /* LCD Reset */
    GPIO_PortClear(BOARD_LCD_RESET_GPIO, 1u << BOARD_LCD_RESET_GPIO_PIN);
    SDK_DelayAtLeastUs(100 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    GPIO_PortSet(BOARD_LCD_RESET_GPIO, 1u << BOARD_LCD_RESET_GPIO_PIN);
    SDK_DelayAtLeastUs(100 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    
    /* LCD Init */
    ST7735_Init(DEMO_SPI_LCD_WriteData, DEMO_SPI_LCD_WriteCmd);

    GPIO_PortSet(BOARD_LCD_LED_GPIO, 1u << BOARD_LCD_LED_GPIO_PIN);
    BackLight_Init();
}



void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], NULL, LCD_VIRTUAL_BUF_SIZE);

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    DEMO_InitLcd();

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);


}

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    lv_coord_t x1 = area->x1+2;
    lv_coord_t y1 = area->y1+1;
    lv_coord_t x2 = area->x2+2;
    lv_coord_t y2 = area->y2+1;

    uint8_t data[4];
    const uint8_t *pdata = (const uint8_t *)color_p;
    uint32_t send_size   = (x2 - x1 + 1) * (y2 - y1 + 1) * LCD_FB_BYTE_PER_PIXEL;

    /*Column addresses*/
    DEMO_SPI_LCD_WriteCmd(ST7735_CASET);
    data[0] = (x1 >> 8) & 0xFF;
    data[1] = x1 & 0xFF;
    data[2] = (x2 >> 8) & 0xFF;
    data[3] = x2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Page addresses*/
    DEMO_SPI_LCD_WriteCmd(ST7735_RASET);
    data[0] = (y1 >> 8) & 0xFF;
    data[1] = y1 & 0xFF;
    data[2] = (y2 >> 8) & 0xFF;
    data[3] = y2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Memory write*/
    // DEMO_SPI_LCD_WriteCmd(ILI9341_CMD_GRAM);
    DEMO_SPI_LCD_WriteCmd(ST7735_RAMWR);
    DEMO_SPI_LCD_WriteMultiData(pdata, send_size);

    lv_disp_flush_ready(disp_drv);
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_touchpad_drv;
    static lv_indev_drv_t indev_encoder_drv;
    /*Initialize touchpad */
    XPT2046_Init();
    /*Initialize encoder */
    EC11_Init();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_touchpad_drv);
    indev_touchpad_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_touchpad_drv.read_cb = DEMO_ReadTouch;
    indev_touchpad = lv_indev_drv_register(&indev_touchpad_drv);

    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_encoder_drv);
    indev_encoder_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_encoder_drv.read_cb = DEMO_ReadEncoder;
    indev_encoder = lv_indev_drv_register(&indev_encoder_drv);

    group = lv_group_create();
    lv_indev_set_group(indev_touchpad, group);
    lv_indev_set_group(indev_encoder, group);

}


/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    uint16_t x = 0;
    uint16_t y = 0;
    uint8_t irq = XPT2046_irq_read();

    if (irq == 0) {
        XPT2046_GetTouch_XY(&x, &y, 1);
        xpt2046_corr(&x, &y);

        if(x<0) x = 0;
        if(y<0) y = 0;
        if(y>LCD_HEIGHT) y = LCD_HEIGHT;
        if(x>LCD_WIDTH) x = LCD_WIDTH;

        data->point.x = x;
        data->point.y = LCD_HEIGHT - y;
        data->state = LV_INDEV_STATE_PR;
    }
    else
        data->state = LV_INDEV_STATE_REL;
}

static void DEMO_ReadEncoder(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
	// lv_indev_state_t encoder_act;
    int16_t encoder_diff = 0;
    int16_t differential_value = EC11_read_differential_value();
    data->state = EC11_key_get_value() ? LV_INDEV_STATE_REL : LV_INDEV_STATE_PR;
    /* 消抖 */
    if(differential_value > 0)
    {
        encoder_diff = differential_value/4 + 1;
    }
    else if(differential_value < 0)
    {
        encoder_diff = differential_value/4 -1;
    }
    data->enc_diff = encoder_diff;
}


static void BOARD_SCREEN_SPI_eDMA_Init()
{
    uint32_t srcClock_Hz;
    /* DMA MUX init*/
    DMAMUX_Init(EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE);

    DMAMUX_SetSource(EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE, EXAMPLE_LPSPI_MASTER_DMA_RX_CHANNEL,
                     EXAMPLE_LPSPI_MASTER_DMA_RX_REQUEST_SOURCE);
    DMAMUX_EnableChannel(EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE, EXAMPLE_LPSPI_MASTER_DMA_RX_CHANNEL);

    DMAMUX_SetSource(EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE, EXAMPLE_LPSPI_MASTER_DMA_TX_CHANNEL,
                     EXAMPLE_LPSPI_MASTER_DMA_TX_REQUEST_SOURCE);
    DMAMUX_EnableChannel(EXAMPLE_LPSPI_MASTER_DMA_MUX_BASE, EXAMPLE_LPSPI_MASTER_DMA_TX_CHANNEL);

    /*Master config*/
    LPSPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate = LCD_TRANSFER_BAUDRATE;
    masterConfig.whichPcs = EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT;
    masterConfig.pcsToSckDelayInNanoSec        = 1000000000U / (masterConfig.baudRate * 2U);
    masterConfig.lastSckToPcsDelayInNanoSec    = 1000000000U / (masterConfig.baudRate * 2U);
    masterConfig.betweenTransferDelayInNanoSec = 1000000000U / (masterConfig.baudRate * 2U);
    
    srcClock_Hz = LPSPI_MASTER_CLK_FREQ;
    LPSPI_MasterInit(EXAMPLE_LPSPI_MASTER_BASEADDR, &masterConfig, srcClock_Hz);

    /*Set up lpspi master*/
    memset(&(lpspiEdmaMasterRxRegToRxDataHandle), 0, sizeof(lpspiEdmaMasterRxRegToRxDataHandle));
    memset(&(lpspiEdmaMasterTxDataToTxRegHandle), 0, sizeof(lpspiEdmaMasterTxDataToTxRegHandle));

    EDMA_CreateHandle(&(lpspiEdmaMasterRxRegToRxDataHandle), EXAMPLE_LPSPI_MASTER_DMA_BASE,
                      EXAMPLE_LPSPI_MASTER_DMA_RX_CHANNEL);
    EDMA_CreateHandle(&(lpspiEdmaMasterTxDataToTxRegHandle), EXAMPLE_LPSPI_MASTER_DMA_BASE,
                      EXAMPLE_LPSPI_MASTER_DMA_TX_CHANNEL);
    LPSPI_MasterTransferCreateHandleEDMA(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle, LPSPI4_MasterUserCallback,
                                         NULL, &lpspiEdmaMasterRxRegToRxDataHandle,
                                         &lpspiEdmaMasterTxDataToTxRegHandle);

    LPSPI_MasterTransferPrepareEDMALite(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle,EXAMPLE_LPSPI_MASTER_PCS_FOR_TRANSFER | kLPSPI_MasterByteSwap | kLPSPI_MasterPcsContinuous);

}

static void LPSPI4_MasterUserCallback(LPSPI_Type *base, lpspi_master_edma_handle_t *handle, status_t status, void *userData)
{
#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);

    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif
}

static void LPSPI4_WaitEvent(void)
{
#if defined(SDK_OS_FREE_RTOS)
    if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
    {
        PRINTF("LCD SPI transfer error\r\n");
    }
#else
    while (false == s_transferDone)
    {
    }
    s_transferDone = false;
#endif
}

static void DEMO_SPI_LCD_WriteCmd(uint8_t Data)
{
    GPIO_PortClear(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);
    lpspi_transfer_t masterXfer;
    masterXfer.txData   = &Data;
    masterXfer.rxData   = NULL;
    masterXfer.dataSize = 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs0 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferEDMA(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle,&masterXfer);
    LPSPI4_WaitEvent();
}

static void DEMO_SPI_LCD_WriteData(uint8_t Data)
{
    GPIO_PortSet(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);
    lpspi_transfer_t masterXfer;
    masterXfer.txData   = &Data;
    masterXfer.rxData   = NULL;
    masterXfer.dataSize = 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs0 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferEDMA(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle,&masterXfer);
    LPSPI4_WaitEvent();
}

static void DEMO_SPI_LCD_WriteMultiData(const uint8_t *pData, int NumItems)
{
    GPIO_PortSet(BOARD_LCD_DC_GPIO, 1u << BOARD_LCD_DC_GPIO_PIN);
    lpspi_transfer_t masterXfer;
    masterXfer.txData   = (uint8_t *)pData;
    masterXfer.rxData   = NULL;
    masterXfer.dataSize = NumItems;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs0 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferEDMA(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle,&masterXfer);
    LPSPI4_WaitEvent();
}

static void LPSPI_SetBaudRate(uint32_t baudRate_Bps)
{
    LPSPI_Deinit(EXAMPLE_LPSPI_MASTER_BASEADDR);
    masterConfig.baudRate = baudRate_Bps;
    masterConfig.pcsToSckDelayInNanoSec        = 1000000000U / (masterConfig.baudRate * 2U);
    masterConfig.lastSckToPcsDelayInNanoSec    = 1000000000U / (masterConfig.baudRate * 2U);
    masterConfig.betweenTransferDelayInNanoSec = 1000000000U / (masterConfig.baudRate * 2U);
    LPSPI_MasterInit(EXAMPLE_LPSPI_MASTER_BASEADDR, &masterConfig, LPSPI_MASTER_CLK_FREQ);
}

void Touch_TransferData(uint8_t txData,uint8_t* rxData,uint32_t len)
{
    LPSPI_SetBaudRate(TOUCH_TRANSFER_BAUDRATE);
    lpspi_transfer_t masterXfer;
    memset(spi_rxbuf, 0, 64);
    memset(spi_txbuf, 0, 64);
    /*Start master transfer*/
    spi_txbuf[0] = txData;
    masterXfer.txData = spi_txbuf;
    masterXfer.rxData = spi_rxbuf;
    masterXfer.dataSize = len + 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs2 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferEDMA(EXAMPLE_LPSPI_MASTER_BASEADDR, &g_m_edma_handle,&masterXfer);
    LPSPI4_WaitEvent();  
    memcpy(rxData, &(spi_rxbuf[1]), len);
    LPSPI_SetBaudRate(LCD_TRANSFER_BAUDRATE);
}