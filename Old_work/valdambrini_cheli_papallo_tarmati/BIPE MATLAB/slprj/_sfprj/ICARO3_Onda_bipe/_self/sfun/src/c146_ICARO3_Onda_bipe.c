/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_sfun.h"
#include "c146_ICARO3_Onda_bipe.h"
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
static const char * c146_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void initialize_params_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void enable_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void disable_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct *
  chartInstance);
static void c146_update_debugger_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void set_sim_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c146_st);
static void finalize_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);
static void sf_gateway_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void initSimStructsc146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c146_machineNumber, uint32_T
  c146_chartNumber, uint32_T c146_instanceNumber);
static const mxArray *c146_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData);
static void c146_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_y, const char_T *c146_identifier, uint8_T
  c146_b_y[8]);
static void c146_b_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId,
  uint8_T c146_y[8]);
static void c146_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData);
static const mxArray *c146_b_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData);
static const mxArray *c146_c_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData);
static real_T c146_c_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId);
static void c146_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData);
static const mxArray *c146_d_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData);
static int32_T c146_d_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId);
static void c146_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData);
static uint8_T c146_e_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_b_is_active_c146_ICARO3_Onda_bipe, const
  char_T *c146_identifier);
static uint8_T c146_f_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId);
static void init_dsm_address_info(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  chartInstance->c146_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c146_is_active_c146_ICARO3_Onda_bipe = 0U;
}

static void initialize_params_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c146_update_debugger_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  const mxArray *c146_st;
  const mxArray *c146_y = NULL;
  int32_T c146_i0;
  uint8_T c146_u[8];
  const mxArray *c146_b_y = NULL;
  uint8_T c146_hoistedGlobal;
  uint8_T c146_b_u;
  const mxArray *c146_c_y = NULL;
  uint8_T (*c146_d_y)[8];
  c146_d_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c146_st = NULL;
  c146_st = NULL;
  c146_y = NULL;
  sf_mex_assign(&c146_y, sf_mex_createcellmatrix(2, 1), false);
  for (c146_i0 = 0; c146_i0 < 8; c146_i0++) {
    c146_u[c146_i0] = (*c146_d_y)[c146_i0];
  }

  c146_b_y = NULL;
  sf_mex_assign(&c146_b_y, sf_mex_create("y", c146_u, 3, 0U, 1U, 0U, 2, 1, 8),
                false);
  sf_mex_setcell(c146_y, 0, c146_b_y);
  c146_hoistedGlobal = chartInstance->c146_is_active_c146_ICARO3_Onda_bipe;
  c146_b_u = c146_hoistedGlobal;
  c146_c_y = NULL;
  sf_mex_assign(&c146_c_y, sf_mex_create("y", &c146_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c146_y, 1, c146_c_y);
  sf_mex_assign(&c146_st, c146_y, false);
  return c146_st;
}

static void set_sim_state_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance, const mxArray *c146_st)
{
  const mxArray *c146_u;
  uint8_T c146_uv0[8];
  int32_T c146_i1;
  uint8_T (*c146_y)[8];
  c146_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c146_doneDoubleBufferReInit = true;
  c146_u = sf_mex_dup(c146_st);
  c146_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c146_u, 0)),
                        "y", c146_uv0);
  for (c146_i1 = 0; c146_i1 < 8; c146_i1++) {
    (*c146_y)[c146_i1] = c146_uv0[c146_i1];
  }

  chartInstance->c146_is_active_c146_ICARO3_Onda_bipe = c146_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c146_u, 1)),
     "is_active_c146_ICARO3_Onda_bipe");
  sf_mex_destroy(&c146_u);
  c146_update_debugger_state_c146_ICARO3_Onda_bipe(chartInstance);
  sf_mex_destroy(&c146_st);
}

