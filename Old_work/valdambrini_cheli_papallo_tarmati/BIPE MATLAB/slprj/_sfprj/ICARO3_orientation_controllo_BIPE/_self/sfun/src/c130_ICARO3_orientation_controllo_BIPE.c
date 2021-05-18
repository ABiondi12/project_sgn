/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_orientation_controllo_BIPE_sfun.h"
#include "c130_ICARO3_orientation_controllo_BIPE.h"
#include <string.h>
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
static const char * c130_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initialize_params_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void enable_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void disable_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c130_update_debugger_state_c130_ICARO3_orientation_controllo_BIP
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void set_sim_state_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_st);
static void finalize_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void sf_gateway_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initSimStructsc130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c130_machineNumber, uint32_T
  c130_chartNumber, uint32_T c130_instanceNumber);
static const mxArray *c130_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData);
static real32_T c130_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_y, const char_T *c130_identifier);
static real32_T c130_b_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId);
static void c130_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData);
static const mxArray *c130_b_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData);
static const mxArray *c130_c_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData);
static real_T c130_c_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId);
static void c130_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData);
static void c130_info_helper(const mxArray **c130_info);
static const mxArray *c130_emlrt_marshallOut(const char * c130_u);
static const mxArray *c130_b_emlrt_marshallOut(const uint32_T c130_u);
static const mxArray *c130_d_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData);
static int32_T c130_d_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId);
static void c130_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData);
static uint8_T c130_e_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_b_is_active_c130_ICARO3_orientation_controllo_BIPE, const
   char_T *c130_identifier);
static uint8_T c130_f_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId);
static void init_dsm_address_info
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  chartInstance->c130_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c130_is_active_c130_ICARO3_orientation_controllo_BIPE = 0U;
}

static void initialize_params_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c130_update_debugger_state_c130_ICARO3_orientation_controllo_BIP
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  const mxArray *c130_st;
  const mxArray *c130_y = NULL;
  real32_T c130_hoistedGlobal;
  real32_T c130_u;
  const mxArray *c130_b_y = NULL;
  uint8_T c130_b_hoistedGlobal;
  uint8_T c130_b_u;
  const mxArray *c130_c_y = NULL;
  real32_T *c130_d_y;
  c130_d_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c130_st = NULL;
  c130_st = NULL;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_createcellmatrix(2, 1), false);
  c130_hoistedGlobal = *c130_d_y;
  c130_u = c130_hoistedGlobal;
  c130_b_y = NULL;
  sf_mex_assign(&c130_b_y, sf_mex_create("y", &c130_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c130_y, 0, c130_b_y);
  c130_b_hoistedGlobal =
    chartInstance->c130_is_active_c130_ICARO3_orientation_controllo_BIPE;
  c130_b_u = c130_b_hoistedGlobal;
  c130_c_y = NULL;
  sf_mex_assign(&c130_c_y, sf_mex_create("y", &c130_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c130_y, 1, c130_c_y);
  sf_mex_assign(&c130_st, c130_y, false);
  return c130_st;
}

static void set_sim_state_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_st)
{
  const mxArray *c130_u;
  real32_T *c130_y;
  c130_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c130_doneDoubleBufferReInit = true;
  c130_u = sf_mex_dup(c130_st);
  *c130_y = c130_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c130_u, 0)), "y");
  chartInstance->c130_is_active_c130_ICARO3_orientation_controllo_BIPE =
    c130_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c130_u, 1)),
    "is_active_c130_ICARO3_orientation_controllo_BIPE");
  sf_mex_destroy(&c130_u);
  c130_update_debugger_state_c130_ICARO3_orientation_controllo_BIP(chartInstance);
  sf_mex_destroy(&c130_st);
}

