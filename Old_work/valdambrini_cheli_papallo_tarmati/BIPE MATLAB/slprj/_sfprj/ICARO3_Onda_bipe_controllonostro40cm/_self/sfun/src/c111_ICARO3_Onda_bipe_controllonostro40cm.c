/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun.h"
#include "c111_ICARO3_Onda_bipe_controllonostro40cm.h"
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
static const char * c111_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initialize_params_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void enable_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void disable_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c111_update_debugger_state_c111_ICARO3_Onda_bipe_controllonostro
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_st);
static void finalize_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void sf_gateway_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c111_chartstep_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initSimStructsc111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c111_machineNumber, uint32_T
  c111_chartNumber, uint32_T c111_instanceNumber);
static const mxArray *c111_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData);
static uint32_T c111_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_y, const char_T *c111_identifier);
static uint32_T c111_b_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId);
static void c111_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData);
static const mxArray *c111_b_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData);
static const mxArray *c111_c_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData);
static real_T c111_c_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId);
static void c111_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData);
static void c111_info_helper(const mxArray **c111_info);
static const mxArray *c111_emlrt_marshallOut(const char * c111_u);
static const mxArray *c111_b_emlrt_marshallOut(const uint32_T c111_u);
static const mxArray *c111_d_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData);
static int32_T c111_d_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId);
static void c111_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData);
static uint8_T c111_e_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_b_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c111_identifier);
static uint8_T c111_f_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId);
static void init_dsm_address_info
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  chartInstance->c111_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c111_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm = 0U;
}

static void initialize_params_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c111_update_debugger_state_c111_ICARO3_Onda_bipe_controllonostro
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  const mxArray *c111_st;
  const mxArray *c111_y = NULL;
  uint32_T c111_hoistedGlobal;
  uint32_T c111_u;
  const mxArray *c111_b_y = NULL;
  uint8_T c111_b_hoistedGlobal;
  uint8_T c111_b_u;
  const mxArray *c111_c_y = NULL;
  uint32_T *c111_d_y;
  c111_d_y = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c111_st = NULL;
  c111_st = NULL;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_createcellmatrix(2, 1), false);
  c111_hoistedGlobal = *c111_d_y;
  c111_u = c111_hoistedGlobal;
  c111_b_y = NULL;
  sf_mex_assign(&c111_b_y, sf_mex_create("y", &c111_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c111_y, 0, c111_b_y);
  c111_b_hoistedGlobal =
    chartInstance->c111_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm;
  c111_b_u = c111_b_hoistedGlobal;
  c111_c_y = NULL;
  sf_mex_assign(&c111_c_y, sf_mex_create("y", &c111_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c111_y, 1, c111_c_y);
  sf_mex_assign(&c111_st, c111_y, false);
  return c111_st;
}

static void set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_st)
{
  const mxArray *c111_u;
  uint32_T *c111_y;
  c111_y = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c111_doneDoubleBufferReInit = true;
  c111_u = sf_mex_dup(c111_st);
  *c111_y = c111_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c111_u, 0)), "y");
  chartInstance->c111_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm =
    c111_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c111_u, 1)),
    "is_active_c111_ICARO3_Onda_bipe_controllonostro40cm");
  sf_mex_destroy(&c111_u);
  c111_update_debugger_state_c111_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c111_st);
}

static void finalize_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  int32_T c111_i0;
  uint32_T *c111_y;
  uint32_T (*c111_u)[4];
  c111_y = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c111_u = (uint32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c111_sfEvent);
  for (c111_i0 = 0; c111_i0 < 4; c111_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c111_u)[c111_i0], 0U);
  }

  chartInstance->c111_sfEvent = CALL_EVENT;
  c111_chartstep_c111_ICARO3_Onda_bipe_controllonostro40cm(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c111_y, 1U);
}

