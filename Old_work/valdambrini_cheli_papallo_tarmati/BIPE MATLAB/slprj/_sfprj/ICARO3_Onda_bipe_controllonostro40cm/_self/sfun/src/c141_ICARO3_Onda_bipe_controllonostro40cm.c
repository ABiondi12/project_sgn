/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun.h"
#include "c141_ICARO3_Onda_bipe_controllonostro40cm.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c141_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initialize_params_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void enable_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void disable_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c141_update_debugger_state_c141_ICARO3_Onda_bipe_controllonostro
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_st);
static void finalize_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void sf_gateway_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initSimStructsc141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c141_machineNumber, uint32_T
  c141_chartNumber, uint32_T c141_instanceNumber);
static const mxArray *c141_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData);
static void c141_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_y, const char_T *c141_identifier, uint8_T c141_b_y[8]);
static void c141_b_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId, uint8_T
   c141_y[8]);
static void c141_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData);
static const mxArray *c141_b_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData);
static const mxArray *c141_c_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData);
static real_T c141_c_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId);
static void c141_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData);
static const mxArray *c141_d_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData);
static int32_T c141_d_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId);
static void c141_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData);
static uint8_T c141_e_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_b_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c141_identifier);
static uint8_T c141_f_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId);
static void init_dsm_address_info
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  chartInstance->c141_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c141_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm = 0U;
}

static void initialize_params_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c141_update_debugger_state_c141_ICARO3_Onda_bipe_controllonostro
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  const mxArray *c141_st;
  const mxArray *c141_y = NULL;
  int32_T c141_i0;
  uint8_T c141_u[8];
  const mxArray *c141_b_y = NULL;
  uint8_T c141_hoistedGlobal;
  uint8_T c141_b_u;
  const mxArray *c141_c_y = NULL;
  uint8_T (*c141_d_y)[8];
  c141_d_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c141_st = NULL;
  c141_st = NULL;
  c141_y = NULL;
  sf_mex_assign(&c141_y, sf_mex_createcellmatrix(2, 1), false);
  for (c141_i0 = 0; c141_i0 < 8; c141_i0++) {
    c141_u[c141_i0] = (*c141_d_y)[c141_i0];
  }

  c141_b_y = NULL;
  sf_mex_assign(&c141_b_y, sf_mex_create("y", c141_u, 3, 0U, 1U, 0U, 2, 1, 8),
                false);
  sf_mex_setcell(c141_y, 0, c141_b_y);
  c141_hoistedGlobal =
    chartInstance->c141_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm;
  c141_b_u = c141_hoistedGlobal;
  c141_c_y = NULL;
  sf_mex_assign(&c141_c_y, sf_mex_create("y", &c141_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c141_y, 1, c141_c_y);
  sf_mex_assign(&c141_st, c141_y, false);
  return c141_st;
}

static void set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_st)
{
  const mxArray *c141_u;
  uint8_T c141_uv0[8];
  int32_T c141_i1;
  uint8_T (*c141_y)[8];
  c141_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c141_doneDoubleBufferReInit = true;
  c141_u = sf_mex_dup(c141_st);
  c141_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c141_u, 0)),
                        "y", c141_uv0);
  for (c141_i1 = 0; c141_i1 < 8; c141_i1++) {
    (*c141_y)[c141_i1] = c141_uv0[c141_i1];
  }

  chartInstance->c141_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm =
    c141_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c141_u, 1)),
    "is_active_c141_ICARO3_Onda_bipe_controllonostro40cm");
  sf_mex_destroy(&c141_u);
  c141_update_debugger_state_c141_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c141_st);
}

