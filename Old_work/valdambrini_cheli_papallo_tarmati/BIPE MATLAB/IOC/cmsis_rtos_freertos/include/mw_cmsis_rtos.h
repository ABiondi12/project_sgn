/* Copyright 2014 The MathWorks, Inc. */
#ifndef __CMSIS_RTOS_INIT_H__
#define __CMSIS_RTOS_INIT_H__

#include <stdio.h>
#include "cmsis_os.h"

#include "mw_thread.h"
#include "mw_semaphore.h"
#include "mw_timer.h"

//#include "MW_target_hardware_resources.h" //removed ! 
//#include "system_stm32f4xx.h"
//#include "stm32f4xx.h"


#ifndef USER_CHECK_STATUS
	#define CHECK_STATUS(status, expStatus, fcn)  		((void)(status))
	#define CHECK_STATUS_NOT(status, errStatus, fcn)	((void)(status))
#else
	void CHECK_STATUS(int32_t status, int32_t expStatus, char_t * str);
	void CHECK_STATUS_NOT(int32_t status, int32_t expStatus, char_t * str);
#endif

void mw_WaitForThisEvent(int sigNo);
void mw_AddBlockForThisEvent(int sigNo);
void mw_AddHandlerForThisEvent(int sigNo, int sigToBlock[], int numSigToBlock, void *sigHandler);
void mw_RestoreDefaultHandlerForThisEvent(int sigNo);

#ifdef TGTSVC_RUNNING
    void * getCommService();
    void terminateCommService();
#endif

extern void mw_RTOSInit(float baseRatePeriod, int numSubrates, int32_t BaseRate_stack_size, int32_t SubRates_stack_size[]);

#endif //__CMSIS_RTOS_INIT_H__
