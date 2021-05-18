/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_sfun.h"
#include "c72_ICARO3_Onda_bipe_controllonostro.h"
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
static const char * c72_debug_family_names[4] = { "nargin", "nargout",
  "theta_in", "theta_out" };

/* Function Declarations */
static void initialize_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initialize_params_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void enable_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void disable_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void c72_update_debugger_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void set_sim_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_st);
static void finalize_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void sf_gateway_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initSimStructsc72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c72_machineNumber, uint32_T
  c72_chartNumber, uint32_T c72_instanceNumber);
static const mxArray *c72_sf_marshallOut(void *chartInstanceVoid, void
  *c72_inData);
static real_T c72_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_theta_out, const char_T *c72_identifier);
static real_T c72_b_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId);
static void c72_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c72_mxArrayInData, const char_T *c72_varName, void *c72_outData);
static void c72_info_helper(const mxArray **c72_info);
static const mxArray *c72_emlrt_marshallOut(const char * c72_u);
static const mxArray *c72_b_emlrt_marshallOut(const uint32_T c72_u);
static void c72_eml_scalar_eg
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static const mxArray *c72_b_sf_marshallOut(void *chartInstanceVoid, void
  *c72_inData);
static int32_T c72_c_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId);
static void c72_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c72_mxArrayInData, const char_T *c72_varName, void *c72_outData);
static uint8_T c72_d_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_b_is_active_c72_ICARO3_Onda_bipe_controllonostro, const char_T
   *c72_identifier);
static uint8_T c72_e_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId);
static void init_dsm_address_info
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  chartInstance->c72_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c72_is_active_c72_ICARO3_Onda_bipe_controllonostro = 0U;
}

static void initialize_params_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c72_update_debugger_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  const mxArray *c72_st;
  const mxArray *c72_y = NULL;
  real_T c72_hoistedGlobal;
  real_T c72_u;
  const mxArray *c72_b_y = NULL;
  uint8_T c72_b_hoistedGlobal;
  uint8_T c72_b_u;
  const mxArray *c72_c_y = NULL;
  real_T *c72_theta_out;
  c72_theta_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c72_st = NULL;
  c72_st = NULL;
  c72_y = NULL;
  sf_mex_assign(&c72_y, sf_mex_createcellmatrix(2, 1), false);
  c72_hoistedGlobal = *c72_theta_out;
  c72_u = c72_hoistedGlobal;
  c72_b_y = NULL;
  sf_mex_assign(&c72_b_y, sf_mex_create("y", &c72_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c72_y, 0, c72_b_y);
  c72_b_hoistedGlobal =
    chartInstance->c72_is_active_c72_ICARO3_Onda_bipe_controllonostro;
  c72_b_u = c72_b_hoistedGlobal;
  c72_c_y = NULL;
  sf_mex_assign(&c72_c_y, sf_mex_create("y", &c72_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c72_y, 1, c72_c_y);
  sf_mex_assign(&c72_st, c72_y, false);
  return c72_st;
}

static void set_sim_state_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_st)
{
  const mxArray *c72_u;
  real_T *c72_theta_out;
  c72_theta_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c72_doneDoubleBufferReInit = true;
  c72_u = sf_mex_dup(c72_st);
  *c72_theta_out = c72_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c72_u, 0)), "theta_out");
  chartInstance->c72_is_active_c72_ICARO3_Onda_bipe_controllonostro =
    c72_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c72_u, 1)),
    "is_active_c72_ICARO3_Onda_bipe_controllonostro");
  sf_mex_destroy(&c72_u);
  c72_update_debugger_state_c72_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c72_st);
}

