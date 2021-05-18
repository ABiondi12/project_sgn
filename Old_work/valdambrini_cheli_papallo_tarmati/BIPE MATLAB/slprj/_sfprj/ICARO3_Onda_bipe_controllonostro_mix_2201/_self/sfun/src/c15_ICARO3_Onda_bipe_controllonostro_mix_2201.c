/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro_mix_2201_sfun.h"
#include "c15_ICARO3_Onda_bipe_controllonostro_mix_2201.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_controllonostro_mix_2201_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c15_debug_family_names[18] = { "nargin", "nargout", "pwms",
  "THROTTLE_IDX", "ROLL_IDX", "PITCH_IDX", "YAW_IDX", "THROTTLE_DOWN",
  "ROLL_MID", "PITCH_MID", "YAW_MID", "INV_THROTTLE_RANGE", "INV_ROLL_RANGE",
  "INV_PITCH_RANGE", "INV_YAW_RANGE", "THROTTLE_LOW_THRES", "RC_TRPY_refs",
  "RC_aux_channels" };

/* Function Declarations */
static void initialize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void initialize_params_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void enable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void disable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_ICARO3_Onda_bipe_controllonostro_m
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static const mxArray
  *get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_st);
static void finalize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void sf_gateway_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void c15_chartstep_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void initSimStructsc15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_RC_aux_channels, const char_T *c15_identifier, real_T
   c15_y[8]);
static void c15_b_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[8]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_RC_TRPY_refs, const char_T *c15_identifier, real_T c15_y[4]);
static void c15_d_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_e_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_f_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_g_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_b_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201,
   const char_T *c15_identifier);
static uint8_T c15_h_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201 =
    0U;
}

