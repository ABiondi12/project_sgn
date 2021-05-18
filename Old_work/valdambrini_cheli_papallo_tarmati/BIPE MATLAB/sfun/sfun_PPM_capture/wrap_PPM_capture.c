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
#define GPIO_PIN_CHANNEL2              GPIO_PIN_7
#define GPIO_AF_TIMx                   GPIO_AF2_TIM3

/* Definition for TIMx's NVIC */
#define TIMx_IRQn                      TIM3_IRQn
#define TIMx_IRQHandler                TIM3_IRQHandler
/* Private Definitions */
#define TIMES_TO_CAPTURE               9
#define SYNC_THRESHOLD                 8000
#define PRESCALER                      45

/* Function prototypes*/
extern void Error_Handler(void); //From USART CUSTOM
void TIM_IC_Config(void);

/* Private Global Variables */

__IO uint8_t MeasReady;

__IO uint32_t uwIC2Value[TIMES_TO_CAPTURE];

uint32_t BufferCapture[TIMES_TO_CAPTURE], CurrentCapture, Timer_Tick_Frequency;

uint8_t  Counter, ErrorCounter;

double Timer_Tick_Period;

/* Notes on how to choose prescaler.

	TIM4 is connected to APB1 bus, which has on F407 device 42MHz clock.                 
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
	
	The TIM4CLK frequency (when prescaler=0) is set to (SystemCoreClock/4) x 2 (Hz). In general it is given by:
	
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

void wrap_PPM_start_fcn(void)
{
    TIM_IC_Config();
    /*USART3 inizialization*/
#ifdef DEBUG
   // USART3_Init();
#endif

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
    TimHandle.Init.Prescaler = PRESCALER;  // Notes on prescaler at the top of the file.
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

    /* Configure the Input Capture of channel 2 */
    sConfig.ICPolarity = TIM_ICPOLARITY_RISING;
    sConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
    if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_2) != HAL_OK)
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
    if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_2) != HAL_OK)
    {
        /* Starting Error */
        Error_Handler();
    }

    /* Flag set to 1 when a new measure is ready */
    MeasReady = 0;
    Counter = 0;
    ErrorCounter = 0;

    /* Timer Tick Frequency: [1/ms] */
    Timer_Tick_Frequency = 84000000*1e-03/(PRESCALER+1);
    /* Timer Tick Period: [us] */
    Timer_Tick_Period = 1e03*1/(double)Timer_Tick_Frequency;
    // Note the different scale of Period and 1/Frequency
}

void wrap_PPM_output_fcn(uint32_t *ppmval, uint8_t *newmess, uint8_t *ErrCnt)
{
    ErrCnt[0] = ErrorCounter;
    if (MeasReady)
    {
        for (int i = 0; i < TIMES_TO_CAPTURE; i++)
            ppmval[i] = Timer_Tick_Period*uwIC2Value[i];

        newmess[0] = 1;
        MeasReady = 0;  
    }
    else
        newmess[0] = 0;

#ifdef DEBUG
    if (ErrorCounter > 0)
    {
        USART3_Send('E');
        USART3_Send(ErrorCounter);
    }
    USART3_Send('C');
    USART3_Send(Counter);

    USART3_Send(0x0D);
#endif
}

void TIM_IC_Config(void)
{

    GPIO_InitTypeDef   GPIO_InitStruct;

    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    /* TIMx Peripheral clock enable */
    TIMx_CLK_ENABLE();

    /* Enable GPIO channels Clock */
    TIMx_CHANNEL_GPIO_PORT();

    /* Configure  (TIMx_Channel) in Alternate function, push-pull and 100MHz speed */
    GPIO_InitStruct.Pin = GPIO_PIN_CHANNEL2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF_TIMx;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    /*##-2- Configure the NVIC for TIMx #########################################*/
    /* Sets the priority grouping field */
    HAL_NVIC_SetPriority(TIMx_IRQn, 2, 0);

    /* Enable the TIM4 global Interrupt */
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
    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
    {
        CurrentCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);

        if (Counter == 0) // Wait for Sync
        {
            if (CurrentCapture >= SYNC_THRESHOLD)
            {
                BufferCapture[Counter] = CurrentCapture;
                Counter++;
            }
            else{}
        }
        else
        {
            if (CurrentCapture < Timer_Tick_Frequency*0.9 || CurrentCapture > Timer_Tick_Frequency*2.1) // Values are expressed in ms
            {   // Data not valid
                Counter = 0; // Restart from Waiting for Sync
                ErrorCounter++; // Notify that an error has occurred
            }
            else
            {   // Data valid
                if (Counter > TIMES_TO_CAPTURE)
                {   // We expect 8 channels + sync, if more than 9 has been captured, an error has occurred
                    Counter = 0;
                    ErrorCounter++;
                }
                else
                {   // Data stored in the temporary buffer
                    BufferCapture[Counter] = CurrentCapture;
                    if (Counter == TIMES_TO_CAPTURE-1)
                    {   // Buffer full of valid data, mirror to output
                        for (int i=0; i<TIMES_TO_CAPTURE; i++)
                            uwIC2Value[i] = BufferCapture[i];

                        Counter = 0;
                        MeasReady = 1;
                    }
                    else
                    {
                        Counter++;
                    }
                }
            }
        }
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */

/*
void Error_Handler(void)
{
  // Turn blue led on
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
  while(1)
  {
  }
}
*/
