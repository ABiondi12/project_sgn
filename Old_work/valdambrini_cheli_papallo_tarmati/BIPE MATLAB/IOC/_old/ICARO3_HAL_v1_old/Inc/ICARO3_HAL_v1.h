/*
 * File: ICARO3_HAL_v1.h
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

#ifndef RTW_HEADER_ICARO3_HAL_v1_h_
#define RTW_HEADER_ICARO3_HAL_v1_h_
#include <string.h>
#include <float.h>
#include <math.h>
#include "ICARO3_HAL_v1_STM32.h"
#ifndef ICARO3_HAL_v1_COMMON_INCLUDES_
# define ICARO3_HAL_v1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ICARO3_HAL_v1_COMMON_INCLUDES_ */

#include "ICARO3_HAL_v1_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<S2>/Attitude Filter ADIS' */
typedef struct {
  real32_T euler_out[3];               /* '<S29>/dcm_marg' */
  real32_T a_ned[3];                   /* '<S29>/dcm_marg' */
} rtB_AttitudeFilterADIS_ICARO3_HAL_v1;

/* Block states (auto storage) for system '<S2>/Attitude Filter ADIS' */
typedef struct {
  real32_T UnitDelay1_DSTATE[4];       /* '<S29>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE[3];       /* '<S29>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[3];       /* '<S29>/Unit Delay3' */
  boolean_T ini_not_empty;             /* '<S29>/dcm_marg' */
  boolean_T AttitudeFilterADIS_MODE;   /* '<S2>/Attitude Filter ADIS' */
} rtDW_AttitudeFilterADIS_ICARO3_HAL_v1;

/* Block signals for system '<S33>/Subsystem' */
typedef struct {
  real_T Product1;                     /* '<S36>/Product1' */
} rtB_Subsystem_ICARO3_HAL_v1;

/* Block states (auto storage) for system '<S33>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S36>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S36>/Discrete-Time Integrator1' */
} rtDW_Subsystem_ICARO3_HAL_v1;

/* Block signals for system '<S34>/Subsystem' */
typedef struct {
  real_T Product1;                     /* '<S37>/Product1' */
} rtB_Subsystem_ICARO3_HAL_v1_j;

/* Block states (auto storage) for system '<S34>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S37>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S37>/Discrete-Time Integrator1' */
} rtDW_Subsystem_ICARO3_HAL_v1_c;

/* Block signals for system '<S47>/MATLAB Function1' */
typedef struct {
  real_T vect_vax[2];                  /* '<S47>/MATLAB Function1' */
} rtB_MATLABFunction1_ICARO3_HAL_v1;

/* Block signals for system '<S47>/MATLAB Function2' */
typedef struct {
  real_T y;                            /* '<S47>/MATLAB Function2' */
} rtB_MATLABFunction2_ICARO3_HAL_v1;

/* Block states (auto storage) for system '<S47>/MATLAB Function2' */
typedef struct {
  real_T old;                          /* '<S47>/MATLAB Function2' */
  real_T k;                            /* '<S47>/MATLAB Function2' */
  boolean_T k_not_empty;               /* '<S47>/MATLAB Function2' */
} rtDW_MATLABFunction2_ICARO3_HAL_v1;

/* Block signals for system '<S108>/MATLAB Function6' */
typedef struct {
  real_T x;                            /* '<S108>/MATLAB Function6' */
  real_T y;                            /* '<S108>/MATLAB Function6' */
} rtB_MATLABFunction6_ICARO3_HAL_v1;

/* Block signals for system '<S183>/h latch' */
typedef struct {
  real_T In1;                          /* '<S195>/In1' */
} rtB_hlatch_ICARO3_HAL_v1;

/* Block signals for system '<S183>/lat lon latch' */
typedef struct {
  real_T In1[2];                       /* '<S196>/In1' */
} rtB_latlonlatch_ICARO3_HAL_v1;

/* Block signals for system '<S267>/clock latch' */
typedef struct {
  real_T In;                           /* '<S270>/In' */
} rtB_clocklatch_ICARO3_HAL_v1;

/* Block signals for system '<S350>/ChangeAsset2' */
typedef struct {
  real32_T y[3];                       /* '<S350>/ChangeAsset2' */
} rtB_ChangeAsset2_ICARO3_HAL_v1;