static void finalize_c146_ICARO3_Onda_bipe(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  int32_T c146_i2;
  int32_T c146_i3;
  uint8_T c146_u[8];
  uint32_T c146_debug_family_var_map[4];
  real_T c146_nargin = 1.0;
  real_T c146_nargout = 1.0;
  uint8_T c146_y[8];
  int32_T c146_i4;
  int32_T c146_i5;
  int32_T c146_i6;
  uint8_T (*c146_b_y)[8];
  uint8_T (*c146_b_u)[8];
  c146_b_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c146_b_u = (uint8_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 47U, chartInstance->c146_sfEvent);
  for (c146_i2 = 0; c146_i2 < 8; c146_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c146_b_u)[c146_i2], 0U);
  }

  chartInstance->c146_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 47U, chartInstance->c146_sfEvent);
  for (c146_i3 = 0; c146_i3 < 8; c146_i3++) {
    c146_u[c146_i3] = (*c146_b_u)[c146_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c146_debug_family_names,
    c146_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c146_nargin, 0U, c146_c_sf_marshallOut,
    c146_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c146_nargout, 1U, c146_c_sf_marshallOut,
    c146_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c146_u, 2U, c146_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c146_y, 3U, c146_sf_marshallOut,
    c146_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 3);
  for (c146_i4 = 0; c146_i4 < 8; c146_i4++) {
    c146_y[c146_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 4);
  c146_y[0] = c146_u[0];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 5);
  c146_y[1] = c146_u[1];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 6);
  c146_y[2] = c146_u[2];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 7);
  c146_y[3] = c146_u[3];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 8);
  c146_y[4] = c146_u[4];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 9);
  c146_y[5] = c146_u[5];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 10);
  c146_y[6] = c146_u[6];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, 11);
  c146_y[7] = c146_u[7];
  _SFD_EML_CALL(0U, chartInstance->c146_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c146_i5 = 0; c146_i5 < 8; c146_i5++) {
    (*c146_b_y)[c146_i5] = c146_y[c146_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c146_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO3_Onda_bipeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c146_i6 = 0; c146_i6 < 8; c146_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c146_b_y)[c146_i6], 1U);
  }
}

static void initSimStructsc146_ICARO3_Onda_bipe
  (SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c146_machineNumber, uint32_T
  c146_chartNumber, uint32_T c146_instanceNumber)
{
  (void)c146_machineNumber;
  (void)c146_chartNumber;
  (void)c146_instanceNumber;
}

static const mxArray *c146_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData)
{
  const mxArray *c146_mxArrayOutData = NULL;
  int32_T c146_i7;
  uint8_T c146_b_inData[8];
  int32_T c146_i8;
  uint8_T c146_u[8];
  const mxArray *c146_y = NULL;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_mxArrayOutData = NULL;
  for (c146_i7 = 0; c146_i7 < 8; c146_i7++) {
    c146_b_inData[c146_i7] = (*(uint8_T (*)[8])c146_inData)[c146_i7];
  }

  for (c146_i8 = 0; c146_i8 < 8; c146_i8++) {
    c146_u[c146_i8] = c146_b_inData[c146_i8];
  }

  c146_y = NULL;
  sf_mex_assign(&c146_y, sf_mex_create("y", c146_u, 3, 0U, 1U, 0U, 2, 1, 8),
                false);
  sf_mex_assign(&c146_mxArrayOutData, c146_y, false);
  return c146_mxArrayOutData;
}

static void c146_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_y, const char_T *c146_identifier, uint8_T
  c146_b_y[8])
{
  emlrtMsgIdentifier c146_thisId;
  c146_thisId.fIdentifier = c146_identifier;
  c146_thisId.fParent = NULL;
  c146_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c146_y), &c146_thisId,
    c146_b_y);
  sf_mex_destroy(&c146_y);
}

static void c146_b_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId,
  uint8_T c146_y[8])
{
  uint8_T c146_uv1[8];
  int32_T c146_i9;
  (void)chartInstance;
  sf_mex_import(c146_parentId, sf_mex_dup(c146_u), c146_uv1, 1, 3, 0U, 1, 0U, 2,
                1, 8);
  for (c146_i9 = 0; c146_i9 < 8; c146_i9++) {
    c146_y[c146_i9] = c146_uv1[c146_i9];
  }

  sf_mex_destroy(&c146_u);
}

static void c146_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData)
{
  const mxArray *c146_y;
  const char_T *c146_identifier;
  emlrtMsgIdentifier c146_thisId;
  uint8_T c146_b_y[8];
  int32_T c146_i10;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_y = sf_mex_dup(c146_mxArrayInData);
  c146_identifier = c146_varName;
  c146_thisId.fIdentifier = c146_identifier;
  c146_thisId.fParent = NULL;
  c146_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c146_y), &c146_thisId,
    c146_b_y);
  sf_mex_destroy(&c146_y);
  for (c146_i10 = 0; c146_i10 < 8; c146_i10++) {
    (*(uint8_T (*)[8])c146_outData)[c146_i10] = c146_b_y[c146_i10];
  }

  sf_mex_destroy(&c146_mxArrayInData);
}

