#include "stm32f4_I2C1_sensors.h"

#define I2C1_SENSORS_TEST


#ifdef I2C1_SENSORS_TEST
#include "stm32f4_custom_USART.h"
#endif


/**************************************************************************
 * Sensors initialization functions
 **************************************************************************/

/**
  * @brief   Initialize ITG3200 gyro.
  * @retval  Operation status:
  *           - 1: if there was no error during sensor initialization 
  *              operation;
  *           - 0: if an error occured.
  */
 
extern I2C_HandleTypeDef I2CHandle;
 
  
uint8_t ITG3200_Init()
{
    /* Sample Rate DIV register (21):
     * - internal sample time at 500 Hz. 
     */
    uint8_t RegConf = 1;
	if(HAL_I2C_Mem_Write(&I2CHandle, ITG3200_ADDRESS << 1, 21, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
	
    
    /* DLPF - Full Scale register (22):
     * - low-pass filter 188Hz;
     * - ADC sampling at 1kHz;
     * - FS_SEL = 3 (+/- 2000 deg/s, full range). 
     */
    RegConf = 25;
	if(HAL_I2C_Mem_Write(&I2CHandle, ITG3200_ADDRESS << 1, 22, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    return 1;
}

/**
  * @brief   Initialize ADXL345 accelerometer.
  * @retval  Operation status:
  *           - 1: if there was no error during sensor initialization 
  *              operation;
  *           - 0: if an error occured.
  */
uint8_t ADXL345_Init()
{
    /* Set BW_RATE register (0x2C):
     * - D7|D6|D5 = 000
     * - D4 -> LOW_POWER = 0 (normal power mode)
     * - D3|D2|D1|D0 -> Rate = 1011 (output data rate 200 Hz, bandwidth 100 Hz) 
     */
    uint8_t RegConf = 11;
	if(HAL_I2C_Mem_Write(&I2CHandle, ADXL345_ADDRESS << 1, 0x2C, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    /* Set DATA_FORMAT register (0x31):
     * - D7 -> SELF_TEST bit = 0 (no self test)
     * - D6 -> SPI bit = 0 (4-wire SPI mode)
     * - D5 -> INT_INVERT bit = 0 (interrupt active high)
     * - D4 = 0
     * - D3-> FULL_RES bit = 1 (full resolution)
     * - D2 -> Justify bit = 0 (right justified mode with sign extension)
     * - D1|D0 -> Range bits = 01 (+/- 4g) 
     */
    RegConf = 9;
	if(HAL_I2C_Mem_Write(&I2CHandle, ADXL345_ADDRESS << 1, 0x31, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    /* Set FIFO_CTL register (0x38):
     * D7|D6 -> FIFO_MODE bit = 10 (stream mode)
     * D5 -> Trigger bit = 0
     * D4|D3|D2|D1|D0 -> Samples bits = 00000 (samples bit watermark int) 
     */ 
    RegConf = 128;
	if(HAL_I2C_Mem_Write(&I2CHandle, ADXL345_ADDRESS << 1, 0x38, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    /* Set POWER_CTL register (0x2D):
     * - D7|D6 = 00
     * - D5 -> Link bit = 0 (no link)
     * - D4 -> AUTO_SLEEP bit = 0 (no auto sleep)
     * - D3 -> Measure bit = 1 (measurement mode)
     * - D2 -> Sleep = 0 (normal mode of operation)
     * - D1|D0 -> Wakeup = 00 (reading frequency in sleep mode) 
     */
    RegConf = 8;
	if(HAL_I2C_Mem_Write(&I2CHandle, ADXL345_ADDRESS << 1, 0x2D, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    return 1;
}

/**
  * @brief   Initialize HMC5883L magnetometer.
  * @retval  Operation status:
  *           - 1: if there was no error during sensor initialization 
  *              operation;
  *           - 0: if an error occured.
  */
uint8_t HMC5883L_Init()
{
    /* Set Configuration Register A (0):
     * - 75 Hz data output rate
     * - normal measurement configuration
     * - 8 samples averaged 
     */
    uint8_t RegConf = 120;
	if(HAL_I2C_Mem_Write(&I2CHandle, HMC5883L_ADDRESS << 1, 0, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    /* Set Mode Register (2):
     * - continuous measurement mode 
     */
    RegConf = 0;
	if(HAL_I2C_Mem_Write(&I2CHandle, HMC5883L_ADDRESS << 1, 2, I2C_MEMADD_SIZE_8BIT, &RegConf,  1, 1))
        return 0;
    
    return 1;
}

/**
  * @brief   Read BMP085 calibration parameters.
  * @retval  Operation status:
  *           - 1: if there was no error during sensor initialization 
  *              operation;
  *           - 0: if an error occured.
  */
uint8_t BMP085_Init(uint8_t* CalibPar)
{
    /* Read calibration parameters: 22 bytes starting from register 170 */
	return !HAL_I2C_Mem_Read(&I2CHandle, BMP085_ADDRESS << 1, 170, I2C_MEMADD_SIZE_8BIT, CalibPar, 22, 1);
}


/**
  * @brief   Initialize MPU9150 accelerometer/temperature/gyroscope.
  * @retval  Operation status:
  *           - 1: if there was no error during sensor initialization 
  *              operation;
  *           - 0: if an error occured.
  */

  /*Initialization inherited from ICAROII, initialization from Arduino Library */
uint8_t MPU9150_Init()
{
  uint8_t RegConf = (MPU6050_CLOCK_PLL_XGYRO+4)*16;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1, MPU6050_RA_PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  RegConf = 0x02;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1, MPU6050_RA_INT_PIN_CFG, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  RegConf = MPU6050_CLOCK_PLL_XGYRO;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1,MPU6050_RA_PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  RegConf = MPU6050_GYRO_FS_250*8;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1,MPU6050_RA_GYRO_CONFIG, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  RegConf = MPU6050_ACCEL_FS_4*8;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1,MPU6050_RA_ACCEL_CONFIG, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  RegConf = MPU6050_DLPF_BW_98;

  if(HAL_I2C_Mem_Write(&I2CHandle, MPU9150_ADDRESS << 1,MPU6050_RA_CONFIG, I2C_MEMADD_SIZE_8BIT, &RegConf, 2, 1))
        return 0;

  return 1;
}


/**************************************************************************
 * Sensor reading operation
 **************************************************************************/

/* Current sensor processed */
uint8_t I2C1_ProcSensor;

/* Measurement buffers */
uint8_t ITG3200_Buffer[ITG3200_BYTES];
uint8_t ADXL345_Buffer[ADXL345_BYTES];
uint8_t HMC5883L_Buffer[HMC5883L_BYTES];
uint8_t BMP085_TempBuffer[BMP085_TEMP_BYTES];
uint8_t BMP085_PressBuffer[BMP085_PRESS_BYTES];
uint8_t MPU9150_Buffer[MPU9150_BYTES];


/* Sensor prescalers */
uint8_t HMC5883L_Prescaler;
uint8_t BMP085_Prescaler;

/* BMP085 oversampling setting, command buffer and command sent flag */ 
uint8_t BMP085_oss;
static uint8_t BMP085_Command;
uint8_t BMP085_CommandSent;

/* I2C1 sensor state */
uint8_t I2C1_SensorEnabled[I2C1_SENSORS_NUMBER];
extern uint8_t I2C1_HAL_Err_Status;

/* I2C1 measurements flag */
uint16_t I2C1_MeasFlag;


/**
  * @brief  I2C1 sensor reading.
  * @note   Read I2C1_ProcSensor if enabled or its prescaler timed out.
  *         Otherwise read the next enabled sensor with prescaler timed out.
  * @note   Use return statement at the end of sensor operation!
  * @retval None.
  */
void I2C1_ReadSensor()
{           
#ifdef I2C1_SENSORS_TEST
    static uint8_t app = 0xFF;
    USART3_Receive(&app);
#endif
    /* While used to go to the next sensor if current one cannot be read */
    while(I2C1_ProcSensor < I2C1_SENSORS_NUMBER)
    {
        if(!I2C1_SensorEnabled[I2C1_ProcSensor])
        {
            /* Go to next enabled sensor */
            I2C1_ProcSensor++;
            continue;
        }
        
        switch(I2C1_ProcSensor)
        {
            case ITG3200_ID:
                
                /* Read gyro measurement */
                I2C1_MeasFlag |= I2C1_GYRO_MEAS;
                
#ifdef I2C1_SENSORS_TEST
                //USART3_Send(0x0D);
               //USART3_Send('i');
                if(app=='0')
				{
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, 'X', ITG3200_DATA_REG, I2C_MEMADD_SIZE_8BIT, ITG3200_Buffer, ITG3200_BYTES); 
				}
                else
#endif              
				I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, ITG3200_ADDRESS << 1, ITG3200_DATA_REG, I2C_MEMADD_SIZE_8BIT, ITG3200_Buffer, ITG3200_BYTES);
                
                return;
                
            case ADXL345_ID:
                
                /* Read accelerometer measurement */
                I2C1_MeasFlag |= I2C1_ACC_MEAS;
                
#ifdef I2C1_SENSORS_TEST
                //USART3_Send(0x0D);
                //USART3_Send('a');
                if(app=='1')
				{
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, 'X', ADXL345_DATA_REG, I2C_MEMADD_SIZE_8BIT, ADXL345_Buffer, ADXL345_BYTES);
				}
                else
#endif
				I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, ADXL345_ADDRESS << 1, ADXL345_DATA_REG, I2C_MEMADD_SIZE_8BIT, ADXL345_Buffer, ADXL345_BYTES);

                return;

            case HMC5883L_ID:
                
                /* Update magnetometer prescaler */
                HMC5883L_Prescaler++;
                
                if(HMC5883L_Prescaler == 5)
                {
                    /* Read magnetometer measurement */
                    I2C1_MeasFlag |= I2C1_MAG_MEAS;
                    
#ifdef I2C1_SENSORS_TEST
                    //USART3_Send(0x0D);
                    //USART3_Send('h');
                    if(app=='2')
					{
						I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, 'X', HMC5883L_DATA_REG, I2C_MEMADD_SIZE_8BIT,  HMC5883L_Buffer, HMC5883L_BYTES);
					}
                    else
#endif
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, HMC5883L_ADDRESS << 1, HMC5883L_DATA_REG, I2C_MEMADD_SIZE_8BIT,  HMC5883L_Buffer, HMC5883L_BYTES);
                    
                    HMC5883L_Prescaler = 0;
                    return;
                }
                else
                {
                    /* Go to the next sensor */
                    I2C1_ProcSensor++;
                    continue;
                }

            case BMP085_ID:
                
                /* Update preassure sensor prescaler */
                BMP085_Prescaler++;
                
                if(BMP085_Prescaler == 1)
                {
                    /* Send temperature conversion command */
                    BMP085_CommandSent = 0;
                    BMP085_Command = 0x2E;
                    
#ifdef I2C1_SENSORS_TEST
                    //USART3_Send(0x0D);
                    //USART3_Send('B');
                    if(app=='3')
					{
						I2C1_HAL_Err_Status = HAL_I2C_Mem_Write_IT(&I2CHandle, 'X', BMP085_COMM_REG, I2C_MEMADD_SIZE_8BIT, &BMP085_Command, 1);
					}
                    else
#endif
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Write_IT(&I2CHandle,  BMP085_ADDRESS << 1, BMP085_COMM_REG, I2C_MEMADD_SIZE_8BIT, &BMP085_Command, 1);
                    
                    return;
                }
                else if(BMP085_Prescaler == 5 && BMP085_CommandSent)
                {
                    /* Temperature reading if command sent successfully */
                    I2C1_MeasFlag |= I2C1_TEMP_MEAS;
                    
#ifdef I2C1_SENSORS_TEST
                    //USART3_Send(0x0D);
                    //USART3_Send('b');
                    if(app=='3')
					{
						I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle,  'X', BMP085_DATA_REG, I2C_MEMADD_SIZE_8BIT, BMP085_TempBuffer, BMP085_TEMP_BYTES);
					}
                    else
#endif
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle,  BMP085_ADDRESS << 1, BMP085_DATA_REG, I2C_MEMADD_SIZE_8BIT, BMP085_TempBuffer, BMP085_TEMP_BYTES);
                    
                    return;
                }
                else if(BMP085_Prescaler == 6)
                {
                    /* Send preassure conversion command */
                    BMP085_CommandSent = 0;
                    BMP085_Command = 52 + 64*BMP085_oss;
                    
#ifdef I2C1_SENSORS_TEST
                    //USART3_Send(0x0D);
                    //USART3_Send('B');
                    if(app=='3')
					{
						I2C1_HAL_Err_Status = HAL_I2C_Mem_Write_IT(&I2CHandle,  'X', BMP085_COMM_REG, I2C_MEMADD_SIZE_8BIT, &BMP085_Command, 1);
					}
                    else
#endif
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Write_IT(&I2CHandle,  BMP085_ADDRESS << 1, BMP085_COMM_REG, I2C_MEMADD_SIZE_8BIT, &BMP085_Command, 1);
                    
                    return;
                }
                else if(BMP085_Prescaler == 24 && BMP085_CommandSent)
                {
                    /* Preassure reading if command sent successfully */
                    I2C1_MeasFlag |= I2C1_PRES_MEAS;
                    
#ifdef I2C1_SENSORS_TEST
                    //USART3_Send(0x0D);
                    //USART3_Send('b');
                    if(app=='3')
					{
						I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle,  'X', BMP085_DATA_REG, I2C_MEMADD_SIZE_8BIT,BMP085_PressBuffer,BMP085_PRESS_BYTES);
					}
                    else
#endif
					I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle,  BMP085_ADDRESS << 1, BMP085_DATA_REG, I2C_MEMADD_SIZE_8BIT, BMP085_PressBuffer, BMP085_PRESS_BYTES);
                    
                    return;
                }
                else if(BMP085_Prescaler == 25)
                {
                    /* Reset BMP085 prescaler and go to next sensor */
                    BMP085_Prescaler = 0;
                    I2C1_ProcSensor++;
                    continue;
                }
                else
                {
                    /* Go to the next sensor */
                    I2C1_ProcSensor++;
                    continue;
                }

            case MPU9150_ID:
                
                /* Read gyro measurement */
                I2C1_MeasFlag |= I2C1_MPU_MEAS;
                
#ifdef I2C1_SENSORS_TEST
                //USART3_Send(0x0D);
                //USART3_Send('m');
                if(app=='4')
        {
          I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, 'X', MPU9150_DATA_REG, I2C_MEMADD_SIZE_8BIT, MPU9150_Buffer, MPU9150_BYTES); 
        }
                else
#endif              
        I2C1_HAL_Err_Status = HAL_I2C_Mem_Read_IT(&I2CHandle, MPU9150_ADDRESS << 1, MPU9150_DATA_REG, I2C_MEMADD_SIZE_8BIT, MPU9150_Buffer, MPU9150_BYTES);
                
                return;

        } // Switch end
    } // While end 
}

