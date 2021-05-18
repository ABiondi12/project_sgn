/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_simple_v2_media_fun_sfun.h"
#include "c164_ICARO3_Onda_simple_v2_media_fun.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_simple_v2_media_fun_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c164_debug_family_names[8] = { "n", "mid", "nargin",
  "nargout", "u", "x_mean", "tag_old", "tag_new" };

/* Function Declarations */
static void initialize_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void initialize_params_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void enable_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void disable_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void c164_update_debugger_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_st);
static void finalize_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void sf_gateway_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void c164_chartstep_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void initSimStructsc164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c164_machineNumber, uint32_T
  c164_chartNumber, uint32_T c164_instanceNumber);
static const mxArray *c164_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData);
static void c164_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_tag_new, const char_T *c164_identifier, real_T c164_y[100]);
static void c164_b_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId, real_T c164_y[100]);
static void c164_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData);
static const mxArray *c164_b_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData);
static void c164_c_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_tag_old, const char_T *c164_identifier, real_T c164_y[100]);
static void c164_d_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId, real_T c164_y[100]);
static void c164_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData);
static const mxArray *c164_c_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData);
static real_T c164_e_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_x_mean, const char_T *c164_identifier);
static real_T c164_f_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId);
static void c164_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData);
static const mxArray *c164_d_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData);
static void c164_info_helper(const mxArray **c164_info);
static const mxArray *c164_emlrt_marshallOut(const char * c164_u);
static const mxArray *c164_b_emlrt_marshallOut(const uint32_T c164_u);
static const mxArray *c164_e_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData);
static int32_T c164_g_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId);
static void c164_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData);
static uint8_T c164_h_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_is_active_c164_ICARO3_Onda_simple_v2_media_fun, const char_T *
   c164_identifier);
static uint8_T c164_i_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId);
static void init_dsm_address_info
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  chartInstance->c164_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c164_tag_old_not_empty = false;
  chartInstance->c164_tag_new_not_empty = false;
  chartInstance->c164_is_active_c164_ICARO3_Onda_simple_v2_media_fun = 0U;
}

static void initialize_params_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c164_update_debugger_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  const mxArray *c164_st;
  const mxArray *c164_y = NULL;
  real_T c164_hoistedGlobal;
  real_T c164_u;
  const mxArray *c164_b_y = NULL;
  int32_T c164_i0;
  real_T c164_b_u[100];
  const mxArray *c164_c_y = NULL;
  int32_T c164_i1;
  real_T c164_c_u[100];
  const mxArray *c164_d_y = NULL;
  uint8_T c164_b_hoistedGlobal;
  uint8_T c164_d_u;
  const mxArray *c164_e_y = NULL;
  real_T *c164_x_mean;
  c164_x_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c164_st = NULL;
  c164_st = NULL;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_createcellmatrix(4, 1), false);
  c164_hoistedGlobal = *c164_x_mean;
  c164_u = c164_hoistedGlobal;
  c164_b_y = NULL;
  sf_mex_assign(&c164_b_y, sf_mex_create("y", &c164_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c164_y, 0, c164_b_y);
  for (c164_i0 = 0; c164_i0 < 100; c164_i0++) {
    c164_b_u[c164_i0] = chartInstance->c164_tag_new[c164_i0];
  }

  c164_c_y = NULL;
  if (!chartInstance->c164_tag_new_not_empty) {
    sf_mex_assign(&c164_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c164_c_y, sf_mex_create("y", c164_b_u, 0, 0U, 1U, 0U, 2, 1,
      100), false);
  }

  sf_mex_setcell(c164_y, 1, c164_c_y);
  for (c164_i1 = 0; c164_i1 < 100; c164_i1++) {
    c164_c_u[c164_i1] = chartInstance->c164_tag_old[c164_i1];
  }

  c164_d_y = NULL;
  if (!chartInstance->c164_tag_old_not_empty) {
    sf_mex_assign(&c164_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c164_d_y, sf_mex_create("y", c164_c_u, 0, 0U, 1U, 0U, 2, 1,
      100), false);
  }

  sf_mex_setcell(c164_y, 2, c164_d_y);
  c164_b_hoistedGlobal =
    chartInstance->c164_is_active_c164_ICARO3_Onda_simple_v2_media_fun;
  c164_d_u = c164_b_hoistedGlobal;
  c164_e_y = NULL;
  sf_mex_assign(&c164_e_y, sf_mex_create("y", &c164_d_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c164_y, 3, c164_e_y);
  sf_mex_assign(&c164_st, c164_y, false);
  return c164_st;
}

static void set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_st)
{
  const mxArray *c164_u;
  real_T c164_dv0[100];
  int32_T c164_i2;
  real_T c164_dv1[100];
  int32_T c164_i3;
  real_T *c164_x_mean;
  c164_x_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c164_doneDoubleBufferReInit = true;
  c164_u = sf_mex_dup(c164_st);
  *c164_x_mean = c164_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c164_u, 0)), "x_mean");
  c164_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c164_u, 1)),
                        "tag_new", c164_dv0);
  for (c164_i2 = 0; c164_i2 < 100; c164_i2++) {
    chartInstance->c164_tag_new[c164_i2] = c164_dv0[c164_i2];
  }

  c164_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c164_u, 2)),
    "tag_old", c164_dv1);
  for (c164_i3 = 0; c164_i3 < 100; c164_i3++) {
    chartInstance->c164_tag_old[c164_i3] = c164_dv1[c164_i3];
  }

  chartInstance->c164_is_active_c164_ICARO3_Onda_simple_v2_media_fun =
    c164_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c164_u, 3)),
    "is_active_c164_ICARO3_Onda_simple_v2_media_fun");
  sf_mex_destroy(&c164_u);
  c164_update_debugger_state_c164_ICARO3_Onda_simple_v2_media_fun(chartInstance);
  sf_mex_destroy(&c164_st);
}