static void finalize_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  int32_T c141_i2;
  int32_T c141_i3;
  uint8_T c141_u[8];
  uint32_T c141_debug_family_var_map[4];
  real_T c141_nargin = 1.0;
  real_T c141_nargout = 1.0;
  uint8_T c141_y[8];
  int32_T c141_i4;
  int32_T c141_i5;
  int32_T c141_i6;
  uint8_T (*c141_b_y)[8];
  uint8_T (*c141_b_u)[8];
  c141_b_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c141_b_u = (uint8_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 41U, chartInstance->c141_sfEvent);
  for (c141_i2 = 0; c141_i2 < 8; c141_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c141_b_u)[c141_i2], 0U);
  }

  chartInstance->c141_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 41U, chartInstance->c141_sfEvent);
  for (c141_i3 = 0; c141_i3 < 8; c141_i3++) {
    c141_u[c141_i3] = (*c141_b_u)[c141_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c141_debug_family_names,
    c141_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c141_nargin, 0U, c141_c_sf_marshallOut,
    c141_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c141_nargout, 1U, c141_c_sf_marshallOut,
    c141_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c141_u, 2U, c141_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c141_y, 3U, c141_sf_marshallOut,
    c141_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 3);
  for (c141_i4 = 0; c141_i4 < 8; c141_i4++) {
    c141_y[c141_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 4);
  c141_y[0] = c141_u[0];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 5);
  c141_y[1] = c141_u[1];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 6);
  c141_y[2] = c141_u[2];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 7);
  c141_y[3] = c141_u[3];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 8);
  c141_y[4] = c141_u[4];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 9);
  c141_y[5] = c141_u[5];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 10);
  c141_y[6] = c141_u[6];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, 11);
  c141_y[7] = c141_u[7];
  _SFD_EML_CALL(0U, chartInstance->c141_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c141_i5 = 0; c141_i5 < 8; c141_i5++) {
    (*c141_b_y)[c141_i5] = c141_y[c141_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c141_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c141_i6 = 0; c141_i6 < 8; c141_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c141_b_y)[c141_i6], 1U);
  }
}

static void initSimStructsc141_ICARO3_Onda_bipe_controllonostro40cm
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c141_machineNumber, uint32_T
  c141_chartNumber, uint32_T c141_instanceNumber)
{
  (void)c141_machineNumber;
  (void)c141_chartNumber;
  (void)c141_instanceNumber;
}

static const mxArray *c141_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData)
{
  const mxArray *c141_mxArrayOutData = NULL;
  int32_T c141_i7;
  uint8_T c141_b_inData[8];
  int32_T c141_i8;
  uint8_T c141_u[8];
  const mxArray *c141_y = NULL;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_mxArrayOutData = NULL;
  for (c141_i7 = 0; c141_i7 < 8; c141_i7++) {
    c141_b_inData[c141_i7] = (*(uint8_T (*)[8])c141_inData)[c141_i7];
  }

  for (c141_i8 = 0; c141_i8 < 8; c141_i8++) {
    c141_u[c141_i8] = c141_b_inData[c141_i8];
  }

  c141_y = NULL;
  sf_mex_assign(&c141_y, sf_mex_create("y", c141_u, 3, 0U, 1U, 0U, 2, 1, 8),
                false);
  sf_mex_assign(&c141_mxArrayOutData, c141_y, false);
  return c141_mxArrayOutData;
}

static void c141_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_y, const char_T *c141_identifier, uint8_T c141_b_y[8])
{
  emlrtMsgIdentifier c141_thisId;
  c141_thisId.fIdentifier = c141_identifier;
  c141_thisId.fParent = NULL;
  c141_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c141_y), &c141_thisId,
    c141_b_y);
  sf_mex_destroy(&c141_y);
}

static void c141_b_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId, uint8_T
   c141_y[8])
{
  uint8_T c141_uv1[8];
  int32_T c141_i9;
  (void)chartInstance;
  sf_mex_import(c141_parentId, sf_mex_dup(c141_u), c141_uv1, 1, 3, 0U, 1, 0U, 2,
                1, 8);
  for (c141_i9 = 0; c141_i9 < 8; c141_i9++) {
    c141_y[c141_i9] = c141_uv1[c141_i9];
  }

  sf_mex_destroy(&c141_u);
}

