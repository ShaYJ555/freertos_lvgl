// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.4
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_mainScreen
void ui_mainScreen_screen_init(void);
lv_obj_t * ui_mainScreen;
void ui_event_TempHumiButton(lv_event_t * e);
lv_obj_t * ui_TempHumiButton;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Label1;
void ui_event_LightSensorButton(lv_event_t * e);
lv_obj_t * ui_LightSensorButton;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Label2;
void ui_event_MotionSensorButton(lv_event_t * e);
lv_obj_t * ui_MotionSensorButton;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Label3;
void ui_event_SetupButton(lv_event_t * e);
lv_obj_t * ui_SetupButton;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Label4;


// SCREEN: ui_TempHumiScreen
void ui_TempHumiScreen_screen_init(void);
lv_obj_t * ui_TempHumiScreen;
lv_obj_t * ui_Chart2;
lv_obj_t * ui_Container5;
lv_obj_t * ui_Image8;
lv_obj_t * ui_TempLabel;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Image6;
lv_obj_t * ui_HumiLabel;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label7;


// SCREEN: ui_LightScreen
void ui_LightScreen_screen_init(void);
lv_obj_t * ui_LightScreen;
lv_obj_t * ui_Container1;
lv_obj_t * ui_Image7;
lv_obj_t * ui_BrightnessLabel;
void ui_event_Arc1(lv_event_t * e);
lv_obj_t * ui_Arc1;
lv_obj_t * ui_AdjustBrightnessLabel;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label9;
void ui_event_Switch1(lv_event_t * e);
lv_obj_t * ui_Switch1;


// SCREEN: ui_MotionSensorScreen
void ui_MotionSensorScreen_screen_init(void);
lv_obj_t * ui_MotionSensorScreen;
lv_obj_t * ui_accLabel;
lv_obj_t * ui_angularLabel;
lv_obj_t * ui_magLabel;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label12;
lv_obj_t * ui_accdata1;
lv_obj_t * ui_XLabel2;
lv_obj_t * ui_YLabel2;
lv_obj_t * ui_ZLabel2;
lv_obj_t * ui_angulardata1;
lv_obj_t * ui_XLabel3;
lv_obj_t * ui_YLabel3;
lv_obj_t * ui_ZLabel3;
lv_obj_t * ui_magdata1;
lv_obj_t * ui_XLabel1;
lv_obj_t * ui_YLabel1;
lv_obj_t * ui_ZLabel1;
lv_obj_t * ui_sixtemp;
lv_obj_t * ui_sixtemp2;


// SCREEN: ui_SetupScreen
void ui_SetupScreen_screen_init(void);
lv_obj_t * ui_SetupScreen;
void ui_event_AdjustTempSlider(lv_event_t * e);
lv_obj_t * ui_AdjustTempSlider;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Label8;
lv_obj_t * ui_Chart1;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_sensor[1] = {&ui_img_sensor2_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_TempHumiButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_TempHumiScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_TempHumiScreen_screen_init);
        TempHumiButton_cb(e);
    }
}
void ui_event_LightSensorButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_LightScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_LightScreen_screen_init);
        LightSensorButton_cb(e);
    }
}
void ui_event_MotionSensorButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MotionSensorScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MotionSensorScreen_screen_init);
        MotionSensorButton_cb(e);
    }
}
void ui_event_SetupButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SetupScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SetupScreen_screen_init);
        SetupButton_cb(e);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_mainScreen_screen_init);
        Button1_cb(e);
    }
}
void ui_event_Arc1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_AdjustBrightnessLabel, target, "", "%");
        updateBackLight(e);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_mainScreen_screen_init);
        Button2_cb(e);
    }
}
void ui_event_Switch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_state_modify(ui_Arc1, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
        switchMode(e);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_mainScreen_screen_init);
        Button3_cb(e);
    }
}

void ui_event_AdjustTempSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_Label6, target, "Set to ", "C");
        updateSetPoint(e);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_mainScreen_screen_init);
        Button4_cb(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_mainScreen_screen_init();
    ui_TempHumiScreen_screen_init();
    ui_LightScreen_screen_init();
    ui_MotionSensorScreen_screen_init();
    ui_SetupScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_mainScreen);
}
