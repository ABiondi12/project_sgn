/*
 * File: main.c
 *
 * Code generated for Simulink model :ICARO3_Onda_bipe_controllonostro.
 *
 * Model version      : 1.1510
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Thu Dec 12 10:23:38 2019
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

/* USER CODE BEGIN 0 */
#include <stdio.h>
#include "ICARO3_Onda_bipe_controllonostro.h" /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */

//
// FREE RTOS includes
//
#include "mw_cmsis_rtos.h"
#include "task.h"

//
// FREE RTOS includes END
//

/* Real-time model */
extern RT_MODEL_ICARO3_Onda_bipe_controllonostro *const
  ICARO3_Onda_bipe_controllonostro_M;

/* Set which subrates need to run this base step (base rate always runs).*/
/* Defined in ICARO3_Onda_bipe_controllonostro.c file */
extern void ICARO3_Onda_bipe_controllonostro_SetEventsForThisBaseStep(boolean_T*);

/* Flags for taskOverrun */
static boolean_T OverrunFlags[6];

/* Number of auto reload timer rotation computed */
static uint32_t autoReloadTimerLoopVal_S = 1;

/* Remaining number of auto reload timer rotation to do */
static uint32_t remainAutoReloadTimerLoopVal_S = 1;

//
// FREE RTOS definition of variables, tasks functions and support functions
//

//helper functions
void exitTask(int sig);
void terminateTask(void *arg);

//functions implementing base rate and subrates
void baseRateTask(void *arg);
void subrateTask(void *arg);

//support variables
volatile boolean_T runModel = true;    //this must be true as long as the model is running

//mw_semaphore_t stopSem;
mw_semaphore_t baserateTaskSem;        //used to signal the task its start moment has arrived
mw_semaphore_t subrateTaskSem[(6 - 1)];//see above
int taskId[(6)];                       //id of sub rate tasks (id of base rate task is 0
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
unsigned long threadJoinStatus[(6 - 1)*2];
int terminatingmodel = 0;
mw_thread_t subRateThread[(6 - 1)];
int stato;                             //temporary used to check heap size

//
// DEFINITION OF STACK SIZES FOR EACH SINGLE TASK
//
int32_t BaseRate_stack_size = 896;

//int32_t SubRates_stack_size[(6 - 1)] = {768, 256, 256, 128};
int32_t SubRates_stack_size[8] = { 384, 256, 256, 128, 128, 128, 128, 128 };

//note: must manaully edit here to change the stack width for each single task !!!!
//TODO: find a way to import this from Matlab !!!!!
//stack SIZE left  for all tasks
UBaseType_t BaseRate_emptystacksize;
UBaseType_t SubRate_emptystacksize[(6 - 1)];
void subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid;                     //note: now subrate tids start from 1 !!!
  while (runModel) {
    mw_osSemaphoreWaitEver(&subrateTaskSem[tid - 1]);//Dim of tid is 5 but tid[0] is the base rate ID
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    ICARO3_Onda_bipe_controllonostro_step(subRateId);
    SubRate_emptystacksize[subRateId-1] = uxTaskGetStackHighWaterMark(NULL);

    /* Get model outputs here */
  }

  mw_osThreadExit((void *)0);
}

void baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(ICARO3_Onda_bipe_controllonostro_M) == (NULL));
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    for (i = 1; i <= (6 - 1); i++) {
      if (rtmStepTask(ICARO3_Onda_bipe_controllonostro_M, i)) {
        mw_osSemaphoreRelease(&subrateTaskSem[ i - 1
                              ]);
      }
    }

    BaseRate_emptystacksize = uxTaskGetStackHighWaterMark(NULL);
    ICARO3_Onda_bipe_controllonostro_step(0);

    /* Get model outputs here */
    BaseRate_emptystacksize = uxTaskGetStackHighWaterMark(NULL);

    /* Get model outputs here */
    runModel = (rtmGetErrorStatus(ICARO3_Onda_bipe_controllonostro_M) == (NULL));
  }

  terminateTask(arg);
  mw_osThreadExit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(ICARO3_Onda_bipe_controllonostro_M, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<(6 - 1); i++) {
      CHECK_STATUS(mw_osSemaphoreRelease(&subrateTaskSem[i]), 0,
                   "mw_osSemaphoreRelease");
      CHECK_STATUS(mw_osSemaphoreDelete(&subrateTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<(6 - 1); i++) {
      ret = mw_osThreadJoin(subRateThread[i], (void *)&threadJoinStatus);
      CHECK_STATUS(ret, 0, "mw_osThreadJoin");
    }

    runModel = 0;
  }

  /* Terminate model */
  //stm32f4discovery_gettingstarted_terminate(); // REMOVED !
  // mw_osSemaphoreRelease(&stopSem);
}

