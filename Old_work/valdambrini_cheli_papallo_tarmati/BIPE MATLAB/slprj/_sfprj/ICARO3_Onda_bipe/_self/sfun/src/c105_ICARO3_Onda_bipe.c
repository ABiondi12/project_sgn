/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_sfun.h"
#include "c105_ICARO3_Onda_bipe.h"
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
static const char * c105_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void initialize_params_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void enable_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void disable_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct *
  chartInstance);
static void c105_update_debugger_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void set_sim_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c105_st);
static void finalize_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void sf_gateway_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void initSimStructsc105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c105_machineNumber, uint32_T
  c105_chartNumber, uint32_T c105_instanceNumber);
static const mxArray *c105_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData);
static uint16_T c105_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_y, const char_T *c105_identifier);
static uint16_T c105_b_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId);
static void c105_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData);
static const mxArray *c105_b_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData);
static const mxArray *c105_c_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData);
static real_T c105_c_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId);
static void c105_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData);
static void c105_info_helper(const mxArray **c105_info);
static const mxArray *c105_emlrt_marshallOut(const char * c105_u);
static const mxArray *c105_b_emlrt_marshallOut(const uint32_T c105_u);
static const mxArray *c105_d_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData);
static int32_T c105_d_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId);
static void c105_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData);
static uint8_T c105_e_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_b_is_active_c105_ICARO3_Onda_bipe, const
  char_T *c105_identifier);
static uint8_T c105_f_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId);
static void init_dsm_address_info(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  chartInstance->c105_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c105_is_active_c105_ICARO3_Onda_bipe = 0U;
}

static void initialize_params_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c105_update_debugger_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  const mxArray *c105_st;
  const mxArray *c105_y = NULL;
  uint16_T c105_hoistedGlobal;
  uint16_T c105_u;
  const mxArray *c105_b_y = NULL;
  uint8_T c105_b_hoistedGlobal;
  uint8_T c105_b_u;
  const mxArray *c105_c_y = NULL;
  uint16_T *c105_d_y;
  c105_d_y = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c105_st = NULL;
  c105_st = NULL;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_createcellmatrix(2, 1), false);
  c105_hoistedGlobal = *c105_d_y;
  c105_u = c105_hoistedGlobal;
  c105_b_y = NULL;
  sf_mex_assign(&c105_b_y, sf_mex_create("y", &c105_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c105_y, 0, c105_b_y);
  c105_b_hoistedGlobal = chartInstance->c105_is_active_c105_ICARO3_Onda_bipe;
  c105_b_u = c105_b_hoistedGlobal;
  c105_c_y = NULL;
  sf_mex_assign(&c105_c_y, sf_mex_create("y", &c105_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c105_y, 1, c105_c_y);
  sf_mex_assign(&c105_st, c105_y, false);
  return c105_st;
}

static void set_sim_state_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c105_st)
{
  const mxArray *c105_u;
  uint16_T *c105_y;
  c105_y = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c105_doneDoubleBufferReInit = true;
  c105_u = sf_mex_dup(c105_st);
  *c105_y = c105_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c105_u, 0)), "y");
  chartInstance->c105_is_active_c105_ICARO3_Onda_bipe = c105_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c105_u, 1)),
     "is_active_c105_ICARO3_Onda_bipe");
  sf_mex_destroy(&c105_u);
  c105_update_debugger_state_c105_ICARO3_Onda_bipe(chartInstance);
  sf_mex_destroy(&c105_st);
}

