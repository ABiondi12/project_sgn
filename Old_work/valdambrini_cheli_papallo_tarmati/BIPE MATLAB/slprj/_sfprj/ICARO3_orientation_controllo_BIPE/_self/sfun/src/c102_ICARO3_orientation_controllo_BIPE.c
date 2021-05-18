/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_orientation_controllo_BIPE_sfun.h"
#include "c102_ICARO3_orientation_controllo_BIPE.h"
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
static const char * c102_debug_family_names[15] = { "AC1", "AC2", "AC3", "AC4",
  "AC5", "AC6", "B1", "B2", "MB", "MC", "MD", "nargin", "nargout", "bytes",
  "params" };

static const char * c102_b_debug_family_names[4] = { "u", "nargin", "nargout",
  "y" };

/* Function Declarations */
static void initialize_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initialize_params_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void enable_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void disable_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c102_update_debugger_state_c102_ICARO3_orientation_controllo_BIP
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void set_sim_state_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_st);
static void finalize_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void sf_gateway_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c102_chartstep_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initSimStructsc102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c102_machineNumber, uint32_T
  c102_chartNumber, uint32_T c102_instanceNumber);
static const mxArray *c102_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static void c102_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_params, const char_T *c102_identifier, real32_T c102_y[11]);
static void c102_b_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId, real32_T c102_y[11]);
static void c102_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData);
static const mxArray *c102_b_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static const mxArray *c102_c_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static real_T c102_c_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId);
static void c102_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData);
static const mxArray *c102_d_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static real32_T c102_d_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId);
static void c102_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData);
static const mxArray *c102_e_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static uint16_T c102_e_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId);
static void c102_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData);
static void c102_info_helper(const mxArray **c102_info);
static const mxArray *c102_emlrt_marshallOut(const char * c102_u);
static const mxArray *c102_b_emlrt_marshallOut(const uint32_T c102_u);
static real32_T c102_decomp
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance,
   uint16_T c102_u);
static const mxArray *c102_f_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData);
static int32_T c102_f_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId);
static void c102_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData);
static uint8_T c102_g_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_b_is_active_c102_ICARO3_orientation_controllo_BIPE, const
   char_T *c102_identifier);
static uint8_T c102_h_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId);
static void init_dsm_address_info
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  chartInstance->c102_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c102_is_active_c102_ICARO3_orientation_controllo_BIPE = 0U;
}

static void initialize_params_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c102_update_debugger_state_c102_ICARO3_orientation_controllo_BIP
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  const mxArray *c102_st;
  const mxArray *c102_y = NULL;
  int32_T c102_i0;
  real32_T c102_u[11];
  const mxArray *c102_b_y = NULL;
  uint8_T c102_hoistedGlobal;
  uint8_T c102_b_u;
  const mxArray *c102_c_y = NULL;
  real32_T (*c102_params)[11];
  c102_params = (real32_T (*)[11])ssGetOutputPortSignal(chartInstance->S, 1);
  c102_st = NULL;
  c102_st = NULL;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_createcellmatrix(2, 1), false);
  for (c102_i0 = 0; c102_i0 < 11; c102_i0++) {
    c102_u[c102_i0] = (*c102_params)[c102_i0];
  }

  c102_b_y = NULL;
  sf_mex_assign(&c102_b_y, sf_mex_create("y", c102_u, 1, 0U, 1U, 0U, 2, 11, 1),
                false);
  sf_mex_setcell(c102_y, 0, c102_b_y);
  c102_hoistedGlobal =
    chartInstance->c102_is_active_c102_ICARO3_orientation_controllo_BIPE;
  c102_b_u = c102_hoistedGlobal;
  c102_c_y = NULL;
  sf_mex_assign(&c102_c_y, sf_mex_create("y", &c102_b_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c102_y, 1, c102_c_y);
  sf_mex_assign(&c102_st, c102_y, false);
  return c102_st;
}

