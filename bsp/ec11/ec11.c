#include "ec11.h"
// driver
#include "fsl_enc.h"
#include "fsl_gpio.h"
// freertos
#include "FreeRTOS.h"
#include "task.h"
// debug
#include "fsl_debug_console.h"
#include "stdio.h"

#define DEMO_ENC_BASEADDR          ENC1
#define BOARD_ENCODED_GPIO         GPIO2
#define BOARD_ENCODED_GPIO_PIN     5U

int16_t diff_value;

void EC11_Init()
{
    gpio_pin_config_t encode_d_config = {
      .direction = kGPIO_DigitalInput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
    };
    GPIO_PinInit(BOARD_ENCODED_GPIO, BOARD_ENCODED_GPIO_PIN, &encode_d_config);
    enc_config_t mEncConfigStruct;
    ENC_GetDefaultConfig(&mEncConfigStruct);
    ENC_Init(DEMO_ENC_BASEADDR, &mEncConfigStruct);
    ENC_DoSoftwareLoadInitialPositionValue(DEMO_ENC_BASEADDR); 
}


int16_t EC11_read_differential_value()
{
    /* This read operation would capture all the position counter to responding hold registers. */
    ENC_GetPositionValue(DEMO_ENC_BASEADDR);
    int16_t value = (int16_t)ENC_GetHoldPositionDifferenceValue(DEMO_ENC_BASEADDR);
    return value;
} 


uint32_t EC11_key_get_value()
{
    return GPIO_PinRead(BOARD_ENCODED_GPIO,BOARD_ENCODED_GPIO_PIN);
}


