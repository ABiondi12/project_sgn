/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_sfun.h"
#include "c98_ICARO3_Onda_bipe_controllonostro.h"
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
static const char * c98_debug_family_names[16] = { "ax", "ay", "az", "temp",
  "gx", "gy", "gz", "a_mpu9150", "g_mpu9150", "nargin", "nargout", "u",
  "mpu9150_gyroacc_enabled", "a", "t", "g" };

static const char * c98_b_debug_family_names[4] = { "u", "nargin", "nargout",
  "y" };

/* Function Declarations */
static void initialize_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initialize_params_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void enable_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void disable_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void c98_update_debugger_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void set_sim_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_st);
static void finalize_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void sf_gateway_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void c98_chartstep_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void initSimStructsc98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c98_machineNumber, uint32_T
  c98_chartNumber, uint32_T c98_instanceNumber);
static const mxArray *c98_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static void c98_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_g, const char_T *c98_identifier, real32_T c98_y[3]);
static void c98_b_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId, real32_T c98_y[3]);
static void c98_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData);
static const mxArray *c98_b_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static real32_T c98_c_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_t, const char_T *c98_identifier);
static real32_T c98_d_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId);
static void c98_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData);
static const mxArray *c98_c_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static const mxArray *c98_d_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static const mxArray *c98_e_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static real_T c98_e_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId);
static void c98_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData);
static const mxArray *c98_f_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static uint16_T c98_f_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId);
static void c98_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData);
static void c98_info_helper(const mxArray **c98_info);
static const mxArray *c98_emlrt_marshallOut(const char * c98_u);
static const mxArray *c98_b_emlrt_marshallOut(const uint32_T c98_u);
static real32_T c98_decomp(SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *
  chartInstance, uint16_T c98_u);
static const mxArray *c98_g_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData);
static int32_T c98_g_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId);
static void c98_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData);
static uint8_T c98_h_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_b_is_active_c98_ICARO3_Onda_bipe_controllonostro, const char_T
   *c98_identifier);
static uint8_T c98_i_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId);
static void init_dsm_address_info
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  chartInstance->c98_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c98_is_active_c98_ICARO3_Onda_bipe_controllonostro = 0U;
}

static void initialize_params_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c98_update_debugger_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  const mxArray *c98_st;
  const mxArray *c98_y = NULL;
  int32_T c98_i0;
  real32_T c98_u[3];
  const mxArray *c98_b_y = NULL;
  int32_T c98_i1;
  real32_T c98_b_u[3];
  const mxArray *c98_c_y = NULL;
  real32_T c98_hoistedGlobal;
  real32_T c98_c_u;
  const mxArray *c98_d_y = NULL;
  uint8_T c98_b_hoistedGlobal;
  uint8_T c98_d_u;
  const mxArray *c98_e_y = NULL;
  real32_T *c98_t;
  real32_T (*c98_g)[3];
  real32_T (*c98_a)[3];
  c98_g = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c98_t = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c98_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c98_st = NULL;
  c98_st = NULL;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_createcellmatrix(4, 1), false);
  for (c98_i0 = 0; c98_i0 < 3; c98_i0++) {
    c98_u[c98_i0] = (*c98_a)[c98_i0];
  }

  c98_b_y = NULL;
  sf_mex_assign(&c98_b_y, sf_mex_create("y", c98_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c98_y, 0, c98_b_y);
  for (c98_i1 = 0; c98_i1 < 3; c98_i1++) {
    c98_b_u[c98_i1] = (*c98_g)[c98_i1];
  }

  c98_c_y = NULL;
  sf_mex_assign(&c98_c_y, sf_mex_create("y", c98_b_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c98_y, 1, c98_c_y);
  c98_hoistedGlobal = *c98_t;
  c98_c_u = c98_hoistedGlobal;
  c98_d_y = NULL;
  sf_mex_assign(&c98_d_y, sf_mex_create("y", &c98_c_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c98_y, 2, c98_d_y);
  c98_b_hoistedGlobal =
    chartInstance->c98_is_active_c98_ICARO3_Onda_bipe_controllonostro;
  c98_d_u = c98_b_hoistedGlobal;
  c98_e_y = NULL;
  sf_mex_assign(&c98_e_y, sf_mex_create("y", &c98_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c98_y, 3, c98_e_y);
  sf_mex_assign(&c98_st, c98_y, false);
  return c98_st;
}

static void set_sim_state_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_st)
{
  const mxArray *c98_u;
  real32_T c98_fv0[3];
  int32_T c98_i2;
  real32_T c98_fv1[3];
  int32_T c98_i3;
  real32_T *c98_t;
  real32_T (*c98_a)[3];
  real32_T (*c98_g)[3];
  c98_g = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c98_t = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c98_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c98_doneDoubleBufferReInit = true;
  c98_u = sf_mex_dup(c98_st);
  c98_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c98_u, 0)), "a",
                       c98_fv0);
  for (c98_i2 = 0; c98_i2 < 3; c98_i2++) {
    (*c98_a)[c98_i2] = c98_fv0[c98_i2];
  }

  c98_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c98_u, 1)), "g",
                       c98_fv1);
  for (c98_i3 = 0; c98_i3 < 3; c98_i3++) {
    (*c98_g)[c98_i3] = c98_fv1[c98_i3];
  }

  *c98_t = c98_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c98_u,
    2)), "t");
  chartInstance->c98_is_active_c98_ICARO3_Onda_bipe_controllonostro =
    c98_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c98_u, 3)),
    "is_active_c98_ICARO3_Onda_bipe_controllonostro");
  sf_mex_destroy(&c98_u);
  c98_update_debugger_state_c98_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c98_st);
}

