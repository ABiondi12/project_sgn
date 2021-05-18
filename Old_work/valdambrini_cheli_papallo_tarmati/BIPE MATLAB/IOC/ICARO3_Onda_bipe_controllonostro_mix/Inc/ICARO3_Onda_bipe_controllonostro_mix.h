/*
 * File: ICARO3_Onda_bipe_controllonostro_mix.h
 *
 * Code generated for Simulink model :ICARO3_Onda_bipe_controllonostro_mix.
 *
 * Model version      : 1.1519
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Jan 21 16:39:05 2020
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

#ifndef RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_h_
#define RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_h_
#include <math.h>
#include <string.h>
#include "ICARO3_Onda_bipe_controllonostro_mix_STM32.h"
#ifndef ICARO3_Onda_bipe_controllonostro_mix_COMMON_INCLUDES_
# define ICARO3_Onda_bipe_controllonostro_mix_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ICARO3_Onda_bipe_controllonostro_mix_COMMON_INCLUDES_ */

#include "ICARO3_Onda_bipe_controllonostro_mix_types.h"
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

/* Block signals for system '<S35>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S38>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S38>/Discrete-Time Integrator1' */
  real_T Product1;                     /* '<S38>/Product1' */
} rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix;

/* Block states (auto storage) for system '<S35>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S38>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S38>/Discrete-Time Integrator1' */
} rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix;

/* Block signals for system '<S80>/clock latch' */
typedef struct {
  real_T In;                           /* '<S95>/In' */
} rtB_clocklatch_ICARO3_Onda_bipe_controllonostro_mix;

/* Block signals for system '<S174>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint16_T y;                          /* '<S174>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost;

/* Block signals for system '<S175>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint32_T y;                          /* '<S175>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_f;

/* Block signals for system '<S194>/MATLAB Function compute gyroxyz1' */
typedef struct {
  uint8_T y[2];                        /* '<S194>/MATLAB Function compute gyroxyz1' */
} rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j;

/* Block signals for system '<S194>/MATLAB Function compute gyroxyz4' */
typedef struct {
  uint8_T TmpSignalConversionAtSFunctionInport1[8];/* '<S194>/MATLAB Function compute gyroxyz4' */
  uint8_T y[8];                        /* '<S194>/MATLAB Function compute gyroxyz4' */
} rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost;

