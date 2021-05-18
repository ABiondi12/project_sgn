/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_mix_sfun.h"
#include "c95_ICARO3_Onda_bipe_controllonostro_mix.h"
#include "mwmathutil.h"
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
static const char * c95_debug_family_names[7] = { "nargin", "nargout",
  "UT_bytes", "UP_bytes", "oss", "UT", "UP" };

/* Function Declarations */
static void initialize_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void initialize_params_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void enable_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void disable_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void c95_update_debugger_state_c95_ICARO3_Onda_bipe_controllonostro_m
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_st);
static void finalize_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void sf_gateway_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void c95_chartstep_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void initSimStructsc95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c95_machineNumber, uint32_T
  c95_chartNumber, uint32_T c95_instanceNumber);
static const mxArray *c95_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static uint32_T c95_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_UP, const char_T *c95_identifier);
static uint32_T c95_b_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId);
static void c95_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData);
static const mxArray *c95_b_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static uint16_T c95_c_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_UT, const char_T *c95_identifier);
static uint16_T c95_d_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId);
static void c95_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData);
static const mxArray *c95_c_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static const mxArray *c95_d_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static const mxArray *c95_e_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static const mxArray *c95_f_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static real_T c95_e_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId);
static void c95_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData);
static void c95_info_helper(const mxArray **c95_info);
static const mxArray *c95_emlrt_marshallOut(const char * c95_u);
static const mxArray *c95_b_emlrt_marshallOut(const uint32_T c95_u);
static uint8_T c95_eml_int_nbits
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);
static const mxArray *c95_g_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData);
static int32_T c95_f_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId);
static void c95_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData);
static uint8_T c95_g_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_b_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix,
   const char_T *c95_identifier);
static uint8_T c95_h_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId);
static void init_dsm_address_info
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  chartInstance->c95_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c95_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix = 0U;
}

static void initialize_params_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c95_update_debugger_state_c95_ICARO3_Onda_bipe_controllonostro_m
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  const mxArray *c95_st;
  const mxArray *c95_y = NULL;
  uint32_T c95_hoistedGlobal;
  uint32_T c95_u;
  const mxArray *c95_b_y = NULL;
  uint16_T c95_b_hoistedGlobal;
  uint16_T c95_b_u;
  const mxArray *c95_c_y = NULL;
  uint8_T c95_c_hoistedGlobal;
  uint8_T c95_c_u;
  const mxArray *c95_d_y = NULL;
  uint32_T *c95_UP;
  uint16_T *c95_UT;
  c95_UP = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c95_UT = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c95_st = NULL;
  c95_st = NULL;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_createcellmatrix(3, 1), false);
  c95_hoistedGlobal = *c95_UP;
  c95_u = c95_hoistedGlobal;
  c95_b_y = NULL;
  sf_mex_assign(&c95_b_y, sf_mex_create("y", &c95_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c95_y, 0, c95_b_y);
  c95_b_hoistedGlobal = *c95_UT;
  c95_b_u = c95_b_hoistedGlobal;
  c95_c_y = NULL;
  sf_mex_assign(&c95_c_y, sf_mex_create("y", &c95_b_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c95_y, 1, c95_c_y);
  c95_c_hoistedGlobal =
    chartInstance->c95_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix;
  c95_c_u = c95_c_hoistedGlobal;
  c95_d_y = NULL;
  sf_mex_assign(&c95_d_y, sf_mex_create("y", &c95_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c95_y, 2, c95_d_y);
  sf_mex_assign(&c95_st, c95_y, false);
  return c95_st;
}

static void set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_st)
{
  const mxArray *c95_u;
  uint32_T *c95_UP;
  uint16_T *c95_UT;
  c95_UP = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c95_UT = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c95_doneDoubleBufferReInit = true;
  c95_u = sf_mex_dup(c95_st);
  *c95_UP = c95_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c95_u,
    0)), "UP");
  *c95_UT = c95_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c95_u, 1)), "UT");
  chartInstance->c95_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix =
    c95_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c95_u, 2)),
    "is_active_c95_ICARO3_Onda_bipe_controllonostro_mix");
  sf_mex_destroy(&c95_u);
  c95_update_debugger_state_c95_ICARO3_Onda_bipe_controllonostro_m(chartInstance);
  sf_mex_destroy(&c95_st);
}

