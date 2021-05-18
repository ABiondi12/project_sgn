/*
 * File: ICARO3_Onda_simple_v2.h
 *
 * Code generated for Simulink model :ICARO3_Onda_simple_v2.
 *
 * Model version      : 1.1500
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Dec 10 12:06:46 2019
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

#ifndef RTW_HEADER_ICARO3_Onda_simple_v2_h_
#define RTW_HEADER_ICARO3_Onda_simple_v2_h_
#include <math.h>
#include <string.h>
#include "ICARO3_Onda_simple_v2_STM32.h"
#ifndef ICARO3_Onda_simple_v2_COMMON_INCLUDES_
# define ICARO3_Onda_simple_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ICARO3_Onda_simple_v2_COMMON_INCLUDES_ */

#include "ICARO3_Onda_simple_v2_types.h"
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

/* Block signals for system '<S115>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S118>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S118>/Discrete-Time Integrator1' */
  real_T Product1;                     /* '<S118>/Product1' */
} rtB_Subsystem_ICARO3_Onda_simple_v2;

/* Block states (auto storage) for system '<S115>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S118>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S118>/Discrete-Time Integrator1' */
} rtDW_Subsystem_ICARO3_Onda_simple_v2;

/* Block signals for system '<Root>/Compensate for sensor mount _acc' */
typedef struct {
  real_T y[3];                         /* '<Root>/Compensate for sensor mount _acc' */
} rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2;

/* Block signals for system '<S239>/clock latch' */
typedef struct {
  real_T In;                           /* '<S254>/In' */
} rtB_clocklatch_ICARO3_Onda_simple_v2;

/* Block signals for system '<S308>/Compensate for sensor mount _acc' */
typedef struct {
  real32_T y[3];                       /* '<S308>/Compensate for sensor mount _acc' */
} rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_f;

/* Block signals for system '<S333>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint16_T y;                          /* '<S333>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2;

/* Block signals for system '<S334>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint32_T y;                          /* '<S334>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_f;

/* Block signals for system '<S353>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint8_T y[2];                        /* '<S353>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j;

/* Block signals for system '<S353>/MATLAB Function compute gyroxyz4' */
typedef struct {
  uint8_T TmpSignalConversionAtSFunctionInport1[8];/* '<S353>/MATLAB Function compute gyroxyz4' */
  uint8_T y[8];                        /* '<S353>/MATLAB Function compute gyroxyz4' */
} rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2;

