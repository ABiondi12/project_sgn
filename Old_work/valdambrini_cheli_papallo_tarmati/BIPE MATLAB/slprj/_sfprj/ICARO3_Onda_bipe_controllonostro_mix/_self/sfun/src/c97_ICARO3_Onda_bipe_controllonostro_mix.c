/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_mix_sfun.h"
#include "c97_ICARO3_Onda_bipe_controllonostro_mix.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_controllonostro_mix_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c97_debug_family_names[9] = { "ax", "ay", "az", "a_adxl",
  "nargin", "nargout", "u", "adxl345_enabled", "a" };

static const char * c97_b_debug_family_names[4] = { "u", "nargin", "nargout",
  "y" };

/* Function Declarations */
static void initialize_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void initialize_params_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void enable_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void disable_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void c97_update_debugger_state_c97_ICARO3_Onda_bipe_controllonostro_m
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_st);
static void finalize_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void sf_gateway_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void c97_chartstep_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void initSimStructsc97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c97_machineNumber, uint32_T
  c97_chartNumber, uint32_T c97_instanceNumber);
static const mxArray *c97_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static void c97_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_a, const char_T *c97_identifier, real32_T c97_y[3]);
static void c97_b_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId, real32_T c97_y
   [3]);
static void c97_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData);
static const mxArray *c97_b_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static const mxArray *c97_c_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static const mxArray *c97_d_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static real_T c97_c_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId);
static void c97_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData);
static const mxArray *c97_e_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static real32_T c97_d_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId);
static void c97_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData);
static const mxArray *c97_f_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static uint16_T c97_e_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId);
static void c97_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData);
static void c97_info_helper(const mxArray **c97_info);
static const mxArray *c97_emlrt_marshallOut(const char * c97_u);
static const mxArray *c97_b_emlrt_marshallOut(const uint32_T c97_u);
static real32_T c97_decomp
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   uint16_T c97_u);
static const mxArray *c97_g_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData);
static int32_T c97_f_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId);
static void c97_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData);
static uint8_T c97_g_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_b_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix,
   const char_T *c97_identifier);
static uint8_T c97_h_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId);
static void init_dsm_address_info
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  chartInstance->c97_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c97_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix = 0U;
}

static void initialize_params_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c97_update_debugger_state_c97_ICARO3_Onda_bipe_controllonostro_m
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  const mxArray *c97_st;
  const mxArray *c97_y = NULL;
  int32_T c97_i0;
  real32_T c97_u[3];
  const mxArray *c97_b_y = NULL;
  uint8_T c97_hoistedGlobal;
  uint8_T c97_b_u;
  const mxArray *c97_c_y = NULL;
  real32_T (*c97_a)[3];
  c97_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c97_st = NULL;
  c97_st = NULL;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_createcellmatrix(2, 1), false);
  for (c97_i0 = 0; c97_i0 < 3; c97_i0++) {
    c97_u[c97_i0] = (*c97_a)[c97_i0];
  }

  c97_b_y = NULL;
  sf_mex_assign(&c97_b_y, sf_mex_create("y", c97_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c97_y, 0, c97_b_y);
  c97_hoistedGlobal =
    chartInstance->c97_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix;
  c97_b_u = c97_hoistedGlobal;
  c97_c_y = NULL;
  sf_mex_assign(&c97_c_y, sf_mex_create("y", &c97_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c97_y, 1, c97_c_y);
  sf_mex_assign(&c97_st, c97_y, false);
  return c97_st;
}

static void set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_st)
{
  const mxArray *c97_u;
  real32_T c97_fv0[3];
  int32_T c97_i1;
  real32_T (*c97_a)[3];
  c97_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c97_doneDoubleBufferReInit = true;
  c97_u = sf_mex_dup(c97_st);
  c97_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c97_u, 0)), "a",
                       c97_fv0);
  for (c97_i1 = 0; c97_i1 < 3; c97_i1++) {
    (*c97_a)[c97_i1] = c97_fv0[c97_i1];
  }

  chartInstance->c97_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix =
    c97_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c97_u, 1)),
    "is_active_c97_ICARO3_Onda_bipe_controllonostro_mix");
  sf_mex_destroy(&c97_u);
  c97_update_debugger_state_c97_ICARO3_Onda_bipe_controllonostro_m(chartInstance);
  sf_mex_destroy(&c97_st);
}