static void finalize_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  int32_T c98_i4;
  int32_T c98_i5;
  int32_T c98_i6;
  uint8_T *c98_mpu9150_gyroacc_enabled;
  real32_T *c98_t;
  real32_T (*c98_g)[3];
  real32_T (*c98_a)[3];
  uint16_T (*c98_u)[14];
  c98_g = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c98_t = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c98_mpu9150_gyroacc_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S,
    1);
  c98_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c98_u = (uint16_T (*)[14])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c98_sfEvent);
  for (c98_i4 = 0; c98_i4 < 14; c98_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c98_u)[c98_i4], 0U);
  }

  chartInstance->c98_sfEvent = CALL_EVENT;
  c98_chartstep_c98_ICARO3_Onda_bipe_controllonostro(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostroMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  for (c98_i5 = 0; c98_i5 < 3; c98_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c98_a)[c98_i5], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c98_mpu9150_gyroacc_enabled, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c98_t, 3U);
  for (c98_i6 = 0; c98_i6 < 3; c98_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c98_g)[c98_i6], 4U);
  }
}

static void c98_chartstep_c98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  uint8_T c98_hoistedGlobal;
  int32_T c98_i7;
  uint16_T c98_u[14];
  uint8_T c98_mpu9150_gyroacc_enabled;
  uint32_T c98_debug_family_var_map[16];
  real32_T c98_ax;
  real32_T c98_ay;
  real32_T c98_az;
  real32_T c98_temp;
  real32_T c98_gx;
  real32_T c98_gy;
  real32_T c98_gz;
  real32_T c98_a_mpu9150[3];
  real32_T c98_g_mpu9150[3];
  real_T c98_nargin = 2.0;
  real_T c98_nargout = 3.0;
  real32_T c98_a[3];
  real32_T c98_t;
  real32_T c98_g[3];
  int32_T c98_i8;
  uint16_T c98_b_a[14];
  int32_T c98_i9;
  uint16_T c98_c_a;
  uint16_T c98_a1;
  uint16_T c98_d_a;
  uint16_T c98_c;
  uint32_T c98_u0;
  real32_T c98_A;
  real32_T c98_x;
  real32_T c98_b_x;
  real32_T c98_c_x;
  real32_T c98_y;
  real32_T c98_e_a;
  uint16_T c98_f_a;
  uint16_T c98_b_a1;
  uint16_T c98_g_a;
  uint16_T c98_b_c;
  uint32_T c98_u1;
  real32_T c98_b_A;
  real32_T c98_d_x;
  real32_T c98_e_x;
  real32_T c98_f_x;
  real32_T c98_b_y;
  real32_T c98_h_a;
  uint16_T c98_i_a;
  uint16_T c98_c_a1;
  uint16_T c98_j_a;
  uint16_T c98_c_c;
  uint32_T c98_u2;
  real32_T c98_c_A;
  real32_T c98_g_x;
  real32_T c98_h_x;
  real32_T c98_i_x;
  real32_T c98_c_y;
  real32_T c98_k_a;
  uint16_T c98_l_a;
  uint16_T c98_d_a1;
  uint16_T c98_m_a;
  uint16_T c98_d_c;
  uint32_T c98_u3;
  real32_T c98_d_A;
  real32_T c98_j_x;
  real32_T c98_k_x;
  real32_T c98_l_x;
  uint16_T c98_n_a;
  uint16_T c98_e_a1;
  uint16_T c98_o_a;
  uint16_T c98_e_c;
  uint32_T c98_u4;
  real32_T c98_e_A;
  real32_T c98_m_x;
  real32_T c98_n_x;
  real32_T c98_o_x;
  real32_T c98_d_y;
  real32_T c98_p_a;
  real32_T c98_e_y;
  real32_T c98_f_A;
  real32_T c98_p_x;
  real32_T c98_q_x;
  real32_T c98_r_x;
  uint16_T c98_q_a;
  uint16_T c98_f_a1;
  uint16_T c98_r_a;
  uint16_T c98_f_c;
  uint32_T c98_u5;
  real32_T c98_g_A;
  real32_T c98_s_x;
  real32_T c98_t_x;
  real32_T c98_u_x;
  real32_T c98_f_y;
  real32_T c98_s_a;
  real32_T c98_g_y;
  real32_T c98_h_A;
  real32_T c98_v_x;
  real32_T c98_w_x;
  real32_T c98_x_x;
  uint16_T c98_t_a;
  uint16_T c98_g_a1;
  uint16_T c98_u_a;
  uint16_T c98_g_c;
  uint32_T c98_u6;
  real32_T c98_i_A;
  real32_T c98_y_x;
  real32_T c98_ab_x;
  real32_T c98_bb_x;
  real32_T c98_h_y;
  real32_T c98_v_a;
  real32_T c98_i_y;
  real32_T c98_j_A;
  real32_T c98_cb_x;
  real32_T c98_db_x;
  real32_T c98_eb_x;
  int32_T c98_i10;
  real32_T c98_b[3];
  int32_T c98_i11;
  int32_T c98_i12;
  int32_T c98_i13;
  static real32_T c98_fv2[9] = { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F,
    -1.0F };

  int32_T c98_i14;
  int32_T c98_i15;
  int32_T c98_i16;
  int32_T c98_i17;
  int32_T c98_i18;
  int32_T c98_i19;
  real32_T *c98_b_t;
  uint8_T *c98_b_mpu9150_gyroacc_enabled;
  real32_T (*c98_w_a)[3];
  real32_T (*c98_b_g)[3];
  uint16_T (*c98_b_u)[14];
  c98_b_g = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c98_b_t = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c98_b_mpu9150_gyroacc_enabled = (uint8_T *)ssGetInputPortSignal
    (chartInstance->S, 1);
  c98_w_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c98_b_u = (uint16_T (*)[14])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c98_sfEvent);
  c98_hoistedGlobal = *c98_b_mpu9150_gyroacc_enabled;
  for (c98_i7 = 0; c98_i7 < 14; c98_i7++) {
    c98_u[c98_i7] = (*c98_b_u)[c98_i7];
  }

  c98_mpu9150_gyroacc_enabled = c98_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c98_debug_family_names,
    c98_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_ax, 0U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_ay, 1U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_az, 2U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_temp, 3U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_gx, 4U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_gy, 5U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_gz, 6U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c98_a_mpu9150, 7U, c98_sf_marshallOut,
    c98_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c98_g_mpu9150, 8U, c98_sf_marshallOut,
    c98_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_nargin, 9U, c98_e_sf_marshallOut,
    c98_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_nargout, 10U, c98_e_sf_marshallOut,
    c98_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c98_u, 11U, c98_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c98_mpu9150_gyroacc_enabled, 12U,
    c98_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c98_a, 13U, c98_sf_marshallOut,
    c98_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_t, 14U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c98_g, 15U, c98_sf_marshallOut,
    c98_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, (real_T)c98_mpu9150_gyroacc_enabled == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 4);
    for (c98_i8 = 0; c98_i8 < 14; c98_i8++) {
      c98_b_a[c98_i8] = c98_u[c98_i8];
    }

    for (c98_i9 = 0; c98_i9 < 14; c98_i9++) {
      c98_u[c98_i9] = 0U;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 37);
  c98_c_a = c98_u[0];
  c98_a1 = c98_c_a;
  c98_d_a = c98_a1;
  c98_c = (uint16_T)(c98_d_a << 8);
  c98_u0 = (uint32_T)c98_c + (uint32_T)c98_u[1];
  if (CV_SATURATION_EVAL(4, 0, 5, 0, c98_u0 > 65535U)) {
    c98_u0 = 65535U;
  }

  c98_A = c98_decomp(chartInstance, (uint16_T)c98_u0);
  c98_x = c98_A;
  c98_b_x = c98_x;
  c98_c_x = c98_b_x;
  c98_y = c98_c_x / 8192.0F;
  c98_e_a = c98_y;
  c98_ax = c98_e_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 38);
  c98_f_a = c98_u[2];
  c98_b_a1 = c98_f_a;
  c98_g_a = c98_b_a1;
  c98_b_c = (uint16_T)(c98_g_a << 8);
  c98_u1 = (uint32_T)c98_b_c + (uint32_T)c98_u[3];
  if (CV_SATURATION_EVAL(4, 0, 6, 0, c98_u1 > 65535U)) {
    c98_u1 = 65535U;
  }

  c98_b_A = c98_decomp(chartInstance, (uint16_T)c98_u1);
  c98_d_x = c98_b_A;
  c98_e_x = c98_d_x;
  c98_f_x = c98_e_x;
  c98_b_y = c98_f_x / 8192.0F;
  c98_h_a = c98_b_y;
  c98_ay = c98_h_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 39);
  c98_i_a = c98_u[4];
  c98_c_a1 = c98_i_a;
  c98_j_a = c98_c_a1;
  c98_c_c = (uint16_T)(c98_j_a << 8);
  c98_u2 = (uint32_T)c98_c_c + (uint32_T)c98_u[5];
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c98_u2 > 65535U)) {
    c98_u2 = 65535U;
  }

  c98_c_A = c98_decomp(chartInstance, (uint16_T)c98_u2);
  c98_g_x = c98_c_A;
  c98_h_x = c98_g_x;
  c98_i_x = c98_h_x;
  c98_c_y = c98_i_x / 8192.0F;
  c98_k_a = c98_c_y;
  c98_az = c98_k_a * 9.81F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 41);
  c98_l_a = c98_u[6];
  c98_d_a1 = c98_l_a;
  c98_m_a = c98_d_a1;
  c98_d_c = (uint16_T)(c98_m_a << 8);
  c98_u3 = (uint32_T)c98_d_c + (uint32_T)c98_u[7];
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c98_u3 > 65535U)) {
    c98_u3 = 65535U;
  }

  c98_d_A = c98_decomp(chartInstance, (uint16_T)c98_u3);
  c98_j_x = c98_d_A;
  c98_k_x = c98_j_x;
  c98_l_x = c98_k_x;
  c98_temp = c98_l_x;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 43);
  c98_n_a = c98_u[8];
  c98_e_a1 = c98_n_a;
  c98_o_a = c98_e_a1;
  c98_e_c = (uint16_T)(c98_o_a << 8);
  c98_u4 = (uint32_T)c98_e_c + (uint32_T)c98_u[9];
  if (CV_SATURATION_EVAL(4, 0, 2, 0, c98_u4 > 65535U)) {
    c98_u4 = 65535U;
  }

  c98_e_A = c98_decomp(chartInstance, (uint16_T)c98_u4);
  c98_m_x = c98_e_A;
  c98_n_x = c98_m_x;
  c98_o_x = c98_n_x;
  c98_d_y = c98_o_x / 131.0F;
  c98_p_a = c98_d_y;
  c98_e_y = c98_p_a * 3.14159274F;
  c98_f_A = c98_e_y;
  c98_p_x = c98_f_A;
  c98_q_x = c98_p_x;
  c98_r_x = c98_q_x;
  c98_gx = c98_r_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 44);
  c98_q_a = c98_u[10];
  c98_f_a1 = c98_q_a;
  c98_r_a = c98_f_a1;
  c98_f_c = (uint16_T)(c98_r_a << 8);
  c98_u5 = (uint32_T)c98_f_c + (uint32_T)c98_u[11];
  if (CV_SATURATION_EVAL(4, 0, 3, 0, c98_u5 > 65535U)) {
    c98_u5 = 65535U;
  }

  c98_g_A = c98_decomp(chartInstance, (uint16_T)c98_u5);
  c98_s_x = c98_g_A;
  c98_t_x = c98_s_x;
  c98_u_x = c98_t_x;
  c98_f_y = c98_u_x / 131.0F;
  c98_s_a = c98_f_y;
  c98_g_y = c98_s_a * 3.14159274F;
  c98_h_A = c98_g_y;
  c98_v_x = c98_h_A;
  c98_w_x = c98_v_x;
  c98_x_x = c98_w_x;
  c98_gy = c98_x_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 45);
  c98_t_a = c98_u[12];
  c98_g_a1 = c98_t_a;
  c98_u_a = c98_g_a1;
  c98_g_c = (uint16_T)(c98_u_a << 8);
  c98_u6 = (uint32_T)c98_g_c + (uint32_T)c98_u[13];
  if (CV_SATURATION_EVAL(4, 0, 4, 0, c98_u6 > 65535U)) {
    c98_u6 = 65535U;
  }

  c98_i_A = c98_decomp(chartInstance, (uint16_T)c98_u6);
  c98_y_x = c98_i_A;
  c98_ab_x = c98_y_x;
  c98_bb_x = c98_ab_x;
  c98_h_y = c98_bb_x / 131.0F;
  c98_v_a = c98_h_y;
  c98_i_y = c98_v_a * 3.14159274F;
  c98_j_A = c98_i_y;
  c98_cb_x = c98_j_A;
  c98_db_x = c98_cb_x;
  c98_eb_x = c98_db_x;
  c98_gz = c98_eb_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 47);
  c98_a_mpu9150[0] = c98_ax;
  c98_a_mpu9150[1] = c98_ay;
  c98_a_mpu9150[2] = c98_az;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 48);
  c98_g_mpu9150[0] = c98_gx;
  c98_g_mpu9150[1] = c98_gy;
  c98_g_mpu9150[2] = c98_gz;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 58);
  for (c98_i10 = 0; c98_i10 < 3; c98_i10++) {
    c98_b[c98_i10] = c98_a_mpu9150[c98_i10];
  }

  for (c98_i11 = 0; c98_i11 < 3; c98_i11++) {
    c98_a[c98_i11] = 0.0F;
    c98_i12 = 0;
    for (c98_i13 = 0; c98_i13 < 3; c98_i13++) {
      c98_a[c98_i11] += c98_fv2[c98_i12 + c98_i11] * c98_b[c98_i13];
      c98_i12 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 59);
  for (c98_i14 = 0; c98_i14 < 3; c98_i14++) {
    c98_b[c98_i14] = c98_g_mpu9150[c98_i14];
  }

  for (c98_i15 = 0; c98_i15 < 3; c98_i15++) {
    c98_g[c98_i15] = 0.0F;
    c98_i16 = 0;
    for (c98_i17 = 0; c98_i17 < 3; c98_i17++) {
      c98_g[c98_i15] += c98_fv2[c98_i16 + c98_i15] * c98_b[c98_i17];
      c98_i16 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 60);
  c98_t = c98_temp;
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, -60);
  _SFD_SYMBOL_SCOPE_POP();
  for (c98_i18 = 0; c98_i18 < 3; c98_i18++) {
    (*c98_w_a)[c98_i18] = c98_a[c98_i18];
  }

  *c98_b_t = c98_t;
  for (c98_i19 = 0; c98_i19 < 3; c98_i19++) {
    (*c98_b_g)[c98_i19] = c98_g[c98_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c98_sfEvent);
}

static void initSimStructsc98_ICARO3_Onda_bipe_controllonostro
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c98_machineNumber, uint32_T
  c98_chartNumber, uint32_T c98_instanceNumber)
{
  (void)c98_machineNumber;
  (void)c98_chartNumber;
  (void)c98_instanceNumber;
}

