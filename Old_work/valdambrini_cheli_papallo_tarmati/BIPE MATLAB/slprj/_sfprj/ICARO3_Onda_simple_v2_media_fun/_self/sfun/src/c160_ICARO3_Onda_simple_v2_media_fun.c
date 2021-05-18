/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_simple_v2_media_fun_sfun.h"
#include "c160_ICARO3_Onda_simple_v2_media_fun.h"
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
static const char * c160_debug_family_names[6] = { "a", "R", "nargin", "nargout",
  "u", "y" };

/* Function Declarations */
static void initialize_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void initialize_params_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void enable_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void disable_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void c160_update_debugger_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_st);
static void finalize_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void sf_gateway_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void initSimStructsc160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c160_machineNumber, uint32_T
  c160_chartNumber, uint32_T c160_instanceNumber);
static const mxArray *c160_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData);
static void c160_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_y, const char_T *c160_identifier, real_T c160_b_y[3]);
static void c160_b_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId, real_T c160_y[3]);
static void c160_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData);
static const mxArray *c160_b_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData);
static real_T c160_c_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId);
static void c160_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData);
static const mxArray *c160_c_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData);
static void c160_info_helper(const mxArray **c160_info);
static const mxArray *c160_emlrt_marshallOut(const char * c160_u);
static const mxArray *c160_b_emlrt_marshallOut(const uint32_T c160_u);
static void c160_eml_scalar_eg
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);
static void c160_eml_xgemm(SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *
  chartInstance, real_T c160_A[9], real_T c160_B[3], real_T c160_C[3], real_T
  c160_b_C[3]);
static const mxArray *c160_d_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData);
static int32_T c160_d_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId);
static void c160_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData);
static uint8_T c160_e_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_b_is_active_c160_ICARO3_Onda_simple_v2_media_fun, const char_T *
   c160_identifier);
static uint8_T c160_f_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId);
static void c160_b_eml_xgemm
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, real_T
   c160_A[9], real_T c160_B[3], real_T c160_C[3]);
static void init_dsm_address_info
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  chartInstance->c160_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c160_is_active_c160_ICARO3_Onda_simple_v2_media_fun = 0U;
}

static void initialize_params_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c160_update_debugger_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  const mxArray *c160_st;
  const mxArray *c160_y = NULL;
  int32_T c160_i0;
  real_T c160_u[3];
  const mxArray *c160_b_y = NULL;
  uint8_T c160_hoistedGlobal;
  uint8_T c160_b_u;
  const mxArray *c160_c_y = NULL;
  real_T (*c160_d_y)[3];
  c160_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c160_st = NULL;
  c160_st = NULL;
  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_createcellmatrix(2, 1), false);
  for (c160_i0 = 0; c160_i0 < 3; c160_i0++) {
    c160_u[c160_i0] = (*c160_d_y)[c160_i0];
  }

  c160_b_y = NULL;
  sf_mex_assign(&c160_b_y, sf_mex_create("y", c160_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c160_y, 0, c160_b_y);
  c160_hoistedGlobal =
    chartInstance->c160_is_active_c160_ICARO3_Onda_simple_v2_media_fun;
  c160_b_u = c160_hoistedGlobal;
  c160_c_y = NULL;
  sf_mex_assign(&c160_c_y, sf_mex_create("y", &c160_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c160_y, 1, c160_c_y);
  sf_mex_assign(&c160_st, c160_y, false);
  return c160_st;
}

static void set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_st)
{
  const mxArray *c160_u;
  real_T c160_dv0[3];
  int32_T c160_i1;
  real_T (*c160_y)[3];
  c160_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c160_doneDoubleBufferReInit = true;
  c160_u = sf_mex_dup(c160_st);
  c160_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c160_u, 0)),
                        "y", c160_dv0);
  for (c160_i1 = 0; c160_i1 < 3; c160_i1++) {
    (*c160_y)[c160_i1] = c160_dv0[c160_i1];
  }

  chartInstance->c160_is_active_c160_ICARO3_Onda_simple_v2_media_fun =
    c160_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c160_u, 1)),
    "is_active_c160_ICARO3_Onda_simple_v2_media_fun");
  sf_mex_destroy(&c160_u);
  c160_update_debugger_state_c160_ICARO3_Onda_simple_v2_media_fun(chartInstance);
  sf_mex_destroy(&c160_st);
}

