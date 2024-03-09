#include "xpt2046ts.h"
// driver
#include "fsl_lpspi.h"
#include "fsl_lpspi_edma.h"
#include "fsl_gpio.h"
#include "fsl_common.h"

#define XPT2046_HOR_RES     128
#define XPT2046_VER_RES     160
#define XPT2046_X_MIN       400
#define XPT2046_Y_MIN       255
#define XPT2046_X_MAX       3750
#define XPT2046_Y_MAX       3900
#define XPT2046_AVG         4
#define XPT2046_INV         0

#define BOARD_TOUCH_GPIO         GPIO2
#define BOARD_TOUCH_GPIO_PIN     30U

int16_t avg_buf_x[XPT2046_AVG];
int16_t avg_buf_y[XPT2046_AVG];
uint8_t avg_last;

#define Y 0x90
#define X 0xD0

// extern void Touch_TransferData(uint8_t txData,uint8_t* rxData);
extern void Touch_TransferData(uint8_t txData,uint8_t* rxData,uint32_t len);


/* SPI 初始化 中断引脚初始化 */
void XPT2046_Init(void)
{
    /* 开启笔中断 */
    gpio_pin_config_t penirq_config = {
        kGPIO_DigitalInput,
        0,
        kGPIO_IntFallingEdge,
    };
    GPIO_PinInit(BOARD_TOUCH_GPIO, BOARD_TOUCH_GPIO_PIN, &penirq_config);
    /* Delay 1ms */
    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

uint32_t XPT2046_irq_read(void)
{
    return  GPIO_PinRead(BOARD_TOUCH_GPIO,BOARD_TOUCH_GPIO_PIN);
}

uint16_t XPT2046_GetTouch(uint8_t address)
{
    uint8_t receive_data[2],dummy=0x00;
    uint16_t data;
    Touch_TransferData(address,receive_data,2);
    data = ((receive_data[0] << 8) | (receive_data[1])) >> 3;
    return data;
}

void XPT2046_GetTouch_XY(volatile uint16_t* x_kor, volatile uint16_t* y_kor, uint8_t count_read)
{
    uint8_t i = 0;
    uint16_t tmpx, tmpy, touch_x, touch_y = 0;

    touch_x = XPT2046_GetTouch(X);
    //delay_us(100);
    touch_y = XPT2046_GetTouch(Y);
    for (i = 0; i < count_read; i++) {
        tmpx = XPT2046_GetTouch(X);
        //delay_us(100);
        tmpy = XPT2046_GetTouch(Y);

        if (tmpx == 0)  tmpy = 0;
        else if (tmpy == 0)  tmpx = 0;
    else 
    {
			touch_x = (touch_x + tmpx) / 2;
			touch_y = (touch_y + tmpy) / 2;
    }
      
	}
		*x_kor = touch_x;
		*y_kor = touch_y; 
		
}
/*
https://github.com/ScarsFun/lvgl_STM32F103_ILI9341_XPT2046/tree/master/XPT2046
*/
void xpt2046_corr(uint16_t * x, uint16_t * y)
{
#if XPT2046_XY_SWAP 
    int16_t swap_tmp;
    swap_tmp = *x;
    *x = *y;
    *y = swap_tmp;
#endif

    if((*x) > XPT2046_X_MIN)(*x) -= XPT2046_X_MIN;
    else(*x) = 0;

    if((*y) > XPT2046_Y_MIN)(*y) -= XPT2046_Y_MIN;
    else(*y) = 0;

    (*x) = (uint32_t)((uint32_t)(*x) * XPT2046_HOR_RES) /
           (XPT2046_X_MAX - XPT2046_X_MIN);

    (*y) = (uint32_t)((uint32_t)(*y) * XPT2046_VER_RES) /
           (XPT2046_Y_MAX - XPT2046_Y_MIN);

#if XPT2046_X_INV 
    (*x) =  XPT2046_HOR_RES - (*x);
#endif

#if XPT2046_Y_INV 
    (*y) =  XPT2046_VER_RES - (*y);
#endif


}

void xpt2046_avg(uint16_t * x, uint16_t * y)
{
    /*Shift out the oldest data*/
    uint8_t i;
    for(i = XPT2046_AVG - 1; i > 0 ; i--) {
        avg_buf_x[i] = avg_buf_x[i - 1];
        avg_buf_y[i] = avg_buf_y[i - 1];
    }

    /*Insert the new point*/
    avg_buf_x[0] = *x;
    avg_buf_y[0] = *y;
    if(avg_last < XPT2046_AVG) avg_last++;

    /*Sum the x and y coordinates*/
    int32_t x_sum = 0;
    int32_t y_sum = 0;
    for(i = 0; i < avg_last ; i++) {
        x_sum += avg_buf_x[i];
        y_sum += avg_buf_y[i];
    }

    /*Normalize the sums*/
    (*x) = (int32_t)x_sum / avg_last;
    (*y) = (int32_t)y_sum / avg_last;
}
