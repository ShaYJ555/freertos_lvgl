#ifndef _APP_H_
#define _APP_H_

typedef struct 
{
    float acceleration[3];
    float angular_rate[3];
    float temp1;
    float magnetic[3];
    float temp2;
    float temperature;
    float humidity;
    float lightIntensity;
}SensorData;


void lvglTask(void *param);
void updataBacklightTask(void *param);
void updataSensorTask(void *param);

#endif