static void finalize_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  int32_T c97_i2;
  int32_T c97_i3;
  uint8_T *c97_adxl345_enabled;
  real32_T (*c97_a)[3];
  uint16_T (*c97_u)[6];
  c97_adxl345_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c97_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c97_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c97_sfEvent);
  for (c97_i2 = 0; c97_i2 < 6; c97_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c97_u)[c97_i2], 0U);
  }

  chartInstance->c97_sfEvent = CALL_EVENT;
  c97_chartstep_c97_ICARO3_Onda_bipe_controllonostro_mix(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c97_i3 = 0; c97_i3 < 3; c97_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c97_a)[c97_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c97_adxl345_enabled, 2U);
}

static void c97_chartstep_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  uint8_T c97_hoistedGlobal;
  int32_T c97_i4;
  uint16_T c97_u[6];
  uint8_T c97_adxl345_enabled;
  uint32_T c97_debug_family_var_map[9];
  real32_T c97_ax;
  real32_T c97_ay;
  real32_T c97_az;
  real32_T c97_a_adxl[3];
  real_T c97_nargin = 2.0;
  real_T c97_nargout = 1.0;
  real32_T c97_a[3];
  int32_T c97_i5;
  uint16_T c97_b_a[6];
  int32_T c97_i6;
  uint16_T c97_c_a;
  uint16_T c97_a1;
  uint16_T c97_d_a;
  uint16_T c97_c;
  uint32_T c97_u0;
  real32_T c97_A;
  real32_T c97_x;
  real32_T c97_b_x;
  real32_T c97_c_x;
  real32_T c97_y;
  real32_T c97_e_a;
  uint16_T c97_f_a;
  uint16_T c97_b_a1;
  uint16_T c97_g_a;
  uint16_T c97_b_c;
  uint32_T c97_u1;
  real32_T c97_b_A;
  real32_T c97_d_x;
  real32_T c97_e_x;
  real32_T c97_f_x;
  real32_T c97_b_y;
  real32_T c97_h_a;
  uint16_T c97_i_a;
  uint16_T c97_c_a1;
  uint16_T c97_j_a;
  uint16_T c97_c_c;
  uint32_T c97_u2;
  real32_T c97_c_A;
  real32_T c97_g_x;
  real32_T c97_h_x;
  real32_T c97_i_x;
  real32_T c97_c_y;
  real32_T c97_k_a;
  int32_T c97_i7;
  real32_T c97_b[3];
  int32_T c97_i8;
  int32_T c97_i9;
  int32_T c97_i10;
  static real32_T c97_fv1[9] = { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F,
    1.0F };

  int32_T c97_i11;
  uint8_T *c97_b_adxl345_enabled;
  real32_T (*c97_l_a)[3];
  uint16_T (*c97_b_u)[6];
  c97_b_adxl345_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c97_l_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c97_b_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c97_sfEvent);
  c97_hoistedGlobal = *c97_b_adxl345_enabled;
  for (c97_i4 = 0; c97_i4 < 6; c97_i4++) {
    c97_u[c97_i4] = (*c97_b_u)[c97_i4];
  }

  c97_adxl345_enabled = c97_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c97_debug_family_names,
    c97_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_ax, 0U, c97_e_sf_marshallOut,
    c97_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_ay, 1U, c97_e_sf_marshallOut,
    c97_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_az, 2U, c97_e_sf_marshallOut,
    c97_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c97_a_adxl, 3U, c97_sf_marshallOut,
    c97_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_nargin, 4U, c97_d_sf_marshallOut,
    c97_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_nargout, 5U, c97_d_sf_marshallOut,
    c97_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c97_u, 6U, c97_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c97_adxl345_enabled, 7U, c97_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c97_a, 8U, c97_sf_marshallOut,
    c97_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, (real_T)c97_adxl345_enabled == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 4);
    for (c97_i5 = 0; c97_i5 < 6; c97_i5++) {
      c97_b_a[c97_i5] = c97_u[c97_i5];
    }

    for (c97_i6 = 0; c97_i6 < 6; c97_i6++) {
      c97_u[c97_i6] = 0U;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 7);
  c97_c_a = c97_u[1];
  c97_a1 = c97_c_a;
  c97_d_a = c97_a1;
  c97_c = (uint16_T)(c97_d_a << 8);
  c97_u0 = (uint32_T)c97_c + (uint32_T)c97_u[0];
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c97_u0 > 65535U)) {
    c97_u0 = 65535U;
  }

  c97_A = c97_decomp(chartInstance, (uint16_T)c97_u0);
  c97_x = c97_A;
  c97_b_x = c97_x;
  c97_c_x = c97_b_x;
  c97_y = c97_c_x / 256.0F;
  c97_e_a = c97_y;
  c97_ax = c97_e_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 8);
  c97_f_a = c97_u[3];
  c97_b_a1 = c97_f_a;
  c97_g_a = c97_b_a1;
  c97_b_c = (uint16_T)(c97_g_a << 8);
  c97_u1 = (uint32_T)c97_b_c + (uint32_T)c97_u[2];
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c97_u1 > 65535U)) {
    c97_u1 = 65535U;
  }

  c97_b_A = c97_decomp(chartInstance, (uint16_T)c97_u1);
  c97_d_x = c97_b_A;
  c97_e_x = c97_d_x;
  c97_f_x = c97_e_x;
  c97_b_y = c97_f_x / 256.0F;
  c97_h_a = c97_b_y;
  c97_ay = c97_h_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 9);
  c97_i_a = c97_u[5];
  c97_c_a1 = c97_i_a;
  c97_j_a = c97_c_a1;
  c97_c_c = (uint16_T)(c97_j_a << 8);
  c97_u2 = (uint32_T)c97_c_c + (uint32_T)c97_u[4];
  if (CV_SATURATION_EVAL(4, 0, 2, 0, c97_u2 > 65535U)) {
    c97_u2 = 65535U;
  }

  c97_c_A = c97_decomp(chartInstance, (uint16_T)c97_u2);
  c97_g_x = c97_c_A;
  c97_h_x = c97_g_x;
  c97_i_x = c97_h_x;
  c97_c_y = c97_i_x / 256.0F;
  c97_k_a = c97_c_y;
  c97_az = c97_k_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 11);
  c97_a_adxl[0] = c97_ax;
  c97_a_adxl[1] = c97_ay;
  c97_a_adxl[2] = c97_az;
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 15);
  for (c97_i7 = 0; c97_i7 < 3; c97_i7++) {
    c97_b[c97_i7] = c97_a_adxl[c97_i7];
  }

  for (c97_i8 = 0; c97_i8 < 3; c97_i8++) {
    c97_a[c97_i8] = 0.0F;
    c97_i9 = 0;
    for (c97_i10 = 0; c97_i10 < 3; c97_i10++) {
      c97_a[c97_i8] += c97_fv1[c97_i9 + c97_i8] * c97_b[c97_i10];
      c97_i9 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  for (c97_i11 = 0; c97_i11 < 3; c97_i11++) {
    (*c97_l_a)[c97_i11] = c97_a[c97_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c97_sfEvent);
}

static void initSimStructsc97_ICARO3_Onda_bipe_controllonostro_mix
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c97_machineNumber, uint32_T
  c97_chartNumber, uint32_T c97_instanceNumber)
{
  (void)c97_machineNumber;
  (void)c97_chartNumber;
  (void)c97_instanceNumber;
}

static const mxArray *c97_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  int32_T c97_i12;
  real32_T c97_b_inData[3];
  int32_T c97_i13;
  real32_T c97_u[3];
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  for (c97_i12 = 0; c97_i12 < 3; c97_i12++) {
    c97_b_inData[c97_i12] = (*(real32_T (*)[3])c97_inData)[c97_i12];
  }

  for (c97_i13 = 0; c97_i13 < 3; c97_i13++) {
    c97_u[c97_i13] = c97_b_inData[c97_i13];
  }

  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", c97_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static void c97_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_a, const char_T *c97_identifier, real32_T c97_y[3])
{
  emlrtMsgIdentifier c97_thisId;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_a), &c97_thisId, c97_y);
  sf_mex_destroy(&c97_a);
}