/* Block signals (auto storage) */
typedef struct {
  real_T Step;                         /* '<S108>/Step' */
  real_T Step1;                        /* '<S108>/Step1' */
  real_T Add;                          /* '<S108>/Add' */
  real_T DataTypeConversion7[3];       /* '<S308>/Data Type Conversion7' */
  real_T Switch2;                      /* '<S114>/Switch2' */
  real_T Switch2_p;                    /* '<S115>/Switch2' */
  real_T Switch2_d;                    /* '<S116>/Switch2' */
  real_T DataTypeConversion9[3];       /* '<S308>/Data Type Conversion9' */
  real_T Gain8[3];                     /* '<Root>/Gain8' */
  real_T Switch2_o;                    /* '<S120>/Switch2' */
  real_T Switch2_pz;                   /* '<S121>/Switch2' */
  real_T Switch2_n;                    /* '<S122>/Switch2' */
  real_T DataTypeConversionmx10[3];    /* '<S4>/Data Type Conversion mx10' */
  real_T RateTransition54;             /* '<Root>/Rate Transition54' */
  real_T DataTypeConversionmx17[3];    /* '<S4>/Data Type Conversion mx17' */
  real_T RateTransition55[3];          /* '<Root>/Rate Transition55' */
  real_T SFunctionUSART3_Receive4_o1[16];/* '<Root>/S-Function-USART3_Receive4' */
  real_T SFunctionUSART3_Receive4_o2;  /* '<Root>/S-Function-USART3_Receive4' */
  real_T RateTransition52[3];          /* '<Root>/Rate Transition52' */
  real_T RateTransition53[3];          /* '<Root>/Rate Transition53' */
  real_T RateTransition47;             /* '<Root>/Rate Transition47' */
  real_T RateTransition48;             /* '<Root>/Rate Transition48' */
  real_T TmpSignalConversionAtreproducePWM9Inport1[4];
  real_T RateTransition46;             /* '<Root>/Rate Transition46' */
  real_T DataTypeConversion1[2];       /* '<S11>/Data Type Conversion1' */
  real_T DataTypeConversion2[2];       /* '<S11>/Data Type Conversion2' */
  real_T relativevector[2];            /* '<S11>/Sum2' */
  real_T angle_error;                  /* '<S11>/Sum3' */
  real_T DataTypeConversion3;          /* '<S11>/Data Type Conversion3' */
  real_T Memory1;                      /* '<S151>/Memory1' */
  real_T Gain1;                        /* '<S151>/Gain1' */
  real_T Switch1;                      /* '<S151>/Switch1' */
  real_T Saturation1;                  /* '<S151>/Saturation1' */
  real_T Sum1;                         /* '<S151>/Sum1' */
  real_T Switch1_p;                    /* '<S150>/Switch1' */
  real_T Saturation;                   /* '<S150>/Saturation' */
  real_T Sum1_a;                       /* '<S150>/Sum1' */
  real_T DataTypeConversion16;         /* '<Root>/Data Type Conversion16' */
  real_T DataTypeConversion19;         /* '<Root>/Data Type Conversion19' */
  real_T DataTypeConversion3_a[3];     /* '<S308>/Data Type Conversion3' */
  real_T downsampleto100Hz3[4];        /* '<S309>/downsample to 100 Hz3' */
  real_T Gain;                         /* '<S329>/Gain' */
  real_T Sum;                          /* '<S329>/Sum' */
  real_T DigitalClock;                 /* '<S238>/Digital Clock' */
  real_T SFunction3_o1[7];             /* '<S236>/S-Function3' */
  real_T SFunction3_o2;                /* '<S236>/S-Function3' */
  real_T gpsselector2;                 /* '<S16>/gps selector 2' */
  real_T Product2;                     /* '<S243>/Product2' */
  real_T Product3;                     /* '<S243>/Product3' */
  real_T Sum2;                         /* '<S243>/Sum2' */
  real_T sqrt_p;                       /* '<S243>/sqrt' */
  real_T Sum1_n;                       /* '<S247>/Sum1' */
  real_T Product1;                     /* '<S240>/Product1' */
  real_T Product2_k;                   /* '<S248>/Product2' */
  real_T Sum1_b;                       /* '<S248>/Sum1' */
  real_T Sum1_d;                       /* '<S246>/Sum1' */
  real_T Product2_a;                   /* '<S246>/Product2' */
  real_T TrigonometricFunction2;       /* '<S240>/Trigonometric Function2' */
  real_T UnitConversion[2];            /* '<S242>/Unit Conversion' */
  real_T sincos_o1;                    /* '<S244>/sincos' */
  real_T sincos_o2;                    /* '<S244>/sincos' */
  real_T Product2_o;                   /* '<S244>/Product2' */
  real_T Product1_h;                   /* '<S244>/Product1' */
  real_T Sum_b;                        /* '<S244>/Sum' */
  real_T sqrt_i;                       /* '<S244>/sqrt' */
  real_T Product3_l;                   /* '<S244>/Product3' */
  real_T Product4;                     /* '<S244>/Product4' */
  real_T Sum2_k;                       /* '<S244>/Sum2' */
  real_T Product5;                     /* '<S244>/Product5' */
  real_T Product6;                     /* '<S244>/Product6' */
  real_T Sum3;                         /* '<S244>/Sum3' */
  real_T gpsselector1[16];             /* '<S16>/gps selector 1' */
  real_T Product;                      /* '<S16>/Product' */
  real_T Sum_f;                        /* '<S238>/Sum' */
  real_T Gain_g;                       /* '<S328>/Gain' */
  real_T Sum_e;                        /* '<S328>/Sum' */
  real_T DigitalClock_k;               /* '<Root>/Digital Clock' */
  real_T DigitalClock_p;               /* '<S239>/Digital Clock' */
  real_T scalefactor[2];               /* '<Root>/scale factor' */
  real_T PulseGenerator1;              /* '<S38>/Pulse Generator1' */
  real_T PulseGenerator;               /* '<S331>/Pulse Generator' */
  real_T Output;                       /* '<S350>/Output' */
  real_T Gain_m;                       /* '<S351>/Gain' */
  real_T Sum_i;                        /* '<S351>/Sum' */
  real_T Gain_k[3];                    /* '<S352>/Gain' */
  real_T Sum_c[3];                     /* '<S352>/Sum' */
  real_T TmpSignalConversionAtSFunctionInport1[12];/* '<S308>/MATLAB Function compute magxyz2' */
  real_T RC_TRPY_refs[4];              /* '<S308>/MATLAB Function compute magxyz2' */
  real_T RC_aux_channels[8];           /* '<S308>/MATLAB Function compute magxyz2' */
  real_T h_calib[3];                   /* '<S308>/MATLAB Function' */
  real_T y[4];                         /* '<Root>/data conversion' */
  real_T In;                           /* '<S253>/In' */
  real_T y_i;                          /* '<S236>/MAP ublox fix type to standard status' */
  real_T Memory;                       /* '<S251>/Memory' */
  real_T Switch;                       /* '<S251>/Switch' */
  real_T sincos_o1_c;                  /* '<S249>/sincos' */
  real_T sincos_o2_e;                  /* '<S249>/sincos' */
  real_T Product3_m;                   /* '<S249>/Product3' */
  real_T Sum2_c;                       /* '<S249>/Sum2' */
  real_T Product4_e;                   /* '<S249>/Product4' */
  real_T Sum1_j;                       /* '<S249>/Sum1' */
  real_T TrigonometricFunction4;       /* '<S249>/Trigonometric Function4' */
  real_T sincos_o1_b;                  /* '<S250>/sincos' */
  real_T sincos_o2_l;                  /* '<S250>/sincos' */
  real_T Product3_o;                   /* '<S250>/Product3' */
  real_T TrigonometricFunction4_o;     /* '<S250>/Trigonometric Function4' */
  real_T Product2_k2;                  /* '<S251>/Product2' */
  real_T TrigonometricFunction3;       /* '<S251>/Trigonometric Function3' */
  real_T control;                      /* '<S151>/MATLAB Function' */
  real_T go;                           /* '<S151>/Control Manager' */
  real_T go_i;                         /* '<S150>/Control Manager' */
  real_T Gain1_m;                      /* '<S150>/Gain1' */
  real_T theta;                        /* '<S11>/atan2' */
  real_T y_o;                          /* '<S11>/VectorNorm' */
  real_T theta_out;                    /* '<S11>/+pi-pi_remapping' */
  real_T Sum1_k;                       /* '<S122>/Sum1' */
  real_T Sum1_f;                       /* '<S121>/Sum1' */
  real_T DiscreteTimeIntegrator;       /* '<S123>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S123>/Discrete-Time Integrator1' */
  real_T Product1_d;                   /* '<S123>/Product1' */
  real_T Sum1_km;                      /* '<S120>/Sum1' */
  real_T Sum1_d4;                      /* '<S116>/Sum1' */
  real_T Sum1_g;                       /* '<S115>/Sum1' */
  real_T DiscreteTimeIntegrator_p;     /* '<S117>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_p;    /* '<S117>/Discrete-Time Integrator1' */
  real_T Product1_f;                   /* '<S117>/Product1' */
  real_T Sum1_dm;                      /* '<S114>/Sum1' */
  real32_T DataTypeConversionmx8;      /* '<S108>/Data Type Conversion mx8' */
  real32_T DataTypeConversionmx1[3];   /* '<S4>/Data Type Conversion mx1' */
  real32_T RateTransition49[3];        /* '<Root>/Rate Transition49' */
  real32_T DataTypeConversionmx2[3];   /* '<S4>/Data Type Conversion mx2' */
  real32_T DataTypeConversion21;       /* '<Root>/Data Type Conversion21' */
  real32_T DataTypeConversion24[3];    /* '<Root>/Data Type Conversion24' */
  real32_T RateTransition56[3];        /* '<Root>/Rate Transition56' */
  real32_T DataTypeConversion18[16];   /* '<Root>/Data Type Conversion18' */
  real32_T RateTransition51[3];        /* '<Root>/Rate Transition51' */
  real32_T RateTransition50[3];        /* '<Root>/Rate Transition50' */
  real32_T DataTypeConversion23;       /* '<Root>/Data Type Conversion23' */
  real32_T DataTypeConversion26[3];    /* '<Root>/Data Type Conversion26' */
  real32_T DataTypeConversion27[3];    /* '<Root>/Data Type Conversion27' */
  real32_T TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1[20];
  real32_T DataTypeConversion4;        /* '<S11>/Data Type Conversion4' */
  real32_T DataTypeConversion5;        /* '<S11>/Data Type Conversion5' */
  real32_T headingdirection[3];        /* '<Root>/Sum12' */
  real32_T DataTypeConversionmx3;      /* '<S64>/Data Type Conversion mx3' */
  real32_T RateTransition2[11];        /* '<S308>/Rate Transition2' */
  real32_T y_g;                        /* '<S330>/typecast uin32 to single1' */
  real32_T y_b;                        /* '<S330>/typecast uin32 to single' */
  real32_T y_b1;                       /* '<S346>/typecast uin32 to single' */
  real32_T a[3];                       /* '<S320>/MATLAB Function compute magxyz1' */
  real32_T w[3];                       /* '<S320>/MATLAB Function compute magxyz1' */
  real32_T params[11];                 /* '<S319>/MATLAB Function1' */
  real32_T m[3];                       /* '<S308>/MATLAB Function compute magxyz' */
  real32_T w_j[3];                     /* '<S308>/MATLAB Function compute gyroxyz' */
  real32_T a_g[3];                     /* '<S308>/MATLAB Function compute accxyz1' */
  real32_T t;                          /* '<S308>/MATLAB Function compute accxyz1' */
  real32_T g[3];                       /* '<S308>/MATLAB Function compute accxyz1' */
  real32_T a_j[3];                     /* '<S308>/MATLAB Function compute accxyz' */
  real32_T DataTypeConversion1_i;      /* '<S312>/Data Type Conversion1' */
  real32_T DataTypeConversion3_g;      /* '<S312>/Data Type Conversion3' */
  real32_T T;                          /* '<S312>/MATLAB Function' */
  real32_T h;                          /* '<S312>/MATLAB Function' */
  real32_T UnitDelay1[4];              /* '<S110>/Unit Delay1' */
  real32_T UnitDelay2[3];              /* '<S110>/Unit Delay2' */
  real32_T UnitDelay3[3];              /* '<S110>/Unit Delay3' */
  real32_T Sum_h[3];                   /* '<S107>/Sum' */
  real32_T euler_out[3];               /* '<S110>/dcm_marg' */
  real32_T a_ned[3];                   /* '<S110>/dcm_marg' */
  real32_T q_out[4];                   /* '<S110>/dcm_marg' */
  real32_T e_int_out_a[3];             /* '<S110>/dcm_marg' */
  real32_T e_int_out_m[3];             /* '<S110>/dcm_marg' */
  real32_T biases[3];                  /* '<S110>/dcm_marg' */
  real32_T e_m[3];                     /* '<S110>/dcm_marg' */
  uint32_T PWM1[4];                    /* '<S2>/PWM1' */
  uint32_T DataTypeConversion8;        /* '<S346>/Data Type Conversion8' */
  uint32_T u;                          /* '<S346>/ ' */
  uint32_T DataTypeConversion9_d;      /* '<S346>/Data Type Conversion9' */
  uint32_T u_o;                        /* '<S346>/  ' */
  uint32_T DataTypeConversion7_c;      /* '<S346>/Data Type Conversion7' */
  uint32_T u_i;                        /* '<S346>/  2' */
  uint32_T DataTypeConversion10;       /* '<S346>/Data Type Conversion10' */
  uint32_T Sum12;                      /* '<S346>/Sum12' */
  uint32_T RateTransition18[2];        /* '<S330>/Rate Transition18' */
  uint32_T DataTypeConversiononi2cmag1[8];/* '<S334>/Data Type Conversion on i2c mag1' */
  uint32_T DataTypeConversion5_l[3];   /* '<S312>/Data Type Conversion5' */
  uint32_T UP;                         /* '<S312>/MATLAB Function1' */
  uint16_T I2C1SensorsLoop_o2;         /* '<S327>/I2C1 Sensors Loop' */
  uint16_T DataTypeConversiononi2cmag3[14];/* '<S308>/Data Type Conversion on i2c mag3' */
  uint16_T DataTypeConversion[22];     /* '<S319>/Data Type Conversion' */
  uint16_T DataTypeConversiononi2cmag[6];/* '<S308>/Data Type Conversion on i2c mag' */
  uint16_T DataTypeConversiononi2cmag1_c[6];/* '<S308>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag2[6];/* '<S308>/Data Type Conversion on i2c mag2' */
  uint16_T RateTransition18_g[7];      /* '<S308>/Rate Transition18' */
  uint16_T BitwiseOperator1;           /* '<S320>/Bitwise Operator1' */
  uint16_T BitwiseOperator2;           /* '<S320>/Bitwise Operator2' */
  uint16_T BitwiseOperator3;           /* '<S320>/Bitwise Operator3' */
  uint16_T BitwiseOperator4;           /* '<S320>/Bitwise Operator4' */
  uint16_T BitwiseOperator5;           /* '<S320>/Bitwise Operator5' */
  uint16_T BitwiseOperator6;           /* '<S320>/Bitwise Operator6' */
  uint16_T DataTypeConversion1_k;      /* '<S309>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_k;      /* '<S329>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_c;      /* '<S328>/Data Type Conversion2' */
  uint16_T capturePWMprova_o1[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T capturePWMprova_o2[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T capturePWMprova_o3[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T DataTypeConversion1_d;      /* '<S331>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_cg;     /* '<S331>/Data Type Conversion2' */
  uint16_T DataTypeConversion3_n[4];   /* '<S331>/Data Type Conversion3' */
  uint16_T IndexVector[3];             /* '<S331>/Index Vector' */
  uint16_T Switch_o[3];                /* '<S331>/Switch' */
  uint16_T DataTypeConversion2_g;      /* '<S351>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_i[3];   /* '<S352>/Data Type Conversion2' */
  uint16_T DataTypeConversiononi2cmag1_j[8];/* '<S333>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag1_a[8];/* '<S335>/Data Type Conversion on i2c mag1' */
  uint16_T TmpSignalConversionAtSFunctionInport1_h[6];/* '<S320>/MATLAB Function compute magxyz1' */
  uint16_T DataTypeConversion4_f[2];   /* '<S312>/Data Type Conversion4' */
  uint16_T UT;                         /* '<S312>/MATLAB Function1' */
  int8_T WhileIterator;                /* '<S245>/While Iterator' */
  uint8_T I2C1SensorsLoop_o1[71];      /* '<S327>/I2C1 Sensors Loop' */
  uint8_T Switch4[6];                  /* '<S309>/Switch4' */
  uint8_T RateTransition10;            /* '<S64>/Rate Transition10' */
  uint8_T RateTransition6[2];          /* '<S308>/Rate Transition6' */
  uint8_T RateTransition5[3];          /* '<S308>/Rate Transition5' */
  uint8_T RateTransition1;             /* '<S308>/Rate Transition1' */
  uint8_T RateTransition[8];           /* '<S330>/Rate Transition' */
  uint8_T Switch_n[6];                 /* '<S309>/Switch' */
  uint8_T RateTransition14[8];         /* '<S330>/Rate Transition14' */
  uint8_T Switch1_k[6];                /* '<S309>/Switch1' */
  uint8_T RateTransition15[8];         /* '<S330>/Rate Transition15' */
  uint8_T Switch2_i[6];                /* '<S309>/Switch2' */
  uint8_T capturePWMprova_o4[2];       /* '<Root>/capture PWM (prova)' */
  uint8_T Output_e;                    /* '<S361>/Output' */
  uint8_T FixPtSum1;                   /* '<S362>/FixPt Sum1' */
  uint8_T FixPtSwitch;                 /* '<S363>/FixPt Switch' */
  uint8_T CANRX_o1[48];                /* '<S326>/CANRX' */
  uint8_T CANRX_o2;                    /* '<S326>/CANRX' */
  boolean_T Compare;                   /* '<S252>/Compare' */
  boolean_T LogicalOperator;           /* '<S309>/Logical Operator' */
  boolean_T RateTransition14_p;        /* '<S309>/Rate Transition14' */
  boolean_T RelationalOperator;        /* '<S245>/Relational Operator' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz5_p;/* '<S360>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz4_f;/* '<S360>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz3_ph;/* '<S360>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz2_i;/* '<S360>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz1_g;/* '<S360>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz5_k;/* '<S359>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz4_j;/* '<S359>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz3_p;/* '<S359>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz2_l;/* '<S359>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz1_i;/* '<S359>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz5_b;/* '<S353>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz4;  /* '<S353>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz3_b;/* '<S353>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz2_g;/* '<S353>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_j
    sf_MATLABFunctioncomputegyroxyz1_b;/* '<S353>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz5_d;/* '<S335>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz3_a;/* '<S335>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz2_h;/* '<S335>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz1_e;/* '<S335>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_f
    sf_MATLABFunctioncomputegyroxyz5_i;/* '<S334>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_f
    sf_MATLABFunctioncomputegyroxyz1_k;/* '<S334>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz5;  /* '<S333>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz3;  /* '<S333>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz2;  /* '<S333>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2
    sf_MATLABFunctioncomputegyroxyz1;  /* '<S333>/MATLAB Function compute gyroxyz1' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_f
    sf_Compensateforsensormount_gyro;  /* '<S308>/Compensate for sensor mount _gyro' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_f
    sf_Compensateforsensormount_acc;   /* '<S308>/Compensate for sensor mount _acc' */
  rtB_clocklatch_ICARO3_Onda_simple_v2 clocklatch_h;/* '<Root>/clock latch' */
  rtB_clocklatch_ICARO3_Onda_simple_v2 clocklatch_m;/* '<S239>/clock latch' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2
    sf_Compensateforsensormount_acc1;  /* '<Root>/Compensate for sensor mount _acc1' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2
    sf_Compensateforsensormount_acc_h; /* '<Root>/Compensate for sensor mount _acc' */
  rtB_Subsystem_ICARO3_Onda_simple_v2 Subsystem_o;/* '<S122>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2 Subsystem_l;/* '<S121>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2 Subsystem_p;/* '<S116>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2 Subsystem_g;/* '<S115>/Subsystem' */
} BlockIO_ICARO3_Onda_simple_v2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S123>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S123>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S117>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S117>/Discrete-Time Integrator1' */
  real_T RateTransition47_Buffer0;     /* '<Root>/Rate Transition47' */
  real_T RateTransition48_Buffer0;     /* '<Root>/Rate Transition48' */
  real_T Memory1_PreviousInput;        /* '<S151>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S251>/Memory' */
  real32_T UnitDelay1_DSTATE[4];       /* '<S110>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE[3];       /* '<S110>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[3];       /* '<S110>/Unit Delay3' */
  real32_T RateTransition49_Buffer0[3];/* '<Root>/Rate Transition49' */
  real32_T RateTransition2_Buffer0[11];/* '<S308>/Rate Transition2' */
  int32_T clockTickCounter;            /* '<S38>/Pulse Generator1' */
  int32_T clockTickCounter_f;          /* '<S331>/Pulse Generator' */
  uint32_T RateTransition18_Buffer[4]; /* '<S330>/Rate Transition18' */
  uint16_T RateTransition18_Buffer0[7];/* '<S308>/Rate Transition18' */
  uint8_T Output_DSTATE;               /* '<S361>/Output' */
  int8_T RateTransition6_semaphoreTaken;/* '<S308>/Rate Transition6' */
  int8_T RateTransition5_semaphoreTaken;/* '<S308>/Rate Transition5' */
  int8_T RateTransition2_semaphoreTaken;/* '<S308>/Rate Transition2' */
  int8_T RateTransition_ActiveBufIdx;  /* '<S330>/Rate Transition' */
  int8_T RateTransition14_ActiveBufIdx;/* '<S330>/Rate Transition14' */
  int8_T RateTransition15_ActiveBufIdx;/* '<S330>/Rate Transition15' */
  int8_T RateTransition18_semaphoreTaken;/* '<S308>/Rate Transition18' */
  int8_T RateTransition18_ActiveBufIdx;/* '<S330>/Rate Transition18' */
  uint8_T RateTransition6_Buffer0[2];  /* '<S308>/Rate Transition6' */
  uint8_T RateTransition5_Buffer0[3];  /* '<S308>/Rate Transition5' */
  uint8_T RateTransition_Buffer[16];   /* '<S330>/Rate Transition' */
  uint8_T RateTransition14_Buffer[16]; /* '<S330>/Rate Transition14' */
  uint8_T RateTransition15_Buffer[16]; /* '<S330>/Rate Transition15' */
  boolean_T ini_not_empty;             /* '<S110>/dcm_marg' */
  boolean_T AttitudeFilterADIS_MODE;   /* '<S4>/Attitude Filter ADIS' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2 Subsystem_o;/* '<S122>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2 Subsystem_l;/* '<S121>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2 Subsystem_p;/* '<S116>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2 Subsystem_g;/* '<S115>/Subsystem' */
} D_Work_ICARO3_Onda_simple_v2;

/* Parameters for system: '<S115>/Subsystem' */
struct rtP_Subsystem_ICARO3_Onda_simple_v2_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S118>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S118>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S118>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S118>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S118>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S239>/clock latch' */
struct rtP_clocklatch_ICARO3_Onda_simple_v2_ {
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S254>/Out'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ICARO3_Onda_simple_v2_ {
  real_T CAL_PARAM[9];                 /* Variable: CAL_PARAM
                                        * Referenced by: '<S308>/MATLAB Function'
                                        */
  real_T INV_PITCH_RANGE;              /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_ROLL_RANGE;               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_THROTTLE_RANGE;           /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_YAW_RANGE;                /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_IDX;                    /* Variable: PITCH_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_MID;                    /* Variable: PITCH_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_IDX;                     /* Variable: ROLL_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_MID;                     /* Variable: ROLL_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_DOWN;                /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_IDX;                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_LOW_THRES;           /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_IDX;                      /* Variable: YAW_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_MID;                      /* Variable: YAW_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  real32_T ST;                         /* Variable: ST
                                        * Referenced by: '<S110>/dcm_marg'
                                        */
  real_T RepeatingSequenceStair_OutValues[12];/* Mask Parameter: RepeatingSequenceStair_OutValues
                                               * Referenced by: '<S350>/Vector'
                                               */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S252>/Constant'
                                        */
  real32_T DCM_MARG_QUAT_Ki;           /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S110>/dcm_marg'
                                        */
  real32_T DCM_MARG_QUAT_Kp;           /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S110>/dcm_marg'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator3_BitMask;   /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator3'
                                        */
  uint16_T BitwiseOperator4_BitMask;   /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator4'
                                        */
  uint16_T BitwiseOperator5_BitMask;   /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator5'
                                        */
  uint16_T BitwiseOperator6_BitMask;   /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator6'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S363>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S114>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S117>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S117>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S117>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S117>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 9.81
                                        * Referenced by: '<S116>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S120>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S123>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_b;/* Computed Parameter: DiscreteTimeIntegrator_gainval_b
                                           * Referenced by: '<S123>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S123>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                            * Referenced by: '<S123>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_i; /* Expression: eps
                                        * Referenced by: '<S123>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S121>/Constant1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S122>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S150>/Gain1'
                                        */
  real_T phi_Y0;                       /* Expression: 0
                                        * Referenced by: '<S245>/phi'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S251>/Memory'
                                        */
  real_T Constant1_Value_oo;           /* Expression: R
                                        * Referenced by: '<S249>/Constant1'
                                        */
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S253>/Out'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S352>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S352>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S351>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 180
                                        * Referenced by: '<S351>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S331>/Switch'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S108>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S108>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S108>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 11
                                        * Referenced by: '<S108>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S108>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S108>/Step1'
                                        */
  real_T I2C1SensorsLoop_P1;           /* Expression: ST
                                        * Referenced by: '<S327>/I2C1 Sensors Loop'
                                        */
  real_T HW0SIM_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch4'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T Constant34_Value;             /* Expression: 17
                                        * Referenced by: '<Root>/Constant34'
                                        */
  real_T SavedatatodataloggerthemicroSDcard2_P1;/* Expression: 0.1
                                                 * Referenced by: '<Root>/Save data to data logger (the micro SD card)2'
                                                 */
  real_T RateTransition47_X0;          /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition47'
                                        */
  real_T RateTransition48_X0;          /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition48'
                                        */
  real_T Constant33_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant33'
                                        */
  real_T Constant32_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant32'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S151>/Memory1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -0.001
                                        * Referenced by: '<S151>/Gain1'
                                        */
  real_T Constant_Value_ob;            /* Expression: 0
                                        * Referenced by: '<S151>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S151>/Switch1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S151>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.2
                                        * Referenced by: '<S151>/Saturation1'
                                        */
  real_T zerospeedvalue_Value;         /* Expression: 1.42
                                        * Referenced by: '<S151>/ zero speed value'
                                        */
  real_T Constant_Value_hv;            /* Expression: 0
                                        * Referenced by: '<S150>/Constant'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.7
                                        * Referenced by: '<S150>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.7
                                        * Referenced by: '<S150>/Saturation'
                                        */
  real_T Constant1_Value_on;           /* Expression: 1.52
                                        * Referenced by: '<S150>/Constant1'
                                        */
  real_T PWM1_P1;                      /* Expression: 0.01
                                        * Referenced by: '<S2>/PWM1'
                                        */
  real_T ConstantSIMULATIONONLY_Value[6];/* Expression: [0 10 50 100 150 200]
                                          * Referenced by: '<Root>/Constant ( SIMULATION ONLY )'
                                          */
  real_T Switch_Threshold_c;           /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 100
                                        * Referenced by: '<S329>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2047
                                        * Referenced by: '<S329>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: R
                                        * Referenced by: '<S240>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S247>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: F
                                        * Referenced by: '<S247>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S248>/Constant'
                                        */
  real_T Constant_Value_cm;            /* Expression: 1
                                        * Referenced by: '<S246>/Constant'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S242>/Unit Conversion'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S236>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: R
                                        * Referenced by: '<S244>/Constant1'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S244>/f'
                                        */
  real_T Constant1_Value_o5;           /* Expression: 0
                                        * Referenced by: '<S236>/Constant1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 100
                                        * Referenced by: '<S328>/Gain'
                                        */
  real_T Constant_Value_ik;            /* Expression: 2047
                                        * Referenced by: '<S328>/Constant'
                                        */
  real_T capturePWMprova_P1;           /* Expression: ST
                                        * Referenced by: '<Root>/capture PWM (prova)'
                                        */
  real_T scalefactor_Gain;             /* Expression: 0.001
                                        * Referenced by: '<Root>/scale factor'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  real32_T q_Y0[4];                    /* Computed Parameter: q_Y0
                                        * Referenced by: '<S107>/q'
                                        */
  real32_T rpy_Y0[3];                  /* Computed Parameter: rpy_Y0
                                        * Referenced by: '<S107>/rpy'
                                        */
  real32_T gyro_bias_Y0[3];            /* Computed Parameter: gyro_bias_Y0
                                        * Referenced by: '<S107>/gyro_bias'
                                        */
  real32_T a_ned_Y0[3];                /* Computed Parameter: a_ned_Y0
                                        * Referenced by: '<S107>/a_ned'
                                        */
  real32_T UnitDelay1_InitialCondition[4];/* Computed Parameter: UnitDelay1_InitialCondition
                                           * Referenced by: '<S110>/Unit Delay1'
                                           */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S110>/Unit Delay2'
                                        */
  real32_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S110>/Unit Delay3'
                                        */
  real32_T Switch2_Threshold_i;        /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S114>/Switch2'
                                        */
  real32_T Switch2_Threshold_d;        /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S115>/Switch2'
                                        */
  real32_T Switch2_Threshold_d3;       /* Computed Parameter: Switch2_Threshold_d3
                                        * Referenced by: '<S116>/Switch2'
                                        */
  real32_T RateTransition49_X0;        /* Computed Parameter: RateTransition49_X0
                                        * Referenced by: '<Root>/Rate Transition49'
                                        */
  real32_T Switch2_Threshold_a;        /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S120>/Switch2'
                                        */
  real32_T Switch2_Threshold_f;        /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S121>/Switch2'
                                        */
  real32_T Switch2_Threshold_j;        /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S122>/Switch2'
                                        */
  real32_T Constant1_Value_dr[3];      /* Computed Parameter: Constant1_Value_dr
                                        * Referenced by: '<S4>/Constant1'
                                        */
  uint32_T Rx_ID1_Value;               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S326>/Rx_ID1'
                                        */
  uint32_T Rx_ID2_Value;               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S326>/Rx_ID2'
                                        */
  uint32_T Rx_ID3_Value;               /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S326>/Rx_ID3'
                                        */
  uint32_T Rx_ID4_Value;               /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S326>/Rx_ID4'
                                        */
  uint32_T Rx_ID5_Value;               /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S326>/Rx_ID5'
                                        */
  uint32_T Rx_ID6_Value;               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S326>/Rx_ID6'
                                        */
  uint32_T RateTransition18_X0;        /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S330>/Rate Transition18'
                                        */
  uint16_T Constant1_Value_e[4];       /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S330>/Constant1'
                                        */
  int8_T Switch_Threshold_j;           /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S251>/Switch'
                                        */
  uint8_T enableall_Value[6];          /* Computed Parameter: enableall_Value
                                        * Referenced by: '<S309>/enable all'
                                        */
  uint8_T enable0_Value;               /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S309>/enable 0'
                                        */
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S363>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S361>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S362>/FixPt Constant'
                                        */
  uint8_T bmp085accuracylevel_Value;   /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S64>/bmp085 accuracy level'
                                        */
  uint8_T RateTransition_X0;           /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S330>/Rate Transition'
                                        */
  uint8_T RateTransition14_X0;         /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S330>/Rate Transition14'
                                        */
  uint8_T RateTransition15_X0;         /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S330>/Rate Transition15'
                                        */
  uint8_T gpsselector2_CurrentSetting; /* Computed Parameter: gpsselector2_CurrentSetting
                                        * Referenced by: '<S16>/gps selector 2'
                                        */
  uint8_T gpsselector1_CurrentSetting; /* Computed Parameter: gpsselector1_CurrentSetting
                                        * Referenced by: '<S16>/gps selector 1'
                                        */
  rtP_clocklatch_ICARO3_Onda_simple_v2 clocklatch_h;/* '<Root>/clock latch' */
  rtP_clocklatch_ICARO3_Onda_simple_v2 clocklatch_m;/* '<S239>/clock latch' */
  rtP_Subsystem_ICARO3_Onda_simple_v2 Subsystem_o;/* '<S122>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2 Subsystem_l;/* '<S121>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2 Subsystem_p;/* '<S116>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2 Subsystem_g;/* '<S115>/Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ICARO3_Onda_simple_v2 {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_4;
      boolean_T TID2_4;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_ICARO3_Onda_simple_v2 ICARO3_Onda_simple_v2_P;

/* Block signals (auto storage) */
extern BlockIO_ICARO3_Onda_simple_v2 ICARO3_Onda_simple_v2_B;

/* Block states (auto storage) */
extern D_Work_ICARO3_Onda_simple_v2 ICARO3_Onda_simple_v2_DWork;

/* External function called from main */
extern void ICARO3_Onda_simple_v2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ICARO3_Onda_simple_v2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ICARO3_Onda_simple_v2_initialize(void);
extern void ICARO3_Onda_simple_v2_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_ICARO3_Onda_simple_v2 *const ICARO3_Onda_simple_v2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Unused code path elimination
 * Block '<S2>/scale factor for resistor network - from mesarured R1 and R2' : Unused code path elimination
 * Block '<S110>/Add3' : Unused code path elimination
 * Block '<S110>/Discrete-Time Integrator3' : Unused code path elimination
 * Block '<S110>/Gain1' : Unused code path elimination
 * Block '<S110>/Scope6' : Unused code path elimination
 * Block '<S107>/Gain1' : Unused code path elimination
 * Block '<S107>/Scope3' : Unused code path elimination
 * Block '<S107>/Scope4' : Unused code path elimination
 * Block '<S107>/Scope5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion mx3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion14' : Unused code path elimination
 * Block '<Root>/Data Type Conversion15' : Unused code path elimination
 * Block '<S239>/Sum' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/ID CAR ' : Unused code path elimination
 * Block '<Root>/Rate Transition45' : Unused code path elimination
 * Block '<S58>/1 h in sec ' : Unused code path elimination
 * Block '<S58>/Asec to Ahour' : Unused code path elimination
 * Block '<S58>/Instantaneous Power' : Unused code path elimination
 * Block '<S58>/integrate current' : Unused code path elimination
 * Block '<S300>/Internal' : Unused code path elimination
 * Block '<S301>/Internal' : Unused code path elimination
 * Block '<S312>/Gain1' : Unused code path elimination
 * Block '<S312>/Gain2' : Unused code path elimination
 * Block '<S308>/Data Type Conversion mx5' : Unused code path elimination
 * Block '<S308>/Data Type Conversion1' : Unused code path elimination
 * Block '<S308>/Data Type Conversion2' : Unused code path elimination
 * Block '<S308>/Data Type Conversion4' : Unused code path elimination
 * Block '<S308>/Data Type Conversion5' : Unused code path elimination
 * Block '<S308>/Data Type Conversion6' : Unused code path elimination
 * Block '<S308>/Rate Transition' : Unused code path elimination
 * Block '<S308>/Switch2' : Unused code path elimination
 * Block '<S308>/scale factor correction (good for test_calib_2)' : Unused code path elimination
 * Block '<S320>/Bitwise Operator' : Unused code path elimination
 * Block '<S320>/Data Type Conversion mx1' : Unused code path elimination
 * Block '<S320>/Gain' : Unused code path elimination
 * Block '<S308>/use calibrated  data' : Unused code path elimination
 * Block '<S308>/use calibrated  data ' : Unused code path elimination
 * Block '<S64>/Rate Transition1' : Unused code path elimination
 * Block '<S64>/Rate Transition2' : Unused code path elimination
 * Block '<S64>/Rate Transition3' : Unused code path elimination
 * Block '<S64>/Rate Transition4' : Unused code path elimination
 * Block '<S64>/Rate Transition5' : Unused code path elimination
 * Block '<S64>/Rate Transition6' : Unused code path elimination
 * Block '<S309>/Data Type Conversion' : Unused code path elimination
 * Block '<S309>/Data Type Conversion2' : Unused code path elimination
 * Block '<S309>/Rate Transition11' : Unused code path elimination
 * Block '<S330>/Constant' : Unused code path elimination
 * Block '<S330>/Constant2' : Unused code path elimination
 * Block '<S330>/Data Type Conversion' : Unused code path elimination
 * Block '<S330>/Data Type Conversion1' : Unused code path elimination
 * Block '<S330>/Data Type Conversion2' : Unused code path elimination
 * Block '<S330>/Data Type Conversion3' : Unused code path elimination
 * Block '<S330>/Rate Transition1' : Unused code path elimination
 * Block '<S330>/Rate Transition2' : Unused code path elimination
 * Block '<S330>/Rate Transition3' : Unused code path elimination
 * Block '<S330>/Rate Transition4' : Unused code path elimination
 * Block '<S330>/fake gps received signal' : Unused code path elimination
 * Block '<S309>/downsample to 100 Hz11' : Unused code path elimination
 * Block '<S309>/downsample to 100 Hz4' : Unused code path elimination
 * Block '<S309>/downsample to 100 Hz5' : Unused code path elimination
 * Block '<S309>/downsample to 100 Hz6' : Unused code path elimination
 * Block '<S309>/downsample to 100 Hz8' : Unused code path elimination
 * Block '<S309>/enable all1' : Unused code path elimination
 * Block '<S309>/enable all2' : Unused code path elimination
 * Block '<S309>/enable all3' : Unused code path elimination
 * Block '<S361>/Data Type Propagation' : Unused code path elimination
 * Block '<S362>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S363>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S354>/Constant' : Unused code path elimination
 * Block '<S354>/Data Type Conversion2' : Unused code path elimination
 * Block '<S354>/Gain' : Unused code path elimination
 * Block '<S354>/Sum' : Unused code path elimination
 * Block '<S355>/Constant' : Unused code path elimination
 * Block '<S355>/Data Type Conversion2' : Unused code path elimination
 * Block '<S355>/Gain' : Unused code path elimination
 * Block '<S355>/Sum' : Unused code path elimination
 * Block '<S356>/Constant' : Unused code path elimination
 * Block '<S356>/Data Type Conversion2' : Unused code path elimination
 * Block '<S356>/Gain' : Unused code path elimination
 * Block '<S356>/Sum' : Unused code path elimination
 * Block '<S357>/Constant' : Unused code path elimination
 * Block '<S357>/Data Type Conversion2' : Unused code path elimination
 * Block '<S357>/Gain' : Unused code path elimination
 * Block '<S357>/Sum' : Unused code path elimination
 * Block '<S358>/Constant' : Unused code path elimination
 * Block '<S358>/Data Type Conversion2' : Unused code path elimination
 * Block '<S358>/Gain' : Unused code path elimination
 * Block '<S358>/Sum' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S110>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S107>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S107>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S107>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S4>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion22' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion25' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition44' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition16' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition17' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S309>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S330>/Rate Transition19' : Eliminated since input and output rates are identical
 * Block '<S330>/Rate Transition20' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz1' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz10' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz2' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz7' : Eliminated since input and output rates are identical
 * Block '<S309>/downsample to 100 Hz9' : Eliminated since input and output rates are identical
 * Block '<S350>/Out' : Eliminate redundant signal conversion block
 */

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
 * '<Root>' : 'ICARO3_Onda_simple_v2'
 * '<S1>'   : 'ICARO3_Onda_simple_v2/ generatore di riferimenti'
 * '<S2>'   : 'ICARO3_Onda_simple_v2/ADC1'
 * '<S3>'   : 'ICARO3_Onda_simple_v2/ADIS AHRS1'
 * '<S4>'   : 'ICARO3_Onda_simple_v2/ADIS AHRS2'
 * '<S5>'   : 'ICARO3_Onda_simple_v2/Compare To Constant'
 * '<S6>'   : 'ICARO3_Onda_simple_v2/Compare To Constant1'
 * '<S7>'   : 'ICARO3_Onda_simple_v2/Compare To Constant2'
 * '<S8>'   : 'ICARO3_Onda_simple_v2/Compare To Constant3'
 * '<S9>'   : 'ICARO3_Onda_simple_v2/Compensate for sensor mount _acc'
 * '<S10>'  : 'ICARO3_Onda_simple_v2/Compensate for sensor mount _acc1'
 * '<S11>'  : 'ICARO3_Onda_simple_v2/Control '
 * '<S12>'  : 'ICARO3_Onda_simple_v2/Controllo'
 * '<S13>'  : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem'
 * '<S14>'  : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem1'
 * '<S15>'  : 'ICARO3_Onda_simple_v2/GET PPS'
 * '<S16>'  : 'ICARO3_Onda_simple_v2/GPS receiver'
 * '<S17>'  : 'ICARO3_Onda_simple_v2/MATLAB Function'
 * '<S18>'  : 'ICARO3_Onda_simple_v2/MATLAB Function1'
 * '<S19>'  : 'ICARO3_Onda_simple_v2/MATLAB Function2'
 * '<S20>'  : 'ICARO3_Onda_simple_v2/MATLAB Function3'
 * '<S21>'  : 'ICARO3_Onda_simple_v2/MATLAB Function4'
 * '<S22>'  : 'ICARO3_Onda_simple_v2/MATLAB Function5'
 * '<S23>'  : 'ICARO3_Onda_simple_v2/MATLAB Function6'
 * '<S24>'  : 'ICARO3_Onda_simple_v2/MATLAB Function7'
 * '<S25>'  : 'ICARO3_Onda_simple_v2/MATLAB Function8'
 * '<S26>'  : 'ICARO3_Onda_simple_v2/PI Controller'
 * '<S27>'  : 'ICARO3_Onda_simple_v2/PID_1joint '
 * '<S28>'  : 'ICARO3_Onda_simple_v2/PID_1joint 1'
 * '<S29>'  : 'ICARO3_Onda_simple_v2/PID_2joint'
 * '<S30>'  : 'ICARO3_Onda_simple_v2/PID_2joint1'
 * '<S31>'  : 'ICARO3_Onda_simple_v2/PID_3joint '
 * '<S32>'  : 'ICARO3_Onda_simple_v2/PID_3joint 1'
 * '<S33>'  : 'ICARO3_Onda_simple_v2/PID_4joint '
 * '<S34>'  : 'ICARO3_Onda_simple_v2/PID_4joint 1'
 * '<S35>'  : 'ICARO3_Onda_simple_v2/Posca_Zocco Steer Map '
 * '<S36>'  : 'ICARO3_Onda_simple_v2/Prescaler'
 * '<S37>'  : 'ICARO3_Onda_simple_v2/SS AHRS'
 * '<S38>'  : 'ICARO3_Onda_simple_v2/Scheme Running'
 * '<S39>'  : 'ICARO3_Onda_simple_v2/Secondo_giunto'
 * '<S40>'  : 'ICARO3_Onda_simple_v2/Signal Builder'
 * '<S41>'  : 'ICARO3_Onda_simple_v2/Signal Builder1'
 * '<S42>'  : 'ICARO3_Onda_simple_v2/Signal Builder2'
 * '<S43>'  : 'ICARO3_Onda_simple_v2/Tabella_trasformazioni1'
 * '<S44>'  : 'ICARO3_Onda_simple_v2/Tabella_trasformazioni2'
 * '<S45>'  : 'ICARO3_Onda_simple_v2/Tabella_trasformazioni3'
 * '<S46>'  : 'ICARO3_Onda_simple_v2/Tabella_trasformazioni4'
 * '<S47>'  : 'ICARO3_Onda_simple_v2/blocco motori se non arrivano pacchetti'
 * '<S48>'  : 'ICARO3_Onda_simple_v2/clock latch'
 * '<S49>'  : 'ICARO3_Onda_simple_v2/configurazione relativa seeker//target'
 * '<S50>'  : 'ICARO3_Onda_simple_v2/data conversion'
 * '<S51>'  : 'ICARO3_Onda_simple_v2/data conversion1'
 * '<S52>'  : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST'
 * '<S53>'  : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST1'
 * '<S54>'  : 'ICARO3_Onda_simple_v2/debug telemtry STATIC TEST'
 * '<S55>'  : 'ICARO3_Onda_simple_v2/debug_telemetry_minimal'
 * '<S56>'  : 'ICARO3_Onda_simple_v2/fkine1'
 * '<S57>'  : 'ICARO3_Onda_simple_v2/latch1'
 * '<S58>'  : 'ICARO3_Onda_simple_v2/power computations1'
 * '<S59>'  : 'ICARO3_Onda_simple_v2/pwm & pi cmds'
 * '<S60>'  : 'ICARO3_Onda_simple_v2/quarto_giunto'
 * '<S61>'  : 'ICARO3_Onda_simple_v2/re-construct pwm signals'
 * '<S62>'  : 'ICARO3_Onda_simple_v2/re-construct pwm signals1'
 * '<S63>'  : 'ICARO3_Onda_simple_v2/send gps to bs'
 * '<S64>'  : 'ICARO3_Onda_simple_v2/sensor and actuators interface'
 * '<S65>'  : 'ICARO3_Onda_simple_v2/sensor and actuators interface1'
 * '<S66>'  : 'ICARO3_Onda_simple_v2/ generatore di riferimenti/fcn'
 * '<S67>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/Attitude Filter ADIS'
 * '<S68>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS'
 * '<S69>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1'
 * '<S70>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S71>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S72>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend '
 * '<S73>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend'
 * '<S74>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend'
 * '<S75>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S76>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S77>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S78>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S79>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S80>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend'
 * '<S81>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1'
 * '<S82>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2'
 * '<S83>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S84>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S85>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S86>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend '
 * '<S87>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1'
 * '<S88>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend'
 * '<S89>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend'
 * '<S90>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend1'
 * '<S91>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend3'
 * '<S92>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend/Subsystem'
 * '<S93>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend1/Subsystem'
 * '<S94>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend3/Subsystem'
 * '<S95>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend'
 * '<S96>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend1'
 * '<S97>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend3'
 * '<S98>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend/Subsystem'
 * '<S99>'  : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend1/Subsystem'
 * '<S100>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend3/Subsystem'
 * '<S101>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend'
 * '<S102>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend1'
 * '<S103>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend2'
 * '<S104>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend/Subsystem'
 * '<S105>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend1/Subsystem'
 * '<S106>' : 'ICARO3_Onda_simple_v2/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend2/Subsystem'
 * '<S107>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/Attitude Filter ADIS'
 * '<S108>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS'
 * '<S109>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1'
 * '<S110>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S111>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S112>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend '
 * '<S113>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend'
 * '<S114>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend'
 * '<S115>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S116>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S117>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S118>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S119>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S120>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend'
 * '<S121>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1'
 * '<S122>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2'
 * '<S123>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S124>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S125>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S126>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend '
 * '<S127>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1'
 * '<S128>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend'
 * '<S129>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend'
 * '<S130>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1'
 * '<S131>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3'
 * '<S132>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend/Subsystem'
 * '<S133>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1/Subsystem'
 * '<S134>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3/Subsystem'
 * '<S135>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend'
 * '<S136>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1'
 * '<S137>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3'
 * '<S138>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend/Subsystem'
 * '<S139>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1/Subsystem'
 * '<S140>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3/Subsystem'
 * '<S141>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend'
 * '<S142>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1'
 * '<S143>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2'
 * '<S144>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend/Subsystem'
 * '<S145>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1/Subsystem'
 * '<S146>' : 'ICARO3_Onda_simple_v2/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2/Subsystem'
 * '<S147>' : 'ICARO3_Onda_simple_v2/Control /+pi-pi_remapping'
 * '<S148>' : 'ICARO3_Onda_simple_v2/Control /VectorNorm'
 * '<S149>' : 'ICARO3_Onda_simple_v2/Control /atan2'
 * '<S150>' : 'ICARO3_Onda_simple_v2/Control /steer_control'
 * '<S151>' : 'ICARO3_Onda_simple_v2/Control /throttle_control '
 * '<S152>' : 'ICARO3_Onda_simple_v2/Control /steer_control/Control Manager'
 * '<S153>' : 'ICARO3_Onda_simple_v2/Control /throttle_control /Control Manager'
 * '<S154>' : 'ICARO3_Onda_simple_v2/Control /throttle_control /MATLAB Function'
 * '<S155>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control '
 * '<S156>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface'
 * '<S157>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /+pi-pi_remapping'
 * '<S158>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /VectorNorm'
 * '<S159>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /atan2'
 * '<S160>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /steer_control'
 * '<S161>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /throttle_control '
 * '<S162>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /steer_control/Control Manager'
 * '<S163>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /throttle_control /Control Manager'
 * '<S164>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/Control /throttle_control /MATLAB Function'
 * '<S165>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing'
 * '<S166>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager'
 * '<S167>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compensate for sensor mount _acc'
 * '<S168>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compensate for sensor mount _gyro'
 * '<S169>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S170>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function'
 * '<S171>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute accxyz'
 * '<S172>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute accxyz1'
 * '<S173>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute gyroxyz'
 * '<S174>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute magxyz'
 * '<S175>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute magxyz2'
 * '<S176>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/compute_parameters'
 * '<S177>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/spi_data_processing'
 * '<S178>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S179>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S180>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/compute_parameters/MATLAB Function1'
 * '<S181>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S182>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Arrange pwms'
 * '<S183>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX'
 * '<S184>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/I2C1 sensors loop'
 * '<S185>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Subsystem1'
 * '<S186>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Subsystem2'
 * '<S187>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus'
 * '<S188>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus'
 * '<S189>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Arrange pwms/clock latch'
 * '<S190>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1'
 * '<S191>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2'
 * '<S192>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3'
 * '<S193>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S194>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S195>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S196>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S197>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S198>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S199>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S200>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S201>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S202>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S203>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/H'
 * '<S204>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S205>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S206>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S207>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S208>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S209>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S210>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S211>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S212>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S213>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S214>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S215>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S216>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S217>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S218>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S219>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S220>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S221>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S222>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S223>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S224>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S225>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S226>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S227>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S228>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S229>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S230>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S231>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 * '<S232>' : 'ICARO3_Onda_simple_v2/Enabled and Triggered Subsystem1/data conversion'
 * '<S233>' : 'ICARO3_Onda_simple_v2/GET PPS/clock latch'
 * '<S234>' : 'ICARO3_Onda_simple_v2/GET PPS/step 2 pulse'
 * '<S235>' : 'ICARO3_Onda_simple_v2/GET PPS/uint16 to vector'
 * '<S236>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS'
 * '<S237>' : 'ICARO3_Onda_simple_v2/GPS receiver/VENUS GPS'
 * '<S238>' : 'ICARO3_Onda_simple_v2/GPS receiver/compute 3d age'
 * '<S239>' : 'ICARO3_Onda_simple_v2/GPS receiver/compute age'
 * '<S240>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA'
 * '<S241>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/MAP ublox fix type to standard status'
 * '<S242>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Angle Conversion1'
 * '<S243>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem2'
 * '<S244>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem3'
 * '<S245>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem'
 * '<S246>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^1'
 * '<S247>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^2'
 * '<S248>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^3'
 * '<S249>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem2'
 * '<S250>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem3'
 * '<S251>' : 'ICARO3_Onda_simple_v2/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem4'
 * '<S252>' : 'ICARO3_Onda_simple_v2/GPS receiver/compute 3d age/Compare To Constant'
 * '<S253>' : 'ICARO3_Onda_simple_v2/GPS receiver/compute 3d age/clock latch'
 * '<S254>' : 'ICARO3_Onda_simple_v2/GPS receiver/compute age/clock latch'
 * '<S255>' : 'ICARO3_Onda_simple_v2/Prescaler/find send time'
 * '<S256>' : 'ICARO3_Onda_simple_v2/Prescaler/latch'
 * '<S257>' : 'ICARO3_Onda_simple_v2/SS AHRS/Attitude Filter SS'
 * '<S258>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS'
 * '<S259>' : 'ICARO3_Onda_simple_v2/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT'
 * '<S260>' : 'ICARO3_Onda_simple_v2/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT/dcm_marg'
 * '<S261>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend '
 * '<S262>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend'
 * '<S263>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend'
 * '<S264>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend1'
 * '<S265>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend3'
 * '<S266>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend/Subsystem'
 * '<S267>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S268>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S269>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend'
 * '<S270>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend1'
 * '<S271>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend2'
 * '<S272>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend/Subsystem'
 * '<S273>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend1/Subsystem'
 * '<S274>' : 'ICARO3_Onda_simple_v2/SS AHRS/debias SS/Gyros Detrend/Detrend2/Subsystem'
 * '<S275>' : 'ICARO3_Onda_simple_v2/blocco motori se non arrivano pacchetti/Enabled Subsystem'
 * '<S276>' : 'ICARO3_Onda_simple_v2/configurazione relativa seeker//target/engagement'
 * '<S277>' : 'ICARO3_Onda_simple_v2/configurazione relativa seeker//target/engagement 2'
 * '<S278>' : 'ICARO3_Onda_simple_v2/configurazione relativa seeker//target/pure PNG '
 * '<S279>' : 'ICARO3_Onda_simple_v2/configurazione relativa seeker//target/engagement/Fading filter del II ordine'
 * '<S280>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/ADC_filt'
 * '<S281>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/ADC_raw'
 * '<S282>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/Ages'
 * '<S283>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/GPS'
 * '<S284>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/GPS ECEF'
 * '<S285>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/MATLAB Function2'
 * '<S286>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S287>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/Raw IMU data MPU + HMC + ADC'
 * '<S288>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/Raw IMU data MPU only + ADC'
 * '<S289>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/Raw IMU data packer'
 * '<S290>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/To be used for ADAPT NN online tuning'
 * '<S291>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/To be used for H PID online tuning'
 * '<S292>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/join enable flags'
 * '<S293>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/recupero di mpu9150 data'
 * '<S294>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/test solo RC_all_channel_usec + RSSI + ....'
 * '<S295>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST/GPS/detect if was 1 in the last 10 samples'
 * '<S296>' : 'ICARO3_Onda_simple_v2/debug telemtry FLIGHT TEST1/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S297>' : 'ICARO3_Onda_simple_v2/debug telemtry STATIC TEST/Raw IMU data packer: MPU + MAG_HMC'
 * '<S298>' : 'ICARO3_Onda_simple_v2/debug telemtry STATIC TEST/Subsystem'
 * '<S299>' : 'ICARO3_Onda_simple_v2/debug telemtry STATIC TEST/join enable flags'
 * '<S300>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter'
 * '<S301>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter1'
 * '<S302>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter/IO Delay'
 * '<S303>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter/Input Delay'
 * '<S304>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter/Output Delay'
 * '<S305>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter1/IO Delay'
 * '<S306>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter1/Input Delay'
 * '<S307>' : 'ICARO3_Onda_simple_v2/power computations1/low pass filter1/Output Delay'
 * '<S308>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing'
 * '<S309>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager'
 * '<S310>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/Compensate for sensor mount _acc'
 * '<S311>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/Compensate for sensor mount _gyro'
 * '<S312>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S313>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function'
 * '<S314>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function compute accxyz'
 * '<S315>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function compute accxyz1'
 * '<S316>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function compute gyroxyz'
 * '<S317>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function compute magxyz'
 * '<S318>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/MATLAB Function compute magxyz2'
 * '<S319>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/compute_parameters'
 * '<S320>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/spi_data_processing'
 * '<S321>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S322>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S323>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/compute_parameters/MATLAB Function1'
 * '<S324>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S325>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/Arrange pwms'
 * '<S326>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX'
 * '<S327>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/I2C1 sensors loop'
 * '<S328>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/Subsystem1'
 * '<S329>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/Subsystem2'
 * '<S330>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/compose data from canbus'
 * '<S331>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus'
 * '<S332>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/Arrange pwms/clock latch'
 * '<S333>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1'
 * '<S334>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2'
 * '<S335>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3'
 * '<S336>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S337>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S338>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S339>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S340>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S341>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S342>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S343>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S344>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S345>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S346>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/compose data from canbus/H'
 * '<S347>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S348>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S349>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S350>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair'
 * '<S351>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S352>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S353>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S354>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S355>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S356>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S357>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S358>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S359>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S360>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S361>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter'
 * '<S362>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S363>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S364>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S365>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S366>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S367>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S368>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S369>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S370>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S371>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S372>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S373>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S374>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S375>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S376>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S377>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S378>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 * '<S379>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing'
 * '<S380>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager'
 * '<S381>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/Compensate for sensor mount _acc'
 * '<S382>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/Compensate for sensor mount _gyro'
 * '<S383>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S384>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function'
 * '<S385>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function compute accxyz'
 * '<S386>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function compute accxyz1'
 * '<S387>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function compute gyroxyz'
 * '<S388>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function compute magxyz'
 * '<S389>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/MATLAB Function compute magxyz2'
 * '<S390>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/compute_parameters'
 * '<S391>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/spi_data_processing'
 * '<S392>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S393>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S394>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/compute_parameters/MATLAB Function1'
 * '<S395>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S396>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/Arrange pwms'
 * '<S397>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX'
 * '<S398>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/I2C1 sensors loop'
 * '<S399>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/Subsystem1'
 * '<S400>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/Subsystem2'
 * '<S401>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/compose data from canbus'
 * '<S402>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus'
 * '<S403>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/Arrange pwms/clock latch'
 * '<S404>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1'
 * '<S405>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2'
 * '<S406>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3'
 * '<S407>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S408>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S409>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S410>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S411>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S412>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S413>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S414>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S415>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S416>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S417>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/compose data from canbus/H'
 * '<S418>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S419>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S420>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S421>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S422>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S423>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S424>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S425>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S426>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S427>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S428>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S429>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S430>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S431>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S432>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S433>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S434>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S435>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S436>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S437>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S438>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S439>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S440>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S441>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S442>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S443>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S444>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S445>' : 'ICARO3_Onda_simple_v2/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 */
#endif                                 /* RTW_HEADER_ICARO3_Onda_simple_v2_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_simple_v2.h
 */