static void finalize_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  int32_T c160_i2;
  int32_T c160_i3;
  real_T c160_u[3];
  uint32_T c160_debug_family_var_map[6];
  real_T c160_a;
  real_T c160_R[9];
  real_T c160_nargin = 1.0;
  real_T c160_nargout = 1.0;
  real_T c160_y[3];
  int32_T c160_i4;
  static real_T c160_b_a[9] = { -1.0, -1.2246467991473532E-16, 0.0,
    1.2246467991473532E-16, -1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c160_i5;
  real_T c160_b[3];
  int32_T c160_i6;
  int32_T c160_i7;
  int32_T c160_i8;
  real_T c160_dv1[9];
  int32_T c160_i9;
  real_T c160_dv2[3];
  int32_T c160_i10;
  real_T c160_dv3[9];
  int32_T c160_i11;
  real_T c160_dv4[3];
  int32_T c160_i12;
  int32_T c160_i13;
  real_T (*c160_b_y)[3];
  real_T (*c160_b_u)[3];
  c160_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c160_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 50U, chartInstance->c160_sfEvent);
  for (c160_i2 = 0; c160_i2 < 3; c160_i2++) {
    _SFD_DATA_RANGE_CHECK((*c160_b_u)[c160_i2], 0U);
  }

  chartInstance->c160_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 50U, chartInstance->c160_sfEvent);
  for (c160_i3 = 0; c160_i3 < 3; c160_i3++) {
    c160_u[c160_i3] = (*c160_b_u)[c160_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c160_debug_family_names,
    c160_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c160_a, 0U, c160_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c160_R, 1U, c160_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c160_nargin, 2U, c160_b_sf_marshallOut,
    c160_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c160_nargout, 3U, c160_b_sf_marshallOut,
    c160_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c160_u, 4U, c160_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c160_y, 5U, c160_sf_marshallOut,
    c160_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c160_sfEvent, 6);
  c160_a = 3.1415926535897931;
  _SFD_EML_CALL(0U, chartInstance->c160_sfEvent, 7);
  for (c160_i4 = 0; c160_i4 < 9; c160_i4++) {
    c160_R[c160_i4] = c160_b_a[c160_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c160_sfEvent, 9);
  for (c160_i5 = 0; c160_i5 < 3; c160_i5++) {
    c160_b[c160_i5] = c160_u[c160_i5];
  }

  c160_eml_scalar_eg(chartInstance);
  c160_eml_scalar_eg(chartInstance);
  for (c160_i6 = 0; c160_i6 < 3; c160_i6++) {
    c160_y[c160_i6] = 0.0;
  }

  for (c160_i7 = 0; c160_i7 < 3; c160_i7++) {
    c160_y[c160_i7] = 0.0;
  }

  for (c160_i8 = 0; c160_i8 < 9; c160_i8++) {
    c160_dv1[c160_i8] = c160_b_a[c160_i8];
  }

  for (c160_i9 = 0; c160_i9 < 3; c160_i9++) {
    c160_dv2[c160_i9] = c160_b[c160_i9];
  }

  for (c160_i10 = 0; c160_i10 < 9; c160_i10++) {
    c160_dv3[c160_i10] = c160_dv1[c160_i10];
  }

  for (c160_i11 = 0; c160_i11 < 3; c160_i11++) {
    c160_dv4[c160_i11] = c160_dv2[c160_i11];
  }

  c160_b_eml_xgemm(chartInstance, c160_dv3, c160_dv4, c160_y);
  _SFD_EML_CALL(0U, chartInstance->c160_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c160_i12 = 0; c160_i12 < 3; c160_i12++) {
    (*c160_b_y)[c160_i12] = c160_y[c160_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, chartInstance->c160_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_simple_v2_media_funMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  for (c160_i13 = 0; c160_i13 < 3; c160_i13++) {
    _SFD_DATA_RANGE_CHECK((*c160_b_y)[c160_i13], 1U);
  }
}

static void initSimStructsc160_ICARO3_Onda_simple_v2_media_fun
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c160_machineNumber, uint32_T
  c160_chartNumber, uint32_T c160_instanceNumber)
{
  (void)c160_machineNumber;
  (void)c160_chartNumber;
  (void)c160_instanceNumber;
}

static const mxArray *c160_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData)
{
  const mxArray *c160_mxArrayOutData = NULL;
  int32_T c160_i14;
  real_T c160_b_inData[3];
  int32_T c160_i15;
  real_T c160_u[3];
  const mxArray *c160_y = NULL;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_mxArrayOutData = NULL;
  for (c160_i14 = 0; c160_i14 < 3; c160_i14++) {
    c160_b_inData[c160_i14] = (*(real_T (*)[3])c160_inData)[c160_i14];
  }

  for (c160_i15 = 0; c160_i15 < 3; c160_i15++) {
    c160_u[c160_i15] = c160_b_inData[c160_i15];
  }

  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", c160_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c160_mxArrayOutData, c160_y, false);
  return c160_mxArrayOutData;
}

static void c160_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_y, const char_T *c160_identifier, real_T c160_b_y[3])
{
  emlrtMsgIdentifier c160_thisId;
  c160_thisId.fIdentifier = c160_identifier;
  c160_thisId.fParent = NULL;
  c160_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c160_y), &c160_thisId,
    c160_b_y);
  sf_mex_destroy(&c160_y);
}

