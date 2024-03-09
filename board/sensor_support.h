#ifndef SENSOR_SUPPORT_H
#define SENSOR_SUPPORT_H

#include <stdint.h>

/* Select OSC_CLK (24 MHz) as master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (1U)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
    float accelerationx;
    float accelerationy;
    float accelerationz;
    float angular_ratex;
    float angular_ratey;
    float angular_ratez;
    float temp;
}SixaxisSensorData;

typedef struct 
{
    float magneticx;
    float magneticy;
    float magneticz;
    float temp;
}MagneticSensorsData;

void DEMO_InitSensor(void);
void SPI_Init(void);
void lsm6ds3tr_read_data(SixaxisSensorData *data);
void lis2mdl_read_data(MagneticSensorsData *data);
#if defined(__cplusplus)
}
#endif

#endif