static void set_sim_state_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_st)
{
  const mxArray *c102_u;
  real32_T c102_fv0[11];
  int32_T c102_i1;
  real32_T (*c102_params)[11];
  c102_params = (real32_T (*)[11])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c102_doneDoubleBufferReInit = true;
  c102_u = sf_mex_dup(c102_st);
  c102_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c102_u, 0)),
                        "params", c102_fv0);
  for (c102_i1 = 0; c102_i1 < 11; c102_i1++) {
    (*c102_params)[c102_i1] = c102_fv0[c102_i1];
  }

  chartInstance->c102_is_active_c102_ICARO3_orientation_controllo_BIPE =
    c102_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c102_u, 1)),
    "is_active_c102_ICARO3_orientation_controllo_BIPE");
  sf_mex_destroy(&c102_u);
  c102_update_debugger_state_c102_ICARO3_orientation_controllo_BIP(chartInstance);
  sf_mex_destroy(&c102_st);
}

static void finalize_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  int32_T c102_i2;
  int32_T c102_i3;
  real32_T (*c102_params)[11];
  uint16_T (*c102_bytes)[22];
  c102_params = (real32_T (*)[11])ssGetOutputPortSignal(chartInstance->S, 1);
  c102_bytes = (uint16_T (*)[22])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c102_sfEvent);
  for (c102_i2 = 0; c102_i2 < 22; c102_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c102_bytes)[c102_i2], 0U);
  }

  chartInstance->c102_sfEvent = CALL_EVENT;
  c102_chartstep_c102_ICARO3_orientation_controllo_BIPE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_orientation_controllo_BIPEMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c102_i3 = 0; c102_i3 < 11; c102_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c102_params)[c102_i3], 1U);
  }
}