static void c111_chartstep_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  int32_T c111_i1;
  uint32_T c111_u[4];
  uint32_T c111_debug_family_var_map[4];
  real_T c111_nargin = 1.0;
  real_T c111_nargout = 1.0;
  uint32_T c111_y;
  uint32_T c111_a;
  uint32_T c111_a1;
  uint32_T c111_b_a;
  uint32_T c111_c;
  uint32_T c111_c_a;
  uint32_T c111_b_a1;
  uint32_T c111_d_a;
  uint32_T c111_b_c;
  uint32_T c111_e_a;
  uint32_T c111_c_a1;
  uint32_T c111_f_a;
  uint32_T c111_c_c;
  uint64_T c111_u0;
  uint64_T c111_u1;
  uint64_T c111_u2;
  uint32_T *c111_b_y;
  uint32_T (*c111_b_u)[4];
  c111_b_y = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c111_b_u = (uint32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c111_sfEvent);
  for (c111_i1 = 0; c111_i1 < 4; c111_i1++) {
    c111_u[c111_i1] = (*c111_b_u)[c111_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c111_debug_family_names,
    c111_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c111_nargin, 0U, c111_c_sf_marshallOut,
    c111_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c111_nargout, 1U, c111_c_sf_marshallOut,
    c111_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c111_u, 2U, c111_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c111_y, 3U, c111_sf_marshallOut,
    c111_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c111_sfEvent, 3);
  c111_a = c111_u[3];
  c111_a1 = c111_a;
  c111_b_a = c111_a1;
  c111_c = c111_b_a << 24U;
  c111_c_a = c111_u[2];
  c111_b_a1 = c111_c_a;
  c111_d_a = c111_b_a1;
  c111_b_c = c111_d_a << 16U;
  c111_e_a = c111_u[1];
  c111_c_a1 = c111_e_a;
  c111_f_a = c111_c_a1;
  c111_c_c = c111_f_a << 8U;
  c111_u0 = (uint64_T)c111_c + (uint64_T)c111_b_c;
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c111_u0 > 4294967295ULL)) {
    c111_u0 = 4294967295ULL;
  }

  c111_u1 = (uint64_T)(uint32_T)c111_u0 + (uint64_T)c111_c_c;
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c111_u1 > 4294967295ULL)) {
    c111_u1 = 4294967295ULL;
  }

  c111_u2 = (uint64_T)(uint32_T)c111_u1 + (uint64_T)c111_u[0];
  if (CV_SATURATION_EVAL(4, 0, 2, 0, c111_u2 > 4294967295ULL)) {
    c111_u2 = 4294967295ULL;
  }

  c111_y = (uint32_T)c111_u2;
  _SFD_EML_CALL(0U, chartInstance->c111_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  *c111_b_y = c111_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c111_sfEvent);
}

static void initSimStructsc111_ICARO3_Onda_bipe_controllonostro40cm
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c111_machineNumber, uint32_T
  c111_chartNumber, uint32_T c111_instanceNumber)
{
  (void)c111_machineNumber;
  (void)c111_chartNumber;
  (void)c111_instanceNumber;
}

static const mxArray *c111_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData)
{
  const mxArray *c111_mxArrayOutData = NULL;
  uint32_T c111_u;
  const mxArray *c111_y = NULL;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_mxArrayOutData = NULL;
  c111_u = *(uint32_T *)c111_inData;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", &c111_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c111_mxArrayOutData, c111_y, false);
  return c111_mxArrayOutData;
}

static uint32_T c111_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_y, const char_T *c111_identifier)
{
  uint32_T c111_b_y;
  emlrtMsgIdentifier c111_thisId;
  c111_thisId.fIdentifier = c111_identifier;
  c111_thisId.fParent = NULL;
  c111_b_y = c111_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c111_y),
    &c111_thisId);
  sf_mex_destroy(&c111_y);
  return c111_b_y;
}