static const mxArray *c146_b_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData)
{
  const mxArray *c146_mxArrayOutData = NULL;
  int32_T c146_i11;
  uint8_T c146_b_inData[8];
  int32_T c146_i12;
  uint8_T c146_u[8];
  const mxArray *c146_y = NULL;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_mxArrayOutData = NULL;
  for (c146_i11 = 0; c146_i11 < 8; c146_i11++) {
    c146_b_inData[c146_i11] = (*(uint8_T (*)[8])c146_inData)[c146_i11];
  }

  for (c146_i12 = 0; c146_i12 < 8; c146_i12++) {
    c146_u[c146_i12] = c146_b_inData[c146_i12];
  }

  c146_y = NULL;
  sf_mex_assign(&c146_y, sf_mex_create("y", c146_u, 3, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c146_mxArrayOutData, c146_y, false);
  return c146_mxArrayOutData;
}

static const mxArray *c146_c_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData)
{
  const mxArray *c146_mxArrayOutData = NULL;
  real_T c146_u;
  const mxArray *c146_y = NULL;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_mxArrayOutData = NULL;
  c146_u = *(real_T *)c146_inData;
  c146_y = NULL;
  sf_mex_assign(&c146_y, sf_mex_create("y", &c146_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c146_mxArrayOutData, c146_y, false);
  return c146_mxArrayOutData;
}

static real_T c146_c_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId)
{
  real_T c146_y;
  real_T c146_d0;
  (void)chartInstance;
  sf_mex_import(c146_parentId, sf_mex_dup(c146_u), &c146_d0, 1, 0, 0U, 0, 0U, 0);
  c146_y = c146_d0;
  sf_mex_destroy(&c146_u);
  return c146_y;
}

static void c146_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData)
{
  const mxArray *c146_nargout;
  const char_T *c146_identifier;
  emlrtMsgIdentifier c146_thisId;
  real_T c146_y;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_nargout = sf_mex_dup(c146_mxArrayInData);
  c146_identifier = c146_varName;
  c146_thisId.fIdentifier = c146_identifier;
  c146_thisId.fParent = NULL;
  c146_y = c146_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c146_nargout),
    &c146_thisId);
  sf_mex_destroy(&c146_nargout);
  *(real_T *)c146_outData = c146_y;
  sf_mex_destroy(&c146_mxArrayInData);
}

const mxArray *sf_c146_ICARO3_Onda_bipe_get_eml_resolved_functions_info(void)
{
  const mxArray *c146_nameCaptureInfo = NULL;
  c146_nameCaptureInfo = NULL;
  sf_mex_assign(&c146_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c146_nameCaptureInfo;
}

static const mxArray *c146_d_sf_marshallOut(void *chartInstanceVoid, void
  *c146_inData)
{
  const mxArray *c146_mxArrayOutData = NULL;
  int32_T c146_u;
  const mxArray *c146_y = NULL;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_mxArrayOutData = NULL;
  c146_u = *(int32_T *)c146_inData;
  c146_y = NULL;
  sf_mex_assign(&c146_y, sf_mex_create("y", &c146_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c146_mxArrayOutData, c146_y, false);
  return c146_mxArrayOutData;
}

static int32_T c146_d_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId)
{
  int32_T c146_y;
  int32_T c146_i13;
  (void)chartInstance;
  sf_mex_import(c146_parentId, sf_mex_dup(c146_u), &c146_i13, 1, 6, 0U, 0, 0U, 0);
  c146_y = c146_i13;
  sf_mex_destroy(&c146_u);
  return c146_y;
}

static void c146_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c146_mxArrayInData, const char_T *c146_varName, void *c146_outData)
{
  const mxArray *c146_b_sfEvent;
  const char_T *c146_identifier;
  emlrtMsgIdentifier c146_thisId;
  int32_T c146_y;
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)chartInstanceVoid;
  c146_b_sfEvent = sf_mex_dup(c146_mxArrayInData);
  c146_identifier = c146_varName;
  c146_thisId.fIdentifier = c146_identifier;
  c146_thisId.fParent = NULL;
  c146_y = c146_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c146_b_sfEvent),
    &c146_thisId);
  sf_mex_destroy(&c146_b_sfEvent);
  *(int32_T *)c146_outData = c146_y;
  sf_mex_destroy(&c146_mxArrayInData);
}