static const mxArray *c98_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  int32_T c98_i20;
  real32_T c98_b_inData[3];
  int32_T c98_i21;
  real32_T c98_u[3];
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  for (c98_i20 = 0; c98_i20 < 3; c98_i20++) {
    c98_b_inData[c98_i20] = (*(real32_T (*)[3])c98_inData)[c98_i20];
  }

  for (c98_i21 = 0; c98_i21 < 3; c98_i21++) {
    c98_u[c98_i21] = c98_b_inData[c98_i21];
  }

  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", c98_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static void c98_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_g, const char_T *c98_identifier, real32_T c98_y[3])
{
  emlrtMsgIdentifier c98_thisId;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_g), &c98_thisId, c98_y);
  sf_mex_destroy(&c98_g);
}

static void c98_b_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId, real32_T c98_y[3])
{
  real32_T c98_fv3[3];
  int32_T c98_i22;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), c98_fv3, 1, 1, 0U, 1, 0U, 1, 3);
  for (c98_i22 = 0; c98_i22 < 3; c98_i22++) {
    c98_y[c98_i22] = c98_fv3[c98_i22];
  }

  sf_mex_destroy(&c98_u);
}

static void c98_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData)
{
  const mxArray *c98_g;
  const char_T *c98_identifier;
  emlrtMsgIdentifier c98_thisId;
  real32_T c98_y[3];
  int32_T c98_i23;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_g = sf_mex_dup(c98_mxArrayInData);
  c98_identifier = c98_varName;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_g), &c98_thisId, c98_y);
  sf_mex_destroy(&c98_g);
  for (c98_i23 = 0; c98_i23 < 3; c98_i23++) {
    (*(real32_T (*)[3])c98_outData)[c98_i23] = c98_y[c98_i23];
  }

  sf_mex_destroy(&c98_mxArrayInData);
}