static uint32_T c111_b_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId)
{
  uint32_T c111_y;
  uint32_T c111_u3;
  (void)chartInstance;
  sf_mex_import(c111_parentId, sf_mex_dup(c111_u), &c111_u3, 1, 7, 0U, 0, 0U, 0);
  c111_y = c111_u3;
  sf_mex_destroy(&c111_u);
  return c111_y;
}

static void c111_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData)
{
  const mxArray *c111_y;
  const char_T *c111_identifier;
  emlrtMsgIdentifier c111_thisId;
  uint32_T c111_b_y;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_y = sf_mex_dup(c111_mxArrayInData);
  c111_identifier = c111_varName;
  c111_thisId.fIdentifier = c111_identifier;
  c111_thisId.fParent = NULL;
  c111_b_y = c111_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c111_y),
    &c111_thisId);
  sf_mex_destroy(&c111_y);
  *(uint32_T *)c111_outData = c111_b_y;
  sf_mex_destroy(&c111_mxArrayInData);
}

static const mxArray *c111_b_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData)
{
  const mxArray *c111_mxArrayOutData = NULL;
  int32_T c111_i2;
  uint32_T c111_b_inData[4];
  int32_T c111_i3;
  uint32_T c111_u[4];
  const mxArray *c111_y = NULL;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_mxArrayOutData = NULL;
  for (c111_i2 = 0; c111_i2 < 4; c111_i2++) {
    c111_b_inData[c111_i2] = (*(uint32_T (*)[4])c111_inData)[c111_i2];
  }

  for (c111_i3 = 0; c111_i3 < 4; c111_i3++) {
    c111_u[c111_i3] = c111_b_inData[c111_i3];
  }

  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", c111_u, 7, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c111_mxArrayOutData, c111_y, false);
  return c111_mxArrayOutData;
}

static const mxArray *c111_c_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData)
{
  const mxArray *c111_mxArrayOutData = NULL;
  real_T c111_u;
  const mxArray *c111_y = NULL;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_mxArrayOutData = NULL;
  c111_u = *(real_T *)c111_inData;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", &c111_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c111_mxArrayOutData, c111_y, false);
  return c111_mxArrayOutData;
}

static real_T c111_c_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId)
{
  real_T c111_y;
  real_T c111_d0;
  (void)chartInstance;
  sf_mex_import(c111_parentId, sf_mex_dup(c111_u), &c111_d0, 1, 0, 0U, 0, 0U, 0);
  c111_y = c111_d0;
  sf_mex_destroy(&c111_u);
  return c111_y;
}

static void c111_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData)
{
  const mxArray *c111_nargout;
  const char_T *c111_identifier;
  emlrtMsgIdentifier c111_thisId;
  real_T c111_y;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_nargout = sf_mex_dup(c111_mxArrayInData);
  c111_identifier = c111_varName;
  c111_thisId.fIdentifier = c111_identifier;
  c111_thisId.fParent = NULL;
  c111_y = c111_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c111_nargout),
    &c111_thisId);
  sf_mex_destroy(&c111_nargout);
  *(real_T *)c111_outData = c111_y;
  sf_mex_destroy(&c111_mxArrayInData);
}

const mxArray
  *sf_c111_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c111_nameCaptureInfo = NULL;
  c111_nameCaptureInfo = NULL;
  sf_mex_assign(&c111_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c111_info_helper(&c111_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c111_nameCaptureInfo);
  return c111_nameCaptureInfo;
}