static void c160_b_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId, real_T c160_y[3])
{
  real_T c160_dv5[3];
  int32_T c160_i16;
  (void)chartInstance;
  sf_mex_import(c160_parentId, sf_mex_dup(c160_u), c160_dv5, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c160_i16 = 0; c160_i16 < 3; c160_i16++) {
    c160_y[c160_i16] = c160_dv5[c160_i16];
  }

  sf_mex_destroy(&c160_u);
}

static void c160_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData)
{
  const mxArray *c160_y;
  const char_T *c160_identifier;
  emlrtMsgIdentifier c160_thisId;
  real_T c160_b_y[3];
  int32_T c160_i17;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_y = sf_mex_dup(c160_mxArrayInData);
  c160_identifier = c160_varName;
  c160_thisId.fIdentifier = c160_identifier;
  c160_thisId.fParent = NULL;
  c160_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c160_y), &c160_thisId,
    c160_b_y);
  sf_mex_destroy(&c160_y);
  for (c160_i17 = 0; c160_i17 < 3; c160_i17++) {
    (*(real_T (*)[3])c160_outData)[c160_i17] = c160_b_y[c160_i17];
  }

  sf_mex_destroy(&c160_mxArrayInData);
}

static const mxArray *c160_b_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData)
{
  const mxArray *c160_mxArrayOutData = NULL;
  real_T c160_u;
  const mxArray *c160_y = NULL;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_mxArrayOutData = NULL;
  c160_u = *(real_T *)c160_inData;
  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", &c160_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c160_mxArrayOutData, c160_y, false);
  return c160_mxArrayOutData;
}

static real_T c160_c_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId)
{
  real_T c160_y;
  real_T c160_d0;
  (void)chartInstance;
  sf_mex_import(c160_parentId, sf_mex_dup(c160_u), &c160_d0, 1, 0, 0U, 0, 0U, 0);
  c160_y = c160_d0;
  sf_mex_destroy(&c160_u);
  return c160_y;
}

static void c160_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData)
{
  const mxArray *c160_nargout;
  const char_T *c160_identifier;
  emlrtMsgIdentifier c160_thisId;
  real_T c160_y;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_nargout = sf_mex_dup(c160_mxArrayInData);
  c160_identifier = c160_varName;
  c160_thisId.fIdentifier = c160_identifier;
  c160_thisId.fParent = NULL;
  c160_y = c160_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c160_nargout),
    &c160_thisId);
  sf_mex_destroy(&c160_nargout);
  *(real_T *)c160_outData = c160_y;
  sf_mex_destroy(&c160_mxArrayInData);
}

