/* Copyright 2014 The MathWorks, Inc. */
#include "mw_cmsis_rtos.h"

/* Create and Initialize a Semaphore object used for managing resources. */
int32_t mw_osSemaphoreCreate(mw_semaphore_t * semaphore_def, int32_t count)
{
	int32_t status;
	
	/* Initialize semaphore structure */
	//(semaphore_def->semaphoreDef).semaphore = semaphore_def->semaphoreInternalData;	
	
	/* Create semaphore */
	semaphore_def->semaphoreId =  osSemaphoreCreate(&(semaphore_def->semaphoreDef), count);
	status = (NULL != semaphore_def->semaphoreId);
	
	return status;
}

/* Wait until a Semaphore token becomes available. */
int32_t mw_osSemaphoreWait(mw_semaphore_t * semaphore_def, uint32_t millisec)
{
	return osSemaphoreWait(semaphore_def->semaphoreId, millisec);
}

/* Wait until a Semaphore token becomes available. */
int32_t mw_osSemaphoreWaitEver(mw_semaphore_t * semaphore_def)
{
    int32_t status;
    status = osSemaphoreWait(semaphore_def->semaphoreId,  osWaitForever);
	return status;
}

/* Release a Semaphore token. */
osStatus mw_osSemaphoreRelease(mw_semaphore_t * semaphore_def)
{
    osStatus status;
	status = osSemaphoreRelease(semaphore_def->semaphoreId);
    
    return status;
}

/* Delete a Semaphore that was created by osSemaphoreCreate. */
osStatus mw_osSemaphoreDelete(mw_semaphore_t * semaphore_def)
{
    osStatus status;
	status = osSemaphoreDelete(semaphore_def->semaphoreId);
    return status;
}