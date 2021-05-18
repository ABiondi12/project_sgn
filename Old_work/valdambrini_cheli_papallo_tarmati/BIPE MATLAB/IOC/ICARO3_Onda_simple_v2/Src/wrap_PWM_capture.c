/*-------------- wrap_PWM_capture.c --------------*/
/* Senses the PWM on two different DIO: one for throttle, one for steering
 * It is meant to work on a car, so may be incopatible with the similar
 * PPM_capture, for UAVs. */

/* Includes ------------------------------------------------------------------*/
//#define DEBUG


#ifdef DEBUG
    #include "stm32f4_custom_USART.h"
    #include "circular_buffer.h"
#endif

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "rtwtypes.h"

/* Definition for TIMx clock resources */
#define TIMx                           TIM3
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()

/* Definition for TIMx Pins */
#define TIMx_CHANNEL_GPIO_PORT()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define GPIO_PORT                      GPIOA
#define GPIO_PIN_CHANNEL2              GPIO_PIN_7   //PA7

#define GPIO_AF_TIMx                   GPIO_AF2_TIM3

#define GPIO_PORTB                     GPIOB
#define GPIO_PIN_CHANNEL4              GPIO_PIN_1	//PB1
#define TIMx_CHANNEL_GPIO_PORTB()      __HAL_RCC_GPIOB_CLK_ENABLE()
/* Definition for TIMx's NVIC */
#define TIMx_IRQn                      TIM3_IRQn
#define TIMx_IRQHandler                TIM3_IRQHandler

/* Private Definitions */
//#define TIMES_TO_CAPTURE               9
//#define SYNC_THRESHOLD                 8000
#define PRESCALER                        90

/* Function prototypes*/
extern void Error_Handler(void); //From USART CUSTOM
void TIM_IC_Config(void);

/* Notes on how to choose prescaler.

	TIM3 is connected to APB1 bus, which has on F407 device 42MHz clock.                 
    But timer has internal PLL, which double this frequency for timer, up to 84MHz     
    Remember: Not each timer is connected to APB1, there are also timers connected     
    on APB2, which works at 84MHz by default, and internal PLL increase                 
    this to up to 168MHz.   
	
    In our case the minimum frequency we want to measure is the one related with the sync duration, which is equal to 4ms, so:
	minimum frequency= 1/0.004 = 250 Hz (we set it down to 200 Hz to be precautionary)
	All the other square waves related to the radio signals have higher frequencies.
	
	First you have to know max value for timer. In our case it is 16bit = 65535.
	In general the minimum frequency value to measure is given by:
	(TIM4 counter clock / CCR MAX)
	= (168MHz/2)/ 65535
	= 1282 Hz
	So we have to decrease that value setting the right prescaler.
	
	The TIM3CLK frequency (when prescaler=0) is set to (SystemCoreClock/4) x 2 (Hz). In general it is given by:
	
    timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)  
	
	Timer period is set with:
	
	TIM_Period = timer_tick_frequency / PWM_frequency - 1
	
	If you get TIM_Period larger than max timer value (in our case 65535 (=CCR_MAX)),
    you have to choose larger prescaler and slow down timer tick frequency.
	
	By calculation the right prescaler in our case is > 5.5 -->6.
*/

/* Timer handler declaration */
TIM_HandleTypeDef        TimHandle;

/* Timer Input Capture Configuration Structure declaration */
TIM_IC_InitTypeDef       sConfig;

/* Slave configuration structure */
TIM_SlaveConfigTypeDef   sSlaveConfig;

/* Captured Value */
__IO uint32_t            uwIC2Value[2] = {0};
/* Captured Value */
__IO uint32_t            uwIC1Value[2] = {0};
/* Duty Cycle Value */
__IO uint32_t            uwDutyCycle[2] = {0};
/* Time On Value */
__IO uint32_t            uwTimeOn[2] = {0};
/* Frequency Value */
__IO uint32_t            uwFrequency[2] = {0};

void wrap_PWM_start_fcn(void)
{
    TIM_IC_Config();
    
    /*##-1- Configure the TIM peripheral #######################################*/ 
    /* Set TIMx instance */
    TimHandle.Instance = TIMx;

    /* Initialize TIMx peripheral as follow:
       + Period = 0xFFFF
       + Prescaler = 0
       + ClockDivision = 0
       + Counter direction = Up
    */
    TimHandle.Init.Period = 0xFFFF;
    TimHandle.Init.Prescaler = PRESCALER;
    TimHandle.Init.ClockDivision = 0;
    TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
     
     if(HAL_TIM_IC_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  
  /*##-2- Configure the Input Capture channels ###############################*/ 
  /* Common configuration */
  sConfig.ICPrescaler = TIM_ICPSC_DIV1;
  sConfig.ICFilter = 0;  
  
  /* Configure the Input Capture of channel 1 on falling edge of signal */
  sConfig.ICPolarity = TIM_ICPOLARITY_FALLING;
  sConfig.ICSelection = TIM_ICSELECTION_INDIRECTTI;    
  if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }
  
  /* Configure the Input Capture of channel 2 on rising edge of signal */
  sConfig.ICPolarity = TIM_ICPOLARITY_RISING;
  sConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
  if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_2) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }
 
  /* Configure the Input Capture of channel 3 on falling edge of signal */
  sConfig.ICPolarity = TIM_ICPOLARITY_FALLING;
  sConfig.ICSelection = TIM_ICSELECTION_INDIRECTTI;    
  if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_3) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }
  
  /* Configure the Input Capture of channel 4 on rising edge of signal */
  sConfig.ICPolarity = TIM_ICPOLARITY_RISING;
  sConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
  if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_4) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }
	

  /*##-3- Configure the slave mode ###########################################*/
  /* Select the slave Mode: Reset Mode */
  sSlaveConfig.SlaveMode     = TIM_SLAVEMODE_RESET;
  sSlaveConfig.InputTrigger  = TIM_TS_TI2FP2;
  if(HAL_TIM_SlaveConfigSynchronization(&TimHandle, &sSlaveConfig) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }
  
  /*##-4- Start the Input Capture in interrupt mode ##########################*/
  if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_4) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
  
  if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_3) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
	
	if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_2) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
  
  /*##-5- Start the Input Capture in interrupt mode ##########################*/
  if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_1) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
	}
}

