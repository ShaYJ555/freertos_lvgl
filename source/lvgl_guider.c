/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
// freertos
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "app.h"
// driver & config
#include "fsl_lpspi.h"
#include "fsl_edma.h"
#include "fsl_dmamux.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
// lvgl
#include "ui.h"
#include "lvgl_support.h"
// bsp 
#include "nsht30.h"
#include "bh1730fvc.h"
#include "heater.h"
#include "sensor_support.h"
// debug
#include "fsl_debug_console.h"
#include "stdio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool s_lvgl_initialized = false;
uint8_t str_buf[50] = {0};
AT_NONCACHEABLE_SECTION_INIT(uint8_t ucHeap[ configTOTAL_HEAP_SIZE ]);
extern TaskHandle_t g_updataSensorTask;
extern TaskHandle_t g_lvglTask;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern float Temperature_humidity_value[2];
extern PIDController heaterPID;
QueueHandle_t updateSensorDataQueue;
QueueHandle_t updateBacklightQueue;
QueueHandle_t updateTemperatureQueue;


// 定时器回调函数，用于执行PID控制算法
void TimerCallback( TimerHandle_t xTimer )
{
    float temperature;
    if(xQueueReceive(updateTemperatureQueue,&temperature,0)==pdTRUE)
    {
        heaterPID.input = temperature;
        // 更新PID控制器
        PIDController_Update(&heaterPID);
        // PRINTF("set point %d \r\n",(int)heaterPID.setpoint);
        if(heaterPID.output>100)
        {
            Heater_Control(100);
        }
        else if(heaterPID.output<0)
        {
            Heater_Control(0);
        }
        else
        {
            Heater_Control((uint8_t)heaterPID.output);
        }
    } 

}

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    BaseType_t lvgl_stat,temphumi_stat;
    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* DMA Mux init and EDMA init */
    edma_config_t edmaConfig = {0};
    EDMA_GetDefaultConfig(&edmaConfig);
    EDMA_Init(DMA0, &edmaConfig);
#if (defined(FSL_FEATURE_SOC_DMAMUX_COUNT) && FSL_FEATURE_SOC_DMAMUX_COUNT)
    DMAMUX_Init(DMAMUX);
#endif

    /* LPSPI Clock */
    DEMO_InitSensor();
    Heater_Init();

    updateSensorDataQueue  = xQueueCreate(1, sizeof(SensorData));
    updateBacklightQueue   = xQueueCreate(1, sizeof(float));
    updateTemperatureQueue = xQueueCreate(1, sizeof(float));
    
    TimerHandle_t xTimer = xTimerCreate("PIDTimer", pdMS_TO_TICKS(100), pdTRUE, NULL, TimerCallback);
    if (xTimer != NULL) {
        // 启动定时器
        xTimerStart(xTimer, 0);
    }   
    
    temphumi_stat = xTaskCreate(updataSensorTask, "sensor", 512, NULL, tskIDLE_PRIORITY + 1,&g_updataSensorTask);
    if (temphumi_stat != pdPASS)
    {
        PRINTF("Failed to create sensor task");
        while (1)
            ;
    }

    lvgl_stat = xTaskCreate(lvglTask, "lvgl", 1024*2, NULL, tskIDLE_PRIORITY + 2,&g_lvglTask);    
    if (lvgl_stat != pdPASS)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }
    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc failed. Increase the heap size.");
    
    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;
    PRINTF("%s task overflow",pcTaskName);
    for (;;)
        ;
}
