/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_yaw_sfun.h"
#include "c96_ICARO3_Onda_bipe_yaw.h"
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
static const char * c96_debug_family_names[5] = { "nargin", "nargout", "h_raw",
  "CAL_PARAM", "h_calib" };

/* Function Declarations */
static void initialize_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void initialize_params_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void enable_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void disable_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void c96_update_debugger_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void set_sim_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance, const mxArray
   *c96_st);
static void finalize_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void sf_gateway_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void c96_chartstep_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void initSimStructsc96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c96_machineNumber, uint32_T
  c96_chartNumber, uint32_T c96_instanceNumber);
static const mxArray *c96_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData);
static void c96_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_h_calib, const char_T *c96_identifier,
  real_T c96_y[3]);
static void c96_b_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId,
  real_T c96_y[3]);
static void c96_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData);
static const mxArray *c96_b_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData);
static void c96_c_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId,
  real_T c96_y[9]);
static void c96_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData);
static const mxArray *c96_c_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData);
static real_T c96_d_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId);
static void c96_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData);
static void c96_info_helper(const mxArray **c96_info);
static const mxArray *c96_emlrt_marshallOut(const char * c96_u);
static const mxArray *c96_b_emlrt_marshallOut(const uint32_T c96_u);
static const mxArray *c96_d_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData);
static int32_T c96_e_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId);
static void c96_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData);
static uint8_T c96_f_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_b_is_active_c96_ICARO3_Onda_bipe_yaw, const
  char_T *c96_identifier);
static uint8_T c96_g_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId);
static void init_dsm_address_info(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  chartInstance->c96_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c96_is_active_c96_ICARO3_Onda_bipe_yaw = 0U;
}

static void initialize_params_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  real_T c96_dv0[9];
  int32_T c96_i0;
  sf_mex_import_named("CAL_PARAM", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c96_dv0, 0, 0, 0U, 1, 0U, 1, 9);
  for (c96_i0 = 0; c96_i0 < 9; c96_i0++) {
    chartInstance->c96_CAL_PARAM[c96_i0] = c96_dv0[c96_i0];
  }
}

static void enable_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c96_update_debugger_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  const mxArray *c96_st;
  const mxArray *c96_y = NULL;
  int32_T c96_i1;
  real_T c96_u[3];
  const mxArray *c96_b_y = NULL;
  uint8_T c96_hoistedGlobal;
  uint8_T c96_b_u;
  const mxArray *c96_c_y = NULL;
  real_T (*c96_h_calib)[3];
  c96_h_calib = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c96_st = NULL;
  c96_st = NULL;
  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_createcellmatrix(2, 1), false);
  for (c96_i1 = 0; c96_i1 < 3; c96_i1++) {
    c96_u[c96_i1] = (*c96_h_calib)[c96_i1];
  }

  c96_b_y = NULL;
  sf_mex_assign(&c96_b_y, sf_mex_create("y", c96_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c96_y, 0, c96_b_y);
  c96_hoistedGlobal = chartInstance->c96_is_active_c96_ICARO3_Onda_bipe_yaw;
  c96_b_u = c96_hoistedGlobal;
  c96_c_y = NULL;
  sf_mex_assign(&c96_c_y, sf_mex_create("y", &c96_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c96_y, 1, c96_c_y);
  sf_mex_assign(&c96_st, c96_y, false);
  return c96_st;
}

static void set_sim_state_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance, const mxArray
   *c96_st)
{
  const mxArray *c96_u;
  real_T c96_dv1[3];
  int32_T c96_i2;
  real_T (*c96_h_calib)[3];
  c96_h_calib = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c96_doneDoubleBufferReInit = true;
  c96_u = sf_mex_dup(c96_st);
  c96_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c96_u, 0)),
                       "h_calib", c96_dv1);
  for (c96_i2 = 0; c96_i2 < 3; c96_i2++) {
    (*c96_h_calib)[c96_i2] = c96_dv1[c96_i2];
  }

  chartInstance->c96_is_active_c96_ICARO3_Onda_bipe_yaw = c96_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c96_u, 1)),
     "is_active_c96_ICARO3_Onda_bipe_yaw");
  sf_mex_destroy(&c96_u);
  c96_update_debugger_state_c96_ICARO3_Onda_bipe_yaw(chartInstance);
  sf_mex_destroy(&c96_st);
}