void wrap_PWM_output_fcn(uint16_t *pwmDuty, uint16_t *pwmTOn, uint16_t *pwmFreq, uint8_t *ErrCnt)
{
    pwmDuty[0] = uwDutyCycle[0];
    pwmTOn[0] = uwTimeOn[0];
    pwmFreq[0] = uwFrequency[0];
    ErrCnt[0] = 0;
    
    pwmDuty[1] = uwDutyCycle[1];
    pwmTOn[1] = uwTimeOn[1];
    pwmFreq[1] = uwFrequency[1];
    ErrCnt[1] = 0;
}

void TIM_IC_Config(void)
{
    GPIO_InitTypeDef   GPIO_InitStruct;
    GPIO_InitTypeDef   GPIO_InitStruct2;

    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    /* TIMx Peripheral clock enable */
    TIMx_CLK_ENABLE();

    /* Enable GPIO channels Clock */
    TIMx_CHANNEL_GPIO_PORT();
		TIMx_CHANNEL_GPIO_PORTB();

    /* Configure  (TIMx_Channel) in Alternate function, push-pull and 100MHz speed */
    GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF_TIMx;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);
    
    /* Configure  (TIMx_Channel) in Alternate function, push-pull and 100MHz speed */
    GPIO_InitStruct2.Pin = GPIO_PIN_CHANNEL4;
    GPIO_InitStruct2.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct2.Pull = GPIO_PULLUP;
    GPIO_InitStruct2.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct2.Alternate = GPIO_AF_TIMx;
    HAL_GPIO_Init(GPIO_PORTB, &GPIO_InitStruct2);

    /*##-2- Configure the NVIC for TIMx #########################################*/
    /* Sets the priority grouping field */
    HAL_NVIC_SetPriority(TIMx_IRQn, 2, 0);

    /* Enable the TIM3 global Interrupt */
    HAL_NVIC_EnableIRQ(TIMx_IRQn);

}

/**
* @brief Interrupt Request Handler
* @param  htim: TIM IC handle
* @retval None
*/
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TimHandle);
}

/**
  * @brief  Input Capture callback in non blocking mode 
  * @param  htim: TIM IC handle
  * @retval None
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  /*** Steering channel ***/
  if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
  {
    int i = 0;  
    /* Get the Input Capture value */
    uwIC2Value[i] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
		
    if (uwIC2Value[i] != 0)
    {
      uwIC1Value[i] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
      /* Duty cycle computation */
      uwDutyCycle[i] = (uwIC1Value[i] * 100 * 100) / uwIC2Value[i];
			
      /* Absolute T_ON */
      uwTimeOn[i] = uwIC1Value[i];
      
      /* uwFrequency computation
      TIM3 counter clock = (RCC_Clocks.HCLK_Frequency)/2 */      
      uwFrequency[i] = (HAL_RCC_GetHCLKFreq())/2 / uwIC2Value[i] / PRESCALER * 100;
      
      #ifdef DEBUG
          char s[200];
          sprintf(s, "Duty: %lu, Freq: %lu\n", (unsigned long) uwDutyCycle[i], (unsigned long) uwFrequency[i]);

          for (uint8_t i = 0; s[i] != '\0'; i++)
             USART3_Send(s[i]);
          USART3_Send(0x0D); //Break the line.
      #endif
    
    }
    else
    {
      uwDutyCycle[i] = 0;
      uwTimeOn[i] = 0;
      uwFrequency[i] = 0;
    }
  }
  
  /*** Throttle channel ***/
  if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
  {
    int i = 1;
    /* Get the Input Capture value */
    uwIC2Value[i] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
		
    if (uwIC2Value[i] != 0)
    {
      uwIC1Value[i] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
      /* Duty cycle computation */
      uwDutyCycle[i] = (uwIC1Value[i] * 100 * 100) / uwIC2Value[i];
			
      /* Absolute T_ON */
      uwTimeOn[i] = uwIC1Value[i];
      
      /* uwFrequency computation
      TIM3 counter clock = (RCC_Clocks.HCLK_Frequency)/2 */      
      uwFrequency[i] = (HAL_RCC_GetHCLKFreq())/2 / uwIC2Value[i] / PRESCALER * 100;
      
      #ifdef DEBUG
          char s[200];
          sprintf(s, "Duty: %lu, Freq: %lu\n", (unsigned long) uwDutyCycle[i], (unsigned long) uwFrequency[i]);

          for (uint8_t i = 0; s[i] != '\0'; i++)
             USART3_Send(s[i]);
          USART3_Send(0x0D); //Break the line.
      #endif
    
    }
    else
    {
      uwDutyCycle[i] = 0;
      uwTimeOn[i] = 0;
      uwFrequency[i] = 0;
    }
  }
}

