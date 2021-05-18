/*
 * File: ICARO3_Onda_bipe_controllonostro40cm.c
 *
 * Code generated for Simulink model :ICARO3_Onda_bipe_controllonostro40cm.
 *
 * Model version      : 1.1515
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Thu Dec 19 15:07:13 2019
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

#include "ICARO3_Onda_bipe_controllonostro40cm.h"
#include "ICARO3_Onda_bipe_controllonostro40cm_private.h"

/* Block signals (auto storage) */
BlockIO_ICARO3_Onda_bipe_controllonostro40cm
  ICARO3_Onda_bipe_controllonostro40cm_B;

/* Block states (auto storage) */
D_Work_ICARO3_Onda_bipe_controllonostro40cm
  ICARO3_Onda_bipe_controllonostro40cm_DWork;

/* Real-time model */
RT_MODEL_ICARO3_Onda_bipe_controllonostro40cm
  ICARO3_Onda_bipe_controllonostro40cm_M_;
RT_MODEL_ICARO3_Onda_bipe_controllonostro40cm *const
  ICARO3_Onda_bipe_controllonostro40cm_M =
  &ICARO3_Onda_bipe_controllonostro40cm_M_;

/* Forward declaration for local functions */
static real32_T ICARO3_Onda_bipe_controllonostro40cm_norm(const real32_T x[3]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ICARO3_Onda_bipe_controllonostro40cm_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ICARO3_Onda_bipe_controllonostro40cm_M,
    1));
  eventFlags[2] = ((boolean_T)rtmStepTask(ICARO3_Onda_bipe_controllonostro40cm_M,
    2));
  eventFlags[3] = ((boolean_T)rtmStepTask(ICARO3_Onda_bipe_controllonostro40cm_M,
    3));
  eventFlags[4] = ((boolean_T)rtmStepTask(ICARO3_Onda_bipe_controllonostro40cm_M,
    4));
  eventFlags[5] = ((boolean_T)rtmStepTask(ICARO3_Onda_bipe_controllonostro40cm_M,
    5));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 4 */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[1] == 0) {
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_2 =
      (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[2] == 0);
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_4 =
      (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* tid 2 shares data with slower tid rate: 4 */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[2] == 0) {
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID2_4 =
      (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* tid 4 shares data with slower tid rate: 5 */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4] == 0) {
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID4_5 =
      (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[5] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[1])++;
  if ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[1]) > 4)
  {                                    /* Sample time: [0.005s, 0.0s] */
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[2])++;
  if ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[2]) > 9)
  {                                    /* Sample time: [0.01s, 0.0s] */
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[3])++;
  if ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[3]) > 19)
  {                                    /* Sample time: [0.02s, 0.0s] */
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[3] = 0;
  }

  (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4])++;
  if ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4]) > 99)
  {                                    /* Sample time: [0.1s, 0.0s] */
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[4] = 0;
  }

  (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[5])++;
  if ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[5]) > 999)
  {                                    /* Sample time: [1.0s, 0.0s] */
    ICARO3_Onda_bipe_controllonostro40cm_M->Timing.TaskCounters.TID[5] = 0;
  }
}

/*
 * Initial conditions for enable system:
 *    '<S35>/Subsystem'
 *    '<S36>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S42>/Subsystem'
 */
void ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Init
  (rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localDW,
   rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE = localP->DiscreteTimeIntegrator1_IC;
}

/*
 * Start for enable system:
 *    '<S35>/Subsystem'
 *    '<S36>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S42>/Subsystem'
 */
void ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Start
  (rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localDW,
   rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localP)
{
  /* InitializeConditions for Enabled SubSystem: '<S35>/Subsystem' */
  ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Init(localDW, localP);

  /* End of InitializeConditions for SubSystem: '<S35>/Subsystem' */
}

/*
 * Output and update for enable system:
 *    '<S35>/Subsystem'
 *    '<S36>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S42>/Subsystem'
 */
void ICARO3_Onda_bipe_controllonostro40cm_Subsystem(real32_T rtu_Enable, real_T
  rtu_In1, rtB_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localB,
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localDW,
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *localP)
{
  /* Outputs for Enabled SubSystem: '<S35>/Subsystem' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  if (rtu_Enable > 0.0F) {
    /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
    localB->DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;

    /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' */
    localB->DiscreteTimeIntegrator1 = localDW->DiscreteTimeIntegrator1_DSTATE;

    /* Product: '<S38>/Product1' */
    localB->Product1 = localB->DiscreteTimeIntegrator /
      localB->DiscreteTimeIntegrator1;

    /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * rtu_In1;

    /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S38>/Constant'
     */
    localDW->DiscreteTimeIntegrator1_DSTATE +=
      localP->DiscreteTimeIntegrator1_gainval * localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S35>/Subsystem' */
}

/*
 * Start for enable system:
 *    '<S80>/clock latch'
 *    '<Root>/clock latch'
 */
void ICARO3_Onda_bipe_controllonostro40cm_clocklatch_Start
  (rtB_clocklatch_ICARO3_Onda_bipe_controllonostro40cm *localB,
   rtP_clocklatch_ICARO3_Onda_bipe_controllonostro40cm *localP)
{
  /* VirtualOutportStart for Outport: '<S95>/Out' */
  localB->In = localP->Out_Y0;
}

/*
 * Output and update for enable system:
 *    '<S80>/clock latch'
 *    '<Root>/clock latch'
 */
void ICARO3_Onda_bipe_controllonostro40cm_clocklatch(real_T rtu_Enable, real_T
  rtu_In, rtB_clocklatch_ICARO3_Onda_bipe_controllonostro40cm *localB)
{
  /* Outputs for Enabled SubSystem: '<S80>/clock latch' incorporates:
   *  EnablePort: '<S95>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* Inport: '<S95>/In' */
    localB->In = rtu_In;
  }

  /* End of Outputs for SubSystem: '<S80>/clock latch' */
}

/*
 * Output and update for atomic system:
 *    '<S149>/Compensate for sensor mount _acc'
 *    '<S149>/Compensate for sensor mount _gyro'
 */
void ICARO3_Onda_bipe_controllonostr_Compensateforsensormount_acc(const real32_T
  rtu_u[3], rtB_Compensateforsensormount_acc_ICARO3_Onda_bipe_controllonostr
  *localB)
{
  static const real32_T b[9] = { -1.0F, -1.22464685E-16F, 0.0F, 1.22464685E-16F,
    -1.0F, 0.0F, 0.0F, 0.0F, 1.0F };

  int32_T i;

  /* MATLAB Function 'sensor and actuators interface/Processing/Compensate for sensor mount _acc': '<S151>:1' */
  /* matrice rotazione */
  /*  quadrotor with DJI F450 a = 135; */
  /*  esacopter with DJI F550 a = 90; */
  /* '<S151>:1:6' a = 180*(pi/180); */
  /* '<S151>:1:7' R=[cos(a) sin(a) 0;-sin(a) cos(a) 0; 0 0 1]; */
  /* '<S151>:1:9' y =R*u; */
  for (i = 0; i < 3; i++) {
    localB->y[i] = 0.0F;
    localB->y[i] += b[i] * rtu_u[0];
    localB->y[i] += b[i + 3] * rtu_u[1];
    localB->y[i] += b[i + 6] * rtu_u[2];
  }
}

/*
 * Output and update for atomic system:
 *    '<S174>/MATLAB Function compute gyroxyz1'
 *    '<S174>/MATLAB Function compute gyroxyz2'
 *    '<S174>/MATLAB Function compute gyroxyz3'
 *    '<S174>/MATLAB Function compute gyroxyz5'
 *    '<S176>/MATLAB Function compute gyroxyz1'
 *    '<S176>/MATLAB Function compute gyroxyz2'
 *    '<S176>/MATLAB Function compute gyroxyz3'
 *    '<S176>/MATLAB Function compute gyroxyz5'
 */
void ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1(const uint16_T
  rtu_u[2], rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
  *localB)
{
  /* MATLAB Function 'sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1': '<S177>:1' */
  /* '<S177>:1:3' y = bitor(bitshift(u(2), 8),u(1)); */
  localB->y = (uint16_T)((uint16_T)(rtu_u[1] << 8) | rtu_u[0]);
}

/*
 * Output and update for atomic system:
 *    '<S175>/MATLAB Function compute gyroxyz1'
 *    '<S175>/MATLAB Function compute gyroxyz5'
 */
void ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_k(const uint32_T
  rtu_u[4], rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_f
  *localB)
{
  uint32_T q0;
  uint32_T qY;

  /* MATLAB Function 'sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1': '<S181>:1' */
  /* '<S181>:1:3' y = bitshift(u(4), 24) + bitshift(u(3), 16)+ bitshift(u(2), 8)+u(1); */
  q0 = rtu_u[3] << 24U;
  qY = (rtu_u[2] << 16U) + q0;
  if (qY < q0) {
    qY = MAX_uint32_T;
  }

  q0 = (rtu_u[1] << 8U) + qY;
  if (q0 < qY) {
    q0 = MAX_uint32_T;
  }

  qY = q0 + rtu_u[0];
  if (qY < q0) {
    qY = MAX_uint32_T;
  }

  localB->y = qY;
}

/*
 * Output and update for atomic system:
 *    '<S194>/MATLAB Function compute gyroxyz1'
 *    '<S194>/MATLAB Function compute gyroxyz2'
 *    '<S194>/MATLAB Function compute gyroxyz3'
 *    '<S194>/MATLAB Function compute gyroxyz5'
 *    '<S200>/MATLAB Function compute gyroxyz1'
 *    '<S200>/MATLAB Function compute gyroxyz2'
 *    '<S200>/MATLAB Function compute gyroxyz3'
 *    '<S200>/MATLAB Function compute gyroxyz5'
 *    '<S201>/MATLAB Function compute gyroxyz1'
 *    '<S201>/MATLAB Function compute gyroxyz2'
 *    ...
 */
void ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b(uint16_T rtu_u,
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j *localB)
{
  /* MATLAB Function 'sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1': '<S205>:1' */
  /* '<S205>:1:3' y =uint8([0,0]); */
  localB->y[0] = 0U;
  localB->y[1] = 0U;

  /* '<S205>:1:4' y(1) = bitand(u,255); */
  localB->y[0] = (uint8_T)(rtu_u & 255);

  /* '<S205>:1:5' y(2) = bitshift(u,-8); */
  localB->y[1] = (uint8_T)((uint32_T)rtu_u >> 8);
}

/*
 * Output and update for atomic system:
 *    '<S194>/MATLAB Function compute gyroxyz4'
 *    '<S200>/MATLAB Function compute gyroxyz4'
 *    '<S201>/MATLAB Function compute gyroxyz4'
 */
void ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz4(const uint8_T
  rtu_u[2], const uint8_T rtu_u_j[2], const uint8_T rtu_u_g[2], const uint8_T
  rtu_u_b[2], rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost
  *localB)
{
  int32_T i;

  /* SignalConversion: '<S208>/TmpSignal ConversionAt SFunction Inport1' */
  localB->TmpSignalConversionAtSFunctionInport1[0] = rtu_u[0];
  localB->TmpSignalConversionAtSFunctionInport1[1] = rtu_u[1];
  localB->TmpSignalConversionAtSFunctionInport1[2] = rtu_u_j[0];
  localB->TmpSignalConversionAtSFunctionInport1[3] = rtu_u_j[1];
  localB->TmpSignalConversionAtSFunctionInport1[4] = rtu_u_g[0];
  localB->TmpSignalConversionAtSFunctionInport1[5] = rtu_u_g[1];
  localB->TmpSignalConversionAtSFunctionInport1[6] = rtu_u_b[0];
  localB->TmpSignalConversionAtSFunctionInport1[7] = rtu_u_b[1];

  /* MATLAB Function 'sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4': '<S208>:1' */
  /* '<S208>:1:3' y=uint8(zeros(1,8)); */
  for (i = 0; i < 8; i++) {
    localB->y[i] = 0U;
  }

  /* '<S208>:1:4' y(1)=u(1); */
  localB->y[0] = localB->TmpSignalConversionAtSFunctionInport1[0];

  /* '<S208>:1:5' y(2)=u(2); */
  localB->y[1] = localB->TmpSignalConversionAtSFunctionInport1[1];

  /* '<S208>:1:6' y(3)=u(3); */
  localB->y[2] = localB->TmpSignalConversionAtSFunctionInport1[2];

  /* '<S208>:1:7' y(4)=u(4); */
  localB->y[3] = localB->TmpSignalConversionAtSFunctionInport1[3];

  /* '<S208>:1:8' y(5)=u(5); */
  localB->y[4] = localB->TmpSignalConversionAtSFunctionInport1[4];

  /* '<S208>:1:9' y(6)=u(6); */
  localB->y[5] = localB->TmpSignalConversionAtSFunctionInport1[5];

  /* '<S208>:1:10' y(7)=u(7); */
  localB->y[6] = localB->TmpSignalConversionAtSFunctionInport1[6];

  /* '<S208>:1:11' y(8)=u(8); */
  localB->y[7] = localB->TmpSignalConversionAtSFunctionInport1[7];
}