static void c102_chartstep_c102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  int32_T c102_i4;
  uint16_T c102_bytes[22];
  uint32_T c102_debug_family_var_map[15];
  real32_T c102_AC1;
  real32_T c102_AC2;
  real32_T c102_AC3;
  real32_T c102_AC4;
  real32_T c102_AC5;
  real32_T c102_AC6;
  real32_T c102_B1;
  real32_T c102_B2;
  real32_T c102_MB;
  real32_T c102_MC;
  real32_T c102_MD;
  real_T c102_nargin = 1.0;
  real_T c102_nargout = 1.0;
  real32_T c102_params[11];
  uint16_T c102_a;
  uint16_T c102_a1;
  uint16_T c102_b_a;
  uint16_T c102_c;
  uint32_T c102_u0;
  uint16_T c102_c_a;
  uint16_T c102_b_a1;
  uint16_T c102_d_a;
  uint16_T c102_b_c;
  uint32_T c102_u1;
  uint16_T c102_e_a;
  uint16_T c102_c_a1;
  uint16_T c102_f_a;
  uint16_T c102_c_c;
  uint32_T c102_u2;
  uint16_T c102_g_a;
  uint16_T c102_d_a1;
  uint16_T c102_h_a;
  uint16_T c102_d_c;
  uint32_T c102_u3;
  uint16_T c102_i_a;
  uint16_T c102_e_a1;
  uint16_T c102_j_a;
  uint16_T c102_e_c;
  uint32_T c102_u4;
  uint16_T c102_k_a;
  uint16_T c102_f_a1;
  uint16_T c102_l_a;
  uint16_T c102_f_c;
  uint32_T c102_u5;
  uint16_T c102_m_a;
  uint16_T c102_g_a1;
  uint16_T c102_n_a;
  uint16_T c102_g_c;
  uint32_T c102_u6;
  uint16_T c102_o_a;
  uint16_T c102_h_a1;
  uint16_T c102_p_a;
  uint16_T c102_h_c;
  uint32_T c102_u7;
  uint16_T c102_q_a;
  uint16_T c102_i_a1;
  uint16_T c102_r_a;
  uint16_T c102_i_c;
  uint32_T c102_u8;
  uint16_T c102_s_a;
  uint16_T c102_j_a1;
  uint16_T c102_t_a;
  uint16_T c102_j_c;
  uint32_T c102_u9;
  uint16_T c102_u_a;
  uint16_T c102_k_a1;
  uint16_T c102_v_a;
  uint16_T c102_k_c;
  uint32_T c102_u10;
  int32_T c102_i5;
  real32_T (*c102_b_params)[11];
  uint16_T (*c102_b_bytes)[22];
  c102_b_params = (real32_T (*)[11])ssGetOutputPortSignal(chartInstance->S, 1);
  c102_b_bytes = (uint16_T (*)[22])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c102_sfEvent);
  for (c102_i4 = 0; c102_i4 < 22; c102_i4++) {
    c102_bytes[c102_i4] = (*c102_b_bytes)[c102_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c102_debug_family_names,
    c102_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC1, 0U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC2, 1U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC3, 2U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC4, 3U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC5, 4U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_AC6, 5U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_B1, 6U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_B2, 7U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_MB, 8U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_MC, 9U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_MD, 10U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_nargin, 11U, c102_c_sf_marshallOut,
    c102_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_nargout, 12U, c102_c_sf_marshallOut,
    c102_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c102_bytes, 13U, c102_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c102_params, 14U, c102_sf_marshallOut,
    c102_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 4);
  c102_a = c102_bytes[0];
  c102_a1 = c102_a;
  c102_b_a = c102_a1;
  c102_c = (uint16_T)(c102_b_a << 8);
  c102_u0 = (uint32_T)c102_c + (uint32_T)c102_bytes[1];
  if (CV_SATURATION_EVAL(4, 0, 10, 0, c102_u0 > 65535U)) {
    c102_u0 = 65535U;
  }

  c102_AC1 = c102_decomp(chartInstance, (uint16_T)c102_u0);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 5);
  c102_c_a = c102_bytes[2];
  c102_b_a1 = c102_c_a;
  c102_d_a = c102_b_a1;
  c102_b_c = (uint16_T)(c102_d_a << 8);
  c102_u1 = (uint32_T)c102_b_c + (uint32_T)c102_bytes[3];
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c102_u1 > 65535U)) {
    c102_u1 = 65535U;
  }

  c102_AC2 = c102_decomp(chartInstance, (uint16_T)c102_u1);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 6);
  c102_e_a = c102_bytes[4];
  c102_c_a1 = c102_e_a;
  c102_f_a = c102_c_a1;
  c102_c_c = (uint16_T)(c102_f_a << 8);
  c102_u2 = (uint32_T)c102_c_c + (uint32_T)c102_bytes[5];
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c102_u2 > 65535U)) {
    c102_u2 = 65535U;
  }

  c102_AC3 = c102_decomp(chartInstance, (uint16_T)c102_u2);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 8);
  c102_g_a = c102_bytes[6];
  c102_d_a1 = c102_g_a;
  c102_h_a = c102_d_a1;
  c102_d_c = (uint16_T)(c102_h_a << 8);
  c102_u3 = (uint32_T)c102_d_c + (uint32_T)c102_bytes[7];
  if (CV_SATURATION_EVAL(4, 0, 2, 0, c102_u3 > 65535U)) {
    c102_u3 = 65535U;
  }

  c102_AC4 = (real32_T)(uint16_T)c102_u3;
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 9);
  c102_i_a = c102_bytes[8];
  c102_e_a1 = c102_i_a;
  c102_j_a = c102_e_a1;
  c102_e_c = (uint16_T)(c102_j_a << 8);
  c102_u4 = (uint32_T)c102_e_c + (uint32_T)c102_bytes[9];
  if (CV_SATURATION_EVAL(4, 0, 3, 0, c102_u4 > 65535U)) {
    c102_u4 = 65535U;
  }

  c102_AC5 = (real32_T)(uint16_T)c102_u4;
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 10);
  c102_k_a = c102_bytes[10];
  c102_f_a1 = c102_k_a;
  c102_l_a = c102_f_a1;
  c102_f_c = (uint16_T)(c102_l_a << 8);
  c102_u5 = (uint32_T)c102_f_c + (uint32_T)c102_bytes[11];
  if (CV_SATURATION_EVAL(4, 0, 4, 0, c102_u5 > 65535U)) {
    c102_u5 = 65535U;
  }

  c102_AC6 = (real32_T)(uint16_T)c102_u5;
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 12);
  c102_m_a = c102_bytes[12];
  c102_g_a1 = c102_m_a;
  c102_n_a = c102_g_a1;
  c102_g_c = (uint16_T)(c102_n_a << 8);
  c102_u6 = (uint32_T)c102_g_c + (uint32_T)c102_bytes[13];
  if (CV_SATURATION_EVAL(4, 0, 5, 0, c102_u6 > 65535U)) {
    c102_u6 = 65535U;
  }

  c102_B1 = c102_decomp(chartInstance, (uint16_T)c102_u6);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 13);
  c102_o_a = c102_bytes[14];
  c102_h_a1 = c102_o_a;
  c102_p_a = c102_h_a1;
  c102_h_c = (uint16_T)(c102_p_a << 8);
  c102_u7 = (uint32_T)c102_h_c + (uint32_T)c102_bytes[15];
  if (CV_SATURATION_EVAL(4, 0, 6, 0, c102_u7 > 65535U)) {
    c102_u7 = 65535U;
  }

  c102_B2 = c102_decomp(chartInstance, (uint16_T)c102_u7);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 15);
  c102_q_a = c102_bytes[16];
  c102_i_a1 = c102_q_a;
  c102_r_a = c102_i_a1;
  c102_i_c = (uint16_T)(c102_r_a << 8);
  c102_u8 = (uint32_T)c102_i_c + (uint32_T)c102_bytes[17];
  if (CV_SATURATION_EVAL(4, 0, 7, 0, c102_u8 > 65535U)) {
    c102_u8 = 65535U;
  }

  c102_MB = c102_decomp(chartInstance, (uint16_T)c102_u8);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 16);
  c102_s_a = c102_bytes[18];
  c102_j_a1 = c102_s_a;
  c102_t_a = c102_j_a1;
  c102_j_c = (uint16_T)(c102_t_a << 8);
  c102_u9 = (uint32_T)c102_j_c + (uint32_T)c102_bytes[19];
  if (CV_SATURATION_EVAL(4, 0, 8, 0, c102_u9 > 65535U)) {
    c102_u9 = 65535U;
  }

  c102_MC = c102_decomp(chartInstance, (uint16_T)c102_u9);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 17);
  c102_u_a = c102_bytes[20];
  c102_k_a1 = c102_u_a;
  c102_v_a = c102_k_a1;
  c102_k_c = (uint16_T)(c102_v_a << 8);
  c102_u10 = (uint32_T)c102_k_c + (uint32_T)c102_bytes[21];
  if (CV_SATURATION_EVAL(4, 0, 9, 0, c102_u10 > 65535U)) {
    c102_u10 = 65535U;
  }

  c102_MD = c102_decomp(chartInstance, (uint16_T)c102_u10);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 19);
  c102_params[0] = c102_AC1;
  c102_params[1] = c102_AC2;
  c102_params[2] = c102_AC3;
  c102_params[3] = c102_AC4;
  c102_params[4] = c102_AC5;
  c102_params[5] = c102_AC6;
  c102_params[6] = c102_B1;
  c102_params[7] = c102_B2;
  c102_params[8] = c102_MB;
  c102_params[9] = c102_MC;
  c102_params[10] = c102_MD;
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  for (c102_i5 = 0; c102_i5 < 11; c102_i5++) {
    (*c102_b_params)[c102_i5] = c102_params[c102_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c102_sfEvent);
}

