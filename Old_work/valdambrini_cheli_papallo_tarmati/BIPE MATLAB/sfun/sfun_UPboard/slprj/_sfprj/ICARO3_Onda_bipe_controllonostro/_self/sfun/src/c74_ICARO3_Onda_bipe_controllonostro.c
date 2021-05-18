/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_sfun.h"
#include "c74_ICARO3_Onda_bipe_controllonostro.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_controllonostro_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c74_debug_family_names[4] = { "nargin", "nargout", "u",
  "theta" };

/* Function Declarations */
static void initialize_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initialize_params_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void enable_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void disable_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void c74_update_debugger_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void set_sim_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_st);
static void finalize_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void sf_gateway_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initSimStructsc74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c74_machineNumber, uint32_T
  c74_chartNumber, uint32_T c74_instanceNumber);
static const mxArray *c74_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData);
static real_T c74_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_theta, const char_T *c74_identifier);
static real_T c74_b_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId);
static void c74_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c74_mxArrayInData, const char_T *c74_varName, void *c74_outData);
static const mxArray *c74_b_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData);
static void c74_info_helper(const mxArray **c74_info);
static const mxArray *c74_emlrt_marshallOut(const char * c74_u);
static const mxArray *c74_b_emlrt_marshallOut(const uint32_T c74_u);
static const mxArray *c74_c_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData);
static int32_T c74_c_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId);
static void c74_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c74_mxArrayInData, const char_T *c74_varName, void *c74_outData);
static uint8_T c74_d_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_b_is_active_c74_ICARO3_Onda_bipe_controllonostro, const char_T
   *c74_identifier);
static uint8_T c74_e_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId);
static void init_dsm_address_info
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  chartInstance->c74_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c74_is_active_c74_ICARO3_Onda_bipe_controllonostro = 0U;
}

static void initialize_params_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c74_update_debugger_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  const mxArray *c74_st;
  const mxArray *c74_y = NULL;
  real_T c74_hoistedGlobal;
  real_T c74_u;
  const mxArray *c74_b_y = NULL;
  uint8_T c74_b_hoistedGlobal;
  uint8_T c74_b_u;
  const mxArray *c74_c_y = NULL;
  real_T *c74_theta;
  c74_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c74_st = NULL;
  c74_st = NULL;
  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_createcellmatrix(2, 1), false);
  c74_hoistedGlobal = *c74_theta;
  c74_u = c74_hoistedGlobal;
  c74_b_y = NULL;
  sf_mex_assign(&c74_b_y, sf_mex_create("y", &c74_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c74_y, 0, c74_b_y);
  c74_b_hoistedGlobal =
    chartInstance->c74_is_active_c74_ICARO3_Onda_bipe_controllonostro;
  c74_b_u = c74_b_hoistedGlobal;
  c74_c_y = NULL;
  sf_mex_assign(&c74_c_y, sf_mex_create("y", &c74_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c74_y, 1, c74_c_y);
  sf_mex_assign(&c74_st, c74_y, false);
  return c74_st;
}

static void set_sim_state_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_st)
{
  const mxArray *c74_u;
  real_T *c74_theta;
  c74_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c74_doneDoubleBufferReInit = true;
  c74_u = sf_mex_dup(c74_st);
  *c74_theta = c74_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c74_u, 0)), "theta");
  chartInstance->c74_is_active_c74_ICARO3_Onda_bipe_controllonostro =
    c74_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c74_u, 1)),
    "is_active_c74_ICARO3_Onda_bipe_controllonostro");
  sf_mex_destroy(&c74_u);
  c74_update_debugger_state_c74_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c74_st);
}