static void finalize_c105_ICARO3_Onda_bipe(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  int32_T c105_i0;
  int32_T c105_i1;
  uint16_T c105_u[2];
  uint32_T c105_debug_family_var_map[4];
  real_T c105_nargin = 1.0;
  real_T c105_nargout = 1.0;
  uint16_T c105_y;
  uint16_T c105_a;
  uint16_T c105_a1;
  uint16_T c105_b_a;
  uint16_T c105_c;
  uint16_T c105_varargin_1;
  uint16_T c105_varargin_2;
  uint16_T c105_c_a;
  uint16_T c105_b;
  uint16_T *c105_b_y;
  uint16_T (*c105_b_u)[2];
  c105_b_y = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c105_b_u = (uint16_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c105_sfEvent);
  for (c105_i0 = 0; c105_i0 < 2; c105_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c105_b_u)[c105_i0], 0U);
  }

  chartInstance->c105_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c105_sfEvent);
  for (c105_i1 = 0; c105_i1 < 2; c105_i1++) {
    c105_u[c105_i1] = (*c105_b_u)[c105_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c105_debug_family_names,
    c105_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c105_nargin, 0U, c105_c_sf_marshallOut,
    c105_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c105_nargout, 1U, c105_c_sf_marshallOut,
    c105_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c105_u, 2U, c105_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c105_y, 3U, c105_sf_marshallOut,
    c105_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c105_sfEvent, 3);
  c105_a = c105_u[1];
  c105_a1 = c105_a;
  c105_b_a = c105_a1;
  c105_c = (uint16_T)(c105_b_a << 8);
  c105_varargin_1 = c105_c;
  c105_varargin_2 = c105_u[0];
  c105_c_a = c105_varargin_1;
  c105_b = c105_varargin_2;
  c105_y = (uint16_T)(c105_c_a | c105_b);
  _SFD_EML_CALL(0U, chartInstance->c105_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  *c105_b_y = c105_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c105_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO3_Onda_bipeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c105_b_y, 1U);
}

static void initSimStructsc105_ICARO3_Onda_bipe
  (SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c105_machineNumber, uint32_T
  c105_chartNumber, uint32_T c105_instanceNumber)
{
  (void)c105_machineNumber;
  (void)c105_chartNumber;
  (void)c105_instanceNumber;
}

static const mxArray *c105_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData)
{
  const mxArray *c105_mxArrayOutData = NULL;
  uint16_T c105_u;
  const mxArray *c105_y = NULL;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_mxArrayOutData = NULL;
  c105_u = *(uint16_T *)c105_inData;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", &c105_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c105_mxArrayOutData, c105_y, false);
  return c105_mxArrayOutData;
}

static uint16_T c105_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_y, const char_T *c105_identifier)
{
  uint16_T c105_b_y;
  emlrtMsgIdentifier c105_thisId;
  c105_thisId.fIdentifier = c105_identifier;
  c105_thisId.fParent = NULL;
  c105_b_y = c105_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c105_y),
    &c105_thisId);
  sf_mex_destroy(&c105_y);
  return c105_b_y;
}

static uint16_T c105_b_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId)
{
  uint16_T c105_y;
  uint16_T c105_u0;
  (void)chartInstance;
  sf_mex_import(c105_parentId, sf_mex_dup(c105_u), &c105_u0, 1, 5, 0U, 0, 0U, 0);
  c105_y = c105_u0;
  sf_mex_destroy(&c105_u);
  return c105_y;
}

static void c105_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData)
{
  const mxArray *c105_y;
  const char_T *c105_identifier;
  emlrtMsgIdentifier c105_thisId;
  uint16_T c105_b_y;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_y = sf_mex_dup(c105_mxArrayInData);
  c105_identifier = c105_varName;
  c105_thisId.fIdentifier = c105_identifier;
  c105_thisId.fParent = NULL;
  c105_b_y = c105_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c105_y),
    &c105_thisId);
  sf_mex_destroy(&c105_y);
  *(uint16_T *)c105_outData = c105_b_y;
  sf_mex_destroy(&c105_mxArrayInData);
}

static const mxArray *c105_b_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData)
{
  const mxArray *c105_mxArrayOutData = NULL;
  int32_T c105_i2;
  uint16_T c105_b_inData[2];
  int32_T c105_i3;
  uint16_T c105_u[2];
  const mxArray *c105_y = NULL;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_mxArrayOutData = NULL;
  for (c105_i2 = 0; c105_i2 < 2; c105_i2++) {
    c105_b_inData[c105_i2] = (*(uint16_T (*)[2])c105_inData)[c105_i2];
  }

  for (c105_i3 = 0; c105_i3 < 2; c105_i3++) {
    c105_u[c105_i3] = c105_b_inData[c105_i3];
  }

  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", c105_u, 5, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c105_mxArrayOutData, c105_y, false);
  return c105_mxArrayOutData;
}