static const mxArray *c160_c_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData)
{
  const mxArray *c160_mxArrayOutData = NULL;
  int32_T c160_i18;
  int32_T c160_i19;
  int32_T c160_i20;
  real_T c160_b_inData[9];
  int32_T c160_i21;
  int32_T c160_i22;
  int32_T c160_i23;
  real_T c160_u[9];
  const mxArray *c160_y = NULL;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_mxArrayOutData = NULL;
  c160_i18 = 0;
  for (c160_i19 = 0; c160_i19 < 3; c160_i19++) {
    for (c160_i20 = 0; c160_i20 < 3; c160_i20++) {
      c160_b_inData[c160_i20 + c160_i18] = (*(real_T (*)[9])c160_inData)
        [c160_i20 + c160_i18];
    }

    c160_i18 += 3;
  }

  c160_i21 = 0;
  for (c160_i22 = 0; c160_i22 < 3; c160_i22++) {
    for (c160_i23 = 0; c160_i23 < 3; c160_i23++) {
      c160_u[c160_i23 + c160_i21] = c160_b_inData[c160_i23 + c160_i21];
    }

    c160_i21 += 3;
  }

  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", c160_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_assign(&c160_mxArrayOutData, c160_y, false);
  return c160_mxArrayOutData;
}

const mxArray
  *sf_c160_ICARO3_Onda_simple_v2_media_fun_get_eml_resolved_functions_info(void)
{
  const mxArray *c160_nameCaptureInfo = NULL;
  c160_nameCaptureInfo = NULL;
  sf_mex_assign(&c160_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c160_info_helper(&c160_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c160_nameCaptureInfo);
  return c160_nameCaptureInfo;
}

static void c160_info_helper(const mxArray **c160_info)
{
  const mxArray *c160_rhs0 = NULL;
  const mxArray *c160_lhs0 = NULL;
  const mxArray *c160_rhs1 = NULL;
  const mxArray *c160_lhs1 = NULL;
  const mxArray *c160_rhs2 = NULL;
  const mxArray *c160_lhs2 = NULL;
  const mxArray *c160_rhs3 = NULL;
  const mxArray *c160_lhs3 = NULL;
  const mxArray *c160_rhs4 = NULL;
  const mxArray *c160_lhs4 = NULL;
  const mxArray *c160_rhs5 = NULL;
  const mxArray *c160_lhs5 = NULL;
  const mxArray *c160_rhs6 = NULL;
  const mxArray *c160_lhs6 = NULL;
  const mxArray *c160_rhs7 = NULL;
  const mxArray *c160_lhs7 = NULL;
  const mxArray *c160_rhs8 = NULL;
  const mxArray *c160_lhs8 = NULL;
  const mxArray *c160_rhs9 = NULL;
  const mxArray *c160_lhs9 = NULL;
  const mxArray *c160_rhs10 = NULL;
  const mxArray *c160_lhs10 = NULL;
  const mxArray *c160_rhs11 = NULL;
  const mxArray *c160_lhs11 = NULL;
  const mxArray *c160_rhs12 = NULL;
  const mxArray *c160_lhs12 = NULL;
  const mxArray *c160_rhs13 = NULL;
  const mxArray *c160_lhs13 = NULL;
  const mxArray *c160_rhs14 = NULL;
  const mxArray *c160_lhs14 = NULL;
  const mxArray *c160_rhs15 = NULL;
  const mxArray *c160_lhs15 = NULL;
  const mxArray *c160_rhs16 = NULL;
  const mxArray *c160_lhs16 = NULL;
  const mxArray *c160_rhs17 = NULL;
  const mxArray *c160_lhs17 = NULL;
  const mxArray *c160_rhs18 = NULL;
  const mxArray *c160_lhs18 = NULL;
  const mxArray *c160_rhs19 = NULL;
  const mxArray *c160_lhs19 = NULL;
  const mxArray *c160_rhs20 = NULL;
  const mxArray *c160_lhs20 = NULL;
  const mxArray *c160_rhs21 = NULL;
  const mxArray *c160_lhs21 = NULL;
  const mxArray *c160_rhs22 = NULL;
  const mxArray *c160_lhs22 = NULL;
  const mxArray *c160_rhs23 = NULL;
  const mxArray *c160_lhs23 = NULL;
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1388460096U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1370009886U),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c160_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c160_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("rdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1363713880U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c160_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c160_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1286818796U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c160_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_div"), "name", "name",
                  5);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c160_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("coder.internal.div"),
                  "name", "name", 6);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c160_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "context", "context",
                  7);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("cos"), "name", "name", 7);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1343830372U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c160_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 8);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1286818722U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c160_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "context", "context",
                  9);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("sin"), "name", "name", 9);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1343830386U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c160_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 10);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1286818736U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c160_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "context", "context",
                  11);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_mtimes_helper"),
                  "name", "name", 11);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1383877294U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c160_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 12);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c160_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs12), "rhs",
                  "rhs", 12);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs12), "lhs",
                  "lhs", 12);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c160_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs13), "rhs",
                  "rhs", 13);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs13), "lhs",
                  "lhs", 13);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c160_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs14), "rhs",
                  "rhs", 14);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs14), "lhs",
                  "lhs", 14);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c160_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs15), "rhs",
                  "rhs", 15);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs15), "lhs",
                  "lhs", 15);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_xgemm"), "name",
                  "name", 16);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1375980690U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c160_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs16), "rhs",
                  "rhs", 16);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs16), "lhs",
                  "lhs", 16);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.blas.inline"), "name", "name", 17);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c160_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs17), "rhs",
                  "rhs", 17);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs17), "lhs",
                  "lhs", 17);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 18);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 18);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c160_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs18), "rhs",
                  "rhs", 18);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs18), "lhs",
                  "lhs", 18);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 19);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 19);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c160_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs19), "rhs",
                  "rhs", 19);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs19), "lhs",
                  "lhs", 19);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 20);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 20);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 20);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c160_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs20), "rhs",
                  "rhs", 20);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs20), "lhs",
                  "lhs", 20);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 21);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 21);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c160_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs21), "rhs",
                  "rhs", 21);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs21), "lhs",
                  "lhs", 21);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 22);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 22);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c160_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs22), "rhs",
                  "rhs", 22);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs22), "lhs",
                  "lhs", 22);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 23);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c160_info, c160_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 23);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c160_info, c160_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c160_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c160_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_rhs23), "rhs",
                  "rhs", 23);
  sf_mex_addfield(*c160_info, sf_mex_duplicatearraysafe(&c160_lhs23), "lhs",
                  "lhs", 23);
  sf_mex_destroy(&c160_rhs0);
  sf_mex_destroy(&c160_lhs0);
  sf_mex_destroy(&c160_rhs1);
  sf_mex_destroy(&c160_lhs1);
  sf_mex_destroy(&c160_rhs2);
  sf_mex_destroy(&c160_lhs2);
  sf_mex_destroy(&c160_rhs3);
  sf_mex_destroy(&c160_lhs3);
  sf_mex_destroy(&c160_rhs4);
  sf_mex_destroy(&c160_lhs4);
  sf_mex_destroy(&c160_rhs5);
  sf_mex_destroy(&c160_lhs5);
  sf_mex_destroy(&c160_rhs6);
  sf_mex_destroy(&c160_lhs6);
  sf_mex_destroy(&c160_rhs7);
  sf_mex_destroy(&c160_lhs7);
  sf_mex_destroy(&c160_rhs8);
  sf_mex_destroy(&c160_lhs8);
  sf_mex_destroy(&c160_rhs9);
  sf_mex_destroy(&c160_lhs9);
  sf_mex_destroy(&c160_rhs10);
  sf_mex_destroy(&c160_lhs10);
  sf_mex_destroy(&c160_rhs11);
  sf_mex_destroy(&c160_lhs11);
  sf_mex_destroy(&c160_rhs12);
  sf_mex_destroy(&c160_lhs12);
  sf_mex_destroy(&c160_rhs13);
  sf_mex_destroy(&c160_lhs13);
  sf_mex_destroy(&c160_rhs14);
  sf_mex_destroy(&c160_lhs14);
  sf_mex_destroy(&c160_rhs15);
  sf_mex_destroy(&c160_lhs15);
  sf_mex_destroy(&c160_rhs16);
  sf_mex_destroy(&c160_lhs16);
  sf_mex_destroy(&c160_rhs17);
  sf_mex_destroy(&c160_lhs17);
  sf_mex_destroy(&c160_rhs18);
  sf_mex_destroy(&c160_lhs18);
  sf_mex_destroy(&c160_rhs19);
  sf_mex_destroy(&c160_lhs19);
  sf_mex_destroy(&c160_rhs20);
  sf_mex_destroy(&c160_lhs20);
  sf_mex_destroy(&c160_rhs21);
  sf_mex_destroy(&c160_lhs21);
  sf_mex_destroy(&c160_rhs22);
  sf_mex_destroy(&c160_lhs22);
  sf_mex_destroy(&c160_rhs23);
  sf_mex_destroy(&c160_lhs23);
}