static void initialize_params_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  real_T c15_d0;
  real_T c15_d1;
  real_T c15_d2;
  real_T c15_d3;
  real_T c15_d4;
  real_T c15_d5;
  real_T c15_d6;
  real_T c15_d7;
  real_T c15_d8;
  real_T c15_d9;
  real_T c15_d10;
  real_T c15_d11;
  real_T c15_d12;
  sf_mex_import_named("THROTTLE_IDX", sf_mex_get_sfun_param(chartInstance->S, 9,
    0), &c15_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_THROTTLE_IDX = c15_d0;
  sf_mex_import_named("ROLL_IDX", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c15_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_ROLL_IDX = c15_d1;
  sf_mex_import_named("PITCH_IDX", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c15_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_PITCH_IDX = c15_d2;
  sf_mex_import_named("YAW_IDX", sf_mex_get_sfun_param(chartInstance->S, 11, 0),
                      &c15_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_YAW_IDX = c15_d3;
  sf_mex_import_named("THROTTLE_DOWN", sf_mex_get_sfun_param(chartInstance->S, 8,
    0), &c15_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_THROTTLE_DOWN = c15_d4;
  sf_mex_import_named("ROLL_MID", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c15_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_ROLL_MID = c15_d5;
  sf_mex_import_named("PITCH_MID", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c15_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_PITCH_MID = c15_d6;
  sf_mex_import_named("YAW_MID", sf_mex_get_sfun_param(chartInstance->S, 12, 0),
                      &c15_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_YAW_MID = c15_d7;
  sf_mex_import_named("INV_THROTTLE_RANGE", sf_mex_get_sfun_param
                      (chartInstance->S, 2, 0), &c15_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_INV_THROTTLE_RANGE = c15_d8;
  sf_mex_import_named("INV_ROLL_RANGE", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c15_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_INV_ROLL_RANGE = c15_d9;
  sf_mex_import_named("INV_PITCH_RANGE", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c15_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_INV_PITCH_RANGE = c15_d10;
  sf_mex_import_named("INV_YAW_RANGE", sf_mex_get_sfun_param(chartInstance->S, 3,
    0), &c15_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_INV_YAW_RANGE = c15_d11;
  sf_mex_import_named("THROTTLE_LOW_THRES", sf_mex_get_sfun_param
                      (chartInstance->S, 10, 0), &c15_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_THROTTLE_LOW_THRES = c15_d12;
}

static void enable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_ICARO3_Onda_bipe_controllonostro_m
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[4];
  const mxArray *c15_b_y = NULL;
  int32_T c15_i1;
  real_T c15_b_u[8];
  const mxArray *c15_c_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  real_T (*c15_RC_aux_channels)[8];
  real_T (*c15_RC_TRPY_refs)[4];
  c15_RC_aux_channels = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_RC_TRPY_refs = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(3, 1), false);
  for (c15_i0 = 0; c15_i0 < 4; c15_i0++) {
    c15_u[c15_i0] = (*c15_RC_TRPY_refs)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  for (c15_i1 = 0; c15_i1 < 8; c15_i1++) {
    c15_b_u[c15_i1] = (*c15_RC_aux_channels)[c15_i1];
  }

  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_b_u, 0, 0U, 1U, 0U, 1, 8),
                false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_hoistedGlobal =
    chartInstance->c15_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  c15_c_u = c15_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[4];
  int32_T c15_i2;
  real_T c15_dv1[8];
  int32_T c15_i3;
  real_T (*c15_RC_TRPY_refs)[4];
  real_T (*c15_RC_aux_channels)[8];
  c15_RC_aux_channels = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_RC_TRPY_refs = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_u = sf_mex_dup(c15_st);
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
    "RC_TRPY_refs", c15_dv0);
  for (c15_i2 = 0; c15_i2 < 4; c15_i2++) {
    (*c15_RC_TRPY_refs)[c15_i2] = c15_dv0[c15_i2];
  }

  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
                       "RC_aux_channels", c15_dv1);
  for (c15_i3 = 0; c15_i3 < 8; c15_i3++) {
    (*c15_RC_aux_channels)[c15_i3] = c15_dv1[c15_i3];
  }

  chartInstance->c15_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201 =
    c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
    "is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_ICARO3_Onda_bipe_controllonostro_m(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  int32_T c15_i4;
  int32_T c15_i5;
  int32_T c15_i6;
  real_T (*c15_RC_aux_channels)[8];
  real_T (*c15_RC_TRPY_refs)[4];
  real_T (*c15_pwms)[12];
  c15_RC_aux_channels = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_RC_TRPY_refs = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_pwms = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c15_sfEvent);
  for (c15_i4 = 0; c15_i4 < 12; c15_i4++) {
    _SFD_DATA_RANGE_CHECK((*c15_pwms)[c15_i4], 0U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c15_i5 = 0; c15_i5 < 4; c15_i5++) {
    _SFD_DATA_RANGE_CHECK((*c15_RC_TRPY_refs)[c15_i5], 1U);
  }

  for (c15_i6 = 0; c15_i6 < 8; c15_i6++) {
    _SFD_DATA_RANGE_CHECK((*c15_RC_aux_channels)[c15_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c15_THROTTLE_IDX, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_ROLL_IDX, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_PITCH_IDX, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_YAW_IDX, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_THROTTLE_DOWN, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_ROLL_MID, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_PITCH_MID, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_YAW_MID, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_INV_THROTTLE_RANGE, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_INV_ROLL_RANGE, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_INV_PITCH_RANGE, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_INV_YAW_RANGE, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_THROTTLE_LOW_THRES, 15U);
}

static void c15_chartstep_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_hoistedGlobal;
  real_T c15_d_hoistedGlobal;
  real_T c15_e_hoistedGlobal;
  real_T c15_f_hoistedGlobal;
  real_T c15_g_hoistedGlobal;
  real_T c15_h_hoistedGlobal;
  real_T c15_i_hoistedGlobal;
  real_T c15_j_hoistedGlobal;
  real_T c15_k_hoistedGlobal;
  real_T c15_l_hoistedGlobal;
  real_T c15_m_hoistedGlobal;
  int32_T c15_i7;
  real_T c15_pwms[12];
  real_T c15_b_THROTTLE_IDX;
  real_T c15_b_ROLL_IDX;
  real_T c15_b_PITCH_IDX;
  real_T c15_b_YAW_IDX;
  real_T c15_b_THROTTLE_DOWN;
  real_T c15_b_ROLL_MID;
  real_T c15_b_PITCH_MID;
  real_T c15_b_YAW_MID;
  real_T c15_b_INV_THROTTLE_RANGE;
  real_T c15_b_INV_ROLL_RANGE;
  real_T c15_b_INV_PITCH_RANGE;
  real_T c15_b_INV_YAW_RANGE;
  real_T c15_b_THROTTLE_LOW_THRES;
  uint32_T c15_debug_family_var_map[18];
  real_T c15_nargin = 14.0;
  real_T c15_nargout = 2.0;
  real_T c15_RC_TRPY_refs[4];
  real_T c15_RC_aux_channels[8];
  real_T c15_A;
  real_T c15_x;
  real_T c15_b_x;
  real_T c15_c_x;
  real_T c15_y;
  real_T c15_b_A;
  real_T c15_d_x;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_b_y;
  real_T c15_c_A;
  real_T c15_g_x;
  real_T c15_h_x;
  real_T c15_i_x;
  real_T c15_c_y;
  real_T c15_d_A;
  real_T c15_j_x;
  real_T c15_k_x;
  real_T c15_l_x;
  real_T c15_d_y;
  real_T c15_e_A;
  real_T c15_m_x;
  real_T c15_n_x;
  real_T c15_o_x;
  real_T c15_e_y;
  real_T c15_f_A;
  real_T c15_p_x;
  real_T c15_q_x;
  real_T c15_r_x;
  real_T c15_f_y;
  real_T c15_g_A;
  real_T c15_s_x;
  real_T c15_t_x;
  real_T c15_u_x;
  real_T c15_g_y;
  real_T c15_h_A;
  real_T c15_v_x;
  real_T c15_w_x;
  real_T c15_x_x;
  real_T c15_h_y;
  int32_T c15_i8;
  int32_T c15_i9;
  real_T (*c15_b_RC_TRPY_refs)[4];
  real_T (*c15_b_RC_aux_channels)[8];
  real_T (*c15_b_pwms)[12];
  c15_b_RC_aux_channels = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S,
    2);
  c15_b_RC_TRPY_refs = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_pwms = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = chartInstance->c15_THROTTLE_IDX;
  c15_b_hoistedGlobal = chartInstance->c15_ROLL_IDX;
  c15_c_hoistedGlobal = chartInstance->c15_PITCH_IDX;
  c15_d_hoistedGlobal = chartInstance->c15_YAW_IDX;
  c15_e_hoistedGlobal = chartInstance->c15_THROTTLE_DOWN;
  c15_f_hoistedGlobal = chartInstance->c15_ROLL_MID;
  c15_g_hoistedGlobal = chartInstance->c15_PITCH_MID;
  c15_h_hoistedGlobal = chartInstance->c15_YAW_MID;
  c15_i_hoistedGlobal = chartInstance->c15_INV_THROTTLE_RANGE;
  c15_j_hoistedGlobal = chartInstance->c15_INV_ROLL_RANGE;
  c15_k_hoistedGlobal = chartInstance->c15_INV_PITCH_RANGE;
  c15_l_hoistedGlobal = chartInstance->c15_INV_YAW_RANGE;
  c15_m_hoistedGlobal = chartInstance->c15_THROTTLE_LOW_THRES;
  for (c15_i7 = 0; c15_i7 < 12; c15_i7++) {
    c15_pwms[c15_i7] = (*c15_b_pwms)[c15_i7];
  }

  c15_b_THROTTLE_IDX = c15_hoistedGlobal;
  c15_b_ROLL_IDX = c15_b_hoistedGlobal;
  c15_b_PITCH_IDX = c15_c_hoistedGlobal;
  c15_b_YAW_IDX = c15_d_hoistedGlobal;
  c15_b_THROTTLE_DOWN = c15_e_hoistedGlobal;
  c15_b_ROLL_MID = c15_f_hoistedGlobal;
  c15_b_PITCH_MID = c15_g_hoistedGlobal;
  c15_b_YAW_MID = c15_h_hoistedGlobal;
  c15_b_INV_THROTTLE_RANGE = c15_i_hoistedGlobal;
  c15_b_INV_ROLL_RANGE = c15_j_hoistedGlobal;
  c15_b_INV_PITCH_RANGE = c15_k_hoistedGlobal;
  c15_b_INV_YAW_RANGE = c15_l_hoistedGlobal;
  c15_b_THROTTLE_LOW_THRES = c15_m_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 0U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 1U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_pwms, 2U, c15_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_THROTTLE_IDX, 3U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_ROLL_IDX, 4U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_PITCH_IDX, 5U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_YAW_IDX, 6U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_THROTTLE_DOWN, 7U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_ROLL_MID, 8U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_PITCH_MID, 9U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_YAW_MID, 10U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_INV_THROTTLE_RANGE, 11U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_INV_ROLL_RANGE, 12U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_INV_PITCH_RANGE, 13U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_INV_YAW_RANGE, 14U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_THROTTLE_LOW_THRES, 15U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_RC_TRPY_refs, 16U,
    c15_b_sf_marshallOut, c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_RC_aux_channels, 17U,
    c15_sf_marshallOut, c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 18);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
  c15_RC_TRPY_refs[0] = c15_b_INV_THROTTLE_RANGE *
    (c15_pwms[_SFD_EML_ARRAY_BOUNDS_CHECK("pwms", (int32_T)_SFD_INTEGER_CHECK(
       "THROTTLE_IDX", c15_b_THROTTLE_IDX), 1, 12, 1, 0) - 1] -
     c15_b_THROTTLE_DOWN);
  c15_RC_TRPY_refs[1] = c15_b_INV_ROLL_RANGE *
    (c15_pwms[_SFD_EML_ARRAY_BOUNDS_CHECK("pwms", (int32_T)_SFD_INTEGER_CHECK(
       "ROLL_IDX", c15_b_ROLL_IDX), 1, 12, 1, 0) - 1] - c15_b_ROLL_MID);
  c15_RC_TRPY_refs[2] = c15_b_INV_PITCH_RANGE *
    (c15_pwms[_SFD_EML_ARRAY_BOUNDS_CHECK("pwms", (int32_T)_SFD_INTEGER_CHECK(
       "PITCH_IDX", c15_b_PITCH_IDX), 1, 12, 1, 0) - 1] - c15_b_PITCH_MID);
  c15_RC_TRPY_refs[3] = c15_b_INV_YAW_RANGE *
    (c15_pwms[_SFD_EML_ARRAY_BOUNDS_CHECK("pwms", (int32_T)_SFD_INTEGER_CHECK(
       "YAW_IDX", c15_b_YAW_IDX), 1, 12, 1, 0) - 1] - c15_b_YAW_MID);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 28);
  if (CV_EML_IF(0, 1, 1, c15_pwms[_SFD_EML_ARRAY_BOUNDS_CHECK("pwms", (int32_T)
        _SFD_INTEGER_CHECK("THROTTLE_IDX", c15_b_THROTTLE_IDX), 1, 12, 1, 0) - 1]
                < c15_b_THROTTLE_LOW_THRES)) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 29);
    c15_RC_TRPY_refs[3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 34);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 50);
  CV_EML_IF(0, 1, 4, false);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 67);
  CV_EML_IF(0, 1, 6, false);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 85);
  c15_A = c15_pwms[4] - 1100.0;
  c15_x = c15_A;
  c15_b_x = c15_x;
  c15_c_x = c15_b_x;
  c15_y = c15_c_x / 1000.0;
  c15_b_A = c15_pwms[5] - 1100.0;
  c15_d_x = c15_b_A;
  c15_e_x = c15_d_x;
  c15_f_x = c15_e_x;
  c15_b_y = c15_f_x / 1000.0;
  c15_c_A = c15_pwms[6] - 1100.0;
  c15_g_x = c15_c_A;
  c15_h_x = c15_g_x;
  c15_i_x = c15_h_x;
  c15_c_y = c15_i_x / 1000.0;
  c15_d_A = c15_pwms[7] - 1100.0;
  c15_j_x = c15_d_A;
  c15_k_x = c15_j_x;
  c15_l_x = c15_k_x;
  c15_d_y = c15_l_x / 1000.0;
  c15_e_A = c15_pwms[8] - 1100.0;
  c15_m_x = c15_e_A;
  c15_n_x = c15_m_x;
  c15_o_x = c15_n_x;
  c15_e_y = c15_o_x / 1000.0;
  c15_f_A = c15_pwms[9] - 1100.0;
  c15_p_x = c15_f_A;
  c15_q_x = c15_p_x;
  c15_r_x = c15_q_x;
  c15_f_y = c15_r_x / 1000.0;
  c15_g_A = c15_pwms[10] - 1100.0;
  c15_s_x = c15_g_A;
  c15_t_x = c15_s_x;
  c15_u_x = c15_t_x;
  c15_g_y = c15_u_x / 1000.0;
  c15_h_A = c15_pwms[11] - 1100.0;
  c15_v_x = c15_h_A;
  c15_w_x = c15_v_x;
  c15_x_x = c15_w_x;
  c15_h_y = c15_x_x / 1000.0;
  c15_RC_aux_channels[0] = c15_y;
  c15_RC_aux_channels[1] = c15_b_y;
  c15_RC_aux_channels[2] = c15_c_y;
  c15_RC_aux_channels[3] = c15_d_y;
  c15_RC_aux_channels[4] = c15_e_y;
  c15_RC_aux_channels[5] = c15_f_y;
  c15_RC_aux_channels[6] = c15_g_y;
  c15_RC_aux_channels[7] = c15_h_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -85);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i8 = 0; c15_i8 < 4; c15_i8++) {
    (*c15_b_RC_TRPY_refs)[c15_i8] = c15_RC_TRPY_refs[c15_i8];
  }

  for (c15_i9 = 0; c15_i9 < 8; c15_i9++) {
    (*c15_b_RC_aux_channels)[c15_i9] = c15_RC_aux_channels[c15_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i10;
  real_T c15_b_inData[8];
  int32_T c15_i11;
  real_T c15_u[8];
  const mxArray *c15_y = NULL;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i10 = 0; c15_i10 < 8; c15_i10++) {
    c15_b_inData[c15_i10] = (*(real_T (*)[8])c15_inData)[c15_i10];
  }

  for (c15_i11 = 0; c15_i11 < 8; c15_i11++) {
    c15_u[c15_i11] = c15_b_inData[c15_i11];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_RC_aux_channels, const char_T *c15_identifier, real_T
   c15_y[8])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_RC_aux_channels),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_RC_aux_channels);
}