static void finalize_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  int32_T c96_i3;
  int32_T c96_i4;
  int32_T c96_i5;
  real_T (*c96_h_calib)[3];
  real_T (*c96_h_raw)[3];
  c96_h_calib = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c96_h_raw = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c96_sfEvent);
  for (c96_i3 = 0; c96_i3 < 3; c96_i3++) {
    _SFD_DATA_RANGE_CHECK((*c96_h_raw)[c96_i3], 0U);
  }

  chartInstance->c96_sfEvent = CALL_EVENT;
  c96_chartstep_c96_ICARO3_Onda_bipe_yaw(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO3_Onda_bipe_yawMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c96_i4 = 0; c96_i4 < 3; c96_i4++) {
    _SFD_DATA_RANGE_CHECK((*c96_h_calib)[c96_i4], 1U);
  }

  for (c96_i5 = 0; c96_i5 < 9; c96_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c96_CAL_PARAM[c96_i5], 2U);
  }
}

static void c96_chartstep_c96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  int32_T c96_i6;
  real_T c96_h_raw[3];
  int32_T c96_i7;
  real_T c96_b_CAL_PARAM[9];
  uint32_T c96_debug_family_var_map[5];
  real_T c96_nargin = 2.0;
  real_T c96_nargout = 1.0;
  real_T c96_h_calib[3];
  int32_T c96_i8;
  real_T c96_A;
  real_T c96_B;
  real_T c96_x;
  real_T c96_y;
  real_T c96_b_x;
  real_T c96_b_y;
  real_T c96_c_x;
  real_T c96_c_y;
  real_T c96_d_y;
  real_T c96_b_A;
  real_T c96_b_B;
  real_T c96_d_x;
  real_T c96_e_y;
  real_T c96_e_x;
  real_T c96_f_y;
  real_T c96_f_x;
  real_T c96_g_y;
  real_T c96_h_y;
  real_T c96_c_A;
  real_T c96_c_B;
  real_T c96_g_x;
  real_T c96_i_y;
  real_T c96_h_x;
  real_T c96_j_y;
  real_T c96_i_x;
  real_T c96_k_y;
  real_T c96_l_y;
  real_T c96_j_x;
  real_T c96_k_x;
  real_T c96_l_x;
  real_T c96_m_x;
  real_T c96_d_A;
  real_T c96_d_B;
  real_T c96_n_x;
  real_T c96_m_y;
  real_T c96_o_x;
  real_T c96_n_y;
  real_T c96_p_x;
  real_T c96_o_y;
  real_T c96_p_y;
  real_T c96_e_A;
  real_T c96_e_B;
  real_T c96_q_x;
  real_T c96_q_y;
  real_T c96_r_x;
  real_T c96_r_y;
  real_T c96_s_x;
  real_T c96_s_y;
  real_T c96_t_y;
  real_T c96_f_A;
  real_T c96_f_B;
  real_T c96_t_x;
  real_T c96_u_y;
  real_T c96_u_x;
  real_T c96_v_y;
  real_T c96_v_x;
  real_T c96_w_y;
  real_T c96_x_y;
  real_T c96_w_x;
  real_T c96_x_x;
  real_T c96_y_x;
  real_T c96_ab_x;
  real_T c96_bb_x;
  real_T c96_cb_x;
  real_T c96_db_x;
  real_T c96_eb_x;
  real_T c96_g_A;
  real_T c96_g_B;
  real_T c96_fb_x;
  real_T c96_y_y;
  real_T c96_gb_x;
  real_T c96_ab_y;
  real_T c96_hb_x;
  real_T c96_bb_y;
  real_T c96_cb_y;
  real_T c96_h_A;
  real_T c96_h_B;
  real_T c96_ib_x;
  real_T c96_db_y;
  real_T c96_jb_x;
  real_T c96_eb_y;
  real_T c96_kb_x;
  real_T c96_fb_y;
  real_T c96_gb_y;
  real_T c96_i_A;
  real_T c96_i_B;
  real_T c96_lb_x;
  real_T c96_hb_y;
  real_T c96_mb_x;
  real_T c96_ib_y;
  real_T c96_nb_x;
  real_T c96_jb_y;
  real_T c96_kb_y;
  real_T c96_ob_x;
  real_T c96_pb_x;
  real_T c96_qb_x;
  real_T c96_rb_x;
  real_T c96_sb_x;
  real_T c96_tb_x;
  real_T c96_j_A;
  real_T c96_j_B;
  real_T c96_ub_x;
  real_T c96_lb_y;
  real_T c96_vb_x;
  real_T c96_mb_y;
  real_T c96_wb_x;
  real_T c96_nb_y;
  real_T c96_ob_y;
  int32_T c96_i9;
  real_T (*c96_b_h_calib)[3];
  real_T (*c96_b_h_raw)[3];
  c96_b_h_calib = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c96_b_h_raw = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c96_sfEvent);
  for (c96_i6 = 0; c96_i6 < 3; c96_i6++) {
    c96_h_raw[c96_i6] = (*c96_b_h_raw)[c96_i6];
  }

  for (c96_i7 = 0; c96_i7 < 9; c96_i7++) {
    c96_b_CAL_PARAM[c96_i7] = chartInstance->c96_CAL_PARAM[c96_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c96_debug_family_names,
    c96_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c96_nargin, 0U, c96_c_sf_marshallOut,
    c96_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c96_nargout, 1U, c96_c_sf_marshallOut,
    c96_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c96_h_raw, 2U, c96_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c96_b_CAL_PARAM, 3U, c96_b_sf_marshallOut,
    c96_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c96_h_calib, 4U, c96_sf_marshallOut,
    c96_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c96_sfEvent, 4);
  for (c96_i8 = 0; c96_i8 < 3; c96_i8++) {
    c96_h_calib[c96_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c96_sfEvent, 5);
  c96_A = c96_h_raw[0] - c96_b_CAL_PARAM[0];
  c96_B = c96_b_CAL_PARAM[3];
  c96_x = c96_A;
  c96_y = c96_B;
  c96_b_x = c96_x;
  c96_b_y = c96_y;
  c96_c_x = c96_b_x;
  c96_c_y = c96_b_y;
  c96_d_y = c96_c_x / c96_c_y;
  c96_h_calib[0] = c96_d_y;
  _SFD_EML_CALL(0U, chartInstance->c96_sfEvent, 6);
  c96_b_A = c96_h_raw[1] - c96_b_CAL_PARAM[1];
  c96_b_B = c96_b_CAL_PARAM[4];
  c96_d_x = c96_b_A;
  c96_e_y = c96_b_B;
  c96_e_x = c96_d_x;
  c96_f_y = c96_e_y;
  c96_f_x = c96_e_x;
  c96_g_y = c96_f_y;
  c96_h_y = c96_f_x / c96_g_y;
  c96_c_A = c96_h_raw[0] - c96_b_CAL_PARAM[0];
  c96_c_B = c96_b_CAL_PARAM[3];
  c96_g_x = c96_c_A;
  c96_i_y = c96_c_B;
  c96_h_x = c96_g_x;
  c96_j_y = c96_i_y;
  c96_i_x = c96_h_x;
  c96_k_y = c96_j_y;
  c96_l_y = c96_i_x / c96_k_y;
  c96_j_x = c96_b_CAL_PARAM[6];
  c96_k_x = c96_j_x;
  c96_k_x = muDoubleScalarSin(c96_k_x);
  c96_l_x = c96_b_CAL_PARAM[6];
  c96_m_x = c96_l_x;
  c96_m_x = muDoubleScalarCos(c96_m_x);
  c96_d_A = c96_h_y - c96_l_y * c96_k_x;
  c96_d_B = c96_m_x;
  c96_n_x = c96_d_A;
  c96_m_y = c96_d_B;
  c96_o_x = c96_n_x;
  c96_n_y = c96_m_y;
  c96_p_x = c96_o_x;
  c96_o_y = c96_n_y;
  c96_p_y = c96_p_x / c96_o_y;
  c96_h_calib[1] = c96_p_y;
  _SFD_EML_CALL(0U, chartInstance->c96_sfEvent, 8);
  c96_e_A = c96_h_raw[2] - c96_b_CAL_PARAM[2];
  c96_e_B = c96_b_CAL_PARAM[5];
  c96_q_x = c96_e_A;
  c96_q_y = c96_e_B;
  c96_r_x = c96_q_x;
  c96_r_y = c96_q_y;
  c96_s_x = c96_r_x;
  c96_s_y = c96_r_y;
  c96_t_y = c96_s_x / c96_s_y;
  c96_f_A = c96_h_raw[0] - c96_b_CAL_PARAM[0];
  c96_f_B = c96_b_CAL_PARAM[3];
  c96_t_x = c96_f_A;
  c96_u_y = c96_f_B;
  c96_u_x = c96_t_x;
  c96_v_y = c96_u_y;
  c96_v_x = c96_u_x;
  c96_w_y = c96_v_y;
  c96_x_y = c96_v_x / c96_w_y;
  c96_w_x = c96_b_CAL_PARAM[7];
  c96_x_x = c96_w_x;
  c96_x_x = muDoubleScalarSin(c96_x_x);
  c96_y_x = c96_b_CAL_PARAM[8];
  c96_ab_x = c96_y_x;
  c96_ab_x = muDoubleScalarCos(c96_ab_x);
  c96_bb_x = c96_b_CAL_PARAM[8];
  c96_cb_x = c96_bb_x;
  c96_cb_x = muDoubleScalarSin(c96_cb_x);
  c96_db_x = c96_b_CAL_PARAM[6];
  c96_eb_x = c96_db_x;
  c96_eb_x = muDoubleScalarCos(c96_eb_x);
  c96_g_A = c96_cb_x;
  c96_g_B = c96_eb_x;
  c96_fb_x = c96_g_A;
  c96_y_y = c96_g_B;
  c96_gb_x = c96_fb_x;
  c96_ab_y = c96_y_y;
  c96_hb_x = c96_gb_x;
  c96_bb_y = c96_ab_y;
  c96_cb_y = c96_hb_x / c96_bb_y;
  c96_h_A = c96_h_raw[1] - c96_b_CAL_PARAM[1];
  c96_h_B = c96_b_CAL_PARAM[4];
  c96_ib_x = c96_h_A;
  c96_db_y = c96_h_B;
  c96_jb_x = c96_ib_x;
  c96_eb_y = c96_db_y;
  c96_kb_x = c96_jb_x;
  c96_fb_y = c96_eb_y;
  c96_gb_y = c96_kb_x / c96_fb_y;
  c96_i_A = c96_h_raw[0] - c96_b_CAL_PARAM[0];
  c96_i_B = c96_b_CAL_PARAM[3];
  c96_lb_x = c96_i_A;
  c96_hb_y = c96_i_B;
  c96_mb_x = c96_lb_x;
  c96_ib_y = c96_hb_y;
  c96_nb_x = c96_mb_x;
  c96_jb_y = c96_ib_y;
  c96_kb_y = c96_nb_x / c96_jb_y;
  c96_ob_x = c96_b_CAL_PARAM[6];
  c96_pb_x = c96_ob_x;
  c96_pb_x = muDoubleScalarSin(c96_pb_x);
  c96_qb_x = c96_b_CAL_PARAM[7];
  c96_rb_x = c96_qb_x;
  c96_rb_x = muDoubleScalarCos(c96_rb_x);
  c96_sb_x = c96_b_CAL_PARAM[8];
  c96_tb_x = c96_sb_x;
  c96_tb_x = muDoubleScalarCos(c96_tb_x);
  c96_j_A = (c96_t_y - c96_x_y * c96_x_x * c96_ab_x) - c96_cb_y * (c96_gb_y -
    c96_kb_y) * c96_pb_x;
  c96_j_B = c96_rb_x * c96_tb_x;
  c96_ub_x = c96_j_A;
  c96_lb_y = c96_j_B;
  c96_vb_x = c96_ub_x;
  c96_mb_y = c96_lb_y;
  c96_wb_x = c96_vb_x;
  c96_nb_y = c96_mb_y;
  c96_ob_y = c96_wb_x / c96_nb_y;
  c96_h_calib[2] = c96_ob_y;
  _SFD_EML_CALL(0U, chartInstance->c96_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c96_i9 = 0; c96_i9 < 3; c96_i9++) {
    (*c96_b_h_calib)[c96_i9] = c96_h_calib[c96_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c96_sfEvent);
}

static void initSimStructsc96_ICARO3_Onda_bipe_yaw
  (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c96_machineNumber, uint32_T
  c96_chartNumber, uint32_T c96_instanceNumber)
{
  (void)c96_machineNumber;
  (void)c96_chartNumber;
  (void)c96_instanceNumber;
}

static const mxArray *c96_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData)
{
  const mxArray *c96_mxArrayOutData = NULL;
  int32_T c96_i10;
  real_T c96_b_inData[3];
  int32_T c96_i11;
  real_T c96_u[3];
  const mxArray *c96_y = NULL;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_mxArrayOutData = NULL;
  for (c96_i10 = 0; c96_i10 < 3; c96_i10++) {
    c96_b_inData[c96_i10] = (*(real_T (*)[3])c96_inData)[c96_i10];
  }

  for (c96_i11 = 0; c96_i11 < 3; c96_i11++) {
    c96_u[c96_i11] = c96_b_inData[c96_i11];
  }

  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", c96_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c96_mxArrayOutData, c96_y, false);
  return c96_mxArrayOutData;
}

static void c96_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_h_calib, const char_T *c96_identifier,
  real_T c96_y[3])
{
  emlrtMsgIdentifier c96_thisId;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c96_h_calib), &c96_thisId,
    c96_y);
  sf_mex_destroy(&c96_h_calib);
}

