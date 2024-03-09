#include "sensor_support.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif

#include "board.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_lpi2c_cmsis.h"
#include "fsl_lpspi.h"
#include "fsl_lpspi_edma.h"
#include "fsl_edma.h"
#include "fsl_pwm.h"

#include "fsl_debug_console.h"
#include "nsht30.h"
#include "bh1730fvc.h"
#include "lsm6ds3tr-c_reg.h"
#include "lis2mdl_reg.h"

#include "stdio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Port Me, Start. */
/* CMSIS Driver LPIIC */
#define BOARD_SENSOR_I2C Driver_I2C1
#define BOARD_SENSOR_I2C_IRQ LPI2C1_IRQn
#define BOARD_SENSOR_I2C_FREQ_FUNC LPI2C1_GetFreq
#define BOARD_SENSOR_I2C_FREQ CLOCK_GetFreq(kCLOCK_OscClk) / LPI2C_CLOCK_SOURCE_DIVIDER

/* Driver LPSPI2 polling*/
#define SENSOR_LPSPI_MASTER_BASEADDR (LPSPI2)
#define SENSOR_LPSPI_MASTER_IRQN LPSPI2_IRQn

#define SENSOR_LPSPI_MASTER_PCS_FOR_INIT (kLPSPI_Pcs0)
#define SENSOR_LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

#define SENSOR_LPSPI_CLOCK_SOURCE_SELECT (2U)
/* Clock divider for master lpspi clock source */
#define SENSOR_LPSPI_CLOCK_SOURCE_DIVIDER (5U)

#define SENSOR_LPSPI_MASTER_CLK_FREQ (CLOCK_GetFreq(kCLOCK_SysPllClk) / (SENSOR_LPSPI_CLOCK_SOURCE_DIVIDER + 1))
#define TRANSFER_BAUDRATE 5000000U /* Transfer baudrate - 5M */
#define TRANSFER_SIZE 20

/* Driver LPSPI4 polling */

/* Port Me, End. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
uint8_t lsm6ds3tr_init(void);
uint8_t lis2mdl_init(void);
extern void LPSPI2_InitPins(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t spi_txbuf[TRANSFER_SIZE] = {0};
uint8_t spi_rxbuf[TRANSFER_SIZE] = {0};
uint8_t tx_buffer[100];
stmdev_ctx_t lsm6ds3tr_ctx, lis2mdl_ctx;
volatile bool i2c_event_received;


pwm_config_t PWM2_SM0_config = {
  .clockSource = kPWM_BusClock,
  .prescale = kPWM_Prescale_Divide_32,
  .pairOperation = kPWM_Independent,
  .initializationControl = kPWM_Initialize_LocalSync,
  .reloadLogic = kPWM_ReloadImmediate,
  .reloadSelect = kPWM_LocalReload,
  .reloadFrequency = kPWM_LoadEveryOportunity,
  .forceTrigger = kPWM_Force_Local,
  .enableDebugMode = false,
};

const pwm_fault_input_filter_param_t PWM2_faultInputFilter_config = {
  .faultFilterPeriod = 1U,
  .faultFilterCount = 3U,
  .faultGlitchStretch = false
};
const pwm_fault_param_t PWM2_Fault0_fault_config = {
  .faultClearingMode = kPWM_Automatic,
  .faultLevel = false,
  .enableCombinationalPath = false,
  .recoverMode = kPWM_NoRecovery
};
const pwm_fault_param_t PWM2_Fault1_fault_config = {
  .faultClearingMode = kPWM_Automatic,
  .faultLevel = false,
  .enableCombinationalPath = false,
  .recoverMode = kPWM_NoRecovery
};
const pwm_fault_param_t PWM2_Fault2_fault_config = {
  .faultClearingMode = kPWM_Automatic,
  .faultLevel = false,
  .enableCombinationalPath = false,
  .recoverMode = kPWM_NoRecovery
};
const pwm_fault_param_t PWM2_Fault3_fault_config = {
  .faultClearingMode = kPWM_Automatic,
  .faultLevel = false,
  .enableCombinationalPath = false,
  .recoverMode = kPWM_NoRecovery
};
/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t BOARD_SENSOR_I2C_FREQ_FUNC(void)
{
    return BOARD_SENSOR_I2C_FREQ;
}

static void I2C_MasterSignalEvent(uint32_t event)
{
    i2c_event_received = true;
}

static void IIC_WaitEvent(void)
{
    /* Wait until transfer completed */
    while (!i2c_event_received)
        ;
    i2c_event_received = false;
    /* Clear event flags before new transfer */
}