static void finalize_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  real_T c72_hoistedGlobal;
  real_T c72_theta_in;
  uint32_T c72_debug_family_var_map[4];
  real_T c72_nargin = 1.0;
  real_T c72_nargout = 1.0;
  real_T c72_theta_out;
  real_T c72_x;
  real_T c72_xk;
  real_T c72_b_x;
  real_T c72_c_x;
  real_T c72_d_x;
  real_T c72_e_x;
  real_T c72_y;
  real_T c72_f_x;
  real_T c72_b_y;
  real_T c72_g_x;
  real_T c72_h_x;
  real_T *c72_b_theta_in;
  real_T *c72_b_theta_out;
  c72_b_theta_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c72_b_theta_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c72_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c72_b_theta_in, 0U);
  chartInstance->c72_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c72_sfEvent);
  c72_hoistedGlobal = *c72_b_theta_in;
  c72_theta_in = c72_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c72_debug_family_names,
    c72_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c72_nargin, 0U, c72_sf_marshallOut,
    c72_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c72_nargout, 1U, c72_sf_marshallOut,
    c72_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c72_theta_in, 2U, c72_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c72_theta_out, 3U, c72_sf_marshallOut,
    c72_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c72_sfEvent, 10);
  c72_theta_in += 6.2831853071795862;
  _SFD_EML_CALL(0U, chartInstance->c72_sfEvent, 11);
  c72_x = c72_theta_in;
  c72_eml_scalar_eg(chartInstance);
  c72_theta_out = 0.0;
  c72_xk = c72_x;
  c72_b_x = c72_xk;
  c72_eml_scalar_eg(chartInstance);
  c72_theta_out = c72_b_x / 6.2831853071795862;
  c72_c_x = c72_theta_out;
  c72_d_x = c72_c_x;
  c72_d_x = muDoubleScalarRound(c72_d_x);
  c72_e_x = c72_theta_out - c72_d_x;
  c72_y = muDoubleScalarAbs(c72_e_x);
  c72_f_x = c72_theta_out;
  c72_b_y = muDoubleScalarAbs(c72_f_x);
  if (c72_y <= 2.2204460492503131E-16 * c72_b_y) {
    c72_theta_out = 0.0;
  } else {
    c72_g_x = c72_theta_out;
    c72_h_x = c72_g_x;
    c72_h_x = muDoubleScalarFloor(c72_h_x);
    c72_theta_out = (c72_theta_out - c72_h_x) * 6.2831853071795862;
  }

  _SFD_EML_CALL(0U, chartInstance->c72_sfEvent, 12);
  if (CV_EML_IF(0, 1, 0, c72_theta_out > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, chartInstance->c72_sfEvent, 13);
    c72_theta_out -= 6.2831853071795862;
  }

  _SFD_EML_CALL(0U, chartInstance->c72_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *c72_b_theta_out = c72_theta_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c72_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostroMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c72_b_theta_out, 1U);
}

static void initSimStructsc72_ICARO3_Onda_bipe_controllonostro
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c72_machineNumber, uint32_T
  c72_chartNumber, uint32_T c72_instanceNumber)
{
  (void)c72_machineNumber;
  (void)c72_chartNumber;
  (void)c72_instanceNumber;
}

static const mxArray *c72_sf_marshallOut(void *chartInstanceVoid, void
  *c72_inData)
{
  const mxArray *c72_mxArrayOutData = NULL;
  real_T c72_u;
  const mxArray *c72_y = NULL;
  SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c72_mxArrayOutData = NULL;
  c72_u = *(real_T *)c72_inData;
  c72_y = NULL;
  sf_mex_assign(&c72_y, sf_mex_create("y", &c72_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c72_mxArrayOutData, c72_y, false);
  return c72_mxArrayOutData;
}

static real_T c72_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_theta_out, const char_T *c72_identifier)
{
  real_T c72_y;
  emlrtMsgIdentifier c72_thisId;
  c72_thisId.fIdentifier = c72_identifier;
  c72_thisId.fParent = NULL;
  c72_y = c72_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c72_theta_out),
    &c72_thisId);
  sf_mex_destroy(&c72_theta_out);
  return c72_y;
}

static real_T c72_b_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId)
{
  real_T c72_y;
  real_T c72_d0;
  (void)chartInstance;
  sf_mex_import(c72_parentId, sf_mex_dup(c72_u), &c72_d0, 1, 0, 0U, 0, 0U, 0);
  c72_y = c72_d0;
  sf_mex_destroy(&c72_u);
  return c72_y;
}

static void c72_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c72_mxArrayInData, const char_T *c72_varName, void *c72_outData)
{
  const mxArray *c72_theta_out;
  const char_T *c72_identifier;
  emlrtMsgIdentifier c72_thisId;
  real_T c72_y;
  SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c72_theta_out = sf_mex_dup(c72_mxArrayInData);
  c72_identifier = c72_varName;
  c72_thisId.fIdentifier = c72_identifier;
  c72_thisId.fParent = NULL;
  c72_y = c72_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c72_theta_out),
    &c72_thisId);
  sf_mex_destroy(&c72_theta_out);
  *(real_T *)c72_outData = c72_y;
  sf_mex_destroy(&c72_mxArrayInData);
}