static void finalize_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  uint32_T c130_hoistedGlobal;
  uint32_T c130_u;
  uint32_T c130_debug_family_var_map[4];
  real_T c130_nargin = 1.0;
  real_T c130_nargout = 1.0;
  real32_T c130_y;
  uint32_T c130_x;
  uint32_T *c130_b_u;
  real32_T *c130_b_y;
  c130_b_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c130_b_u = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 30U, chartInstance->c130_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c130_b_u, 0U);
  chartInstance->c130_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 30U, chartInstance->c130_sfEvent);
  c130_hoistedGlobal = *c130_b_u;
  c130_u = c130_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c130_debug_family_names,
    c130_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c130_nargin, 0U, c130_c_sf_marshallOut,
    c130_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c130_nargout, 1U, c130_c_sf_marshallOut,
    c130_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c130_u, 2U, c130_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c130_y, 3U, c130_sf_marshallOut,
    c130_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c130_sfEvent, 4);
  c130_x = c130_u;
  memcpy(&c130_y, &c130_x, 4U);
  _SFD_EML_CALL(0U, chartInstance->c130_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *c130_b_y = c130_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c130_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_orientation_controllo_BIPEMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c130_b_y, 1U);
}

static void initSimStructsc130_ICARO3_orientation_controllo_BIPE
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c130_machineNumber, uint32_T
  c130_chartNumber, uint32_T c130_instanceNumber)
{
  (void)c130_machineNumber;
  (void)c130_chartNumber;
  (void)c130_instanceNumber;
}

static const mxArray *c130_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData)
{
  const mxArray *c130_mxArrayOutData = NULL;
  real32_T c130_u;
  const mxArray *c130_y = NULL;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_mxArrayOutData = NULL;
  c130_u = *(real32_T *)c130_inData;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", &c130_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c130_mxArrayOutData, c130_y, false);
  return c130_mxArrayOutData;
}

static real32_T c130_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_y, const char_T *c130_identifier)
{
  real32_T c130_b_y;
  emlrtMsgIdentifier c130_thisId;
  c130_thisId.fIdentifier = c130_identifier;
  c130_thisId.fParent = NULL;
  c130_b_y = c130_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c130_y),
    &c130_thisId);
  sf_mex_destroy(&c130_y);
  return c130_b_y;
}

static real32_T c130_b_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId)
{
  real32_T c130_y;
  real32_T c130_f0;
  (void)chartInstance;
  sf_mex_import(c130_parentId, sf_mex_dup(c130_u), &c130_f0, 1, 1, 0U, 0, 0U, 0);
  c130_y = c130_f0;
  sf_mex_destroy(&c130_u);
  return c130_y;
}

static void c130_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData)
{
  const mxArray *c130_y;
  const char_T *c130_identifier;
  emlrtMsgIdentifier c130_thisId;
  real32_T c130_b_y;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_y = sf_mex_dup(c130_mxArrayInData);
  c130_identifier = c130_varName;
  c130_thisId.fIdentifier = c130_identifier;
  c130_thisId.fParent = NULL;
  c130_b_y = c130_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c130_y),
    &c130_thisId);
  sf_mex_destroy(&c130_y);
  *(real32_T *)c130_outData = c130_b_y;
  sf_mex_destroy(&c130_mxArrayInData);
}

static const mxArray *c130_b_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData)
{
  const mxArray *c130_mxArrayOutData = NULL;
  uint32_T c130_u;
  const mxArray *c130_y = NULL;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_mxArrayOutData = NULL;
  c130_u = *(uint32_T *)c130_inData;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", &c130_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c130_mxArrayOutData, c130_y, false);
  return c130_mxArrayOutData;
}

static const mxArray *c130_c_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData)
{
  const mxArray *c130_mxArrayOutData = NULL;
  real_T c130_u;
  const mxArray *c130_y = NULL;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_mxArrayOutData = NULL;
  c130_u = *(real_T *)c130_inData;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", &c130_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c130_mxArrayOutData, c130_y, false);
  return c130_mxArrayOutData;
}

static real_T c130_c_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId)
{
  real_T c130_y;
  real_T c130_d0;
  (void)chartInstance;
  sf_mex_import(c130_parentId, sf_mex_dup(c130_u), &c130_d0, 1, 0, 0U, 0, 0U, 0);
  c130_y = c130_d0;
  sf_mex_destroy(&c130_u);
  return c130_y;
}