static void DEMO_InitSensorI2cClk(void)
{
    /* Set LPI2C_CLK_PODF. */
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);
    /* Set Lpi2c clock source. */
    CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SOURCE_SELECT);
}

void SPI_Init()
{
    lpspi_master_config_t masterConfig;
    /*Master config*/
    LPSPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate = TRANSFER_BAUDRATE;
    masterConfig.whichPcs = SENSOR_LPSPI_MASTER_PCS_FOR_INIT;
    masterConfig.cpol = kLPSPI_ClockPolarityActiveLow;
    masterConfig.cpha = kLPSPI_ClockPhaseSecondEdge;
    LPSPI_MasterInit(SENSOR_LPSPI_MASTER_BASEADDR, &masterConfig, SENSOR_LPSPI_MASTER_CLK_FREQ);
}

void BOARD_PWM_Init()
{
    /* Initialize PWM submodule SM0 main configuration */
    PWM_Init(PWM2, kPWM_Fault_0, &PWM2_SM0_config);
    /* Initialize fault input filter configuration */
    PWM_SetupFaultInputFilter(PWM2, &PWM2_faultInputFilter_config);
    /* Initialize fault channel 0 fault Fault0 configuration */
    PWM_SetupFaults(PWM2, kPWM_Fault_0, &PWM2_Fault0_fault_config);
    /* Initialize fault channel 0 fault Fault1 configuration */
    PWM_SetupFaults(PWM2, kPWM_Fault_1, &PWM2_Fault1_fault_config);
    /* Initialize fault channel 0 fault Fault2 configuration */
    PWM_SetupFaults(PWM2, kPWM_Fault_2, &PWM2_Fault2_fault_config);
    /* Initialize fault channel 0 fault Fault3 configuration */
    PWM_SetupFaults(PWM2, kPWM_Fault_2, &PWM2_Fault3_fault_config);
}

/*Initialize your touchpad*/
void DEMO_InitSensor(void)
{
    /* The FreeRTOS kernel APIs are not used in I2C ISR, so the
     * interrupt priority could be set to 0.
     */

    NVIC_SetPriority(BOARD_SENSOR_I2C_IRQ, 0);

    DEMO_InitSensorI2cClk();

    /*Init I2C1 */
    BOARD_SENSOR_I2C.Initialize(I2C_MasterSignalEvent);
    BOARD_SENSOR_I2C.PowerControl(ARM_POWER_FULL);
    BOARD_SENSOR_I2C.Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_STANDARD);

    /* Set LPSPI_PODF. */
    CLOCK_SetDiv(kCLOCK_LpspiDiv, LPSPI_CLOCK_SOURCE_DIVIDER);
    /* Set Lpspi clock source. */
    CLOCK_SetMux(kCLOCK_LpspiMux, LPSPI_CLOCK_SOURCE_SELECT);
    
    SPI_Init();
    nsht30_init();
    PRINTF("nsht30 Init OK\r\n");
    if(bh1730fvc_init())   PRINTF("bh1730fvc Init OK\r\n");
    if (lis2mdl_init())    PRINTF("lis2mdl Init OK\r\n");
    if (lsm6ds3tr_init())  PRINTF("lsm6ds3tr Init OK\r\n");

}

void nsht30_send_data(uint8_t *data, uint32_t num)
{
    BOARD_SENSOR_I2C.MasterTransmit(NSHT30_ADDR, data, num, false);
    IIC_WaitEvent();
}

void nsht30_read_data(uint8_t *data, uint32_t num)
{
    BOARD_SENSOR_I2C.MasterReceive(NSHT30_ADDR, data, num, false);
    IIC_WaitEvent();
}

void bh1730fvc_send_data(uint8_t *data, uint32_t num)
{
    BOARD_SENSOR_I2C.MasterTransmit(BH1730FVC_ADDR, data, num, false);
    IIC_WaitEvent();
}

void bh1730fvc_read_data(uint8_t *data, uint32_t num)
{
    BOARD_SENSOR_I2C.MasterReceive(BH1730FVC_ADDR, data, num, false);
    IIC_WaitEvent();
}