static uint8_T c146_e_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_b_is_active_c146_ICARO3_Onda_bipe, const
  char_T *c146_identifier)
{
  uint8_T c146_y;
  emlrtMsgIdentifier c146_thisId;
  c146_thisId.fIdentifier = c146_identifier;
  c146_thisId.fParent = NULL;
  c146_y = c146_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c146_b_is_active_c146_ICARO3_Onda_bipe), &c146_thisId);
  sf_mex_destroy(&c146_b_is_active_c146_ICARO3_Onda_bipe);
  return c146_y;
}

static uint8_T c146_f_emlrt_marshallIn(SFc146_ICARO3_Onda_bipeInstanceStruct
  *chartInstance, const mxArray *c146_u, const emlrtMsgIdentifier *c146_parentId)
{
  uint8_T c146_y;
  uint8_T c146_u0;
  (void)chartInstance;
  sf_mex_import(c146_parentId, sf_mex_dup(c146_u), &c146_u0, 1, 3, 0U, 0, 0U, 0);
  c146_y = c146_u0;
  sf_mex_destroy(&c146_u);
  return c146_y;
}

static void init_dsm_address_info(SFc146_ICARO3_Onda_bipeInstanceStruct
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

void sf_c146_ICARO3_Onda_bipe_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2837198802U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3478148634U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3421058923U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2870579574U);
}

mxArray *sf_c146_ICARO3_Onda_bipe_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6ioYYHHv4D3Rx4NuebSW0");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      pr[1] = (double)(8);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

mxArray *sf_c146_ICARO3_Onda_bipe_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c146_ICARO3_Onda_bipe_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c146_ICARO3_Onda_bipe(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c146_ICARO3_Onda_bipe\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c146_ICARO3_Onda_bipe_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipeMachineNumber_,
           146,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,134);

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c146_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c146_sf_marshallOut,(MexInFcnForType)
            c146_sf_marshallIn);
        }

        {
          uint8_T (*c146_u)[8];
          uint8_T (*c146_y)[8];
          c146_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          c146_u = (uint8_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c146_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c146_y);
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
  return "gqXZOAzeuxEazoJ7TcegDC";
}

static void sf_opaque_initialize_c146_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
  initialize_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c146_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  enable_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c146_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  disable_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c146_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  sf_gateway_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c146_ICARO3_Onda_bipe(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c146_ICARO3_Onda_bipe
    ((SFc146_ICARO3_Onda_bipeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c146_ICARO3_Onda_bipe();/* state var info */
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

extern void sf_internal_set_sim_state_c146_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c146_ICARO3_Onda_bipe();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c146_ICARO3_Onda_bipe(SimStruct* S)
{
  return sf_internal_get_sim_state_c146_ICARO3_Onda_bipe(S);
}

static void sf_opaque_set_sim_state_c146_ICARO3_Onda_bipe(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c146_ICARO3_Onda_bipe(S, st);
}

static void sf_opaque_terminate_c146_ICARO3_Onda_bipe(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc146_ICARO3_Onda_bipeInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_optimization_info();
    }

    finalize_c146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
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
  initSimStructsc146_ICARO3_Onda_bipe((SFc146_ICARO3_Onda_bipeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c146_ICARO3_Onda_bipe(SimStruct *S)
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
    initialize_params_c146_ICARO3_Onda_bipe
      ((SFc146_ICARO3_Onda_bipeInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c146_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_bipe_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      146);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,146,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,146,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,146);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,146,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,146,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,146);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1942999319U));
  ssSetChecksum1(S,(1339096226U));
  ssSetChecksum2(S,(337993607U));
  ssSetChecksum3(S,(284073480U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c146_ICARO3_Onda_bipe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c146_ICARO3_Onda_bipe(SimStruct *S)
{
  SFc146_ICARO3_Onda_bipeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc146_ICARO3_Onda_bipeInstanceStruct *)utMalloc(sizeof
    (SFc146_ICARO3_Onda_bipeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc146_ICARO3_Onda_bipeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlStart = mdlStart_c146_ICARO3_Onda_bipe;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c146_ICARO3_Onda_bipe;
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

void c146_ICARO3_Onda_bipe_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c146_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c146_ICARO3_Onda_bipe(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c146_ICARO3_Onda_bipe(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c146_ICARO3_Onda_bipe_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
