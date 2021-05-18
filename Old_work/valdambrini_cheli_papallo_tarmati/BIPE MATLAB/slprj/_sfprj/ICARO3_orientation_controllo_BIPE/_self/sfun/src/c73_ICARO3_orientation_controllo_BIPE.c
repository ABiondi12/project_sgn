/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_orientation_controllo_BIPE_sfun.h"
#include "c73_ICARO3_orientation_controllo_BIPE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_orientation_controllo_BIPE_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c73_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initialize_params_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void enable_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void disable_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c73_update_debugger_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void set_sim_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_st);
static void finalize_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void sf_gateway_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initSimStructsc73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c73_machineNumber, uint32_T
  c73_chartNumber, uint32_T c73_instanceNumber);
static const mxArray *c73_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData);
static real_T c73_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_y, const char_T *c73_identifier);
static real_T c73_b_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId);
static void c73_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c73_mxArrayInData, const char_T *c73_varName, void *c73_outData);
static const mxArray *c73_b_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData);
static void c73_info_helper(const mxArray **c73_info);
static const mxArray *c73_emlrt_marshallOut(const char * c73_u);
static const mxArray *c73_b_emlrt_marshallOut(const uint32_T c73_u);
static real_T c73_eml_xnrm2
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, real_T
   c73_x[2]);
static const mxArray *c73_c_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData);
static int32_T c73_c_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId);
static void c73_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c73_mxArrayInData, const char_T *c73_varName, void *c73_outData);
static uint8_T c73_d_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_b_is_active_c73_ICARO3_orientation_controllo_BIPE, const char_T *
   c73_identifier);
static uint8_T c73_e_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId);
static void init_dsm_address_info
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  chartInstance->c73_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c73_is_active_c73_ICARO3_orientation_controllo_BIPE = 0U;
}

static void initialize_params_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c73_update_debugger_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  const mxArray *c73_st;
  const mxArray *c73_y = NULL;
  real_T c73_hoistedGlobal;
  real_T c73_u;
  const mxArray *c73_b_y = NULL;
  uint8_T c73_b_hoistedGlobal;
  uint8_T c73_b_u;
  const mxArray *c73_c_y = NULL;
  real_T *c73_d_y;
  c73_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c73_st = NULL;
  c73_st = NULL;
  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_createcellmatrix(2, 1), false);
  c73_hoistedGlobal = *c73_d_y;
  c73_u = c73_hoistedGlobal;
  c73_b_y = NULL;
  sf_mex_assign(&c73_b_y, sf_mex_create("y", &c73_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c73_y, 0, c73_b_y);
  c73_b_hoistedGlobal =
    chartInstance->c73_is_active_c73_ICARO3_orientation_controllo_BIPE;
  c73_b_u = c73_b_hoistedGlobal;
  c73_c_y = NULL;
  sf_mex_assign(&c73_c_y, sf_mex_create("y", &c73_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c73_y, 1, c73_c_y);
  sf_mex_assign(&c73_st, c73_y, false);
  return c73_st;
}

static void set_sim_state_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_st)
{
  const mxArray *c73_u;
  real_T *c73_y;
  c73_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c73_doneDoubleBufferReInit = true;
  c73_u = sf_mex_dup(c73_st);
  *c73_y = c73_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c73_u,
    0)), "y");
  chartInstance->c73_is_active_c73_ICARO3_orientation_controllo_BIPE =
    c73_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c73_u, 1)),
    "is_active_c73_ICARO3_orientation_controllo_BIPE");
  sf_mex_destroy(&c73_u);
  c73_update_debugger_state_c73_ICARO3_orientation_controllo_BIPE(chartInstance);
  sf_mex_destroy(&c73_st);
}

