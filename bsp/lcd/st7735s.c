/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017,2019, 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "st7735s.h"
// drivers
#include "fsl_pwm.h"

void ST7735_Init(st7735_send_byte_t _writeData, st7735_send_byte_t _writeCommand)
{
    _writeCommand(ST7735_SLPOUT);
    SDK_DelayAtLeastUs(ST7735_RESET_CANCEL_MS * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    
    _writeCommand(ST7735_FRMCTR1);
    _writeData(0x01);
    _writeData(0x2C);
    _writeData(0x2D);
    _writeCommand(ST7735_FRMCTR2);
    _writeData(0x01);
    _writeData(0x2C);
    _writeData(0x2D);
    _writeCommand(ST7735_FRMCTR3);
    _writeData(0x01);
    _writeData(0x2C);
    _writeData(0x2D);
    _writeData(0x01);
    _writeData(0x2C);
    _writeData(0x2D);
    _writeCommand(ST7735_INVCTR);
    _writeData(0x07);
    _writeCommand(ST7735_PWCTR1);
    _writeData(0xA2);
    _writeData(0x02);
    _writeData(0x84);
    _writeCommand(ST7735_PWCTR2);
    _writeData(0xC5);
    _writeCommand(ST7735_PWCTR3);
    _writeData(0x0A);
    _writeData(0x00);
    _writeCommand(ST7735_PWCTR4);
    _writeData(0x8A);
    _writeData(0x2A);
    _writeCommand(ST7735_PWCTR5);
    _writeData(0x8A);
    _writeData(0xEE);
    _writeCommand(ST7735_VMCTR1);
    _writeData(0x0E);
    _writeCommand(ST7735_INVOFF);
    _writeCommand(ST7735_COLMOD);
    _writeData(0x05);
    _writeCommand(ST7735_CASET);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x7F);
    _writeCommand(ST7735_RASET);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x9F);
    _writeCommand(ST7735_GMCTRP1);
    _writeData(0x02);
    _writeData(0x1C);
    _writeData(0x07);
    _writeData(0x12);
    _writeData(0x37);
    _writeData(0x32);
    _writeData(0x29);
    _writeData(0x2D);
    _writeData(0x29);
    _writeData(0x25);
    _writeData(0x2B);
    _writeData(0x39);
    _writeData(0x00);
    _writeData(0x01);
    _writeData(0x03);
    _writeData(0x10);
    _writeCommand(ST7735_GMCTRN1);
    _writeData(0x03);
    _writeData(0x1D);
    _writeData(0x07);
    _writeData(0x06);
    _writeData(0x2E);
    _writeData(0x2C);
    _writeData(0x29);
    _writeData(0x2D);
    _writeData(0x2E);
    _writeData(0x2E);
    _writeData(0x37);
    _writeData(0x3F);
    _writeData(0x00);
    _writeData(0x00);
    _writeData(0x02);
    _writeData(0x10);
    _writeCommand(ST7735_NORON);
    
    SDK_DelayAtLeastUs(10 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    _writeCommand(ST7735_DISPON);
    SDK_DelayAtLeastUs(10 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    /* Change to landscape view. */
    _writeCommand(ST7735_MADCTL);
    _writeData(ST7735_MADCTL_MX | ST7735_MADCTL_MY | ST7735_MADCTL_RGB);
}

void BackLight_Init()
{   
    pwm_config_t pwmConfig;
    pwm_signal_param_t pwmSignal;
    uint32_t sourceclock = CLOCK_GetFreq(kCLOCK_IpgClk);
    CLOCK_EnableClock(kCLOCK_Pwm2);
    PWM_GetDefaultConfig(&pwmConfig);
    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    pwmConfig.pairOperation   = kPWM_Independent;
    pwmConfig.prescale = kPWM_Prescale_Divide_128;
    PWM_Init(PWM2,kPWM_Module_2,&pwmConfig);
    
    PWM2->SM[2].DISMAP[0]=0;    // 禁用fault 

    pwmSignal.pwmChannel=kPWM_PwmB;//PWM通道B
    pwmSignal.dutyCyclePercent=50;//占空比，输入参数duty
    pwmSignal.level=kPWM_HighTrue;//高电平有效
    pwmSignal.pwmchannelenable = true;
    
    PWM_SetupPwm(PWM2, kPWM_Module_2, &pwmSignal, 1, kPWM_CenterAligned, 10000, sourceclock);

    PWM_SetPwmLdok(PWM2,kPWM_Control_Module_2,true);//设置PWM的load ok位
    PWM_StartTimer(PWM2, kPWM_Control_Module_2);//开启定时器

}

void adjustBacklight(uint8_t duty)
{
    PWM_UpdatePwmDutycycle(PWM2,kPWM_Module_2,kPWM_PwmB,kPWM_CenterAligned,duty);
    PWM_SetPwmLdok(PWM2, kPWM_Control_Module_2, true);    //更新有关设置
}

