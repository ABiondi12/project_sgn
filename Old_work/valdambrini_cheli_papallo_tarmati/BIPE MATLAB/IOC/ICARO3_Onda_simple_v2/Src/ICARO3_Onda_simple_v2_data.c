/*
 * File: ICARO3_Onda_simple_v2_data.c
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

#include "ICARO3_Onda_simple_v2.h"
#include "ICARO3_Onda_simple_v2_private.h"

/* Block parameters (auto storage) */
Parameters_ICARO3_Onda_simple_v2 ICARO3_Onda_simple_v2_P = {
  /*  Variable: CAL_PARAM
   * Referenced by: '<S308>/MATLAB Function'
   */
  { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0 },
  0.0024213075060532689,               /* Variable: INV_PITCH_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  0.0024390243902439024,               /* Variable: INV_ROLL_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  0.0012121212121212121,               /* Variable: INV_THROTTLE_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  0.0024271844660194173,               /* Variable: INV_YAW_RANGE
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  2.0,                                 /* Variable: PITCH_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1515.0,                              /* Variable: PITCH_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1.0,                                 /* Variable: ROLL_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1518.0,                              /* Variable: ROLL_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1105.0,                              /* Variable: THROTTLE_DOWN
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  3.0,                                 /* Variable: THROTTLE_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1146.25,                             /* Variable: THROTTLE_LOW_THRES
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  4.0,                                 /* Variable: YAW_IDX
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  1507.0,                              /* Variable: YAW_MID
                                        * Referenced by: '<S308>/MATLAB Function compute magxyz2'
                                        */
  0.005F,                              /* Variable: ST
                                        * Referenced by: '<S110>/dcm_marg'
                                        */

  /*  Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S350>/Vector'
   */
  { 0.0, 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0 },
  2.0,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S252>/Constant'
                                        */
  0.0F,                                /* Mask Parameter: DCM_MARG_QUAT_Ki
                                        * Referenced by: '<S110>/dcm_marg'
                                        */
  0.15F,                               /* Mask Parameter: DCM_MARG_QUAT_Kp
                                        * Referenced by: '<S110>/dcm_marg'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator1'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator2'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator3'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator4'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator5'
                                        */
  16383U,                              /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S320>/Bitwise Operator6'
                                        */
  11U,                                 /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S363>/FixPt Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S114>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S117>/Constant'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S117>/Discrete-Time Integrator1'
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S117>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S115>/Constant1'
                                        */
  9.81,                                /* Expression: 9.81
                                        * Referenced by: '<S116>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S116>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S120>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S123>/Constant'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval_b
                                        * Referenced by: '<S123>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S123>/Discrete-Time Integrator'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval_j
                                        * Referenced by: '<S123>/Discrete-Time Integrator1'
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S123>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S121>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S122>/Constant1'
                                        */
  1.2,                                 /* Expression: 1.2
                                        * Referenced by: '<S150>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S245>/phi'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S251>/Memory'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S249>/Constant1'
                                        */
  -1000.0,                             /* Expression: -1000
                                        * Referenced by: '<S253>/Out'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S352>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S352>/Constant'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S351>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S351>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S331>/Pulse Generator'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S331>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S108>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S108>/Step'
                                        */
  11.0,                                /* Expression: 11
                                        * Referenced by: '<S108>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S108>/Step1'
                                        */
  0.005,                               /* Expression: ST
                                        * Referenced by: '<S327>/I2C1 Sensors Loop'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/1: HW 0: SIM'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain8'
                                        */
  17.0,                                /* Expression: 17
                                        * Referenced by: '<Root>/Constant34'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S151>/Memory1'
                                        */
  -0.001,                              /* Expression: -0.001
                                        * Referenced by: '<S151>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S151>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S151>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S151>/Saturation1'
                                        */
  -0.2,                                /* Expression: -0.2
                                        * Referenced by: '<S151>/Saturation1'
                                        */
  1.42,                                /* Expression: 1.42
                                        * Referenced by: '<S151>/ zero speed value'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S150>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Switch1'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<S150>/Saturation'
                                        */
  -0.7,                                /* Expression: -0.7
                                        * Referenced by: '<S150>/Saturation'
                                        */
  1.52,                                /* Expression: 1.52
                                        * Referenced by: '<S150>/Constant1'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/PWM1'
                                        */

  /*  Expression: [0 10 50 100 150 200]
   * Referenced by: '<Root>/Constant ( SIMULATION ONLY )'
   */
  { 0.0, 10.0, 50.0, 100.0, 150.0, 200.0 },
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S309>/Switch2'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S329>/Gain'
                                        */
  2047.0,                              /* Expression: 2047
                                        * Referenced by: '<S329>/Constant'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S240>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S247>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S247>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S248>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S246>/Constant'
                                        */
  57.295779513082323,                  /* Expression: slope
                                        * Referenced by: '<S242>/Unit Conversion'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S236>/Constant'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S244>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S244>/f'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S236>/Constant1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S328>/Gain'
                                        */
  2047.0,                              /* Expression: 2047
                                        * Referenced by: '<S328>/Constant'
                                        */
  0.005,                               /* Expression: ST
                                        * Referenced by: '<Root>/capture PWM (prova)'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<Root>/scale factor'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  30.0,                                /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Pulse Generator1'
                                        */

  /*  Computed Parameter: q_Y0
   * Referenced by: '<S107>/q'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: rpy_Y0
   * Referenced by: '<S107>/rpy'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: gyro_bias_Y0
   * Referenced by: '<S107>/gyro_bias'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: a_ned_Y0
   * Referenced by: '<S107>/a_ned'
   */
  { 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S110>/Unit Delay1'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },
  0.0F,                                /* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S110>/Unit Delay2'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay3_InitialCondition
                                        * Referenced by: '<S110>/Unit Delay3'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_i
                                        * Referenced by: '<S114>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_d
                                        * Referenced by: '<S115>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_d3
                                        * Referenced by: '<S116>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: RateTransition49_X0
                                        * Referenced by: '<Root>/Rate Transition49'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_a
                                        * Referenced by: '<S120>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_f
                                        * Referenced by: '<S121>/Switch2'
                                        */
  0.5F,                                /* Computed Parameter: Switch2_Threshold_j
                                        * Referenced by: '<S122>/Switch2'
                                        */

  /*  Computed Parameter: Constant1_Value_dr
   * Referenced by: '<S4>/Constant1'
   */
  { 0.0F, 0.0F, 0.0F },
  1551U,                               /* Computed Parameter: Rx_ID1_Value
                                        * Referenced by: '<S326>/Rx_ID1'
                                        */
  1039U,                               /* Computed Parameter: Rx_ID2_Value
                                        * Referenced by: '<S326>/Rx_ID2'
                                        */
  783U,                                /* Computed Parameter: Rx_ID3_Value
                                        * Referenced by: '<S326>/Rx_ID3'
                                        */
  527U,                                /* Computed Parameter: Rx_ID4_Value
                                        * Referenced by: '<S326>/Rx_ID4'
                                        */
  271U,                                /* Computed Parameter: Rx_ID5_Value
                                        * Referenced by: '<S326>/Rx_ID5'
                                        */
  1807U,                               /* Computed Parameter: Rx_ID6_Value
                                        * Referenced by: '<S326>/Rx_ID6'
                                        */
  0U,                                  /* Computed Parameter: RateTransition18_X0
                                        * Referenced by: '<S330>/Rate Transition18'
                                        */

  /*  Computed Parameter: Constant1_Value_e
   * Referenced by: '<S330>/Constant1'
   */
  { 0U, 0U, 0U, 0U },
  0,                                   /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S251>/Switch'
                                        */

  /*  Computed Parameter: enableall_Value
   * Referenced by: '<S309>/enable all'
   */
  { 1U, 1U, 1U, 1U, 1U, 1U },
  1U,                                  /* Computed Parameter: enable0_Value
                                        * Referenced by: '<S309>/enable 0'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S363>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S361>/Output'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S362>/FixPt Constant'
                                        */
  3U,                                  /* Computed Parameter: bmp085accuracylevel_Value
                                        * Referenced by: '<S64>/bmp085 accuracy level'
                                        */
  0U,                                  /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S330>/Rate Transition'
                                        */
  0U,                                  /* Computed Parameter: RateTransition14_X0
                                        * Referenced by: '<S330>/Rate Transition14'
                                        */
  0U,                                  /* Computed Parameter: RateTransition15_X0
                                        * Referenced by: '<S330>/Rate Transition15'
                                        */
  0U,                                  /* Computed Parameter: gpsselector2_CurrentSetting
                                        * Referenced by: '<S16>/gps selector 2'
                                        */
  0U,                                  /* Computed Parameter: gpsselector1_CurrentSetting
                                        * Referenced by: '<S16>/gps selector 1'
                                        */

  /* Start of '<Root>/clock latch' */
  {
    -1000.0                            /* Expression: -1000
                                        * Referenced by: '<S48>/Out'
                                        */
  }
  /* End of '<Root>/clock latch' */
  ,

  /* Start of '<S239>/clock latch' */
  {
    -1000.0                            /* Expression: -1000
                                        * Referenced by: '<S254>/Out'
                                        */
  }
  /* End of '<S239>/clock latch' */
  ,

  /* Start of '<S122>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S125>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S125>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S125>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S125>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S125>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S122>/Subsystem' */
  ,

  /* Start of '<S121>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S124>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S124>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S124>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S121>/Subsystem' */
  ,

  /* Start of '<S116>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S119>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S119>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S119>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S119>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S119>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S116>/Subsystem' */
  ,

  /* Start of '<S115>/Subsystem' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S118>/Constant'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S118>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S118>/Discrete-Time Integrator'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S118>/Discrete-Time Integrator1'
                                        */
    2.2204460492503131E-16             /* Expression: eps
                                        * Referenced by: '<S118>/Discrete-Time Integrator1'
                                        */
  }
  /* End of '<S115>/Subsystem' */
};

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_simple_v2_data.c
 */
