/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_orientation_controllo_BIPE_sfun.h"
#include "c94_ICARO3_orientation_controllo_BIPE.h"
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
static const char * c94_debug_family_names[29] = { "AC1", "AC2", "AC3", "AC4",
  "AC5", "AC6", "B1", "B2", "MB", "MC", "MD", "X1", "X2", "B5", "B6", "X3", "B3",
  "B4", "B7", "P", "nargin", "nargout", "UT", "UP", "oss", "params",
  "bmp085_enabled", "T", "h" };

/* Function Declarations */
static void initialize_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initialize_params_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void enable_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void disable_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c94_update_debugger_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void set_sim_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_st);
static void finalize_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void sf_gateway_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c94_chartstep_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initSimStructsc94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c94_machineNumber, uint32_T
  c94_chartNumber, uint32_T c94_instanceNumber);
static const mxArray *c94_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData);
static real32_T c94_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_h, const char_T *c94_identifier);
static real32_T c94_b_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId);
static void c94_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData);
static const mxArray *c94_b_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData);
static const mxArray *c94_c_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData);
static const mxArray *c94_d_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData);
static real_T c94_c_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId);
static void c94_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData);
static void c94_info_helper(const mxArray **c94_info);
static const mxArray *c94_emlrt_marshallOut(const char * c94_u);
static const mxArray *c94_b_emlrt_marshallOut(const uint32_T c94_u);
static real32_T c94_mpower(SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct
  *chartInstance, real_T c94_a, real32_T c94_b);
static void c94_eml_scalar_eg
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c94_eml_error(SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *
  chartInstance);
static void c94_b_eml_scalar_eg
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *c94_e_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData);
static int32_T c94_d_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId);
static void c94_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData);
static uint8_T c94_e_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_b_is_active_c94_ICARO3_orientation_controllo_BIPE, const char_T *
   c94_identifier);
static uint8_T c94_f_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId);
static void init_dsm_address_info
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  chartInstance->c94_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c94_is_active_c94_ICARO3_orientation_controllo_BIPE = 0U;
}

static void initialize_params_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c94_update_debugger_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  const mxArray *c94_st;
  const mxArray *c94_y = NULL;
  real32_T c94_hoistedGlobal;
  real32_T c94_u;
  const mxArray *c94_b_y = NULL;
  real32_T c94_b_hoistedGlobal;
  real32_T c94_b_u;
  const mxArray *c94_c_y = NULL;
  uint8_T c94_c_hoistedGlobal;
  uint8_T c94_c_u;
  const mxArray *c94_d_y = NULL;
  real32_T *c94_T;
  real32_T *c94_h;
  c94_h = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c94_T = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c94_st = NULL;
  c94_st = NULL;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_createcellmatrix(3, 1), false);
  c94_hoistedGlobal = *c94_T;
  c94_u = c94_hoistedGlobal;
  c94_b_y = NULL;
  sf_mex_assign(&c94_b_y, sf_mex_create("y", &c94_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c94_y, 0, c94_b_y);
  c94_b_hoistedGlobal = *c94_h;
  c94_b_u = c94_b_hoistedGlobal;
  c94_c_y = NULL;
  sf_mex_assign(&c94_c_y, sf_mex_create("y", &c94_b_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c94_y, 1, c94_c_y);
  c94_c_hoistedGlobal =
    chartInstance->c94_is_active_c94_ICARO3_orientation_controllo_BIPE;
  c94_c_u = c94_c_hoistedGlobal;
  c94_d_y = NULL;
  sf_mex_assign(&c94_d_y, sf_mex_create("y", &c94_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c94_y, 2, c94_d_y);
  sf_mex_assign(&c94_st, c94_y, false);
  return c94_st;
}

static void set_sim_state_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_st)
{
  const mxArray *c94_u;
  real32_T *c94_T;
  real32_T *c94_h;
  c94_h = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c94_T = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c94_doneDoubleBufferReInit = true;
  c94_u = sf_mex_dup(c94_st);
  *c94_T = c94_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c94_u,
    0)), "T");
  *c94_h = c94_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c94_u,
    1)), "h");
  chartInstance->c94_is_active_c94_ICARO3_orientation_controllo_BIPE =
    c94_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c94_u, 2)),
    "is_active_c94_ICARO3_orientation_controllo_BIPE");
  sf_mex_destroy(&c94_u);
  c94_update_debugger_state_c94_ICARO3_orientation_controllo_BIPE(chartInstance);
  sf_mex_destroy(&c94_st);
}

static void finalize_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  int32_T c94_i0;
  real32_T *c94_UT;
  real32_T *c94_T;
  real32_T *c94_UP;
  real32_T *c94_h;
  real32_T *c94_oss;
  uint8_T *c94_bmp085_enabled;
  real32_T (*c94_params)[11];
  c94_bmp085_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c94_params = (real32_T (*)[11])ssGetInputPortSignal(chartInstance->S, 3);
  c94_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c94_h = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c94_UP = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c94_T = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c94_UT = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c94_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c94_UT, 0U);
  chartInstance->c94_sfEvent = CALL_EVENT;
  c94_chartstep_c94_ICARO3_orientation_controllo_BIPE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_orientation_controllo_BIPEMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c94_T, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c94_UP, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c94_h, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c94_oss, 4U);
  for (c94_i0 = 0; c94_i0 < 11; c94_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c94_params)[c94_i0], 5U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c94_bmp085_enabled, 6U);
}