static void c141_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData)
{
  const mxArray *c141_y;
  const char_T *c141_identifier;
  emlrtMsgIdentifier c141_thisId;
  uint8_T c141_b_y[8];
  int32_T c141_i10;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_y = sf_mex_dup(c141_mxArrayInData);
  c141_identifier = c141_varName;
  c141_thisId.fIdentifier = c141_identifier;
  c141_thisId.fParent = NULL;
  c141_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c141_y), &c141_thisId,
    c141_b_y);
  sf_mex_destroy(&c141_y);
  for (c141_i10 = 0; c141_i10 < 8; c141_i10++) {
    (*(uint8_T (*)[8])c141_outData)[c141_i10] = c141_b_y[c141_i10];
  }

  sf_mex_destroy(&c141_mxArrayInData);
}

static const mxArray *c141_b_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData)
{
  const mxArray *c141_mxArrayOutData = NULL;
  int32_T c141_i11;
  uint8_T c141_b_inData[8];
  int32_T c141_i12;
  uint8_T c141_u[8];
  const mxArray *c141_y = NULL;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_mxArrayOutData = NULL;
  for (c141_i11 = 0; c141_i11 < 8; c141_i11++) {
    c141_b_inData[c141_i11] = (*(uint8_T (*)[8])c141_inData)[c141_i11];
  }

  for (c141_i12 = 0; c141_i12 < 8; c141_i12++) {
    c141_u[c141_i12] = c141_b_inData[c141_i12];
  }

  c141_y = NULL;
  sf_mex_assign(&c141_y, sf_mex_create("y", c141_u, 3, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c141_mxArrayOutData, c141_y, false);
  return c141_mxArrayOutData;
}

static const mxArray *c141_c_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData)
{
  const mxArray *c141_mxArrayOutData = NULL;
  real_T c141_u;
  const mxArray *c141_y = NULL;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_mxArrayOutData = NULL;
  c141_u = *(real_T *)c141_inData;
  c141_y = NULL;
  sf_mex_assign(&c141_y, sf_mex_create("y", &c141_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c141_mxArrayOutData, c141_y, false);
  return c141_mxArrayOutData;
}

static real_T c141_c_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId)
{
  real_T c141_y;
  real_T c141_d0;
  (void)chartInstance;
  sf_mex_import(c141_parentId, sf_mex_dup(c141_u), &c141_d0, 1, 0, 0U, 0, 0U, 0);
  c141_y = c141_d0;
  sf_mex_destroy(&c141_u);
  return c141_y;
}

static void c141_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData)
{
  const mxArray *c141_nargout;
  const char_T *c141_identifier;
  emlrtMsgIdentifier c141_thisId;
  real_T c141_y;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_nargout = sf_mex_dup(c141_mxArrayInData);
  c141_identifier = c141_varName;
  c141_thisId.fIdentifier = c141_identifier;
  c141_thisId.fParent = NULL;
  c141_y = c141_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c141_nargout),
    &c141_thisId);
  sf_mex_destroy(&c141_nargout);
  *(real_T *)c141_outData = c141_y;
  sf_mex_destroy(&c141_mxArrayInData);
}

const mxArray
  *sf_c141_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c141_nameCaptureInfo = NULL;
  c141_nameCaptureInfo = NULL;
  sf_mex_assign(&c141_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c141_nameCaptureInfo;
}

static const mxArray *c141_d_sf_marshallOut(void *chartInstanceVoid, void
  *c141_inData)
{
  const mxArray *c141_mxArrayOutData = NULL;
  int32_T c141_u;
  const mxArray *c141_y = NULL;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_mxArrayOutData = NULL;
  c141_u = *(int32_T *)c141_inData;
  c141_y = NULL;
  sf_mex_assign(&c141_y, sf_mex_create("y", &c141_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c141_mxArrayOutData, c141_y, false);
  return c141_mxArrayOutData;
}

static int32_T c141_d_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId)
{
  int32_T c141_y;
  int32_T c141_i13;
  (void)chartInstance;
  sf_mex_import(c141_parentId, sf_mex_dup(c141_u), &c141_i13, 1, 6, 0U, 0, 0U, 0);
  c141_y = c141_i13;
  sf_mex_destroy(&c141_u);
  return c141_y;
}

