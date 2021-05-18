#ifndef _SIMPLE_TRACE_INCLUDED_
#define _SIMPLE_TRACE_INCLUDED_

#include "circular_buffer.h"
#include "simple_trace.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

//#define telemetry_send(PAR) USART5_Send(PAR)
#define __byte(POINTER, DELTA) (((unsigned char*)POINTER)[DELTA])
#define Basic_TIMx_ARR          0xFFFFFFFF //AutoReloadRegister. This value must be minor or less than (2e32)
#define TIMx                       TIM2
TIM_HandleTypeDef 	TIM2_HandleStructure;

void start_TIM2()
	{
   
  TIM_Base_InitTypeDef 	TIM_TimeBaseStructure;
  //TIM_HandleTypeDef 	TIM_HandleStructure;
  

  __TIM2_CLK_ENABLE();

 
  /* TIM4 is connected to APB1 bus which has 42Mhz clock in F407
  But, timer ha internal PLL which double this frequency for timer, up to 84Mhz.
  Remember: not every timer is connected to APB1, there are timers connected to APB2
  (168Mhz). */
  
  TIM_TimeBaseStructure.Period = Basic_TIMx_ARR-1;

  /* PRESCALER CHOICE 
     TIM_TICK_FREQ = TIM_CLK/(PRESCALER+1)
     We want TIM_TICK_FREQ = 1 Mhz, so PRESCALER = 83
     In this way we get TIM_TICK_PERIOD = 1us.
     And so with ARR (Auto Reload Register) we can generate PWM waves with period up to 65536*1us = 65.536 ms.
     Motor PWMS are clocked at 250Hz, 4 ms.
     Method is simple: BasicPWMx_TIM_ARR = 4000 means 4ms period (PRESCALER = 83).
     However this code is adaptable to different situations, simply modifing ARR value.
   */

  TIM_TimeBaseStructure.Prescaler = 83;
  TIM_TimeBaseStructure.ClockDivision = TIM_CLOCKDIVISION_DIV1;// Specifica per quanto viene diviso il SystemClock
  TIM_TimeBaseStructure.CounterMode = TIM_COUNTERMODE_UP;
  TIM_TimeBaseStructure.RepetitionCounter = 0x0000; //TIMx_RCR register. UEV interrupt generated every overflow of the TIMx_CNT register.
  
  TIM2_HandleStructure.Instance 	= TIMx; // defined as TIM2
  TIM2_HandleStructure.Init 		= TIM_TimeBaseStructure;
	
	HAL_TIM_Base_Init(&TIM2_HandleStructure);
	HAL_TIM_Base_Start(&TIM2_HandleStructure);
  
}


void trace_send_via_USART(char byte_to_send) 
{
//	//uint32_t time = HAL_GetTick();
//	uint32_t time = __HAL_TIM_GET_COUNTER(&TIM2_HandleStructure);
//	
//	USART5_Send((unsigned char)'*');
//	USART5_Send((unsigned char)'*');
//	USART5_Send(byte_to_send);
//  
//  uint8_t *temp=(uint8_t *)&(time);
//  USART5_Send((uint8_t)__byte(temp,0));
//  USART5_Send((uint8_t)__byte(temp,1));
//  USART5_Send((uint8_t)__byte(temp,2));
//  USART5_Send((uint8_t)__byte(temp,3));

	
}
	
#endif


	
