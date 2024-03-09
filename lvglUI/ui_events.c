// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.4
// Project name: SquareLine_Project

#include "ui.h"
// bsp
#include "st7735s.h"
#include "heater.h"
// freertos
#include "FreeRTOS.h"
#include "task.h"
#include "app.h"
// debug
#include "fsl_debug_console.h"
#include "stdio.h"

extern lv_group_t *group;
extern PIDController heaterPID;

void updateBackLight(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	adjustBacklight((uint8_t)lv_arc_get_value(target));
}

void switchMode(lv_event_t * e)
{
	BaseType_t backlight_stat;
	extern TaskHandle_t g_updataBacklightTask;
	lv_obj_t * target = lv_event_get_target(e);
	if(!lv_obj_has_state(target, LV_STATE_CHECKED))
	{
		taskENTER_CRITICAL();
		backlight_stat = xTaskCreate(updataBacklightTask,"backlight",400,NULL,tskIDLE_PRIORITY + 1,&g_updataBacklightTask);
		PRINTF("switch off\r\n");
		taskEXIT_CRITICAL();
	}
	else
	{
		taskENTER_CRITICAL();
		vTaskDelete(g_updataBacklightTask);
		PRINTF("switch on\r\n");
		taskEXIT_CRITICAL();
	}
}

void TempHumiButton_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_TempHumiButton);
    lv_group_remove_obj(ui_LightSensorButton);
    lv_group_remove_obj(ui_MotionSensorButton);
    lv_group_remove_obj(ui_SetupButton);
}

void LightSensorButton_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_TempHumiButton);
    lv_group_remove_obj(ui_LightSensorButton);
    lv_group_remove_obj(ui_MotionSensorButton);
    lv_group_remove_obj(ui_SetupButton);
}

void MotionSensorButton_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_TempHumiButton);
    lv_group_remove_obj(ui_LightSensorButton);
    lv_group_remove_obj(ui_MotionSensorButton);
    lv_group_remove_obj(ui_SetupButton);
}

void SetupButton_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_TempHumiButton);
    lv_group_remove_obj(ui_LightSensorButton);
    lv_group_remove_obj(ui_MotionSensorButton);
    lv_group_remove_obj(ui_SetupButton);
}

void Button1_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_Button1);
}

void Button2_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_Button2);
    lv_group_remove_obj(ui_Arc1);
    lv_group_remove_obj(ui_Switch1);
}

void Button3_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_Button3);
}

void Button4_cb(lv_event_t * e)
{
	lv_group_remove_obj(ui_Button4);
    lv_group_remove_obj(ui_AdjustTempSlider);
}

void updateSetPoint(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	// taskENTER_CRITICAL();
	heaterPID.setpoint = (float)lv_slider_get_value(target);
	// taskEXIT_CRITICAL();
}

