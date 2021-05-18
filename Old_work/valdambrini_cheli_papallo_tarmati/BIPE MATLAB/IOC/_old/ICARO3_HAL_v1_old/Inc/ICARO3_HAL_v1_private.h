/*
 * File: ICARO3_HAL_v1_private.h
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

#ifndef RTW_HEADER_ICARO3_HAL_v1_private_h_
#define RTW_HEADER_ICARO3_HAL_v1_private_h_
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "circular_buffer.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real32_T rt_roundf_snf(real32_T u);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void wrap_CAN_Receive_start_fcn(uint32_T*,double);
extern void wrap_CAN_Receive_output_fcn(uint8_T*,uint32_T*,double,uint8_T*);
extern void wrap_CAN_Transmit_start_fcn(void);
extern void wrap_CAN_Transmit_output_fcn(double, uint8_T*,uint8_T);
extern void wrap_I2C1_sensors_loop_start_fcn(uint8_T*, uint16_T*);
extern void wrap_I2C1_sensors_loop_output_fcn(uint8_T*, uint8_T*, uint16_T*);
extern void wrap_rcv_from_bs_start_fcn(double*, double*, double*, double*);
extern void wrap_rcv_from_bs_output_fcn(double*, double*, double*, double*);
extern void wrap_PPM_start_fcn(void);
extern void wrap_PPM_output_fcn(uint32_T*,uint8_T*,uint8_T*);
extern void wrap_raw_float_downlink_start_fcn();
extern void wrap_raw_float_downlink_output_width_fcn(float*, uint8_T);
extern void wrap_gpsparser_start_fcn();
extern void wrap_gpsparser_output_fcn(double*, double*);
extern void wrap_send_to_bs_start_fcn();
extern void wrap_send_to_bs_output_fcn(double*, double*, double*, double*,
  double*);
extern void wrap_pm_init_start_fcn();
extern void wrap_pm_init_output_fcn();
extern void wrap_PWM_start_fcn(double,double,double,double);
extern void wrap_PWM_output_fcn(real_T*,double,double,double,double);
extern void wrap_ADC_Receive_start_fcn(void);
extern void wrap_ADC_Receive_output_fcn(uint32_T*);
extern void wrap_USART2_Init_start_fcn(void);
extern void wrap_USART3_Init_start_fcn(void);
extern void wrap_USART4_Init_start_fcn(void);
extern void wrap_USART5_Init_start_fcn(void);
extern void ICARO3_HAL_v1_AttitudeFilterADIS_Init
  (rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW,
   rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_AttitudeFilterADIS_Start
  (rtB_AttitudeFilterADIS_ICARO3_HAL_v1 *localB,
   rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW,
   rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_AttitudeFilterADIS_Disable
  (rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW);
extern void ICARO3_HAL_v1_AttitudeFilterADIS(real_T rtu_Enable, const real32_T
  rtu_acc[3], const real32_T rtu_bias[3], const real32_T rtu_gyro[3], const
  real32_T rtu_mag[3], rtB_AttitudeFilterADIS_ICARO3_HAL_v1 *localB,
  rtDW_AttitudeFilterADIS_ICARO3_HAL_v1 *localDW,
  rtP_AttitudeFilterADIS_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_Subsystem_Init(rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_Subsystem_Start(rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_Subsystem(real32_T rtu_Enable, real_T rtu_In1,
  rtB_Subsystem_ICARO3_HAL_v1 *localB, rtDW_Subsystem_ICARO3_HAL_v1 *localDW,
  rtP_Subsystem_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_Subsystem_c_Init(rtDW_Subsystem_ICARO3_HAL_v1_c
  *localDW, rtP_Subsystem_ICARO3_HAL_v1_o *localP);
extern void ICARO3_HAL_v1_Subsystem_d_Start(rtDW_Subsystem_ICARO3_HAL_v1_c
  *localDW, rtP_Subsystem_ICARO3_HAL_v1_o *localP);
extern void ICARO3_HAL_v1_Subsystem_b(real32_T rtu_Enable, real_T rtu_In1,
  rtB_Subsystem_ICARO3_HAL_v1_j *localB, rtDW_Subsystem_ICARO3_HAL_v1_c *localDW,
  rtP_Subsystem_ICARO3_HAL_v1_o *localP);
extern void ICARO3_HAL_v1_MATLABFunction1(real_T rtu_vect_ned, real_T
  rtu_vect_ned_i, const real_T rtu_rpy[3], rtB_MATLABFunction1_ICARO3_HAL_v1
  *localB);
extern void ICARO3_HAL_v1_MATLABFunction2_Init
  (rtDW_MATLABFunction2_ICARO3_HAL_v1 *localDW);
extern void ICARO3_HAL_v1_MATLABFunction2(real_T rtu_u,
  rtB_MATLABFunction2_ICARO3_HAL_v1 *localB, rtDW_MATLABFunction2_ICARO3_HAL_v1 *
  localDW);
extern void ICARO3_HAL_v1_MATLABFunction6(real_T rtu_latr, real_T rtu_lonr,
  real_T rtu_lat, real_T rtu_lon, rtB_MATLABFunction6_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_hlatch(boolean_T rtu_Enable, real_T rtu_In1,
  rtB_hlatch_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_latlonlatch(boolean_T rtu_Enable, const real_T
  rtu_In1[2], rtB_latlonlatch_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_clocklatch_Start(rtB_clocklatch_ICARO3_HAL_v1 *localB,
  rtP_clocklatch_ICARO3_HAL_v1 *localP);
extern void ICARO3_HAL_v1_clocklatch(real_T rtu_Enable, real_T rtu_In,
  rtB_clocklatch_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_ChangeAsset2(const real32_T rtu_u[3],
  rtB_ChangeAsset2_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1(const uint16_T rtu_u[2],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_j(const uint32_T rtu_u[4],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_g *localB);
extern void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz1_e(uint16_T rtu_u,
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_HAL_v1_a *localB);
extern void ICARO3_HAL_v1_MATLABFunctioncomputegyroxyz4(const uint8_T rtu_u[2],
  const uint8_T rtu_u_e[2], const uint8_T rtu_u_n[2], const uint8_T rtu_u_b[2],
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_HAL_v1 *localB);
extern void ICARO3_HAL_v1_step0(void);
extern void ICARO3_HAL_v1_step1(void);
extern void ICARO3_HAL_v1_step2(void);
extern void ICARO3_HAL_v1_step3(void);
extern void ICARO3_HAL_v1_step4(void);

#endif                                 /* RTW_HEADER_ICARO3_HAL_v1_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_HAL_v1_private.h
 */