static void c15_b_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[8])
{
  real_T c15_dv2[8];
  int32_T c15_i12;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv2, 1, 0, 0U, 1, 0U, 1, 8);
  for (c15_i12 = 0; c15_i12 < 8; c15_i12++) {
    c15_y[c15_i12] = c15_dv2[c15_i12];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_RC_aux_channels;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[8];
  int32_T c15_i13;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_RC_aux_channels = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_RC_aux_channels),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_RC_aux_channels);
  for (c15_i13 = 0; c15_i13 < 8; c15_i13++) {
    (*(real_T (*)[8])c15_outData)[c15_i13] = c15_y[c15_i13];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i14;
  real_T c15_b_inData[4];
  int32_T c15_i15;
  real_T c15_u[4];
  const mxArray *c15_y = NULL;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i14 = 0; c15_i14 < 4; c15_i14++) {
    c15_b_inData[c15_i14] = (*(real_T (*)[4])c15_inData)[c15_i14];
  }

  for (c15_i15 = 0; c15_i15 < 4; c15_i15++) {
    c15_u[c15_i15] = c15_b_inData[c15_i15];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_RC_TRPY_refs, const char_T *c15_identifier, real_T c15_y[4])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_RC_TRPY_refs),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_RC_TRPY_refs);
}

static void c15_d_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[4])
{
  real_T c15_dv3[4];
  int32_T c15_i16;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c15_i16 = 0; c15_i16 < 4; c15_i16++) {
    c15_y[c15_i16] = c15_dv3[c15_i16];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_RC_TRPY_refs;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[4];
  int32_T c15_i17;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_RC_TRPY_refs = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_RC_TRPY_refs),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_RC_TRPY_refs);
  for (c15_i17 = 0; c15_i17 < 4; c15_i17++) {
    (*(real_T (*)[4])c15_outData)[c15_i17] = c15_y[c15_i17];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_e_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d13;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d13, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d13;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_THROTTLE_LOW_THRES;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_b_THROTTLE_LOW_THRES = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_THROTTLE_LOW_THRES), &c15_thisId);
  sf_mex_destroy(&c15_b_THROTTLE_LOW_THRES);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i18;
  real_T c15_b_inData[12];
  int32_T c15_i19;
  real_T c15_u[12];
  const mxArray *c15_y = NULL;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i18 = 0; c15_i18 < 12; c15_i18++) {
    c15_b_inData[c15_i18] = (*(real_T (*)[12])c15_inData)[c15_i18];
  }

  for (c15_i19 = 0; c15_i19 < 12; c15_i19++) {
    c15_u[c15_i19] = c15_b_inData[c15_i19];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

const mxArray
  *sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  const mxArray *c15_rhs4 = NULL;
  const mxArray *c15_lhs4 = NULL;
  const mxArray *c15_rhs5 = NULL;
  const mxArray *c15_lhs5 = NULL;
  const mxArray *c15_rhs6 = NULL;
  const mxArray *c15_lhs6 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c15_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c15_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c15_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
  sf_mex_destroy(&c15_rhs4);
  sf_mex_destroy(&c15_lhs4);
  sf_mex_destroy(&c15_rhs5);
  sf_mex_destroy(&c15_lhs5);
  sf_mex_destroy(&c15_rhs6);
  sf_mex_destroy(&c15_lhs6);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_f_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i20;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i20, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i20;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_g_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_b_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201,
   const char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201);
  return c15_y;
}