static void finalize_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  int32_T c95_i0;
  int32_T c95_i1;
  uint16_T *c95_UT;
  uint32_T *c95_UP;
  real32_T *c95_oss;
  uint32_T (*c95_UP_bytes)[3];
  uint16_T (*c95_UT_bytes)[2];
  c95_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c95_UP = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c95_UP_bytes = (uint32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c95_UT = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c95_UT_bytes = (uint16_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c95_sfEvent);
  for (c95_i0 = 0; c95_i0 < 2; c95_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c95_UT_bytes)[c95_i0], 0U);
  }

  chartInstance->c95_sfEvent = CALL_EVENT;
  c95_chartstep_c95_ICARO3_Onda_bipe_controllonostro_mix(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c95_UT, 1U);
  for (c95_i1 = 0; c95_i1 < 3; c95_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c95_UP_bytes)[c95_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c95_UP, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c95_oss, 4U);
}

static void c95_chartstep_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  real32_T c95_hoistedGlobal;
  int32_T c95_i2;
  uint16_T c95_UT_bytes[2];
  int32_T c95_i3;
  uint32_T c95_UP_bytes[3];
  real32_T c95_oss;
  uint32_T c95_debug_family_var_map[7];
  real_T c95_nargin = 3.0;
  real_T c95_nargout = 2.0;
  uint16_T c95_UT;
  uint32_T c95_UP;
  uint16_T c95_a;
  uint16_T c95_a1;
  uint16_T c95_b_a;
  uint16_T c95_c;
  uint32_T c95_u0;
  uint32_T c95_c_a;
  uint32_T c95_b_a1;
  uint32_T c95_d_a;
  uint32_T c95_b_c;
  uint32_T c95_e_a;
  uint32_T c95_c_a1;
  uint32_T c95_f_a;
  uint32_T c95_c_c;
  uint64_T c95_u1;
  uint64_T c95_u2;
  uint32_T c95_g_a;
  real32_T c95_k;
  real32_T c95_x;
  boolean_T c95_p;
  real32_T c95_b_x;
  real32_T c95_c_x;
  boolean_T c95_cond;
  int32_T c95_i4;
  static char_T c95_cv0[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    's', 'h', 'i', 'f', 't', ':', 'i', 'n', 'p', 'u', 't', 's', 'M', 'u', 's',
    't', 'B', 'e', 'I', 'n', 't', 'e', 'g', 'e', 'r', 's' };

  char_T c95_u[36];
  const mxArray *c95_y = NULL;
  uint32_T c95_d_a1;
  real32_T c95_k1;
  uint32_T c95_h_a;
  real32_T c95_b_k;
  uint32_T c95_q0;
  uint32_T c95_qY;
  uint32_T c95_u3;
  uint8_T c95_maxshift;
  uint32_T c95_i_a;
  real32_T c95_c_k;
  uint32_T c95_b_q0;
  uint32_T c95_b_qY;
  uint32_T c95_u4;
  uint8_T c95_b_maxshift;
  real32_T *c95_b_oss;
  uint16_T *c95_b_UT;
  uint32_T *c95_b_UP;
  uint32_T (*c95_b_UP_bytes)[3];
  uint16_T (*c95_b_UT_bytes)[2];
  c95_b_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c95_b_UP = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c95_b_UP_bytes = (uint32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c95_b_UT = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c95_b_UT_bytes = (uint16_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c95_sfEvent);
  c95_hoistedGlobal = *c95_b_oss;
  for (c95_i2 = 0; c95_i2 < 2; c95_i2++) {
    c95_UT_bytes[c95_i2] = (*c95_b_UT_bytes)[c95_i2];
  }

  for (c95_i3 = 0; c95_i3 < 3; c95_i3++) {
    c95_UP_bytes[c95_i3] = (*c95_b_UP_bytes)[c95_i3];
  }

  c95_oss = c95_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c95_debug_family_names,
    c95_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c95_nargin, 0U, c95_f_sf_marshallOut,
    c95_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c95_nargout, 1U, c95_f_sf_marshallOut,
    c95_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c95_UT_bytes, 2U, c95_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c95_UP_bytes, 3U, c95_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c95_oss, 4U, c95_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c95_UT, 5U, c95_b_sf_marshallOut,
    c95_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c95_UP, 6U, c95_sf_marshallOut,
    c95_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c95_sfEvent, 4);
  c95_a = c95_UT_bytes[0];
  c95_a1 = c95_a;
  c95_b_a = c95_a1;
  c95_c = (uint16_T)(c95_b_a << 8);
  c95_u0 = (uint32_T)c95_c + (uint32_T)c95_UT_bytes[1];
  if (CV_SATURATION_EVAL(4, 0, 3, 0, c95_u0 > 65535U)) {
    c95_u0 = 65535U;
  }

  c95_UT = (uint16_T)c95_u0;
  _SFD_EML_CALL(0U, chartInstance->c95_sfEvent, 6);
  c95_c_a = c95_UP_bytes[0];
  c95_b_a1 = c95_c_a;
  c95_d_a = c95_b_a1;
  c95_b_c = c95_d_a << 16U;
  c95_e_a = c95_UP_bytes[1];
  c95_c_a1 = c95_e_a;
  c95_f_a = c95_c_a1;
  c95_c_c = c95_f_a << 8U;
  c95_u1 = (uint64_T)c95_b_c + (uint64_T)c95_c_c;
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c95_u1 > 4294967295ULL)) {
    c95_u1 = 4294967295ULL;
  }

  c95_u2 = (uint64_T)(uint32_T)c95_u1 + (uint64_T)c95_UP_bytes[2];
  if (CV_SATURATION_EVAL(4, 0, 2, 0, c95_u2 > 4294967295ULL)) {
    c95_u2 = 4294967295ULL;
  }

  c95_g_a = (uint32_T)c95_u2;
  c95_k = -(8.0F - c95_oss);
  c95_UP = 0U;
  c95_x = c95_k;
  c95_p = true;
  c95_b_x = c95_x;
  c95_c_x = c95_b_x;
  c95_c_x = muSingleScalarFloor(c95_c_x);
  if (c95_x != c95_c_x) {
    c95_p = false;
  }

  c95_cond = c95_p;
  if (c95_cond) {
  } else {
    for (c95_i4 = 0; c95_i4 < 36; c95_i4++) {
      c95_u[c95_i4] = c95_cv0[c95_i4];
    }

    c95_y = NULL;
    sf_mex_assign(&c95_y, sf_mex_create("y", c95_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c95_y));
  }

  c95_d_a1 = c95_g_a;
  c95_k1 = c95_k;
  if (c95_k1 < 0.0F) {
    c95_h_a = c95_d_a1;
    c95_b_k = -c95_k1;
    c95_q0 = c95_eml_int_nbits(chartInstance);
    c95_qY = c95_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c95_qY > c95_q0)) {
      c95_qY = 0U;
    }

    c95_u3 = c95_qY;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c95_u3 > 255U)) {
      c95_u3 = 255U;
    }

    c95_maxshift = (uint8_T)c95_u3;
    if (c95_b_k <= (real32_T)c95_maxshift) {
      c95_UP = c95_h_a >> (uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        (uint32_T)_SFD_INTEGER_CHECK("", (real_T)(uint32_T)muSingleScalarRound
        (c95_b_k)), 0, 31, 1, 1);
    } else {
      c95_UP = 0U;
    }
  } else {
    c95_i_a = c95_d_a1;
    c95_c_k = c95_k1;
    c95_b_q0 = c95_eml_int_nbits(chartInstance);
    c95_b_qY = c95_b_q0 - 1U;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c95_b_qY > c95_b_q0)) {
      c95_b_qY = 0U;
    }

    c95_u4 = c95_b_qY;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c95_u4 > 255U)) {
      c95_u4 = 255U;
    }

    c95_b_maxshift = (uint8_T)c95_u4;
    if (c95_c_k <= (real32_T)c95_b_maxshift) {
      c95_UP = c95_i_a << (uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        (uint32_T)_SFD_INTEGER_CHECK("", (real_T)(uint32_T)muSingleScalarRound
        (c95_c_k)), 0, 31, 1, 1);
    } else {
      c95_UP = 0U;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c95_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c95_b_UT = c95_UT;
  *c95_b_UP = c95_UP;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c95_sfEvent);
}