static const mxArray *c98_b_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  real32_T c98_u;
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  c98_u = *(real32_T *)c98_inData;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static real32_T c98_c_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_t, const char_T *c98_identifier)
{
  real32_T c98_y;
  emlrtMsgIdentifier c98_thisId;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_t), &c98_thisId);
  sf_mex_destroy(&c98_t);
  return c98_y;
}

static real32_T c98_d_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId)
{
  real32_T c98_y;
  real32_T c98_f0;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), &c98_f0, 1, 1, 0U, 0, 0U, 0);
  c98_y = c98_f0;
  sf_mex_destroy(&c98_u);
  return c98_y;
}

static void c98_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData)
{
  const mxArray *c98_t;
  const char_T *c98_identifier;
  emlrtMsgIdentifier c98_thisId;
  real32_T c98_y;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_t = sf_mex_dup(c98_mxArrayInData);
  c98_identifier = c98_varName;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_t), &c98_thisId);
  sf_mex_destroy(&c98_t);
  *(real32_T *)c98_outData = c98_y;
  sf_mex_destroy(&c98_mxArrayInData);
}

static const mxArray *c98_c_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  uint8_T c98_u;
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  c98_u = *(uint8_T *)c98_inData;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static const mxArray *c98_d_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  int32_T c98_i24;
  uint16_T c98_b_inData[14];
  int32_T c98_i25;
  uint16_T c98_u[14];
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  for (c98_i24 = 0; c98_i24 < 14; c98_i24++) {
    c98_b_inData[c98_i24] = (*(uint16_T (*)[14])c98_inData)[c98_i24];
  }

  for (c98_i25 = 0; c98_i25 < 14; c98_i25++) {
    c98_u[c98_i25] = c98_b_inData[c98_i25];
  }

  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", c98_u, 5, 0U, 1U, 0U, 1, 14), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static const mxArray *c98_e_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  real_T c98_u;
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  c98_u = *(real_T *)c98_inData;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static real_T c98_e_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId)
{
  real_T c98_y;
  real_T c98_d0;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), &c98_d0, 1, 0, 0U, 0, 0U, 0);
  c98_y = c98_d0;
  sf_mex_destroy(&c98_u);
  return c98_y;
}