/* Block signals for system '<S377>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint16_T y;                          /* '<S377>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1;

/* Block signals for system '<S378>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint32_T y;                          /* '<S378>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_g;

/* Block signals for system '<S397>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint8_T y[2];                        /* '<S397>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a;

/* Block signals for system '<S397>/MATLAB Function compute gyroxyz4' */
typedef struct {
  uint8_T y[8];                        /* '<S397>/MATLAB Function compute gyroxyz4' */
} rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1;

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction_o1[20];             /* '<S278>/S-Function' */
  real_T SFunction_o2[4];              /* '<S278>/S-Function' */
  real_T SFunction_o3[10];             /* '<S278>/S-Function' */
  real_T SFunction_o4;                 /* '<S278>/S-Function' */
  real_T Switch5;                      /* '<S351>/Switch5' */
  real_T RateTransition3;              /* '<S48>/Rate Transition3' */
  real_T RateTransition1;              /* '<S16>/Rate Transition1' */
  real_T Switch;                       /* '<S470>/Switch' */
  real_T Switch_o;                     /* '<S61>/Switch' */
  real_T RateTransition1_a[10];        /* '<Root>/Rate Transition1' */
  real_T converttohifreqHz[3];         /* '<S16>/convert to hi freq Hz' */
  real_T ZeroOrderHold3[3];            /* '<S48>/Zero-Order Hold3' */
  real_T ZeroOrderHold1[10];           /* '<S48>/Zero-Order Hold1' */
  real_T RateTransition2;              /* '<S48>/Rate Transition2' */
  real_T ZeroOrderHold2;               /* '<S48>/Zero-Order Hold2' */
  real_T RateTransition1_ay[6];        /* '<S48>/Rate Transition1' */
  real_T RateTransition4;              /* '<S48>/Rate Transition4' */
  real_T SFunction3_o1[16];            /* '<S8>/S-Function3' */
  real_T SFunction3_o2;                /* '<S8>/S-Function3' */
  real_T Switch2[4];                   /* '<S479>/Switch2' */
  real_T RateTransition[4];            /* '<S1>/Rate Transition' */
  real_T TmpSignalConversionAtSFunction2Inport1[54];
  real_T limittoBYTE0255[15];          /* '<S271>/limit to BYTE [0-255]' */
  real_T RateTransition1_j;            /* '<S276>/Rate Transition1' */
  real_T TmpSignalConversionAtSFunction2Inport3[4];
  real_T RateTransition16[7];          /* '<S9>/Rate Transition16' */
  real_T ManualSwitch5[7];             /* '<S9>/Manual Switch5' */
  real_T ManualSwitch1[4];             /* '<S352>/Manual Switch1' */
  real_T RateTransition_e;             /* '<S350>/Rate Transition' */
  real_T RateTransition4_b;            /* '<S374>/Rate Transition4' */
  real_T downsampleto100Hz[4];         /* '<S351>/downsample to 100 Hz' */
  real_T downsampleto100Hz3[4];        /* '<S351>/downsample to 100 Hz3' */
  real_T downsampleto100Hz9;           /* '<S351>/downsample to 100 Hz9' */
  real_T PulseGenerator1;              /* '<S20>/Pulse Generator1' */
  real_T lo;                           /* '<S25>/low_sat' */
  real_T In;                           /* '<S376>/In' */
  real_T RC_TRPY_refs[4];              /* '<S350>/MATLAB Function compute magxyz2' */
  real_T LLH_in[3];                    /* '<S327>/LLH_in' */
  real_T In_c;                         /* '<S269>/In' */
  real_T Sum;                          /* '<S239>/Sum' */
  real_T Sum1;                         /* '<S247>/Sum1' */
  real_T Sum1_f;                       /* '<S248>/Sum1' */
  real_T ManualSwitch;                 /* '<S240>/Manual Switch' */
  real_T In1[6];                       /* '<S234>/In1' */
  real_T Constant;                     /* '<S50>/Constant' */
  real_T Constant1;                    /* '<S50>/Constant1' */
  real_T Constant2;                    /* '<S50>/Constant2' */
  real_T dontuseusemotorswhencontrollerisnotactivated;/* '<S50>/dont use//use motors when controller is not activated' */
  real_T Sum_e;                        /* '<S98>/Sum' */
  real_T Sum1_b;                       /* '<S98>/Sum1' */
  real_T Sum1_h;                       /* '<S115>/Sum1' */
  real_T Sum1_i;                       /* '<S116>/Sum1' */
  real_T Sum1_fr;                      /* '<S99>/Sum1' */
  real_T Sum1_n;                       /* '<S47>/Sum1' */
  real_T Sum1_d;                       /* '<S88>/Sum1' */
  real_T Sum1_n1;                      /* '<S89>/Sum1' */
  real_T Sum1_l;                       /* '<S87>/Sum1' */
  real_T gainonthrottledim;            /* '<S46>/gain on throttle (dim)' */
  real_T Sum_l;                        /* '<S64>/Sum' */
  real_T Sum1_k;                       /* '<S77>/Sum1' */
  real_T Sum1_e;                       /* '<S78>/Sum1' */
  real_T Sum1_p;                       /* '<S65>/Sum1' */
  real_T DiscreteTimeIntegrator1;      /* '<S4>/Discrete-Time Integrator1' */
  real_T Sum1_g;                       /* '<S4>/Sum1' */
  real_T DiscreteTimeIntegrator1_i;    /* '<S3>/Discrete-Time Integrator1' */
  real_T Sum1_j;                       /* '<S3>/Sum1' */
  real_T Product1;                     /* '<S42>/Product1' */
  real32_T DataTypeConversionmx2[22];  /* '<Root>/Data Type Conversion mx2' */
  uint32_T PPMCapture_o1[9];           /* '<S351>/PPM Capture' */
  uint32_T PWM1[4];                    /* '<S1>/PWM1' */
  uint16_T I2C1SensorsLoop_o2;         /* '<S371>/I2C1 Sensors Loop' */
  uint16_T RateTransition19[4];        /* '<S374>/Rate Transition19' */
  uint16_T RateTransition20[4];        /* '<S374>/Rate Transition20' */
  uint16_T downsampleto100Hz1[12];     /* '<S351>/downsample to 100 Hz1' */
  uint8_T I2C1SensorsLoop_o1[71];      /* '<S371>/I2C1 Sensors Loop' */
  uint8_T Switch4[6];                  /* '<S351>/Switch4' */
  uint8_T PPMCapture_o2;               /* '<S351>/PPM Capture' */
  uint8_T PPMCapture_o3;               /* '<S351>/PPM Capture' */
  uint8_T CANRX_o1[48];                /* '<S370>/CANRX' */
  uint8_T CANRX_o2;                    /* '<S370>/CANRX' */
  boolean_T RateTransition2_b;         /* '<S16>/Rate Transition2' */
  boolean_T LogicalOperator;           /* '<S9>/Logical Operator' */
  boolean_T LogicalOperator_j;         /* '<S351>/Logical Operator' */
  rtB_Subsystem_ICARO3_HAL_v1 Subsystem_a;/* '<S484>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_e4;/* '<S440>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_f;/* '<S439>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_e1;/* '<S438>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_n;/* '<S434>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_p;/* '<S433>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1 Subsystem_c;/* '<S432>/Subsystem' */
  rtB_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterSS;/* '<S19>/Attitude Filter SS' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz5_n;/* '<S404>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz4_e;/* '<S404>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz3_h;/* '<S404>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz2_p;/* '<S404>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz1_d;/* '<S404>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz5_i;/* '<S403>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz4_a;/* '<S403>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz3_f;/* '<S403>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz2_l;/* '<S403>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz1_o;/* '<S403>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz5_m;/* '<S397>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz4;  /* '<S397>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz3_k;/* '<S397>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz2_h;/* '<S397>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a
    sf_MATLABFunctioncomputegyroxyz1_e;/* '<S397>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz5_d;/* '<S379>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz3_b;/* '<S379>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz2_b;/* '<S379>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz1_jl;/* '<S379>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_g
    sf_MATLABFunctioncomputegyroxyz5_l;/* '<S378>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_g
    sf_MATLABFunctioncomputegyroxyz1_j;/* '<S378>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz5;  /* '<S377>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz3;  /* '<S377>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz2;  /* '<S377>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1
    sf_MATLABFunctioncomputegyroxyz1;  /* '<S377>/MATLAB Function compute gyroxyz1' */
  rtB_ChangeAsset2_ICARO3_HAL_v1 sf_ChangeAsset3;/* '<S350>/ChangeAsset3' */
  rtB_ChangeAsset2_ICARO3_HAL_v1 sf_ChangeAsset2;/* '<S350>/ChangeAsset2' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_i;/* '<S346>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_e5;/* '<S345>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_m;/* '<S344>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_e;/* '<S340>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_h;/* '<S339>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1 Subsystem;/* '<S338>/Subsystem' */
  rtB_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterMPU;/* '<S17>/Attitude Filter MPU' */
  rtB_clocklatch_ICARO3_HAL_v1 clocklatch_a;/* '<S278>/clock latch' */
  rtB_clocklatch_ICARO3_HAL_v1 clocklatch_m;/* '<S267>/clock latch' */
  rtB_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2_j;/* '<S240>/MATLAB Function2' */
  rtB_hlatch_ICARO3_HAL_v1 yawlatch_l; /* '<S219>/yaw latch' */
  rtB_hlatch_ICARO3_HAL_v1 rolllatch;  /* '<S219>/roll latch' */
  rtB_hlatch_ICARO3_HAL_v1 pitchlatch; /* '<S219>/pitch latch' */
  rtB_latlonlatch_ICARO3_HAL_v1 latlonlatch_a;/* '<S219>/lat lon latch' */
  rtB_hlatch_ICARO3_HAL_v1 hlatch_n;   /* '<S219>/h latch' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_a4;/* '<S221>/MATLAB Function6' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_l;/* '<S220>/MATLAB Function6' */
  rtB_hlatch_ICARO3_HAL_v1 yawlatch_g; /* '<S186>/yaw latch' */
  rtB_latlonlatch_ICARO3_HAL_v1 latlonlatch;/* '<S186>/lat lon latch' */
  rtB_hlatch_ICARO3_HAL_v1 hlatch_a;   /* '<S186>/h latch' */
  rtB_hlatch_ICARO3_HAL_v1 yawlatch;   /* '<S183>/yaw latch' */
  rtB_latlonlatch_ICARO3_HAL_v1 latlonlatch_j;/* '<S183>/lat lon latch' */
  rtB_hlatch_ICARO3_HAL_v1 hlatch;     /* '<S183>/h latch' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_m;/* '<S191>/MATLAB Function6' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_k;/* '<S190>/MATLAB Function6' */
  rtB_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction4;/* '<S49>/MATLAB Function4' */
  rtB_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2;/* '<S160>/MATLAB Function2' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_a;/* '<S169>/MATLAB Function6' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_au;/* '<S109>/MATLAB Function6' */
  rtB_MATLABFunction6_ICARO3_HAL_v1 sf_MATLABFunction6_hx;/* '<S108>/MATLAB Function6' */
  rtB_MATLABFunction1_ICARO3_HAL_v1 sf_MATLABFunction3_j;/* '<S47>/MATLAB Function3' */
  rtB_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2_l;/* '<S47>/MATLAB Function2' */
  rtB_MATLABFunction1_ICARO3_HAL_v1 sf_MATLABFunction1_i;/* '<S47>/MATLAB Function1' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_d;/* '<S41>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_n4;/* '<S40>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_o;/* '<S35>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1_j Subsystem_b;/* '<S34>/Subsystem' */
  rtB_Subsystem_ICARO3_HAL_v1 Subsystem_l;/* '<S33>/Subsystem' */
  rtB_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterADIS;/* '<S2>/Attitude Filter ADIS' */
} BlockIO_ICARO3_HAL_v1;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T storeinside_RTH_circleflag_DSTATE;/* '<S49>/store inside_RTH_circle flag' */
  real_T UnitDelay_DSTATE;             /* '<S184>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S185>/Unit Delay' */
  real_T UnitDelay_DSTATE_m;           /* '<S189>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S188>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S180>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_b;           /* '<S215>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S214>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S181>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_p;           /* '<S168>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_er;/* '<S165>/Discrete-Time Integrator' */
  real_T delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt;/* '<S51>/delay by one sample to allow for  hover to start and last 1 sample  before going to waypoints ' */
  real_T Internal_DSTATE;              /* '<S471>/Internal' */
  real_T Internal_DSTATE_h;            /* '<S472>/Internal' */
  real_T integratecurrent_DSTATE;      /* '<S24>/integrate current' */
  real_T UnitDelay_DSTATE_g;           /* '<S282>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S282>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_i;           /* '<S283>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_l5;/* '<S283>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_m1;          /* '<S284>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S284>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S286>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_bv[7];       /* '<S285>/Unit Delay' */
  real_T UnitDelay_DSTATE_f;           /* '<S276>/Unit Delay' */
  real_T Delay_DSTATE;                 /* '<S352>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S241>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_i;            /* '<S242>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_p;/* '<S247>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_f;            /* '<S250>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_k;/* '<S248>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_i5;           /* '<S254>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_iq;/* '<S240>/Discrete-Time Integrator' */
  real_T Internal_DSTATE_b;            /* '<S258>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S249>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTATE_i3;/* '<S110>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_hw;           /* '<S111>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_j;/* '<S115>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_o[2];         /* '<S100>/Internal' */
  real_T Internal_DSTATE_j;            /* '<S117>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_o;/* '<S116>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_jn[2];        /* '<S101>/Internal' */
  real_T Internal_DSTATE_n;            /* '<S121>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S99>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S105>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_py;/* '<S106>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_l;            /* '<S133>/Internal' */
  real_T Internal_DSTATE_lh;           /* '<S134>/Internal' */
  real_T Internal_DSTATE_hd;           /* '<S135>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_c;/* '<S107>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_a;            /* '<S145>/Internal' */
  real_T Internal_DSTATE_m;            /* '<S146>/Internal' */
  real_T Internal_DSTATE_nu;           /* '<S147>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_a;/* '<S88>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_g;            /* '<S90>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_b;/* '<S89>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_p;            /* '<S94>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S87>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_in;          /* '<S72>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_i5;/* '<S71>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_am;/* '<S69>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S70>/Discrete-Time Integrator' */
  real_T Internal_DSTATE_ah;           /* '<S73>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_pq;/* '<S77>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_ax;           /* '<S79>/Internal' */
  real_T DiscreteTimeIntegrator1_DSTATE_ap;/* '<S78>/Discrete-Time Integrator1' */
  real_T Internal_DSTATE_lk;           /* '<S83>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S65>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S4>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_os;/* '<S4>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S4>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE_kb;/* '<S3>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_jq;/* '<S3>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE_l;/* '<S3>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S42>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_kb;/* '<S42>/Discrete-Time Integrator1' */
  real_T RateTransition2_Buffer0;      /* '<S22>/Rate Transition2' */
  real_T RateTransition5_Buffer0[6];   /* '<S22>/Rate Transition5' */
  real_T RateTransition1_Buffer0[9];   /* '<S22>/Rate Transition1' */
  real_T RateTransition6_Buffer[4];    /* '<S22>/Rate Transition6' */
  real_T RateTransition22_Buffer0[5];  /* '<S22>/Rate Transition22' */
  real_T RateTransition3_Buffer0;      /* '<S48>/Rate Transition3' */
  real_T RateTransition1_Buffer0_a;    /* '<S16>/Rate Transition1' */
  real_T RateTransition2_Buffer[2];    /* '<Root>/Rate Transition2' */
  real_T RateTransition23_Buffer0[3];  /* '<S22>/Rate Transition23' */
  real_T RateTransition4_Buffer0;      /* '<S22>/Rate Transition4' */
  real_T RateTransition7_Buffer0[3];   /* '<S22>/Rate Transition7' */
  real_T RateTransition3_Buffer[2];    /* '<Root>/Rate Transition3' */
  real_T RateTransition1_Buffer[20];   /* '<Root>/Rate Transition1' */
  real_T converttohifreqHz_Buffer0[3]; /* '<S16>/convert to hi freq Hz' */
  real_T RateTransition1_Buffer0_j[6]; /* '<S48>/Rate Transition1' */
  real_T RateTransition4_Buffer0_d;    /* '<S48>/Rate Transition4' */
  real_T Memory_PreviousInput;         /* '<S224>/Memory' */
  real_T RateTransition1_Buffer0_i[3]; /* '<S9>/Rate Transition1' */
  real_T RateTransition23_Buffer0_d;   /* '<S9>/Rate Transition23' */
  real_T RateTransition12_Buffer0;     /* '<S9>/Rate Transition12' */
  real_T RateTransition22_Buffer0_d[5];/* '<S9>/Rate Transition22' */
  real_T RateTransition21_Buffer0;     /* '<S9>/Rate Transition21' */
  real_T RateTransition14_Buffer0;     /* '<S9>/Rate Transition14' */
  real_T RateTransition4_Buffer0_l[4]; /* '<Root>/Rate Transition4' */
  real_T RateTransition11_Buffer[4];   /* '<S9>/Rate Transition11' */
  real_T RateTransition2_Buffer0_k[3]; /* '<S9>/Rate Transition2' */
  real_T RateTransition4_Buffer0_j[6]; /* '<S9>/Rate Transition4' */
  real_T RateTransition15_Buffer0[15]; /* '<S9>/Rate Transition15' */
  real_T RateTransition25_Buffer0[6];  /* '<S9>/Rate Transition25' */
  real_T RateTransition6_Buffer0[6];   /* '<S9>/Rate Transition6' */
  real_T RateTransition_Buffer0[4];    /* '<S1>/Rate Transition' */
  real_T RateTransition6_Buffer0_f[2]; /* '<S271>/Rate Transition6' */
  real_T RateTransition1_Buffer0_n[2]; /* '<S271>/Rate Transition1' */
  real_T RateTransition2_Buffer0_d;    /* '<S271>/Rate Transition2' */
  real_T RateTransition4_Buffer0_ls[7];/* '<S271>/Rate Transition4' */
  real_T RateTransition9_Buffer0;      /* '<S9>/Rate Transition9' */
  real_T RateTransition16_Buffer0[7];  /* '<S9>/Rate Transition16' */
  real_T RateTransition10_Buffer0[8];  /* '<S9>/Rate Transition10' */
  real_T m;                            /* '<S21>/MATLAB Function2' */
  real_T controller_age;               /* '<S16>/MATLAB Function' */
  real_T safety_hover_age;             /* '<S16>/MATLAB Function' */
  real_T csel;                         /* '<S15>/MATLAB Function3' */
  real_T a;                            /* '<Root>/MATLAB Function' */
  real_T WP_DB_tmp[1200];              /* '<S277>/Vehicle_DataBase_Manager' */
  real_T WP_DB[1400];                  /* '<S277>/Vehicle_DataBase_Manager' */
  real_T wayp_count;                   /* '<S277>/Vehicle_DataBase_Manager' */
  real_T act_wp;                       /* '<S277>/Vehicle_DataBase_Manager' */
  real_T timer;                        /* '<S277>/Vehicle_DataBase_Manager' */
  real_T en_timer;                     /* '<S277>/Vehicle_DataBase_Manager' */
  real_T send_delay;                   /* '<S277>/Vehicle_DataBase_Manager' */
  real_T send_flag;                    /* '<S277>/Vehicle_DataBase_Manager' */
  real_T miss_pkg;                     /* '<S277>/Vehicle_DataBase_Manager' */
  real_T tmpPitch;                     /* '<S224>/MATLAB Function6' */
  real_T pitch;                        /* '<S160>/pitch regulator' */
  real_T en_short2long;                /* '<S160>/pitch regulator' */
  real_T prec_r;                       /* '<S160>/pitch regulator' */
  real_T INDICE;                       /* '<S166>/WP Manager' */
  real_T End_WPset;                    /* '<S166>/WP Manager' */
  real_T h_ref;                        /* '<S64>/MATLAB Function4' */
  real_T thrust_offset;                /* '<S64>/MATLAB Function4' */
  real_T h_ref_j;                      /* '<S64>/MATLAB Function1' */
  real32_T RateTransition2_Buffer0_f[11];/* '<S350>/Rate Transition2' */
  int32_T clockTickCounter;            /* '<S470>/Pulse Generator1' */
  int32_T clockTickCounter_n;          /* '<S470>/Pulse Generator2' */
  int32_T clockTickCounter_l;          /* '<S282>/Reset  Generator' */
  int32_T clockTickCounter_p;          /* '<S283>/Reset  Generator' */
  int32_T clockTickCounter_e;          /* '<S284>/Reset  Generator' */
  int32_T clockTickCounter_lx;         /* '<S285>/Reset  Generator' */
  int32_T clockTickCounter_k;          /* '<S286>/Reset  Generator' */
  int32_T clockTickCounter_kw;         /* '<S276>/Reset  Generator' */
  int32_T clockTickCounter_kr;         /* '<S20>/Pulse Generator1' */
  int32_T clockTickCounter_j;          /* '<S375>/Pulse Generator' */
  uint32_T RateTransition18_Buffer[4]; /* '<S374>/Rate Transition18' */
  uint16_T RateTransition19_Buffer[8]; /* '<S374>/Rate Transition19' */
  uint16_T RateTransition20_Buffer[8]; /* '<S374>/Rate Transition20' */
  uint8_T Output_DSTATE;               /* '<S467>/Output' */
  uint8_T Output_DSTATE_k;             /* '<S405>/Output' */
  boolean_T UnitDelay_DSTATE_c4;       /* '<S294>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S294>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S294>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE;         /* '<S294>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S294>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_id;       /* '<S295>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_d;       /* '<S295>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_b;       /* '<S295>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_l;       /* '<S295>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE_k;       /* '<S295>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S293>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S293>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_a;       /* '<S293>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_o;       /* '<S293>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE_l;       /* '<S293>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_iy;       /* '<S296>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_eb;      /* '<S296>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_c;       /* '<S296>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_ly;      /* '<S296>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE_h;       /* '<S296>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_fu;       /* '<S297>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_k;       /* '<S297>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_j;       /* '<S297>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S297>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE_g;       /* '<S297>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S298>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_ds;      /* '<S298>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_e;       /* '<S298>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_e;       /* '<S298>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE_kz;      /* '<S298>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S63>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ni;       /* '<S209>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_iy1;      /* '<S194>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_j;        /* '<S279>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_o;       /* '<S282>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_j;       /* '<S283>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_g;       /* '<S284>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_c;       /* '<S286>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_b;       /* '<S285>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_l;       /* '<S276>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_nl;       /* '<S326>/Unit Delay' */
  boolean_T notifyONLYafterstoringinitialLLHfordataprojection_DSTATE;/* '<S326>/notify ONLY after storing initial LLH for data projection' */
  int8_T RateTransition2_semaphoreTaken;/* '<S22>/Rate Transition2' */
  int8_T RateTransition5_semaphoreTaken;/* '<S22>/Rate Transition5' */
  int8_T RateTransition14_ActiveBufIdx;/* '<S374>/Rate Transition14' */
  int8_T RateTransition15_ActiveBufIdx;/* '<S374>/Rate Transition15' */
  int8_T RateTransition1_semaphoreTaken;/* '<S22>/Rate Transition1' */
  int8_T RateTransition6_ActiveBufIdx; /* '<S22>/Rate Transition6' */
  int8_T RateTransition3_semaphoreTaken;/* '<S22>/Rate Transition3' */
  int8_T RateTransition22_semaphoreTaken;/* '<S22>/Rate Transition22' */
  int8_T RateTransition_ActiveBufIdx;  /* '<S374>/Rate Transition' */
  int8_T RateTransition19_ActiveBufIdx;/* '<S374>/Rate Transition19' */
  int8_T RateTransition20_ActiveBufIdx;/* '<S374>/Rate Transition20' */
  int8_T RateTransition2_ActiveBufIdx; /* '<Root>/Rate Transition2' */
  int8_T RateTransition23_semaphoreTaken;/* '<S22>/Rate Transition23' */
  int8_T RateTransition4_semaphoreTaken;/* '<S22>/Rate Transition4' */
  int8_T RateTransition7_semaphoreTaken;/* '<S22>/Rate Transition7' */
  int8_T RateTransition3_ActiveBufIdx; /* '<Root>/Rate Transition3' */
  int8_T RateTransition1_ActiveBufIdx; /* '<Root>/Rate Transition1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S188>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_c;/* '<S180>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S214>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_k;/* '<S181>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S165>/Discrete-Time Integrator' */
  int8_T RateTransition1_semaphoreTaken_o;/* '<S9>/Rate Transition1' */
  int8_T RateTransition23_semaphoreTaken_m;/* '<S9>/Rate Transition23' */
  int8_T RateTransition12_semaphoreTaken;/* '<S9>/Rate Transition12' */
  int8_T RateTransition22_semaphoreTaken_a;/* '<S9>/Rate Transition22' */
  int8_T RateTransition21_semaphoreTaken;/* '<S9>/Rate Transition21' */
  int8_T RateTransition14_semaphoreTaken;/* '<S9>/Rate Transition14' */
  int8_T RateTransition4_semaphoreTaken_a;/* '<Root>/Rate Transition4' */
  int8_T RateTransition11_ActiveBufIdx;/* '<S9>/Rate Transition11' */
  int8_T RateTransition2_semaphoreTaken_o;/* '<S9>/Rate Transition2' */
  int8_T RateTransition4_semaphoreTaken_f;/* '<S9>/Rate Transition4' */
  int8_T RateTransition15_semaphoreTaken;/* '<S9>/Rate Transition15' */
  int8_T RateTransition25_semaphoreTaken;/* '<S9>/Rate Transition25' */
  int8_T RateTransition6_semaphoreTaken;/* '<S9>/Rate Transition6' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p2;/* '<S282>/Discrete-Time Integrator' */
  int8_T RateTransition6_semaphoreTaken_k;/* '<S271>/Rate Transition6' */
  int8_T DiscreteTimeIntegrator_PrevResetState_o;/* '<S283>/Discrete-Time Integrator' */
  int8_T RateTransition1_semaphoreTaken_a;/* '<S271>/Rate Transition1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S284>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_gc;/* '<S286>/Discrete-Time Integrator' */
  int8_T RateTransition2_semaphoreTaken_d;/* '<S271>/Rate Transition2' */
  int8_T RateTransition4_semaphoreTaken_o;/* '<S271>/Rate Transition4' */
  int8_T RateTransition9_semaphoreTaken;/* '<S9>/Rate Transition9' */
  int8_T RateTransition16_semaphoreTaken;/* '<S9>/Rate Transition16' */
  int8_T RateTransition10_semaphoreTaken;/* '<S9>/Rate Transition10' */
  int8_T RateTransition6_semaphoreTaken_h;/* '<S350>/Rate Transition6' */
  int8_T RateTransition5_semaphoreTaken_m;/* '<S350>/Rate Transition5' */
  int8_T RateTransition2_semaphoreTaken_h;/* '<S350>/Rate Transition2' */
  int8_T RateTransition18_ActiveBufIdx;/* '<S374>/Rate Transition18' */
  int8_T DiscreteTimeIntegrator_PrevResetState_c0;/* '<S71>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_om;/* '<S70>/Discrete-Time Integrator' */
  uint8_T RateTransition14_Buffer[16]; /* '<S374>/Rate Transition14' */
  uint8_T RateTransition15_Buffer[16]; /* '<S374>/Rate Transition15' */
  uint8_T RateTransition3_Buffer0_n[9];/* '<S22>/Rate Transition3' */
  uint8_T RateTransition_Buffer[16];   /* '<S374>/Rate Transition' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S180>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_m;/* '<S181>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_k;/* '<S165>/Discrete-Time Integrator' */
  uint8_T RateTransition6_Buffer0_k[2];/* '<S350>/Rate Transition6' */
  uint8_T RateTransition5_Buffer0_f[3];/* '<S350>/Rate Transition5' */
  uint8_T mode;                        /* '<S16>/MATLAB Function' */
  uint8_T controller_sel;              /* '<S16>/MATLAB Function' */
  uint8_T ahrs_sel;                    /* '<S16>/MATLAB Function' */
  uint8_T command_sel;                 /* '<S16>/MATLAB Function' */
  uint8_T arming_request_not_valid;    /* '<S16>/MATLAB Function' */
  uint8_T initial_gps_fix_arrived;     /* '<S16>/MATLAB Function' */
  uint8_T enable_motors;               /* '<S16>/MATLAB Function' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_o;/* '<S70>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput_o;    /* '<S301>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S308>/Memory' */
  boolean_T RateTransition2_Buffer0_l; /* '<S16>/Rate Transition2' */
  boolean_T Memory_PreviousInput_g;    /* '<S237>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S330>/Memory' */
  boolean_T tmpPitch_not_empty;        /* '<S224>/MATLAB Function6' */
  boolean_T pitch_not_empty;           /* '<S160>/pitch regulator' */
  boolean_T prec_r_not_empty;          /* '<S160>/pitch regulator' */
  boolean_T h_ref_not_empty;           /* '<S64>/MATLAB Function4' */
  boolean_T h_ref_not_empty_b;         /* '<S64>/MATLAB Function1' */
  boolean_T AltitudeComplementaryFilterwith9dofACC1_MODE;/* '<Root>/Altitude Complementary Filter with 9dof ACC1' */
  boolean_T AltitudeComplementaryFilterwithH_DATA__MODE;/* '<Root>/Altitude Complementary Filter with H_DATA_' */
  boolean_T AttitudeAltitudeController_MODE;/* '<S5>/Attitude + Altitude Controller' */
  boolean_T AttitudeController_MODE;   /* '<S5>/Attitude Controller' */
  boolean_T DPAltitudeController_MODE; /* '<S5>/DP + Altitude Controller' */
  boolean_T Off_MODE;                  /* '<S5>/Off' */
  boolean_T fuzzyguidanceController_MODE;/* '<S5>/fuzzy guidance Controller' */
  rtDW_Subsystem_ICARO3_HAL_v1 Subsystem_a;/* '<S484>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_e4;/* '<S440>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_f;/* '<S439>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_e1;/* '<S438>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_n;/* '<S434>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_p;/* '<S433>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1 Subsystem_c;/* '<S432>/Subsystem' */
  rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterSS;/* '<S19>/Attitude Filter SS' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_i;/* '<S346>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_e5;/* '<S345>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_m;/* '<S344>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_e;/* '<S340>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_h;/* '<S339>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1 Subsystem;/* '<S338>/Subsystem' */
  rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterMPU;/* '<S17>/Attitude Filter MPU' */
  rtDW_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2_j;/* '<S240>/MATLAB Function2' */
  rtDW_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction4;/* '<S49>/MATLAB Function4' */
  rtDW_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2;/* '<S160>/MATLAB Function2' */
  rtDW_MATLABFunction2_ICARO3_HAL_v1 sf_MATLABFunction2_l;/* '<S47>/MATLAB Function2' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_d;/* '<S41>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_n4;/* '<S40>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_o;/* '<S35>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1_c Subsystem_b;/* '<S34>/Subsystem' */
  rtDW_Subsystem_ICARO3_HAL_v1 Subsystem_l;/* '<S33>/Subsystem' */
  rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterADIS;/* '<S2>/Attitude Filter ADIS' */
} D_Work_ICARO3_HAL_v1;

/* Parameters for system: '<S2>/Attitude Filter ADIS' */
struct rtP_AttitudeFilterADIS_ICARO3_HAL_v1_ {
  real32_T DCM_MARG_QUAT_Ki;           /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S29>/dcm_marg'
                                        */
  real32_T DCM_MARG_QUAT_Kp;           /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S29>/dcm_marg'
                                        */
  real32_T dcm_marg_T;                 /* Expression: T
                                        * Referenced by: '<S29>/dcm_marg'
                                        */
  real32_T q_Y0[4];                    /* Computed Parameter: q_Y0
                                        * Referenced by: '<S27>/q'
                                        */
  real32_T rpy_Y0[3];                  /* Computed Parameter: rpy_Y0
                                        * Referenced by: '<S27>/rpy'
                                        */
  real32_T gyro_bias_Y0[3];            /* Computed Parameter: gyro_bias_Y0
                                        * Referenced by: '<S27>/gyro_bias'
                                        */
  real32_T a_ned_Y0[3];                /* Computed Parameter: a_ned_Y0
                                        * Referenced by: '<S27>/a_ned'
                                        */
  real32_T UnitDelay1_InitialCondition[4];/* Computed Parameter: UnitDelay1_InitialCondition
                                           * Referenced by: '<S29>/Unit Delay1'
                                           */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S29>/Unit Delay2'
                                        */
  real32_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S29>/Unit Delay3'
                                        */
};

