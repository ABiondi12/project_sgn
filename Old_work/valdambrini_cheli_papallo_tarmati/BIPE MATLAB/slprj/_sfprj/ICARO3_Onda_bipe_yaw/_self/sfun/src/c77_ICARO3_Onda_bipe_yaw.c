/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_yaw_sfun.h"
#include "c77_ICARO3_Onda_bipe_yaw.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_yaw_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c77_debug_family_names[11] = { "zero_speed_pwm",
  "max_speed_pwm", "control_freq", "rise_time", "delta", "cur_prev_diff",
  "nargin", "nargout", "prev_des_control", "current_des_control", "control" };

/* Function Declarations */
static void initialize_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void initialize_params_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void enable_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void disable_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void c77_update_debugger_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void set_sim_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance, const mxArray
   *c77_st);
static void finalize_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void sf_gateway_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void initSimStructsc77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c77_machineNumber, uint32_T
  c77_chartNumber, uint32_T c77_instanceNumber);
static const mxArray *c77_sf_marshallOut(void *chartInstanceVoid, void
  *c77_inData);
static real_T c77_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_control, const char_T *c77_identifier);
static real_T c77_b_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId);
static void c77_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c77_mxArrayInData, const char_T *c77_varName, void *c77_outData);
static void c77_info_helper(const mxArray **c77_info);
static const mxArray *c77_emlrt_marshallOut(const char * c77_u);
static const mxArray *c77_b_emlrt_marshallOut(const uint32_T c77_u);
static const mxArray *c77_b_sf_marshallOut(void *chartInstanceVoid, void
  *c77_inData);
static int32_T c77_c_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId);
static void c77_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c77_mxArrayInData, const char_T *c77_varName, void *c77_outData);
static uint8_T c77_d_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_b_is_active_c77_ICARO3_Onda_bipe_yaw, const
  char_T *c77_identifier);
static uint8_T c77_e_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId);
static void init_dsm_address_info(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  chartInstance->c77_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c77_is_active_c77_ICARO3_Onda_bipe_yaw = 0U;
}

static void initialize_params_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c77_update_debugger_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  const mxArray *c77_st;
  const mxArray *c77_y = NULL;
  real_T c77_hoistedGlobal;
  real_T c77_u;
  const mxArray *c77_b_y = NULL;
  uint8_T c77_b_hoistedGlobal;
  uint8_T c77_b_u;
  const mxArray *c77_c_y = NULL;
  real_T *c77_control;
  c77_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c77_st = NULL;
  c77_st = NULL;
  c77_y = NULL;
  sf_mex_assign(&c77_y, sf_mex_createcellmatrix(2, 1), false);
  c77_hoistedGlobal = *c77_control;
  c77_u = c77_hoistedGlobal;
  c77_b_y = NULL;
  sf_mex_assign(&c77_b_y, sf_mex_create("y", &c77_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c77_y, 0, c77_b_y);
  c77_b_hoistedGlobal = chartInstance->c77_is_active_c77_ICARO3_Onda_bipe_yaw;
  c77_b_u = c77_b_hoistedGlobal;
  c77_c_y = NULL;
  sf_mex_assign(&c77_c_y, sf_mex_create("y", &c77_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c77_y, 1, c77_c_y);
  sf_mex_assign(&c77_st, c77_y, false);
  return c77_st;
}

static void set_sim_state_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance, const mxArray
   *c77_st)
{
  const mxArray *c77_u;
  real_T *c77_control;
  c77_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c77_doneDoubleBufferReInit = true;
  c77_u = sf_mex_dup(c77_st);
  *c77_control = c77_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c77_u, 0)), "control");
  chartInstance->c77_is_active_c77_ICARO3_Onda_bipe_yaw = c77_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c77_u, 1)),
     "is_active_c77_ICARO3_Onda_bipe_yaw");
  sf_mex_destroy(&c77_u);
  c77_update_debugger_state_c77_ICARO3_Onda_bipe_yaw(chartInstance);
  sf_mex_destroy(&c77_st);
}