/* Block signals (auto storage) */
typedef struct {
  real_T Step;                         /* '<S28>/Step' */
  real_T Step1;                        /* '<S28>/Step1' */
  real_T Add;                          /* '<S28>/Add' */
  real_T DataTypeConversion7[3];       /* '<S149>/Data Type Conversion7' */
  real_T Gain1[3];                     /* '<Root>/Gain1' */
  real_T Switch2;                      /* '<S34>/Switch2' */
  real_T Switch2_p;                    /* '<S35>/Switch2' */
  real_T Switch2_d;                    /* '<S36>/Switch2' */
  real_T DataTypeConversion9[3];       /* '<S149>/Data Type Conversion9' */
  real_T Switch2_o;                    /* '<S40>/Switch2' */
  real_T Switch2_pz;                   /* '<S41>/Switch2' */
  real_T Switch2_n;                    /* '<S42>/Switch2' */
  real_T DataTypeConversionmx10[3];    /* '<S3>/Data Type Conversion mx10' */
  real_T RateTransition46;             /* '<Root>/Rate Transition46' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T RateTransition54[3];          /* '<Root>/Rate Transition54' */
  real_T RateTransition53[3];          /* '<Root>/Rate Transition53' */
  real_T RateTransition52[3];          /* '<Root>/Rate Transition52' */
  real_T SFunctionUSART3_Receive4_o1[13];/* '<Root>/S-Function-USART3_Receive4' */
  real_T SFunctionUSART3_Receive4_o2;  /* '<Root>/S-Function-USART3_Receive4' */
  real_T DataTypeConversionmx17[3];    /* '<S3>/Data Type Conversion mx17' */
  real_T RateTransition55[3];          /* '<Root>/Rate Transition55' */
  real_T DataTypeConversion1[3];       /* '<S6>/Data Type Conversion1' */
  real_T DataTypeConversion2[3];       /* '<S6>/Data Type Conversion2' */
  real_T relativevector[3];            /* '<S6>/Sum2' */
  real_T Gain[2];                      /* '<S6>/Gain' */
  real_T DataTypeConversion3;          /* '<S6>/Data Type Conversion3' */
  real_T Switch1;                      /* '<S69>/Switch1' */
  real_T Saturation;                   /* '<S69>/Saturation' */
  real_T Sum1;                         /* '<S69>/Sum1' */
  real_T Memory1;                      /* '<S70>/Memory1' */
  real_T Gain1_c;                      /* '<S70>/Gain1' */
  real_T Switch1_i;                    /* '<S70>/Switch1' */
  real_T Saturation1;                  /* '<S70>/Saturation1' */
  real_T Sum1_a;                       /* '<S70>/Sum1' */
  real_T RateTransition47;             /* '<Root>/Rate Transition47' */
  real_T RateTransition48;             /* '<Root>/Rate Transition48' */
  real_T TmpSignalConversionAtreproducePWM9Inport1[4];
  real_T DataTypeConversion16;         /* '<Root>/Data Type Conversion16' */
  real_T DataTypeConversion19;         /* '<Root>/Data Type Conversion19' */
  real_T DigitalClock1;                /* '<Root>/Digital Clock1' */
  real_T DataTypeConversion3_a[3];     /* '<S149>/Data Type Conversion3' */
  real_T downsampleto100Hz3[4];        /* '<S150>/downsample to 100 Hz3' */
  real_T Gain_i;                       /* '<S170>/Gain' */
  real_T Sum;                          /* '<S170>/Sum' */
  real_T DigitalClock;                 /* '<S79>/Digital Clock' */
  real_T SFunction3_o1[7];             /* '<S77>/S-Function3' */
  real_T SFunction3_o2;                /* '<S77>/S-Function3' */
  real_T gpsselector2;                 /* '<S8>/gps selector 2' */
  real_T Product2;                     /* '<S84>/Product2' */
  real_T Product3;                     /* '<S84>/Product3' */
  real_T Sum2;                         /* '<S84>/Sum2' */
  real_T sqrt_p;                       /* '<S84>/sqrt' */
  real_T Sum1_n;                       /* '<S88>/Sum1' */
  real_T Product1;                     /* '<S81>/Product1' */
  real_T Product2_k;                   /* '<S89>/Product2' */
  real_T Sum1_b;                       /* '<S89>/Sum1' */
  real_T Sum1_d;                       /* '<S87>/Sum1' */
  real_T Product2_a;                   /* '<S87>/Product2' */
  real_T TrigonometricFunction2;       /* '<S81>/Trigonometric Function2' */
  real_T UnitConversion[2];            /* '<S83>/Unit Conversion' */
  real_T sincos_o1;                    /* '<S85>/sincos' */
  real_T sincos_o2;                    /* '<S85>/sincos' */
  real_T Product2_o;                   /* '<S85>/Product2' */
  real_T Product1_h;                   /* '<S85>/Product1' */
  real_T Sum_b;                        /* '<S85>/Sum' */
  real_T sqrt_i;                       /* '<S85>/sqrt' */
  real_T Product3_l;                   /* '<S85>/Product3' */
  real_T Product4;                     /* '<S85>/Product4' */
  real_T Sum2_k;                       /* '<S85>/Sum2' */
  real_T Product5;                     /* '<S85>/Product5' */
  real_T Product6;                     /* '<S85>/Product6' */
  real_T Sum3;                         /* '<S85>/Sum3' */
  real_T gpsselector1[16];             /* '<S8>/gps selector 1' */
  real_T Product;                      /* '<S8>/Product' */
  real_T Sum_f;                        /* '<S79>/Sum' */
  real_T Gain_g;                       /* '<S169>/Gain' */
  real_T Sum_e;                        /* '<S169>/Sum' */
  real_T DigitalClock_k;               /* '<Root>/Digital Clock' */
  real_T DigitalClock_p;               /* '<S80>/Digital Clock' */
  real_T PulseGenerator1;              /* '<S13>/Pulse Generator1' */
  real_T PulseGenerator;               /* '<S172>/Pulse Generator' */
  real_T Output;                       /* '<S191>/Output' */
  real_T Gain_m;                       /* '<S192>/Gain' */
  real_T Sum_i;                        /* '<S192>/Sum' */
  real_T Gain_k[3];                    /* '<S193>/Gain' */
  real_T Sum_c[3];                     /* '<S193>/Sum' */
  real_T TmpSignalConversionAtSFunctionInport1[12];/* '<S149>/MATLAB Function compute magxyz2' */
  real_T RC_TRPY_refs[4];              /* '<S149>/MATLAB Function compute magxyz2' */
  real_T RC_aux_channels[8];           /* '<S149>/MATLAB Function compute magxyz2' */
  real_T h_calib[3];                   /* '<S149>/MATLAB Function' */
  real_T In;                           /* '<S94>/In' */
  real_T y;                            /* '<S77>/MAP ublox fix type to standard status' */
  real_T Memory;                       /* '<S92>/Memory' */
  real_T Switch;                       /* '<S92>/Switch' */
  real_T sincos_o1_c;                  /* '<S90>/sincos' */
  real_T sincos_o2_e;                  /* '<S90>/sincos' */
  real_T Product3_m;                   /* '<S90>/Product3' */
  real_T Sum2_c;                       /* '<S90>/Sum2' */
  real_T Product4_e;                   /* '<S90>/Product4' */
  real_T Sum1_j;                       /* '<S90>/Sum1' */
  real_T TrigonometricFunction4;       /* '<S90>/Trigonometric Function4' */
  real_T sincos_o1_b;                  /* '<S91>/sincos' */
  real_T sincos_o2_l;                  /* '<S91>/sincos' */
  real_T Product3_o;                   /* '<S91>/Product3' */
  real_T TrigonometricFunction4_o;     /* '<S91>/Trigonometric Function4' */
  real_T Product2_k2;                  /* '<S92>/Product2' */
  real_T TrigonometricFunction3;       /* '<S92>/Trigonometric Function3' */
  real_T control;                      /* '<S70>/MATLAB Function' */
  real_T go;                           /* '<S70>/Control Manager' */
  real_T go_i;                         /* '<S69>/Control Manager' */
  real_T Sum3_d;                       /* '<S6>/Sum3' */
  real_T Gain1_m;                      /* '<S69>/Gain1' */
  real_T theta;                        /* '<S6>/atan2' */
  real_T y_o;                          /* '<S6>/VectorNorm' */
  real_T Sum1_k;                       /* '<S42>/Sum1' */
  real_T Sum1_f;                       /* '<S41>/Sum1' */
  real_T DiscreteTimeIntegrator;       /* '<S43>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S43>/Discrete-Time Integrator1' */
  real_T Product1_d;                   /* '<S43>/Product1' */
  real_T Sum1_km;                      /* '<S40>/Sum1' */
  real_T Sum1_d4;                      /* '<S36>/Sum1' */
  real_T Sum1_g;                       /* '<S35>/Sum1' */
  real_T DiscreteTimeIntegrator_p;     /* '<S37>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_p;    /* '<S37>/Discrete-Time Integrator1' */
  real_T Product1_f;                   /* '<S37>/Product1' */
  real_T Sum1_dm;                      /* '<S34>/Sum1' */
  real32_T DataTypeConversionmx8;      /* '<S28>/Data Type Conversion mx8' */
  real32_T DataTypeConversionmx1[3];   /* '<S3>/Data Type Conversion mx1' */
  real32_T RateTransition49[3];        /* '<Root>/Rate Transition49' */
  real32_T DataTypeConversionmx2[3];   /* '<S3>/Data Type Conversion mx2' */
  real32_T DataTypeConversion3_d;      /* '<Root>/Data Type Conversion3' */
  real32_T DataTypeConversion2_o;      /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion1_e[3];   /* '<Root>/Data Type Conversion1' */
  real32_T DataTypeConversion27[3];    /* '<Root>/Data Type Conversion27' */
  real32_T DataTypeConversion26[3];    /* '<Root>/Data Type Conversion26' */
  real32_T DataTypeConversion18[13];   /* '<Root>/Data Type Conversion18' */
  real32_T RateTransition51[3];        /* '<Root>/Rate Transition51' */
  real32_T RateTransition50[3];        /* '<Root>/Rate Transition50' */
  real32_T RateTransition56[3];        /* '<Root>/Rate Transition56' */
  real32_T DataTypeConversion24[3];    /* '<Root>/Data Type Conversion24' */
  real32_T RateTransition4[3];         /* '<Root>/Rate Transition4' */
  real32_T RateTransition6[3];         /* '<Root>/Rate Transition6' */
  real32_T DataTypeConversion5;        /* '<S6>/Data Type Conversion5' */
  real32_T RateTransition12;           /* '<Root>/Rate Transition12' */
  real32_T DataTypeConversion4;        /* '<S6>/Data Type Conversion4' */
  real32_T RateTransition7;            /* '<Root>/Rate Transition7' */
  real32_T TmpSignalConversionAtSavedatatodataloggerthemicroSDcard2Inport1[30];
  real32_T headingdirection[3];        /* '<Root>/Sum12' */
  real32_T DataTypeConversionmx3;      /* '<S25>/Data Type Conversion mx3' */
  real32_T RateTransition2[11];        /* '<S149>/Rate Transition2' */
  real32_T y_g;                        /* '<S171>/typecast uin32 to single1' */
  real32_T y_b;                        /* '<S171>/typecast uin32 to single' */
  real32_T y_b1;                       /* '<S187>/typecast uin32 to single' */
  real32_T a[3];                       /* '<S161>/MATLAB Function compute magxyz1' */
  real32_T w[3];                       /* '<S161>/MATLAB Function compute magxyz1' */
  real32_T params[11];                 /* '<S160>/MATLAB Function1' */
  real32_T m[3];                       /* '<S149>/MATLAB Function compute magxyz' */
  real32_T w_j[3];                     /* '<S149>/MATLAB Function compute gyroxyz' */
  real32_T a_g[3];                     /* '<S149>/MATLAB Function compute accxyz1' */
  real32_T t;                          /* '<S149>/MATLAB Function compute accxyz1' */
  real32_T g[3];                       /* '<S149>/MATLAB Function compute accxyz1' */
  real32_T a_j[3];                     /* '<S149>/MATLAB Function compute accxyz' */
  real32_T DataTypeConversion1_i;      /* '<S153>/Data Type Conversion1' */
  real32_T DataTypeConversion3_g;      /* '<S153>/Data Type Conversion3' */
  real32_T T;                          /* '<S153>/MATLAB Function' */
  real32_T h;                          /* '<S153>/MATLAB Function' */
  real32_T y_be[3];                    /* '<S149>/Compensate for sensor mount _gyro' */
  real32_T y_gr[3];                    /* '<S149>/Compensate for sensor mount _acc' */
  real32_T y_j[3];                     /* '<Root>/Compensate for sensor mount _acc1' */
  real32_T y_k[3];                     /* '<Root>/Compensate for sensor mount _acc' */
  real32_T UnitDelay1[4];              /* '<S30>/Unit Delay1' */
  real32_T UnitDelay2[3];              /* '<S30>/Unit Delay2' */
  real32_T UnitDelay3[3];              /* '<S30>/Unit Delay3' */
  real32_T Sum_h[3];                   /* '<S27>/Sum' */
  real32_T euler_out[3];               /* '<S30>/dcm_marg' */
  real32_T a_ned[3];                   /* '<S30>/dcm_marg' */
  real32_T q_out[4];                   /* '<S30>/dcm_marg' */
  real32_T e_int_out_a[3];             /* '<S30>/dcm_marg' */
  real32_T e_int_out_m[3];             /* '<S30>/dcm_marg' */
  real32_T biases[3];                  /* '<S30>/dcm_marg' */
  real32_T e_m[3];                     /* '<S30>/dcm_marg' */
  uint32_T PWM1[4];                    /* '<S2>/PWM1' */
  uint32_T DataTypeConversion8;        /* '<S187>/Data Type Conversion8' */
  uint32_T u;                          /* '<S187>/ ' */
  uint32_T DataTypeConversion9_d;      /* '<S187>/Data Type Conversion9' */
  uint32_T u_o;                        /* '<S187>/  ' */
  uint32_T DataTypeConversion7_c;      /* '<S187>/Data Type Conversion7' */
  uint32_T u_i;                        /* '<S187>/  2' */
  uint32_T DataTypeConversion10;       /* '<S187>/Data Type Conversion10' */
  uint32_T Sum12;                      /* '<S187>/Sum12' */
  uint32_T RateTransition18[2];        /* '<S171>/Rate Transition18' */
  uint32_T DataTypeConversiononi2cmag1[8];/* '<S175>/Data Type Conversion on i2c mag1' */
  uint32_T DataTypeConversion5_l[3];   /* '<S153>/Data Type Conversion5' */
  uint32_T UP;                         /* '<S153>/MATLAB Function1' */
  uint16_T I2C1SensorsLoop_o2;         /* '<S168>/I2C1 Sensors Loop' */
  uint16_T DataTypeConversiononi2cmag3[14];/* '<S149>/Data Type Conversion on i2c mag3' */
  uint16_T DataTypeConversion[22];     /* '<S160>/Data Type Conversion' */
  uint16_T DataTypeConversiononi2cmag[6];/* '<S149>/Data Type Conversion on i2c mag' */
  uint16_T DataTypeConversiononi2cmag1_c[6];/* '<S149>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag2[6];/* '<S149>/Data Type Conversion on i2c mag2' */
  uint16_T RateTransition18_g[7];      /* '<S149>/Rate Transition18' */
  uint16_T BitwiseOperator1;           /* '<S161>/Bitwise Operator1' */
  uint16_T BitwiseOperator2;           /* '<S161>/Bitwise Operator2' */
  uint16_T BitwiseOperator3;           /* '<S161>/Bitwise Operator3' */
  uint16_T BitwiseOperator4;           /* '<S161>/Bitwise Operator4' */
  uint16_T BitwiseOperator5;           /* '<S161>/Bitwise Operator5' */
  uint16_T BitwiseOperator6;           /* '<S161>/Bitwise Operator6' */
  uint16_T DataTypeConversion1_k;      /* '<S150>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_k;      /* '<S170>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_c;      /* '<S169>/Data Type Conversion2' */
  uint16_T DataTypeConversion1_d;      /* '<S172>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_cg;     /* '<S172>/Data Type Conversion2' */
  uint16_T DataTypeConversion3_n[4];   /* '<S172>/Data Type Conversion3' */
  uint16_T IndexVector[3];             /* '<S172>/Index Vector' */
  uint16_T Switch_o[3];                /* '<S172>/Switch' */
  uint16_T DataTypeConversion2_g;      /* '<S192>/Data Type Conversion2' */
  uint16_T DataTypeConversion2_i[3];   /* '<S193>/Data Type Conversion2' */
  uint16_T DataTypeConversiononi2cmag1_j[8];/* '<S174>/Data Type Conversion on i2c mag1' */
  uint16_T DataTypeConversiononi2cmag1_a[8];/* '<S176>/Data Type Conversion on i2c mag1' */
  uint16_T TmpSignalConversionAtSFunctionInport1_h[6];/* '<S161>/MATLAB Function compute magxyz1' */
  uint16_T DataTypeConversion4_f[2];   /* '<S153>/Data Type Conversion4' */
  uint16_T UT;                         /* '<S153>/MATLAB Function1' */
  int8_T WhileIterator;                /* '<S86>/While Iterator' */
  uint8_T I2C1SensorsLoop_o1[71];      /* '<S168>/I2C1 Sensors Loop' */
  uint8_T Switch4[6];                  /* '<S150>/Switch4' */
  uint8_T RateTransition10;            /* '<S25>/Rate Transition10' */
  uint8_T RateTransition6_i[2];        /* '<S149>/Rate Transition6' */
  uint8_T RateTransition5[3];          /* '<S149>/Rate Transition5' */
  uint8_T RateTransition1_g;           /* '<S149>/Rate Transition1' */
  uint8_T RateTransition[8];           /* '<S171>/Rate Transition' */
  uint8_T Switch_n[6];                 /* '<S150>/Switch' */
  uint8_T RateTransition14[8];         /* '<S171>/Rate Transition14' */
  uint8_T Switch1_k[6];                /* '<S150>/Switch1' */
  uint8_T RateTransition15[8];         /* '<S171>/Rate Transition15' */
  uint8_T Switch2_i[6];                /* '<S150>/Switch2' */
  uint8_T Output_e;                    /* '<S202>/Output' */
  uint8_T FixPtSum1;                   /* '<S203>/FixPt Sum1' */
  uint8_T FixPtSwitch;                 /* '<S204>/FixPt Switch' */
  uint8_T CANRX_o1[48];                /* '<S167>/CANRX' */
  uint8_T CANRX_o2;                    /* '<S167>/CANRX' */
  boolean_T Compare;                   /* '<S93>/Compare' */
  boolean_T LogicalOperator;           /* '<S150>/Logical Operator' */
  boolean_T RateTransition14_p;        /* '<S150>/Rate Transition14' */
  boolean_T RelationalOperator;        /* '<S86>/Relational Operator' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz5_p;/* '<S201>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz4_f;/* '<S201>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz3_ph;/* '<S201>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz2_i;/* '<S201>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz1_g;/* '<S201>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz5_k;/* '<S200>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz4_j;/* '<S200>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz3_p;/* '<S200>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz2_l;/* '<S200>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz1_i;/* '<S200>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz5_b;/* '<S194>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz4;  /* '<S194>/MATLAB Function compute gyroxyz4' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz3_b;/* '<S194>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz2_g;/* '<S194>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j
    sf_MATLABFunctioncomputegyroxyz1_b;/* '<S194>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz5_d;/* '<S176>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz3_a;/* '<S176>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz2_h;/* '<S176>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz1_e;/* '<S176>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_f
    sf_MATLABFunctioncomputegyroxyz5_i;/* '<S175>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_f
    sf_MATLABFunctioncomputegyroxyz1_k;/* '<S175>/MATLAB Function compute gyroxyz1' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz5;  /* '<S174>/MATLAB Function compute gyroxyz5' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz3;  /* '<S174>/MATLAB Function compute gyroxyz3' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz2;  /* '<S174>/MATLAB Function compute gyroxyz2' */
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost
    sf_MATLABFunctioncomputegyroxyz1;  /* '<S174>/MATLAB Function compute gyroxyz1' */
  rtB_clocklatch_ICARO3_Onda_bipe_controllonostro_mix clocklatch_h;/* '<Root>/clock latch' */
  rtB_clocklatch_ICARO3_Onda_bipe_controllonostro_mix clocklatch_m;/* '<S80>/clock latch' */
  rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_o;/* '<S42>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_l;/* '<S41>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_p;/* '<S36>/Subsystem' */
  rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_g;/* '<S35>/Subsystem' */
} BlockIO_ICARO3_Onda_bipe_controllonostro_mix;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S43>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S43>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S37>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S37>/Discrete-Time Integrator1' */
  real_T RateTransition1_Buffer0;      /* '<Root>/Rate Transition1' */
  real_T Memory1_PreviousInput;        /* '<S70>/Memory1' */
  real_T RateTransition47_Buffer0;     /* '<Root>/Rate Transition47' */
  real_T RateTransition48_Buffer0;     /* '<Root>/Rate Transition48' */
  real_T Memory_PreviousInput;         /* '<S92>/Memory' */
  real32_T UnitDelay1_DSTATE[4];       /* '<S30>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE[3];       /* '<S30>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[3];       /* '<S30>/Unit Delay3' */
  real32_T RateTransition49_Buffer0[3];/* '<Root>/Rate Transition49' */
  real32_T RateTransition2_Buffer0[11];/* '<S149>/Rate Transition2' */
  int32_T clockTickCounter;            /* '<S13>/Pulse Generator1' */
  int32_T clockTickCounter_f;          /* '<S172>/Pulse Generator' */
  uint32_T RateTransition18_Buffer[4]; /* '<S171>/Rate Transition18' */
  uint16_T RateTransition18_Buffer0[7];/* '<S149>/Rate Transition18' */
  uint8_T Output_DSTATE;               /* '<S202>/Output' */
  int8_T RateTransition6_semaphoreTaken;/* '<S149>/Rate Transition6' */
  int8_T RateTransition5_semaphoreTaken;/* '<S149>/Rate Transition5' */
  int8_T RateTransition2_semaphoreTaken;/* '<S149>/Rate Transition2' */
  int8_T RateTransition_ActiveBufIdx;  /* '<S171>/Rate Transition' */
  int8_T RateTransition14_ActiveBufIdx;/* '<S171>/Rate Transition14' */
  int8_T RateTransition15_ActiveBufIdx;/* '<S171>/Rate Transition15' */
  int8_T RateTransition18_semaphoreTaken;/* '<S149>/Rate Transition18' */
  int8_T RateTransition18_ActiveBufIdx;/* '<S171>/Rate Transition18' */
  uint8_T RateTransition6_Buffer0[2];  /* '<S149>/Rate Transition6' */
  uint8_T RateTransition5_Buffer0[3];  /* '<S149>/Rate Transition5' */
  uint8_T RateTransition_Buffer[16];   /* '<S171>/Rate Transition' */
  uint8_T RateTransition14_Buffer[16]; /* '<S171>/Rate Transition14' */
  uint8_T RateTransition15_Buffer[16]; /* '<S171>/Rate Transition15' */
  boolean_T ini_not_empty;             /* '<S30>/dcm_marg' */
  boolean_T AttitudeFilterADIS_MODE;   /* '<S3>/Attitude Filter ADIS' */
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_o;/* '<S42>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_l;/* '<S41>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_p;/* '<S36>/Subsystem' */
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_g;/* '<S35>/Subsystem' */
} D_Work_ICARO3_Onda_bipe_controllonostro_mix;