static const mxArray *c105_c_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData)
{
  const mxArray *c105_mxArrayOutData = NULL;
  real_T c105_u;
  const mxArray *c105_y = NULL;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_mxArrayOutData = NULL;
  c105_u = *(real_T *)c105_inData;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", &c105_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c105_mxArrayOutData, c105_y, false);
  return c105_mxArrayOutData;
}

static real_T c105_c_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId)
{
  real_T c105_y;
  real_T c105_d0;
  (void)chartInstance;
  sf_mex_import(c105_parentId, sf_mex_dup(c105_u), &c105_d0, 1, 0, 0U, 0, 0U, 0);
  c105_y = c105_d0;
  sf_mex_destroy(&c105_u);
  return c105_y;
}

static void c105_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData)
{
  const mxArray *c105_nargout;
  const char_T *c105_identifier;
  emlrtMsgIdentifier c105_thisId;
  real_T c105_y;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_nargout = sf_mex_dup(c105_mxArrayInData);
  c105_identifier = c105_varName;
  c105_thisId.fIdentifier = c105_identifier;
  c105_thisId.fParent = NULL;
  c105_y = c105_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c105_nargout),
    &c105_thisId);
  sf_mex_destroy(&c105_nargout);
  *(real_T *)c105_outData = c105_y;
  sf_mex_destroy(&c105_mxArrayInData);
}

const mxArray *sf_c105_ICARO3_Onda_bipe_get_eml_resolved_functions_info(void)
{
  const mxArray *c105_nameCaptureInfo = NULL;
  c105_nameCaptureInfo = NULL;
  sf_mex_assign(&c105_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c105_info_helper(&c105_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c105_nameCaptureInfo);
  return c105_nameCaptureInfo;
}

static void c105_info_helper(const mxArray **c105_info)
{
  const mxArray *c105_rhs0 = NULL;
  const mxArray *c105_lhs0 = NULL;
  const mxArray *c105_rhs1 = NULL;
  const mxArray *c105_lhs1 = NULL;
  const mxArray *c105_rhs2 = NULL;
  const mxArray *c105_lhs2 = NULL;
  const mxArray *c105_rhs3 = NULL;
  const mxArray *c105_lhs3 = NULL;
  const mxArray *c105_rhs4 = NULL;
  const mxArray *c105_lhs4 = NULL;
  const mxArray *c105_rhs5 = NULL;
  const mxArray *c105_lhs5 = NULL;
  const mxArray *c105_rhs6 = NULL;
  const mxArray *c105_lhs6 = NULL;
  const mxArray *c105_rhs7 = NULL;
  const mxArray *c105_lhs7 = NULL;
  const mxArray *c105_rhs8 = NULL;
  const mxArray *c105_lhs8 = NULL;
  const mxArray *c105_rhs9 = NULL;
  const mxArray *c105_lhs9 = NULL;
  const mxArray *c105_rhs10 = NULL;
  const mxArray *c105_lhs10 = NULL;
  const mxArray *c105_rhs11 = NULL;
  const mxArray *c105_lhs11 = NULL;
  const mxArray *c105_rhs12 = NULL;
  const mxArray *c105_lhs12 = NULL;
  const mxArray *c105_rhs13 = NULL;
  const mxArray *c105_lhs13 = NULL;
  const mxArray *c105_rhs14 = NULL;
  const mxArray *c105_lhs14 = NULL;
  const mxArray *c105_rhs15 = NULL;
  const mxArray *c105_lhs15 = NULL;
  const mxArray *c105_rhs16 = NULL;
  const mxArray *c105_lhs16 = NULL;
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("bitshift"), "name", "name",
                  0);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1383877292U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c105_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c105_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 2);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1286818782U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c105_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c105_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c105_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_scalexp_alloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c105_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "coder.internal.scalexpAlloc"), "name", "name", 6);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c105_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 7);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1363713854U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c105_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c105_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1286818726U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c105_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 10);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 10);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c105_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 11);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c105_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(""), "context", "context",
                  12);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("bitor"), "name", "name",
                  12);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1383877292U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c105_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs12), "rhs",
                  "rhs", 12);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs12), "lhs",
                  "lhs", 12);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 13);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c105_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs13), "rhs",
                  "rhs", 13);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs13), "lhs",
                  "lhs", 13);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("bitbinop"), "name", "name",
                  14);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1383877290U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c105_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs14), "rhs",
                  "rhs", 14);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs14), "lhs",
                  "lhs", 14);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 15);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c105_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs15), "rhs",
                  "rhs", 15);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs15), "lhs",
                  "lhs", 15);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 16);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c105_info, c105_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(1286818796U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c105_info, c105_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c105_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c105_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_rhs16), "rhs",
                  "rhs", 16);
  sf_mex_addfield(*c105_info, sf_mex_duplicatearraysafe(&c105_lhs16), "lhs",
                  "lhs", 16);
  sf_mex_destroy(&c105_rhs0);
  sf_mex_destroy(&c105_lhs0);
  sf_mex_destroy(&c105_rhs1);
  sf_mex_destroy(&c105_lhs1);
  sf_mex_destroy(&c105_rhs2);
  sf_mex_destroy(&c105_lhs2);
  sf_mex_destroy(&c105_rhs3);
  sf_mex_destroy(&c105_lhs3);
  sf_mex_destroy(&c105_rhs4);
  sf_mex_destroy(&c105_lhs4);
  sf_mex_destroy(&c105_rhs5);
  sf_mex_destroy(&c105_lhs5);
  sf_mex_destroy(&c105_rhs6);
  sf_mex_destroy(&c105_lhs6);
  sf_mex_destroy(&c105_rhs7);
  sf_mex_destroy(&c105_lhs7);
  sf_mex_destroy(&c105_rhs8);
  sf_mex_destroy(&c105_lhs8);
  sf_mex_destroy(&c105_rhs9);
  sf_mex_destroy(&c105_lhs9);
  sf_mex_destroy(&c105_rhs10);
  sf_mex_destroy(&c105_lhs10);
  sf_mex_destroy(&c105_rhs11);
  sf_mex_destroy(&c105_lhs11);
  sf_mex_destroy(&c105_rhs12);
  sf_mex_destroy(&c105_lhs12);
  sf_mex_destroy(&c105_rhs13);
  sf_mex_destroy(&c105_lhs13);
  sf_mex_destroy(&c105_rhs14);
  sf_mex_destroy(&c105_lhs14);
  sf_mex_destroy(&c105_rhs15);
  sf_mex_destroy(&c105_lhs15);
  sf_mex_destroy(&c105_rhs16);
  sf_mex_destroy(&c105_lhs16);
}