static void finalize_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  real32_T *c164_u;
  real_T *c164_x_mean;
  c164_x_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c164_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 52U, chartInstance->c164_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c164_u, 0U);
  chartInstance->c164_sfEvent = CALL_EVENT;
  c164_chartstep_c164_ICARO3_Onda_simple_v2_media_fun(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_simple_v2_media_funMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c164_x_mean, 1U);
}

static void c164_chartstep_c164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  real32_T c164_hoistedGlobal;
  real32_T c164_u;
  uint32_T c164_debug_family_var_map[8];
  real_T c164_n;
  real_T c164_mid;
  real_T c164_nargin = 1.0;
  real_T c164_nargout = 1.0;
  real_T c164_x_mean;
  int32_T c164_i4;
  int32_T c164_i5;
  int32_T c164_i6;
  int32_T c164_i7;
  real_T c164_b_hoistedGlobal[100];
  real_T c164_y;
  int32_T c164_k;
  int32_T c164_b_k;
  real_T c164_A;
  real_T c164_x;
  real_T c164_b_x;
  real_T c164_c_x;
  int32_T c164_i8;
  real32_T *c164_b_u;
  real_T *c164_b_x_mean;
  c164_b_x_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c164_b_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 52U, chartInstance->c164_sfEvent);
  c164_hoistedGlobal = *c164_b_u;
  c164_u = c164_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c164_debug_family_names,
    c164_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c164_n, 0U, c164_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c164_mid, 1U, c164_c_sf_marshallOut,
    c164_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c164_nargin, 2U, c164_c_sf_marshallOut,
    c164_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c164_nargout, 3U, c164_c_sf_marshallOut,
    c164_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c164_u, 4U, c164_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c164_x_mean, 5U, c164_c_sf_marshallOut,
    c164_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c164_tag_old, 6U,
    c164_b_sf_marshallOut, c164_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c164_tag_new, 7U,
    c164_sf_marshallOut, c164_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 3);
  c164_n = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c164_tag_old_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 6);
    for (c164_i4 = 0; c164_i4 < 100; c164_i4++) {
      chartInstance->c164_tag_old[c164_i4] = 0.0;
    }

    chartInstance->c164_tag_old_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 8);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c164_tag_new_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 9);
    for (c164_i5 = 0; c164_i5 < 100; c164_i5++) {
      chartInstance->c164_tag_new[c164_i5] = 0.0;
    }

    chartInstance->c164_tag_new_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 12);
  chartInstance->c164_tag_new[0] = c164_u;
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 13);
  for (c164_i6 = 0; c164_i6 < 99; c164_i6++) {
    chartInstance->c164_tag_new[c164_i6 + 1] = chartInstance->
      c164_tag_old[c164_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 16);
  for (c164_i7 = 0; c164_i7 < 100; c164_i7++) {
    c164_b_hoistedGlobal[c164_i7] = chartInstance->c164_tag_new[c164_i7];
  }

  c164_y = c164_b_hoistedGlobal[0];
  for (c164_k = 2; c164_k < 101; c164_k++) {
    c164_b_k = c164_k;
    c164_y += c164_b_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c164_b_k), 1, 100, 1, 0) - 1];
  }

  c164_A = c164_y;
  c164_x = c164_A;
  c164_b_x = c164_x;
  c164_c_x = c164_b_x;
  c164_mid = c164_c_x / 100.0;
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 17);
  for (c164_i8 = 0; c164_i8 < 100; c164_i8++) {
    chartInstance->c164_tag_old[c164_i8] = chartInstance->c164_tag_new[c164_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, 19);
  c164_x_mean = c164_mid;
  _SFD_EML_CALL(0U, chartInstance->c164_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  *c164_b_x_mean = c164_x_mean;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, chartInstance->c164_sfEvent);
}