static void c98_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData)
{
  const mxArray *c98_nargout;
  const char_T *c98_identifier;
  emlrtMsgIdentifier c98_thisId;
  real_T c98_y;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_nargout = sf_mex_dup(c98_mxArrayInData);
  c98_identifier = c98_varName;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_nargout),
    &c98_thisId);
  sf_mex_destroy(&c98_nargout);
  *(real_T *)c98_outData = c98_y;
  sf_mex_destroy(&c98_mxArrayInData);
}

static const mxArray *c98_f_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  uint16_T c98_u;
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  c98_u = *(uint16_T *)c98_inData;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static uint16_T c98_f_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId)
{
  uint16_T c98_y;
  uint16_T c98_u7;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), &c98_u7, 1, 5, 0U, 0, 0U, 0);
  c98_y = c98_u7;
  sf_mex_destroy(&c98_u);
  return c98_y;
}

static void c98_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData)
{
  const mxArray *c98_u;
  const char_T *c98_identifier;
  emlrtMsgIdentifier c98_thisId;
  uint16_T c98_y;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_u = sf_mex_dup(c98_mxArrayInData);
  c98_identifier = c98_varName;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_u), &c98_thisId);
  sf_mex_destroy(&c98_u);
  *(uint16_T *)c98_outData = c98_y;
  sf_mex_destroy(&c98_mxArrayInData);
}