static const mxArray *c105_emlrt_marshallOut(const char * c105_u)
{
  const mxArray *c105_y = NULL;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", c105_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c105_u)), false);
  return c105_y;
}

static const mxArray *c105_b_emlrt_marshallOut(const uint32_T c105_u)
{
  const mxArray *c105_y = NULL;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", &c105_u, 7, 0U, 0U, 0U, 0), false);
  return c105_y;
}

static const mxArray *c105_d_sf_marshallOut(void *chartInstanceVoid, void
  *c105_inData)
{
  const mxArray *c105_mxArrayOutData = NULL;
  int32_T c105_u;
  const mxArray *c105_y = NULL;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_mxArrayOutData = NULL;
  c105_u = *(int32_T *)c105_inData;
  c105_y = NULL;
  sf_mex_assign(&c105_y, sf_mex_create("y", &c105_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c105_mxArrayOutData, c105_y, false);
  return c105_mxArrayOutData;
}

static int32_T c105_d_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId)
{
  int32_T c105_y;
  int32_T c105_i4;
  (void)chartInstance;
  sf_mex_import(c105_parentId, sf_mex_dup(c105_u), &c105_i4, 1, 6, 0U, 0, 0U, 0);
  c105_y = c105_i4;
  sf_mex_destroy(&c105_u);
  return c105_y;
}

static void c105_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c105_mxArrayInData, const char_T *c105_varName, void *c105_outData)
{
  const mxArray *c105_b_sfEvent;
  const char_T *c105_identifier;
  emlrtMsgIdentifier c105_thisId;
  int32_T c105_y;
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c105_b_sfEvent = sf_mex_dup(c105_mxArrayInData);
  c105_identifier = c105_varName;
  c105_thisId.fIdentifier = c105_identifier;
  c105_thisId.fParent = NULL;
  c105_y = c105_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c105_b_sfEvent),
    &c105_thisId);
  sf_mex_destroy(&c105_b_sfEvent);
  *(int32_T *)c105_outData = c105_y;
  sf_mex_destroy(&c105_mxArrayInData);
}