static void c97_b_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId, real32_T c97_y
   [3])
{
  real32_T c97_fv2[3];
  int32_T c97_i14;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), c97_fv2, 1, 1, 0U, 1, 0U, 1, 3);
  for (c97_i14 = 0; c97_i14 < 3; c97_i14++) {
    c97_y[c97_i14] = c97_fv2[c97_i14];
  }

  sf_mex_destroy(&c97_u);
}

static void c97_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData)
{
  const mxArray *c97_a;
  const char_T *c97_identifier;
  emlrtMsgIdentifier c97_thisId;
  real32_T c97_y[3];
  int32_T c97_i15;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_a = sf_mex_dup(c97_mxArrayInData);
  c97_identifier = c97_varName;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_a), &c97_thisId, c97_y);
  sf_mex_destroy(&c97_a);
  for (c97_i15 = 0; c97_i15 < 3; c97_i15++) {
    (*(real32_T (*)[3])c97_outData)[c97_i15] = c97_y[c97_i15];
  }

  sf_mex_destroy(&c97_mxArrayInData);
}

static const mxArray *c97_b_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  uint8_T c97_u;
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  c97_u = *(uint8_T *)c97_inData;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static const mxArray *c97_c_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  int32_T c97_i16;
  uint16_T c97_b_inData[6];
  int32_T c97_i17;
  uint16_T c97_u[6];
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  for (c97_i16 = 0; c97_i16 < 6; c97_i16++) {
    c97_b_inData[c97_i16] = (*(uint16_T (*)[6])c97_inData)[c97_i16];
  }

  for (c97_i17 = 0; c97_i17 < 6; c97_i17++) {
    c97_u[c97_i17] = c97_b_inData[c97_i17];
  }

  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", c97_u, 5, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static const mxArray *c97_d_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  real_T c97_u;
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  c97_u = *(real_T *)c97_inData;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static real_T c97_c_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId)
{
  real_T c97_y;
  real_T c97_d0;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), &c97_d0, 1, 0, 0U, 0, 0U, 0);
  c97_y = c97_d0;
  sf_mex_destroy(&c97_u);
  return c97_y;
}

