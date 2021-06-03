/* SysTick scheduler
 * 
 * Copyright 2013-2014 The MathWorks, Inc.
 */
 
//#include "MW_target_hardware_resources.h"
#include "SysTickScheduler.h"

//#include "system_stm32f4xx.h"

#define uint32_t unsigned int

uint32_t schdl_counter;
uint32_t schdl_counter_max;

static void SysTick_Isr(void)
{
    __DSB();
    __ISB();
	//__dsb(); //TODO: controllare cosa facevano i vecchi dsb e isb 
	//__isb();
	
	if (schdl_counter >= schdl_counter_max)
	{
		schdl_counter = 0;
	}
	
    if (0 == schdl_counter++)	/* Compare with zero before increament */
	{
		/* The rt_OneStep() function expects interrupts to be disabled. 
           Hence disable interrupt before rt_OneStep(). */
        __disable_irq();
        rt_OneStep();
        /* The rt_OneStep() function disables interrupt. 
           Hence enable interrupt immediately after rt_OneStep(). */
        __enable_irq();
	}
}

//#if defined(MW_SCHEDULER_INTERRUPT_SOURCE) && (MW_SCHEDULER_INTERRUPT_SOURCE == 0) && (MW_MULTI_TASKING_MODE == 1)
__attribute__ ((naked)) void SysTick_Handler_2(void)
{
    /* Multi tasking, enable re-entrancy to interrupt */
    ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR();
    arm_cortex_m_call_thread_with_context_switch(SysTick_Isr);
}
//#else
//void SysTick_Handler(void)
//{
//    /* Single tasking */
//    SysTick_Isr();
//}
//#endif

void ARMCM_SysTick_Config(float modelBaseRate)
{
#if defined(MW_SCHEDULER_INTERRUPT_SOURCE) && (MW_SCHEDULER_INTERRUPT_SOURCE == 0)
	/* SysTick Scheduler is selected */
	uint32_t tick_counter;
	
	tick_counter = (uint32_t)(SystemCoreClock * modelBaseRate);
	
	if (tick_counter > SysTick_LOAD_RELOAD_Msk)
	{
		schdl_counter_max = (uint32_t)((float)tick_counter / (float)SysTick_LOAD_RELOAD_Msk) + 1;
		SysTick_Config(tick_counter/schdl_counter_max);		
	}
	else
	{
		schdl_counter_max = 0;
		SysTick_Config(tick_counter);
	}
	
	schdl_counter = 0;
	
	/* Set the SysTick priority */
	#ifdef MW_SCHEDULER_PRIORITY
		NVIC_SetPriority((IRQn_Type)(-1), MW_SCHEDULER_PRIORITY);
	#endif
#endif
}