static void c130_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData)
{
  const mxArray *c130_nargout;
  const char_T *c130_identifier;
  emlrtMsgIdentifier c130_thisId;
  real_T c130_y;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_nargout = sf_mex_dup(c130_mxArrayInData);
  c130_identifier = c130_varName;
  c130_thisId.fIdentifier = c130_identifier;
  c130_thisId.fParent = NULL;
  c130_y = c130_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c130_nargout),
    &c130_thisId);
  sf_mex_destroy(&c130_nargout);
  *(real_T *)c130_outData = c130_y;
  sf_mex_destroy(&c130_mxArrayInData);
}

const mxArray
  *sf_c130_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c130_nameCaptureInfo = NULL;
  c130_nameCaptureInfo = NULL;
  sf_mex_assign(&c130_nameCaptureInfo, sf_mex_createstruct("structure", 2, 51, 1),
                false);
  c130_info_helper(&c130_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c130_nameCaptureInfo);
  return c130_nameCaptureInfo;
}

static void c130_info_helper(const mxArray **c130_info)
{
  const mxArray *c130_rhs0 = NULL;
  const mxArray *c130_lhs0 = NULL;
  const mxArray *c130_rhs1 = NULL;
  const mxArray *c130_lhs1 = NULL;
  const mxArray *c130_rhs2 = NULL;
  const mxArray *c130_lhs2 = NULL;
  const mxArray *c130_rhs3 = NULL;
  const mxArray *c130_lhs3 = NULL;
  const mxArray *c130_rhs4 = NULL;
  const mxArray *c130_lhs4 = NULL;
  const mxArray *c130_rhs5 = NULL;
  const mxArray *c130_lhs5 = NULL;
  const mxArray *c130_rhs6 = NULL;
  const mxArray *c130_lhs6 = NULL;
  const mxArray *c130_rhs7 = NULL;
  const mxArray *c130_lhs7 = NULL;
  const mxArray *c130_rhs8 = NULL;
  const mxArray *c130_lhs8 = NULL;
  const mxArray *c130_rhs9 = NULL;
  const mxArray *c130_lhs9 = NULL;
  const mxArray *c130_rhs10 = NULL;
  const mxArray *c130_lhs10 = NULL;
  const mxArray *c130_rhs11 = NULL;
  const mxArray *c130_lhs11 = NULL;
  const mxArray *c130_rhs12 = NULL;
  const mxArray *c130_lhs12 = NULL;
  const mxArray *c130_rhs13 = NULL;
  const mxArray *c130_lhs13 = NULL;
  const mxArray *c130_rhs14 = NULL;
  const mxArray *c130_lhs14 = NULL;
  const mxArray *c130_rhs15 = NULL;
  const mxArray *c130_lhs15 = NULL;
  const mxArray *c130_rhs16 = NULL;
  const mxArray *c130_lhs16 = NULL;
  const mxArray *c130_rhs17 = NULL;
  const mxArray *c130_lhs17 = NULL;
  const mxArray *c130_rhs18 = NULL;
  const mxArray *c130_lhs18 = NULL;
  const mxArray *c130_rhs19 = NULL;
  const mxArray *c130_lhs19 = NULL;
  const mxArray *c130_rhs20 = NULL;
  const mxArray *c130_lhs20 = NULL;
  const mxArray *c130_rhs21 = NULL;
  const mxArray *c130_lhs21 = NULL;
  const mxArray *c130_rhs22 = NULL;
  const mxArray *c130_lhs22 = NULL;
  const mxArray *c130_rhs23 = NULL;
  const mxArray *c130_lhs23 = NULL;
  const mxArray *c130_rhs24 = NULL;
  const mxArray *c130_lhs24 = NULL;
  const mxArray *c130_rhs25 = NULL;
  const mxArray *c130_lhs25 = NULL;
  const mxArray *c130_rhs26 = NULL;
  const mxArray *c130_lhs26 = NULL;
  const mxArray *c130_rhs27 = NULL;
  const mxArray *c130_lhs27 = NULL;
  const mxArray *c130_rhs28 = NULL;
  const mxArray *c130_lhs28 = NULL;
  const mxArray *c130_rhs29 = NULL;
  const mxArray *c130_lhs29 = NULL;
  const mxArray *c130_rhs30 = NULL;
  const mxArray *c130_lhs30 = NULL;
  const mxArray *c130_rhs31 = NULL;
  const mxArray *c130_lhs31 = NULL;
  const mxArray *c130_rhs32 = NULL;
  const mxArray *c130_lhs32 = NULL;
  const mxArray *c130_rhs33 = NULL;
  const mxArray *c130_lhs33 = NULL;
  const mxArray *c130_rhs34 = NULL;
  const mxArray *c130_lhs34 = NULL;
  const mxArray *c130_rhs35 = NULL;
  const mxArray *c130_lhs35 = NULL;
  const mxArray *c130_rhs36 = NULL;
  const mxArray *c130_lhs36 = NULL;
  const mxArray *c130_rhs37 = NULL;
  const mxArray *c130_lhs37 = NULL;
  const mxArray *c130_rhs38 = NULL;
  const mxArray *c130_lhs38 = NULL;
  const mxArray *c130_rhs39 = NULL;
  const mxArray *c130_lhs39 = NULL;
  const mxArray *c130_rhs40 = NULL;
  const mxArray *c130_lhs40 = NULL;
  const mxArray *c130_rhs41 = NULL;
  const mxArray *c130_lhs41 = NULL;
  const mxArray *c130_rhs42 = NULL;
  const mxArray *c130_lhs42 = NULL;
  const mxArray *c130_rhs43 = NULL;
  const mxArray *c130_lhs43 = NULL;
  const mxArray *c130_rhs44 = NULL;
  const mxArray *c130_lhs44 = NULL;
  const mxArray *c130_rhs45 = NULL;
  const mxArray *c130_lhs45 = NULL;
  const mxArray *c130_rhs46 = NULL;
  const mxArray *c130_lhs46 = NULL;
  const mxArray *c130_rhs47 = NULL;
  const mxArray *c130_lhs47 = NULL;
  const mxArray *c130_rhs48 = NULL;
  const mxArray *c130_lhs48 = NULL;
  const mxArray *c130_rhs49 = NULL;
  const mxArray *c130_lhs49 = NULL;
  const mxArray *c130_rhs50 = NULL;
  const mxArray *c130_lhs50 = NULL;
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("typecast"), "name", "name",
                  0);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1370652830U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c130_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c130_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 2);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 2);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c130_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 3);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 3);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c130_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 4);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c130_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 5);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_rdivide"),
                  "name", "name", 5);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c130_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.indexDivide"), "name", "name", 6);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c130_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("deblank"), "name", "name",
                  7);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1331304888U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c130_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("ismatrix"), "name", "name",
                  8);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1331304858U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c130_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m!allwspace"),
                  "context", "context", 9);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("isstrprop"), "name",
                  "name", 9);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1375980694U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c130_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 10);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "eml_assert_supported_string"), "name", "name", 10);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1327419110U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c130_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 11);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 11);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1327419110U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c130_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmax"), "name", "name",
                  12);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c130_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs12), "rhs",
                  "rhs", 12);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs12), "lhs",
                  "lhs", 12);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 13);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c130_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs13), "rhs",
                  "rhs", 13);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs13), "lhs",
                  "lhs", 13);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 14);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1327419110U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c130_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs14), "rhs",
                  "rhs", 14);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs14), "lhs",
                  "lhs", 14);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 15);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 15);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1327419110U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c130_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs15), "rhs",
                  "rhs", 15);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs15), "lhs",
                  "lhs", 15);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 16);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("colon"), "name", "name",
                  16);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1378295988U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c130_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs16), "rhs",
                  "rhs", 16);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs16), "lhs",
                  "lhs", 16);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("colon"), "name", "name",
                  17);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1378295988U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c130_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs17), "rhs",
                  "rhs", 17);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs17), "lhs",
                  "lhs", 17);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 18);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c130_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs18), "rhs",
                  "rhs", 18);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs18), "lhs",
                  "lhs", 18);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 19);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c130_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs19), "rhs",
                  "rhs", 19);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs19), "lhs",
                  "lhs", 19);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("floor"), "name", "name",
                  20);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1363713854U),
                  "fileTimeLo", "fileTimeLo", 20);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c130_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs20), "rhs",
                  "rhs", 20);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs20), "lhs",
                  "lhs", 20);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 21);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c130_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs21), "rhs",
                  "rhs", 21);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs21), "lhs",
                  "lhs", 21);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 22);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1286818726U),
                  "fileTimeLo", "fileTimeLo", 22);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c130_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs22), "rhs",
                  "rhs", 22);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs22), "lhs",
                  "lhs", 22);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 23);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmin"), "name", "name",
                  23);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 23);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c130_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs23), "rhs",
                  "rhs", 23);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs23), "lhs",
                  "lhs", 23);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 24);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 24);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c130_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs24), "rhs",
                  "rhs", 24);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs24), "lhs",
                  "lhs", 24);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 25);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmax"), "name", "name",
                  25);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 25);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c130_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs25), "rhs",
                  "rhs", 25);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs25), "lhs",
                  "lhs", 25);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 26);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmin"), "name", "name",
                  26);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 26);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c130_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs26), "rhs",
                  "rhs", 26);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs26), "lhs",
                  "lhs", 26);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 27);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmax"), "name", "name",
                  27);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 27);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c130_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs27), "rhs",
                  "rhs", 27);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs27), "lhs",
                  "lhs", 27);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 28);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 28);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 28);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c130_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs28), "rhs",
                  "rhs", 28);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs28), "lhs",
                  "lhs", 28);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 29);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 29);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c130_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs29), "rhs",
                  "rhs", 29);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs29), "lhs",
                  "lhs", 29);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 30);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_unsigned_class"),
                  "name", "name", 30);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 30);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c130_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs30), "rhs",
                  "rhs", 30);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs30), "lhs",
                  "lhs", 30);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 31);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1389307922U),
                  "fileTimeLo", "fileTimeLo", 31);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c130_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs31), "rhs",
                  "rhs", 31);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs31), "lhs",
                  "lhs", 31);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 32);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 32);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 32);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c130_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs32), "rhs",
                  "rhs", 32);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs32), "lhs",
                  "lhs", 32);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 33);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 33);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c130_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs33), "rhs",
                  "rhs", 33);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs33), "lhs",
                  "lhs", 33);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 34);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmax"), "name", "name",
                  34);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 34);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c130_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs34), "rhs",
                  "rhs", 34);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs34), "lhs",
                  "lhs", 34);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 35);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 35);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 35);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c130_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs35), "rhs",
                  "rhs", 35);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs35), "lhs",
                  "lhs", 35);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 36);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 36);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 36);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c130_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs36), "rhs",
                  "rhs", 36);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs36), "lhs",
                  "lhs", 36);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 37);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 37);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c130_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs37), "rhs",
                  "rhs", 37);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs37), "lhs",
                  "lhs", 37);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 38);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 38);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 38);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c130_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs38), "rhs",
                  "rhs", 38);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs38), "lhs",
                  "lhs", 38);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 39);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("intmax"), "name", "name",
                  39);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1362261882U),
                  "fileTimeLo", "fileTimeLo", 39);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c130_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs39), "rhs",
                  "rhs", 39);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs39), "lhs",
                  "lhs", 39);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 40);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "name", "name", 40);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1319729968U),
                  "fileTimeLo", "fileTimeLo", 40);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c130_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs40), "rhs",
                  "rhs", 40);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs40), "lhs",
                  "lhs", 40);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 41);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_float_nbits"), "name",
                  "name", 41);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_nbits.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1307651242U),
                  "fileTimeLo", "fileTimeLo", 41);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c130_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs41), "rhs",
                  "rhs", 41);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs41), "lhs",
                  "lhs", 41);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_nbits.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 42);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1326727996U),
                  "fileTimeLo", "fileTimeLo", 42);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c130_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs42), "rhs",
                  "rhs", 42);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs42), "lhs",
                  "lhs", 42);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 43);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_rdivide"),
                  "name", "name", 43);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 43);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c130_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs43), "rhs",
                  "rhs", 43);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs43), "lhs",
                  "lhs", 43);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.indexDivide"), "name", "name", 44);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 44);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c130_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs44), "rhs",
                  "rhs", 44);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs44), "lhs",
                  "lhs", 44);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 45);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 45);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c130_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs45), "rhs",
                  "rhs", 45);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs45), "lhs",
                  "lhs", 45);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 46);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 46);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c130_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs46), "rhs",
                  "rhs", 46);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs46), "lhs",
                  "lhs", 46);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_rdivide"),
                  "name", "name", 47);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 47);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c130_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs47), "rhs",
                  "rhs", 47);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs47), "lhs",
                  "lhs", 47);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "coder.internal.indexDivide"), "name", "name", 48);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 48);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c130_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs48), "rhs",
                  "rhs", 48);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs48), "lhs",
                  "lhs", 48);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 49);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372582416U),
                  "fileTimeLo", "fileTimeLo", 49);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c130_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs49), "rhs",
                  "rhs", 49);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs49), "lhs",
                  "lhs", 49);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 50);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c130_info, c130_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(1372583160U),
                  "fileTimeLo", "fileTimeLo", 50);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c130_info, c130_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c130_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c130_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_rhs50), "rhs",
                  "rhs", 50);
  sf_mex_addfield(*c130_info, sf_mex_duplicatearraysafe(&c130_lhs50), "lhs",
                  "lhs", 50);
  sf_mex_destroy(&c130_rhs0);
  sf_mex_destroy(&c130_lhs0);
  sf_mex_destroy(&c130_rhs1);
  sf_mex_destroy(&c130_lhs1);
  sf_mex_destroy(&c130_rhs2);
  sf_mex_destroy(&c130_lhs2);
  sf_mex_destroy(&c130_rhs3);
  sf_mex_destroy(&c130_lhs3);
  sf_mex_destroy(&c130_rhs4);
  sf_mex_destroy(&c130_lhs4);
  sf_mex_destroy(&c130_rhs5);
  sf_mex_destroy(&c130_lhs5);
  sf_mex_destroy(&c130_rhs6);
  sf_mex_destroy(&c130_lhs6);
  sf_mex_destroy(&c130_rhs7);
  sf_mex_destroy(&c130_lhs7);
  sf_mex_destroy(&c130_rhs8);
  sf_mex_destroy(&c130_lhs8);
  sf_mex_destroy(&c130_rhs9);
  sf_mex_destroy(&c130_lhs9);
  sf_mex_destroy(&c130_rhs10);
  sf_mex_destroy(&c130_lhs10);
  sf_mex_destroy(&c130_rhs11);
  sf_mex_destroy(&c130_lhs11);
  sf_mex_destroy(&c130_rhs12);
  sf_mex_destroy(&c130_lhs12);
  sf_mex_destroy(&c130_rhs13);
  sf_mex_destroy(&c130_lhs13);
  sf_mex_destroy(&c130_rhs14);
  sf_mex_destroy(&c130_lhs14);
  sf_mex_destroy(&c130_rhs15);
  sf_mex_destroy(&c130_lhs15);
  sf_mex_destroy(&c130_rhs16);
  sf_mex_destroy(&c130_lhs16);
  sf_mex_destroy(&c130_rhs17);
  sf_mex_destroy(&c130_lhs17);
  sf_mex_destroy(&c130_rhs18);
  sf_mex_destroy(&c130_lhs18);
  sf_mex_destroy(&c130_rhs19);
  sf_mex_destroy(&c130_lhs19);
  sf_mex_destroy(&c130_rhs20);
  sf_mex_destroy(&c130_lhs20);
  sf_mex_destroy(&c130_rhs21);
  sf_mex_destroy(&c130_lhs21);
  sf_mex_destroy(&c130_rhs22);
  sf_mex_destroy(&c130_lhs22);
  sf_mex_destroy(&c130_rhs23);
  sf_mex_destroy(&c130_lhs23);
  sf_mex_destroy(&c130_rhs24);
  sf_mex_destroy(&c130_lhs24);
  sf_mex_destroy(&c130_rhs25);
  sf_mex_destroy(&c130_lhs25);
  sf_mex_destroy(&c130_rhs26);
  sf_mex_destroy(&c130_lhs26);
  sf_mex_destroy(&c130_rhs27);
  sf_mex_destroy(&c130_lhs27);
  sf_mex_destroy(&c130_rhs28);
  sf_mex_destroy(&c130_lhs28);
  sf_mex_destroy(&c130_rhs29);
  sf_mex_destroy(&c130_lhs29);
  sf_mex_destroy(&c130_rhs30);
  sf_mex_destroy(&c130_lhs30);
  sf_mex_destroy(&c130_rhs31);
  sf_mex_destroy(&c130_lhs31);
  sf_mex_destroy(&c130_rhs32);
  sf_mex_destroy(&c130_lhs32);
  sf_mex_destroy(&c130_rhs33);
  sf_mex_destroy(&c130_lhs33);
  sf_mex_destroy(&c130_rhs34);
  sf_mex_destroy(&c130_lhs34);
  sf_mex_destroy(&c130_rhs35);
  sf_mex_destroy(&c130_lhs35);
  sf_mex_destroy(&c130_rhs36);
  sf_mex_destroy(&c130_lhs36);
  sf_mex_destroy(&c130_rhs37);
  sf_mex_destroy(&c130_lhs37);
  sf_mex_destroy(&c130_rhs38);
  sf_mex_destroy(&c130_lhs38);
  sf_mex_destroy(&c130_rhs39);
  sf_mex_destroy(&c130_lhs39);
  sf_mex_destroy(&c130_rhs40);
  sf_mex_destroy(&c130_lhs40);
  sf_mex_destroy(&c130_rhs41);
  sf_mex_destroy(&c130_lhs41);
  sf_mex_destroy(&c130_rhs42);
  sf_mex_destroy(&c130_lhs42);
  sf_mex_destroy(&c130_rhs43);
  sf_mex_destroy(&c130_lhs43);
  sf_mex_destroy(&c130_rhs44);
  sf_mex_destroy(&c130_lhs44);
  sf_mex_destroy(&c130_rhs45);
  sf_mex_destroy(&c130_lhs45);
  sf_mex_destroy(&c130_rhs46);
  sf_mex_destroy(&c130_lhs46);
  sf_mex_destroy(&c130_rhs47);
  sf_mex_destroy(&c130_lhs47);
  sf_mex_destroy(&c130_rhs48);
  sf_mex_destroy(&c130_lhs48);
  sf_mex_destroy(&c130_rhs49);
  sf_mex_destroy(&c130_lhs49);
  sf_mex_destroy(&c130_rhs50);
  sf_mex_destroy(&c130_lhs50);
}