static void c94_chartstep_c94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  real32_T c94_hoistedGlobal;
  real32_T c94_b_hoistedGlobal;
  real32_T c94_c_hoistedGlobal;
  uint8_T c94_d_hoistedGlobal;
  real32_T c94_UT;
  real32_T c94_UP;
  real32_T c94_oss;
  int32_T c94_i1;
  real32_T c94_params[11];
  uint8_T c94_bmp085_enabled;
  uint32_T c94_debug_family_var_map[29];
  real32_T c94_AC1;
  real32_T c94_AC2;
  real32_T c94_AC3;
  real32_T c94_AC4;
  real32_T c94_AC5;
  real32_T c94_AC6;
  real32_T c94_B1;
  real32_T c94_B2;
  real32_T c94_MB;
  real32_T c94_MC;
  real32_T c94_MD;
  real32_T c94_X1;
  real32_T c94_X2;
  real32_T c94_B5;
  real32_T c94_B6;
  real32_T c94_X3;
  real32_T c94_B3;
  real32_T c94_B4;
  real32_T c94_B7;
  real32_T c94_P;
  real_T c94_nargin = 5.0;
  real_T c94_nargout = 2.0;
  real32_T c94_T;
  real32_T c94_h;
  real32_T c94_A;
  real32_T c94_x;
  real32_T c94_b_x;
  real32_T c94_c_x;
  real32_T c94_a;
  real32_T c94_y;
  real32_T c94_b_A;
  real32_T c94_B;
  real32_T c94_d_x;
  real32_T c94_b_y;
  real32_T c94_e_x;
  real32_T c94_c_y;
  real32_T c94_f_x;
  real32_T c94_d_y;
  real32_T c94_c_A;
  real32_T c94_g_x;
  real32_T c94_h_x;
  real32_T c94_i_x;
  real32_T c94_d_A;
  real32_T c94_j_x;
  real32_T c94_k_x;
  real32_T c94_l_x;
  real32_T c94_e_y;
  real32_T c94_e_A;
  real32_T c94_m_x;
  real32_T c94_n_x;
  real32_T c94_o_x;
  real32_T c94_f_A;
  real32_T c94_p_x;
  real32_T c94_q_x;
  real32_T c94_r_x;
  real32_T c94_b_a;
  real32_T c94_f_y;
  real32_T c94_g_A;
  real32_T c94_s_x;
  real32_T c94_t_x;
  real32_T c94_u_x;
  real32_T c94_h_A;
  real32_T c94_v_x;
  real32_T c94_w_x;
  real32_T c94_x_x;
  real32_T c94_i_A;
  real32_T c94_y_x;
  real32_T c94_ab_x;
  real32_T c94_bb_x;
  real32_T c94_g_y;
  real32_T c94_j_A;
  real32_T c94_cb_x;
  real32_T c94_db_x;
  real32_T c94_eb_x;
  real32_T c94_k_A;
  real32_T c94_fb_x;
  real32_T c94_gb_x;
  real32_T c94_hb_x;
  real32_T c94_l_A;
  real32_T c94_ib_x;
  real32_T c94_jb_x;
  real32_T c94_kb_x;
  real32_T c94_c_a;
  real32_T c94_h_y;
  real32_T c94_m_A;
  real32_T c94_b_B;
  real32_T c94_lb_x;
  real32_T c94_i_y;
  real32_T c94_mb_x;
  real32_T c94_j_y;
  real32_T c94_nb_x;
  real32_T c94_k_y;
  real32_T c94_d_a;
  real32_T c94_l_y;
  real32_T c94_n_A;
  real32_T c94_c_B;
  real32_T c94_ob_x;
  real32_T c94_m_y;
  real32_T c94_pb_x;
  real32_T c94_n_y;
  real32_T c94_qb_x;
  real32_T c94_o_y;
  real32_T c94_o_A;
  real32_T c94_rb_x;
  real32_T c94_sb_x;
  real32_T c94_tb_x;
  real32_T c94_p_y;
  real32_T c94_p_A;
  real32_T c94_ub_x;
  real32_T c94_vb_x;
  real32_T c94_wb_x;
  real32_T c94_q_y;
  real32_T c94_e_a;
  real32_T c94_r_y;
  real32_T c94_q_A;
  real32_T c94_xb_x;
  real32_T c94_yb_x;
  real32_T c94_ac_x;
  real32_T c94_b;
  real32_T c94_s_y;
  real32_T c94_r_A;
  real32_T c94_bc_x;
  real32_T c94_cc_x;
  real32_T c94_dc_x;
  real32_T c94_s_A;
  real32_T c94_ec_x;
  real32_T c94_fc_x;
  real32_T c94_gc_x;
  real32_T c94_t_y;
  real32_T c94_t_A;
  real32_T c94_hc_x;
  real32_T c94_ic_x;
  real32_T c94_jc_x;
  real32_T c94_u_y;
  real32_T c94_f_a;
  real32_T c94_g_a;
  real32_T c94_h_a;
  real32_T c94_ak;
  real32_T c94_i_a;
  real32_T c94_ar;
  real32_T c94_c;
  real32_T c94_b_b;
  real32_T *c94_b_h;
  real32_T *c94_b_T;
  uint8_T *c94_b_bmp085_enabled;
  real32_T *c94_b_oss;
  real32_T *c94_b_UP;
  real32_T *c94_b_UT;
  real32_T (*c94_b_params)[11];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c94_b_bmp085_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c94_b_params = (real32_T (*)[11])ssGetInputPortSignal(chartInstance->S, 3);
  c94_b_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c94_b_h = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c94_b_UP = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c94_b_T = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c94_b_UT = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c94_sfEvent);
  c94_hoistedGlobal = *c94_b_UT;
  c94_b_hoistedGlobal = *c94_b_UP;
  c94_c_hoistedGlobal = *c94_b_oss;
  c94_d_hoistedGlobal = *c94_b_bmp085_enabled;
  c94_UT = c94_hoistedGlobal;
  c94_UP = c94_b_hoistedGlobal;
  c94_oss = c94_c_hoistedGlobal;
  for (c94_i1 = 0; c94_i1 < 11; c94_i1++) {
    c94_params[c94_i1] = (*c94_b_params)[c94_i1];
  }

  c94_bmp085_enabled = c94_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 29U, 29U, c94_debug_family_names,
    c94_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC1, 0U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC2, 1U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC3, 2U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC4, 3U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC5, 4U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_AC6, 5U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B1, 6U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B2, 7U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_MB, 8U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_MC, 9U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_MD, 10U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_X1, 11U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_X2, 12U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B5, 13U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B6, 14U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_X3, 15U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B3, 16U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B4, 17U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_B7, 18U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_P, 19U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_nargin, 20U, c94_d_sf_marshallOut,
    c94_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_nargout, 21U, c94_d_sf_marshallOut,
    c94_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c94_UT, 22U, c94_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c94_UP, 23U, c94_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c94_oss, 24U, c94_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c94_params, 25U, c94_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c94_bmp085_enabled, 26U, c94_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_T, 27U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c94_h, 28U, c94_sf_marshallOut,
    c94_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 22);
  c94_AC1 = c94_params[0];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 23);
  c94_AC2 = c94_params[1];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 24);
  c94_AC3 = c94_params[2];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 25);
  c94_AC4 = c94_params[3];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 26);
  c94_AC5 = c94_params[4];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 27);
  c94_AC6 = c94_params[5];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 29);
  c94_B1 = c94_params[6];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 30);
  c94_B2 = c94_params[7];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 32);
  c94_MB = c94_params[8];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 33);
  c94_MC = c94_params[9];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 34);
  c94_MD = c94_params[10];
  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 54);
  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c94_UT == 0.0F)) {
    if (CV_EML_COND(0, 1, 1, c94_UP == 0.0F)) {
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    if (CV_EML_COND(0, 1, 2, (real_T)c94_bmp085_enabled == 0.0)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 58);
      c94_A = (c94_UT - c94_AC6) * c94_AC5;
      c94_x = c94_A;
      c94_b_x = c94_x;
      c94_c_x = c94_b_x;
      c94_X1 = c94_c_x / 32768.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 59);
      c94_a = c94_MC;
      c94_y = c94_a * 2048.0F;
      c94_b_A = c94_y;
      c94_B = c94_X1 + c94_MD;
      c94_d_x = c94_b_A;
      c94_b_y = c94_B;
      c94_e_x = c94_d_x;
      c94_c_y = c94_b_y;
      c94_f_x = c94_e_x;
      c94_d_y = c94_c_y;
      c94_X2 = c94_f_x / c94_d_y;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 60);
      c94_B5 = c94_X1 + c94_X2;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 61);
      c94_c_A = c94_B5 + 8.0F;
      c94_g_x = c94_c_A;
      c94_h_x = c94_g_x;
      c94_i_x = c94_h_x;
      c94_T = c94_i_x / 16.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 63);
      c94_B6 = c94_B5 - 4000.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 64);
      c94_d_A = c94_B6 * c94_B6;
      c94_j_x = c94_d_A;
      c94_k_x = c94_j_x;
      c94_l_x = c94_k_x;
      c94_e_y = c94_l_x / 4096.0F;
      c94_e_A = c94_B2 * c94_e_y;
      c94_m_x = c94_e_A;
      c94_n_x = c94_m_x;
      c94_o_x = c94_n_x;
      c94_X1 = c94_o_x / 2048.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 65);
      c94_f_A = c94_AC2 * c94_B6;
      c94_p_x = c94_f_A;
      c94_q_x = c94_p_x;
      c94_r_x = c94_q_x;
      c94_X2 = c94_r_x / 2048.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 66);
      c94_X3 = c94_X1 + c94_X2;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 67);
      c94_b_a = c94_AC1;
      c94_f_y = c94_b_a * 4.0F;
      c94_g_A = (c94_f_y + c94_X3) * c94_mpower(chartInstance, 2.0, c94_oss) +
        2.0F;
      c94_s_x = c94_g_A;
      c94_t_x = c94_s_x;
      c94_u_x = c94_t_x;
      c94_B3 = c94_u_x / 4.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 68);
      c94_h_A = c94_AC3 * c94_B6;
      c94_v_x = c94_h_A;
      c94_w_x = c94_v_x;
      c94_x_x = c94_w_x;
      c94_X1 = c94_x_x / 8192.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 69);
      c94_i_A = c94_B6 * c94_B6;
      c94_y_x = c94_i_A;
      c94_ab_x = c94_y_x;
      c94_bb_x = c94_ab_x;
      c94_g_y = c94_bb_x / 4096.0F;
      c94_j_A = c94_B1 * c94_g_y;
      c94_cb_x = c94_j_A;
      c94_db_x = c94_cb_x;
      c94_eb_x = c94_db_x;
      c94_X2 = c94_eb_x / 65536.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 70);
      c94_k_A = (c94_X1 + c94_X2) + 2.0F;
      c94_fb_x = c94_k_A;
      c94_gb_x = c94_fb_x;
      c94_hb_x = c94_gb_x;
      c94_X3 = c94_hb_x / 4.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 71);
      c94_l_A = c94_AC4 * (c94_X3 + 32768.0F);
      c94_ib_x = c94_l_A;
      c94_jb_x = c94_ib_x;
      c94_kb_x = c94_jb_x;
      c94_B4 = c94_kb_x / 32768.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 72);
      c94_c_a = c94_UP - c94_B3;
      c94_h_y = c94_c_a * 50000.0F;
      c94_m_A = c94_h_y;
      c94_b_B = c94_mpower(chartInstance, 2.0, c94_oss);
      c94_lb_x = c94_m_A;
      c94_i_y = c94_b_B;
      c94_mb_x = c94_lb_x;
      c94_j_y = c94_i_y;
      c94_nb_x = c94_mb_x;
      c94_k_y = c94_j_y;
      c94_B7 = c94_nb_x / c94_k_y;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 73);
      c94_d_a = c94_B7;
      c94_l_y = c94_d_a * 2.0F;
      c94_n_A = c94_l_y;
      c94_c_B = c94_B4;
      c94_ob_x = c94_n_A;
      c94_m_y = c94_c_B;
      c94_pb_x = c94_ob_x;
      c94_n_y = c94_m_y;
      c94_qb_x = c94_pb_x;
      c94_o_y = c94_n_y;
      c94_P = c94_qb_x / c94_o_y;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 74);
      c94_o_A = c94_P;
      c94_rb_x = c94_o_A;
      c94_sb_x = c94_rb_x;
      c94_tb_x = c94_sb_x;
      c94_p_y = c94_tb_x / 256.0F;
      c94_p_A = c94_P;
      c94_ub_x = c94_p_A;
      c94_vb_x = c94_ub_x;
      c94_wb_x = c94_vb_x;
      c94_q_y = c94_wb_x / 256.0F;
      c94_X1 = c94_p_y * c94_q_y;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 75);
      c94_e_a = c94_X1;
      c94_r_y = c94_e_a * 3038.0F;
      c94_q_A = c94_r_y;
      c94_xb_x = c94_q_A;
      c94_yb_x = c94_xb_x;
      c94_ac_x = c94_yb_x;
      c94_X1 = c94_ac_x / 65536.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 76);
      c94_b = c94_P;
      c94_s_y = -7357.0F * c94_b;
      c94_r_A = c94_s_y;
      c94_bc_x = c94_r_A;
      c94_cc_x = c94_bc_x;
      c94_dc_x = c94_cc_x;
      c94_X2 = c94_dc_x / 65536.0F;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 77);
      c94_s_A = (c94_X1 + c94_X2) + 3791.0F;
      c94_ec_x = c94_s_A;
      c94_fc_x = c94_ec_x;
      c94_gc_x = c94_fc_x;
      c94_t_y = c94_gc_x / 16.0F;
      c94_P += c94_t_y;
      _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 78);
      c94_t_A = c94_P;
      c94_hc_x = c94_t_A;
      c94_ic_x = c94_hc_x;
      c94_jc_x = c94_ic_x;
      c94_u_y = c94_jc_x / 101325.0F;
      c94_f_a = c94_u_y;
      c94_g_a = c94_f_a;
      c94_h_a = c94_g_a;
      c94_b_eml_scalar_eg(chartInstance);
      c94_ak = c94_h_a;
      if (c94_ak < 0.0F) {
        c94_eml_error(chartInstance);
      }

      c94_i_a = c94_ak;
      c94_b_eml_scalar_eg(chartInstance);
      c94_ar = c94_i_a;
      c94_c = muSingleScalarPower(c94_ar, 0.190294951F);
      c94_b_b = 1.0F - c94_c;
      c94_h = 44330.0F * c94_b_b;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 55);
    c94_T = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, 56);
    c94_h = 0.0F;
  }

  _SFD_EML_CALL(0U, chartInstance->c94_sfEvent, -78);
  _SFD_SYMBOL_SCOPE_POP();
  *c94_b_T = c94_T;
  *c94_b_h = c94_h;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c94_sfEvent);
}

