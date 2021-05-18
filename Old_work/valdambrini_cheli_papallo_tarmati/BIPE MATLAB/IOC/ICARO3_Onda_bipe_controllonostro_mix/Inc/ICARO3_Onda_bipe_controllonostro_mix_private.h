/*
 * File: ICARO3_Onda_bipe_controllonostro_mix_private.h
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

#ifndef RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_private_h_
#define RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_private_h_
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "circular_buffer.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "circular_buffer.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real32_T rt_roundf_snf(real32_T u);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void wrap_CAN_Receive_start_fcn(uint32_T*,double);
extern void wrap_CAN_Receive_output_fcn(uint8_T*,uint32_T*,double,uint8_T*);
extern void wrap_CAN_Transmit_start_fcn(void);
extern void wrap_CAN_Transmit_output_fcn(double, uint8_T*,uint8_T);
extern void wrap_I2C1_sensors_loop_start_fcn(uint8_T*, uint16_T*);
extern void wrap_I2C1_sensors_loop_output_fcn(uint8_T*, uint8_T*, uint16_T*);
extern void wrap_UPboard_downlink_start_fcn();
extern void wrap_UPboard_downlink_output_width_fcn(float*, uint8_T);
extern void wrap_UPboard_start_fcn();
extern void wrap_UPboard_output_fcn(double*, double*);
extern void wrap_raw_float_downlink_start_fcn();
extern void wrap_raw_float_downlink_output_width_fcn(float*, uint8_T);
extern void wrap_PWM_servomotor_start_fcn(double,double,double,double);
extern void wrap_PWM_servomotor_output_fcn(real_T*,double,double,double,double);
extern void wrap_ADC_Receive_start_fcn(void);
extern void wrap_ADC_Receive_output_fcn(uint32_T*);
extern void wrap_gpsparser_UBLOX_start_fcn();
extern void wrap_gpsparser_UBLOX_output_fcn(double*, double*);
extern void wrap_USART2_Init_start_fcn(void);
extern void wrap_USART3_Init_start_fcn(void);
extern void wrap_USART4_Init_start_fcn(void);
extern void wrap_USART5_Init_start_fcn(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_Subsystem_Init
  (rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localDW,
   rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localP);
extern void ICARO3_Onda_bipe_controllonostro_mix_Subsystem_Start
  (rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localDW,
   rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localP);
extern void ICARO3_Onda_bipe_controllonostro_mix_Subsystem(real32_T rtu_Enable,
  real_T rtu_In1, rtB_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localB,
  rtDW_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localDW,
  rtP_Subsystem_ICARO3_Onda_bipe_controllonostro_mix *localP);
extern void ICARO3_Onda_bipe_controllonostro_mix_clocklatch_Start
  (rtB_clocklatch_ICARO3_Onda_bipe_controllonostro_mix *localB,
   rtP_clocklatch_ICARO3_Onda_bipe_controllonostro_mix *localP);
extern void ICARO3_Onda_bipe_controllonostro_mix_clocklatch(real_T rtu_Enable,
  real_T rtu_In, rtB_clocklatch_ICARO3_Onda_bipe_controllonostro_mix *localB);
extern void ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz1(const
  uint16_T rtu_u[2],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllonost *localB);
extern void ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_k(const
  uint32_T rtu_u[4],
  rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_f *localB);
extern void ICARO3_Onda_bipe_controllono_MATLABFunctioncomputegyroxyz1_b
  (uint16_T rtu_u,
   rtB_MATLABFunctioncomputegyroxyz1_ICARO3_Onda_bipe_controllono_j *localB);
extern void ICARO3_Onda_bipe_controllonost_MATLABFunctioncomputegyroxyz4(const
  uint8_T rtu_u[2], const uint8_T rtu_u_j[2], const uint8_T rtu_u_g[2], const
  uint8_T rtu_u_b[2],
  rtB_MATLABFunctioncomputegyroxyz4_ICARO3_Onda_bipe_controllonost *localB);
extern void ICARO3_Onda_bipe_controllonostro_mix_step0(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step1(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step2(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step3(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step4(void);
extern void ICARO3_Onda_bipe_controllonostro_mix_step5(void);

#endif                                 /* RTW_HEADER_ICARO3_Onda_bipe_controllonostro_mix_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ICARO3_Onda_bipe_controllonostro_mix_private.h
 */