static void finalize_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  int32_T c73_i0;
  int32_T c73_i1;
  real_T c73_u[2];
  uint32_T c73_debug_family_var_map[4];
  real_T c73_nargin = 1.0;
  real_T c73_nargout = 1.0;
  real_T c73_y;
  int32_T c73_i2;
  real_T c73_x[2];
  int32_T c73_i3;
  real_T c73_b_x[2];
  real_T *c73_b_y;
  real_T (*c73_b_u)[2];
  c73_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c73_b_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c73_sfEvent);
  for (c73_i0 = 0; c73_i0 < 2; c73_i0++) {
    _SFD_DATA_RANGE_CHECK((*c73_b_u)[c73_i0], 0U);
  }

  chartInstance->c73_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c73_sfEvent);
  for (c73_i1 = 0; c73_i1 < 2; c73_i1++) {
    c73_u[c73_i1] = (*c73_b_u)[c73_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c73_debug_family_names,
    c73_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c73_nargin, 0U, c73_sf_marshallOut,
    c73_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c73_nargout, 1U, c73_sf_marshallOut,
    c73_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c73_u, 2U, c73_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c73_y, 3U, c73_sf_marshallOut,
    c73_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c73_sfEvent, 9);
  for (c73_i2 = 0; c73_i2 < 2; c73_i2++) {
    c73_x[c73_i2] = c73_u[c73_i2];
  }

  for (c73_i3 = 0; c73_i3 < 2; c73_i3++) {
    c73_b_x[c73_i3] = c73_x[c73_i3];
  }

  c73_y = c73_eml_xnrm2(chartInstance, c73_b_x);
  _SFD_EML_CALL(0U, chartInstance->c73_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *c73_b_y = c73_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c73_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_orientation_controllo_BIPEMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c73_b_y, 1U);
}

static void initSimStructsc73_ICARO3_orientation_controllo_BIPE
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c73_machineNumber, uint32_T
  c73_chartNumber, uint32_T c73_instanceNumber)
{
  (void)c73_machineNumber;
  (void)c73_chartNumber;
  (void)c73_instanceNumber;
}

static const mxArray *c73_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData)
{
  const mxArray *c73_mxArrayOutData = NULL;
  real_T c73_u;
  const mxArray *c73_y = NULL;
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c73_mxArrayOutData = NULL;
  c73_u = *(real_T *)c73_inData;
  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_create("y", &c73_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c73_mxArrayOutData, c73_y, false);
  return c73_mxArrayOutData;
}

static real_T c73_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_y, const char_T *c73_identifier)
{
  real_T c73_b_y;
  emlrtMsgIdentifier c73_thisId;
  c73_thisId.fIdentifier = c73_identifier;
  c73_thisId.fParent = NULL;
  c73_b_y = c73_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c73_y), &c73_thisId);
  sf_mex_destroy(&c73_y);
  return c73_b_y;
}

static real_T c73_b_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId)
{
  real_T c73_y;
  real_T c73_d0;
  (void)chartInstance;
  sf_mex_import(c73_parentId, sf_mex_dup(c73_u), &c73_d0, 1, 0, 0U, 0, 0U, 0);
  c73_y = c73_d0;
  sf_mex_destroy(&c73_u);
  return c73_y;
}

static void c73_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c73_mxArrayInData, const char_T *c73_varName, void *c73_outData)
{
  const mxArray *c73_y;
  const char_T *c73_identifier;
  emlrtMsgIdentifier c73_thisId;
  real_T c73_b_y;
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c73_y = sf_mex_dup(c73_mxArrayInData);
  c73_identifier = c73_varName;
  c73_thisId.fIdentifier = c73_identifier;
  c73_thisId.fParent = NULL;
  c73_b_y = c73_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c73_y), &c73_thisId);
  sf_mex_destroy(&c73_y);
  *(real_T *)c73_outData = c73_b_y;
  sf_mex_destroy(&c73_mxArrayInData);
}

static const mxArray *c73_b_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData)
{
  const mxArray *c73_mxArrayOutData = NULL;
  int32_T c73_i4;
  real_T c73_b_inData[2];
  int32_T c73_i5;
  real_T c73_u[2];
  const mxArray *c73_y = NULL;
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c73_mxArrayOutData = NULL;
  for (c73_i4 = 0; c73_i4 < 2; c73_i4++) {
    c73_b_inData[c73_i4] = (*(real_T (*)[2])c73_inData)[c73_i4];
  }

  for (c73_i5 = 0; c73_i5 < 2; c73_i5++) {
    c73_u[c73_i5] = c73_b_inData[c73_i5];
  }

  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_create("y", c73_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c73_mxArrayOutData, c73_y, false);
  return c73_mxArrayOutData;
}

