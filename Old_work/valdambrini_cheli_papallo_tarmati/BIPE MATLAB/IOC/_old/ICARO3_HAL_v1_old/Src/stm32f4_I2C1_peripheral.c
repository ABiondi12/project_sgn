/* HAL I2C1 PERIPHERAL */

#include "stm32f4_I2C1_peripheral.h"


//#define I2C1_SENSORS_TEST


#ifdef I2C1_SENSORS_TEST
#include "stm32f4_custom_USART.h"
#endif

/**************************************************************************
 * I2C1 Reset and Initialization functions
 **************************************************************************/

// I2C handler declaration
I2C_HandleTypeDef I2CHandle;

/**
  * @brief  I2C1 peripheral initialization.
  * @retval None.
  * @note   GPIO_config Simulink block does not initialize correctly I2C
  *         peripherals (for example it is not possible to enable or not
  *         Pull-Up resistors).  
  */
void I2C1_Init()
{    
    
    // Structs for initialization
    GPIO_InitTypeDef GPIO_InitStruct;

    
    // Enable APB1 peripheral clock for I2C1
	__HAL_RCC_I2C1_CLK_ENABLE();
 
    // Enable the peripheral clock for pins PB6 and PB9 used by I2C1
    // (respectively SCL and SDA)
	__GPIOB_CLK_ENABLE();
 
    /* Set up pins PB6 (SCL) and PB9 (SDA) 
     * 1) PIN number
     * 2) Alternate Function mode (connect to I2C1 peripheral)
     * 3) GPIO speed (nothing to do with I2C1 rate)
     * 4) Output type as open drain
     * 5) No Pull-Up or Pull-Down resistor */
    GPIO_InitStruct.Pin 		= GPIO_PIN_6 | GPIO_PIN_9;
	  GPIO_InitStruct.Mode 		= GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_PULLUP;
	  GPIO_InitStruct.Alternate 	= GPIO_AF4_I2C1;
	
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
    // Set the I2C1 structure parameters
	I2CHandle.Instance             = I2C1;
	I2CHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	I2CHandle.Init.ClockSpeed      = I2C1_SPEED;
	I2CHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2CHandle.Init.DutyCycle       = I2C1_DUTY_CYCLE;
	I2CHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2CHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
	I2CHandle.Init.OwnAddress1     = 0xAA;
	I2CHandle.Init.OwnAddress2     = I2C_STM32F4_ADDRESS;
	
	HAL_I2C_Init(&I2CHandle);

	
    // Enable I2C1 Event and Error Interrupts on NVIC
	HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
	
	HAL_NVIC_SetPriority(I2C1_ER_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
		
    // Enable I2C1 peripheral
    //OLD: 
	//I2C1->CR1 |= I2C_CR1_PE;
	//New
	//__HAL_I2C_ENABLE();
}


/**
  * @brief  I2C1 peripheral reset.
  * @note   Based on I2C_DeInit() (file stm32f4xx_i2c.c).
  * @note   Peripheral disable clears error flags.
  * @retval None.
  */
void I2C1_Reset()
{    
#ifdef I2C1_SENSORS_TEST
    USART3_Send('R');
#endif

    // Close on-going communication
    //OLD:
	I2C1->CR1 |= I2C_CR1_STOP;
	
    // Disable I2C1 peripheral (clear error flags)
    //OLD: 
	HAL_I2C_DeInit(&I2CHandle);
	//NEW
    //__HAL_I2C_DISABLE();
	
	
    /* Deinitialize I2C1 peripheral register to their default reset values
     * (see HAL_I2C_DeInit(), file stm32f4xx_hal_i2c.c): first enable I2C1 reset 
     * state, and then release I2C1 from that state */
  __HAL_RCC_I2C1_CLK_DISABLE();
	__HAL_RCC_I2C1_CLK_ENABLE();
    
  // Initialize again I2C1
	HAL_I2C_Init(&I2CHandle);
    
}


/**************************************************************************
 * I2C1 Reading and writing: polling
 **************************************************************************/

// I2C1 error flag
static uint8_t I2C1_ErrorFlag;

/**
  * @brief  I2C1 Error Interrupt handler.
  * @note   Set the I2C1 error flag and reset the peripheral
  * @retval None.
  */
void I2C1_ER_IRQHandler() 
{
    I2C1_ErrorFlag = 1;
    I2C1_Reset();
}

/**
  * @brief  I2C1 Event Interrupt handler.
  * @note   Handle with the interrupts generated from specific events.
  * @retval None.
  */
void I2C1_EV_IRQHandler()
{
    HAL_I2C_EV_IRQHandler(&I2CHandle);
}

/**
  * @brief  Master Tx Transfer completed callbacks.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @retval None
  */
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
    I2C1_ProcSensor++;
    I2C1_ReadSensor();
}

/**
  * @brief  Master Rx Transfer completed callbacks.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @retval None
  */
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
    I2C1_ProcSensor++;
    I2C1_ReadSensor();
}