static void initSimStructsc94_ICARO3_orientation_controllo_BIPE
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c94_machineNumber, uint32_T
  c94_chartNumber, uint32_T c94_instanceNumber)
{
  (void)c94_machineNumber;
  (void)c94_chartNumber;
  (void)c94_instanceNumber;
}

static const mxArray *c94_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData)
{
  const mxArray *c94_mxArrayOutData = NULL;
  real32_T c94_u;
  const mxArray *c94_y = NULL;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_mxArrayOutData = NULL;
  c94_u = *(real32_T *)c94_inData;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", &c94_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c94_mxArrayOutData, c94_y, false);
  return c94_mxArrayOutData;
}

static real32_T c94_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_h, const char_T *c94_identifier)
{
  real32_T c94_y;
  emlrtMsgIdentifier c94_thisId;
  c94_thisId.fIdentifier = c94_identifier;
  c94_thisId.fParent = NULL;
  c94_y = c94_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c94_h), &c94_thisId);
  sf_mex_destroy(&c94_h);
  return c94_y;
}

static real32_T c94_b_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId)
{
  real32_T c94_y;
  real32_T c94_f0;
  (void)chartInstance;
  sf_mex_import(c94_parentId, sf_mex_dup(c94_u), &c94_f0, 1, 1, 0U, 0, 0U, 0);
  c94_y = c94_f0;
  sf_mex_destroy(&c94_u);
  return c94_y;
}