const mxArray
  *sf_c73_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info(void)
{
  const mxArray *c73_nameCaptureInfo = NULL;
  c73_nameCaptureInfo = NULL;
  sf_mex_assign(&c73_nameCaptureInfo, sf_mex_createstruct("structure", 2, 22, 1),
                false);
  c73_info_helper(&c73_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c73_nameCaptureInfo);
  return c73_nameCaptureInfo;
}

static void c73_info_helper(const mxArray **c73_info)
{
  const mxArray *c73_rhs0 = NULL;
  const mxArray *c73_lhs0 = NULL;
  const mxArray *c73_rhs1 = NULL;
  const mxArray *c73_lhs1 = NULL;
  const mxArray *c73_rhs2 = NULL;
  const mxArray *c73_lhs2 = NULL;
  const mxArray *c73_rhs3 = NULL;
  const mxArray *c73_lhs3 = NULL;
  const mxArray *c73_rhs4 = NULL;
  const mxArray *c73_lhs4 = NULL;
  const mxArray *c73_rhs5 = NULL;
  const mxArray *c73_lhs5 = NULL;
  const mxArray *c73_rhs6 = NULL;
  const mxArray *c73_lhs6 = NULL;
  const mxArray *c73_rhs7 = NULL;
  const mxArray *c73_lhs7 = NULL;
  const mxArray *c73_rhs8 = NULL;
  const mxArray *c73_lhs8 = NULL;
  const mxArray *c73_rhs9 = NULL;
  const mxArray *c73_lhs9 = NULL;
  const mxArray *c73_rhs10 = NULL;
  const mxArray *c73_lhs10 = NULL;
  const mxArray *c73_rhs11 = NULL;
  const mxArray *c73_lhs11 = NULL;
  const mxArray *c73_rhs12 = NULL;
  const mxArray *c73_lhs12 = NULL;
  const mxArray *c73_rhs13 = NULL;
  const mxArray *c73_lhs13 = NULL;
  const mxArray *c73_rhs14 = NULL;
  const mxArray *c73_lhs14 = NULL;
  const mxArray *c73_rhs15 = NULL;
  const mxArray *c73_lhs15 = NULL;
  const mxArray *c73_rhs16 = NULL;
  const mxArray *c73_lhs16 = NULL;
  const mxArray *c73_rhs17 = NULL;
  const mxArray *c73_lhs17 = NULL;
  const mxArray *c73_rhs18 = NULL;
  const mxArray *c73_lhs18 = NULL;
  const mxArray *c73_rhs19 = NULL;
  const mxArray *c73_lhs19 = NULL;
  const mxArray *c73_rhs20 = NULL;
  const mxArray *c73_lhs20 = NULL;
  const mxArray *c73_rhs21 = NULL;
  const mxArray *c73_lhs21 = NULL;
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("norm"), "name", "name", 0);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c73_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 1);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 1);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c73_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 2);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c73_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 3);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  3);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1375980692U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c73_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 4);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c73_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 5);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c73_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 6);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 6);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c73_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 7);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 7);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c73_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 8);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c73_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 9);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c73_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("realmin"), "name", "name",
                  10);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c73_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 11);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c73_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c73_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 13);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c73_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 14);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c73_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 15);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c73_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c73_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c73_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c73_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("abs"), "name", "name", 19);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c73_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c73_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 21);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c73_info, c73_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c73_info, c73_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c73_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c73_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c73_info, sf_mex_duplicatearraysafe(&c73_lhs21), "lhs", "lhs",
                  21);
  sf_mex_destroy(&c73_rhs0);
  sf_mex_destroy(&c73_lhs0);
  sf_mex_destroy(&c73_rhs1);
  sf_mex_destroy(&c73_lhs1);
  sf_mex_destroy(&c73_rhs2);
  sf_mex_destroy(&c73_lhs2);
  sf_mex_destroy(&c73_rhs3);
  sf_mex_destroy(&c73_lhs3);
  sf_mex_destroy(&c73_rhs4);
  sf_mex_destroy(&c73_lhs4);
  sf_mex_destroy(&c73_rhs5);
  sf_mex_destroy(&c73_lhs5);
  sf_mex_destroy(&c73_rhs6);
  sf_mex_destroy(&c73_lhs6);
  sf_mex_destroy(&c73_rhs7);
  sf_mex_destroy(&c73_lhs7);
  sf_mex_destroy(&c73_rhs8);
  sf_mex_destroy(&c73_lhs8);
  sf_mex_destroy(&c73_rhs9);
  sf_mex_destroy(&c73_lhs9);
  sf_mex_destroy(&c73_rhs10);
  sf_mex_destroy(&c73_lhs10);
  sf_mex_destroy(&c73_rhs11);
  sf_mex_destroy(&c73_lhs11);
  sf_mex_destroy(&c73_rhs12);
  sf_mex_destroy(&c73_lhs12);
  sf_mex_destroy(&c73_rhs13);
  sf_mex_destroy(&c73_lhs13);
  sf_mex_destroy(&c73_rhs14);
  sf_mex_destroy(&c73_lhs14);
  sf_mex_destroy(&c73_rhs15);
  sf_mex_destroy(&c73_lhs15);
  sf_mex_destroy(&c73_rhs16);
  sf_mex_destroy(&c73_lhs16);
  sf_mex_destroy(&c73_rhs17);
  sf_mex_destroy(&c73_lhs17);
  sf_mex_destroy(&c73_rhs18);
  sf_mex_destroy(&c73_lhs18);
  sf_mex_destroy(&c73_rhs19);
  sf_mex_destroy(&c73_lhs19);
  sf_mex_destroy(&c73_rhs20);
  sf_mex_destroy(&c73_lhs20);
  sf_mex_destroy(&c73_rhs21);
  sf_mex_destroy(&c73_lhs21);
}