const mxArray
  *sf_c72_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void)
{
  const mxArray *c72_nameCaptureInfo = NULL;
  c72_nameCaptureInfo = NULL;
  sf_mex_assign(&c72_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c72_info_helper(&c72_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c72_nameCaptureInfo);
  return c72_nameCaptureInfo;
}

static void c72_info_helper(const mxArray **c72_info)
{
  const mxArray *c72_rhs0 = NULL;
  const mxArray *c72_lhs0 = NULL;
  const mxArray *c72_rhs1 = NULL;
  const mxArray *c72_lhs1 = NULL;
  const mxArray *c72_rhs2 = NULL;
  const mxArray *c72_lhs2 = NULL;
  const mxArray *c72_rhs3 = NULL;
  const mxArray *c72_lhs3 = NULL;
  const mxArray *c72_rhs4 = NULL;
  const mxArray *c72_lhs4 = NULL;
  const mxArray *c72_rhs5 = NULL;
  const mxArray *c72_lhs5 = NULL;
  const mxArray *c72_rhs6 = NULL;
  const mxArray *c72_lhs6 = NULL;
  const mxArray *c72_rhs7 = NULL;
  const mxArray *c72_lhs7 = NULL;
  const mxArray *c72_rhs8 = NULL;
  const mxArray *c72_lhs8 = NULL;
  const mxArray *c72_rhs9 = NULL;
  const mxArray *c72_lhs9 = NULL;
  const mxArray *c72_rhs10 = NULL;
  const mxArray *c72_lhs10 = NULL;
  const mxArray *c72_rhs11 = NULL;
  const mxArray *c72_lhs11 = NULL;
  const mxArray *c72_rhs12 = NULL;
  const mxArray *c72_lhs12 = NULL;
  const mxArray *c72_rhs13 = NULL;
  const mxArray *c72_lhs13 = NULL;
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("mod"), "name", "name", 0);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c72_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c72_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c72_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c72_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 4);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c72_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c72_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 6);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c72_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 7);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 7);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c72_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 8);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 8);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1307651238U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c72_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 9);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c72_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 10);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eps"), "name", "name", 10);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c72_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c72_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_eps"), "name", "name",
                  12);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c72_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c72_info, c72_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c72_info, c72_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c72_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c72_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c72_info, sf_mex_duplicatearraysafe(&c72_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c72_rhs0);
  sf_mex_destroy(&c72_lhs0);
  sf_mex_destroy(&c72_rhs1);
  sf_mex_destroy(&c72_lhs1);
  sf_mex_destroy(&c72_rhs2);
  sf_mex_destroy(&c72_lhs2);
  sf_mex_destroy(&c72_rhs3);
  sf_mex_destroy(&c72_lhs3);
  sf_mex_destroy(&c72_rhs4);
  sf_mex_destroy(&c72_lhs4);
  sf_mex_destroy(&c72_rhs5);
  sf_mex_destroy(&c72_lhs5);
  sf_mex_destroy(&c72_rhs6);
  sf_mex_destroy(&c72_lhs6);
  sf_mex_destroy(&c72_rhs7);
  sf_mex_destroy(&c72_lhs7);
  sf_mex_destroy(&c72_rhs8);
  sf_mex_destroy(&c72_lhs8);
  sf_mex_destroy(&c72_rhs9);
  sf_mex_destroy(&c72_lhs9);
  sf_mex_destroy(&c72_rhs10);
  sf_mex_destroy(&c72_lhs10);
  sf_mex_destroy(&c72_rhs11);
  sf_mex_destroy(&c72_lhs11);
  sf_mex_destroy(&c72_rhs12);
  sf_mex_destroy(&c72_lhs12);
  sf_mex_destroy(&c72_rhs13);
  sf_mex_destroy(&c72_lhs13);
}

static const mxArray *c72_emlrt_marshallOut(const char * c72_u)
{
  const mxArray *c72_y = NULL;
  c72_y = NULL;
  sf_mex_assign(&c72_y, sf_mex_create("y", c72_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c72_u)), false);
  return c72_y;
}

static const mxArray *c72_b_emlrt_marshallOut(const uint32_T c72_u)
{
  const mxArray *c72_y = NULL;
  c72_y = NULL;
  sf_mex_assign(&c72_y, sf_mex_create("y", &c72_u, 7, 0U, 0U, 0U, 0), false);
  return c72_y;
}

static void c72_eml_scalar_eg
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c72_b_sf_marshallOut(void *chartInstanceVoid, void
  *c72_inData)
{
  const mxArray *c72_mxArrayOutData = NULL;
  int32_T c72_u;
  const mxArray *c72_y = NULL;
  SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c72_mxArrayOutData = NULL;
  c72_u = *(int32_T *)c72_inData;
  c72_y = NULL;
  sf_mex_assign(&c72_y, sf_mex_create("y", &c72_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c72_mxArrayOutData, c72_y, false);
  return c72_mxArrayOutData;
}

static int32_T c72_c_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId)
{
  int32_T c72_y;
  int32_T c72_i0;
  (void)chartInstance;
  sf_mex_import(c72_parentId, sf_mex_dup(c72_u), &c72_i0, 1, 6, 0U, 0, 0U, 0);
  c72_y = c72_i0;
  sf_mex_destroy(&c72_u);
  return c72_y;
}