/*
    六轴和磁力计
*/
int32_t lsmd6s3tr_read(void *handle, uint8_t reg, uint8_t *bufp,
                       uint16_t len)
{
    lpspi_transfer_t masterXfer;
    memset(spi_rxbuf, 0, TRANSFER_SIZE);
    memset(spi_txbuf, 0, TRANSFER_SIZE);
    /*Start master transfer*/
    spi_txbuf[0] = reg | 0x80;
    masterXfer.txData = spi_txbuf;
    masterXfer.rxData = spi_rxbuf;
    masterXfer.dataSize = len + 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs0 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferBlocking(SENSOR_LPSPI_MASTER_BASEADDR, &masterXfer);
    memcpy(bufp, &(spi_rxbuf[1]), len);
    // PRINTF("lsmd6s3tr read ok\r\n");

    return 0;
}

int32_t lsmd6s3tr_write(void *handle, uint8_t reg, const uint8_t *bufp,
                        uint16_t len)
{
    lpspi_transfer_t masterXfer;
    memset(spi_txbuf, 0, TRANSFER_SIZE);
    spi_txbuf[0] = reg;
    memcpy(&(spi_txbuf[1]), bufp, len);
    /*Start master transfer*/
    masterXfer.txData = spi_txbuf;
    masterXfer.rxData = NULL;
    masterXfer.dataSize = len + 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs0 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferBlocking(SENSOR_LPSPI_MASTER_BASEADDR, &masterXfer);
    // PRINTF("lsmd6s3tr write ok\r\n");
    return 0;
}

int32_t lis2mdl_read(void *handle, uint8_t reg, uint8_t *bufp,
                     uint16_t len)
{
    lpspi_transfer_t masterXfer;
    memset(spi_rxbuf, 0, TRANSFER_SIZE);
    memset(spi_txbuf, 0, TRANSFER_SIZE);
    /*Start master transfer*/
    spi_txbuf[0] = reg | 0xC0;
    masterXfer.txData = spi_txbuf;
    masterXfer.rxData = spi_rxbuf;
    masterXfer.dataSize = len + 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs1 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferBlocking(SENSOR_LPSPI_MASTER_BASEADDR, &masterXfer);
    memcpy(bufp, &(spi_rxbuf[1]), len);
    // PRINTF("lis2mdl read ok\r\n");
    return 0;
}

int32_t lis2mdl_write(void *handle, uint8_t reg, const uint8_t *bufp,
                      uint16_t len)
{
    lpspi_transfer_t masterXfer;
    memset(spi_txbuf, 0, TRANSFER_SIZE);
    memset(spi_rxbuf, 0, TRANSFER_SIZE);

    spi_txbuf[0] = reg | 0x40;
    memcpy(&(spi_txbuf[1]), bufp, len);
    /*Start master transfer*/
    masterXfer.txData = spi_txbuf;
    masterXfer.rxData = NULL;
    masterXfer.dataSize = len + 1;
    masterXfer.configFlags = (uint32_t)kLPSPI_MasterPcs1 | (uint32_t)kLPSPI_MasterPcsContinuous;
    LPSPI_MasterTransferBlocking(SENSOR_LPSPI_MASTER_BASEADDR, &masterXfer);
    // PRINTF("lis2mdl write ok\r\n");
    return 0;
}