static uint8_T c15_h_emlrt_marshallIn
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance,
   const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info
  (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance)
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

void sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2054239218U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(453623385U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3499027646U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2308324570U);
}

mxArray
  *sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sj2jf7X0Z4mftEfUYtggoE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray
  *sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"RC_TRPY_refs\",},{M[1],M[14],T\"RC_aux_channels\",},{M[8],M[0],T\"is_active_c15_ICARO3_Onda_bipe_controllonostro_mix_2201\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_ICARO3_Onda_bipe_controllonostro_mix_2201_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance =
      (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
           15,
           1,
           1,
           0,
           16,
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
          (_ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pwms");
          _SFD_SET_DATA_PROPS(1,2,0,1,"RC_TRPY_refs");
          _SFD_SET_DATA_PROPS(2,2,0,1,"RC_aux_channels");
          _SFD_SET_DATA_PROPS(3,10,0,0,"THROTTLE_IDX");
          _SFD_SET_DATA_PROPS(4,10,0,0,"ROLL_IDX");
          _SFD_SET_DATA_PROPS(5,10,0,0,"PITCH_IDX");
          _SFD_SET_DATA_PROPS(6,10,0,0,"YAW_IDX");
          _SFD_SET_DATA_PROPS(7,10,0,0,"THROTTLE_DOWN");
          _SFD_SET_DATA_PROPS(8,10,0,0,"ROLL_MID");
          _SFD_SET_DATA_PROPS(9,10,0,0,"PITCH_MID");
          _SFD_SET_DATA_PROPS(10,10,0,0,"YAW_MID");
          _SFD_SET_DATA_PROPS(11,10,0,0,"INV_THROTTLE_RANGE");
          _SFD_SET_DATA_PROPS(12,10,0,0,"INV_ROLL_RANGE");
          _SFD_SET_DATA_PROPS(13,10,0,0,"INV_PITCH_RANGE");
          _SFD_SET_DATA_PROPS(14,10,0,0,"INV_YAW_RANGE");
          _SFD_SET_DATA_PROPS(15,10,0,0,"THROTTLE_LOW_THRES");
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
        _SFD_CV_INIT_EML(0,1,1,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3242);
        _SFD_CV_INIT_EML_IF(0,1,0,492,498,-1,1047);
        _SFD_CV_INIT_EML_IF(0,1,1,962,1004,-1,1042);
        _SFD_CV_INIT_EML_IF(0,1,2,1055,1061,-1,1660);
        _SFD_CV_INIT_EML_IF(0,1,3,1600,1617,-1,1655);
        _SFD_CV_INIT_EML_IF(0,1,4,1663,1669,-1,2247);
        _SFD_CV_INIT_EML_IF(0,1,5,2187,2204,-1,2242);
        _SFD_CV_INIT_EML_IF(0,1,6,2251,2257,-1,2868);
        _SFD_CV_INIT_EML_IF(0,1,7,2808,2825,-1,2863);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
            c15_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);

        {
          real_T (*c15_pwms)[12];
          real_T (*c15_RC_TRPY_refs)[4];
          real_T (*c15_RC_aux_channels)[8];
          c15_RC_aux_channels = (real_T (*)[8])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c15_RC_TRPY_refs = (real_T (*)[4])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c15_pwms = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_pwms);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_RC_TRPY_refs);
          _SFD_SET_DATA_VALUE_PTR(2U, *c15_RC_aux_channels);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c15_THROTTLE_IDX);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c15_ROLL_IDX);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c15_PITCH_IDX);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c15_YAW_IDX);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c15_THROTTLE_DOWN);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c15_ROLL_MID);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c15_PITCH_MID);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c15_YAW_MID);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c15_INV_THROTTLE_RANGE);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c15_INV_ROLL_RANGE);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c15_INV_PITCH_RANGE);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c15_INV_YAW_RANGE);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c15_THROTTLE_LOW_THRES);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_controllonostro_mix_2201MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "rz3TPjmGLxgiZEIQUdypJG";
}

