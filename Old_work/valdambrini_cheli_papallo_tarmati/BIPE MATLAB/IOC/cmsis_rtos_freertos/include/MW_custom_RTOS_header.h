#ifndef _MW_CUSTOM_RTOS_HEADER_H_
#define _MW_CUSTOM_RTOS_HEADER_H_												
#define MW_BASERATE_PRIORITY           40								//NOT USED
//MW_BASERATE_PERIOD modified: it was 0.01: manually adapted to 400 Hz
#define MW_BASERATE_PERIOD             0.0025						//NOT USED
//MW_NUMBER_SUBRATES modified: it was 2: manually adapted to 4
#define MW_NUMBER_SUBRATES             4
#define MW_NUMBER_APERIODIC_TASKS      0								//NOT USED
#define MW_IS_CONCURRENT               0 								//NOT USED
#define MW_HAS_MULTIPLE_RATES
//MW_MULTI_TASKING_MODE : aggiunto a mano
#define MW_MULTI_TASKING_MODE 			   1
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

#endif