static void c94_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData)
{
  const mxArray *c94_h;
  const char_T *c94_identifier;
  emlrtMsgIdentifier c94_thisId;
  real32_T c94_y;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_h = sf_mex_dup(c94_mxArrayInData);
  c94_identifier = c94_varName;
  c94_thisId.fIdentifier = c94_identifier;
  c94_thisId.fParent = NULL;
  c94_y = c94_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c94_h), &c94_thisId);
  sf_mex_destroy(&c94_h);
  *(real32_T *)c94_outData = c94_y;
  sf_mex_destroy(&c94_mxArrayInData);
}

static const mxArray *c94_b_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData)
{
  const mxArray *c94_mxArrayOutData = NULL;
  uint8_T c94_u;
  const mxArray *c94_y = NULL;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_mxArrayOutData = NULL;
  c94_u = *(uint8_T *)c94_inData;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", &c94_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c94_mxArrayOutData, c94_y, false);
  return c94_mxArrayOutData;
}

static const mxArray *c94_c_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData)
{
  const mxArray *c94_mxArrayOutData = NULL;
  int32_T c94_i2;
  real32_T c94_b_inData[11];
  int32_T c94_i3;
  real32_T c94_u[11];
  const mxArray *c94_y = NULL;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_mxArrayOutData = NULL;
  for (c94_i2 = 0; c94_i2 < 11; c94_i2++) {
    c94_b_inData[c94_i2] = (*(real32_T (*)[11])c94_inData)[c94_i2];
  }

  for (c94_i3 = 0; c94_i3 < 11; c94_i3++) {
    c94_u[c94_i3] = c94_b_inData[c94_i3];
  }

  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", c94_u, 1, 0U, 1U, 0U, 2, 11, 1),
                false);
  sf_mex_assign(&c94_mxArrayOutData, c94_y, false);
  return c94_mxArrayOutData;
}