static void initSimStructsc164_ICARO3_Onda_simple_v2_media_fun
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c164_machineNumber, uint32_T
  c164_chartNumber, uint32_T c164_instanceNumber)
{
  (void)c164_machineNumber;
  (void)c164_chartNumber;
  (void)c164_instanceNumber;
}

static const mxArray *c164_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData)
{
  const mxArray *c164_mxArrayOutData = NULL;
  int32_T c164_i9;
  real_T c164_b_inData[100];
  int32_T c164_i10;
  real_T c164_u[100];
  const mxArray *c164_y = NULL;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_mxArrayOutData = NULL;
  for (c164_i9 = 0; c164_i9 < 100; c164_i9++) {
    c164_b_inData[c164_i9] = (*(real_T (*)[100])c164_inData)[c164_i9];
  }

  for (c164_i10 = 0; c164_i10 < 100; c164_i10++) {
    c164_u[c164_i10] = c164_b_inData[c164_i10];
  }

  c164_y = NULL;
  if (!chartInstance->c164_tag_new_not_empty) {
    sf_mex_assign(&c164_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c164_y, sf_mex_create("y", c164_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c164_mxArrayOutData, c164_y, false);
  return c164_mxArrayOutData;
}

static void c164_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_tag_new, const char_T *c164_identifier, real_T c164_y[100])
{
  emlrtMsgIdentifier c164_thisId;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_b_tag_new),
    &c164_thisId, c164_y);
  sf_mex_destroy(&c164_b_tag_new);
}

static void c164_b_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId, real_T c164_y[100])
{
  real_T c164_dv2[100];
  int32_T c164_i11;
  if (mxIsEmpty(c164_u)) {
    chartInstance->c164_tag_new_not_empty = false;
  } else {
    chartInstance->c164_tag_new_not_empty = true;
    sf_mex_import(c164_parentId, sf_mex_dup(c164_u), c164_dv2, 1, 0, 0U, 1, 0U,
                  2, 1, 100);
    for (c164_i11 = 0; c164_i11 < 100; c164_i11++) {
      c164_y[c164_i11] = c164_dv2[c164_i11];
    }
  }

  sf_mex_destroy(&c164_u);
}

static void c164_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData)
{
  const mxArray *c164_b_tag_new;
  const char_T *c164_identifier;
  emlrtMsgIdentifier c164_thisId;
  real_T c164_y[100];
  int32_T c164_i12;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_b_tag_new = sf_mex_dup(c164_mxArrayInData);
  c164_identifier = c164_varName;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_b_tag_new),
    &c164_thisId, c164_y);
  sf_mex_destroy(&c164_b_tag_new);
  for (c164_i12 = 0; c164_i12 < 100; c164_i12++) {
    (*(real_T (*)[100])c164_outData)[c164_i12] = c164_y[c164_i12];
  }

  sf_mex_destroy(&c164_mxArrayInData);
}

