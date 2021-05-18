/*
 * File: ICARO3_Onda_bipe_controllonostro_mix_data.c
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

#include "ICARO3_Onda_bipe_controllonostro_mix.h"
#include "ICARO3_Onda_bipe_controllonostro_mix_private.h"

/* Block parameters (auto storage) */
Parameters_ICARO3_Onda_bipe_controllonostro_mix
  ICARO3_Onda_bipe_controllonostro_mix_P = {
  /*  Variable: CAL_PARAM
   * Referenced by: '<S149>/MATLAB Function'
   */
  { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0 },
  0.0024213075060532689,               /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  0.0024390243902439024,               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  0.0012121212121212121,               /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  0.0024271844660194173,               /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  2.0,                                 /* Variable: PITCH_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1515.0,                              /* Variable: PITCH_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1.0,                                 /* Variable: ROLL_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1518.0,                              /* Variable: ROLL_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1105.0,                              /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  3.0,                                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1146.25,                             /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  4.0,                                 /* Variable: YAW_IDX
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  1507.0,                              /* Variable: YAW_MID
                                        * Referenced by: '<S149>/MATLAB Function compute magxyz2'
                                        */
  0.005F,                              /* Variable: ST
                                        * Referenced by: '<S30>/dcm_marg'
                                        */

  /*  Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S191>/Vector'
   */
  { 0.0, 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0 },
  2.0,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S93>/Constant'
                                        */
  0.0F,                                /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S30>/dcm_marg'
                                        */
  0.15F,                               /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S30>/dcm_marg'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator1'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator2'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator3'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator4'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator5'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S161>/Bitwise Operator6'
                                        */
  11U,                                 /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S204>/FixPt Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S37>/Constant'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S37>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Discrete-Time Integrator'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S37>/Discrete-Time Integrator1'
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S37>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
  9.81,                                /* Expression: 9.81
                                        * Referenced by: '<S36>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval_b
                                        * Referenced by: '<S43>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Discrete-Time Integrator'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                        * Referenced by: '<S43>/Discrete-Time Integrator1'
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S43>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  1.2,                                 /* Expression: 1.2
                                        * Referenced by: '<S69>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S86>/phi'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Memory'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S90>/Constant1'
                                        */
  -1000.0,                             /* Expression: -1000
                                        * Referenced by: '<S94>/Out'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S193>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S193>/Constant'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S192>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S192>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S172>/Pulse Generator'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S172>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  11.0,                                /* Expression: 11
                                        * Referenced by: '<S28>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Step1'
                                        */
  0.005,                               /* Expression: ST
                                        * Referenced by: '<S168>/I2C1 Sensors Loop'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch4'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S6>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S69>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S69>/Switch1'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<S69>/Saturation'
                                        */
  -0.7,                                /* Expression: -0.7
                                        * Referenced by: '<S69>/Saturation'
                                        */
  1.52,                                /* Expression: 1.52
                                        * Referenced by: '<S69>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S70>/Memory1'
                                        */
  -0.001,                              /* Expression: -0.001
                                        * Referenced by: '<S70>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S70>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S70>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  -0.2,                                /* Expression: -0.2
                                        * Referenced by: '<S70>/Saturation1'
                                        */
  1.42,                                /* Expression: 1.42
                                        * Referenced by: '<S70>/ zero speed value'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Save data to data logger (the micro SD card)2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition47'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition48'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant33'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant32'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/PWM1'
                                        */

  /*  Expression: [0 10 50 100 150 200]
   * Referenced by: '<Root>/Constant ( SIMULATION ONLY )'
   */
  { 0.0, 10.0, 50.0, 100.0, 150.0, 200.0 },
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch2'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S170>/Gain'
                                        */
  2047.0,                              /* Expression: 2047
                                        * Referenced by: '<S170>/Constant'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S81>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S88>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S88>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S89>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S87>/Constant'
                                        */
  57.295779513082323,                  /* Expression: slope
                                        * Referenced by: '<S83>/Unit Conversion'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S77>/Constant'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S85>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S85>/f'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S77>/Constant1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S169>/Gain'
                                        */
  2047.0,                              /* Expression: 2047
                                        * Referenced by: '<S169>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  30.0,                                /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Pulse Generator1'
                                        */

  /*  Computed Parameter: q_Y0
   * Referenced by: '<S27>/q'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: rpy_Y0
   * Referenced by: '<S27>/rpy'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: gyro_bias_Y0
   * Referenced by: '<S27>/gyro_bias'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: a_ned_Y0
   * Referenced by: '<S27>/a_ned'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S30>/Unit Delay1'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },
  0.0F,                                /* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S30>/Unit Delay2'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S30>/Unit Delay3'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S34>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S35>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_d3
                                        * Referenced by: '<S36>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: RateTransition49_X0
                                        * Referenced by: '<Root>/Rate Transition49'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S40>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S41>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S42>/Switch2'
                                        */

  /*  Computed Parameter: Constant1_Value_dr
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0F, 0.0F, 0.0F },
  1551U,                               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S167>/Rx_ID1'
                                        */
  1039U,                               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S167>/Rx_ID2'
                                        */
  783U,                                /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S167>/Rx_ID3'
                                        */
  527U,                                /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S167>/Rx_ID4'
                                        */
  271U,                                /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S167>/Rx_ID5'
                                        */
  1807U,                               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S167>/Rx_ID6'
                                        */
  0U,                                  /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S171>/Rate Transition18'
                                        */

  /*  Computed Parameter: Constant1_Value_e
   * Referenced by: '<S171>/Constant1'
   */
  { 0U, 0U, 0U, 0U },
  0,                                   /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S92>/Switch'
                                        */

  /*  Computed Parameter: enableall_Value
   * Referenced by: '<S150>/enable all'
   */
  { 1U, 1U, 1U, 1U, 1U, 1U },
  1U,                                  /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S150>/enable 0'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S204>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S202>/Output'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S203>/FixPt Constant'
                                        */
  3U,                                  /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S25>/bmp085 accuracy level'
                                        */
  0U,                                  /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S171>/Rate Transition'
                                        */
  0U,                                  /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S171>/Rate Transition14'
                                        */
  0U,                                  /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S171>/Rate Transition15'
                                        */
  0U,                                  /* Computed Parameter: gpsselector2_CurrentSetting
                                        * Referenced by: '<S8>/gps selector 2'
                                        */
  0U,                                  /* Computed Parameter: gpsselector1_CurrentSetting
                                        * Referenced by: '<S8>/gps selector 1'
                                        */

  /* Start of '<Root>/clock latch' */
  {
    -1000.0                            /* Expression: -1000
                                        * Referenced by: '<S15>/Out'
                                        */
  }
  /* End of '<Root>/clock latch' */
  ,

  /* Start of '<S80>/clock latch' */
  {
    -1000.0                            /* Expression: -1000
                                        * Referenced by: '<S95>/Out'
                                        */
  }
  /* End of '<S80>/clock latch' */
  ,

  /* Start of '<S42>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S45>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S45>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S45>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S45>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S45>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S42>/Subsystem' */
  ,

  /* Start of '<S41>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S44>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S44>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S44>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S44>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S41>/Subsystem' */
  ,

  /* Start of '<S36>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S39>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S39>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S39>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S39>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S36>/Subsystem' */
  ,

  /* Start of '<S35>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S38>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S38>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S35>/Subsystem' */
};

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_bipe_controllonostro_mix_data.c
 */