static void c97_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData)
{
  const mxArray *c97_nargout;
  const char_T *c97_identifier;
  emlrtMsgIdentifier c97_thisId;
  real_T c97_y;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_nargout = sf_mex_dup(c97_mxArrayInData);
  c97_identifier = c97_varName;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_y = c97_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_nargout),
    &c97_thisId);
  sf_mex_destroy(&c97_nargout);
  *(real_T *)c97_outData = c97_y;
  sf_mex_destroy(&c97_mxArrayInData);
}

static const mxArray *c97_e_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  real32_T c97_u;
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  c97_u = *(real32_T *)c97_inData;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static real32_T c97_d_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId)
{
  real32_T c97_y;
  real32_T c97_f0;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), &c97_f0, 1, 1, 0U, 0, 0U, 0);
  c97_y = c97_f0;
  sf_mex_destroy(&c97_u);
  return c97_y;
}

static void c97_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData)
{
  const mxArray *c97_az;
  const char_T *c97_identifier;
  emlrtMsgIdentifier c97_thisId;
  real32_T c97_y;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_az = sf_mex_dup(c97_mxArrayInData);
  c97_identifier = c97_varName;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_y = c97_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_az), &c97_thisId);
  sf_mex_destroy(&c97_az);
  *(real32_T *)c97_outData = c97_y;
  sf_mex_destroy(&c97_mxArrayInData);
}

static const mxArray *c97_f_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  uint16_T c97_u;
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  c97_u = *(uint16_T *)c97_inData;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static uint16_T c97_e_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId)
{
  uint16_T c97_y;
  uint16_T c97_u3;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), &c97_u3, 1, 5, 0U, 0, 0U, 0);
  c97_y = c97_u3;
  sf_mex_destroy(&c97_u);
  return c97_y;
}

static void c97_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData)
{
  const mxArray *c97_u;
  const char_T *c97_identifier;
  emlrtMsgIdentifier c97_thisId;
  uint16_T c97_y;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_u = sf_mex_dup(c97_mxArrayInData);
  c97_identifier = c97_varName;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_y = c97_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_u), &c97_thisId);
  sf_mex_destroy(&c97_u);
  *(uint16_T *)c97_outData = c97_y;
  sf_mex_destroy(&c97_mxArrayInData);
}