static const mxArray *c94_d_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData)
{
  const mxArray *c94_mxArrayOutData = NULL;
  real_T c94_u;
  const mxArray *c94_y = NULL;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_mxArrayOutData = NULL;
  c94_u = *(real_T *)c94_inData;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", &c94_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c94_mxArrayOutData, c94_y, false);
  return c94_mxArrayOutData;
}

static real_T c94_c_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId)
{
  real_T c94_y;
  real_T c94_d0;
  (void)chartInstance;
  sf_mex_import(c94_parentId, sf_mex_dup(c94_u), &c94_d0, 1, 0, 0U, 0, 0U, 0);
  c94_y = c94_d0;
  sf_mex_destroy(&c94_u);
  return c94_y;
}

static void c94_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData)
{
  const mxArray *c94_nargout;
  const char_T *c94_identifier;
  emlrtMsgIdentifier c94_thisId;
  real_T c94_y;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_nargout = sf_mex_dup(c94_mxArrayInData);
  c94_identifier = c94_varName;
  c94_thisId.fIdentifier = c94_identifier;
  c94_thisId.fParent = NULL;
  c94_y = c94_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c94_nargout),
    &c94_thisId);
  sf_mex_destroy(&c94_nargout);
  *(real_T *)c94_outData = c94_y;
  sf_mex_destroy(&c94_mxArrayInData);
}

const mxArray
  *sf_c94_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info(void)
{
  const mxArray *c94_nameCaptureInfo = NULL;
  c94_nameCaptureInfo = NULL;
  sf_mex_assign(&c94_nameCaptureInfo, sf_mex_createstruct("structure", 2, 43, 1),
                false);
  c94_info_helper(&c94_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c94_nameCaptureInfo);
  return c94_nameCaptureInfo;
}

