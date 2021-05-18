#ifndef __STM32F4_I2C1_SENSORS_H__
#define __STM32F4_I2C1_SENSORS_H__

#include "stm32f4_I2C1_peripheral.h"


   
/* Sensors ****************************************************************/


#define I2C1_SENSORS_NUMBER 5


#define ITG3200_ID          0
#define ITG3200_ADDRESS     0x68
#define ITG3200_DATA_REG    29
#define ITG3200_BYTES       6

#define ADXL345_ID          1
#define ADXL345_ADDRESS     0x53
#define ADXL345_DATA_REG    0x32
#define ADXL345_BYTES       6

#define HMC5883L_ID         2
#define HMC5883L_ADDRESS    0x1E
#define HMC5883L_DATA_REG   3
#define HMC5883L_BYTES      6

#define BMP085_ID           3
#define BMP085_ADDRESS      0x77
#define BMP085_DATA_REG     0xF6
#define BMP085_PRESS_BYTES  3
#define BMP085_TEMP_BYTES   2
#define BMP085_COMM_REG     0xF4


#define MPU9150_ID          4
#define MPU9150_ADDRESS     0x69
#define MPU9150_DATA_REG    59
#define MPU9150_BYTES       14 //ACC+TEMP+GYRO (6+2+6)





/* MPU defines */
/* Peripheral Registers    */

#define MPU6050_RA_PWR_MGMT_1       0x6B
#define MPU6050_RA_INT_PIN_CFG      0x37
#define MPU6050_RA_GYRO_CONFIG      0x1B
#define MPU6050_RA_ACCEL_CONFIG     0x1C
#define MPU6050_RA_CONFIG           0x1A

/* Values to write for initialization */

#define MPU6050_CLOCK_PLL_XGYRO         0x01
#define MPU6050_GYRO_FS_250             0x00
#define MPU6050_ACCEL_FS_4              0x01
#define MPU6050_DLPF_BW_98              0x02



/* Sensor measurement buffers *********************************************/
extern uint8_t ITG3200_Buffer[ITG3200_BYTES];
extern uint8_t ADXL345_Buffer[ADXL345_BYTES];
extern uint8_t HMC5883L_Buffer[HMC5883L_BYTES];
extern uint8_t BMP085_TempBuffer[BMP085_TEMP_BYTES];
extern uint8_t BMP085_PressBuffer[BMP085_PRESS_BYTES];
extern uint8_t MPU9150_Buffer[MPU9150_BYTES];


/* Sensor initialization functions ****************************************/
uint8_t ITG3200_Init(void);
uint8_t ADXL345_Init(void);
uint8_t HMC5883L_Init(void);
uint8_t BMP085_Init(uint8_t* CalibPar);
uint8_t MPU9150_Init(void);




/* Sensor prescalers ******************************************************/
extern uint8_t HMC5883L_Prescaler;
extern uint8_t BMP085_Prescaler;

/* BMP085 oversampling setting & command sent flag ************************/
extern uint8_t BMP085_oss;
extern uint8_t BMP085_CommandSent;

/* I2C1 sensor state ******************************************************/
extern uint8_t I2C1_SensorEnabled[I2C1_SENSORS_NUMBER];

/* I2C1 processed sensor **************************************************/
extern uint8_t I2C1_ProcSensor;

/* I2C1 measurements flag *************************************************/
#define I2C1_TEMP_MEAS  0x0001      // 0000 0000 0000 0001
#define I2C1_PRES_MEAS  0x0002      // 0000 0000 0000 0010 
#define I2C1_GYRO_MEAS  0x0004      // 0000 0000 0000 0100
#define I2C1_ACC_MEAS   0x0008      // 0000 0000 0000 1000
#define I2C1_MAG_MEAS   0x0010      // 0000 0000 0001 0000
#define I2C1_MPU_MEAS   0x0020      // 0000 0000 0010 0000


extern uint16_t I2C1_MeasFlag;

/* I2C1 sensors reading operation *****************************************/
void I2C1_ReadSensor(void);

/* Error management *******************************************************/

#define MAX_ERROR_NUMBER 50

//#define I2C1_ERROR_CAN_LIKE_MANAGEMENT 
#ifdef I2C1_ERROR_CAN_LIKE_MANAGEMENT

#define I2C_CAN_PR_THR  10
static uint8_t I2C1_CANPrescaler[I2C1_SENSORS_NUMBER];

#endif

#endif
