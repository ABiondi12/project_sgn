/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_sfun.h"
#include "c4_ICARO3_Onda_bipe.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[5] = { "R", "nargin", "nargout", "u",
  "y" };

/* Function Declarations */
static void initialize_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void initialize_params_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void enable_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void disable_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void set_sim_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void sf_gateway_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void initSimStructsc4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_y, const char_T *c4_identifier, real32_T
  c4_b_y[3]);
static void c4_b_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real32_T c4_y[3]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_ICARO3_Onda_bipe, const
  char_T *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_ICARO3_Onda_bipe = 0U;
}

static void initialize_params_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real32_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real32_T (*c4_d_y)[3];
  c4_d_y = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_u[c4_i0] = (*c4_d_y)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_ICARO3_Onda_bipe;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real32_T c4_fv0[3];
  int32_T c4_i1;
  real32_T (*c4_y)[3];
  c4_y = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "y",
                      c4_fv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*c4_y)[c4_i1] = c4_fv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_ICARO3_Onda_bipe = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_ICARO3_Onda_bipe");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_ICARO3_Onda_bipe(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_ICARO3_Onda_bipe(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real32_T c4_u[3];
  uint32_T c4_debug_family_var_map[5];
  real_T c4_R[9];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real32_T c4_y[3];
  int32_T c4_i4;
  static real_T c4_a[9] = { 1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0 };

  int32_T c4_i5;
  real32_T c4_b[3];
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  static real32_T c4_fv1[9] = { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F,
    -1.0F };

  int32_T c4_i9;
  int32_T c4_i10;
  real32_T (*c4_b_y)[3];
  real32_T (*c4_b_u)[3];
  c4_b_y = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c4_b_u)[c4_i2], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_u[c4_i3] = (*c4_b_u)[c4_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_R, 0U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_u, 3U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_y, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i4 = 0; c4_i4 < 9; c4_i4++) {
    c4_R[c4_i4] = c4_a[c4_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_b[c4_i5] = c4_u[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_y[c4_i6] = 0.0F;
    c4_i7 = 0;
    for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
      c4_y[c4_i6] += c4_fv1[c4_i7 + c4_i6] * c4_b[c4_i8];
      c4_i7 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    (*c4_b_y)[c4_i9] = c4_y[c4_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO3_Onda_bipeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c4_b_y)[c4_i10], 1U);
  }
}

static void initSimStructsc4_ICARO3_Onda_bipe
  (SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i11;
  real32_T c4_b_inData[3];
  int32_T c4_i12;
  real32_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_b_inData[c4_i11] = (*(real32_T (*)[3])c4_inData)[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_u[c4_i12] = c4_b_inData[c4_i12];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_y, const char_T *c4_identifier, real32_T
  c4_b_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
}

static void c4_b_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real32_T c4_y[3])
{
  real32_T c4_fv2[3];
  int32_T c4_i13;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_fv2, 1, 1, 0U, 1, 0U, 1, 3);
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_y[c4_i13] = c4_fv2[c4_i13];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_y;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_b_y[3];
  int32_T c4_i14;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_y = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    (*(real32_T (*)[3])c4_outData)[c4_i14] = c4_b_y[c4_i14];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  real_T c4_b_inData[9];
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i15 = 0;
  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
      c4_b_inData[c4_i17 + c4_i15] = (*(real_T (*)[9])c4_inData)[c4_i17 + c4_i15];
    }

    c4_i15 += 3;
  }

  c4_i18 = 0;
  for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
    for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
      c4_u[c4_i20 + c4_i18] = c4_b_inData[c4_i20 + c4_i18];
    }

    c4_i18 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_ICARO3_Onda_bipe_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i21;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i21, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i21;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_ICARO3_Onda_bipe, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_ICARO3_Onda_bipe), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_ICARO3_Onda_bipe);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
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

void sf_c4_ICARO3_Onda_bipe_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1649941481U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(832916628U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(186841368U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2386809097U);
}

mxArray *sf_c4_ICARO3_Onda_bipe_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ies247orudw6kH9Wo65rvE");
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

mxArray *sf_c4_ICARO3_Onda_bipe_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_ICARO3_Onda_bipe_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_ICARO3_Onda_bipe(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_ICARO3_Onda_bipe\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ICARO3_Onda_bipe_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipeMachineNumber_,
           4,
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
        init_script_number_translation(_ICARO3_Onda_bipeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ICARO3_Onda_bipeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipeMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,60);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real32_T (*c4_u)[3];
          real32_T (*c4_y)[3];
          c4_y = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "uY1vOOgcPZZRi96IqwoE2E";
}

static void sf_opaque_initialize_c4_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
  initialize_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  enable_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  disable_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  sf_gateway_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_ICARO3_Onda_bipe(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_ICARO3_Onda_bipe
    ((SFc4_ICARO3_Onda_bipeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_ICARO3_Onda_bipe();/* state var info */
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

extern void sf_internal_set_sim_state_c4_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_ICARO3_Onda_bipe();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_ICARO3_Onda_bipe(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_ICARO3_Onda_bipe(S);
}

static void sf_opaque_set_sim_state_c4_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_ICARO3_Onda_bipe(S, st);
}

static void sf_opaque_terminate_c4_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_ICARO3_Onda_bipeInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_optimization_info();
    }

    finalize_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
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
  initSimStructsc4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_ICARO3_Onda_bipe(SimStruct *S)
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
    initialize_params_c4_ICARO3_Onda_bipe((SFc4_ICARO3_Onda_bipeInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_bipe_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1491168247U));
  ssSetChecksum1(S,(2976165074U));
  ssSetChecksum2(S,(1144300987U));
  ssSetChecksum3(S,(2366295104U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_ICARO3_Onda_bipe(SimStruct *S)
{
  SFc4_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_ICARO3_Onda_bipeInstanceStruct *)utMalloc(sizeof
    (SFc4_ICARO3_Onda_bipeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_ICARO3_Onda_bipeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_ICARO3_Onda_bipe;
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

void c4_ICARO3_Onda_bipe_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ICARO3_Onda_bipe(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ICARO3_Onda_bipe_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