static void c96_b_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId,
  real_T c96_y[3])
{
  real_T c96_dv2[3];
  int32_T c96_i12;
  (void)chartInstance;
  sf_mex_import(c96_parentId, sf_mex_dup(c96_u), c96_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c96_i12 = 0; c96_i12 < 3; c96_i12++) {
    c96_y[c96_i12] = c96_dv2[c96_i12];
  }

  sf_mex_destroy(&c96_u);
}

static void c96_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData)
{
  const mxArray *c96_h_calib;
  const char_T *c96_identifier;
  emlrtMsgIdentifier c96_thisId;
  real_T c96_y[3];
  int32_T c96_i13;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_h_calib = sf_mex_dup(c96_mxArrayInData);
  c96_identifier = c96_varName;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c96_h_calib), &c96_thisId,
    c96_y);
  sf_mex_destroy(&c96_h_calib);
  for (c96_i13 = 0; c96_i13 < 3; c96_i13++) {
    (*(real_T (*)[3])c96_outData)[c96_i13] = c96_y[c96_i13];
  }

  sf_mex_destroy(&c96_mxArrayInData);
}

static const mxArray *c96_b_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData)
{
  const mxArray *c96_mxArrayOutData = NULL;
  int32_T c96_i14;
  real_T c96_b_inData[9];
  int32_T c96_i15;
  real_T c96_u[9];
  const mxArray *c96_y = NULL;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_mxArrayOutData = NULL;
  for (c96_i14 = 0; c96_i14 < 9; c96_i14++) {
    c96_b_inData[c96_i14] = (*(real_T (*)[9])c96_inData)[c96_i14];
  }

  for (c96_i15 = 0; c96_i15 < 9; c96_i15++) {
    c96_u[c96_i15] = c96_b_inData[c96_i15];
  }

  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", c96_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c96_mxArrayOutData, c96_y, false);
  return c96_mxArrayOutData;
}