/* Parameters for system: '<S33>/Subsystem' */
struct rtP_Subsystem_ICARO3_HAL_v1_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S36>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S36>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S36>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S36>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S34>/Subsystem' */
struct rtP_Subsystem_ICARO3_HAL_v1_o_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S37>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S37>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S37>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S37>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S267>/clock latch' */
struct rtP_clocklatch_ICARO3_HAL_v1_ {
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S270>/Out'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ICARO3_HAL_v1_ {
  real_T ARRAY_WPT[18];                /* Variable: ARRAY_WPT
                                        * Referenced by: '<S166>/WP Manager'
                                        */
  real_T CAL_PARAM[9];                 /* Variable: CAL_PARAM
                                        * Referenced by: '<S350>/MATLAB Function'
                                        */
  real_T ET[2];                        /* Variable: ET
                                        * Referenced by: '<S166>/WP Manager'
                                        */
  real_T Fmax;                         /* Variable: Fmax
                                        * Referenced by:
                                        *   '<S46>/gain on throttle (dim)'
                                        *   '<S50>/gain on throttle (dim)'
                                        *   '<S481>/Gain1'
                                        *   '<S64>/Constant'
                                        *   '<S98>/Constant'
                                        *   '<S239>/Constant'
                                        */
  real_T H_CONTROL_SIGN;               /* Variable: H_CONTROL_SIGN
                                        * Referenced by:
                                        *   '<S305>/throttle sign1'
                                        *   '<S323>/Constant'
                                        */
  real_T H_CONTROL_THRES;              /* Variable: H_CONTROL_THRES
                                        * Referenced by: '<S323>/Constant'
                                        */
  real_T H_CONTROL_VALID;              /* Variable: H_CONTROL_VALID
                                        * Referenced by: '<S322>/Constant'
                                        */
  real_T INV_PITCH_RANGE;              /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_ROLL_RANGE;               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_THROTTLE_RANGE;           /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_YAW_RANGE;                /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T MAN_HOVER_RTH_HOVER_THRES;    /* Variable: MAN_HOVER_RTH_HOVER_THRES
                                        * Referenced by:
                                        *   '<S317>/Constant'
                                        *   '<S318>/Constant'
                                        */
  real_T MAN_HOVER_RTH_RTH_THRES;      /* Variable: MAN_HOVER_RTH_RTH_THRES
                                        * Referenced by:
                                        *   '<S319>/Constant'
                                        *   '<S320>/Constant'
                                        */
  real_T MAN_HOVER_RTH_SIGN;           /* Variable: MAN_HOVER_RTH_SIGN
                                        * Referenced by:
                                        *   '<S304>/throttle sign1'
                                        *   '<S317>/Constant'
                                        *   '<S318>/Constant'
                                        *   '<S319>/Constant'
                                        *   '<S320>/Constant'
                                        */
  real_T MAN_HOVER_RTH_VALID;          /* Variable: MAN_HOVER_RTH_VALID
                                        * Referenced by: '<S321>/Constant'
                                        */
  real_T Nprop;                        /* Variable: Nprop
                                        * Referenced by:
                                        *   '<S46>/gain on throttle (dim)'
                                        *   '<S50>/gain on throttle (dim)'
                                        *   '<S64>/Constant'
                                        *   '<S98>/Constant'
                                        *   '<S239>/Constant'
                                        */
  real_T PITCH_IDX;                    /* Variable: PITCH_IDX
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_MID;                    /* Variable: PITCH_MID
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_IDX;                     /* Variable: ROLL_IDX
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_MID;                     /* Variable: ROLL_MID
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T SF_H_PID_GAINS[9];            /* Variable: SF_H_PID_GAINS
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T SF_RPY_PID_GAINS[25];         /* Variable: SF_RPY_PID_GAINS
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T SF_YAW_PID_GAINS[4];          /* Variable: SF_YAW_PID_GAINS
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T THROTTLE_DOWN;                /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_IDX;                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_LOW_THRES;           /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by:
                                        *   '<S350>/MATLAB Function compute magxyz2'
                                        *   '<S309>/Constant'
                                        *   '<S313>/Constant'
                                        */
  real_T THROTTLE_SIGN;                /* Variable: THROTTLE_SIGN
                                        * Referenced by:
                                        *   '<S302>/throttle sign'
                                        *   '<S303>/throttle sign'
                                        *   '<S309>/Constant'
                                        *   '<S313>/Constant'
                                        */
  real_T THROTTLE_VALID;               /* Variable: THROTTLE_VALID
                                        * Referenced by:
                                        *   '<S310>/Constant'
                                        *   '<S314>/Constant'
                                        */
  real_T TLMNsat[4];                   /* Variable: TLMNsat
                                        * Referenced by: '<S481>/Saturation'
                                        */
  real_T WAYP_MODE;                    /* Variable: WAYP_MODE
                                        * Referenced by: '<S216>/Constant'
                                        */
  real_T YAW_IDX;                      /* Variable: YAW_IDX
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_LEFT_THRES;               /* Variable: YAW_LEFT_THRES
                                        * Referenced by: '<S315>/Constant'
                                        */
  real_T YAW_MID;                      /* Variable: YAW_MID
                                        * Referenced by: '<S350>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_RIGHT_THRES;              /* Variable: YAW_RIGHT_THRES
                                        * Referenced by: '<S311>/Constant'
                                        */
  real_T YAW_SIGN;                     /* Variable: YAW_SIGN
                                        * Referenced by:
                                        *   '<S302>/throttle sign1'
                                        *   '<S303>/throttle sign1'
                                        *   '<S311>/Constant'
                                        *   '<S315>/Constant'
                                        */
  real_T YAW_VALID;                    /* Variable: YAW_VALID
                                        * Referenced by:
                                        *   '<S312>/Constant'
                                        *   '<S316>/Constant'
                                        */
  real_T h_ref;                        /* Variable: h_ref
                                        * Referenced by: '<S238>/Constant'
                                        */
  real_T pinvM[16];                    /* Variable: pinvM
                                        * Referenced by: '<S481>/allocation matrix'
                                        */
  real_T wayp_R;                       /* Variable: wayp_R
                                        * Referenced by:
                                        *   '<S51>/check request for next wayp'
                                        *   '<S224>/MATLAB Function6'
                                        */
  real_T wayp_pitch;                   /* Variable: wayp_pitch
                                        * Referenced by: '<S224>/MATLAB Function6'
                                        */
  real_T wayp_roll_limit;              /* Variable: wayp_roll_limit
                                        * Referenced by: '<S224>/Saturation'
                                        */
  real_T RepeatingSequenceStair_OutValues[12];/* Mask Parameter: RepeatingSequenceStair_OutValues
                                               * Referenced by: '<S394>/Vector'
                                               */
  real_T muxer_OutValues[10];          /* Mask Parameter: muxer_OutValues
                                        * Referenced by: '<S466>/Vector'
                                        */
  real_T AttitudeFilterSS_T;           /* Mask Parameter: AttitudeFilterSS_T
                                        * Referenced by: '<S19>/Attitude Filter SS'
                                        */
  real_T AttitudeFilterADIS_T;         /* Mask Parameter: AttitudeFilterADIS_T
                                        * Referenced by: '<S2>/Attitude Filter ADIS'
                                        */
  real_T AttitudeFilterMPU_T;          /* Mask Parameter: AttitudeFilterMPU_T
                                        * Referenced by: '<S17>/Attitude Filter MPU'
                                        */
  real_T discretetimeRAMP_X0[4];       /* Mask Parameter: discretetimeRAMP_X0
                                        * Referenced by: '<S425>/Constant1'
                                        */
  real_T RCisok_const;                 /* Mask Parameter: RCisok_const
                                        * Referenced by: '<S300>/Constant'
                                        */
  real_T _const;                       /* Mask Parameter: _const
                                        * Referenced by: '<S291>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S263>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S264>/Constant'
                                        */
  real_T controller7_const;            /* Mask Parameter: controller7_const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T controller2_const;            /* Mask Parameter: controller2_const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T controller1_const;            /* Mask Parameter: controller1_const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T CompareToConstant_const_p;    /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S235>/Constant'
                                        */
  real_T CompareToConstant1_const_l;   /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S236>/Constant'
                                        */
  real_T CompareToConstant_const_g;    /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S199>/Constant'
                                        */
  real_T CompareToConstant1_const_g;   /* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S200>/Constant'
                                        */
  real_T CompareToConstant2_const;     /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S201>/Constant'
                                        */
  real_T CompareToConstant3_const;     /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S202>/Constant'
                                        */
  real_T CompareToConstant_const_a;    /* Mask Parameter: CompareToConstant_const_a
                                        * Referenced by: '<S203>/Constant'
                                        */
  real_T CompareToConstant4_const;     /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S205>/Constant'
                                        */
  real_T CompareToConstant6_const;     /* Mask Parameter: CompareToConstant6_const
                                        * Referenced by: '<S207>/Constant'
                                        */
  real_T CompareToConstant1_const_n;   /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S204>/Constant'
                                        */
  real_T CompareToConstant5_const;     /* Mask Parameter: CompareToConstant5_const
                                        * Referenced by: '<S206>/Constant'
                                        */
  real_T CompareToConstant7_const;     /* Mask Parameter: CompareToConstant7_const
                                        * Referenced by: '<S208>/Constant'
                                        */
  real_T controller3hover_const;       /* Mask Parameter: controller3hover_const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T controller4RettoHome_const;   /* Mask Parameter: controller4RettoHome_const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T controller5waypoint_const;    /* Mask Parameter: controller5waypoint_const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T CompareToConstant_const_e;    /* Mask Parameter: CompareToConstant_const_e
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T CompareToConstant_const_f;    /* Mask Parameter: CompareToConstant_const_f
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T CompareToConstant1_const_p;   /* Mask Parameter: CompareToConstant1_const_p
                                        * Referenced by: '<S176>/Constant'
                                        */
  real_T manual_const;                 /* Mask Parameter: manual_const
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T controller6fuzzyguidance_const;/* Mask Parameter: controller6fuzzyguidance_const
                                         * Referenced by: '<S57>/Constant'
                                         */
  real_T CompareToConstant_const_c;    /* Mask Parameter: CompareToConstant_const_c
                                        * Referenced by: '<S268>/Constant'
                                        */
  real_T CompareToConstant_const_cr;   /* Mask Parameter: CompareToConstant_const_cr
                                        * Referenced by: '<S272>/Constant'
                                        */
  real_T CompareToConstant1_const_h;   /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S273>/Constant'
                                        */
  real_T CompareToConstant2_const_e;   /* Mask Parameter: CompareToConstant2_const_e
                                        * Referenced by: '<S274>/Constant'
                                        */
  real_T CompareToConstant_const_ez;   /* Mask Parameter: CompareToConstant_const_ez
                                        * Referenced by: '<S328>/Constant'
                                        */
  real_T CompareToConstant1_const_f;   /* Mask Parameter: CompareToConstant1_const_f
                                        * Referenced by: '<S329>/Constant'
                                        */
  real_T AltitudeComplementaryFilterwith9dofACC1_kd;/* Mask Parameter: AltitudeComplementaryFilterwith9dofACC1_kd
                                                     * Referenced by: '<S3>/Gain10'
                                                     */
  real_T AltitudeComplementaryFilterwithH_DATA_kd;/* Mask Parameter: AltitudeComplementaryFilterwithH_DATA_kd
                                                   * Referenced by: '<S4>/Gain10'
                                                   */
  real_T AltitudeComplementaryFilterwith9dofACC1_ki;/* Mask Parameter: AltitudeComplementaryFilterwith9dofACC1_ki
                                                     * Referenced by: '<S3>/Gain12'
                                                     */
  real_T AltitudeComplementaryFilterwithH_DATA_ki;/* Mask Parameter: AltitudeComplementaryFilterwithH_DATA_ki
                                                   * Referenced by: '<S4>/Gain12'
                                                   */
  real_T AltitudeComplementaryFilterwith9dofACC1_kp;/* Mask Parameter: AltitudeComplementaryFilterwith9dofACC1_kp
                                                     * Referenced by: '<S3>/Gain11'
                                                     */
  real_T AltitudeComplementaryFilterwithH_DATA_kp;/* Mask Parameter: AltitudeComplementaryFilterwithH_DATA_kp
                                                   * Referenced by: '<S4>/Gain11'
                                                   */
  real_T Subsystem_period_samples;     /* Mask Parameter: Subsystem_period_samples
                                        * Referenced by: '<S282>/Reset  Generator'
                                        */
  real_T Subsystem1_period_samples;    /* Mask Parameter: Subsystem1_period_samples
                                        * Referenced by: '<S283>/Reset  Generator'
                                        */
  real_T Subsystem2_period_samples;    /* Mask Parameter: Subsystem2_period_samples
                                        * Referenced by: '<S284>/Reset  Generator'
                                        */
  real_T Subsystem4_period_samples;    /* Mask Parameter: Subsystem4_period_samples
                                        * Referenced by: '<S285>/Reset  Generator'
                                        */
  real_T Subsystem6_period_samples;    /* Mask Parameter: Subsystem6_period_samples
                                        * Referenced by: '<S286>/Reset  Generator'
                                        */
  real_T Subsystem4_period_samples_e;  /* Mask Parameter: Subsystem4_period_samples_e
                                        * Referenced by: '<S276>/Reset  Generator'
                                        */
  real_T ResetableslewratelimiterYAWwithextresetvalue_slew_rate_SR;/* Mask Parameter: ResetableslewratelimiterYAWwithextresetvalue_slew_rate_SR
                                                                    * Referenced by: '<S165>/Saturation1'
                                                                    */
  real_T ResetableslewratelimiterYAWwithextresetvalue_slew_rate_ST;/* Mask Parameter: ResetableslewratelimiterYAWwithextresetvalue_slew_rate_ST
                                                                    * Referenced by: '<S165>/Saturation1'
                                                                    */
  real_T discretetimeRAMP_slope;       /* Mask Parameter: discretetimeRAMP_slope
                                        * Referenced by: '<S425>/Step'
                                        */
  real_T discretetimeRAMP_start;       /* Mask Parameter: discretetimeRAMP_start
                                        * Referenced by:
                                        *   '<S425>/Constant'
                                        *   '<S425>/Step'
                                        */
  real_T Hvario_x_dead_zone;           /* Mask Parameter: Hvario_x_dead_zone
                                        * Referenced by:
                                        *   '<S71>/Dead Zone'
                                        *   '<S71>/Gain'
                                        */
  real_T Hvario_x_dead_zone_l;         /* Mask Parameter: Hvario_x_dead_zone_l
                                        * Referenced by:
                                        *   '<S188>/Dead Zone'
                                        *   '<S188>/Gain'
                                        */
  real_T Hvario_x_dead_zone_n;         /* Mask Parameter: Hvario_x_dead_zone_n
                                        * Referenced by:
                                        *   '<S214>/Dead Zone'
                                        *   '<S214>/Gain'
                                        */
  real_T Hvario_x_max;                 /* Mask Parameter: Hvario_x_max
                                        * Referenced by: '<S71>/Discrete-Time Integrator'
                                        */
  real_T Hvario_x_max_o;               /* Mask Parameter: Hvario_x_max_o
                                        * Referenced by: '<S188>/Discrete-Time Integrator'
                                        */
  real_T Hvario_x_max_l;               /* Mask Parameter: Hvario_x_max_l
                                        * Referenced by: '<S214>/Discrete-Time Integrator'
                                        */
  real_T Hvario_x_min;                 /* Mask Parameter: Hvario_x_min
                                        * Referenced by: '<S71>/Discrete-Time Integrator'
                                        */
  real_T Hvario_x_min_a;               /* Mask Parameter: Hvario_x_min_a
                                        * Referenced by: '<S188>/Discrete-Time Integrator'
                                        */
  real_T Hvario_x_min_h;               /* Mask Parameter: Hvario_x_min_h
                                        * Referenced by: '<S214>/Discrete-Time Integrator'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator3_BitMask;   /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator3'
                                        */
  uint16_T BitwiseOperator4_BitMask;   /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator4'
                                        */
  uint16_T BitwiseOperator5_BitMask;   /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator5'
                                        */
  uint16_T BitwiseOperator6_BitMask;   /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator6'
                                        */
  uint16_T BitwiseOperator_BitMask;    /* Mask Parameter: BitwiseOperator_BitMask
                                        * Referenced by: '<S364>/Bitwise Operator'
                                        */
  uint8_T CompareToConstant1_const_b;  /* Mask Parameter: CompareToConstant1_const_b
                                        * Referenced by: '<S281>/Constant'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S407>/FixPt Switch'
                                        */
  uint8_T LimitedCounter_uplimit_b;    /* Mask Parameter: LimitedCounter_uplimit_b
                                        * Referenced by: '<S469>/FixPt Switch'
                                        */
  boolean_T detectpositivevalues_const;/* Mask Parameter: detectpositivevalues_const
                                        * Referenced by: '<S213>/Constant'
                                        */
  boolean_T detectpositivevalues_const_d;/* Mask Parameter: detectpositivevalues_const_d
                                          * Referenced by: '<S198>/Constant'
                                          */
  boolean_T SRFlipFlop_initial_condition;/* Mask Parameter: SRFlipFlop_initial_condition
                                          * Referenced by: '<S301>/Memory'
                                          */
  boolean_T SRFlipFlop_initial_condition_g;/* Mask Parameter: SRFlipFlop_initial_condition_g
                                            * Referenced by: '<S308>/Memory'
                                            */
  boolean_T SRFlipFlop_initial_condition_b;/* Mask Parameter: SRFlipFlop_initial_condition_b
                                            * Referenced by: '<S237>/Memory'
                                            */
  boolean_T SRFlipFlop_initial_condition_d;/* Mask Parameter: SRFlipFlop_initial_condition_d
                                            * Referenced by: '<S330>/Memory'
                                            */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 9.81
                                        * Referenced by: '<S35>/Constant2'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S42>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S42>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S42>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S42>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant1_Value_de;           /* Expression: 0
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T h_Y0;                         /* Expression: [0]
                                        * Referenced by: '<S3>/h'
                                        */
  real_T hd_Y0;                        /* Expression: [0]
                                        * Referenced by: '<S3>/hd'
                                        */
  real_T Constant3_Value;              /* Expression: 9.81
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T DiscreteTimeIntegrator_gainval_o;/* Computed Parameter: DiscreteTimeIntegrator_gainval_o
                                           * Referenced by: '<S3>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_k;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_k
                                            * Referenced by: '<S3>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_a; /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S3>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator2'
                                        */
  real_T Gain13_Gain;                  /* Expression: -1
                                        * Referenced by: '<S3>/Gain13'
                                        */
  real_T h_Y0_a;                       /* Expression: [0]
                                        * Referenced by: '<S4>/h'
                                        */
  real_T hd_Y0_m;                      /* Expression: [0]
                                        * Referenced by: '<S4>/hd'
                                        */
  real_T Constant3_Value_o;            /* Expression: 9.81
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T DiscreteTimeIntegrator_gainval_d;/* Computed Parameter: DiscreteTimeIntegrator_gainval_d
                                           * Referenced by: '<S4>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_o;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_o
                                            * Referenced by: '<S4>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_e; /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval_n;/* Computed Parameter: DiscreteTimeIntegrator2_gainval_n
                                            * Referenced by: '<S4>/Discrete-Time Integrator2'
                                            */
  real_T DiscreteTimeIntegrator2_IC_l; /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator2'
                                        */
  real_T Gain13_Gain_c;                /* Expression: -1
                                        * Referenced by: '<S4>/Gain13'
                                        */
  real_T Frpyforsafetydescent_Value[4];/* Expression: [0.5-1/2 0 0 0]
                                        * Referenced by: '<S5>/Frpy for safety descent'
                                        */
  real_T MATLABFunction4_T;            /* Expression: T
                                        * Referenced by: '<S64>/MATLAB Function4'
                                        */
  real_T cmds_Y0[4];                   /* Expression: [0; 0; 0; 0]
                                        * Referenced by: '<S45>/cmds'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S64>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 0.5
                                        * Referenced by: '<S66>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S66>/Constant7'
                                        */
  real_T varioen_Value;                /* Expression: 1
                                        * Referenced by: '<S64>/vario en'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S72>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval_m;/* Computed Parameter: DiscreteTimeIntegrator_gainval_m
                                           * Referenced by: '<S71>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S71>/Discrete-Time Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S71>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S71>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_a;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_a
                                            * Referenced by: '<S69>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_k; /* Expression: 0
                                        * Referenced by: '<S69>/Discrete-Time Integrator1'
                                        */
  real_T resetonstartup1_Value;        /* Expression: 1
                                        * Referenced by: '<S64>/reset on start-up1'
                                        */
  real_T DiscreteTimeIntegrator_gainval_e;/* Computed Parameter: DiscreteTimeIntegrator_gainval_e
                                           * Referenced by: '<S70>/Discrete-Time Integrator'
                                           */
  real_T Internal_A;                   /* Computed Parameter: Internal_A
                                        * Referenced by: '<S73>/Internal'
                                        */
  real_T Internal_B;                   /* Computed Parameter: Internal_B
                                        * Referenced by: '<S73>/Internal'
                                        */
  real_T Internal_C;                   /* Computed Parameter: Internal_C
                                        * Referenced by: '<S73>/Internal'
                                        */
  real_T Internal_D;                   /* Computed Parameter: Internal_D
                                        * Referenced by: '<S73>/Internal'
                                        */
  real_T Internal_X0;                  /* Expression: 0
                                        * Referenced by: '<S73>/Internal'
                                        */
  real_T Saturation1_UpperSat_h;       /* Expression: slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 0.3
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -0.3
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_d
                                            * Referenced by: '<S77>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_b; /* Expression: 0
                                        * Referenced by: '<S77>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians2_Gain;/* Expression: pi/180
                                            * Referenced by: '<S45>/convert -1,1 to -20,20 deg in radians2'
                                            */
  real_T Internal_A_p;                 /* Computed Parameter: Internal_A_p
                                        * Referenced by: '<S79>/Internal'
                                        */
  real_T Internal_B_j;                 /* Computed Parameter: Internal_B_j
                                        * Referenced by: '<S79>/Internal'
                                        */
  real_T Internal_C_n;                 /* Computed Parameter: Internal_C_n
                                        * Referenced by: '<S79>/Internal'
                                        */
  real_T Internal_D_l;                 /* Computed Parameter: Internal_D_l
                                        * Referenced by: '<S79>/Internal'
                                        */
  real_T Internal_X0_h;                /* Expression: 0
                                        * Referenced by: '<S79>/Internal'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_c;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_c
                                            * Referenced by: '<S78>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_g; /* Expression: 0
                                        * Referenced by: '<S78>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians1_Gain;/* Expression: pi/180
                                            * Referenced by: '<S45>/convert -1,1 to -20,20 deg in radians1'
                                            */
  real_T Internal_A_l;                 /* Computed Parameter: Internal_A_l
                                        * Referenced by: '<S83>/Internal'
                                        */
  real_T Internal_B_c;                 /* Computed Parameter: Internal_B_c
                                        * Referenced by: '<S83>/Internal'
                                        */
  real_T Internal_C_e;                 /* Computed Parameter: Internal_C_e
                                        * Referenced by: '<S83>/Internal'
                                        */
  real_T Internal_D_m;                 /* Computed Parameter: Internal_D_m
                                        * Referenced by: '<S83>/Internal'
                                        */
  real_T Internal_X0_d;                /* Expression: 0
                                        * Referenced by: '<S83>/Internal'
                                        */
  real_T DiscreteTimeIntegrator_gainval_i;/* Computed Parameter: DiscreteTimeIntegrator_gainval_i
                                           * Referenced by: '<S65>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  real_T yawvelgain_Gain;              /* Expression: 2
                                        * Referenced by: '<S45>/yaw vel gain'
                                        */
  real_T cmds_Y0_h[4];                 /* Expression: [0; 0; 0; 0]
                                        * Referenced by: '<S46>/cmds'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_e;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_e
                                            * Referenced by: '<S88>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_d; /* Expression: 0
                                        * Referenced by: '<S88>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians2_Gain_f;/* Expression: pi/180
                                              * Referenced by: '<S46>/convert -1,1 to -20,20 deg in radians2'
                                              */
  real_T Internal_A_e;                 /* Computed Parameter: Internal_A_e
                                        * Referenced by: '<S90>/Internal'
                                        */
  real_T Internal_B_k;                 /* Computed Parameter: Internal_B_k
                                        * Referenced by: '<S90>/Internal'
                                        */
  real_T Internal_C_p;                 /* Computed Parameter: Internal_C_p
                                        * Referenced by: '<S90>/Internal'
                                        */
  real_T Internal_D_b;                 /* Computed Parameter: Internal_D_b
                                        * Referenced by: '<S90>/Internal'
                                        */
  real_T Internal_X0_m;                /* Expression: 0
                                        * Referenced by: '<S90>/Internal'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_kw;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_kw
                                             * Referenced by: '<S89>/Discrete-Time Integrator1'
                                             */
  real_T DiscreteTimeIntegrator1_IC_es;/* Expression: 0
                                        * Referenced by: '<S89>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians1_Gain_n;/* Expression: pi/180
                                              * Referenced by: '<S46>/convert -1,1 to -20,20 deg in radians1'
                                              */
  real_T Internal_A_m;                 /* Computed Parameter: Internal_A_m
                                        * Referenced by: '<S94>/Internal'
                                        */
  real_T Internal_B_f;                 /* Computed Parameter: Internal_B_f
                                        * Referenced by: '<S94>/Internal'
                                        */
  real_T Internal_C_f;                 /* Computed Parameter: Internal_C_f
                                        * Referenced by: '<S94>/Internal'
                                        */
  real_T Internal_D_mk;                /* Computed Parameter: Internal_D_mk
                                        * Referenced by: '<S94>/Internal'
                                        */
  real_T Internal_X0_hd;               /* Expression: 0
                                        * Referenced by: '<S94>/Internal'
                                        */
  real_T DiscreteTimeIntegrator_gainval_a;/* Computed Parameter: DiscreteTimeIntegrator_gainval_a
                                           * Referenced by: '<S87>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_nj; /* Expression: 0
                                        * Referenced by: '<S87>/Discrete-Time Integrator'
                                        */
  real_T yawvelgain_Gain_i;            /* Expression: 2
                                        * Referenced by: '<S46>/yaw vel gain'
                                        */
  real_T Constant2_Value_b;            /* Expression: 2*pi
                                        * Referenced by: '<S131>/Constant2'
                                        */
  real_T cmds_Y0_a[4];                 /* Expression: [0; 0; 0; 0]
                                        * Referenced by: '<S47>/cmds'
                                        */
  real_T ctrl_data_body_Y0;            /* Expression: 0
                                        * Referenced by: '<S47>/ctrl_data_body'
                                        */
  real_T ctrl_data_earth_Y0;           /* Expression: 0
                                        * Referenced by: '<S47>/ctrl_data_earth'
                                        */
  real_T todynarefdata_Y0[4];          /* Expression: [0; 0; 0; 0]
                                        * Referenced by: '<S47>/to dyna ref data'
                                        */
  real_T RPY_ref_out_Y0[3];            /* Expression: [0; 0; 0]
                                        * Referenced by: '<S47>/RPY_ref_out'
                                        */
  real_T debug_data_body_Y0;           /* Expression: 0
                                        * Referenced by: '<S47>/debug_data_body'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                            * Referenced by: '<S110>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_f; /* Expression: 0
                                        * Referenced by: '<S110>/Discrete-Time Integrator1'
                                        */
  real_T Internal_A_i;                 /* Computed Parameter: Internal_A_i
                                        * Referenced by: '<S111>/Internal'
                                        */
  real_T Internal_B_n;                 /* Computed Parameter: Internal_B_n
                                        * Referenced by: '<S111>/Internal'
                                        */
  real_T Internal_C_m;                 /* Computed Parameter: Internal_C_m
                                        * Referenced by: '<S111>/Internal'
                                        */
  real_T Internal_D_h;                 /* Computed Parameter: Internal_D_h
                                        * Referenced by: '<S111>/Internal'
                                        */
  real_T Internal_X0_j;                /* Expression: 0
                                        * Referenced by: '<S111>/Internal'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.3
                                        * Referenced by: '<S98>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -0.3
                                        * Referenced by: '<S98>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_i;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_i
                                            * Referenced by: '<S115>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_l; /* Expression: 0
                                        * Referenced by: '<S115>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians1_Gain_l;/* Expression: pi/180
                                              * Referenced by: '<S47>/convert -1,1 to -20,20 deg in radians1'
                                              */
  real_T Constant7_Value_e;            /* Expression: 0
                                        * Referenced by: '<S47>/Constant7'
                                        */
  real_T Internal_A_pz[3];             /* Computed Parameter: Internal_A_pz
                                        * Referenced by: '<S100>/Internal'
                                        */
  real_T Internal_B_g;                 /* Computed Parameter: Internal_B_g
                                        * Referenced by: '<S100>/Internal'
                                        */
  real_T Internal_C_j[2];              /* Computed Parameter: Internal_C_j
                                        * Referenced by: '<S100>/Internal'
                                        */
  real_T Internal_X0_dj;               /* Expression: 0
                                        * Referenced by: '<S100>/Internal'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 20*pi/180
                                        * Referenced by: '<S47>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -20*pi/180
                                        * Referenced by: '<S47>/Saturation'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S47>/Gain'
                                        */
  real_T Internal_A_a;                 /* Computed Parameter: Internal_A_a
                                        * Referenced by: '<S117>/Internal'
                                        */
  real_T Internal_B_l;                 /* Computed Parameter: Internal_B_l
                                        * Referenced by: '<S117>/Internal'
                                        */
  real_T Internal_C_jf;                /* Computed Parameter: Internal_C_jf
                                        * Referenced by: '<S117>/Internal'
                                        */
  real_T Internal_D_i;                 /* Computed Parameter: Internal_D_i
                                        * Referenced by: '<S117>/Internal'
                                        */
  real_T Internal_X0_g;                /* Expression: 0
                                        * Referenced by: '<S117>/Internal'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_b;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_b
                                            * Referenced by: '<S116>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_ah;/* Expression: 0
                                        * Referenced by: '<S116>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians_Gain;/* Expression: pi/180
                                           * Referenced by: '<S47>/convert -1,1 to -20,20 deg in radians'
                                           */
  real_T Internal_A_k[3];              /* Computed Parameter: Internal_A_k
                                        * Referenced by: '<S101>/Internal'
                                        */
  real_T Internal_B_i;                 /* Computed Parameter: Internal_B_i
                                        * Referenced by: '<S101>/Internal'
                                        */
  real_T Internal_C_jq[2];             /* Computed Parameter: Internal_C_jq
                                        * Referenced by: '<S101>/Internal'
                                        */
  real_T Internal_X0_da;               /* Expression: 0
                                        * Referenced by: '<S101>/Internal'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 20*pi/180
                                        * Referenced by: '<S47>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: -20*pi/180
                                        * Referenced by: '<S47>/Saturation1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S47>/Gain1'
                                        */
  real_T Internal_A_f;                 /* Computed Parameter: Internal_A_f
                                        * Referenced by: '<S121>/Internal'
                                        */
  real_T Internal_B_b;                 /* Computed Parameter: Internal_B_b
                                        * Referenced by: '<S121>/Internal'
                                        */
  real_T Internal_C_ed;                /* Computed Parameter: Internal_C_ed
                                        * Referenced by: '<S121>/Internal'
                                        */
  real_T Internal_D_a;                 /* Computed Parameter: Internal_D_a
                                        * Referenced by: '<S121>/Internal'
                                        */
  real_T Internal_X0_c;                /* Expression: 0
                                        * Referenced by: '<S121>/Internal'
                                        */
  real_T DiscreteTimeIntegrator_gainval_mc;/* Computed Parameter: DiscreteTimeIntegrator_gainval_mc
                                            * Referenced by: '<S99>/Discrete-Time Integrator'
                                            */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S99>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_f;            /* Expression: 2*pi
                                        * Referenced by: '<S131>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: pi
                                        * Referenced by: '<S131>/Switch'
                                        */
  real_T DiscreteTimeIntegrator_gainval_c;/* Computed Parameter: DiscreteTimeIntegrator_gainval_c
                                           * Referenced by: '<S105>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S105>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant1_Value_pj;           /* Expression: 0
                                        * Referenced by: '<S47>/Constant1'
                                        */
  real_T Constant3_Value_p;            /* Expression: 0
                                        * Referenced by: '<S47>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S47>/Constant4'
                                        */
  real_T Gain3_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S108>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S108>/Gain4'
                                        */
  real_T Constant7_Value_j;            /* Expression: 0
                                        * Referenced by: '<S108>/Constant7'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S108>/Constant1'
                                        */
  real_T Gain5_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S108>/Gain5'
                                        */
  real_T Constant2_Value_p;            /* Expression: 0
                                        * Referenced by: '<S108>/Constant2'
                                        */
  real_T Gain6_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S108>/Gain6'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S109>/Gain3'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S109>/Gain4'
                                        */
  real_T Constant7_Value_jg;           /* Expression: 0
                                        * Referenced by: '<S109>/Constant7'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S109>/Constant1'
                                        */
  real_T Gain5_Gain_e;                 /* Expression: pi/180
                                        * Referenced by: '<S109>/Gain5'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S109>/Constant2'
                                        */
  real_T Gain6_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S109>/Gain6'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_j4;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_j4
                                             * Referenced by: '<S106>/Discrete-Time Integrator1'
                                             */
  real_T DiscreteTimeIntegrator1_IC_gs;/* Expression: 0
                                        * Referenced by: '<S106>/Discrete-Time Integrator1'
                                        */
  real_T Internal_A_g;                 /* Computed Parameter: Internal_A_g
                                        * Referenced by: '<S133>/Internal'
                                        */
  real_T Internal_B_m;                 /* Computed Parameter: Internal_B_m
                                        * Referenced by: '<S133>/Internal'
                                        */
  real_T Internal_C_pe;                /* Computed Parameter: Internal_C_pe
                                        * Referenced by: '<S133>/Internal'
                                        */
  real_T Internal_D_f;                 /* Computed Parameter: Internal_D_f
                                        * Referenced by: '<S133>/Internal'
                                        */
  real_T Internal_X0_l;                /* Expression: 0
                                        * Referenced by: '<S133>/Internal'
                                        */
  real_T Internal_A_fc;                /* Computed Parameter: Internal_A_fc
                                        * Referenced by: '<S134>/Internal'
                                        */
  real_T Internal_B_fu;                /* Computed Parameter: Internal_B_fu
                                        * Referenced by: '<S134>/Internal'
                                        */
  real_T Internal_C_ec;                /* Computed Parameter: Internal_C_ec
                                        * Referenced by: '<S134>/Internal'
                                        */
  real_T Internal_D_bn;                /* Computed Parameter: Internal_D_bn
                                        * Referenced by: '<S134>/Internal'
                                        */
  real_T Internal_X0_m0;               /* Expression: 0
                                        * Referenced by: '<S134>/Internal'
                                        */
  real_T Internal_A_n;                 /* Computed Parameter: Internal_A_n
                                        * Referenced by: '<S135>/Internal'
                                        */
  real_T Internal_B_cv;                /* Computed Parameter: Internal_B_cv
                                        * Referenced by: '<S135>/Internal'
                                        */
  real_T Internal_C_l;                 /* Computed Parameter: Internal_C_l
                                        * Referenced by: '<S135>/Internal'
                                        */
  real_T Internal_D_k;                 /* Computed Parameter: Internal_D_k
                                        * Referenced by: '<S135>/Internal'
                                        */
  real_T Internal_X0_b;                /* Expression: 0
                                        * Referenced by: '<S135>/Internal'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_cf;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_cf
                                             * Referenced by: '<S107>/Discrete-Time Integrator1'
                                             */
  real_T DiscreteTimeIntegrator1_IC_fe;/* Expression: 0
                                        * Referenced by: '<S107>/Discrete-Time Integrator1'
                                        */
  real_T Internal_A_id;                /* Computed Parameter: Internal_A_id
                                        * Referenced by: '<S145>/Internal'
                                        */
  real_T Internal_B_ff;                /* Computed Parameter: Internal_B_ff
                                        * Referenced by: '<S145>/Internal'
                                        */
  real_T Internal_C_d;                 /* Computed Parameter: Internal_C_d
                                        * Referenced by: '<S145>/Internal'
                                        */
  real_T Internal_D_n;                 /* Computed Parameter: Internal_D_n
                                        * Referenced by: '<S145>/Internal'
                                        */
  real_T Internal_X0_e;                /* Expression: 0
                                        * Referenced by: '<S145>/Internal'
                                        */
  real_T Internal_A_kc;                /* Computed Parameter: Internal_A_kc
                                        * Referenced by: '<S146>/Internal'
                                        */
  real_T Internal_B_d;                 /* Computed Parameter: Internal_B_d
                                        * Referenced by: '<S146>/Internal'
                                        */
  real_T Internal_C_mr;                /* Computed Parameter: Internal_C_mr
                                        * Referenced by: '<S146>/Internal'
                                        */
  real_T Internal_D_px;                /* Computed Parameter: Internal_D_px
                                        * Referenced by: '<S146>/Internal'
                                        */
  real_T Internal_X0_o;                /* Expression: 0
                                        * Referenced by: '<S146>/Internal'
                                        */
  real_T Internal_A_o;                 /* Computed Parameter: Internal_A_o
                                        * Referenced by: '<S147>/Internal'
                                        */
  real_T Internal_B_kr;                /* Computed Parameter: Internal_B_kr
                                        * Referenced by: '<S147>/Internal'
                                        */
  real_T Internal_C_mj;                /* Computed Parameter: Internal_C_mj
                                        * Referenced by: '<S147>/Internal'
                                        */
  real_T Internal_D_kc;                /* Computed Parameter: Internal_D_kc
                                        * Referenced by: '<S147>/Internal'
                                        */
  real_T Internal_X0_jq;               /* Expression: 0
                                        * Referenced by: '<S147>/Internal'
                                        */
  real_T cmds_Y0_hv[4];                /* Expression: [0; 0; 0; 0]
                                        * Referenced by: '<S50>/cmds'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Constant1_Value_db;           /* Expression: 0
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S50>/Constant2'
                                        */
  real_T Constant3_Value_g;            /* Expression: 0
                                        * Referenced by: '<S50>/Constant3'
                                        */
  real_T latch_NOK_Value;              /* Expression: 0
                                        * Referenced by: '<S229>/latch_NOK'
                                        */
  real_T Constant2_Value_n;            /* Expression: 2*pi
                                        * Referenced by: '<S259>/Constant2'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_m
                                            * Referenced by: '<S241>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_o; /* Expression: 0
                                        * Referenced by: '<S241>/Discrete-Time Integrator1'
                                        */
  real_T Internal_A_i0;                /* Computed Parameter: Internal_A_i0
                                        * Referenced by: '<S242>/Internal'
                                        */
  real_T Internal_B_a;                 /* Computed Parameter: Internal_B_a
                                        * Referenced by: '<S242>/Internal'
                                        */
  real_T Internal_C_pu;                /* Computed Parameter: Internal_C_pu
                                        * Referenced by: '<S242>/Internal'
                                        */
  real_T Internal_D_g;                 /* Computed Parameter: Internal_D_g
                                        * Referenced by: '<S242>/Internal'
                                        */
  real_T Internal_X0_i;                /* Expression: 0
                                        * Referenced by: '<S242>/Internal'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 0.3
                                        * Referenced by: '<S239>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -0.3
                                        * Referenced by: '<S239>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_g;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_g
                                            * Referenced by: '<S247>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_aq;/* Expression: 0
                                        * Referenced by: '<S247>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians2_Gain_o;/* Expression: pi/180
                                              * Referenced by: '<S238>/convert -1,1 to -20,20 deg in radians2'
                                              */
  real_T Internal_A_kt;                /* Computed Parameter: Internal_A_kt
                                        * Referenced by: '<S250>/Internal'
                                        */
  real_T Internal_B_j4;                /* Computed Parameter: Internal_B_j4
                                        * Referenced by: '<S250>/Internal'
                                        */
  real_T Internal_C_nc;                /* Computed Parameter: Internal_C_nc
                                        * Referenced by: '<S250>/Internal'
                                        */
  real_T Internal_D_n3;                /* Computed Parameter: Internal_D_n3
                                        * Referenced by: '<S250>/Internal'
                                        */
  real_T Internal_X0_ib;               /* Expression: 0
                                        * Referenced by: '<S250>/Internal'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_bs;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_bs
                                             * Referenced by: '<S248>/Discrete-Time Integrator1'
                                             */
  real_T DiscreteTimeIntegrator1_IC_og;/* Expression: 0
                                        * Referenced by: '<S248>/Discrete-Time Integrator1'
                                        */
  real_T convert11to2020deginradians1_Gain_m;/* Expression: pi/180
                                              * Referenced by: '<S238>/convert -1,1 to -20,20 deg in radians1'
                                              */
  real_T Internal_A_if;                /* Computed Parameter: Internal_A_if
                                        * Referenced by: '<S254>/Internal'
                                        */
  real_T Internal_B_lx;                /* Computed Parameter: Internal_B_lx
                                        * Referenced by: '<S254>/Internal'
                                        */
  real_T Internal_C_nf;                /* Computed Parameter: Internal_C_nf
                                        * Referenced by: '<S254>/Internal'
                                        */
  real_T Internal_D_fj;                /* Computed Parameter: Internal_D_fj
                                        * Referenced by: '<S254>/Internal'
                                        */
  real_T Internal_X0_g5;               /* Expression: 0
                                        * Referenced by: '<S254>/Internal'
                                        */
  real_T DiscreteTimeIntegrator_gainval_n;/* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                                           * Referenced by: '<S240>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S240>/Discrete-Time Integrator'
                                        */
  real_T yawvelgain_Gain_e;            /* Expression: 2
                                        * Referenced by: '<S238>/yaw vel gain'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.5*pi/180
                                        * Referenced by: '<S240>/Gain'
                                        */
  real_T Internal_A_m2;                /* Computed Parameter: Internal_A_m2
                                        * Referenced by: '<S258>/Internal'
                                        */
  real_T Internal_B_p;                 /* Computed Parameter: Internal_B_p
                                        * Referenced by: '<S258>/Internal'
                                        */
  real_T Internal_C_i;                 /* Computed Parameter: Internal_C_i
                                        * Referenced by: '<S258>/Internal'
                                        */
  real_T Internal_D_in;                /* Computed Parameter: Internal_D_in
                                        * Referenced by: '<S258>/Internal'
                                        */
  real_T Internal_X0_oi;               /* Expression: 0
                                        * Referenced by: '<S258>/Internal'
                                        */
  real_T yaw_gains_Value[3];           /* Expression: [4*0.15 0 0.15]
                                        * Referenced by: '<S60>/yaw_gains'
                                        */
  real_T Constant1_Value_d4;           /* Expression: 2*pi
                                        * Referenced by: '<S259>/Constant1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: pi
                                        * Referenced by: '<S259>/Switch'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_l;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_l
                                            * Referenced by: '<S249>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_aw;/* Expression: 0
                                        * Referenced by: '<S249>/Discrete-Time Integrator1'
                                        */
  real_T Hovermode_Value;              /* Expression: 3
                                        * Referenced by: '<S61>/Hover mode'
                                        */
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S269>/Out'
                                        */
  real_T LLH_ref_Y0[3];                /* Expression: [43.723141 10.393313 0]
                                        * Referenced by: '<S327>/LLH_ref'
                                        */
  real_T ECEF_ref_Y0[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<S327>/ECEF_ref'
                                        */
  real_T ECEF2NED_Y0[9];               /* Expression: eye(3,3)
                                        * Referenced by: '<S327>/ECEF2NED'
                                        */
  real_T Constant1_Value_kf;           /* Expression: 0
                                        * Referenced by: '<S338>/Constant1'
                                        */
  real_T Constant1_Value_ba;           /* Expression: 0
                                        * Referenced by: '<S339>/Constant1'
                                        */
  real_T Constant2_Value_gx;           /* Expression: 9.81
                                        * Referenced by: '<S340>/Constant2'
                                        */
  real_T Constant1_Value_jd;           /* Expression: 0
                                        * Referenced by: '<S340>/Constant1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S344>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S345>/Constant1'
                                        */
  real_T Constant1_Value_pa;           /* Expression: 0
                                        * Referenced by: '<S346>/Constant1'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S374>/Constant2'
                                        */
  real_T fake0secPPMage_Value;         /* Expression: 0
                                        * Referenced by: '<S351>/fake 0 sec PPM age'
                                        */
  real_T Out_Y0_o;                     /* Expression: -1000
                                        * Referenced by: '<S376>/Out'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S396>/Gain'
                                        */
  real_T Constant_Value_a;             /* Expression: 180
                                        * Referenced by: '<S396>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S395>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 180
                                        * Referenced by: '<S395>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S375>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<S375>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S375>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S375>/Pulse Generator'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0.5
                                        * Referenced by: '<S375>/Switch'
                                        */
  real_T Constant1_Value_h1;           /* Expression: 0
                                        * Referenced by: '<S432>/Constant1'
                                        */
  real_T Constant1_Value_nw;           /* Expression: 0
                                        * Referenced by: '<S433>/Constant1'
                                        */
  real_T Constant2_Value_a0;           /* Expression: 9.81
                                        * Referenced by: '<S434>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S434>/Constant1'
                                        */
  real_T Constant1_Value_ol;           /* Expression: 0
                                        * Referenced by: '<S438>/Constant1'
                                        */
  real_T Constant1_Value_ot;           /* Expression: 0
                                        * Referenced by: '<S439>/Constant1'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S440>/Constant1'
                                        */
  real_T Constant1_Value_h1r;          /* Expression: 0
                                        * Referenced by: '<S484>/Constant1'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S333>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S333>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S333>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 11
                                        * Referenced by: '<S333>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S333>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S333>/Step1'
                                        */
  real_T HW0SIM_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch4'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch2'
                                        */
  real_T RateTransition6_X0;           /* Expression: 0
                                        * Referenced by: '<S22>/Rate Transition6'
                                        */
  real_T Constant3_Value_b[5];         /* Expression: [0.46 0 0.15 0.15 0]'
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T Step_Time_c;                  /* Expression: 1
                                        * Referenced by: '<S427>/Step'
                                        */
  real_T Step_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S427>/Step'
                                        */
  real_T Step_YFinal_b;                /* Expression: 1
                                        * Referenced by: '<S427>/Step'
                                        */
  real_T Step1_Time_n;                 /* Expression: 11
                                        * Referenced by: '<S427>/Step1'
                                        */
  real_T Step1_Y0_g;                   /* Expression: 0
                                        * Referenced by: '<S427>/Step1'
                                        */
  real_T Step1_YFinal_m;               /* Expression: 1
                                        * Referenced by: '<S427>/Step1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch1'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch'
                                        */
  real_T scalefactorcorrectiongoodfortest_calib_2_Gain;/* Expression: 1.155
                                                        * Referenced by: '<S350>/scale factor correction (good for test_calib_2)'
                                                        */
  real_T PPMCapture_P1;                /* Expression: ST
                                        * Referenced by: '<S351>/PPM Capture'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch3'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S351>/Switch5'
                                        */
  real_T WPmodedisabled_Value;         /* Expression: 0
                                        * Referenced by: '<S15>/WP mode disabled '
                                        */
  real_T RateTransition3_X0;           /* Expression: 0
                                        * Referenced by: '<S48>/Rate Transition3'
                                        */
  real_T CommandselalwaysJETI_Value;   /* Expression: bin2dec('00001000')
                                        * Referenced by: '<S15>/Command sel : always JETI  '
                                        */
  real_T SSonly_Value;                 /* Expression: 0
                                        * Referenced by: '<S15>/SS only'
                                        */
  real_T ahrs_sel_Gain;                /* Expression: 128
                                        * Referenced by: '<S15>/ahrs_sel'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<S16>/Rate Transition1'
                                        */
  real_T udisablein_flightflagfunctionalities_Value;/* Expression: 0
                                                     * Referenced by: '<S16>/==0 disable in_flight flag functionalities'
                                                     */
  real_T Step1_Time_e;                 /* Expression: 11
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T Step1_Y0_c;                   /* Expression: 0
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T Step1_YFinal_n;               /* Expression: 1
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T RateTransition2_X0;           /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition2'
                                        */
  real_T Step_Time_j;                  /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_YFinal_n;                /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S470>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S470>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S470>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S470>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<S470>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;       /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S470>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S470>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S470>/Pulse Generator2'
                                        */
  real_T RateTransition3_X0_e;         /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition3'
                                        */
  real_T Constant3_Value_pr;           /* Expression: -9.81
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T lowerHdynamics_Value[3];      /* Expression: [0.08 0 0.08]'
                                        * Referenced by: '<S9>/lower H dynamics'
                                        */
  real_T higherHdynamics_Value[3];     /* Expression: [0.12 0 0.15]'
                                        * Referenced by: '<S9>/higher H dynamics'
                                        */
  real_T Constant14_Value;             /* Expression: 35
                                        * Referenced by: '<S9>/Constant14'
                                        */
  real_T RateTransition1_X0_p;         /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  real_T Constant7_Value_h[2];         /* Expression: [4 0]'
                                        * Referenced by: '<S9>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: [0.05]'
                                        * Referenced by: '<S9>/Constant8'
                                        */
  real_T controllerseltoDPmodesel_Value;/* Expression: 3
                                         * Referenced by: '<S49>/controller sel to DP mode sel'
                                         */
  real_T converttohifreqHz_X0;         /* Expression: 0
                                        * Referenced by: '<S16>/convert to hi freq Hz'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S191>/Gain3'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S191>/Gain4'
                                        */
  real_T Constant7_Value_k;            /* Expression: 0
                                        * Referenced by: '<S191>/Constant7'
                                        */
  real_T Constant1_Value_mo;           /* Expression: 0
                                        * Referenced by: '<S191>/Constant1'
                                        */
  real_T Gain5_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S191>/Gain5'
                                        */
  real_T Constant2_Value_ot;           /* Expression: 0
                                        * Referenced by: '<S191>/Constant2'
                                        */
  real_T Gain6_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S191>/Gain6'
                                        */
  real_T Gain3_Gain_hv;                /* Expression: pi/180
                                        * Referenced by: '<S190>/Gain3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: pi/180
                                        * Referenced by: '<S190>/Gain4'
                                        */
  real_T Constant7_Value_i;            /* Expression: 0
                                        * Referenced by: '<S190>/Constant7'
                                        */
  real_T Constant1_Value_h2;           /* Expression: 0
                                        * Referenced by: '<S190>/Constant1'
                                        */
  real_T Gain5_Gain_f;                 /* Expression: pi/180
                                        * Referenced by: '<S190>/Gain5'
                                        */
  real_T Constant2_Value_at;           /* Expression: 0
                                        * Referenced by: '<S190>/Constant2'
                                        */
  real_T Gain6_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S190>/Gain6'
                                        */
  real_T avoid0dist_Value;             /* Expression: 0.1
                                        * Referenced by: '<S182>/avoid 0 dist'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T storeinside_RTH_circleflag_InitialCondition;/* Expression: 0
                                                      * Referenced by: '<S49>/store inside_RTH_circle flag'
                                                      */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S184>/Unit Delay'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S185>/Unit Delay'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S189>/Unit Delay'
                                        */
  real_T deltaHforreturntohome_Value;  /* Expression: 3
                                        * Referenced by: '<S186>/delta H for return to home'
                                        */
  real_T DiscreteTimeIntegrator_gainval_l;/* Computed Parameter: DiscreteTimeIntegrator_gainval_l
                                           * Referenced by: '<S188>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_az; /* Expression: 0
                                        * Referenced by: '<S188>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval_cn;/* Computed Parameter: DiscreteTimeIntegrator_gainval_cn
                                            * Referenced by: '<S180>/Discrete-Time Integrator'
                                            */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S215>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval_g;/* Computed Parameter: DiscreteTimeIntegrator_gainval_g
                                           * Referenced by: '<S214>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_bu; /* Expression: 0
                                        * Referenced by: '<S214>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval_ax;/* Computed Parameter: DiscreteTimeIntegrator_gainval_ax
                                            * Referenced by: '<S181>/Discrete-Time Integrator'
                                            */
  real_T Fr_ref_Value[2];              /* Expression: [0 0]
                                        * Referenced by: '<S48>/Fr_ref'
                                        */
  real_T Gain3_Gain_hvp;               /* Expression: pi/180
                                        * Referenced by: '<S169>/Gain3'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S169>/Gain4'
                                        */
  real_T Constant7_Value_f;            /* Expression: 0
                                        * Referenced by: '<S169>/Constant7'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S169>/Constant1'
                                        */
  real_T Gain5_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S169>/Gain5'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S169>/Constant2'
                                        */
  real_T Gain6_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S169>/Gain6'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S173>/Gain3'
                                        */
  real_T Gain4_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S173>/Gain4'
                                        */
  real_T Constant7_Value_o;            /* Expression: 0
                                        * Referenced by: '<S173>/Constant7'
                                        */
  real_T Constant1_Value_ka;           /* Expression: 0
                                        * Referenced by: '<S173>/Constant1'
                                        */
  real_T Gain5_Gain_k;                 /* Expression: pi/180
                                        * Referenced by: '<S173>/Gain5'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S173>/Constant2'
                                        */
  real_T Gain6_Gain_k;                 /* Expression: pi/180
                                        * Referenced by: '<S173>/Gain6'
                                        */
  real_T Pitch_ref_Value;              /* Expression: -15
                                        * Referenced by: '<S160>/Pitch_ref'
                                        */
  real_T UnitDelay_InitialCondition_j; /* Expression: 0
                                        * Referenced by: '<S168>/Unit Delay'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 180/pi
                                        * Referenced by: '<S160>/rad2deg1'
                                        */
  real_T DiscreteTimeIntegrator_gainval_h;/* Computed Parameter: DiscreteTimeIntegrator_gainval_h
                                           * Referenced by: '<S165>/Discrete-Time Integrator'
                                           */
  real_T rad2deg_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S160>/rad2deg'
                                        */
  real_T gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S160>/gain'
                                        */
  real_T rad2deg2_Gain;                /* Expression: 180/pi
                                        * Referenced by: '<S160>/rad2deg2'
                                        */
  real_T RateTransition1_X0_o;         /* Expression: 0
                                        * Referenced by: '<S48>/Rate Transition1'
                                        */
  real_T RateTransition4_X0;           /* Expression: 0
                                        * Referenced by: '<S48>/Rate Transition4'
                                        */
  real_T Constant1_Value_aw;           /* Expression: 1
                                        * Referenced by: '<S177>/Constant1'
                                        */
  real_T Constant6_Value_k;            /* Expression: 0.5
                                        * Referenced by: '<S177>/Constant6'
                                        */
  real_T Constant7_Value_ic;           /* Expression: 0
                                        * Referenced by: '<S177>/Constant7'
                                        */
  real_T Gain_Gain_f1;                 /* Expression: 2
                                        * Referenced by: '<S177>/Gain'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S188>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -1
                                        * Referenced by: '<S188>/Saturation1'
                                        */
  real_T Saturation_UpperSat_az;       /* Expression: 1
                                        * Referenced by: '<S188>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S188>/Saturation'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S180>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S180>/Saturation1'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S181>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_gp;      /* Expression: -slew_rate_SR*slew_rate_ST
                                        * Referenced by: '<S181>/Saturation1'
                                        */
  real_T Constant6_Value_d;            /* Expression: 1
                                        * Referenced by: '<S187>/Constant6'
                                        */
  real_T Constant7_Value_ik;           /* Expression: 0
                                        * Referenced by: '<S187>/Constant7'
                                        */
  real_T Saturation1_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S214>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_f;       /* Expression: -1
                                        * Referenced by: '<S214>/Saturation1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1
                                        * Referenced by: '<S214>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -1
                                        * Referenced by: '<S214>/Saturation'
                                        */
  real_T delaybyonesampletoallowforhovertostartandlast1samplebeforegoingt;/* Expression: 0
                                                                      * Referenced by: '<S51>/delay by one sample to allow for  hover to start and last 1 sample  before going to waypoints '
                                                                      */
  real_T Gain3_Gain_o;                 /* Expression: pi/180
                                        * Referenced by: '<S220>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: pi/180
                                        * Referenced by: '<S220>/Gain4'
                                        */
  real_T Constant7_Value_ei;           /* Expression: 0
                                        * Referenced by: '<S220>/Constant7'
                                        */
  real_T Constant1_Value_ok;           /* Expression: 0
                                        * Referenced by: '<S220>/Constant1'
                                        */
  real_T Gain5_Gain_a;                 /* Expression: pi/180
                                        * Referenced by: '<S220>/Gain5'
                                        */
  real_T Constant2_Value_an;           /* Expression: 0
                                        * Referenced by: '<S220>/Constant2'
                                        */
  real_T Gain6_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S220>/Gain6'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T syncro1_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/syncro == 1'
                                        */
  real_T dummydata1_Value[6];          /* Expression: [0 0 0 0 0 0]'
                                        * Referenced by: '<Root>/dummy data1'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S221>/Gain3'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S221>/Gain4'
                                        */
  real_T Constant7_Value_c;            /* Expression: 0
                                        * Referenced by: '<S221>/Constant7'
                                        */
  real_T Constant1_Value_fw;           /* Expression: 0
                                        * Referenced by: '<S221>/Constant1'
                                        */
  real_T Gain5_Gain_o;                 /* Expression: pi/180
                                        * Referenced by: '<S221>/Gain5'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S221>/Constant2'
                                        */
  real_T Gain6_Gain_nx;                /* Expression: pi/180
                                        * Referenced by: '<S221>/Gain6'
                                        */
  real_T avoid0dist1_Value;            /* Expression: 0.1
                                        * Referenced by: '<S218>/avoid 0 dist1'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S232>/Gain3'
                                        */
  real_T Gain4_Gain_da;                /* Expression: pi/180
                                        * Referenced by: '<S232>/Gain4'
                                        */
  real_T Gain5_Gain_gq;                /* Expression: pi/180
                                        * Referenced by: '<S232>/Gain5'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: pi/180
                                        * Referenced by: '<S232>/Gain6'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 1
                                        * Referenced by: '<S229>/Switch'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S224>/Memory'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S224>/Switch'
                                        */
  real_T Switch3_Threshold_b;          /* Expression: 0
                                        * Referenced by: '<S219>/Switch3'
                                        */
  real_T Kroll_Gain;                   /* Expression: -1
                                        * Referenced by: '<S224>/Kroll'
                                        */
  real_T Gain_Gain_fl;                 /* Expression: 1.8315/1000
                                        * Referenced by: '<S364>/Gain'
                                        */
  real_T Constant2_Value_k;            /* Expression: 255
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Saturation_LowerSat_d[4];     /* Expression: [0; -TLMNsat(2:end)]
                                        * Referenced by: '<S481>/Saturation'
                                        */
  real_T Gain_Gain_lp;                 /* Expression: 255
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T RateTransition11_X0;          /* Expression: 0
                                        * Referenced by: '<S9>/Rate Transition11'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S1>/Rate Transition'
                                        */
  real_T Gain16_Gain;                  /* Expression: 3/4096
                                        * Referenced by: '<S1>/Gain16'
                                        */
  real_T scalefactorforresistornetworkfromdirectVmeasures_Gain;/* Expression: 16.43/1.69
                                                                * Referenced by: '<S1>/scale factor for resistor network - from direct V measures'
                                                                */
  real_T Gain1_Gain_n;                 /* Expression: 3/4096
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3/4096
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Currentsensorsensitivity_Value;/* Expression: 0.028 * 3.3 / 5
                                         * Referenced by: '<S1>/Current sensor sensitivity'
                                         */
  real_T Internal_A_ld;                /* Computed Parameter: Internal_A_ld
                                        * Referenced by: '<S471>/Internal'
                                        */
  real_T Internal_B_g4;                /* Computed Parameter: Internal_B_g4
                                        * Referenced by: '<S471>/Internal'
                                        */
  real_T Internal_C_o;                 /* Computed Parameter: Internal_C_o
                                        * Referenced by: '<S471>/Internal'
                                        */
  real_T Internal_X0_hc;               /* Expression: 0
                                        * Referenced by: '<S471>/Internal'
                                        */
  real_T Internal_A_ee;                /* Computed Parameter: Internal_A_ee
                                        * Referenced by: '<S472>/Internal'
                                        */
  real_T Internal_B_po;                /* Computed Parameter: Internal_B_po
                                        * Referenced by: '<S472>/Internal'
                                        */
  real_T Internal_C_mn;                /* Computed Parameter: Internal_C_mn
                                        * Referenced by: '<S472>/Internal'
                                        */
  real_T Internal_X0_gk;               /* Expression: 0
                                        * Referenced by: '<S472>/Internal'
                                        */
  real_T integratecurrent_gainval;     /* Computed Parameter: integratecurrent_gainval
                                        * Referenced by: '<S24>/integrate current'
                                        */
  real_T integratecurrent_IC;          /* Expression: 0
                                        * Referenced by: '<S24>/integrate current'
                                        */
  real_T hinsec_Value;                 /* Expression: 3600
                                        * Referenced by: '<S24>/1 h in sec '
                                        */
  real_T secto10thofmsecrepresentsavaluefrom001secto255seconaBYTE_Gain;/* Expression: 100
                                                                      * Referenced by: '<S271>/sec to 10th of msec ( represents a value from 0.01 sec to 2.55 sec on a BYTE )'
                                                                      */
  real_T UnitDelay_InitialCondition_eq;/* Expression: 0
                                        * Referenced by: '<S282>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval_eq;/* Computed Parameter: DiscreteTimeIntegrator_gainval_eq
                                            * Referenced by: '<S282>/Discrete-Time Integrator'
                                            */
  real_T DiscreteTimeIntegrator_IC_af; /* Expression: 0
                                        * Referenced by: '<S282>/Discrete-Time Integrator'
                                        */
  real_T secto10thofmsecrepresentsavaluefrom001secto255seconaBYTE_Gain_e;/* Expression: 100
                                                                      * Referenced by: '<S271>/sec to 10th of msec ( represents a value from 0.01 sec to 2.55 sec on a BYTE ) '
                                                                      */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S283>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval_g1;/* Computed Parameter: DiscreteTimeIntegrator_gainval_g1
                                            * Referenced by: '<S283>/Discrete-Time Integrator'
                                            */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S283>/Discrete-Time Integrator'
                                        */
  real_T secto10thofmsecrepresentsavaluefrom01secto255seconaBYTE_Gain;/* Expression: 10
                                                                      * Referenced by: '<S271>/sec to 10th of msec ( represents a value from 0.1 sec to 25.5 sec on a BYTE )'
                                                                      */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S284>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval_p;/* Computed Parameter: DiscreteTimeIntegrator_gainval_p
                                           * Referenced by: '<S284>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S284>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval_ah;/* Computed Parameter: DiscreteTimeIntegrator_gainval_ah
                                            * Referenced by: '<S286>/Discrete-Time Integrator'
                                            */
  real_T DiscreteTimeIntegrator_IC_ae; /* Expression: 0
                                        * Referenced by: '<S286>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay_InitialCondition_px;/* Expression: 0
                                        * Referenced by: '<S285>/Unit Delay'
                                        */
  real_T limittoBYTE0255_UpperSat;     /* Expression: 255
                                        * Referenced by: '<S271>/limit to BYTE [0-255]'
                                        */
  real_T limittoBYTE0255_LowerSat;     /* Expression: 0
                                        * Referenced by: '<S271>/limit to BYTE [0-255]'
                                        */
  real_T telemetrytypeseldebugtelemetrywithDPdataintheDEBUG_6_FLOATSpacke[4];/* Expression: [3 0 0 0]'
                                                                      * Referenced by: '<S15>/telemetry type sel: debug telemetry with DP data in  the DEBUG_6_FLOATS packet'
                                                                      */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S276>/Unit Delay'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant4'
                                        */
  real_T Constant2_Value_e[7];         /* Expression: [0 0 0 0 0 0 0]'
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T ResetGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S282>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<S282>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S282>/Reset  Generator'
                                        */
  real_T ResetGenerator_Amp_g;         /* Expression: 1
                                        * Referenced by: '<S283>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty_m;        /* Expression: 1
                                        * Referenced by: '<S283>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay_f;  /* Expression: 0
                                        * Referenced by: '<S283>/Reset  Generator'
                                        */
  real_T ResetGenerator_Amp_k;         /* Expression: 1
                                        * Referenced by: '<S284>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty_l;        /* Expression: 1
                                        * Referenced by: '<S284>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay_g;  /* Expression: 0
                                        * Referenced by: '<S284>/Reset  Generator'
                                        */
  real_T ResetGenerator_Amp_h;         /* Expression: 1
                                        * Referenced by: '<S285>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty_d;        /* Expression: 1
                                        * Referenced by: '<S285>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay_k;  /* Expression: 0
                                        * Referenced by: '<S285>/Reset  Generator'
                                        */
  real_T ResetGenerator_Amp_f;         /* Expression: 1
                                        * Referenced by: '<S286>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty_a;        /* Expression: 1
                                        * Referenced by: '<S286>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay_n;  /* Expression: 0
                                        * Referenced by: '<S286>/Reset  Generator'
                                        */
  real_T ResetGenerator_Amp_j;         /* Expression: 1
                                        * Referenced by: '<S276>/Reset  Generator'
                                        */
  real_T ResetGenerator_Duty_n;        /* Expression: 1
                                        * Referenced by: '<S276>/Reset  Generator'
                                        */
  real_T ResetGenerator_PhaseDelay_b;  /* Expression: 0
                                        * Referenced by: '<S276>/Reset  Generator'
                                        */
  real_T Gain_Gain_f5[9];              /* Expression: diag([pi/180 pi/180 1])
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S352>/Delay'
                                        */
  real_T calibrateStep_Time;           /* Expression: 10
                                        * Referenced by: '<S424>/calibrate Step'
                                        */
  real_T calibrateStep_Y0[4];          /* Expression: [255 255 255 255]
                                        * Referenced by: '<S424>/calibrate Step'
                                        */
  real_T calibrateStep_YFinal[4];      /* Expression: [0 0 0 0]
                                        * Referenced by: '<S424>/calibrate Step'
                                        */
  real_T enablemotorscmd_Time;         /* Expression: 20
                                        * Referenced by: '<S424>/enable motors cmd'
                                        */
  real_T enablemotorscmd_Y0;           /* Expression: 0
                                        * Referenced by: '<S424>/enable motors cmd'
                                        */
  real_T enablemotorscmd_YFinal;       /* Expression: 1
                                        * Referenced by: '<S424>/enable motors cmd'
                                        */
  real_T disnablemotors_Time;          /* Expression: 60
                                        * Referenced by: '<S424>/disnable motors'
                                        */
  real_T disnablemotors_Y0;            /* Expression: 0
                                        * Referenced by: '<S424>/disnable motors'
                                        */
  real_T disnablemotors_YFinal;        /* Expression: -1
                                        * Referenced by: '<S424>/disnable motors'
                                        */
  real_T minspeed_Value[4];            /* Expression: [1 1 1 1]
                                        * Referenced by: '<S424>/min speed'
                                        */
  real_T Step_Y0_e;                    /* Expression: 0
                                        * Referenced by: '<S425>/Step'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 255
                                        * Referenced by: '<S424>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S424>/Saturation'
                                        */
  real_T TestRamp_Value[3];            /* Expression: [1 1 1]
                                        * Referenced by: '<S352>/Test Ramp'
                                        */
  real_T pwm0ms_Value;                 /* Expression: 1.120
                                        * Referenced by: '<S352>/pwm0 [ms]'
                                        */
  real_T step_Value;                   /* Expression: 0.82/4*ST
                                        * Referenced by: '<S352>/step'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1.940
                                        * Referenced by: '<S352>/Saturation'
                                        */
  real_T Saturation_LowerSat_ju;       /* Expression: 0
                                        * Referenced by: '<S352>/Saturation'
                                        */
  real_T TestSimple_Value[4];          /* Expression: [1 1.5 2 2.25]
                                        * Referenced by: '<S352>/Test Simple'
                                        */
  real_T Switch2_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S350>/Switch2'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 100
                                        * Referenced by: '<S373>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 2047
                                        * Referenced by: '<S373>/Constant'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 100
                                        * Referenced by: '<S372>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2047
                                        * Referenced by: '<S372>/Constant'
                                        */
  real_T Step_Time_f;                  /* Expression: 1
                                        * Referenced by: '<S26>/Step'
                                        */
  real_T Step_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S26>/Step'
                                        */
  real_T Step_YFinal_a;                /* Expression: 1
                                        * Referenced by: '<S26>/Step'
                                        */
  real_T Step1_Time_l;                 /* Expression: 11
                                        * Referenced by: '<S26>/Step1'
                                        */
  real_T Step1_Y0_f;                   /* Expression: 0
                                        * Referenced by: '<S26>/Step1'
                                        */
  real_T Step1_YFinal_k;               /* Expression: 1
                                        * Referenced by: '<S26>/Step1'
                                        */
  real_T PWM1_P1;                      /* Expression: 1
                                        * Referenced by: '<S1>/PWM1'
                                        */
  real_T PulseGenerator1_Amp_e;        /* Expression: 1
                                        * Referenced by: '<S20>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_l;     /* Computed Parameter: PulseGenerator1_Period_l
                                        * Referenced by: '<S20>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty_f;       /* Computed Parameter: PulseGenerator1_Duty_f
                                        * Referenced by: '<S20>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay_d; /* Expression: 0
                                        * Referenced by: '<S20>/Pulse Generator1'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S355>/Gain1'
                                        */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S355>/Gain2'
                                        */
  real32_T Switch2_Threshold_j;        /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S338>/Switch2'
                                        */
  real32_T Switch2_Threshold_l;        /* Computed Parameter: Switch2_Threshold_l
                                        * Referenced by: '<S339>/Switch2'
                                        */
  real32_T Switch2_Threshold_i;        /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S340>/Switch2'
                                        */
  real32_T Switch2_Threshold_k;        /* Computed Parameter: Switch2_Threshold_k
                                        * Referenced by: '<S344>/Switch2'
                                        */
  real32_T Switch2_Threshold_i4;       /* Computed Parameter: Switch2_Threshold_i4
                                        * Referenced by: '<S345>/Switch2'
                                        */
  real32_T Switch2_Threshold_h;        /* Computed Parameter: Switch2_Threshold_h
                                        * Referenced by: '<S346>/Switch2'
                                        */
  real32_T Switch2_Threshold_a;        /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S432>/Switch2'
                                        */
  real32_T Switch2_Threshold_n;        /* Computed Parameter: Switch2_Threshold_n
                                        * Referenced by: '<S433>/Switch2'
                                        */
  real32_T Switch2_Threshold_m;        /* Computed Parameter: Switch2_Threshold_m
                                        * Referenced by: '<S434>/Switch2'
                                        */
  real32_T Switch2_Threshold_d;        /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S438>/Switch2'
                                        */
  real32_T Switch2_Threshold_d2;       /* Computed Parameter: Switch2_Threshold_d2
                                        * Referenced by: '<S439>/Switch2'
                                        */
  real32_T Switch2_Threshold_g;        /* Computed Parameter: Switch2_Threshold_g
                                        * Referenced by: '<S440>/Switch2'
                                        */
  real32_T Constant1_Value_hs[3];      /* Computed Parameter: Constant1_Value_hs
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real32_T Switch2_Threshold_lc;       /* Computed Parameter: Switch2_Threshold_lc
                                        * Referenced by: '<S33>/Switch2'
                                        */
  real32_T Switch2_Threshold_b;        /* Computed Parameter: Switch2_Threshold_b
                                        * Referenced by: '<S34>/Switch2'
                                        */
  real32_T Switch2_Threshold_jj;       /* Computed Parameter: Switch2_Threshold_jj
                                        * Referenced by: '<S35>/Switch2'
                                        */
  real32_T Switch2_Threshold_nb;       /* Computed Parameter: Switch2_Threshold_nb
                                        * Referenced by: '<S39>/Switch2'
                                        */
  real32_T Switch2_Threshold_o;        /* Computed Parameter: Switch2_Threshold_o
                                        * Referenced by: '<S40>/Switch2'
                                        */
  real32_T Switch2_Threshold_f;        /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S41>/Switch2'
                                        */
  real32_T Constant1_Value_e[3];       /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real32_T Constant1_Value_mc[3];      /* Computed Parameter: Constant1_Value_mc
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real32_T Switch2_Threshold_oz;       /* Computed Parameter: Switch2_Threshold_oz
                                        * Referenced by: '<S484>/Switch2'
                                        */
  uint32_T Expected12channelFillingwithzeros_Value[4];/* Computed Parameter: Expected12channelFillingwithzeros_Value
                                                       * Referenced by: '<S369>/Expected 12 channel: Filling with zeros'
                                                       */
  uint32_T Rx_ID1_Value;               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S370>/Rx_ID1'
                                        */
  uint32_T Rx_ID2_Value;               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S370>/Rx_ID2'
                                        */
  uint32_T Rx_ID3_Value;               /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S370>/Rx_ID3'
                                        */
  uint32_T Rx_ID4_Value;               /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S370>/Rx_ID4'
                                        */
  uint32_T Rx_ID5_Value;               /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S370>/Rx_ID5'
                                        */
  uint32_T Rx_ID6_Value;               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S370>/Rx_ID6'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S352>/Delay'
                                        */
  uint32_T RateTransition18_X0;        /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S374>/Rate Transition18'
                                        */
  uint16_T RateTransition19_X0;        /* Computed Parameter: RateTransition19_X0
                                        * Referenced by: '<S374>/Rate Transition19'
                                        */
  uint16_T RateTransition20_X0;        /* Computed Parameter: RateTransition20_X0
                                        * Referenced by: '<S374>/Rate Transition20'
                                        */
  uint16_T Constant1_Value_pv[4];      /* Computed Parameter: Constant1_Value_pv
                                        * Referenced by: '<S374>/Constant1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S66>/Manual Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting_g;/* Computed Parameter: ManualSwitch_CurrentSetting_g
                                         * Referenced by: '<S64>/Manual Switch'
                                         */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S47>/Manual Switch1'
                                        */
  uint8_T ManualSwitch_CurrentSetting_f;/* Computed Parameter: ManualSwitch_CurrentSetting_f
                                         * Referenced by: '<S47>/Manual Switch'
                                         */
  uint8_T selectOLDvsNEWcontroller_CurrentSetting;/* Computed Parameter: selectOLDvsNEWcontroller_CurrentSetting
                                                   * Referenced by: '<S106>/select OLD vs NEW controller'
                                                   */
  uint8_T ManualSwitch_CurrentSetting_fr;/* Computed Parameter: ManualSwitch_CurrentSetting_fr
                                          * Referenced by: '<S107>/Manual Switch'
                                          */
  uint8_T dontuseusemotorswhencontrollerisnotactivated_CurrentSetting;/* Computed Parameter: dontuseusemotorswhencontrollerisnotactivated_CurrentSetting
                                                                      * Referenced by: '<S50>/dont use//use motors when controller is not activated'
                                                                      */
  uint8_T ManualSwitch_CurrentSetting_e;/* Computed Parameter: ManualSwitch_CurrentSetting_e
                                         * Referenced by: '<S240>/Manual Switch'
                                         */
  uint8_T enableall_Value[6];          /* Computed Parameter: enableall_Value
                                        * Referenced by: '<S351>/enable all'
                                        */
  uint8_T enable0_Value;               /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S351>/enable 0'
                                        */
  uint8_T Constant_Value_ey;           /* Computed Parameter: Constant_Value_ey
                                        * Referenced by: '<S407>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S405>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S406>/FixPt Constant'
                                        */
  uint8_T Constant_Value_ec;           /* Computed Parameter: Constant_Value_ec
                                        * Referenced by: '<S469>/Constant'
                                        */
  uint8_T RateTransition14_X0;         /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S374>/Rate Transition14'
                                        */
  uint8_T RateTransition15_X0;         /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S374>/Rate Transition15'
                                        */
  uint8_T usecalibrateddata_CurrentSetting;/* Computed Parameter: usecalibrateddata_CurrentSetting
                                            * Referenced by: '<S350>/use calibrated  data'
                                            */
  uint8_T ManualSwitch8_CurrentSetting;/* Computed Parameter: ManualSwitch8_CurrentSetting
                                        * Referenced by: '<S463>/Manual Switch8'
                                        */
  uint8_T Output_InitialCondition_g;   /* Computed Parameter: Output_InitialCondition_g
                                        * Referenced by: '<S467>/Output'
                                        */
  uint8_T enableall3_Value[9];         /* Computed Parameter: enableall3_Value
                                        * Referenced by: '<S351>/enable all3'
                                        */
  uint8_T ManualSwitch4_CurrentSetting;/* Computed Parameter: ManualSwitch4_CurrentSetting
                                        * Referenced by: '<S9>/Manual Switch4'
                                        */
  uint8_T RateTransition_X0_p;         /* Computed Parameter: RateTransition_X0_p
                                        * Referenced by: '<S374>/Rate Transition'
                                        */
  uint8_T usecalibrateddata_CurrentSetting_d;/* Computed Parameter: usecalibrateddata_CurrentSetting_d
                                              * Referenced by: '<S350>/use calibrated  data '
                                              */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<S15>/Manual Switch3'
                                        */
  uint8_T ManualSwitch4_CurrentSetting_m;/* Computed Parameter: ManualSwitch4_CurrentSetting_m
                                          * Referenced by: '<Root>/Manual Switch4'
                                          */
  uint8_T ManualSwitch5_CurrentSetting;/* Computed Parameter: ManualSwitch5_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch5'
                                        */
  uint8_T ManualSwitch_CurrentSetting_c;/* Computed Parameter: ManualSwitch_CurrentSetting_c
                                         * Referenced by: '<S16>/Manual Switch'
                                         */
  uint8_T ManualSwitch11_CurrentSetting;/* Computed Parameter: ManualSwitch11_CurrentSetting
                                         * Referenced by: '<Root>/Manual Switch11'
                                         */
  uint8_T ManualSwitch8_CurrentSetting_p;/* Computed Parameter: ManualSwitch8_CurrentSetting_p
                                          * Referenced by: '<Root>/Manual Switch8'
                                          */
  uint8_T ManualSwitch9_CurrentSetting;/* Computed Parameter: ManualSwitch9_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch9'
                                        */
  uint8_T ManualSwitch10_CurrentSetting;/* Computed Parameter: ManualSwitch10_CurrentSetting
                                         * Referenced by: '<Root>/Manual Switch10'
                                         */
  uint8_T ManualSwitch3_CurrentSetting_g;/* Computed Parameter: ManualSwitch3_CurrentSetting_g
                                          * Referenced by: '<S9>/Manual Switch3'
                                          */
  uint8_T ManualSwitch8_CurrentSetting_l;/* Computed Parameter: ManualSwitch8_CurrentSetting_l
                                          * Referenced by: '<S9>/Manual Switch8'
                                          */
  uint8_T ManualSwitch_CurrentSetting_ei;/* Computed Parameter: ManualSwitch_CurrentSetting_ei
                                          * Referenced by: '<S160>/Manual Switch'
                                          */
  uint8_T ManualSwitch_CurrentSetting_en;/* Computed Parameter: ManualSwitch_CurrentSetting_en
                                          * Referenced by: '<S177>/Manual Switch'
                                          */
  uint8_T ManualSwitch_CurrentSetting_p;/* Computed Parameter: ManualSwitch_CurrentSetting_p
                                         * Referenced by: '<S187>/Manual Switch'
                                         */
  uint8_T ManualSwitch_CurrentSetting_m;/* Computed Parameter: ManualSwitch_CurrentSetting_m
                                         * Referenced by: '<S5>/Manual Switch'
                                         */
  uint8_T ManualSwitch6_CurrentSetting;/* Computed Parameter: ManualSwitch6_CurrentSetting
                                        * Referenced by: '<S9>/Manual Switch6'
                                        */
  uint8_T ManualSwitch7_CurrentSetting;/* Computed Parameter: ManualSwitch7_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch7'
                                        */
  uint8_T ManualSwitch7_CurrentSetting_o;/* Computed Parameter: ManualSwitch7_CurrentSetting_o
                                          * Referenced by: '<S9>/Manual Switch7'
                                          */
  uint8_T ManualSwitch7_CurrentSetting_i;/* Computed Parameter: ManualSwitch7_CurrentSetting_i
                                          * Referenced by: '<S275>/Manual Switch7'
                                          */
  uint8_T ManualSwitch1_CurrentSetting_a;/* Computed Parameter: ManualSwitch1_CurrentSetting_a
                                          * Referenced by: '<S275>/Manual Switch1'
                                          */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S9>/Manual Switch2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting_d;/* Computed Parameter: ManualSwitch1_CurrentSetting_d
                                          * Referenced by: '<S9>/Manual Switch1'
                                          */
  uint8_T ManualSwitch2_CurrentSetting_k;/* Computed Parameter: ManualSwitch2_CurrentSetting_k
                                          * Referenced by: '<S271>/Manual Switch2'
                                          */
  uint8_T ManualSwitch6_CurrentSetting_e;/* Computed Parameter: ManualSwitch6_CurrentSetting_e
                                          * Referenced by: '<Root>/Manual Switch6'
                                          */
  uint8_T ManualSwitch5_CurrentSetting_o;/* Computed Parameter: ManualSwitch5_CurrentSetting_o
                                          * Referenced by: '<S9>/Manual Switch5'
                                          */
  uint8_T enableall2_Value;            /* Computed Parameter: enableall2_Value
                                        * Referenced by: '<S351>/enable all2'
                                        */
  uint8_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S288>/Constant'
                                        */
  uint8_T ManualSwitch_CurrentSetting_et;/* Computed Parameter: ManualSwitch_CurrentSetting_et
                                          * Referenced by: '<S352>/Manual Switch'
                                          */
  uint8_T ManualSwitch2_CurrentSetting_g;/* Computed Parameter: ManualSwitch2_CurrentSetting_g
                                          * Referenced by: '<S352>/Manual Switch2'
                                          */
  uint8_T ManualSwitch1_CurrentSetting_m;/* Computed Parameter: ManualSwitch1_CurrentSetting_m
                                          * Referenced by: '<S352>/Manual Switch1'
                                          */
  uint8_T bmp085accuracylevel_Value;   /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S18>/bmp085 accuracy level'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S468>/FixPt Constant'
                                        */
  boolean_T UnitDelay_InitialCondition_n;/* Computed Parameter: UnitDelay_InitialCondition_n
                                          * Referenced by: '<S294>/Unit Delay'
                                          */
  boolean_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                         * Referenced by: '<S294>/Unit Delay1'
                                         */
  boolean_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                         * Referenced by: '<S294>/Unit Delay2'
                                         */
  boolean_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                         * Referenced by: '<S294>/Unit Delay3'
                                         */
  boolean_T UnitDelay4_InitialCondition;/* Computed Parameter: UnitDelay4_InitialCondition
                                         * Referenced by: '<S294>/Unit Delay4'
                                         */
  boolean_T UnitDelay_InitialCondition_i;/* Computed Parameter: UnitDelay_InitialCondition_i
                                          * Referenced by: '<S295>/Unit Delay'
                                          */
  boolean_T UnitDelay1_InitialCondition_e;/* Computed Parameter: UnitDelay1_InitialCondition_e
                                           * Referenced by: '<S295>/Unit Delay1'
                                           */
  boolean_T UnitDelay2_InitialCondition_d;/* Computed Parameter: UnitDelay2_InitialCondition_d
                                           * Referenced by: '<S295>/Unit Delay2'
                                           */
  boolean_T UnitDelay3_InitialCondition_n;/* Computed Parameter: UnitDelay3_InitialCondition_n
                                           * Referenced by: '<S295>/Unit Delay3'
                                           */
  boolean_T UnitDelay4_InitialCondition_d;/* Computed Parameter: UnitDelay4_InitialCondition_d
                                           * Referenced by: '<S295>/Unit Delay4'
                                           */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S301>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_ey;/* Computed Parameter: UnitDelay_InitialCondition_ey
                                           * Referenced by: '<S293>/Unit Delay'
                                           */
  boolean_T UnitDelay1_InitialCondition_d;/* Computed Parameter: UnitDelay1_InitialCondition_d
                                           * Referenced by: '<S293>/Unit Delay1'
                                           */
  boolean_T UnitDelay2_InitialCondition_e;/* Computed Parameter: UnitDelay2_InitialCondition_e
                                           * Referenced by: '<S293>/Unit Delay2'
                                           */
  boolean_T UnitDelay3_InitialCondition_j;/* Computed Parameter: UnitDelay3_InitialCondition_j
                                           * Referenced by: '<S293>/Unit Delay3'
                                           */
  boolean_T UnitDelay4_InitialCondition_f;/* Computed Parameter: UnitDelay4_InitialCondition_f
                                           * Referenced by: '<S293>/Unit Delay4'
                                           */
  boolean_T Logic_table_o[16];         /* Computed Parameter: Logic_table_o
                                        * Referenced by: '<S308>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_j1;/* Computed Parameter: UnitDelay_InitialCondition_j1
                                           * Referenced by: '<S296>/Unit Delay'
                                           */
  boolean_T UnitDelay1_InitialCondition_n;/* Computed Parameter: UnitDelay1_InitialCondition_n
                                           * Referenced by: '<S296>/Unit Delay1'
                                           */
  boolean_T UnitDelay2_InitialCondition_b;/* Computed Parameter: UnitDelay2_InitialCondition_b
                                           * Referenced by: '<S296>/Unit Delay2'
                                           */
  boolean_T UnitDelay3_InitialCondition_a;/* Computed Parameter: UnitDelay3_InitialCondition_a
                                           * Referenced by: '<S296>/Unit Delay3'
                                           */
  boolean_T UnitDelay4_InitialCondition_b;/* Computed Parameter: UnitDelay4_InitialCondition_b
                                           * Referenced by: '<S296>/Unit Delay4'
                                           */
  boolean_T UnitDelay_InitialCondition_c;/* Computed Parameter: UnitDelay_InitialCondition_c
                                          * Referenced by: '<S297>/Unit Delay'
                                          */
  boolean_T UnitDelay1_InitialCondition_h;/* Computed Parameter: UnitDelay1_InitialCondition_h
                                           * Referenced by: '<S297>/Unit Delay1'
                                           */
  boolean_T UnitDelay2_InitialCondition_j;/* Computed Parameter: UnitDelay2_InitialCondition_j
                                           * Referenced by: '<S297>/Unit Delay2'
                                           */
  boolean_T UnitDelay3_InitialCondition_c;/* Computed Parameter: UnitDelay3_InitialCondition_c
                                           * Referenced by: '<S297>/Unit Delay3'
                                           */
  boolean_T UnitDelay4_InitialCondition_l;/* Computed Parameter: UnitDelay4_InitialCondition_l
                                           * Referenced by: '<S297>/Unit Delay4'
                                           */
  boolean_T UnitDelay_InitialCondition_ad;/* Computed Parameter: UnitDelay_InitialCondition_ad
                                           * Referenced by: '<S298>/Unit Delay'
                                           */
  boolean_T UnitDelay1_InitialCondition_i;/* Computed Parameter: UnitDelay1_InitialCondition_i
                                           * Referenced by: '<S298>/Unit Delay1'
                                           */
  boolean_T UnitDelay2_InitialCondition_a;/* Computed Parameter: UnitDelay2_InitialCondition_a
                                           * Referenced by: '<S298>/Unit Delay2'
                                           */
  boolean_T UnitDelay3_InitialCondition_i;/* Computed Parameter: UnitDelay3_InitialCondition_i
                                           * Referenced by: '<S298>/Unit Delay3'
                                           */
  boolean_T UnitDelay4_InitialCondition_n;/* Computed Parameter: UnitDelay4_InitialCondition_n
                                           * Referenced by: '<S298>/Unit Delay4'
                                           */
  boolean_T donotwaitforGPS_Value;     /* Computed Parameter: donotwaitforGPS_Value
                                        * Referenced by: '<S16>/do not wait for GPS'
                                        */
  boolean_T RateTransition2_X0_j;      /* Computed Parameter: RateTransition2_X0_j
                                        * Referenced by: '<S16>/Rate Transition2'
                                        */
  boolean_T Constant1_Value_fi;        /* Computed Parameter: Constant1_Value_fi
                                        * Referenced by: '<S59>/Constant1'
                                        */
  boolean_T Logic_table_a[16];         /* Computed Parameter: Logic_table_a
                                        * Referenced by: '<S237>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_g3;/* Computed Parameter: UnitDelay_InitialCondition_g3
                                           * Referenced by: '<S63>/Unit Delay'
                                           */
  boolean_T UnitDelay_InitialCondition_h5;/* Computed Parameter: UnitDelay_InitialCondition_h5
                                           * Referenced by: '<S209>/Unit Delay'
                                           */
  boolean_T UnitDelay_InitialCondition_n4;/* Computed Parameter: UnitDelay_InitialCondition_n4
                                           * Referenced by: '<S194>/Unit Delay'
                                           */
  boolean_T UnitDelay_InitialCondition_d;/* Computed Parameter: UnitDelay_InitialCondition_d
                                          * Referenced by: '<S279>/Unit Delay'
                                          */
  boolean_T UnitDelay1_InitialCondition_nd;/* Computed Parameter: UnitDelay1_InitialCondition_nd
                                            * Referenced by: '<S282>/Unit Delay1'
                                            */
  boolean_T UnitDelay1_InitialCondition_j;/* Computed Parameter: UnitDelay1_InitialCondition_j
                                           * Referenced by: '<S283>/Unit Delay1'
                                           */
  boolean_T UnitDelay1_InitialCondition_nb;/* Computed Parameter: UnitDelay1_InitialCondition_nb
                                            * Referenced by: '<S284>/Unit Delay1'
                                            */
  boolean_T UnitDelay1_InitialCondition_d1;/* Computed Parameter: UnitDelay1_InitialCondition_d1
                                            * Referenced by: '<S286>/Unit Delay1'
                                            */
  boolean_T UnitDelay1_InitialCondition_g;/* Computed Parameter: UnitDelay1_InitialCondition_g
                                           * Referenced by: '<S285>/Unit Delay1'
                                           */
  boolean_T UnitDelay1_InitialCondition_b;/* Computed Parameter: UnitDelay1_InitialCondition_b
                                           * Referenced by: '<S276>/Unit Delay1'
                                           */
  boolean_T Constant1_Value_o4;        /* Computed Parameter: Constant1_Value_o4
                                        * Referenced by: '<S326>/Constant1'
                                        */
  boolean_T Logic_table_n[16];         /* Computed Parameter: Logic_table_n
                                        * Referenced by: '<S330>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_m;/* Computed Parameter: UnitDelay_InitialCondition_m
                                          * Referenced by: '<S326>/Unit Delay'
                                          */
  boolean_T notifyONLYafterstoringinitialLLHfordataprojection_InitialConditi;/* Computed Parameter: notifyONLYafterstoringinitialLLHfordataprojection_InitialConditi
                                                                      * Referenced by: '<S326>/notify ONLY after storing initial LLH for data projection'
                                                                      */
  rtP_Subsystem_ICARO3_HAL_v1 Subsystem_a;/* '<S484>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_e4;/* '<S440>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_f;/* '<S439>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_e1;/* '<S438>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_n;/* '<S434>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_p;/* '<S433>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1 Subsystem_c;/* '<S432>/Subsystem' */
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterSS;/* '<S19>/Attitude Filter SS' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_i;/* '<S346>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_e5;/* '<S345>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_m;/* '<S344>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_e;/* '<S340>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_h;/* '<S339>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1 Subsystem;/* '<S338>/Subsystem' */
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterMPU;/* '<S17>/Attitude Filter MPU' */
  rtP_clocklatch_ICARO3_HAL_v1 clocklatch_a;/* '<S278>/clock latch' */
  rtP_clocklatch_ICARO3_HAL_v1 clocklatch_m;/* '<S267>/clock latch' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_d;/* '<S41>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_n4;/* '<S40>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_o;/* '<S35>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1_o Subsystem_b;/* '<S34>/Subsystem' */
  rtP_Subsystem_ICARO3_HAL_v1 Subsystem_l;/* '<S33>/Subsystem' */
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 AttitudeFilterADIS;/* '<S2>/Attitude Filter ADIS' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ICARO3_HAL_v1 {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint16_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
      boolean_T TID0_3;
      boolean_T TID1_4;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_ICARO3_HAL_v1 ICARO3_HAL_v1_P;

/* Block signals (auto storage) */
extern BlockIO_ICARO3_HAL_v1 ICARO3_HAL_v1_B;

/* Block states (auto storage) */
extern D_Work_ICARO3_HAL_v1 ICARO3_HAL_v1_DWork;

/* External function called from main */
extern void ICARO3_HAL_v1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ICARO3_HAL_v1_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ICARO3_HAL_v1_initialize(void);
extern void ICARO3_HAL_v1_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_ICARO3_HAL_v1 *const ICARO3_HAL_v1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ICARO3_HAL_v1'
 * '<S1>'   : 'ICARO3_HAL_v1/ADC1'
 * '<S2>'   : 'ICARO3_HAL_v1/ADIS AHRS1'
 * '<S3>'   : 'ICARO3_HAL_v1/Altitude Complementary Filter with 9dof ACC1'
 * '<S4>'   : 'ICARO3_HAL_v1/Altitude Complementary Filter with H_DATA_'
 * '<S5>'   : 'ICARO3_HAL_v1/Controllers w// FUZZY'
 * '<S6>'   : 'ICARO3_HAL_v1/DocBlock1'
 * '<S7>'   : 'ICARO3_HAL_v1/GPS UBLOX'
 * '<S8>'   : 'ICARO3_HAL_v1/GPS receiver VENUS'
 * '<S9>'   : 'ICARO3_HAL_v1/MAIN TELEMETRY1'
 * '<S10>'  : 'ICARO3_HAL_v1/MATLAB Function'
 * '<S11>'  : 'ICARO3_HAL_v1/MATLAB Function6'
 * '<S12>'  : 'ICARO3_HAL_v1/MATLAB Function7'
 * '<S13>'  : 'ICARO3_HAL_v1/MATLAB Function8'
 * '<S14>'  : 'ICARO3_HAL_v1/MATLAB Function9'
 * '<S15>'  : 'ICARO3_HAL_v1/MK stick commands decoder1'
 * '<S16>'  : 'ICARO3_HAL_v1/MODE manager1'
 * '<S17>'  : 'ICARO3_HAL_v1/MPU AHRS'
 * '<S18>'  : 'ICARO3_HAL_v1/NUOVO1'
 * '<S19>'  : 'ICARO3_HAL_v1/SS AHRS'
 * '<S20>'  : 'ICARO3_HAL_v1/Scheme Running'
 * '<S21>'  : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST'
 * '<S22>'  : 'ICARO3_HAL_v1/debug telemtry STATIC TEST'
 * '<S23>'  : 'ICARO3_HAL_v1/flashing LED notifier slow: filters debiasing fast: filter running'
 * '<S24>'  : 'ICARO3_HAL_v1/power computations1'
 * '<S25>'  : 'ICARO3_HAL_v1/quadrotor  control allocation1'
 * '<S26>'  : 'ICARO3_HAL_v1/set initial altitude to 1'
 * '<S27>'  : 'ICARO3_HAL_v1/ADIS AHRS1/Attitude Filter ADIS'
 * '<S28>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS'
 * '<S29>'  : 'ICARO3_HAL_v1/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S30>'  : 'ICARO3_HAL_v1/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S31>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend '
 * '<S32>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend'
 * '<S33>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend'
 * '<S34>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S35>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S36>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S37>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S38>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S39>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend'
 * '<S40>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1'
 * '<S41>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2'
 * '<S42>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S43>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S44>'  : 'ICARO3_HAL_v1/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S45>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller'
 * '<S46>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller'
 * '<S47>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller'
 * '<S48>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance'
 * '<S49>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator'
 * '<S50>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Off'
 * '<S51>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref'
 * '<S52>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 1'
 * '<S53>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 2'
 * '<S54>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 3: hover'
 * '<S55>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 4:Ret to Home'
 * '<S56>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 5: waypoint'
 * '<S57>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 6: fuzzy guidance'
 * '<S58>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/controller 7'
 * '<S59>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/detect first take off'
 * '<S60>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller'
 * '<S61>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/go back to hover when  waypoint list is empty (fuzzy guidance only : mode = 6)'
 * '<S62>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/manual'
 * '<S63>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/step 2 pulse generate trigger  for take off latch'
 * '<S64>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID'
 * '<S65>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS'
 * '<S66>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/H ref vario generation'
 * '<S67>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/MATLAB Function1'
 * '<S68>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/MATLAB Function4'
 * '<S69>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/PID altitude'
 * '<S70>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/Resetable slew rate limiter H'
 * '<S71>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/H ref vario generation/H vario'
 * '<S72>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/H ref vario generation/detect ref change and reset vario'
 * '<S73>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System'
 * '<S74>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/IO Delay'
 * '<S75>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/Input Delay'
 * '<S76>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/Output Delay'
 * '<S77>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch'
 * '<S78>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch1'
 * '<S79>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System'
 * '<S80>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/IO Delay'
 * '<S81>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Input Delay'
 * '<S82>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Output Delay'
 * '<S83>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System'
 * '<S84>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/IO Delay'
 * '<S85>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/Input Delay'
 * '<S86>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/Output Delay'
 * '<S87>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS'
 * '<S88>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch'
 * '<S89>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch1'
 * '<S90>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch/LTI System'
 * '<S91>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch/LTI System/IO Delay'
 * '<S92>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch/LTI System/Input Delay'
 * '<S93>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch/LTI System/Output Delay'
 * '<S94>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch1/LTI System'
 * '<S95>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch1/LTI System/IO Delay'
 * '<S96>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch1/LTI System/Input Delay'
 * '<S97>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/Attitude Controller/Attitude PIDS/PID Pitch1/LTI System/Output Delay'
 * '<S98>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID'
 * '<S99>'  : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS'
 * '<S100>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter2'
 * '<S101>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter3'
 * '<S102>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/MATLAB Function1'
 * '<S103>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/MATLAB Function2'
 * '<S104>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/MATLAB Function3'
 * '<S105>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PI Yaw'
 * '<S106>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x'
 * '<S107>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y'
 * '<S108>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/geo2ned'
 * '<S109>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/geo2ned1'
 * '<S110>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID/PID altitude'
 * '<S111>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID/PID altitude/LTI System'
 * '<S112>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID/PID altitude/LTI System/IO Delay'
 * '<S113>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID/PID altitude/LTI System/Input Delay'
 * '<S114>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Altitude PID/PID altitude/LTI System/Output Delay'
 * '<S115>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch'
 * '<S116>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch1'
 * '<S117>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch/LTI System'
 * '<S118>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/IO Delay'
 * '<S119>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Input Delay'
 * '<S120>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Output Delay'
 * '<S121>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System'
 * '<S122>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/IO Delay'
 * '<S123>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/Input Delay'
 * '<S124>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/Attitude PIDS/PID Pitch1/LTI System/Output Delay'
 * '<S125>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter2/IO Delay'
 * '<S126>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter2/Input Delay'
 * '<S127>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter2/Output Delay'
 * '<S128>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter3/IO Delay'
 * '<S129>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter3/Input Delay'
 * '<S130>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/LP Filter3/Output Delay'
 * '<S131>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PI Yaw/ensure that  -PI < y < PI'
 * '<S132>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/Discrete Derivative'
 * '<S133>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System'
 * '<S134>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System1'
 * '<S135>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System2'
 * '<S136>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System/IO Delay'
 * '<S137>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System/Input Delay'
 * '<S138>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System/Output Delay'
 * '<S139>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System1/IO Delay'
 * '<S140>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System1/Input Delay'
 * '<S141>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System1/Output Delay'
 * '<S142>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System2/IO Delay'
 * '<S143>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System2/Input Delay'
 * '<S144>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID x/LTI System2/Output Delay'
 * '<S145>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System'
 * '<S146>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System1'
 * '<S147>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System2'
 * '<S148>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System/IO Delay'
 * '<S149>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System/Input Delay'
 * '<S150>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System/Output Delay'
 * '<S151>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System1/IO Delay'
 * '<S152>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System1/Input Delay'
 * '<S153>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System1/Output Delay'
 * '<S154>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System2/IO Delay'
 * '<S155>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System2/Input Delay'
 * '<S156>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/PID y/LTI System2/Output Delay'
 * '<S157>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/geo2ned/MATLAB Function6'
 * '<S158>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/DP + Altitude Controller/geo2ned1/MATLAB Function6'
 * '<S159>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Compare To Constant'
 * '<S160>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance'
 * '<S161>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/FG Telemetry'
 * '<S162>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/GPS to NED'
 * '<S163>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/Guidance'
 * '<S164>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/MATLAB Function2'
 * '<S165>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/Resetable slew rate limiter YAW with ext reset value'
 * '<S166>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/WP Manager'
 * '<S167>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/pitch regulator'
 * '<S168>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/reset slew rate limiter when enabling FG'
 * '<S169>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/GPS to NED/geo2ned'
 * '<S170>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/GPS to NED/geo2ned/MATLAB Function6'
 * '<S171>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/WP Manager/LatLon to NED'
 * '<S172>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/WP Manager/WP Manager'
 * '<S173>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/WP Manager/LatLon to NED/geo2ned'
 * '<S174>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/WP Manager/LatLon to NED/geo2ned/MATLAB Function6'
 * '<S175>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/reset slew rate limiter when enabling FG/Compare To Constant'
 * '<S176>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/GUidance/Guidance/reset slew rate limiter when enabling FG/Compare To Constant1'
 * '<S177>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/H ref vario generation'
 * '<S178>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/MATLAB Function4'
 * '<S179>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/Ref manager'
 * '<S180>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/Resetable slew rate limiter H'
 * '<S181>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/Resetable slew rate limiter YAW'
 * '<S182>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/compute position error'
 * '<S183>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover'
 * '<S184>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/pulse when entering Hover or RTH '
 * '<S185>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints'
 * '<S186>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point'
 * '<S187>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/yaw ref vario generation'
 * '<S188>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/H ref vario generation/H vario'
 * '<S189>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/H ref vario generation/detect ref change and reset vario'
 * '<S190>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/compute position error/geo2ned1'
 * '<S191>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/compute position error/geo2ned2'
 * '<S192>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/compute position error/geo2ned1/MATLAB Function6'
 * '<S193>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/compute position error/geo2ned2/MATLAB Function6'
 * '<S194>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover/detect rising edge: transform rising edge to positive pulse1'
 * '<S195>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover/h latch'
 * '<S196>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover/lat lon latch'
 * '<S197>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover/yaw latch'
 * '<S198>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/hover/detect rising edge: transform rising edge to positive pulse1/detect positive values'
 * '<S199>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/pulse when entering Hover or RTH /Compare To Constant'
 * '<S200>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/pulse when entering Hover or RTH /Compare To Constant1'
 * '<S201>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/pulse when entering Hover or RTH /Compare To Constant2'
 * '<S202>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/pulse when entering Hover or RTH /Compare To Constant3'
 * '<S203>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant'
 * '<S204>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant1'
 * '<S205>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant4'
 * '<S206>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant5'
 * '<S207>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant6'
 * '<S208>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/reset slew rate limiter when enabling hover, RTH or waypoints/Compare To Constant7'
 * '<S209>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point/detect rising edge: transform rising edge to positive pulse1'
 * '<S210>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point/h latch'
 * '<S211>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point/lat lon latch'
 * '<S212>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point/yaw latch'
 * '<S213>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/take off point/detect rising edge: transform rising edge to positive pulse1/detect positive values'
 * '<S214>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/yaw ref vario generation/H vario'
 * '<S215>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/LLHY Reference Generator/yaw ref vario generation/detect ref change and reset vario'
 * '<S216>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/Compare To Constant'
 * '<S217>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/check request for next wayp'
 * '<S218>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/compute position error'
 * '<S219>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint'
 * '<S220>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/compute position error/geo2ned'
 * '<S221>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/compute position error/geo2ned1'
 * '<S222>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/compute position error/geo2ned/MATLAB Function6'
 * '<S223>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/compute position error/geo2ned1/MATLAB Function6'
 * '<S224>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/compute yaw, roll, pitch for wayp_guid'
 * '<S225>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/h latch'
 * '<S226>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/lat lon latch'
 * '<S227>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/pitch latch'
 * '<S228>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/roll latch'
 * '<S229>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/waypoint latch'
 * '<S230>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/yaw latch'
 * '<S231>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/compute yaw, roll, pitch for wayp_guid/MATLAB Function6'
 * '<S232>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/compute yaw, roll, pitch for wayp_guid/compute wayp bearing angle'
 * '<S233>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/compute yaw, roll, pitch for wayp_guid/compute wayp bearing angle/MATLAB Function6'
 * '<S234>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/Waypoint guidance ref/waypoint/waypoint latch/waypoint latch'
 * '<S235>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/detect first take off/Compare To Constant'
 * '<S236>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/detect first take off/Compare To Constant1'
 * '<S237>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/detect first take off/S-R Flip-Flop'
 * '<S238>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller'
 * '<S239>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID'
 * '<S240>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS'
 * '<S241>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID/PID altitude'
 * '<S242>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System'
 * '<S243>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/IO Delay'
 * '<S244>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/Input Delay'
 * '<S245>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Altitude PID/PID altitude/LTI System/Output Delay'
 * '<S246>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/MATLAB Function2'
 * '<S247>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Pitch'
 * '<S248>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Roll'
 * '<S249>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw'
 * '<S250>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System'
 * '<S251>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/IO Delay'
 * '<S252>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Input Delay'
 * '<S253>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Pitch/LTI System/Output Delay'
 * '<S254>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Roll/LTI System'
 * '<S255>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Roll/LTI System/IO Delay'
 * '<S256>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Roll/LTI System/Input Delay'
 * '<S257>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Roll/LTI System/Output Delay'
 * '<S258>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw/LTI System'
 * '<S259>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw/ensure that  -PI < y < PI'
 * '<S260>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw/LTI System/IO Delay'
 * '<S261>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw/LTI System/Input Delay'
 * '<S262>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/fuzzy guidance Controller/Attitude + Altitude Controller/Attitude PIDS/PID Yaw/LTI System/Output Delay'
 * '<S263>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/go back to hover when  waypoint list is empty (fuzzy guidance only : mode = 6)/Compare To Constant'
 * '<S264>' : 'ICARO3_HAL_v1/Controllers w// FUZZY/go back to hover when  waypoint list is empty (fuzzy guidance only : mode = 6)/Compare To Constant1'
 * '<S265>' : 'ICARO3_HAL_v1/GPS UBLOX/clock latch'
 * '<S266>' : 'ICARO3_HAL_v1/GPS receiver VENUS/compute 3d age'
 * '<S267>' : 'ICARO3_HAL_v1/GPS receiver VENUS/compute age'
 * '<S268>' : 'ICARO3_HAL_v1/GPS receiver VENUS/compute 3d age/Compare To Constant'
 * '<S269>' : 'ICARO3_HAL_v1/GPS receiver VENUS/compute 3d age/clock latch'
 * '<S270>' : 'ICARO3_HAL_v1/GPS receiver VENUS/compute age/clock latch'
 * '<S271>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input '
 * '<S272>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Compare To Constant'
 * '<S273>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Compare To Constant1'
 * '<S274>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Compare To Constant2'
 * '<S275>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Raw IMU data packer'
 * '<S276>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Subsystem4'
 * '<S277>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/WAYPOINT_MANAGER'
 * '<S278>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/recv from bs'
 * '<S279>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/step 2 pulse generate trigger  for take next waypoint'
 * '<S280>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/step 2 pulse generate trigger  to send gains to bs'
 * '<S281>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Compare To Constant1'
 * '<S282>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem'
 * '<S283>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem1'
 * '<S284>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem2'
 * '<S285>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem4'
 * '<S286>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem6'
 * '<S287>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /join enable flags'
 * '<S288>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/Assemble debug input /Subsystem6/Compare To Zero'
 * '<S289>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/WAYPOINT_MANAGER/Vehicle_DataBase_Manager'
 * '<S290>' : 'ICARO3_HAL_v1/MAIN TELEMETRY1/recv from bs/clock latch'
 * '<S291>' : 'ICARO3_HAL_v1/MK stick commands decoder1/ '
 * '<S292>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 0//1-value qualification'
 * '<S293>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 0//1-value qualification1'
 * '<S294>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 1-value qualification 1'
 * '<S295>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 1-value qualification 2'
 * '<S296>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 1-value qualification 3'
 * '<S297>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 1-value qualification 4'
 * '<S298>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 1-value qualification 5'
 * '<S299>' : 'ICARO3_HAL_v1/MK stick commands decoder1/MATLAB Function3'
 * '<S300>' : 'ICARO3_HAL_v1/MK stick commands decoder1/RC is ok '
 * '<S301>' : 'ICARO3_HAL_v1/MK stick commands decoder1/S-R Flip-Flop'
 * '<S302>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect ARM REQUEST'
 * '<S303>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DISARM REQUEST'
 * '<S304>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status'
 * '<S305>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect H'
 * '<S306>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect IMU selection'
 * '<S307>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 0//1-value qualification/S-R Flip-Flop'
 * '<S308>' : 'ICARO3_HAL_v1/MK stick commands decoder1/6 samples 0//1-value qualification1/S-R Flip-Flop'
 * '<S309>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect ARM REQUEST/throttle low'
 * '<S310>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect ARM REQUEST/throttle valid'
 * '<S311>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect ARM REQUEST/yaw RIGHT'
 * '<S312>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect ARM REQUEST/yaw valid'
 * '<S313>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DISARM REQUEST/throttle low'
 * '<S314>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DISARM REQUEST/throttle valid'
 * '<S315>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DISARM REQUEST/yaw LEFT'
 * '<S316>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DISARM REQUEST/yaw valid'
 * '<S317>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status/HOVER'
 * '<S318>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status/MAN'
 * '<S319>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status/RTH'
 * '<S320>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status/RTH1'
 * '<S321>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect DP status/throttle valid'
 * '<S322>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect H/h control valid'
 * '<S323>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect H/throttle low2'
 * '<S324>' : 'ICARO3_HAL_v1/MK stick commands decoder1/detect IMU selection/posizione 1'
 * '<S325>' : 'ICARO3_HAL_v1/MODE manager1/MATLAB Function'
 * '<S326>' : 'ICARO3_HAL_v1/MODE manager1/detect valid 3d fix'
 * '<S327>' : 'ICARO3_HAL_v1/MODE manager1/store ref system'
 * '<S328>' : 'ICARO3_HAL_v1/MODE manager1/detect valid 3d fix/Compare To Constant'
 * '<S329>' : 'ICARO3_HAL_v1/MODE manager1/detect valid 3d fix/Compare To Constant1'
 * '<S330>' : 'ICARO3_HAL_v1/MODE manager1/detect valid 3d fix/S-R Flip-Flop'
 * '<S331>' : 'ICARO3_HAL_v1/MODE manager1/store ref system/MATLAB Function1'
 * '<S332>' : 'ICARO3_HAL_v1/MPU AHRS/Attitude Filter MPU'
 * '<S333>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU'
 * '<S334>' : 'ICARO3_HAL_v1/MPU AHRS/Attitude Filter MPU/DCM_MARG_QUAT'
 * '<S335>' : 'ICARO3_HAL_v1/MPU AHRS/Attitude Filter MPU/DCM_MARG_QUAT/dcm_marg'
 * '<S336>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend '
 * '<S337>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend'
 * '<S338>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend'
 * '<S339>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend1'
 * '<S340>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend3'
 * '<S341>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend/Subsystem'
 * '<S342>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend1/Subsystem'
 * '<S343>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Acceleration Detrend /Detrend3/Subsystem'
 * '<S344>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend'
 * '<S345>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend1'
 * '<S346>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend2'
 * '<S347>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend/Subsystem'
 * '<S348>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend1/Subsystem'
 * '<S349>' : 'ICARO3_HAL_v1/MPU AHRS/debias MPU/Gyros Detrend/Detrend2/Subsystem'
 * '<S350>' : 'ICARO3_HAL_v1/NUOVO1/Processing'
 * '<S351>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager'
 * '<S352>' : 'ICARO3_HAL_v1/NUOVO1/motors_cmd on PWM'
 * '<S353>' : 'ICARO3_HAL_v1/NUOVO1/Processing/ChangeAsset2'
 * '<S354>' : 'ICARO3_HAL_v1/NUOVO1/Processing/ChangeAsset3'
 * '<S355>' : 'ICARO3_HAL_v1/NUOVO1/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S356>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function'
 * '<S357>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute accxyz'
 * '<S358>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute accxyz1'
 * '<S359>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute gyroxyz'
 * '<S360>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute magxyz'
 * '<S361>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute magxyz1'
 * '<S362>' : 'ICARO3_HAL_v1/NUOVO1/Processing/MATLAB Function compute magxyz2'
 * '<S363>' : 'ICARO3_HAL_v1/NUOVO1/Processing/compute_parameters'
 * '<S364>' : 'ICARO3_HAL_v1/NUOVO1/Processing/spi_data_processing'
 * '<S365>' : 'ICARO3_HAL_v1/NUOVO1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S366>' : 'ICARO3_HAL_v1/NUOVO1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S367>' : 'ICARO3_HAL_v1/NUOVO1/Processing/compute_parameters/MATLAB Function1'
 * '<S368>' : 'ICARO3_HAL_v1/NUOVO1/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S369>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/Arrange pwms'
 * '<S370>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX'
 * '<S371>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/I2C1 sensors loop'
 * '<S372>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/Subsystem1'
 * '<S373>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/Subsystem2'
 * '<S374>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/compose data from canbus'
 * '<S375>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus'
 * '<S376>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/Arrange pwms/clock latch'
 * '<S377>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem1'
 * '<S378>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem2'
 * '<S379>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem3'
 * '<S380>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S381>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S382>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S383>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S384>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S385>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S386>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S387>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S388>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S389>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S390>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/compose data from canbus/H'
 * '<S391>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S392>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S393>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S394>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Repeating Sequence Stair'
 * '<S395>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S396>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S397>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S398>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S399>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S400>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S401>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S402>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S403>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S404>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S405>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter'
 * '<S406>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S407>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S408>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S409>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S410>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S411>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S412>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S413>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S414>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S415>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S416>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S417>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S418>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S419>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S420>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S421>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S422>' : 'ICARO3_HAL_v1/NUOVO1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 * '<S423>' : 'ICARO3_HAL_v1/NUOVO1/motors_cmd on PWM/MATLAB Function'
 * '<S424>' : 'ICARO3_HAL_v1/NUOVO1/motors_cmd on PWM/calibrate SIMONK ESC'
 * '<S425>' : 'ICARO3_HAL_v1/NUOVO1/motors_cmd on PWM/calibrate SIMONK ESC/discrete time RAMP'
 * '<S426>' : 'ICARO3_HAL_v1/SS AHRS/Attitude Filter SS'
 * '<S427>' : 'ICARO3_HAL_v1/SS AHRS/debias SS'
 * '<S428>' : 'ICARO3_HAL_v1/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT'
 * '<S429>' : 'ICARO3_HAL_v1/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT/dcm_marg'
 * '<S430>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend '
 * '<S431>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend'
 * '<S432>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend'
 * '<S433>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend1'
 * '<S434>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend3'
 * '<S435>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend/Subsystem'
 * '<S436>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S437>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S438>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend'
 * '<S439>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend1'
 * '<S440>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend2'
 * '<S441>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend/Subsystem'
 * '<S442>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend1/Subsystem'
 * '<S443>' : 'ICARO3_HAL_v1/SS AHRS/debias SS/Gyros Detrend/Detrend2/Subsystem'
 * '<S444>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/ADC_filt'
 * '<S445>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/ADC_raw'
 * '<S446>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/Ages'
 * '<S447>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/Compare To Constant'
 * '<S448>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/GPS'
 * '<S449>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/GPS ECEF'
 * '<S450>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/MATLAB Function2'
 * '<S451>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S452>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/Raw IMU data MPU + HMC + ADC'
 * '<S453>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/Raw IMU data MPU only + ADC'
 * '<S454>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/Raw IMU data packer'
 * '<S455>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/join enable flags'
 * '<S456>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/muxer'
 * '<S457>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/recupero di mpu9150 data'
 * '<S458>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/test solo RC_all_channel_usec + RSSI + ....'
 * '<S459>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/GPS/detect if was 1 in the last 10 samples'
 * '<S460>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/muxer/LimitedCounter'
 * '<S461>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/muxer/LimitedCounter/Increment Real World'
 * '<S462>' : 'ICARO3_HAL_v1/debug telemtry FLIGHT TEST/muxer/LimitedCounter/Wrap To Zero'
 * '<S463>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/Raw IMU data packer: MPU + MAG_HMC'
 * '<S464>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/Subsystem'
 * '<S465>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/join enable flags'
 * '<S466>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/muxer'
 * '<S467>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/muxer/LimitedCounter'
 * '<S468>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/muxer/LimitedCounter/Increment Real World'
 * '<S469>' : 'ICARO3_HAL_v1/debug telemtry STATIC TEST/muxer/LimitedCounter/Wrap To Zero'
 * '<S470>' : 'ICARO3_HAL_v1/flashing LED notifier slow: filters debiasing fast: filter running/LED'
 * '<S471>' : 'ICARO3_HAL_v1/power computations1/low pass filter'
 * '<S472>' : 'ICARO3_HAL_v1/power computations1/low pass filter1'
 * '<S473>' : 'ICARO3_HAL_v1/power computations1/low pass filter/IO Delay'
 * '<S474>' : 'ICARO3_HAL_v1/power computations1/low pass filter/Input Delay'
 * '<S475>' : 'ICARO3_HAL_v1/power computations1/low pass filter/Output Delay'
 * '<S476>' : 'ICARO3_HAL_v1/power computations1/low pass filter1/IO Delay'
 * '<S477>' : 'ICARO3_HAL_v1/power computations1/low pass filter1/Input Delay'
 * '<S478>' : 'ICARO3_HAL_v1/power computations1/low pass filter1/Output Delay'
 * '<S479>' : 'ICARO3_HAL_v1/quadrotor  control allocation1/Saturation Dynamic'
 * '<S480>' : 'ICARO3_HAL_v1/quadrotor  control allocation1/low_sat'
 * '<S481>' : 'ICARO3_HAL_v1/quadrotor  control allocation1/new re-allocation matrix (X flight_mode)'
 * '<S482>' : 'ICARO3_HAL_v1/quadrotor  control allocation1/reallocate (+ flight_mode)'
 * '<S483>' : 'ICARO3_HAL_v1/set initial altitude to 1/Altitude Detrend '
 * '<S484>' : 'ICARO3_HAL_v1/set initial altitude to 1/Altitude Detrend /Detrend'
 * '<S485>' : 'ICARO3_HAL_v1/set initial altitude to 1/Altitude Detrend /Detrend/Subsystem'
 */
#endif                                 /* RTW_HEADER_ICARO3_HAL_v1_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_HAL_v1.h
 */