static const mxArray *c164_b_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData)
{
  const mxArray *c164_mxArrayOutData = NULL;
  int32_T c164_i13;
  real_T c164_b_inData[100];
  int32_T c164_i14;
  real_T c164_u[100];
  const mxArray *c164_y = NULL;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_mxArrayOutData = NULL;
  for (c164_i13 = 0; c164_i13 < 100; c164_i13++) {
    c164_b_inData[c164_i13] = (*(real_T (*)[100])c164_inData)[c164_i13];
  }

  for (c164_i14 = 0; c164_i14 < 100; c164_i14++) {
    c164_u[c164_i14] = c164_b_inData[c164_i14];
  }

  c164_y = NULL;
  if (!chartInstance->c164_tag_old_not_empty) {
    sf_mex_assign(&c164_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c164_y, sf_mex_create("y", c164_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c164_mxArrayOutData, c164_y, false);
  return c164_mxArrayOutData;
}

static void c164_c_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_tag_old, const char_T *c164_identifier, real_T c164_y[100])
{
  emlrtMsgIdentifier c164_thisId;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_b_tag_old),
    &c164_thisId, c164_y);
  sf_mex_destroy(&c164_b_tag_old);
}

static void c164_d_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId, real_T c164_y[100])
{
  real_T c164_dv3[100];
  int32_T c164_i15;
  if (mxIsEmpty(c164_u)) {
    chartInstance->c164_tag_old_not_empty = false;
  } else {
    chartInstance->c164_tag_old_not_empty = true;
    sf_mex_import(c164_parentId, sf_mex_dup(c164_u), c164_dv3, 1, 0, 0U, 1, 0U,
                  2, 1, 100);
    for (c164_i15 = 0; c164_i15 < 100; c164_i15++) {
      c164_y[c164_i15] = c164_dv3[c164_i15];
    }
  }

  sf_mex_destroy(&c164_u);
}

static void c164_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData)
{
  const mxArray *c164_b_tag_old;
  const char_T *c164_identifier;
  emlrtMsgIdentifier c164_thisId;
  real_T c164_y[100];
  int32_T c164_i16;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_b_tag_old = sf_mex_dup(c164_mxArrayInData);
  c164_identifier = c164_varName;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_b_tag_old),
    &c164_thisId, c164_y);
  sf_mex_destroy(&c164_b_tag_old);
  for (c164_i16 = 0; c164_i16 < 100; c164_i16++) {
    (*(real_T (*)[100])c164_outData)[c164_i16] = c164_y[c164_i16];
  }

  sf_mex_destroy(&c164_mxArrayInData);
}

static const mxArray *c164_c_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData)
{
  const mxArray *c164_mxArrayOutData = NULL;
  real_T c164_u;
  const mxArray *c164_y = NULL;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_mxArrayOutData = NULL;
  c164_u = *(real_T *)c164_inData;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_create("y", &c164_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c164_mxArrayOutData, c164_y, false);
  return c164_mxArrayOutData;
}

static real_T c164_e_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_x_mean, const char_T *c164_identifier)
{
  real_T c164_y;
  emlrtMsgIdentifier c164_thisId;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_y = c164_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_x_mean),
    &c164_thisId);
  sf_mex_destroy(&c164_x_mean);
  return c164_y;
}

static real_T c164_f_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId)
{
  real_T c164_y;
  real_T c164_d0;
  (void)chartInstance;
  sf_mex_import(c164_parentId, sf_mex_dup(c164_u), &c164_d0, 1, 0, 0U, 0, 0U, 0);
  c164_y = c164_d0;
  sf_mex_destroy(&c164_u);
  return c164_y;
}

static void c164_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData)
{
  const mxArray *c164_x_mean;
  const char_T *c164_identifier;
  emlrtMsgIdentifier c164_thisId;
  real_T c164_y;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_x_mean = sf_mex_dup(c164_mxArrayInData);
  c164_identifier = c164_varName;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_y = c164_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_x_mean),
    &c164_thisId);
  sf_mex_destroy(&c164_x_mean);
  *(real_T *)c164_outData = c164_y;
  sf_mex_destroy(&c164_mxArrayInData);
}