static void finalize_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  int32_T c74_i0;
  int32_T c74_i1;
  real_T c74_u[2];
  uint32_T c74_debug_family_var_map[4];
  real_T c74_nargin = 1.0;
  real_T c74_nargout = 1.0;
  real_T c74_theta;
  real_T c74_y;
  real_T c74_x;
  real_T c74_b_y;
  real_T c74_b_x;
  real_T *c74_b_theta;
  real_T (*c74_b_u)[2];
  c74_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c74_b_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c74_sfEvent);
  for (c74_i0 = 0; c74_i0 < 2; c74_i0++) {
    _SFD_DATA_RANGE_CHECK((*c74_b_u)[c74_i0], 0U);
  }

  chartInstance->c74_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c74_sfEvent);
  for (c74_i1 = 0; c74_i1 < 2; c74_i1++) {
    c74_u[c74_i1] = (*c74_b_u)[c74_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c74_debug_family_names,
    c74_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c74_nargin, 0U, c74_sf_marshallOut,
    c74_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c74_nargout, 1U, c74_sf_marshallOut,
    c74_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c74_u, 2U, c74_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c74_theta, 3U, c74_sf_marshallOut,
    c74_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c74_sfEvent, 10);
  c74_y = c74_u[1];
  c74_x = c74_u[0];
  c74_b_y = c74_y;
  c74_b_x = c74_x;
  c74_theta = muDoubleScalarAtan2(c74_b_y, c74_b_x);
  _SFD_EML_CALL(0U, chartInstance->c74_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  *c74_b_theta = c74_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c74_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostroMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c74_b_theta, 1U);
}

static void initSimStructsc74_ICARO3_Onda_bipe_controllonostro
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c74_machineNumber, uint32_T
  c74_chartNumber, uint32_T c74_instanceNumber)
{
  (void)c74_machineNumber;
  (void)c74_chartNumber;
  (void)c74_instanceNumber;
}

static const mxArray *c74_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData)
{
  const mxArray *c74_mxArrayOutData = NULL;
  real_T c74_u;
  const mxArray *c74_y = NULL;
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c74_mxArrayOutData = NULL;
  c74_u = *(real_T *)c74_inData;
  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_create("y", &c74_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c74_mxArrayOutData, c74_y, false);
  return c74_mxArrayOutData;
}

static real_T c74_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_theta, const char_T *c74_identifier)
{
  real_T c74_y;
  emlrtMsgIdentifier c74_thisId;
  c74_thisId.fIdentifier = c74_identifier;
  c74_thisId.fParent = NULL;
  c74_y = c74_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c74_theta),
    &c74_thisId);
  sf_mex_destroy(&c74_theta);
  return c74_y;
}

static real_T c74_b_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId)
{
  real_T c74_y;
  real_T c74_d0;
  (void)chartInstance;
  sf_mex_import(c74_parentId, sf_mex_dup(c74_u), &c74_d0, 1, 0, 0U, 0, 0U, 0);
  c74_y = c74_d0;
  sf_mex_destroy(&c74_u);
  return c74_y;
}

static void c74_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c74_mxArrayInData, const char_T *c74_varName, void *c74_outData)
{
  const mxArray *c74_theta;
  const char_T *c74_identifier;
  emlrtMsgIdentifier c74_thisId;
  real_T c74_y;
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c74_theta = sf_mex_dup(c74_mxArrayInData);
  c74_identifier = c74_varName;
  c74_thisId.fIdentifier = c74_identifier;
  c74_thisId.fParent = NULL;
  c74_y = c74_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c74_theta),
    &c74_thisId);
  sf_mex_destroy(&c74_theta);
  *(real_T *)c74_outData = c74_y;
  sf_mex_destroy(&c74_mxArrayInData);
}

static const mxArray *c74_b_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData)
{
  const mxArray *c74_mxArrayOutData = NULL;
  int32_T c74_i2;
  real_T c74_b_inData[2];
  int32_T c74_i3;
  real_T c74_u[2];
  const mxArray *c74_y = NULL;
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c74_mxArrayOutData = NULL;
  for (c74_i2 = 0; c74_i2 < 2; c74_i2++) {
    c74_b_inData[c74_i2] = (*(real_T (*)[2])c74_inData)[c74_i2];
  }

  for (c74_i3 = 0; c74_i3 < 2; c74_i3++) {
    c74_u[c74_i3] = c74_b_inData[c74_i3];
  }

  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_create("y", c74_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c74_mxArrayOutData, c74_y, false);
  return c74_mxArrayOutData;
}