static void initSimStructsc95_ICARO3_Onda_bipe_controllonostro_mix
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c95_machineNumber, uint32_T
  c95_chartNumber, uint32_T c95_instanceNumber)
{
  (void)c95_machineNumber;
  (void)c95_chartNumber;
  (void)c95_instanceNumber;
}

static const mxArray *c95_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  uint32_T c95_u;
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  c95_u = *(uint32_T *)c95_inData;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static uint32_T c95_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_UP, const char_T *c95_identifier)
{
  uint32_T c95_y;
  emlrtMsgIdentifier c95_thisId;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_UP), &c95_thisId);
  sf_mex_destroy(&c95_UP);
  return c95_y;
}

static uint32_T c95_b_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId)
{
  uint32_T c95_y;
  uint32_T c95_u5;
  (void)chartInstance;
  sf_mex_import(c95_parentId, sf_mex_dup(c95_u), &c95_u5, 1, 7, 0U, 0, 0U, 0);
  c95_y = c95_u5;
  sf_mex_destroy(&c95_u);
  return c95_y;
}

static void c95_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData)
{
  const mxArray *c95_UP;
  const char_T *c95_identifier;
  emlrtMsgIdentifier c95_thisId;
  uint32_T c95_y;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_UP = sf_mex_dup(c95_mxArrayInData);
  c95_identifier = c95_varName;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_UP), &c95_thisId);
  sf_mex_destroy(&c95_UP);
  *(uint32_T *)c95_outData = c95_y;
  sf_mex_destroy(&c95_mxArrayInData);
}