const mxArray
  *sf_c97_ICARO3_Onda_bipe_controllonostro_mix_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c97_nameCaptureInfo = NULL;
  c97_nameCaptureInfo = NULL;
  sf_mex_assign(&c97_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c97_info_helper(&c97_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c97_nameCaptureInfo);
  return c97_nameCaptureInfo;
}

static void c97_info_helper(const mxArray **c97_info)
{
  const mxArray *c97_rhs0 = NULL;
  const mxArray *c97_lhs0 = NULL;
  const mxArray *c97_rhs1 = NULL;
  const mxArray *c97_lhs1 = NULL;
  const mxArray *c97_rhs2 = NULL;
  const mxArray *c97_lhs2 = NULL;
  const mxArray *c97_rhs3 = NULL;
  const mxArray *c97_lhs3 = NULL;
  const mxArray *c97_rhs4 = NULL;
  const mxArray *c97_lhs4 = NULL;
  const mxArray *c97_rhs5 = NULL;
  const mxArray *c97_lhs5 = NULL;
  const mxArray *c97_rhs6 = NULL;
  const mxArray *c97_lhs6 = NULL;
  const mxArray *c97_rhs7 = NULL;
  const mxArray *c97_lhs7 = NULL;
  const mxArray *c97_rhs8 = NULL;
  const mxArray *c97_lhs8 = NULL;
  const mxArray *c97_rhs9 = NULL;
  const mxArray *c97_lhs9 = NULL;
  const mxArray *c97_rhs10 = NULL;
  const mxArray *c97_lhs10 = NULL;
  const mxArray *c97_rhs11 = NULL;
  const mxArray *c97_lhs11 = NULL;
  const mxArray *c97_rhs12 = NULL;
  const mxArray *c97_lhs12 = NULL;
  const mxArray *c97_rhs13 = NULL;
  const mxArray *c97_lhs13 = NULL;
  const mxArray *c97_rhs14 = NULL;
  const mxArray *c97_lhs14 = NULL;
  const mxArray *c97_rhs15 = NULL;
  const mxArray *c97_lhs15 = NULL;
  const mxArray *c97_rhs16 = NULL;
  const mxArray *c97_lhs16 = NULL;
  const mxArray *c97_rhs17 = NULL;
  const mxArray *c97_lhs17 = NULL;
  const mxArray *c97_rhs18 = NULL;
  const mxArray *c97_lhs18 = NULL;
  const mxArray *c97_rhs19 = NULL;
  const mxArray *c97_lhs19 = NULL;
  const mxArray *c97_rhs20 = NULL;
  const mxArray *c97_lhs20 = NULL;
  const mxArray *c97_rhs21 = NULL;
  const mxArray *c97_lhs21 = NULL;
  const mxArray *c97_rhs22 = NULL;
  const mxArray *c97_lhs22 = NULL;
  const mxArray *c97_rhs23 = NULL;
  const mxArray *c97_lhs23 = NULL;
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c97_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c97_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c97_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("bitshift"), "name", "name",
                  3);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1383877292U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c97_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c97_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c97_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c97_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c97_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 8);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c97_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 9);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c97_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 10);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("floor"), "name", "name", 10);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c97_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c97_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 12);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c97_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 13);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 13);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c97_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c97_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("mrdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c97_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 16);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 16);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c97_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("rdivide"), "name", "name",
                  17);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c97_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c97_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c97_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 20);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c97_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("eml_div"), "name", "name",
                  21);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c97_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 22);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c97_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 23);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c97_info, c97_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c97_info, c97_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c97_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c97_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c97_info, sf_mex_duplicatearraysafe(&c97_lhs23), "lhs", "lhs",
                  23);
  sf_mex_destroy(&c97_rhs0);
  sf_mex_destroy(&c97_lhs0);
  sf_mex_destroy(&c97_rhs1);
  sf_mex_destroy(&c97_lhs1);
  sf_mex_destroy(&c97_rhs2);
  sf_mex_destroy(&c97_lhs2);
  sf_mex_destroy(&c97_rhs3);
  sf_mex_destroy(&c97_lhs3);
  sf_mex_destroy(&c97_rhs4);
  sf_mex_destroy(&c97_lhs4);
  sf_mex_destroy(&c97_rhs5);
  sf_mex_destroy(&c97_lhs5);
  sf_mex_destroy(&c97_rhs6);
  sf_mex_destroy(&c97_lhs6);
  sf_mex_destroy(&c97_rhs7);
  sf_mex_destroy(&c97_lhs7);
  sf_mex_destroy(&c97_rhs8);
  sf_mex_destroy(&c97_lhs8);
  sf_mex_destroy(&c97_rhs9);
  sf_mex_destroy(&c97_lhs9);
  sf_mex_destroy(&c97_rhs10);
  sf_mex_destroy(&c97_lhs10);
  sf_mex_destroy(&c97_rhs11);
  sf_mex_destroy(&c97_lhs11);
  sf_mex_destroy(&c97_rhs12);
  sf_mex_destroy(&c97_lhs12);
  sf_mex_destroy(&c97_rhs13);
  sf_mex_destroy(&c97_lhs13);
  sf_mex_destroy(&c97_rhs14);
  sf_mex_destroy(&c97_lhs14);
  sf_mex_destroy(&c97_rhs15);
  sf_mex_destroy(&c97_lhs15);
  sf_mex_destroy(&c97_rhs16);
  sf_mex_destroy(&c97_lhs16);
  sf_mex_destroy(&c97_rhs17);
  sf_mex_destroy(&c97_lhs17);
  sf_mex_destroy(&c97_rhs18);
  sf_mex_destroy(&c97_lhs18);
  sf_mex_destroy(&c97_rhs19);
  sf_mex_destroy(&c97_lhs19);
  sf_mex_destroy(&c97_rhs20);
  sf_mex_destroy(&c97_lhs20);
  sf_mex_destroy(&c97_rhs21);
  sf_mex_destroy(&c97_lhs21);
  sf_mex_destroy(&c97_rhs22);
  sf_mex_destroy(&c97_lhs22);
  sf_mex_destroy(&c97_rhs23);
  sf_mex_destroy(&c97_lhs23);
}

