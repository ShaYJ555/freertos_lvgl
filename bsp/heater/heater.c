#include "heater.h"
// driver
#include "fsl_pwm.h"
#include "fsl_gpt.h"
// bsp
#include "nsht30.h"
// debug
#include "fsl_debug_console.h"
#include "stdio.h"


#define KP   5.0
#define KI   1.5
#define KD   3.0 

PIDController heaterPID;
extern uint8_t str_buf[50];

void Timer_Init();
void TimerCallback();

void Heater_Init()
{ 
    pwm_config_t pwmConfig;
    pwm_signal_param_t pwmSignal;
    CLOCK_EnableClock(kCLOCK_Pwm2);
    PWM_GetDefaultConfig(&pwmConfig);
    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    pwmConfig.pairOperation   = kPWM_Independent;
    pwmConfig.prescale = kPWM_Prescale_Divide_128;
    PWM_Init(PWM2,kPWM_Module_3,&pwmConfig);
    
    /* 禁用故障检测功能 */
    PWM2->SM[3].DISMAP[0] = 0;
    
    pwmSignal.pwmChannel=kPWM_PwmB;
    pwmSignal.dutyCyclePercent=0;
    pwmSignal.level=kPWM_HighTrue;
    pwmSignal.pwmchannelenable = true;

    //设置PWM2，中央对齐模式
    //哪个PWM,子模块,通道参数,通道数,对齐模式,频率input,时钟频率
    PWM_SetupPwm(PWM2, kPWM_Module_3, &pwmSignal, 1, kPWM_CenterAligned, 1000U, CLOCK_GetFreq(kCLOCK_IpgClk));

    PWM_SetPwmLdok(PWM2,kPWM_Control_Module_3,true);//设置PWM的load ok位
    PWM_StartTimer(PWM2, kPWM_Control_Module_3);//开启定时器
    
    PIDController_Init(&heaterPID);

    // Timer_Init();
}

void Timer_Init()
{
    uint32_t gptFreq;
    gpt_config_t gptConfig;
    GPT_GetDefaultConfig(&gptConfig);

    /* Initialize GPT module */
    GPT_Init(GPT2, &gptConfig);    

    /* Divide GPT clock source frequency by 3 inside GPT module */
    GPT_SetClockDivider(GPT2, 2);
    gptFreq = CLOCK_GetFreq(kCLOCK_PerClk);

    /* GPT frequency is divided by 3 inside module */
    gptFreq /= 2;

    /* Set both GPT modules to 10 millisecond duration */
    GPT_SetOutputCompareValue(GPT2, kGPT_OutputCompare_Channel1, gptFreq/100);

    /* Enable GPT Output Compare1 interrupt */
    GPT_EnableInterrupts(GPT2, kGPT_OutputCompare1InterruptEnable);

    /* Enable at the Interrupt */
    EnableIRQ(GPT2_IRQn);

    GPT_StartTimer(GPT2);
}

void GPT2_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    GPT_ClearStatusFlags(GPT2, kGPT_OutputCompare1Flag);
    // PRINTF("hello world\r\n");
    TimerCallback();

/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F, Cortex-M7, Cortex-M7F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U || __CORTEX_M == 7U)
    __DSB();
#endif
}


void Heater_Control(uint8_t duty)
{
    //更新占空比
    PWM_UpdatePwmDutycycle(PWM2, kPWM_Module_3, kPWM_PwmB, kPWM_CenterAligned, duty);
    //设置PWM的load ok位
    PWM_SetPwmLdok(PWM2,kPWM_Control_Module_3,true);
}

// 初始化PID控制器
void PIDController_Init(PIDController *pid) {
    pid->setpoint = 30.0;
    pid->input = 0.0;
    pid->output = 0.0;
    pid->error = 0.0;
    pid->prevError = 0.0;
    pid->integral = 0.0;
}

// PID控制算法
void PIDController_Update(PIDController *pid) {

    pid->error = pid->setpoint - pid->input;
    pid->integral += pid->error;
    float derivative = (pid->error - pid->prevError);

    pid->output = KP * pid->error + KI * pid->integral + KD * derivative;

    pid->prevError = pid->error;
}