static const mxArray *c95_b_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  uint16_T c95_u;
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  c95_u = *(uint16_T *)c95_inData;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static uint16_T c95_c_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_UT, const char_T *c95_identifier)
{
  uint16_T c95_y;
  emlrtMsgIdentifier c95_thisId;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_UT), &c95_thisId);
  sf_mex_destroy(&c95_UT);
  return c95_y;
}

static uint16_T c95_d_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId)
{
  uint16_T c95_y;
  uint16_T c95_u6;
  (void)chartInstance;
  sf_mex_import(c95_parentId, sf_mex_dup(c95_u), &c95_u6, 1, 5, 0U, 0, 0U, 0);
  c95_y = c95_u6;
  sf_mex_destroy(&c95_u);
  return c95_y;
}

static void c95_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData)
{
  const mxArray *c95_UT;
  const char_T *c95_identifier;
  emlrtMsgIdentifier c95_thisId;
  uint16_T c95_y;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_UT = sf_mex_dup(c95_mxArrayInData);
  c95_identifier = c95_varName;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_UT), &c95_thisId);
  sf_mex_destroy(&c95_UT);
  *(uint16_T *)c95_outData = c95_y;
  sf_mex_destroy(&c95_mxArrayInData);
}

static const mxArray *c95_c_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  real32_T c95_u;
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  c95_u = *(real32_T *)c95_inData;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static const mxArray *c95_d_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  int32_T c95_i5;
  uint32_T c95_b_inData[3];
  int32_T c95_i6;
  uint32_T c95_u[3];
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  for (c95_i5 = 0; c95_i5 < 3; c95_i5++) {
    c95_b_inData[c95_i5] = (*(uint32_T (*)[3])c95_inData)[c95_i5];
  }

  for (c95_i6 = 0; c95_i6 < 3; c95_i6++) {
    c95_u[c95_i6] = c95_b_inData[c95_i6];
  }

  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", c95_u, 7, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static const mxArray *c95_e_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  int32_T c95_i7;
  uint16_T c95_b_inData[2];
  int32_T c95_i8;
  uint16_T c95_u[2];
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  for (c95_i7 = 0; c95_i7 < 2; c95_i7++) {
    c95_b_inData[c95_i7] = (*(uint16_T (*)[2])c95_inData)[c95_i7];
  }

  for (c95_i8 = 0; c95_i8 < 2; c95_i8++) {
    c95_u[c95_i8] = c95_b_inData[c95_i8];
  }

  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", c95_u, 5, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static const mxArray *c95_f_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  real_T c95_u;
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  c95_u = *(real_T *)c95_inData;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static real_T c95_e_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId)
{
  real_T c95_y;
  real_T c95_d0;
  (void)chartInstance;
  sf_mex_import(c95_parentId, sf_mex_dup(c95_u), &c95_d0, 1, 0, 0U, 0, 0U, 0);
  c95_y = c95_d0;
  sf_mex_destroy(&c95_u);
  return c95_y;
}