const mxArray
  *sf_c98_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void)
{
  const mxArray *c98_nameCaptureInfo = NULL;
  c98_nameCaptureInfo = NULL;
  sf_mex_assign(&c98_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c98_info_helper(&c98_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c98_nameCaptureInfo);
  return c98_nameCaptureInfo;
}

static void c98_info_helper(const mxArray **c98_info)
{
  const mxArray *c98_rhs0 = NULL;
  const mxArray *c98_lhs0 = NULL;
  const mxArray *c98_rhs1 = NULL;
  const mxArray *c98_lhs1 = NULL;
  const mxArray *c98_rhs2 = NULL;
  const mxArray *c98_lhs2 = NULL;
  const mxArray *c98_rhs3 = NULL;
  const mxArray *c98_lhs3 = NULL;
  const mxArray *c98_rhs4 = NULL;
  const mxArray *c98_lhs4 = NULL;
  const mxArray *c98_rhs5 = NULL;
  const mxArray *c98_lhs5 = NULL;
  const mxArray *c98_rhs6 = NULL;
  const mxArray *c98_lhs6 = NULL;
  const mxArray *c98_rhs7 = NULL;
  const mxArray *c98_lhs7 = NULL;
  const mxArray *c98_rhs8 = NULL;
  const mxArray *c98_lhs8 = NULL;
  const mxArray *c98_rhs9 = NULL;
  const mxArray *c98_lhs9 = NULL;
  const mxArray *c98_rhs10 = NULL;
  const mxArray *c98_lhs10 = NULL;
  const mxArray *c98_rhs11 = NULL;
  const mxArray *c98_lhs11 = NULL;
  const mxArray *c98_rhs12 = NULL;
  const mxArray *c98_lhs12 = NULL;
  const mxArray *c98_rhs13 = NULL;
  const mxArray *c98_lhs13 = NULL;
  const mxArray *c98_rhs14 = NULL;
  const mxArray *c98_lhs14 = NULL;
  const mxArray *c98_rhs15 = NULL;
  const mxArray *c98_lhs15 = NULL;
  const mxArray *c98_rhs16 = NULL;
  const mxArray *c98_lhs16 = NULL;
  const mxArray *c98_rhs17 = NULL;
  const mxArray *c98_lhs17 = NULL;
  const mxArray *c98_rhs18 = NULL;
  const mxArray *c98_lhs18 = NULL;
  const mxArray *c98_rhs19 = NULL;
  const mxArray *c98_lhs19 = NULL;
  const mxArray *c98_rhs20 = NULL;
  const mxArray *c98_lhs20 = NULL;
  const mxArray *c98_rhs21 = NULL;
  const mxArray *c98_lhs21 = NULL;
  const mxArray *c98_rhs22 = NULL;
  const mxArray *c98_lhs22 = NULL;
  const mxArray *c98_rhs23 = NULL;
  const mxArray *c98_lhs23 = NULL;
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c98_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c98_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c98_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("bitshift"), "name", "name",
                  3);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1383877292U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c98_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c98_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c98_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c98_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c98_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 8);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c98_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 9);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c98_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 10);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("floor"), "name", "name", 10);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c98_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c98_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 12);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c98_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 13);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 13);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c98_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c98_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("mrdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c98_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 16);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 16);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c98_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("rdivide"), "name", "name",
                  17);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c98_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c98_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c98_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 20);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c98_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("eml_div"), "name", "name",
                  21);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c98_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 22);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c98_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 23);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c98_info, c98_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c98_info, c98_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c98_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c98_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c98_info, sf_mex_duplicatearraysafe(&c98_lhs23), "lhs", "lhs",
                  23);
  sf_mex_destroy(&c98_rhs0);
  sf_mex_destroy(&c98_lhs0);
  sf_mex_destroy(&c98_rhs1);
  sf_mex_destroy(&c98_lhs1);
  sf_mex_destroy(&c98_rhs2);
  sf_mex_destroy(&c98_lhs2);
  sf_mex_destroy(&c98_rhs3);
  sf_mex_destroy(&c98_lhs3);
  sf_mex_destroy(&c98_rhs4);
  sf_mex_destroy(&c98_lhs4);
  sf_mex_destroy(&c98_rhs5);
  sf_mex_destroy(&c98_lhs5);
  sf_mex_destroy(&c98_rhs6);
  sf_mex_destroy(&c98_lhs6);
  sf_mex_destroy(&c98_rhs7);
  sf_mex_destroy(&c98_lhs7);
  sf_mex_destroy(&c98_rhs8);
  sf_mex_destroy(&c98_lhs8);
  sf_mex_destroy(&c98_rhs9);
  sf_mex_destroy(&c98_lhs9);
  sf_mex_destroy(&c98_rhs10);
  sf_mex_destroy(&c98_lhs10);
  sf_mex_destroy(&c98_rhs11);
  sf_mex_destroy(&c98_lhs11);
  sf_mex_destroy(&c98_rhs12);
  sf_mex_destroy(&c98_lhs12);
  sf_mex_destroy(&c98_rhs13);
  sf_mex_destroy(&c98_lhs13);
  sf_mex_destroy(&c98_rhs14);
  sf_mex_destroy(&c98_lhs14);
  sf_mex_destroy(&c98_rhs15);
  sf_mex_destroy(&c98_lhs15);
  sf_mex_destroy(&c98_rhs16);
  sf_mex_destroy(&c98_lhs16);
  sf_mex_destroy(&c98_rhs17);
  sf_mex_destroy(&c98_lhs17);
  sf_mex_destroy(&c98_rhs18);
  sf_mex_destroy(&c98_lhs18);
  sf_mex_destroy(&c98_rhs19);
  sf_mex_destroy(&c98_lhs19);
  sf_mex_destroy(&c98_rhs20);
  sf_mex_destroy(&c98_lhs20);
  sf_mex_destroy(&c98_rhs21);
  sf_mex_destroy(&c98_lhs21);
  sf_mex_destroy(&c98_rhs22);
  sf_mex_destroy(&c98_lhs22);
  sf_mex_destroy(&c98_rhs23);
  sf_mex_destroy(&c98_lhs23);
}