static void c72_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c72_mxArrayInData, const char_T *c72_varName, void *c72_outData)
{
  const mxArray *c72_b_sfEvent;
  const char_T *c72_identifier;
  emlrtMsgIdentifier c72_thisId;
  int32_T c72_y;
  SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c72_b_sfEvent = sf_mex_dup(c72_mxArrayInData);
  c72_identifier = c72_varName;
  c72_thisId.fIdentifier = c72_identifier;
  c72_thisId.fParent = NULL;
  c72_y = c72_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c72_b_sfEvent),
    &c72_thisId);
  sf_mex_destroy(&c72_b_sfEvent);
  *(int32_T *)c72_outData = c72_y;
  sf_mex_destroy(&c72_mxArrayInData);
}

static uint8_T c72_d_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_b_is_active_c72_ICARO3_Onda_bipe_controllonostro, const char_T
   *c72_identifier)
{
  uint8_T c72_y;
  emlrtMsgIdentifier c72_thisId;
  c72_thisId.fIdentifier = c72_identifier;
  c72_thisId.fParent = NULL;
  c72_y = c72_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c72_b_is_active_c72_ICARO3_Onda_bipe_controllonostro), &c72_thisId);
  sf_mex_destroy(&c72_b_is_active_c72_ICARO3_Onda_bipe_controllonostro);
  return c72_y;
}

static uint8_T c72_e_emlrt_marshallIn
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c72_u, const emlrtMsgIdentifier *c72_parentId)
{
  uint8_T c72_y;
  uint8_T c72_u0;
  (void)chartInstance;
  sf_mex_import(c72_parentId, sf_mex_dup(c72_u), &c72_u0, 1, 3, 0U, 0, 0U, 0);
  c72_y = c72_u0;
  sf_mex_destroy(&c72_u);
  return c72_y;
}

static void init_dsm_address_info
  (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
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

void sf_c72_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1059824504U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1111759851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3102334758U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(321826054U);
}

mxArray *sf_c72_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("V0074mVK2JvY0uDlfVjc3G");
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

mxArray *sf_c72_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c72_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c72_ICARO3_Onda_bipe_controllonostro
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"theta_out\",},{M[8],M[0],T\"is_active_c72_ICARO3_Onda_bipe_controllonostro\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c72_ICARO3_Onda_bipe_controllonostro_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostroMachineNumber_,
           72,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"theta_out");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,470);
        _SFD_CV_INIT_EML_IF(0,1,0,383,402,-1,461);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c72_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c72_sf_marshallOut,(MexInFcnForType)c72_sf_marshallIn);

        {
          real_T *c72_theta_in;
          real_T *c72_theta_out;
          c72_theta_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c72_theta_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c72_theta_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c72_theta_out);
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
  return "ct28WR52DkpPp1A3x5BM5G";
}

static void sf_opaque_initialize_c72_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
  initialize_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c72_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  enable_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c72_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  disable_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c72_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  sf_gateway_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c72_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c72_ICARO3_Onda_bipe_controllonostro();/* state var info */
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

extern void sf_internal_set_sim_state_c72_ICARO3_Onda_bipe_controllonostro
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
    sf_get_sim_state_info_c72_ICARO3_Onda_bipe_controllonostro();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c72_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  return sf_internal_get_sim_state_c72_ICARO3_Onda_bipe_controllonostro(S);
}

static void sf_opaque_set_sim_state_c72_ICARO3_Onda_bipe_controllonostro
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c72_ICARO3_Onda_bipe_controllonostro(S, st);
}

static void sf_opaque_terminate_c72_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_optimization_info();
    }

    finalize_c72_ICARO3_Onda_bipe_controllonostro
      ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc72_ICARO3_Onda_bipe_controllonostro
    ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c72_ICARO3_Onda_bipe_controllonostro(SimStruct *
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
    initialize_params_c72_ICARO3_Onda_bipe_controllonostro
      ((SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c72_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      72);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,72,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,72,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,72);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,72,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,72,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,72);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3798025755U));
  ssSetChecksum1(S,(1150047452U));
  ssSetChecksum2(S,(1226172788U));
  ssSetChecksum3(S,(1637521284U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c72_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c72_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    utMalloc(sizeof(SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc72_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c72_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c72_ICARO3_Onda_bipe_controllonostro;
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

void c72_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c72_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c72_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c72_ICARO3_Onda_bipe_controllonostro(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c72_ICARO3_Onda_bipe_controllonostro_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