static void sf_opaque_initialize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
  initialize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(void *
  chartInstanceVar)
{
  enable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(void
  *chartInstanceVar)
{
  disable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(void
  *chartInstanceVar)
{
  sf_gateway_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*)
    get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c15_ICARO3_Onda_bipe_controllonostro_mix_2201();/* state var info */
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

extern void
  sf_internal_set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
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
    sf_get_sim_state_info_c15_ICARO3_Onda_bipe_controllonostro_mix_2201();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
    (S);
}

static void
  sf_opaque_set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(S, st);
}

static void sf_opaque_terminate_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
       chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro_mix_2201_optimization_info();
    }

    finalize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
      ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
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
  initSimStructsc15_ICARO3_Onda_bipe_controllonostro_mix_2201
    ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
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
    initialize_params_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
      ((SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_ICARO3_Onda_bipe_controllonostro_mix_2201
  (SimStruct *S)
{
  /* Actual parameters from chart:
     INV_PITCH_RANGE INV_ROLL_RANGE INV_THROTTLE_RANGE INV_YAW_RANGE PITCH_IDX PITCH_MID ROLL_IDX ROLL_MID THROTTLE_DOWN THROTTLE_IDX THROTTLE_LOW_THRES YAW_IDX YAW_MID
   */
  const char_T *rtParamNames[] = { "INV_PITCH_RANGE", "INV_ROLL_RANGE",
    "INV_THROTTLE_RANGE", "INV_YAW_RANGE", "PITCH_IDX", "PITCH_MID", "ROLL_IDX",
    "ROLL_MID", "THROTTLE_DOWN", "THROTTLE_IDX", "THROTTLE_LOW_THRES", "YAW_IDX",
    "YAW_MID" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for INV_PITCH_RANGE*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for INV_ROLL_RANGE*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for INV_THROTTLE_RANGE*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for INV_YAW_RANGE*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for PITCH_IDX*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for PITCH_MID*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for ROLL_IDX*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for ROLL_MID*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for THROTTLE_DOWN*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);

  /* registration for THROTTLE_IDX*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_DOUBLE);

  /* registration for THROTTLE_LOW_THRES*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_DOUBLE);

  /* registration for YAW_IDX*/
  ssRegDlgParamAsRunTimeParam(S, 11, 11, rtParamNames[11], SS_DOUBLE);

  /* registration for YAW_MID*/
  ssRegDlgParamAsRunTimeParam(S, 12, 12, rtParamNames[12], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro_mix_2201_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3783133537U));
  ssSetChecksum1(S,(1687459046U));
  ssSetChecksum2(S,(3675085080U));
  ssSetChecksum3(S,(160579642U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(SimStruct *S)
{
  SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
                   *)utMalloc(sizeof
    (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc15_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_ICARO3_Onda_bipe_controllonostro_mix_2201;
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

void c15_ICARO3_Onda_bipe_controllonostro_mix_2201_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_ICARO3_Onda_bipe_controllonostro_mix_2201(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_ICARO3_Onda_bipe_controllonostro_mix_2201_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
