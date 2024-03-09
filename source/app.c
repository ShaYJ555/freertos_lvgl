#include "app.h"
// freertos
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
// lvgl
#include "lvgl_support.h"
#include "lvgl.h"
#include "ui.h"
// bsp
#include "sensor_support.h"
#include "bh1730fvc.h"
#include "st7735s.h"
#include "nsht30.h"
// debug
#include "stdio.h"
#include "string.h"
#include "fsl_debug_console.h"
// math
#include "math.h"

TaskHandle_t g_updataBacklightTask;
TaskHandle_t g_updataSensorTask;
TaskHandle_t g_lvglTask;
extern uint8_t str_buf[50];
extern volatile bool s_lvgl_initialized;
// sensor data
// float Temperature_humidity_value[2];
// float lightIntensity;
extern QueueHandle_t updateSensorDataQueue;
extern QueueHandle_t updateBacklightQueue;
extern QueueHandle_t updateTemperatureQueue;

// chart 
extern lv_chart_series_t * ui_Chart2_series_1;
extern lv_chart_series_t * ui_Chart2_series_2;
extern lv_chart_series_t * ui_Chart1_series_1;

int8_t mapFloatToDuty(float value);
void updateDataTask(lv_timer_t *t);

#if LV_USE_LOG
void print_cb(const char *buf)
{
    PRINTF("\rlvgl:%s\n", buf);
}
#endif

void updataSensorTask(void *param)
{   
    float Temperature_humidity_value[2];
    float temperature;
    float lightIntensity;
    SixaxisSensorData sixaxisdata;
    MagneticSensorsData magneticdata;
    SensorData sensordata;
    for(;;)
    {
        if(nsht30_read_temp_humi_1ch(Temperature_humidity_value))
        {
            sensordata.temperature = Temperature_humidity_value[0];
            sensordata.humidity = Temperature_humidity_value[1];
            temperature = Temperature_humidity_value[0];
        }
        if(bh1730fvc_read_lux(&lightIntensity))
        {
            sensordata.lightIntensity = lightIntensity;
        }
        lsm6ds3tr_read_data(&sixaxisdata);
        sensordata.acceleration[0] = sixaxisdata.accelerationx;
        sensordata.acceleration[1] = sixaxisdata.accelerationy;
        sensordata.acceleration[2] = sixaxisdata.accelerationz;
        sensordata.angular_rate[0] = sixaxisdata.angular_ratex;
        sensordata.angular_rate[1] = sixaxisdata.angular_ratey;
        sensordata.angular_rate[2] = sixaxisdata.angular_ratez;
        sensordata.temp1 = sixaxisdata.temp;
        lis2mdl_read_data(&magneticdata);
        sensordata.magnetic[0] = magneticdata.magneticx;
        sensordata.magnetic[1] = magneticdata.magneticy;
        sensordata.magnetic[2] = magneticdata.magneticz;
        sensordata.temp2 = magneticdata.temp;
        xQueueSend(updateSensorDataQueue,&sensordata,0);
        xQueueSend(updateBacklightQueue,&lightIntensity,0);
        xQueueSend(updateTemperatureQueue,&temperature,0);
        vTaskDelay(1000);
    }
}

void lvglTask(void *param)
{
    static lv_timer_t *updata_data_task;
#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif
    lv_port_pre_init();
    lv_init();
    
    lv_port_disp_init();
    lv_port_indev_init();
    ui_init();
    s_lvgl_initialized = true;

    lv_chart_set_update_mode(ui_Chart1, LV_CHART_UPDATE_MODE_SHIFT);
    lv_chart_set_update_mode(ui_Chart2, LV_CHART_UPDATE_MODE_SHIFT);
    updata_data_task = lv_timer_create(updateDataTask,100,NULL);
    for (;;)
    {
        lv_task_handler();
        vTaskDelay(5);
    }
}

void updataBacklightTask(void *param)
{
    float data;
    static int8_t nowDuty=0,lastDuty=0;
    float lightIntensity;
    for(;;)
    {
        if(xQueueReceive(updateBacklightQueue,&lightIntensity,0)==pdTRUE)
        {
            data = powf(lightIntensity,2.0);
            nowDuty = mapFloatToDuty(data);
            if((nowDuty - lastDuty)>5)
            {
                nowDuty += 5;
                if(nowDuty>= 100) nowDuty = 100;
            }
            if((nowDuty - lastDuty)<-5)
            {
                nowDuty -= 5;
                if(nowDuty<10) nowDuty = 10;
            }
            adjustBacklight((uint8_t)nowDuty);
            lastDuty = nowDuty;
        }
        vTaskDelay(100);
    }
}

int8_t mapFloatToDuty(float value) {
    // 确保输入值在[minInput, maxInput]范围内
    float minInput = 30.0;
    float maxInput = 100000.0;
    uint8_t minDuty = 20;
    uint8_t maxDuty = 100;
    if (value < minInput) {
        value = minInput;
    } else if (value > maxInput) {
        value = maxInput;
    }

    // 线性映射
    int8_t output = (int8_t)(((value - minInput) / (maxInput - minInput)) * (maxDuty - minDuty) + minDuty);
    return output;
}


void updateDataTask(lv_timer_t *t)
{
    SensorData sensordata;
    if(xQueueReceive(updateSensorDataQueue,&sensordata,0)==pdTRUE)
    {
        // Temp & Humi
        lv_label_set_text_fmt(ui_TempLabel,"%4.1f C",sensordata.temperature);
        lv_label_set_text_fmt(ui_HumiLabel,"%3.1f %%",sensordata.humidity);
        lv_chart_set_next_value(ui_Chart2,ui_Chart2_series_1,(lv_coord_t)sensordata.temperature);
        lv_chart_set_next_value(ui_Chart2,ui_Chart2_series_2,(lv_coord_t)sensordata.humidity);
        lv_chart_refresh(ui_Chart2);

        // Motion Sensor
        lv_label_set_text_fmt(ui_XLabel2,"X:%4.2f ",sensordata.acceleration[0]);
        lv_label_set_text_fmt(ui_YLabel2,"Y:%4.2f ",sensordata.acceleration[1]);
        lv_label_set_text_fmt(ui_ZLabel2,"Z:%4.2f ",sensordata.acceleration[2]);

        lv_label_set_text_fmt(ui_XLabel3,"X:%4.2f ",sensordata.angular_rate[0]);
        lv_label_set_text_fmt(ui_YLabel3,"Y:%4.2f ",sensordata.angular_rate[1]);
        lv_label_set_text_fmt(ui_ZLabel3,"Z:%4.2f ",sensordata.angular_rate[2]);

        lv_label_set_text_fmt(ui_sixtemp,"%3.1f C ",sensordata.temp1);

        lv_label_set_text_fmt(ui_XLabel1,"X:%4.2f ",sensordata.magnetic[0]);
        lv_label_set_text_fmt(ui_YLabel1,"Y:%4.2f ",sensordata.magnetic[1]);
        lv_label_set_text_fmt(ui_ZLabel1,"Z:%4.2f ",sensordata.magnetic[2]);

        lv_label_set_text_fmt(ui_sixtemp2,"%3.1f C ",sensordata.temp2);

        // Light Sensor
        lv_label_set_text_fmt(ui_BrightnessLabel,"%6.1f lux",sensordata.lightIntensity);

        // Setup Temperature
        lv_label_set_text_fmt(ui_Label8,"%4.1f C",sensordata.temperature);
        lv_chart_set_next_value(ui_Chart1,ui_Chart1_series_1,(lv_coord_t)sensordata.temperature);
        lv_chart_refresh(ui_Chart1);
    }
}