//void stm32f4xx_init_board(void)
//{
//	/* Enable double word stack alignment */
//	SCB->CCR |= SCB_CCR_STKALIGN_Msk;

//	#if MW_MULTI_TASKING_MODE == 1
//    /* Set the interrupt priority at highest */
//    NVIC_SetPriority(SVCall_IRQn, 0x0);
//    #endif
//
//    #if defined(MW_ENABLE_CLOCK_TO_I2S) && (MW_ENABLE_CLOCK_TO_I2S == 1)
//    MW_I2S_Clock_config((uint32_t)MW_I2S_CLOCK_PLLN, (uint32_t)MW_I2S_CLOCK_PLLR);
//    #endif
//}

//
// FREE RTOS definition of variables, tasks functions and support functions END
//

/* USER CODE END 0 */

/****************************************************
   main function
   Example of main :
   - Clock configuration
   - call Initialize
   - Wait for systick (infinite loop)
 *****************************************************/
int main (void)
{
  /* USER CODE BEGIN 1 */
  /* Data initialization */
  int_T i;
  boolean_T eventFlags[6];             /* Model has 6 rates */

  /* USER CODE END 1 */

  /* USER CODE BEGIN 2 */
  /* Systick configuration and enable SysTickHandler interrupt */

  /* REMOVED !
     if (SysTick_Config((uint32_t)(SystemCoreClock * 0.001)))
     {
     autoReloadTimerLoopVal_S = 1;
     do {
     autoReloadTimerLoopVal_S++;
     } while((uint32_t)(SystemCoreClock * 0.001)/autoReloadTimerLoopVal_S > SysTick_LOAD_RELOAD_Msk);
     SysTick_Config((uint32_t)(SystemCoreClock * 0.001)/autoReloadTimerLoopVal_S);
     }
     remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S; //Set nb of loop to do
   */

  //
  // FREE RTOS initialization: creation of tasks, semaphores and scheduler timer
  //

  /* Model initialization call */
  ICARO3_Onda_bipe_controllonostro_initialize();

  //note: must call model initialize here

  /* Call RTOS Initialization function */
  //traceSTART function defined in simple_trace.c --> useful for trace debug
  traceSTART();
  mw_RTOSInit(0.001, (6 - 1), BaseRate_stack_size, SubRates_stack_size );
  stato = xPortGetFreeHeapSize();      //debug: read heap left space

  //
  // FREE RTOS initialization: creation of tasks, semaphores and scheduler timer END
  //

  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  for (i=0;i<6;i++) {
    OverrunFlags[i] = 0;
  }

  /* Model initialization call */
  ICARO3_Onda_bipe_controllonostro_initialize();

  /* Infinite loop */
  /* Real time from systickHandler */
  while (1) {
    /*Process tasks every solver time*/
    if (remainAutoReloadTimerLoopVal_S == 0) {
      remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;

      /* Check base rate for overrun */
      if (OverrunFlags[0]) {
        rtmSetErrorStatus(ICARO3_Onda_bipe_controllonostro_M, "Overrun");
      }

      OverrunFlags[0] = true;

      /*
       * For a bare-board target (i.e., no operating system), the rates
       * that execute this base step are buffered locally to allow for
       * overlapping preemption.  The generated code includes function
       * writeCodeInfoFcn() which sets the rates
       * that need to run this time step.  The return values are 1 and 0
       * for true and false, respectively.
       */
      ICARO3_Onda_bipe_controllonostro_SetEventsForThisBaseStep(eventFlags);

      /* Step the model for base rate */
      ICARO3_Onda_bipe_controllonostro_step(0);

      /* Get model outputs here */

      /* Indicate task for base rate complete */
      OverrunFlags[0] = false;

      /* Step the model for any subrate */
      for (i = 1; i < 6; i++) {
        if (eventFlags[i]) {
          if (OverrunFlags[i]) {
            rtmSetErrorStatus(ICARO3_Onda_bipe_controllonostro_M, "Overrun");
          }

          OverrunFlags[i] = true;

          /* Step the model for subrate "i" */
          ICARO3_Onda_bipe_controllonostro_step(i);

          /* Indicate task complete for sample time "i" */
          OverrunFlags[i] = false;
        }
      }
    }
  }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */
/****************************************************
   SysTick_Handler callback function
   This handler is called every tick and schedules tasks
 *****************************************************/
void HAL_SYSTICK_Callback(void)
{
  /* For TIME OUT processing */
  HAL_IncTick();

  /* Manage nb of loop before interrupt has to be processed */
  //removed
  //if( remainAutoReloadTimerLoopVal_S) {
  //	remainAutoReloadTimerLoopVal_S--;
  //}
}

/* USER CODE END 4 */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] main.c
 */
