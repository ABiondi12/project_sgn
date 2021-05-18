/*
 * File: ICARO3_Onda_simple_v2_media_fun.h
 *
 * Code generated for Simulink model :ICARO3_Onda_simple_v2_media_fun.
 *
 * Model version      : 1.1542
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Mon Dec 09 17:20:12 2019
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

#ifndef RTW_HEADER_ICARO3_Onda_simple_v2_media_fun_h_
#define RTW_HEADER_ICARO3_Onda_simple_v2_media_fun_h_
#include <math.h>
#include <string.h>
#include "ICARO3_Onda_simple_v2_media_fun_STM32.h"
#ifndef ICARO3_Onda_simple_v2_media_fun_COMMON_INCLUDES_
# define ICARO3_Onda_simple_v2_media_fun_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ICARO3_Onda_simple_v2_media_fun_COMMON_INCLUDES_ */

#include "ICARO3_Onda_simple_v2_media_fun_types.h"
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

/* Block signals for system '<S122>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S125>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S125>/Discrete-Time Integrator1' */
  real_T Product1;                     /* '<S125>/Product1' */
} rtB_Subsystem_ICARO3_Onda_simple_v2_media_fun;

/* Block states (auto storage) for system '<S122>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S125>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S125>/Discrete-Time Integrator1' */
} rtDW_Subsystem_ICARO3_Onda_simple_v2_media_fun;

/* Block signals for system '<S246>/clock latch' */
typedef struct {
  real_T In;                           /* '<S261>/In' */
} rtB_clocklatch_ICARO3_Onda_simple_v2_media_fun;

/* Block signals for system '<S315>/Compensate for sensor mount _acc' */
typedef struct {
  real32_T y[3];                       /* '<S315>/Compensate for sensor mount _acc' */
} rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_media_fun;

/* Block signals for system '<S340>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint16_T y;                          /* '<S340>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu;

/* Block signals for system '<S341>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint32_T y;                          /* '<S341>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__f;

/* Block signals for system '<S360>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint8_T y[2];                        /* '<S360>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j;

/* Block signals for system '<S360>/MATLAB Function compute gyroxyz4' */
typedef struct {
  uint8_T TmpSignalConversionAtSFunctionInport1[8];/* '<S360>/MATLAB Function compute gyroxyz4' */
  uint8_T y[8];                        /* '<S360>/MATLAB Function compute gyroxyz4' */
} rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2_media_fu;