static void c94_info_helper(const mxArray **c94_info)
{
  const mxArray *c94_rhs0 = NULL;
  const mxArray *c94_lhs0 = NULL;
  const mxArray *c94_rhs1 = NULL;
  const mxArray *c94_lhs1 = NULL;
  const mxArray *c94_rhs2 = NULL;
  const mxArray *c94_lhs2 = NULL;
  const mxArray *c94_rhs3 = NULL;
  const mxArray *c94_lhs3 = NULL;
  const mxArray *c94_rhs4 = NULL;
  const mxArray *c94_lhs4 = NULL;
  const mxArray *c94_rhs5 = NULL;
  const mxArray *c94_lhs5 = NULL;
  const mxArray *c94_rhs6 = NULL;
  const mxArray *c94_lhs6 = NULL;
  const mxArray *c94_rhs7 = NULL;
  const mxArray *c94_lhs7 = NULL;
  const mxArray *c94_rhs8 = NULL;
  const mxArray *c94_lhs8 = NULL;
  const mxArray *c94_rhs9 = NULL;
  const mxArray *c94_lhs9 = NULL;
  const mxArray *c94_rhs10 = NULL;
  const mxArray *c94_lhs10 = NULL;
  const mxArray *c94_rhs11 = NULL;
  const mxArray *c94_lhs11 = NULL;
  const mxArray *c94_rhs12 = NULL;
  const mxArray *c94_lhs12 = NULL;
  const mxArray *c94_rhs13 = NULL;
  const mxArray *c94_lhs13 = NULL;
  const mxArray *c94_rhs14 = NULL;
  const mxArray *c94_lhs14 = NULL;
  const mxArray *c94_rhs15 = NULL;
  const mxArray *c94_lhs15 = NULL;
  const mxArray *c94_rhs16 = NULL;
  const mxArray *c94_lhs16 = NULL;
  const mxArray *c94_rhs17 = NULL;
  const mxArray *c94_lhs17 = NULL;
  const mxArray *c94_rhs18 = NULL;
  const mxArray *c94_lhs18 = NULL;
  const mxArray *c94_rhs19 = NULL;
  const mxArray *c94_lhs19 = NULL;
  const mxArray *c94_rhs20 = NULL;
  const mxArray *c94_lhs20 = NULL;
  const mxArray *c94_rhs21 = NULL;
  const mxArray *c94_lhs21 = NULL;
  const mxArray *c94_rhs22 = NULL;
  const mxArray *c94_lhs22 = NULL;
  const mxArray *c94_rhs23 = NULL;
  const mxArray *c94_lhs23 = NULL;
  const mxArray *c94_rhs24 = NULL;
  const mxArray *c94_lhs24 = NULL;
  const mxArray *c94_rhs25 = NULL;
  const mxArray *c94_lhs25 = NULL;
  const mxArray *c94_rhs26 = NULL;
  const mxArray *c94_lhs26 = NULL;
  const mxArray *c94_rhs27 = NULL;
  const mxArray *c94_lhs27 = NULL;
  const mxArray *c94_rhs28 = NULL;
  const mxArray *c94_lhs28 = NULL;
  const mxArray *c94_rhs29 = NULL;
  const mxArray *c94_lhs29 = NULL;
  const mxArray *c94_rhs30 = NULL;
  const mxArray *c94_lhs30 = NULL;
  const mxArray *c94_rhs31 = NULL;
  const mxArray *c94_lhs31 = NULL;
  const mxArray *c94_rhs32 = NULL;
  const mxArray *c94_lhs32 = NULL;
  const mxArray *c94_rhs33 = NULL;
  const mxArray *c94_lhs33 = NULL;
  const mxArray *c94_rhs34 = NULL;
  const mxArray *c94_lhs34 = NULL;
  const mxArray *c94_rhs35 = NULL;
  const mxArray *c94_lhs35 = NULL;
  const mxArray *c94_rhs36 = NULL;
  const mxArray *c94_lhs36 = NULL;
  const mxArray *c94_rhs37 = NULL;
  const mxArray *c94_lhs37 = NULL;
  const mxArray *c94_rhs38 = NULL;
  const mxArray *c94_lhs38 = NULL;
  const mxArray *c94_rhs39 = NULL;
  const mxArray *c94_lhs39 = NULL;
  const mxArray *c94_rhs40 = NULL;
  const mxArray *c94_lhs40 = NULL;
  const mxArray *c94_rhs41 = NULL;
  const mxArray *c94_lhs41 = NULL;
  const mxArray *c94_rhs42 = NULL;
  const mxArray *c94_lhs42 = NULL;
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c94_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c94_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c94_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c94_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c94_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c94_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c94_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c94_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c94_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c94_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c94_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c94_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c94_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c94_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c94_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c94_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c94_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c94_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 18);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c94_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_div"), "name", "name",
                  19);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c94_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 20);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c94_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c94_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 22);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c94_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 23);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c94_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "context", "context", 24);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("mpower"), "name", "name", 24);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c94_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c94_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("ismatrix"), "name", "name",
                  26);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c94_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("power"), "name", "name", 27);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c94_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c94_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 29);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 29);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c94_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 30);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c94_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 31);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 31);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c94_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 32);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c94_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 33);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("floor"), "name", "name", 33);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c94_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c94_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 35);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c94_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 36);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_error"), "name", "name",
                  36);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c94_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 37);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c94_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("mrdivide"), "name", "name",
                  38);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c94_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 39);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("rdivide"), "name", "name",
                  39);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c94_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 40);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c94_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("eml_div"), "name", "name",
                  41);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c94_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 42);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c94_info, c94_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c94_info, c94_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c94_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c94_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c94_info, sf_mex_duplicatearraysafe(&c94_lhs42), "lhs", "lhs",
                  42);
  sf_mex_destroy(&c94_rhs0);
  sf_mex_destroy(&c94_lhs0);
  sf_mex_destroy(&c94_rhs1);
  sf_mex_destroy(&c94_lhs1);
  sf_mex_destroy(&c94_rhs2);
  sf_mex_destroy(&c94_lhs2);
  sf_mex_destroy(&c94_rhs3);
  sf_mex_destroy(&c94_lhs3);
  sf_mex_destroy(&c94_rhs4);
  sf_mex_destroy(&c94_lhs4);
  sf_mex_destroy(&c94_rhs5);
  sf_mex_destroy(&c94_lhs5);
  sf_mex_destroy(&c94_rhs6);
  sf_mex_destroy(&c94_lhs6);
  sf_mex_destroy(&c94_rhs7);
  sf_mex_destroy(&c94_lhs7);
  sf_mex_destroy(&c94_rhs8);
  sf_mex_destroy(&c94_lhs8);
  sf_mex_destroy(&c94_rhs9);
  sf_mex_destroy(&c94_lhs9);
  sf_mex_destroy(&c94_rhs10);
  sf_mex_destroy(&c94_lhs10);
  sf_mex_destroy(&c94_rhs11);
  sf_mex_destroy(&c94_lhs11);
  sf_mex_destroy(&c94_rhs12);
  sf_mex_destroy(&c94_lhs12);
  sf_mex_destroy(&c94_rhs13);
  sf_mex_destroy(&c94_lhs13);
  sf_mex_destroy(&c94_rhs14);
  sf_mex_destroy(&c94_lhs14);
  sf_mex_destroy(&c94_rhs15);
  sf_mex_destroy(&c94_lhs15);
  sf_mex_destroy(&c94_rhs16);
  sf_mex_destroy(&c94_lhs16);
  sf_mex_destroy(&c94_rhs17);
  sf_mex_destroy(&c94_lhs17);
  sf_mex_destroy(&c94_rhs18);
  sf_mex_destroy(&c94_lhs18);
  sf_mex_destroy(&c94_rhs19);
  sf_mex_destroy(&c94_lhs19);
  sf_mex_destroy(&c94_rhs20);
  sf_mex_destroy(&c94_lhs20);
  sf_mex_destroy(&c94_rhs21);
  sf_mex_destroy(&c94_lhs21);
  sf_mex_destroy(&c94_rhs22);
  sf_mex_destroy(&c94_lhs22);
  sf_mex_destroy(&c94_rhs23);
  sf_mex_destroy(&c94_lhs23);
  sf_mex_destroy(&c94_rhs24);
  sf_mex_destroy(&c94_lhs24);
  sf_mex_destroy(&c94_rhs25);
  sf_mex_destroy(&c94_lhs25);
  sf_mex_destroy(&c94_rhs26);
  sf_mex_destroy(&c94_lhs26);
  sf_mex_destroy(&c94_rhs27);
  sf_mex_destroy(&c94_lhs27);
  sf_mex_destroy(&c94_rhs28);
  sf_mex_destroy(&c94_lhs28);
  sf_mex_destroy(&c94_rhs29);
  sf_mex_destroy(&c94_lhs29);
  sf_mex_destroy(&c94_rhs30);
  sf_mex_destroy(&c94_lhs30);
  sf_mex_destroy(&c94_rhs31);
  sf_mex_destroy(&c94_lhs31);
  sf_mex_destroy(&c94_rhs32);
  sf_mex_destroy(&c94_lhs32);
  sf_mex_destroy(&c94_rhs33);
  sf_mex_destroy(&c94_lhs33);
  sf_mex_destroy(&c94_rhs34);
  sf_mex_destroy(&c94_lhs34);
  sf_mex_destroy(&c94_rhs35);
  sf_mex_destroy(&c94_lhs35);
  sf_mex_destroy(&c94_rhs36);
  sf_mex_destroy(&c94_lhs36);
  sf_mex_destroy(&c94_rhs37);
  sf_mex_destroy(&c94_lhs37);
  sf_mex_destroy(&c94_rhs38);
  sf_mex_destroy(&c94_lhs38);
  sf_mex_destroy(&c94_rhs39);
  sf_mex_destroy(&c94_lhs39);
  sf_mex_destroy(&c94_rhs40);
  sf_mex_destroy(&c94_lhs40);
  sf_mex_destroy(&c94_rhs41);
  sf_mex_destroy(&c94_lhs41);
  sf_mex_destroy(&c94_rhs42);
  sf_mex_destroy(&c94_lhs42);
}