static void initSimStructsc102_ICARO3_orientation_controllo_BIPE
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c102_machineNumber, uint32_T
  c102_chartNumber, uint32_T c102_instanceNumber)
{
  (void)c102_machineNumber;
  (void)c102_chartNumber;
  (void)c102_instanceNumber;
}

static const mxArray *c102_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  int32_T c102_i6;
  real32_T c102_b_inData[11];
  int32_T c102_i7;
  real32_T c102_u[11];
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  for (c102_i6 = 0; c102_i6 < 11; c102_i6++) {
    c102_b_inData[c102_i6] = (*(real32_T (*)[11])c102_inData)[c102_i6];
  }

  for (c102_i7 = 0; c102_i7 < 11; c102_i7++) {
    c102_u[c102_i7] = c102_b_inData[c102_i7];
  }

  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", c102_u, 1, 0U, 1U, 0U, 2, 11, 1),
                false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static void c102_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_params, const char_T *c102_identifier, real32_T c102_y[11])
{
  emlrtMsgIdentifier c102_thisId;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_params), &c102_thisId,
    c102_y);
  sf_mex_destroy(&c102_params);
}

static void c102_b_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId, real32_T c102_y[11])
{
  real32_T c102_fv1[11];
  int32_T c102_i8;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), c102_fv1, 1, 1, 0U, 1, 0U, 2,
                11, 1);
  for (c102_i8 = 0; c102_i8 < 11; c102_i8++) {
    c102_y[c102_i8] = c102_fv1[c102_i8];
  }

  sf_mex_destroy(&c102_u);
}

