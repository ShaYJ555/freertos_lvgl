#include "bh1730fvc.h"
// freertos
#include "FreeRTOS.h"
#include "task.h"

#define defalt_GAIN      1
#define defalt_ITIME     0xDA
#define T_INT_US         2.8 //uS, typical, from datasheet
#define defalt_ITIME_ms  ((T_INT_US * 964 * (256 - defalt_ITIME)) / 1000.0)

#define RET_TIMEOUT      100


extern void bh1730fvc_send_data(uint8_t *data, uint32_t num);
extern void bh1730fvc_read_data(uint8_t *data, uint32_t num);

static void bh1730fvc_write_cmd(uint8_t cmd)
{
    bh1730fvc_send_data(&cmd,1);
}

static void bh1730fvc_read_id(uint8_t* id)
{
    uint8_t cmd = (uint8_t)BH1730FVC_ID; 
    bh1730fvc_send_data(&cmd,1);
    bh1730fvc_read_data(id,1);
}

static uint8_t bh1730fvc_read_reg(uint8_t reg_addr)
{
    uint8_t val;
    bh1730fvc_send_data(&reg_addr,1);
    bh1730fvc_read_data(&val,1);
    return val;
}

uint8_t bh1730fvc_init()
{
    uint8_t chip_id = 0;
    /* Software Reset */
    bh1730fvc_write_cmd(BH1730FVC_RESET);
    /* Read Id & Check Id*/ 
    bh1730fvc_read_id(&chip_id);
    if((chip_id&0xF0) == 0x70)
    {
        return 1;
    }else
    {
        return 0;
    }
}

uint8_t bh1730fvc_read_lux(float* lux)
{
    /* Continue Measurement */ 
    uint8_t cmd[2] = {0};
    cmd[0] = BH1730FVC_CONTROL;
    cmd[1] = BH1730FVC_CONTROL_ONE_TIME_ONETIME|BH1730FVC_CONTROL_ADC_EN_ENABLE|BH1730FVC_CONTROL_POWER_ENABLE;
    bh1730fvc_send_data(cmd,2);

    // // Wait for ADC data is valid
    uint8_t ret = 0;
    while(((bh1730fvc_read_reg(BH1730FVC_CONTROL) & BH1730FVC_CONTROL_ADC_VALID) == 0) && ++ret < RET_TIMEOUT){
        vTaskDelay(10);
    }

    if(ret == RET_TIMEOUT){
        return 0;
    }

    /* Read real light and IR light from registers  */
    /* Write Data register start addr */
    uint8_t data[4];
    bh1730fvc_write_cmd(BH1730FVC_DATA0LOW);
    bh1730fvc_read_data(data,4);

    float data0 = (float)(data[0] | data[1] << 8);
    float data1 = (float)(data[2] | data[3] << 8);
    
    /* special case */
    if(data0 == 0.0)
    {
        *lux = 0;
        return 0;
    }
    
    float div = data1/data0;

    if(div < 0.26) {
        *lux = ((1.29 * data0) - (2.733 * data1)) / defalt_GAIN * 102.6 / defalt_ITIME_ms;
    }else if(div < 0.55) {
        *lux = ((0.795 * data0) - (0.859 * data1)) / defalt_GAIN * 102.6 / defalt_ITIME_ms;
    }else if(div < 1.09) {
        *lux = ((0.51 * data0) - (0.345 * data1)) / defalt_GAIN * 102.6 / defalt_ITIME_ms;
    }else if(div < 2.13) {
        *lux = ((0.276 * data0) - (0.13 * data1)) / defalt_GAIN * 102.6 / defalt_ITIME_ms;
    }

    return 1;
}