static const mxArray *c164_d_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData)
{
  const mxArray *c164_mxArrayOutData = NULL;
  real32_T c164_u;
  const mxArray *c164_y = NULL;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_mxArrayOutData = NULL;
  c164_u = *(real32_T *)c164_inData;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_create("y", &c164_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c164_mxArrayOutData, c164_y, false);
  return c164_mxArrayOutData;
}

const mxArray
  *sf_c164_ICARO3_Onda_simple_v2_media_fun_get_eml_resolved_functions_info(void)
{
  const mxArray *c164_nameCaptureInfo = NULL;
  c164_nameCaptureInfo = NULL;
  sf_mex_assign(&c164_nameCaptureInfo, sf_mex_createstruct("structure", 2, 19, 1),
                false);
  c164_info_helper(&c164_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c164_nameCaptureInfo);
  return c164_nameCaptureInfo;
}

static void c164_info_helper(const mxArray **c164_info)
{
  const mxArray *c164_rhs0 = NULL;
  const mxArray *c164_lhs0 = NULL;
  const mxArray *c164_rhs1 = NULL;
  const mxArray *c164_lhs1 = NULL;
  const mxArray *c164_rhs2 = NULL;
  const mxArray *c164_lhs2 = NULL;
  const mxArray *c164_rhs3 = NULL;
  const mxArray *c164_lhs3 = NULL;
  const mxArray *c164_rhs4 = NULL;
  const mxArray *c164_lhs4 = NULL;
  const mxArray *c164_rhs5 = NULL;
  const mxArray *c164_lhs5 = NULL;
  const mxArray *c164_rhs6 = NULL;
  const mxArray *c164_lhs6 = NULL;
  const mxArray *c164_rhs7 = NULL;
  const mxArray *c164_lhs7 = NULL;
  const mxArray *c164_rhs8 = NULL;
  const mxArray *c164_lhs8 = NULL;
  const mxArray *c164_rhs9 = NULL;
  const mxArray *c164_lhs9 = NULL;
  const mxArray *c164_rhs10 = NULL;
  const mxArray *c164_lhs10 = NULL;
  const mxArray *c164_rhs11 = NULL;
  const mxArray *c164_lhs11 = NULL;
  const mxArray *c164_rhs12 = NULL;
  const mxArray *c164_lhs12 = NULL;
  const mxArray *c164_rhs13 = NULL;
  const mxArray *c164_lhs13 = NULL;
  const mxArray *c164_rhs14 = NULL;
  const mxArray *c164_lhs14 = NULL;
  const mxArray *c164_rhs15 = NULL;
  const mxArray *c164_lhs15 = NULL;
  const mxArray *c164_rhs16 = NULL;
  const mxArray *c164_lhs16 = NULL;
  const mxArray *c164_rhs17 = NULL;
  const mxArray *c164_lhs17 = NULL;
  const mxArray *c164_rhs18 = NULL;
  const mxArray *c164_lhs18 = NULL;
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("sum"), "name", "name", 0);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1363713858U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c164_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c164_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("isequal"), "name", "name",
                  2);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1286818758U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c164_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 3);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1286818786U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c164_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "eml_const_nonsingleton_dim"), "name", "name", 4);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c164_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 5);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c164_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c164_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c164_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c164_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 9);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c164_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 10);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("intmax"), "name", "name",
                  10);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c164_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 11);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c164_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(""), "context", "context",
                  12);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("mrdivide"), "name", "name",
                  12);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1388460096U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1370009886U),
                  "mFileTimeLo", "mFileTimeLo", 12);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c164_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs12), "rhs",
                  "rhs", 12);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs12), "lhs",
                  "lhs", 12);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 13);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c164_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs13), "rhs",
                  "rhs", 13);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs13), "lhs",
                  "lhs", 13);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("rdivide"), "name", "name",
                  14);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1363713880U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c164_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs14), "rhs",
                  "rhs", 14);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs14), "lhs",
                  "lhs", 14);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c164_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs15), "rhs",
                  "rhs", 15);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs15), "lhs",
                  "lhs", 15);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 16);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1286818796U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c164_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs16), "rhs",
                  "rhs", 16);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs16), "lhs",
                  "lhs", 16);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("eml_div"), "name", "name",
                  17);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c164_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs17), "rhs",
                  "rhs", 17);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs17), "lhs",
                  "lhs", 17);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("coder.internal.div"),
                  "name", "name", 18);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c164_info, c164_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 18);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c164_info, c164_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c164_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c164_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_rhs18), "rhs",
                  "rhs", 18);
  sf_mex_addfield(*c164_info, sf_mex_duplicatearraysafe(&c164_lhs18), "lhs",
                  "lhs", 18);
  sf_mex_destroy(&c164_rhs0);
  sf_mex_destroy(&c164_lhs0);
  sf_mex_destroy(&c164_rhs1);
  sf_mex_destroy(&c164_lhs1);
  sf_mex_destroy(&c164_rhs2);
  sf_mex_destroy(&c164_lhs2);
  sf_mex_destroy(&c164_rhs3);
  sf_mex_destroy(&c164_lhs3);
  sf_mex_destroy(&c164_rhs4);
  sf_mex_destroy(&c164_lhs4);
  sf_mex_destroy(&c164_rhs5);
  sf_mex_destroy(&c164_lhs5);
  sf_mex_destroy(&c164_rhs6);
  sf_mex_destroy(&c164_lhs6);
  sf_mex_destroy(&c164_rhs7);
  sf_mex_destroy(&c164_lhs7);
  sf_mex_destroy(&c164_rhs8);
  sf_mex_destroy(&c164_lhs8);
  sf_mex_destroy(&c164_rhs9);
  sf_mex_destroy(&c164_lhs9);
  sf_mex_destroy(&c164_rhs10);
  sf_mex_destroy(&c164_lhs10);
  sf_mex_destroy(&c164_rhs11);
  sf_mex_destroy(&c164_lhs11);
  sf_mex_destroy(&c164_rhs12);
  sf_mex_destroy(&c164_lhs12);
  sf_mex_destroy(&c164_rhs13);
  sf_mex_destroy(&c164_lhs13);
  sf_mex_destroy(&c164_rhs14);
  sf_mex_destroy(&c164_lhs14);
  sf_mex_destroy(&c164_rhs15);
  sf_mex_destroy(&c164_lhs15);
  sf_mex_destroy(&c164_rhs16);
  sf_mex_destroy(&c164_lhs16);
  sf_mex_destroy(&c164_rhs17);
  sf_mex_destroy(&c164_lhs17);
  sf_mex_destroy(&c164_rhs18);
  sf_mex_destroy(&c164_lhs18);
}

