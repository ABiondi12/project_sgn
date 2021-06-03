#include "rtwtypes.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"

//this function is identical to wrap PWM excpet that the ARR is not set to 2500 (that is 2.5 ms 
//that is needed for 400 Hz update of quadrotor commands) but is set to 13840, that is 20 ms 
//that is necessary for the HPI-RF20 servomotor control !!!

//TODO: add ARR in ms as parameter !!!!

#define BasicPWM_TIMx_ARR          55360  //13840*4 //AutoReloadRegister. This value must be minor or less than 65536 (2e16)
#define TIMx                       TIM8
#define TIM_PIN1                   GPIO_PIN_6
#define TIM_PIN2                   GPIO_PIN_7
#define TIM_PIN3                   GPIO_PIN_8
#define TIM_PIN4                   GPIO_PIN_9
#define TIM_GPIO_PORT              GPIOC
#define TIM_AF_PORT                GPIO_AF3_TIM8




void wrap_PWM_servomotor_start_fcn(double ch1,double ch2,double ch3, double ch4)
{
    
    
  // Block: BasicPWM
  GPIO_InitTypeDef 		GPIO_InitStructure;
  TIM_Base_InitTypeDef 	TIM_TimeBaseStructure;
  TIM_OC_InitTypeDef 	TIM_OCInitStructure;
  TIM_HandleTypeDef 	TIM_HandleStructure;
  

  __TIM8_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();

  // GPIOx configuration:
  
  if (ch1 == 1){
        // Connect TIMx pins to AF
        GPIO_InitStructure.Pin 		 = GPIO_InitStructure.Pin | TIM_PIN1;
		
  }
  if (ch2 == 1){
        GPIO_InitStructure.Pin 		 = GPIO_InitStructure.Pin | TIM_PIN2;
		
  }
  if (ch3 == 1){
        GPIO_InitStructure.Pin 		 = GPIO_InitStructure.Pin | TIM_PIN3;
		
  }
  if (ch4 == 1){
        GPIO_InitStructure.Pin 		 = GPIO_InitStructure.Pin | TIM_PIN4;
		
  }
  
  GPIO_InitStructure.Alternate = TIM_AF_PORT;
  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  
  HAL_GPIO_Init(TIM_GPIO_PORT, &GPIO_InitStructure);

  
  /* TIM4 is connected to APB1 bus which has 42Mhz clock in F407
  But, timer ha internal PLL which double this frequency for timer, up to 84Mhz.
  Remember: not every timer is connected to APB1, there are timers connected to APB2
  (168Mhz). */
  
  TIM_TimeBaseStructure.Period = BasicPWM_TIMx_ARR-1;

  /* PRESCALER CHOICE 
     TIM_TICK_FREQ = TIM_CLK/(PRESCALER+1)
     We want TIM_TICK_FREQ = 1 Mhz, so PRESCALER = 83
     In this way we get TIM_TICK_PERIOD = 1us.
     And so with ARR (Auto Reload Register) we can generate PWM waves with period up to 65536*1us = 65.536 ms.
     Motor PWMS are clocked at 250Hz, 4 ms.
     Method is simple: BasicPWMx_TIM_ARR = 4000 means 4ms period (PRESCALER = 83).
     However this code is adaptable to different situations, simply modifing ARR value.
   */

  TIM_TimeBaseStructure.Prescaler = 41;  //167;
  TIM_TimeBaseStructure.ClockDivision = TIM_CLOCKDIVISION_DIV1;// Specifica per quanto viene diviso il SystemClock
  TIM_TimeBaseStructure.CounterMode = TIM_COUNTERMODE_UP;
  TIM_TimeBaseStructure.RepetitionCounter = 0x0000; //TIMx_RCR register. UEV interrupt generated every overflow of the TIMx_CNT register.
  
  TIM_HandleStructure.Instance 	= TIMx; // defined as TIM4
  TIM_HandleStructure.Init 		= TIM_TimeBaseStructure;

  if(HAL_TIM_PWM_Init(&TIM_HandleStructure) != HAL_OK)
	{
		Error_Handler();
	}
  
  
  TIM_OCInitStructure.OCMode = TIM_OCMODE_PWM1;
  TIM_OCInitStructure.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_RESET;
  TIM_OCInitStructure.OCNIdleState = TIM_OCIDLESTATE_RESET;
  TIM_OCInitStructure.OCFastMode = TIM_OCFAST_DISABLE;  
  TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;

  
  if (ch1 == 1){
      // PWM Mode configuration: Channel 1
      
	  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStructure, &TIM_OCInitStructure, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&TIM_HandleStructure, TIM_CHANNEL_1);
  }
  
  if (ch2 == 1){
      // PWM Mode configuration: Channel 2
    //OLD:
	  //TIM_OC2Init(TIMx, &TIM_OCInitStructure);
    //TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
	  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStructure, &TIM_OCInitStructure, TIM_CHANNEL_2);
	  HAL_TIM_PWM_Start(&TIM_HandleStructure, TIM_CHANNEL_2);
  }
  
  if (ch3 == 1){
      // PWM Mode configuration: Channel 3
	  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStructure, &TIM_OCInitStructure, TIM_CHANNEL_3);
      HAL_TIM_PWM_Start(&TIM_HandleStructure, TIM_CHANNEL_3);
  }
  
  if (ch4 == 1){
      // PWM Mode configuration: Channel 4
	  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStructure, &TIM_OCInitStructure, TIM_CHANNEL_4);
	  HAL_TIM_PWM_Start(&TIM_HandleStructure, TIM_CHANNEL_4);
  }
  
}



void wrap_PWM_servomotor_output_fcn(real_T* time,double ch1,double ch2,double ch3,double ch4)
{
    
  /* Writing on enabled channels. Output Compare (OC) mode: Pin linked to TIM toggle (OFF) when
     CNTx > CCRx, toggle (ON) otherwise. */
//   if (ch1 == 1)
//     TIMx->CCR1 = (uint32_t) (time[0] * 1000);
//   if (ch2 == 1)
//     TIMx->CCR2 = (uint32_t) (time[1] * 1000);
//   if (ch3 == 1)
//     TIMx->CCR3 = (uint32_t) (time[2] * 1000);
//   if (ch4 == 1)
//     TIMx->CCR4 = (uint32_t) (time[3] * 1000);
    
  if (ch1 == 1)
    TIMx->CCR1 = (uint32_t) (time[0] * 4000);
  if (ch2 == 1)
     TIMx->CCR2 = (uint32_t) (time[1] * 4000);
  if (ch3 == 1)
    TIMx->CCR3 = (uint32_t) (time[2] * 4000);
  if (ch4 == 1)
     TIMx->CCR4 = (uint32_t) (time[3] * 4000);

 }