static const mxArray *c94_emlrt_marshallOut(const char * c94_u)
{
  const mxArray *c94_y = NULL;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", c94_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c94_u)), false);
  return c94_y;
}

static const mxArray *c94_b_emlrt_marshallOut(const uint32_T c94_u)
{
  const mxArray *c94_y = NULL;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", &c94_u, 7, 0U, 0U, 0U, 0), false);
  return c94_y;
}

static real32_T c94_mpower(SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct
  *chartInstance, real_T c94_a, real32_T c94_b)
{
  real_T c94_b_a;
  real32_T c94_b_b;
  real_T c94_c_a;
  real32_T c94_c_b;
  real_T c94_ak;
  real32_T c94_bk;
  real32_T c94_x;
  real32_T c94_b_x;
  real_T c94_d_a;
  real32_T c94_d_b;
  real_T c94_ar;
  real32_T c94_br;
  c94_b_a = c94_a;
  c94_b_b = c94_b;
  c94_c_a = c94_b_a;
  c94_c_b = c94_b_b;
  c94_eml_scalar_eg(chartInstance);
  c94_ak = c94_c_a;
  c94_bk = c94_c_b;
  if (c94_ak < 0.0) {
    c94_x = c94_bk;
    c94_b_x = c94_x;
    c94_b_x = muSingleScalarFloor(c94_b_x);
    if (c94_b_x != c94_bk) {
      c94_eml_error(chartInstance);
    }
  }

  c94_d_a = c94_ak;
  c94_d_b = c94_bk;
  c94_eml_scalar_eg(chartInstance);
  c94_ar = c94_d_a;
  c94_br = c94_d_b;
  return muSingleScalarPower((real32_T)c94_ar, c94_br);
}

static void c94_eml_scalar_eg
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c94_eml_error(SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *
  chartInstance)
{
  int32_T c94_i4;
  static char_T c94_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c94_u[31];
  const mxArray *c94_y = NULL;
  (void)chartInstance;
  for (c94_i4 = 0; c94_i4 < 31; c94_i4++) {
    c94_u[c94_i4] = c94_cv0[c94_i4];
  }

  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", c94_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c94_y));
}

static void c94_b_eml_scalar_eg
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c94_e_sf_marshallOut(void *chartInstanceVoid, void
  *c94_inData)
{
  const mxArray *c94_mxArrayOutData = NULL;
  int32_T c94_u;
  const mxArray *c94_y = NULL;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_mxArrayOutData = NULL;
  c94_u = *(int32_T *)c94_inData;
  c94_y = NULL;
  sf_mex_assign(&c94_y, sf_mex_create("y", &c94_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c94_mxArrayOutData, c94_y, false);
  return c94_mxArrayOutData;
}

static int32_T c94_d_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId)
{
  int32_T c94_y;
  int32_T c94_i5;
  (void)chartInstance;
  sf_mex_import(c94_parentId, sf_mex_dup(c94_u), &c94_i5, 1, 6, 0U, 0, 0U, 0);
  c94_y = c94_i5;
  sf_mex_destroy(&c94_u);
  return c94_y;
}

static void c94_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c94_mxArrayInData, const char_T *c94_varName, void *c94_outData)
{
  const mxArray *c94_b_sfEvent;
  const char_T *c94_identifier;
  emlrtMsgIdentifier c94_thisId;
  int32_T c94_y;
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c94_b_sfEvent = sf_mex_dup(c94_mxArrayInData);
  c94_identifier = c94_varName;
  c94_thisId.fIdentifier = c94_identifier;
  c94_thisId.fParent = NULL;
  c94_y = c94_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c94_b_sfEvent),
    &c94_thisId);
  sf_mex_destroy(&c94_b_sfEvent);
  *(int32_T *)c94_outData = c94_y;
  sf_mex_destroy(&c94_mxArrayInData);
}