static const mxArray *c73_emlrt_marshallOut(const char * c73_u)
{
  const mxArray *c73_y = NULL;
  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_create("y", c73_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c73_u)), false);
  return c73_y;
}

static const mxArray *c73_b_emlrt_marshallOut(const uint32_T c73_u)
{
  const mxArray *c73_y = NULL;
  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_create("y", &c73_u, 7, 0U, 0U, 0U, 0), false);
  return c73_y;
}

static real_T c73_eml_xnrm2
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, real_T
   c73_x[2])
{
  real_T c73_y;
  real_T c73_scale;
  int32_T c73_k;
  int32_T c73_b_k;
  real_T c73_b_x;
  real_T c73_c_x;
  real_T c73_absxk;
  real_T c73_t;
  (void)chartInstance;
  c73_y = 0.0;
  c73_scale = 2.2250738585072014E-308;
  for (c73_k = 1; c73_k < 3; c73_k++) {
    c73_b_k = c73_k;
    c73_b_x = c73_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c73_b_k), 1, 2, 1, 0) - 1];
    c73_c_x = c73_b_x;
    c73_absxk = muDoubleScalarAbs(c73_c_x);
    if (c73_absxk > c73_scale) {
      c73_t = c73_scale / c73_absxk;
      c73_y = 1.0 + c73_y * c73_t * c73_t;
      c73_scale = c73_absxk;
    } else {
      c73_t = c73_absxk / c73_scale;
      c73_y += c73_t * c73_t;
    }
  }

  return c73_scale * muDoubleScalarSqrt(c73_y);
}

static const mxArray *c73_c_sf_marshallOut(void *chartInstanceVoid, void
  *c73_inData)
{
  const mxArray *c73_mxArrayOutData = NULL;
  int32_T c73_u;
  const mxArray *c73_y = NULL;
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c73_mxArrayOutData = NULL;
  c73_u = *(int32_T *)c73_inData;
  c73_y = NULL;
  sf_mex_assign(&c73_y, sf_mex_create("y", &c73_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c73_mxArrayOutData, c73_y, false);
  return c73_mxArrayOutData;
}

static int32_T c73_c_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId)
{
  int32_T c73_y;
  int32_T c73_i6;
  (void)chartInstance;
  sf_mex_import(c73_parentId, sf_mex_dup(c73_u), &c73_i6, 1, 6, 0U, 0, 0U, 0);
  c73_y = c73_i6;
  sf_mex_destroy(&c73_u);
  return c73_y;
}