static void finalize_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  real_T c77_hoistedGlobal;
  real_T c77_b_hoistedGlobal;
  real_T c77_prev_des_control;
  real_T c77_current_des_control;
  uint32_T c77_debug_family_var_map[11];
  real_T c77_zero_speed_pwm;
  real_T c77_max_speed_pwm;
  real_T c77_control_freq;
  real_T c77_rise_time;
  real_T c77_delta;
  real_T c77_cur_prev_diff;
  real_T c77_nargin = 2.0;
  real_T c77_nargout = 1.0;
  real_T c77_control;
  real_T c77_x;
  real_T c77_b_x;
  real_T c77_y;
  real_T c77_c_x;
  real_T c77_d_x;
  real_T *c77_b_prev_des_control;
  real_T *c77_b_current_des_control;
  real_T *c77_b_control;
  c77_b_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c77_b_current_des_control = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c77_b_prev_des_control = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c77_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c77_b_prev_des_control, 0U);
  _SFD_DATA_RANGE_CHECK(*c77_b_current_des_control, 1U);
  chartInstance->c77_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c77_sfEvent);
  c77_hoistedGlobal = *c77_b_prev_des_control;
  c77_b_hoistedGlobal = *c77_b_current_des_control;
  c77_prev_des_control = c77_hoistedGlobal;
  c77_current_des_control = c77_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c77_debug_family_names,
    c77_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_zero_speed_pwm, 0U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_max_speed_pwm, 1U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_control_freq, 2U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_rise_time, 3U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_delta, 4U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c77_cur_prev_diff, 5U,
    c77_sf_marshallOut, c77_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c77_nargin, 6U, c77_sf_marshallOut,
    c77_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c77_nargout, 7U, c77_sf_marshallOut,
    c77_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_prev_des_control, 8U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c77_current_des_control, 9U, c77_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c77_control, 10U, c77_sf_marshallOut,
    c77_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 12);
  c77_zero_speed_pwm = 1.42;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 13);
  c77_max_speed_pwm = 1.2;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 14);
  c77_control_freq = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 15);
  c77_rise_time = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 17);
  c77_delta = 0.00043999999999999996;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 19);
  c77_cur_prev_diff = c77_current_des_control - c77_prev_des_control;
  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 21);
  c77_x = c77_cur_prev_diff;
  c77_b_x = c77_x;
  c77_y = muDoubleScalarAbs(c77_b_x);
  if (CV_EML_IF(0, 1, 0, c77_y < c77_delta)) {
    _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 22);
    c77_control = c77_current_des_control;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, 24);
    c77_c_x = c77_cur_prev_diff;
    c77_d_x = c77_c_x;
    c77_d_x = muDoubleScalarSign(c77_d_x);
    c77_control = c77_prev_des_control + c77_d_x * 0.00043999999999999996;
  }

  _SFD_EML_CALL(0U, chartInstance->c77_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  *c77_b_control = c77_control;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c77_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO3_Onda_bipe_yawMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c77_b_control, 2U);
}

static void initSimStructsc77_ICARO3_Onda_bipe_yaw
  (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c77_machineNumber, uint32_T
  c77_chartNumber, uint32_T c77_instanceNumber)
{
  (void)c77_machineNumber;
  (void)c77_chartNumber;
  (void)c77_instanceNumber;
}

static const mxArray *c77_sf_marshallOut(void *chartInstanceVoid, void
  *c77_inData)
{
  const mxArray *c77_mxArrayOutData = NULL;
  real_T c77_u;
  const mxArray *c77_y = NULL;
  SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c77_mxArrayOutData = NULL;
  c77_u = *(real_T *)c77_inData;
  c77_y = NULL;
  sf_mex_assign(&c77_y, sf_mex_create("y", &c77_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c77_mxArrayOutData, c77_y, false);
  return c77_mxArrayOutData;
}

static real_T c77_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_control, const char_T *c77_identifier)
{
  real_T c77_y;
  emlrtMsgIdentifier c77_thisId;
  c77_thisId.fIdentifier = c77_identifier;
  c77_thisId.fParent = NULL;
  c77_y = c77_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c77_control),
    &c77_thisId);
  sf_mex_destroy(&c77_control);
  return c77_y;
}