static const mxArray *c130_emlrt_marshallOut(const char * c130_u)
{
  const mxArray *c130_y = NULL;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", c130_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c130_u)), false);
  return c130_y;
}

static const mxArray *c130_b_emlrt_marshallOut(const uint32_T c130_u)
{
  const mxArray *c130_y = NULL;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", &c130_u, 7, 0U, 0U, 0U, 0), false);
  return c130_y;
}

static const mxArray *c130_d_sf_marshallOut(void *chartInstanceVoid, void
  *c130_inData)
{
  const mxArray *c130_mxArrayOutData = NULL;
  int32_T c130_u;
  const mxArray *c130_y = NULL;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_mxArrayOutData = NULL;
  c130_u = *(int32_T *)c130_inData;
  c130_y = NULL;
  sf_mex_assign(&c130_y, sf_mex_create("y", &c130_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c130_mxArrayOutData, c130_y, false);
  return c130_mxArrayOutData;
}

static int32_T c130_d_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId)
{
  int32_T c130_y;
  int32_T c130_i0;
  (void)chartInstance;
  sf_mex_import(c130_parentId, sf_mex_dup(c130_u), &c130_i0, 1, 6, 0U, 0, 0U, 0);
  c130_y = c130_i0;
  sf_mex_destroy(&c130_u);
  return c130_y;
}