static void c73_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c73_mxArrayInData, const char_T *c73_varName, void *c73_outData)
{
  const mxArray *c73_b_sfEvent;
  const char_T *c73_identifier;
  emlrtMsgIdentifier c73_thisId;
  int32_T c73_y;
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c73_b_sfEvent = sf_mex_dup(c73_mxArrayInData);
  c73_identifier = c73_varName;
  c73_thisId.fIdentifier = c73_identifier;
  c73_thisId.fParent = NULL;
  c73_y = c73_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c73_b_sfEvent),
    &c73_thisId);
  sf_mex_destroy(&c73_b_sfEvent);
  *(int32_T *)c73_outData = c73_y;
  sf_mex_destroy(&c73_mxArrayInData);
}

static uint8_T c73_d_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_b_is_active_c73_ICARO3_orientation_controllo_BIPE, const char_T *
   c73_identifier)
{
  uint8_T c73_y;
  emlrtMsgIdentifier c73_thisId;
  c73_thisId.fIdentifier = c73_identifier;
  c73_thisId.fParent = NULL;
  c73_y = c73_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c73_b_is_active_c73_ICARO3_orientation_controllo_BIPE), &c73_thisId);
  sf_mex_destroy(&c73_b_is_active_c73_ICARO3_orientation_controllo_BIPE);
  return c73_y;
}

static uint8_T c73_e_emlrt_marshallIn
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c73_u, const emlrtMsgIdentifier *c73_parentId)
{
  uint8_T c73_y;
  uint8_T c73_u0;
  (void)chartInstance;
  sf_mex_import(c73_parentId, sf_mex_dup(c73_u), &c73_u0, 1, 3, 0U, 0, 0U, 0);
  c73_y = c73_u0;
  sf_mex_destroy(&c73_u);
  return c73_y;
}

static void init_dsm_address_info
  (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
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

void sf_c73_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3429693403U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3469044459U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1779304983U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2143075045U);
}

mxArray *sf_c73_ICARO3_orientation_controllo_BIPE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HvbDTZvK6UoVsqSgPp3idE");
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

mxArray *sf_c73_ICARO3_orientation_controllo_BIPE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c73_ICARO3_orientation_controllo_BIPE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c73_ICARO3_orientation_controllo_BIPE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c73_ICARO3_orientation_controllo_BIPE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c73_ICARO3_orientation_controllo_BIPE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_orientation_controllo_BIPEMachineNumber_,
           73,
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
          (_ICARO3_orientation_controllo_BIPEMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_orientation_controllo_BIPEMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_orientation_controllo_BIPEMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,158);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c73_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c73_sf_marshallOut,(MexInFcnForType)c73_sf_marshallIn);

        {
          real_T *c73_y;
          real_T (*c73_u)[2];
          c73_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c73_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c73_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c73_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_orientation_controllo_BIPEMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "LBxY3dqaQCQxQvNXUHagEF";
}

static void sf_opaque_initialize_c73_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
  initialize_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c73_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  enable_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c73_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  disable_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c73_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  sf_gateway_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c73_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c73_ICARO3_orientation_controllo_BIPE();/* state var info */
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

extern void sf_internal_set_sim_state_c73_ICARO3_orientation_controllo_BIPE
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
    sf_get_sim_state_info_c73_ICARO3_orientation_controllo_BIPE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c73_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  return sf_internal_get_sim_state_c73_ICARO3_orientation_controllo_BIPE(S);
}

static void sf_opaque_set_sim_state_c73_ICARO3_orientation_controllo_BIPE
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c73_ICARO3_orientation_controllo_BIPE(S, st);
}

static void sf_opaque_terminate_c73_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_orientation_controllo_BIPE_optimization_info();
    }

    finalize_c73_ICARO3_orientation_controllo_BIPE
      ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc73_ICARO3_orientation_controllo_BIPE
    ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c73_ICARO3_orientation_controllo_BIPE(SimStruct
  *S)
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
    initialize_params_c73_ICARO3_orientation_controllo_BIPE
      ((SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c73_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_orientation_controllo_BIPE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      73);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,73,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,73,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,73);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,73,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,73,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,73);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2716820020U));
  ssSetChecksum1(S,(1500347370U));
  ssSetChecksum2(S,(749644131U));
  ssSetChecksum3(S,(3745976376U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c73_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c73_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    utMalloc(sizeof(SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc73_ICARO3_orientation_controllo_BIPEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c73_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c73_ICARO3_orientation_controllo_BIPE;
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

void c73_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c73_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c73_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c73_ICARO3_orientation_controllo_BIPE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c73_ICARO3_orientation_controllo_BIPE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