static void c95_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData)
{
  const mxArray *c95_nargout;
  const char_T *c95_identifier;
  emlrtMsgIdentifier c95_thisId;
  real_T c95_y;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_nargout = sf_mex_dup(c95_mxArrayInData);
  c95_identifier = c95_varName;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_nargout),
    &c95_thisId);
  sf_mex_destroy(&c95_nargout);
  *(real_T *)c95_outData = c95_y;
  sf_mex_destroy(&c95_mxArrayInData);
}

const mxArray
  *sf_c95_ICARO3_Onda_bipe_controllonostro_mix_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c95_nameCaptureInfo = NULL;
  c95_nameCaptureInfo = NULL;
  sf_mex_assign(&c95_nameCaptureInfo, sf_mex_createstruct("structure", 2, 21, 1),
                false);
  c95_info_helper(&c95_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c95_nameCaptureInfo);
  return c95_nameCaptureInfo;
}

static void c95_info_helper(const mxArray **c95_info)
{
  const mxArray *c95_rhs0 = NULL;
  const mxArray *c95_lhs0 = NULL;
  const mxArray *c95_rhs1 = NULL;
  const mxArray *c95_lhs1 = NULL;
  const mxArray *c95_rhs2 = NULL;
  const mxArray *c95_lhs2 = NULL;
  const mxArray *c95_rhs3 = NULL;
  const mxArray *c95_lhs3 = NULL;
  const mxArray *c95_rhs4 = NULL;
  const mxArray *c95_lhs4 = NULL;
  const mxArray *c95_rhs5 = NULL;
  const mxArray *c95_lhs5 = NULL;
  const mxArray *c95_rhs6 = NULL;
  const mxArray *c95_lhs6 = NULL;
  const mxArray *c95_rhs7 = NULL;
  const mxArray *c95_lhs7 = NULL;
  const mxArray *c95_rhs8 = NULL;
  const mxArray *c95_lhs8 = NULL;
  const mxArray *c95_rhs9 = NULL;
  const mxArray *c95_lhs9 = NULL;
  const mxArray *c95_rhs10 = NULL;
  const mxArray *c95_lhs10 = NULL;
  const mxArray *c95_rhs11 = NULL;
  const mxArray *c95_lhs11 = NULL;
  const mxArray *c95_rhs12 = NULL;
  const mxArray *c95_lhs12 = NULL;
  const mxArray *c95_rhs13 = NULL;
  const mxArray *c95_lhs13 = NULL;
  const mxArray *c95_rhs14 = NULL;
  const mxArray *c95_lhs14 = NULL;
  const mxArray *c95_rhs15 = NULL;
  const mxArray *c95_lhs15 = NULL;
  const mxArray *c95_rhs16 = NULL;
  const mxArray *c95_lhs16 = NULL;
  const mxArray *c95_rhs17 = NULL;
  const mxArray *c95_lhs17 = NULL;
  const mxArray *c95_rhs18 = NULL;
  const mxArray *c95_lhs18 = NULL;
  const mxArray *c95_rhs19 = NULL;
  const mxArray *c95_lhs19 = NULL;
  const mxArray *c95_rhs20 = NULL;
  const mxArray *c95_lhs20 = NULL;
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("bitshift"), "name", "name",
                  0);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1383877292U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c95_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c95_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 2);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c95_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c95_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c95_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 5);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c95_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 6);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c95_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 7);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c95_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c95_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c95_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 10);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 10);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c95_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c95_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("bitshift"), "name", "name",
                  12);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1383877292U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c95_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 13);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c95_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 14);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c95_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 15);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c95_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 16);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c95_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 17);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("floor"), "name", "name", 17);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c95_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c95_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 19);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c95_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!rshift"),
                  "context", "context", 20);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 20);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c95_info, c95_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c95_info, c95_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c95_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c95_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c95_info, sf_mex_duplicatearraysafe(&c95_lhs20), "lhs", "lhs",
                  20);
  sf_mex_destroy(&c95_rhs0);
  sf_mex_destroy(&c95_lhs0);
  sf_mex_destroy(&c95_rhs1);
  sf_mex_destroy(&c95_lhs1);
  sf_mex_destroy(&c95_rhs2);
  sf_mex_destroy(&c95_lhs2);
  sf_mex_destroy(&c95_rhs3);
  sf_mex_destroy(&c95_lhs3);
  sf_mex_destroy(&c95_rhs4);
  sf_mex_destroy(&c95_lhs4);
  sf_mex_destroy(&c95_rhs5);
  sf_mex_destroy(&c95_lhs5);
  sf_mex_destroy(&c95_rhs6);
  sf_mex_destroy(&c95_lhs6);
  sf_mex_destroy(&c95_rhs7);
  sf_mex_destroy(&c95_lhs7);
  sf_mex_destroy(&c95_rhs8);
  sf_mex_destroy(&c95_lhs8);
  sf_mex_destroy(&c95_rhs9);
  sf_mex_destroy(&c95_lhs9);
  sf_mex_destroy(&c95_rhs10);
  sf_mex_destroy(&c95_lhs10);
  sf_mex_destroy(&c95_rhs11);
  sf_mex_destroy(&c95_lhs11);
  sf_mex_destroy(&c95_rhs12);
  sf_mex_destroy(&c95_lhs12);
  sf_mex_destroy(&c95_rhs13);
  sf_mex_destroy(&c95_lhs13);
  sf_mex_destroy(&c95_rhs14);
  sf_mex_destroy(&c95_lhs14);
  sf_mex_destroy(&c95_rhs15);
  sf_mex_destroy(&c95_lhs15);
  sf_mex_destroy(&c95_rhs16);
  sf_mex_destroy(&c95_lhs16);
  sf_mex_destroy(&c95_rhs17);
  sf_mex_destroy(&c95_lhs17);
  sf_mex_destroy(&c95_rhs18);
  sf_mex_destroy(&c95_lhs18);
  sf_mex_destroy(&c95_rhs19);
  sf_mex_destroy(&c95_lhs19);
  sf_mex_destroy(&c95_rhs20);
  sf_mex_destroy(&c95_lhs20);
}