static void c102_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData)
{
  const mxArray *c102_params;
  const char_T *c102_identifier;
  emlrtMsgIdentifier c102_thisId;
  real32_T c102_y[11];
  int32_T c102_i9;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_params = sf_mex_dup(c102_mxArrayInData);
  c102_identifier = c102_varName;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_params), &c102_thisId,
    c102_y);
  sf_mex_destroy(&c102_params);
  for (c102_i9 = 0; c102_i9 < 11; c102_i9++) {
    (*(real32_T (*)[11])c102_outData)[c102_i9] = c102_y[c102_i9];
  }

  sf_mex_destroy(&c102_mxArrayInData);
}

static const mxArray *c102_b_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  int32_T c102_i10;
  uint16_T c102_b_inData[22];
  int32_T c102_i11;
  uint16_T c102_u[22];
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  for (c102_i10 = 0; c102_i10 < 22; c102_i10++) {
    c102_b_inData[c102_i10] = (*(uint16_T (*)[22])c102_inData)[c102_i10];
  }

  for (c102_i11 = 0; c102_i11 < 22; c102_i11++) {
    c102_u[c102_i11] = c102_b_inData[c102_i11];
  }

  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", c102_u, 5, 0U, 1U, 0U, 1, 22), false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static const mxArray *c102_c_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  real_T c102_u;
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  c102_u = *(real_T *)c102_inData;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", &c102_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static real_T c102_c_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId)
{
  real_T c102_y;
  real_T c102_d0;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), &c102_d0, 1, 0, 0U, 0, 0U, 0);
  c102_y = c102_d0;
  sf_mex_destroy(&c102_u);
  return c102_y;
}

static void c102_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData)
{
  const mxArray *c102_nargout;
  const char_T *c102_identifier;
  emlrtMsgIdentifier c102_thisId;
  real_T c102_y;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_nargout = sf_mex_dup(c102_mxArrayInData);
  c102_identifier = c102_varName;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_y = c102_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_nargout),
    &c102_thisId);
  sf_mex_destroy(&c102_nargout);
  *(real_T *)c102_outData = c102_y;
  sf_mex_destroy(&c102_mxArrayInData);
}

static const mxArray *c102_d_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  real32_T c102_u;
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  c102_u = *(real32_T *)c102_inData;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", &c102_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static real32_T c102_d_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId)
{
  real32_T c102_y;
  real32_T c102_f0;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), &c102_f0, 1, 1, 0U, 0, 0U, 0);
  c102_y = c102_f0;
  sf_mex_destroy(&c102_u);
  return c102_y;
}

static void c102_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData)
{
  const mxArray *c102_MD;
  const char_T *c102_identifier;
  emlrtMsgIdentifier c102_thisId;
  real32_T c102_y;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_MD = sf_mex_dup(c102_mxArrayInData);
  c102_identifier = c102_varName;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_y = c102_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_MD),
    &c102_thisId);
  sf_mex_destroy(&c102_MD);
  *(real32_T *)c102_outData = c102_y;
  sf_mex_destroy(&c102_mxArrayInData);
}