static const mxArray *c97_emlrt_marshallOut(const char * c97_u)
{
  const mxArray *c97_y = NULL;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", c97_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c97_u)), false);
  return c97_y;
}

static const mxArray *c97_b_emlrt_marshallOut(const uint32_T c97_u)
{
  const mxArray *c97_y = NULL;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 7, 0U, 0U, 0U, 0), false);
  return c97_y;
}

static real32_T c97_decomp
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   uint16_T c97_u)
{
  real32_T c97_y;
  uint32_T c97_debug_family_var_map[4];
  real32_T c97_b_u;
  real_T c97_nargin = 1.0;
  real_T c97_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c97_b_debug_family_names,
    c97_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_b_u, MAX_uint32_T,
    c97_e_sf_marshallOut, c97_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_nargin, 1U, c97_d_sf_marshallOut,
    c97_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_nargout, 2U, c97_d_sf_marshallOut,
    c97_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_u, 0U, c97_f_sf_marshallOut,
    c97_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c97_y, 3U, c97_e_sf_marshallOut,
    c97_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 19);
  c97_b_u = (real32_T)c97_u;
  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 21);
  if (CV_EML_IF(0, 1, 1, c97_b_u > 32767.0F)) {
    _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 22);
    c97_y = -65536.0F + c97_b_u;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, 24);
    c97_y = c97_b_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c97_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  return c97_y;
}

static const mxArray *c97_g_sf_marshallOut(void *chartInstanceVoid, void
  *c97_inData)
{
  const mxArray *c97_mxArrayOutData = NULL;
  int32_T c97_u;
  const mxArray *c97_y = NULL;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_mxArrayOutData = NULL;
  c97_u = *(int32_T *)c97_inData;
  c97_y = NULL;
  sf_mex_assign(&c97_y, sf_mex_create("y", &c97_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c97_mxArrayOutData, c97_y, false);
  return c97_mxArrayOutData;
}

static int32_T c97_f_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId)
{
  int32_T c97_y;
  int32_T c97_i18;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), &c97_i18, 1, 6, 0U, 0, 0U, 0);
  c97_y = c97_i18;
  sf_mex_destroy(&c97_u);
  return c97_y;
}