static uint8_T c94_e_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_b_is_active_c94_ICARO3_orientation_controllo_BIPE, const char_T *
   c94_identifier)
{
  uint8_T c94_y;
  emlrtMsgIdentifier c94_thisId;
  c94_thisId.fIdentifier = c94_identifier;
  c94_thisId.fParent = NULL;
  c94_y = c94_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c94_b_is_active_c94_ICARO3_orientation_controllo_BIPE), &c94_thisId);
  sf_mex_destroy(&c94_b_is_active_c94_ICARO3_orientation_controllo_BIPE);
  return c94_y;
}

static uint8_T c94_f_emlrt_marshallIn
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c94_u, const emlrtMsgIdentifier *c94_parentId)
{
  uint8_T c94_y;
  uint8_T c94_u0;
  (void)chartInstance;
  sf_mex_import(c94_parentId, sf_mex_dup(c94_u), &c94_u0, 1, 3, 0U, 0, 0U, 0);
  c94_y = c94_u0;
  sf_mex_destroy(&c94_u);
  return c94_y;
}

static void init_dsm_address_info
  (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
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

void sf_c94_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3806204932U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1660825411U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2428832670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3746638473U);
}

mxArray *sf_c94_ICARO3_orientation_controllo_BIPE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sIEjzZYhWGac1BwuYKX6LH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(11);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c94_ICARO3_orientation_controllo_BIPE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c94_ICARO3_orientation_controllo_BIPE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c94_ICARO3_orientation_controllo_BIPE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"T\",},{M[1],M[8],T\"h\",},{M[8],M[0],T\"is_active_c94_ICARO3_orientation_controllo_BIPE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c94_ICARO3_orientation_controllo_BIPE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_orientation_controllo_BIPEMachineNumber_,
           94,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"UT");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T");
          _SFD_SET_DATA_PROPS(2,1,1,0,"UP");
          _SFD_SET_DATA_PROPS(3,2,0,1,"h");
          _SFD_SET_DATA_PROPS(4,1,1,0,"oss");
          _SFD_SET_DATA_PROPS(5,1,1,0,"params");
          _SFD_SET_DATA_PROPS(6,1,1,0,"bmp085_enabled");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1938);
        _SFD_CV_INIT_EML_IF(0,1,0,1257,1305,1344,1933);

        {
          static int condStart[] = { 1262, 1273, 1285 };

          static int condEnd[] = { 1269, 1280, 1304 };

          static int pfixExpr[] = { 0, 1, -3, 2, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1261,1304,3,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_sf_marshallOut,(MexInFcnForType)c94_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_sf_marshallOut,(MexInFcnForType)c94_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 11;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c94_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c94_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real32_T *c94_UT;
          real32_T *c94_T;
          real32_T *c94_UP;
          real32_T *c94_h;
          real32_T *c94_oss;
          uint8_T *c94_bmp085_enabled;
          real32_T (*c94_params)[11];
          c94_bmp085_enabled = (uint8_T *)ssGetInputPortSignal(chartInstance->S,
            4);
          c94_params = (real32_T (*)[11])ssGetInputPortSignal(chartInstance->S,
            3);
          c94_oss = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c94_h = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c94_UP = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c94_T = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c94_UT = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c94_UT);
          _SFD_SET_DATA_VALUE_PTR(1U, c94_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c94_UP);
          _SFD_SET_DATA_VALUE_PTR(3U, c94_h);
          _SFD_SET_DATA_VALUE_PTR(4U, c94_oss);
          _SFD_SET_DATA_VALUE_PTR(5U, *c94_params);
          _SFD_SET_DATA_VALUE_PTR(6U, c94_bmp085_enabled);
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
  return "atOUxWXKZFIACs8CSaWMU";
}

static void sf_opaque_initialize_c94_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
  initialize_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c94_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  enable_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c94_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  disable_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c94_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  sf_gateway_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c94_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c94_ICARO3_orientation_controllo_BIPE();/* state var info */
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

extern void sf_internal_set_sim_state_c94_ICARO3_orientation_controllo_BIPE
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
    sf_get_sim_state_info_c94_ICARO3_orientation_controllo_BIPE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c94_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  return sf_internal_get_sim_state_c94_ICARO3_orientation_controllo_BIPE(S);
}

static void sf_opaque_set_sim_state_c94_ICARO3_orientation_controllo_BIPE
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c94_ICARO3_orientation_controllo_BIPE(S, st);
}

static void sf_opaque_terminate_c94_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_orientation_controllo_BIPE_optimization_info();
    }

    finalize_c94_ICARO3_orientation_controllo_BIPE
      ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc94_ICARO3_orientation_controllo_BIPE
    ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c94_ICARO3_orientation_controllo_BIPE(SimStruct
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
    initialize_params_c94_ICARO3_orientation_controllo_BIPE
      ((SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c94_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_orientation_controllo_BIPE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      94);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,94,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,94,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,94);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,94,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,94,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,94);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2180799078U));
  ssSetChecksum1(S,(3214871930U));
  ssSetChecksum2(S,(459286203U));
  ssSetChecksum3(S,(24547710U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c94_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c94_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    utMalloc(sizeof(SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc94_ICARO3_orientation_controllo_BIPEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c94_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c94_ICARO3_orientation_controllo_BIPE;
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

void c94_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c94_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c94_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c94_ICARO3_orientation_controllo_BIPE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c94_ICARO3_orientation_controllo_BIPE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