static const mxArray *c102_e_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  uint16_T c102_u;
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  c102_u = *(uint16_T *)c102_inData;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", &c102_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static uint16_T c102_e_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId)
{
  uint16_T c102_y;
  uint16_T c102_u11;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), &c102_u11, 1, 5, 0U, 0, 0U, 0);
  c102_y = c102_u11;
  sf_mex_destroy(&c102_u);
  return c102_y;
}

static void c102_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData)
{
  const mxArray *c102_u;
  const char_T *c102_identifier;
  emlrtMsgIdentifier c102_thisId;
  uint16_T c102_y;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_u = sf_mex_dup(c102_mxArrayInData);
  c102_identifier = c102_varName;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_y = c102_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_u),
    &c102_thisId);
  sf_mex_destroy(&c102_u);
  *(uint16_T *)c102_outData = c102_y;
  sf_mex_destroy(&c102_mxArrayInData);
}

const mxArray
  *sf_c102_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c102_nameCaptureInfo = NULL;
  c102_nameCaptureInfo = NULL;
  sf_mex_assign(&c102_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c102_info_helper(&c102_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c102_nameCaptureInfo);
  return c102_nameCaptureInfo;
}

static void c102_info_helper(const mxArray **c102_info)
{
  const mxArray *c102_rhs0 = NULL;
  const mxArray *c102_lhs0 = NULL;
  const mxArray *c102_rhs1 = NULL;
  const mxArray *c102_lhs1 = NULL;
  const mxArray *c102_rhs2 = NULL;
  const mxArray *c102_lhs2 = NULL;
  const mxArray *c102_rhs3 = NULL;
  const mxArray *c102_lhs3 = NULL;
  const mxArray *c102_rhs4 = NULL;
  const mxArray *c102_lhs4 = NULL;
  const mxArray *c102_rhs5 = NULL;
  const mxArray *c102_lhs5 = NULL;
  const mxArray *c102_rhs6 = NULL;
  const mxArray *c102_lhs6 = NULL;
  const mxArray *c102_rhs7 = NULL;
  const mxArray *c102_lhs7 = NULL;
  const mxArray *c102_rhs8 = NULL;
  const mxArray *c102_lhs8 = NULL;
  const mxArray *c102_rhs9 = NULL;
  const mxArray *c102_lhs9 = NULL;
  const mxArray *c102_rhs10 = NULL;
  const mxArray *c102_lhs10 = NULL;
  const mxArray *c102_rhs11 = NULL;
  const mxArray *c102_lhs11 = NULL;
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("bitshift"), "name", "name",
                  0);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1383877292U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c102_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c102_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 2);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1286818782U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c102_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c102_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c102_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_scalexp_alloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c102_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "coder.internal.scalexpAlloc"), "name", "name", 6);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c102_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 7);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1363713854U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c102_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c102_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1286818726U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c102_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 10);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 10);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1323170578U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c102_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut("eml_switch_helper"),
                  "name", "name", 11);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c102_info, c102_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(1381850300U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c102_info, c102_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c102_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c102_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c102_info, sf_mex_duplicatearraysafe(&c102_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_destroy(&c102_rhs0);
  sf_mex_destroy(&c102_lhs0);
  sf_mex_destroy(&c102_rhs1);
  sf_mex_destroy(&c102_lhs1);
  sf_mex_destroy(&c102_rhs2);
  sf_mex_destroy(&c102_lhs2);
  sf_mex_destroy(&c102_rhs3);
  sf_mex_destroy(&c102_lhs3);
  sf_mex_destroy(&c102_rhs4);
  sf_mex_destroy(&c102_lhs4);
  sf_mex_destroy(&c102_rhs5);
  sf_mex_destroy(&c102_lhs5);
  sf_mex_destroy(&c102_rhs6);
  sf_mex_destroy(&c102_lhs6);
  sf_mex_destroy(&c102_rhs7);
  sf_mex_destroy(&c102_lhs7);
  sf_mex_destroy(&c102_rhs8);
  sf_mex_destroy(&c102_lhs8);
  sf_mex_destroy(&c102_rhs9);
  sf_mex_destroy(&c102_lhs9);
  sf_mex_destroy(&c102_rhs10);
  sf_mex_destroy(&c102_lhs10);
  sf_mex_destroy(&c102_rhs11);
  sf_mex_destroy(&c102_lhs11);
}

static const mxArray *c102_emlrt_marshallOut(const char * c102_u)
{
  const mxArray *c102_y = NULL;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", c102_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c102_u)), false);
  return c102_y;
}

static const mxArray *c102_b_emlrt_marshallOut(const uint32_T c102_u)
{
  const mxArray *c102_y = NULL;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", &c102_u, 7, 0U, 0U, 0U, 0), false);
  return c102_y;
}

static real32_T c102_decomp
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance,
   uint16_T c102_u)
{
  real32_T c102_y;
  uint32_T c102_debug_family_var_map[4];
  real32_T c102_b_u;
  real_T c102_nargin = 1.0;
  real_T c102_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c102_b_debug_family_names,
    c102_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_b_u, MAX_uint32_T,
    c102_d_sf_marshallOut, c102_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_nargin, 1U, c102_c_sf_marshallOut,
    c102_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_nargout, 2U, c102_c_sf_marshallOut,
    c102_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_u, 0U, c102_e_sf_marshallOut,
    c102_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c102_y, 3U, c102_d_sf_marshallOut,
    c102_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 25);
  c102_b_u = (real32_T)c102_u;
  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 27);
  if (CV_EML_IF(0, 1, 0, c102_b_u > 32767.0F)) {
    _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 28);
    c102_y = -65536.0F + c102_b_u;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, 30);
    c102_y = c102_b_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c102_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  return c102_y;
}