static const mxArray *c164_emlrt_marshallOut(const char * c164_u)
{
  const mxArray *c164_y = NULL;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_create("y", c164_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c164_u)), false);
  return c164_y;
}

static const mxArray *c164_b_emlrt_marshallOut(const uint32_T c164_u)
{
  const mxArray *c164_y = NULL;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_create("y", &c164_u, 7, 0U, 0U, 0U, 0), false);
  return c164_y;
}

static const mxArray *c164_e_sf_marshallOut(void *chartInstanceVoid, void
  *c164_inData)
{
  const mxArray *c164_mxArrayOutData = NULL;
  int32_T c164_u;
  const mxArray *c164_y = NULL;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_mxArrayOutData = NULL;
  c164_u = *(int32_T *)c164_inData;
  c164_y = NULL;
  sf_mex_assign(&c164_y, sf_mex_create("y", &c164_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c164_mxArrayOutData, c164_y, false);
  return c164_mxArrayOutData;
}

static int32_T c164_g_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId)
{
  int32_T c164_y;
  int32_T c164_i17;
  (void)chartInstance;
  sf_mex_import(c164_parentId, sf_mex_dup(c164_u), &c164_i17, 1, 6, 0U, 0, 0U, 0);
  c164_y = c164_i17;
  sf_mex_destroy(&c164_u);
  return c164_y;
}

static void c164_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c164_mxArrayInData, const char_T *c164_varName, void *c164_outData)
{
  const mxArray *c164_b_sfEvent;
  const char_T *c164_identifier;
  emlrtMsgIdentifier c164_thisId;
  int32_T c164_y;
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c164_b_sfEvent = sf_mex_dup(c164_mxArrayInData);
  c164_identifier = c164_varName;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_y = c164_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c164_b_sfEvent),
    &c164_thisId);
  sf_mex_destroy(&c164_b_sfEvent);
  *(int32_T *)c164_outData = c164_y;
  sf_mex_destroy(&c164_mxArrayInData);
}