static void c111_info_helper(const mxArray **c111_info)
{
  const mxArray *c111_rhs0 = NULL;
  const mxArray *c111_lhs0 = NULL;
  const mxArray *c111_rhs1 = NULL;
  const mxArray *c111_lhs1 = NULL;
  const mxArray *c111_rhs2 = NULL;
  const mxArray *c111_lhs2 = NULL;
  const mxArray *c111_rhs3 = NULL;
  const mxArray *c111_lhs3 = NULL;
  const mxArray *c111_rhs4 = NULL;
  const mxArray *c111_lhs4 = NULL;
  const mxArray *c111_rhs5 = NULL;
  const mxArray *c111_lhs5 = NULL;
  const mxArray *c111_rhs6 = NULL;
  const mxArray *c111_lhs6 = NULL;
  const mxArray *c111_rhs7 = NULL;
  const mxArray *c111_lhs7 = NULL;
  const mxArray *c111_rhs8 = NULL;
  const mxArray *c111_lhs8 = NULL;
  const mxArray *c111_rhs9 = NULL;
  const mxArray *c111_lhs9 = NULL;
  const mxArray *c111_rhs10 = NULL;
  const mxArray *c111_lhs10 = NULL;
  const mxArray *c111_rhs11 = NULL;
  const mxArray *c111_lhs11 = NULL;
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("bitshift"), "name", "name",
                  0);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1383877292U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c111_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c111_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 2);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1286818782U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c111_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c111_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c111_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_scalexp_alloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c111_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "coder.internal.scalexpAlloc"), "name", "name", 6);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c111_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 7);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1363713854U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c111_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c111_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1286818726U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c111_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 10);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 10);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c111_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 11);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c111_info, c111_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c111_info, c111_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c111_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c111_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c111_info, sf_mex_duplicatearraysafe(&c111_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_destroy(&c111_rhs0);
  sf_mex_destroy(&c111_lhs0);
  sf_mex_destroy(&c111_rhs1);
  sf_mex_destroy(&c111_lhs1);
  sf_mex_destroy(&c111_rhs2);
  sf_mex_destroy(&c111_lhs2);
  sf_mex_destroy(&c111_rhs3);
  sf_mex_destroy(&c111_lhs3);
  sf_mex_destroy(&c111_rhs4);
  sf_mex_destroy(&c111_lhs4);
  sf_mex_destroy(&c111_rhs5);
  sf_mex_destroy(&c111_lhs5);
  sf_mex_destroy(&c111_rhs6);
  sf_mex_destroy(&c111_lhs6);
  sf_mex_destroy(&c111_rhs7);
  sf_mex_destroy(&c111_lhs7);
  sf_mex_destroy(&c111_rhs8);
  sf_mex_destroy(&c111_lhs8);
  sf_mex_destroy(&c111_rhs9);
  sf_mex_destroy(&c111_lhs9);
  sf_mex_destroy(&c111_rhs10);
  sf_mex_destroy(&c111_lhs10);
  sf_mex_destroy(&c111_rhs11);
  sf_mex_destroy(&c111_lhs11);
}

static const mxArray *c111_emlrt_marshallOut(const char * c111_u)
{
  const mxArray *c111_y = NULL;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", c111_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c111_u)), false);
  return c111_y;
}

static const mxArray *c111_b_emlrt_marshallOut(const uint32_T c111_u)
{
  const mxArray *c111_y = NULL;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", &c111_u, 7, 0U, 0U, 0U, 0), false);
  return c111_y;
}

static const mxArray *c111_d_sf_marshallOut(void *chartInstanceVoid, void
  *c111_inData)
{
  const mxArray *c111_mxArrayOutData = NULL;
  int32_T c111_u;
  const mxArray *c111_y = NULL;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_mxArrayOutData = NULL;
  c111_u = *(int32_T *)c111_inData;
  c111_y = NULL;
  sf_mex_assign(&c111_y, sf_mex_create("y", &c111_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c111_mxArrayOutData, c111_y, false);
  return c111_mxArrayOutData;
}

static int32_T c111_d_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId)
{
  int32_T c111_y;
  int32_T c111_i4;
  (void)chartInstance;
  sf_mex_import(c111_parentId, sf_mex_dup(c111_u), &c111_i4, 1, 6, 0U, 0, 0U, 0);
  c111_y = c111_i4;
  sf_mex_destroy(&c111_u);
  return c111_y;
}