static real_T c77_b_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId)
{
  real_T c77_y;
  real_T c77_d0;
  (void)chartInstance;
  sf_mex_import(c77_parentId, sf_mex_dup(c77_u), &c77_d0, 1, 0, 0U, 0, 0U, 0);
  c77_y = c77_d0;
  sf_mex_destroy(&c77_u);
  return c77_y;
}

static void c77_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c77_mxArrayInData, const char_T *c77_varName, void *c77_outData)
{
  const mxArray *c77_control;
  const char_T *c77_identifier;
  emlrtMsgIdentifier c77_thisId;
  real_T c77_y;
  SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c77_control = sf_mex_dup(c77_mxArrayInData);
  c77_identifier = c77_varName;
  c77_thisId.fIdentifier = c77_identifier;
  c77_thisId.fParent = NULL;
  c77_y = c77_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c77_control),
    &c77_thisId);
  sf_mex_destroy(&c77_control);
  *(real_T *)c77_outData = c77_y;
  sf_mex_destroy(&c77_mxArrayInData);
}

const mxArray *sf_c77_ICARO3_Onda_bipe_yaw_get_eml_resolved_functions_info(void)
{
  const mxArray *c77_nameCaptureInfo = NULL;
  c77_nameCaptureInfo = NULL;
  sf_mex_assign(&c77_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c77_info_helper(&c77_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c77_nameCaptureInfo);
  return c77_nameCaptureInfo;
}

static void c77_info_helper(const mxArray **c77_info)
{
  const mxArray *c77_rhs0 = NULL;
  const mxArray *c77_lhs0 = NULL;
  const mxArray *c77_rhs1 = NULL;
  const mxArray *c77_lhs1 = NULL;
  const mxArray *c77_rhs2 = NULL;
  const mxArray *c77_lhs2 = NULL;
  const mxArray *c77_rhs3 = NULL;
  const mxArray *c77_lhs3 = NULL;
  const mxArray *c77_rhs4 = NULL;
  const mxArray *c77_lhs4 = NULL;
  const mxArray *c77_rhs5 = NULL;
  const mxArray *c77_lhs5 = NULL;
  const mxArray *c77_rhs6 = NULL;
  const mxArray *c77_lhs6 = NULL;
  const mxArray *c77_rhs7 = NULL;
  const mxArray *c77_lhs7 = NULL;
  const mxArray *c77_rhs8 = NULL;
  const mxArray *c77_lhs8 = NULL;
  const mxArray *c77_rhs9 = NULL;
  const mxArray *c77_lhs9 = NULL;
  const mxArray *c77_rhs10 = NULL;
  const mxArray *c77_lhs10 = NULL;
  const mxArray *c77_rhs11 = NULL;
  const mxArray *c77_lhs11 = NULL;
  const mxArray *c77_rhs12 = NULL;
  const mxArray *c77_lhs12 = NULL;
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c77_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c77_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c77_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c77_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c77_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c77_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c77_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("abs"), "name", "name", 7);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c77_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c77_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c77_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("sign"), "name", "name", 10);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c77_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c77_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 12);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c77_info, c77_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(1356541494U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c77_info, c77_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c77_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c77_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c77_info, sf_mex_duplicatearraysafe(&c77_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c77_rhs0);
  sf_mex_destroy(&c77_lhs0);
  sf_mex_destroy(&c77_rhs1);
  sf_mex_destroy(&c77_lhs1);
  sf_mex_destroy(&c77_rhs2);
  sf_mex_destroy(&c77_lhs2);
  sf_mex_destroy(&c77_rhs3);
  sf_mex_destroy(&c77_lhs3);
  sf_mex_destroy(&c77_rhs4);
  sf_mex_destroy(&c77_lhs4);
  sf_mex_destroy(&c77_rhs5);
  sf_mex_destroy(&c77_lhs5);
  sf_mex_destroy(&c77_rhs6);
  sf_mex_destroy(&c77_lhs6);
  sf_mex_destroy(&c77_rhs7);
  sf_mex_destroy(&c77_lhs7);
  sf_mex_destroy(&c77_rhs8);
  sf_mex_destroy(&c77_lhs8);
  sf_mex_destroy(&c77_rhs9);
  sf_mex_destroy(&c77_lhs9);
  sf_mex_destroy(&c77_rhs10);
  sf_mex_destroy(&c77_lhs10);
  sf_mex_destroy(&c77_rhs11);
  sf_mex_destroy(&c77_lhs11);
  sf_mex_destroy(&c77_rhs12);
  sf_mex_destroy(&c77_lhs12);
}