static const mxArray *c160_emlrt_marshallOut(const char * c160_u)
{
  const mxArray *c160_y = NULL;
  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", c160_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c160_u)), false);
  return c160_y;
}

static const mxArray *c160_b_emlrt_marshallOut(const uint32_T c160_u)
{
  const mxArray *c160_y = NULL;
  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", &c160_u, 7, 0U, 0U, 0U, 0), false);
  return c160_y;
}

static void c160_eml_scalar_eg
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c160_eml_xgemm(SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *
  chartInstance, real_T c160_A[9], real_T c160_B[3], real_T c160_C[3], real_T
  c160_b_C[3])
{
  int32_T c160_i24;
  int32_T c160_i25;
  real_T c160_b_A[9];
  int32_T c160_i26;
  real_T c160_b_B[3];
  for (c160_i24 = 0; c160_i24 < 3; c160_i24++) {
    c160_b_C[c160_i24] = c160_C[c160_i24];
  }

  for (c160_i25 = 0; c160_i25 < 9; c160_i25++) {
    c160_b_A[c160_i25] = c160_A[c160_i25];
  }

  for (c160_i26 = 0; c160_i26 < 3; c160_i26++) {
    c160_b_B[c160_i26] = c160_B[c160_i26];
  }

  c160_b_eml_xgemm(chartInstance, c160_b_A, c160_b_B, c160_b_C);
}

