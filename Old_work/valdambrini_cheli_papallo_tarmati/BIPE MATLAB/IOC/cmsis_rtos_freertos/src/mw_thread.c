/* Copyright 2014 The MathWorks, Inc. */
#include "mw_cmsis_rtos.h"

	char temp_task_name[2]; 

/*------------------------------------------------------------------------------------------------------*/
/*------------------------------------- Thread functions -----------------------------------------------*/
/*------------------------------------------------------------------------------------------------------*/
/* Create a thread and add it to Active Threads and set it to state READY. */
int32_t mw_osThreadCreate(mw_thread_t * thread_def, void (*pthread)(void *), int32_t priority, int32_t stacksize, void *argument)
{
	int32_t status;
	

	
	/* Initialize thread */
	(thread_def->threadDef).pthread   = (os_pthread)pthread;
	(thread_def->threadDef).tpriority = priority;
	(thread_def->threadDef).instances = 1;
	(thread_def->threadDef).stacksize = stacksize;
	
	//THIS IS A TRY
	//use argument to create a task name as: 0(NULL) ->'A', 1->'B', '2->'C' .... 
	if (argument!=NULL) {
		//its a subrate task => start from B
		temp_task_name[0] = 65 + *((int*)(argument)); //66 is ASCII code for 'B'
//	} else {
//		//argument is NULL = > use A as name
//		temp_task_name[0] = 65;
	}
	//terminate string 
	temp_task_name[1] = 0x00;
	(thread_def->threadDef).name = temp_task_name;

	
	thread_def->threadId = osThreadCreate(&thread_def->threadDef, argument);
	//set name pointer back to null (the temp_task_name is not valid outside of here)
	(thread_def->threadDef).name = NULL;
	
	status = (NULL != thread_def->threadId);
	
	return status;
}

/* Return the thread ID of the current running thread.  */
osThreadId mw_osThreadGetId 		(void)
{
	return osThreadGetId();
}

/* Terminate execution of a thread and remove it from Active Threads. */
osStatus   mw_osThreadTerminate 	(mw_thread_t * thread_def)
{
	return osThreadTerminate(thread_def->threadId);
}

/* Change priority of an active thread. */
osStatus   mw_osThreadSetPriority 	(mw_thread_t * thread_def, osPriority priority)
{
	return osThreadSetPriority(thread_def->threadId, priority);
}

/* Get current priority of an active thread. */
osPriority mw_osThreadGetPriority 	(mw_thread_t * thread_def)
{
	return osThreadGetPriority(thread_def->threadId);
}

/* Pass control to next thread that is in state READY. */
osStatus   mw_osThreadYield 		(void)
{
	return osThreadYield();
}

void   mw_osThreadExit 	(void * value_ptr)
{
	osThreadId current_thread;
	osStatus status;
	
	current_thread = osThreadGetId();
	status = osThreadTerminate(current_thread);
	
	(void)status;
}

int32_t   mw_osThreadJoin 	(mw_thread_t thread_def, void ** value_ptr)
{
	return (int32_t)1; // Not supported on CMSIS RTX
					   // So just return 1 for success
}