static const mxArray *c98_emlrt_marshallOut(const char * c98_u)
{
  const mxArray *c98_y = NULL;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", c98_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c98_u)), false);
  return c98_y;
}

static const mxArray *c98_b_emlrt_marshallOut(const uint32_T c98_u)
{
  const mxArray *c98_y = NULL;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 7, 0U, 0U, 0U, 0), false);
  return c98_y;
}

static real32_T c98_decomp(SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *
  chartInstance, uint16_T c98_u)
{
  real32_T c98_y;
  uint32_T c98_debug_family_var_map[4];
  real32_T c98_b_u;
  real_T c98_nargin = 1.0;
  real_T c98_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c98_b_debug_family_names,
    c98_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_b_u, MAX_uint32_T,
    c98_b_sf_marshallOut, c98_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_nargin, 1U, c98_e_sf_marshallOut,
    c98_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_nargout, 2U, c98_e_sf_marshallOut,
    c98_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_u, 0U, c98_f_sf_marshallOut,
    c98_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c98_y, 3U, c98_b_sf_marshallOut,
    c98_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 66);
  c98_b_u = (real32_T)c98_u;
  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 68);
  if (CV_EML_IF(0, 1, 1, c98_b_u > 32767.0F)) {
    _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 69);
    c98_y = -65536.0F + c98_b_u;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, 71);
    c98_y = c98_b_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c98_sfEvent, -71);
  _SFD_SYMBOL_SCOPE_POP();
  return c98_y;
}

static const mxArray *c98_g_sf_marshallOut(void *chartInstanceVoid, void
  *c98_inData)
{
  const mxArray *c98_mxArrayOutData = NULL;
  int32_T c98_u;
  const mxArray *c98_y = NULL;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_mxArrayOutData = NULL;
  c98_u = *(int32_T *)c98_inData;
  c98_y = NULL;
  sf_mex_assign(&c98_y, sf_mex_create("y", &c98_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c98_mxArrayOutData, c98_y, false);
  return c98_mxArrayOutData;
}

static int32_T c98_g_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId)
{
  int32_T c98_y;
  int32_T c98_i26;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), &c98_i26, 1, 6, 0U, 0, 0U, 0);
  c98_y = c98_i26;
  sf_mex_destroy(&c98_u);
  return c98_y;
}

static void c98_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c98_mxArrayInData, const char_T *c98_varName, void *c98_outData)
{
  const mxArray *c98_b_sfEvent;
  const char_T *c98_identifier;
  emlrtMsgIdentifier c98_thisId;
  int32_T c98_y;
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    chartInstanceVoid;
  c98_b_sfEvent = sf_mex_dup(c98_mxArrayInData);
  c98_identifier = c98_varName;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c98_b_sfEvent),
    &c98_thisId);
  sf_mex_destroy(&c98_b_sfEvent);
  *(int32_T *)c98_outData = c98_y;
  sf_mex_destroy(&c98_mxArrayInData);
}

static uint8_T c98_h_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_b_is_active_c98_ICARO3_Onda_bipe_controllonostro, const char_T
   *c98_identifier)
{
  uint8_T c98_y;
  emlrtMsgIdentifier c98_thisId;
  c98_thisId.fIdentifier = c98_identifier;
  c98_thisId.fParent = NULL;
  c98_y = c98_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c98_b_is_active_c98_ICARO3_Onda_bipe_controllonostro), &c98_thisId);
  sf_mex_destroy(&c98_b_is_active_c98_ICARO3_Onda_bipe_controllonostro);
  return c98_y;
}