/* Parameters for system: '<S35>/Subsystem' */
struct rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S38>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S38>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: eps
                                        * Referenced by: '<S38>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S80>/clock latch' */
struct rtP_clocklatch_ICARO3_Onda_bipe_controllonostro_mix_ {
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S95>/Out'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ICARO3_Onda_bipe_controllonostro_mix_ {
  real_T CAL_PARAM[9];                 /* Variable: CAL_PARAM
                                        * Referenced by: '<S149>/MATLAB Function'
                                        */
  real_T INV_PITCH_RANGE;              /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_ROLL_RANGE;               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_THROTTLE_RANGE;           /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T INV_YAW_RANGE;                /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_IDX;                    /* Variable: PITCH_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T PITCH_MID;                    /* Variable: PITCH_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_IDX;                     /* Variable: ROLL_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T ROLL_MID;                     /* Variable: ROLL_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_DOWN;                /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_IDX;                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T THROTTLE_LOW_THRES;           /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_IDX;                      /* Variable: YAW_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real_T YAW_MID;                      /* Variable: YAW_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  real32_T ST;                         /* Variable: ST
                                        * Referenced by: '<S30>/dcm_marg'
                                        */
  real_T RepeatingSequenceStair_OutValues[12];/* Mask Parameter: RepeatingSequenceStair_OutValues
                                               * Referenced by: '<S191>/Vector'
                                               */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S93>/Constant'
                                        */
  real32_T DCM_MARG_QUAT_Ki;           /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S30>/dcm_marg'
                                        */
  real32_T DCM_MARG_QUAT_Kp;           /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S30>/dcm_marg'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator3_BitMask;   /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator3'
                                        */
  uint16_T BitwiseOperator4_BitMask;   /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator4'
                                        */
  uint16_T BitwiseOperator5_BitMask;   /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator5'
                                        */
  uint16_T BitwiseOperator6_BitMask;   /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator6'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S204>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
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
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 9.81
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_b;/* Computed Parameter: DiscreteTimeIntegrator_gainval_b
                                           * Referenced by: '<S43>/Discrete-Time Integrator'
                                           */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S43>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                            * Referenced by: '<S43>/Discrete-Time Integrator1'
                                            */
  real_T DiscreteTimeIntegrator1_IC_i; /* Expression: eps
                                        * Referenced by: '<S43>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S69>/Gain1'
                                        */
  real_T phi_Y0;                       /* Expression: 0
                                        * Referenced by: '<S86>/phi'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S92>/Memory'
                                        */
  real_T Constant1_Value_oo;           /* Expression: R
                                        * Referenced by: '<S90>/Constant1'
                                        */
  real_T Out_Y0;                       /* Expression: -1000
                                        * Referenced by: '<S94>/Out'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S193>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S193>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S192>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 180
                                        * Referenced by: '<S192>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S172>/Switch'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 11
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S28>/Step1'
                                        */
  real_T I2C1SensorsLoop_P1;           /* Expression: ST
                                        * Referenced by: '<S168>/I2C1 Sensors Loop'
                                        */
  real_T HW0SIM_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch4'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value_hv;            /* Expression: 0
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S69>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.7
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.7
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Constant1_Value_on;           /* Expression: 1.52
                                        * Referenced by: '<S69>/Constant1'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S70>/Memory1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -0.001
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real_T Constant_Value_ob;            /* Expression: 0
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 0.5
                                        * Referenced by: '<S70>/Switch1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.2
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  real_T zerospeedvalue_Value;         /* Expression: 1.42
                                        * Referenced by: '<S70>/ zero speed value'
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
  real_T PWM1_P1;                      /* Expression: 0.01
                                        * Referenced by: '<S2>/PWM1'
                                        */
  real_T ConstantSIMULATIONONLY_Value[6];/* Expression: [0 10 50 100 150 200]
                                          * Referenced by: '<Root>/Constant ( SIMULATION ONLY )'
                                          */
  real_T Switch_Threshold_c;           /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 100
                                        * Referenced by: '<S170>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2047
                                        * Referenced by: '<S170>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: R
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: F
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Constant_Value_cm;            /* Expression: 1
                                        * Referenced by: '<S87>/Constant'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S83>/Unit Conversion'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: R
                                        * Referenced by: '<S85>/Constant1'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S85>/f'
                                        */
  real_T Constant1_Value_o5;           /* Expression: 0
                                        * Referenced by: '<S77>/Constant1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 100
                                        * Referenced by: '<S169>/Gain'
                                        */
  real_T Constant_Value_ik;            /* Expression: 2047
                                        * Referenced by: '<S169>/Constant'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S13>/Pulse Generator1'
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
                                           * Referenced by: '<S30>/Unit Delay1'
                                           */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S30>/Unit Delay2'
                                        */
  real32_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S30>/Unit Delay3'
                                        */
  real32_T Switch2_Threshold_i;        /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S34>/Switch2'
                                        */
  real32_T Switch2_Threshold_d;        /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S35>/Switch2'
                                        */
  real32_T Switch2_Threshold_d3;       /* Computed Parameter: Switch2_Threshold_d3
                                        * Referenced by: '<S36>/Switch2'
                                        */
  real32_T RateTransition49_X0;        /* Computed Parameter: RateTransition49_X0
                                        * Referenced by: '<Root>/Rate Transition49'
                                        */
  real32_T Switch2_Threshold_a;        /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S40>/Switch2'
                                        */
  real32_T Switch2_Threshold_f;        /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S41>/Switch2'
                                        */
  real32_T Switch2_Threshold_j;        /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S42>/Switch2'
                                        */
  real32_T Constant1_Value_dr[3];      /* Computed Parameter: Constant1_Value_dr
                                        * Referenced by: '<S3>/Constant1'
                                        */
  uint32_T Rx_ID1_Value;               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S167>/Rx_ID1'
                                        */
  uint32_T Rx_ID2_Value;               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S167>/Rx_ID2'
                                        */
  uint32_T Rx_ID3_Value;               /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S167>/Rx_ID3'
                                        */
  uint32_T Rx_ID4_Value;               /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S167>/Rx_ID4'
                                        */
  uint32_T Rx_ID5_Value;               /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S167>/Rx_ID5'
                                        */
  uint32_T Rx_ID6_Value;               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S167>/Rx_ID6'
                                        */
  uint32_T RateTransition18_X0;        /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S171>/Rate Transition18'
                                        */
  uint16_T Constant1_Value_e[4];       /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S171>/Constant1'
                                        */
  int8_T Switch_Threshold_j;           /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S92>/Switch'
                                        */
  uint8_T enableall_Value[6];          /* Computed Parameter: enableall_Value
                                        * Referenced by: '<S150>/enable all'
                                        */
  uint8_T enable0_Value;               /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S150>/enable 0'
                                        */
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S204>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S202>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S203>/FixPt Constant'
                                        */
  uint8_T bmp085accuracylevel_Value;   /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S25>/bmp085 accuracy level'
                                        */
  uint8_T RateTransition_X0;           /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S171>/Rate Transition'
                                        */
  uint8_T RateTransition14_X0;         /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S171>/Rate Transition14'
                                        */
  uint8_T RateTransition15_X0;         /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S171>/Rate Transition15'
                                        */
  uint8_T gpsselector2_CurrentSetting; /* Computed Parameter: gpsselector2_CurrentSetting
                                        * Referenced by: '<S8>/gps selector 2'
                                        */
  uint8_T gpsselector1_CurrentSetting; /* Computed Parameter: gpsselector1_CurrentSetting
                                        * Referenced by: '<S8>/gps selector 1'
                                        */
  rtP_clocklatch_ICARO3_Onda_bipe_controllonostro_mix clocklatch_h;/* '<Root>/clock latch' */
  rtP_clocklatch_ICARO3_Onda_bipe_controllonostro_mix clocklatch_m;/* '<S80>/clock latch' */
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_o;/* '<S42>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_l;/* '<S41>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_p;/* '<S36>/Subsystem' */
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix Subsystem_g;/* '<S35>/Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ICARO3_Onda_bipe_controllonostro_mix {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick5;
    struct {
      uint16_T TID[6];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_4;
      boolean_T TID2_4;
      boolean_T TID4_5;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_ICARO3_Onda_bipe_controllonostro_mix
  ICARO3_Onda_bipe_controllonostro_mix_P;

/* Block signals (auto storage) */
extern BlockIO_ICARO3_Onda_bipe_controllonostro_mix
  ICARO3_Onda_bipe_controllonostro_mix_B;

/* Block states (auto storage) */
extern D_Work_ICARO3_Onda_bipe_controllonostro_mix
  ICARO3_Onda_bipe_controllonostro_mix_DWork;

/* External function called from main */
extern void ICARO3_Onda_bipe_controllonostro_mix_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void ICARO3_Onda_bipe_controllonostro_mix_SetEventsForThisBaseStep
  (boolean_T *eventFlags);
extern void ICARO3_Onda_bipe_controllonostro_mix_initialize(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_ICARO3_Onda_bipe_controllonostro_mix *const
  ICARO3_Onda_bipe_controllonostro_mix_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Unused code path elimination
 * Block '<S2>/scale factor for resistor network - from mesarured R1 and R2' : Unused code path elimination
 * Block '<S30>/Add3' : Unused code path elimination
 * Block '<S30>/Discrete-Time Integrator3' : Unused code path elimination
 * Block '<S30>/Gain1' : Unused code path elimination
 * Block '<S30>/Scope6' : Unused code path elimination
 * Block '<S27>/Gain1' : Unused code path elimination
 * Block '<S27>/Scope3' : Unused code path elimination
 * Block '<S27>/Scope4' : Unused code path elimination
 * Block '<S27>/Scope5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion mx3' : Unused code path elimination
 * Block '<S80>/Sum' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/ID CAR ' : Unused code path elimination
 * Block '<S22>/1 h in sec ' : Unused code path elimination
 * Block '<S22>/Asec to Ahour' : Unused code path elimination
 * Block '<S22>/Instantaneous Power' : Unused code path elimination
 * Block '<S22>/integrate current' : Unused code path elimination
 * Block '<S141>/Internal' : Unused code path elimination
 * Block '<S142>/Internal' : Unused code path elimination
 * Block '<S153>/Gain1' : Unused code path elimination
 * Block '<S153>/Gain2' : Unused code path elimination
 * Block '<S149>/Data Type Conversion mx5' : Unused code path elimination
 * Block '<S149>/Data Type Conversion1' : Unused code path elimination
 * Block '<S149>/Data Type Conversion2' : Unused code path elimination
 * Block '<S149>/Data Type Conversion4' : Unused code path elimination
 * Block '<S149>/Data Type Conversion5' : Unused code path elimination
 * Block '<S149>/Data Type Conversion6' : Unused code path elimination
 * Block '<S149>/Rate Transition' : Unused code path elimination
 * Block '<S149>/Switch2' : Unused code path elimination
 * Block '<S149>/scale factor correction (good for test_calib_2)' : Unused code path elimination
 * Block '<S161>/Bitwise Operator' : Unused code path elimination
 * Block '<S161>/Data Type Conversion mx1' : Unused code path elimination
 * Block '<S161>/Gain' : Unused code path elimination
 * Block '<S149>/use calibrated  data' : Unused code path elimination
 * Block '<S149>/use calibrated  data ' : Unused code path elimination
 * Block '<S25>/Rate Transition1' : Unused code path elimination
 * Block '<S25>/Rate Transition2' : Unused code path elimination
 * Block '<S25>/Rate Transition3' : Unused code path elimination
 * Block '<S25>/Rate Transition4' : Unused code path elimination
 * Block '<S25>/Rate Transition5' : Unused code path elimination
 * Block '<S25>/Rate Transition6' : Unused code path elimination
 * Block '<S150>/Data Type Conversion' : Unused code path elimination
 * Block '<S150>/Data Type Conversion2' : Unused code path elimination
 * Block '<S150>/Rate Transition11' : Unused code path elimination
 * Block '<S171>/Constant' : Unused code path elimination
 * Block '<S171>/Constant2' : Unused code path elimination
 * Block '<S171>/Data Type Conversion' : Unused code path elimination
 * Block '<S171>/Data Type Conversion1' : Unused code path elimination
 * Block '<S171>/Data Type Conversion2' : Unused code path elimination
 * Block '<S171>/Data Type Conversion3' : Unused code path elimination
 * Block '<S171>/Rate Transition1' : Unused code path elimination
 * Block '<S171>/Rate Transition2' : Unused code path elimination
 * Block '<S171>/Rate Transition3' : Unused code path elimination
 * Block '<S171>/Rate Transition4' : Unused code path elimination
 * Block '<S171>/fake gps received signal' : Unused code path elimination
 * Block '<S150>/downsample to 100 Hz11' : Unused code path elimination
 * Block '<S150>/downsample to 100 Hz4' : Unused code path elimination
 * Block '<S150>/downsample to 100 Hz5' : Unused code path elimination
 * Block '<S150>/downsample to 100 Hz6' : Unused code path elimination
 * Block '<S150>/downsample to 100 Hz8' : Unused code path elimination
 * Block '<S150>/enable all1' : Unused code path elimination
 * Block '<S150>/enable all2' : Unused code path elimination
 * Block '<S150>/enable all3' : Unused code path elimination
 * Block '<S202>/Data Type Propagation' : Unused code path elimination
 * Block '<S203>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S195>/Constant' : Unused code path elimination
 * Block '<S195>/Data Type Conversion2' : Unused code path elimination
 * Block '<S195>/Gain' : Unused code path elimination
 * Block '<S195>/Sum' : Unused code path elimination
 * Block '<S196>/Constant' : Unused code path elimination
 * Block '<S196>/Data Type Conversion2' : Unused code path elimination
 * Block '<S196>/Gain' : Unused code path elimination
 * Block '<S196>/Sum' : Unused code path elimination
 * Block '<S197>/Constant' : Unused code path elimination
 * Block '<S197>/Data Type Conversion2' : Unused code path elimination
 * Block '<S197>/Gain' : Unused code path elimination
 * Block '<S197>/Sum' : Unused code path elimination
 * Block '<S198>/Constant' : Unused code path elimination
 * Block '<S198>/Data Type Conversion2' : Unused code path elimination
 * Block '<S198>/Gain' : Unused code path elimination
 * Block '<S198>/Sum' : Unused code path elimination
 * Block '<S199>/Constant' : Unused code path elimination
 * Block '<S199>/Data Type Conversion2' : Unused code path elimination
 * Block '<S199>/Gain' : Unused code path elimination
 * Block '<S199>/Sum' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S30>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<S27>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S27>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S3>/Data Type Conversion mx3' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion22' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion25' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition44' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition16' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition17' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S150>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S171>/Rate Transition19' : Eliminated since input and output rates are identical
 * Block '<S171>/Rate Transition20' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz1' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz10' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz2' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz7' : Eliminated since input and output rates are identical
 * Block '<S150>/downsample to 100 Hz9' : Eliminated since input and output rates are identical
 * Block '<S191>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'ICARO3_Onda_bipe_controllonostro_mix'
 * '<S1>'   : 'ICARO3_Onda_bipe_controllonostro_mix/ generatore di riferimenti'
 * '<S2>'   : 'ICARO3_Onda_bipe_controllonostro_mix/ADC1'
 * '<S3>'   : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2'
 * '<S4>'   : 'ICARO3_Onda_bipe_controllonostro_mix/Compensate for sensor mount _acc'
 * '<S5>'   : 'ICARO3_Onda_bipe_controllonostro_mix/Compensate for sensor mount _acc1'
 * '<S6>'   : 'ICARO3_Onda_bipe_controllonostro_mix/Control '
 * '<S7>'   : 'ICARO3_Onda_bipe_controllonostro_mix/GET PPS'
 * '<S8>'   : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver'
 * '<S9>'   : 'ICARO3_Onda_bipe_controllonostro_mix/PI Controller'
 * '<S10>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Posca_Zocco Steer Map '
 * '<S11>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Prescaler'
 * '<S12>'  : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS'
 * '<S13>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Scheme Running'
 * '<S14>'  : 'ICARO3_Onda_bipe_controllonostro_mix/blocco motori se non arrivano pacchetti'
 * '<S15>'  : 'ICARO3_Onda_bipe_controllonostro_mix/clock latch'
 * '<S16>'  : 'ICARO3_Onda_bipe_controllonostro_mix/configurazione relativa seeker//target'
 * '<S17>'  : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST'
 * '<S18>'  : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST1'
 * '<S19>'  : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry STATIC TEST'
 * '<S20>'  : 'ICARO3_Onda_bipe_controllonostro_mix/debug_telemetry_minimal'
 * '<S21>'  : 'ICARO3_Onda_bipe_controllonostro_mix/latch1'
 * '<S22>'  : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1'
 * '<S23>'  : 'ICARO3_Onda_bipe_controllonostro_mix/pwm & pi cmds'
 * '<S24>'  : 'ICARO3_Onda_bipe_controllonostro_mix/send gps to bs'
 * '<S25>'  : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface'
 * '<S26>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ generatore di riferimenti/fcn'
 * '<S27>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/Attitude Filter ADIS'
 * '<S28>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS'
 * '<S29>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1'
 * '<S30>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT'
 * '<S31>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/Attitude Filter ADIS/DCM_MARG_QUAT/dcm_marg'
 * '<S32>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend '
 * '<S33>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend'
 * '<S34>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend'
 * '<S35>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1'
 * '<S36>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3'
 * '<S37>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend/Subsystem'
 * '<S38>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S39>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S40>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend'
 * '<S41>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1'
 * '<S42>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2'
 * '<S43>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend/Subsystem'
 * '<S44>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend1/Subsystem'
 * '<S45>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS/Gyros Detrend/Detrend2/Subsystem'
 * '<S46>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend '
 * '<S47>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1'
 * '<S48>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend'
 * '<S49>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend'
 * '<S50>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1'
 * '<S51>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3'
 * '<S52>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend/Subsystem'
 * '<S53>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend1/Subsystem'
 * '<S54>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend /Detrend3/Subsystem'
 * '<S55>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend'
 * '<S56>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1'
 * '<S57>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3'
 * '<S58>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend/Subsystem'
 * '<S59>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend1/Subsystem'
 * '<S60>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Acceleration Detrend 1/Detrend3/Subsystem'
 * '<S61>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend'
 * '<S62>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1'
 * '<S63>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2'
 * '<S64>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend/Subsystem'
 * '<S65>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend1/Subsystem'
 * '<S66>'  : 'ICARO3_Onda_bipe_controllonostro_mix/ADIS AHRS2/debias ADIS1/Gyros Detrend/Detrend2/Subsystem'
 * '<S67>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /VectorNorm'
 * '<S68>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /atan2'
 * '<S69>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /steer_control'
 * '<S70>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /throttle_control '
 * '<S71>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /steer_control/Control Manager'
 * '<S72>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /throttle_control /Control Manager'
 * '<S73>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Control /throttle_control /MATLAB Function'
 * '<S74>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GET PPS/clock latch'
 * '<S75>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GET PPS/step 2 pulse'
 * '<S76>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GET PPS/uint16 to vector'
 * '<S77>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS'
 * '<S78>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/VENUS GPS'
 * '<S79>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/compute 3d age'
 * '<S80>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/compute age'
 * '<S81>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA'
 * '<S82>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/MAP ublox fix type to standard status'
 * '<S83>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Angle Conversion1'
 * '<S84>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem2'
 * '<S85>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/Subsystem3'
 * '<S86>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem'
 * '<S87>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^1'
 * '<S88>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^2'
 * '<S89>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/e^3'
 * '<S90>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem2'
 * '<S91>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem3'
 * '<S92>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/UBLOX LEA 6 GPS/ECEF Position to LLA/While Iterator Subsystem/Subsystem4'
 * '<S93>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/compute 3d age/Compare To Constant'
 * '<S94>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/compute 3d age/clock latch'
 * '<S95>'  : 'ICARO3_Onda_bipe_controllonostro_mix/GPS receiver/compute age/clock latch'
 * '<S96>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Prescaler/find send time'
 * '<S97>'  : 'ICARO3_Onda_bipe_controllonostro_mix/Prescaler/latch'
 * '<S98>'  : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/Attitude Filter SS'
 * '<S99>'  : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS'
 * '<S100>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT'
 * '<S101>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/Attitude Filter SS/DCM_MARG_QUAT/dcm_marg'
 * '<S102>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend '
 * '<S103>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend'
 * '<S104>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend'
 * '<S105>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend1'
 * '<S106>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend3'
 * '<S107>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend/Subsystem'
 * '<S108>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend1/Subsystem'
 * '<S109>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Acceleration Detrend /Detrend3/Subsystem'
 * '<S110>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend'
 * '<S111>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend1'
 * '<S112>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend2'
 * '<S113>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend/Subsystem'
 * '<S114>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend1/Subsystem'
 * '<S115>' : 'ICARO3_Onda_bipe_controllonostro_mix/SS AHRS/debias SS/Gyros Detrend/Detrend2/Subsystem'
 * '<S116>' : 'ICARO3_Onda_bipe_controllonostro_mix/blocco motori se non arrivano pacchetti/Enabled Subsystem'
 * '<S117>' : 'ICARO3_Onda_bipe_controllonostro_mix/configurazione relativa seeker//target/engagement'
 * '<S118>' : 'ICARO3_Onda_bipe_controllonostro_mix/configurazione relativa seeker//target/engagement 2'
 * '<S119>' : 'ICARO3_Onda_bipe_controllonostro_mix/configurazione relativa seeker//target/pure PNG '
 * '<S120>' : 'ICARO3_Onda_bipe_controllonostro_mix/configurazione relativa seeker//target/engagement/Fading filter del II ordine'
 * '<S121>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/ADC_filt'
 * '<S122>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/ADC_raw'
 * '<S123>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/Ages'
 * '<S124>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/GPS'
 * '<S125>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/GPS ECEF'
 * '<S126>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/MATLAB Function2'
 * '<S127>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S128>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/Raw IMU data MPU + HMC + ADC'
 * '<S129>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/Raw IMU data MPU only + ADC'
 * '<S130>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/Raw IMU data packer'
 * '<S131>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/To be used for ADAPT NN online tuning'
 * '<S132>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/To be used for H PID online tuning'
 * '<S133>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/join enable flags'
 * '<S134>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/recupero di mpu9150 data'
 * '<S135>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/test solo RC_all_channel_usec + RSSI + ....'
 * '<S136>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST/GPS/detect if was 1 in the last 10 samples'
 * '<S137>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry FLIGHT TEST1/MODIFIED Raw IMU data MPU only  + RPY AHRS + ALTITUDE (H Hd 0) to be used for AHRS online tuning'
 * '<S138>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry STATIC TEST/Raw IMU data packer: MPU + MAG_HMC'
 * '<S139>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry STATIC TEST/Subsystem'
 * '<S140>' : 'ICARO3_Onda_bipe_controllonostro_mix/debug telemtry STATIC TEST/join enable flags'
 * '<S141>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter'
 * '<S142>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter1'
 * '<S143>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter/IO Delay'
 * '<S144>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter/Input Delay'
 * '<S145>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter/Output Delay'
 * '<S146>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter1/IO Delay'
 * '<S147>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter1/Input Delay'
 * '<S148>' : 'ICARO3_Onda_bipe_controllonostro_mix/power computations1/low pass filter1/Output Delay'
 * '<S149>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing'
 * '<S150>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager'
 * '<S151>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/Compensate for sensor mount _acc'
 * '<S152>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/Compensate for sensor mount _gyro'
 * '<S153>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)'
 * '<S154>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function'
 * '<S155>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function compute accxyz'
 * '<S156>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function compute accxyz1'
 * '<S157>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function compute gyroxyz'
 * '<S158>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function compute magxyz'
 * '<S159>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/MATLAB Function compute magxyz2'
 * '<S160>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/compute_parameters'
 * '<S161>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/spi_data_processing'
 * '<S162>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function'
 * '<S163>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/Compute Temperature (T) and Altitude (H)/MATLAB Function1'
 * '<S164>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/compute_parameters/MATLAB Function1'
 * '<S165>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/Processing/spi_data_processing/MATLAB Function compute magxyz1'
 * '<S166>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/Arrange pwms'
 * '<S167>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX'
 * '<S168>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/I2C1 sensors loop'
 * '<S169>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/Subsystem1'
 * '<S170>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/Subsystem2'
 * '<S171>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/compose data from canbus'
 * '<S172>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus'
 * '<S173>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/Arrange pwms/clock latch'
 * '<S174>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1'
 * '<S175>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2'
 * '<S176>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3'
 * '<S177>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz1'
 * '<S178>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz2'
 * '<S179>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz3'
 * '<S180>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem1/MATLAB Function compute gyroxyz5'
 * '<S181>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz1'
 * '<S182>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem2/MATLAB Function compute gyroxyz5'
 * '<S183>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz1'
 * '<S184>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz2'
 * '<S185>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz3'
 * '<S186>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/CANbus data RX/Subsystem3/MATLAB Function compute gyroxyz5'
 * '<S187>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/compose data from canbus/H'
 * '<S188>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single'
 * '<S189>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/compose data from canbus/typecast uin32 to single1'
 * '<S190>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/compose data from canbus/H/typecast uin32 to single'
 * '<S191>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair'
 * '<S192>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem'
 * '<S193>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem1'
 * '<S194>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10'
 * '<S195>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem2'
 * '<S196>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem3'
 * '<S197>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem4'
 * '<S198>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem5'
 * '<S199>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem6'
 * '<S200>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7'
 * '<S201>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8'
 * '<S202>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter'
 * '<S203>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S204>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S205>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz1'
 * '<S206>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz2'
 * '<S207>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz3'
 * '<S208>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz4'
 * '<S209>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem10/MATLAB Function compute gyroxyz5'
 * '<S210>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz1'
 * '<S211>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz2'
 * '<S212>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz3'
 * '<S213>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz4'
 * '<S214>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem7/MATLAB Function compute gyroxyz5'
 * '<S215>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz1'
 * '<S216>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz2'
 * '<S217>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz3'
 * '<S218>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz4'
 * '<S219>' : 'ICARO3_Onda_bipe_controllonostro_mix/sensor and actuators interface/interrupt manager/send motor commands via canbus/Subsystem8/MATLAB Function compute gyroxyz5'
 */
#endif                                 /* RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_bipe_controllonostro_mix.h
 */