static const mxArray *c95_emlrt_marshallOut(const char * c95_u)
{
  const mxArray *c95_y = NULL;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", c95_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c95_u)), false);
  return c95_y;
}

static const mxArray *c95_b_emlrt_marshallOut(const uint32_T c95_u)
{
  const mxArray *c95_y = NULL;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 7, 0U, 0U, 0U, 0), false);
  return c95_y;
}

static uint8_T c95_eml_int_nbits
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return 32U;
}

static const mxArray *c95_g_sf_marshallOut(void *chartInstanceVoid, void
  *c95_inData)
{
  const mxArray *c95_mxArrayOutData = NULL;
  int32_T c95_u;
  const mxArray *c95_y = NULL;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_mxArrayOutData = NULL;
  c95_u = *(int32_T *)c95_inData;
  c95_y = NULL;
  sf_mex_assign(&c95_y, sf_mex_create("y", &c95_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c95_mxArrayOutData, c95_y, false);
  return c95_mxArrayOutData;
}

static int32_T c95_f_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId)
{
  int32_T c95_y;
  int32_T c95_i9;
  (void)chartInstance;
  sf_mex_import(c95_parentId, sf_mex_dup(c95_u), &c95_i9, 1, 6, 0U, 0, 0U, 0);
  c95_y = c95_i9;
  sf_mex_destroy(&c95_u);
  return c95_y;
}

static void c95_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c95_mxArrayInData, const char_T *c95_varName, void *c95_outData)
{
  const mxArray *c95_b_sfEvent;
  const char_T *c95_identifier;
  emlrtMsgIdentifier c95_thisId;
  int32_T c95_y;
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    chartInstanceVoid;
  c95_b_sfEvent = sf_mex_dup(c95_mxArrayInData);
  c95_identifier = c95_varName;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c95_b_sfEvent),
    &c95_thisId);
  sf_mex_destroy(&c95_b_sfEvent);
  *(int32_T *)c95_outData = c95_y;
  sf_mex_destroy(&c95_mxArrayInData);
}

static uint8_T c95_g_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_b_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix,
   const char_T *c95_identifier)
{
  uint8_T c95_y;
  emlrtMsgIdentifier c95_thisId;
  c95_thisId.fIdentifier = c95_identifier;
  c95_thisId.fParent = NULL;
  c95_y = c95_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c95_b_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix), &c95_thisId);
  sf_mex_destroy(&c95_b_is_active_c95_ICARO3_Onda_bipe_controllonostro_mix);
  return c95_y;
}