static const mxArray *c160_d_sf_marshallOut(void *chartInstanceVoid, void
  *c160_inData)
{
  const mxArray *c160_mxArrayOutData = NULL;
  int32_T c160_u;
  const mxArray *c160_y = NULL;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_mxArrayOutData = NULL;
  c160_u = *(int32_T *)c160_inData;
  c160_y = NULL;
  sf_mex_assign(&c160_y, sf_mex_create("y", &c160_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c160_mxArrayOutData, c160_y, false);
  return c160_mxArrayOutData;
}

static int32_T c160_d_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId)
{
  int32_T c160_y;
  int32_T c160_i27;
  (void)chartInstance;
  sf_mex_import(c160_parentId, sf_mex_dup(c160_u), &c160_i27, 1, 6, 0U, 0, 0U, 0);
  c160_y = c160_i27;
  sf_mex_destroy(&c160_u);
  return c160_y;
}

static void c160_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c160_mxArrayInData, const char_T *c160_varName, void *c160_outData)
{
  const mxArray *c160_b_sfEvent;
  const char_T *c160_identifier;
  emlrtMsgIdentifier c160_thisId;
  int32_T c160_y;
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    chartInstanceVoid;
  c160_b_sfEvent = sf_mex_dup(c160_mxArrayInData);
  c160_identifier = c160_varName;
  c160_thisId.fIdentifier = c160_identifier;
  c160_thisId.fParent = NULL;
  c160_y = c160_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c160_b_sfEvent),
    &c160_thisId);
  sf_mex_destroy(&c160_b_sfEvent);
  *(int32_T *)c160_outData = c160_y;
  sf_mex_destroy(&c160_mxArrayInData);
}

static uint8_T c160_e_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_b_is_active_c160_ICARO3_Onda_simple_v2_media_fun, const char_T *
   c160_identifier)
{
  uint8_T c160_y;
  emlrtMsgIdentifier c160_thisId;
  c160_thisId.fIdentifier = c160_identifier;
  c160_thisId.fParent = NULL;
  c160_y = c160_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c160_b_is_active_c160_ICARO3_Onda_simple_v2_media_fun), &c160_thisId);
  sf_mex_destroy(&c160_b_is_active_c160_ICARO3_Onda_simple_v2_media_fun);
  return c160_y;
}