static uint8_T c98_i_emlrt_marshallIn
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance, const
   mxArray *c98_u, const emlrtMsgIdentifier *c98_parentId)
{
  uint8_T c98_y;
  uint8_T c98_u8;
  (void)chartInstance;
  sf_mex_import(c98_parentId, sf_mex_dup(c98_u), &c98_u8, 1, 3, 0U, 0, 0U, 0);
  c98_y = c98_u8;
  sf_mex_destroy(&c98_u);
  return c98_y;
}

static void init_dsm_address_info
  (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance)
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

void sf_c98_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(588425875U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4180726097U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1958284065U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1767578810U);
}

mxArray *sf_c98_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YjkLFGOD9sbht5HufE2hkF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(14);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c98_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c98_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c98_ICARO3_Onda_bipe_controllonostro
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"a\",},{M[1],M[15],T\"g\",},{M[1],M[14],T\"t\",},{M[8],M[0],T\"is_active_c98_ICARO3_Onda_bipe_controllonostro\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c98_ICARO3_Onda_bipe_controllonostro_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostroMachineNumber_,
           98,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"a");
          _SFD_SET_DATA_PROPS(2,1,1,0,"mpu9150_gyroacc_enabled");
          _SFD_SET_DATA_PROPS(3,2,0,1,"t");
          _SFD_SET_DATA_PROPS(4,2,0,1,"g");
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
        _SFD_CV_INIT_EML(0,1,2,2,0,7,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1732);
        _SFD_CV_INIT_EML_FCN(0,1,"decomp",1734,-1,1847);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,1013,-1,1037);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,1067,-1,1091);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,1118,-1,1143);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,1200,-1,1226);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,1254,-1,1280);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,907,-1,931);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,962,-1,986);
        _SFD_CV_INIT_EML_IF(0,1,0,74,107,-1,124);
        _SFD_CV_INIT_EML_IF(0,1,1,1773,1787,1816,1843);

        {
          unsigned int dimVector[1];
          dimVector[0]= 14;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c98_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c98_sf_marshallOut,(MexInFcnForType)
            c98_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c98_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c98_b_sf_marshallOut,(MexInFcnForType)
          c98_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c98_sf_marshallOut,(MexInFcnForType)
            c98_sf_marshallIn);
        }

        {
          uint8_T *c98_mpu9150_gyroacc_enabled;
          real32_T *c98_t;
          uint16_T (*c98_u)[14];
          real32_T (*c98_a)[3];
          real32_T (*c98_g)[3];
          c98_g = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c98_t = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c98_mpu9150_gyroacc_enabled = (uint8_T *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c98_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c98_u = (uint16_T (*)[14])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c98_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c98_a);
          _SFD_SET_DATA_VALUE_PTR(2U, c98_mpu9150_gyroacc_enabled);
          _SFD_SET_DATA_VALUE_PTR(3U, c98_t);
          _SFD_SET_DATA_VALUE_PTR(4U, *c98_g);
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
  return "hdsIUO1GvTlIhlXoDjCG9F";
}

static void sf_opaque_initialize_c98_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
  initialize_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c98_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  enable_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c98_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  disable_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c98_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  sf_gateway_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c98_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c98_ICARO3_Onda_bipe_controllonostro();/* state var info */
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

extern void sf_internal_set_sim_state_c98_ICARO3_Onda_bipe_controllonostro
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
    sf_get_sim_state_info_c98_ICARO3_Onda_bipe_controllonostro();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c98_ICARO3_Onda_bipe_controllonostro(SimStruct* S)
{
  return sf_internal_get_sim_state_c98_ICARO3_Onda_bipe_controllonostro(S);
}

static void sf_opaque_set_sim_state_c98_ICARO3_Onda_bipe_controllonostro
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c98_ICARO3_Onda_bipe_controllonostro(S, st);
}

static void sf_opaque_terminate_c98_ICARO3_Onda_bipe_controllonostro(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_optimization_info();
    }

    finalize_c98_ICARO3_Onda_bipe_controllonostro
      ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc98_ICARO3_Onda_bipe_controllonostro
    ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c98_ICARO3_Onda_bipe_controllonostro(SimStruct *
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
    initialize_params_c98_ICARO3_Onda_bipe_controllonostro
      ((SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c98_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      98);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,98,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,98,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,98);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,98,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,98,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,98);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1957792975U));
  ssSetChecksum1(S,(2471395709U));
  ssSetChecksum2(S,(3371522706U));
  ssSetChecksum3(S,(1104871982U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c98_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c98_ICARO3_Onda_bipe_controllonostro(SimStruct *S)
{
  SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct *)
    utMalloc(sizeof(SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc98_ICARO3_Onda_bipe_controllonostroInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c98_ICARO3_Onda_bipe_controllonostro;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c98_ICARO3_Onda_bipe_controllonostro;
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

void c98_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c98_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c98_ICARO3_Onda_bipe_controllonostro(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c98_ICARO3_Onda_bipe_controllonostro(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c98_ICARO3_Onda_bipe_controllonostro_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
