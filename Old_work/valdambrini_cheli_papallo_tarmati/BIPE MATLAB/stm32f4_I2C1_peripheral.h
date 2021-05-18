#ifndef __STM32F4_I2C1_PERIPHERAL_H__
#define __STM32F4_I2C1_PERIPHERAL_H__

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

#include "stm32f4_I2C1_sensors.h"

/* I2C1 peripheral setup **************************************************/
#define I2C_STM32F4_ADDRESS (uint8_t)0xA0

#define I2C1_FAST_MODE
#ifdef I2C1_FAST_MODE

/* Fast mode, 400 kHz */
#define I2C1_SPEED      400000
//#define I2C1_DUTY_CYCLE I2C_DUTYCYCLE_16_9  
#define I2C1_DUTY_CYCLE  I2C_DUTYCYCLE_2

#else 

/* Standard mode, 100 kHz */
#define I2C1_SPEED       100000
#define I2C1_DUTY_CYCLE  I2C_DUTYCYCLE_2

#endif

/* I2C1 Event and Error Interrupt handlers ********************************/
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c);

/* I2C1 initialization and reset functions ********************************/
void I2C1_Init(void);
void I2C1_Reset(void);

#endif