static uint8_T c160_f_emlrt_marshallIn
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, const
   mxArray *c160_u, const emlrtMsgIdentifier *c160_parentId)
{
  uint8_T c160_y;
  uint8_T c160_u0;
  (void)chartInstance;
  sf_mex_import(c160_parentId, sf_mex_dup(c160_u), &c160_u0, 1, 3, 0U, 0, 0U, 0);
  c160_y = c160_u0;
  sf_mex_destroy(&c160_u);
  return c160_y;
}

static void c160_b_eml_xgemm
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance, real_T
   c160_A[9], real_T c160_B[3], real_T c160_C[3])
{
  int32_T c160_i28;
  int32_T c160_i29;
  int32_T c160_i30;
  (void)chartInstance;
  for (c160_i28 = 0; c160_i28 < 3; c160_i28++) {
    c160_C[c160_i28] = 0.0;
    c160_i29 = 0;
    for (c160_i30 = 0; c160_i30 < 3; c160_i30++) {
      c160_C[c160_i28] += c160_A[c160_i29 + c160_i28] * c160_B[c160_i30];
      c160_i29 += 3;
    }
  }
}

static void init_dsm_address_info
  (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance)
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

void sf_c160_ICARO3_Onda_simple_v2_media_fun_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3451245063U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4286920000U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1956300075U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1084845270U);
}

mxArray *sf_c160_ICARO3_Onda_simple_v2_media_fun_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eGgmFw00fwzzVMU6R7kVOE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      pr[0] = (double)(3);
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

mxArray *sf_c160_ICARO3_Onda_simple_v2_media_fun_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c160_ICARO3_Onda_simple_v2_media_fun_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c160_ICARO3_Onda_simple_v2_media_fun
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c160_ICARO3_Onda_simple_v2_media_fun\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c160_ICARO3_Onda_simple_v2_media_fun_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_simple_v2_media_funMachineNumber_,
           160,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,185);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c160_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c160_sf_marshallOut,(MexInFcnForType)
            c160_sf_marshallIn);
        }

        {
          real_T (*c160_u)[3];
          real_T (*c160_y)[3];
          c160_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c160_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c160_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c160_y);
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
  return "naYA8aoBlOG59C58Oq5tCD";
}

static void sf_opaque_initialize_c160_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
  initialize_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c160_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  enable_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c160_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  disable_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c160_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  sf_gateway_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c160_ICARO3_Onda_simple_v2_media_fun();/* state var info */
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

extern void sf_internal_set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
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
    sf_get_sim_state_info_c160_ICARO3_Onda_simple_v2_media_fun();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct* S)
{
  return sf_internal_get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun(S);
}

static void sf_opaque_set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun(S, st);
}

static void sf_opaque_terminate_c160_ICARO3_Onda_simple_v2_media_fun(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_simple_v2_media_fun_optimization_info();
    }

    finalize_c160_ICARO3_Onda_simple_v2_media_fun
      ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc160_ICARO3_Onda_simple_v2_media_fun
    ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct *
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
    initialize_params_c160_ICARO3_Onda_simple_v2_media_fun
      ((SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_simple_v2_media_fun_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      160);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,160,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,160,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,160);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,160,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,160,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,160);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2300951450U));
  ssSetChecksum1(S,(1201344891U));
  ssSetChecksum2(S,(3667221400U));
  ssSetChecksum3(S,(92902354U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c160_ICARO3_Onda_simple_v2_media_fun(SimStruct *S)
{
  SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct *)
    utMalloc(sizeof(SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc160_ICARO3_Onda_simple_v2_media_funInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c160_ICARO3_Onda_simple_v2_media_fun;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c160_ICARO3_Onda_simple_v2_media_fun;
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

void c160_ICARO3_Onda_simple_v2_media_fun_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c160_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c160_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c160_ICARO3_Onda_simple_v2_media_fun(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c160_ICARO3_Onda_simple_v2_media_fun_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