static uint8_T c164_h_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_b_is_active_c164_ICARO3_Onda_simple_v2_media_fun, const char_T *
   c164_identifier)
{
  uint8_T c164_y;
  emlrtMsgIdentifier c164_thisId;
  c164_thisId.fIdentifier = c164_identifier;
  c164_thisId.fParent = NULL;
  c164_y = c164_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c164_b_is_active_c164_ICARO3_Onda_simple_v2_media_fun), &c164_thisId);
  sf_mex_destroy(&c164_b_is_active_c164_ICARO3_Onda_simple_v2_media_fun);
  return c164_y;
}

static uint8_T c164_i_emlrt_marshallIn
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c164_u, const emlrtMsgIdentifier *c164_parentId)
{
  uint8_T c164_y;
  uint8_T c164_u0;
  (void)chartInstance;
  sf_mex_import(c164_parentId, sf_mex_dup(c164_u), &c164_u0, 1, 3, 0U, 0, 0U, 0);
  c164_y = c164_u0;
  sf_mex_destroy(&c164_u);
  return c164_y;
}

static void init_dsm_address_info
  (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
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

void sf_c164_ICARO3_Onda_simple_v2_media_fun_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1242615634U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(558794837U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3480693850U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2898004881U);
}

mxArray *sf_c164_ICARO3_Onda_simple_v2_media_fun_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wbWuWADZDtSwwAN7CaBIdH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

mxArray *sf_c164_ICARO3_Onda_simple_v2_media_fun_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c164_ICARO3_Onda_simple_v2_media_fun_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c164_ICARO3_Onda_simple_v2_media_fun
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"x_mean\",},{M[4],M[0],T\"tag_new\",S'l','i','p'{{M1x2[49 56],M[0],}}},{M[4],M[0],T\"tag_old\",S'l','i','p'{{M1x2[41 48],M[0],}}},{M[8],M[0],T\"is_active_c164_ICARO3_Onda_simple_v2_media_fun\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c164_ICARO3_Onda_simple_v2_media_fun_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_simple_v2_media_funMachineNumber_,
           164,
           1,
           1,
           0,
           2,
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
          (_ICARO3_Onda_simple_v2_media_funMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_simple_v2_media_funMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_simple_v2_media_funMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x_mean");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,452);
        _SFD_CV_INIT_EML_IF(0,1,0,67,86,-1,116);
        _SFD_CV_INIT_EML_IF(0,1,1,117,136,-1,166);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c164_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c164_c_sf_marshallOut,(MexInFcnForType)
          c164_c_sf_marshallIn);

        {
          real32_T *c164_u;
          real_T *c164_x_mean;
          c164_x_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c164_u = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c164_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c164_x_mean);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_simple_v2_media_funMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "J0xIJfCjjRArmWboL24lSF";
}

static void sf_opaque_initialize_c164_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
  initialize_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c164_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  enable_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c164_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  disable_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c164_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  sf_gateway_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c164_ICARO3_Onda_simple_v2_media_fun();/* state var info */
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

extern void sf_internal_set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
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
    sf_get_sim_state_info_c164_ICARO3_Onda_simple_v2_media_fun();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct* S)
{
  return sf_internal_get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun(S);
}

static void sf_opaque_set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun(S, st);
}

static void sf_opaque_terminate_c164_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_simple_v2_media_fun_optimization_info();
    }

    finalize_c164_ICARO3_Onda_simple_v2_media_fun
      ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc164_ICARO3_Onda_simple_v2_media_fun
    ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct *
  S)
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
    initialize_params_c164_ICARO3_Onda_simple_v2_media_fun
      ((SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_simple_v2_media_fun_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      164);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,164,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,164,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,164);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,164,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,164,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,164);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2327772328U));
  ssSetChecksum1(S,(3270519231U));
  ssSetChecksum2(S,(1997745224U));
  ssSetChecksum3(S,(1560537658U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c164_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    utMalloc(sizeof(SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc164_ICARO3_Onda_simple_v2_media_funInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c164_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c164_ICARO3_Onda_simple_v2_media_fun;
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

void c164_ICARO3_Onda_simple_v2_media_fun_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c164_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c164_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c164_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c164_ICARO3_Onda_simple_v2_media_fun_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