static uint8_T c105_e_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_b_is_active_c105_ICARO3_Onda_bipe, const
  char_T *c105_identifier)
{
  uint8_T c105_y;
  emlrtMsgIdentifier c105_thisId;
  c105_thisId.fIdentifier = c105_identifier;
  c105_thisId.fParent = NULL;
  c105_y = c105_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c105_b_is_active_c105_ICARO3_Onda_bipe), &c105_thisId);
  sf_mex_destroy(&c105_b_is_active_c105_ICARO3_Onda_bipe);
  return c105_y;
}

static uint8_T c105_f_emlrt_marshallIn(SFc105_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c105_u, const emlrtMsgIdentifier *c105_parentId)
{
  uint8_T c105_y;
  uint8_T c105_u1;
  (void)chartInstance;
  sf_mex_import(c105_parentId, sf_mex_dup(c105_u), &c105_u1, 1, 3, 0U, 0, 0U, 0);
  c105_y = c105_u1;
  sf_mex_destroy(&c105_u);
  return c105_y;
}

static void init_dsm_address_info(SFc105_ICARO3_Onda_bipeInstanceStruct
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

void sf_c105_ICARO3_Onda_bipe_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(532167515U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3938357286U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3556479691U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1183272826U);
}

mxArray *sf_c105_ICARO3_Onda_bipe_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TFhVhoeD2Wq2p2Z7tMYnnC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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

mxArray *sf_c105_ICARO3_Onda_bipe_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c105_ICARO3_Onda_bipe_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c105_ICARO3_Onda_bipe(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c105_ICARO3_Onda_bipe\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c105_ICARO3_Onda_bipe_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipeMachineNumber_,
           105,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,70);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c105_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c105_sf_marshallOut,(MexInFcnForType)c105_sf_marshallIn);

        {
          uint16_T *c105_y;
          uint16_T (*c105_u)[2];
          c105_y = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c105_u = (uint16_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c105_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c105_y);
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
  return "Yf1P9MepgOLabHJvS3ddEH";
}

static void sf_opaque_initialize_c105_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
  initialize_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c105_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  enable_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c105_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  disable_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c105_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  sf_gateway_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c105_ICARO3_Onda_bipe(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c105_ICARO3_Onda_bipe
    ((SFc105_ICARO3_Onda_bipeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c105_ICARO3_Onda_bipe();/* state var info */
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

extern void sf_internal_set_sim_state_c105_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c105_ICARO3_Onda_bipe();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c105_ICARO3_Onda_bipe(SimStruct* S)
{
  return sf_internal_get_sim_state_c105_ICARO3_Onda_bipe(S);
}

static void sf_opaque_set_sim_state_c105_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c105_ICARO3_Onda_bipe(S, st);
}

static void sf_opaque_terminate_c105_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc105_ICARO3_Onda_bipeInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_optimization_info();
    }

    finalize_c105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
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
  initSimStructsc105_ICARO3_Onda_bipe((SFc105_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c105_ICARO3_Onda_bipe(SimStruct *S)
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
    initialize_params_c105_ICARO3_Onda_bipe
      ((SFc105_ICARO3_Onda_bipeInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c105_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_bipe_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      105);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,105,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,105,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,105);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,105,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,105,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,105);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(727739660U));
  ssSetChecksum1(S,(2650127090U));
  ssSetChecksum2(S,(448181975U));
  ssSetChecksum3(S,(1019439784U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c105_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c105_ICARO3_Onda_bipe(SimStruct *S)
{
  SFc105_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc105_ICARO3_Onda_bipeInstanceStruct *)utMalloc(sizeof
    (SFc105_ICARO3_Onda_bipeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc105_ICARO3_Onda_bipeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlStart = mdlStart_c105_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c105_ICARO3_Onda_bipe;
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

void c105_ICARO3_Onda_bipe_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c105_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c105_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c105_ICARO3_Onda_bipe(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c105_ICARO3_Onda_bipe_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}