static void c141_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c141_mxArrayInData, const char_T *c141_varName, void *c141_outData)
{
  const mxArray *c141_b_sfEvent;
  const char_T *c141_identifier;
  emlrtMsgIdentifier c141_thisId;
  int32_T c141_y;
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c141_b_sfEvent = sf_mex_dup(c141_mxArrayInData);
  c141_identifier = c141_varName;
  c141_thisId.fIdentifier = c141_identifier;
  c141_thisId.fParent = NULL;
  c141_y = c141_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c141_b_sfEvent),
    &c141_thisId);
  sf_mex_destroy(&c141_b_sfEvent);
  *(int32_T *)c141_outData = c141_y;
  sf_mex_destroy(&c141_mxArrayInData);
}

static uint8_T c141_e_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_b_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c141_identifier)
{
  uint8_T c141_y;
  emlrtMsgIdentifier c141_thisId;
  c141_thisId.fIdentifier = c141_identifier;
  c141_thisId.fParent = NULL;
  c141_y = c141_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c141_b_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm), &c141_thisId);
  sf_mex_destroy(&c141_b_is_active_c141_ICARO3_Onda_bipe_controllonostro40cm);
  return c141_y;
}

static uint8_T c141_f_emlrt_marshallIn
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c141_u, const emlrtMsgIdentifier *c141_parentId)
{
  uint8_T c141_y;
  uint8_T c141_u0;
  (void)chartInstance;
  sf_mex_import(c141_parentId, sf_mex_dup(c141_u), &c141_u0, 1, 3, 0U, 0, 0U, 0);
  c141_y = c141_u0;
  sf_mex_destroy(&c141_u);
  return c141_y;
}

static void init_dsm_address_info
  (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
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

void sf_c141_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2837198802U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3478148634U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3421058923U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2870579574U);
}

mxArray *sf_c141_ICARO3_Onda_bipe_controllonostro40cm_get_autoinheritance_info
  (void)
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

mxArray *sf_c141_ICARO3_Onda_bipe_controllonostro40cm_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c141_ICARO3_Onda_bipe_controllonostro40cm_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c141_ICARO3_Onda_bipe_controllonostro40cm(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c141_ICARO3_Onda_bipe_controllonostro40cm\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c141_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           141,
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
          (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c141_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c141_sf_marshallOut,(MexInFcnForType)
            c141_sf_marshallIn);
        }

        {
          uint8_T (*c141_u)[8];
          uint8_T (*c141_y)[8];
          c141_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          c141_u = (uint8_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c141_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c141_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "gqXZOAzeuxEazoJ7TcegDC";
}

static void sf_opaque_initialize_c141_ICARO3_Onda_bipe_controllonostro40cm(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
  initialize_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c141_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  enable_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c141_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  disable_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c141_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  sf_gateway_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c141_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
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

extern void sf_internal_set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
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
    sf_get_sim_state_info_c141_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm(SimStruct* S)
{
  return sf_internal_get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm(S);
}

static void sf_opaque_set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm(S, st);
}

static void sf_opaque_terminate_c141_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    }

    finalize_c141_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
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
  initSimStructsc141_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c141_ICARO3_Onda_bipe_controllonostro40cm
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
    initialize_params_c141_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c141_ICARO3_Onda_bipe_controllonostro40cm(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      141);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,141,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,141,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,141);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,141,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,141,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,141);
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

static void mdlRTW_c141_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c141_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    utMalloc(sizeof(SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc141_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c141_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c141_ICARO3_Onda_bipe_controllonostro40cm;
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

void c141_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c141_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c141_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c141_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c141_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