static const mxArray *c102_f_sf_marshallOut(void *chartInstanceVoid, void
  *c102_inData)
{
  const mxArray *c102_mxArrayOutData = NULL;
  int32_T c102_u;
  const mxArray *c102_y = NULL;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_mxArrayOutData = NULL;
  c102_u = *(int32_T *)c102_inData;
  c102_y = NULL;
  sf_mex_assign(&c102_y, sf_mex_create("y", &c102_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c102_mxArrayOutData, c102_y, false);
  return c102_mxArrayOutData;
}

static int32_T c102_f_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId)
{
  int32_T c102_y;
  int32_T c102_i12;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), &c102_i12, 1, 6, 0U, 0, 0U, 0);
  c102_y = c102_i12;
  sf_mex_destroy(&c102_u);
  return c102_y;
}

static void c102_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c102_mxArrayInData, const char_T *c102_varName, void *c102_outData)
{
  const mxArray *c102_b_sfEvent;
  const char_T *c102_identifier;
  emlrtMsgIdentifier c102_thisId;
  int32_T c102_y;
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c102_b_sfEvent = sf_mex_dup(c102_mxArrayInData);
  c102_identifier = c102_varName;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_y = c102_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c102_b_sfEvent),
    &c102_thisId);
  sf_mex_destroy(&c102_b_sfEvent);
  *(int32_T *)c102_outData = c102_y;
  sf_mex_destroy(&c102_mxArrayInData);
}

static uint8_T c102_g_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_b_is_active_c102_ICARO3_orientation_controllo_BIPE, const
   char_T *c102_identifier)
{
  uint8_T c102_y;
  emlrtMsgIdentifier c102_thisId;
  c102_thisId.fIdentifier = c102_identifier;
  c102_thisId.fParent = NULL;
  c102_y = c102_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c102_b_is_active_c102_ICARO3_orientation_controllo_BIPE), &c102_thisId);
  sf_mex_destroy(&c102_b_is_active_c102_ICARO3_orientation_controllo_BIPE);
  return c102_y;
}

static uint8_T c102_h_emlrt_marshallIn
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c102_u, const emlrtMsgIdentifier *c102_parentId)
{
  uint8_T c102_y;
  uint8_T c102_u12;
  (void)chartInstance;
  sf_mex_import(c102_parentId, sf_mex_dup(c102_u), &c102_u12, 1, 3, 0U, 0, 0U, 0);
  c102_y = c102_u12;
  sf_mex_destroy(&c102_u);
  return c102_y;
}