/* Function for MATLAB Function: '<S30>/dcm_marg' */
static real32_T ICARO3_Onda_bipe_controllonostro40cm_norm(const real32_T x[3])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.17549435E-38F;
  absxk = (real32_T)fabs(x[0]);
  if (absxk > 1.17549435E-38F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.17549435E-38F;
    y = t * t;
  }

  absxk = (real32_T)fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = (real32_T)fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * (real32_T)sqrt(y);
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = (real32_T)atan2((real32_T)u0_0, (real32_T)u1_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = (rtNaNF);
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void ICARO3_Onda_bipe_controllonostro40cm_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  real32_T y;
  int32_T i;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function Block: <Root>/STM32_Config */

  /* RateTransition: '<S149>/Rate Transition18' */
  if (!(ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_semaphoreTaken
        != 0)) {
    for (i = 0; i < 7; i++) {
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer0[i] =
        ((uint16_T)0U);
    }
  }

  /* End of RateTransition: '<S149>/Rate Transition18' */

  /* RateTransition: '<S171>/Rate Transition18' */
  i = ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_ActiveBufIdx <<
    1;
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[0] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer[i];
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[1] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer[1 + i];

  /* MATLAB Function: '<S171>/typecast uin32 to single' */
  /* MATLAB Function 'sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single': '<S188>:1' */
  /* '<S188>:1:4' y = typecast(u,'single'); */
  memcpy(&y, &ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[0], 4U);
  ICARO3_Onda_bipe_controllonostro40cm_B.y_b = y;

  /* MATLAB Function: '<S171>/typecast uin32 to single1' */
  /* MATLAB Function 'sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1': '<S189>:1' */
  /* '<S189>:1:4' y = typecast(u,'single'); */
  memcpy(&y, &ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[1], 4U);
  ICARO3_Onda_bipe_controllonostro40cm_B.y_g = y;

  /* DiscretePulseGenerator: '<S13>/Pulse Generator1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.PulseGenerator1 =
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter <
     ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator1_Duty) &&
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter >= 0) ?
    ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator1_Amp : 0.0;
  if (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter >=
      ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator1_Period - 1.0) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter = 0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S13>/Pulse Generator1' */
  /* S-Function Block: <S13>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,
                    ICARO3_Onda_bipe_controllonostro40cm_B.PulseGenerator1);
}

/* Model step function for TID1 */
void ICARO3_Onda_bipe_controllonostro40cm_step1(void) /* Sample time: [0.005s, 0.0s] */
{
  real_T currentTime;
  uint16_T u[14];
  static const int8_T b[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  int32_T AC2;
  int32_T AC3;
  int32_T B1;
  int32_T B2;
  int32_T MB;
  int32_T MC;
  int32_T MD;
  uint16_T u_0[6];
  static const int8_T b_0[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_1[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_3[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T c[9] = { -1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real32_T acc[3];
  real32_T q1;
  real32_T q2;
  real32_T q3;
  real32_T q4;
  real32_T ib[3];
  real32_T mb[3];
  real32_T jb[3];
  real32_T c_0[9];
  real32_T b_q1;
  static const int8_T f[3] = { 0, 0, -1 };

  int32_T i;
  real32_T ib_0[9];
  real32_T jb_0[9];
  real32_T tmp[3];
  real32_T tmp_0[9];
  real32_T AC1_idx_2;
  real32_T mr_idx_0;
  real32_T mr_idx_1;
  real32_T q_idx_2;
  real32_T q_idx_3;
  uint32_T tmp_1;

  /* Step: '<S28>/Step' */
  currentTime = ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick1) *
                 0.005);
  if (currentTime < ICARO3_Onda_bipe_controllonostro40cm_P.Step_Time) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Step =
      ICARO3_Onda_bipe_controllonostro40cm_P.Step_Y0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Step =
      ICARO3_Onda_bipe_controllonostro40cm_P.Step_YFinal;
  }

  /* End of Step: '<S28>/Step' */

  /* Step: '<S28>/Step1' */
  currentTime = ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick1) *
                 0.005);
  if (currentTime < ICARO3_Onda_bipe_controllonostro40cm_P.Step1_Time) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Step1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Step1_Y0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Step1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Step1_YFinal;
  }

  /* End of Step: '<S28>/Step1' */

  /* Sum: '<S28>/Add' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Add =
    ICARO3_Onda_bipe_controllonostro40cm_B.Step -
    ICARO3_Onda_bipe_controllonostro40cm_B.Step1;

  /* DataTypeConversion: '<S28>/Data Type Conversion mx8' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Add;

  /* S-Function (sfun_I2C1_sensors_loop): '<S168>/I2C1 Sensors Loop' */
  wrap_I2C1_sensors_loop_output_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_P.bmp085accuracylevel_Value,
     &ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o2);

  /* DataTypeConversion: '<S149>/Data Type Conversion on i2c mag3' */
  for (i = 0; i < 14; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag3[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[i + 54];
  }

  /* End of DataTypeConversion: '<S149>/Data Type Conversion on i2c mag3' */

  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<Root>/1: HW 0: SIM'
   *  Constant: '<S150>/enable 0'
   *  Constant: '<S150>/enable all'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_P.HW0SIM_Value >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch4_Threshold) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enable0_Value;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[27];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[28];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[29];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[4] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[30];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[5] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[69];
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[2];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[3] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[3];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[4] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[4];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[5] =
      ICARO3_Onda_bipe_controllonostro40cm_P.enableall_Value[5];
  }

  /* End of Switch: '<S150>/Switch4' */

  /* MATLAB Function: '<S149>/MATLAB Function compute accxyz1' */
  for (i = 0; i < 14; i++) {
    u[i] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag3[i];
  }

  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function compute accxyz1': '<S156>:1' */
  /* '<S156>:1:3' if (mpu9150_gyroacc_enabled == 0) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[5] == 0) {
    /* '<S156>:1:4' u = u*0; */
    for (i = 0; i < 14; i++) {
      u[i] = 0U;
    }
  }

  /* map of MPU9150 scale factors  */
  /* ACCELEROMETER */
  /*  Full-Scale Range  */
  /*  AFS_SEL=0 ±2 g */
  /*  AFS_SEL=1 ±4 g */
  /*  AFS_SEL=2 ±8 g */
  /*  AFS_SEL=3 ±16 g */
  /*  ADC Word Length Output in two’s complement format 16 bits */
  /*  Sensitivity Scale Factor  */
  /*  AFS_SEL=0 16,384 LSB/g */
  /*  AFS_SEL=1 8,192 LSB/g */
  /*  AFS_SEL=2 4,096 LSB/g */
  /*  AFS_SEL=3 2,048 LSB/g */
  /*  */
  /* GYROSCOPE */
  /*  Full-Scale Range  */
  /*  FS_SEL=0 ±250 º/s */
  /*  FS_SEL=1 ±500 º/s */
  /*  FS_SEL=2 ±1000 º/s */
  /*  FS_SEL=3 ±2000 º/s */
  /*  Gyroscope ADC Word Length 16 bits */
  /*  Sensitivity Scale Factor  */
  /*  FS_SEL=0 131 LSB/(º/s) */
  /*  FS_SEL=1 65.5 LSB/(º/s) */
  /*  FS_SEL=2 32.8 LSB/(º/s) */
  /*  FS_SEL=3 16.4 LSB/(º/s) */
  /*  ax = decomp(bitshift(u(1), 8) + u(2))/16384.0*9.81; %2g */
  /*  ay = decomp(bitshift(u(3), 8) + u(4))/16384.0*9.81; */
  /*  az = decomp(bitshift(u(5), 8) + u(6))/16384.0*9.81; */
  /* '<S156>:1:37' ax = decomp(bitshift(u(1), 8) + u(2))/8192.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u[0] << 8) + u[1];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    i = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    i = (uint16_T)tmp_1;
  }

  /* 4g */
  /* '<S156>:1:38' ay = decomp(bitshift(u(3), 8) + u(4))/8192.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u[2] << 8) + u[3];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    AC2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    AC2 = (uint16_T)tmp_1;
  }

  /* '<S156>:1:39' az = decomp(bitshift(u(5), 8) + u(6))/8192.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u[4] << 8) + u[5];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    AC3 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    AC3 = (uint16_T)tmp_1;
  }

  /* '<S156>:1:41' temp = decomp(bitshift(u(7), 8) + u(8))/1; */
  tmp_1 = (uint32_T)(uint16_T)(u[6] << 8) + u[7];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    B1 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    B1 = (uint16_T)tmp_1;
  }

  /* unknown */
  /* '<S156>:1:43' gx = decomp(bitshift(u(9), 8) + u(10))/131.0*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u[8] << 8) + u[9];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    B2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    B2 = (uint16_T)tmp_1;
  }

  /*  rad/sec %131 = 250 deg/sec */
  /* '<S156>:1:44' gy = decomp(bitshift(u(11), 8) + u(12))/131.0*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u[10] << 8) + u[11];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    MB = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    MB = (uint16_T)tmp_1;
  }

  /* '<S156>:1:45' gz = decomp(bitshift(u(13), 8) + u(14))/131.0*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u[12] << 8) + u[13];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S156>:1:66' u = single(u); */
  /* '<S156>:1:68' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S156>:1:69' y = single(-65536 + u); */
    MC = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S156>:1:70' else */
    /* '<S156>:1:71' y = single(u); */
    MC = (uint16_T)tmp_1;
  }

  /* '<S156>:1:47' a_mpu9150 = [ax; ay; az]; */
  /* '<S156>:1:48' g_mpu9150 = [gx; gy; gz]; */
  /*  Convert a from mpu9150 axes to ICARO2 axes */
  /*    ipotesi di montaggio 1: test preliminari */
  /*        pettine allineato con asse X e chip sul lato di sotto  */
  /* OLD CONFIGURATION */
  /* a = [0 -1 0; 1 0 0; 0 0 1]*a_mpu9150; */
  /* g = [0 -1 0; 1 0 0; 0 0 1]*g_mpu9150; */
  /* NEW CONFIGURATION (24/04/2015) */
  /* '<S156>:1:58' a = [1 0 0; 0 -1 0; 0 0 -1]*a_mpu9150; */
  mr_idx_0 = (real32_T)i / 8192.0F * 9.81F;
  mr_idx_1 = (real32_T)AC2 / 8192.0F * 9.81F;
  AC1_idx_2 = (real32_T)AC3 / 8192.0F * 9.81F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.a_g[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_g[AC2] += (real32_T)b[AC2] *
      mr_idx_0;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_g[AC2] += (real32_T)b[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_g[AC2] += (real32_T)b[AC2 + 6] *
      AC1_idx_2;
  }

  /* '<S156>:1:59' g = [1 0 0; 0 -1 0; 0 0 -1]*g_mpu9150; */
  mr_idx_0 = (real32_T)B2 / 131.0F * 3.14159274F / 180.0F;
  mr_idx_1 = (real32_T)MB / 131.0F * 3.14159274F / 180.0F;
  AC1_idx_2 = (real32_T)MC / 131.0F * 3.14159274F / 180.0F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.g[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.g[AC2] += (real32_T)b[AC2] * mr_idx_0;
    ICARO3_Onda_bipe_controllonostro40cm_B.g[AC2] += (real32_T)b[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.g[AC2] += (real32_T)b[AC2 + 6] *
      AC1_idx_2;
  }

  /* '<S156>:1:60' t=temp; */
  ICARO3_Onda_bipe_controllonostro40cm_B.t = (real32_T)B1;

  /* End of MATLAB Function: '<S149>/MATLAB Function compute accxyz1' */

  /* MATLAB Function: '<S149>/Compensate for sensor mount _acc' */
  ICARO3_Onda_bipe_controllonostr_Compensateforsensormount_acc
    (ICARO3_Onda_bipe_controllonostro40cm_B.a_g,
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_acc);

  /* DataTypeConversion: '<S149>/Data Type Conversion7' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_acc.y[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_acc.y[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_acc.y[2];

  /* Gain: '<Root>/Gain1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[0] =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain1_Gain_a *
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[1] =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain1_Gain_a *
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[2] =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain1_Gain_a *
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7[2];

  /* Outputs for Enabled SubSystem: '<S34>/Subsystem' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 > 0.0F) {
    /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator_p =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE_e;

    /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator1_p =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE_i;

    /* Product: '<S37>/Product1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Product1_f =
      ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator_p /
      ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator1_p;

    /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE_e +=
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator_gainval *
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[0];

    /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S37>/Constant'
     */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE_i +=
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator1_gainval *
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S34>/Subsystem' */

  /* Switch: '<S34>/Switch2' incorporates:
   *  Constant: '<S34>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_i) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value;
  } else {
    /* Sum: '<S34>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_dm =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[0] -
      ICARO3_Onda_bipe_controllonostro40cm_B.Product1_f;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2 =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_dm;
  }

  /* End of Switch: '<S34>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S35>/Subsystem' */
  ICARO3_Onda_bipe_controllonostro40cm_Subsystem
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8,
     ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[1],
     &ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_g,
     &ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_g,
     (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
     &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_g);

  /* End of Outputs for SubSystem: '<S35>/Subsystem' */

  /* Switch: '<S35>/Switch2' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_d) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_p =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_b;
  } else {
    /* Sum: '<S35>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_g =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[1] -
      ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_g.Product1;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_p =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_g;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S36>/Subsystem' */
  ICARO3_Onda_bipe_controllonostro40cm_Subsystem
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8,
     ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[2],
     &ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_p,
     &ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_p,
     (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
     &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_p);

  /* End of Outputs for SubSystem: '<S36>/Subsystem' */

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S36>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_d3) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_d =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_m;
  } else {
    /* Sum: '<S36>/Sum1' incorporates:
     *  Constant: '<S36>/Constant2'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_d4 =
      (ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[2] -
       ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_p.Product1) -
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant2_Value;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_d =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_d4;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* DataTypeConversion: '<S3>/Data Type Conversion mx1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2;
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_p;
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_d;

  /* RateTransition: '<Root>/Rate Transition49' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_2) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[0] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[1] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[2] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition49' */

  /* MATLAB Function: '<S149>/Compensate for sensor mount _gyro' */
  ICARO3_Onda_bipe_controllonostr_Compensateforsensormount_acc
    (ICARO3_Onda_bipe_controllonostro40cm_B.g,
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_gyro);

  /* DataTypeConversion: '<S149>/Data Type Conversion9' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_gyro.y[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_gyro.y[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_Compensateforsensormount_gyro.y[2];

  /* Outputs for Enabled SubSystem: '<S40>/Subsystem' incorporates:
   *  EnablePort: '<S43>/Enable'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 > 0.0F) {
    /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE;

    /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator1 =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE;

    /* Product: '<S43>/Product1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Product1_d =
      ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator /
      ICARO3_Onda_bipe_controllonostro40cm_B.DiscreteTimeIntegrator1;

    /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE +=
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator_gainval_b *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[0];

    /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S43>/Constant'
     */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE +=
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator1_gainval_j *
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_c;
  }

  /* End of Outputs for SubSystem: '<S40>/Subsystem' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  Constant: '<S40>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_a) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_o =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_o;
  } else {
    /* Sum: '<S40>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_km =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[0] -
      ICARO3_Onda_bipe_controllonostro40cm_B.Product1_d;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_o =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_km;
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem' */
  ICARO3_Onda_bipe_controllonostro40cm_Subsystem
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8,
     ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[1],
     &ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_l,
     &ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_l,
     (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
     &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_l);

  /* End of Outputs for SubSystem: '<S41>/Subsystem' */

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_f) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_pz =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_d;
  } else {
    /* Sum: '<S41>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_f =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[1] -
      ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_l.Product1;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_pz =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_f;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S42>/Subsystem' */
  ICARO3_Onda_bipe_controllonostro40cm_Subsystem
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8,
     ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[2],
     &ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_o,
     &ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_o,
     (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
     &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_o);

  /* End of Outputs for SubSystem: '<S42>/Subsystem' */

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S42>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx8 >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold_j) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_n =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_a;
  } else {
    /* Sum: '<S42>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_k =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[2] -
      ICARO3_Onda_bipe_controllonostro40cm_B.Subsystem_o.Product1;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_n =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_k;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* DataTypeConversion: '<S3>/Data Type Conversion mx2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_o;
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_pz;
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_n;

  /* Outputs for Enabled SubSystem: '<S3>/Attitude Filter ADIS' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Step1 > 0.0) {
    if (!ICARO3_Onda_bipe_controllonostro40cm_DWork.AttitudeFilterADIS_MODE) {
      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[0] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[0];
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[1] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[1];
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[2];
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[3] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[3];

      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[0] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[1] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay3' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[0] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[1] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;

      /* InitializeConditions for MATLAB Function: '<S30>/dcm_marg' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.ini_not_empty = false;
      ICARO3_Onda_bipe_controllonostro40cm_DWork.AttitudeFilterADIS_MODE = true;
    }

    /* UnitDelay: '<S30>/Unit Delay1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[0] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[1] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[2] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[2];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[3] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[3];

    /* UnitDelay: '<S30>/Unit Delay2' */
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[0] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[1] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[2] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[2];

    /* UnitDelay: '<S30>/Unit Delay3' */
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[0] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[1] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[2] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[2];

    /* Sum: '<S27>/Sum' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[0] -
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_dr[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[1] -
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_dr[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx1[2] -
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_dr[2];

    /* MATLAB Function: '<S30>/dcm_marg' */
    acc[0] = ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[0];
    acc[1] = ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[1];
    acc[2] = ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h[2];
    q1 = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[0];
    q2 = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[1];
    AC1_idx_2 = ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[0];
    q4 = ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[1];
    q_idx_2 = ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[2];
    q_idx_3 = ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay1[3];

    /* MATLAB Function 'ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg': '<S31>:1' */
    /*  mode == 0: magnetos' errors don't affect roll and pitch angles */
    /*  mode == 1: standard implementation, roll, pitch and yaw depend on */
    /*  acceleroters and magnetos in the same measure */
    /* '<S31>:1:9' mode = 0; */
    /*  Magnetos and accelerometers MUST have non null norm, if they have null */
    /*  norm an error occurred and filter probably will get confused, adjust mag */
    /*  and acc values to try to avoid filter problems.  */
    /* '<S31>:1:15' if (norm(acc) < 1e-4) */
    if (ICARO3_Onda_bipe_controllonostro40cm_norm
        (ICARO3_Onda_bipe_controllonostro40cm_B.Sum_h) < 0.0001) {
      /* '<S31>:1:16' acc = single([0; 0; -9.81]); */
      acc[0] = 0.0F;
      acc[1] = 0.0F;
      acc[2] = -9.81F;
    }

    /* '<S31>:1:19' if (norm(mag) < 1e-4) */
    if (ICARO3_Onda_bipe_controllonostro40cm_norm
        (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49) < 0.0001) {
      /* mag = single([0.234; 0.008; 0.404]); */
      /* '<S31>:1:21' mag = single([0; 0.5; 0]); */
      q1 = 0.0F;
      q2 = 0.5F;
    }

    /*  Init quaternion using the first accelerometers and magnetometers reading */
    /*  in triad algorithm. */
    /* '<S31>:1:28' if (isempty(ini)) */
    if (!ICARO3_Onda_bipe_controllonostro40cm_DWork.ini_not_empty) {
      /* '<S31>:1:29' q = qtriad(acc, mag); */
      /*  Triad algorithm */
      /* '<S31>:1:162' ib = acc/norm(acc); */
      b_q1 = ICARO3_Onda_bipe_controllonostro40cm_norm(acc);
      ib[0] = acc[0] / b_q1;
      ib[1] = acc[1] / b_q1;
      ib[2] = acc[2] / b_q1;

      /* '<S31>:1:163' ir = [0; 0; -1]; */
      /* mb = mag; */
      /* mr = [0.234; 0.008; 0.404]; */
      /*  modifiche per vettore tag */
      /* '<S31>:1:167' mb = [0; sqrt((mag(1)^2) + mag(2)^2); 0]; */
      mb[1] = (real32_T)sqrt(q1 * q1 + q2 * q2);

      /* '<S31>:1:168' mr = [mag(1); mag(2); 0]; */
      /* '<S31>:1:169' jb = cross(ib,mb); */
      jb[0] = ib[1] * 0.0F - ib[2] * mb[1];
      jb[1] = ib[2] * 0.0F - ib[0] * 0.0F;
      jb[2] = ib[0] * mb[1] - ib[1] * 0.0F;

      /* '<S31>:1:170' jb = jb/norm(jb); */
      b_q1 = ICARO3_Onda_bipe_controllonostro40cm_norm(jb);
      jb[0] /= b_q1;
      jb[1] /= b_q1;
      mr_idx_1 = jb[2] / b_q1;

      /* '<S31>:1:171' jr = cross(ir,mr); */
      mb[0] = 0.0F - (-q2);
      mb[1] = -q1;
      mb[2] = 0.0F * q2 - 0.0F * q1;

      /* '<S31>:1:172' jr = jr/norm(jr); */
      b_q1 = ICARO3_Onda_bipe_controllonostro40cm_norm(mb);
      mb[0] = (0.0F - (-q2)) / b_q1;
      mb[1] = -q1 / b_q1;
      mr_idx_0 = mb[2] / b_q1;
      mb[2] = mr_idx_0;

      /* '<S31>:1:173' kb = cross(ib,jb); */
      /* '<S31>:1:174' kr = cross(ir,jr); */
      /* '<S31>:1:175' c = (ib*ir' + jb*jr' + kb*kr')'; */
      for (AC2 = 0; AC2 < 3; AC2++) {
        ib_0[AC2] = ib[0] * (real32_T)f[AC2];
        ib_0[AC2 + 3] = ib[1] * (real32_T)f[AC2];
        ib_0[AC2 + 6] = ib[2] * (real32_T)f[AC2];
      }

      for (AC2 = 0; AC2 < 3; AC2++) {
        jb_0[AC2] = jb[0] * mb[AC2];
        jb_0[AC2 + 3] = jb[1] * mb[AC2];
        jb_0[AC2 + 6] = mr_idx_1 * mb[AC2];
      }

      tmp[0] = 0.0F * mr_idx_0 - (-mb[1]);
      tmp[1] = -mb[0] - 0.0F * mr_idx_0;
      tmp[2] = 0.0F * mb[1] - 0.0F * mb[0];
      AC1_idx_2 = ib[1] * mr_idx_1 - ib[2] * jb[1];
      mr_idx_0 = ib[2] * jb[0] - ib[0] * mr_idx_1;
      mr_idx_1 = ib[0] * jb[1] - ib[1] * jb[0];
      for (AC2 = 0; AC2 < 3; AC2++) {
        c_0[AC2] = (ib_0[AC2] + jb_0[AC2]) + AC1_idx_2 * tmp[AC2];
        c_0[AC2 + 3] = (ib_0[AC2 + 3] + jb_0[AC2 + 3]) + mr_idx_0 * tmp[AC2];
        c_0[AC2 + 6] = (ib_0[AC2 + 6] + jb_0[AC2 + 6]) + mr_idx_1 * tmp[AC2];
      }

      /* '<S31>:1:177' q1 = 0.5*sqrt(1+c(1,1)+c(2,2)+c(3,3)); */
      b_q1 = (real32_T)sqrt(((1.0F + c_0[0]) + c_0[4]) + c_0[8]) * 0.5F;

      /* '<S31>:1:178' q2 = 0.25/q1*(c(3,2)-c(2,3)); */
      /* '<S31>:1:179' q3 = 0.25/q1*(c(1,3)-c(3,1)); */
      /* '<S31>:1:180' q4 = 0.25/q1*(c(2,1)-c(1,2)); */
      /* '<S31>:1:182' q_out = [q1 q2 q3 q4]'; */
      AC1_idx_2 = b_q1;
      q4 = 0.25F / b_q1 * (c_0[5] - c_0[7]);
      q_idx_2 = 0.25F / b_q1 * (c_0[6] - c_0[2]);
      q_idx_3 = 0.25F / b_q1 * (c_0[1] - c_0[3]);

      /* '<S31>:1:30' ini = 1; */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.ini_not_empty = true;
    }

    /* '<S31>:1:33' q1 = q(1); */
    /* '<S31>:1:34' q2 = q(2); */
    /* '<S31>:1:35' q3 = q(3); */
    /* '<S31>:1:36' q4 = q(4); */
    /* '<S31>:1:39' gx = gyro(1); */
    /* '<S31>:1:40' gy = gyro(2); */
    /* '<S31>:1:41' gz = gyro(3); */
    /* '<S31>:1:43' ax = acc(1); */
    /* '<S31>:1:44' ay = acc(2); */
    /* '<S31>:1:45' az = acc(3); */
    /* '<S31>:1:47' mx = mag(1); */
    /* '<S31>:1:48' my = mag(2); */
    /* '<S31>:1:49' mz = mag(3); */
    /*  Rt rotates NED to body, and obviously converts body cordinates into ned */
    /*  coordinates. */
    /* '<S31>:1:54' Rt = [1 - 2*q3^2 - 2*q4^2, 2*(q2*q3-q1*q4), 2*(q2*q4+q1*q3); */
    /* '<S31>:1:55'      2*(q2*q3+q1*q4), 1 - 2*q2^2 - 2*q4^2, 2*(q3*q4-q1*q2); */
    /* '<S31>:1:56'      2*(q2*q4-q1*q3), 2*(q3*q4+q1*q2), 1 - 2*q2^2 - 2*q3^2]; */
    c_0[0] = (1.0F - q_idx_2 * q_idx_2 * 2.0F) - q_idx_3 * q_idx_3 * 2.0F;
    c_0[3] = (q4 * q_idx_2 - AC1_idx_2 * q_idx_3) * 2.0F;
    c_0[6] = (q4 * q_idx_3 + AC1_idx_2 * q_idx_2) * 2.0F;
    c_0[1] = (q4 * q_idx_2 + AC1_idx_2 * q_idx_3) * 2.0F;
    c_0[4] = (1.0F - q4 * q4 * 2.0F) - q_idx_3 * q_idx_3 * 2.0F;
    c_0[7] = (q_idx_2 * q_idx_3 - AC1_idx_2 * q4) * 2.0F;
    c_0[2] = (q4 * q_idx_3 - AC1_idx_2 * q_idx_2) * 2.0F;
    c_0[5] = (q_idx_2 * q_idx_3 + AC1_idx_2 * q4) * 2.0F;
    c_0[8] = (1.0F - q4 * q4 * 2.0F) - q_idx_2 * q_idx_2 * 2.0F;

    /*  Filter implementation, see article for details */
    /*  h = Rt*[mx; my; mz]; % mag in body frame */
    /* '<S31>:1:61' h = [mx; my; mz]; */
    /*  tag in Deca frame */
    /* '<S31>:1:63' bx = sqrt(h(1)^2+h(2)^2); */
    /* '<S31>:1:64' bz = abs(h(3)); */
    /* '<S31>:1:66' norm_a = sqrt(ax^2+ay^2+az^2+eps); */
    b_q1 = (real32_T)sqrt(((acc[0] * acc[0] + acc[1] * acc[1]) + acc[2] * acc[2])
                          + 2.22044605E-16F);

    /* '<S31>:1:67' e_a = cross([ax ay az]'/norm_a, Rt'*[0 0 -1]'); */
    ib[2] = acc[2] / b_q1;
    for (AC2 = 0; AC2 < 3; AC2++) {
      mb[AC2] = -c_0[3 * AC2 + 2] + (c_0[3 * AC2 + 1] * 0.0F + c_0[3 * AC2] *
        0.0F);
    }

    mr_idx_0 = acc[1] / b_q1 * mb[2] - ib[2] * mb[1];
    mr_idx_1 = ib[2] * mb[0] - acc[0] / b_q1 * mb[2];

    /*  norm_m = sqrt(mx^2+my^2+mz^2+eps); */
    /* '<S31>:1:69' norm_m = sqrt(mx^2+my^2+eps); */
    b_q1 = (real32_T)sqrt((q1 * q1 + q2 * q2) + 2.22044605E-16F);

    /* '<S31>:1:70' norm_b = sqrt(bx^2+bz^2+eps); */
    /*  e_m = cross([mx my mz]'/norm_m, Rt'*[bx 0 bz]'/norm_b); */
    /* '<S31>:1:72' e_m = -1.0*cross(Rt'*[mx my 0]'/norm_m, [1 0 0]'); */
    for (AC2 = 0; AC2 < 3; AC2++) {
      ib[AC2] = ((c_0[3 * AC2 + 1] * q2 + c_0[3 * AC2] * q1) + c_0[3 * AC2 + 2] *
                 0.0F) / b_q1;
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.e_m[0] = -(ib[1] * 0.0F - ib[2] *
      0.0F);
    ICARO3_Onda_bipe_controllonostro40cm_B.e_m[1] = -(ib[2] - ib[0] * 0.0F);
    ICARO3_Onda_bipe_controllonostro40cm_B.e_m[2] = -(ib[0] * 0.0F - ib[1]);

    /*  e_m = cross([mx my 0]'/norm([mx my 0]), Rt'*[0 1 0]'); */
    /* '<S31>:1:75' if (mode == 0) */
    /* '<S31>:1:77' e_int_out_a = e_int_a + T*[e_a(1:2); 0]; */
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST * mr_idx_0 +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST * mr_idx_1 +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST * 0.0F +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay2[2];

    /* '<S31>:1:78' e_int_out_m = e_int_m + T*[0; 0; e_m(3)]; */
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST * 0.0F +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST * 0.0F +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.ST *
      ICARO3_Onda_bipe_controllonostro40cm_B.e_m[2] +
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitDelay3[2];

    /*      e_int_out_a = e_int_a + T*[e_a(1); e_a(2); e_a(3)]; */
    /*      e_int_out_m = e_int_m + T*[e_m(1:2); 0]; */
    /* '<S31>:1:84' g = [gx; gy; gz] + Kp*[e_a(1:2); e_m(3)] + Ki*(e_int_out_a + e_int_out_m); */
    mb[0] = (ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Kp * mr_idx_0
             + ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[0])
      + (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[0] +
         ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[0]) *
      ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;
    mb[1] = (ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Kp * mr_idx_1
             + ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[1])
      + (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[1] +
         ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[1]) *
      ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;
    mb[2] = (ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Kp *
             ICARO3_Onda_bipe_controllonostro40cm_B.e_m[2] +
             ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[2]) +
      (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[2] +
       ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[2]) *
      ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;

    /* '<S31>:1:95' gx = g(1); */
    /* '<S31>:1:96' gy = g(2); */
    /* '<S31>:1:97' gz = g(3); */
    /*  Quaternion integration */
    /* '<S31>:1:101' dq1 = (-q2*gx - q3*gy - q4*gz)/2; */
    /* '<S31>:1:102' dq2 = (q1*gx + q3*gz - q4*gy)/2; */
    /* '<S31>:1:103' dq3 = (q1*gy - q2*gz + q4*gx)/2; */
    /* '<S31>:1:104' dq4 = (q1*gz + q2*gy - q3*gx)/2; */
    /* '<S31>:1:106' q1 = q1 + dq1*T; */
    q1 = ((-q4 * mb[0] - q_idx_2 * mb[1]) - q_idx_3 * mb[2]) / 2.0F *
      ICARO3_Onda_bipe_controllonostro40cm_P.ST + AC1_idx_2;

    /* '<S31>:1:107' q2 = q2 + dq2*T; */
    q2 = ((AC1_idx_2 * mb[0] + q_idx_2 * mb[2]) - q_idx_3 * mb[1]) / 2.0F *
      ICARO3_Onda_bipe_controllonostro40cm_P.ST + q4;

    /* '<S31>:1:108' q3 = q3 + dq3*T; */
    q3 = ((AC1_idx_2 * mb[1] - q4 * mb[2]) + q_idx_3 * mb[0]) / 2.0F *
      ICARO3_Onda_bipe_controllonostro40cm_P.ST + q_idx_2;

    /* '<S31>:1:109' q4 = q4 + dq4*T; */
    q4 = ((AC1_idx_2 * mb[2] + q4 * mb[1]) - q_idx_2 * mb[0]) / 2.0F *
      ICARO3_Onda_bipe_controllonostro40cm_P.ST + q_idx_3;

    /*  Quaternion normalization */
    /* '<S31>:1:113' norm_q = sqrt(q1*q1 + q2*q2 + q3*q3 + q4*q4); */
    b_q1 = (real32_T)sqrt(((q1 * q1 + q2 * q2) + q3 * q3) + q4 * q4);

    /* '<S31>:1:114' q1 = q1 / norm_q; */
    q1 /= b_q1;

    /* '<S31>:1:115' q2 = q2 / norm_q; */
    q2 /= b_q1;

    /* '<S31>:1:116' q3 = q3 / norm_q; */
    q3 /= b_q1;

    /* '<S31>:1:117' q4 = q4 / norm_q; */
    q4 /= b_q1;

    /* '<S31>:1:119' q_out = [q1; q2; q3; q4]; */
    /*  Rt rotates NED to body, and obviously converts body cordinates into ned */
    /*  coordinates. */
    /* '<S31>:1:124' Rt = [1 - 2*q3^2 - 2*q4^2, 2*(q2*q3-q1*q4), 2*(q2*q4+q1*q3); */
    /* '<S31>:1:125'      2*(q2*q3+q1*q4), 1 - 2*q2^2 - 2*q4^2, 2*(q3*q4-q1*q2); */
    /* '<S31>:1:126'      2*(q2*q4-q1*q3), 2*(q3*q4+q1*q2), 1 - 2*q2^2 - 2*q3^2]; */
    /*  Obtain rpy angles */
    /* '<S31>:1:130' psi = atan2(2*(q2*q3+q1*q4), 1 - 2*q3^2 - 2*q4^2); */
    /* '<S31>:1:131' theta = atan2(-2*(q2*q4-q1*q3), sqrt((2*(q3*q4+q1*q2))^2 + (1 - 2*q2^2 - 2*q3^2)^2)); */
    mr_idx_0 = (q3 * q4 + q1 * q2) * 2.0F;
    b_q1 = (1.0F - q2 * q2 * 2.0F) - q3 * q3 * 2.0F;

    /* '<S31>:1:132' phi = atan2(2*(q3*q4+q1*q2), 1 - 2*q2^2 - 2*q3^2); */
    /*  Compute accelerations in NED */
    /* '<S31>:1:136' a_ned = Rt*acc; */
    /* '<S31>:1:138' euler_out = [phi; theta; psi]; */
    /*  Suppose that mean of integral correction is bias value */
    /* '<S31>:1:142' biases = -Ki*(e_int_out_a + e_int_out_m); */
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[0] = rt_atan2f_snf((q3 * q4
      + q1 * q2) * 2.0F, (1.0F - q2 * q2 * 2.0F) - q3 * q3 * 2.0F);
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[1] = rt_atan2f_snf((q2 * q4
      - q1 * q3) * -2.0F, (real32_T)sqrt(mr_idx_0 * mr_idx_0 + b_q1 * b_q1));
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[2] = rt_atan2f_snf((q2 * q3
      + q1 * q4) * 2.0F, (1.0F - q3 * q3 * 2.0F) - q4 * q4 * 2.0F);
    tmp_0[0] = (1.0F - q3 * q3 * 2.0F) - q4 * q4 * 2.0F;
    tmp_0[3] = (q2 * q3 - q1 * q4) * 2.0F;
    tmp_0[6] = (q2 * q4 + q1 * q3) * 2.0F;
    tmp_0[1] = (q2 * q3 + q1 * q4) * 2.0F;
    tmp_0[4] = (1.0F - q2 * q2 * 2.0F) - q4 * q4 * 2.0F;
    tmp_0[7] = (q3 * q4 - q1 * q2) * 2.0F;
    tmp_0[2] = (q2 * q4 - q1 * q3) * 2.0F;
    tmp_0[5] = (q3 * q4 + q1 * q2) * 2.0F;
    tmp_0[8] = (1.0F - q2 * q2 * 2.0F) - q3 * q3 * 2.0F;
    for (AC2 = 0; AC2 < 3; AC2++) {
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[AC2] = 0.0F;
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[AC2] += tmp_0[AC2] * acc[0];
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[AC2] += tmp_0[AC2 + 3] * acc
        [1];
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[AC2] += tmp_0[AC2 + 6] * acc
        [2];
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[0] = q1;
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[1] = q2;
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[2] = q3;
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[3] = q4;
    ICARO3_Onda_bipe_controllonostro40cm_B.biases[0] =
      (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[0] +
       ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[0]) *
      -ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;
    ICARO3_Onda_bipe_controllonostro40cm_B.biases[1] =
      (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[1] +
       ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[1]) *
      -ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;
    ICARO3_Onda_bipe_controllonostro40cm_B.biases[2] =
      (ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[2] +
       ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[2]) *
      -ICARO3_Onda_bipe_controllonostro40cm_P.DCM_MARG_QUAT_Ki;

    /* End of MATLAB Function: '<S30>/dcm_marg' */

    /* Update for UnitDelay: '<S30>/Unit Delay1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.q_out[0];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.q_out[1];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.q_out[2];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.q_out[3];

    /* Update for UnitDelay: '<S30>/Unit Delay2' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[0];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[1];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_a[2];

    /* Update for UnitDelay: '<S30>/Unit Delay3' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[0];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[1];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.e_int_out_m[2];
  } else {
    if (ICARO3_Onda_bipe_controllonostro40cm_DWork.AttitudeFilterADIS_MODE) {
      ICARO3_Onda_bipe_controllonostro40cm_DWork.AttitudeFilterADIS_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S3>/Attitude Filter ADIS' */

  /* DataTypeConversion: '<S3>/Data Type Conversion mx10' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[2];

  /* RateTransition: '<Root>/Rate Transition46' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_2) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition46 =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition46' */

  /* RateTransition: '<Root>/Rate Transition54' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx10[2];

    /* RateTransition: '<Root>/Rate Transition53' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9[2];

    /* RateTransition: '<Root>/Rate Transition52' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1[2];

    /* RateTransition: '<Root>/Rate Transition56' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition54' */

  /* DataTypeConversion: '<S3>/Data Type Conversion mx17' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx2[2];

  /* RateTransition: '<Root>/Rate Transition55' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx17[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition55' */

  /* RateTransition: '<Root>/Rate Transition47' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_2) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition47 =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition47_Buffer0;

    /* RateTransition: '<Root>/Rate Transition48' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition48 =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition48_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition47' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtreproduce PWM9Inport1' incorporates:
   *  Constant: '<Root>/Constant32'
   *  Constant: '<Root>/Constant33'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtreproducePWM9Inport1
    [0] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition47;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtreproducePWM9Inport1
    [1] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition48;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtreproducePWM9Inport1
    [2] = ICARO3_Onda_bipe_controllonostro40cm_P.Constant33_Value;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtreproducePWM9Inport1
    [3] = ICARO3_Onda_bipe_controllonostro40cm_P.Constant32_Value;

  /* S-Function (sfun_PWM_servomotor): '<Root>/reproduce PWM9' */
  wrap_PWM_servomotor_output_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtreproducePWM9Inport1
     [0],1.0,1.0,1.0,1.0);
  for (i = 0; i < 12; i++) {
    /* SignalConversion: '<S159>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S149>/MATLAB Function compute magxyz2'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1[
      i] = 0.0;
  }

  /* MATLAB Function: '<S149>/MATLAB Function compute magxyz2' */
  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function compute magxyz2': '<S159>:1' */
  /* % */
  /* %  Mange settings for different radios */
  /* % */
  /*  RC_TRPY_refs */
  /*  1. throttle  -> up = 1, down = 0 */
  /*  2. roll      -> left = -1, right = 1 */
  /*  3. pitch     -> up = -1, down = 1 */
  /*  4. yaw       -> left = -1, right = 1 */
  /* '<S159>:1:18' if (1) */
  /* GENERIC RADIO WITH PARAMETRS  */
  /* '<S159>:1:19' RC_TRPY_refs = [INV_THROTTLE_RANGE*(pwms(THROTTLE_IDX) - THROTTLE_DOWN); */
  /* '<S159>:1:20'                   INV_ROLL_RANGE*(pwms(ROLL_IDX) - ROLL_MID); */
  /* '<S159>:1:21'                   INV_PITCH_RANGE*(pwms(PITCH_IDX) - PITCH_MID); */
  /* '<S159>:1:22'                   INV_YAW_RANGE*(pwms(YAW_IDX) - YAW_MID);]; */
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[0] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [(int32_T)ICARO3_Onda_bipe_controllonostro40cm_P.THROTTLE_IDX - 1] -
     ICARO3_Onda_bipe_controllonostro40cm_P.THROTTLE_DOWN) *
    ICARO3_Onda_bipe_controllonostro40cm_P.INV_THROTTLE_RANGE;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[1] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [(int32_T)ICARO3_Onda_bipe_controllonostro40cm_P.ROLL_IDX - 1] -
     ICARO3_Onda_bipe_controllonostro40cm_P.ROLL_MID) *
    ICARO3_Onda_bipe_controllonostro40cm_P.INV_ROLL_RANGE;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[2] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [(int32_T)ICARO3_Onda_bipe_controllonostro40cm_P.PITCH_IDX - 1] -
     ICARO3_Onda_bipe_controllonostro40cm_P.PITCH_MID) *
    ICARO3_Onda_bipe_controllonostro40cm_P.INV_PITCH_RANGE;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[3] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [(int32_T)ICARO3_Onda_bipe_controllonostro40cm_P.YAW_IDX - 1] -
     ICARO3_Onda_bipe_controllonostro40cm_P.YAW_MID) *
    ICARO3_Onda_bipe_controllonostro40cm_P.INV_YAW_RANGE;

  /* PATCH: this patch nulls the yaw command when the throttle */
  /*        is below a minimumk value in oredr to allow a safe arm, disarm */
  /*        procedure */
  /* '<S159>:1:28' if pwms(THROTTLE_IDX) < THROTTLE_LOW_THRES */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
      [(int32_T)ICARO3_Onda_bipe_controllonostro40cm_P.THROTTLE_IDX - 1] <
      ICARO3_Onda_bipe_controllonostro40cm_P.THROTTLE_LOW_THRES) {
    /* '<S159>:1:29' RC_TRPY_refs(4) = 0; */
    ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[3] = 0.0;
  }

  /* '<S159>:1:34' if (0) */
  /* '<S159>:1:50' if (0) */
  /* '<S159>:1:67' if (0) */
  /*  all other channels: 1100 usec = > 0, 2100 usec => 1  */
  /* '<S159>:1:85' RC_aux_channels =  [(pwms(5) - 1100)/1000; */
  /* '<S159>:1:86'               (pwms(6) - 1100)/1000; */
  /* '<S159>:1:87'               (pwms(7) - 1100)/1000; */
  /* '<S159>:1:88'               (pwms(8) - 1100)/1000; */
  /* '<S159>:1:89'               (pwms(9) - 1100)/1000; */
  /* '<S159>:1:90'               (pwms(10) - 1100)/1000; */
  /* '<S159>:1:91'               (pwms(11) - 1100)/1000; */
  /* '<S159>:1:92'               (pwms(12) - 1100)/1000]; */
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[0] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [4] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[1] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [5] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[2] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [6] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[3] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [7] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[4] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [8] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[5] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [9] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[6] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [10] - 1100.0) / 1000.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.RC_aux_channels[7] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1
     [11] - 1100.0) / 1000.0;

  /* RateTransition: '<S149>/Rate Transition6' */
  if (!(ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_semaphoreTaken
        != 0)) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_Buffer0[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[0];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_Buffer0[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[1];
  }

  /* End of RateTransition: '<S149>/Rate Transition6' */

  /* RateTransition: '<S149>/Rate Transition5' */
  if (!(ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_semaphoreTaken
        != 0)) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[2];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[3];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[4];
  }

  /* End of RateTransition: '<S149>/Rate Transition5' */

  /* DataTypeConversion: '<S160>/Data Type Conversion' */
  for (i = 0; i < 22; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[i + 32];
  }

  /* End of DataTypeConversion: '<S160>/Data Type Conversion' */

  /* MATLAB Function: '<S160>/MATLAB Function1' */
  /* MATLAB Function 'sensor and actuators interface/Processing/compute_parameters/MATLAB Function1': '<S164>:1' */
  /* '<S164>:1:4' AC1 = decomp(bitshift(bytes(1), 8) + bytes(2)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[0] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[1];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    i = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    i = (uint16_T)tmp_1;
  }

  /* '<S164>:1:5' AC2 = decomp(bitshift(bytes(3), 8) + bytes(4)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[2] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[3];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    AC2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    AC2 = (uint16_T)tmp_1;
  }

  /* '<S164>:1:6' AC3 = decomp(bitshift(bytes(5), 8) + bytes(6)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[4] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[5];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    AC3 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    AC3 = (uint16_T)tmp_1;
  }

  /* '<S164>:1:8' AC4 = single(bitshift(bytes(7), 8) + bytes(8)); */
  /* '<S164>:1:9' AC5 = single(bitshift(bytes(9), 8) + bytes(10)); */
  /* '<S164>:1:10' AC6 = single(bitshift(bytes(11), 8) + bytes(12)); */
  /* '<S164>:1:12' B1 = decomp(bitshift(bytes(13), 8) + bytes(14)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[12] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[13];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    B1 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    B1 = (uint16_T)tmp_1;
  }

  /* '<S164>:1:13' B2 = decomp(bitshift(bytes(15), 8) + bytes(16)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[14] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[15];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    B2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    B2 = (uint16_T)tmp_1;
  }

  /* '<S164>:1:15' MB = decomp(bitshift(bytes(17), 8) + bytes(18)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[16] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[17];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    MB = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    MB = (uint16_T)tmp_1;
  }

  /* '<S164>:1:16' MC = decomp(bitshift(bytes(19), 8) + bytes(20)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[18] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[19];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    MC = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    MC = (uint16_T)tmp_1;
  }

  /* '<S164>:1:17' MD = decomp(bitshift(bytes(21), 8) + bytes(22)); */
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[20] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[21];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S164>:1:25' u = single(u); */
  /* '<S164>:1:27' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S164>:1:28' y = single(-65536 + u); */
    MD = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S164>:1:29' else */
    /* '<S164>:1:30' y = single(u); */
    MD = (uint16_T)tmp_1;
  }

  /* '<S164>:1:19' params = [AC1; AC2; AC3; AC4; AC5; AC6; B1; B2; MB; MC; MD]; */
  ICARO3_Onda_bipe_controllonostro40cm_B.params[0] = (real32_T)i;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[1] = (real32_T)AC2;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[2] = (real32_T)AC3;
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[6] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[7];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.params[3] = (real32_T)tmp_1;
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[8] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[9];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.params[4] = (real32_T)tmp_1;
  tmp_1 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[10] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion[11];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.params[5] = (real32_T)tmp_1;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[6] = (real32_T)B1;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[7] = (real32_T)B2;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[8] = (real32_T)MB;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[9] = (real32_T)MC;
  ICARO3_Onda_bipe_controllonostro40cm_B.params[10] = (real32_T)MD;

  /* End of MATLAB Function: '<S160>/MATLAB Function1' */

  /* RateTransition: '<S149>/Rate Transition2' */
  if (!(ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition2_semaphoreTaken
        != 0)) {
    for (i = 0; i < 11; i++) {
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition2_Buffer0[i] =
        ICARO3_Onda_bipe_controllonostro40cm_B.params[i];
    }
  }

  /* End of RateTransition: '<S149>/Rate Transition2' */

  /* RateTransition: '<S171>/Rate Transition' */
  AC2 = ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_ActiveBufIdx <<
    3;
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition[i] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_Buffer[i + AC2];
  }

  for (i = 0; i < 6; i++) {
    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<Root>/1: HW 0: SIM'
     */
    if (ICARO3_Onda_bipe_controllonostro40cm_P.HW0SIM_Value >=
        ICARO3_Onda_bipe_controllonostro40cm_P.Switch_Threshold_c) {
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_n[i] =
        ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[i + 5];
    } else {
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_n[i] =
        ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition[i];
    }

    /* End of Switch: '<S150>/Switch' */

    /* DataTypeConversion: '<S149>/Data Type Conversion on i2c mag' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_n[i];
  }

  /* End of RateTransition: '<S171>/Rate Transition' */

  /* RateTransition: '<S171>/Rate Transition14' */
  AC2 = ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_ActiveBufIdx
    << 3;
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[i] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_Buffer[i + AC2];
  }

  /* End of RateTransition: '<S171>/Rate Transition14' */

  /* Switch: '<S150>/Switch1' incorporates:
   *  Constant: '<Root>/1: HW 0: SIM'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_P.HW0SIM_Value >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch1_Threshold_c) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[11];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[12];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[13];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[14];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[4] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[15];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[5] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[16];
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition[6];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition[7];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[4] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[2];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[5] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[3];
  }

  /* End of Switch: '<S150>/Switch1' */

  /* DataTypeConversion: '<S149>/Data Type Conversion on i2c mag1' */
  for (i = 0; i < 6; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_c[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_k[i];
  }

  /* End of DataTypeConversion: '<S149>/Data Type Conversion on i2c mag1' */

  /* RateTransition: '<S171>/Rate Transition15' */
  AC2 = ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_ActiveBufIdx
    << 3;
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[i] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_Buffer[i + AC2];
  }

  /* End of RateTransition: '<S171>/Rate Transition15' */

  /* Switch: '<S150>/Switch2' incorporates:
   *  Constant: '<Root>/1: HW 0: SIM'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_P.HW0SIM_Value >=
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch2_Threshold) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[17];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[18];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[19];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[20];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[4] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[21];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[5] =
      ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[22];
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[4];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[5];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[6];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[7];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[4] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[5] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[1];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S149>/Data Type Conversion on i2c mag2' */
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag2[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch2_i[i];

    /* MATLAB Function: '<S149>/MATLAB Function compute magxyz' */
    u_0[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag2[i];
  }

  /* End of Switch: '<S150>/Switch2' */

  /* MATLAB Function: '<S149>/MATLAB Function compute magxyz' */
  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function compute magxyz': '<S158>:1' */
  /* '<S158>:1:4' if (hmc5833_enabled == 0) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[3] == 0) {
    /* '<S158>:1:5' u = u*0; */
    for (i = 0; i < 6; i++) {
      u_0[i] = 0U;
    }
  }

  /* note: register order is X Z Y */
  /* OLD */
  /*  mx = decomp(bitshift(u(1), 8) + u(2))/1090; */
  /*  my = decomp(bitshift(u(3), 8) + u(4))/1090; */
  /*  mz = decomp(bitshift(u(5), 8) + u(6))/1090; */
  /*   */
  /*  m_hmc = [mx; my; mz]; */
  /*   */
  /*  Convert m from hmc axes to ICARO2 axes */
  /*  (nota nel nuovo file) */
  /*  m = [0 0 1; -1 0 0; 0 1 0]*m_hmc; */
  /* NEW */
  /* '<S158>:1:20' mx = decomp(bitshift(u(1), 8) + u(2))/1090; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[0] << 8) + u_0[1];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S158>:1:33' u = single(u); */
  /* '<S158>:1:35' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S158>:1:36' y = single(-65536 + u); */
    i = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S158>:1:37' else */
    /* '<S158>:1:38' y = single(u); */
    i = (uint16_T)tmp_1;
  }

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  /* '<S158>:1:21' mz = decomp(bitshift(u(3), 8) + u(4))/1090; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[2] << 8) + u_0[3];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S158>:1:33' u = single(u); */
  /* '<S158>:1:35' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S158>:1:36' y = single(-65536 + u); */
    AC2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S158>:1:37' else */
    /* '<S158>:1:38' y = single(u); */
    AC2 = (uint16_T)tmp_1;
  }

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  /* '<S158>:1:22' my = decomp(bitshift(u(5), 8) + u(6))/1090; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[4] << 8) + u_0[5];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S158>:1:33' u = single(u); */
  /* '<S158>:1:35' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S158>:1:36' y = single(-65536 + u); */
    AC3 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S158>:1:37' else */
    /* '<S158>:1:38' y = single(u); */
    AC3 = (uint16_T)tmp_1;
  }

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  /* '<S158>:1:23' m_hmc = [mx; my; mz]; */
  /*  Convert m from HMC5883 axes to dji axis */
  /* R_x(180) */
  /* '<S158>:1:27' m = [1 0 0; 0 -1 0; 0 0 -1]*m_hmc; */
  mr_idx_0 = (real32_T)i / 1090.0F;
  mr_idx_1 = (real32_T)AC3 / 1090.0F;
  AC1_idx_2 = (real32_T)AC2 / 1090.0F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.m[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.m[AC2] += (real32_T)b_0[AC2] *
      mr_idx_0;
    ICARO3_Onda_bipe_controllonostro40cm_B.m[AC2] += (real32_T)b_0[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.m[AC2] += (real32_T)b_0[AC2 + 6] *
      AC1_idx_2;
  }

  /* DataTypeConversion: '<S149>/Data Type Conversion3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.m[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.m[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.m[2];

  /* MATLAB Function: '<S149>/MATLAB Function' */
  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function': '<S154>:1' */
  /* '<S154>:1:4' h_calib=[0 0 0]'; */
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[0] = 0.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[1] = 0.0;
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[2] = 0.0;

  /* '<S154>:1:5' h_calib(1) = (h_raw(1)-CAL_PARAM(1))/CAL_PARAM(4); */
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[0] =
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[0] -
     ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[0]) /
    ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[3];

  /* '<S154>:1:6' h_calib(2) = ((h_raw(2)-CAL_PARAM(2))/CAL_PARAM(5) - ... */
  /* '<S154>:1:7'     ((h_raw(1)-CAL_PARAM(1))/CAL_PARAM(4))*sin(CAL_PARAM(7)))/(cos(CAL_PARAM(7))); */
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[1] =
    ((ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[1] -
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[1]) /
     ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[4] -
     (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[0] -
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[0]) /
     ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[3] * sin
     (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[6])) / cos
    (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[6]);

  /* '<S154>:1:8' h_calib(3) = ((h_raw(3)-CAL_PARAM(3))/CAL_PARAM(6) - ... */
  /* '<S154>:1:9'     ((h_raw(1)-CAL_PARAM(1))/CAL_PARAM(4))*sin(CAL_PARAM(8))*cos(CAL_PARAM(9)) - ... */
  /* '<S154>:1:10'     (sin(CAL_PARAM(9))/cos(CAL_PARAM(7)))*((h_raw(2)-CAL_PARAM(2))/CAL_PARAM(5)- ... */
  /* '<S154>:1:11'     (h_raw(1)-CAL_PARAM(1))/CAL_PARAM(4))*sin(CAL_PARAM(7)))/(cos(CAL_PARAM(8))*cos(CAL_PARAM(9))); */
  ICARO3_Onda_bipe_controllonostro40cm_B.h_calib[2] =
    (((ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[2] -
       ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[2]) /
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[5] -
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[0] -
       ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[0]) /
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[3] * sin
      (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[7]) * cos
      (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[8])) -
     ((ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[1] -
       ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[1]) /
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[4] -
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_a[0] -
       ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[0]) /
      ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[3]) * (sin
      (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[8]) / cos
      (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[6])) * sin
     (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[6])) / (cos
    (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[7]) * cos
    (ICARO3_Onda_bipe_controllonostro40cm_P.CAL_PARAM[8]));

  /* MATLAB Function: '<S149>/MATLAB Function compute accxyz' */
  for (i = 0; i < 6; i++) {
    u_0[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_c[i];
  }

  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function compute accxyz': '<S155>:1' */
  /* '<S155>:1:3' if (adxl345_enabled == 0) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[2] == 0) {
    /* '<S155>:1:4' u = u*0; */
    for (i = 0; i < 6; i++) {
      u_0[i] = 0U;
    }
  }

  /* '<S155>:1:7' ax = decomp(bitshift(u(2), 8) + u(1))/256.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[1] << 8) + u_0[0];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S155>:1:19' u = single(u); */
  /* '<S155>:1:21' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S155>:1:22' y = single(-65536 + u); */
    i = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S155>:1:23' else */
    /* '<S155>:1:24' y = single(u); */
    i = (uint16_T)tmp_1;
  }

  /* '<S155>:1:8' ay = decomp(bitshift(u(4), 8) + u(3))/256.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[3] << 8) + u_0[2];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S155>:1:19' u = single(u); */
  /* '<S155>:1:21' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S155>:1:22' y = single(-65536 + u); */
    AC2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S155>:1:23' else */
    /* '<S155>:1:24' y = single(u); */
    AC2 = (uint16_T)tmp_1;
  }

  /* '<S155>:1:9' az = decomp(bitshift(u(6), 8) + u(5))/256.0*9.81; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[5] << 8) + u_0[4];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S155>:1:19' u = single(u); */
  /* '<S155>:1:21' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S155>:1:22' y = single(-65536 + u); */
    AC3 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S155>:1:23' else */
    /* '<S155>:1:24' y = single(u); */
    AC3 = (uint16_T)tmp_1;
  }

  /* '<S155>:1:11' a_adxl = [ax; ay; az]; */
  /*  Convert a from adxl axes to ICARO2 axes */
  /* '<S155>:1:15' a = [1 0 0; 0 1 0; 0 0 1]*a_adxl; */
  mr_idx_0 = (real32_T)i / 256.0F * 9.81F;
  mr_idx_1 = (real32_T)AC2 / 256.0F * 9.81F;
  AC1_idx_2 = (real32_T)AC3 / 256.0F * 9.81F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.a_j[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_j[AC2] += (real32_T)b_1[AC2] *
      mr_idx_0;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_j[AC2] += (real32_T)b_1[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.a_j[AC2] += (real32_T)b_1[AC2 + 6] *
      AC1_idx_2;
  }

  /* End of MATLAB Function: '<S149>/MATLAB Function compute accxyz' */

  /* MATLAB Function: '<S149>/MATLAB Function compute gyroxyz' */
  for (i = 0; i < 6; i++) {
    u_0[i] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag[i];
  }

  /* MATLAB Function 'sensor and actuators interface/Processing/MATLAB Function compute gyroxyz': '<S157>:1' */
  /* '<S157>:1:3' if (itg3200_enabled == 0) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[1] == 0) {
    /* '<S157>:1:4' u = u*0; */
    for (i = 0; i < 6; i++) {
      u_0[i] = 0U;
    }
  }

  /* '<S157>:1:8' wx = decomp(bitshift(u(1), 8) + u(2))*0.061*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[0] << 8) + u_0[1];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S157>:1:23' u = single(u); */
  /* '<S157>:1:25' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S157>:1:26' y = single(-65536 + u); */
    i = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S157>:1:27' else */
    /* '<S157>:1:28' y = single(u); */
    i = (uint16_T)tmp_1;
  }

  /* rad/s */
  /* '<S157>:1:9' wy = decomp(bitshift(u(3), 8) + u(4))*0.061*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[2] << 8) + u_0[3];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S157>:1:23' u = single(u); */
  /* '<S157>:1:25' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S157>:1:26' y = single(-65536 + u); */
    AC2 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S157>:1:27' else */
    /* '<S157>:1:28' y = single(u); */
    AC2 = (uint16_T)tmp_1;
  }

  /* '<S157>:1:10' wz = decomp(bitshift(u(5), 8) + u(6))*0.061*pi/180; */
  tmp_1 = (uint32_T)(uint16_T)(u_0[4] << 8) + u_0[5];
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* '<S157>:1:23' u = single(u); */
  /* '<S157>:1:25' if (u > 32767) */
  if ((uint16_T)tmp_1 > 32767) {
    /* '<S157>:1:26' y = single(-65536 + u); */
    AC3 = (uint16_T)tmp_1 - 65536;
  } else {
    /* '<S157>:1:27' else */
    /* '<S157>:1:28' y = single(u); */
    AC3 = (uint16_T)tmp_1;
  }

  /* '<S157>:1:12' w_itg = [wx; wy; wz]; */
  /*  Convert w from itg axes to ICARO2 axes */
  /* '<S157>:1:16' w = [1 0 0; 0 1 0; 0 0 1]*w_itg; */
  mr_idx_0 = (real32_T)i * 0.061F * 3.14159274F / 180.0F;
  mr_idx_1 = (real32_T)AC2 * 0.061F * 3.14159274F / 180.0F;
  AC1_idx_2 = (real32_T)AC3 * 0.061F * 3.14159274F / 180.0F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.w_j[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.w_j[AC2] += (real32_T)b_2[AC2] *
      mr_idx_0;
    ICARO3_Onda_bipe_controllonostro40cm_B.w_j[AC2] += (real32_T)b_2[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.w_j[AC2] += (real32_T)b_2[AC2 + 6] *
      AC1_idx_2;
  }

  /* End of MATLAB Function: '<S149>/MATLAB Function compute gyroxyz' */

  /* RateTransition: '<S149>/Rate Transition18' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_semaphoreTaken = 1;
  for (i = 0; i < 7; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[i] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer0[i];
  }

  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_semaphoreTaken = 0;

  /* End of RateTransition: '<S149>/Rate Transition18' */

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator1 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[1] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator1_BitMask);

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator2 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[2] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator2_BitMask);

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator3 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[3] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator3_BitMask);

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator4' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator4 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[4] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator4_BitMask);

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator5' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator5 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[5] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator5_BitMask);

  /* S-Function (sfix_bitop): '<S161>/Bitwise Operator6' */
  ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator6 = (uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18_g[6] &
     ICARO3_Onda_bipe_controllonostro40cm_P.BitwiseOperator6_BitMask);

  /* SignalConversion: '<S165>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S161>/MATLAB Function compute magxyz1'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    0] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator1;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    1] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator2;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    2] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator3;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    3] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator4;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    4] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator5;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h[
    5] = ICARO3_Onda_bipe_controllonostro40cm_B.BitwiseOperator6;

  /* MATLAB Function: '<S161>/MATLAB Function compute magxyz1' */
  /* MATLAB Function 'sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1': '<S165>:1' */
  /*  Accelerations in m/s^2 */
  /* '<S165>:1:6' ax = decomp(u(1))*2.522*9.81/1000; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [0] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    mr_idx_0 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [0];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    mr_idx_0 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [0];
  }

  /* '<S165>:1:7' ay = decomp(u(2))*2.522*9.81/1000; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [1] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    b_q1 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [1];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    b_q1 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [1];
  }

  /* '<S165>:1:8' az = decomp(u(3))*2.522*9.81/1000; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [2] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    q1 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [2];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    q1 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [2];
  }

  /*  PQR in rad/s */
  /* '<S165>:1:12' wx = decomp(u(4))*0.07326*pi/180; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [3] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    q2 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [3];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    q2 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [3];
  }

  /* '<S165>:1:13' wy = decomp(u(5))*0.07326*pi/180; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [4] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    q3 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [4];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    q3 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [4];
  }

  /* '<S165>:1:14' wz = decomp(u(6))*0.07326*pi/180; */
  /* '<S165>:1:28' u = single(u); */
  /* '<S165>:1:30' if (u > 2^13 - 1) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [5] > 8191) {
    /* '<S165>:1:31' y = single(-2^14 + u); */
    q4 = -16384.0F + (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [5];
  } else {
    /* '<S165>:1:32' else */
    /* '<S165>:1:33' y = single(u); */
    q4 =
      ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSFunctionInport1_h
      [5];
  }

  /* '<S165>:1:16' a_adis = [ax; ay; az]; */
  /* '<S165>:1:17' w_adis = [wx; wy; wz]; */
  /*  Convert a and w from adis axes to ICARO2 axes */
  /* '<S165>:1:21' a = [-1 0 0; 0 1 0; 0 0 1]*a_adis; */
  AC1_idx_2 = mr_idx_0 * 2.522F * 9.81F / 1000.0F;
  mr_idx_1 = b_q1 * 2.522F * 9.81F / 1000.0F;
  mr_idx_0 = q1 * 2.522F * 9.81F / 1000.0F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.a[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.a[AC2] += (real32_T)c[AC2] *
      AC1_idx_2;
    ICARO3_Onda_bipe_controllonostro40cm_B.a[AC2] += (real32_T)c[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.a[AC2] += (real32_T)c[AC2 + 6] *
      mr_idx_0;
  }

  /* '<S165>:1:22' w = [1 0 0; 0 -1 0; 0 0 -1]*w_adis; */
  AC1_idx_2 = q2 * 0.07326F * 3.14159274F / 180.0F;
  mr_idx_1 = q3 * 0.07326F * 3.14159274F / 180.0F;
  mr_idx_0 = q4 * 0.07326F * 3.14159274F / 180.0F;
  for (AC2 = 0; AC2 < 3; AC2++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.w[AC2] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.w[AC2] += (real32_T)b_3[AC2] *
      AC1_idx_2;
    ICARO3_Onda_bipe_controllonostro40cm_B.w[AC2] += (real32_T)b_3[AC2 + 3] *
      mr_idx_1;
    ICARO3_Onda_bipe_controllonostro40cm_B.w[AC2] += (real32_T)b_3[AC2 + 6] *
      mr_idx_0;
  }

  /* ZeroOrderHold: '<S150>/downsample to 100 Hz3' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID1_2) {
    ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[2];
    ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[3] =
      ICARO3_Onda_bipe_controllonostro40cm_B.RC_TRPY_refs[3];
  }

  /* End of ZeroOrderHold: '<S150>/downsample to 100 Hz3' */

  /* Logic: '<S150>/Logical Operator' incorporates:
   *  Constant: '<Root>/1: HW 0: SIM'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.LogicalOperator =
    !(ICARO3_Onda_bipe_controllonostro40cm_P.HW0SIM_Value != 0.0);

  /* DataTypeConversion: '<S187>/Data Type Conversion8' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion8 =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[2];

  /* ArithShift: '<S187>/ ' */
  ICARO3_Onda_bipe_controllonostro40cm_B.u =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion8 << 24;

  /* DataTypeConversion: '<S187>/Data Type Conversion9' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9_d =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[3];

  /* ArithShift: '<S187>/  ' */
  ICARO3_Onda_bipe_controllonostro40cm_B.u_o =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion9_d << 16;

  /* DataTypeConversion: '<S187>/Data Type Conversion7' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7_c =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[4];

  /* ArithShift: '<S187>/  2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.u_i =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion7_c << 8;

  /* DataTypeConversion: '<S187>/Data Type Conversion10' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion10 =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[5];

  /* Sum: '<S187>/Sum12' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum12 =
    ((ICARO3_Onda_bipe_controllonostro40cm_B.u +
      ICARO3_Onda_bipe_controllonostro40cm_B.u_o) +
     ICARO3_Onda_bipe_controllonostro40cm_B.u_i) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion10;

  /* MATLAB Function: '<S187>/typecast uin32 to single' */
  /* MATLAB Function 'sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single': '<S190>:1' */
  /* '<S190>:1:4' y = typecast(u,'single'); */
  memcpy(&mr_idx_0, &ICARO3_Onda_bipe_controllonostro40cm_B.Sum12, 4U);
  ICARO3_Onda_bipe_controllonostro40cm_B.y_b1 = mr_idx_0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void ICARO3_Onda_bipe_controllonostro40cm_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  static const int8_T b[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_0[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  real_T scale;
  real_T absxk;
  real_T t;
  int8_T s86_iter;
  int32_T i;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_d = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition46;

  /* S-Function (sfun_UPboard_downlink): '<Root>/Save data to data logger (the micro SD card)1' */
  wrap_UPboard_downlink_output_width_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_d, 1);

  /* S-Function (sfun_UPboard): '<Root>/S-Function-USART3_Receive4' */
  wrap_UPboard_output_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_B.SFunctionUSART3_Receive4_o1[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.SFunctionUSART3_Receive4_o2);

  /* DataTypeConversion: '<Root>/Data Type Conversion18' */
  for (i = 0; i < 13; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[i] = (real32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.SFunctionUSART3_Receive4_o1[i];
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion18' */

  /* MATLAB Function: '<Root>/Compensate for sensor mount _acc' */
  /* MATLAB Function 'Compensate for sensor mount _acc': '<S4>:1' */
  /* '<S4>:1:5' R=[1 0 0;0 -1 0;0 0 -1]; */
  /* '<S4>:1:7' y =R*u; */
  for (i = 0; i < 3; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[i] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[i] += (real32_T)b[i] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[i] += (real32_T)b[i + 3] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[i] += (real32_T)b[i + 6] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[2];
  }

  /* End of MATLAB Function: '<Root>/Compensate for sensor mount _acc' */

  /* RateTransition: '<Root>/Rate Transition51' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID2_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_k[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_k[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_k[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition51' */

  /* MATLAB Function: '<Root>/Compensate for sensor mount _acc1' */
  /* MATLAB Function 'Compensate for sensor mount _acc1': '<S5>:1' */
  /* '<S5>:1:4' R=[1 0 0;0 -1 0;0 0 -1]; */
  /* '<S5>:1:6' y =R*u; */
  for (i = 0; i < 3; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[i] = 0.0F;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[i] += (real32_T)b_0[i] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[3];
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[i] += (real32_T)b_0[i + 3] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[4];
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[i] += (real32_T)b_0[i + 6] *
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[5];
  }

  /* End of MATLAB Function: '<Root>/Compensate for sensor mount _acc1' */

  /* RateTransition: '<Root>/Rate Transition50' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID2_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_j[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_j[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_j[2];

    /* RateTransition: '<Root>/Rate Transition4' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[10];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[11];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[12];

    /* RateTransition: '<Root>/Rate Transition6' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[6];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[7];
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[8];
  }

  /* End of RateTransition: '<Root>/Rate Transition50' */

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[6];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[7];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[8];

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[10];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[11];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[12];

  /* Sum: '<S6>/Sum2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[0] -
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[1] -
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2[2] -
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1[2];

  /* MATLAB Function: '<S6>/+pi-pi_remapping' */
  /* MATLAB Function 'Control /+pi-pi_remapping': '<S67>:1' */
  /*  Function that maps the input angle with possible values in [+2pi, -2pi] in [+pi, -pi] interval */
  /*  Args: */
  /*  theta_in: angle within [+2pi, -2pi] interval */
  /*  Returns: */
  /*  theta_out: angle remapped in [+pi, -pi] interval */
  /*  2pi-shift -> [0, +4pi] interval */
  /* '<S67>:1:10' theta_in = theta_in + 2*pi % 2pi-shift -> [0, +4pi] interval */
  /*  0-2pi interval */
  /* '<S67>:1:11' theta_out = mod(theta_in, 2*pi) % 0-2pi interval */
  ICARO3_Onda_bipe_controllonostro40cm_B.theta_out =
    (ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[2] +
     6.2831853071795862) / 6.2831853071795862;
  if (fabs(ICARO3_Onda_bipe_controllonostro40cm_B.theta_out - rt_roundd_snf
           (ICARO3_Onda_bipe_controllonostro40cm_B.theta_out)) <=
      2.2204460492503131E-16 * fabs
      (ICARO3_Onda_bipe_controllonostro40cm_B.theta_out)) {
    ICARO3_Onda_bipe_controllonostro40cm_B.theta_out = 0.0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.theta_out =
      (ICARO3_Onda_bipe_controllonostro40cm_B.theta_out - floor
       (ICARO3_Onda_bipe_controllonostro40cm_B.theta_out)) * 6.2831853071795862;
  }

  /* '<S67>:1:12' if (theta_out > pi) */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.theta_out > 3.1415926535897931) {
    /* '<S67>:1:13' theta_out = theta_out -2*pi; */
    ICARO3_Onda_bipe_controllonostro40cm_B.theta_out -= 6.2831853071795862;

    /*  [+pi, -pi] interval */
  }

  /* End of MATLAB Function: '<S6>/+pi-pi_remapping' */

  /* Gain: '<S6>/Gain' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain[0] =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain_b *
    ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain[1] =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain_b *
    ICARO3_Onda_bipe_controllonostro40cm_B.relativevector[1];

  /* MATLAB Function: '<S6>/VectorNorm' */
  /* MATLAB Function 'Control /VectorNorm': '<S68>:1' */
  /*  Function that computes tha norm of an input vector  */
  /*  Args: */
  /*  u: vector */
  /*  Returns: */
  /*  y = norm of input vector u */
  /* '<S68>:1:9' y = norm(u); */
  ICARO3_Onda_bipe_controllonostro40cm_B.y_o = 0.0;
  scale = 2.2250738585072014E-308;
  absxk = fabs(ICARO3_Onda_bipe_controllonostro40cm_B.Gain[0]);
  if (absxk > 2.2250738585072014E-308) {
    t = 2.2250738585072014E-308 / absxk;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_o =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_o * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_o += t * t;
  }

  absxk = fabs(ICARO3_Onda_bipe_controllonostro40cm_B.Gain[1]);
  if (absxk > scale) {
    t = scale / absxk;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_o =
      ICARO3_Onda_bipe_controllonostro40cm_B.y_o * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    ICARO3_Onda_bipe_controllonostro40cm_B.y_o += t * t;
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.y_o = scale * sqrt
    (ICARO3_Onda_bipe_controllonostro40cm_B.y_o);

  /* End of MATLAB Function: '<S6>/VectorNorm' */

  /* DataTypeConversion: '<S6>/Data Type Conversion3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion18[9];

  /* MATLAB Function: '<S69>/Control Manager' */
  /* MATLAB Function 'Control /steer_control/Control Manager': '<S71>:1' */
  /*  Function for managing the controller action */
  /*  Args: */
  /*  distance: distance from car to the waypoint */
  /*  startstop: 0 if you want to stop the car, 1 if you want the controller */
  /*             ON */
  /*  Returns: */
  /*  go: 0 if the car is near enough to the waypoint (distance > */
  /*      distance_threshold) or you want to stop manually the car (startstop = */
  /*      0). */
  /*      1 if the car is far from the waypoint (distance > distance_threshold) */
  /*      and startstop = 1 */
  /* '<S71>:1:15' distance_threshold = 400; */
  /* mm BIPE */
  /* '<S71>:1:16' if ((distance < distance_threshold) || (startstop==0)) */
  if ((ICARO3_Onda_bipe_controllonostro40cm_B.y_o < 400.0) ||
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3 == 0.0)) {
    /* '<S71>:1:17' go = 0; */
    ICARO3_Onda_bipe_controllonostro40cm_B.go_i = 0.0;
  } else {
    /* '<S71>:1:18' else */
    /* '<S71>:1:19' go = 1; */
    ICARO3_Onda_bipe_controllonostro40cm_B.go_i = 1.0;
  }

  /* End of MATLAB Function: '<S69>/Control Manager' */

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S69>/Constant'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.go_i >
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch1_Threshold) {
    /* Gain: '<S69>/Gain1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Gain1_m =
      ICARO3_Onda_bipe_controllonostro40cm_P.Gain1_Gain *
      ICARO3_Onda_bipe_controllonostro40cm_B.theta_out;
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1 =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1_m;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_hv;
  }

  /* End of Switch: '<S69>/Switch1' */

  /* Saturate: '<S69>/Saturation' */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch1 >
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation_UpperSat) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation =
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation_UpperSat;
  } else if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch1 <
             ICARO3_Onda_bipe_controllonostro40cm_P.Saturation_LowerSat) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation =
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation_LowerSat;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation =
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch1;
  }

  /* End of Saturate: '<S69>/Saturation' */

  /* Sum: '<S69>/Sum1' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum1 =
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation +
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_on;

  /* DataTypeConversion: '<S6>/Data Type Conversion5' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5 = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1;

  /* RateTransition: '<Root>/Rate Transition12' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID2_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition12 =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5;
  }

  /* End of RateTransition: '<Root>/Rate Transition12' */

  /* Memory: '<S70>/Memory1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Memory1 =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory1_PreviousInput;

  /* Gain: '<S70>/Gain1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain1_c =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain1_Gain_k *
    ICARO3_Onda_bipe_controllonostro40cm_B.y_o;

  /* MATLAB Function: '<S70>/MATLAB Function' */
  /* MATLAB Function 'Control /throttle_control /MATLAB Function': '<S73>:1' */
  /*  Function that limits the rising speed of pwm value. The control is  */
  /*  limited by a ramp with angular coefficient equal to 0.1 with different */
  /*  sign if the car accelerates or decelerates */
  /*  Args: */
  /*  prev_des_control: desired control (output of the proportional */
  /*  controller) at previous time step  */
  /*  current_des_control: desired control (output of the proportional */
  /*  controller) at current time step  */
  /* '<S73>:1:12' zero_speed_pwm = 1.42; */
  /*  ms */
  /* '<S73>:1:13' max_speed_pwm = 1.2; */
  /*  ms */
  /* Hz */
  /* '<S73>:1:14' control_freq = 100 %Hz */
  /* '<S73>:1:15' rise_time = 5; */
  /*  sec */
  /*  value to reach the max pwm within rise_time from zero_speed_pwm */
  /* '<S73>:1:17' delta = (-max_speed_pwm + zero_speed_pwm)/ rise_time / control_freq % value to reach the max pwm within rise_time from zero_speed_pwm */
  /* '<S73>:1:19' cur_prev_diff = current_des_control-prev_des_control; */
  scale = ICARO3_Onda_bipe_controllonostro40cm_B.Gain1_c -
    ICARO3_Onda_bipe_controllonostro40cm_B.Memory1;

  /* '<S73>:1:21' if (abs(cur_prev_diff) < delta) */
  if (fabs(scale) < 0.00043999999999999996) {
    /* '<S73>:1:22' control = current_des_control; */
    ICARO3_Onda_bipe_controllonostro40cm_B.control =
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain1_c;
  } else {
    /* '<S73>:1:23' else */
    /* '<S73>:1:24' control = prev_des_control + sign(cur_prev_diff)*delta; */
    if (scale < 0.0) {
      scale = -1.0;
    } else if (scale > 0.0) {
      scale = 1.0;
    } else {
      if (scale == 0.0) {
        scale = 0.0;
      }
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.control = scale *
      0.00043999999999999996 + ICARO3_Onda_bipe_controllonostro40cm_B.Memory1;
  }

  /* End of MATLAB Function: '<S70>/MATLAB Function' */

  /* MATLAB Function: '<S70>/Control Manager' */
  /* MATLAB Function 'Control /throttle_control /Control Manager': '<S72>:1' */
  /*  Function for managing the controller action */
  /*  Args: */
  /*  distance: distance from car to the waypoint */
  /*  startstop: 0 if you want to stop the car, 1 if you want the controller */
  /*             ON */
  /*  Returns: */
  /*  go: 0 if the car is near enough to the waypoint (distance > */
  /*      distance_threshold) or you want to stop manually the car (startstop = */
  /*      0). */
  /*      1 if the car is far from the waypoint (distance > distance_threshold) */
  /*      and startstop = 1 */
  /* '<S72>:1:14' distance_threshold = 400; */
  /* mm %BIPE */
  /* '<S72>:1:15' if ((distance < distance_threshold) || (startstop==0)) */
  if ((ICARO3_Onda_bipe_controllonostro40cm_B.y_o < 400.0) ||
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3 == 0.0)) {
    /* '<S72>:1:16' go = 0; */
    ICARO3_Onda_bipe_controllonostro40cm_B.go = 0.0;
  } else {
    /* '<S72>:1:17' else */
    /* '<S72>:1:18' go = 1; */
    ICARO3_Onda_bipe_controllonostro40cm_B.go = 1.0;
  }

  /* End of MATLAB Function: '<S70>/Control Manager' */

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.go >
      ICARO3_Onda_bipe_controllonostro40cm_P.Switch1_Threshold_p) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_i =
      ICARO3_Onda_bipe_controllonostro40cm_B.control;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_i =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_ob;
  }

  /* End of Switch: '<S70>/Switch1' */

  /* Saturate: '<S70>/Saturation1' */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_i >
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation1_UpperSat) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation1_UpperSat;
  } else if (ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_i <
             ICARO3_Onda_bipe_controllonostro40cm_P.Saturation1_LowerSat) {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.Saturation1_LowerSat;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation1 =
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch1_i;
  }

  /* End of Saturate: '<S70>/Saturation1' */

  /* Sum: '<S70>/Sum1' incorporates:
   *  Constant: '<S70>/ zero speed value'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_a =
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation1 +
    ICARO3_Onda_bipe_controllonostro40cm_P.zerospeedvalue_Value;

  /* DataTypeConversion: '<S6>/Data Type Conversion4' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4 = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_a;

  /* RateTransition: '<Root>/Rate Transition7' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID2_4) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition7 =
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4;
  }

  /* End of RateTransition: '<Root>/Rate Transition7' */

  /* DataTypeConversion: '<Root>/Data Type Conversion16' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion16 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4;

  /* DataTypeConversion: '<Root>/Data Type Conversion19' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion19 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5;

  /* Sum: '<Root>/Sum12' */
  ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[0] -
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[1] -
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.y_k[2] -
    ICARO3_Onda_bipe_controllonostro40cm_B.y_j[2];

  /* S-Function (sfun_ADC_Receive): '<S2>/PWM1' */
  wrap_ADC_Receive_output_fcn(&ICARO3_Onda_bipe_controllonostro40cm_B.PWM1[0]);

  /* Outputs for Atomic SubSystem: '<S150>/CANbus data RX' */

  /* S-Function (sfun_CAN_Receive): '<S167>/CANRX' */
  wrap_CAN_Receive_output_fcn(&ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[0],
    &ICARO3_Onda_bipe_controllonostro40cm_P.Rx_ID1_Value,6.0,
    &ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o2);

  /* DataTypeConversion: '<S174>/Data Type Conversion on i2c mag1' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_j[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i + 32];
  }

  /* End of DataTypeConversion: '<S174>/Data Type Conversion on i2c mag1' */

  /* MATLAB Function: '<S174>/MATLAB Function compute gyroxyz1' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_j[2],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1);

  /* MATLAB Function: '<S174>/MATLAB Function compute gyroxyz2' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_j[4],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2);

  /* MATLAB Function: '<S174>/MATLAB Function compute gyroxyz3' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_j[6],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3);

  /* MATLAB Function: '<S174>/MATLAB Function compute gyroxyz5' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_j[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5);

  /* DataTypeConversion: '<S175>/Data Type Conversion on i2c mag1' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i + 24];
  }

  /* End of DataTypeConversion: '<S175>/Data Type Conversion on i2c mag1' */

  /* MATLAB Function: '<S175>/MATLAB Function compute gyroxyz1' */
  ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_k
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1[4],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_k);

  /* MATLAB Function: '<S175>/MATLAB Function compute gyroxyz5' */
  ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_k
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_i);

  /* DataTypeConversion: '<S176>/Data Type Conversion on i2c mag1' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_a[i] =
      ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i + 40];
  }

  /* End of DataTypeConversion: '<S176>/Data Type Conversion on i2c mag1' */

  /* MATLAB Function: '<S176>/MATLAB Function compute gyroxyz1' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_a[2],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_e);

  /* MATLAB Function: '<S176>/MATLAB Function compute gyroxyz2' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_a[4],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_h);

  /* MATLAB Function: '<S176>/MATLAB Function compute gyroxyz3' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_a[6],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_a);

  /* MATLAB Function: '<S176>/MATLAB Function compute gyroxyz5' */
  ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1
    (&ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversiononi2cmag1_a[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_d);

  /* End of Outputs for SubSystem: '<S150>/CANbus data RX' */

  /* DataTypeConversion: '<S150>/Data Type Conversion1' */
  scale = floor(0.0);
  if (rtIsNaN(scale) || rtIsInf(scale)) {
    scale = 0.0;
  } else {
    scale = fmod(scale, 65536.0);
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_k = (uint16_T)
    (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
     (uint16_T)scale);

  /* End of DataTypeConversion: '<S150>/Data Type Conversion1' */

  /* Gain: '<S170>/Gain' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain_i =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain_d * 0.0;

  /* Sum: '<S170>/Sum' incorporates:
   *  Constant: '<S170>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum =
    ICARO3_Onda_bipe_controllonostro40cm_B.Gain_i +
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_f;

  /* DataTypeConversion: '<S170>/Data Type Conversion2' */
  scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum);
  if (rtIsNaN(scale) || rtIsInf(scale)) {
    scale = 0.0;
  } else {
    scale = fmod(scale, 65536.0);
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_k = (uint16_T)
    (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
     (uint16_T)scale);

  /* End of DataTypeConversion: '<S170>/Data Type Conversion2' */

  /* DigitalClock: '<S79>/Digital Clock' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock =
    ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick2) * 0.01);

  /* S-Function (sfun_gpsparser_UBLOX): '<S77>/S-Function3' */
  wrap_gpsparser_UBLOX_output_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[0],
     &ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o2);

  /* ManualSwitch: '<S8>/gps selector 2' */
  if (ICARO3_Onda_bipe_controllonostro40cm_P.gpsselector2_CurrentSetting == 1) {
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector2 = 0.0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector2 =
      ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o2;
  }

  /* End of ManualSwitch: '<S8>/gps selector 2' */

  /* Product: '<S84>/Product2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product2 =
    ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[0] *
    ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[0];

  /* Product: '<S84>/Product3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product3 =
    ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[1] *
    ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[1];

  /* Sum: '<S84>/Sum2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum2 =
    ICARO3_Onda_bipe_controllonostro40cm_B.Product2 +
    ICARO3_Onda_bipe_controllonostro40cm_B.Product3;

  /* Sqrt: '<S84>/sqrt' */
  ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_p = sqrt
    (ICARO3_Onda_bipe_controllonostro40cm_B.Sum2);

  /* Sum: '<S88>/Sum1' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S88>/Constant1'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n =
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_n -
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_h;

  /* Product: '<S81>/Product1' incorporates:
   *  Constant: '<S81>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product1 =
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_e *
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n;

  /* Product: '<S89>/Product2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product2_k =
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n *
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n;

  /* Sum: '<S89>/Sum1' incorporates:
   *  Constant: '<S89>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_b =
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_d -
    ICARO3_Onda_bipe_controllonostro40cm_B.Product2_k;

  /* Sum: '<S87>/Sum1' incorporates:
   *  Constant: '<S87>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_d =
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_cm -
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_b;

  /* Product: '<S87>/Product2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product2_a =
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_b /
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_d;

  /* Outputs for Iterator SubSystem: '<S81>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S86>/While Iterator'
   */
  s86_iter = 1;
  do {
    ICARO3_Onda_bipe_controllonostro40cm_B.WhileIterator = s86_iter;

    /* Memory: '<S92>/Memory' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Memory =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory_PreviousInput;

    /* Switch: '<S92>/Switch' */
    if (ICARO3_Onda_bipe_controllonostro40cm_B.WhileIterator >
        ICARO3_Onda_bipe_controllonostro40cm_P.Switch_Threshold_j) {
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch =
        ICARO3_Onda_bipe_controllonostro40cm_B.Memory;
    } else {
      /* Product: '<S92>/Product2' */
      ICARO3_Onda_bipe_controllonostro40cm_B.Product2_k2 =
        ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n *
        ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_p;

      /* Trigonometry: '<S92>/Trigonometric Function3' */
      ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction3 =
        rt_atan2d_snf(ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[2],
                      ICARO3_Onda_bipe_controllonostro40cm_B.Product2_k2);
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch =
        ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction3;
    }

    /* End of Switch: '<S92>/Switch' */

    /* Trigonometry: '<S90>/sincos' */
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_c = sin
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch);
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_e = cos
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch);

    /* Product: '<S90>/Product3' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Product3_m =
      ICARO3_Onda_bipe_controllonostro40cm_B.Product2_a *
      ICARO3_Onda_bipe_controllonostro40cm_B.Product1 *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_c *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_c *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_c;

    /* Sum: '<S90>/Sum2' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum2_c =
      ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[2] +
      ICARO3_Onda_bipe_controllonostro40cm_B.Product3_m;

    /* Product: '<S90>/Product4' incorporates:
     *  Constant: '<S90>/Constant1'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.Product4_e =
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_e *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_e *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_e *
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_b *
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_oo;

    /* Sum: '<S90>/Sum1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_j =
      ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_p -
      ICARO3_Onda_bipe_controllonostro40cm_B.Product4_e;

    /* Trigonometry: '<S90>/Trigonometric Function4' */
    ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4 =
      rt_atan2d_snf(ICARO3_Onda_bipe_controllonostro40cm_B.Sum2_c,
                    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_j);

    /* Trigonometry: '<S91>/sincos' */
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_b = sin
      (ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4);
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_l = cos
      (ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4);

    /* Product: '<S91>/Product3' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Product3_o =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_n *
      ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1_b;

    /* Trigonometry: '<S91>/Trigonometric Function4' */
    ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4_o =
      rt_atan2d_snf(ICARO3_Onda_bipe_controllonostro40cm_B.Product3_o,
                    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2_l);

    /* RelationalOperator: '<S86>/Relational Operator' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RelationalOperator =
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch !=
       ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4_o);

    /* Update for Memory: '<S92>/Memory' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory_PreviousInput =
      ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4_o;
    s86_iter++;
  } while (ICARO3_Onda_bipe_controllonostro40cm_B.RelationalOperator &&
           (s86_iter <= 5));

  /* End of Outputs for SubSystem: '<S81>/While Iterator Subsystem' */

  /* Trigonometry: '<S81>/Trigonometric Function2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction2 = rt_atan2d_snf
    (ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[1],
     ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[0]);

  /* Gain: '<S83>/Unit Conversion' */
  ICARO3_Onda_bipe_controllonostro40cm_B.UnitConversion[0] =
    ICARO3_Onda_bipe_controllonostro40cm_P.UnitConversion_Gain *
    ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4;
  ICARO3_Onda_bipe_controllonostro40cm_B.UnitConversion[1] =
    ICARO3_Onda_bipe_controllonostro40cm_P.UnitConversion_Gain *
    ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction2;

  /* MATLAB Function: '<S77>/MAP ublox fix type to standard status' */
  /* MATLAB Function 'GPS receiver/UBLOX LEA 6 GPS/MAP ublox fix type to standard status': '<S82>:1' */
  /*  Maps UBLOX gpsFix to icaro iii standard (venus gps) */
  /*  IN: */
  /*  10 - U1 - gpsFix - GPSfix Type, range 0..5 */
  /*      0x00 = No Fix */
  /*      0x01 = Dead Reckoning only */
  /*      0x02 = 2D-Fix */
  /*      0x03 = 3D-Fix */
  /*      0x04 = GPS + dead reckoning combined */
  /*      0x05 = Time only fix */
  /*      0x06..0xff: reserved */
  /*  OUT:  */
  /*  2 Fix Mode 02 Quality of fix */
  /*      0: no fix */
  /*      1: 2D */
  /*      2: 3D */
  /*      3: 3D+DGPS */
  /*      UINT8 */
  /* '<S82>:1:22' switch u */
  switch ((int32_T)ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[6]) {
   case 2:
    /* '<S82>:1:23' case 2, */
    /* '<S82>:1:23' y=1; */
    ICARO3_Onda_bipe_controllonostro40cm_B.y = 1.0;
    break;

   case 3:
    /* '<S82>:1:24' case 3, */
    /* '<S82>:1:24' y=2; */
    ICARO3_Onda_bipe_controllonostro40cm_B.y = 2.0;
    break;

   default:
    /* '<S82>:1:25' otherwise */
    /* '<S82>:1:25' y=0; */
    ICARO3_Onda_bipe_controllonostro40cm_B.y = 0.0;
    break;
  }

  /* End of MATLAB Function: '<S77>/MAP ublox fix type to standard status' */

  /* Trigonometry: '<S85>/sincos' */
  ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1 = sin
    (ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4);
  ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2 = cos
    (ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4);

  /* Product: '<S85>/Product2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product2_o =
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1 *
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum1_b;

  /* Product: '<S85>/Product1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product1_h =
    ICARO3_Onda_bipe_controllonostro40cm_B.Product2_o *
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1;

  /* Sum: '<S85>/Sum' incorporates:
   *  Constant: '<S85>/f'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum_b =
    ICARO3_Onda_bipe_controllonostro40cm_P.f_Value -
    ICARO3_Onda_bipe_controllonostro40cm_B.Product1_h;

  /* Sqrt: '<S85>/sqrt' */
  ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_i = sqrt
    (ICARO3_Onda_bipe_controllonostro40cm_B.Sum_b);

  /* Product: '<S85>/Product3' incorporates:
   *  Constant: '<S85>/Constant1'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product3_l =
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_g /
    ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_i;

  /* Product: '<S85>/Product4' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product4 =
    ICARO3_Onda_bipe_controllonostro40cm_B.Product2_o *
    ICARO3_Onda_bipe_controllonostro40cm_B.Product3_l;

  /* Sum: '<S85>/Sum2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum2_k =
    ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[2] +
    ICARO3_Onda_bipe_controllonostro40cm_B.Product4;

  /* Product: '<S85>/Product5' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product5 =
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o1 *
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum2_k;

  /* Product: '<S85>/Product6' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product6 =
    ICARO3_Onda_bipe_controllonostro40cm_B.sincos_o2 *
    ICARO3_Onda_bipe_controllonostro40cm_B.sqrt_p;

  /* Sum: '<S85>/Sum3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum3 =
    (ICARO3_Onda_bipe_controllonostro40cm_B.Product5 -
     ICARO3_Onda_bipe_controllonostro40cm_B.Product3_l) +
    ICARO3_Onda_bipe_controllonostro40cm_B.Product6;

  /* ManualSwitch: '<S8>/gps selector 1' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/Constant1'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_P.gpsselector1_CurrentSetting == 1) {
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[0] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[1] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[2] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[3] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[4] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[5] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[6] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[7] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[8] = 0.0;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[9] = 0.0;
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[0] =
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitConversion[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[1] =
      ICARO3_Onda_bipe_controllonostro40cm_B.UnitConversion[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[2] =
      ICARO3_Onda_bipe_controllonostro40cm_B.y;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[3] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_i;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[4] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_i;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[5] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_i;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[6] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_i;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[7] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_i;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[8] =
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum3;
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[9] =
      ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_o5;
  }

  for (i = 0; i < 6; i++) {
    if (ICARO3_Onda_bipe_controllonostro40cm_P.gpsselector1_CurrentSetting == 1)
    {
      ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[i + 10] = 0.0;
    } else {
      ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[i + 10] =
        ICARO3_Onda_bipe_controllonostro40cm_B.SFunction3_o1[i];
    }
  }

  /* End of ManualSwitch: '<S8>/gps selector 1' */

  /* Product: '<S8>/Product' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Product =
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector2 *
    ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector1[2];

  /* RelationalOperator: '<S93>/Compare' incorporates:
   *  Constant: '<S93>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Compare =
    (ICARO3_Onda_bipe_controllonostro40cm_B.Product >=
     ICARO3_Onda_bipe_controllonostro40cm_P.CompareToConstant_const);

  /* Outputs for Enabled SubSystem: '<S79>/clock latch' incorporates:
   *  EnablePort: '<S94>/Enable'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.Compare) {
    /* Inport: '<S94>/In' */
    ICARO3_Onda_bipe_controllonostro40cm_B.In =
      ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock;
  }

  /* End of Outputs for SubSystem: '<S79>/clock latch' */

  /* Sum: '<S79>/Sum' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum_f =
    ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock -
    ICARO3_Onda_bipe_controllonostro40cm_B.In;

  /* Gain: '<S169>/Gain' */
  ICARO3_Onda_bipe_controllonostro40cm_B.Gain_g =
    ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain_i *
    ICARO3_Onda_bipe_controllonostro40cm_B.Sum_f;

  /* Sum: '<S169>/Sum' incorporates:
   *  Constant: '<S169>/Constant'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.Sum_e =
    ICARO3_Onda_bipe_controllonostro40cm_B.Gain_g +
    ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_ik;

  /* DataTypeConversion: '<S169>/Data Type Conversion2' */
  scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum_e);
  if (rtIsNaN(scale) || rtIsInf(scale)) {
    scale = 0.0;
  } else {
    scale = fmod(scale, 65536.0);
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_c = (uint16_T)
    (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
     (uint16_T)scale);

  /* End of DataTypeConversion: '<S169>/Data Type Conversion2' */

  /* RateTransition: '<S150>/Rate Transition14' */
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14_p =
    ICARO3_Onda_bipe_controllonostro40cm_B.LogicalOperator;

  /* Outputs for Enabled SubSystem: '<S150>/send motor commands via canbus' incorporates:
   *  EnablePort: '<S172>/Enable'
   */
  if (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14_p) {
    /* S-Function (sfun_CAN_Transmit): '<S172>/CANTX1' */
    wrap_CAN_Transmit_output_fcn(1295.0,
      &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4.y[
      0],8U);

    /* S-Function (sfun_CAN_Transmit): '<S172>/CANTX2' */
    wrap_CAN_Transmit_output_fcn(1311.0,
      &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4_j.y
      [0],8U);

    /* S-Function (sfun_CAN_Transmit): '<S172>/CANTX3' */
    wrap_CAN_Transmit_output_fcn(1327.0,
      &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4_f.y
      [0],8U);

    /* DiscretePulseGenerator: '<S172>/Pulse Generator' */
    ICARO3_Onda_bipe_controllonostro40cm_B.PulseGenerator =
      (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f <
       ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator_Duty) &&
      (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f >= 0) ?
      ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator_Amp : 0.0;
    if (ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f >=
        ICARO3_Onda_bipe_controllonostro40cm_P.PulseGenerator_Period - 1.0) {
      ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f = 0;
    } else {
      ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f++;
    }

    /* End of DiscretePulseGenerator: '<S172>/Pulse Generator' */

    /* DataTypeConversion: '<S172>/Data Type Conversion1' */
    scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.PulseGenerator);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_d = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);

    /* End of DataTypeConversion: '<S172>/Data Type Conversion1' */

    /* UnitDelay: '<S202>/Output' */
    ICARO3_Onda_bipe_controllonostro40cm_B.Output_e =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.Output_DSTATE;

    /* MultiPortSwitch: '<S191>/Output' incorporates:
     *  Constant: '<S191>/Vector'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.Output =
      ICARO3_Onda_bipe_controllonostro40cm_P.RepeatingSequenceStair_OutValues[ICARO3_Onda_bipe_controllonostro40cm_B.Output_e];

    /* DataTypeConversion: '<S172>/Data Type Conversion2' */
    scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Output);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_cg = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);

    /* End of DataTypeConversion: '<S172>/Data Type Conversion2' */

    /* DataTypeConversion: '<S172>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant ( SIMULATION ONLY )'
     */
    scale = floor
      (ICARO3_Onda_bipe_controllonostro40cm_P.ConstantSIMULATIONONLY_Value[0]);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[0] = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);
    scale = floor
      (ICARO3_Onda_bipe_controllonostro40cm_P.ConstantSIMULATIONONLY_Value[1]);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[1] = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);
    scale = floor
      (ICARO3_Onda_bipe_controllonostro40cm_P.ConstantSIMULATIONONLY_Value[2]);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[2] = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);
    scale = floor
      (ICARO3_Onda_bipe_controllonostro40cm_P.ConstantSIMULATIONONLY_Value[3]);
    if (rtIsNaN(scale) || rtIsInf(scale)) {
      scale = 0.0;
    } else {
      scale = fmod(scale, 65536.0);
    }

    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[3] = (uint16_T)
      (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
       (uint16_T)scale);

    /* End of DataTypeConversion: '<S172>/Data Type Conversion3' */

    /* MultiPortSwitch: '<S172>/Index Vector' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    switch ((int32_T)ICARO3_Onda_bipe_controllonostro40cm_B.Output) {
     case 0:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2.y;
      break;

     case 1:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_d.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_e.y;
      break;

     case 2:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_h.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_a.y;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_e[0];
      break;

     case 3:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_e[1];
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_e[2];
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant1_Value_e[3];
      break;

     case 4:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] = ((uint16_T)0U);
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] = ((uint16_T)0U);
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] = ((uint16_T)0U);
      break;

     default:
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_k;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_k;
      ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_c;
      break;
    }

    /* End of MultiPortSwitch: '<S172>/Index Vector' */

    /* Sum: '<S203>/FixPt Sum1' incorporates:
     *  Constant: '<S203>/FixPt Constant'
     */
    ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSum1 = (uint8_T)((uint32_T)
      ICARO3_Onda_bipe_controllonostro40cm_B.Output_e +
      ICARO3_Onda_bipe_controllonostro40cm_P.FixPtConstant_Value);

    /* Switch: '<S204>/FixPt Switch' incorporates:
     *  Constant: '<S204>/Constant'
     */
    if (ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSum1 >
        ICARO3_Onda_bipe_controllonostro40cm_P.LimitedCounter_uplimit) {
      ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSwitch =
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_b;
    } else {
      ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSwitch =
        ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSum1;
    }

    /* End of Switch: '<S204>/FixPt Switch' */

    /* MATLAB Function: '<S194>/MATLAB Function compute gyroxyz1' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[1],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_b);

    /* MATLAB Function: '<S194>/MATLAB Function compute gyroxyz2' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[2],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_g);

    /* MATLAB Function: '<S194>/MATLAB Function compute gyroxyz3' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[3],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_b);

    /* MATLAB Function: '<S194>/MATLAB Function compute gyroxyz5' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_n[0],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_b);

    /* MATLAB Function: '<S194>/MATLAB Function compute gyroxyz4' */
    ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz4
      (ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_b.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_b.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_g.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_b.y,
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4);

    /* Switch: '<S172>/Switch' */
    if (ICARO3_Onda_bipe_controllonostro40cm_B.PulseGenerator >=
        ICARO3_Onda_bipe_controllonostro40cm_P.Switch_Threshold) {
      /* Gain: '<S192>/Gain' */
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain_m =
        ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain_h * 0.0;

      /* Sum: '<S192>/Sum' incorporates:
       *  Constant: '<S192>/Constant'
       */
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum_i =
        ICARO3_Onda_bipe_controllonostro40cm_B.Gain_m +
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_h;

      /* DataTypeConversion: '<S192>/Data Type Conversion2' */
      scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum_i);
      if (rtIsNaN(scale) || rtIsInf(scale)) {
        scale = 0.0;
      } else {
        scale = fmod(scale, 65536.0);
      }

      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_g = (uint16_T)
        (scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale : (int32_T)
         (uint16_T)scale);

      /* End of DataTypeConversion: '<S192>/Data Type Conversion2' */
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_g;
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_g;
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_g;
    } else {
      /* Gain: '<S193>/Gain' */
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[0] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain *
        ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[1];
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[1] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain *
        ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[2];
      ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[2] =
        ICARO3_Onda_bipe_controllonostro40cm_P.Gain_Gain *
        ICARO3_Onda_bipe_controllonostro40cm_B.downsampleto100Hz3[3];

      /* Sum: '<S193>/Sum' incorporates:
       *  Constant: '<S193>/Constant'
       */
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[0] +
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_o;
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[1] +
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_o;
      ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.Gain_k[2] +
        ICARO3_Onda_bipe_controllonostro40cm_P.Constant_Value_o;

      /* DataTypeConversion: '<S193>/Data Type Conversion2' */
      scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[0]);
      if (rtIsNaN(scale) || rtIsInf(scale)) {
        scale = 0.0;
      } else {
        scale = fmod(scale, 65536.0);
      }

      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[0] =
        (uint16_T)(scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale :
                   (int32_T)(uint16_T)scale);
      scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[1]);
      if (rtIsNaN(scale) || rtIsInf(scale)) {
        scale = 0.0;
      } else {
        scale = fmod(scale, 65536.0);
      }

      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[1] =
        (uint16_T)(scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale :
                   (int32_T)(uint16_T)scale);
      scale = floor(ICARO3_Onda_bipe_controllonostro40cm_B.Sum_c[2]);
      if (rtIsNaN(scale) || rtIsInf(scale)) {
        scale = 0.0;
      } else {
        scale = fmod(scale, 65536.0);
      }

      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[2] =
        (uint16_T)(scale < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-scale :
                   (int32_T)(uint16_T)scale);

      /* End of DataTypeConversion: '<S193>/Data Type Conversion2' */
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[0] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[0];
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[1] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[1];
      ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[2] =
        ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_i[2];
    }

    /* End of Switch: '<S172>/Switch' */

    /* MATLAB Function: '<S200>/MATLAB Function compute gyroxyz1' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[1],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_i);

    /* MATLAB Function: '<S200>/MATLAB Function compute gyroxyz2' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[2],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_l);

    /* MATLAB Function: '<S200>/MATLAB Function compute gyroxyz3' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_d,
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_p);

    /* MATLAB Function: '<S200>/MATLAB Function compute gyroxyz5' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.Switch_o[0],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_k);

    /* MATLAB Function: '<S200>/MATLAB Function compute gyroxyz4' */
    ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz4
      (ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_k.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_i.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_l.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_p.y,
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4_j);

    /* MATLAB Function: '<S201>/MATLAB Function compute gyroxyz1' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[1],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_g);

    /* MATLAB Function: '<S201>/MATLAB Function compute gyroxyz2' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[2],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_i);

    /* MATLAB Function: '<S201>/MATLAB Function compute gyroxyz3' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_cg,
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_ph);

    /* MATLAB Function: '<S201>/MATLAB Function compute gyroxyz5' */
    ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
      (ICARO3_Onda_bipe_controllonostro40cm_B.IndexVector[0],
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_p);

    /* MATLAB Function: '<S201>/MATLAB Function compute gyroxyz4' */
    ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz4
      (ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_p.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_g.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz2_i.y,
       ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz3_ph.y,
       &ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz4_f);

    /* Update for UnitDelay: '<S202>/Output' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Output_DSTATE =
      ICARO3_Onda_bipe_controllonostro40cm_B.FixPtSwitch;
  }

  /* End of Outputs for SubSystem: '<S150>/send motor commands via canbus' */

  /* DigitalClock: '<Root>/Digital Clock' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock_k =
    ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick2) * 0.01);

  /* DigitalClock: '<S80>/Digital Clock' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock_p =
    ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick2) * 0.01);

  /* Outputs for Enabled SubSystem: '<S80>/clock latch' */
  ICARO3_Onda_bipe_controllonostro40cm_clocklatch
    (ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector2,
     ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock_p,
     &ICARO3_Onda_bipe_controllonostro40cm_B.clocklatch_m);

  /* End of Outputs for SubSystem: '<S80>/clock latch' */

  /* Outputs for Enabled SubSystem: '<Root>/clock latch' */
  ICARO3_Onda_bipe_controllonostro40cm_clocklatch
    (ICARO3_Onda_bipe_controllonostro40cm_B.gpsselector2,
     ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock_k,
     &ICARO3_Onda_bipe_controllonostro40cm_B.clocklatch_h);

  /* End of Outputs for SubSystem: '<Root>/clock latch' */

  /* Update for RateTransition: '<Root>/Rate Transition49' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[0];
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[1];
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.headingdirection[2];

  /* Update for Memory: '<S70>/Memory1' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory1_PreviousInput =
    ICARO3_Onda_bipe_controllonostro40cm_B.Saturation1;

  /* Update for RateTransition: '<Root>/Rate Transition47' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition47_Buffer0 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion19;

  /* Update for RateTransition: '<Root>/Rate Transition48' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition48_Buffer0 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion16;

  /* Update for RateTransition: '<S171>/Rate Transition' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_Buffer[i +
      ((ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_ActiveBufIdx ==
        0) << 3)] = ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i];
  }

  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_ActiveBufIdx =
    (int8_T)
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_ActiveBufIdx == 0);

  /* End of Update for RateTransition: '<S171>/Rate Transition' */

  /* Update for RateTransition: '<S171>/Rate Transition14' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_Buffer[i +
      ((ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_ActiveBufIdx
        == 0) << 3)] = ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i + 8];
  }

  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_ActiveBufIdx =
    (int8_T)
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_ActiveBufIdx ==
     0);

  /* End of Update for RateTransition: '<S171>/Rate Transition14' */

  /* Update for RateTransition: '<S171>/Rate Transition15' */
  for (i = 0; i < 8; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_Buffer[i +
      ((ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_ActiveBufIdx
        == 0) << 3)] = ICARO3_Onda_bipe_controllonostro40cm_B.CANRX_o1[i + 16];
  }

  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_ActiveBufIdx =
    (int8_T)
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_ActiveBufIdx ==
     0);

  /* End of Update for RateTransition: '<S171>/Rate Transition15' */

  /* Update for RateTransition: '<S171>/Rate Transition18' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer
    [(ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_ActiveBufIdx ==
      0) << 1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz5_i.y;
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer[1 +
    ((ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_ActiveBufIdx ==
      0) << 1)] =
    ICARO3_Onda_bipe_controllonostro40cm_B.sf_MATLABFunctioncomputegyroxyz1_k.y;
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_ActiveBufIdx =
    (int8_T)
    (ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_ActiveBufIdx ==
     0);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void ICARO3_Onda_bipe_controllonostro40cm_step3(void) /* Sample time: [0.02s, 0.0s] */
{
  real32_T X1;
  int32_T i;
  uint32_T q0;
  uint32_T qY;

  /* RateTransition: '<S25>/Rate Transition10' incorporates:
   *  Constant: '<S25>/bmp085 accuracy level'
   */
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition10 =
    ICARO3_Onda_bipe_controllonostro40cm_P.bmp085accuracylevel_Value;

  /* DataTypeConversion: '<S25>/Data Type Conversion mx3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3 =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition10;

  /* RateTransition: '<S149>/Rate Transition6' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_semaphoreTaken = 1;
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6_i[0] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_Buffer0[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6_i[1] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_Buffer0[1];
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition6_semaphoreTaken = 0;

  /* RateTransition: '<S149>/Rate Transition5' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_semaphoreTaken = 1;
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[0] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[1] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[2] =
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_Buffer0[2];
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition5_semaphoreTaken = 0;

  /* RateTransition: '<S149>/Rate Transition2' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition2_semaphoreTaken = 1;
  for (i = 0; i < 11; i++) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[i] =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition2_Buffer0[i];
  }

  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition2_semaphoreTaken = 0;

  /* End of RateTransition: '<S149>/Rate Transition2' */

  /* RateTransition: '<S149>/Rate Transition1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition1_g =
    ICARO3_Onda_bipe_controllonostro40cm_B.Switch4[4];

  /* Outputs for Atomic SubSystem: '<S149>/Compute Temperature (T) and Altitude (H)' */
  /* DataTypeConversion: '<S153>/Data Type Conversion4' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4_f[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6_i[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4_f[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6_i[1];

  /* DataTypeConversion: '<S153>/Data Type Conversion5' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[0] =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[1] =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[2] =
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition5[2];

  /* MATLAB Function: '<S153>/MATLAB Function1' */
  /* MATLAB Function 'sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1': '<S163>:1' */
  /* '<S163>:1:4' UT = bitshift(UT_bytes(1), 8) + UT_bytes(2); */
  q0 = (uint32_T)(uint16_T)
    (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4_f[0] << 8) +
    ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion4_f[1];
  if (q0 > 65535U) {
    q0 = 65535U;
  }

  ICARO3_Onda_bipe_controllonostro40cm_B.UT = (uint16_T)q0;

  /* UP = bitshift(UP_bytes(1), 8) + UP_bytes(2); */
  /* '<S163>:1:6' UP = bitshift(bitshift(UP_bytes(1), 16) + bitshift(UP_bytes(2), 8) + UP_bytes(3),-(8 - oss)); */
  q0 = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[0] << 16U;
  qY = (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[1] << 8U) +
    q0;
  if (qY < q0) {
    qY = MAX_uint32_T;
  }

  q0 = qY + ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion5_l[2];
  if (q0 < qY) {
    q0 = MAX_uint32_T;
  }

  if (-(8.0F - ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3) <
      0.0F) {
    if (-(-(8.0F - ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3))
        <= 31.0F) {
      ICARO3_Onda_bipe_controllonostro40cm_B.UP = q0 >> (uint32_T)rt_roundf_snf(
        -(-(8.0F - ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3)));
    } else {
      ICARO3_Onda_bipe_controllonostro40cm_B.UP = 0U;
    }
  } else if (-(8.0F -
               ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3) <=
             31.0F) {
    ICARO3_Onda_bipe_controllonostro40cm_B.UP = q0 << (uint32_T)rt_roundf_snf
      (-(8.0F - ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3));
  } else {
    ICARO3_Onda_bipe_controllonostro40cm_B.UP = 0U;
  }

  /* End of MATLAB Function: '<S153>/MATLAB Function1' */

  /* DataTypeConversion: '<S153>/Data Type Conversion1' */
  /* UP = 0; */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_i =
    ICARO3_Onda_bipe_controllonostro40cm_B.UT;

  /* DataTypeConversion: '<S153>/Data Type Conversion3' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_g = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.UP;

  /* MATLAB Function: '<S153>/MATLAB Function' */
  /* MATLAB Function 'sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function': '<S162>:1' */
  /*  AC1 = single(decomp(bitshift(bytes(1), 8) + bytes(2))); */
  /*  AC2 = single(decomp(bitshift(bytes(3), 8) + bytes(4))); */
  /*  AC3 = single(decomp(bitshift(bytes(5), 8) + bytes(6))); */
  /*   */
  /*  AC4 = single(bitshift(bytes(7), 8) + bytes(8)); */
  /*  AC5 = single(bitshift(bytes(9), 8) + bytes(10)); */
  /*  AC6 = single(bitshift(bytes(11), 8) + bytes(12)); */
  /*   */
  /*  B1 = single(decomp(bitshift(bytes(13), 8) + bytes(14))); */
  /*  B2 = single(decomp(bitshift(bytes(15), 8) + bytes(16))); */
  /*   */
  /*  MB = single(decomp(bitshift(bytes(17), 8) + bytes(18))); */
  /*  MC = single(decomp(bitshift(bytes(19), 8) + bytes(20))); */
  /*  MD = single(decomp(bitshift(bytes(21), 8) + bytes(22))); */
  /*   */
  /*  params = [AC1; AC2; AC3; AC4; AC5; AC6; B1; B2; MB; MC; MD]; */
  /* '<S162>:1:22' AC1 = params(1); */
  /* '<S162>:1:23' AC2 = params(2); */
  /* '<S162>:1:24' AC3 = params(3); */
  /* '<S162>:1:25' AC4 = params(4); */
  /* '<S162>:1:26' AC5 = params(5); */
  /* '<S162>:1:27' AC6 = params(6); */
  /* '<S162>:1:29' B1 = params(7); */
  /* '<S162>:1:30' B2 = params(8); */
  /* '<S162>:1:32' MB = params(9); */
  /* '<S162>:1:33' MC = params(10); */
  /* '<S162>:1:34' MD = params(11); */
  /*  AC1 = 9169; */
  /*  AC2 = -1269; */
  /*  AC3 = -14477; */
  /*  AC4 = 35455; */
  /*  AC5 = 24446; */
  /*  AC6 = 18385; */
  /*  */
  /*  B1 = 5498; */
  /*  B2 = 179; */
  /*  */
  /*  MB = -32768; */
  /*  MC = -11075; */
  /*  MD = 2432; */
  /*  UT = UT_bytes(1)*256 + UT_bytes(2); */
  /*  UP = (UP_bytes(1)*256*256 + UP_bytes(2)*256 + UP_bytes(3))/(2^(8 - oss)); */
  /*  Invalid data */
  /* '<S162>:1:54' if ((UT == 0 && UP == 0) || bmp085_enabled == 0) */
  if (((ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_i == 0.0F) &&
       (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_g == 0.0F)) ||
      (ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition1_g == 0)) {
    /* '<S162>:1:55' T = single(0); */
    ICARO3_Onda_bipe_controllonostro40cm_B.T = 0.0F;

    /* '<S162>:1:56' h = single(0); */
    ICARO3_Onda_bipe_controllonostro40cm_B.h = 0.0F;
  } else {
    /* '<S162>:1:57' else */
    /* '<S162>:1:58' X1 = (UT - AC6)*AC5/(2^15); */
    X1 = (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_i -
          ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[5]) *
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[4] / 32768.0F;

    /* '<S162>:1:59' X2 = MC*2^11/(X1 + MD); */
    /* '<S162>:1:60' B5 = X1 + X2; */
    X1 += ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[9] * 2048.0F /
      (X1 + ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[10]);

    /* '<S162>:1:61' T = (B5 + 8)/(2^4); */
    ICARO3_Onda_bipe_controllonostro40cm_B.T = (X1 + 8.0F) / 16.0F;

    /* '<S162>:1:63' B6 = B5 - 4000; */
    /* '<S162>:1:64' X1 = (B2*(B6*B6/(2^12)))/(2^11); */
    /* '<S162>:1:65' X2 = AC2*B6/(2^11); */
    /* '<S162>:1:66' X3 = X1 + X2; */
    /* '<S162>:1:67' B3 = ((AC1*4 + X3)*(2^oss) + 2)/4; */
    /* '<S162>:1:68' X1 = AC3*B6/(2^13); */
    /* '<S162>:1:69' X2 = (B1*(B6*B6/(2^12)))/(2^16); */
    /* '<S162>:1:70' X3 = ((X1 + X2) + 2)/(2^2); */
    /* '<S162>:1:71' B4 = AC4*(X3 + 32768)/(2^15); */
    /* '<S162>:1:72' B7 = (UP - B3)*50000/2^oss; */
    /* '<S162>:1:73' P = (B7*2)/B4; */
    X1 = (ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion3_g - ((((X1
              - 4000.0F) * (X1 - 4000.0F) / 4096.0F *
             ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[7] / 2048.0F
             + (X1 - 4000.0F) *
             ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[1] / 2048.0F)
            + ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[0] * 4.0F) *
           rt_powf_snf(2.0F,
                       ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3)
           + 2.0F) / 4.0F) * 50000.0F / rt_powf_snf(2.0F,
      ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversionmx3) * 2.0F /
      (((((X1 - 4000.0F) * (X1 - 4000.0F) / 4096.0F *
          ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[6] / 65536.0F +
          (X1 - 4000.0F) *
          ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[2] / 8192.0F) +
         2.0F) / 4.0F + 32768.0F) *
       ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition2[3] / 32768.0F);

    /* '<S162>:1:74' X1 = (P/(2^8))*(P/(2^8)); */
    /* '<S162>:1:75' X1 = (X1*3038)/2^16; */
    /* '<S162>:1:76' X2 = (-7357*P)/(2^16); */
    /* '<S162>:1:77' P = P + (X1 + X2 + 3791)/2^4; */
    X1 += ((X1 / 256.0F * (X1 / 256.0F) * 3038.0F / 65536.0F + -7357.0F * X1 /
            65536.0F) + 3791.0F) / 16.0F;

    /* '<S162>:1:78' h = 44330*(1 - (P/101325)^(1/5.255)); */
    ICARO3_Onda_bipe_controllonostro40cm_B.h = (1.0F - rt_powf_snf(X1 /
      101325.0F, 0.190294951F)) * 44330.0F;
  }

  /* End of MATLAB Function: '<S153>/MATLAB Function' */
  /* End of Outputs for SubSystem: '<S149>/Compute Temperature (T) and Altitude (H)' */
  /*  function y = decomp(u) */
  /*   */
  /*  u = single(u); */
  /*   */
  /*  if (u > 32767) */
  /*      y = single(-65536 + u); */
  /*  else */
  /*      y = single(u); */
  /*  end */
  /*   */
  /*  end */
}

