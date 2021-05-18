/*
 * File: ICARO3_HAL_v1.c
 *
 * Code generated for Simulink model :ICARO3_HAL_v1.
 *
 * Model version      : 1.596
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Wed Jun 01 14:53:28 2016
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

#include "ICARO3_HAL_v1.h"
#include "ICARO3_HAL_v1_private.h"

/* Block signals (auto storage) */
BlockIO_ICARO3_HAL_v1 ICARO3_HAL_v1_B;

/* Block states (auto storage) */
D_Work_ICARO3_HAL_v1 ICARO3_HAL_v1_DWork;

/* Real-time model */
RT_MODEL_ICARO3_HAL_v1 ICARO3_HAL_v1_M_;
RT_MODEL_ICARO3_HAL_v1 *const ICARO3_HAL_v1_M = &ICARO3_HAL_v1_M_;

/* Forward declaration for local functions */
static real32_T ICARO3_HAL_v1_norm(const real32_T x[3]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ICARO3_HAL_v1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ICARO3_HAL_v1_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(ICARO3_HAL_v1_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(ICARO3_HAL_v1_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(ICARO3_HAL_v1_M, 4));
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

  /* tid 0 shares data with slower tid rates: 1, 2, 3 */
  ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1 =
    (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[1] == 0);
  ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_2 =
    (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[2] == 0);
  ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_3 =
    (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[3] == 0);

  /* tid 1 shares data with slower tid rate: 4 */
  if (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[1] == 0) {
    ICARO3_HAL_v1_M->Timing.RateInteraction.TID1_4 =
      (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[1])++;
  if ((ICARO3_HAL_v1_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.01s, 0.0s] */
    ICARO3_HAL_v1_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[2])++;
  if ((ICARO3_HAL_v1_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.02s, 0.0s] */
    ICARO3_HAL_v1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[3])++;
  if ((ICARO3_HAL_v1_M->Timing.TaskCounters.TID[3]) > 39) {/* Sample time: [0.1s, 0.0s] */
    ICARO3_HAL_v1_M->Timing.TaskCounters.TID[3] = 0;
  }

  (ICARO3_HAL_v1_M->Timing.TaskCounters.TID[4])++;
  if ((ICARO3_HAL_v1_M->Timing.TaskCounters.TID[4]) > 399) {/* Sample time: [1.0s, 0.0s] */
    ICARO3_HAL_v1_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Function for MATLAB Function: '<S29>/dcm_marg' */
static real32_T ICARO3_HAL_v1_norm(const real32_T x[3])
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

/*
 * Initial conditions for enable system:
 *    '<S2>/Attitude Filter ADIS'
 *    '<S17>/Attitude Filter MPU'
 *    '<S19>/Attitude Filter SS'
 */
void ICARO3_HAL_v1_AttitudeFilterADIS_Init(rtDW_AttitudeFilterADIS_ICARO3_HAL_v1
  *localDW, rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP)
{
  localDW->UnitDelay1_DSTATE[0] = localP->UnitDelay1_InitialCondition[0];
  localDW->UnitDelay1_DSTATE[1] = localP->UnitDelay1_InitialCondition[1];
  localDW->UnitDelay1_DSTATE[2] = localP->UnitDelay1_InitialCondition[2];
  localDW->UnitDelay1_DSTATE[3] = localP->UnitDelay1_InitialCondition[3];
  localDW->UnitDelay2_DSTATE[0] = localP->UnitDelay2_InitialCondition;
  localDW->UnitDelay2_DSTATE[1] = localP->UnitDelay2_InitialCondition;
  localDW->UnitDelay2_DSTATE[2] = localP->UnitDelay2_InitialCondition;
  localDW->UnitDelay3_DSTATE[0] = localP->UnitDelay3_InitialCondition;
  localDW->UnitDelay3_DSTATE[1] = localP->UnitDelay3_InitialCondition;
  localDW->UnitDelay3_DSTATE[2] = localP->UnitDelay3_InitialCondition;
  localDW->ini_not_empty = false;
}

/*
 * Disable for enable system:
 *    '<S2>/Attitude Filter ADIS'
 *    '<S17>/Attitude Filter MPU'
 *    '<S19>/Attitude Filter SS'
 */
void ICARO3_HAL_v1_AttitudeFilterADIS_Disable
  (rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW)
{
  localDW->AttitudeFilterADIS_MODE = false;
}

/*
 * Start for enable system:
 *    '<S2>/Attitude Filter ADIS'
 *    '<S17>/Attitude Filter MPU'
 *    '<S19>/Attitude Filter SS'
 */
void ICARO3_HAL_v1_AttitudeFilterADIS_Start(rtB_AttitudeFilterADIS_ICARO3_HAL_v1
  *localB, rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW,
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP)
{
  ICARO3_HAL_v1_AttitudeFilterADIS_Init(localDW, localP);
  localB->euler_out[0] = localP->rpy_Y0[0];
  localB->euler_out[1] = localP->rpy_Y0[1];
  localB->euler_out[2] = localP->rpy_Y0[2];
  localB->a_ned[0] = localP->a_ned_Y0[0];
  localB->a_ned[1] = localP->a_ned_Y0[1];
  localB->a_ned[2] = localP->a_ned_Y0[2];
}

/*
 * Output and update for enable system:
 *    '<S2>/Attitude Filter ADIS'
 *    '<S17>/Attitude Filter MPU'
 *    '<S19>/Attitude Filter SS'
 */
void ICARO3_HAL_v1_AttitudeFilterADIS(real_T rtu_Enable, const real32_T rtu_acc
  [3], const real32_T rtu_bias[3], const real32_T rtu_gyro[3], const real32_T
  rtu_mag[3], rtB_AttitudeFilterADIS_ICARO3_HAL_v1 *localB,
  rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW,
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP)
{
  real32_T q3;
  real32_T bx;
  real32_T bz;
  real32_T ib[3];
  real32_T jb[3];
  real32_T c[9];
  real32_T b_q1;
  static const int8_T f[3] = { 0, 0, -1 };

  static const real32_T g[3] = { 0.034168072F, -0.999416113F, 0.0F };

  static const real32_T h[3] = { -0.999416113F, -0.034168072F, 0.0F };

  real32_T rtb_Sum_p[3];
  real32_T ib_0[9];
  real32_T jb_0[9];
  int32_T i;
  real32_T tmp[9];
  real32_T e_m_idx_2;
  real32_T e_m_idx_1;
  real32_T e_m_idx_0;
  real32_T q_idx_0;
  real32_T q_idx_1;
  real32_T q_idx_2;
  real32_T q_idx_3;
  real32_T e_a_idx_0;
  real32_T e_a_idx_1;
  real32_T rtb_e_int_out_m_idx_2;
  if (rtu_Enable > 0.0) {
    if (!localDW->AttitudeFilterADIS_MODE) {
      ICARO3_HAL_v1_AttitudeFilterADIS_Init(localDW, localP);
      localDW->AttitudeFilterADIS_MODE = true;
    }

    rtb_Sum_p[0] = rtu_acc[0] - rtu_bias[0];
    rtb_Sum_p[1] = rtu_acc[1] - rtu_bias[1];
    rtb_Sum_p[2] = rtu_acc[2] - rtu_bias[2];
    e_m_idx_0 = rtu_mag[0];
    e_m_idx_1 = rtu_mag[1];
    e_m_idx_2 = rtu_mag[2];
    q_idx_0 = localDW->UnitDelay1_DSTATE[0];
    q_idx_1 = localDW->UnitDelay1_DSTATE[1];
    q_idx_2 = localDW->UnitDelay1_DSTATE[2];
    q_idx_3 = localDW->UnitDelay1_DSTATE[3];

    /*  mode == 0: magnetos' errors don't affect roll and pitch angles */
    /*  mode == 1: standard implementation, roll, pitch and yaw depend on */
    /*  acceleroters and magnetos in the same measure */
    /*  Magnetos and accelerometers MUST have non null norm, if they have null */
    /*  norm an error occurred and filter probably will get confused, adjust mag */
    /*  and acc values to try to avoid filter problems.  */
    if ((real_T)ICARO3_HAL_v1_norm(rtb_Sum_p) < 0.0001) {
      rtb_Sum_p[0] = 0.0F;
      rtb_Sum_p[1] = 0.0F;
      rtb_Sum_p[2] = -9.81F;
    }

    if ((real_T)ICARO3_HAL_v1_norm(rtu_mag) < 0.0001) {
      e_m_idx_0 = 0.234F;
      e_m_idx_1 = 0.008F;
      e_m_idx_2 = 0.404F;
    }

    /*  Init quaternion using the first accelerometers and magnetometers reading */
    /*  in triad algorithm. */
    if (!localDW->ini_not_empty) {
      /*  Triad algorithm */
      b_q1 = ICARO3_HAL_v1_norm(rtb_Sum_p);
      ib[0] = rtb_Sum_p[0] / b_q1;
      ib[1] = rtb_Sum_p[1] / b_q1;
      ib[2] = rtb_Sum_p[2] / b_q1;
      jb[0] = ib[1] * e_m_idx_2 - ib[2] * e_m_idx_1;
      jb[1] = ib[2] * e_m_idx_0 - ib[0] * e_m_idx_2;
      jb[2] = ib[0] * e_m_idx_1 - ib[1] * e_m_idx_0;
      b_q1 = ICARO3_HAL_v1_norm(jb);
      jb[0] /= b_q1;
      jb[1] /= b_q1;
      e_a_idx_1 = jb[2] / b_q1;
      for (i = 0; i < 3; i++) {
        ib_0[i] = ib[0] * (real32_T)f[i];
        ib_0[i + 3] = ib[1] * (real32_T)f[i];
        ib_0[i + 6] = ib[2] * (real32_T)f[i];
      }

      for (i = 0; i < 3; i++) {
        jb_0[i] = jb[0] * g[i];
        jb_0[i + 3] = jb[1] * g[i];
        jb_0[i + 6] = e_a_idx_1 * g[i];
      }

      e_a_idx_0 = ib[1] * e_a_idx_1 - ib[2] * jb[1];
      e_a_idx_1 = ib[2] * jb[0] - ib[0] * e_a_idx_1;
      q3 = ib[0] * jb[1] - ib[1] * jb[0];
      for (i = 0; i < 3; i++) {
        c[i] = (ib_0[i] + jb_0[i]) + e_a_idx_0 * h[i];
        c[i + 3] = (ib_0[i + 3] + jb_0[i + 3]) + e_a_idx_1 * h[i];
        c[i + 6] = (ib_0[i + 6] + jb_0[i + 6]) + q3 * h[i];
      }

      b_q1 = (real32_T)sqrt(((1.0F + c[0]) + c[4]) + c[8]) * 0.5F;
      q_idx_0 = b_q1;
      q_idx_1 = 0.25F / b_q1 * (c[5] - c[7]);
      q_idx_2 = 0.25F / b_q1 * (c[6] - c[2]);
      q_idx_3 = 0.25F / b_q1 * (c[1] - c[3]);
      localDW->ini_not_empty = true;
    }

    /*  Rt rotates NED to body, and obviously converts body cordinates into ned */
    /*  coordinates. */
    c[0] = (1.0F - q_idx_2 * q_idx_2 * 2.0F) - q_idx_3 * q_idx_3 * 2.0F;
    c[3] = (q_idx_1 * q_idx_2 - q_idx_0 * q_idx_3) * 2.0F;
    c[6] = (q_idx_1 * q_idx_3 + q_idx_0 * q_idx_2) * 2.0F;
    c[1] = (q_idx_1 * q_idx_2 + q_idx_0 * q_idx_3) * 2.0F;
    c[4] = (1.0F - q_idx_1 * q_idx_1 * 2.0F) - q_idx_3 * q_idx_3 * 2.0F;
    c[7] = (q_idx_2 * q_idx_3 - q_idx_0 * q_idx_1) * 2.0F;
    c[2] = (q_idx_1 * q_idx_3 - q_idx_0 * q_idx_2) * 2.0F;
    c[5] = (q_idx_2 * q_idx_3 + q_idx_0 * q_idx_1) * 2.0F;
    c[8] = (1.0F - q_idx_1 * q_idx_1 * 2.0F) - q_idx_2 * q_idx_2 * 2.0F;

    /*  Filter implementation, see article for details */
    for (i = 0; i < 3; i++) {
      ib[i] = c[i + 6] * e_m_idx_2 + (c[i + 3] * e_m_idx_1 + c[i] * e_m_idx_0);
    }

    bx = (real32_T)sqrt(ib[0] * ib[0] + ib[1] * ib[1]);
    bz = (real32_T)fabs(ib[2]);
    b_q1 = (real32_T)sqrt(((rtb_Sum_p[0] * rtb_Sum_p[0] + rtb_Sum_p[1] *
      rtb_Sum_p[1]) + rtb_Sum_p[2] * rtb_Sum_p[2]) + 2.22044605E-16F);
    ib[2] = rtb_Sum_p[2] / b_q1;
    for (i = 0; i < 3; i++) {
      jb[i] = -c[3 * i + 2] + (c[3 * i + 1] * 0.0F + c[3 * i] * 0.0F);
    }

    e_a_idx_0 = rtb_Sum_p[1] / b_q1 * jb[2] - ib[2] * jb[1];
    e_a_idx_1 = ib[2] * jb[0] - rtb_Sum_p[0] / b_q1 * jb[2];
    b_q1 = (real32_T)sqrt(((e_m_idx_0 * e_m_idx_0 + e_m_idx_1 * e_m_idx_1) +
      e_m_idx_2 * e_m_idx_2) + 2.22044605E-16F);
    e_m_idx_2 = (real32_T)sqrt((bx * bx + bz * bz) + 2.22044605E-16F);
    for (i = 0; i < 3; i++) {
      jb[i] = ((c[3 * i + 1] * 0.0F + c[3 * i] * bx) + c[3 * i + 2] * bz) /
        e_m_idx_2;
    }

    e_m_idx_2 = e_m_idx_0 / b_q1 * jb[1] - e_m_idx_1 / b_q1 * jb[0];
    jb[0] = localP->dcm_marg_T * e_a_idx_0 + localDW->UnitDelay2_DSTATE[0];
    jb[1] = localP->dcm_marg_T * e_a_idx_1 + localDW->UnitDelay2_DSTATE[1];
    jb[2] = localP->dcm_marg_T * 0.0F + localDW->UnitDelay2_DSTATE[2];
    e_m_idx_0 = localP->dcm_marg_T * 0.0F + localDW->UnitDelay3_DSTATE[0];
    e_m_idx_1 = localP->dcm_marg_T * 0.0F + localDW->UnitDelay3_DSTATE[1];
    rtb_e_int_out_m_idx_2 = localP->dcm_marg_T * e_m_idx_2 +
      localDW->UnitDelay3_DSTATE[2];
    ib[0] = (localP->DCM_MARG_QUAT_Kp * e_a_idx_0 + rtu_gyro[0]) + (jb[0] +
      e_m_idx_0) * localP->DCM_MARG_QUAT_Ki;
    ib[1] = (localP->DCM_MARG_QUAT_Kp * e_a_idx_1 + rtu_gyro[1]) + (jb[1] +
      e_m_idx_1) * localP->DCM_MARG_QUAT_Ki;
    ib[2] = (localP->DCM_MARG_QUAT_Kp * e_m_idx_2 + rtu_gyro[2]) + (jb[2] +
      rtb_e_int_out_m_idx_2) * localP->DCM_MARG_QUAT_Ki;

    /*  Quaternion integration */
    bx = ((-q_idx_1 * ib[0] - q_idx_2 * ib[1]) - q_idx_3 * ib[2]) / 2.0F *
      localP->dcm_marg_T + q_idx_0;
    bz = ((q_idx_0 * ib[0] + q_idx_2 * ib[2]) - q_idx_3 * ib[1]) / 2.0F *
      localP->dcm_marg_T + q_idx_1;
    q3 = ((q_idx_0 * ib[1] - q_idx_1 * ib[2]) + q_idx_3 * ib[0]) / 2.0F *
      localP->dcm_marg_T + q_idx_2;
    e_a_idx_1 = ((q_idx_0 * ib[2] + q_idx_1 * ib[1]) - q_idx_2 * ib[0]) / 2.0F *
      localP->dcm_marg_T + q_idx_3;

    /*  Quaternion normalization */
    b_q1 = (real32_T)sqrt(((bx * bx + bz * bz) + q3 * q3) + e_a_idx_1 *
                          e_a_idx_1);
    bx /= b_q1;
    bz /= b_q1;
    q3 /= b_q1;
    e_a_idx_1 /= b_q1;

    /*  Rt rotates NED to body, and obviously converts body cordinates into ned */
    /*  coordinates. */
    /*  Obtain rpy angles */
    b_q1 = (q3 * e_a_idx_1 + bx * bz) * 2.0F;
    e_m_idx_2 = (1.0F - bz * bz * 2.0F) - q3 * q3 * 2.0F;

    /*  Compute accelerations in NED */
    /*  Suppose that mean of integral correction is bias value */
    localB->euler_out[0] = rt_atan2f_snf((q3 * e_a_idx_1 + bx * bz) * 2.0F,
      (1.0F - bz * bz * 2.0F) - q3 * q3 * 2.0F);
    localB->euler_out[1] = rt_atan2f_snf((bz * e_a_idx_1 - bx * q3) * -2.0F,
      (real32_T)sqrt(b_q1 * b_q1 + e_m_idx_2 * e_m_idx_2));
    localB->euler_out[2] = rt_atan2f_snf((bz * q3 + bx * e_a_idx_1) * 2.0F,
      (1.0F - q3 * q3 * 2.0F) - e_a_idx_1 * e_a_idx_1 * 2.0F);
    tmp[0] = (1.0F - q3 * q3 * 2.0F) - e_a_idx_1 * e_a_idx_1 * 2.0F;
    tmp[3] = (bz * q3 - bx * e_a_idx_1) * 2.0F;
    tmp[6] = (bz * e_a_idx_1 + bx * q3) * 2.0F;
    tmp[1] = (bz * q3 + bx * e_a_idx_1) * 2.0F;
    tmp[4] = (1.0F - bz * bz * 2.0F) - e_a_idx_1 * e_a_idx_1 * 2.0F;
    tmp[7] = (q3 * e_a_idx_1 - bx * bz) * 2.0F;
    tmp[2] = (bz * e_a_idx_1 - bx * q3) * 2.0F;
    tmp[5] = (q3 * e_a_idx_1 + bx * bz) * 2.0F;
    tmp[8] = (1.0F - bz * bz * 2.0F) - q3 * q3 * 2.0F;
    for (i = 0; i < 3; i++) {
      localB->a_ned[i] = 0.0F;
      localB->a_ned[i] += tmp[i] * rtb_Sum_p[0];
      localB->a_ned[i] += tmp[i + 3] * rtb_Sum_p[1];
      localB->a_ned[i] += tmp[i + 6] * rtb_Sum_p[2];
    }

    localDW->UnitDelay1_DSTATE[0] = bx;
    localDW->UnitDelay1_DSTATE[1] = bz;
    localDW->UnitDelay1_DSTATE[2] = q3;
    localDW->UnitDelay1_DSTATE[3] = e_a_idx_1;
    localDW->UnitDelay2_DSTATE[0] = jb[0];
    localDW->UnitDelay2_DSTATE[1] = jb[1];
    localDW->UnitDelay2_DSTATE[2] = jb[2];
    localDW->UnitDelay3_DSTATE[0] = e_m_idx_0;
    localDW->UnitDelay3_DSTATE[1] = e_m_idx_1;
    localDW->UnitDelay3_DSTATE[2] = rtb_e_int_out_m_idx_2;
  } else {
    if (localDW->AttitudeFilterADIS_MODE) {
      ICARO3_HAL_v1_AttitudeFilterADIS_Disable(localDW);
    }
  }
}

/*
 * Initial conditions for enable system:
 *    '<S33>/Subsystem'
 *    '<S338>/Subsystem'
 *    '<S432>/Subsystem'
 *    '<S484>/Subsystem'
 */
void ICARO3_HAL_v1_Subsystem_Init(rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP)
{
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator1_DSTATE = localP->DiscreteTimeIntegrator1_IC;
}

/*
 * Start for enable system:
 *    '<S33>/Subsystem'
 *    '<S338>/Subsystem'
 *    '<S432>/Subsystem'
 *    '<S484>/Subsystem'
 */
void ICARO3_HAL_v1_Subsystem_Start(rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP)
{
  ICARO3_HAL_v1_Subsystem_Init(localDW, localP);
}

/*
 * Output and update for enable system:
 *    '<S33>/Subsystem'
 *    '<S338>/Subsystem'
 *    '<S432>/Subsystem'
 *    '<S484>/Subsystem'
 */
void ICARO3_HAL_v1_Subsystem(real32_T rtu_Enable, real_T rtu_In1,
  rtB_Subsystem_ICARO3_HAL_v1 *localB, rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP)
{
  if (rtu_Enable > 0.0F) {
    localB->Product1 = localDW->DiscreteTimeIntegrator_DSTATE /
      localDW->DiscreteTimeIntegrator1_DSTATE;
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * rtu_In1;
    localDW->DiscreteTimeIntegrator1_DSTATE +=
      localP->DiscreteTimeIntegrator1_gainval * localP->Constant_Value;
  }
}

/*
 * Initial conditions for enable system:
 *    '<S34>/Subsystem'
 *    '<S35>/Subsystem'
 *    '<S40>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S339>/Subsystem'
 *    '<S340>/Subsystem'
 *    '<S344>/Subsystem'
 *    '<S345>/Subsystem'
 *    '<S346>/Subsystem'
 *    '<S433>/Subsystem'
 *    ...
 */
void ICARO3_HAL_v1_Subsystem_c_Init(rtDW_Subsystem_ICARO3_HAL_v1_c *localDW,
  rtP_Subsystem_ICARO3_HAL_v1_o *localP)
{
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator1_DSTATE = localP->DiscreteTimeIntegrator1_IC;
}

/*
 * Start for enable system:
 *    '<S34>/Subsystem'
 *    '<S35>/Subsystem'
 *    '<S40>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S339>/Subsystem'
 *    '<S340>/Subsystem'
 *    '<S344>/Subsystem'
 *    '<S345>/Subsystem'
 *    '<S346>/Subsystem'
 *    '<S433>/Subsystem'
 *    ...
 */
void ICARO3_HAL_v1_Subsystem_d_Start(rtDW_Subsystem_ICARO3_HAL_v1_c *localDW,
  rtP_Subsystem_ICARO3_HAL_v1_o *localP)
{
  ICARO3_HAL_v1_Subsystem_c_Init(localDW, localP);
}

/*
 * Output and update for enable system:
 *    '<S34>/Subsystem'
 *    '<S35>/Subsystem'
 *    '<S40>/Subsystem'
 *    '<S41>/Subsystem'
 *    '<S339>/Subsystem'
 *    '<S340>/Subsystem'
 *    '<S344>/Subsystem'
 *    '<S345>/Subsystem'
 *    '<S346>/Subsystem'
 *    '<S433>/Subsystem'
 *    ...
 */
void ICARO3_HAL_v1_Subsystem_b(real32_T rtu_Enable, real_T rtu_In1,
  rtB_Subsystem_ICARO3_HAL_v1_j *localB, rtDW_Subsystem_ICARO3_HAL_v1_c *localDW,
  rtP_Subsystem_ICARO3_HAL_v1_o *localP)
{
  if (rtu_Enable > 0.0F) {
    localB->Product1 = localDW->DiscreteTimeIntegrator_DSTATE /
      localDW->DiscreteTimeIntegrator1_DSTATE;
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * rtu_In1;
    localDW->DiscreteTimeIntegrator1_DSTATE +=
      localP->DiscreteTimeIntegrator1_gainval * localP->Constant_Value;
  }
}

/*
 * Output and update for atomic system:
 *    '<S47>/MATLAB Function1'
 *    '<S47>/MATLAB Function3'
 */
void ICARO3_HAL_v1_MATLABFunction1(real_T rtu_vect_ned, real_T rtu_vect_ned_i,
  const real_T rtu_rpy[3], rtB_MATLABFunction1_ICARO3_HAL_v1 *localB)
{
  /*  rpy -> vehicle attitude */
  /*  vect_ned -> NED coordinates vector */
  /*  VERTICAL AXIS coordinates vector */
  localB->vect_vax[0] = 0.0;
  localB->vect_vax[0] += cos(rtu_rpy[2]) * rtu_vect_ned;
  localB->vect_vax[0] += sin(rtu_rpy[2]) * rtu_vect_ned_i;
  localB->vect_vax[1] = 0.0;
  localB->vect_vax[1] += -sin(rtu_rpy[2]) * rtu_vect_ned;
  localB->vect_vax[1] += cos(rtu_rpy[2]) * rtu_vect_ned_i;
}

/*
 * Initial conditions for atomic system:
 *    '<S47>/MATLAB Function2'
 *    '<S160>/MATLAB Function2'
 *    '<S49>/MATLAB Function4'
 *    '<S240>/MATLAB Function2'
 */
void ICARO3_HAL_v1_MATLABFunction2_Init(rtDW_MATLABFunction2_ICARO3_HAL_v1
  *localDW)
{
  localDW->k_not_empty = false;
}

/*
 * Output and update for atomic system:
 *    '<S47>/MATLAB Function2'
 *    '<S160>/MATLAB Function2'
 *    '<S49>/MATLAB Function4'
 *    '<S240>/MATLAB Function2'
 */
void ICARO3_HAL_v1_MATLABFunction2(real_T rtu_u,
  rtB_MATLABFunction2_ICARO3_HAL_v1 *localB, rtDW_MATLABFunction2_ICARO3_HAL_v1 *
  localDW)
{
  if (!localDW->k_not_empty) {
    localDW->k = 0.0;
    localDW->k_not_empty = true;
    localDW->old = rtu_u;
  }

  if (rtu_u - localDW->old > 3.1415926535897931) {
    localDW->k--;
  } else {
    if (rtu_u - localDW->old < -3.1415926535897931) {
      localDW->k++;
    }
  }

  localB->y = localDW->k * 2.0 * 3.1415926535897931 + rtu_u;
  localDW->old = rtu_u;
}

/*
 * Output and update for atomic system:
 *    '<S108>/MATLAB Function6'
 *    '<S109>/MATLAB Function6'
 *    '<S169>/MATLAB Function6'
 *    '<S190>/MATLAB Function6'
 *    '<S191>/MATLAB Function6'
 *    '<S220>/MATLAB Function6'
 *    '<S221>/MATLAB Function6'
 */
void ICARO3_HAL_v1_MATLABFunction6(real_T rtu_latr, real_T rtu_lonr, real_T
  rtu_lat, real_T rtu_lon, rtB_MATLABFunction6_ICARO3_HAL_v1 *localB)
{
  real_T R_normal;

  /*  latr -> reference system origin latitude */
  /*  lonr -> reference system origin longitude */
  /*  hr -> reference system origin altitude */
  /*  lat -> object latitude */
  /*  lon -> object longitude */
  /*  h -> object altitude */
  /*  cog -> course over groung */
  /*  sog -> speed over ground */
  /*  eccentricity squared */
  /*  semi-major axis */
  /* Flamsteed or natural projection: LL to NED */
  /*  compute R_normal */
  /* PolarRad = sqrt((1-e2)*a*a); */
  /* planar_N = a*a/sqrt(a*a*cos(latr)*cos(latr)+PolarRad*PolarRad*sin(latr)*sin(latr)); */
  R_normal = sin(rtu_latr);
  R_normal = 6.378137E+6 / sqrt(1.0 - R_normal * R_normal * 0.00669438);
  localB->y = R_normal * cos(rtu_latr) * (rtu_lon - rtu_lonr);
  localB->x = (rtu_lat - rtu_latr) * R_normal;

  /*  NED velocities (x-y) */
}

/*
 * Output and update for enable system:
 *    '<S183>/h latch'
 *    '<S183>/yaw latch'
 *    '<S186>/h latch'
 *    '<S186>/yaw latch'
 *    '<S219>/h latch'
 *    '<S219>/pitch latch'
 *    '<S219>/roll latch'
 *    '<S219>/yaw latch'
 */
void ICARO3_HAL_v1_hlatch(boolean_T rtu_Enable, real_T rtu_In1,
  rtB_hlatch_ICARO3_HAL_v1 *localB)
{
  if (rtu_Enable) {
    localB->In1 = rtu_In1;
  }
}

/*
 * Output and update for enable system:
 *    '<S183>/lat lon latch'
 *    '<S186>/lat lon latch'
 *    '<S219>/lat lon latch'
 */
void ICARO3_HAL_v1_latlonlatch(boolean_T rtu_Enable, const real_T rtu_In1[2],
  rtB_latlonlatch_ICARO3_HAL_v1 *localB)
{
  if (rtu_Enable) {
    localB->In1[0] = rtu_In1[0];
    localB->In1[1] = rtu_In1[1];
  }
}

/*
 * Start for enable system:
 *    '<S267>/clock latch'
 *    '<S278>/clock latch'
 */
void ICARO3_HAL_v1_clocklatch_Start(rtB_clocklatch_ICARO3_HAL_v1 *localB,
  rtP_clocklatch_ICARO3_HAL_v1 *localP)
{
  localB->In = localP->Out_Y0;
}

/*
 * Output and update for enable system:
 *    '<S267>/clock latch'
 *    '<S278>/clock latch'
 */
void ICARO3_HAL_v1_clocklatch(real_T rtu_Enable, real_T rtu_In,
  rtB_clocklatch_ICARO3_HAL_v1 *localB)
{
  if (rtu_Enable > 0.0) {
    localB->In = rtu_In;
  }
}

/*
 * Output and update for atomic system:
 *    '<S350>/ChangeAsset2'
 *    '<S350>/ChangeAsset3'
 */
void ICARO3_HAL_v1_ChangeAsset2(const real32_T rtu_u[3],
  rtB_ChangeAsset2_ICARO3_HAL_v1 *localB)
{
  static const real32_T b[9] = { -0.707106769F, -0.707106769F, 0.0F,
    0.707106769F, -0.707106769F, 0.0F, 0.0F, 0.0F, 1.0F };

  int32_T i;

  /* matrice rotazione */
  for (i = 0; i < 3; i++) {
    localB->y[i] = 0.0F;
    localB->y[i] += b[i] * rtu_u[0];
    localB->y[i] += b[i + 3] * rtu_u[1];
    localB->y[i] += b[i + 6] * rtu_u[2];
  }
}

/*
 * Output and update for atomic system:
 *    '<S377>/MATLAB Function compute gyroxyz1'
 *    '<S377>/MATLAB Function compute gyroxyz2'
 *    '<S377>/MATLAB Function compute gyroxyz3'
 *    '<S377>/MATLAB Function compute gyroxyz5'
 *    '<S379>/MATLAB Function compute gyroxyz1'
 *    '<S379>/MATLAB Function compute gyroxyz2'
 *    '<S379>/MATLAB Function compute gyroxyz3'
 *    '<S379>/MATLAB Function compute gyroxyz5'
 */
void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1(const uint16_T rtu_u[2],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1 *localB)
{
  localB->y = (uint16_T)((uint16_T)(rtu_u[1] << 8) | rtu_u[0]);
}

/*
 * Output and update for atomic system:
 *    '<S378>/MATLAB Function compute gyroxyz1'
 *    '<S378>/MATLAB Function compute gyroxyz5'
 */
void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_j(const uint32_T rtu_u[4],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_g *localB)
{
  uint32_T q0;
  uint32_T qY;
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
 *    '<S397>/MATLAB Function compute gyroxyz1'
 *    '<S397>/MATLAB Function compute gyroxyz2'
 *    '<S397>/MATLAB Function compute gyroxyz3'
 *    '<S397>/MATLAB Function compute gyroxyz5'
 *    '<S403>/MATLAB Function compute gyroxyz1'
 *    '<S403>/MATLAB Function compute gyroxyz2'
 *    '<S403>/MATLAB Function compute gyroxyz3'
 *    '<S403>/MATLAB Function compute gyroxyz5'
 *    '<S404>/MATLAB Function compute gyroxyz1'
 *    '<S404>/MATLAB Function compute gyroxyz2'
 *    ...
 */
void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(uint16_T rtu_u,
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a *localB)
{
  localB->y[0] = 0U;
  localB->y[1] = 0U;
  localB->y[0] = (uint8_T)(rtu_u & 255);
  localB->y[1] = (uint8_T)((uint32_T)rtu_u >> 8);
}

/*
 * Output and update for atomic system:
 *    '<S397>/MATLAB Function compute gyroxyz4'
 *    '<S403>/MATLAB Function compute gyroxyz4'
 *    '<S404>/MATLAB Function compute gyroxyz4'
 */
void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz4(const uint8_T rtu_u[2], const
  uint8_T rtu_u_e[2], const uint8_T rtu_u_n[2], const uint8_T rtu_u_b[2],
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1 *localB)
{
  int32_T i;
  for (i = 0; i < 8; i++) {
    localB->y[i] = 0U;
  }

  localB->y[0] = rtu_u[0];
  localB->y[1] = rtu_u[1];
  localB->y[2] = rtu_u_e[0];
  localB->y[3] = rtu_u_e[1];
  localB->y[4] = rtu_u_n[0];
  localB->y[5] = rtu_u_n[1];
  localB->y[6] = rtu_u_b[0];
  localB->y[7] = rtu_u_b[1];
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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
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
void ICARO3_HAL_v1_step0(void)         /* Sample time: [0.0025s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DigitalClock;
  real_T rtb_Step1;
  real_T rtb_DataTypeConversion7[3];
  real_T rtb_DataTypeConversion9[3];
  real_T rtb_Step1_d;
  real_T rtb_DataTypeConversion2[3];
  real_T rtb_usecalibrateddata_c[3];
  real_T rtb_DigitalClock_f;
  real_T rtb_DigitalClock_k;
  real_T rtb_Step1_k;
  real_T rtb_DataTypeConversion6[3];
  real_T rtb_DataTypeConversion5[3];
  real_T rtb_Gain3;
  real_T rtb_Gain4;
  real_T rtb_Gain5;
  real_T rtb_Gain6;
  real_T rtb_Gain3_g;
  real_T rtb_Gain4_c;
  real_T rtb_Gain5_l;
  real_T rtb_Gain6_p;
  real_T rtb_Sum_n;
  real_T rtb_Gain3_e;
  real_T rtb_Gain4_k;
  real_T rtb_Gain5_o;
  real_T rtb_Gain6_ov;
  real_T rtb_Gain3_k;
  real_T rtb_Gain4_p;
  real_T rtb_Gain5_d;
  real_T rtb_Gain6_mx;
  real_T rtb_Switch3_g;
  real_T rtb_Saturation_gf;
  real_T rtb_h_data[2];
  real_T rtb_rpy[3];
  real_T rtb_convert11to2020deginradians2;
  real_T rtb_convert11to2020deginradians1;
  real_T rtb_Gain_m;
  real_T rtb_waypPitch;
  real_T rtb_lat_lon_h_yaw_ref[4];
  real_T rtb_Sum7;
  real_T rtb_Sum6;
  real_T rtb_Gain3_ef;
  real_T rtb_Gain4_i;
  real_T rtb_Gain5_g;
  real_T rtb_Gain6_d;
  real_T rtb_Gain3_ce;
  real_T rtb_Gain4_f;
  real_T rtb_Gain5_f;
  real_T rtb_Gain6_b;
  real_T rtb_Sum2_p;
  real_T rtb_selectOLDvsNEWcontroller;
  real_T rtb_Sum2_l;
  real_T rtb_ManualSwitch_h;
  real_T rtb_Divide1;
  real_T rtb_Divide_g;
  real_T rtb_DiscreteTimeIntegrator_f;
  real_T rtb_Divide1_j;
  real_T rtb_Divide_b;
  real_T rtb_Switch_ck;
  real_T rtb_Sum1_mw;
  real_T rtb_Sum_ot;
  real_T rtb_DiscreteTimeIntegrator_fg;
  real_T rtb_Sum1_my;
  real_T rtb_Internal_l;
  real_T rtb_DigitalClock_c;
  real_T rtb_Sum_h1;
  real_T rtb_Internal_j;
  real_T rtb_Sum_fw;
  real_T rtb_Internal_p;
  real32_T rtb_DataTypeConversionmx8;
  real32_T rtb_DataTypeConversionmx8_m;
  real32_T rtb_DataTypeConversionmx1[3];
  real32_T rtb_DataTypeConversionmx4[3];
  real32_T rtb_DataTypeConversionmx2[3];
  real32_T rtb_DataTypeConversionmx8_g;
  real32_T rtb_DataTypeConversionmx1_e[3];
  real32_T rtb_DataTypeConversionmx4_c[3];
  real32_T rtb_DataTypeConversionmx2_k[3];
  real32_T rtb_DataTypeConversionmx1_j[3];
  real32_T rtb_DataTypeConversionmx4_m[3];
  real32_T rtb_DataTypeConversionmx2_e[3];
  real32_T rtb_a_e[3];
  real32_T rtb_g[3];
  boolean_T rtb_LogicalOperator_p;
  boolean_T rtb_LogicalOperator_o;
  boolean_T rtb_LogicalOperator3_k;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator_c;
  boolean_T rtb_LogicalOperator_pm;
  boolean_T rtb_UnitDelay1_nc;
  boolean_T rtb_UnitDelay1_l;
  boolean_T rtb_RelationalOperator_d;
  uint16_T b_u;
  uint16_T c_u;
  uint16_T d_u;
  uint16_T f_u;
  uint16_T g_u;
  uint16_T h_u;
  static const int8_T b[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_0[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_1[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  uint8_T ahrs_sel_tmp;
  uint8_T command_sel_tmp;
  static const int8_T b_3[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T c[9] = { -1, 0, 0, 0, 1, 0, 0, 0, 1 };

  int32_T wayp_sync_cs;
  int32_T send_sync;
  int32_T ack;
  int32_T newwp;
  real_T rtb_Switch2_oq;
  uint8_T rtb_DataTypeConversiononi2cmag3[14];
  uint8_T rtb_RateTransition14_h[8];
  uint8_T rtb_RateTransition15_m[8];
  uint16_T rtb_DataTypeConversiononi2cmag2[6];
  real_T rtb_DataTypeConversion3[3];
  real_T rtb_Gain[5];
  uint8_T rtb_RateTransition[8];
  uint32_T rtb_Switch3[12];
  boolean_T rtb_Compare_p3;
  boolean_T rtb_LogicalOperator_k;
  boolean_T rtb_UnitDelay_j1;
  boolean_T rtb_UnitDelay1;
  boolean_T rtb_UnitDelay2;
  boolean_T rtb_UnitDelay3;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator1_k;
  boolean_T rtb_UnitDelay_j3;
  boolean_T rtb_UnitDelay1_k;
  boolean_T rtb_UnitDelay2_g;
  boolean_T rtb_UnitDelay3_ix;
  boolean_T rtb_LogicalOperator_n;
  boolean_T rtb_Compare_pc;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_UnitDelay_p5;
  boolean_T rtb_UnitDelay1_f;
  boolean_T rtb_UnitDelay2_h;
  boolean_T rtb_UnitDelay3_n;
  real_T rtb_DataTypeConversion2_a;
  uint8_T rtb_Compare_om;
  boolean_T rtb_LogicalOperator4;
  boolean_T rtb_UnitDelay_g3;
  boolean_T rtb_UnitDelay1_pu;
  boolean_T rtb_UnitDelay2_or;
  boolean_T rtb_UnitDelay3_p;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_UnitDelay_p;
  boolean_T rtb_UnitDelay1_b;
  boolean_T rtb_UnitDelay2_b;
  boolean_T rtb_UnitDelay3_e;
  boolean_T rtb_LogicalOperator6;
  boolean_T rtb_UnitDelay_i1;
  boolean_T rtb_UnitDelay1_o;
  boolean_T rtb_UnitDelay2_a;
  boolean_T rtb_UnitDelay3_l;
  real_T rtb_RateTransition2;
  int32_T rtb_controller_sel_out;
  real_T rtb_enable_motors_out;
  real_T rtb_Gain1[3];
  boolean_T rtb_Compare_l;
  boolean_T rtb_Compare_gn;
  real_T rtb_Sum_hd;
  real_T rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2;
  real_T rtb_DataTypeConversion_j;
  real_T rtb_Divide_e;
  real_T rtb_ManualSwitch7[7];
  int32_T rtb_mode_out;
  real_T rtb_ManualSwitch_b[6];
  real_T rtb_Sum;
  boolean_T rtb_LogicalOperator2_p;
  boolean_T rtb_LogicalOperator2_ni;
  uint8_T rtb_DataTypeConversion_f[22];
  uint32_T rtb_RateTransition18[2];
  real_T rtb_Switch2;
  real_T rtb_Switch2_a;
  real_T rtb_Switch2_ag;
  real_T rtb_Switch2_og;
  real_T rtb_Switch2_g;
  real_T rtb_Switch2_d;
  real_T rtb_h_calib[3];
  uint32_T rtb_Sum12;
  real_T rtb_ahrs_sel_out;
  int32_T rtb_command_sel_out;
  real_T rtb_inside_RTH_circle;
  real_T rtb_wayp_data_cs[6];
  real_T rtb_data_send_to_bs[6];
  real32_T rtb_params[11];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  real_T tmp[5];
  int32_T rtb_Switch2_a_0;
  real_T tmp_0[7];
  real_T tmp_1[4];
  real_T rtb_DataTypeConversion3_j;
  real_T rtb_ManualSwitch3_g;
  real_T rtb_refs_idx_0;
  real_T rtb_refs_idx_1;
  real_T rtb_refs_idx_2;
  real_T rtb_refs_idx_3;
  real32_T b_u_idx_0;
  real32_T b_u_idx_1;
  real32_T b_u_idx_2;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_i_idx_0;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_3;
  boolean_T rtb_Logic_d_idx_0;
  real_T rtb_Gain2_idx_0;
  real_T rtb_DataTypeConversionmx10_idx_0;
  real_T rtb_DataTypeConversionmx10_idx_1;
  real_T rtb_DataTypeConversionmx10_idx_2;
  real_T rtb_ManualSwitch3_a_idx_0;
  real_T rtb_ManualSwitch3_a_idx_1;
  real_T rtb_ManualSwitch3_a_idx_2;
  real_T rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1;
  boolean_T rtb_LowerRelop1_idx_2;
  uint8_T tmp_2;

  {                                    /* Sample time: [0.0025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function Block: <Root>/STM32_Config */
  rtb_DigitalClock = ((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025);
  if (!(ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0 = rtb_DigitalClock;
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step1_Time) {
    rtb_Step1 = ICARO3_HAL_v1_P.Step1_Y0;
  } else {
    rtb_Step1 = ICARO3_HAL_v1_P.Step1_YFinal;
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step_Time) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Step_Y0;
  } else {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Step_YFinal;
  }

  rtb_DataTypeConversionmx8 = (real32_T)(rtb_ManualSwitch3_a_idx_2 - rtb_Step1);
  wrap_I2C1_sensors_loop_output_fcn(&ICARO3_HAL_v1_P.bmp085accuracylevel_Value,
    &ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[0], &ICARO3_HAL_v1_B.I2C1SensorsLoop_o2);
  for (i = 0; i < 14; i++) {
    rtb_DataTypeConversiononi2cmag3[i] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[i +
      54];
  }

  if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch4_Threshold) {
    ICARO3_HAL_v1_B.Switch4[0] = ICARO3_HAL_v1_P.enable0_Value;
    ICARO3_HAL_v1_B.Switch4[1] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[27];
    ICARO3_HAL_v1_B.Switch4[2] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[28];
    ICARO3_HAL_v1_B.Switch4[3] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[29];
    ICARO3_HAL_v1_B.Switch4[4] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[30];
    ICARO3_HAL_v1_B.Switch4[5] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[69];
  } else {
    ICARO3_HAL_v1_B.Switch4[0] = ICARO3_HAL_v1_P.enableall_Value[0];
    ICARO3_HAL_v1_B.Switch4[1] = ICARO3_HAL_v1_P.enableall_Value[1];
    ICARO3_HAL_v1_B.Switch4[2] = ICARO3_HAL_v1_P.enableall_Value[2];
    ICARO3_HAL_v1_B.Switch4[3] = ICARO3_HAL_v1_P.enableall_Value[3];
    ICARO3_HAL_v1_B.Switch4[4] = ICARO3_HAL_v1_P.enableall_Value[4];
    ICARO3_HAL_v1_B.Switch4[5] = ICARO3_HAL_v1_P.enableall_Value[5];
  }

  if (ICARO3_HAL_v1_B.Switch4[5] == 0) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_DataTypeConversiononi2cmag3[i_0] = 0U;
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
  b_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[0] << 8) +
                   rtb_DataTypeConversiononi2cmag3[1]);

  /* 4g */
  c_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[2] << 8) +
                   rtb_DataTypeConversiononi2cmag3[3]);
  d_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[4] << 8) +
                   rtb_DataTypeConversiononi2cmag3[5]);

  /* unknown */
  f_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[8] << 8) +
                   rtb_DataTypeConversiononi2cmag3[9]);

  /*  rad/sec %131 = 250 deg/sec */
  g_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[10] << 8) +
                   rtb_DataTypeConversiononi2cmag3[11]);
  h_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag3[12] << 8) +
                   rtb_DataTypeConversiononi2cmag3[13]);

  /*  Convert a from mpu9150 axes to ICARO2 axes */
  /*    ipotesi di montaggio 1: test preliminari */
  /*        pettine allineato con asse X e chip sul lato di sotto  */
  /* OLD CONFIGURATION */
  /* a = [0 -1 0; 1 0 0; 0 0 1]*a_mpu9150; */
  /* g = [0 -1 0; 1 0 0; 0 0 1]*g_mpu9150; */
  /* NEW CONFIGURATION (24/04/2015) */
  if (b_u > 32767) {
    i = b_u - 65536;
  } else {
    i = b_u;
  }

  b_u_idx_0 = (real32_T)i / 8192.0F * 9.81F;
  if (c_u > 32767) {
    i = c_u - 65536;
  } else {
    i = c_u;
  }

  b_u_idx_1 = (real32_T)i / 8192.0F * 9.81F;
  if (d_u > 32767) {
    i = d_u - 65536;
  } else {
    i = d_u;
  }

  b_u_idx_2 = (real32_T)i / 8192.0F * 9.81F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_a_e[i_0] = 0.0F;
    rtb_a_e[i_0] += (real32_T)b[i_0] * b_u_idx_0;
    rtb_a_e[i_0] += (real32_T)b[i_0 + 3] * b_u_idx_1;
    rtb_a_e[i_0] += (real32_T)b[i_0 + 6] * b_u_idx_2;
  }

  if (f_u > 32767) {
    i = f_u - 65536;
  } else {
    i = f_u;
  }

  b_u_idx_0 = (real32_T)i / 131.0F * 3.14159274F / 180.0F;
  if (g_u > 32767) {
    i = g_u - 65536;
  } else {
    i = g_u;
  }

  b_u_idx_1 = (real32_T)i / 131.0F * 3.14159274F / 180.0F;
  if (h_u > 32767) {
    i = h_u - 65536;
  } else {
    i = h_u;
  }

  b_u_idx_2 = (real32_T)i / 131.0F * 3.14159274F / 180.0F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_g[i_0] = 0.0F;
    rtb_g[i_0] += (real32_T)b[i_0] * b_u_idx_0;
    rtb_g[i_0] += (real32_T)b[i_0 + 3] * b_u_idx_1;
    rtb_g[i_0] += (real32_T)b[i_0 + 6] * b_u_idx_2;
  }

  ICARO3_HAL_v1_ChangeAsset2(rtb_a_e, &ICARO3_HAL_v1_B.sf_ChangeAsset2);
  rtb_DataTypeConversion7[0] = ICARO3_HAL_v1_B.sf_ChangeAsset2.y[0];
  rtb_DataTypeConversion7[1] = ICARO3_HAL_v1_B.sf_ChangeAsset2.y[1];
  rtb_DataTypeConversion7[2] = ICARO3_HAL_v1_B.sf_ChangeAsset2.y[2];
  ICARO3_HAL_v1_Subsystem(rtb_DataTypeConversionmx8, rtb_DataTypeConversion7[0],
    &ICARO3_HAL_v1_B.Subsystem, &ICARO3_HAL_v1_DWork.Subsystem,
    (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_j) {
    rtb_Switch2 = ICARO3_HAL_v1_P.Constant1_Value_kf;
  } else {
    rtb_Switch2 = rtb_DataTypeConversion7[0] -
      ICARO3_HAL_v1_B.Subsystem.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8, rtb_DataTypeConversion7[1],
    &ICARO3_HAL_v1_B.Subsystem_h, &ICARO3_HAL_v1_DWork.Subsystem_h,
    (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_h);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_l) {
    rtb_Switch2_a = ICARO3_HAL_v1_P.Constant1_Value_ba;
  } else {
    rtb_Switch2_a = rtb_DataTypeConversion7[1] -
      ICARO3_HAL_v1_B.Subsystem_h.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8, rtb_DataTypeConversion7[2],
    &ICARO3_HAL_v1_B.Subsystem_e, &ICARO3_HAL_v1_DWork.Subsystem_e,
    (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_i) {
    rtb_Switch2_ag = ICARO3_HAL_v1_P.Constant1_Value_jd;
  } else {
    rtb_Switch2_ag = (rtb_DataTypeConversion7[2] -
                      ICARO3_HAL_v1_B.Subsystem_e.Product1) -
      ICARO3_HAL_v1_P.Constant2_Value_gx;
  }

  ICARO3_HAL_v1_ChangeAsset2(rtb_g, &ICARO3_HAL_v1_B.sf_ChangeAsset3);
  rtb_DataTypeConversion9[0] = ICARO3_HAL_v1_B.sf_ChangeAsset3.y[0];
  rtb_DataTypeConversion9[1] = ICARO3_HAL_v1_B.sf_ChangeAsset3.y[1];
  rtb_DataTypeConversion9[2] = ICARO3_HAL_v1_B.sf_ChangeAsset3.y[2];
  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8, rtb_DataTypeConversion9[0],
    &ICARO3_HAL_v1_B.Subsystem_m, &ICARO3_HAL_v1_DWork.Subsystem_m,
    (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_m);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_k) {
    rtb_Switch2_og = ICARO3_HAL_v1_P.Constant1_Value_n;
  } else {
    rtb_Switch2_og = rtb_DataTypeConversion9[0] -
      ICARO3_HAL_v1_B.Subsystem_m.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8, rtb_DataTypeConversion9[1],
    &ICARO3_HAL_v1_B.Subsystem_e5, &ICARO3_HAL_v1_DWork.Subsystem_e5,
    (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e5);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_i4) {
    rtb_Switch2_g = ICARO3_HAL_v1_P.Constant1_Value_o;
  } else {
    rtb_Switch2_g = rtb_DataTypeConversion9[1] -
      ICARO3_HAL_v1_B.Subsystem_e5.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8, rtb_DataTypeConversion9[2],
    &ICARO3_HAL_v1_B.Subsystem_i, &ICARO3_HAL_v1_DWork.Subsystem_i,
    (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_i);
  if (rtb_DataTypeConversionmx8 >= ICARO3_HAL_v1_P.Switch2_Threshold_h) {
    rtb_Switch2_d = ICARO3_HAL_v1_P.Constant1_Value_pa;
  } else {
    rtb_Switch2_d = rtb_DataTypeConversion9[2] -
      ICARO3_HAL_v1_B.Subsystem_i.Product1;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[0] = rtb_Switch2;
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[1] = rtb_Switch2_a;
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[2] = rtb_Switch2_ag;
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[3] = rtb_Switch2_og;
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[4] = rtb_Switch2_g;
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[5] = rtb_Switch2_d;
  }

  i_0 = ICARO3_HAL_v1_DWork.RateTransition14_ActiveBufIdx << 3;
  i_1 = ICARO3_HAL_v1_DWork.RateTransition15_ActiveBufIdx << 3;
  for (i = 0; i < 8; i++) {
    rtb_RateTransition14_h[i] = ICARO3_HAL_v1_DWork.RateTransition14_Buffer[i +
      i_0];
    rtb_RateTransition15_m[i] = ICARO3_HAL_v1_DWork.RateTransition15_Buffer[i +
      i_1];
  }

  if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch2_Threshold) {
    rtb_DataTypeConversiononi2cmag2[0] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[17];
    rtb_DataTypeConversiononi2cmag2[1] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[18];
    rtb_DataTypeConversiononi2cmag2[2] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[19];
    rtb_DataTypeConversiononi2cmag2[3] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[20];
    rtb_DataTypeConversiononi2cmag2[4] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[21];
    rtb_DataTypeConversiononi2cmag2[5] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[22];
  } else {
    rtb_DataTypeConversiononi2cmag2[0] = rtb_RateTransition14_h[4];
    rtb_DataTypeConversiononi2cmag2[1] = rtb_RateTransition14_h[5];
    rtb_DataTypeConversiononi2cmag2[2] = rtb_RateTransition14_h[6];
    rtb_DataTypeConversiononi2cmag2[3] = rtb_RateTransition14_h[7];
    rtb_DataTypeConversiononi2cmag2[4] = rtb_RateTransition15_m[0];
    rtb_DataTypeConversiononi2cmag2[5] = rtb_RateTransition15_m[1];
  }

  if (ICARO3_HAL_v1_B.Switch4[3] == 0) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DataTypeConversiononi2cmag2[i_0] = 0U;
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
  b_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[0] << 8) +
                   rtb_DataTypeConversiononi2cmag2[1]);

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  c_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[2] << 8) +
                   rtb_DataTypeConversiononi2cmag2[3]);

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  d_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[4] << 8) +
                   rtb_DataTypeConversiononi2cmag2[5]);

  /*  if (my > 32767) */
  /*      my = 65535 - my; */
  /*  end */
  /*   */
  /*  if (mz > 32767) */
  /*      mz = 65535 - mz; */
  /*  end */
  /*  Convert m from HMC5883 axes to dji axis */
  /* R_x(180) */
  if (b_u > 32767) {
    i = b_u - 65536;
  } else {
    i = b_u;
  }

  b_u_idx_0 = (real32_T)i / 1090.0F;
  if (d_u > 32767) {
    i = d_u - 65536;
  } else {
    i = d_u;
  }

  b_u_idx_1 = (real32_T)i / 1090.0F;
  if (c_u > 32767) {
    i = c_u - 65536;
  } else {
    i = c_u;
  }

  b_u_idx_2 = (real32_T)i / 1090.0F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_DataTypeConversion3[i_0] = ((real32_T)b_0[i_0 + 3] * b_u_idx_1 +
      (real32_T)b_0[i_0] * b_u_idx_0) + (real32_T)b_0[i_0 + 6] * b_u_idx_2;
  }

  rtb_h_calib[1] = ((rtb_DataTypeConversion3[1] - ICARO3_HAL_v1_P.CAL_PARAM[1]) /
                    ICARO3_HAL_v1_P.CAL_PARAM[4] - (rtb_DataTypeConversion3[0] -
    ICARO3_HAL_v1_P.CAL_PARAM[0]) / ICARO3_HAL_v1_P.CAL_PARAM[3] * sin
                    (ICARO3_HAL_v1_P.CAL_PARAM[6])) / cos
    (ICARO3_HAL_v1_P.CAL_PARAM[6]);
  rtb_h_calib[2] = (((rtb_DataTypeConversion3[2] - ICARO3_HAL_v1_P.CAL_PARAM[2])
                     / ICARO3_HAL_v1_P.CAL_PARAM[5] - (rtb_DataTypeConversion3[0]
    - ICARO3_HAL_v1_P.CAL_PARAM[0]) / ICARO3_HAL_v1_P.CAL_PARAM[3] * sin
                     (ICARO3_HAL_v1_P.CAL_PARAM[7]) * cos
                     (ICARO3_HAL_v1_P.CAL_PARAM[8])) -
                    ((rtb_DataTypeConversion3[1] - ICARO3_HAL_v1_P.CAL_PARAM[1])
                     / ICARO3_HAL_v1_P.CAL_PARAM[4] - (rtb_DataTypeConversion3[0]
    - ICARO3_HAL_v1_P.CAL_PARAM[0]) / ICARO3_HAL_v1_P.CAL_PARAM[3]) * (sin
    (ICARO3_HAL_v1_P.CAL_PARAM[8]) / cos(ICARO3_HAL_v1_P.CAL_PARAM[6])) * sin
                    (ICARO3_HAL_v1_P.CAL_PARAM[6])) / (cos
    (ICARO3_HAL_v1_P.CAL_PARAM[7]) * cos(ICARO3_HAL_v1_P.CAL_PARAM[8]));
  rtb_Compare_pc = (ICARO3_HAL_v1_P.usecalibrateddata_CurrentSetting == 1);
  rtb_DataTypeConversion3_j = rtb_DataTypeConversion3[0];
  if (!rtb_Compare_pc) {
    rtb_DataTypeConversion3_j = (rtb_DataTypeConversion3[0] -
      ICARO3_HAL_v1_P.CAL_PARAM[0]) / ICARO3_HAL_v1_P.CAL_PARAM[3];
  }

  rtb_DataTypeConversion3[0] = rtb_DataTypeConversion3_j;
  rtb_DataTypeConversion3_j = rtb_DataTypeConversion3[1];
  if (!rtb_Compare_pc) {
    rtb_DataTypeConversion3_j = rtb_h_calib[1];
  }

  rtb_DataTypeConversion3[1] = rtb_DataTypeConversion3_j;
  rtb_DataTypeConversion3_j = rtb_DataTypeConversion3[2];
  if (!rtb_Compare_pc) {
    rtb_DataTypeConversion3_j = rtb_h_calib[2];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[0] = rtb_DataTypeConversion9[0];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[1] = rtb_DataTypeConversion9[1];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[2] = rtb_DataTypeConversion9[2];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[3] = rtb_DataTypeConversion7[0];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[4] = rtb_DataTypeConversion7[1];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[5] = rtb_DataTypeConversion7[2];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[6] = rtb_DataTypeConversion3[0];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[7] = rtb_DataTypeConversion3[1];
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[8] = rtb_DataTypeConversion3_j;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition3_semaphoreTaken != 0)) {
    for (i = 0; i < 9; i++) {
      ICARO3_HAL_v1_DWork.RateTransition3_Buffer0_n[i] =
        ICARO3_HAL_v1_P.enableall3_Value[i];
    }
  }

  wrap_rcv_from_bs_output_fcn(&ICARO3_HAL_v1_B.SFunction_o1[0],
    &ICARO3_HAL_v1_B.SFunction_o2[0], &ICARO3_HAL_v1_B.SFunction_o3[0],
    &ICARO3_HAL_v1_B.SFunction_o4);
  rtb_Compare_pc = (ICARO3_HAL_v1_P.ManualSwitch4_CurrentSetting == 1);
  for (i_0 = 0; i_0 < 5; i_0++) {
    if (rtb_Compare_pc) {
      tmp[i_0] = ICARO3_HAL_v1_B.SFunction_o1[4 + i_0];
    } else {
      tmp[i_0] = ICARO3_HAL_v1_P.Constant3_Value_b[i_0];
    }
  }

  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_Gain[i_0] = 0.0;
    for (i_1 = 0; i_1 < 5; i_1++) {
      rtb_Gain[i_0] += ICARO3_HAL_v1_P.SF_RPY_PID_GAINS[5 * i_1 + i_0] * tmp[i_1];
    }
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken != 0)) {
    for (i = 0; i < 5; i++) {
      ICARO3_HAL_v1_DWork.RateTransition22_Buffer0[i] = rtb_Gain[i];
    }
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step1_Time_n) {
    rtb_Step1_d = ICARO3_HAL_v1_P.Step1_Y0_g;
  } else {
    rtb_Step1_d = ICARO3_HAL_v1_P.Step1_YFinal_m;
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step_Time_c) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Step_Y0_a;
  } else {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Step_YFinal_b;
  }

  rtb_DataTypeConversionmx8_m = (real32_T)(rtb_ManualSwitch3_a_idx_2 -
    rtb_Step1_d);
  i_0 = ICARO3_HAL_v1_DWork.RateTransition_ActiveBufIdx << 3;
  for (i_1 = 0; i_1 < 8; i_1++) {
    rtb_RateTransition[i_1] = ICARO3_HAL_v1_DWork.RateTransition_Buffer[i_1 +
      i_0];
  }

  if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch1_Threshold) {
    rtb_DataTypeConversiononi2cmag2[0] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[11];
    rtb_DataTypeConversiononi2cmag2[1] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[12];
    rtb_DataTypeConversiononi2cmag2[2] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[13];
    rtb_DataTypeConversiononi2cmag2[3] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[14];
    rtb_DataTypeConversiononi2cmag2[4] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[15];
    rtb_DataTypeConversiononi2cmag2[5] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[16];
  } else {
    rtb_DataTypeConversiononi2cmag2[0] = rtb_RateTransition[6];
    rtb_DataTypeConversiononi2cmag2[1] = rtb_RateTransition[7];
    rtb_DataTypeConversiononi2cmag2[2] = rtb_RateTransition14_h[0];
    rtb_DataTypeConversiononi2cmag2[3] = rtb_RateTransition14_h[1];
    rtb_DataTypeConversiononi2cmag2[4] = rtb_RateTransition14_h[2];
    rtb_DataTypeConversiononi2cmag2[5] = rtb_RateTransition14_h[3];
  }

  if (ICARO3_HAL_v1_B.Switch4[2] == 0) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DataTypeConversiononi2cmag2[i_0] = 0U;
    }
  }

  b_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[1] << 8) +
                   rtb_DataTypeConversiononi2cmag2[0]);
  c_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[3] << 8) +
                   rtb_DataTypeConversiononi2cmag2[2]);
  d_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[5] << 8) +
                   rtb_DataTypeConversiononi2cmag2[4]);

  /*  Convert a from adxl axes to ICARO2 axes */
  if (b_u > 32767) {
    i = b_u - 65536;
  } else {
    i = b_u;
  }

  b_u_idx_0 = (real32_T)i / 256.0F * 9.81F;
  if (c_u > 32767) {
    i = c_u - 65536;
  } else {
    i = c_u;
  }

  b_u_idx_1 = (real32_T)i / 256.0F * 9.81F;
  if (d_u > 32767) {
    i = d_u - 65536;
  } else {
    i = d_u;
  }

  b_u_idx_2 = (real32_T)i / 256.0F * 9.81F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_DataTypeConversion2[i_0] = ((real32_T)b_1[i_0 + 3] * b_u_idx_1 +
      (real32_T)b_1[i_0] * b_u_idx_0) + (real32_T)b_1[i_0 + 6] * b_u_idx_2;
  }

  ICARO3_HAL_v1_Subsystem(rtb_DataTypeConversionmx8_m, rtb_DataTypeConversion2[0],
    &ICARO3_HAL_v1_B.Subsystem_c, &ICARO3_HAL_v1_DWork.Subsystem_c,
    (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_c);
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_a) {
    rtb_Switch2_oq = ICARO3_HAL_v1_P.Constant1_Value_h1;
  } else {
    rtb_Switch2_oq = rtb_DataTypeConversion2[0] -
      ICARO3_HAL_v1_B.Subsystem_c.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_m,
    rtb_DataTypeConversion2[1], &ICARO3_HAL_v1_B.Subsystem_p,
    &ICARO3_HAL_v1_DWork.Subsystem_p, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_p);
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_n) {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.Constant1_Value_nw;
  } else {
    rtb_DigitalClock_c = rtb_DataTypeConversion2[1] -
      ICARO3_HAL_v1_B.Subsystem_p.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_m,
    rtb_DataTypeConversion2[2], &ICARO3_HAL_v1_B.Subsystem_n,
    &ICARO3_HAL_v1_DWork.Subsystem_n, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_n);
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_m) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant1_Value_m;
  } else {
    rtb_DataTypeConversion2_a = (rtb_DataTypeConversion2[2] -
      ICARO3_HAL_v1_B.Subsystem_n.Product1) - ICARO3_HAL_v1_P.Constant2_Value_a0;
  }

  rtb_DataTypeConversionmx1[0] = (real32_T)rtb_Switch2_oq;
  rtb_DataTypeConversionmx1[1] = (real32_T)rtb_DigitalClock_c;
  rtb_DataTypeConversionmx1[2] = (real32_T)rtb_DataTypeConversion2_a;
  rtb_DataTypeConversionmx4[0] = (real32_T)rtb_DataTypeConversion3[0];
  rtb_DataTypeConversionmx4[1] = (real32_T)rtb_DataTypeConversion3[1];
  rtb_DataTypeConversionmx4[2] = (real32_T)rtb_DataTypeConversion3_j;
  for (i = 0; i < 6; i++) {
    if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch_Threshold_i) {
      rtb_DataTypeConversiononi2cmag2[i] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[i
        + 5];
    } else {
      rtb_DataTypeConversiononi2cmag2[i] = rtb_RateTransition[i];
    }
  }

  if (ICARO3_HAL_v1_B.Switch4[1] == 0) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_DataTypeConversiononi2cmag2[i_0] = 0U;
    }
  }

  b_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[0] << 8) +
                   rtb_DataTypeConversiononi2cmag2[1]);

  /* rad/s */
  c_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[2] << 8) +
                   rtb_DataTypeConversiononi2cmag2[3]);
  d_u = (uint16_T)((uint32_T)(rtb_DataTypeConversiononi2cmag2[4] << 8) +
                   rtb_DataTypeConversiononi2cmag2[5]);

  /*  Convert w from itg axes to ICARO2 axes */
  if (b_u > 32767) {
    i = b_u - 65536;
  } else {
    i = b_u;
  }

  b_u_idx_0 = (real32_T)i * 0.061F * 3.14159274F / 180.0F;
  if (c_u > 32767) {
    i = c_u - 65536;
  } else {
    i = c_u;
  }

  b_u_idx_1 = (real32_T)i * 0.061F * 3.14159274F / 180.0F;
  if (d_u > 32767) {
    i = d_u - 65536;
  } else {
    i = d_u;
  }

  b_u_idx_2 = (real32_T)i * 0.061F * 3.14159274F / 180.0F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_h_calib[i_0] = ((real32_T)b_2[i_0 + 3] * b_u_idx_1 + (real32_T)b_2[i_0] *
                        b_u_idx_0) + (real32_T)b_2[i_0 + 6] * b_u_idx_2;
  }

  if (ICARO3_HAL_v1_P.usecalibrateddata_CurrentSetting_d == 1) {
    rtb_usecalibrateddata_c[0] =
      ICARO3_HAL_v1_P.scalefactorcorrectiongoodfortest_calib_2_Gain *
      rtb_h_calib[0];
    rtb_usecalibrateddata_c[1] =
      ICARO3_HAL_v1_P.scalefactorcorrectiongoodfortest_calib_2_Gain *
      rtb_h_calib[1];
    rtb_usecalibrateddata_c[2] =
      ICARO3_HAL_v1_P.scalefactorcorrectiongoodfortest_calib_2_Gain *
      rtb_h_calib[2];
  } else {
    rtb_usecalibrateddata_c[0] = rtb_h_calib[0];
    rtb_usecalibrateddata_c[1] = rtb_h_calib[1];
    rtb_usecalibrateddata_c[2] = rtb_h_calib[2];
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_m,
    rtb_usecalibrateddata_c[0], &ICARO3_HAL_v1_B.Subsystem_e1,
    &ICARO3_HAL_v1_DWork.Subsystem_e1, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_e1);
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_d) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant1_Value_ol;
  } else {
    rtb_DataTypeConversion2_a = rtb_usecalibrateddata_c[0] -
      ICARO3_HAL_v1_B.Subsystem_e1.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_m,
    rtb_usecalibrateddata_c[1], &ICARO3_HAL_v1_B.Subsystem_f,
    &ICARO3_HAL_v1_DWork.Subsystem_f, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_f);
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_d2) {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.Constant1_Value_ot;
  } else {
    rtb_DigitalClock_c = rtb_usecalibrateddata_c[1] -
      ICARO3_HAL_v1_B.Subsystem_f.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_m,
    rtb_usecalibrateddata_c[2], &ICARO3_HAL_v1_B.Subsystem_e4,
    &ICARO3_HAL_v1_DWork.Subsystem_e4, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_e4);
  rtb_DataTypeConversionmx2[0] = (real32_T)rtb_DataTypeConversion2_a;
  rtb_DataTypeConversionmx2[1] = (real32_T)rtb_DigitalClock_c;
  if (rtb_DataTypeConversionmx8_m >= ICARO3_HAL_v1_P.Switch2_Threshold_g) {
    rtb_DataTypeConversionmx2[2] = (real32_T)ICARO3_HAL_v1_P.Constant1_Value_i;
  } else {
    rtb_DataTypeConversionmx2[2] = (real32_T)(rtb_usecalibrateddata_c[2] -
      ICARO3_HAL_v1_B.Subsystem_e4.Product1);
  }

  ICARO3_HAL_v1_AttitudeFilterADIS(rtb_Step1_d, rtb_DataTypeConversionmx1,
    ICARO3_HAL_v1_P.Constant1_Value_hs, rtb_DataTypeConversionmx2,
    rtb_DataTypeConversionmx4, &ICARO3_HAL_v1_B.AttitudeFilterSS,
    &ICARO3_HAL_v1_DWork.AttitudeFilterSS, (rtP_AttitudeFilterADIS_ICARO3_HAL_v1
    *)&ICARO3_HAL_v1_P.AttitudeFilterSS);
  rtb_DataTypeConversionmx10_idx_0 = ICARO3_HAL_v1_B.AttitudeFilterSS.euler_out
    [0];
  rtb_DataTypeConversionmx10_idx_1 = ICARO3_HAL_v1_B.AttitudeFilterSS.euler_out
    [1];
  rtb_DataTypeConversionmx10_idx_2 = ICARO3_HAL_v1_B.AttitudeFilterSS.euler_out
    [2];
  wrap_PPM_output_fcn(&ICARO3_HAL_v1_B.PPMCapture_o1[0],
                      &ICARO3_HAL_v1_B.PPMCapture_o2,
                      &ICARO3_HAL_v1_B.PPMCapture_o3);
  i_0 = ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx << 2;
  ICARO3_HAL_v1_B.RateTransition19[0] =
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[i_0];
  ICARO3_HAL_v1_B.RateTransition19[1] =
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[1 + i_0];
  ICARO3_HAL_v1_B.RateTransition19[2] =
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[2 + i_0];
  ICARO3_HAL_v1_B.RateTransition19[3] =
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[3 + i_0];
  i_0 = ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx << 2;
  ICARO3_HAL_v1_B.RateTransition20[0] =
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[i_0];
  ICARO3_HAL_v1_B.RateTransition20[1] =
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[1 + i_0];
  ICARO3_HAL_v1_B.RateTransition20[2] =
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[2 + i_0];
  ICARO3_HAL_v1_B.RateTransition20[3] =
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[3 + i_0];
  if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch3_Threshold) {
    for (i = 0; i < 8; i++) {
      rtb_Switch3[i] = ICARO3_HAL_v1_B.PPMCapture_o1[i + 1];
    }

    rtb_Switch3[8] = ICARO3_HAL_v1_P.Expected12channelFillingwithzeros_Value[0];
    rtb_Switch3[9] = ICARO3_HAL_v1_P.Expected12channelFillingwithzeros_Value[1];
    rtb_Switch3[10] = ICARO3_HAL_v1_P.Expected12channelFillingwithzeros_Value[2];
    rtb_Switch3[11] = ICARO3_HAL_v1_P.Expected12channelFillingwithzeros_Value[3];
  } else {
    rtb_Switch3[0] = ICARO3_HAL_v1_B.RateTransition19[0];
    rtb_Switch3[1] = ICARO3_HAL_v1_B.RateTransition19[1];
    rtb_Switch3[2] = ICARO3_HAL_v1_B.RateTransition19[2];
    rtb_Switch3[3] = ICARO3_HAL_v1_B.RateTransition19[3];
    rtb_Switch3[4] = ICARO3_HAL_v1_B.RateTransition20[0];
    rtb_Switch3[5] = ICARO3_HAL_v1_B.RateTransition20[1];
    rtb_Switch3[6] = ICARO3_HAL_v1_B.RateTransition20[2];
    rtb_Switch3[7] = ICARO3_HAL_v1_B.RateTransition20[3];
    rtb_Switch3[8] = ICARO3_HAL_v1_P.Constant1_Value_pv[0];
    rtb_Switch3[9] = ICARO3_HAL_v1_P.Constant1_Value_pv[1];
    rtb_Switch3[10] = ICARO3_HAL_v1_P.Constant1_Value_pv[2];
    rtb_Switch3[11] = ICARO3_HAL_v1_P.Constant1_Value_pv[3];
  }

  rtb_DigitalClock_f = ((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025);
  if (ICARO3_HAL_v1_B.PPMCapture_o2 > 0) {
    ICARO3_HAL_v1_B.In = rtb_DigitalClock_f;
  }

  if (ICARO3_HAL_v1_P.HW0SIM_Value >= ICARO3_HAL_v1_P.Switch5_Threshold) {
    ICARO3_HAL_v1_B.Switch5 = rtb_DigitalClock_f - ICARO3_HAL_v1_B.In;
  } else {
    ICARO3_HAL_v1_B.Switch5 = ICARO3_HAL_v1_P.fake0secPPMage_Value;
  }

  rtb_Compare_p3 = (ICARO3_HAL_v1_B.Switch5 <= ICARO3_HAL_v1_P.RCisok_const);
  rtb_LogicalOperator_k = ((ICARO3_HAL_v1_P.THROTTLE_SIGN * (real_T)rtb_Switch3
    [2] <= ICARO3_HAL_v1_P.THROTTLE_LOW_THRES * ICARO3_HAL_v1_P.THROTTLE_SIGN) &&
                           (rtb_Switch3[2] >= ICARO3_HAL_v1_P.THROTTLE_VALID) &&
                           ((ICARO3_HAL_v1_P.YAW_SIGN * (real_T)rtb_Switch3[3] >=
    ICARO3_HAL_v1_P.YAW_RIGHT_THRES * ICARO3_HAL_v1_P.YAW_SIGN) && (rtb_Switch3
    [3] >= ICARO3_HAL_v1_P.YAW_VALID)) && rtb_Compare_p3);
  rtb_UnitDelay_j1 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c4;
  rtb_UnitDelay1 = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE;
  rtb_UnitDelay2 = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE;
  rtb_UnitDelay3 = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE;
  rtb_LogicalOperator1_k = ((ICARO3_HAL_v1_P.THROTTLE_SIGN * (real_T)
    rtb_Switch3[2] <= ICARO3_HAL_v1_P.THROTTLE_LOW_THRES *
    ICARO3_HAL_v1_P.THROTTLE_SIGN) && (rtb_Switch3[2] >=
    ICARO3_HAL_v1_P.THROTTLE_VALID) && ((ICARO3_HAL_v1_P.YAW_SIGN * (real_T)
    rtb_Switch3[3] <= ICARO3_HAL_v1_P.YAW_LEFT_THRES * ICARO3_HAL_v1_P.YAW_SIGN)
    && (rtb_Switch3[3] >= ICARO3_HAL_v1_P.YAW_VALID)) && rtb_Compare_p3);
  rtb_UnitDelay_j3 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_id;
  rtb_UnitDelay1_k = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_d;
  rtb_UnitDelay2_g = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_b;
  rtb_UnitDelay3_ix = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_l;
  rtb_Logic_idx_0 = ICARO3_HAL_v1_P.Logic_table[((((uint32_T)
    (rtb_LogicalOperator_k && ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c4 &&
     ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE &&
     ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE &&
     ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE &&
     ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE) << 1) + (rtb_LogicalOperator1_k &&
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_id &&
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_d &&
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_b &&
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_l &&
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_k)) << 1) +
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_o];
  rtb_LogicalOperator3 = (rtb_Compare_p3 && ((ICARO3_HAL_v1_P.H_CONTROL_SIGN *
    (real_T)rtb_Switch3[4] >= ICARO3_HAL_v1_P.H_CONTROL_THRES *
    ICARO3_HAL_v1_P.H_CONTROL_SIGN) && (rtb_Switch3[4] >=
    ICARO3_HAL_v1_P.H_CONTROL_VALID)));
  rtb_UnitDelay_p5 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_n;
  rtb_UnitDelay1_f = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_e;
  rtb_UnitDelay2_h = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_a;
  rtb_UnitDelay3_n = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_o;
  rtb_Sum12 = ((((uint32_T)(rtb_LogicalOperator3 &&
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_n &&
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_e &&
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_a &&
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_o &&
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_l) << 1) + !(rtb_LogicalOperator3 ||
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_n ||
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_e ||
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_a ||
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_o ||
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_l)) << 1) +
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_e;
  rtb_Logic_i_idx_0 = ICARO3_HAL_v1_P.Logic_table_o[rtb_Sum12];
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.MAN_HOVER_RTH_SIGN * (real_T)
    rtb_Switch3[5];
  rtb_Compare_om = (uint8_T)(rtb_Switch3[5] >=
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_VALID);
  rtb_LogicalOperator4 = (rtb_Compare_p3 && ((rtb_DataTypeConversion2_a <=
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_HOVER_THRES *
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_SIGN) && (rtb_Compare_om != 0)));
  rtb_UnitDelay_g3 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy;
  rtb_UnitDelay1_pu = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_eb;
  rtb_UnitDelay2_or = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_c;
  rtb_UnitDelay3_p = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_ly;
  rtb_LogicalOperator5 = (rtb_Compare_p3 && ((rtb_DataTypeConversion2_a >
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_HOVER_THRES *
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_SIGN) && (rtb_DataTypeConversion2_a <=
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_RTH_THRES * ICARO3_HAL_v1_P.MAN_HOVER_RTH_SIGN)
    && (rtb_Compare_om != 0)));
  rtb_UnitDelay_p = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_fu;
  rtb_UnitDelay1_b = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_k;
  rtb_UnitDelay2_b = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_j;
  rtb_UnitDelay3_e = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_i;
  rtb_LogicalOperator6 = (rtb_Compare_p3 && ((rtb_DataTypeConversion2_a >
    ICARO3_HAL_v1_P.MAN_HOVER_RTH_RTH_THRES * ICARO3_HAL_v1_P.MAN_HOVER_RTH_SIGN)
    && (rtb_Compare_om != 0)));
  rtb_UnitDelay_i1 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_h;
  rtb_UnitDelay1_o = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_ds;
  rtb_UnitDelay2_a = ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_e;
  rtb_UnitDelay3_l = ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_e;
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_3) {
    ICARO3_HAL_v1_B.RateTransition3 =
      ICARO3_HAL_v1_DWork.RateTransition3_Buffer0;
  }

  if (ICARO3_HAL_v1_P.Logic_table[((((uint32_T)(rtb_LogicalOperator_k &&
          ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c4 &&
          ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE &&
          ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE &&
          ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE &&
          ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE) << 1) + (rtb_LogicalOperator1_k
         && ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_id &&
         ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_d &&
         ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_b &&
         ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_l &&
         ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_k)) << 1) +
      ICARO3_HAL_v1_DWork.Memory_PreviousInput_o] == 0) {
    /* disarm system */
    ICARO3_HAL_v1_DWork.csel = 0.0;
  } else {
    /* arm is 1, */
    /*    => arm may be 1  */
    /* give priority to DP */
    if ((rtb_LogicalOperator4 && ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy &&
         ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_eb &&
         ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_c &&
         ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_ly &&
         ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_h) == 1) {
      /* DP is off => check Wp guidance and H */
      if (ICARO3_HAL_v1_P.ManualSwitch3_CurrentSetting == 1) {
        rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.SFunction_o4;
      } else {
        rtb_ManualSwitch3_a_idx_2 = ((ICARO3_HAL_v1_B.SFunction_o4 != 0.0) &&
          (ICARO3_HAL_v1_B.RateTransition3 != ICARO3_HAL_v1_P._const));
      }

      if (rtb_ManualSwitch3_a_idx_2 == 1.0) {
        /*  fuzzy guidance  */
        ICARO3_HAL_v1_DWork.csel = 6.0;
      } else if (ICARO3_HAL_v1_P.WPmodedisabled_Value == 1.0) {
        /*  waypoint guidance using hover and rth block */
        ICARO3_HAL_v1_DWork.csel = 5.0;
      } else if (ICARO3_HAL_v1_P.Logic_table_o[rtb_Sum12] == 1) {
        /* attitude + altitude control ONLY */
        ICARO3_HAL_v1_DWork.csel = 2.0;
      } else {
        /* attitude control  */
        ICARO3_HAL_v1_DWork.csel = 1.0;
      }
    } else if ((rtb_LogicalOperator5 && ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_fu &&
                ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_k &&
                ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_j &&
                ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_i &&
                ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_g) == 1) {
      /* hover */
      ICARO3_HAL_v1_DWork.csel = 3.0;
    } else {
      if ((rtb_LogicalOperator6 && ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_h &&
           ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_ds &&
           ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_e &&
           ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_e &&
           ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_kz) == 1) {
        /* return to home */
        ICARO3_HAL_v1_DWork.csel = 4.0;
      }
    }
  }

  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.csel +
    ICARO3_HAL_v1_P.CommandselalwaysJETI_Value) + ICARO3_HAL_v1_P.ahrs_sel_Gain *
    ICARO3_HAL_v1_P.SSonly_Value;
  if (ICARO3_HAL_v1_P.ManualSwitch4_CurrentSetting_m == 1) {
    rtb_Switch2_oq = ICARO3_HAL_v1_B.SFunction_o1[15];
  } else {
    rtb_Switch2_oq = rtb_DataTypeConversion2_a;
  }

  rtb_DigitalClock_k = ((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025);
  ICARO3_HAL_v1_clocklatch(ICARO3_HAL_v1_B.SFunction_o1[16], rtb_DigitalClock_k,
    &ICARO3_HAL_v1_B.clocklatch_a);
  rtb_Sum = rtb_DigitalClock_k - ICARO3_HAL_v1_B.clocklatch_a.In;
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1) {
    ICARO3_HAL_v1_B.RateTransition1 =
      ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_a;
  }

  /* % */
  /* %  Mange settings for different radios */
  /* % */
  /*  RC_TRPY_refs */
  /*  1. throttle  -> up = 1, down = 0 */
  /*  2. roll      -> left = -1, right = 1 */
  /*  3. pitch     -> up = -1, down = 1 */
  /*  4. yaw       -> left = -1, right = 1 */
  /* GENERIC RADIO WITH PARAMETRS  */
  ICARO3_HAL_v1_B.RC_TRPY_refs[0] = ((real_T)rtb_Switch3[(int32_T)
    ICARO3_HAL_v1_P.THROTTLE_IDX - 1] - ICARO3_HAL_v1_P.THROTTLE_DOWN) *
    ICARO3_HAL_v1_P.INV_THROTTLE_RANGE;
  ICARO3_HAL_v1_B.RC_TRPY_refs[1] = ((real_T)rtb_Switch3[(int32_T)
    ICARO3_HAL_v1_P.ROLL_IDX - 1] - ICARO3_HAL_v1_P.ROLL_MID) *
    ICARO3_HAL_v1_P.INV_ROLL_RANGE;
  ICARO3_HAL_v1_B.RC_TRPY_refs[2] = ((real_T)rtb_Switch3[(int32_T)
    ICARO3_HAL_v1_P.PITCH_IDX - 1] - ICARO3_HAL_v1_P.PITCH_MID) *
    ICARO3_HAL_v1_P.INV_PITCH_RANGE;
  ICARO3_HAL_v1_B.RC_TRPY_refs[3] = ((real_T)rtb_Switch3[(int32_T)
    ICARO3_HAL_v1_P.YAW_IDX - 1] - ICARO3_HAL_v1_P.YAW_MID) *
    ICARO3_HAL_v1_P.INV_YAW_RANGE;

  /* PATCH: this patch nulls the yaw command when the throttle */
  /*        is below a minimumk value in oredr to allow a safe arm, disarm */
  /*        procedure */
  if (rtb_Switch3[(int32_T)ICARO3_HAL_v1_P.THROTTLE_IDX - 1] <
      ICARO3_HAL_v1_P.THROTTLE_LOW_THRES) {
    ICARO3_HAL_v1_B.RC_TRPY_refs[3] = 0.0;
  }

  /*  all other channels: 1100 usec = > 0, 2100 usec => 1  */
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1) {
    ICARO3_HAL_v1_B.RateTransition2_b =
      ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_l;
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step1_Time_e) {
    rtb_Step1_k = ICARO3_HAL_v1_P.Step1_Y0_c;
  } else {
    rtb_Step1_k = ICARO3_HAL_v1_P.Step1_YFinal_n;
  }

  if (ICARO3_HAL_v1_P.ManualSwitch11_CurrentSetting == 1) {
    rtb_DataTypeConversion2_a = rtb_Step1_k;
  } else {
    rtb_DataTypeConversion2_a = rtb_Step1;
  }

  rtb_RateTransition2 =
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer[ICARO3_HAL_v1_DWork.RateTransition2_ActiveBufIdx];
  rtb_LogicalOperator_n = ((rtb_Step1_d != 0.0) && (rtb_DataTypeConversion2_a !=
    0.0) &&
    (ICARO3_HAL_v1_DWork.RateTransition2_Buffer[ICARO3_HAL_v1_DWork.RateTransition2_ActiveBufIdx]
     != 0.0));

  /* flag used to control if the last arming request was NOT valid: */
  /*    when controller_sel_tmp == 0 */
  /*    the only possible new state is c_sel = 1 */
  /*    if a different c_sel is requested */
  /*    => raise the flag  */
  /*    the flag will requite that c_sel */
  /*    passes from 0 (disarm) before going */
  /*    back to 0 */
  /* keep a variable that stores how many cycles (at 500 Hz) */
  /* ago the controller was enabled/disabled (with a saturation to 10 seconds) */
  if (ICARO3_HAL_v1_DWork.controller_age < 5000.0) {
    ICARO3_HAL_v1_DWork.controller_age++;
  }

  /* update safety age variables */
  /*    update only if variable is alreday positive (that is initialized) */
  /*    otherwise the safety mode is off */
  if ((ICARO3_HAL_v1_DWork.safety_hover_age > 0.0) &&
      (ICARO3_HAL_v1_DWork.safety_hover_age < 50000.0)) {
    /* limite age to 100 seconds */
    ICARO3_HAL_v1_DWork.safety_hover_age++;
  }

  /* decode modereq */
  rtb_ManualSwitch3_a_idx_2 = rt_roundd_snf(rtb_Switch2_oq);
  if (rtb_ManualSwitch3_a_idx_2 < 256.0) {
    if (rtb_ManualSwitch3_a_idx_2 >= 0.0) {
      tmp_2 = (uint8_T)rtb_ManualSwitch3_a_idx_2;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  rtb_Compare_om = (uint8_T)(tmp_2 & 7);
  rtb_ManualSwitch3_a_idx_2 = rt_roundd_snf(rtb_Switch2_oq);
  if (rtb_ManualSwitch3_a_idx_2 < 256.0) {
    if (rtb_ManualSwitch3_a_idx_2 >= 0.0) {
      tmp_2 = (uint8_T)rtb_ManualSwitch3_a_idx_2;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  ahrs_sel_tmp = (uint8_T)((tmp_2 & 128) > 1);
  rtb_ManualSwitch3_a_idx_2 = rt_roundd_snf(rtb_Switch2_oq);
  if (rtb_ManualSwitch3_a_idx_2 < 256.0) {
    if (rtb_ManualSwitch3_a_idx_2 >= 0.0) {
      tmp_2 = (uint8_T)rtb_ManualSwitch3_a_idx_2;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  command_sel_tmp = (uint8_T)((tmp_2 & 8) > 1);

  /* check if last c_sel (controller_sel_tmp) produced an invalid arming request */
  if ((ICARO3_HAL_v1_DWork.arming_request_not_valid == 1) && (rtb_Compare_om ==
       0)) {
    /* wait for c_sel to be 0 */
    /* reset flag */
    ICARO3_HAL_v1_DWork.arming_request_not_valid = 0U;
  } else {
    /* wrong request permains */
    /*  => do nothing */
  }

  if (ICARO3_HAL_v1_DWork.initial_gps_fix_arrived == 1) {
    if (ICARO3_HAL_v1_P.ManualSwitch5_CurrentSetting == 1) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.SFunction_o1[17];
    } else {
      rtb_ManualSwitch3_a_idx_2 = rtb_Compare_p3;
    }

    if ((ICARO3_HAL_v1_DWork.arming_request_not_valid == 0) && (rtb_Switch2_oq
         != ICARO3_HAL_v1_DWork.mode) && (rtb_ManualSwitch3_a_idx_2 == 1.0)) {
      /* use modereq value only if the arming request was reset to 0 after an */
      /*    previous arming request */
      /*  new mode request occurred */
      if ((rtb_Compare_om != ICARO3_HAL_v1_DWork.controller_sel) &&
          (ICARO3_HAL_v1_DWork.controller_age > 250.0)) {
        /*  switch to new controller if possible */
        /*  switching condition: the last controller was ON for at least 250 cycles (1/2 sec) */
        /* ensure that, when arming, the only valid controller selection */
        /*    is Attitude Control Mode ( controller_sel_tmp == 1) */
        /*    BUT only if not in flight (in_flight == 0) */
        /*    if the vehicle is flying, allow on the fly re-arm into */
        /*    any mode! */
        /*  this is needed for promt recovery if a disarm is issue in */
        /*  flight unadvertitely and the pilot needs to re-arm the */
        /*  vehicle quickly to the state he was flying before !!!!! */
        if ((ICARO3_HAL_v1_DWork.controller_sel == 0) &&
            (ICARO3_HAL_v1_P.udisablein_flightflagfunctionalities_Value == 0.0))
        {
          /* only available controller when arming is 1: attitude control */
          if (rtb_Compare_om == 1) {
            /*    => disable motors, they will be armed below if the */
            /*    throttle command is low !!! */
            ICARO3_HAL_v1_DWork.enable_motors = 0U;

            /* set new controller and reset age */
            ICARO3_HAL_v1_DWork.controller_sel = 1U;
            ICARO3_HAL_v1_DWork.controller_age = 0.0;
          } else {
            /* the system was disarmed but a mode different from 1 was */
            /*    requested => stay disarmed */
            ICARO3_HAL_v1_DWork.controller_sel = 0U;

            /* this is not necessary, it is here for readability */
            ICARO3_HAL_v1_DWork.enable_motors = 0U;

            /* raise arming request not valid flag */
            /*    this will require that controller_sel_tmp */
            /*    passes from 0 before a new valid mode_req is */
            /*    considered */
            ICARO3_HAL_v1_DWork.arming_request_not_valid = 1U;
          }
        } else {
          /* the current controller is not 0 (disarmed) */
          /*    => permit the switch */
          /* check if the mode can be activated */
          if ((rtb_Compare_om == 3) || (rtb_Compare_om == 4) || (rtb_Compare_om ==
               5) || (rtb_Compare_om == 6)) {
            /* these modes require gps to work */
            /* check gps status */
            if (ICARO3_HAL_v1_B.RateTransition1 < 5.0) {
              /* gps is less than the thresold => allow activation */
              ICARO3_HAL_v1_DWork.controller_sel = rtb_Compare_om;
              ICARO3_HAL_v1_DWork.controller_age = 0.0;

              /* if the vehicle is already in flight => enable the */
              /*    motors regardless of throttle stick position at the */
              /*    minimum */
              if (ICARO3_HAL_v1_P.udisablein_flightflagfunctionalities_Value ==
                  1.0) {
                ICARO3_HAL_v1_DWork.enable_motors = 1U;
              }
            }
          } else {
            ICARO3_HAL_v1_DWork.controller_sel = rtb_Compare_om;

            /* check if disarming, if yes disable the motors */
            if (ICARO3_HAL_v1_DWork.controller_sel == 0) {
              ICARO3_HAL_v1_DWork.enable_motors = 0U;
            }

            ICARO3_HAL_v1_DWork.controller_age = 0.0;
            if (ICARO3_HAL_v1_P.udisablein_flightflagfunctionalities_Value ==
                1.0) {
              ICARO3_HAL_v1_DWork.enable_motors = 1U;
            }
          }
        }
      }

      if ((command_sel_tmp == 1) && (ICARO3_HAL_v1_DWork.command_sel == 0)) {
        /*  switch to RC command if possible */
        if (ICARO3_HAL_v1_B.Switch5 < 0.5) {
          /*  switching condition */
          ICARO3_HAL_v1_DWork.command_sel = 1U;
          if (ICARO3_HAL_v1_DWork.controller_sel == 1) {
            ICARO3_HAL_v1_DWork.enable_motors = 0U;
          }
        }
      } else {
        if ((command_sel_tmp == 0) && (ICARO3_HAL_v1_DWork.command_sel == 1) &&
            (rtb_Sum < 0.5)) {
          /*  switch to joystick command if possible */
          /*  switching condition */
          ICARO3_HAL_v1_DWork.command_sel = 0U;
          if (ICARO3_HAL_v1_DWork.controller_sel == 1) {
            ICARO3_HAL_v1_DWork.enable_motors = 0U;
          }
        }
      }

      if ((ahrs_sel_tmp == 1) && (ICARO3_HAL_v1_DWork.ahrs_sel == 0)) {
        /*  switch to stick IMU if possible */
        /*  switching condition */
        ICARO3_HAL_v1_DWork.ahrs_sel = 1U;
      } else {
        if ((ahrs_sel_tmp == 0) && (ICARO3_HAL_v1_DWork.ahrs_sel == 1)) {
          /*  switch to analog IMU if possible */
          /*  switching condition */
          ICARO3_HAL_v1_DWork.ahrs_sel = 0U;
        }
      }
    }

    if (ICARO3_HAL_v1_DWork.controller_sel != 0) {
      /* only if controller sel is not DISARMED */
      /*    check if enable_motors must be set */
      /*    anyway it is NEVER reset !!!! */
      if ((ICARO3_HAL_v1_DWork.command_sel == 0) &&
          (ICARO3_HAL_v1_B.SFunction_o1[0] < 0.02)) {
        ICARO3_HAL_v1_DWork.enable_motors = 1U;
      } else {
        if ((ICARO3_HAL_v1_DWork.command_sel == 1) &&
            (ICARO3_HAL_v1_B.RC_TRPY_refs[0] < 0.02)) {
          ICARO3_HAL_v1_DWork.enable_motors = 1U;
        }
      }
    }

    /*  qui alzo le soglie di tolleranza su RC_ e CMD_ age: se il risultato */
    /*    di scoprire un age troppo alta e' spegnere tutto ...questa deve essere proprio una manovra */
    /*    di estrema disperazione .... quindi metto la soglia a 2 secondi */
    /*  In futuro andra' inserita la modalità return to home in questa situazione, in cui il velivolo */
    /*    ritorna lentamente verso la locazione di decollo alla quota attuale per poi scenedere a 2 metri di quota */
    /*    quando si trova sulla verticale del punto di partenza ...cosi' che male che vada (radio morta) possa essere */
    /*    addirittura recuperato a mano */
    /* safety management  */
    if (ICARO3_HAL_v1_DWork.controller_sel != 0) {
      /* only if controller sel is not DISARMED => check for safety */
      /* conditions */
      /* NOTE: this check is necessary because, if the user is on the */
      /* ground, disarmed, and switches the radio off or loses GPS signal  */
      /* no safety hover or RTH must be applied  */
      if (((ICARO3_HAL_v1_DWork.command_sel == 1) && (ICARO3_HAL_v1_B.Switch5 >
            2.0)) || ((ICARO3_HAL_v1_DWork.command_sel == 0) && (rtb_Sum > 2.0)))
      {
        /* was 0.5 */
        /* RC is lost */
        /* check if already in safety hover or RTH */
        if (ICARO3_HAL_v1_DWork.safety_hover_age < 2500.0) {
          /* age of safety hover is : */
          /*    0: not enabled yet */
          /*    >0: already enabled */
          if (ICARO3_HAL_v1_DWork.safety_hover_age == 0.0) {
            /* safety hover not enabled yet */
            /*    => go to hover for 15 seconds ONLY if GPS is working */
            if (ICARO3_HAL_v1_B.RateTransition1 < 5.0) {
              ICARO3_HAL_v1_DWork.controller_sel = 3U;

              /* hover with gps  */
              ICARO3_HAL_v1_DWork.safety_hover_age = 1.0;

              /* enable counter */
            } else {
              /* GPS not valid => SELF DESTRUCTION */
              ICARO3_HAL_v1_DWork.controller_sel = 7U;

              /* slow descent without gps */
            }
          } else {
            /* safety hover already engaged */
            /* if GPS signal returns, switch to hover with gps  */
            if ((ICARO3_HAL_v1_B.RateTransition1 < 5.0) &&
                (ICARO3_HAL_v1_DWork.controller_sel == 7)) {
              ICARO3_HAL_v1_DWork.controller_sel = 3U;
            }
          }
        } else {
          /* safety hover lasted more then 5 seconds */
          /*    => switch to RTH */
          if (ICARO3_HAL_v1_B.RateTransition1 < 5.0) {
            ICARO3_HAL_v1_DWork.controller_sel = 4U;

            /* return to home  */
          } else {
            /* GPS not valid => SELF DESTRUCTION */
            ICARO3_HAL_v1_DWork.controller_sel = 7U;
          }
        }

        /* controller_sel = uint8(0); */
      } else {
        /* command link is working */
        /* check if in safety mode */
        if (ICARO3_HAL_v1_DWork.safety_hover_age > 0.0) {
          /* go to hover (not safety hover) */
          ICARO3_HAL_v1_DWork.safety_hover_age = 0.0;

          /* reset and disable counter */
          if (ICARO3_HAL_v1_B.RateTransition1 < 5.0) {
            ICARO3_HAL_v1_DWork.controller_sel = 3U;

            /* and wait for pilot to take over */
            /* NOTE:  esempio di possibile cricita : volo in manuale, perdita della radio per piu' di 2 secondi  */
            /*        va in safety hover, poi ritorna la radio, il codice qui presente lo mette in hover   */
            /*        ma al prossimo passaggio viene rimesso subito */
            /*        in manuale perche' la radio va, ed i bottoni sulla radio saranno impostati sempre su manuale  */
            /* TODO: gestire questa situazione, magari forzando il */
            /*        pilota a dover mettere a mano gli stick su hover prima di poter riprendere il modo manuale  */
          } else {
            /* go to manual + altitude */
            ICARO3_HAL_v1_DWork.controller_sel = 2U;
          }
        }
      }
    }

    /* check that GPS is valid when in modes that requires it  */
    if (((ICARO3_HAL_v1_DWork.controller_sel == 3) ||
         (ICARO3_HAL_v1_DWork.controller_sel == 4) ||
         (ICARO3_HAL_v1_DWork.controller_sel == 5) ||
         (ICARO3_HAL_v1_DWork.controller_sel == 6)) &&
        (!(ICARO3_HAL_v1_B.RateTransition1 < 5.0))) {
      /* GPS signal lost  */
      /*    => go to manual + altitude  */
      ICARO3_HAL_v1_DWork.controller_sel = 2U;

      /* manual + altitude */
      ICARO3_HAL_v1_DWork.controller_age = 0.0;

      /* if later GPS signal returns and the operator is still requesting a mode with GPS */
      /*    the requested mode is automatically re-entered */
    } else {
      /* OK => do nothing */
    }

    /*  if (command_sel == 0 && cmd_age > 2.0)  %was 0.5 */
    /*      controller_sel = uint8(0); */
    /*  end */
  } else {
    /* check for first fix */
    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_c == 1) {
      rtb_Compare_pc = ICARO3_HAL_v1_P.donotwaitforGPS_Value;
    } else {
      rtb_Compare_pc = ICARO3_HAL_v1_B.RateTransition2_b;
    }

    if ((rtb_Compare_pc && rtb_LogicalOperator_n) == 1) {
      ICARO3_HAL_v1_DWork.initial_gps_fix_arrived = 1U;
    }

    /* just in case request a virtual disarm */
    if (rtb_Compare_om != 0) {
      ICARO3_HAL_v1_DWork.arming_request_not_valid = 1U;
    }
  }

  if ((ICARO3_HAL_v1_B.Switch4[2] == 0) || (ICARO3_HAL_v1_B.Switch4[3] == 0) ||
      ((ICARO3_HAL_v1_B.Switch4[4] == 0) && (ICARO3_HAL_v1_DWork.ahrs_sel == 1)))
  {
    ICARO3_HAL_v1_DWork.ahrs_sel = 0U;
  }

  if (ICARO3_HAL_v1_DWork.ahrs_sel > 1) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(ICARO3_HAL_v1_DWork.ahrs_sel << 7);
  }

  if (ICARO3_HAL_v1_DWork.command_sel > 31) {
    command_sel_tmp = MAX_uint8_T;
  } else {
    command_sel_tmp = (uint8_T)(ICARO3_HAL_v1_DWork.command_sel << 3);
  }

  i_0 = (int32_T)((uint32_T)tmp_2 + command_sel_tmp);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  i_0 = (int32_T)((uint32_T)i_0 + ICARO3_HAL_v1_DWork.controller_sel);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  ICARO3_HAL_v1_DWork.mode = (uint8_T)i_0;
  rtb_mode_out = ICARO3_HAL_v1_DWork.mode;
  rtb_controller_sel_out = ICARO3_HAL_v1_DWork.controller_sel;
  rtb_ahrs_sel_out = ICARO3_HAL_v1_DWork.ahrs_sel;
  rtb_command_sel_out = ICARO3_HAL_v1_DWork.command_sel;
  rtb_enable_motors_out = ICARO3_HAL_v1_DWork.enable_motors;
  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.Step_Time_j) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Step_Y0_o;
  } else {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Step_YFinal_n;
  }

  rtb_DataTypeConversion2_a -= rtb_Step1_k;
  rtb_DataTypeConversionmx8_g = (real32_T)rtb_DataTypeConversion2_a;
  rtb_DataTypeConversiononi2cmag2[0] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator1_BitMask);
  rtb_DataTypeConversiononi2cmag2[1] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator2_BitMask);
  rtb_DataTypeConversiononi2cmag2[2] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator3_BitMask);
  rtb_DataTypeConversiononi2cmag2[3] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator4_BitMask);
  rtb_DataTypeConversiononi2cmag2[4] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator5_BitMask);
  rtb_DataTypeConversiononi2cmag2[5] = (uint16_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator6_BitMask);

  /*  Accelerations in m/s^2 */
  /*  PQR in rad/s */
  /*  Convert a and w from adis axes to ICARO2 axes */
  if (rtb_DataTypeConversiononi2cmag2[0] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[0];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[0];
  }

  b_u_idx_1 = b_u_idx_0 * 2.522F * 9.81F / 1000.0F;
  if (rtb_DataTypeConversiononi2cmag2[1] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[1];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[1];
  }

  b_u_idx_2 = b_u_idx_0 * 2.522F * 9.81F / 1000.0F;
  if (rtb_DataTypeConversiononi2cmag2[2] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[2];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[2];
  }

  b_u_idx_0 = b_u_idx_0 * 2.522F * 9.81F / 1000.0F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_DataTypeConversion6[i_0] = ((real32_T)c[i_0 + 3] * b_u_idx_2 + (real32_T)
      c[i_0] * b_u_idx_1) + (real32_T)c[i_0 + 6] * b_u_idx_0;
  }

  ICARO3_HAL_v1_Subsystem(rtb_DataTypeConversionmx8_g, rtb_DataTypeConversion6[0],
    &ICARO3_HAL_v1_B.Subsystem_l, &ICARO3_HAL_v1_DWork.Subsystem_l,
    (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_l);
  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_lc) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant1_Value;
  } else {
    rtb_DataTypeConversion2_a = rtb_DataTypeConversion6[0] -
      ICARO3_HAL_v1_B.Subsystem_l.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_g,
    rtb_DataTypeConversion6[1], &ICARO3_HAL_v1_B.Subsystem_b,
    &ICARO3_HAL_v1_DWork.Subsystem_b, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_b);
  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_b) {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.Constant1_Value_d;
  } else {
    rtb_DigitalClock_c = rtb_DataTypeConversion6[1] -
      ICARO3_HAL_v1_B.Subsystem_b.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_g,
    rtb_DataTypeConversion6[2], &ICARO3_HAL_v1_B.Subsystem_o,
    &ICARO3_HAL_v1_DWork.Subsystem_o, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_o);
  rtb_DataTypeConversionmx1_e[0] = (real32_T)rtb_DataTypeConversion2_a;
  rtb_DataTypeConversionmx1_e[1] = (real32_T)rtb_DigitalClock_c;
  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_jj) {
    rtb_DataTypeConversionmx1_e[2] = (real32_T)ICARO3_HAL_v1_P.Constant1_Value_h;
  } else {
    rtb_DataTypeConversionmx1_e[2] = (real32_T)((rtb_DataTypeConversion6[2] -
      ICARO3_HAL_v1_B.Subsystem_o.Product1) - ICARO3_HAL_v1_P.Constant2_Value);
  }

  rtb_DataTypeConversionmx4_c[0] = (real32_T)rtb_DataTypeConversion3[0];
  rtb_DataTypeConversionmx4_c[1] = (real32_T)rtb_DataTypeConversion3[1];
  rtb_DataTypeConversionmx4_c[2] = (real32_T)rtb_DataTypeConversion3_j;
  if (rtb_DataTypeConversiononi2cmag2[3] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[3];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[3];
  }

  b_u_idx_1 = b_u_idx_0 * 0.07326F * 3.14159274F / 180.0F;
  if (rtb_DataTypeConversiononi2cmag2[4] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[4];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[4];
  }

  b_u_idx_2 = b_u_idx_0 * 0.07326F * 3.14159274F / 180.0F;
  if (rtb_DataTypeConversiononi2cmag2[5] > 8191) {
    b_u_idx_0 = -16384.0F + (real32_T)rtb_DataTypeConversiononi2cmag2[5];
  } else {
    b_u_idx_0 = rtb_DataTypeConversiononi2cmag2[5];
  }

  b_u_idx_0 = b_u_idx_0 * 0.07326F * 3.14159274F / 180.0F;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_DataTypeConversion5[i_0] = ((real32_T)b_3[i_0 + 3] * b_u_idx_2 +
      (real32_T)b_3[i_0] * b_u_idx_1) + (real32_T)b_3[i_0 + 6] * b_u_idx_0;
  }

  if (rtb_DataTypeConversionmx8_g > 0.0F) {
    ICARO3_HAL_v1_B.Product1 =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_j /
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_kb;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_j +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval * rtb_DataTypeConversion5[0];
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_kb +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval *
      ICARO3_HAL_v1_P.Constant_Value;
  }

  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_nb) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant1_Value_l;
  } else {
    rtb_DataTypeConversion2_a = rtb_DataTypeConversion5[0] -
      ICARO3_HAL_v1_B.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_g,
    rtb_DataTypeConversion5[1], &ICARO3_HAL_v1_B.Subsystem_n4,
    &ICARO3_HAL_v1_DWork.Subsystem_n4, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_n4);
  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_o) {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.Constant1_Value_j;
  } else {
    rtb_DigitalClock_c = rtb_DataTypeConversion5[1] -
      ICARO3_HAL_v1_B.Subsystem_n4.Product1;
  }

  ICARO3_HAL_v1_Subsystem_b(rtb_DataTypeConversionmx8_g,
    rtb_DataTypeConversion5[2], &ICARO3_HAL_v1_B.Subsystem_d,
    &ICARO3_HAL_v1_DWork.Subsystem_d, (rtP_Subsystem_ICARO3_HAL_v1_o *)
    &ICARO3_HAL_v1_P.Subsystem_d);
  rtb_DataTypeConversionmx2_k[0] = (real32_T)rtb_DataTypeConversion2_a;
  rtb_DataTypeConversionmx2_k[1] = (real32_T)rtb_DigitalClock_c;
  if (rtb_DataTypeConversionmx8_g >= ICARO3_HAL_v1_P.Switch2_Threshold_f) {
    rtb_DataTypeConversionmx2_k[2] = (real32_T)
      ICARO3_HAL_v1_P.Constant1_Value_de;
  } else {
    rtb_DataTypeConversionmx2_k[2] = (real32_T)(rtb_DataTypeConversion5[2] -
      ICARO3_HAL_v1_B.Subsystem_d.Product1);
  }

  ICARO3_HAL_v1_AttitudeFilterADIS(rtb_Step1_k, rtb_DataTypeConversionmx1_e,
    ICARO3_HAL_v1_P.Constant1_Value_e, rtb_DataTypeConversionmx2_k,
    rtb_DataTypeConversionmx4_c, &ICARO3_HAL_v1_B.AttitudeFilterADIS,
    &ICARO3_HAL_v1_DWork.AttitudeFilterADIS,
    (rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.AttitudeFilterADIS);
  rtb_ManualSwitch3_a_idx_0 = ICARO3_HAL_v1_B.AttitudeFilterADIS.euler_out[0];
  rtb_ManualSwitch3_a_idx_1 = ICARO3_HAL_v1_B.AttitudeFilterADIS.euler_out[1];
  rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.AttitudeFilterADIS.euler_out[2];
  rtb_DataTypeConversionmx1_j[0] = (real32_T)rtb_Switch2;
  rtb_DataTypeConversionmx1_j[1] = (real32_T)rtb_Switch2_a;
  rtb_DataTypeConversionmx1_j[2] = (real32_T)rtb_Switch2_ag;
  rtb_DataTypeConversionmx4_m[0] = (real32_T)rtb_DataTypeConversion3[0];
  rtb_DataTypeConversionmx4_m[1] = (real32_T)rtb_DataTypeConversion3[1];
  rtb_DataTypeConversionmx4_m[2] = (real32_T)rtb_DataTypeConversion3_j;
  rtb_DataTypeConversionmx2_e[0] = (real32_T)rtb_Switch2_og;
  rtb_DataTypeConversionmx2_e[1] = (real32_T)rtb_Switch2_g;
  rtb_DataTypeConversionmx2_e[2] = (real32_T)rtb_Switch2_d;
  ICARO3_HAL_v1_AttitudeFilterADIS(rtb_Step1, rtb_DataTypeConversionmx1_j,
    ICARO3_HAL_v1_P.Constant1_Value_mc, rtb_DataTypeConversionmx2_e,
    rtb_DataTypeConversionmx4_m, &ICARO3_HAL_v1_B.AttitudeFilterMPU,
    &ICARO3_HAL_v1_DWork.AttitudeFilterMPU,
    (rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.AttitudeFilterMPU);
  rtb_h_calib[0] = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[0];
  rtb_h_calib[1] = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[1];
  rtb_h_calib[2] = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[2];
  rtb_Compare_pc = (ICARO3_HAL_v1_P.ManualSwitch8_CurrentSetting_p == 1);
  rtb_ManualSwitch3_g = rtb_ManualSwitch3_a_idx_0;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_g = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[0];
  }

  rtb_ManualSwitch3_a_idx_0 = rtb_ManualSwitch3_g;
  rtb_ManualSwitch3_g = rtb_ManualSwitch3_a_idx_1;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_g = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[1];
  }

  rtb_ManualSwitch3_a_idx_1 = rtb_ManualSwitch3_g;
  rtb_ManualSwitch3_g = rtb_ManualSwitch3_a_idx_2;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_g = ICARO3_HAL_v1_B.AttitudeFilterMPU.euler_out[2];
  }

  if (rtb_ahrs_sel_out == 0.0) {
    rtb_rpy[0] = rtb_ManualSwitch3_a_idx_0;
    rtb_rpy[1] = rtb_ManualSwitch3_a_idx_1;
    rtb_rpy[2] = rtb_ManualSwitch3_g;
  } else if (rtb_ahrs_sel_out == 1.0) {
    rtb_rpy[0] = rtb_DataTypeConversionmx10_idx_0;
    rtb_rpy[1] = rtb_DataTypeConversionmx10_idx_1;
    rtb_rpy[2] = rtb_DataTypeConversionmx10_idx_2;
  } else {
    rtb_rpy[0] = 0.0;
    rtb_rpy[1] = 0.0;
    rtb_rpy[2] = 0.0;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[0] = rtb_rpy[0];
    ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[1] = rtb_rpy[1];
    ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[2] = rtb_rpy[2];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0 = ICARO3_HAL_v1_B.SFunction_o1
      [19];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition7_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[0] = rtb_h_calib[0];
    ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[1] = rtb_h_calib[1];
    ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[2] = rtb_h_calib[2];
  }

  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.clockTickCounter <
    ICARO3_HAL_v1_P.PulseGenerator1_Duty) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter >= 0) ?
    ICARO3_HAL_v1_P.PulseGenerator1_Amp : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter >=
      ICARO3_HAL_v1_P.PulseGenerator1_Period - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter++;
  }

  rtb_DigitalClock_c = (ICARO3_HAL_v1_DWork.clockTickCounter_n <
                        ICARO3_HAL_v1_P.PulseGenerator2_Duty) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_n >= 0) ?
    ICARO3_HAL_v1_P.PulseGenerator2_Amp : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_n >=
      ICARO3_HAL_v1_P.PulseGenerator2_Period - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_n = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_n++;
  }

  if (rtb_LogicalOperator_n) {
    ICARO3_HAL_v1_B.Switch = rtb_DataTypeConversion2_a;
  } else {
    ICARO3_HAL_v1_B.Switch = rtb_DigitalClock_c;
  }

  /* S-Function Block: <S23>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, ICARO3_HAL_v1_B.Switch);
  if (rtb_RateTransition2 > 0.0) {
    if (!ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwith9dofACC1_MODE) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_kb =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_i;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_jq =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_a;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE_l =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_IC;
      ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwith9dofACC1_MODE = true;
    }

    ICARO3_HAL_v1_B.DiscreteTimeIntegrator1_i =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_jq;
    rtb_Switch2_oq =
      ICARO3_HAL_v1_DWork.RateTransition3_Buffer[ICARO3_HAL_v1_DWork.RateTransition3_ActiveBufIdx]
      - ICARO3_HAL_v1_B.DiscreteTimeIntegrator1_i;
    ICARO3_HAL_v1_B.Sum1_j =
      ICARO3_HAL_v1_P.AltitudeComplementaryFilterwith9dofACC1_kd *
      rtb_Switch2_oq + ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_kb;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_kb +=
      (((ICARO3_HAL_v1_P.Constant3_Value_pr + ICARO3_HAL_v1_P.Constant3_Value) *
        ICARO3_HAL_v1_P.Gain13_Gain +
        ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE_l) +
       ICARO3_HAL_v1_P.AltitudeComplementaryFilterwith9dofACC1_kp *
       rtb_Switch2_oq) * ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_o;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_jq +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_k * ICARO3_HAL_v1_B.Sum1_j;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE_l +=
      ICARO3_HAL_v1_P.AltitudeComplementaryFilterwith9dofACC1_ki *
      rtb_Switch2_oq * ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_gainval;
  } else {
    if (ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwith9dofACC1_MODE) {
      ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwith9dofACC1_MODE = false;
    }
  }

  if (rtb_RateTransition2 > 0.0) {
    if (!ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwithH_DATA__MODE) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_b =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_g;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_os =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_e;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_IC_l;
      ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwithH_DATA__MODE = true;
    }

    ICARO3_HAL_v1_B.DiscreteTimeIntegrator1 =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_os;
    rtb_Switch2_oq =
      ICARO3_HAL_v1_DWork.RateTransition3_Buffer[ICARO3_HAL_v1_DWork.RateTransition3_ActiveBufIdx]
      - ICARO3_HAL_v1_B.DiscreteTimeIntegrator1;
    ICARO3_HAL_v1_B.Sum1_g =
      ICARO3_HAL_v1_P.AltitudeComplementaryFilterwithH_DATA_kd * rtb_Switch2_oq
      + ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_b;
    if (ICARO3_HAL_v1_P.ManualSwitch9_CurrentSetting == 1) {
      b_u_idx_0 = ICARO3_HAL_v1_B.AttitudeFilterADIS.a_ned[2];
    } else {
      b_u_idx_0 = ICARO3_HAL_v1_B.AttitudeFilterMPU.a_ned[2];
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_b += (((b_u_idx_0 +
      ICARO3_HAL_v1_P.Constant3_Value_o) * ICARO3_HAL_v1_P.Gain13_Gain_c +
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE) +
      ICARO3_HAL_v1_P.AltitudeComplementaryFilterwithH_DATA_kp * rtb_Switch2_oq)
      * ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_d;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_os +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_o * ICARO3_HAL_v1_B.Sum1_g;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE +=
      ICARO3_HAL_v1_P.AltitudeComplementaryFilterwithH_DATA_ki * rtb_Switch2_oq *
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_gainval_n;
  } else {
    if (ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwithH_DATA__MODE) {
      ICARO3_HAL_v1_DWork.AltitudeComplementaryFilterwithH_DATA__MODE = false;
    }
  }

  if (rtb_ahrs_sel_out == 0.0) {
    if (ICARO3_HAL_v1_P.ManualSwitch10_CurrentSetting == 1) {
      rtb_h_calib[0] = rtb_DataTypeConversionmx2_k[0];
      rtb_h_calib[1] = rtb_DataTypeConversionmx2_k[1];
      rtb_h_calib[2] = rtb_DataTypeConversionmx2_k[2];
    } else {
      rtb_h_calib[0] = rtb_DataTypeConversionmx2_e[0];
      rtb_h_calib[1] = rtb_DataTypeConversionmx2_e[1];
      rtb_h_calib[2] = rtb_DataTypeConversionmx2_e[2];
    }
  } else if (rtb_ahrs_sel_out == 1.0) {
    rtb_h_calib[0] = rtb_DataTypeConversionmx2[0];
    rtb_h_calib[1] = rtb_DataTypeConversionmx2[1];
    rtb_h_calib[2] = rtb_DataTypeConversionmx2[2];
  } else {
    rtb_h_calib[0] = 0.0;
    rtb_h_calib[1] = 0.0;
    rtb_h_calib[2] = 0.0;
  }

  rtb_DataTypeConversion2_a = (real_T)rtb_controller_sel_out *
    rtb_enable_motors_out;
  if ((ICARO3_HAL_v1_B.RateTransition3 ==
       ICARO3_HAL_v1_P.CompareToConstant_const) && (rtb_DataTypeConversion2_a ==
       ICARO3_HAL_v1_P.CompareToConstant1_const)) {
    ICARO3_HAL_v1_B.Switch_o = ICARO3_HAL_v1_P.Hovermode_Value;
  } else {
    ICARO3_HAL_v1_B.Switch_o = rtb_DataTypeConversion2_a;
  }

  rtb_Compare_pc = (ICARO3_HAL_v1_B.Switch_o ==
                    ICARO3_HAL_v1_P.controller7_const);
  if (rtb_command_sel_out == 0) {
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.SFunction_o1[0];
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.SFunction_o1[1];
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.SFunction_o1[2];
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.SFunction_o1[3];
  } else if (rtb_command_sel_out == 1) {
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.RC_TRPY_refs[0];
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.RC_TRPY_refs[1];
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.RC_TRPY_refs[2];
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.RC_TRPY_refs[3];
  } else {
    rtb_refs_idx_0 = 0.0;
    rtb_refs_idx_1 = 0.0;
    rtb_refs_idx_2 = 0.0;
    rtb_refs_idx_3 = 0.0;
  }

  if (rtb_Compare_pc) {
    rtb_Switch_idx_0 = ICARO3_HAL_v1_P.Frpyforsafetydescent_Value[0];
    rtb_Switch_idx_1 = ICARO3_HAL_v1_P.Frpyforsafetydescent_Value[1];
    rtb_Switch2_ag = ICARO3_HAL_v1_P.Frpyforsafetydescent_Value[2];
    rtb_Switch_idx_3 = ICARO3_HAL_v1_P.Frpyforsafetydescent_Value[3];
  } else {
    rtb_Switch_idx_0 = rtb_refs_idx_0;
    rtb_Switch_idx_1 = rtb_refs_idx_1;
    rtb_Switch2_ag = rtb_refs_idx_2;
    rtb_Switch_idx_3 = rtb_refs_idx_3;
  }

  if (ICARO3_HAL_v1_P.ManualSwitch3_CurrentSetting_g == 1) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.lowerHdynamics_Value[0];
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
      ICARO3_HAL_v1_P.lowerHdynamics_Value[1];
    rtb_Gain2_idx_0 = ICARO3_HAL_v1_P.lowerHdynamics_Value[2];
  } else {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.higherHdynamics_Value[0];
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
      ICARO3_HAL_v1_P.higherHdynamics_Value[1];
    rtb_Gain2_idx_0 = ICARO3_HAL_v1_P.higherHdynamics_Value[2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Gain1[i_0] = ICARO3_HAL_v1_P.SF_H_PID_GAINS[i_0 + 6] * rtb_Gain2_idx_0 +
      (ICARO3_HAL_v1_P.SF_H_PID_GAINS[i_0 + 3] *
       rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 +
       ICARO3_HAL_v1_P.SF_H_PID_GAINS[i_0] * rtb_ManualSwitch3_a_idx_2);
  }

  if (rtb_ahrs_sel_out == 0.0) {
    rtb_h_data[0] = ICARO3_HAL_v1_B.DiscreteTimeIntegrator1;
  } else if (rtb_ahrs_sel_out == 1.0) {
    rtb_h_data[0] = ICARO3_HAL_v1_B.DiscreteTimeIntegrator1_i;
  } else {
    rtb_h_data[0] = 0.0;
  }

  if (rtb_ahrs_sel_out == 0.0) {
    rtb_h_data[1] = ICARO3_HAL_v1_B.Sum1_g;
  } else if (rtb_ahrs_sel_out == 1.0) {
    rtb_h_data[1] = ICARO3_HAL_v1_B.Sum1_j;
  } else {
    rtb_h_data[1] = 0.0;
  }

  if (ICARO3_HAL_v1_P.ManualSwitch8_CurrentSetting_l == 1) {
    rtb_enable_motors_out = ICARO3_HAL_v1_B.SFunction_o1[19];
  } else {
    rtb_enable_motors_out = ICARO3_HAL_v1_P.Constant14_Value;
  }

  if ((ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller2_const) ||
      rtb_Compare_pc) {
    if (!ICARO3_HAL_v1_DWork.AttitudeAltitudeController_MODE) {
      ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_in =
        ICARO3_HAL_v1_P.UnitDelay_InitialCondition;
      ICARO3_HAL_v1_DWork.h_ref_not_empty_b = false;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_n;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c0 = 2;
      ICARO3_HAL_v1_DWork.h_ref_not_empty = false;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_am =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_k;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_o = 1U;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = 2;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_ah = ICARO3_HAL_v1_P.Internal_X0;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_pq =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_b;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_ax = ICARO3_HAL_v1_P.Internal_X0_h;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_ap =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_g;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_lk = ICARO3_HAL_v1_P.Internal_X0_d;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_g =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_h;
      ICARO3_HAL_v1_DWork.AttitudeAltitudeController_MODE = true;
    }

    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Sum_fw = ICARO3_HAL_v1_P.Constant6_Value;
    } else {
      rtb_Sum_fw = ICARO3_HAL_v1_P.Constant7_Value;
    }

    rtb_Switch2_d = rtb_Sum_fw * ICARO3_HAL_v1_P.varioen_Value;
    rtb_Sum_fw = ICARO3_HAL_v1_P.Gain_Gain * rtb_Switch_idx_0 -
      ICARO3_HAL_v1_P.Constant1_Value_p;
    if (rtb_Sum_fw > ICARO3_HAL_v1_P.Saturation1_UpperSat) {
      rtb_Sum_fw = ICARO3_HAL_v1_P.Saturation1_UpperSat;
    } else {
      if (rtb_Sum_fw < ICARO3_HAL_v1_P.Saturation1_LowerSat) {
        rtb_Sum_fw = ICARO3_HAL_v1_P.Saturation1_LowerSat;
      }
    }

    if (rtb_Sum_fw > ICARO3_HAL_v1_P.Hvario_x_dead_zone) {
      rtb_Sum_fw -= ICARO3_HAL_v1_P.Hvario_x_dead_zone;
    } else if (rtb_Sum_fw >= -ICARO3_HAL_v1_P.Hvario_x_dead_zone) {
      rtb_Sum_fw = 0.0;
    } else {
      rtb_Sum_fw -= -ICARO3_HAL_v1_P.Hvario_x_dead_zone;
    }

    if (!ICARO3_HAL_v1_DWork.h_ref_not_empty_b) {
      ICARO3_HAL_v1_DWork.h_ref_j = rtb_h_data[0];
      ICARO3_HAL_v1_DWork.h_ref_not_empty_b = true;
    }

    rtb_RelationalOperator_d = (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_in !=
      ICARO3_HAL_v1_DWork.h_ref_j);
    if (rtb_RelationalOperator_d &&
        (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c0 <= 0)) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_n;
    }

    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 >=
        ICARO3_HAL_v1_P.Hvario_x_max) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
        ICARO3_HAL_v1_P.Hvario_x_max;
    } else {
      if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 <=
          ICARO3_HAL_v1_P.Hvario_x_min) {
        ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
          ICARO3_HAL_v1_P.Hvario_x_min;
      }
    }

    rtb_Sum_fw *= 1.0 / (1.0 - ICARO3_HAL_v1_P.Hvario_x_dead_zone);
    if (rtb_Sum_fw > ICARO3_HAL_v1_P.Saturation_UpperSat) {
      rtb_RateTransition2 = ICARO3_HAL_v1_P.Saturation_UpperSat;
    } else if (rtb_Sum_fw < ICARO3_HAL_v1_P.Saturation_LowerSat) {
      rtb_RateTransition2 = ICARO3_HAL_v1_P.Saturation_LowerSat;
    } else {
      rtb_RateTransition2 = rtb_Sum_fw;
    }

    rtb_Switch2_a = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 +
      ICARO3_HAL_v1_DWork.h_ref_j;
    if (!ICARO3_HAL_v1_DWork.h_ref_not_empty) {
      /*      thrust_offset = thrust; */
      ICARO3_HAL_v1_DWork.thrust_offset = 0.5;
      ICARO3_HAL_v1_DWork.h_ref = rtb_h_data[0];
      ICARO3_HAL_v1_DWork.h_ref_not_empty = true;
    }

    rtb_Switch2_oq = rtb_Switch_idx_0 - ICARO3_HAL_v1_DWork.thrust_offset;
    if (fabs(rtb_Switch2_oq) < 0.4) {
      rtb_Switch2_oq = 0.0;
    }

    if ((ICARO3_HAL_v1_DWork.h_ref <= -5.0) && (rtb_Switch2_oq < 0.0)) {
      rtb_Switch2_oq = 0.0;
    } else {
      if ((ICARO3_HAL_v1_DWork.h_ref >= 5.0) && (rtb_Switch2_oq > 0.0)) {
        rtb_Switch2_oq = 0.0;
      }
    }

    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_g == 1) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Constant1_Value_b;
    } else {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Constant2_Value_c;
    }

    ICARO3_HAL_v1_DWork.h_ref += ICARO3_HAL_v1_P.MATLABFunction4_T
      * rtb_Switch2_oq * rtb_ManualSwitch3_a_idx_2;
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_o != 0) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_p = rtb_Switch2_a;
    }

    if ((ICARO3_HAL_v1_P.resetonstartup1_Value > 0.0) &&
        (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om <= 0)) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_p = rtb_Switch2_a;
    }

    rtb_DiscreteTimeIntegrator_f =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_p;

    {
      rtb_Sum_fw = (ICARO3_HAL_v1_P.Internal_C)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_ah;
      rtb_Sum_fw += ICARO3_HAL_v1_P.Internal_D*rtb_DiscreteTimeIntegrator_f;
    }

    rtb_Switch2_oq = rtb_Sum_fw - rtb_h_data[1];
    rtb_Sum_fw = rtb_DiscreteTimeIntegrator_f - rtb_h_data[0];
    rtb_Switch2_g = rtb_Sum_fw * rtb_Gain1[1];
    rtb_Switch2 = (rtb_Switch2_oq * rtb_Gain1[2] + rtb_Sum_fw * rtb_Gain1[0]) +
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_am;
    rtb_Sum_fw = rtb_Switch2_a - rtb_DiscreteTimeIntegrator_f;
    if (rtb_Sum_fw > ICARO3_HAL_v1_P.Saturation1_UpperSat_h) {
      rtb_Switch2_og = ICARO3_HAL_v1_P.Saturation1_UpperSat_h;
    } else if (rtb_Sum_fw < ICARO3_HAL_v1_P.Saturation1_LowerSat_b) {
      rtb_Switch2_og = ICARO3_HAL_v1_P.Saturation1_LowerSat_b;
    } else {
      rtb_Switch2_og = rtb_Sum_fw;
    }

    if (rtb_Switch2 > ICARO3_HAL_v1_P.Saturation_UpperSat_j) {
      rtb_Switch2 = ICARO3_HAL_v1_P.Saturation_UpperSat_j;
    } else {
      if (rtb_Switch2 < ICARO3_HAL_v1_P.Saturation_LowerSat_n) {
        rtb_Switch2 = ICARO3_HAL_v1_P.Saturation_LowerSat_n;
      }
    }

    ICARO3_HAL_v1_B.Sum_l = 0.4 * ICARO3_HAL_v1_P.Nprop * ICARO3_HAL_v1_P.Fmax +
      rtb_Switch2;
    rtb_Divide1_j = ICARO3_HAL_v1_P.convert11to2020deginradians2_Gain *
      rtb_Switch2_ag * rtb_enable_motors_out;

    {
      rtb_Sum_fw = (ICARO3_HAL_v1_P.Internal_C_n)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_ax;
      rtb_Sum_fw += ICARO3_HAL_v1_P.Internal_D_l*rtb_Divide1_j;
    }

    rtb_Switch2_a = rtb_Sum_fw - rtb_h_calib[1];
    rtb_Sum_fw = rtb_Divide1_j - rtb_rpy[1];
    rtb_Switch2_ag = rtb_Sum_fw * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_k = (rtb_Switch2_a * rtb_Gain[2] + rtb_Sum_fw *
      rtb_Gain[0]) + ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_pq;
    rtb_Divide_b = ICARO3_HAL_v1_P.convert11to2020deginradians1_Gain *
      rtb_Switch_idx_1 * rtb_enable_motors_out;

    {
      rtb_Sum_fw = (ICARO3_HAL_v1_P.Internal_C_e)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_lk;
      rtb_Sum_fw += ICARO3_HAL_v1_P.Internal_D_m*rtb_Divide_b;
    }

    rtb_Switch2_oq = rtb_Sum_fw - rtb_h_calib[0];
    rtb_Sum_fw = rtb_Divide_b - rtb_rpy[0];
    rtb_Switch2 = rtb_Sum_fw * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_e = (rtb_Switch2_oq * rtb_Gain[2] + rtb_Sum_fw *
      rtb_Gain[0]) + ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_ap;
    rtb_Sum_fw = ICARO3_HAL_v1_P.yawvelgain_Gain * rtb_Switch_idx_3 -
      rtb_h_calib[2];
    rtb_Switch2_oq = rtb_Sum_fw * rtb_Gain[4];
    ICARO3_HAL_v1_B.Sum1_p = rtb_Sum_fw * rtb_Gain[3] +
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_g;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_in = ICARO3_HAL_v1_DWork.h_ref_j;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 += rtb_RateTransition2 *
      rtb_Switch2_d * ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_m;
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 >=
        ICARO3_HAL_v1_P.Hvario_x_max) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
        ICARO3_HAL_v1_P.Hvario_x_max;
    } else {
      if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 <=
          ICARO3_HAL_v1_P.Hvario_x_min) {
        ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
          ICARO3_HAL_v1_P.Hvario_x_min;
      }
    }

    if (rtb_RelationalOperator_d) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c0 = 1;
    } else {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c0 = 0;
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_am +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_a * rtb_Switch2_g;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_o = 0U;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_p +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_e * rtb_Switch2_og;
    if (ICARO3_HAL_v1_P.resetonstartup1_Value > 0.0) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = 1;
    } else if (ICARO3_HAL_v1_P.resetonstartup1_Value < 0.0) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = -1;
    } else if (ICARO3_HAL_v1_P.resetonstartup1_Value == 0.0) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = 0;
    } else {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = 2;
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_ah;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B*rtb_DiscreteTimeIntegrator_f;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_ah, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_pq +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_d * rtb_Switch2_ag;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_p*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_ax;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_j*rtb_Divide1_j;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_ax, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_ap +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_c * rtb_Switch2;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_l*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_lk;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_c*rtb_Divide_b;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_lk, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_g +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_i * rtb_Switch2_oq;
  } else {
    if (ICARO3_HAL_v1_DWork.AttitudeAltitudeController_MODE) {
      ICARO3_HAL_v1_B.Sum_l = ICARO3_HAL_v1_P.cmds_Y0[0];
      ICARO3_HAL_v1_B.Sum1_e = ICARO3_HAL_v1_P.cmds_Y0[1];
      ICARO3_HAL_v1_B.Sum1_k = ICARO3_HAL_v1_P.cmds_Y0[2];
      ICARO3_HAL_v1_B.Sum1_p = ICARO3_HAL_v1_P.cmds_Y0[3];
      ICARO3_HAL_v1_DWork.AttitudeAltitudeController_MODE = false;
    }
  }

  if (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller1_const) {
    if (!ICARO3_HAL_v1_DWork.AttitudeController_MODE) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_a =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_d;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_g = ICARO3_HAL_v1_P.Internal_X0_m;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_b =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_es;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_p = ICARO3_HAL_v1_P.Internal_X0_hd;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_o =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_nj;
      ICARO3_HAL_v1_DWork.AttitudeController_MODE = true;
    }

    rtb_Sum_ot = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_a;
    rtb_Divide1 = ICARO3_HAL_v1_P.convert11to2020deginradians2_Gain_f *
      rtb_refs_idx_2 * rtb_enable_motors_out;

    {
      rtb_DiscreteTimeIntegrator_fg = (ICARO3_HAL_v1_P.Internal_C_p)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_g;
      rtb_DiscreteTimeIntegrator_fg += ICARO3_HAL_v1_P.Internal_D_b*rtb_Divide1;
    }

    rtb_Switch2_oq = rtb_DiscreteTimeIntegrator_fg - rtb_h_calib[1];
    rtb_DiscreteTimeIntegrator_fg = rtb_Divide1 - rtb_rpy[1];
    rtb_Switch2_a = rtb_DiscreteTimeIntegrator_fg * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_d = (rtb_Switch2_oq * rtb_Gain[2] +
      rtb_DiscreteTimeIntegrator_fg * rtb_Gain[0]) + rtb_Sum_ot;
    rtb_DiscreteTimeIntegrator_fg =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_b;
    rtb_Divide_g = ICARO3_HAL_v1_P.convert11to2020deginradians1_Gain_n *
      rtb_refs_idx_1 * rtb_enable_motors_out;

    {
      rtb_Sum_ot = (ICARO3_HAL_v1_P.Internal_C_f)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_p;
      rtb_Sum_ot += ICARO3_HAL_v1_P.Internal_D_mk*rtb_Divide_g;
    }

    rtb_Switch2_oq = rtb_Sum_ot - rtb_h_calib[0];
    rtb_Sum_ot = rtb_Divide_g - rtb_rpy[0];
    rtb_Switch2 = rtb_Sum_ot * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_n1 = (rtb_Switch2_oq * rtb_Gain[2] + rtb_Sum_ot *
      rtb_Gain[0]) + rtb_DiscreteTimeIntegrator_fg;
    rtb_DiscreteTimeIntegrator_fg =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_o;
    rtb_Sum_ot = ICARO3_HAL_v1_P.yawvelgain_Gain_i * rtb_refs_idx_3 -
      rtb_h_calib[2];
    rtb_Switch2_oq = rtb_Sum_ot * rtb_Gain[4];
    ICARO3_HAL_v1_B.Sum1_l = rtb_Sum_ot * rtb_Gain[3] +
      rtb_DiscreteTimeIntegrator_fg;
    ICARO3_HAL_v1_B.gainonthrottledim = ICARO3_HAL_v1_P.Nprop *
      ICARO3_HAL_v1_P.Fmax * rtb_refs_idx_0;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_a +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_e * rtb_Switch2_a;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_e*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_g;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_k*rtb_Divide1;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_g, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_b +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_kw * rtb_Switch2;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_m*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_p;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_f*rtb_Divide_g;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_p, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_o +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_a * rtb_Switch2_oq;
  } else {
    if (ICARO3_HAL_v1_DWork.AttitudeController_MODE) {
      ICARO3_HAL_v1_B.gainonthrottledim = ICARO3_HAL_v1_P.cmds_Y0_h[0];
      ICARO3_HAL_v1_B.Sum1_n1 = ICARO3_HAL_v1_P.cmds_Y0_h[1];
      ICARO3_HAL_v1_B.Sum1_d = ICARO3_HAL_v1_P.cmds_Y0_h[2];
      ICARO3_HAL_v1_B.Sum1_l = ICARO3_HAL_v1_P.cmds_Y0_h[3];
      ICARO3_HAL_v1_DWork.AttitudeController_MODE = false;
    }
  }

  i_0 = ICARO3_HAL_v1_DWork.RateTransition1_ActiveBufIdx * 10;
  memcpy(&ICARO3_HAL_v1_B.RateTransition1_a[0],
         &ICARO3_HAL_v1_DWork.RateTransition1_Buffer[i_0], 10U * sizeof(real_T));
  rtb_Gain2_idx_0 = ICARO3_HAL_v1_P.SF_YAW_PID_GAINS[0] *
    ICARO3_HAL_v1_P.Constant7_Value_h[0] + ICARO3_HAL_v1_P.SF_YAW_PID_GAINS[2] *
    ICARO3_HAL_v1_P.Constant7_Value_h[1];
  rtb_Switch_idx_0 = ICARO3_HAL_v1_P.SF_YAW_PID_GAINS[1] *
    ICARO3_HAL_v1_P.Constant7_Value_h[0] + ICARO3_HAL_v1_P.SF_YAW_PID_GAINS[3] *
    ICARO3_HAL_v1_P.Constant7_Value_h[1];
  rtb_Switch2 = ICARO3_HAL_v1_B.Switch_o -
    ICARO3_HAL_v1_P.controllerseltoDPmodesel_Value;
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1) {
    ICARO3_HAL_v1_B.converttohifreqHz[0] =
      ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[0];
    ICARO3_HAL_v1_B.converttohifreqHz[1] =
      ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[1];
    ICARO3_HAL_v1_B.converttohifreqHz[2] =
      ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[2];
  }

  rtb_Gain3 = ICARO3_HAL_v1_P.Gain3_Gain_h * ICARO3_HAL_v1_B.RateTransition1_a[0];
  rtb_Gain4 = ICARO3_HAL_v1_P.Gain4_Gain_n * ICARO3_HAL_v1_B.RateTransition1_a[1];
  rtb_Gain5 = ICARO3_HAL_v1_P.Gain5_Gain_c * ICARO3_HAL_v1_P.Constant1_Value_mo;
  rtb_Gain6 = ICARO3_HAL_v1_P.Gain6_Gain_p * ICARO3_HAL_v1_P.Constant2_Value_ot;
  ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
    ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3, rtb_Gain4,
    &ICARO3_HAL_v1_B.sf_MATLABFunction6_m);
  rtb_Sum12 = ((((uint32_T)((rtb_DataTypeConversion2_a >=
    ICARO3_HAL_v1_P.CompareToConstant_const_p) && (rtb_refs_idx_0 >=
    ICARO3_HAL_v1_P.CompareToConstant1_const_l)) << 1) +
                ICARO3_HAL_v1_P.Constant1_Value_fi) << 1) +
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_g;
  rtb_Logic_d_idx_0 = ICARO3_HAL_v1_P.Logic_table_a[rtb_Sum12];
  rtb_Compare_l = ((ICARO3_HAL_v1_P.Logic_table_a[rtb_Sum12] &&
                    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_e) > (int32_T)
                   ICARO3_HAL_v1_P.detectpositivevalues_const);
  rtb_LogicalOperator_p = (rtb_Compare_l &&
    (!ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_ni));
  ICARO3_HAL_v1_latlonlatch(rtb_LogicalOperator_p,
    &ICARO3_HAL_v1_B.RateTransition1_a[0], &ICARO3_HAL_v1_B.latlonlatch);
  rtb_Gain3_g = ICARO3_HAL_v1_P.Gain3_Gain_hv * ICARO3_HAL_v1_B.latlonlatch.In1
    [0];
  rtb_Gain4_c = ICARO3_HAL_v1_P.Gain4_Gain_k * ICARO3_HAL_v1_B.latlonlatch.In1[1];
  rtb_Gain5_l = ICARO3_HAL_v1_P.Gain5_Gain_f *
    ICARO3_HAL_v1_P.Constant1_Value_h2;
  rtb_Gain6_p = ICARO3_HAL_v1_P.Gain6_Gain_g *
    ICARO3_HAL_v1_P.Constant2_Value_at;
  ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
    ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3_g, rtb_Gain4_c,
    &ICARO3_HAL_v1_B.sf_MATLABFunction6_k);
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_B.sf_MATLABFunction6_m.x -
    ICARO3_HAL_v1_B.sf_MATLABFunction6_k.x;
  rtb_Switch2_oq = rtb_DataTypeConversion2_a * rtb_DataTypeConversion2_a;
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_B.sf_MATLABFunction6_m.y -
    ICARO3_HAL_v1_B.sf_MATLABFunction6_k.y;
  rtb_DataTypeConversion2_a = (rtb_Switch2_oq + ICARO3_HAL_v1_P.avoid0dist_Value)
    + rtb_DataTypeConversion2_a * rtb_DataTypeConversion2_a;

  /* mode manager: */
  /* initially assign flag  */
  rtb_inside_RTH_circle = ICARO3_HAL_v1_DWork.storeinside_RTH_circleflag_DSTATE;
  if (rtb_Switch2 == 0.0) {
    /* HOVER */
    rtb_Switch2_oq = 0.0;
    rtb_Switch2 = 0.0;
    rtb_command_sel_out = 1;
    rtb_Switch2_a = 0.0;
    rtb_inside_RTH_circle = 0.0;

    /* reset flag  */
  } else if (rtb_Switch2 == 2.0) {
    /* waypoint mode */
    rtb_Switch2_oq = 2.0;
    rtb_Switch2 = 2.0;
    rtb_command_sel_out = 0;

    /* disable vario on waypoints for now */
    rtb_Switch2_a = 2.0;
    rtb_inside_RTH_circle = 0.0;

    /* reset flag  */
  } else {
    /* return to home and all other modes  */
    /* NOTE:  the output of this block is used */
    /*        by an enabled subsystem that is enabled with controller_sel ==3,4, or 5  */
    /*        thus mode =c_sel-3 = 0, 1 or 2 */
    rtb_Switch2_oq = 1.0;
    rtb_Switch2_a = 1.0;
    if (ICARO3_HAL_v1_DWork.storeinside_RTH_circleflag_DSTATE != 0.0) {
      rtb_Switch2 = 1.0;
      rtb_command_sel_out = 0;
    } else if (sqrt(rtb_DataTypeConversion2_a) < 10.0) {
      rtb_Switch2 = 1.0;
      rtb_inside_RTH_circle = 1.0;
      rtb_command_sel_out = 0;

      /*  disable vario when reference is 3 m above takeoff altitude */
    } else {
      rtb_Switch2 = 0.0;
      rtb_inside_RTH_circle = 0.0;
      rtb_command_sel_out = 1;
    }
  }

  /*  else */
  /*      %NOTE: this should not be necessary because the output of this block is used */
  /*      %       by an enabled subsystem that is enabled with controller_sel ==3,4, or 5  */
  /*      %       thus mode =c_sel-3 = 0, 1 or 2 */
  /*   */
  /*      %invalid use return to home data that must be valid */
  /*      LLsel = 1; */
  /*      if XY_dist_RTH < 10; */
  /*          Hsel=1; */
  /*      else  */
  /*          Hsel=0; */
  /*      end; */
  /*      Ysel=1; */
  /*      inside_RTH_circle=0; %reset flag  */
  /*  end; */
  rtb_Compare_gn = ((((ICARO3_HAL_v1_B.Switch_o ==
                       ICARO3_HAL_v1_P.CompareToConstant_const_g) &&
                      (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE !=
                       ICARO3_HAL_v1_P.CompareToConstant1_const_g)) ||
                     ((ICARO3_HAL_v1_B.Switch_o ==
                       ICARO3_HAL_v1_P.CompareToConstant2_const) &&
                      (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE !=
                       ICARO3_HAL_v1_P.CompareToConstant3_const))) > (int32_T)
                    ICARO3_HAL_v1_P.detectpositivevalues_const_d);
  rtb_LogicalOperator_o = (rtb_Compare_gn &&
    (!ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy1));
  ICARO3_HAL_v1_latlonlatch(rtb_LogicalOperator_o,
    &ICARO3_HAL_v1_B.RateTransition1_a[0], &ICARO3_HAL_v1_B.latlonlatch_j);
  switch ((int32_T)rtb_Switch2_oq) {
   case 0:
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.latlonlatch_j.In1[0];
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
      ICARO3_HAL_v1_B.latlonlatch_j.In1[1];
    break;

   case 1:
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.latlonlatch.In1[0];
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
      ICARO3_HAL_v1_B.latlonlatch.In1[1];
    break;

   default:
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.latlonlatch.In1[0];
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
      ICARO3_HAL_v1_B.latlonlatch.In1[1];
    break;
  }

  rtb_LogicalOperator3_k = (((ICARO3_HAL_v1_B.Switch_o ==
    ICARO3_HAL_v1_P.CompareToConstant_const_a) || (ICARO3_HAL_v1_B.Switch_o ==
    ICARO3_HAL_v1_P.CompareToConstant4_const) || (ICARO3_HAL_v1_B.Switch_o ==
    ICARO3_HAL_v1_P.CompareToConstant6_const)) &&
    ((ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c !=
      ICARO3_HAL_v1_P.CompareToConstant1_const_n) &&
     (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c !=
      ICARO3_HAL_v1_P.CompareToConstant5_const) &&
     (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c !=
      ICARO3_HAL_v1_P.CompareToConstant7_const)));
  rtb_Switch2_oq = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m;
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_o, rtb_h_data[0],
                       &ICARO3_HAL_v1_B.hlatch);
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_p, rtb_h_data[0],
                       &ICARO3_HAL_v1_B.hlatch_a);
  rtb_Sum_hd = ICARO3_HAL_v1_B.hlatch_a.In1 +
    ICARO3_HAL_v1_P.deltaHforreturntohome_Value;
  if (rtb_Switch2 == 0.0) {
    rtb_Sum_hd = ICARO3_HAL_v1_B.hlatch.In1;
  }

  rtb_RelationalOperator = (rtb_Switch2_oq != rtb_Sum_hd);
  if (rtb_RelationalOperator &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState <= 0)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_az;
  }

  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE >=
      ICARO3_HAL_v1_P.Hvario_x_max_o) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
      ICARO3_HAL_v1_P.Hvario_x_max_o;
  } else {
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE <=
        ICARO3_HAL_v1_P.Hvario_x_min_a) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
        ICARO3_HAL_v1_P.Hvario_x_min_a;
    }
  }

  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE;
  rtb_RateTransition2 = rtb_DataTypeConversion2_a + rtb_Sum_hd;
  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING != 0) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_a = rtb_RateTransition2;
  }

  if (rtb_LogicalOperator3_k &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c <= 0)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_a = rtb_RateTransition2;
  }

  rtb_ahrs_sel_out = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_a;
  rtb_Switch2_oq = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_b;
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_o, rtb_rpy[2],
                       &ICARO3_HAL_v1_B.yawlatch);
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_p, rtb_rpy[2],
                       &ICARO3_HAL_v1_B.yawlatch_g);
  switch ((int32_T)rtb_Switch2_a) {
   case 0:
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2 =
      ICARO3_HAL_v1_B.yawlatch.In1;
    break;

   case 1:
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2 =
      ICARO3_HAL_v1_B.yawlatch_g.In1;
    break;

   default:
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2 =
      ICARO3_HAL_v1_B.yawlatch_g.In1;
    break;
  }

  rtb_RelationalOperator_c = (rtb_Switch2_oq !=
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2);
  if (rtb_RelationalOperator_c &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_h <= 0)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_bu;
  }

  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k >=
      ICARO3_HAL_v1_P.Hvario_x_max_l) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
      ICARO3_HAL_v1_P.Hvario_x_max_l;
  } else {
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k <=
        ICARO3_HAL_v1_P.Hvario_x_min_h) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
        ICARO3_HAL_v1_P.Hvario_x_min_h;
    }
  }

  rtb_DataTypeConversion2_a =
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k;
  rtb_Sum_n = rtb_DataTypeConversion2_a +
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2;
  ICARO3_HAL_v1_MATLABFunction2(rtb_Sum_n, &ICARO3_HAL_v1_B.sf_MATLABFunction4,
    &ICARO3_HAL_v1_DWork.sf_MATLABFunction4);
  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_m != 0) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_e =
      ICARO3_HAL_v1_B.sf_MATLABFunction4.y;
  }

  if (rtb_LogicalOperator3_k &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_k <= 0)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_e =
      ICARO3_HAL_v1_B.sf_MATLABFunction4.y;
  }

  rtb_Switch2_d = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_e;
  if ((ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller3hover_const) ||
      (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller4RettoHome_const) ||
      (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller5waypoint_const)) {
    if (!ICARO3_HAL_v1_DWork.DPAltitudeController_MODE) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i3 =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_f;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_hw = ICARO3_HAL_v1_P.Internal_X0_j;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_j =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_l;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0] = ICARO3_HAL_v1_P.Internal_X0_dj;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_o[1] = ICARO3_HAL_v1_P.Internal_X0_dj;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_j = ICARO3_HAL_v1_P.Internal_X0_g;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_o =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_ah;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0] = ICARO3_HAL_v1_P.Internal_X0_da;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[1] = ICARO3_HAL_v1_P.Internal_X0_da;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_n = ICARO3_HAL_v1_P.Internal_X0_c;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_m =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_k;
      ICARO3_HAL_v1_MATLABFunction2_Init
        (&ICARO3_HAL_v1_DWork.sf_MATLABFunction2_l);
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_f =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_a;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_py =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_gs;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_l = ICARO3_HAL_v1_P.Internal_X0_l;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_lh = ICARO3_HAL_v1_P.Internal_X0_m0;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_hd = ICARO3_HAL_v1_P.Internal_X0_b;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_c =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_fe;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_a = ICARO3_HAL_v1_P.Internal_X0_e;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_m = ICARO3_HAL_v1_P.Internal_X0_o;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_nu = ICARO3_HAL_v1_P.Internal_X0_jq;
      ICARO3_HAL_v1_DWork.DPAltitudeController_MODE = true;
    }

    rtb_Internal_j = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i3;
    rtb_lat_lon_h_yaw_ref[0] = rtb_ManualSwitch3_a_idx_2;
    rtb_lat_lon_h_yaw_ref[1] =
      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1;
    rtb_lat_lon_h_yaw_ref[2] = rtb_ahrs_sel_out;
    rtb_lat_lon_h_yaw_ref[3] = rtb_Switch2_d;

    {
      rtb_Internal_p = (ICARO3_HAL_v1_P.Internal_C_m)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_hw;
      rtb_Internal_p += ICARO3_HAL_v1_P.Internal_D_h*rtb_lat_lon_h_yaw_ref[2];
    }

    rtb_Switch2_oq = rtb_Internal_p - rtb_h_data[1];
    rtb_Internal_p = rtb_h_data[0];
    rtb_Internal_l = rtb_lat_lon_h_yaw_ref[2] - rtb_Internal_p;
    rtb_Switch2_g = rtb_Internal_l * rtb_Gain1[1];
    rtb_Internal_j += rtb_Switch2_oq * rtb_Gain1[2] + rtb_Internal_l *
      rtb_Gain1[0];
    if (rtb_Internal_j > ICARO3_HAL_v1_P.Saturation_UpperSat_p) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_UpperSat_p;
    } else if (rtb_Internal_j < ICARO3_HAL_v1_P.Saturation_LowerSat_p) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_LowerSat_p;
    } else {
      rtb_ManualSwitch3_a_idx_2 = rtb_Internal_j;
    }

    ICARO3_HAL_v1_B.Sum_e = 0.5 * ICARO3_HAL_v1_P.Nprop * ICARO3_HAL_v1_P.Fmax +
      rtb_ManualSwitch3_a_idx_2;
    ICARO3_HAL_v1_B.Sum1_b = rtb_lat_lon_h_yaw_ref[2] - rtb_Internal_p;
    rtb_Internal_l = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_j;
    rtb_Internal_p = ICARO3_HAL_v1_P.convert11to2020deginradians1_Gain_l *
      rtb_refs_idx_2 * rtb_enable_motors_out;
    if (ICARO3_HAL_v1_P.ManualSwitch1_CurrentSetting != 1) {
      rtb_Internal_p = ICARO3_HAL_v1_P.Constant7_Value_e;
    }

    {
      rtb_Internal_j = (ICARO3_HAL_v1_P.Internal_C_j[0])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0]
        + (ICARO3_HAL_v1_P.Internal_C_j[1])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_o[1];
    }

    if (rtb_Internal_j > ICARO3_HAL_v1_P.Saturation_UpperSat_o) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_UpperSat_o;
    } else if (rtb_Internal_j < ICARO3_HAL_v1_P.Saturation_LowerSat_i) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_LowerSat_i;
    } else {
      rtb_ManualSwitch3_a_idx_2 = rtb_Internal_j;
    }

    rtb_Sum7 = ICARO3_HAL_v1_P.Gain_Gain_l * rtb_ManualSwitch3_a_idx_2 +
      rtb_Internal_p;

    {
      rtb_Internal_p = (ICARO3_HAL_v1_P.Internal_C_jf)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_j;
      rtb_Internal_p += ICARO3_HAL_v1_P.Internal_D_i*rtb_Sum7;
    }

    rtb_Switch2_oq = rtb_Internal_p - rtb_h_calib[1];
    rtb_Internal_p = rtb_Sum7 - rtb_rpy[1];
    rtb_Switch2_og = rtb_Internal_p * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_h = (rtb_Switch2_oq * rtb_Gain[2] + rtb_Internal_p *
      rtb_Gain[0]) + rtb_Internal_l;
    rtb_Internal_l = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_o;
    rtb_Internal_p = ICARO3_HAL_v1_P.convert11to2020deginradians_Gain *
      rtb_refs_idx_1 * rtb_enable_motors_out;
    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_f != 1) {
      rtb_Internal_p = ICARO3_HAL_v1_P.Constant7_Value_e;
    }

    {
      rtb_Internal_j = (ICARO3_HAL_v1_P.Internal_C_jq[0])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0]
        + (ICARO3_HAL_v1_P.Internal_C_jq[1])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[1];
    }

    if (rtb_Internal_j > ICARO3_HAL_v1_P.Saturation1_UpperSat_c) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation1_UpperSat_c;
    } else if (rtb_Internal_j < ICARO3_HAL_v1_P.Saturation1_LowerSat_d) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation1_LowerSat_d;
    } else {
      rtb_ManualSwitch3_a_idx_2 = rtb_Internal_j;
    }

    rtb_Sum6 = ICARO3_HAL_v1_P.Gain1_Gain * rtb_ManualSwitch3_a_idx_2 +
      rtb_Internal_p;

    {
      rtb_Internal_p = (ICARO3_HAL_v1_P.Internal_C_ed)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_n;
      rtb_Internal_p += ICARO3_HAL_v1_P.Internal_D_a*rtb_Sum6;
    }

    rtb_Switch2_oq = rtb_Internal_p - rtb_h_calib[0];
    rtb_Internal_p = rtb_Sum6 - rtb_rpy[0];
    rtb_Switch2_ag = rtb_Internal_p * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_i = (rtb_Switch2_oq * rtb_Gain[2] + rtb_Internal_p *
      rtb_Gain[0]) + rtb_Internal_l;
    rtb_Internal_l = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_m;
    ICARO3_HAL_v1_MATLABFunction2(rtb_rpy[2],
      &ICARO3_HAL_v1_B.sf_MATLABFunction2_l,
      &ICARO3_HAL_v1_DWork.sf_MATLABFunction2_l);
    rtb_Internal_p = rtb_lat_lon_h_yaw_ref[3] -
      ICARO3_HAL_v1_B.sf_MATLABFunction2_l.y;
    rtb_Switch2_oq = rt_modd_snf(rtb_Internal_p,
      ICARO3_HAL_v1_P.Constant1_Value_f);
    if (rtb_Switch2_oq > ICARO3_HAL_v1_P.Switch_Threshold) {
      rtb_Internal_p = rtb_Switch2_oq - ICARO3_HAL_v1_P.Constant2_Value_b;
    } else {
      rtb_Internal_p = rtb_Switch2_oq;
    }

    rtb_Internal_j = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_f;
    rtb_Internal_j = (rtb_Internal_p * rtb_Gain2_idx_0 + rtb_Internal_j) -
      rtb_h_calib[2];
    rtb_Switch2 = rtb_Internal_j * rtb_Gain[4];
    ICARO3_HAL_v1_B.Sum1_fr = rtb_Internal_j * rtb_Gain[3] + rtb_Internal_l;
    rtb_Gain3_ef = ICARO3_HAL_v1_P.Gain3_Gain *
      ICARO3_HAL_v1_B.RateTransition1_a[0];
    rtb_Gain4_i = ICARO3_HAL_v1_P.Gain4_Gain *
      ICARO3_HAL_v1_B.RateTransition1_a[1];
    rtb_Gain5_g = ICARO3_HAL_v1_P.Gain5_Gain * ICARO3_HAL_v1_P.Constant1_Value_a;
    rtb_Gain6_d = ICARO3_HAL_v1_P.Gain6_Gain * ICARO3_HAL_v1_P.Constant2_Value_p;
    ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
      ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3_ef, rtb_Gain4_i,
      &ICARO3_HAL_v1_B.sf_MATLABFunction6_hx);
    ICARO3_HAL_v1_MATLABFunction1(ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.x,
      ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.y, rtb_rpy,
      &ICARO3_HAL_v1_B.sf_MATLABFunction1_i);
    rtb_Gain3_ce = ICARO3_HAL_v1_P.Gain3_Gain_c * rtb_lat_lon_h_yaw_ref[0];
    rtb_Gain4_f = ICARO3_HAL_v1_P.Gain4_Gain_d * rtb_lat_lon_h_yaw_ref[1];
    rtb_Gain5_f = ICARO3_HAL_v1_P.Gain5_Gain_e *
      ICARO3_HAL_v1_P.Constant1_Value_k;
    rtb_Gain6_b = ICARO3_HAL_v1_P.Gain6_Gain_h *
      ICARO3_HAL_v1_P.Constant2_Value_a;
    ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
      ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3_ce, rtb_Gain4_f,
      &ICARO3_HAL_v1_B.sf_MATLABFunction6_au);
    ICARO3_HAL_v1_MATLABFunction1(ICARO3_HAL_v1_B.sf_MATLABFunction6_au.x,
      ICARO3_HAL_v1_B.sf_MATLABFunction6_au.y, rtb_rpy,
      &ICARO3_HAL_v1_B.sf_MATLABFunction3_j);
    rtb_Switch2_a = rtb_Internal_p * rtb_Switch_idx_0;
    rtb_Internal_l = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_py;

    {
      rtb_Internal_p = (ICARO3_HAL_v1_P.Internal_C_pe)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_l;
      rtb_Internal_p += ICARO3_HAL_v1_P.Internal_D_f*
        ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0];
    }

    {
      rtb_Internal_j = (ICARO3_HAL_v1_P.Internal_C_ec)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_lh;
      rtb_Internal_j += ICARO3_HAL_v1_P.Internal_D_bn*
        ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0];
    }

    rtb_Sum2_p = ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0] -
      ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0];

    {
      rtb_Sum1_mw = (ICARO3_HAL_v1_P.Internal_C_l)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_hd;
      rtb_Sum1_mw += ICARO3_HAL_v1_P.Internal_D_k*rtb_Sum2_p;
    }

    rtb_Internal_l += (rtb_Internal_p - rtb_Internal_j) *
      ICARO3_HAL_v1_P.Constant1_Value_pj + rtb_Sum2_p *
      ICARO3_HAL_v1_P.Constant8_Value;
    if (ICARO3_HAL_v1_P.selectOLDvsNEWcontroller_CurrentSetting == 1) {
      rtb_selectOLDvsNEWcontroller = rtb_Internal_l;
    } else {
      rtb_selectOLDvsNEWcontroller = rtb_Sum1_mw;
    }

    rtb_Sum1_mw = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_c;

    {
      rtb_Internal_l = (ICARO3_HAL_v1_P.Internal_C_d)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_a;
      rtb_Internal_l += ICARO3_HAL_v1_P.Internal_D_n*
        ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1];
    }

    {
      rtb_Internal_p = (ICARO3_HAL_v1_P.Internal_C_mr)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_m;
      rtb_Internal_p += ICARO3_HAL_v1_P.Internal_D_px*
        ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1];
    }

    rtb_Sum2_l = ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1] -
      ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1];

    {
      rtb_Internal_j = (ICARO3_HAL_v1_P.Internal_C_mj)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_nu;
      rtb_Internal_j += ICARO3_HAL_v1_P.Internal_D_kc*rtb_Sum2_l;
    }

    rtb_Sum1_mw += (rtb_Internal_l - rtb_Internal_p) *
      ICARO3_HAL_v1_P.Constant4_Value + rtb_Sum2_l *
      ICARO3_HAL_v1_P.Constant8_Value;
    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_fr == 1) {
      rtb_ManualSwitch_h = rtb_Sum1_mw;
    } else {
      rtb_ManualSwitch_h = rtb_Internal_j;
    }

    ICARO3_HAL_v1_B.Sum1_n = rtb_lat_lon_h_yaw_ref[3] -
      ICARO3_HAL_v1_B.sf_MATLABFunction2_l.y;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i3 +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_j * rtb_Switch2_g;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_i*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_hw;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_n*rtb_lat_lon_h_yaw_ref[2];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_hw, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_j +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_i * rtb_Switch2_og;

    {
      real_T xnew[2];
      xnew[0] = (ICARO3_HAL_v1_P.Internal_A_pz[0])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0]
        + (ICARO3_HAL_v1_P.Internal_A_pz[1])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_o[1];
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_g*rtb_selectOLDvsNEWcontroller;
      xnew[1] = (ICARO3_HAL_v1_P.Internal_A_pz[2])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0], xnew,
                    sizeof(real_T)*2);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_a*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_j;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_l*rtb_Sum7;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_j, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_o +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_b * rtb_Switch2_ag;

    {
      real_T xnew[2];
      xnew[0] = (ICARO3_HAL_v1_P.Internal_A_k[0])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0]
        + (ICARO3_HAL_v1_P.Internal_A_k[1])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[1];
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_i*rtb_ManualSwitch_h;
      xnew[1] = (ICARO3_HAL_v1_P.Internal_A_k[2])*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0], xnew,
                    sizeof(real_T)*2);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_f*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_n;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_b*rtb_Sum6;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_n, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_m +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_mc * rtb_Switch2;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_f +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_c * rtb_Switch2_a;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_py += rtb_Sum2_p *
      ICARO3_HAL_v1_P.Constant_Value_k *
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_j4;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_g*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_l;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_m*
        ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_l, xnew,
                    sizeof(real_T)*1);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_fc*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_lh;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_fu*
        ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_lh, xnew,
                    sizeof(real_T)*1);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_n*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_hd;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_cv*rtb_Sum2_p;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_hd, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_c += rtb_Sum2_l *
      ICARO3_HAL_v1_P.Constant3_Value_p *
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_cf;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_id*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_a;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_ff*
        ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_a, xnew,
                    sizeof(real_T)*1);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_kc*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_m;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_d*
        ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1];
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_m, xnew,
                    sizeof(real_T)*1);
    }

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_o*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_nu;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_kr*rtb_Sum2_l;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_nu, xnew,
                    sizeof(real_T)*1);
    }
  } else {
    if (ICARO3_HAL_v1_DWork.DPAltitudeController_MODE) {
      ICARO3_HAL_v1_B.Sum_e = ICARO3_HAL_v1_P.cmds_Y0_a[0];
      ICARO3_HAL_v1_B.Sum1_i = ICARO3_HAL_v1_P.cmds_Y0_a[1];
      ICARO3_HAL_v1_B.Sum1_h = ICARO3_HAL_v1_P.cmds_Y0_a[2];
      ICARO3_HAL_v1_B.Sum1_fr = ICARO3_HAL_v1_P.cmds_Y0_a[3];
      ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0] =
        ICARO3_HAL_v1_P.ctrl_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0] =
        ICARO3_HAL_v1_P.ctrl_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1] =
        ICARO3_HAL_v1_P.ctrl_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1] =
        ICARO3_HAL_v1_P.ctrl_data_body_Y0;
      ICARO3_HAL_v1_B.Sum1_n = ICARO3_HAL_v1_P.ctrl_data_earth_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction2_l.y =
        ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_B.Sum1_b = ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.x =
        ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.y =
        ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction6_au.x =
        ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_B.sf_MATLABFunction6_au.y =
        ICARO3_HAL_v1_P.debug_data_body_Y0;
      ICARO3_HAL_v1_DWork.DPAltitudeController_MODE = false;
    }
  }

  rtb_DataTypeConversion_j = (ICARO3_HAL_v1_B.Switch_o ==
    ICARO3_HAL_v1_P.CompareToConstant_const_e);
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_3) {
    ICARO3_HAL_v1_B.ZeroOrderHold3[0] = ICARO3_HAL_v1_B.converttohifreqHz[0];
    ICARO3_HAL_v1_B.ZeroOrderHold3[1] = ICARO3_HAL_v1_B.converttohifreqHz[1];
    ICARO3_HAL_v1_B.ZeroOrderHold3[2] = ICARO3_HAL_v1_B.converttohifreqHz[2];
    memcpy(&ICARO3_HAL_v1_B.ZeroOrderHold1[0],
           &ICARO3_HAL_v1_B.RateTransition1_a[0], 10U * sizeof(real_T));
    ICARO3_HAL_v1_B.RateTransition2 = rtb_rpy[2];
  }

  /*  Pitch for long distance guidance (deg) */
  /*  Pitch for short distance guidance (deg) */
  /*  Guidance Sample Time */
  /*  Variation of pitch: deg/sec */
  if (!ICARO3_HAL_v1_DWork.pitch_not_empty) {
    ICARO3_HAL_v1_DWork.pitch = (1.0 - 0.0) * 10.0 + 0.0 * 20.0;
    ICARO3_HAL_v1_DWork.pitch_not_empty = true;
  }

  if (!ICARO3_HAL_v1_DWork.prec_r_not_empty) {
    ICARO3_HAL_v1_DWork.prec_r = 0.0;
    ICARO3_HAL_v1_DWork.prec_r_not_empty = true;
  }

  if ((0.0 == 1.0) && (ICARO3_HAL_v1_DWork.prec_r < 0.001)) {
    ICARO3_HAL_v1_DWork.en_short2long = 1.0;
  }

  if (ICARO3_HAL_v1_DWork.en_short2long != 0.0) {
    ICARO3_HAL_v1_DWork.pitch += 0.2;
    if (ICARO3_HAL_v1_DWork.pitch >= 20.0) {
      ICARO3_HAL_v1_DWork.en_short2long = 0.0;
    }
  } else {
    ICARO3_HAL_v1_DWork.pitch = (1.0 - 0.0) * 10.0 + 0.0 * 20.0;
  }

  ICARO3_HAL_v1_DWork.prec_r = 0.0;
  if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_ei == 1) {
    rtb_Switch2 = -ICARO3_HAL_v1_DWork.pitch;
  } else {
    rtb_Switch2 = ICARO3_HAL_v1_P.Pitch_ref_Value;
  }

  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_3) {
    ICARO3_HAL_v1_B.ZeroOrderHold2 = ICARO3_HAL_v1_B.Switch_o;
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_B.RateTransition1_ay[i] =
        ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[i];
    }

    ICARO3_HAL_v1_B.RateTransition4 =
      ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_d;
  }

  if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_en == 1) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant6_Value_k;
  } else {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant7_Value_ic;
  }

  rtb_Switch2_oq = rtb_DataTypeConversion2_a * (real_T)rtb_command_sel_out;
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Gain_Gain_f1 * rtb_refs_idx_0 -
    ICARO3_HAL_v1_P.Constant1_Value_aw;
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation1_UpperSat_b) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation1_UpperSat_b;
  } else {
    if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation1_LowerSat_g) {
      rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation1_LowerSat_g;
    }
  }

  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Hvario_x_dead_zone_l) {
    rtb_DataTypeConversion2_a -= ICARO3_HAL_v1_P.Hvario_x_dead_zone_l;
  } else if (rtb_DataTypeConversion2_a >= -ICARO3_HAL_v1_P.Hvario_x_dead_zone_l)
  {
    rtb_DataTypeConversion2_a = 0.0;
  } else {
    rtb_DataTypeConversion2_a -= -ICARO3_HAL_v1_P.Hvario_x_dead_zone_l;
  }

  rtb_DataTypeConversion2_a *= 1.0 / (1.0 - ICARO3_HAL_v1_P.Hvario_x_dead_zone_l);
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation_UpperSat_az) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation_UpperSat_az;
  } else {
    if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation_LowerSat_k) {
      rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation_LowerSat_k;
    }
  }

  rtb_Divide_e = rtb_DataTypeConversion2_a * rtb_Switch2_oq;
  rtb_DataTypeConversion2_a = rtb_RateTransition2 - rtb_ahrs_sel_out;
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation1_UpperSat_g) {
    rtb_Gain2_idx_0 = ICARO3_HAL_v1_P.Saturation1_UpperSat_g;
  } else if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation1_LowerSat_l)
  {
    rtb_Gain2_idx_0 = ICARO3_HAL_v1_P.Saturation1_LowerSat_l;
  } else {
    rtb_Gain2_idx_0 = rtb_DataTypeConversion2_a;
  }

  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_B.sf_MATLABFunction4.y -
    rtb_Switch2_d;
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation1_UpperSat_o) {
    rtb_RateTransition2 = ICARO3_HAL_v1_P.Saturation1_UpperSat_o;
  } else if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation1_LowerSat_gp)
  {
    rtb_RateTransition2 = ICARO3_HAL_v1_P.Saturation1_LowerSat_gp;
  } else {
    rtb_RateTransition2 = rtb_DataTypeConversion2_a;
  }

  if (rtb_refs_idx_3 > ICARO3_HAL_v1_P.Saturation1_UpperSat_k) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation1_UpperSat_k;
  } else if (rtb_refs_idx_3 < ICARO3_HAL_v1_P.Saturation1_LowerSat_f) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation1_LowerSat_f;
  } else {
    rtb_DataTypeConversion2_a = rtb_refs_idx_3;
  }

  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Hvario_x_dead_zone_n) {
    rtb_DataTypeConversion2_a -= ICARO3_HAL_v1_P.Hvario_x_dead_zone_n;
  } else if (rtb_DataTypeConversion2_a >= -ICARO3_HAL_v1_P.Hvario_x_dead_zone_n)
  {
    rtb_DataTypeConversion2_a = 0.0;
  } else {
    rtb_DataTypeConversion2_a -= -ICARO3_HAL_v1_P.Hvario_x_dead_zone_n;
  }

  rtb_DataTypeConversion2_a *= 1.0 / (1.0 - ICARO3_HAL_v1_P.Hvario_x_dead_zone_n);
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation_UpperSat_i) {
    rtb_Switch2_oq = ICARO3_HAL_v1_P.Saturation_UpperSat_i;
  } else if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation_LowerSat_f)
  {
    rtb_Switch2_oq = ICARO3_HAL_v1_P.Saturation_LowerSat_f;
  } else {
    rtb_Switch2_oq = rtb_DataTypeConversion2_a;
  }

  if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_p == 1) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant6_Value_d;
  } else {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Constant7_Value_ik;
  }

  rtb_enable_motors_out = rtb_Switch2_oq * rtb_DataTypeConversion2_a;
  rtb_ManualSwitch_b[0] = ICARO3_HAL_v1_B.Sum1_b;
  rtb_ManualSwitch_b[1] = ICARO3_HAL_v1_B.Sum1_n;
  if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_m == 1) {
    rtb_ManualSwitch_b[2] = ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0];
    rtb_ManualSwitch_b[3] = ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0];
    rtb_ManualSwitch_b[4] = ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1];
    rtb_ManualSwitch_b[5] = ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1];
  } else {
    rtb_ManualSwitch_b[2] = ICARO3_HAL_v1_B.sf_MATLABFunction6_au.x;
    rtb_ManualSwitch_b[3] = ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.x;
    rtb_ManualSwitch_b[4] = ICARO3_HAL_v1_B.sf_MATLABFunction6_au.y;
    rtb_ManualSwitch_b[5] = ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.y;
  }

  if (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.manual_const) {
    if (!ICARO3_HAL_v1_DWork.Off_MODE) {
      ICARO3_HAL_v1_DWork.Off_MODE = true;
    }

    ICARO3_HAL_v1_B.Constant = ICARO3_HAL_v1_P.Constant_Value_j;
    ICARO3_HAL_v1_B.Constant1 = ICARO3_HAL_v1_P.Constant1_Value_db;
    ICARO3_HAL_v1_B.Constant2 = ICARO3_HAL_v1_P.Constant2_Value_g;
    if (ICARO3_HAL_v1_P.dontuseusemotorswhencontrollerisnotactivated_CurrentSetting
        == 1) {
      ICARO3_HAL_v1_B.dontuseusemotorswhencontrollerisnotactivated =
        ICARO3_HAL_v1_P.Constant3_Value_g;
    } else {
      ICARO3_HAL_v1_B.dontuseusemotorswhencontrollerisnotactivated =
        ICARO3_HAL_v1_P.Nprop * ICARO3_HAL_v1_P.Fmax * rtb_refs_idx_0;
    }
  } else {
    if (ICARO3_HAL_v1_DWork.Off_MODE) {
      ICARO3_HAL_v1_B.dontuseusemotorswhencontrollerisnotactivated =
        ICARO3_HAL_v1_P.cmds_Y0_hv[0];
      ICARO3_HAL_v1_B.Constant = ICARO3_HAL_v1_P.cmds_Y0_hv[1];
      ICARO3_HAL_v1_B.Constant1 = ICARO3_HAL_v1_P.cmds_Y0_hv[2];
      ICARO3_HAL_v1_B.Constant2 = ICARO3_HAL_v1_P.cmds_Y0_hv[3];
      ICARO3_HAL_v1_DWork.Off_MODE = false;
    }
  }

  if (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.controller6fuzzyguidance_const)
  {
    if (!ICARO3_HAL_v1_DWork.fuzzyguidanceController_MODE) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_o;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_i = ICARO3_HAL_v1_P.Internal_X0_i;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_p =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_aq;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_f = ICARO3_HAL_v1_P.Internal_X0_ib;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_k =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_og;
      ICARO3_HAL_v1_DWork.Internal_DSTATE_i5 = ICARO3_HAL_v1_P.Internal_X0_g5;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_iq =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_b;
      ICARO3_HAL_v1_MATLABFunction2_Init
        (&ICARO3_HAL_v1_DWork.sf_MATLABFunction2_j);
      ICARO3_HAL_v1_DWork.Internal_DSTATE_b = ICARO3_HAL_v1_P.Internal_X0_oi;
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i =
        ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_aw;
      ICARO3_HAL_v1_DWork.fuzzyguidanceController_MODE = true;
    }

    rtb_Sum_h1 = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE;

    {
      rtb_Sum1_my = (ICARO3_HAL_v1_P.Internal_C_pu)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_i;
      rtb_Sum1_my += ICARO3_HAL_v1_P.Internal_D_g*ICARO3_HAL_v1_P.h_ref;
    }

    rtb_Switch2_oq = rtb_Sum1_my - rtb_h_data[1];
    rtb_Sum1_my = ICARO3_HAL_v1_P.h_ref - rtb_h_data[0];
    rtb_Switch2_og = rtb_Sum1_my * rtb_Gain1[1];
    rtb_Sum_h1 += rtb_Switch2_oq * rtb_Gain1[2] + rtb_Sum1_my * rtb_Gain1[0];
    if (rtb_Sum_h1 > ICARO3_HAL_v1_P.Saturation_UpperSat_a) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_UpperSat_a;
    } else if (rtb_Sum_h1 < ICARO3_HAL_v1_P.Saturation_LowerSat_g) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Saturation_LowerSat_g;
    } else {
      rtb_ManualSwitch3_a_idx_2 = rtb_Sum_h1;
    }

    ICARO3_HAL_v1_B.Sum = 0.4 * ICARO3_HAL_v1_P.Nprop * ICARO3_HAL_v1_P.Fmax +
      rtb_ManualSwitch3_a_idx_2;
    rtb_Sum1_my = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_p;
    rtb_convert11to2020deginradians2 =
      ICARO3_HAL_v1_P.convert11to2020deginradians2_Gain_o * rtb_Switch2;

    {
      rtb_Sum_h1 = (ICARO3_HAL_v1_P.Internal_C_nc)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_f;
      rtb_Sum_h1 += ICARO3_HAL_v1_P.Internal_D_n3*
        rtb_convert11to2020deginradians2;
    }

    rtb_Switch2_oq = rtb_Sum_h1 - rtb_h_calib[1];
    rtb_Sum_h1 = rtb_convert11to2020deginradians2 - rtb_rpy[1];
    rtb_Switch2_ag = rtb_Sum_h1 * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1 = (rtb_Switch2_oq * rtb_Gain[2] + rtb_Sum_h1 *
      rtb_Gain[0]) + rtb_Sum1_my;
    rtb_Sum1_my = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_k;
    rtb_convert11to2020deginradians1 =
      ICARO3_HAL_v1_P.convert11to2020deginradians1_Gain_m *
      ICARO3_HAL_v1_P.Fr_ref_Value[1];

    {
      rtb_Sum_h1 = (ICARO3_HAL_v1_P.Internal_C_nf)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_i5;
      rtb_Sum_h1 += ICARO3_HAL_v1_P.Internal_D_fj*
        rtb_convert11to2020deginradians1;
    }

    rtb_Switch2 = rtb_Sum_h1 - rtb_h_calib[0];
    rtb_Sum_h1 = rtb_convert11to2020deginradians1 - rtb_rpy[0];
    rtb_Switch2_oq = rtb_Sum_h1 * rtb_Gain[1];
    ICARO3_HAL_v1_B.Sum1_f = (rtb_Switch2 * rtb_Gain[2] + rtb_Sum_h1 * rtb_Gain
      [0]) + rtb_Sum1_my;
    rtb_Sum1_my = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_iq;
    rtb_Sum_h1 = ICARO3_HAL_v1_P.yawvelgain_Gain_e *
      ICARO3_HAL_v1_B.RateTransition4;
    rtb_Gain_m = ICARO3_HAL_v1_P.Gain_Gain_n * rtb_Sum_h1;
    ICARO3_HAL_v1_MATLABFunction2(rtb_rpy[2],
      &ICARO3_HAL_v1_B.sf_MATLABFunction2_j,
      &ICARO3_HAL_v1_DWork.sf_MATLABFunction2_j);
    rtb_Sum_h1 -= rtb_h_calib[2];
    rtb_Sum1_my += rtb_Sum_h1 * rtb_Gain[3];

    {
      rtb_Switch_ck = (ICARO3_HAL_v1_P.Internal_C_i)*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_b;
      rtb_Switch_ck += ICARO3_HAL_v1_P.Internal_D_in*rtb_Gain_m;
    }

    rtb_Switch2 = (rtb_Switch_ck - rtb_h_calib[2]) *
      ICARO3_HAL_v1_P.yaw_gains_Value[2];
    rtb_Switch_ck = rtb_Gain_m - ICARO3_HAL_v1_B.sf_MATLABFunction2_j.y;
    rtb_Switch2_a = rt_modd_snf(rtb_Switch_ck,
      ICARO3_HAL_v1_P.Constant1_Value_d4);
    if (rtb_Switch2_a > ICARO3_HAL_v1_P.Switch_Threshold_f) {
      rtb_Switch_ck = rtb_Switch2_a - ICARO3_HAL_v1_P.Constant2_Value_n;
    } else {
      rtb_Switch_ck = rtb_Switch2_a;
    }

    if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_e == 1) {
      ICARO3_HAL_v1_B.ManualSwitch = rtb_Sum1_my;
    } else {
      ICARO3_HAL_v1_B.ManualSwitch = (rtb_Switch_ck *
        ICARO3_HAL_v1_P.yaw_gains_Value[0] + rtb_Switch2) +
        ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i;
    }

    rtb_Switch2 = rtb_Switch_ck * ICARO3_HAL_v1_P.yaw_gains_Value[1];
    rtb_Switch2_a = rtb_Sum_h1 * rtb_Gain[4];
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_m * rtb_Switch2_og;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_i0*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_i;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_a*ICARO3_HAL_v1_P.h_ref;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_i, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_p +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_g * rtb_Switch2_ag;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_kt*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_f;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_j4*rtb_convert11to2020deginradians2;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_f, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_k +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_bs * rtb_Switch2_oq;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_if*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_i5;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_lx*rtb_convert11to2020deginradians1;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_i5, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_iq +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_n * rtb_Switch2_a;

    {
      real_T xnew[1];
      xnew[0] = ICARO3_HAL_v1_P.Internal_A_m2*
        ICARO3_HAL_v1_DWork.Internal_DSTATE_b;
      xnew[0] += ICARO3_HAL_v1_P.Internal_B_p*rtb_Gain_m;
      (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_b, xnew,
                    sizeof(real_T)*1);
    }

    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i +=
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_gainval_l * rtb_Switch2;
  } else {
    if (ICARO3_HAL_v1_DWork.fuzzyguidanceController_MODE) {
      ICARO3_HAL_v1_DWork.fuzzyguidanceController_MODE = false;
    }
  }

  switch ((int32_T)ICARO3_HAL_v1_B.Switch_o) {
   case 0:
    rtb_refs_idx_0 =
      ICARO3_HAL_v1_B.dontuseusemotorswhencontrollerisnotactivated;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Constant;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Constant1;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Constant2;
    break;

   case 1:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.gainonthrottledim;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_n1;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_d;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_l;
    break;

   case 2:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum_l;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_e;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_k;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_p;
    break;

   case 3:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum_e;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_i;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_h;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_fr;
    break;

   case 4:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum_e;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_i;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_h;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_fr;
    break;

   case 5:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum_e;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_i;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_h;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_fr;
    break;

   case 6:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_f;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.ManualSwitch;
    break;

   default:
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Sum_l;
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Sum1_e;
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Sum1_k;
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Sum1_p;
    break;
  }

  rtb_Compare_pc = (ICARO3_HAL_v1_B.Switch_o == ICARO3_HAL_v1_P.WAYP_MODE);
  rtb_LogicalOperator_n = (rtb_Compare_pc &&
    (ICARO3_HAL_v1_DWork.delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt
     != 0.0));
  rtb_Gain3_e = ICARO3_HAL_v1_P.Gain3_Gain_o *
    ICARO3_HAL_v1_B.RateTransition1_a[0];
  rtb_Gain4_k = ICARO3_HAL_v1_P.Gain4_Gain_f *
    ICARO3_HAL_v1_B.RateTransition1_a[1];
  rtb_Gain5_o = ICARO3_HAL_v1_P.Gain5_Gain_a *
    ICARO3_HAL_v1_P.Constant1_Value_ok;
  rtb_Gain6_ov = ICARO3_HAL_v1_P.Gain6_Gain_c *
    ICARO3_HAL_v1_P.Constant2_Value_an;
  ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
    ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3_e, rtb_Gain4_k,
    &ICARO3_HAL_v1_B.sf_MATLABFunction6_l);/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

  /*  Function for update database on vehicle. Input data can be :           %    */
  /*           - Waypoint data (new_mission, add_wp, change_wp)              % */
  /*           - Cmd request (reset_database, delete_wp, request_wp)         % */
  /*                                                                         %        */
  /*  The outputs of this function are the data for the control system and   % */
  /*  a response for groundStation.                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Struct of PCK_WAYP (base version)                                  % */
  /*                                                                     %    */
  /*     1   2    3    4    5   6                                        %          */
  /*  |sync|lat|long|alti|id_wp|N|                                       % */
  /*                                                                     % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Struct of PCK_WAYP_EXT (extended version)                          % */
  /*                                                                     %              */
  /*     1   2    3   4     5   6   7     8                              %          */
  /*  |sync|lat|long|alti|id_wp|N|head|act_cmd|                          % */
  /*                                                                     % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Struct of PCK_WAYP_CMD                                             % */
  /*                                                                     %    */
  /*     1    2      3                                                   %          */
  /*  |sync|RES/N|0/ID|                                                  % */
  /*                                                                     % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Struct of PCK_WAYP_ACK                                             % */
  /*                                                                     %    */
  /*     1    2   3                                                      %          */
  /*  |sync|CODE|ID|                                                     % */
  /*                                                                     % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Ack value mean                                                     % */
  /*            ack == 0  NULL                                           % */
  /*                                                                     % */
  /*            ack == 1  WAYP_OK                                        % */
  /*            ack == -1 WAYP_NOK                                       % */
  /*                                                                     % */
  /*            ack == 2  CMD_RES_OK                                     % */
  /*            ack == -2 CMD_RES_NOK                                    % */
  /*                                                                     % */
  /*            ack == 3  CMD_DEL_OK                                     %    */
  /*            ack == -3 CMD_DEL_NOK                                    % */
  /*                                                                     %   */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Flag to signal how modify have been made to the   % */
  /*  current mission. For memory efficiency, is used   % */
  /*  the WP_DB_tmp for this scope. The field of        % */
  /*  WP_DB_tmp used are the following :                % */
  /*                                                    % */
  /*    WP_DB_tmp(1,3) = -70000 -> reset WP_DB_tmp      % */
  /*    WP_DB_tmp(1,4) -> OP_code of current mission    % */
  /*    WP_DB_tmp(1,5) -> Num of wayp changed/removed   % */
  /*    WP_DB_tmp(1,6) -> IDs of wayp changed/removed   % */
  /*                                                    %     */
  /*    OP_code = 0  -> NULL                            % */
  /*    OP_Code = -1 -> RESET ACT_WP variable           % */
  /*    OP_Code = -2 -> CHANGED SOME WAYP               % */
  /*    OP_Code = -3 -> REMOVED SOME WAYP               % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  reset the outputs of block. In particular the data for % */
  /*  control system and the data to send to basestation.    % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  wayp_sync_cs = 0;
  send_sync = 0;
  for (i = 0; i < 6; i++) {
    rtb_wayp_data_cs[i] = 0.0;
    rtb_data_send_to_bs[i] = 0.0;
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  reset local variable, used for basestation ack code      % */
  /*  response.                                                % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  ack = 0;

  /* check if new packet PCK_WAYP or PACK_WAYP_EXT is arrived */
  if ((ICARO3_HAL_v1_B.SFunction_o3[0] == 1.0) || (ICARO3_HAL_v1_B.SFunction_o3
       [0] == 2.0)) {
    /* check for abort signal */
    if ((ICARO3_HAL_v1_B.SFunction_o3[4] == 0.0) &&
        (ICARO3_HAL_v1_B.SFunction_o3[5] == 0.0)) {
      /* ABORT */
      ICARO3_HAL_v1_DWork.en_timer = 0.0;
      ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
      ICARO3_HAL_v1_DWork.wayp_count = 0.0;
      memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
    } else {
      ICARO3_HAL_v1_DWork.en_timer = 1.0;
      ICARO3_HAL_v1_DWork.timer = 1000.0;
      if (ICARO3_HAL_v1_DWork.WP_DB[1200] > 0.0) {
        /* DB NOT EMPTY -> SOME MODIFY (NO NEW MISSION) */
        i = 0;

        /* find if wayp is present on current mission */
        newwp = 0;
        rtb_LogicalOperator1_h = false;
        while ((!rtb_LogicalOperator1_h) && (newwp <= (int32_T)
                ICARO3_HAL_v1_DWork.WP_DB[1200] - 1)) {
          if (ICARO3_HAL_v1_DWork.WP_DB[1000 + newwp] ==
              ICARO3_HAL_v1_B.SFunction_o3[4]) {
            i = 1;
            rtb_LogicalOperator1_h = true;
          } else {
            newwp++;
          }
        }

        if (i == 0) {
          /* ADDED NEW WP */
          newwp = 1;

          /* check if wp_id is already arrived */
          if (ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_B.SFunction_o3[4] + 999] ==
              ICARO3_HAL_v1_B.SFunction_o3[4]) {
            newwp = 0;
          }

          if (newwp != 0) {
            /* not yet arrived -> add wp to db_tmp */
            ICARO3_HAL_v1_DWork.wayp_count++;

            /* new id to add */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] - 1] = ICARO3_HAL_v1_B.SFunction_o3[1];

            /* LAT */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 199] = ICARO3_HAL_v1_B.SFunction_o3[2];

            /* LON */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 399] = ICARO3_HAL_v1_B.SFunction_o3[3];

            /* ALTI */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 599] = 10.0;

            /* DEF.HEAD */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 799] = 0.0;

            /* DEF.ACT */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 999] = ICARO3_HAL_v1_B.SFunction_o3[4];

            /* ID */
            if (ICARO3_HAL_v1_B.SFunction_o3[0] == 2.0) {
              ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
                ICARO3_HAL_v1_B.SFunction_o3[4] + 599] =
                ICARO3_HAL_v1_B.SFunction_o3[6];

              /* NEW HEAD */
              ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
                ICARO3_HAL_v1_B.SFunction_o3[4] + 799] =
                ICARO3_HAL_v1_B.SFunction_o3[7];

              /* NEW ACT */
            }

            if ((ICARO3_HAL_v1_DWork.miss_pkg == 0.0) &&
                (ICARO3_HAL_v1_DWork.wayp_count + ICARO3_HAL_v1_DWork.WP_DB[1200]
                 != ICARO3_HAL_v1_B.SFunction_o3[4])) {
              ICARO3_HAL_v1_DWork.miss_pkg = ICARO3_HAL_v1_DWork.wayp_count -
                1.0;
            }
          }

          /* check if all data is arrived */
          if (ICARO3_HAL_v1_DWork.wayp_count == ICARO3_HAL_v1_B.SFunction_o3[5])
          {
            ICARO3_HAL_v1_DWork.en_timer = 0.0;
            ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
            ack = 1;
            send_sync = 1;
            rtb_Switch2_oq = ICARO3_HAL_v1_DWork.WP_DB[1200];

            /* update the value of actual_waypoint for control */
            /* system */
            ICARO3_HAL_v1_DWork.act_wp = ICARO3_HAL_v1_DWork.WP_DB[1200];
            for (newwp = 0; newwp < (int32_T)ICARO3_HAL_v1_DWork.wayp_count;
                 newwp++) {
              /* add new wp to the real database */
              rtb_Switch2_a_0 = (int32_T)((1.0 + (real_T)newwp) + rtb_Switch2_oq);
              i = (int32_T)((1.0 + (real_T)newwp) + rtb_Switch2_oq);
              for (i_0 = 0; i_0 < 6; i_0++) {
                ICARO3_HAL_v1_DWork.WP_DB[(rtb_Switch2_a_0 + 200 * i_0) - 1] =
                  ICARO3_HAL_v1_DWork.WP_DB_tmp[(200 * i_0 + i) - 1];
              }
            }

            rtb_Switch2_oq += ICARO3_HAL_v1_DWork.wayp_count;

            /* update the number of total wp on database */
            if (1.0 > rtb_Switch2_oq) {
              newwp = 0;
            } else {
              newwp = (int32_T)rtb_Switch2_oq;
            }

            for (i_0 = 0; i_0 < newwp; i_0++) {
              ICARO3_HAL_v1_DWork.WP_DB[1200 + i_0] = rtb_Switch2_oq;
            }

            memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
            ICARO3_HAL_v1_DWork.wayp_count = 0.0;
          }
        } else {
          /* CHANGE A WP DATA */
          newwp = 1;

          /* check if wp_id is already arrived */
          i = 0;
          rtb_LogicalOperator1_h = false;
          while ((!rtb_LogicalOperator1_h) && (i <= (int32_T)
                  ICARO3_HAL_v1_B.SFunction_o3[5] - 1)) {
            if (ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + i] ==
                ICARO3_HAL_v1_B.SFunction_o3[4]) {
              newwp = 0;
              rtb_LogicalOperator1_h = true;
            } else {
              i++;
            }
          }

          if (newwp != 0) {
            ICARO3_HAL_v1_DWork.wayp_count++;
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count - 1] =
              ICARO3_HAL_v1_B.SFunction_o3[1];

            /* NEW LAT */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count + 199] =
              ICARO3_HAL_v1_B.SFunction_o3[2];

            /* NEW LON */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count + 399] =
              ICARO3_HAL_v1_B.SFunction_o3[3];

            /* NEW ALTI */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count + 599] = 10.0;

            /* DEF. HEAD */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count + 799] = 0.0;

            /* DEF. ACT */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
              ICARO3_HAL_v1_DWork.wayp_count + 999] =
              ICARO3_HAL_v1_B.SFunction_o3[4];

            /* ID TO CHANGE */
            if (ICARO3_HAL_v1_B.SFunction_o3[0] == 2.0) {
              ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
                ICARO3_HAL_v1_DWork.wayp_count + 599] =
                ICARO3_HAL_v1_B.SFunction_o3[6];

              /* NEW HEAD */
              ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
                ICARO3_HAL_v1_DWork.wayp_count + 799] =
                ICARO3_HAL_v1_B.SFunction_o3[7];

              /* NEW ACT */
            }
          }

          ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
          if (ICARO3_HAL_v1_DWork.wayp_count == ICARO3_HAL_v1_B.SFunction_o3[5])
          {
            ICARO3_HAL_v1_DWork.en_timer = 0.0;
            ack = 1;
            send_sync = 1;
            for (newwp = 0; newwp < (int32_T)ICARO3_HAL_v1_DWork.wayp_count;
                 newwp++) {
              i = 0;
              rtb_LogicalOperator1_h = false;
              while ((!rtb_LogicalOperator1_h) && (i <= (int32_T)
                      ICARO3_HAL_v1_DWork.WP_DB[1200] - 1)) {
                if (ICARO3_HAL_v1_DWork.WP_DB[1000 + i] ==
                    ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + newwp]) {
                  /* save new change on database */
                  for (i_0 = 0; i_0 < 5; i_0++) {
                    ICARO3_HAL_v1_DWork.WP_DB[i + 200 * i_0] =
                      ICARO3_HAL_v1_DWork.WP_DB_tmp[200 * i_0 + newwp];
                  }

                  rtb_LogicalOperator1_h = true;
                } else {
                  i++;
                }
              }
            }

            /* set OP_CODE to -2 -> changed wayps */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[600] = -2.0;

            /* set number of wayp changed on WP_DB_tmp(1,5) field */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[800] = ICARO3_HAL_v1_DWork.wayp_count;
            ICARO3_HAL_v1_DWork.wayp_count = 0.0;

            /* set RESET_CODE to reset temporary database */
            /* Note : field WP_DB_tmp(1,3) is altitude (16bit), */
            /*        the maximum number is 2^16-1 = 65535. */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[400] = -70000.0;
          }
        }
      } else {
        /* DB EMPTY -> NEW MISSION ARRIVED */
        newwp = 1;

        /* check if wp_id is already arrived */
        if (ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
            [4] + 999] == ICARO3_HAL_v1_B.SFunction_o3[4]) {
          newwp = 0;
        }

        if (newwp != 0) {
          ICARO3_HAL_v1_DWork.wayp_count++;
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            - 1] = ICARO3_HAL_v1_B.SFunction_o3[1];

          /* LAT */
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            + 199] = ICARO3_HAL_v1_B.SFunction_o3[2];

          /* LON */
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            + 399] = ICARO3_HAL_v1_B.SFunction_o3[3];

          /* ALTI */
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            + 599] = 10.0;

          /* DEF.HEAD */
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            + 799] = 0.0;

          /* DEF.ACT */
          ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3[4]
            + 999] = ICARO3_HAL_v1_B.SFunction_o3[4];

          /* ID */
          if (ICARO3_HAL_v1_B.SFunction_o3[0] == 2.0) {
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 599] = ICARO3_HAL_v1_B.SFunction_o3[6];

            /* HEAD */
            ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)ICARO3_HAL_v1_B.SFunction_o3
              [4] + 799] = ICARO3_HAL_v1_B.SFunction_o3[7];

            /* ACT */
          }

          if ((ICARO3_HAL_v1_DWork.miss_pkg == 0.0) &&
              (ICARO3_HAL_v1_DWork.wayp_count != ICARO3_HAL_v1_B.SFunction_o3[4]))
          {
            ICARO3_HAL_v1_DWork.miss_pkg = ICARO3_HAL_v1_DWork.wayp_count - 1.0;
          }
        }

        if (ICARO3_HAL_v1_DWork.wayp_count == ICARO3_HAL_v1_B.SFunction_o3[5]) {
          /* last packet arrived */
          ICARO3_HAL_v1_DWork.en_timer = 0.0;
          ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
          ack = 1;
          send_sync = 1;
          for (i_0 = 0; i_0 < 6; i_0++) {
            memcpy(&ICARO3_HAL_v1_DWork.WP_DB[200 * i_0],
                   &ICARO3_HAL_v1_DWork.WP_DB_tmp[200 * i_0], 200U * sizeof
                   (real_T));
          }

          for (i_0 = 0; i_0 < 200; i_0++) {
            ICARO3_HAL_v1_DWork.WP_DB[1200 + i_0] =
              ICARO3_HAL_v1_DWork.wayp_count;
          }

          memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
          ICARO3_HAL_v1_DWork.wayp_count = 0.0;

          /* new mission loaded -> reset act_wp */
          ICARO3_HAL_v1_DWork.act_wp = 0.0;
        }
      }
    }
  }

  /* check if new packet PCK_WAYP_CMD is arrived */
  if (ICARO3_HAL_v1_B.SFunction_o3[0] == 3.0) {
    if (ICARO3_HAL_v1_DWork.WP_DB[1200] == 0.0) {
      ack = -2;

      /* Empty Database ERROR */
      /* set OP_Code to reset act_wp variable for control system */
      ICARO3_HAL_v1_DWork.WP_DB_tmp[600] = -1.0;
      send_sync = 1;
    } else {
      /* check if reset request */
      if (ICARO3_HAL_v1_B.SFunction_o3[1] == 254.0) {
        ICARO3_HAL_v1_DWork.en_timer = 0.0;
        memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
        memset(&ICARO3_HAL_v1_DWork.WP_DB[0], 0, 1400U * sizeof(real_T));
        ack = 2;

        /* CMD_RESET_OK */
        /* set OP_Code to reset act_wp variable for control system */
        ICARO3_HAL_v1_DWork.WP_DB_tmp[600] = -1.0;
        send_sync = 1;
        ICARO3_HAL_v1_DWork.wayp_count = 0.0;

        /* delete wayp request */
      } else {
        if ((ICARO3_HAL_v1_B.SFunction_o3[1] > 0.0) &&
            (ICARO3_HAL_v1_B.SFunction_o3[1] <= 200.0)) {
          /* check if wp_id is present on database */
          i = 0;
          newwp = 0;
          rtb_LogicalOperator1_h = false;
          while ((!rtb_LogicalOperator1_h) && (newwp <= (int32_T)
                  ICARO3_HAL_v1_DWork.WP_DB[1200] - 1)) {
            if (ICARO3_HAL_v1_DWork.WP_DB[1000 + newwp] ==
                ICARO3_HAL_v1_B.SFunction_o3[2]) {
              i = 1;
              rtb_LogicalOperator1_h = true;
            } else {
              newwp++;
            }
          }

          if (i == 0) {
            ICARO3_HAL_v1_DWork.en_timer = 0.0;
            ack = -3;
            ICARO3_HAL_v1_DWork.miss_pkg = ICARO3_HAL_v1_B.SFunction_o3[2];
            send_sync = 1;
            ICARO3_HAL_v1_DWork.wayp_count = 0.0;
          } else {
            ICARO3_HAL_v1_DWork.en_timer = 1.0;
            ICARO3_HAL_v1_DWork.timer = 1000.0;
            ack = 0;

            /* save id wp to delete */
            newwp = 1;

            /* check if wp_id is already arrived */
            i = 0;
            rtb_LogicalOperator1_h = false;
            while ((!rtb_LogicalOperator1_h) && (i <= (int32_T)
                    ICARO3_HAL_v1_B.SFunction_o3[1] - 1)) {
              if (ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + i] ==
                  ICARO3_HAL_v1_B.SFunction_o3[2]) {
                newwp = 0;
                rtb_LogicalOperator1_h = true;
              } else {
                i++;
              }
            }

            if (newwp != 0) {
              ICARO3_HAL_v1_DWork.wayp_count++;
              ICARO3_HAL_v1_DWork.WP_DB_tmp[(int32_T)
                ICARO3_HAL_v1_DWork.wayp_count + 999] =
                ICARO3_HAL_v1_B.SFunction_o3[2];

              /* ID to delete */
            }

            ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
            if (ICARO3_HAL_v1_DWork.wayp_count == ICARO3_HAL_v1_B.SFunction_o3[1])
            {
              ICARO3_HAL_v1_DWork.en_timer = 0.0;
              ack = 3;
              send_sync = 1;
              for (newwp = 0; newwp < (int32_T)ICARO3_HAL_v1_DWork.wayp_count;
                   newwp++) {
                rtb_Switch2_oq = 1.0;
                rtb_Switch2 = ICARO3_HAL_v1_DWork.WP_DB[1200];
                for (i = 0; i < (int32_T)rtb_Switch2; i++) {
                  if (ICARO3_HAL_v1_DWork.WP_DB[1000 + i] !=
                      ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + newwp]) {
                    rtb_Switch2_a_0 = (int32_T)rtb_Switch2_oq;
                    for (i_0 = 0; i_0 < 7; i_0++) {
                      tmp_0[i_0] = ICARO3_HAL_v1_DWork.WP_DB[200 * i_0 + i];
                    }

                    for (i_0 = 0; i_0 < 7; i_0++) {
                      ICARO3_HAL_v1_DWork.WP_DB[(rtb_Switch2_a_0 + 200 * i_0) -
                        1] = tmp_0[i_0];
                    }

                    rtb_Switch2_oq++;
                  }
                }
              }

              for (i_0 = 0; i_0 < 200; i_0++) {
                ICARO3_HAL_v1_DWork.WP_DB[1200 + i_0] -=
                  ICARO3_HAL_v1_DWork.wayp_count;
              }

              /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
              /* adjust the id field with new wp number */
              rtb_Switch2_oq = ICARO3_HAL_v1_DWork.WP_DB[1200];
              for (newwp = 0; newwp < (int32_T)rtb_Switch2_oq; newwp++) {
                ICARO3_HAL_v1_DWork.WP_DB[1000 + newwp] = 1.0 + (real_T)newwp;
              }

              /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
              if (ICARO3_HAL_v1_DWork.WP_DB[1200] + 1.0 > 200.0) {
                newwp = 1;
                i = 1;
              } else {
                newwp = (int32_T)(ICARO3_HAL_v1_DWork.WP_DB[1200] + 1.0);
                i = 201;
              }

              i -= newwp;
              for (i_0 = 0; i_0 < 7; i_0++) {
                for (i_1 = 0; i_1 < i; i_1++) {
                  ICARO3_HAL_v1_DWork.WP_DB[((newwp + i_1) + 200 * i_0) - 1] =
                    0.0;
                }
              }

              /* set OP_Code to -3 -> deleted wayps */
              ICARO3_HAL_v1_DWork.WP_DB_tmp[600] = -3.0;

              /* set number of wayp deleted on WP_DB_tmp(1,5) field */
              ICARO3_HAL_v1_DWork.WP_DB_tmp[800] =
                ICARO3_HAL_v1_DWork.wayp_count;
              ICARO3_HAL_v1_DWork.wayp_count = 0.0;

              /* set RESET_CODE to reset temporary database */
              /* Note : field WP_DB_tmp(1,3) is altitude (16bit), */
              /*        the maximum number is 2^16-1 = 65535. */
              ICARO3_HAL_v1_DWork.WP_DB_tmp[400] = -70000.0;
            }

            /* end if(all deleted data arrive) */
          }
        }
      }
    }
  }

  /* end of PCK_WAYP_CMD */
  if (ICARO3_HAL_v1_B.SFunction_o3[0] == 4.0) {
    /*  PCK_WAYP_REQ_ACK received */
    ack = 0;
    ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
    if (ICARO3_HAL_v1_B.SFunction_o3[1] == 2.0) {
      /* RESTART MISSION REQUEST */
      ICARO3_HAL_v1_DWork.act_wp = 0.0;
    } else if (ICARO3_HAL_v1_B.SFunction_o3[1] == 3.0) {
      /* WP ON DATABASE REQUEST */
      ICARO3_HAL_v1_DWork.send_flag = 1.0;
    } else {
      if (ICARO3_HAL_v1_B.SFunction_o3[1] == 4.0) {
        /* START MISSION FROM WP_ID */
        /* check for safety, the dimension of received data */
        if (ICARO3_HAL_v1_B.SFunction_o3[2] > 0.0) {
          ICARO3_HAL_v1_DWork.act_wp = ICARO3_HAL_v1_B.SFunction_o3[2] - 1.0;
        } else {
          ICARO3_HAL_v1_DWork.act_wp = 0.0;
        }
      }
    }
  }

  /* timer function */
  if (ICARO3_HAL_v1_DWork.en_timer == 1.0) {
    ICARO3_HAL_v1_DWork.timer--;
    if (ICARO3_HAL_v1_DWork.timer == 0.0) {
      ICARO3_HAL_v1_DWork.en_timer = 0.0;
      ack = -1;

      /*  Timeout Ack Code */
      send_sync = 1;

      /* Code to send PCK_WAYP_ACK to basestation */
    }
  }

  /* end of timer */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Check value of send_sync to decide what        % */
  /*  packet must be sent to basestation :           % */
  /*                                                 % */
  /*    send_sync = 1 -> PCK_WAYP_ACK                % */
  /*    send_sync = 2 -> PCK_WAYP_EXT                % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  if (send_sync == 1) {
    /* send PCK_WAYP_ACK response */
    rtb_data_send_to_bs[0] = ack;
    rtb_data_send_to_bs[1] = ICARO3_HAL_v1_DWork.miss_pkg;
  }

  if (ICARO3_HAL_v1_DWork.send_delay != 0.0) {
    ICARO3_HAL_v1_DWork.send_delay--;
  }

  if ((ICARO3_HAL_v1_DWork.send_flag != 0.0) && (ICARO3_HAL_v1_DWork.send_delay ==
       0.0)) {
    /* send PCK_WAYP_EXT  */
    ICARO3_HAL_v1_DWork.send_delay = 100.0;
    ICARO3_HAL_v1_DWork.wayp_count++;
    rtb_data_send_to_bs[0] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count - 1];

    /* LAT */
    rtb_data_send_to_bs[1] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count + 199];

    /* LON */
    rtb_data_send_to_bs[2] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count + 599];

    /* HDG */
    rtb_data_send_to_bs[3] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count + 399];

    /* ALT */
    rtb_data_send_to_bs[4] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count + 799];

    /* ACT */
    rtb_data_send_to_bs[5] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
      ICARO3_HAL_v1_DWork.wayp_count + 1199] * 256.0 +
      ICARO3_HAL_v1_DWork.WP_DB[(int32_T)ICARO3_HAL_v1_DWork.wayp_count + 999];

    /* ID_N = N*256+ID */
    /* check if database is empty or last wayp sent */
    if ((ICARO3_HAL_v1_DWork.WP_DB[1200] == 0.0) ||
        (ICARO3_HAL_v1_DWork.wayp_count == ICARO3_HAL_v1_DWork.WP_DB[1200])) {
      ICARO3_HAL_v1_DWork.send_flag = 0.0;
      ICARO3_HAL_v1_DWork.wayp_count = 0.0;
    }

    send_sync = 2;
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Code for select the i-th waypoint data for the control loop. % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* check if reset request from db_man */
  if (ICARO3_HAL_v1_DWork.WP_DB_tmp[600] == -1.0) {
    /* if(flag_code == -1) */
    /* STOP VEHICLE WAYPOINT GUIDANCE */
    wayp_sync_cs = 2;
    ICARO3_HAL_v1_DWork.act_wp = 0.0;

    /* set RESET_CODE to reset temporary database */
    ICARO3_HAL_v1_DWork.WP_DB_tmp[400] = -70000.0;
  } else {
    if (ICARO3_HAL_v1_DWork.act_wp != 0.0) {
      if (ICARO3_HAL_v1_DWork.WP_DB_tmp[600] == -2.0) {
        /* some wayp was changed */
        newwp = 0;
        rtb_LogicalOperator1_h = false;
        while ((!rtb_LogicalOperator1_h) && (newwp <= (int32_T)
                ICARO3_HAL_v1_DWork.WP_DB_tmp[800] - 1)) {
          /* check if the waypoint where the vehicle must go  */
          /* is changed */
          if (ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + newwp] ==
              ICARO3_HAL_v1_DWork.act_wp) {
            /* save new data of waypoint  */
            rtb_wayp_data_cs[0] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
              ICARO3_HAL_v1_DWork.act_wp - 1];
            rtb_wayp_data_cs[1] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
              ICARO3_HAL_v1_DWork.act_wp + 199];
            rtb_wayp_data_cs[2] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
              ICARO3_HAL_v1_DWork.act_wp + 399];
            rtb_wayp_data_cs[3] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
              ICARO3_HAL_v1_DWork.act_wp + 599];
            rtb_wayp_data_cs[4] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
              ICARO3_HAL_v1_DWork.act_wp + 799];
            rtb_wayp_data_cs[5] = 0.0;

            /* send new wayp_data that is changed */
            wayp_sync_cs = 1;
            rtb_LogicalOperator1_h = true;
          } else {
            newwp++;
          }
        }

        /* set RESET_CODE to reset temporary database */
        ICARO3_HAL_v1_DWork.WP_DB_tmp[400] = -70000.0;
      }

      /* if some waypoint was deleted, then the value of */
      /* act_wp MUST be adjusted */
      if (ICARO3_HAL_v1_DWork.WP_DB_tmp[600] == -3.0) {
        /* some wayp was deleted */
        rtb_Switch2_oq = 0.0;
        i = 0;
        newwp = 0;
        rtb_LogicalOperator1_h = false;
        while ((!rtb_LogicalOperator1_h) && (newwp <= (int32_T)
                ICARO3_HAL_v1_DWork.WP_DB_tmp[800] - 1)) {
          /* until number of wayp deleted */
          if (ICARO3_HAL_v1_DWork.WP_DB_tmp[1000 + newwp] ==
              ICARO3_HAL_v1_DWork.act_wp) {
            /* check id of wayps deleted */
            i = 1;
            rtb_LogicalOperator1_h = true;
          } else {
            if (ICARO3_HAL_v1_DWork.act_wp > ICARO3_HAL_v1_DWork.WP_DB_tmp[1000
                + newwp]) {
              rtb_Switch2_oq++;
            }

            newwp++;
          }
        }

        ICARO3_HAL_v1_DWork.act_wp -= rtb_Switch2_oq;
        if ((i != 0) && (ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
                         ICARO3_HAL_v1_DWork.act_wp + 999] ==
                         ICARO3_HAL_v1_DWork.act_wp)) {
          rtb_wayp_data_cs[0] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
            ICARO3_HAL_v1_DWork.act_wp - 1];
          rtb_wayp_data_cs[1] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
            ICARO3_HAL_v1_DWork.act_wp + 199];
          rtb_wayp_data_cs[2] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
            ICARO3_HAL_v1_DWork.act_wp + 399];
          rtb_wayp_data_cs[3] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
            ICARO3_HAL_v1_DWork.act_wp + 599];
          rtb_wayp_data_cs[4] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
            ICARO3_HAL_v1_DWork.act_wp + 799];
          rtb_wayp_data_cs[5] = 0.0;

          /* send new wp_data that is deleted */
          wayp_sync_cs = 1;
        } else {
          if ((i != 0) && (ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
                           ICARO3_HAL_v1_DWork.act_wp + 999] !=
                           ICARO3_HAL_v1_DWork.act_wp)) {
            /* STOP VEHICLE WAYPOINT GUIDANCE */
            wayp_sync_cs = 2;
          }
        }

        /* set RESET_CODE to reset temporary database */
        ICARO3_HAL_v1_DWork.WP_DB_tmp[400] = -70000.0;
      }
    }

    if (ICARO3_HAL_v1_P.ManualSwitch6_CurrentSetting == 1) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.Constant_Value_e;
    } else {
      rtb_ManualSwitch3_a_idx_2 = (rtb_LogicalOperator_n &&
        ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_j);
    }

    if ((rtb_ManualSwitch3_a_idx_2 == 1.0) && (ICARO3_HAL_v1_DWork.WP_DB[1200]
         != 0.0)) {
      /* check if the vehicle arrived at the end of mission */
      if (ICARO3_HAL_v1_DWork.act_wp >= ICARO3_HAL_v1_DWork.WP_DB[1200]) {
        /* STOP VEHICLE WAYPOINT GUIDANCE */
        wayp_sync_cs = 2;
      } else {
        ICARO3_HAL_v1_DWork.act_wp++;

        /* select the data from the i-th wp on database */
        rtb_wayp_data_cs[0] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
          ICARO3_HAL_v1_DWork.act_wp - 1];
        rtb_wayp_data_cs[1] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
          ICARO3_HAL_v1_DWork.act_wp + 199];
        rtb_wayp_data_cs[2] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
          ICARO3_HAL_v1_DWork.act_wp + 399];
        rtb_wayp_data_cs[3] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
          ICARO3_HAL_v1_DWork.act_wp + 599];
        rtb_wayp_data_cs[4] = ICARO3_HAL_v1_DWork.WP_DB[(int32_T)
          ICARO3_HAL_v1_DWork.act_wp + 799];
        rtb_wayp_data_cs[5] = 0.0;
        wayp_sync_cs = 1;
      }

      /* if(act_wp == WP_DB(1,7)) */
      /* DO NOT RESET COUNTER - THE MISSION MUST BE RESTARTED */
      /* DIFFERENTLY  */
      /* act_wp = 0; */
      /* end */
    }
  }

  /* check for reset_code valu of temporary database */
  if (ICARO3_HAL_v1_DWork.WP_DB_tmp[400] == -70000.0) {
    memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
  }

  /* end of function DB_MAN() */
  if (ICARO3_HAL_v1_P.ManualSwitch7_CurrentSetting == 1) {
    rtb_ManualSwitch7[0] = wayp_sync_cs;
  } else {
    rtb_ManualSwitch7[0] = ICARO3_HAL_v1_P.syncro1_Value;
  }

  for (i = 0; i < 6; i++) {
    if (ICARO3_HAL_v1_P.ManualSwitch7_CurrentSetting == 1) {
      rtb_ManualSwitch7[i + 1] = rtb_wayp_data_cs[i];
    } else {
      rtb_ManualSwitch7[i + 1] = ICARO3_HAL_v1_P.dummydata1_Value[i];
    }
  }

  if (rtb_ManualSwitch7[0] > 0.0) {
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_B.In1[i] = rtb_ManualSwitch7[i + 1];
    }
  }

  rtb_LogicalOperator_pm = ((rtb_ManualSwitch7[0] != 0.0) && rtb_Compare_pc);
  ICARO3_HAL_v1_latlonlatch(rtb_LogicalOperator_pm, &ICARO3_HAL_v1_B.In1[0],
    &ICARO3_HAL_v1_B.latlonlatch_a);
  rtb_Gain3_k = ICARO3_HAL_v1_P.Gain3_Gain_p *
    ICARO3_HAL_v1_B.latlonlatch_a.In1[0];
  rtb_Gain4_p = ICARO3_HAL_v1_P.Gain4_Gain_i *
    ICARO3_HAL_v1_B.latlonlatch_a.In1[1];
  rtb_Gain5_d = ICARO3_HAL_v1_P.Gain5_Gain_o *
    ICARO3_HAL_v1_P.Constant1_Value_fw;
  rtb_Gain6_mx = ICARO3_HAL_v1_P.Gain6_Gain_nx *
    ICARO3_HAL_v1_P.Constant2_Value_m;
  ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.converttohifreqHz[0],
    ICARO3_HAL_v1_B.converttohifreqHz[1], rtb_Gain3_k, rtb_Gain4_p,
    &ICARO3_HAL_v1_B.sf_MATLABFunction6_a4);
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_B.sf_MATLABFunction6_l.x -
    ICARO3_HAL_v1_B.sf_MATLABFunction6_a4.x;
  rtb_Switch2_oq = rtb_DataTypeConversion2_a * rtb_DataTypeConversion2_a;
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_B.sf_MATLABFunction6_l.y -
    ICARO3_HAL_v1_B.sf_MATLABFunction6_a4.y;
  rtb_DataTypeConversion2_a = (rtb_Switch2_oq +
    ICARO3_HAL_v1_P.avoid0dist1_Value) + rtb_DataTypeConversion2_a *
    rtb_DataTypeConversion2_a;

  /* wayp_reached_status = 0; %flag for ask the DB_MAN to send a new waypoint */
  /* -----------------------------------% */
  if (sqrt(rtb_DataTypeConversion2_a) < ICARO3_HAL_v1_P.wayp_R) {
    rtb_command_sel_out = 1;
  } else {
    rtb_command_sel_out = 0;
  }

  /* -----------------------------------% */
  /*  latr -> reference system origin latitude */
  /*  lonr -> reference system origin longitude */
  /*  hr -> reference system origin altitude */
  /*  lat -> vehicle actual latitude */
  /*  lon -> vehicle actual longitude */
  /*  lat_wayp -> waypoint latitude */
  /*  lon_wayp -> waypoint longitude */
  /* Define constant parameter */
  /* eccentricity of Earth */
  /* equatorial radius (in meter) */
  rtb_Switch2_oq = sin(ICARO3_HAL_v1_B.converttohifreqHz[0]);
  rtb_Switch2_a = 6.378137E+6 / sqrt(1.0 - rtb_Switch2_oq * rtb_Switch2_oq *
    0.0066912399999999993);

  /* Normal */
  rtb_Switch2_oq = sin(ICARO3_HAL_v1_B.converttohifreqHz[0]);
  rtb_Switch2_oq = 1.0 - rtb_Switch2_oq * rtb_Switch2_oq * 0.0066912399999999993;
  rtb_Switch2 = 0.99330876 / (rtb_Switch2_oq * rtb_Switch2_oq) * rtb_Switch2_a;

  /* Meridian */
  rtb_Switch2_ag = (ICARO3_HAL_v1_P.Gain3_Gain_i *
                    ICARO3_HAL_v1_B.RateTransition1_a[0] -
                    ICARO3_HAL_v1_B.converttohifreqHz[0]) * (rtb_Switch2 +
    ICARO3_HAL_v1_B.converttohifreqHz[2]);
  rtb_Switch2_og = (rtb_Switch2_a + ICARO3_HAL_v1_B.converttohifreqHz[2]) * cos
    (ICARO3_HAL_v1_B.converttohifreqHz[0]) * (ICARO3_HAL_v1_P.Gain4_Gain_da *
    ICARO3_HAL_v1_B.RateTransition1_a[1] - ICARO3_HAL_v1_B.converttohifreqHz[1]);
  rtb_Switch2_oq = (ICARO3_HAL_v1_P.Gain5_Gain_gq * ICARO3_HAL_v1_B.In1[0] -
                    ICARO3_HAL_v1_B.converttohifreqHz[0]) * (rtb_Switch2 +
    ICARO3_HAL_v1_B.converttohifreqHz[2]);
  rtb_Switch2 = (rtb_Switch2_a + ICARO3_HAL_v1_B.converttohifreqHz[2]) * cos
    (ICARO3_HAL_v1_B.converttohifreqHz[0]) * (ICARO3_HAL_v1_P.Gain6_Gain_a *
    ICARO3_HAL_v1_B.In1[1] - ICARO3_HAL_v1_B.converttohifreqHz[1]);

  /* give the angle between the actual position and the selected wayp */
  /* set the distance between Y and Ywayp */
  /* set the abs value of distance between actual X position and X of waypoint */
  rtb_Switch2_a = rtb_Switch2_oq - rtb_Switch2_ag;
  if (rtb_ManualSwitch7[0] > ICARO3_HAL_v1_P.Switch_Threshold_p) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.latch_NOK_Value;
  } else {
    rtb_DataTypeConversion2_a = rtb_ManualSwitch7[0];
  }

  rtb_DigitalClock_c = ICARO3_HAL_v1_DWork.Memory_PreviousInput;
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Switch_Threshold_g) {
    rtb_ahrs_sel_out = rt_atan2d_snf(rtb_Switch2 - rtb_Switch2_og,
      rtb_Switch2_oq - rtb_Switch2_ag);
  } else {
    rtb_ahrs_sel_out = rtb_DigitalClock_c;
  }

  if (ICARO3_HAL_v1_B.In1[4] > ICARO3_HAL_v1_P.Switch3_Threshold_b) {
    rtb_Switch3_g = ICARO3_HAL_v1_B.In1[3];
  } else {
    rtb_Switch3_g = rtb_ahrs_sel_out;
  }

  rtb_DataTypeConversion2_a = (rtb_Switch2 - rtb_Switch2_og) *
    ICARO3_HAL_v1_P.Kroll_Gain;
  if (!ICARO3_HAL_v1_DWork.tmpPitch_not_empty) {
    ICARO3_HAL_v1_DWork.tmpPitch = ICARO3_HAL_v1_P.wayp_pitch;
    ICARO3_HAL_v1_DWork.tmpPitch_not_empty = true;
  }

  if (fabs(rtb_Switch2_a) > ICARO3_HAL_v1_P.wayp_R) {
    rtb_waypPitch = -ICARO3_HAL_v1_DWork.tmpPitch;
  } else if ((fabs(rtb_Switch2_a) <= ICARO3_HAL_v1_P.wayp_R) && (fabs
              (rtb_Switch2_a) > 0.05) && (ICARO3_HAL_v1_DWork.tmpPitch > 0.0)) {
    ICARO3_HAL_v1_DWork.tmpPitch -= 0.0008726646259971648;
    rtb_waypPitch = -ICARO3_HAL_v1_DWork.tmpPitch;
  } else {
    ICARO3_HAL_v1_DWork.tmpPitch = ICARO3_HAL_v1_P.wayp_pitch;
    rtb_waypPitch = 0.0;
  }

  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.wayp_roll_limit) {
    rtb_Saturation_gf = ICARO3_HAL_v1_P.wayp_roll_limit;
  } else if (rtb_DataTypeConversion2_a < -ICARO3_HAL_v1_P.wayp_roll_limit) {
    rtb_Saturation_gf = -ICARO3_HAL_v1_P.wayp_roll_limit;
  } else {
    rtb_Saturation_gf = rtb_DataTypeConversion2_a;
  }

  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_pm, ICARO3_HAL_v1_B.In1[2],
                       &ICARO3_HAL_v1_B.hlatch_n);
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_pm, rtb_waypPitch,
                       &ICARO3_HAL_v1_B.pitchlatch);
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_pm, rtb_Saturation_gf,
                       &ICARO3_HAL_v1_B.rolllatch);
  ICARO3_HAL_v1_hlatch(rtb_LogicalOperator_pm, rtb_Switch3_g,
                       &ICARO3_HAL_v1_B.yawlatch_l);
  rtb_Compare_p3 = !rtb_Logic_d_idx_0;
  if (!(ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_o != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[0] = rtb_ManualSwitch3_a_idx_0;
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[1] = rtb_ManualSwitch3_a_idx_1;
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[2] = rtb_ManualSwitch3_g;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken_m != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition23_Buffer0_d = rtb_mode_out;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition12_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition12_Buffer0 = ICARO3_HAL_v1_B.SFunction_o1
      [19];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken_a != 0)) {
    for (i = 0; i < 5; i++) {
      ICARO3_HAL_v1_DWork.RateTransition22_Buffer0_d[i] =
        ICARO3_HAL_v1_B.SFunction_o1[i + 4];
    }
  }

  rtb_DataTypeConversion2_a = (real_T)(((uint16_T)0U) &
    ICARO3_HAL_v1_P.BitwiseOperator_BitMask);
  if (!(ICARO3_HAL_v1_DWork.RateTransition21_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition21_Buffer0 = ICARO3_HAL_v1_P.Gain_Gain_fl *
      rtb_DataTypeConversion2_a;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition14_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition14_Buffer0 = rtb_h_data[0];
  }

  rtb_Switch2_og = 1.0 / ICARO3_HAL_v1_P.Fmax;
  if (rtb_refs_idx_0 > ICARO3_HAL_v1_P.TLMNsat[0]) {
    rtb_refs_idx_0 = ICARO3_HAL_v1_P.TLMNsat[0];
  } else {
    if (rtb_refs_idx_0 < ICARO3_HAL_v1_P.Saturation_LowerSat_d[0]) {
      rtb_refs_idx_0 = ICARO3_HAL_v1_P.Saturation_LowerSat_d[0];
    }
  }

  if (rtb_refs_idx_1 > ICARO3_HAL_v1_P.TLMNsat[1]) {
    rtb_refs_idx_1 = ICARO3_HAL_v1_P.TLMNsat[1];
  } else {
    if (rtb_refs_idx_1 < ICARO3_HAL_v1_P.Saturation_LowerSat_d[1]) {
      rtb_refs_idx_1 = ICARO3_HAL_v1_P.Saturation_LowerSat_d[1];
    }
  }

  if (rtb_refs_idx_2 > ICARO3_HAL_v1_P.TLMNsat[2]) {
    rtb_refs_idx_2 = ICARO3_HAL_v1_P.TLMNsat[2];
  } else {
    if (rtb_refs_idx_2 < ICARO3_HAL_v1_P.Saturation_LowerSat_d[2]) {
      rtb_refs_idx_2 = ICARO3_HAL_v1_P.Saturation_LowerSat_d[2];
    }
  }

  if (rtb_refs_idx_3 > ICARO3_HAL_v1_P.TLMNsat[3]) {
    rtb_refs_idx_3 = ICARO3_HAL_v1_P.TLMNsat[3];
  } else {
    if (rtb_refs_idx_3 < ICARO3_HAL_v1_P.Saturation_LowerSat_d[3]) {
      rtb_refs_idx_3 = ICARO3_HAL_v1_P.Saturation_LowerSat_d[3];
    }
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.pinvM[i_0 + 12] * rtb_refs_idx_3
      + (ICARO3_HAL_v1_P.pinvM[i_0 + 8] * rtb_refs_idx_2 +
         (ICARO3_HAL_v1_P.pinvM[i_0 + 4] * rtb_refs_idx_1 +
          ICARO3_HAL_v1_P.pinvM[i_0] * rtb_refs_idx_0));
    tmp_1[i_0] = rtb_ManualSwitch3_a_idx_2;
  }

  rtb_Switch_idx_0 = rtb_Switch2_og * tmp_1[0] * ICARO3_HAL_v1_P.Gain_Gain_lp;
  rtb_Switch_idx_1 = rtb_Switch2_og * tmp_1[1] * ICARO3_HAL_v1_P.Gain_Gain_lp;
  rtb_Switch2_ag = rtb_Switch2_og * tmp_1[2] * ICARO3_HAL_v1_P.Gain_Gain_lp;
  rtb_Switch_idx_3 = rtb_Switch2_og * tmp_1[3] * ICARO3_HAL_v1_P.Gain_Gain_lp;
  rtb_Compare_pc = (rtb_Switch_idx_0 > ICARO3_HAL_v1_P.Constant2_Value_k);
  rtb_LogicalOperator1_h = (rtb_Switch_idx_1 > ICARO3_HAL_v1_P.Constant2_Value_k);
  rtb_LowerRelop1_idx_2 = (rtb_Switch2_ag > ICARO3_HAL_v1_P.Constant2_Value_k);
  if (rtb_controller_sel_out == 0) {
    ICARO3_HAL_v1_B.lo = 0.0;

    /* manual */
  } else {
    /* lo = 1; %all other controllers */
    ICARO3_HAL_v1_B.lo = 5.0;
  }

  rtb_ManualSwitch3_a_idx_2 = rtb_Switch_idx_0;
  if (rtb_Switch_idx_0 < ICARO3_HAL_v1_B.lo) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.lo;
  }

  rtb_Switch_idx_0 = rtb_ManualSwitch3_a_idx_2;
  rtb_ManualSwitch3_a_idx_2 = rtb_Switch_idx_1;
  if (rtb_Switch_idx_1 < ICARO3_HAL_v1_B.lo) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.lo;
  }

  rtb_Switch_idx_1 = rtb_ManualSwitch3_a_idx_2;
  rtb_ManualSwitch3_a_idx_2 = rtb_Switch2_ag;
  if (rtb_Switch2_ag < ICARO3_HAL_v1_B.lo) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.lo;
  }

  rtb_Switch2_ag = rtb_ManualSwitch3_a_idx_2;
  rtb_ManualSwitch3_a_idx_2 = rtb_Switch_idx_3;
  if (rtb_Switch_idx_3 < ICARO3_HAL_v1_B.lo) {
    rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_B.lo;
  }

  if (rtb_Compare_pc) {
    ICARO3_HAL_v1_B.Switch2[0] = ICARO3_HAL_v1_P.Constant2_Value_k;
  } else {
    ICARO3_HAL_v1_B.Switch2[0] = rtb_Switch_idx_0;
  }

  if (rtb_LogicalOperator1_h) {
    ICARO3_HAL_v1_B.Switch2[1] = ICARO3_HAL_v1_P.Constant2_Value_k;
  } else {
    ICARO3_HAL_v1_B.Switch2[1] = rtb_Switch_idx_1;
  }

  if (rtb_LowerRelop1_idx_2) {
    ICARO3_HAL_v1_B.Switch2[2] = ICARO3_HAL_v1_P.Constant2_Value_k;
  } else {
    ICARO3_HAL_v1_B.Switch2[2] = rtb_Switch2_ag;
  }

  if (rtb_Switch_idx_3 > ICARO3_HAL_v1_P.Constant2_Value_k) {
    ICARO3_HAL_v1_B.Switch2[3] = ICARO3_HAL_v1_P.Constant2_Value_k;
  } else {
    ICARO3_HAL_v1_B.Switch2[3] = rtb_ManualSwitch3_a_idx_2;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_a != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[0] = ICARO3_HAL_v1_B.Switch2[0];
    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[1] = ICARO3_HAL_v1_B.Switch2[1];
    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[2] = ICARO3_HAL_v1_B.Switch2[2];
    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[3] = ICARO3_HAL_v1_B.Switch2[3];
  }

  rtb_Compare_pc = (ICARO3_HAL_v1_P.ManualSwitch7_CurrentSetting_o == 1);
  rtb_ManualSwitch3_a_idx_2 = rtb_ManualSwitch3_a_idx_0;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_a_idx_2 = rtb_DataTypeConversionmx10_idx_0;
  }

  rtb_ManualSwitch3_a_idx_0 = rtb_ManualSwitch3_a_idx_2;
  rtb_ManualSwitch3_a_idx_2 = rtb_ManualSwitch3_a_idx_1;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_a_idx_2 = rtb_DataTypeConversionmx10_idx_1;
  }

  rtb_ManualSwitch3_a_idx_1 = rtb_ManualSwitch3_a_idx_2;
  rtb_ManualSwitch3_a_idx_2 = rtb_ManualSwitch3_g;
  if (!rtb_Compare_pc) {
    rtb_ManualSwitch3_a_idx_2 = rtb_DataTypeConversionmx10_idx_2;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_o != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[0] = rtb_ManualSwitch3_a_idx_0;
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[1] = rtb_ManualSwitch3_a_idx_1;
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[2] = rtb_ManualSwitch3_a_idx_2;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_f != 0)) {
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_j[i] =
        ICARO3_HAL_v1_B.SFunction_o1[i + 9];
    }
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition15_semaphoreTaken != 0)) {
    if (ICARO3_HAL_v1_P.ManualSwitch7_CurrentSetting_i == 1) {
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[0] = rtb_DataTypeConversion6
        [0];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[1] = rtb_DataTypeConversion6
        [1];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[2] = rtb_DataTypeConversion6
        [2];
    } else {
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[0] = rtb_DataTypeConversion7
        [0];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[1] = rtb_DataTypeConversion7
        [1];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[2] = rtb_DataTypeConversion7
        [2];
    }

    if (ICARO3_HAL_v1_P.ManualSwitch1_CurrentSetting_a == 1) {
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[3] = rtb_DataTypeConversion5
        [0];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[4] = rtb_DataTypeConversion5
        [1];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[5] = rtb_DataTypeConversion5
        [2];
    } else {
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[3] = rtb_DataTypeConversion9
        [0];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[4] = rtb_DataTypeConversion9
        [1];
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[5] = rtb_DataTypeConversion9
        [2];
    }

    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[6] = rtb_usecalibrateddata_c[0];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[7] = rtb_usecalibrateddata_c[1];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[8] = rtb_usecalibrateddata_c[2];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[9] = rtb_DataTypeConversion2[0];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[10] = rtb_DataTypeConversion2[1];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[11] = rtb_DataTypeConversion2[2];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[12] = rtb_DataTypeConversion3[0];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[13] = rtb_DataTypeConversion3[1];
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[14] = rtb_DataTypeConversion3_j;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition25_semaphoreTaken != 0)) {
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_DWork.RateTransition25_Buffer0[i] = rtb_ManualSwitch_b[i];
    }
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[0] = rtb_Switch3[1];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[1] = rtb_Switch3[2];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[2] = rtb_Switch3[3];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[3] = rtb_Switch3[4];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[4] = rtb_Switch3[6];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[5] = rtb_Switch3[8];
  }

  rtb_Switch2_ag =
    ICARO3_HAL_v1_P.secto10thofmsecrepresentsavaluefrom001secto255seconaBYTE_Gain
    * rtb_Sum;
  rtb_UnitDelay1_nc = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_o;
  if (rtb_UnitDelay1_nc) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_g;
  } else {
    rtb_DataTypeConversion2_a = rtb_Switch2_ag;
  }

  if ((rtb_Switch2_ag >= rtb_DataTypeConversion2_a) || rtIsNaN
      (rtb_DataTypeConversion2_a)) {
    rtb_Switch2_og = rtb_Switch2_ag;
  } else {
    rtb_Switch2_og = rtb_DataTypeConversion2_a;
  }

  if ((!rtb_UnitDelay1_nc) &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p2 == 1)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_af;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_k != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_f[0] = rtb_Switch2_og;
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_f[1] =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l;
  }

  rtb_Switch2_g =
    ICARO3_HAL_v1_P.secto10thofmsecrepresentsavaluefrom001secto255seconaBYTE_Gain_e
    * ICARO3_HAL_v1_B.Switch5;
  rtb_UnitDelay1_l = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_j;
  if (rtb_UnitDelay1_l) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_i;
  } else {
    rtb_DataTypeConversion2_a = rtb_Switch2_g;
  }

  if ((rtb_Switch2_g >= rtb_DataTypeConversion2_a) || rtIsNaN
      (rtb_DataTypeConversion2_a)) {
    rtb_Switch2_d = rtb_Switch2_g;
  } else {
    rtb_Switch2_d = rtb_DataTypeConversion2_a;
  }

  if ((!rtb_UnitDelay1_l) &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_o == 1)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l5 =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_m;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_a != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_n[0] = rtb_Switch2_d;
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_n[1] =
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l5;
  }

  /* compress i2c enable flags into bits: */
  /* MSB [motors press gyro acc mag 0 0 0 ] LSB */
  /*  */
  /* from wrap_i2c_requests.c: */
  /*      output[22 + MOTORS_IDX] = i2c_enabled[MOTORS_IDX]; */
  /*      output[22 + PRESS_IDX] = i2c_enabled[PRESS_IDX]; */
  /*      output[22 + GYRO_IDX] = i2c_enabled[GYRO_IDX]; */
  /*      output[22 + ACC_IDX] = i2c_enabled[ACC_IDX]; */
  /*      output[22 + MAG_IDX] = i2c_enabled[MAG_IDX]; */
  if (ICARO3_HAL_v1_B.Switch4[0] > 1) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(ICARO3_HAL_v1_B.Switch4[0] << 7);
  }

  if (ICARO3_HAL_v1_B.Switch4[1] > 3) {
    command_sel_tmp = MAX_uint8_T;
  } else {
    command_sel_tmp = (uint8_T)(ICARO3_HAL_v1_B.Switch4[1] << 6);
  }

  i_0 = (int32_T)((uint32_T)tmp_2 + command_sel_tmp);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  if (ICARO3_HAL_v1_B.Switch4[2] > 7) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(ICARO3_HAL_v1_B.Switch4[2] << 5);
  }

  i_0 = (int32_T)((uint32_T)i_0 + tmp_2);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  if (ICARO3_HAL_v1_B.Switch4[3] > 15) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(ICARO3_HAL_v1_B.Switch4[3] << 4);
  }

  i_0 = (int32_T)((uint32_T)i_0 + tmp_2);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  if (ICARO3_HAL_v1_B.Switch4[4] > 31) {
    tmp_2 = MAX_uint8_T;
  } else {
    tmp_2 = (uint8_T)(ICARO3_HAL_v1_B.Switch4[4] << 3);
  }

  i_0 = (int32_T)((uint32_T)i_0 + tmp_2);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_d != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_d = i_0;
  }

  for (i = 0; i < 7; i++) {
    if (ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_b) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_bv[i];
    } else {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.enableall3_Value[i + 2];
    }

    if ((ICARO3_HAL_v1_P.enableall3_Value[i + 2] >= rtb_ManualSwitch3_a_idx_2) ||
        rtIsNaN(rtb_ManualSwitch3_a_idx_2)) {
      rtb_ManualSwitch7[i] = ICARO3_HAL_v1_P.enableall3_Value[i + 2];
    } else {
      rtb_ManualSwitch7[i] = rtb_ManualSwitch3_a_idx_2;
    }
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_o != 0)) {
    for (i = 0; i < 7; i++) {
      ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_ls[i] = rtb_ManualSwitch7[i];
    }
  }

  if (ICARO3_HAL_v1_P.ManualSwitch6_CurrentSetting_e == 1) {
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.SFunction_o2[0];
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.SFunction_o2[1];
  } else {
    rtb_refs_idx_0 =
      ICARO3_HAL_v1_P.telemetrytypeseldebugtelemetrywithDPdataintheDEBUG_6_FLOATSpacke
      [0];
    rtb_refs_idx_1 =
      ICARO3_HAL_v1_P.telemetrytypeseldebugtelemetrywithDPdataintheDEBUG_6_FLOATSpacke
      [1];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition9_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition9_Buffer0 = rtb_refs_idx_0;
  }

  if (ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_l) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_f;
  } else {
    rtb_DataTypeConversion2_a = rtb_refs_idx_1;
  }

  if ((rtb_refs_idx_1 >= rtb_DataTypeConversion2_a) || rtIsNaN
      (rtb_DataTypeConversion2_a)) {
    rtb_Switch2_a = rtb_refs_idx_1;
  } else {
    rtb_Switch2_a = rtb_DataTypeConversion2_a;
  }

  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1) {
    ICARO3_HAL_v1_B.RateTransition1_j = rtb_Switch2_a;
  }

  ICARO3_HAL_v1_B.LogicalOperator = ((rtb_mode_out ==
    ICARO3_HAL_v1_P.CompareToConstant_const_cr) || (rtb_mode_out ==
    ICARO3_HAL_v1_P.CompareToConstant1_const_h) || (rtb_mode_out ==
    ICARO3_HAL_v1_P.CompareToConstant2_const_e));
  if (!(ICARO3_HAL_v1_DWork.RateTransition16_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition16_Buffer0[0] = send_sync;
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_DWork.RateTransition16_Buffer0[i + 1] =
        rtb_data_send_to_bs[i];
    }
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition10_semaphoreTaken != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition10_Buffer0[0] = rtb_DataTypeConversion_j;
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_DWork.RateTransition10_Buffer0[i + 1] =
        ICARO3_HAL_v1_B.RateTransition1_ay[i];
    }

    ICARO3_HAL_v1_DWork.RateTransition10_Buffer0[7] =
      ICARO3_HAL_v1_B.RateTransition3;
  }

  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.clockTickCounter_l <
    ICARO3_HAL_v1_P.ResetGenerator_Duty) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_l >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_l >=
      ICARO3_HAL_v1_P.Subsystem_period_samples - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_l = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_l++;
  }

  rtb_Compare_pc = !(rtb_DataTypeConversion2_a != 0.0);
  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.clockTickCounter_p <
    ICARO3_HAL_v1_P.ResetGenerator_Duty_m) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_p >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp_g : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_p >=
      ICARO3_HAL_v1_P.Subsystem1_period_samples - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_p = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_p++;
  }

  rtb_LowerRelop1_idx_2 = !(rtb_DataTypeConversion2_a != 0.0);
  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.clockTickCounter_lx <
    ICARO3_HAL_v1_P.ResetGenerator_Duty_d) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_lx >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp_h : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_lx >=
      ICARO3_HAL_v1_P.Subsystem4_period_samples - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_lx = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_lx++;
  }

  rtb_LogicalOperator2_p = !(rtb_DataTypeConversion2_a != 0.0);
  rtb_DataTypeConversion2_a = (ICARO3_HAL_v1_DWork.clockTickCounter_kw <
    ICARO3_HAL_v1_P.ResetGenerator_Duty_n) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_kw >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp_j : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_kw >=
      ICARO3_HAL_v1_P.Subsystem4_period_samples_e - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_kw = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_kw++;
  }

  rtb_LogicalOperator2_ni = !(rtb_DataTypeConversion2_a != 0.0);
  rtb_LogicalOperator1_h = !rtb_LogicalOperator_n;
  wrap_PWM_output_fcn(&ICARO3_HAL_v1_B.ManualSwitch1[0],1.0,1.0,1.0,1.0);
  rtb_DataTypeConversion_j = ((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025);
  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.enablemotorscmd_Time) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.enablemotorscmd_Y0;
  } else {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.enablemotorscmd_YFinal;
  }

  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.disnablemotors_Time) {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.disnablemotors_Y0;
  } else {
    rtb_DigitalClock_c = ICARO3_HAL_v1_P.disnablemotors_YFinal;
  }

  rtb_Switch2_oq = rtb_DataTypeConversion2_a + rtb_DigitalClock_c;
  if (((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025) <
      ICARO3_HAL_v1_P.discretetimeRAMP_start) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Step_Y0_e;
  } else {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.discretetimeRAMP_slope;
  }

  rtb_DigitalClock_c = ((ICARO3_HAL_v1_M->Timing.clockTick0) * 0.0025);
  rtb_Switch2 = (rtb_DigitalClock_c - ICARO3_HAL_v1_P.discretetimeRAMP_start) *
    rtb_DataTypeConversion2_a;
  if (ICARO3_HAL_v1_P.ManualSwitch_CurrentSetting_et == 1) {
    rtb_refs_idx_0 = ICARO3_HAL_v1_B.Switch2[0];
    rtb_refs_idx_1 = ICARO3_HAL_v1_B.Switch2[1];
    rtb_refs_idx_2 = ICARO3_HAL_v1_B.Switch2[2];
    rtb_refs_idx_3 = ICARO3_HAL_v1_B.Switch2[3];
  } else {
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 = rtb_Switch2 +
      ICARO3_HAL_v1_P.discretetimeRAMP_X0[0];
    if (rtb_DataTypeConversion_j < ICARO3_HAL_v1_P.calibrateStep_Time) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_Y0[0];
    } else {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_YFinal[0];
    }

    if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 >
        ICARO3_HAL_v1_P.Saturation_UpperSat_c) {
      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
        ICARO3_HAL_v1_P.Saturation_UpperSat_c;
    } else {
      if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 <
          ICARO3_HAL_v1_P.Saturation_LowerSat_j) {
        rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
          ICARO3_HAL_v1_P.Saturation_LowerSat_j;
      }
    }

    rtb_refs_idx_0 = (ICARO3_HAL_v1_P.minspeed_Value[0] +
                      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1)
      * rtb_Switch2_oq + rtb_ManualSwitch3_a_idx_2;
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 = rtb_Switch2 +
      ICARO3_HAL_v1_P.discretetimeRAMP_X0[1];
    if (rtb_DataTypeConversion_j < ICARO3_HAL_v1_P.calibrateStep_Time) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_Y0[1];
    } else {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_YFinal[1];
    }

    if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 >
        ICARO3_HAL_v1_P.Saturation_UpperSat_c) {
      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
        ICARO3_HAL_v1_P.Saturation_UpperSat_c;
    } else {
      if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 <
          ICARO3_HAL_v1_P.Saturation_LowerSat_j) {
        rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
          ICARO3_HAL_v1_P.Saturation_LowerSat_j;
      }
    }

    rtb_refs_idx_1 = (ICARO3_HAL_v1_P.minspeed_Value[1] +
                      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1)
      * rtb_Switch2_oq + rtb_ManualSwitch3_a_idx_2;
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 = rtb_Switch2 +
      ICARO3_HAL_v1_P.discretetimeRAMP_X0[2];
    if (rtb_DataTypeConversion_j < ICARO3_HAL_v1_P.calibrateStep_Time) {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_Y0[2];
    } else {
      rtb_ManualSwitch3_a_idx_2 = ICARO3_HAL_v1_P.calibrateStep_YFinal[2];
    }

    if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 >
        ICARO3_HAL_v1_P.Saturation_UpperSat_c) {
      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
        ICARO3_HAL_v1_P.Saturation_UpperSat_c;
    } else {
      if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 <
          ICARO3_HAL_v1_P.Saturation_LowerSat_j) {
        rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
          ICARO3_HAL_v1_P.Saturation_LowerSat_j;
      }
    }

    rtb_refs_idx_2 = (ICARO3_HAL_v1_P.minspeed_Value[2] +
                      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1)
      * rtb_Switch2_oq + rtb_ManualSwitch3_a_idx_2;
    rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 = rtb_Switch2 +
      ICARO3_HAL_v1_P.discretetimeRAMP_X0[3];
    if (rtb_DataTypeConversion_j < ICARO3_HAL_v1_P.calibrateStep_Time) {
      rtb_DataTypeConversion_j = ICARO3_HAL_v1_P.calibrateStep_Y0[3];
    } else {
      rtb_DataTypeConversion_j = ICARO3_HAL_v1_P.calibrateStep_YFinal[3];
    }

    if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 >
        ICARO3_HAL_v1_P.Saturation_UpperSat_c) {
      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
        ICARO3_HAL_v1_P.Saturation_UpperSat_c;
    } else {
      if (rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 <
          ICARO3_HAL_v1_P.Saturation_LowerSat_j) {
        rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1 =
          ICARO3_HAL_v1_P.Saturation_LowerSat_j;
      }
    }

    rtb_refs_idx_3 = (ICARO3_HAL_v1_P.minspeed_Value[3] +
                      rtb_selectrefpointLATLON0Hover1takeoffpoint2waypoint_idx_1)
      * rtb_Switch2_oq + rtb_DataTypeConversion_j;
  }

  /* number of motors */
  /* define values for 0, 1, and range 255 */
  /* msec */
  rtb_Switch2 = ICARO3_HAL_v1_P.step_Value + ICARO3_HAL_v1_DWork.Delay_DSTATE;
  rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.pwm0ms_Value + rtb_Switch2;
  if (rtb_DataTypeConversion2_a > ICARO3_HAL_v1_P.Saturation_UpperSat_l) {
    rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation_UpperSat_l;
  } else {
    if (rtb_DataTypeConversion2_a < ICARO3_HAL_v1_P.Saturation_LowerSat_ju) {
      rtb_DataTypeConversion2_a = ICARO3_HAL_v1_P.Saturation_LowerSat_ju;
    }
  }

  if (ICARO3_HAL_v1_P.ManualSwitch1_CurrentSetting_m == 1) {
    if (ICARO3_HAL_v1_P.ManualSwitch2_CurrentSetting_g == 1) {
      ICARO3_HAL_v1_B.ManualSwitch1[0] = ICARO3_HAL_v1_P.TestRamp_Value[0];
      ICARO3_HAL_v1_B.ManualSwitch1[1] = ICARO3_HAL_v1_P.TestRamp_Value[1];
      ICARO3_HAL_v1_B.ManualSwitch1[2] = ICARO3_HAL_v1_P.TestRamp_Value[2];
    } else {
      ICARO3_HAL_v1_B.ManualSwitch1[0] = ICARO3_HAL_v1_P.TestSimple_Value[0];
      ICARO3_HAL_v1_B.ManualSwitch1[1] = ICARO3_HAL_v1_P.TestSimple_Value[1];
      ICARO3_HAL_v1_B.ManualSwitch1[2] = ICARO3_HAL_v1_P.TestSimple_Value[2];
    }
  } else {
    if (rtb_refs_idx_0 == 0.0) {
      ICARO3_HAL_v1_B.ManualSwitch1[0] = 0.92;
    } else {
      ICARO3_HAL_v1_B.ManualSwitch1[0] = rtb_refs_idx_0 / 255.0 *
        0.81999999999999984 + 1.12;
    }

    if (rtb_refs_idx_1 == 0.0) {
      ICARO3_HAL_v1_B.ManualSwitch1[1] = 0.92;
    } else {
      ICARO3_HAL_v1_B.ManualSwitch1[1] = rtb_refs_idx_1 / 255.0 *
        0.81999999999999984 + 1.12;
    }

    if (rtb_refs_idx_2 == 0.0) {
      ICARO3_HAL_v1_B.ManualSwitch1[2] = 0.92;
    } else {
      ICARO3_HAL_v1_B.ManualSwitch1[2] = rtb_refs_idx_2 / 255.0 *
        0.81999999999999984 + 1.12;
    }
  }

  if (ICARO3_HAL_v1_P.ManualSwitch1_CurrentSetting_m == 1) {
    if (ICARO3_HAL_v1_P.ManualSwitch2_CurrentSetting_g == 1) {
      ICARO3_HAL_v1_B.ManualSwitch1[3] = rtb_DataTypeConversion2_a;
    } else {
      ICARO3_HAL_v1_B.ManualSwitch1[3] = ICARO3_HAL_v1_P.TestSimple_Value[3];
    }
  } else if (rtb_refs_idx_3 == 0.0) {
    ICARO3_HAL_v1_B.ManualSwitch1[3] = 0.92;
  } else {
    ICARO3_HAL_v1_B.ManualSwitch1[3] = rtb_refs_idx_3 / 255.0 *
      0.81999999999999984 + 1.12;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_h != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_k[0] =
      ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[0];
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_k[1] =
      ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[1];
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken_m != 0)) {
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[0] =
      ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[2];
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[1] =
      ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[3];
    ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[2] =
      ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[4];
  }

  for (i = 0; i < 22; i++) {
    rtb_DataTypeConversion_f[i] = ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[i + 32];
  }

  i_0 = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[0] << 8) +
                  rtb_DataTypeConversion_f[1]);
  i_1 = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[2] << 8) +
                  rtb_DataTypeConversion_f[3]);
  i = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[4] << 8) +
                rtb_DataTypeConversion_f[5]);
  rtb_Switch2_a_0 = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[12] << 8) +
    rtb_DataTypeConversion_f[13]);
  ack = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[14] << 8) +
                  rtb_DataTypeConversion_f[15]);
  newwp = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[16] << 8) +
                    rtb_DataTypeConversion_f[17]);
  wayp_sync_cs = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[18] << 8) +
    rtb_DataTypeConversion_f[19]);
  rtb_mode_out = (int32_T)((uint32_T)(rtb_DataTypeConversion_f[20] << 8) +
    rtb_DataTypeConversion_f[21]);
  if ((uint16_T)i_0 > 32767) {
    rtb_params[0] = (real32_T)(uint16_T)i_0 - 65536.0F;
  } else {
    rtb_params[0] = (uint16_T)i_0;
  }

  if ((uint16_T)i_1 > 32767) {
    rtb_params[1] = (real32_T)(uint16_T)i_1 - 65536.0F;
  } else {
    rtb_params[1] = (uint16_T)i_1;
  }

  if ((uint16_T)i > 32767) {
    rtb_params[2] = (real32_T)(uint16_T)i - 65536.0F;
  } else {
    rtb_params[2] = (uint16_T)i;
  }

  rtb_params[3] = (real32_T)(int32_T)((uint32_T)(rtb_DataTypeConversion_f[6] <<
    8) + rtb_DataTypeConversion_f[7]);
  rtb_params[4] = (real32_T)(int32_T)((uint32_T)(rtb_DataTypeConversion_f[8] <<
    8) + rtb_DataTypeConversion_f[9]);
  rtb_params[5] = (real32_T)(int32_T)((uint32_T)(rtb_DataTypeConversion_f[10] <<
    8) + rtb_DataTypeConversion_f[11]);
  if ((uint16_T)rtb_Switch2_a_0 > 32767) {
    rtb_params[6] = (real32_T)(uint16_T)rtb_Switch2_a_0 - 65536.0F;
  } else {
    rtb_params[6] = (uint16_T)rtb_Switch2_a_0;
  }

  if ((uint16_T)ack > 32767) {
    rtb_params[7] = (real32_T)(uint16_T)ack - 65536.0F;
  } else {
    rtb_params[7] = (uint16_T)ack;
  }

  if ((uint16_T)newwp > 32767) {
    rtb_params[8] = (real32_T)(uint16_T)newwp - 65536.0F;
  } else {
    rtb_params[8] = (uint16_T)newwp;
  }

  if ((uint16_T)wayp_sync_cs > 32767) {
    rtb_params[9] = (real32_T)(uint16_T)wayp_sync_cs - 65536.0F;
  } else {
    rtb_params[9] = (uint16_T)wayp_sync_cs;
  }

  if ((uint16_T)rtb_mode_out > 32767) {
    rtb_params[10] = (real32_T)(uint16_T)rtb_mode_out - 65536.0F;
  } else {
    rtb_params[10] = (uint16_T)rtb_mode_out;
  }

  if (!(ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_h != 0)) {
    for (i = 0; i < 11; i++) {
      ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_f[i] = rtb_params[i];
    }
  }

  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_2) {
    ICARO3_HAL_v1_B.RateTransition_e = ICARO3_HAL_v1_P.HW0SIM_Value;
  }

  rtb_Sum12 = ((((uint32_T)rtb_RateTransition15_m[2] << 24) + ((uint32_T)
    rtb_RateTransition15_m[3] << 16)) + ((uint32_T)rtb_RateTransition15_m[4] <<
    8)) + rtb_RateTransition15_m[5];
  memcpy(&b_u_idx_0, &rtb_Sum12, 4U);
  rtb_DataTypeConversion2_a = b_u_idx_0;
  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_2) {
    ICARO3_HAL_v1_B.RateTransition4_b = rtb_DataTypeConversion2_a;
  }

  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID0_1) {
    ICARO3_HAL_v1_B.downsampleto100Hz[0] = ICARO3_HAL_v1_B.Switch2[0];
    ICARO3_HAL_v1_B.downsampleto100Hz[1] = ICARO3_HAL_v1_B.Switch2[1];
    ICARO3_HAL_v1_B.downsampleto100Hz[2] = ICARO3_HAL_v1_B.Switch2[2];
    ICARO3_HAL_v1_B.downsampleto100Hz[3] = ICARO3_HAL_v1_B.Switch2[3];
    ICARO3_HAL_v1_B.downsampleto100Hz1[0] = ICARO3_HAL_v1_B.RateTransition19[0];
    ICARO3_HAL_v1_B.downsampleto100Hz1[1] = ICARO3_HAL_v1_B.RateTransition19[1];
    ICARO3_HAL_v1_B.downsampleto100Hz1[2] = ICARO3_HAL_v1_B.RateTransition19[2];
    ICARO3_HAL_v1_B.downsampleto100Hz1[3] = ICARO3_HAL_v1_B.RateTransition19[3];
    ICARO3_HAL_v1_B.downsampleto100Hz1[4] = ICARO3_HAL_v1_B.RateTransition20[0];
    ICARO3_HAL_v1_B.downsampleto100Hz1[5] = ICARO3_HAL_v1_B.RateTransition20[1];
    ICARO3_HAL_v1_B.downsampleto100Hz1[6] = ICARO3_HAL_v1_B.RateTransition20[2];
    ICARO3_HAL_v1_B.downsampleto100Hz1[7] = ICARO3_HAL_v1_B.RateTransition20[3];
    ICARO3_HAL_v1_B.downsampleto100Hz1[8] = ICARO3_HAL_v1_P.Constant1_Value_pv[0];
    ICARO3_HAL_v1_B.downsampleto100Hz1[9] = ICARO3_HAL_v1_P.Constant1_Value_pv[1];
    ICARO3_HAL_v1_B.downsampleto100Hz1[10] = ICARO3_HAL_v1_P.Constant1_Value_pv
      [2];
    ICARO3_HAL_v1_B.downsampleto100Hz1[11] = ICARO3_HAL_v1_P.Constant1_Value_pv
      [3];
    ICARO3_HAL_v1_B.downsampleto100Hz3[0] = ICARO3_HAL_v1_B.RC_TRPY_refs[0];
    ICARO3_HAL_v1_B.downsampleto100Hz3[1] = ICARO3_HAL_v1_B.RC_TRPY_refs[1];
    ICARO3_HAL_v1_B.downsampleto100Hz3[2] = ICARO3_HAL_v1_B.RC_TRPY_refs[2];
    ICARO3_HAL_v1_B.downsampleto100Hz3[3] = ICARO3_HAL_v1_B.RC_TRPY_refs[3];
    ICARO3_HAL_v1_B.downsampleto100Hz9 = ICARO3_HAL_v1_B.Switch5;
  }

  ICARO3_HAL_v1_B.LogicalOperator_j = !(ICARO3_HAL_v1_P.HW0SIM_Value != 0.0);
  i_0 = ICARO3_HAL_v1_DWork.RateTransition18_ActiveBufIdx << 1;
  rtb_RateTransition18[0] = ICARO3_HAL_v1_DWork.RateTransition18_Buffer[i_0];
  rtb_RateTransition18[1] = ICARO3_HAL_v1_DWork.RateTransition18_Buffer[1 + i_0];
  memcpy(&b_u_idx_0, &rtb_RateTransition18[0], 4U);
  memcpy(&b_u_idx_0, &rtb_RateTransition18[1], 4U);

  /* compress i2c enable flags into bits: */
  /* MSB [motors press gyro acc mag gyroacc_mpu mag_mpu 0] LSB */
  /*  */
  /* from wrap_i2c_requests.c: */
  /*      output[22 + MOTORS_IDX]          = i2c_enabled[MOTORS_IDX]; */
  /*      output[22 + PRESS_IDX]           = i2c_enabled[PRESS_IDX]; */
  /*      output[22 + GYRO_IDX]            = i2c_enabled[GYRO_IDX]; */
  /*      output[22 + ACC_IDX]             = i2c_enabled[ACC_IDX]; */
  /*      output[22 + MAG_IDX]             = i2c_enabled[MAG_IDX]; */
  /*      output[22 + MPU9150_GYROACC_IDX] = i2c_enabled[MPU9150_GYROACC_IDX]; */
  /*      output[22 + MPU9150_MAG_IDX]     = i2c_enabled[MPU9150_MAG_IDX]; */
  /* +u(7)*2; */
  if (ICARO3_HAL_v1_B.PPMCapture_o3 > ICARO3_HAL_v1_DWork.m) {
    ICARO3_HAL_v1_DWork.m = ICARO3_HAL_v1_B.PPMCapture_o3;
  }

  /* compress i2c enable flags into bits: */
  /* MSB [motors press gyro acc mag 0 0 0 ] LSB */
  /*  */
  /* from wrap_i2c_requests.c: */
  /*      output[22 + MOTORS_IDX] = i2c_enabled[MOTORS_IDX]; */
  /*      output[22 + PRESS_IDX] = i2c_enabled[PRESS_IDX]; */
  /*      output[22 + GYRO_IDX] = i2c_enabled[GYRO_IDX]; */
  /*      output[22 + ACC_IDX] = i2c_enabled[ACC_IDX]; */
  /*      output[22 + MAG_IDX] = i2c_enabled[MAG_IDX]; */
  /*      output[22 + MPU9150_GYROACC_IDX] = i2c_enabled[MPU9150_GYROACC_IDX]; */
  /*      output[22 + MPU9150_MAG_IDX] = i2c_enabled[MPU9150_MAG_IDX]; */
  /* +u(7)*2; */
  /* S-Function Block: <S25>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, ICARO3_HAL_v1_B.lo);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /*  l = 0.28; */
  /*  k = 0.2; */
  /*  F_k = 20; */
  ICARO3_HAL_v1_B.PulseGenerator1 = (ICARO3_HAL_v1_DWork.clockTickCounter_kr <
    ICARO3_HAL_v1_P.PulseGenerator1_Duty_f) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_kr >= 0) ?
    ICARO3_HAL_v1_P.PulseGenerator1_Amp_e : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_kr >=
      ICARO3_HAL_v1_P.PulseGenerator1_Period_l - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_kr = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_kr++;
  }

  /* S-Function Block: <S20>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, ICARO3_HAL_v1_B.PulseGenerator1);
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c4 = rtb_LogicalOperator_k;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE = rtb_UnitDelay_j1;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE = rtb_UnitDelay1;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE = rtb_UnitDelay2;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE = rtb_UnitDelay3;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_id = rtb_LogicalOperator1_k;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_d = rtb_UnitDelay_j3;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_b = rtb_UnitDelay1_k;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_l = rtb_UnitDelay2_g;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_k = rtb_UnitDelay3_ix;
  ICARO3_HAL_v1_DWork.Memory_PreviousInput_o = rtb_Logic_idx_0;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_n = rtb_LogicalOperator3;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_e = rtb_UnitDelay_p5;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_a = rtb_UnitDelay1_f;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_o = rtb_UnitDelay2_h;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_l = rtb_UnitDelay3_n;
  ICARO3_HAL_v1_DWork.Memory_PreviousInput_e = rtb_Logic_i_idx_0;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy = rtb_LogicalOperator4;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_eb = rtb_UnitDelay_g3;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_c = rtb_UnitDelay1_pu;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_ly = rtb_UnitDelay2_or;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_h = rtb_UnitDelay3_p;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_fu = rtb_LogicalOperator5;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_k = rtb_UnitDelay_p;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_j = rtb_UnitDelay1_b;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_i = rtb_UnitDelay2_b;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_g = rtb_UnitDelay3_e;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_h = rtb_LogicalOperator6;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_ds = rtb_UnitDelay_i1;
  ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_e = rtb_UnitDelay1_o;
  ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_e = rtb_UnitDelay2_a;
  ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_kz = rtb_UnitDelay3_l;
  ICARO3_HAL_v1_DWork.Memory_PreviousInput_g = rtb_Logic_d_idx_0;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_e = rtb_Compare_p3;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_ni = rtb_Compare_l;
  ICARO3_HAL_v1_DWork.storeinside_RTH_circleflag_DSTATE = rtb_inside_RTH_circle;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE = ICARO3_HAL_v1_B.Switch_o;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy1 = rtb_Compare_gn;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c = ICARO3_HAL_v1_B.Switch_o;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m = rtb_Sum_hd;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_l * rtb_Divide_e;
  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE >=
      ICARO3_HAL_v1_P.Hvario_x_max_o) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
      ICARO3_HAL_v1_P.Hvario_x_max_o;
  } else {
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE <=
        ICARO3_HAL_v1_P.Hvario_x_min_a) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
        ICARO3_HAL_v1_P.Hvario_x_min_a;
    }
  }

  if (rtb_RelationalOperator) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState = 0;
  }

  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING = 0U;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_a +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_cn * rtb_Gain2_idx_0;
  if (rtb_LogicalOperator3_k) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c = 0;
  }

  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_b =
    rtb_selectrefpointYAW0Hover1takeoffpoint2waypoint2;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_g * rtb_enable_motors_out;
  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k >=
      ICARO3_HAL_v1_P.Hvario_x_max_l) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
      ICARO3_HAL_v1_P.Hvario_x_max_l;
  } else {
    if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k <=
        ICARO3_HAL_v1_P.Hvario_x_min_h) {
      ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
        ICARO3_HAL_v1_P.Hvario_x_min_h;
    }
  }

  if (rtb_RelationalOperator_c) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_h = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_h = 0;
  }

  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_m = 0U;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_e +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_ax * rtb_RateTransition2;
  if (rtb_LogicalOperator3_k) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_k = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_k = 0;
  }

  ICARO3_HAL_v1_DWork.delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt
    = rtb_command_sel_out;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_j = rtb_LogicalOperator1_h;
  ICARO3_HAL_v1_DWork.Memory_PreviousInput = rtb_ahrs_sel_out;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_g = rtb_Switch2_og;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_o = rtb_Compare_pc;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_eq * rtb_Switch2_ag;
  if (rtb_UnitDelay1_nc) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p2 = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p2 = 0;
  }

  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_i = rtb_Switch2_d;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_j = rtb_LowerRelop1_idx_2;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l5 +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_g1 * rtb_Switch2_g;
  if (rtb_UnitDelay1_l) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_o = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_o = 0;
  }

  for (i = 0; i < 7; i++) {
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_bv[i] = rtb_ManualSwitch7[i];
  }

  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_b = rtb_LogicalOperator2_p;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_f = rtb_Switch2_a;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_l = rtb_LogicalOperator2_ni;
  ICARO3_HAL_v1_DWork.Delay_DSTATE = rtb_Switch2;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0025, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_HAL_v1_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void ICARO3_HAL_v1_step1(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DigitalClock_m;
  real_T rtb_DigitalClock_l;
  real_T rtb_scalefactorforresistornetworkfromdirectVmeasures;
  real_T rtb_Product_l;
  real_T rtb_Internal;
  real_T rtb_RateTransition2_k;
  uint32_T rtb_DataTypeConversiononi2cmag1[8];
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion2_em;
  uint16_T rtb_DataTypeConversion3_d[4];
  uint16_T rtb_IndexVector[3];
  uint16_T rtb_Switch_h[3];
  uint16_T rtb_DataTypeConversiononi2cmag1_j[8];
  uint16_T rtb_DataTypeConversiononi2cmag1_c[8];
  boolean_T rtb_UnitDelay1_e;
  boolean_T rtb_UnitDelay1_j;
  real_T rtb_ManualSwitch2;
  real_T rtb_RateTransition4_k[6];
  real_T rtb_RateTransition1[9];
  real_T rtb_RateTransition6_o[2];
  uint8_T rtb_Output_g;
  real_T rtb_Output;
  uint8_T rtb_RateTransition3_h[9];
  uint8_T rtb_DataTypeConversion[9];
  real_T rtb_RateTransition22[5];
  real_T rtb_RateTransition23[3];
  real_T rtb_RateTransition4;
  real_T rtb_RateTransition7[3];
  real_T rtb_RateTransition21;
  real_T rtb_RateTransition14;
  real_T rtb_RateTransition4_a[4];
  real_T rtb_RateTransition15[15];
  real_T rtb_ManualSwitch1_h[6];
  real_T rtb_RateTransition6[6];
  real_T rtb_Sum;
  real_T rtb_RateTransition1_j[2];
  real_T rtb_RateTransition4_o[7];
  boolean_T rtb_LogicalOperator_h;
  real_T rtb_RateTransition10[8];
  boolean_T rtb_LogicalOperator2_o;
  boolean_T rtb_LogicalOperator2_p;
  real_T rtb_Sum_b;
  uint16_T rtb_DataTypeConversion2_p;
  boolean_T rtb_RateTransition14_f;
  boolean_T rtb_notifyONLYafterstoringinitialLLHfordataprojection;
  uint8_T rtb_FixPtSum1;
  int32_T i;
  real_T tmp[6];
  real_T rtb_ManualSwitch1_p;
  boolean_T rtb_Logic_b_idx_0;
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken = 1;
  rtb_ManualSwitch2 = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken = 1;
  for (i = 0; i < 6; i++) {
    rtb_RateTransition4_k[i] = ICARO3_HAL_v1_DWork.RateTransition5_Buffer0[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken = 1;
  memcpy(&rtb_RateTransition1[0], &ICARO3_HAL_v1_DWork.RateTransition1_Buffer0[0],
         9U * sizeof(real_T));
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken = 0;
  rtb_RateTransition6_o[1] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition6_ActiveBufIdx << 1) + 1];
  rtb_Output_g = ICARO3_HAL_v1_DWork.Output_DSTATE;
  rtb_Output = ICARO3_HAL_v1_P.muxer_OutValues[ICARO3_HAL_v1_DWork.Output_DSTATE];
  ICARO3_HAL_v1_DWork.RateTransition3_semaphoreTaken = 1;
  for (i = 0; i < 9; i++) {
    rtb_RateTransition3_h[i] = ICARO3_HAL_v1_DWork.RateTransition3_Buffer0_n[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition3_semaphoreTaken = 0;
  for (i = 0; i < 9; i++) {
    rtb_DataTypeConversion[i] = rtb_RateTransition3_h[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken = 1;
  for (i = 0; i < 5; i++) {
    rtb_RateTransition22[i] = ICARO3_HAL_v1_DWork.RateTransition22_Buffer0[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken = 1;
  rtb_RateTransition23[0] = ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[0];
  rtb_RateTransition23[1] = ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[1];
  rtb_RateTransition23[2] = ICARO3_HAL_v1_DWork.RateTransition23_Buffer0[2];
  ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken = 1;
  rtb_RateTransition4 = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition7_semaphoreTaken = 1;
  rtb_RateTransition7[0] = ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[0];
  rtb_RateTransition7[1] = ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[1];
  rtb_RateTransition7[2] = ICARO3_HAL_v1_DWork.RateTransition7_Buffer0[2];
  ICARO3_HAL_v1_DWork.RateTransition7_semaphoreTaken = 0;
  switch ((int32_T)rtb_Output) {
   case 0:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[2];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 1:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[3];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 2:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[4];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 3:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[5];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 4:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[6];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 5:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[7];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 6:
    rtb_RateTransition22[0] = rtb_DataTypeConversion[8];
    rtb_RateTransition22[1] = 0.0;
    rtb_RateTransition22[2] = 0.0;
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;

   case 7:
    break;

   case 8:
    rtb_RateTransition22[0] = rtb_RateTransition23[0];
    rtb_RateTransition22[1] = rtb_RateTransition23[1];
    rtb_RateTransition22[2] = rtb_RateTransition23[2];
    rtb_RateTransition22[3] = rtb_RateTransition4;
    rtb_RateTransition22[4] = 0.0;
    break;

   default:
    rtb_RateTransition22[0] = rtb_RateTransition7[0];
    rtb_RateTransition22[1] = rtb_RateTransition7[1];
    rtb_RateTransition22[2] = rtb_RateTransition7[2];
    rtb_RateTransition22[3] = 0.0;
    rtb_RateTransition22[4] = 0.0;
    break;
  }

  ICARO3_HAL_v1_B.DataTypeConversionmx2[0] = (real32_T)rtb_ManualSwitch2;
  for (i = 0; i < 6; i++) {
    ICARO3_HAL_v1_B.DataTypeConversionmx2[i + 1] = (real32_T)
      rtb_RateTransition4_k[i];
  }

  for (i = 0; i < 9; i++) {
    ICARO3_HAL_v1_B.DataTypeConversionmx2[i + 7] = (real32_T)
      rtb_RateTransition1[i];
  }

  ICARO3_HAL_v1_B.DataTypeConversionmx2[16] = (real32_T)rtb_RateTransition6_o[1];
  for (i = 0; i < 5; i++) {
    ICARO3_HAL_v1_B.DataTypeConversionmx2[i + 17] = (real32_T)
      rtb_RateTransition22[i];
  }

  wrap_raw_float_downlink_output_width_fcn
    (&ICARO3_HAL_v1_B.DataTypeConversionmx2[0], 22);
  wrap_gpsparser_output_fcn(&ICARO3_HAL_v1_B.SFunction3_o1[0],
    &ICARO3_HAL_v1_B.SFunction3_o2);
  rtb_DigitalClock_m = ((ICARO3_HAL_v1_M->Timing.clockTick1) * 0.01);
  if (ICARO3_HAL_v1_B.SFunction3_o2 * ICARO3_HAL_v1_B.SFunction3_o1[2] >=
      ICARO3_HAL_v1_P.CompareToConstant_const_c) {
    ICARO3_HAL_v1_B.In_c = rtb_DigitalClock_m;
  }

  rtb_Sum_b = rtb_DigitalClock_m - ICARO3_HAL_v1_B.In_c;
  rtb_DigitalClock_l = ((ICARO3_HAL_v1_M->Timing.clockTick1) * 0.01);
  ICARO3_HAL_v1_clocklatch(ICARO3_HAL_v1_B.SFunction3_o2, rtb_DigitalClock_l,
    &ICARO3_HAL_v1_B.clocklatch_m);
  rtb_ManualSwitch2 = rtb_DigitalClock_l - ICARO3_HAL_v1_B.clocklatch_m.In;
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_o = 1;
  rtb_RateTransition23[0] = ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[0];
  rtb_RateTransition23[1] = ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[1];
  rtb_RateTransition23[2] = ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_i[2];
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_o = 0;
  ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken_m = 1;
  rtb_Output = ICARO3_HAL_v1_DWork.RateTransition23_Buffer0_d;
  ICARO3_HAL_v1_DWork.RateTransition23_semaphoreTaken_m = 0;
  ICARO3_HAL_v1_DWork.RateTransition12_semaphoreTaken = 1;
  rtb_RateTransition4 = ICARO3_HAL_v1_DWork.RateTransition12_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition12_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken_a = 1;
  for (i = 0; i < 5; i++) {
    rtb_RateTransition22[i] = ICARO3_HAL_v1_DWork.RateTransition22_Buffer0_d[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition22_semaphoreTaken_a = 0;
  ICARO3_HAL_v1_DWork.RateTransition21_semaphoreTaken = 1;
  rtb_RateTransition21 = ICARO3_HAL_v1_DWork.RateTransition21_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition21_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition14_semaphoreTaken = 1;
  rtb_RateTransition14 = ICARO3_HAL_v1_DWork.RateTransition14_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition14_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_a = 1;
  rtb_RateTransition4_a[0] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[0];
  rtb_RateTransition4_a[1] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[1];
  rtb_RateTransition4_a[2] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[2];
  rtb_RateTransition4_a[3] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_l[3];
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_a = 0;
  i = ICARO3_HAL_v1_DWork.RateTransition11_ActiveBufIdx << 1;
  rtb_RateTransition6_o[0] = ICARO3_HAL_v1_DWork.RateTransition11_Buffer[i];
  rtb_RateTransition6_o[1] = ICARO3_HAL_v1_DWork.RateTransition11_Buffer[1 + i];
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_o = 1;
  rtb_RateTransition7[0] = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[0];
  rtb_RateTransition7[1] = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[1];
  rtb_RateTransition7[2] = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_k[2];
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_o = 0;
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_f = 1;
  for (i = 0; i < 6; i++) {
    rtb_RateTransition4_k[i] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_j[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_f = 0;
  ICARO3_HAL_v1_DWork.RateTransition15_semaphoreTaken = 1;
  memcpy(&rtb_RateTransition15[0],
         &ICARO3_HAL_v1_DWork.RateTransition15_Buffer0[0], 15U * sizeof(real_T));
  ICARO3_HAL_v1_DWork.RateTransition15_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition25_semaphoreTaken = 1;
  for (i = 0; i < 6; i++) {
    rtb_ManualSwitch1_h[i] = ICARO3_HAL_v1_DWork.RateTransition25_Buffer0[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition25_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken = 1;
  for (i = 0; i < 6; i++) {
    rtb_RateTransition6[i] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer0[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken = 0;
  rtb_LogicalOperator_h = (ICARO3_HAL_v1_P.ManualSwitch2_CurrentSetting == 1);
  for (i = 0; i < 6; i++) {
    rtb_ManualSwitch1_p = rtb_ManualSwitch1_h[i];
    if (!rtb_LogicalOperator_h) {
      rtb_ManualSwitch1_p = rtb_RateTransition6[i];
    }

    rtb_ManualSwitch1_h[i] = rtb_ManualSwitch1_p;
  }

  if (ICARO3_HAL_v1_M->Timing.RateInteraction.TID1_4) {
    ICARO3_HAL_v1_B.RateTransition[0] =
      ICARO3_HAL_v1_DWork.RateTransition_Buffer0[0];
    ICARO3_HAL_v1_B.RateTransition[1] =
      ICARO3_HAL_v1_DWork.RateTransition_Buffer0[1];
    ICARO3_HAL_v1_B.RateTransition[2] =
      ICARO3_HAL_v1_DWork.RateTransition_Buffer0[2];
    ICARO3_HAL_v1_B.RateTransition[3] =
      ICARO3_HAL_v1_DWork.RateTransition_Buffer0[3];
  }

  rtb_scalefactorforresistornetworkfromdirectVmeasures =
    ICARO3_HAL_v1_P.Gain16_Gain * ICARO3_HAL_v1_B.RateTransition[0] *
    ICARO3_HAL_v1_P.scalefactorforresistornetworkfromdirectVmeasures_Gain;
  rtb_Product_l = (ICARO3_HAL_v1_P.Gain1_Gain_n *
                   ICARO3_HAL_v1_B.RateTransition[1] -
                   ICARO3_HAL_v1_P.Gain2_Gain * ICARO3_HAL_v1_B.RateTransition[2])
    / ICARO3_HAL_v1_P.Currentsensorsensitivity_Value;

  {
    rtb_Internal = ICARO3_HAL_v1_P.Internal_C_o*
      ICARO3_HAL_v1_DWork.Internal_DSTATE;
  }

  {
    rtb_RateTransition2_k = ICARO3_HAL_v1_P.Internal_C_mn*
      ICARO3_HAL_v1_DWork.Internal_DSTATE_h;
  }

  rtb_Sum = ICARO3_HAL_v1_DWork.integratecurrent_DSTATE;
  rtb_Sum /= ICARO3_HAL_v1_P.hinsec_Value;
  rtb_LogicalOperator_h = (ICARO3_HAL_v1_P.ManualSwitch1_CurrentSetting_d == 1);
  tmp[0] = rtb_scalefactorforresistornetworkfromdirectVmeasures;
  tmp[1] = rtb_Product_l;
  tmp[2] = rtb_Internal;
  tmp[3] = rtb_RateTransition2_k;
  tmp[4] = rtb_Internal * rtb_RateTransition2_k;
  tmp[5] = rtb_Sum;
  for (i = 0; i < 6; i++) {
    rtb_ManualSwitch1_p = rtb_ManualSwitch1_h[i];
    if (!rtb_LogicalOperator_h) {
      rtb_ManualSwitch1_p = tmp[i];
    }

    rtb_ManualSwitch1_h[i] = rtb_ManualSwitch1_p;
  }

  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[0] =
    rtb_RateTransition23[0];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[1] =
    rtb_RateTransition23[1];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[2] =
    rtb_RateTransition23[2];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[3] = rtb_Output;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[4] =
    rtb_RateTransition4;
  for (i = 0; i < 5; i++) {
    ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[i + 5] =
      rtb_RateTransition22[i];
  }

  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[10] =
    rtb_RateTransition21;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[11] =
    ICARO3_HAL_v1_B.SFunction3_o1[0];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[12] =
    ICARO3_HAL_v1_B.SFunction3_o1[1];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[13] =
    rtb_RateTransition14;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[14] =
    rtb_RateTransition4_a[0];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[15] =
    rtb_RateTransition4_a[1];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[16] =
    rtb_RateTransition4_a[2];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[17] =
    rtb_RateTransition4_a[3];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[18] =
    rtb_RateTransition6_o[0];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[19] =
    rtb_RateTransition6_o[1];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[20] =
    rtb_RateTransition7[0];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[21] =
    rtb_RateTransition7[1];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[22] =
    rtb_RateTransition7[2];
  for (i = 0; i < 6; i++) {
    ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[i + 23] =
      rtb_RateTransition4_k[i];
  }

  memcpy(&ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[29],
         &rtb_RateTransition15[0], 15U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[i + 44] =
      rtb_ManualSwitch1_h[i];
  }

  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[50] =
    ICARO3_HAL_v1_B.SFunction3_o1[7];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[51] =
    ICARO3_HAL_v1_B.SFunction3_o1[7];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[52] =
    ICARO3_HAL_v1_B.SFunction3_o1[2];
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[53] =
    ICARO3_HAL_v1_B.SFunction3_o1[6];
  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_k = 1;
  rtb_RateTransition6_o[0] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_f[0];
  rtb_RateTransition6_o[1] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_f[1];
  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_k = 0;
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_a = 1;
  rtb_RateTransition1_j[0] = ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_n[0];
  rtb_RateTransition1_j[1] = ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_n[1];
  ICARO3_HAL_v1_DWork.RateTransition1_semaphoreTaken_a = 0;
  if (ICARO3_HAL_v1_P.ManualSwitch2_CurrentSetting_k != 1) {
    rtb_ManualSwitch2 = rtb_Sum_b;
  }

  rtb_RateTransition21 =
    ICARO3_HAL_v1_P.secto10thofmsecrepresentsavaluefrom01secto255seconaBYTE_Gain
    * rtb_ManualSwitch2;
  rtb_UnitDelay1_e = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_g;
  if (rtb_UnitDelay1_e) {
    rtb_Sum = ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m1;
  } else {
    rtb_Sum = rtb_RateTransition21;
  }

  if ((rtb_RateTransition21 >= rtb_Sum) || rtIsNaN(rtb_Sum)) {
    rtb_RateTransition14 = rtb_RateTransition21;
  } else {
    rtb_RateTransition14 = rtb_Sum;
  }

  if ((!rtb_UnitDelay1_e) &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_g == 1)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_n =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_p;
  }

  rtb_Sum = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_n;
  rtb_UnitDelay1_j = ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_c;
  if ((!rtb_UnitDelay1_j) &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_gc == 1)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_ae;
  }

  rtb_Output = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i;
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_d = 1;
  rtb_RateTransition2_k = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_d;
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_d = 0;
  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_o = 1;
  for (i = 0; i < 7; i++) {
    rtb_RateTransition4_o[i] = ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_ls[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition4_semaphoreTaken_o = 0;
  if (rtb_RateTransition6_o[0] > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[0] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition6_o[0] < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat)
  {
    ICARO3_HAL_v1_B.limittoBYTE0255[0] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[0] = rtb_RateTransition6_o[0];
  }

  if (rtb_RateTransition6_o[1] > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[1] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition6_o[1] < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat)
  {
    ICARO3_HAL_v1_B.limittoBYTE0255[1] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[1] = rtb_RateTransition6_o[1];
  }

  if (rtb_RateTransition1_j[0] > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[2] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition1_j[0] < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat)
  {
    ICARO3_HAL_v1_B.limittoBYTE0255[2] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[2] = rtb_RateTransition1_j[0];
  }

  if (rtb_RateTransition1_j[1] > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[3] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition1_j[1] < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat)
  {
    ICARO3_HAL_v1_B.limittoBYTE0255[3] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[3] = rtb_RateTransition1_j[1];
  }

  if (rtb_RateTransition14 > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[4] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition14 < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[4] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[4] = rtb_RateTransition14;
  }

  if (rtb_Sum > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[5] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_Sum < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[5] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[5] = rtb_Sum;
  }

  if (rtb_Output > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[6] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_Output < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[6] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[6] = rtb_Output;
  }

  if (rtb_RateTransition2_k > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[7] =
      ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
  } else if (rtb_RateTransition2_k < ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat) {
    ICARO3_HAL_v1_B.limittoBYTE0255[7] =
      ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
  } else {
    ICARO3_HAL_v1_B.limittoBYTE0255[7] = rtb_RateTransition2_k;
  }

  for (i = 0; i < 7; i++) {
    if (rtb_RateTransition4_o[i] > ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat) {
      ICARO3_HAL_v1_B.limittoBYTE0255[i + 8] =
        ICARO3_HAL_v1_P.limittoBYTE0255_UpperSat;
    } else if (rtb_RateTransition4_o[i] <
               ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat) {
      ICARO3_HAL_v1_B.limittoBYTE0255[i + 8] =
        ICARO3_HAL_v1_P.limittoBYTE0255_LowerSat;
    } else {
      ICARO3_HAL_v1_B.limittoBYTE0255[i + 8] = rtb_RateTransition4_o[i];
    }
  }

  ICARO3_HAL_v1_DWork.RateTransition9_semaphoreTaken = 1;
  rtb_Sum = ICARO3_HAL_v1_DWork.RateTransition9_Buffer0;
  ICARO3_HAL_v1_DWork.RateTransition9_semaphoreTaken = 0;
  rtb_LogicalOperator_h = ICARO3_HAL_v1_B.LogicalOperator;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport3[0] = rtb_Sum;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport3[1] =
    ICARO3_HAL_v1_B.RateTransition1_j;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport3[2] =
    rtb_LogicalOperator_h;
  ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport3[3] =
    ICARO3_HAL_v1_P.Constant4_Value_h;
  ICARO3_HAL_v1_DWork.RateTransition16_semaphoreTaken = 1;
  for (i = 0; i < 7; i++) {
    ICARO3_HAL_v1_B.RateTransition16[i] =
      ICARO3_HAL_v1_DWork.RateTransition16_Buffer0[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition16_semaphoreTaken = 0;
  ICARO3_HAL_v1_DWork.RateTransition10_semaphoreTaken = 1;
  memcpy(&rtb_RateTransition10[0],
         &ICARO3_HAL_v1_DWork.RateTransition10_Buffer0[0], sizeof(real_T) << 3U);
  ICARO3_HAL_v1_DWork.RateTransition10_semaphoreTaken = 0;
  for (i = 0; i < 7; i++) {
    if (ICARO3_HAL_v1_P.ManualSwitch5_CurrentSetting_o == 1) {
      ICARO3_HAL_v1_B.ManualSwitch5[i] = ICARO3_HAL_v1_P.Constant2_Value_e[i];
    } else {
      ICARO3_HAL_v1_B.ManualSwitch5[i] = rtb_RateTransition10[i];
    }
  }

  wrap_send_to_bs_output_fcn
    (&ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport1[0],
     &ICARO3_HAL_v1_B.limittoBYTE0255[0],
     &ICARO3_HAL_v1_B.TmpSignalConversionAtSFunction2Inport3[0],
     &ICARO3_HAL_v1_B.RateTransition16[0],&ICARO3_HAL_v1_B.ManualSwitch5[0]);
  rtb_Sum = (ICARO3_HAL_v1_DWork.clockTickCounter_e <
             ICARO3_HAL_v1_P.ResetGenerator_Duty_l) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_e >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp_k : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_e >=
      ICARO3_HAL_v1_P.Subsystem2_period_samples - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_e = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_e++;
  }

  rtb_LogicalOperator2_o = !(rtb_Sum != 0.0);
  rtb_Output = ((ICARO3_HAL_v1_P.enableall2_Value !=
                 ICARO3_HAL_v1_P.CompareToConstant1_const_b) !=
                ICARO3_HAL_v1_P.Constant_Value_o);
  rtb_Sum = (ICARO3_HAL_v1_DWork.clockTickCounter_k <
             ICARO3_HAL_v1_P.ResetGenerator_Duty_a) &&
    (ICARO3_HAL_v1_DWork.clockTickCounter_k >= 0) ?
    ICARO3_HAL_v1_P.ResetGenerator_Amp_f : 0.0;
  if (ICARO3_HAL_v1_DWork.clockTickCounter_k >=
      ICARO3_HAL_v1_P.Subsystem6_period_samples - 1.0) {
    ICARO3_HAL_v1_DWork.clockTickCounter_k = 0;
  } else {
    ICARO3_HAL_v1_DWork.clockTickCounter_k++;
  }

  rtb_LogicalOperator2_p = !(rtb_Sum != 0.0);
  rtb_RateTransition7[0] = ICARO3_HAL_v1_B.SFunction3_o1[0];
  rtb_RateTransition7[1] = ICARO3_HAL_v1_B.SFunction3_o1[1];
  rtb_RateTransition7[2] = ICARO3_HAL_v1_B.SFunction3_o1[8];
  rtb_LogicalOperator_h = ((rtb_Sum_b <=
    ICARO3_HAL_v1_P.CompareToConstant_const_ez) &&
    (ICARO3_HAL_v1_B.SFunction3_o1[2] >=
     ICARO3_HAL_v1_P.CompareToConstant1_const_f));
  i = (int32_T)(((((uint32_T)rtb_LogicalOperator_h << 1) +
                  ICARO3_HAL_v1_P.Constant1_Value_o4) << 1) +
                ICARO3_HAL_v1_DWork.Memory_PreviousInput_l);
  rtb_Logic_b_idx_0 = ICARO3_HAL_v1_P.Logic_table_n[(uint32_T)i];
  rtb_LogicalOperator_h = !ICARO3_HAL_v1_P.Logic_table_n[(uint32_T)i];
  rtb_notifyONLYafterstoringinitialLLHfordataprojection =
    ICARO3_HAL_v1_DWork.notifyONLYafterstoringinitialLLHfordataprojection_DSTATE;
  if (ICARO3_HAL_v1_P.Logic_table_n[(uint32_T)i] &&
      ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_nl) {
    for (i = 0; i < 3; i++) {
      ICARO3_HAL_v1_B.LLH_in[i] = 0.0;
      ICARO3_HAL_v1_B.LLH_in[i] += ICARO3_HAL_v1_P.Gain_Gain_f5[i] *
        rtb_RateTransition7[0];
      ICARO3_HAL_v1_B.LLH_in[i] += ICARO3_HAL_v1_P.Gain_Gain_f5[i + 3] *
        rtb_RateTransition7[1];
      ICARO3_HAL_v1_B.LLH_in[i] += ICARO3_HAL_v1_P.Gain_Gain_f5[i + 6] *
        rtb_RateTransition7[2];
    }

    /*  Matrix used to trasform position and velocity from ecef to ned coordinates */
  }

  rtb_Sum = ICARO3_HAL_v1_P.Gain_Gain_b * ICARO3_HAL_v1_B.downsampleto100Hz9 +
    ICARO3_HAL_v1_P.Constant_Value_m;
  rtb_ManualSwitch1_p = floor(rtb_Sum);
  if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
    rtb_ManualSwitch1_p = 0.0;
  } else {
    rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
  }

  rtb_Sum = ICARO3_HAL_v1_P.Gain_Gain_e * rtb_Sum_b +
    ICARO3_HAL_v1_P.Constant_Value_i;
  rtb_RateTransition14_f = ICARO3_HAL_v1_B.LogicalOperator_j;
  if (rtb_RateTransition14_f) {
    wrap_CAN_Transmit_output_fcn(1295.0,
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4.y[0],8U);
    wrap_CAN_Transmit_output_fcn(1311.0,
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4_a.y[0],8U);
    wrap_CAN_Transmit_output_fcn(1327.0,
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4_e.y[0],8U);
    rtb_RateTransition4 = (ICARO3_HAL_v1_DWork.clockTickCounter_j <
      ICARO3_HAL_v1_P.PulseGenerator_Duty) &&
      (ICARO3_HAL_v1_DWork.clockTickCounter_j >= 0) ?
      ICARO3_HAL_v1_P.PulseGenerator_Amp : 0.0;
    if (ICARO3_HAL_v1_DWork.clockTickCounter_j >=
        ICARO3_HAL_v1_P.PulseGenerator_Period - 1.0) {
      ICARO3_HAL_v1_DWork.clockTickCounter_j = 0;
    } else {
      ICARO3_HAL_v1_DWork.clockTickCounter_j++;
    }

    rtb_ManualSwitch2 = floor(rtb_RateTransition4);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion1_a = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    rtb_ManualSwitch2 = floor
      (ICARO3_HAL_v1_P.RepeatingSequenceStair_OutValues[ICARO3_HAL_v1_DWork.Output_DSTATE_k]);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion2_em = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    rtb_ManualSwitch2 = floor(ICARO3_HAL_v1_B.downsampleto100Hz[0]);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion3_d[0] = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    rtb_ManualSwitch2 = floor(ICARO3_HAL_v1_B.downsampleto100Hz[1]);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion3_d[1] = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    rtb_ManualSwitch2 = floor(ICARO3_HAL_v1_B.downsampleto100Hz[2]);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion3_d[2] = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    rtb_ManualSwitch2 = floor(ICARO3_HAL_v1_B.downsampleto100Hz[3]);
    if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
      rtb_ManualSwitch2 = 0.0;
    } else {
      rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
    }

    rtb_DataTypeConversion3_d[3] = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
      rtb_ManualSwitch2);
    switch ((int32_T)
            ICARO3_HAL_v1_P.RepeatingSequenceStair_OutValues[ICARO3_HAL_v1_DWork.Output_DSTATE_k])
    {
     case 0:
      rtb_IndexVector[0] = ICARO3_HAL_v1_B.downsampleto100Hz1[0];
      rtb_IndexVector[1] = ICARO3_HAL_v1_B.downsampleto100Hz1[1];
      rtb_IndexVector[2] = ICARO3_HAL_v1_B.downsampleto100Hz1[2];
      break;

     case 1:
      rtb_IndexVector[0] = ICARO3_HAL_v1_B.downsampleto100Hz1[3];
      rtb_IndexVector[1] = ICARO3_HAL_v1_B.downsampleto100Hz1[4];
      rtb_IndexVector[2] = ICARO3_HAL_v1_B.downsampleto100Hz1[5];
      break;

     case 2:
      rtb_IndexVector[0] = ICARO3_HAL_v1_B.downsampleto100Hz1[6];
      rtb_IndexVector[1] = ICARO3_HAL_v1_B.downsampleto100Hz1[7];
      rtb_IndexVector[2] = ICARO3_HAL_v1_B.downsampleto100Hz1[8];
      break;

     case 3:
      rtb_IndexVector[0] = ICARO3_HAL_v1_B.downsampleto100Hz1[9];
      rtb_IndexVector[1] = ICARO3_HAL_v1_B.downsampleto100Hz1[10];
      rtb_IndexVector[2] = ICARO3_HAL_v1_B.downsampleto100Hz1[11];
      break;

     case 4:
      rtb_IndexVector[0] = ((uint16_T)0U);
      rtb_IndexVector[1] = ((uint16_T)0U);
      rtb_IndexVector[2] = ((uint16_T)0U);
      break;

     default:
      rtb_ManualSwitch2 = floor(0.0);
      if (rtIsNaN(rtb_ManualSwitch2) || rtIsInf(rtb_ManualSwitch2)) {
        rtb_ManualSwitch2 = 0.0;
      } else {
        rtb_ManualSwitch2 = fmod(rtb_ManualSwitch2, 65536.0);
      }

      rtb_IndexVector[0] = (uint16_T)(rtb_ManualSwitch2 < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch2 : (int32_T)(uint16_T)
        rtb_ManualSwitch2);
      rtb_IndexVector[1] = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)(uint16_T)
        rtb_ManualSwitch1_p);
      rtb_ManualSwitch1_p = floor(rtb_Sum);
      if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
        rtb_ManualSwitch1_p = 0.0;
      } else {
        rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
      }

      rtb_IndexVector[2] = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)(uint16_T)
        rtb_ManualSwitch1_p);
      break;
    }

    rtb_FixPtSum1 = (uint8_T)((uint32_T)ICARO3_HAL_v1_DWork.Output_DSTATE_k +
      ICARO3_HAL_v1_P.FixPtConstant_Value);
    if (rtb_FixPtSum1 > ICARO3_HAL_v1_P.LimitedCounter_uplimit) {
      rtb_FixPtSum1 = ICARO3_HAL_v1_P.Constant_Value_ey;
    }

    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion3_d[1],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_e);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion3_d[2],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_h);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion3_d[3],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_k);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion3_d[0],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_m);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz4
      (ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_m.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_e.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_h.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_k.y,
       &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4);
    if (rtb_RateTransition4 >= ICARO3_HAL_v1_P.Switch_Threshold_c) {
      rtb_ManualSwitch1_p = floor(ICARO3_HAL_v1_P.Gain_Gain_a * 0.0 +
        ICARO3_HAL_v1_P.Constant_Value_h);
      if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
        rtb_ManualSwitch1_p = 0.0;
      } else {
        rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
      }

      rtb_DataTypeConversion2_p = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)
        (uint16_T)rtb_ManualSwitch1_p);
      rtb_Switch_h[0] = rtb_DataTypeConversion2_p;
      rtb_Switch_h[1] = rtb_DataTypeConversion2_p;
      rtb_Switch_h[2] = rtb_DataTypeConversion2_p;
    } else {
      rtb_ManualSwitch1_p = floor(ICARO3_HAL_v1_P.Gain_Gain_f *
        ICARO3_HAL_v1_B.downsampleto100Hz3[1] + ICARO3_HAL_v1_P.Constant_Value_a);
      if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
        rtb_ManualSwitch1_p = 0.0;
      } else {
        rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
      }

      rtb_Switch_h[0] = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)(uint16_T)
        rtb_ManualSwitch1_p);
      rtb_ManualSwitch1_p = floor(ICARO3_HAL_v1_P.Gain_Gain_f *
        ICARO3_HAL_v1_B.downsampleto100Hz3[2] + ICARO3_HAL_v1_P.Constant_Value_a);
      if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
        rtb_ManualSwitch1_p = 0.0;
      } else {
        rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
      }

      rtb_Switch_h[1] = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)(uint16_T)
        rtb_ManualSwitch1_p);
      rtb_ManualSwitch1_p = floor(ICARO3_HAL_v1_P.Gain_Gain_f *
        ICARO3_HAL_v1_B.downsampleto100Hz3[3] + ICARO3_HAL_v1_P.Constant_Value_a);
      if (rtIsNaN(rtb_ManualSwitch1_p) || rtIsInf(rtb_ManualSwitch1_p)) {
        rtb_ManualSwitch1_p = 0.0;
      } else {
        rtb_ManualSwitch1_p = fmod(rtb_ManualSwitch1_p, 65536.0);
      }

      rtb_Switch_h[2] = (uint16_T)(rtb_ManualSwitch1_p < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_ManualSwitch1_p : (int32_T)(uint16_T)
        rtb_ManualSwitch1_p);
    }

    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_Switch_h[1],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_o);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_Switch_h[2],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_l);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion1_a,
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_f);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_Switch_h[0],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_i);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz4
      (ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_i.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_o.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_l.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_f.y,
       &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4_a);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_IndexVector[1],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_d);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_IndexVector[2],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_p);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_DataTypeConversion2_em,
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_h);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(rtb_IndexVector[0],
      &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_n);
    ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz4
      (ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_n.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_d.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_p.y,
       ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_h.y,
       &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz4_e);
    ICARO3_HAL_v1_DWork.Output_DSTATE_k = rtb_FixPtSum1;
  }

  wrap_CAN_Receive_output_fcn(&ICARO3_HAL_v1_B.CANRX_o1[0],
    &ICARO3_HAL_v1_P.Rx_ID1_Value,6.0,&ICARO3_HAL_v1_B.CANRX_o2);
  for (i = 0; i < 8; i++) {
    rtb_DataTypeConversiononi2cmag1_j[i] = ICARO3_HAL_v1_B.CANRX_o1[i + 32];
  }

  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_j[2],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_j[4],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_j[6],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_j[0],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5);
  for (i = 0; i < 8; i++) {
    rtb_DataTypeConversiononi2cmag1[i] = ICARO3_HAL_v1_B.CANRX_o1[i + 24];
  }

  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_j
    (&rtb_DataTypeConversiononi2cmag1[4],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_j);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_j
    (&rtb_DataTypeConversiononi2cmag1[0],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_l);
  for (i = 0; i < 8; i++) {
    rtb_DataTypeConversiononi2cmag1_c[i] = ICARO3_HAL_v1_B.CANRX_o1[i + 40];
  }

  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_c[2],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_jl);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_c[4],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_b);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_c[6],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_b);
  ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1
    (&rtb_DataTypeConversiononi2cmag1_c[0],
     &ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_d);
  rtb_FixPtSum1 = (uint8_T)((uint32_T)rtb_Output_g +
    ICARO3_HAL_v1_P.FixPtConstant_Value_o);
  if (rtb_FixPtSum1 > ICARO3_HAL_v1_P.LimitedCounter_uplimit_b) {
    rtb_FixPtSum1 = ICARO3_HAL_v1_P.Constant_Value_ec;
  }

  for (i = 0; i < 8; i++) {
    ICARO3_HAL_v1_DWork.RateTransition14_Buffer[i +
      ((ICARO3_HAL_v1_DWork.RateTransition14_ActiveBufIdx == 0) << 3)] =
      ICARO3_HAL_v1_B.CANRX_o1[i + 8];
  }

  ICARO3_HAL_v1_DWork.RateTransition14_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition14_ActiveBufIdx == 0);
  for (i = 0; i < 8; i++) {
    ICARO3_HAL_v1_DWork.RateTransition15_Buffer[i +
      ((ICARO3_HAL_v1_DWork.RateTransition15_ActiveBufIdx == 0) << 3)] =
      ICARO3_HAL_v1_B.CANRX_o1[i + 16];
  }

  ICARO3_HAL_v1_DWork.RateTransition15_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition15_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.Output_DSTATE = rtb_FixPtSum1;
  for (i = 0; i < 8; i++) {
    ICARO3_HAL_v1_DWork.RateTransition_Buffer[i +
      ((ICARO3_HAL_v1_DWork.RateTransition_ActiveBufIdx == 0) << 3)] =
      ICARO3_HAL_v1_B.CANRX_o1[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition19_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx == 0) << 2] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5.y;
  ICARO3_HAL_v1_DWork.RateTransition19_Buffer[1 +
    ((ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1.y;
  ICARO3_HAL_v1_DWork.RateTransition19_Buffer[2 +
    ((ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2.y;
  ICARO3_HAL_v1_DWork.RateTransition19_Buffer[3 +
    ((ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3.y;
  ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition19_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition20_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx == 0) << 2] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_d.y;
  ICARO3_HAL_v1_DWork.RateTransition20_Buffer[1 +
    ((ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_jl.y;
  ICARO3_HAL_v1_DWork.RateTransition20_Buffer[2 +
    ((ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz2_b.y;
  ICARO3_HAL_v1_DWork.RateTransition20_Buffer[3 +
    ((ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx == 0) << 2)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz3_b.y;
  ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition20_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_a = rtb_Sum_b;
  ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_l =
    rtb_notifyONLYafterstoringinitialLLHfordataprojection;
  memcpy(&ICARO3_HAL_v1_DWork.RateTransition1_Buffer
         [(ICARO3_HAL_v1_DWork.RateTransition1_ActiveBufIdx == 0) * 10],
         &ICARO3_HAL_v1_B.SFunction3_o1[0], 10U * sizeof(real_T));
  ICARO3_HAL_v1_DWork.RateTransition1_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition1_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[0] = ICARO3_HAL_v1_B.LLH_in[0];
  ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[1] = ICARO3_HAL_v1_B.LLH_in[1];
  ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[2] = ICARO3_HAL_v1_B.LLH_in[2];

  {
    real_T xnew[1];
    xnew[0] = ICARO3_HAL_v1_P.Internal_A_ld*ICARO3_HAL_v1_DWork.Internal_DSTATE;
    xnew[0] += ICARO3_HAL_v1_P.Internal_B_g4*
      rtb_scalefactorforresistornetworkfromdirectVmeasures;
    (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  {
    real_T xnew[1];
    xnew[0] = ICARO3_HAL_v1_P.Internal_A_ee*
      ICARO3_HAL_v1_DWork.Internal_DSTATE_h;
    xnew[0] += ICARO3_HAL_v1_P.Internal_B_po*rtb_Product_l;
    (void) memcpy(&ICARO3_HAL_v1_DWork.Internal_DSTATE_h, xnew,
                  sizeof(real_T)*1);
  }

  ICARO3_HAL_v1_DWork.integratecurrent_DSTATE +=
    ICARO3_HAL_v1_P.integratecurrent_gainval * rtb_Product_l;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m1 = rtb_RateTransition14;
  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_g = rtb_LogicalOperator2_o;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_n +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_p * rtb_RateTransition21;
  if (rtb_UnitDelay1_e) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_g = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_g = 0;
  }

  ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_c = rtb_LogicalOperator2_p;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_ah * rtb_Output;
  if (rtb_UnitDelay1_j) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_gc = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_gc = 0;
  }

  ICARO3_HAL_v1_DWork.Memory_PreviousInput_l = rtb_Logic_b_idx_0;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_nl = rtb_LogicalOperator_h;
  ICARO3_HAL_v1_DWork.notifyONLYafterstoringinitialLLHfordataprojection_DSTATE =
    rtb_Logic_b_idx_0;
  ICARO3_HAL_v1_DWork.RateTransition18_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition18_ActiveBufIdx == 0) << 1] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz5_l.y;
  ICARO3_HAL_v1_DWork.RateTransition18_Buffer[1 +
    ((ICARO3_HAL_v1_DWork.RateTransition18_ActiveBufIdx == 0) << 1)] =
    ICARO3_HAL_v1_B.sf_MATLABFunctioncomputegyroxyz1_j.y;
  ICARO3_HAL_v1_DWork.RateTransition18_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition18_ActiveBufIdx == 0);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_HAL_v1_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void ICARO3_HAL_v1_step2(void)         /* Sample time: [0.02s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Switch2_h[2];
  real32_T rtb_DataTypeConversionmx8_l;
  real_T currentTime;
  real32_T X1;
  uint8_T rtb_RateTransition10;
  uint8_T rtb_RateTransition6[2];
  uint8_T rtb_RateTransition5[3];
  uint8_T rtb_RateTransition1;
  uint32_T rtb_UP;
  real32_T rtb_T;
  real_T rtb_Step1_g;
  real_T rtb_Switch2;
  real32_T rtb_RateTransition2[11];
  int32_T i;
  uint32_T qY;
  rtb_RateTransition10 = ICARO3_HAL_v1_P.bmp085accuracylevel_Value;
  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_h = 1;
  rtb_RateTransition6[0] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_k[0];
  rtb_RateTransition6[1] = ICARO3_HAL_v1_DWork.RateTransition6_Buffer0_k[1];
  ICARO3_HAL_v1_DWork.RateTransition6_semaphoreTaken_h = 0;
  ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken_m = 1;
  rtb_RateTransition5[0] = ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[0];
  rtb_RateTransition5[1] = ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[1];
  rtb_RateTransition5[2] = ICARO3_HAL_v1_DWork.RateTransition5_Buffer0_f[2];
  ICARO3_HAL_v1_DWork.RateTransition5_semaphoreTaken_m = 0;
  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_h = 1;
  for (i = 0; i < 11; i++) {
    rtb_RateTransition2[i] = ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_f[i];
  }

  ICARO3_HAL_v1_DWork.RateTransition2_semaphoreTaken_h = 0;
  rtb_RateTransition1 = ICARO3_HAL_v1_B.Switch4[4];
  i = (int32_T)((uint32_T)(rtb_RateTransition6[0] << 8) + rtb_RateTransition6[1]);

  /* UP = bitshift(UP_bytes(1), 8) + UP_bytes(2); */
  rtb_UP = (uint32_T)rtb_RateTransition5[0] << 16U;
  qY = ((uint32_T)rtb_RateTransition5[1] << 8U) + rtb_UP;
  if (qY < rtb_UP) {
    qY = MAX_uint32_T;
  }

  rtb_UP = qY + rtb_RateTransition5[2];
  if (rtb_UP < qY) {
    rtb_UP = MAX_uint32_T;
  }

  if (rtb_RateTransition10 - 8 < 0) {
    rtb_UP >>= (uint32_T)rt_roundf_snf(-(-(8.0F - (real32_T)rtb_RateTransition10)));
  } else if (rtb_RateTransition10 - 8 <= 31) {
    rtb_UP <<= (uint32_T)rt_roundf_snf(-(8.0F - (real32_T)rtb_RateTransition10));
  } else {
    rtb_UP = 0U;
  }

  /* UP = 0; */
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
  if ((((uint16_T)i == 0) && (rtb_UP == 0.0F)) || (rtb_RateTransition1 == 0)) {
    rtb_T = 0.0F;
    X1 = 0.0F;
  } else {
    X1 = ((real32_T)(uint16_T)i - rtb_RateTransition2[5]) * rtb_RateTransition2
      [4] / 32768.0F;
    X1 += rtb_RateTransition2[9] * 2048.0F / (X1 + rtb_RateTransition2[10]);
    rtb_T = (X1 + 8.0F) / 16.0F;
    X1 = ((real32_T)rtb_UP - ((((X1 - 4000.0F) * (X1 - 4000.0F) / 4096.0F *
             rtb_RateTransition2[7] / 2048.0F + (X1 - 4000.0F) *
             rtb_RateTransition2[1] / 2048.0F) + rtb_RateTransition2[0] * 4.0F) *
           rt_powf_snf(2.0F, (real32_T)rtb_RateTransition10) + 2.0F) / 4.0F) *
      50000.0F / rt_powf_snf(2.0F, (real32_T)rtb_RateTransition10) * 2.0F /
      (((((X1 - 4000.0F) * (X1 - 4000.0F) / 4096.0F * rtb_RateTransition2[6] /
          65536.0F + (X1 - 4000.0F) * rtb_RateTransition2[2] / 8192.0F) + 2.0F) /
        4.0F + 32768.0F) * rtb_RateTransition2[3] / 32768.0F);
    X1 += ((X1 / 256.0F * (X1 / 256.0F) * 3038.0F / 65536.0F + -7357.0F * X1 /
            65536.0F) + 3791.0F) / 16.0F;
    X1 = (1.0F - rt_powf_snf(X1 / 101325.0F, 0.190294951F)) * 44330.0F;
  }

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
  if (ICARO3_HAL_v1_B.RateTransition_e >= ICARO3_HAL_v1_P.Switch2_Threshold_c) {
    rtb_Switch2_h[0] = ICARO3_HAL_v1_P.Gain1_Gain_h * rtb_T;
    rtb_Switch2_h[1] = ICARO3_HAL_v1_P.Gain2_Gain_a * X1;
  } else {
    rtb_Switch2_h[0] = ICARO3_HAL_v1_P.Constant2_Value_o;
    rtb_Switch2_h[1] = ICARO3_HAL_v1_B.RateTransition4_b;
  }

  currentTime = ((ICARO3_HAL_v1_M->Timing.clockTick2) * 0.02);
  rtb_Switch2 = ((ICARO3_HAL_v1_M->Timing.clockTick2) * 0.02);
  if (rtb_Switch2 < ICARO3_HAL_v1_P.Step1_Time_l) {
    rtb_Step1_g = ICARO3_HAL_v1_P.Step1_Y0_f;
  } else {
    rtb_Step1_g = ICARO3_HAL_v1_P.Step1_YFinal_k;
  }

  if (currentTime < ICARO3_HAL_v1_P.Step_Time_f) {
    currentTime = ICARO3_HAL_v1_P.Step_Y0_g;
  } else {
    currentTime = ICARO3_HAL_v1_P.Step_YFinal_a;
  }

  rtb_DataTypeConversionmx8_l = (real32_T)(currentTime - rtb_Step1_g);
  ICARO3_HAL_v1_Subsystem(rtb_DataTypeConversionmx8_l, rtb_Switch2_h[1],
    &ICARO3_HAL_v1_B.Subsystem_a, &ICARO3_HAL_v1_DWork.Subsystem_a,
    (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_a);
  if (rtb_DataTypeConversionmx8_l >= ICARO3_HAL_v1_P.Switch2_Threshold_oz) {
    rtb_Switch2 = ICARO3_HAL_v1_P.Constant1_Value_h1r;
  } else {
    rtb_Switch2 = rtb_Switch2_h[1] - ICARO3_HAL_v1_B.Subsystem_a.Product1;
  }

  ICARO3_HAL_v1_DWork.RateTransition6_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition6_ActiveBufIdx == 0) << 1] =
    rtb_Switch2_h[0];
  ICARO3_HAL_v1_DWork.RateTransition6_Buffer[1 +
    ((ICARO3_HAL_v1_DWork.RateTransition6_ActiveBufIdx == 0) << 1)] =
    rtb_Switch2_h[1];
  ICARO3_HAL_v1_DWork.RateTransition6_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition6_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition2_Buffer[ICARO3_HAL_v1_DWork.RateTransition2_ActiveBufIdx
    == 0] = rtb_Step1_g;
  ICARO3_HAL_v1_DWork.RateTransition2_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition2_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition3_Buffer[ICARO3_HAL_v1_DWork.RateTransition3_ActiveBufIdx
    == 0] = rtb_Switch2;
  ICARO3_HAL_v1_DWork.RateTransition3_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition3_ActiveBufIdx == 0);
  ICARO3_HAL_v1_DWork.RateTransition11_Buffer
    [(ICARO3_HAL_v1_DWork.RateTransition11_ActiveBufIdx == 0) << 1] =
    rtb_Switch2_h[0];
  ICARO3_HAL_v1_DWork.RateTransition11_Buffer[1 +
    ((ICARO3_HAL_v1_DWork.RateTransition11_ActiveBufIdx == 0) << 1)] =
    rtb_Switch2_h[1];
  ICARO3_HAL_v1_DWork.RateTransition11_ActiveBufIdx = (int8_T)
    (ICARO3_HAL_v1_DWork.RateTransition11_ActiveBufIdx == 0);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ICARO3_HAL_v1_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void ICARO3_HAL_v1_step3(void)         /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Gain3_c;
  real_T rtb_Gain4_e;
  real_T rtb_Gain5_b;
  real_T rtb_Gain6_o;
  boolean_T rtb_LogicalOperator3_bc;
  real_T err_chi;
  real_T correzione;
  real_T scale;
  real_T t;
  real_T rtb_rad2deg2;
  real_T rtb_nrWP;
  real_T rtb_d;
  real_T err_position_idx_0;
  real_T rtb_Act_WP_idx_2;
  real_T rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0;
  real_T rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1;
  rtb_Gain3_c = ICARO3_HAL_v1_P.Gain3_Gain_hvp * ICARO3_HAL_v1_B.ZeroOrderHold1
    [0];
  rtb_Gain4_e = ICARO3_HAL_v1_P.Gain4_Gain_l * ICARO3_HAL_v1_B.ZeroOrderHold1[1];
  rtb_Gain5_b = ICARO3_HAL_v1_P.Gain5_Gain_g * ICARO3_HAL_v1_P.Constant1_Value_g;
  rtb_Gain6_o = ICARO3_HAL_v1_P.Gain6_Gain_n * ICARO3_HAL_v1_P.Constant2_Value_i;
  ICARO3_HAL_v1_MATLABFunction6(ICARO3_HAL_v1_B.ZeroOrderHold3[0],
    ICARO3_HAL_v1_B.ZeroOrderHold3[1], rtb_Gain3_c, rtb_Gain4_e,
    &ICARO3_HAL_v1_B.sf_MATLABFunction6_a);/*    INPUT */

  /*    [Current Heading, Current position (X,Y)] */
  /*    OUTPUT */
  /*    [Active WP, num of remaining WP] */
  /*  Structure of the  */
  /*  ARRAY_WPT(i,:) = [Xw,Yw,CHIw] */
  /*  Index of the actual waypoint */
  /*  Flag that is setted when final WP of the ARRAY_WPT is reached */
  /*  Active WP Heading */
  /*  Active WP Position */
  /*  Errors */
  /* -------------------------------------------------------------------------- */
  correzione = 0.0;
  for (err_chi = ICARO3_HAL_v1_B.RateTransition2 - ICARO3_HAL_v1_P.ARRAY_WPT
       [(int32_T)ICARO3_HAL_v1_DWork.INDICE + 11]; err_chi < -3.1415926535897931;
       err_chi = ICARO3_HAL_v1_B.RateTransition2 - (correzione * 2.0 *
        3.1415926535897931 + ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
        ICARO3_HAL_v1_DWork.INDICE + 11])) {
    correzione--;
  }

  while (err_chi > 3.1415926535897931) {
    correzione++;
    err_chi = ICARO3_HAL_v1_B.RateTransition2 - (correzione * 2.0 *
      3.1415926535897931 + ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
      ICARO3_HAL_v1_DWork.INDICE + 11]);
  }

  /* -------------------------------------------------------------------------- */
  /*  Verify satisfation of the Error Threshold */
  scale = 2.2250738585072014E-308;
  rtb_rad2deg2 = fabs(ICARO3_HAL_v1_B.ZeroOrderHold1[0] -
                      ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
                      ICARO3_HAL_v1_DWork.INDICE - 1]);
  if (rtb_rad2deg2 > 2.2250738585072014E-308) {
    correzione = 1.0;
    scale = rtb_rad2deg2;
  } else {
    t = rtb_rad2deg2 / 2.2250738585072014E-308;
    correzione = t * t;
  }

  rtb_rad2deg2 = fabs(ICARO3_HAL_v1_B.ZeroOrderHold1[1] -
                      ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
                      ICARO3_HAL_v1_DWork.INDICE + 5]);
  if (rtb_rad2deg2 > scale) {
    t = scale / rtb_rad2deg2;
    correzione = correzione * t * t + 1.0;
    scale = rtb_rad2deg2;
  } else {
    t = rtb_rad2deg2 / scale;
    correzione += t * t;
  }

  correzione = scale * sqrt(correzione);
  if ((correzione < ICARO3_HAL_v1_P.ET[0] / 100000.0) && (fabs(err_chi) <
       ICARO3_HAL_v1_P.ET[1] * 0.017453292519943295)) {
    if (ICARO3_HAL_v1_DWork.INDICE < 6.0) {
      ICARO3_HAL_v1_DWork.INDICE++;
    } else {
      if (ICARO3_HAL_v1_DWork.INDICE == 6.0) {
        ICARO3_HAL_v1_DWork.End_WPset = 1.0;
      }
    }
  }

  /*  Number of remaining WP */
  if (ICARO3_HAL_v1_DWork.End_WPset != 0.0) {
    rtb_nrWP = 0.0;
  } else {
    rtb_nrWP = (6.0 - ICARO3_HAL_v1_DWork.INDICE) + 1.0;
  }

  /*  Active Waypoint */
  rtb_Act_WP_idx_2 = ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
    ICARO3_HAL_v1_DWork.INDICE + 11];

  /*  latr -> reference system origin latitude */
  /*  lonr -> reference system origin longitude */
  /*  hr -> reference system origin altitude */
  /*  lat -> object latitude */
  /*  lon -> object longitude */
  /*  h -> object altitude */
  /*  cog -> course over groung */
  /*  sog -> speed over ground */
  /*  eccentricity squared */
  /*  semi-major axis */
  /* Flamsteed or natural projection: LL to NED */
  /*  compute R_normal */
  /* PolarRad = sqrt((1-e2)*a*a); */
  /* planar_N = a*a/sqrt(a*a*cos(latr)*cos(latr)+PolarRad*PolarRad*sin(latr)*sin(latr)); */
  correzione = sin(ICARO3_HAL_v1_B.ZeroOrderHold3[0]);
  correzione = 6.378137E+6 / sqrt(1.0 - correzione * correzione * 0.00669438);

  /*  NED velocities (x-y) */
  rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0 =
    (ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)ICARO3_HAL_v1_DWork.INDICE - 1] *
     ICARO3_HAL_v1_P.Gain3_Gain_d - ICARO3_HAL_v1_B.ZeroOrderHold3[0]) *
    correzione;
  rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1 =
    (ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)ICARO3_HAL_v1_DWork.INDICE + 5] *
     ICARO3_HAL_v1_P.Gain4_Gain_m - ICARO3_HAL_v1_B.ZeroOrderHold3[1]) *
    (correzione * cos(ICARO3_HAL_v1_B.ZeroOrderHold3[0]));
  scale = 2.2250738585072014E-308;
  rtb_rad2deg2 = fabs(ICARO3_HAL_v1_B.sf_MATLABFunction6_a.x -
                      rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0);
  if (rtb_rad2deg2 > 2.2250738585072014E-308) {
    rtb_d = 1.0;
    scale = rtb_rad2deg2;
  } else {
    t = rtb_rad2deg2 / 2.2250738585072014E-308;
    rtb_d = t * t;
  }

  rtb_rad2deg2 = fabs(ICARO3_HAL_v1_B.sf_MATLABFunction6_a.y -
                      rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1);
  if (rtb_rad2deg2 > scale) {
    t = scale / rtb_rad2deg2;
    rtb_d = rtb_d * t * t + 1.0;
    scale = rtb_rad2deg2;
  } else {
    t = rtb_rad2deg2 / scale;
    rtb_d += t * t;
  }

  rtb_d = scale * sqrt(rtb_d);

  /*  error rotation matrix */
  t = ICARO3_HAL_v1_B.sf_MATLABFunction6_a.x -
    rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0;
  rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0 =
    ICARO3_HAL_v1_B.sf_MATLABFunction6_a.y -
    rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1;
  err_position_idx_0 = cos(ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
    ICARO3_HAL_v1_DWork.INDICE + 11] + 1.5707963267948966) * t + sin
    (ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)ICARO3_HAL_v1_DWork.INDICE + 11] +
     1.5707963267948966) * rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0;
  rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1 = -sin
    (ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)ICARO3_HAL_v1_DWork.INDICE + 11] +
     1.5707963267948966) * t + cos(ICARO3_HAL_v1_P.ARRAY_WPT[(int32_T)
    ICARO3_HAL_v1_DWork.INDICE + 11] + 1.5707963267948966) *
    rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0;
  ICARO3_HAL_v1_MATLABFunction2(0.0, &ICARO3_HAL_v1_B.sf_MATLABFunction2,
    &ICARO3_HAL_v1_DWork.sf_MATLABFunction2);
  rtb_LogicalOperator3_bc = ((ICARO3_HAL_v1_B.ZeroOrderHold2 ==
    ICARO3_HAL_v1_P.CompareToConstant_const_f) &&
    (ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_p !=
     ICARO3_HAL_v1_P.CompareToConstant1_const_p));
  correzione = ICARO3_HAL_v1_P.rad2deg1_Gain * ICARO3_HAL_v1_B.RateTransition2;
  if (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_k != 0) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_er = correzione;
  }

  if (rtb_LogicalOperator3_bc &&
      (ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p <= 0)) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_er = correzione;
  }

  correzione = ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_er;
  err_chi = ICARO3_HAL_v1_P.rad2deg_Gain * ICARO3_HAL_v1_B.sf_MATLABFunction2.y
    - ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_er;
  t = -ICARO3_HAL_v1_P.ResetableslewratelimiterYAWwithextresetvalue_slew_rate_SR
    * ICARO3_HAL_v1_P.ResetableslewratelimiterYAWwithextresetvalue_slew_rate_ST;
  rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0 =
    ICARO3_HAL_v1_P.ResetableslewratelimiterYAWwithextresetvalue_slew_rate_SR *
    ICARO3_HAL_v1_P.ResetableslewratelimiterYAWwithextresetvalue_slew_rate_ST;
  if (err_chi > rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0) {
    err_chi = rtb_TmpSignalConversionAtSFunctionInport3_a_idx_0;
  } else {
    if (err_chi < t) {
      err_chi = t;
    }
  }

  scale = ICARO3_HAL_v1_P.gain_Gain * 0.0;
  rtb_rad2deg2 = ICARO3_HAL_v1_P.rad2deg2_Gain * rtb_Act_WP_idx_2;
  ICARO3_HAL_v1_DWork.RateTransition3_Buffer0 = rtb_nrWP;
  ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_p = ICARO3_HAL_v1_B.ZeroOrderHold2;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_k = 0U;
  ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_er +=
    ICARO3_HAL_v1_P.DiscreteTimeIntegrator_gainval_h * err_chi;
  if (rtb_LogicalOperator3_bc) {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p = 1;
  } else {
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p = 0;
  }

  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[0] = rtb_d;
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[1] = err_position_idx_0;
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[2] =
    rtb_TmpSignalConversionAtSFunctionInport3_a_idx_1;
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[3] = scale;
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[4] = correzione;
  ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[5] = rtb_rad2deg2;
  ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_d = correzione;
}

/* Model step function for TID4 */
void ICARO3_HAL_v1_step4(void)         /* Sample time: [1.0s, 0.0s] */
{
  uint32_T rtb_DataTypeConversion[4];
  wrap_pm_init_output_fcn();
  wrap_ADC_Receive_output_fcn(&ICARO3_HAL_v1_B.PWM1[0]);
  rtb_DataTypeConversion[0] = ICARO3_HAL_v1_B.PWM1[0];
  rtb_DataTypeConversion[1] = ICARO3_HAL_v1_B.PWM1[1];
  rtb_DataTypeConversion[2] = ICARO3_HAL_v1_B.PWM1[2];
  rtb_DataTypeConversion[3] = ICARO3_HAL_v1_B.PWM1[3];
  ICARO3_HAL_v1_DWork.a = (ICARO3_HAL_v1_DWork.a + 1.0) - floor
    ((ICARO3_HAL_v1_DWork.a + 1.0) / 2.0) * 2.0;
  ICARO3_HAL_v1_DWork.RateTransition_Buffer0[0] = rtb_DataTypeConversion[0];
  ICARO3_HAL_v1_DWork.RateTransition_Buffer0[1] = rtb_DataTypeConversion[1];
  ICARO3_HAL_v1_DWork.RateTransition_Buffer0[2] = rtb_DataTypeConversion[2];
  ICARO3_HAL_v1_DWork.RateTransition_Buffer0[3] = rtb_DataTypeConversion[3];
}

/* Model step wrapper function for compatibility with a static main program */
void ICARO3_HAL_v1_step(int_T tid)
{
  switch (tid) {
   case 0 :
    ICARO3_HAL_v1_step0();
    break;

   case 1 :
    ICARO3_HAL_v1_step1();
    break;

   case 2 :
    ICARO3_HAL_v1_step2();
    break;

   case 3 :
    ICARO3_HAL_v1_step3();
    break;

   case 4 :
    ICARO3_HAL_v1_step4();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ICARO3_HAL_v1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ICARO3_HAL_v1_P.Hvario_x_max_l = rtInf;
  ICARO3_HAL_v1_P.Hvario_x_min_h = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)ICARO3_HAL_v1_M, 0,
                sizeof(RT_MODEL_ICARO3_HAL_v1));

  /* block I/O */
  (void) memset(((void *) &ICARO3_HAL_v1_B), 0,
                sizeof(BlockIO_ICARO3_HAL_v1));

  /* states (dwork) */
  (void) memset((void *)&ICARO3_HAL_v1_DWork, 0,
                sizeof(D_Work_ICARO3_HAL_v1));

  {
    int32_T i;
    wrap_I2C1_sensors_loop_start_fcn(&ICARO3_HAL_v1_B.I2C1SensorsLoop_o1[0],
      &ICARO3_HAL_v1_B.I2C1SensorsLoop_o2);
    ICARO3_HAL_v1_Subsystem_Start(&ICARO3_HAL_v1_DWork.Subsystem,
      (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_h,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_h);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_e,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_m,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_m);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_e5,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e5);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_i,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_i);
    wrap_rcv_from_bs_start_fcn(&ICARO3_HAL_v1_B.SFunction_o1[0],
      &ICARO3_HAL_v1_B.SFunction_o2[0], &ICARO3_HAL_v1_B.SFunction_o3[0],
      &ICARO3_HAL_v1_B.SFunction_o4);
    ICARO3_HAL_v1_Subsystem_Start(&ICARO3_HAL_v1_DWork.Subsystem_c,
      (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_c);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_p,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_p);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_n,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_n);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_e1,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e1);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_f,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_f);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_e4,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_e4);
    ICARO3_HAL_v1_AttitudeFilterADIS_Start(&ICARO3_HAL_v1_B.AttitudeFilterSS,
      &ICARO3_HAL_v1_DWork.AttitudeFilterSS,
      (rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.AttitudeFilterSS);
    wrap_PPM_start_fcn();
    ICARO3_HAL_v1_B.RateTransition19[0] = ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_B.RateTransition19[1] = ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_B.RateTransition19[2] = ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_B.RateTransition19[3] = ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_B.RateTransition20[0] = ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_B.RateTransition20[1] = ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_B.RateTransition20[2] = ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_B.RateTransition20[3] = ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_B.In = ICARO3_HAL_v1_P.Out_Y0_o;
    ICARO3_HAL_v1_B.RateTransition3 = ICARO3_HAL_v1_P.RateTransition3_X0;
    ICARO3_HAL_v1_clocklatch_Start(&ICARO3_HAL_v1_B.clocklatch_a,
      (rtP_clocklatch_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.clocklatch_a);
    ICARO3_HAL_v1_B.RateTransition1 = ICARO3_HAL_v1_P.RateTransition1_X0;
    ICARO3_HAL_v1_B.RateTransition2_b = ICARO3_HAL_v1_P.RateTransition2_X0_j;
    ICARO3_HAL_v1_Subsystem_Start(&ICARO3_HAL_v1_DWork.Subsystem_l,
      (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_l);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_b,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_b);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_o,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_o);
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_j =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_kb =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC;
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_n4,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_n4);
    ICARO3_HAL_v1_Subsystem_d_Start(&ICARO3_HAL_v1_DWork.Subsystem_d,
      (rtP_Subsystem_ICARO3_HAL_v1_o *)&ICARO3_HAL_v1_P.Subsystem_d);
    ICARO3_HAL_v1_AttitudeFilterADIS_Start(&ICARO3_HAL_v1_B.AttitudeFilterADIS,
      &ICARO3_HAL_v1_DWork.AttitudeFilterADIS,
      (rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *)
      &ICARO3_HAL_v1_P.AttitudeFilterADIS);
    ICARO3_HAL_v1_AttitudeFilterADIS_Start(&ICARO3_HAL_v1_B.AttitudeFilterMPU,
      &ICARO3_HAL_v1_DWork.AttitudeFilterMPU,
      (rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.AttitudeFilterMPU);
    wrap_raw_float_downlink_start_fcn();
    ICARO3_HAL_v1_DWork.clockTickCounter = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_n = 0;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_kb =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_i;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_jq =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_a;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE_l =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_IC;
    ICARO3_HAL_v1_B.DiscreteTimeIntegrator1_i = ICARO3_HAL_v1_P.h_Y0;
    ICARO3_HAL_v1_B.Sum1_j = ICARO3_HAL_v1_P.hd_Y0;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_b =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_g;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_os =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_e;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator2_DSTATE =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator2_IC_l;
    ICARO3_HAL_v1_B.DiscreteTimeIntegrator1 = ICARO3_HAL_v1_P.h_Y0_a;
    ICARO3_HAL_v1_B.Sum1_g = ICARO3_HAL_v1_P.hd_Y0_m;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_in =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition;
    ICARO3_HAL_v1_DWork.h_ref_not_empty_b = false;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i5 =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_n;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c0 = 2;
    ICARO3_HAL_v1_DWork.h_ref_not_empty = false;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_am =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_k;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_o = 1U;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_om = 2;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_ah = ICARO3_HAL_v1_P.Internal_X0;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_pq =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_b;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_ax = ICARO3_HAL_v1_P.Internal_X0_h;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_ap =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_g;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_lk = ICARO3_HAL_v1_P.Internal_X0_d;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_g =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_h;
    ICARO3_HAL_v1_B.Sum_l = ICARO3_HAL_v1_P.cmds_Y0[0];
    ICARO3_HAL_v1_B.Sum1_e = ICARO3_HAL_v1_P.cmds_Y0[1];
    ICARO3_HAL_v1_B.Sum1_k = ICARO3_HAL_v1_P.cmds_Y0[2];
    ICARO3_HAL_v1_B.Sum1_p = ICARO3_HAL_v1_P.cmds_Y0[3];
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_a =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_d;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_g = ICARO3_HAL_v1_P.Internal_X0_m;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_b =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_es;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_p = ICARO3_HAL_v1_P.Internal_X0_hd;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_o =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_nj;
    ICARO3_HAL_v1_B.gainonthrottledim = ICARO3_HAL_v1_P.cmds_Y0_h[0];
    ICARO3_HAL_v1_B.Sum1_n1 = ICARO3_HAL_v1_P.cmds_Y0_h[1];
    ICARO3_HAL_v1_B.Sum1_d = ICARO3_HAL_v1_P.cmds_Y0_h[2];
    ICARO3_HAL_v1_B.Sum1_l = ICARO3_HAL_v1_P.cmds_Y0_h[3];
    for (i = 0; i < 10; i++) {
      ICARO3_HAL_v1_B.RateTransition1_a[i] =
        ICARO3_HAL_v1_P.RateTransition1_X0_p;
    }

    ICARO3_HAL_v1_B.converttohifreqHz[0] = ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_B.converttohifreqHz[1] = ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_B.converttohifreqHz[2] = ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i3 =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_f;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_hw = ICARO3_HAL_v1_P.Internal_X0_j;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_j =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_l;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_o[0] = ICARO3_HAL_v1_P.Internal_X0_dj;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_o[1] = ICARO3_HAL_v1_P.Internal_X0_dj;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_j = ICARO3_HAL_v1_P.Internal_X0_g;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_o =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_ah;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[0] = ICARO3_HAL_v1_P.Internal_X0_da;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_jn[1] = ICARO3_HAL_v1_P.Internal_X0_da;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_n = ICARO3_HAL_v1_P.Internal_X0_c;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_m =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_k;
    ICARO3_HAL_v1_MATLABFunction2_Init(&ICARO3_HAL_v1_DWork.sf_MATLABFunction2_l);
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_f =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_a;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_py =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_gs;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_l = ICARO3_HAL_v1_P.Internal_X0_l;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_lh = ICARO3_HAL_v1_P.Internal_X0_m0;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_hd = ICARO3_HAL_v1_P.Internal_X0_b;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_c =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_fe;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_a = ICARO3_HAL_v1_P.Internal_X0_e;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_m = ICARO3_HAL_v1_P.Internal_X0_o;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_nu = ICARO3_HAL_v1_P.Internal_X0_jq;
    ICARO3_HAL_v1_B.Sum_e = ICARO3_HAL_v1_P.cmds_Y0_a[0];
    ICARO3_HAL_v1_B.Sum1_i = ICARO3_HAL_v1_P.cmds_Y0_a[1];
    ICARO3_HAL_v1_B.Sum1_h = ICARO3_HAL_v1_P.cmds_Y0_a[2];
    ICARO3_HAL_v1_B.Sum1_fr = ICARO3_HAL_v1_P.cmds_Y0_a[3];
    ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[0] =
      ICARO3_HAL_v1_P.ctrl_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[0] =
      ICARO3_HAL_v1_P.ctrl_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction3_j.vect_vax[1] =
      ICARO3_HAL_v1_P.ctrl_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction1_i.vect_vax[1] =
      ICARO3_HAL_v1_P.ctrl_data_body_Y0;
    ICARO3_HAL_v1_B.Sum1_n = ICARO3_HAL_v1_P.ctrl_data_earth_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction2_l.y = ICARO3_HAL_v1_P.debug_data_body_Y0;
    ICARO3_HAL_v1_B.Sum1_b = ICARO3_HAL_v1_P.debug_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.x = ICARO3_HAL_v1_P.debug_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction6_hx.y = ICARO3_HAL_v1_P.debug_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction6_au.x = ICARO3_HAL_v1_P.debug_data_body_Y0;
    ICARO3_HAL_v1_B.sf_MATLABFunction6_au.y = ICARO3_HAL_v1_P.debug_data_body_Y0;
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_B.RateTransition1_ay[i] =
        ICARO3_HAL_v1_P.RateTransition1_X0_o;
    }

    ICARO3_HAL_v1_B.RateTransition4 = ICARO3_HAL_v1_P.RateTransition4_X0;
    ICARO3_HAL_v1_B.dontuseusemotorswhencontrollerisnotactivated =
      ICARO3_HAL_v1_P.cmds_Y0_hv[0];
    ICARO3_HAL_v1_B.Constant = ICARO3_HAL_v1_P.cmds_Y0_hv[1];
    ICARO3_HAL_v1_B.Constant1 = ICARO3_HAL_v1_P.cmds_Y0_hv[2];
    ICARO3_HAL_v1_B.Constant2 = ICARO3_HAL_v1_P.cmds_Y0_hv[3];
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_o;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_i = ICARO3_HAL_v1_P.Internal_X0_i;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_p =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_aq;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_f = ICARO3_HAL_v1_P.Internal_X0_ib;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_k =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_og;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_i5 = ICARO3_HAL_v1_P.Internal_X0_g5;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_iq =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_b;
    ICARO3_HAL_v1_MATLABFunction2_Init(&ICARO3_HAL_v1_DWork.sf_MATLABFunction2_j);
    ICARO3_HAL_v1_DWork.Internal_DSTATE_b = ICARO3_HAL_v1_P.Internal_X0_oi;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator1_DSTATE_i =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator1_IC_aw;
    wrap_gpsparser_start_fcn();
    ICARO3_HAL_v1_B.In_c = ICARO3_HAL_v1_P.Out_Y0;
    ICARO3_HAL_v1_clocklatch_Start(&ICARO3_HAL_v1_B.clocklatch_m,
      (rtP_clocklatch_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.clocklatch_m);
    ICARO3_HAL_v1_B.RateTransition[0] = ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_B.RateTransition[1] = ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_B.RateTransition[2] = ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_B.RateTransition[3] = ICARO3_HAL_v1_P.RateTransition_X0;
    wrap_send_to_bs_start_fcn();
    ICARO3_HAL_v1_DWork.clockTickCounter_l = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_p = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_e = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_lx = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_k = 0;
    ICARO3_HAL_v1_DWork.clockTickCounter_kw = 0;
    wrap_pm_init_start_fcn();
    ICARO3_HAL_v1_B.LLH_in[0] = ICARO3_HAL_v1_P.LLH_ref_Y0[0];
    ICARO3_HAL_v1_B.LLH_in[1] = ICARO3_HAL_v1_P.LLH_ref_Y0[1];
    ICARO3_HAL_v1_B.LLH_in[2] = ICARO3_HAL_v1_P.LLH_ref_Y0[2];
    wrap_PWM_start_fcn(1.0,1.0,1.0,1.0);
    wrap_CAN_Transmit_start_fcn();
    wrap_CAN_Transmit_start_fcn();
    wrap_CAN_Transmit_start_fcn();
    ICARO3_HAL_v1_DWork.clockTickCounter_j = 0;
    ICARO3_HAL_v1_DWork.Output_DSTATE_k =
      ICARO3_HAL_v1_P.Output_InitialCondition;
    wrap_CAN_Receive_start_fcn(&ICARO3_HAL_v1_P.Rx_ID1_Value,6.0);
    ICARO3_HAL_v1_Subsystem_Start(&ICARO3_HAL_v1_DWork.Subsystem_a,
      (rtP_Subsystem_ICARO3_HAL_v1 *)&ICARO3_HAL_v1_P.Subsystem_a);
    wrap_ADC_Receive_start_fcn();
    ICARO3_HAL_v1_DWork.clockTickCounter_kr = 0;
    wrap_USART2_Init_start_fcn();
    wrap_USART3_Init_start_fcn();
    wrap_USART4_Init_start_fcn();
    wrap_USART5_Init_start_fcn();
  }

  {
    int32_T i;
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition6_X0;
    ICARO3_HAL_v1_DWork.RateTransition6_Buffer[1] =
      ICARO3_HAL_v1_P.RateTransition6_X0;
    ICARO3_HAL_v1_DWork.Output_DSTATE =
      ICARO3_HAL_v1_P.Output_InitialCondition_g;
    for (i = 0; i < 8; i++) {
      ICARO3_HAL_v1_DWork.RateTransition14_Buffer[i] =
        ICARO3_HAL_v1_P.RateTransition14_X0;
      ICARO3_HAL_v1_DWork.RateTransition15_Buffer[i] =
        ICARO3_HAL_v1_P.RateTransition15_X0;
      ICARO3_HAL_v1_DWork.RateTransition_Buffer[i] =
        ICARO3_HAL_v1_P.RateTransition_X0_p;
    }

    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[1] =
      ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[2] =
      ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_DWork.RateTransition19_Buffer[3] =
      ICARO3_HAL_v1_P.RateTransition19_X0;
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[1] =
      ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[2] =
      ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_DWork.RateTransition20_Buffer[3] =
      ICARO3_HAL_v1_P.RateTransition20_X0;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c4 =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_n;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_id =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_i;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_d =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_e;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_b =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition_d;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_l =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition_n;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_k =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition_d;
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_o =
      ICARO3_HAL_v1_P.SRFlipFlop_initial_condition;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_n =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_ey;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_e =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_d;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_a =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition_e;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_o =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition_j;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_l =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition_f;
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_e =
      ICARO3_HAL_v1_P.SRFlipFlop_initial_condition_g;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_j1;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_eb =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_n;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_c =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition_b;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_ly =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition_a;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_h =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition_b;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_fu =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_c;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_k =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_h;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_j =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition_j;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_i =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition_c;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_g =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition_l;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_h =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_ad;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_ds =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_i;
    ICARO3_HAL_v1_DWork.UnitDelay2_DSTATE_e =
      ICARO3_HAL_v1_P.UnitDelay2_InitialCondition_a;
    ICARO3_HAL_v1_DWork.UnitDelay3_DSTATE_e =
      ICARO3_HAL_v1_P.UnitDelay3_InitialCondition_i;
    ICARO3_HAL_v1_DWork.UnitDelay4_DSTATE_kz =
      ICARO3_HAL_v1_P.UnitDelay4_InitialCondition_n;
    ICARO3_HAL_v1_DWork.RateTransition3_Buffer0 =
      ICARO3_HAL_v1_P.RateTransition3_X0;
    ICARO3_HAL_v1_DWork.csel = 0.0;
    ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_a =
      ICARO3_HAL_v1_P.RateTransition1_X0;
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer0_l =
      ICARO3_HAL_v1_P.RateTransition2_X0_j;
    ICARO3_HAL_v1_DWork.RateTransition2_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition2_X0;
    ICARO3_HAL_v1_DWork.controller_age = 0.0;
    ICARO3_HAL_v1_DWork.mode = 0U;
    ICARO3_HAL_v1_DWork.controller_sel = 0U;
    ICARO3_HAL_v1_DWork.ahrs_sel = 0U;
    ICARO3_HAL_v1_DWork.command_sel = 0U;
    ICARO3_HAL_v1_DWork.enable_motors = 0U;
    ICARO3_HAL_v1_DWork.arming_request_not_valid = 1U;
    ICARO3_HAL_v1_DWork.safety_hover_age = 0.0;
    ICARO3_HAL_v1_DWork.initial_gps_fix_arrived = 0U;
    ICARO3_HAL_v1_DWork.RateTransition3_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition3_X0_e;
    for (i = 0; i < 10; i++) {
      ICARO3_HAL_v1_DWork.RateTransition1_Buffer[i] =
        ICARO3_HAL_v1_P.RateTransition1_X0_p;
    }

    ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[0] =
      ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[1] =
      ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_DWork.converttohifreqHz_Buffer0[2] =
      ICARO3_HAL_v1_P.converttohifreqHz_X0;
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_g =
      ICARO3_HAL_v1_P.SRFlipFlop_initial_condition_b;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_e =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_g3;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_ni =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_h5;
    ICARO3_HAL_v1_DWork.storeinside_RTH_circleflag_DSTATE =
      ICARO3_HAL_v1_P.storeinside_RTH_circleflag_InitialCondition;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_e;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_iy1 =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_n4;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_c =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_o;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_b;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_az;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState = 2;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING = 1U;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_c = 2;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_b =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_h;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_k =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_bu;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_h = 2;
    ICARO3_HAL_v1_MATLABFunction2_Init(&ICARO3_HAL_v1_DWork.sf_MATLABFunction4);
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_m = 1U;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_k = 2;
    ICARO3_HAL_v1_DWork.INDICE = 1.0;
    ICARO3_HAL_v1_DWork.End_WPset = 0.0;
    ICARO3_HAL_v1_MATLABFunction2_Init(&ICARO3_HAL_v1_DWork.sf_MATLABFunction2);
    ICARO3_HAL_v1_DWork.pitch_not_empty = false;
    ICARO3_HAL_v1_DWork.prec_r_not_empty = false;
    ICARO3_HAL_v1_DWork.en_short2long = 0.0;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_p =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_j;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_IC_LOADING_k = 1U;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p = 2;
    for (i = 0; i < 6; i++) {
      ICARO3_HAL_v1_DWork.RateTransition1_Buffer0_j[i] =
        ICARO3_HAL_v1_P.RateTransition1_X0_o;
    }

    ICARO3_HAL_v1_DWork.RateTransition4_Buffer0_d =
      ICARO3_HAL_v1_P.RateTransition4_X0;
    ICARO3_HAL_v1_DWork.delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt
      =
      ICARO3_HAL_v1_P.delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_j =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_d;
    memset(&ICARO3_HAL_v1_DWork.WP_DB_tmp[0], 0, 1200U * sizeof(real_T));
    memset(&ICARO3_HAL_v1_DWork.WP_DB[0], 0, 1400U * sizeof(real_T));
    ICARO3_HAL_v1_DWork.wayp_count = 0.0;
    ICARO3_HAL_v1_DWork.act_wp = 0.0;
    ICARO3_HAL_v1_DWork.timer = 1000.0;
    ICARO3_HAL_v1_DWork.en_timer = 0.0;
    ICARO3_HAL_v1_DWork.send_delay = 0.0;
    ICARO3_HAL_v1_DWork.send_flag = 0.0;
    ICARO3_HAL_v1_DWork.miss_pkg = 0.0;
    ICARO3_HAL_v1_DWork.Memory_PreviousInput = ICARO3_HAL_v1_P.Memory_X0;
    ICARO3_HAL_v1_DWork.tmpPitch_not_empty = false;
    ICARO3_HAL_v1_DWork.RateTransition11_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition11_X0;
    ICARO3_HAL_v1_DWork.RateTransition11_Buffer[1] =
      ICARO3_HAL_v1_P.RateTransition11_X0;
    ICARO3_HAL_v1_DWork.RateTransition_Buffer0[0] =
      ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_DWork.RateTransition_Buffer0[1] =
      ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_DWork.RateTransition_Buffer0[2] =
      ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_DWork.RateTransition_Buffer0[3] =
      ICARO3_HAL_v1_P.RateTransition_X0;
    ICARO3_HAL_v1_DWork.Internal_DSTATE = ICARO3_HAL_v1_P.Internal_X0_hc;
    ICARO3_HAL_v1_DWork.Internal_DSTATE_h = ICARO3_HAL_v1_P.Internal_X0_gk;
    ICARO3_HAL_v1_DWork.integratecurrent_DSTATE =
      ICARO3_HAL_v1_P.integratecurrent_IC;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_g =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_eq;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_o =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_nd;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_af;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_p2 = 2;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_i =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_p;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_j =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_j;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_l5 =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_m;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_o = 2;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_m1 =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_a;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_g =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_nb;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_n =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_p;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_g = 2;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_c =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_d1;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_DSTATE_i =
      ICARO3_HAL_v1_P.DiscreteTimeIntegrator_IC_ae;
    ICARO3_HAL_v1_DWork.DiscreteTimeIntegrator_PrevResetState_gc = 2;
    for (i = 0; i < 7; i++) {
      ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_bv[i] =
        ICARO3_HAL_v1_P.UnitDelay_InitialCondition_px;
    }

    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_b =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_g;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_f =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_g;
    ICARO3_HAL_v1_DWork.UnitDelay1_DSTATE_l =
      ICARO3_HAL_v1_P.UnitDelay1_InitialCondition_b;
    ICARO3_HAL_v1_DWork.Memory_PreviousInput_l =
      ICARO3_HAL_v1_P.SRFlipFlop_initial_condition_d;
    ICARO3_HAL_v1_DWork.UnitDelay_DSTATE_nl =
      ICARO3_HAL_v1_P.UnitDelay_InitialCondition_m;
    ICARO3_HAL_v1_DWork.notifyONLYafterstoringinitialLLHfordataprojection_DSTATE
      =
      ICARO3_HAL_v1_P.notifyONLYafterstoringinitialLLHfordataprojection_InitialConditi;
    ICARO3_HAL_v1_DWork.Delay_DSTATE = ICARO3_HAL_v1_P.Delay_InitialCondition;
    ICARO3_HAL_v1_DWork.RateTransition18_Buffer[0] =
      ICARO3_HAL_v1_P.RateTransition18_X0;
    ICARO3_HAL_v1_DWork.RateTransition18_Buffer[1] =
      ICARO3_HAL_v1_P.RateTransition18_X0;
    ICARO3_HAL_v1_DWork.m = 0.0;
    ICARO3_HAL_v1_DWork.a = 0.0;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_HAL_v1.c
 */
