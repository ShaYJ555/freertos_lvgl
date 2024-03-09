#ifndef _HEATER_H_
#define _HEATER_H_

#include "fsl_common.h"


typedef struct {
    float setpoint;
    float input;
    float output;
    float error;
    float prevError;
    float integral;
} PIDController;


void Heater_Init(void);
void Heater_Control(uint8_t duty);
void PIDController_Init(PIDController *pid);
void PIDController_Update(PIDController *pid);
#endif