static uint8_T c95_h_emlrt_marshallIn
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance,
   const mxArray *c95_u, const emlrtMsgIdentifier *c95_parentId)
{
  uint8_T c95_y;
  uint8_T c95_u7;
  (void)chartInstance;
  sf_mex_import(c95_parentId, sf_mex_dup(c95_u), &c95_u7, 1, 3, 0U, 0, 0U, 0);
  c95_y = c95_u7;
  sf_mex_destroy(&c95_u);
  return c95_y;
}

static void init_dsm_address_info
  (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance)
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

void sf_c95_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2959305882U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(685105584U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3883796247U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4083307037U);
}

mxArray *sf_c95_ICARO3_Onda_bipe_controllonostro_mix_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1n0dOR2gqX3cOmQHv8IGbH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c95_ICARO3_Onda_bipe_controllonostro_mix_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c95_ICARO3_Onda_bipe_controllonostro_mix_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c95_ICARO3_Onda_bipe_controllonostro_mix(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"UP\",},{M[1],M[5],T\"UT\",},{M[8],M[0],T\"is_active_c95_ICARO3_Onda_bipe_controllonostro_mix\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c95_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro_mixMachineNumber_,
           95,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"UT_bytes");
          _SFD_SET_DATA_PROPS(1,2,0,1,"UT");
          _SFD_SET_DATA_PROPS(2,1,1,0,"UP_bytes");
          _SFD_SET_DATA_PROPS(3,2,0,1,"UP");
          _SFD_SET_DATA_PROPS(4,1,1,0,"oss");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,4,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,265);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,166,-1,253);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,175,-1,227);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,175,-1,241);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,75,-1,113);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c95_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c95_b_sf_marshallOut,(MexInFcnForType)
          c95_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c95_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c95_sf_marshallOut,(MexInFcnForType)c95_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c95_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint16_T *c95_UT;
          uint32_T *c95_UP;
          real32_T *c95_oss;
          uint16_T (*c95_UT_bytes)[2];
          uint32_T (*c95_UP_bytes)[3];
          c95_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c95_UP = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c95_UP_bytes = (uint32_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            1);
          c95_UT = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c95_UT_bytes = (uint16_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c95_UT_bytes);
          _SFD_SET_DATA_VALUE_PTR(1U, c95_UT);
          _SFD_SET_DATA_VALUE_PTR(2U, *c95_UP_bytes);
          _SFD_SET_DATA_VALUE_PTR(3U, c95_UP);
          _SFD_SET_DATA_VALUE_PTR(4U, c95_oss);
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
  return "DQaB4RHsc2M7nzUw5aR9cC";
}

static void sf_opaque_initialize_c95_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
  initialize_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c95_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  enable_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c95_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  disable_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c95_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  sf_gateway_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c95_ICARO3_Onda_bipe_controllonostro_mix();/* state var info */
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

extern void sf_internal_set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
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
    sf_get_sim_state_info_c95_ICARO3_Onda_bipe_controllonostro_mix();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix(SimStruct* S)
{
  return sf_internal_get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix(S);
}

static void sf_opaque_set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix(S, st);
}

static void sf_opaque_terminate_c95_ICARO3_Onda_bipe_controllonostro_mix(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_mix_optimization_info();
    }

    finalize_c95_ICARO3_Onda_bipe_controllonostro_mix
      ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
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
  initSimStructsc95_ICARO3_Onda_bipe_controllonostro_mix
    ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c95_ICARO3_Onda_bipe_controllonostro_mix
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
    initialize_params_c95_ICARO3_Onda_bipe_controllonostro_mix
      ((SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c95_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *
  S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_mix_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      95);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,95,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,95,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,95);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,95,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,95,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,95);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2190978506U));
  ssSetChecksum1(S,(1398886418U));
  ssSetChecksum2(S,(495901262U));
  ssSetChecksum3(S,(3070285531U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c95_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c95_ICARO3_Onda_bipe_controllonostro_mix(SimStruct *S)
{
  SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct *)
    utMalloc(sizeof(SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc95_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c95_ICARO3_Onda_bipe_controllonostro_mix;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c95_ICARO3_Onda_bipe_controllonostro_mix;
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

void c95_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c95_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c95_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c95_ICARO3_Onda_bipe_controllonostro_mix(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c95_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