uint8_t lsm6ds3tr_init()
{
    lsm6ds3tr_ctx.write_reg = lsmd6s3tr_write;
    lsm6ds3tr_ctx.read_reg = lsmd6s3tr_read;

    /* Wait sensor boot time delay 15ms */
    SDK_DelayAtLeastUs(15 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    uint8_t whoamI, rst;
    lsm6ds3tr_c_device_id_get(&lsm6ds3tr_ctx, &whoamI);
    if (whoamI != LSM6DS3TR_C_ID)
        return 0; /*manage here device not found */

    /* Restore default configuration */
    lsm6ds3tr_c_reset_set(&lsm6ds3tr_ctx, PROPERTY_ENABLE);

    do
    {
        lsm6ds3tr_c_reset_get(&lsm6ds3tr_ctx, &rst);
    } while (rst);

    /* Enable Block Data Update */
    lsm6ds3tr_c_block_data_update_set(&lsm6ds3tr_ctx, PROPERTY_ENABLE);
    /* Set Output Data Rate */
    lsm6ds3tr_c_xl_data_rate_set(&lsm6ds3tr_ctx, LSM6DS3TR_C_XL_ODR_12Hz5);
    lsm6ds3tr_c_gy_data_rate_set(&lsm6ds3tr_ctx, LSM6DS3TR_C_GY_ODR_12Hz5);
    /* Set full scale */
    lsm6ds3tr_c_xl_full_scale_set(&lsm6ds3tr_ctx, LSM6DS3TR_C_2g);
    lsm6ds3tr_c_gy_full_scale_set(&lsm6ds3tr_ctx, LSM6DS3TR_C_2000dps);
    /* Configure filtering chain(No aux interface) */
    /* Accelerometer - analog filter */
    lsm6ds3tr_c_xl_filter_analog_set(&lsm6ds3tr_ctx,
                                     LSM6DS3TR_C_XL_ANA_BW_400Hz);
    /* Accelerometer - LPF1 path ( LPF2 not used )*/
    // lsm6ds3tr_c_xl_lp1_bandwidth_set(&dev_ctx, LSM6DS3TR_C_XL_LP1_ODR_DIV_4);
    /* Accelerometer - LPF1 + LPF2 path */
    lsm6ds3tr_c_xl_lp2_bandwidth_set(&lsm6ds3tr_ctx,
                                     LSM6DS3TR_C_XL_LOW_NOISE_LP_ODR_DIV_100);
    /* Accelerometer - High Pass / Slope path */
    // lsm6ds3tr_c_xl_reference_mode_set(&dev_ctx, PROPERTY_DISABLE);
    // lsm6ds3tr_c_xl_hp_bandwidth_set(&dev_ctx, LSM6DS3TR_C_XL_HP_ODR_DIV_100);
    /* Gyroscope - filtering chain */
    lsm6ds3tr_c_gy_band_pass_set(&lsm6ds3tr_ctx,
                                 LSM6DS3TR_C_HP_260mHz_LP1_STRONG);
    return 1;
}

uint8_t lis2mdl_init()
{
    lis2mdl_ctx.write_reg = lis2mdl_write;
    lis2mdl_ctx.read_reg = lis2mdl_read;

    uint8_t whoamI, rst;
    /* Wait sensor boot time delay 20ms */
    SDK_DelayAtLeastUs(20 * 1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    lis2mdl_spi_mode_set(&lis2mdl_ctx, LIS2MDL_SPI_4_WIRE);
    /* Check device ID */
    lis2mdl_device_id_get(&lis2mdl_ctx, &whoamI);

    if (whoamI != LIS2MDL_ID)
        return 0; /* manage here device not found */

    /* Restore default configuration */
    lis2mdl_reset_set(&lis2mdl_ctx, PROPERTY_ENABLE);
    /* Default SPI mode is 3 wire, so enable 4 wire mode */
    lis2mdl_spi_mode_set(&lis2mdl_ctx, LIS2MDL_SPI_4_WIRE);
    do
    {   
        lis2mdl_reset_get(&lis2mdl_ctx, &rst);
    } while (rst);

    
    /* Enable Block Data Update */
    lis2mdl_block_data_update_set(&lis2mdl_ctx, PROPERTY_ENABLE);
    /* Set Output Data Rate */
    lis2mdl_data_rate_set(&lis2mdl_ctx, LIS2MDL_ODR_10Hz);
    /* Set / Reset sensor mode */
    lis2mdl_set_rst_mode_set(&lis2mdl_ctx, LIS2MDL_SENS_OFF_CANC_EVERY_ODR);
    /* Enable temperature compensation */
    lis2mdl_offset_temp_comp_set(&lis2mdl_ctx, PROPERTY_ENABLE);
    /* Set device in continuous mode */
    lis2mdl_operating_mode_set(&lis2mdl_ctx, LIS2MDL_CONTINUOUS_MODE);
    return 1;
}

void lsm6ds3tr_read_data(SixaxisSensorData *data)
{
    int16_t data_raw_acceleration[3];
    int16_t data_raw_angular_rate[3];
    int16_t data_raw_temperature;
    float acceleration_mg[3];
    float angular_rate_mdps[3];
    float temperature_degC;
    lsm6ds3tr_c_reg_t reg;

    lsm6ds3tr_c_status_reg_get(&lsm6ds3tr_ctx, &reg.status_reg);
    if (reg.status_reg.xlda)
    {
        /* Read magnetic field data */
        memset(data_raw_acceleration, 0x00, 3 * sizeof(int16_t));
        lsm6ds3tr_c_acceleration_raw_get(&lsm6ds3tr_ctx,
                                         data_raw_acceleration);
        data->accelerationx = lsm6ds3tr_c_from_fs2g_to_mg(
            data_raw_acceleration[0]);
        data->accelerationy = lsm6ds3tr_c_from_fs2g_to_mg(
            data_raw_acceleration[1]);
        data->accelerationz = lsm6ds3tr_c_from_fs2g_to_mg(
            data_raw_acceleration[2]);
        // memset(tx_buffer, 0, 100);
        // sprintf((char *)tx_buffer,
        //         "Acceleration [mg]:%4.2f\t%4.2f\t%4.2f\r\n",
        //         data->accelerationx, data->accelerationy, data->accelerationz);
        // PRINTF("%s", tx_buffer);
    }

    if (reg.status_reg.gda)
    {
        /* Read magnetic field data */
        memset(data_raw_angular_rate, 0x00, 3 * sizeof(int16_t));
        lsm6ds3tr_c_angular_rate_raw_get(&lsm6ds3tr_ctx,
                                         data_raw_angular_rate);
        data->angular_ratex = lsm6ds3tr_c_from_fs2000dps_to_mdps(
            data_raw_angular_rate[0]);
        data->angular_ratey = lsm6ds3tr_c_from_fs2000dps_to_mdps(
            data_raw_angular_rate[1]);
        data->angular_ratez = lsm6ds3tr_c_from_fs2000dps_to_mdps(
            data_raw_angular_rate[2]);
        // memset(tx_buffer, 0, 100);
        // sprintf((char *)tx_buffer,
        //         "Angular rate [mdps]:%4.2f\t%4.2f\t%4.2f\r\n",
        //         data->angular_ratex, data->angular_ratey, data->angular_ratez);
        // PRINTF("%s", tx_buffer);
    }

    if (reg.status_reg.tda)
    {
        /* Read temperature data */
        memset(&data_raw_temperature, 0x00, sizeof(int16_t));
        lsm6ds3tr_c_temperature_raw_get(&lsm6ds3tr_ctx, &data_raw_temperature);
        data->temp = lsm6ds3tr_c_from_lsb_to_celsius(
            data_raw_temperature);
        memset(tx_buffer, 0, 100);
        sprintf((char *)tx_buffer, "Temperature [degC]:%6.2f\r\n",
                data->temp);
        PRINTF("%s", tx_buffer);
    }
}

void lis2mdl_read_data(MagneticSensorsData *data)
{
    uint8_t reg;
    int16_t data_raw_magnetic[3];
    int16_t data_raw_temperature;
    float magnetic_mG[3];
    float temperature_degC;

    /* Read output only if new value is available */
    lis2mdl_mag_data_ready_get(&lis2mdl_ctx, &reg);

    if (reg)
    {
        /* Read magnetic field data */
        memset(data_raw_magnetic, 0x00, 3 * sizeof(int16_t));
        lis2mdl_magnetic_raw_get(&lis2mdl_ctx, data_raw_magnetic);
        data->magneticx = lis2mdl_from_lsb_to_mgauss(data_raw_magnetic[0]);
        data->magneticy = lis2mdl_from_lsb_to_mgauss(data_raw_magnetic[1]);
        data->magneticz = lis2mdl_from_lsb_to_mgauss(data_raw_magnetic[2]);
        // memset(tx_buffer, 0, 100);
        // sprintf((char *)tx_buffer,
        //         "Magnetic field [mG]:%4.2f\t%4.2f\t%4.2f\r\n",
        //         data->magneticx, data->magneticy, data->magneticz);
        // PRINTF("%s", tx_buffer);
        /* Read temperature data */
        memset(&data_raw_temperature, 0x00, sizeof(int16_t));
        lis2mdl_temperature_raw_get(&lis2mdl_ctx, &data_raw_temperature);
        data->temp = lis2mdl_from_lsb_to_celsius(data_raw_temperature);
        memset(tx_buffer, 0, 100);
        sprintf((char *)tx_buffer, "Temperature [degC]:%6.2f\r\n",
                data->temp);
        PRINTF("%s", tx_buffer);
    }
}
