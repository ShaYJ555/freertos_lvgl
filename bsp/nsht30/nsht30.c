#include "nsht30.h"
// driver
#include "fsl_gpio.h"
// freertos
#include "FreeRTOS.h"
#include "task.h"

#define BOARD_SENSOR_NRST_GPIO      GPIO2
#define BOARD_SENSOR_NRST_GPIO_PIN  0U

extern void nsht30_send_data(uint8_t* data,uint32_t num);
extern void  nsht30_read_data(uint8_t* data,uint32_t num);

void nsht30_send_cmd(uint16_t cmd)
{
    uint8_t data[2];
    data[0] = (cmd & 0xFF00) >> 8;
    data[1] = cmd & 0xFF;
    nsht30_send_data(data,2);
}

void nsht30_init()
{
    gpio_pin_config_t nrst_config = {
        // LED 引脚
        kGPIO_DigitalOutput,
        1,
        kGPIO_NoIntmode,
    };
    GPIO_PinInit(BOARD_SENSOR_NRST_GPIO, BOARD_SENSOR_NRST_GPIO_PIN, &nrst_config);
        /* Chip reset */
    GPIO_PortSet(BOARD_SENSOR_NRST_GPIO, 1u << BOARD_SENSOR_NRST_GPIO_PIN);
    SDK_DelayAtLeastUs(100U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY); // delay 100us
    GPIO_PortClear(BOARD_SENSOR_NRST_GPIO, 1u << BOARD_SENSOR_NRST_GPIO_PIN);
    SDK_DelayAtLeastUs(100U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY); // delay 100us
    GPIO_PortSet(BOARD_SENSOR_NRST_GPIO, 1u << BOARD_SENSOR_NRST_GPIO_PIN);
}


// periodic mode    没测试过
void nsht30_read_raw_periodic(uint8_t *buff)
{
    uint8_t cmd[2] = {0xE0,0x00};   // Read cmd
    nsht30_send_data(cmd,2);
    vTaskDelay(10);
    nsht30_read_data(buff,6);       // Read data
}


// Single mode
void nsht30_read_raw_single(uint16_t cmd, uint8_t *buff)
{
    uint8_t data[2];
    data[0] = (cmd & 0xFF00) >> 8;
    data[1] = cmd & 0xFF;
    nsht30_send_data(data,2);
    vTaskDelay(10);         // delay 10ms
    nsht30_read_data(buff,6);
}


// CRC calculation
int nst30_crc_check(uint8_t *data, uint8_t len, uint8_t checksum)
{
    uint8_t crc = 0xFF, bit;
    uint8_t byteCtr;
    // calculates 8-Bit checksum with given polynomial
    for (byteCtr = 0; byteCtr < len; ++byteCtr)
    {
        crc ^= (data[byteCtr]);
        for (bit = 8; bit > 0; --bit)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x131;
            else
                crc = (crc << 1);
        }
    }
    if (crc == checksum)
        return 1;
    else
        return 0;
}


int32_t nsht30_read_temp_humi_1ch(float *pout)
{
    uint8_t data[6];
    uint16_t temperature, humidity;
    nsht30_read_raw_single(CMD_MEAS_SINGLE_M, data);    // single mode
    temperature = ((uint16_t)data[0] << 8) | data[1];
    humidity = ((uint16_t)data[3] << 8) | data[4];
    if((nst30_crc_check(data,2,data[2])) && (nst30_crc_check(data+3,2,data[5])))
    {
        pout[0] = (175.0 * (float)temperature / 65535.0 - 45.0); // T = -45 + 175 * tem / (2^16-1)
        pout[1] = (100.0 * (float)humidity / 65535.0);        // RH = hum*100 / (2^16-1)
        return 1;
    }
    else
    {
        return 0;
    }
}