static void c96_c_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId,
  real_T c96_y[9])
{
  real_T c96_dv3[9];
  int32_T c96_i16;
  (void)chartInstance;
  sf_mex_import(c96_parentId, sf_mex_dup(c96_u), c96_dv3, 1, 0, 0U, 1, 0U, 1, 9);
  for (c96_i16 = 0; c96_i16 < 9; c96_i16++) {
    c96_y[c96_i16] = c96_dv3[c96_i16];
  }

  sf_mex_destroy(&c96_u);
}

static void c96_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData)
{
  const mxArray *c96_b_CAL_PARAM;
  const char_T *c96_identifier;
  emlrtMsgIdentifier c96_thisId;
  real_T c96_y[9];
  int32_T c96_i17;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_b_CAL_PARAM = sf_mex_dup(c96_mxArrayInData);
  c96_identifier = c96_varName;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c96_b_CAL_PARAM), &c96_thisId,
    c96_y);
  sf_mex_destroy(&c96_b_CAL_PARAM);
  for (c96_i17 = 0; c96_i17 < 9; c96_i17++) {
    (*(real_T (*)[9])c96_outData)[c96_i17] = c96_y[c96_i17];
  }

  sf_mex_destroy(&c96_mxArrayInData);
}

static const mxArray *c96_c_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData)
{
  const mxArray *c96_mxArrayOutData = NULL;
  real_T c96_u;
  const mxArray *c96_y = NULL;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_mxArrayOutData = NULL;
  c96_u = *(real_T *)c96_inData;
  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", &c96_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c96_mxArrayOutData, c96_y, false);
  return c96_mxArrayOutData;
}