static const mxArray *c77_emlrt_marshallOut(const char * c77_u)
{
  const mxArray *c77_y = NULL;
  c77_y = NULL;
  sf_mex_assign(&c77_y, sf_mex_create("y", c77_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c77_u)), false);
  return c77_y;
}

static const mxArray *c77_b_emlrt_marshallOut(const uint32_T c77_u)
{
  const mxArray *c77_y = NULL;
  c77_y = NULL;
  sf_mex_assign(&c77_y, sf_mex_create("y", &c77_u, 7, 0U, 0U, 0U, 0), false);
  return c77_y;
}

static const mxArray *c77_b_sf_marshallOut(void *chartInstanceVoid, void
  *c77_inData)
{
  const mxArray *c77_mxArrayOutData = NULL;
  int32_T c77_u;
  const mxArray *c77_y = NULL;
  SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c77_mxArrayOutData = NULL;
  c77_u = *(int32_T *)c77_inData;
  c77_y = NULL;
  sf_mex_assign(&c77_y, sf_mex_create("y", &c77_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c77_mxArrayOutData, c77_y, false);
  return c77_mxArrayOutData;
}

static int32_T c77_c_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId)
{
  int32_T c77_y;
  int32_T c77_i0;
  (void)chartInstance;
  sf_mex_import(c77_parentId, sf_mex_dup(c77_u), &c77_i0, 1, 6, 0U, 0, 0U, 0);
  c77_y = c77_i0;
  sf_mex_destroy(&c77_u);
  return c77_y;
}

static void c77_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c77_mxArrayInData, const char_T *c77_varName, void *c77_outData)
{
  const mxArray *c77_b_sfEvent;
  const char_T *c77_identifier;
  emlrtMsgIdentifier c77_thisId;
  int32_T c77_y;
  SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c77_b_sfEvent = sf_mex_dup(c77_mxArrayInData);
  c77_identifier = c77_varName;
  c77_thisId.fIdentifier = c77_identifier;
  c77_thisId.fParent = NULL;
  c77_y = c77_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c77_b_sfEvent),
    &c77_thisId);
  sf_mex_destroy(&c77_b_sfEvent);
  *(int32_T *)c77_outData = c77_y;
  sf_mex_destroy(&c77_mxArrayInData);
}

static uint8_T c77_d_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_b_is_active_c77_ICARO3_Onda_bipe_yaw, const
  char_T *c77_identifier)
{
  uint8_T c77_y;
  emlrtMsgIdentifier c77_thisId;
  c77_thisId.fIdentifier = c77_identifier;
  c77_thisId.fParent = NULL;
  c77_y = c77_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c77_b_is_active_c77_ICARO3_Onda_bipe_yaw), &c77_thisId);
  sf_mex_destroy(&c77_b_is_active_c77_ICARO3_Onda_bipe_yaw);
  return c77_y;
}

static uint8_T c77_e_emlrt_marshallIn(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c77_u, const emlrtMsgIdentifier *c77_parentId)
{
  uint8_T c77_y;
  uint8_T c77_u0;
  (void)chartInstance;
  sf_mex_import(c77_parentId, sf_mex_dup(c77_u), &c77_u0, 1, 3, 0U, 0, 0U, 0);
  c77_y = c77_u0;
  sf_mex_destroy(&c77_u);
  return c77_y;
}