static void c97_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c97_mxArrayInData, const char_T *c97_varName, void *c97_outData)
{
  const mxArray *c97_b_sfEvent;
  const char_T *c97_identifier;
  emlrtMsgIdentifier c97_thisId;
  int32_T c97_y;
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c97_b_sfEvent = sf_mex_dup(c97_mxArrayInData);
  c97_identifier = c97_varName;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_y = c97_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c97_b_sfEvent),
    &c97_thisId);
  sf_mex_destroy(&c97_b_sfEvent);
  *(int32_T *)c97_outData = c97_y;
  sf_mex_destroy(&c97_mxArrayInData);
}

static uint8_T c97_g_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_b_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix,
   const char_T *c97_identifier)
{
  uint8_T c97_y;
  emlrtMsgIdentifier c97_thisId;
  c97_thisId.fIdentifier = c97_identifier;
  c97_thisId.fParent = NULL;
  c97_y = c97_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c97_b_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix), &c97_thisId);
  sf_mex_destroy(&c97_b_is_active_c97_ICARO3_Onda_bipe_controllonostro_mix);
  return c97_y;
}

static uint8_T c97_h_emlrt_marshallIn
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c97_u, const emlrtMsgIdentifier *c97_parentId)
{
  uint8_T c97_y;
  uint8_T c97_u4;
  (void)chartInstance;
  sf_mex_import(c97_parentId, sf_mex_dup(c97_u), &c97_u4, 1, 3, 0U, 0, 0U, 0);
  c97_y = c97_u4;
  sf_mex_destroy(&c97_u);
  return c97_y;
}

static void init_dsm_address_info
  (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c97_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2193053020U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(760991859U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2743841049U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3339858624U);
}

mxArray *sf_c97_ICARO3_Onda_bipe_controllonostro_mix_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("weE4U3gemlZgduLCkgE2u");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c97_ICARO3_Onda_bipe_controllonostro_mix_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c97_ICARO3_Onda_bipe_controllonostro_mix_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c97_ICARO3_Onda_bipe_controllonostro_mix(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"a\",},{M[8],M[0],T\"is_active_c97_ICARO3_Onda_bipe_controllonostro_mix\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c97_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
           97,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation
          (_ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a");
          _SFD_SET_DATA_PROPS(2,1,1,0,"adxl345_enabled");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,2,0,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,350);
        _SFD_CV_INIT_EML_FCN(0,1,"decomp",352,-1,465);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,107,-1,131);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,157,-1,181);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,207,-1,231);
        _SFD_CV_INIT_EML_IF(0,1,0,51,76,-1,93);
        _SFD_CV_INIT_EML_IF(0,1,1,391,405,434,461);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c97_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c97_sf_marshallOut,(MexInFcnForType)
            c97_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c97_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint8_T *c97_adxl345_enabled;
          uint16_T (*c97_u)[6];
          real32_T (*c97_a)[3];
          c97_adxl345_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c97_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c97_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c97_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c97_a);
          _SFD_SET_DATA_VALUE_PTR(2U, c97_adxl345_enabled);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ypn7bWcbhprfGcbJXHsGG";
}

static void sf_opaque_initialize_c97_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
  initialize_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c97_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  enable_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c97_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  disable_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c97_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  sf_gateway_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c97_ICARO3_Onda_bipe_controllonostro_mix();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*)
    sf_get_sim_state_info_c97_ICARO3_Onda_bipe_controllonostro_mix();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix(SimStruct* S)
{
  return sf_internal_get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix(S);
}

static void sf_opaque_set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix(S, st);
}

static void sf_opaque_terminate_c97_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_mix_optimization_info();
    }

    finalize_c97_ICARO3_Onda_bipe_controllonostro_mix
      ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc97_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c97_ICARO3_Onda_bipe_controllonostro_mix
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c97_ICARO3_Onda_bipe_controllonostro_mix
      ((SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c97_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *
  S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_mix_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      97);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,97,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,97,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,97);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,97,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,97,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,97);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(542938830U));
  ssSetChecksum1(S,(3346859147U));
  ssSetChecksum2(S,(3565820429U));
  ssSetChecksum3(S,(2737723090U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c97_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c97_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *S)
{
  SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    utMalloc(sizeof(SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc97_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c97_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c97_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c97_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c97_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c97_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c97_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
