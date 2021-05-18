/* HAL I2C1 PERIPHERAL */

#include "stm32f4_I2C1_peripheral.h"


//#define I2C1_SENSORS_TEST


#ifdef I2C1_SENSORS_TEST
#include "stm32f4_custom_USART.h"
#endif

#define TINY_DELAY(DC) for (volatile int delay_counter=0; delay_counter<DC; ) {delay_counter++;}


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
	HAL_NVIC_SetPriority(I2C1_EV_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
	
	HAL_NVIC_SetPriority(I2C1_ER_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
		
    // Enable I2C1 peripheral
    //OLD: 
	//I2C1->CR1 |= I2C_CR1_PE;
	//New
	//__HAL_I2C_ENABLE();
}


unsigned int I2C1_ResetCount = 0;
unsigned int I2C1_ResetCount_SDA_LOW = 0;
unsigned int I2C1_ResetCount_SCL_LOW = 0;
unsigned int I2C1_ResetCount_SDA_SCL_LOW = 0;


/**
  * @brief  I2C1 peripheral reset.
  * @note   Based on I2C_DeInit() (file stm32f4xx_i2c.c).
  * @note   Peripheral disable clears error flags.
  * @retval None.
  */
void I2C1_Reset()
{    
	//notify that a fault has happened via the blu led
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_RESET);
	
	//stats for activation
	I2C1_ResetCount++;
	unsigned char is_SDA_LOW = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	unsigned char is_SCL_LOW = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
	if (is_SDA_LOW) I2C1_ResetCount_SDA_LOW++;
	if (is_SCL_LOW) I2C1_ResetCount_SCL_LOW++;
	if ((is_SDA_LOW) && (is_SCL_LOW)) I2C1_ResetCount_SDA_SCL_LOW++;
	
	
#ifdef I2C1_SENSORS_TEST
    USART3_Send('R');
#endif

		//chcek if stm32 i2c master is ok or if it's a peripheral problem:
		//	if SDA pin == 1 => it's a master problem => reset master 
		//	if SDA pin == 0 => it's a slave problem => apply AN686 solution 1 AND reset master
		//
		//  REF: http://www.analog.com/media/en/technical-documentation/application-notes/54305147357414AN686_0.pdf
		//
		
		//send a stop just in case it works
		I2C1->CR1 |= I2C_CR1_STOP;
		// Disable I2C1 peripheral (clear error flags)
		HAL_I2C_DeInit(&I2CHandle);
		__HAL_RCC_I2C1_CLK_DISABLE();

		//end of disable I2c
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_SET);


#define ENABLE_AN686_RECOVERY 1	
	
		//check SDA state : MOD do not check SDA sttae, always perform the AN868 recovery procedure
		if ( ( (1) || (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_RESET) ) && (ENABLE_AN686_RECOVERY) ){
				//SDA line is low, this should be kept low by a faulty peripheral 
				// try to let peripheral terminate its read or wrire cycle by follwoing 
				// the AN686 solution
			
				
				//
				// 		now apply AN686 
				//
				/**
				 * This procedure tries to recover the BUS state from a previous disaster situation
				 * in which after a reset the SLAVE is hanging in an inconsistent state, e.g. it holds
				 * te SDA line at zero value:
				 *
				 * The procedure generates up to 9 additional clock cycles as a worst case scenario
				 * to allow the SLAVE sending it ACK/NACK and then generates a virtual STOP condition.
				 *
				 * The procedure is as follows:
				 * 1. SDA is set to logic state 1
				 * 2. SCK is set to 1
				 * 3. If SDA value is zero ak 1-0-1 clock transition is generated.
				 * 4. If SDA is still 0 we go to point 3 up to 9 times
				 * 5. We generate finally a stop condition
				 *
				 * The procedure is expected to be called before I2C init.
				 */
				// Configure pins for SDA and SCL as digital ouput with open drain output 
				// Structs for initialization
				GPIO_InitTypeDef GPIO_InitStruct;
				GPIO_InitStruct.Pin 		= GPIO_PIN_6 | GPIO_PIN_9;
				GPIO_InitStruct.Mode 		= GPIO_MODE_OUTPUT_OD;
				GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
				GPIO_InitStruct.Pull 		= GPIO_PULLUP;
				//GPIO_InitStruct.Alternate 	= GPIO_AF4_I2C1;
				HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
				//
				// ensure both outputs are set 
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); 
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
				TINY_DELAY(100);
				//	
				//end of new port configuration
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_RESET);


				// Perform 10 Loop cycles on SCL1 to finish uncompleted
				// Transfer and emulate a stop condition. This recover
				// Device frozen on the bus
				for (int i =0; i<10; i++) {
					//if SDA is reset	
					if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_RESET) {
							//reset SCL
							HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
							TINY_DELAY(100);
							//set SCL
							HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
							TINY_DELAY(100);
						}
						else break;
				}
				//end of false clock generation
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_SET);

				
				//clock down
				//data down (NOT START)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
				TINY_DELAY(200);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);;
				TINY_DELAY(200);

				//clock up
				//data up (BUT STOP)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
				TINY_DELAY(200);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);;
				TINY_DELAY(200);

				//put back PIN in AF mode
				// Configure pins for SDA and SCL as digital ouput with open drain output 
				// Structs for initialization
				GPIO_InitStruct.Mode 		= GPIO_MODE_AF_OD;
				GPIO_InitStruct.Alternate 	= GPIO_AF4_I2C1;
				HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

				//end false stop generation
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_RESET);

		}
		//reactivate i2c
		__HAL_RCC_I2C1_CLK_ENABLE();
		// Initialize again I2C1
		HAL_I2C_Init(&I2CHandle);
    
		//end of resest procedure
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,GPIO_PIN_SET);

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
  HAL_I2C_ER_IRQHandler(&I2CHandle);  
	//OLD : now the reset call in in the callback 
	//I2C1_ErrorFlag = 1;
  //I2C1_Reset();
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

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	I2C1_ErrorFlag = 1;
  I2C1_Reset();
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
	  //generate a tiny delay before startying new sensor
		for (volatile int delay_counter=0; delay_counter<100; ) {
			delay_counter++;
		}
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
		//generate a tiny delay before startying new sensor
		for (volatile int delay_counter=0; delay_counter<100; ) {
			delay_counter++;
		}
    I2C1_ReadSensor();
}