static real_T c96_d_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId)
{
  real_T c96_y;
  real_T c96_d0;
  (void)chartInstance;
  sf_mex_import(c96_parentId, sf_mex_dup(c96_u), &c96_d0, 1, 0, 0U, 0, 0U, 0);
  c96_y = c96_d0;
  sf_mex_destroy(&c96_u);
  return c96_y;
}

static void c96_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData)
{
  const mxArray *c96_nargout;
  const char_T *c96_identifier;
  emlrtMsgIdentifier c96_thisId;
  real_T c96_y;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_nargout = sf_mex_dup(c96_mxArrayInData);
  c96_identifier = c96_varName;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_y = c96_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c96_nargout),
    &c96_thisId);
  sf_mex_destroy(&c96_nargout);
  *(real_T *)c96_outData = c96_y;
  sf_mex_destroy(&c96_mxArrayInData);
}

const mxArray *sf_c96_ICARO3_Onda_bipe_yaw_get_eml_resolved_functions_info(void)
{
  const mxArray *c96_nameCaptureInfo = NULL;
  c96_nameCaptureInfo = NULL;
  sf_mex_assign(&c96_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c96_info_helper(&c96_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c96_nameCaptureInfo);
  return c96_nameCaptureInfo;
}

static void c96_info_helper(const mxArray **c96_info)
{
  const mxArray *c96_rhs0 = NULL;
  const mxArray *c96_lhs0 = NULL;
  const mxArray *c96_rhs1 = NULL;
  const mxArray *c96_lhs1 = NULL;
  const mxArray *c96_rhs2 = NULL;
  const mxArray *c96_lhs2 = NULL;
  const mxArray *c96_rhs3 = NULL;
  const mxArray *c96_lhs3 = NULL;
  const mxArray *c96_rhs4 = NULL;
  const mxArray *c96_lhs4 = NULL;
  const mxArray *c96_rhs5 = NULL;
  const mxArray *c96_lhs5 = NULL;
  const mxArray *c96_rhs6 = NULL;
  const mxArray *c96_lhs6 = NULL;
  const mxArray *c96_rhs7 = NULL;
  const mxArray *c96_lhs7 = NULL;
  const mxArray *c96_rhs8 = NULL;
  const mxArray *c96_lhs8 = NULL;
  const mxArray *c96_rhs9 = NULL;
  const mxArray *c96_lhs9 = NULL;
  const mxArray *c96_rhs10 = NULL;
  const mxArray *c96_lhs10 = NULL;
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c96_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c96_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c96_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c96_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c96_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c96_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c96_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c96_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c96_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c96_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c96_info, c96_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c96_info, c96_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c96_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c96_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c96_info, sf_mex_duplicatearraysafe(&c96_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c96_rhs0);
  sf_mex_destroy(&c96_lhs0);
  sf_mex_destroy(&c96_rhs1);
  sf_mex_destroy(&c96_lhs1);
  sf_mex_destroy(&c96_rhs2);
  sf_mex_destroy(&c96_lhs2);
  sf_mex_destroy(&c96_rhs3);
  sf_mex_destroy(&c96_lhs3);
  sf_mex_destroy(&c96_rhs4);
  sf_mex_destroy(&c96_lhs4);
  sf_mex_destroy(&c96_rhs5);
  sf_mex_destroy(&c96_lhs5);
  sf_mex_destroy(&c96_rhs6);
  sf_mex_destroy(&c96_lhs6);
  sf_mex_destroy(&c96_rhs7);
  sf_mex_destroy(&c96_lhs7);
  sf_mex_destroy(&c96_rhs8);
  sf_mex_destroy(&c96_lhs8);
  sf_mex_destroy(&c96_rhs9);
  sf_mex_destroy(&c96_lhs9);
  sf_mex_destroy(&c96_rhs10);
  sf_mex_destroy(&c96_lhs10);
}

static const mxArray *c96_emlrt_marshallOut(const char * c96_u)
{
  const mxArray *c96_y = NULL;
  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", c96_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c96_u)), false);
  return c96_y;
}

static const mxArray *c96_b_emlrt_marshallOut(const uint32_T c96_u)
{
  const mxArray *c96_y = NULL;
  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", &c96_u, 7, 0U, 0U, 0U, 0), false);
  return c96_y;
}

static const mxArray *c96_d_sf_marshallOut(void *chartInstanceVoid, void
  *c96_inData)
{
  const mxArray *c96_mxArrayOutData = NULL;
  int32_T c96_u;
  const mxArray *c96_y = NULL;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_mxArrayOutData = NULL;
  c96_u = *(int32_T *)c96_inData;
  c96_y = NULL;
  sf_mex_assign(&c96_y, sf_mex_create("y", &c96_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c96_mxArrayOutData, c96_y, false);
  return c96_mxArrayOutData;
}

static int32_T c96_e_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId)
{
  int32_T c96_y;
  int32_T c96_i18;
  (void)chartInstance;
  sf_mex_import(c96_parentId, sf_mex_dup(c96_u), &c96_i18, 1, 6, 0U, 0, 0U, 0);
  c96_y = c96_i18;
  sf_mex_destroy(&c96_u);
  return c96_y;
}

static void c96_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c96_mxArrayInData, const char_T *c96_varName, void *c96_outData)
{
  const mxArray *c96_b_sfEvent;
  const char_T *c96_identifier;
  emlrtMsgIdentifier c96_thisId;
  int32_T c96_y;
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)chartInstanceVoid;
  c96_b_sfEvent = sf_mex_dup(c96_mxArrayInData);
  c96_identifier = c96_varName;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_y = c96_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c96_b_sfEvent),
    &c96_thisId);
  sf_mex_destroy(&c96_b_sfEvent);
  *(int32_T *)c96_outData = c96_y;
  sf_mex_destroy(&c96_mxArrayInData);
}