static void c130_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c130_mxArrayInData, const char_T *c130_varName, void *c130_outData)
{
  const mxArray *c130_b_sfEvent;
  const char_T *c130_identifier;
  emlrtMsgIdentifier c130_thisId;
  int32_T c130_y;
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c130_b_sfEvent = sf_mex_dup(c130_mxArrayInData);
  c130_identifier = c130_varName;
  c130_thisId.fIdentifier = c130_identifier;
  c130_thisId.fParent = NULL;
  c130_y = c130_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c130_b_sfEvent),
    &c130_thisId);
  sf_mex_destroy(&c130_b_sfEvent);
  *(int32_T *)c130_outData = c130_y;
  sf_mex_destroy(&c130_mxArrayInData);
}

static uint8_T c130_e_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_b_is_active_c130_ICARO3_orientation_controllo_BIPE, const
   char_T *c130_identifier)
{
  uint8_T c130_y;
  emlrtMsgIdentifier c130_thisId;
  c130_thisId.fIdentifier = c130_identifier;
  c130_thisId.fParent = NULL;
  c130_y = c130_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c130_b_is_active_c130_ICARO3_orientation_controllo_BIPE), &c130_thisId);
  sf_mex_destroy(&c130_b_is_active_c130_ICARO3_orientation_controllo_BIPE);
  return c130_y;
}