const mxArray
  *sf_c74_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void)
{
  const mxArray *c74_nameCaptureInfo = NULL;
  c74_nameCaptureInfo = NULL;
  sf_mex_assign(&c74_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
                false);
  c74_info_helper(&c74_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c74_nameCaptureInfo);
  return c74_nameCaptureInfo;
}

static void c74_info_helper(const mxArray **c74_info)
{
  const mxArray *c74_rhs0 = NULL;
  const mxArray *c74_lhs0 = NULL;
  const mxArray *c74_rhs1 = NULL;
  const mxArray *c74_lhs1 = NULL;
  const mxArray *c74_rhs2 = NULL;
  const mxArray *c74_lhs2 = NULL;
  const mxArray *c74_rhs3 = NULL;
  const mxArray *c74_lhs3 = NULL;
  const mxArray *c74_rhs4 = NULL;
  const mxArray *c74_lhs4 = NULL;
  const mxArray *c74_rhs5 = NULL;
  const mxArray *c74_lhs5 = NULL;
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("atan2"), "name", "name", 0);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c74_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 1);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c74_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 2);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c74_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c74_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 4);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c74_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 5);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c74_info, c74_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c74_info, c74_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c74_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c74_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c74_info, sf_mex_duplicatearraysafe(&c74_lhs5), "lhs", "lhs",
                  5);
  sf_mex_destroy(&c74_rhs0);
  sf_mex_destroy(&c74_lhs0);
  sf_mex_destroy(&c74_rhs1);
  sf_mex_destroy(&c74_lhs1);
  sf_mex_destroy(&c74_rhs2);
  sf_mex_destroy(&c74_lhs2);
  sf_mex_destroy(&c74_rhs3);
  sf_mex_destroy(&c74_lhs3);
  sf_mex_destroy(&c74_rhs4);
  sf_mex_destroy(&c74_lhs4);
  sf_mex_destroy(&c74_rhs5);
  sf_mex_destroy(&c74_lhs5);
}

static const mxArray *c74_emlrt_marshallOut(const char * c74_u)
{
  const mxArray *c74_y = NULL;
  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_create("y", c74_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c74_u)), false);
  return c74_y;
}

static const mxArray *c74_b_emlrt_marshallOut(const uint32_T c74_u)
{
  const mxArray *c74_y = NULL;
  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_create("y", &c74_u, 7, 0U, 0U, 0U, 0), false);
  return c74_y;
}

static const mxArray *c74_c_sf_marshallOut(void *chartInstanceVoid, void
  *c74_inData)
{
  const mxArray *c74_mxArrayOutData = NULL;
  int32_T c74_u;
  const mxArray *c74_y = NULL;
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c74_mxArrayOutData = NULL;
  c74_u = *(int32_T *)c74_inData;
  c74_y = NULL;
  sf_mex_assign(&c74_y, sf_mex_create("y", &c74_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c74_mxArrayOutData, c74_y, false);
  return c74_mxArrayOutData;
}

static int32_T c74_c_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId)
{
  int32_T c74_y;
  int32_T c74_i4;
  (void)chartInstance;
  sf_mex_import(c74_parentId, sf_mex_dup(c74_u), &c74_i4, 1, 6, 0U, 0, 0U, 0);
  c74_y = c74_i4;
  sf_mex_destroy(&c74_u);
  return c74_y;
}

static void c74_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c74_mxArrayInData, const char_T *c74_varName, void *c74_outData)
{
  const mxArray *c74_b_sfEvent;
  const char_T *c74_identifier;
  emlrtMsgIdentifier c74_thisId;
  int32_T c74_y;
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c74_b_sfEvent = sf_mex_dup(c74_mxArrayInData);
  c74_identifier = c74_varName;
  c74_thisId.fIdentifier = c74_identifier;
  c74_thisId.fParent = NULL;
  c74_y = c74_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c74_b_sfEvent),
    &c74_thisId);
  sf_mex_destroy(&c74_b_sfEvent);
  *(int32_T *)c74_outData = c74_y;
  sf_mex_destroy(&c74_mxArrayInData);
}