static uint8_T c96_f_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_b_is_active_c96_ICARO3_Onda_bipe_yaw, const
  char_T *c96_identifier)
{
  uint8_T c96_y;
  emlrtMsgIdentifier c96_thisId;
  c96_thisId.fIdentifier = c96_identifier;
  c96_thisId.fParent = NULL;
  c96_y = c96_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c96_b_is_active_c96_ICARO3_Onda_bipe_yaw), &c96_thisId);
  sf_mex_destroy(&c96_b_is_active_c96_ICARO3_Onda_bipe_yaw);
  return c96_y;
}

static uint8_T c96_g_emlrt_marshallIn(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
  *chartInstance, const mxArray *c96_u, const emlrtMsgIdentifier *c96_parentId)
{
  uint8_T c96_y;
  uint8_T c96_u0;
  (void)chartInstance;
  sf_mex_import(c96_parentId, sf_mex_dup(c96_u), &c96_u0, 1, 3, 0U, 0, 0U, 0);
  c96_y = c96_u0;
  sf_mex_destroy(&c96_u);
  return c96_y;
}

static void init_dsm_address_info(SFc96_ICARO3_Onda_bipe_yawInstanceStruct
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

void sf_c96_ICARO3_Onda_bipe_yaw_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(900775743U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(34344813U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(54992102U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2977901411U);
}

mxArray *sf_c96_ICARO3_Onda_bipe_yaw_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HGw6JxblLekhRJUnRx7OcF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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

mxArray *sf_c96_ICARO3_Onda_bipe_yaw_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c96_ICARO3_Onda_bipe_yaw_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c96_ICARO3_Onda_bipe_yaw(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"h_calib\",},{M[8],M[0],T\"is_active_c96_ICARO3_Onda_bipe_yaw\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c96_ICARO3_Onda_bipe_yaw_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_yawMachineNumber_,
           96,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"h_raw");
          _SFD_SET_DATA_PROPS(1,2,0,1,"h_calib");
          _SFD_SET_DATA_PROPS(2,10,0,0,"CAL_PARAM");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,588);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c96_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c96_sf_marshallOut,(MexInFcnForType)
            c96_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c96_b_sf_marshallOut,(MexInFcnForType)
            c96_b_sf_marshallIn);
        }

        {
          real_T (*c96_h_raw)[3];
          real_T (*c96_h_calib)[3];
          c96_h_calib = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c96_h_raw = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c96_h_raw);
          _SFD_SET_DATA_VALUE_PTR(1U, *c96_h_calib);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c96_CAL_PARAM);
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
  return "I6ujCSVLmUs6yrsYWq7CTF";
}