static uint8_T c130_f_emlrt_marshallIn
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c130_u, const emlrtMsgIdentifier *c130_parentId)
{
  uint8_T c130_y;
  uint8_T c130_u0;
  (void)chartInstance;
  sf_mex_import(c130_parentId, sf_mex_dup(c130_u), &c130_u0, 1, 3, 0U, 0, 0U, 0);
  c130_y = c130_u0;
  sf_mex_destroy(&c130_u);
  return c130_y;
}

static void init_dsm_address_info
  (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
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

void sf_c130_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3197488497U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3843586001U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(557611314U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2664098630U);
}

mxArray *sf_c130_ICARO3_orientation_controllo_BIPE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ktvHqBbqhH40zEmAtg0cdC");
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

mxArray *sf_c130_ICARO3_orientation_controllo_BIPE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c130_ICARO3_orientation_controllo_BIPE_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c130_ICARO3_orientation_controllo_BIPE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c130_ICARO3_orientation_controllo_BIPE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c130_ICARO3_orientation_controllo_BIPE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_orientation_controllo_BIPEMachineNumber_,
           130,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,70);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c130_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c130_sf_marshallOut,(MexInFcnForType)c130_sf_marshallIn);

        {
          uint32_T *c130_u;
          real32_T *c130_y;
          c130_y = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c130_u = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c130_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c130_y);
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
  return "t9iO4rfJdENQAK9g08k0OG";
}