static void init_dsm_address_info
  (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
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

void sf_c102_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3414138958U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(986390514U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2996817240U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4122931461U);
}

mxArray *sf_c102_ICARO3_orientation_controllo_BIPE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wQketIGMq6D4CYDTa0ZdbF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(22);
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
      pr[0] = (double)(11);
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

mxArray *sf_c102_ICARO3_orientation_controllo_BIPE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c102_ICARO3_orientation_controllo_BIPE_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c102_ICARO3_orientation_controllo_BIPE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"params\",},{M[8],M[0],T\"is_active_c102_ICARO3_orientation_controllo_BIPE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c102_ICARO3_orientation_controllo_BIPE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_orientation_controllo_BIPEMachineNumber_,
           102,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"bytes");
          _SFD_SET_DATA_PROPS(1,2,0,1,"params");
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
        _SFD_CV_INIT_EML(0,1,2,1,0,11,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,662);
        _SFD_CV_INIT_EML_FCN(0,1,"decomp",664,-1,779);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,118,-1,150);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,166,-1,198);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,215,-1,247);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,263,-1,296);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,312,-1,346);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,362,-1,396);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,411,-1,445);
        _SFD_CV_INIT_EML_SATURATION(0,1,7,461,-1,495);
        _SFD_CV_INIT_EML_SATURATION(0,1,8,510,-1,544);
        _SFD_CV_INIT_EML_SATURATION(0,1,9,559,-1,593);
        _SFD_CV_INIT_EML_SATURATION(0,1,10,70,-1,102);
        _SFD_CV_INIT_EML_IF(0,1,0,704,718,747,774);

        {
          unsigned int dimVector[1];
          dimVector[0]= 22;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c102_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 11;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c102_sf_marshallOut,(MexInFcnForType)
            c102_sf_marshallIn);
        }

        {
          uint16_T (*c102_bytes)[22];
          real32_T (*c102_params)[11];
          c102_params = (real32_T (*)[11])ssGetOutputPortSignal(chartInstance->S,
            1);
          c102_bytes = (uint16_T (*)[22])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c102_bytes);
          _SFD_SET_DATA_VALUE_PTR(1U, *c102_params);
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
  return "y4ZUNA9Y6lGwmZxUDuTzKF";
}

static void sf_opaque_initialize_c102_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
  initialize_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c102_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  enable_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c102_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  disable_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c102_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  sf_gateway_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c102_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c102_ICARO3_orientation_controllo_BIPE();/* state var info */
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

extern void sf_internal_set_sim_state_c102_ICARO3_orientation_controllo_BIPE
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
    sf_get_sim_state_info_c102_ICARO3_orientation_controllo_BIPE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c102_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  return sf_internal_get_sim_state_c102_ICARO3_orientation_controllo_BIPE(S);
}

static void sf_opaque_set_sim_state_c102_ICARO3_orientation_controllo_BIPE
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c102_ICARO3_orientation_controllo_BIPE(S, st);
}

static void sf_opaque_terminate_c102_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_orientation_controllo_BIPE_optimization_info();
    }

    finalize_c102_ICARO3_orientation_controllo_BIPE
      ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*)
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
  initSimStructsc102_ICARO3_orientation_controllo_BIPE
    ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c102_ICARO3_orientation_controllo_BIPE
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
    initialize_params_c102_ICARO3_orientation_controllo_BIPE
      ((SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c102_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_orientation_controllo_BIPE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      102);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,102,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,102,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,102);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,102,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,102,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,102);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1415501840U));
  ssSetChecksum1(S,(3648915974U));
  ssSetChecksum2(S,(654273176U));
  ssSetChecksum3(S,(3442938101U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c102_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c102_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    utMalloc(sizeof(SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc102_ICARO3_orientation_controllo_BIPEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c102_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c102_ICARO3_orientation_controllo_BIPE;
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

void c102_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c102_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c102_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c102_ICARO3_orientation_controllo_BIPE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c102_ICARO3_orientation_controllo_BIPE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