static void c111_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c111_mxArrayInData, const char_T *c111_varName, void *c111_outData)
{
  const mxArray *c111_b_sfEvent;
  const char_T *c111_identifier;
  emlrtMsgIdentifier c111_thisId;
  int32_T c111_y;
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c111_b_sfEvent = sf_mex_dup(c111_mxArrayInData);
  c111_identifier = c111_varName;
  c111_thisId.fIdentifier = c111_identifier;
  c111_thisId.fParent = NULL;
  c111_y = c111_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c111_b_sfEvent),
    &c111_thisId);
  sf_mex_destroy(&c111_b_sfEvent);
  *(int32_T *)c111_outData = c111_y;
  sf_mex_destroy(&c111_mxArrayInData);
}

static uint8_T c111_e_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_b_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c111_identifier)
{
  uint8_T c111_y;
  emlrtMsgIdentifier c111_thisId;
  c111_thisId.fIdentifier = c111_identifier;
  c111_thisId.fParent = NULL;
  c111_y = c111_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c111_b_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm), &c111_thisId);
  sf_mex_destroy(&c111_b_is_active_c111_ICARO3_Onda_bipe_controllonostro40cm);
  return c111_y;
}

static uint8_T c111_f_emlrt_marshallIn
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c111_u, const emlrtMsgIdentifier *c111_parentId)
{
  uint8_T c111_y;
  uint8_T c111_u4;
  (void)chartInstance;
  sf_mex_import(c111_parentId, sf_mex_dup(c111_u), &c111_u4, 1, 3, 0U, 0, 0U, 0);
  c111_y = c111_u4;
  sf_mex_destroy(&c111_u);
  return c111_y;
}

static void init_dsm_address_info
  (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
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

void sf_c111_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4172939698U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3348487269U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(220513826U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2697336904U);
}

mxArray *sf_c111_ICARO3_Onda_bipe_controllonostro40cm_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0dnJ8Y284mVkSbhLfNZA9B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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

mxArray *sf_c111_ICARO3_Onda_bipe_controllonostro40cm_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c111_ICARO3_Onda_bipe_controllonostro40cm_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c111_ICARO3_Onda_bipe_controllonostro40cm(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c111_ICARO3_Onda_bipe_controllonostro40cm\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c111_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           111,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,101);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,35,-1,74);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,35,-1,93);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,35,-1,98);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c111_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c111_sf_marshallOut,(MexInFcnForType)c111_sf_marshallIn);

        {
          uint32_T *c111_y;
          uint32_T (*c111_u)[4];
          c111_y = (uint32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c111_u = (uint32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c111_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c111_y);
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
  return "VS1eVFj5oLHYCVJmmkYpEG";
}

static void sf_opaque_initialize_c111_ICARO3_Onda_bipe_controllonostro40cm(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
  initialize_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c111_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  enable_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c111_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  disable_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c111_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  sf_gateway_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c111_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
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

extern void sf_internal_set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
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
    sf_get_sim_state_info_c111_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm(SimStruct* S)
{
  return sf_internal_get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm(S);
}

static void sf_opaque_set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm(S, st);
}

static void sf_opaque_terminate_c111_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    }

    finalize_c111_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
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
  initSimStructsc111_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c111_ICARO3_Onda_bipe_controllonostro40cm
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
    initialize_params_c111_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c111_ICARO3_Onda_bipe_controllonostro40cm(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      111);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,111,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,111,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,111);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,111,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,111,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,111);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(119299375U));
  ssSetChecksum1(S,(2378571573U));
  ssSetChecksum2(S,(678727818U));
  ssSetChecksum3(S,(140981906U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c111_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c111_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    utMalloc(sizeof(SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc111_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c111_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c111_ICARO3_Onda_bipe_controllonostro40cm;
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

void c111_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c111_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c111_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c111_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c111_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
