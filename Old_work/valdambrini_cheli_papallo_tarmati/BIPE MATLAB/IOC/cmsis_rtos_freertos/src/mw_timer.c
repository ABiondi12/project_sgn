/* Copyright 2014 The MathWorks, Inc. */
#include "mw_cmsis_rtos.h"

/*------------------------------------------------------------------------------------------------------*/
/*----------------------------- Timer Wrapper functions ------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------*/
int32_t mw_osTimerCreate(mw_timer_t * timer_def, os_timer_type type, void (*func_ptr)(void *), void *argument)
{
	int32_t status;
	
	/* Internal data init */
	//(timer_def->timerDef).timer = timer_def->timerInternalData; //REMOVED !
	//	NOTE: osTimerCreate uses freeRTOS xTimerCreate that takes as argument timer_def->ptimer
	// 				thus timer_def->timer is not used (apparently) :-)
	
	/* Timer function init */
	(timer_def->timerDef).ptimer = (os_ptimer)func_ptr;
	
	/* Create timer */
	timer_def->timerId = osTimerCreate(&(timer_def->timerDef), type, argument);
	
	status = (NULL != timer_def->timerId);
	
	return status;
}

osStatus mw_osTimerStart(mw_timer_t * timer_def, uint32_t millisec)
{
	osStatus status;
	status = osTimerStart(timer_def->timerId, millisec);
	return status;
}

osStatus mw_osTimerStop(mw_timer_t * timer_def)
{
	return osTimerStop(timer_def->timerId);
}

osStatus mw_osTimerDelete(mw_timer_t * timer_def)
{
	return osTimerDelete(timer_def->timerId);
}