/* Block signals (auto storage) */
typedef struct {
  real_T Step;                         /* '<S115>/Step' */
  real_T Step1;                        /* '<S115>/Step1' */
  real_T Add;                          /* '<S115>/Add' */
  real_T DataTypeConversion7[3];       /* '<S315>/Data Type Conversion7' */
  real_T Switch2;                      /* '<S121>/Switch2' */
  real_T Switch2_p;                    /* '<S122>/Switch2' */
  real_T Switch2_d;                    /* '<S123>/Switch2' */
  real_T DataTypeConversion9[3];       /* '<S315>/Data Type Conversion9' */
  real_T Gain8[3];                     /* '<Root>/Gain8' */
  real_T Switch2_o;                    /* '<S127>/Switch2' */
  real_T Switch2_pz;                   /* '<S128>/Switch2' */
  real_T Switch2_n;                    /* '<S129>/Switch2' */
  real_T DataTypeConversionmx10[3];    /* '<S4>/Data Type Conversion mx10' */
  real_T RateTransition54;             /* '<Root>/Rate Transition54' */
  real_T DataTypeConversionmx17[3];    /* '<S4>/Data Type Conversion mx17' */
  real_T RateTransition55[3];          /* '<Root>/Rate Transition55' */
  real_T SFunctionUSART3_Receive4_o1[16];/* '<Root>/S-Function-USART3_Receive4' */
  real_T SFunctionUSART3_Receive4_o2;  /* '<Root>/S-Function-USART3_Receive4' */
  real_T VectorTAG0[3];                /* '<Root>/Vector TAG0' */
  real_T VectorTAG1[3];                /* '<Root>/Vector TAG1' */
  real_T RateTransition47;             /* '<Root>/Rate Transition47' */
  real_T RateTransition48;             /* '<Root>/Rate Transition48' */
  real_T TmpSignalConversionAtreproducePWM9Inport1[4];
  real_T RateTransition46;             /* '<Root>/Rate Transition46' */
  real_T DataTypeConversion1[2];       /* '<S18>/Data Type Conversion1' */
  real_T DataTypeConversion2[2];       /* '<S18>/Data Type Conversion2' */
  real_T relativevector[2];            /* '<S18>/Sum2' */
  real_T angle_error;                  /* '<S18>/Sum3' */
  real_T DataTypeConversion3;          /* '<S18>/Data Type Conversion3' */
  real_T Memory1;                      /* '<S158>/Memory1' */
  real_T Gain1;                        /* '<S158>/Gain1' */
  real_T Switch1;                      /* '<S158>/Switch1' */
  real_T Saturation1;                  /* '<S158>/Saturation1' */
  real_T Sum1;                         /* '<S158>/Sum1' */
  real_T Switch1_p;                    /* '<S157>/Switch1' */
  real_T Saturation;                   /* '<S157>/Saturation' */
  real_T Sum1_a;                       /* '<S157>/Sum1' */
  real_T DataTypeConversion16;         /* '<Root>/Data Type Conversion16' */
  real_T DataTypeConversion19;         /* '<Root>/Data Type Conversion19' */
  real_T DataTypeConversion3_a[3];     /* '<S315>/Data Type Conversion3' */
  real_T downsampleto100Hz3[4];        /* '<S316>/downsample to 100 Hz3' */
  real_T Gain;                         /* '<S336>/Gain' */
  real_T Sum;                          /* '<S336>/Sum' */
  real_T DigitalClock;                 /* '<S245>/Digital Clock' */
  real_T SFunction3_o1[7];             /* '<S243>/S-Function3' */
  real_T SFunction3_o2;                /* '<S243>/S-Function3' */
  real_T gpsselector2;                 /* '<S23>/gps selector 2' */
  real_T Product2;                     /* '<S250>/Product2' */
  real_T Product3;                     /* '<S250>/Product3' */
  real_T Sum2;                         /* '<S250>/Sum2' */
  real_T sqrt_p;                       /* '<S250>/sqrt' */
  real_T Sum1_n;                       /* '<S254>/Sum1' */
  real_T Product1;                     /* '<S247>/Product1' */
  real_T Product2_k;                   /* '<S255>/Product2' */
  real_T Sum1_b;                       /* '<S255>/Sum1' */
  real_T Sum1_d;                       /* '<S253>/Sum1' */
  real_T Product2_a;                   /* '<S253>/Product2' */
  real_T TrigonometricFunction2;       /* '<S247>/Trigonometric Function2' */
  real_T UnitConversion[2];            /* '<S249>/Unit Conversion' */
  real_T sincos_o1;                    /* '<S251>/sincos' */
  real_T sincos_o2;                    /* '<S251>/sincos' */
  real_T Product2_o;                   /* '<S251>/Product2' */
  real_T Product1_h;                   /* '<S251>/Product1' */
  real_T Sum_b;                        /* '<S251>/Sum' */
  real_T sqrt_i;                       /* '<S251>/sqrt' */
  real_T Product3_l;                   /* '<S251>/Product3' */
  real_T Product4;                     /* '<S251>/Product4' */
  real_T Sum2_k;                       /* '<S251>/Sum2' */
  real_T Product5;                     /* '<S251>/Product5' */
  real_T Product6;                     /* '<S251>/Product6' */
  real_T Sum3;                         /* '<S251>/Sum3' */
  real_T gpsselector1[16];             /* '<S23>/gps selector 1' */
  real_T Product;                      /* '<S23>/Product' */
  real_T Sum_f;                        /* '<S245>/Sum' */
  real_T Gain_g;                       /* '<S335>/Gain' */
  real_T Sum_e;                        /* '<S335>/Sum' */
  real_T DigitalClock_k;               /* '<Root>/Digital Clock' */
  real_T DigitalClock_p;               /* '<S246>/Digital Clock' */
  real_T scalefactor[2];               /* '<Root>/scale factor' */
  real_T PulseGenerator1;              /* '<S45>/Pulse Generator1' */
  real_T PulseGenerator;               /* '<S338>/Pulse Generator' */
  real_T Output;                       /* '<S357>/Output' */
  real_T Gain_m;                       /* '<S358>/Gain' */
  real_T Sum_i;                        /* '<S358>/Sum' */
  real_T Gain_k[3];                    /* '<S359>/Gain' */
  real_T Sum_c[3];                     /* '<S359>/Sum' */
  real_T TmpSignalConversionAtSFunctionInport1[12];/* '<S315>/MATLAB Function compute magxyz2' */
  real_T RC_TRPY_refs[4];              /* '<S315>/MATLAB Function compute magxyz2' */
  real_T RC_aux_channels[8];           /* '<S315>/MATLAB Function compute magxyz2' */
  real_T h_calib[3];                   /* '<S315>/MATLAB Function' */
  real_T y[4];                         /* '<Root>/data conversion' */
  real_T In;                           /* '<S260>/In' */
  real_T y_i;                          /* '<S243>/MAP ublox fix type to standard status' */
  real_T Memory;                       /* '<S258>/Memory' */
  real_T Switch;                       /* '<S258>/Switch' */
  real_T sincos_o1_c;                  /* '<S256>/sincos' */
  real_T sincos_o2_e;                  /* '<S256>/sincos' */
  real_T Product3_m;                   /* '<S256>/Product3' */
  real_T Sum2_c;                       /* '<S256>/Sum2' */
  real_T Product4_e;                   /* '<S256>/Product4' */
  real_T Sum1_j;                       /* '<S256>/Sum1' */
  real_T TrigonometricFunction4;       /* '<S256>/Trigonometric Function4' */
  real_T sincos_o1_b;                  /* '<S257>/sincos' */
  real_T sincos_o2_l;                  /* '<S257>/sincos' */
  real_T Product3_o;                   /* '<S257>/Product3' */
  real_T TrigonometricFunction4_o;     /* '<S257>/Trigonometric Function4' */
  real_T Product2_k2;                  /* '<S258>/Product2' */
  real_T TrigonometricFunction3;       /* '<S258>/Trigonometric Function3' */
  real_T control;                      /* '<S158>/MATLAB Function' */
  real_T go;                           /* '<S158>/Control Manager' */
  real_T go_i;                         /* '<S157>/Control Manager' */
  real_T Gain1_m;                      /* '<S157>/Gain1' */
  real_T theta;                        /* '<S18>/atan2' */
  real_T y_o;                          /* '<S18>/VectorNorm' */
  real_T theta_out;                    /* '<S18>/+pi-pi_remapping' */
  real_T y_c[3];                       /* '<Root>/Compensate for sensor mount _acc1' */
  real_T y_k[3];                       /* '<Root>/Compensate for sensor mount _acc' */
  real_T Sum1_k;                       /* '<S129>/Sum1' */
  real_T Sum1_f;                       /* '<S128>/Sum1' */
  real_T DiscreteTimeIntegrator;       /* '<S130>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S130>/Discrete-Time Integrator1' */
  real_T Product1_d;                   /* '<S130>/Product1' */
  real_T Sum1_km;                      /* '<S127>/Sum1' */
  real_T Sum1_d4;                      /* '<S123>/Sum1' */
  real_T Sum1_g;                       /* '<S122>/Sum1' */
  real_T DiscreteTimeIntegrator_p;     /* '<S124>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_p;    /* '<S124>/Discrete-Time Integrator1' */
  real_T Product1_f;                   /* '<S124>/Product1' */
  real_T Sum1_dm;                      /* '<S121>/Sum1' */
  real32_T DataTypeConversionmx8;      /* '<S115>/Data Type Conversion mx8' */
  real32_T DataTypeConversionmx1[3];   /* '<S4>/Data Type Conversion mx1' */
  real32_T RateTransition49[3];        /* '<Root>/Rate Transition49' */
  real32_T DataTypeConversionmx2[3];   /* '<S4>/Data Type Conversion mx2' */
  real32_T DataTypeConversion21;       /* '<Root>/Data Type Conversion21' */
  real32_T DataTypeConversion24[3];    /* '<Root>/Data Type Conversion24' */
  real32_T RateTransition56[3];        /* '<Root>/Rate Transition56' */
  real32_T DataTypeConversion18[16];   /* '<Root>/Data Type Conversion18' */
  real32_T DataTypeConversion28[3];    /* '<Root>/Data Type Conversion28' */
  real32_T DataTypeConversion27[3];    /* '<Root>/Data Type Conversion27' */
  real32_T TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1[19];
  real32_T DataTypeConversion4;        /* '<S18>/Data Type Conversion4' */
  real32_T DataTypeConversion5;        /* '<S18>/Data Type Conversion5' */
  real32_T headingdirection[3];        /* '<Root>/Sum12' */
  real32_T VectorConcatenate[3];       /* '<Root>/Vector Concatenate' */
  real32_T VectorConcatenate1[3];      /* '<Root>/Vector Concatenate1' */
  real32_T DataTypeConversionmx3;      /* '<S71>/Data Type Conversion mx3' */
  real32_T RateTransition2[11];        /* '<S315>/Rate Transition2' */
  real32_T y_g;                        /* '<S337>/typecast uin32 to single1' */
  real32_T y_b;                        /* '<S337>/typecast uin32 to single' */
  real32_T y_b1;                       /* '<S353>/typecast uin32 to single' */
  real32_T a[3];                       /* '<S327>/MATLAB Function compute magxyz1' */
  real32_T w[3];                       /* '<S327>/MATLAB Function compute magxyz1' */
  real32_T params[11];                 /* '<S326>/MATLAB Function1' */
  real32_T m[3];                       /* '<S315>/MATLAB Function compute magxyz' */
  real32_T w_j[3];                     /* '<S315>/MATLAB Function compute gyroxyz' */
  real32_T a_g[3];                     /* '<S315>/MATLAB Function compute accxyz1' */
  real32_T t;                          /* '<S315>/MATLAB Function compute accxyz1' */
  real32_T g[3];                       /* '<S315>/MATLAB Function compute accxyz1' */
  real32_T a_j[3];                     /* '<S315>/MATLAB Function compute accxyz' */
  real32_T DataTypeConversion1_i;      /* '<S319>/Data Type Conversion1' */
  real32_T DataTypeConversion3_g;      /* '<S319>/Data Type Conversion3' */
  real32_T T;                          /* '<S319>/MATLAB Function' */
  real32_T h;                          /* '<S319>/MATLAB Function' */
  real32_T UnitDelay1[4];              /* '<S117>/Unit Delay1' */
  real32_T UnitDelay2[3];              /* '<S117>/Unit Delay2' */
  real32_T UnitDelay3[3];              /* '<S117>/Unit Delay3' */
  real32_T Sum_h[3];                   /* '<S114>/Sum' */
  real32_T euler_out[3];               /* '<S117>/dcm_marg' */
  real32_T a_ned[3];                   /* '<S117>/dcm_marg' */
  real32_T q_out[4];                   /* '<S117>/dcm_marg' */
  real32_T e_int_out_a[3];             /* '<S117>/dcm_marg' */
  real32_T e_int_out_m[3];             /* '<S117>/dcm_marg' */
  real32_T biases[3];                  /* '<S117>/dcm_marg' */
  real32_T e_m[3];                     /* '<S117>/dcm_marg' */
  uint32_T PWM1[4];                    /* '<S2>/PWM1' */
  uint32_T DataTypeConversion8;        /* '<S353>/Data Type Conversion8' */
  uint32_T u;                          /* '<S353>/ ' */
  uint32_T DataTypeConversion9_d;      /* '<S353>/Data Type Conversion9' */
  uint32_T u_o;                        /* '<S353>/  ' */
  uint32_T DataTypeConversion7_c;      /* '<S353>/Data Type Conversion7' */
  uint32_T u_i;                        /* '<S353>/  2' */
  uint32_T DataTypeConversion10;       /* '<S353>/Data Type Conversion10' */
  uint32_T Sum12;                      /* '<S353>/Sum12' */
  uint32_T RateTransition18[2];        /* '<S337>/Rate Transition18' */
  uint32_T DataTypeConversiononi2cmag1[8];/* '<S341>/Data Type Conversion on i2c mag1' */
  uint32_T DataTypeConversion5_l[3];   /* '<S319>/Data Type Conversion5' */
  uint32_T UP;                         /* '<S319>/MATLAB Function1' */
  uint16_T I2C1SensorsLoop_o2;         /* '<S334>/I2C1 Sensors Loop' */
  uint16_T DataTypeConversiononi2cmag3[14];/* '<S315>/Data Type Conversion on i2c mag3' */
  uint16_T DataTypeConversion[22];     /* '<S326>/Data Type Conversion' */
  uint16_T DataTypeConversiononi2cmag[6];/* '<S315>/Data Type Conversion on i2c mag' */
  uint16_T DataTypeConversiononi2cmag1_c[6];/* '<S315>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag2[6];/* '<S315>/Data Type Conversion on i2c mag2' */
  uint16_T RateTransition18_g[7];      /* '<S315>/Rate Transition18' */
  uint16_T BitwiseOperator1;           /* '<S327>/Bitwise Operator1' */
  uint16_T BitwiseOperator2;           /* '<S327>/Bitwise Operator2' */
  uint16_T BitwiseOperator3;           /* '<S327>/Bitwise Operator3' */
  uint16_T BitwiseOperator4;           /* '<S327>/Bitwise Operator4' */
  uint16_T BitwiseOperator5;           /* '<S327>/Bitwise Operator5' */
  uint16_T BitwiseOperator6;           /* '<S327>/Bitwise Operator6' */
  uint16_T DataTypeConversion1_k;      /* '<S316>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_k;      /* '<S336>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_c;      /* '<S335>/Data Type Conversion2' */
  uint16_T capturePWMprova_o1[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T capturePWMprova_o2[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T capturePWMprova_o3[2];      /* '<Root>/capture PWM (prova)' */
  uint16_T DataTypeConversion1_d;      /* '<S338>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_cg;     /* '<S338>/Data Type Conversion2' */
  uint16_T DataTypeConversion3_n[4];   /* '<S338>/Data Type Conversion3' */
  uint16_T IndexVector[3];             /* '<S338>/Index Vector' */
  uint16_T Switch_o[3];                /* '<S338>/Switch' */
  uint16_T DataTypeConversion2_g;      /* '<S358>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_i[3];   /* '<S359>/Data Type Conversion2' */
  uint16_T DataTypeConversiononi2cmag1_j[8];/* '<S340>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag1_a[8];/* '<S342>/Data Type Conversion on i2c mag1' */
  uint16_T TmpSignalConversionAtSFunctionInport1_h[6];/* '<S327>/MATLAB Function compute magxyz1' */
  uint16_T DataTypeConversion4_f[2];   /* '<S319>/Data Type Conversion4' */
  uint16_T UT;                         /* '<S319>/MATLAB Function1' */
  int8_T WhileIterator;                /* '<S252>/While Iterator' */
  uint8_T I2C1SensorsLoop_o1[71];      /* '<S334>/I2C1 Sensors Loop' */
  uint8_T Switch4[6];                  /* '<S316>/Switch4' */
  uint8_T RateTransition10;            /* '<S71>/Rate Transition10' */
  uint8_T RateTransition6[2];          /* '<S315>/Rate Transition6' */
  uint8_T RateTransition5[3];          /* '<S315>/Rate Transition5' */
  uint8_T RateTransition1;             /* '<S315>/Rate Transition1' */
  uint8_T RateTransition[8];           /* '<S337>/Rate Transition' */
  uint8_T Switch_n[6];                 /* '<S316>/Switch' */
  uint8_T RateTransition14[8];         /* '<S337>/Rate Transition14' */
  uint8_T Switch1_k[6];                /* '<S316>/Switch1' */
  uint8_T RateTransition15[8];         /* '<S337>/Rate Transition15' */
  uint8_T Switch2_i[6];                /* '<S316>/Switch2' */
  uint8_T capturePWMprova_o4[2];       /* '<Root>/capture PWM (prova)' */
  uint8_T Output_e;                    /* '<S368>/Output' */
  uint8_T FixPtSum1;                   /* '<S369>/FixPt Sum1' */
  uint8_T FixPtSwitch;                 /* '<S370>/FixPt Switch' */
  uint8_T CANRX_o1[48];                /* '<S333>/CANRX' */
  uint8_T CANRX_o2;                    /* '<S333>/CANRX' */
  boolean_T Compare;                   /* '<S259>/Compare' */
  boolean_T LogicalOperator;           /* '<S316>/Logical Operator' */
  boolean_T RateTransition14_p;        /* '<S316>/Rate Transition14' */
  boolean_T RelationalOperator;        /* '<S252>/Relational Operator' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz5_p;/* '<S367>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz4_f;/* '<S367>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz3_ph;/* '<S367>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz2_i;/* '<S367>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz1_g;/* '<S367>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz5_k;/* '<S366>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz4_j;/* '<S366>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz3_p;/* '<S366>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz2_l;/* '<S366>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz1_i;/* '<S366>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz5_b;/* '<S360>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz4;  /* '<S360>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz3_b;/* '<S360>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz2_g;/* '<S360>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__j
    sf_MATLABFunctioncomputegyroxyz1_b;/* '<S360>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz5_d;/* '<S342>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz3_a;/* '<S342>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz2_h;/* '<S342>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz1_e;/* '<S342>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__f
    sf_MATLABFunctioncomputegyroxyz5_i;/* '<S341>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media__f
    sf_MATLABFunctioncomputegyroxyz1_k;/* '<S341>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz5;  /* '<S340>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz3;  /* '<S340>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz2;  /* '<S340>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_simple_v2_media_fu
    sf_MATLABFunctioncomputegyroxyz1;  /* '<S340>/MATLAB Function compute gyroxyz1' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_media_fun
    sf_Compensateforsensormount_gyro;  /* '<S315>/Compensate for sensor mount _gyro' */
  rtB_Compensateforsensormount_acc_ICARO3_Onda_simple_v2_media_fun
    sf_Compensateforsensormount_acc;   /* '<S315>/Compensate for sensor mount _acc' */
  rtB_clocklatch_ICARO3_Onda_simple_v2_media_fun clocklatch_h;/* '<Root>/clock latch' */
  rtB_clocklatch_ICARO3_Onda_simple_v2_media_fun clocklatch_m;/* '<S246>/clock latch' */
  rtB_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_o;/* '<S129>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_l;/* '<S128>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_p;/* '<S123>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_g;/* '<S122>/Subsystem' */
} BlockIO_ICARO3_Onda_simple_v2_media_fun;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S130>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S130>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S124>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S124>/Discrete-Time Integrator1' */
  real_T RateTransition47_Buffer0;     /* '<Root>/Rate Transition47' */
  real_T RateTransition48_Buffer0;     /* '<Root>/Rate Transition48' */
  real_T Memory1_PreviousInput;        /* '<S158>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S258>/Memory' */
  real32_T UnitDelay1_DSTATE[4];       /* '<S117>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE[3];       /* '<S117>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[3];       /* '<S117>/Unit Delay3' */
  real32_T RateTransition49_Buffer0[3];/* '<Root>/Rate Transition49' */
  real32_T RateTransition2_Buffer0[11];/* '<S315>/Rate Transition2' */
  int32_T clockTickCounter;            /* '<S45>/Pulse Generator1' */
  int32_T clockTickCounter_f;          /* '<S338>/Pulse Generator' */
  uint32_T RateTransition18_Buffer[4]; /* '<S337>/Rate Transition18' */
  uint16_T RateTransition18_Buffer0[7];/* '<S315>/Rate Transition18' */
  uint8_T Output_DSTATE;               /* '<S368>/Output' */
  int8_T RateTransition6_semaphoreTaken;/* '<S315>/Rate Transition6' */
  int8_T RateTransition5_semaphoreTaken;/* '<S315>/Rate Transition5' */
  int8_T RateTransition2_semaphoreTaken;/* '<S315>/Rate Transition2' */
  int8_T RateTransition_ActiveBufIdx;  /* '<S337>/Rate Transition' */
  int8_T RateTransition14_ActiveBufIdx;/* '<S337>/Rate Transition14' */
  int8_T RateTransition15_ActiveBufIdx;/* '<S337>/Rate Transition15' */
  int8_T RateTransition18_semaphoreTaken;/* '<S315>/Rate Transition18' */
  int8_T RateTransition18_ActiveBufIdx;/* '<S337>/Rate Transition18' */
  uint8_T RateTransition6_Buffer0[2];  /* '<S315>/Rate Transition6' */
  uint8_T RateTransition5_Buffer0[3];  /* '<S315>/Rate Transition5' */
  uint8_T RateTransition_Buffer[16];   /* '<S337>/Rate Transition' */
  uint8_T RateTransition14_Buffer[16]; /* '<S337>/Rate Transition14' */
  uint8_T RateTransition15_Buffer[16]; /* '<S337>/Rate Transition15' */
  boolean_T ini_not_empty;             /* '<S117>/dcm_marg' */
  boolean_T AttitudeFilterADIS_MODE;   /* '<S4>/Attitude Filter ADIS' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_o;/* '<S129>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_l;/* '<S128>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_p;/* '<S123>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_g;/* '<S122>/Subsystem' */
} D_Work_ICARO3_Onda_simple_v2_media_fun;

/* Parameters for system: '<S122>/Subsystem' */
struct rtP_Subsystem_ICARO3_Onda_simple_v2_media_fun_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S125>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S125>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S125>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S125>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S125>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S246>/clock latch' */
struct rtP_clocklatch_ICARO3_Onda_simple_v2_media_fun_ {
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S261>/Out'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ICARO3_Onda_simple_v2_media_fun_ {
  real_T CAL_PARAM[9];                 /* Variable: CAL_PARAM
                                        * Referenced by: '<S315>/MATLAB Function'
                                        */
  real_T INV_PITCH_RANGE;              /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_ROLL_RANGE;               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_THROTTLE_RANGE;           /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_YAW_RANGE;                /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_IDX;                    /* Variable: PITCH_IDX
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_MID;                    /* Variable: PITCH_MID
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_IDX;                     /* Variable: ROLL_IDX
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_MID;                     /* Variable: ROLL_MID
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_DOWN;                /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_IDX;                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_LOW_THRES;           /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_IDX;                      /* Variable: YAW_IDX
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_MID;                      /* Variable: YAW_MID
                                        * Referenced by: '<S315>/MATLAB Function compute magxyz2'
                                        */
  real32_T ST;                         /* Variable: ST
                                        * Referenced by: '<S117>/dcm_marg'
                                        */
  real_T RepeatingSequenceStair_OutValues[12];/* Mask Parameter: RepeatingSequenceStair_OutValues
                                               * Referenced by: '<S357>/Vector'
                                               */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S259>/Constant'
                                        */
  real32_T DCM_MARG_QUAT_Ki;           /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S117>/dcm_marg'
                                        */
  real32_T DCM_MARG_QUAT_Kp;           /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S117>/dcm_marg'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator3_BitMask;   /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator3'
                                        */
  uint16_T BitwiseOperator4_BitMask;   /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator4'
                                        */
  uint16_T BitwiseOperator5_BitMask;   /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator5'
                                        */
  uint16_T BitwiseOperator6_BitMask;   /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S327>/Bitwise Operator6'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S370>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S121>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S124>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S124>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S124>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S122>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 9.81
                                        * Referenced by: '<S123>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S123>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S127>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S130>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_b;/* Computed Parameter: DiscreteTimeIntegrator_gainval_b
                                           * Referenced by: '<S130>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S130>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                            * Referenced by: '<S130>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_i; /* Expression: eps
                                        * Referenced by: '<S130>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S128>/Constant1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S129>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S157>/Gain1'
                                        */
  real_T phi_Y0;                       /* Expression: 0
                                        * Referenced by: '<S252>/phi'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S258>/Memory'
                                        */
  real_T Constant1_Value_oo;           /* Expression: R
                                        * Referenced by: '<S256>/Constant1'
                                        */
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S260>/Out'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S359>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S359>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S358>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 180
                                        * Referenced by: '<S358>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S338>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<S338>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S338>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S338>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S338>/Switch'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S115>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S115>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S115>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 11
                                        * Referenced by: '<S115>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S115>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S115>/Step1'
                                        */
  real_T I2C1SensorsLoop_P1;           /* Expression: ST
                                        * Referenced by: '<S334>/I2C1 Sensors Loop'
                                        */
  real_T HW0SIM_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch4'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T SavedatatodataloggerthemicroSDcard2_P1;/* Expression: 0.01
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
                                        * Referenced by: '<S158>/Memory1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -0.001
                                        * Referenced by: '<S158>/Gain1'
                                        */
  real_T Constant_Value_ob;            /* Expression: 0
                                        * Referenced by: '<S158>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S158>/Switch1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S158>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.2
                                        * Referenced by: '<S158>/Saturation1'
                                        */
  real_T zerospeedvalue_Value;         /* Expression: 1.42
                                        * Referenced by: '<S158>/ zero speed value'
                                        */
  real_T Constant_Value_hv;            /* Expression: 0
                                        * Referenced by: '<S157>/Constant'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0.5
                                        * Referenced by: '<S157>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.7
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.7
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T Constant1_Value_on;           /* Expression: 1.52
                                        * Referenced by: '<S157>/Constant1'
                                        */
  real_T PWM1_P1;                      /* Expression: 0.01
                                        * Referenced by: '<S2>/PWM1'
                                        */
  real_T ConstantSIMULATIONONLY_Value[6];/* Expression: [0 10 50 100 150 200]
                                          * Referenced by: '<Root>/Constant ( SIMULATION ONLY )'
                                          */
  real_T Switch_Threshold_c;           /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 100
                                        * Referenced by: '<S336>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2047
                                        * Referenced by: '<S336>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: R
                                        * Referenced by: '<S247>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S254>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: F
                                        * Referenced by: '<S254>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S255>/Constant'
                                        */
  real_T Constant_Value_cm;            /* Expression: 1
                                        * Referenced by: '<S253>/Constant'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S249>/Unit Conversion'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S243>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: R
                                        * Referenced by: '<S251>/Constant1'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S251>/f'
                                        */
  real_T Constant1_Value_o5;           /* Expression: 0
                                        * Referenced by: '<S243>/Constant1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 100
                                        * Referenced by: '<S335>/Gain'
                                        */
  real_T Constant_Value_ik;            /* Expression: 2047
                                        * Referenced by: '<S335>/Constant'
                                        */
  real_T capturePWMprova_P1;           /* Expression: ST
                                        * Referenced by: '<Root>/capture PWM (prova)'
                                        */
  real_T scalefactor_Gain;             /* Expression: 0.001
                                        * Referenced by: '<Root>/scale factor'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S45>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S45>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S45>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S45>/Pulse Generator1'
                                        */
  real32_T q_Y0[4];                    /* Computed Parameter: q_Y0
                                        * Referenced by: '<S114>/q'
                                        */
  real32_T rpy_Y0[3];                  /* Computed Parameter: rpy_Y0
                                        * Referenced by: '<S114>/rpy'
                                        */
  real32_T gyro_bias_Y0[3];            /* Computed Parameter: gyro_bias_Y0
                                        * Referenced by: '<S114>/gyro_bias'
                                        */
  real32_T a_ned_Y0[3];                /* Computed Parameter: a_ned_Y0
                                        * Referenced by: '<S114>/a_ned'
                                        */
  real32_T UnitDelay1_InitialCondition[4];/* Computed Parameter: UnitDelay1_InitialCondition
                                           * Referenced by: '<S117>/Unit Delay1'
                                           */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S117>/Unit Delay2'
                                        */
  real32_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S117>/Unit Delay3'
                                        */
  real32_T Switch2_Threshold_i;        /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S121>/Switch2'
                                        */
  real32_T Switch2_Threshold_d;        /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S122>/Switch2'
                                        */
  real32_T Switch2_Threshold_d3;       /* Computed Parameter: Switch2_Threshold_d3
                                        * Referenced by: '<S123>/Switch2'
                                        */
  real32_T RateTransition49_X0;        /* Computed Parameter: RateTransition49_X0
                                        * Referenced by: '<Root>/Rate Transition49'
                                        */
  real32_T Switch2_Threshold_a;        /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S127>/Switch2'
                                        */
  real32_T Switch2_Threshold_f;        /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S128>/Switch2'
                                        */
  real32_T Switch2_Threshold_j;        /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S129>/Switch2'
                                        */
  real32_T Constant1_Value_dr[3];      /* Computed Parameter: Constant1_Value_dr
                                        * Referenced by: '<S4>/Constant1'
                                        */
  uint32_T Rx_ID1_Value;               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S333>/Rx_ID1'
                                        */
  uint32_T Rx_ID2_Value;               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S333>/Rx_ID2'
                                        */
  uint32_T Rx_ID3_Value;               /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S333>/Rx_ID3'
                                        */
  uint32_T Rx_ID4_Value;               /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S333>/Rx_ID4'
                                        */
  uint32_T Rx_ID5_Value;               /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S333>/Rx_ID5'
                                        */
  uint32_T Rx_ID6_Value;               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S333>/Rx_ID6'
                                        */
  uint32_T RateTransition18_X0;        /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S337>/Rate Transition18'
                                        */
  uint16_T Constant1_Value_e[4];       /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S337>/Constant1'
                                        */
  int8_T Switch_Threshold_j;           /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S258>/Switch'
                                        */
  uint8_T enableall_Value[6];          /* Computed Parameter: enableall_Value
                                        * Referenced by: '<S316>/enable all'
                                        */
  uint8_T enable0_Value;               /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S316>/enable 0'
                                        */
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S370>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S368>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S369>/FixPt Constant'
                                        */
  uint8_T bmp085accuracylevel_Value;   /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S71>/bmp085 accuracy level'
                                        */
  uint8_T RateTransition_X0;           /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S337>/Rate Transition'
                                        */
  uint8_T RateTransition14_X0;         /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S337>/Rate Transition14'
                                        */
  uint8_T RateTransition15_X0;         /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S337>/Rate Transition15'
                                        */
  uint8_T gpsselector2_CurrentSetting; /* Computed Parameter: gpsselector2_CurrentSetting
                                        * Referenced by: '<S23>/gps selector 2'
                                        */
  uint8_T gpsselector1_CurrentSetting; /* Computed Parameter: gpsselector1_CurrentSetting
                                        * Referenced by: '<S23>/gps selector 1'
                                        */
  rtP_clocklatch_ICARO3_Onda_simple_v2_media_fun clocklatch_h;/* '<Root>/clock latch' */
  rtP_clocklatch_ICARO3_Onda_simple_v2_media_fun clocklatch_m;/* '<S246>/clock latch' */
  rtP_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_o;/* '<S129>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_l;/* '<S128>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_p;/* '<S123>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_simple_v2_media_fun Subsystem_g;/* '<S122>/Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ICARO3_Onda_simple_v2_media_fun {
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
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_ICARO3_Onda_simple_v2_media_fun
  ICARO3_Onda_simple_v2_media_fun_P;

/* Block signals (auto storage) */
extern BlockIO_ICARO3_Onda_simple_v2_media_fun ICARO3_Onda_simple_v2_media_fun_B;

/* Block states (auto storage) */
extern D_Work_ICARO3_Onda_simple_v2_media_fun
  ICARO3_Onda_simple_v2_media_fun_DWork;

/* External function called from main */
extern void ICARO3_Onda_simple_v2_media_fun_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void ICARO3_Onda_simple_v2_media_fun_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void ICARO3_Onda_simple_v2_media_fun_initialize(void);
extern void ICARO3_Onda_simple_v2_media_fun_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_ICARO3_Onda_simple_v2_media_fun *const
  ICARO3_Onda_simple_v2_media_fun_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Unused code path elimination
 * Block '<S2>/scale factor for resistor network - from mesarured R1 and R2' : Unused code path elimination
 * Block '<S117>/Add3' : Unused code path elimination
 * Block '<S117>/Discrete-Time Integrator3' : Unused code path elimination
 * Block '<S117>/Gain1' : Unused code path elimination
 * Block '<S117>/Scope6' : Unused code path elimination
 * Block '<S114>/Gain1' : Unused code path elimination
 * Block '<S114>/Scope3' : Unused code path elimination
 * Block '<S114>/Scope4' : Unused code path elimination
 * Block '<S114>/Scope5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion mx3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion14' : Unused code path elimination
 * Block '<Root>/Data Type Conversion15' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<S246>/Sum' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/ID CAR ' : Unused code path elimination
 * Block '<Root>/Rate Transition45' : Unused code path elimination
 * Block '<Root>/Rate Transition53' : Unused code path elimination
 * Block '<S65>/1 h in sec ' : Unused code path elimination
 * Block '<S65>/Asec to Ahour' : Unused code path elimination
 * Block '<S65>/Instantaneous Power' : Unused code path elimination
 * Block '<S65>/integrate current' : Unused code path elimination
 * Block '<S307>/Internal' : Unused code path elimination
 * Block '<S308>/Internal' : Unused code path elimination
 * Block '<S319>/Gain1' : Unused code path elimination
 * Block '<S319>/Gain2' : Unused code path elimination
 * Block '<S315>/Data Type Conversion mx5' : Unused code path elimination
 * Block '<S315>/Data Type Conversion1' : Unused code path elimination
 * Block '<S315>/Data Type Conversion2' : Unused code path elimination
 * Block '<S315>/Data Type Conversion4' : Unused code path elimination
 * Block '<S315>/Data Type Conversion5' : Unused code path elimination
 * Block '<S315>/Data Type Conversion6' : Unused code path elimination
 * Block '<S315>/Rate Transition' : Unused code path elimination
 * Block '<S315>/Switch2' : Unused code path elimination
 * Block '<S315>/scale factor correction (good for test_calib_2)' : Unused code path elimination
 * Block '<S327>/Bitwise Operator' : Unused code path elimination
 * Block '<S327>/Data Type Conversion mx1' : Unused code path elimination
 * Block '<S327>/Gain' : Unused code path elimination
 * Block '<S315>/use calibrated  data' : Unused code path elimination
 * Block '<S315>/use calibrated  data ' : Unused code path elimination
 * Block '<S71>/Rate Transition1' : Unused code path elimination
 * Block '<S71>/Rate Transition2' : Unused code path elimination
 * Block '<S71>/Rate Transition3' : Unused code path elimination
 * Block '<S71>/Rate Transition4' : Unused code path elimination
 * Block '<S71>/Rate Transition5' : Unused code path elimination
 * Block '<S71>/Rate Transition6' : Unused code path elimination
 * Block '<S316>/Data Type Conversion' : Unused code path elimination
 * Block '<S316>/Data Type Conversion2' : Unused code path elimination
 * Block '<S316>/Rate Transition11' : Unused code path elimination
 * Block '<S337>/Constant' : Unused code path elimination
 * Block '<S337>/Constant2' : Unused code path elimination
 * Block '<S337>/Data Type Conversion' : Unused code path elimination
 * Block '<S337>/Data Type Conversion1' : Unused code path elimination
 * Block '<S337>/Data Type Conversion2' : Unused code path elimination
 * Block '<S337>/Data Type Conversion3' : Unused code path elimination
 * Block '<S337>/Rate Transition1' : Unused code path elimination
 * Block '<S337>/Rate Transition2' : Unused code path elimination
 * Block '<S337>/Rate Transition3' : Unused code path elimination
 * Block '<S337>/Rate Transition4' : Unused code path elimination
 * Block '<S337>/fake gps received signal' : Unused code path elimination
 * Block '<S316>/downsample to 100 Hz11' : Unused code path elimination
 * Block '<S316>/downsample to 100 Hz4' : Unused code path elimination
 * Block '<S316>/downsample to 100 Hz5' : Unused code path elimination
 * Block '<S316>/downsample to 100 Hz6' : Unused code path elimination
 * Block '<S316>/downsample to 100 Hz8' : Unused code path elimination
 * Block '<S316>/enable all1' : Unused code path elimination
 * Block '<S316>/enable all2' : Unused code path elimination
 * Block '<S316>/enable all3' : Unused code path elimination
 * Block '<S368>/Data Type Propagation' : Unused code path elimination
 * Block '<S369>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S370>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S361>/Constant' : Unused code path elimination
 * Block '<S361>/Data Type Conversion2' : Unused code path elimination
 * Block '<S361>/Gain' : Unused code path elimination
 * Block '<S361>/Sum' : Unused code path elimination
 * Block '<S362>/Constant' : Unused code path elimination
 * Block '<S362>/Data Type Conversion2' : Unused code path elimination
 * Block '<S362>/Gain' : Unused code path elimination
 * Block '<S362>/Sum' : Unused code path elimination
 * Block '<S363>/Constant' : Unused code path elimination
 * Block '<S363>/Data Type Conversion2' : Unused code path elimination
 * Block '<S363>/Gain' : Unused code path elimination
 * Block '<S363>/Sum' : Unused code path elimination
 * Block '<S364>/Constant' : Unused code path elimination
 * Block '<S364>/Data Type Conversion2' : Unused code path elimination
 * Block '<S364>/Gain' : Unused code path elimination
 * Block '<S364>/Sum' : Unused code path elimination
 * Block '<S365>/Constant' : Unused code path elimination
 * Block '<S365>/Data Type Conversion2' : Unused code path elimination
 * Block '<S365>/Gain' : Unused code path elimination
 * Block '<S365>/Sum' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S117>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S114>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S114>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S4>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion25' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion26' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition44' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition50' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition51' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition57' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition58' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition16' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition17' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S316>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S337>/Rate Transition19' : Eliminated since input and output rates are identical
 * Block '<S337>/Rate Transition20' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz1' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz10' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz2' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz7' : Eliminated since input and output rates are identical
 * Block '<S316>/downsample to 100 Hz9' : Eliminated since input and output rates are identical
 * Block '<S357>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'ICARO3_Onda_simple_v2_media_fun'
 * '<S1>'   : 'ICARO3_Onda_simple_v2_media_fun/ generatore di riferimenti'
 * '<S2>'   : 'ICARO3_Onda_simple_v2_media_fun/ADC1'
 * '<S3>'   : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1'
 * '<S4>'   : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2'
 * '<S5>'   : 'ICARO3_Onda_simple_v2_media_fun/Band-Limited White Noise'
 * '<S6>'   : 'ICARO3_Onda_simple_v2_media_fun/Compare To Constant'
 * '<S7>'   : 'ICARO3_Onda_simple_v2_media_fun/Compare To Constant1'
 * '<S8>'   : 'ICARO3_Onda_simple_v2_media_fun/Compare To Constant2'
 * '<S9>'   : 'ICARO3_Onda_simple_v2_media_fun/Compare To Constant3'
 * '<S10>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc'
 * '<S11>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc1'
 * '<S12>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc2'
 * '<S13>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc3'
 * '<S14>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc4'
 * '<S15>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc5'
 * '<S16>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc6'
 * '<S17>'  : 'ICARO3_Onda_simple_v2_media_fun/Compensate for sensor mount _acc7'
 * '<S18>'  : 'ICARO3_Onda_simple_v2_media_fun/Control '
 * '<S19>'  : 'ICARO3_Onda_simple_v2_media_fun/Controllo'
 * '<S20>'  : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem'
 * '<S21>'  : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem1'
 * '<S22>'  : 'ICARO3_Onda_simple_v2_media_fun/GET PPS'
 * '<S23>'  : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver'
 * '<S24>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function'
 * '<S25>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function1'
 * '<S26>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function2'
 * '<S27>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function3'
 * '<S28>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function4'
 * '<S29>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function5'
 * '<S30>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function6'
 * '<S31>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function7'
 * '<S32>'  : 'ICARO3_Onda_simple_v2_media_fun/MATLAB Function8'
 * '<S33>'  : 'ICARO3_Onda_simple_v2_media_fun/PI Controller'
 * '<S34>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_1joint '
 * '<S35>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_1joint 1'
 * '<S36>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_2joint'
 * '<S37>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_2joint1'
 * '<S38>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_3joint '
 * '<S39>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_3joint 1'
 * '<S40>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_4joint '
 * '<S41>'  : 'ICARO3_Onda_simple_v2_media_fun/PID_4joint 1'
 * '<S42>'  : 'ICARO3_Onda_simple_v2_media_fun/Posca_Zocco Steer Map '
 * '<S43>'  : 'ICARO3_Onda_simple_v2_media_fun/Prescaler'
 * '<S44>'  : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS'
 * '<S45>'  : 'ICARO3_Onda_simple_v2_media_fun/Scheme Running'
 * '<S46>'  : 'ICARO3_Onda_simple_v2_media_fun/Secondo_giunto'
 * '<S47>'  : 'ICARO3_Onda_simple_v2_media_fun/Signal Builder'
 * '<S48>'  : 'ICARO3_Onda_simple_v2_media_fun/Signal Builder1'
 * '<S49>'  : 'ICARO3_Onda_simple_v2_media_fun/Signal Builder2'
 * '<S50>'  : 'ICARO3_Onda_simple_v2_media_fun/Tabella_trasformazioni1'
 * '<S51>'  : 'ICARO3_Onda_simple_v2_media_fun/Tabella_trasformazioni2'
 * '<S52>'  : 'ICARO3_Onda_simple_v2_media_fun/Tabella_trasformazioni3'
 * '<S53>'  : 'ICARO3_Onda_simple_v2_media_fun/Tabella_trasformazioni4'
 * '<S54>'  : 'ICARO3_Onda_simple_v2_media_fun/blocco motori se non arrivano pacchetti'
 * '<S55>'  : 'ICARO3_Onda_simple_v2_media_fun/clock latch'
 * '<S56>'  : 'ICARO3_Onda_simple_v2_media_fun/configurazione relativa seeker//target'
 * '<S57>'  : 'ICARO3_Onda_simple_v2_media_fun/data conversion'
 * '<S58>'  : 'ICARO3_Onda_simple_v2_media_fun/data conversion1'
 * '<S59>'  : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST'
 * '<S60>'  : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST1'
 * '<S61>'  : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry STATIC TEST'
 * '<S62>'  : 'ICARO3_Onda_simple_v2_media_fun/debug_telemetry_minimal'
 * '<S63>'  : 'ICARO3_Onda_simple_v2_media_fun/fkine1'
 * '<S64>'  : 'ICARO3_Onda_simple_v2_media_fun/latch1'
 * '<S65>'  : 'ICARO3_Onda_simple_v2_media_fun/power computations1'
 * '<S66>'  : 'ICARO3_Onda_simple_v2_media_fun/pwm & pi cmds'
 * '<S67>'  : 'ICARO3_Onda_simple_v2_media_fun/quarto_giunto'
 * '<S68>'  : 'ICARO3_Onda_simple_v2_media_fun/re-construct pwm signals'
 * '<S69>'  : 'ICARO3_Onda_simple_v2_media_fun/re-construct pwm signals1'
 * '<S70>'  : 'ICARO3_Onda_simple_v2_media_fun/send gps to bs'
 * '<S71>'  : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface'
 * '<S72>'  : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1'
 * '<S73>'  : 'ICARO3_Onda_simple_v2_media_fun/ generatore di riferimenti/fcn'
 * '<S74>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/Attitude Filter ADIS'
 * '<S75>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS'
 * '<S76>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1'
 * '<S77>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S78>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S79>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend '
 * '<S80>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend'
 * '<S81>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend'
 * '<S82>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S83>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S84>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S85>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S86>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S87>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend'
 * '<S88>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1'
 * '<S89>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2'
 * '<S90>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S91>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S92>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S93>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend '
 * '<S94>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1'
 * '<S95>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend'
 * '<S96>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend'
 * '<S97>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend1'
 * '<S98>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend3'
 * '<S99>'  : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend/Subsystem'
 * '<S100>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend1/Subsystem'
 * '<S101>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend /Detrend3/Subsystem'
 * '<S102>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend'
 * '<S103>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend1'
 * '<S104>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend3'
 * '<S105>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend/Subsystem'
 * '<S106>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend1/Subsystem'
 * '<S107>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Acceleration Detrend 1/Detrend3/Subsystem'
 * '<S108>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend'
 * '<S109>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend1'
 * '<S110>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend2'
 * '<S111>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend/Subsystem'
 * '<S112>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend1/Subsystem'
 * '<S113>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS1/debias ADIS1/Gyros Detrend/Detrend2/Subsystem'
 * '<S114>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/Attitude Filter ADIS'
 * '<S115>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS'
 * '<S116>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1'
 * '<S117>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S118>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S119>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend '
 * '<S120>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend'
 * '<S121>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend'
 * '<S122>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S123>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S124>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S125>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S126>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S127>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend'
 * '<S128>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1'
 * '<S129>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2'
 * '<S130>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S131>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S132>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S133>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend '
 * '<S134>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1'
 * '<S135>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend'
 * '<S136>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend'
 * '<S137>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1'
 * '<S138>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3'
 * '<S139>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend/Subsystem'
 * '<S140>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1/Subsystem'
 * '<S141>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3/Subsystem'
 * '<S142>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend'
 * '<S143>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1'
 * '<S144>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3'
 * '<S145>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend/Subsystem'
 * '<S146>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1/Subsystem'
 * '<S147>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3/Subsystem'
 * '<S148>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend'
 * '<S149>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1'
 * '<S150>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2'
 * '<S151>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend/Subsystem'
 * '<S152>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1/Subsystem'
 * '<S153>' : 'ICARO3_Onda_simple_v2_media_fun/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2/Subsystem'
 * '<S154>' : 'ICARO3_Onda_simple_v2_media_fun/Control /+pi-pi_remapping'
 * '<S155>' : 'ICARO3_Onda_simple_v2_media_fun/Control /VectorNorm'
 * '<S156>' : 'ICARO3_Onda_simple_v2_media_fun/Control /atan2'
 * '<S157>' : 'ICARO3_Onda_simple_v2_media_fun/Control /steer_control'
 * '<S158>' : 'ICARO3_Onda_simple_v2_media_fun/Control /throttle_control '
 * '<S159>' : 'ICARO3_Onda_simple_v2_media_fun/Control /steer_control/Control Manager'
 * '<S160>' : 'ICARO3_Onda_simple_v2_media_fun/Control /throttle_control /Control Manager'
 * '<S161>' : 'ICARO3_Onda_simple_v2_media_fun/Control /throttle_control /MATLAB Function'
 * '<S162>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control '
 * '<S163>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface'
 * '<S164>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /+pi-pi_remapping'
 * '<S165>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /VectorNorm'
 * '<S166>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /atan2'
 * '<S167>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /steer_control'
 * '<S168>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /throttle_control '
 * '<S169>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /steer_control/Control Manager'
 * '<S170>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /throttle_control /Control Manager'
 * '<S171>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/Control /throttle_control /MATLAB Function'
 * '<S172>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing'
 * '<S173>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager'
 * '<S174>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compensate for sensor mount _acc'
 * '<S175>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compensate for sensor mount _gyro'
 * '<S176>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S177>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function'
 * '<S178>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute accxyz'
 * '<S179>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute accxyz1'
 * '<S180>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute gyroxyz'
 * '<S181>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute magxyz'
 * '<S182>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/MATLAB Function compute magxyz2'
 * '<S183>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/compute_parameters'
 * '<S184>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/spi_data_processing'
 * '<S185>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S186>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S187>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/compute_parameters/MATLAB Function1'
 * '<S188>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S189>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Arrange pwms'
 * '<S190>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX'
 * '<S191>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/I2C1 sensors loop'
 * '<S192>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Subsystem1'
 * '<S193>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Subsystem2'
 * '<S194>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus'
 * '<S195>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus'
 * '<S196>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/Arrange pwms/clock latch'
 * '<S197>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1'
 * '<S198>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2'
 * '<S199>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3'
 * '<S200>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S201>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S202>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S203>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S204>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S205>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S206>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S207>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S208>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S209>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S210>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/H'
 * '<S211>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S212>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S213>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S214>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S215>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S216>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S217>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S218>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S219>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S220>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S221>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S222>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S223>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S224>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S225>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S226>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S227>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S228>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S229>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S230>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S231>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S232>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S233>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S234>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S235>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S236>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S237>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S238>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 * '<S239>' : 'ICARO3_Onda_simple_v2_media_fun/Enabled and Triggered Subsystem1/data conversion'
 * '<S240>' : 'ICARO3_Onda_simple_v2_media_fun/GET PPS/clock latch'
 * '<S241>' : 'ICARO3_Onda_simple_v2_media_fun/GET PPS/step 2 pulse'
 * '<S242>' : 'ICARO3_Onda_simple_v2_media_fun/GET PPS/uint16 to vector'
 * '<S243>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS'
 * '<S244>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/VENUS GPS'
 * '<S245>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/compute 3d age'
 * '<S246>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/compute age'
 * '<S247>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA'
 * '<S248>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/MAP ublox fix type to standard status'
 * '<S249>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Angle Conversion1'
 * '<S250>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem2'
 * '<S251>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem3'
 * '<S252>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem'
 * '<S253>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^1'
 * '<S254>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^2'
 * '<S255>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^3'
 * '<S256>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem2'
 * '<S257>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem3'
 * '<S258>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem4'
 * '<S259>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/compute 3d age/Compare To Constant'
 * '<S260>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/compute 3d age/clock latch'
 * '<S261>' : 'ICARO3_Onda_simple_v2_media_fun/GPS receiver/compute age/clock latch'
 * '<S262>' : 'ICARO3_Onda_simple_v2_media_fun/Prescaler/find send time'
 * '<S263>' : 'ICARO3_Onda_simple_v2_media_fun/Prescaler/latch'
 * '<S264>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/Attitude Filter SS'
 * '<S265>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS'
 * '<S266>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT'
 * '<S267>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT/dcm_marg'
 * '<S268>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend '
 * '<S269>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend'
 * '<S270>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend'
 * '<S271>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend1'
 * '<S272>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend3'
 * '<S273>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend/Subsystem'
 * '<S274>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S275>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S276>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend'
 * '<S277>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend1'
 * '<S278>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend2'
 * '<S279>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend/Subsystem'
 * '<S280>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend1/Subsystem'
 * '<S281>' : 'ICARO3_Onda_simple_v2_media_fun/SS AHRS/debias SS/Gyros Detrend/Detrend2/Subsystem'
 * '<S282>' : 'ICARO3_Onda_simple_v2_media_fun/blocco motori se non arrivano pacchetti/Enabled Subsystem'
 * '<S283>' : 'ICARO3_Onda_simple_v2_media_fun/configurazione relativa seeker//target/engagement'
 * '<S284>' : 'ICARO3_Onda_simple_v2_media_fun/configurazione relativa seeker//target/engagement 2'
 * '<S285>' : 'ICARO3_Onda_simple_v2_media_fun/configurazione relativa seeker//target/pure PNG '
 * '<S286>' : 'ICARO3_Onda_simple_v2_media_fun/configurazione relativa seeker//target/engagement/Fading filter del II ordine'
 * '<S287>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/ADC_filt'
 * '<S288>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/ADC_raw'
 * '<S289>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/Ages'
 * '<S290>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/GPS'
 * '<S291>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/GPS ECEF'
 * '<S292>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/MATLAB Function2'
 * '<S293>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S294>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/Raw IMU data MPU + HMC + ADC'
 * '<S295>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/Raw IMU data MPU only + ADC'
 * '<S296>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/Raw IMU data packer'
 * '<S297>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/To be used for ADAPT NN online tuning'
 * '<S298>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/To be used for H PID online tuning'
 * '<S299>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/join enable flags'
 * '<S300>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/recupero di mpu9150 data'
 * '<S301>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/test solo RC_all_channel_usec + RSSI + ....'
 * '<S302>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST/GPS/detect if was 1 in the last 10 samples'
 * '<S303>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry FLIGHT TEST1/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S304>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry STATIC TEST/Raw IMU data packer: MPU + MAG_HMC'
 * '<S305>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry STATIC TEST/Subsystem'
 * '<S306>' : 'ICARO3_Onda_simple_v2_media_fun/debug telemtry STATIC TEST/join enable flags'
 * '<S307>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter'
 * '<S308>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter1'
 * '<S309>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter/IO Delay'
 * '<S310>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter/Input Delay'
 * '<S311>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter/Output Delay'
 * '<S312>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter1/IO Delay'
 * '<S313>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter1/Input Delay'
 * '<S314>' : 'ICARO3_Onda_simple_v2_media_fun/power computations1/low pass filter1/Output Delay'
 * '<S315>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing'
 * '<S316>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager'
 * '<S317>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/Compensate for sensor mount _acc'
 * '<S318>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/Compensate for sensor mount _gyro'
 * '<S319>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S320>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function'
 * '<S321>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function compute accxyz'
 * '<S322>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function compute accxyz1'
 * '<S323>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function compute gyroxyz'
 * '<S324>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function compute magxyz'
 * '<S325>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/MATLAB Function compute magxyz2'
 * '<S326>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/compute_parameters'
 * '<S327>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/spi_data_processing'
 * '<S328>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S329>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S330>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/compute_parameters/MATLAB Function1'
 * '<S331>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S332>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/Arrange pwms'
 * '<S333>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX'
 * '<S334>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/I2C1 sensors loop'
 * '<S335>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/Subsystem1'
 * '<S336>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/Subsystem2'
 * '<S337>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/compose data from canbus'
 * '<S338>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus'
 * '<S339>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/Arrange pwms/clock latch'
 * '<S340>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1'
 * '<S341>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2'
 * '<S342>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3'
 * '<S343>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S344>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S345>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S346>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S347>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S348>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S349>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S350>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S351>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S352>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S353>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/compose data from canbus/H'
 * '<S354>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S355>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S356>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S357>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair'
 * '<S358>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S359>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S360>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S361>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S362>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S363>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S364>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S365>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S366>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S367>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S368>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter'
 * '<S369>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S370>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S371>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S372>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S373>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S374>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S375>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S376>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S377>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S378>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S379>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S380>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S381>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S382>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S383>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S384>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S385>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 * '<S386>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing'
 * '<S387>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager'
 * '<S388>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/Compensate for sensor mount _acc'
 * '<S389>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/Compensate for sensor mount _gyro'
 * '<S390>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S391>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function'
 * '<S392>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function compute accxyz'
 * '<S393>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function compute accxyz1'
 * '<S394>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function compute gyroxyz'
 * '<S395>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function compute magxyz'
 * '<S396>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/MATLAB Function compute magxyz2'
 * '<S397>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/compute_parameters'
 * '<S398>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/spi_data_processing'
 * '<S399>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S400>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S401>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/compute_parameters/MATLAB Function1'
 * '<S402>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S403>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/Arrange pwms'
 * '<S404>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX'
 * '<S405>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/I2C1 sensors loop'
 * '<S406>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/Subsystem1'
 * '<S407>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/Subsystem2'
 * '<S408>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/compose data from canbus'
 * '<S409>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus'
 * '<S410>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/Arrange pwms/clock latch'
 * '<S411>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1'
 * '<S412>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2'
 * '<S413>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3'
 * '<S414>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S415>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S416>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S417>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S418>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S419>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S420>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S421>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S422>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S423>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S424>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/compose data from canbus/H'
 * '<S425>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S426>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S427>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S428>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S429>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S430>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S431>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S432>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S433>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S434>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S435>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S436>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S437>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S438>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S439>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S440>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S441>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S442>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S443>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S444>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S445>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S446>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S447>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S448>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S449>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S450>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S451>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S452>' : 'ICARO3_Onda_simple_v2_media_fun/sensor and actuators interface1/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 */
#endif                                 /* RTW_HEADER_ICARO3_Onda_simple_v2_media_fun_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_simple_v2_media_fun.h
 */