/* Model step function for TID4 */
void ICARO3_Onda_bipe_controllonostro40cm_step4(void) /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition1' */
  if (ICARO3_Onda_bipe_controllonostro40cm_M->Timing.RateInteraction.TID4_5) {
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition1 =
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_o = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition1;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition54[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion27' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition53[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion26' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition52[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion24' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[0] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[1] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[2] = (real32_T)
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition55[2];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtSave data to data logger (the micro SD card)2Inport1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [0] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion2_o;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [1] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [2] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [3] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion1_e[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [4] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [5] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [6] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion27[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [7] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [8] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [9] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion26[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [10] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [11] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [12] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition51[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [13] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [14] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [15] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition50[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [16] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [17] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [18] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition56[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [19] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [20] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [21] = ICARO3_Onda_bipe_controllonostro40cm_B.DataTypeConversion24[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [22] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [23] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [24] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition4[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [25] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[0];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [26] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[1];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [27] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition6[2];
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [28] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition12;
  ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
    [29] = ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition7;

  /* S-Function (sfun_raw_float_downlink): '<Root>/Save data to data logger (the micro SD card)2' */
  wrap_raw_float_downlink_output_width_fcn
    (&ICARO3_Onda_bipe_controllonostro40cm_B.TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1
     [0], 30);
}

/* Model step function for TID5 */
void ICARO3_Onda_bipe_controllonostro40cm_step5(void) /* Sample time: [1.0s, 0.0s] */
{
  /* DigitalClock: '<Root>/Digital Clock1' */
  ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock1 =
    ((ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick5) );

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition1_Buffer0 =
    ICARO3_Onda_bipe_controllonostro40cm_B.DigitalClock1;

  /* Update absolute time */
  /* The "clockTick5" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick5" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_Onda_bipe_controllonostro40cm_M->Timing.clockTick5++;
}

/* Model step wrapper function for compatibility with a static main program */
void ICARO3_Onda_bipe_controllonostro40cm_step(int_T tid)
{
  switch (tid) {
   case 0 :
    ICARO3_Onda_bipe_controllonostro40cm_step0();
    break;

   case 1 :
    ICARO3_Onda_bipe_controllonostro40cm_step1();
    break;

   case 2 :
    ICARO3_Onda_bipe_controllonostro40cm_step2();
    break;

   case 3 :
    ICARO3_Onda_bipe_controllonostro40cm_step3();
    break;

   case 4 :
    ICARO3_Onda_bipe_controllonostro40cm_step4();
    break;

   case 5 :
    ICARO3_Onda_bipe_controllonostro40cm_step5();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ICARO3_Onda_bipe_controllonostro40cm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ICARO3_Onda_bipe_controllonostro40cm_M, 0,
                sizeof(RT_MODEL_ICARO3_Onda_bipe_controllonostro40cm));

  /* block I/O */
  (void) memset(((void *) &ICARO3_Onda_bipe_controllonostro40cm_B), 0,
                sizeof(BlockIO_ICARO3_Onda_bipe_controllonostro40cm));

  /* states (dwork) */
  (void) memset((void *)&ICARO3_Onda_bipe_controllonostro40cm_DWork, 0,
                sizeof(D_Work_ICARO3_Onda_bipe_controllonostro40cm));

  {
    int32_T i;

    /* Start for S-Function (sfun_I2C1_sensors_loop): '<S168>/I2C1 Sensors Loop' */
    wrap_I2C1_sensors_loop_start_fcn
      (&ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o1[0],
       &ICARO3_Onda_bipe_controllonostro40cm_B.I2C1SensorsLoop_o2);

    /* InitializeConditions for Enabled SubSystem: '<S34>/Subsystem' */
    /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE_e =
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE_i =
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator1_IC;

    /* End of InitializeConditions for SubSystem: '<S34>/Subsystem' */

    /* Start for Enabled SubSystem: '<S35>/Subsystem' */
    ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_g,
       (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_g);

    /* End of Start for SubSystem: '<S35>/Subsystem' */

    /* Start for Enabled SubSystem: '<S36>/Subsystem' */
    ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_p,
       (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_p);

    /* End of Start for SubSystem: '<S36>/Subsystem' */

    /* Start for RateTransition: '<Root>/Rate Transition49' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition49[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;

    /* InitializeConditions for Enabled SubSystem: '<S40>/Subsystem' */
    /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator_DSTATE =
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator_IC_d;

    /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.DiscreteTimeIntegrator1_DSTATE =
      ICARO3_Onda_bipe_controllonostro40cm_P.DiscreteTimeIntegrator1_IC_i;

    /* End of InitializeConditions for SubSystem: '<S40>/Subsystem' */

    /* Start for Enabled SubSystem: '<S41>/Subsystem' */
    ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_l,
       (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_l);

    /* End of Start for SubSystem: '<S41>/Subsystem' */

    /* Start for Enabled SubSystem: '<S42>/Subsystem' */
    ICARO3_Onda_bipe_controllonostro40cm_Subsystem_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_DWork.Subsystem_o,
       (rtP_Subsystem_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.Subsystem_o);

    /* End of Start for SubSystem: '<S42>/Subsystem' */

    /* InitializeConditions for Enabled SubSystem: '<S3>/Attitude Filter ADIS' */
    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[0];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[1];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[2];
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay1_DSTATE[3] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay1_InitialCondition[3];

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay2_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay3' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.UnitDelay3_DSTATE[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S30>/dcm_marg' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.ini_not_empty = false;

    /* End of InitializeConditions for SubSystem: '<S3>/Attitude Filter ADIS' */

    /* Start for Enabled SubSystem: '<S3>/Attitude Filter ADIS' */
    /* VirtualOutportStart for Outport: '<S27>/q' */
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.q_Y0[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.q_Y0[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.q_Y0[2];
    ICARO3_Onda_bipe_controllonostro40cm_B.q_out[3] =
      ICARO3_Onda_bipe_controllonostro40cm_P.q_Y0[3];

    /* VirtualOutportStart for Outport: '<S27>/rpy' */
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.rpy_Y0[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.rpy_Y0[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.euler_out[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.rpy_Y0[2];

    /* VirtualOutportStart for Outport: '<S27>/a_ned' */
    ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.a_ned_Y0[0];
    ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.a_ned_Y0[1];
    ICARO3_Onda_bipe_controllonostro40cm_B.a_ned[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.a_ned_Y0[2];

    /* End of Start for SubSystem: '<S3>/Attitude Filter ADIS' */
    /* Start for S-Function (sfun_UPboard_downlink): '<Root>/Save data to data logger (the micro SD card)1' */
    wrap_UPboard_downlink_start_fcn();

    /* Start for RateTransition: '<Root>/Rate Transition1' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition1 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition1_X0;

    /* Start for S-Function (sfun_UPboard): '<Root>/S-Function-USART3_Receive4' */
    wrap_UPboard_start_fcn();

    /* Start for S-Function (sfun_raw_float_downlink): '<Root>/Save data to data logger (the micro SD card)2' */
    wrap_raw_float_downlink_start_fcn();

    /* Start for RateTransition: '<Root>/Rate Transition47' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition47 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition47_X0;

    /* Start for RateTransition: '<Root>/Rate Transition48' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition48 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition48_X0;

    /* Start for S-Function (sfun_PWM_servomotor): '<Root>/reproduce PWM9' */
    wrap_PWM_servomotor_start_fcn(1.0,1.0,1.0,1.0);

    /* Start for S-Function (sfun_ADC_Receive): '<S2>/PWM1' */
    wrap_ADC_Receive_start_fcn();
    for (i = 0; i < 8; i++) {
      /* Start for RateTransition: '<S171>/Rate Transition' */
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition_X0;

      /* Start for RateTransition: '<S171>/Rate Transition14' */
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition14[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition14_X0;

      /* Start for RateTransition: '<S171>/Rate Transition15' */
      ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition15[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition15_X0;
    }

    /* Start for Atomic SubSystem: '<S150>/CANbus data RX' */

    /* Start for S-Function (sfun_CAN_Receive): '<S167>/CANRX' */
    wrap_CAN_Receive_start_fcn
      (&ICARO3_Onda_bipe_controllonostro40cm_P.Rx_ID1_Value,6.0);

    /* End of Start for SubSystem: '<S150>/CANbus data RX' */

    /* Start for S-Function (sfun_gpsparser_UBLOX): '<S77>/S-Function3' */
    wrap_gpsparser_UBLOX_start_fcn();

    /* InitializeConditions for Iterator SubSystem: '<S81>/While Iterator Subsystem' */
    /* InitializeConditions for Memory: '<S92>/Memory' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory_PreviousInput =
      ICARO3_Onda_bipe_controllonostro40cm_P.Memory_X0;

    /* End of InitializeConditions for SubSystem: '<S81>/While Iterator Subsystem' */

    /* Start for Iterator SubSystem: '<S81>/While Iterator Subsystem' */
    /* VirtualOutportStart for Outport: '<S86>/phi' */
    ICARO3_Onda_bipe_controllonostro40cm_B.TrigonometricFunction4 =
      ICARO3_Onda_bipe_controllonostro40cm_P.phi_Y0;

    /* End of Start for SubSystem: '<S81>/While Iterator Subsystem' */

    /* Start for Enabled SubSystem: '<S79>/clock latch' */
    /* VirtualOutportStart for Outport: '<S94>/Out' */
    ICARO3_Onda_bipe_controllonostro40cm_B.In =
      ICARO3_Onda_bipe_controllonostro40cm_P.Out_Y0;

    /* End of Start for SubSystem: '<S79>/clock latch' */

    /* Start for Enabled SubSystem: '<S150>/send motor commands via canbus' */
    /* Start for S-Function (sfun_CAN_Transmit): '<S172>/CANTX1' */
    wrap_CAN_Transmit_start_fcn();

    /* Start for S-Function (sfun_CAN_Transmit): '<S172>/CANTX2' */
    wrap_CAN_Transmit_start_fcn();

    /* Start for S-Function (sfun_CAN_Transmit): '<S172>/CANTX3' */
    wrap_CAN_Transmit_start_fcn();

    /* Start for DiscretePulseGenerator: '<S172>/Pulse Generator' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter_f = 0;

    /* End of Start for SubSystem: '<S150>/send motor commands via canbus' */

    /* InitializeConditions for Enabled SubSystem: '<S150>/send motor commands via canbus' */
    /* InitializeConditions for UnitDelay: '<S202>/Output' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Output_DSTATE =
      ICARO3_Onda_bipe_controllonostro40cm_P.Output_InitialCondition;

    /* End of InitializeConditions for SubSystem: '<S150>/send motor commands via canbus' */

    /* Start for RateTransition: '<S171>/Rate Transition18' */
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition18_X0;
    ICARO3_Onda_bipe_controllonostro40cm_B.RateTransition18[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition18_X0;

    /* Start for Enabled SubSystem: '<S80>/clock latch' */
    ICARO3_Onda_bipe_controllonostro40cm_clocklatch_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_B.clocklatch_m,
       (rtP_clocklatch_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.clocklatch_m);

    /* End of Start for SubSystem: '<S80>/clock latch' */

    /* Start for Enabled SubSystem: '<Root>/clock latch' */
    ICARO3_Onda_bipe_controllonostro40cm_clocklatch_Start
      (&ICARO3_Onda_bipe_controllonostro40cm_B.clocklatch_h,
       (rtP_clocklatch_ICARO3_Onda_bipe_controllonostro40cm *)
       &ICARO3_Onda_bipe_controllonostro40cm_P.clocklatch_h);

    /* End of Start for SubSystem: '<Root>/clock latch' */

    /* Start for DiscretePulseGenerator: '<S13>/Pulse Generator1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.clockTickCounter = 0;

    /* Start for S-Function (sfun_USART2_Init): '<Root>/USART2 Initialization' */
    wrap_USART2_Init_start_fcn();

    /* Start for S-Function (sfun_USART3_Init): '<Root>/USART3 Initialization' */
    wrap_USART3_Init_start_fcn();

    /* Start for S-Function (sfun_USART4_Init): '<Root>/USART4 Initialization' */
    wrap_USART4_Init_start_fcn();

    /* Start for S-Function (sfun_USART5_Init): '<Root>/USART5 Initialization' */
    wrap_USART5_Init_start_fcn();
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition49' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition49_Buffer0[2] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition49_X0;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition1_Buffer0 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition1_X0;

    /* InitializeConditions for Memory: '<S70>/Memory1' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.Memory1_PreviousInput =
      ICARO3_Onda_bipe_controllonostro40cm_P.Memory1_X0;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition47' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition47_Buffer0 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition47_X0;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition48' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition48_Buffer0 =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition48_X0;
    for (i = 0; i < 8; i++) {
      /* InitializeConditions for RateTransition: '<S171>/Rate Transition' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition_Buffer[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition_X0;

      /* InitializeConditions for RateTransition: '<S171>/Rate Transition14' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition14_Buffer[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition14_X0;

      /* InitializeConditions for RateTransition: '<S171>/Rate Transition15' */
      ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition15_Buffer[i] =
        ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition15_X0;
    }

    /* InitializeConditions for RateTransition: '<S171>/Rate Transition18' */
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer[0] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition18_X0;
    ICARO3_Onda_bipe_controllonostro40cm_DWork.RateTransition18_Buffer[1] =
      ICARO3_Onda_bipe_controllonostro40cm_P.RateTransition18_X0;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_bipe_controllonostro40cm.c
 */
