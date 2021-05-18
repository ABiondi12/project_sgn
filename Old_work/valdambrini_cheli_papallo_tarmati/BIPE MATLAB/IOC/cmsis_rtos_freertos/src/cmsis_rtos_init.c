/* Copyright 2014-2015 The MathWorks, Inc. */


/* ---------------------------- */
/* RTOS-specific headers        */
/* Note: must be included first */
/* ---------------------------- */
#include "mw_cmsis_rtos.h"

/* ---------------------------- */
/* Required Coder Target header */
/* ---------------------------- */
//#include "MW_custom_RTOS_header.h"
//#define MW_HAS_MULTIPLE_RATES
//MW_MULTI_TASKING_MODE : aggiunto a mano
//#define MW_MULTI_TASKING_MODE 			   1
#include "cmsis_os.h"

extern void exitTask(int sig);
extern void terminateTask(void *arg);
extern void baseRateTask(void *arg);
extern void subrateTask(void *arg);
extern mw_thread_t schedulerThread;
extern mw_thread_t baseRateThread;
extern mw_thread_t subRateThread[];
extern mw_semaphore_t stopSem;
extern mw_semaphore_t baserateTaskSem;
extern mw_semaphore_t subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

/* ---------------------------- */
/* RTOS-specific declarations   */
/* ---------------------------- */
int status;
/* Scheduler timer */
mw_timer_t mw_scheduler_timer_def;

#ifdef MW_HAS_TARGET_SERVICES
mw_thread_t runCommServiceThread;
osMutexDef (CSMtxDef);
osMutexId csmtx_id;
extern void runCommService();
extern void terminateCommServiceTask();
#endif


/* Scheduler task move base rate task from wait state to ready state */
void schedulerTask(void* arg)
{
		
#ifdef MW_RTOS_DEBUG
	printf("schedulerTask entered\n");
    fflush(stdout);
#endif
	
    /* Release base rate semaphore to move base rate task from wait state to ready state */
    mw_osSemaphoreRelease(&baserateTaskSem);  
			
}

#ifdef MW_HAS_TARGET_SERVICES
void runCommServiceTask(void *arg)
{
	int32_t status;
    while(1){
    	status  = osMutexWait(csmtx_id, 0);
    	CHECK_STATUS(status, osOK, "osMutexWait");
		runCommService();
    	status = osMutexRelease(csmtx_id);
		CHECK_STATUS(status, osOK, "osMutexRelease");
    }
}
#endif

/* ---------------------------- */
/* Externally visible functions */
/* ---------------------------- */
void mw_WaitForThisEvent(int sigNo)
{
}

void mw_AddBlockForThisEvent(int sigNo)
{
}

void mw_AddHandlerForThisEvent(int sigNo, int sigToBlock[], int numSigToBlock, void *sigHandler)
{
}

void mw_RestoreDefaultHandlerForThisEvent(int sigNo)
{
}

#ifdef MW_HAS_TARGET_SERVICES
void initializeCommService()
{
	int32_t status;
	csmtx_id = osMutexCreate  (osMutex (CSMtxDef));
    /* Create runCommServiceTask thread */
	status = mw_osThreadCreate(&runCommServiceThread, runCommServiceTask, osPriorityIdle , 0, NULL);
	CHECK_STATUS(status, 0,"mw_osThreadCreate"); 
}
void terminateCommService()
{
	terminateCommServiceTask();
}
#endif


//define stack sizes task by task
//TODO: let this be set outside of here

//int32_t BaseRate_stack_size = 512;
//int32_t SubRates_stack_size[4] = {768, 256, 256, 128};


void mw_RTOSInit(float baseRatePeriod, int numSubrates, int32_t BaseRate_stack_size, int32_t SubRates_stack_size[] )
{
	int i;
	int32_t status;
	osPriority taskPriority;
	//osPriority defaultPriority = osPriorityRealtime;
	int32_t defaultPriority = configTIMER_TASK_PRIORITY - 1; //la massima priorità viene assegnata al timer
	
	
	/* Create semaphore for base rate task */
	status = mw_osSemaphoreCreate(&baserateTaskSem, 1);
    CHECK_STATUS(status, 0, "mw_osSemaphoreCreate:baserateTaskSem");
	/* Create semaphore for stop task */
//	status = mw_osSemaphoreCreate(&stopSem, 1);
  //  CHECK_STATUS(status, 1, "mw_osSemaphoreCreate:stopSem");

#ifdef MW_RTOS_DEBUG
	printf("**creating the base rate task thread**\n");
    fflush(stdout);
#endif
	/* Create baseRateTask thread */
	taskId[0] = 0;
	status = mw_osThreadCreate(&baseRateThread, baseRateTask, defaultPriority, BaseRate_stack_size, (void *)&taskId[0]);
	CHECK_STATUS(status, 0,"mw_osThreadCreate");

//#ifdef MW_HAS_MULTIPLE_RATES
if(numSubrates > 0){
#ifdef MW_RTOS_DEBUG    
	printf("**creating subrate task threads**\n");
    fflush(stdout);
#endif    
	for (i = 0; i < numSubrates; i++) {
		taskId[i+1] = i+1; //NOTE now base rate task id is 0
		status = mw_osSemaphoreCreate(&subrateTaskSem[i], 1);
		CHECK_STATUS(status, 1,"mw_osSemaphoreCreate");
		/* Initialize thread structure */
			/* Assigning thread priority between osPriorityRealtime and osPriorityLow. */
			/* Other priority values are not allowed. */
		taskPriority = defaultPriority - (i+1);
		if (taskPriority < osPriorityLow)
		{
			taskPriority = osPriorityLow;
		}
		status = mw_osThreadCreate(&subRateThread[i], subrateTask, taskPriority, SubRates_stack_size[i], (void *)&taskId[i+1]);// i+1 perche taskId[0] è il base rate
		
		CHECK_STATUS(status, 0, "mw_osThreadCreate");
	}
//#endif
}
	/* Set the SysTick priority */
	#ifdef MW_SCHEDULER_PRIORITY
		NVIC_SetPriority((IRQn_Type)(-1), MW_SCHEDULER_PRIORITY);
	#endif
	
#ifdef MW_NEEDS_BACKGROUND_TASK
#ifdef MW_HAS_TARGET_SERVICES
    status  = osMutexWait(csmtx_id, 0);
	CHECK_STATUS(status, osOK, "osMutexWait");
    mw_osThreadTerminate(&runCommServiceThread);
	status = osMutexRelease(csmtx_id);
	CHECK_STATUS(status, osOK, "osMutexRelease");
#endif
#ifdef MW_RTOS_DEBUG
	printf("**creating background thread**\n");
    fflush(stdout);
#endif
    /* Create backgroundTask thread */
    status = mw_osThreadCreate(&backgroundThread, backgroundTask, osPriorityIdle, 0, NULL);
    CHECK_STATUS(status, 0,"mw_osThreadCreate");
#endif
	
	/* Create timer to call scheduler task */
#ifdef MW_RTOS_DEBUG    
	printf("**creating timer to invoke scheduler task**\n");
    fflush(stdout);
#endif
	status = mw_osTimerCreate(&mw_scheduler_timer_def, osTimerPeriodic, schedulerTask, NULL);
	CHECK_STATUS(status, 0,"mw_osTimerCreate");
    mw_osTimerStart(&mw_scheduler_timer_def, (uint32_t)(baseRatePeriod*1000
		));
    
    (void)taskPriority;
    (void)status;
    (void)i;
}