static void init_dsm_address_info(SFc77_ICARO3_Onda_bipe_yawInstanceStruct
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

void sf_c77_ICARO3_Onda_bipe_yaw_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1686056663U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3364002738U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2332107244U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4178138077U);
}

mxArray *sf_c77_ICARO3_Onda_bipe_yaw_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hXVnCQBNlAdLZa4MpoePYB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c77_ICARO3_Onda_bipe_yaw_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c77_ICARO3_Onda_bipe_yaw_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c77_ICARO3_Onda_bipe_yaw(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"control\",},{M[8],M[0],T\"is_active_c77_ICARO3_Onda_bipe_yaw\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c77_ICARO3_Onda_bipe_yaw_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_yawMachineNumber_,
           77,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ICARO3_Onda_bipe_yawMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ICARO3_Onda_bipe_yawMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_yawMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"prev_des_control");
          _SFD_SET_DATA_PROPS(1,1,1,0,"current_des_control");
          _SFD_SET_DATA_PROPS(2,2,0,1,"control");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,910);
        _SFD_CV_INIT_EML_IF(0,1,0,771,802,838,906);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c77_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c77_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c77_sf_marshallOut,(MexInFcnForType)c77_sf_marshallIn);

        {
          real_T *c77_prev_des_control;
          real_T *c77_current_des_control;
          real_T *c77_control;
          c77_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c77_current_des_control = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c77_prev_des_control = (real_T *)ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, c77_prev_des_control);
          _SFD_SET_DATA_VALUE_PTR(1U, c77_current_des_control);
          _SFD_SET_DATA_VALUE_PTR(2U, c77_control);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_yawMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XbD1cPPhDGPfNfqaCYFEN";
}

static void sf_opaque_initialize_c77_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c77_ICARO3_Onda_bipe_yaw
    ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar);
  initialize_c77_ICARO3_Onda_bipe_yaw((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c77_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  enable_c77_ICARO3_Onda_bipe_yaw((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c77_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  disable_c77_ICARO3_Onda_bipe_yaw((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c77_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  sf_gateway_c77_ICARO3_Onda_bipe_yaw((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c77_ICARO3_Onda_bipe_yaw
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c77_ICARO3_Onda_bipe_yaw
    ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c77_ICARO3_Onda_bipe_yaw();/* state var info */
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

extern void sf_internal_set_sim_state_c77_ICARO3_Onda_bipe_yaw(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c77_ICARO3_Onda_bipe_yaw();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c77_ICARO3_Onda_bipe_yaw
    ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c77_ICARO3_Onda_bipe_yaw(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c77_ICARO3_Onda_bipe_yaw(S);
}

static void sf_opaque_set_sim_state_c77_ICARO3_Onda_bipe_yaw(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c77_ICARO3_Onda_bipe_yaw(S, st);
}

static void sf_opaque_terminate_c77_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_yaw_optimization_info();
    }

    finalize_c77_ICARO3_Onda_bipe_yaw((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)
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
  initSimStructsc77_ICARO3_Onda_bipe_yaw
    ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c77_ICARO3_Onda_bipe_yaw(SimStruct *S)
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
    initialize_params_c77_ICARO3_Onda_bipe_yaw
      ((SFc77_ICARO3_Onda_bipe_yawInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c77_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_bipe_yaw_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      77);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,77,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,77,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,77);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,77,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,77,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,77);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1895427840U));
  ssSetChecksum1(S,(3368432702U));
  ssSetChecksum2(S,(1077007633U));
  ssSetChecksum3(S,(1076742283U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c77_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c77_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  SFc77_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc77_ICARO3_Onda_bipe_yawInstanceStruct *)utMalloc(sizeof
    (SFc77_ICARO3_Onda_bipe_yawInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc77_ICARO3_Onda_bipe_yawInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.mdlStart = mdlStart_c77_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c77_ICARO3_Onda_bipe_yaw;
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

void c77_ICARO3_Onda_bipe_yaw_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c77_ICARO3_Onda_bipe_yaw(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c77_ICARO3_Onda_bipe_yaw(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c77_ICARO3_Onda_bipe_yaw(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c77_ICARO3_Onda_bipe_yaw_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