static uint8_T c74_d_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_b_is_active_c74_ICARO3_Onda_bipe_controllonostro, const char_T
   *c74_identifier)
{
  uint8_T c74_y;
  emlrtMsgIdentifier c74_thisId;
  c74_thisId.fIdentifier = c74_identifier;
  c74_thisId.fParent = NULL;
  c74_y = c74_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c74_b_is_active_c74_ICARO3_Onda_bipe_controllonostro), &c74_thisId);
  sf_mex_destroy(&c74_b_is_active_c74_ICARO3_Onda_bipe_controllonostro);
  return c74_y;
}

static uint8_T c74_e_emlrt_marshallIn
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c74_u, const emlrtMsgIdentifier *c74_parentId)
{
  uint8_T c74_y;
  uint8_T c74_u0;
  (void)chartInstance;
  sf_mex_import(c74_parentId, sf_mex_dup(c74_u), &c74_u0, 1, 3, 0U, 0, 0U, 0);
  c74_y = c74_u0;
  sf_mex_destroy(&c74_u);
  return c74_y;
}

static void init_dsm_address_info
  (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
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

void sf_c74_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3756427227U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2603831302U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1297260362U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3254476609U);
}

mxArray *sf_c74_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YsGVWlkTesVlZCfLinpN6B");
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

mxArray *sf_c74_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c74_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c74_ICARO3_Onda_bipe_controllonostro
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"theta\",},{M[8],M[0],T\"is_active_c74_ICARO3_Onda_bipe_controllonostro\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c74_ICARO3_Onda_bipe_controllonostro_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostroMachineNumber_,
           74,
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
          (_ICARO3_Onda_bipe_controllonostroMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_bipe_controllonostroMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_controllonostroMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"theta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,232);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c74_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c74_sf_marshallOut,(MexInFcnForType)c74_sf_marshallIn);

        {
          real_T *c74_theta;
          real_T (*c74_u)[2];
          c74_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c74_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c74_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c74_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_controllonostroMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "JSDsNSAj7vNxFylC68AlmC";
}

static void sf_opaque_initialize_c74_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
  initialize_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c74_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  enable_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c74_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  disable_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c74_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  sf_gateway_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c74_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c74_ICARO3_Onda_bipe_controllonostro();/* state var info */
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

extern void sf_internal_set_sim_state_c74_ICARO3_Onda_bipe_controllonostro
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
    sf_get_sim_state_info_c74_ICARO3_Onda_bipe_controllonostro();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c74_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  return sf_internal_get_sim_state_c74_ICARO3_Onda_bipe_controllonostro(S);
}

static void sf_opaque_set_sim_state_c74_ICARO3_Onda_bipe_controllonostro
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c74_ICARO3_Onda_bipe_controllonostro(S, st);
}

static void sf_opaque_terminate_c74_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_optimization_info();
    }

    finalize_c74_ICARO3_Onda_bipe_controllonostro
      ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc74_ICARO3_Onda_bipe_controllonostro
    ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c74_ICARO3_Onda_bipe_controllonostro(SimStruct *
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
    initialize_params_c74_ICARO3_Onda_bipe_controllonostro
      ((SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c74_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      74);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,74,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,74,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,74);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,74,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,74,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,74);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1169252569U));
  ssSetChecksum1(S,(93234558U));
  ssSetChecksum2(S,(1773927201U));
  ssSetChecksum3(S,(3941312432U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c74_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c74_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    utMalloc(sizeof(SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc74_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c74_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c74_ICARO3_Onda_bipe_controllonostro;
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

void c74_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c74_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c74_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c74_ICARO3_Onda_bipe_controllonostro(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c74_ICARO3_Onda_bipe_controllonostro_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