static void sf_opaque_initialize_c96_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c96_ICARO3_Onda_bipe_yaw
    ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar);
  initialize_c96_ICARO3_Onda_bipe_yaw((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c96_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  enable_c96_ICARO3_Onda_bipe_yaw((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c96_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  disable_c96_ICARO3_Onda_bipe_yaw((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c96_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  sf_gateway_c96_ICARO3_Onda_bipe_yaw((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c96_ICARO3_Onda_bipe_yaw
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c96_ICARO3_Onda_bipe_yaw
    ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c96_ICARO3_Onda_bipe_yaw();/* state var info */
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

extern void sf_internal_set_sim_state_c96_ICARO3_Onda_bipe_yaw(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c96_ICARO3_Onda_bipe_yaw();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c96_ICARO3_Onda_bipe_yaw
    ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c96_ICARO3_Onda_bipe_yaw(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c96_ICARO3_Onda_bipe_yaw(S);
}

static void sf_opaque_set_sim_state_c96_ICARO3_Onda_bipe_yaw(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c96_ICARO3_Onda_bipe_yaw(S, st);
}

static void sf_opaque_terminate_c96_ICARO3_Onda_bipe_yaw(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_yaw_optimization_info();
    }

    finalize_c96_ICARO3_Onda_bipe_yaw((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)
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
  initSimStructsc96_ICARO3_Onda_bipe_yaw
    ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c96_ICARO3_Onda_bipe_yaw(SimStruct *S)
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
    initialize_params_c96_ICARO3_Onda_bipe_yaw
      ((SFc96_ICARO3_Onda_bipe_yawInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c96_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  /* Actual parameters from chart:
     CAL_PARAM
   */
  const char_T *rtParamNames[] = { "CAL_PARAM" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for CAL_PARAM*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO3_Onda_bipe_yaw_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      96);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,96,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,96,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,96);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,96,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,96,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,96);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3883109036U));
  ssSetChecksum1(S,(4129792793U));
  ssSetChecksum2(S,(2293315229U));
  ssSetChecksum3(S,(343383843U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c96_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c96_ICARO3_Onda_bipe_yaw(SimStruct *S)
{
  SFc96_ICARO3_Onda_bipe_yawInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc96_ICARO3_Onda_bipe_yawInstanceStruct *)utMalloc(sizeof
    (SFc96_ICARO3_Onda_bipe_yawInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc96_ICARO3_Onda_bipe_yawInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.mdlStart = mdlStart_c96_ICARO3_Onda_bipe_yaw;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c96_ICARO3_Onda_bipe_yaw;
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

void c96_ICARO3_Onda_bipe_yaw_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c96_ICARO3_Onda_bipe_yaw(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c96_ICARO3_Onda_bipe_yaw(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c96_ICARO3_Onda_bipe_yaw(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c96_ICARO3_Onda_bipe_yaw_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