static void sf_opaque_initialize_c130_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
  initialize_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c130_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  enable_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c130_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  disable_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c130_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  sf_gateway_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c130_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c130_ICARO3_orientation_controllo_BIPE();/* state var info */
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

extern void sf_internal_set_sim_state_c130_ICARO3_orientation_controllo_BIPE
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
    sf_get_sim_state_info_c130_ICARO3_orientation_controllo_BIPE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c130_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  return sf_internal_get_sim_state_c130_ICARO3_orientation_controllo_BIPE(S);
}

static void sf_opaque_set_sim_state_c130_ICARO3_orientation_controllo_BIPE
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c130_ICARO3_orientation_controllo_BIPE(S, st);
}

static void sf_opaque_terminate_c130_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_orientation_controllo_BIPE_optimization_info();
    }

    finalize_c130_ICARO3_orientation_controllo_BIPE
      ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*)
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
  initSimStructsc130_ICARO3_orientation_controllo_BIPE
    ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c130_ICARO3_orientation_controllo_BIPE
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
    initialize_params_c130_ICARO3_orientation_controllo_BIPE
      ((SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c130_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_orientation_controllo_BIPE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      130);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,130,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,130,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,130);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,130,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,130,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,130);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(732826177U));
  ssSetChecksum1(S,(574233083U));
  ssSetChecksum2(S,(1638863566U));
  ssSetChecksum3(S,(133206155U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c130_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c130_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    utMalloc(sizeof(SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc130_ICARO3_orientation_controllo_BIPEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c130_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c130_ICARO3_orientation_controllo_BIPE;
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

void c130_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c130_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c130_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c130_ICARO3_orientation_controllo_BIPE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c130_ICARO3_orientation_controllo_BIPE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
