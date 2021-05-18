#include "rtwtypes.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"

#define BasicPWM_TIMx_ARR          2500
#define TIMx                       TIM3
#define TIM_PIN1                   GPIO_PIN_6
#define TIM_PIN2                   GPIO_PIN_7
#define TIM_PIN3                   GPIO_PIN_8
#define TIM_PIN4                   GPIO_PIN_9
#define TIM_GPIO_PORT              GPIOC
#define TIM_AF_PORT                GPIO_AF2_TIM3




void wrap_PWM2_start_fcn(double ch1,double ch2,double ch3,double ch4)
{
    
    
  // Block: BasicPWM
  GPIO_InitTypeDef 		GPIO_InitStructure;
  TIM_Base_InitTypeDef 	TIM_TimeBaseStructure;
  TIM_OC_InitTypeDef 	TIM_OCInitStructure;
  TIM_HandleTypeDef 	TIM_HandleStructure;
  
  __TIM3_CLK_ENABLE();
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


  
  TIM_TimeBaseStructure.Period = BasicPWM_TIMx_ARR-1;
  
  
  TIM_TimeBaseStructure.Prescaler = 83;
  TIM_TimeBaseStructure.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM_TimeBaseStructure.CounterMode = TIM_COUNTERMODE_UP;
  TIM_TimeBaseStructure.RepetitionCounter = 0x0000;
  
  TIM_HandleStructure.Instance 	= TIMx; // defined as TIM3
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
  //TIM_OCInitStructure.Pulse = 1500; 
  
  if (ch1 == 1){
      // PWM Mode configuration: Channel 1
	  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStructure, &TIM_OCInitStructure, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&TIM_HandleStructure, TIM_CHANNEL_1);
  }
  
  if (ch2 == 1){
      // PWM Mode configuration: Channel 2
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



void wrap_PWM2_output_fcn(real_T* time,double ch1,double ch2,double ch3,double ch4)
{

  if (ch1 == 1)
    TIMx->CCR1 = (uint32_t) (time[0] * 1000);
  if (ch2 == 1)
    TIMx->CCR2 = (uint32_t) (time[1] * 1000);
  if (ch3 == 1)
    TIMx->CCR3 = (uint32_t) (time[2] * 1000);
  if (ch4 == 1)
    TIMx->CCR4 = (uint32_t) (time[3] * 1000);
  
 }
