/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun.h"
#include "c103_ICARO3_Onda_bipe_controllonostro40cm.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c103_debug_family_names[13] = { "ax", "ay", "az", "wx", "wy",
  "wz", "a_adis", "w_adis", "nargin", "nargout", "u", "a", "w" };

static const char * c103_b_debug_family_names[4] = { "u", "nargin", "nargout",
  "y" };

/* Function Declarations */
static void initialize_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initialize_params_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void enable_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void disable_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c103_update_debugger_state_c103_ICARO3_Onda_bipe_controllonostro
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_st);
static void finalize_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void sf_gateway_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c103_chartstep_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initSimStructsc103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c103_machineNumber, uint32_T
  c103_chartNumber, uint32_T c103_instanceNumber);
static const mxArray *c103_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static void c103_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_w, const char_T *c103_identifier, real32_T c103_y[3]);
static void c103_b_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId, real32_T
   c103_y[3]);
static void c103_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData);
static const mxArray *c103_b_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static const mxArray *c103_c_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static real_T c103_c_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId);
static void c103_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData);
static const mxArray *c103_d_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static real32_T c103_d_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId);
static void c103_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData);
static const mxArray *c103_e_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static uint16_T c103_e_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId);
static void c103_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData);
static void c103_info_helper(const mxArray **c103_info);
static const mxArray *c103_emlrt_marshallOut(const char * c103_u);
static const mxArray *c103_b_emlrt_marshallOut(const uint32_T c103_u);
static real32_T c103_decomp
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   uint16_T c103_u);
static void c103_eml_scalar_eg
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static const mxArray *c103_f_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData);
static int32_T c103_f_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId);
static void c103_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData);
static uint8_T c103_g_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_b_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c103_identifier);
static uint8_T c103_h_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId);
static void init_dsm_address_info
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  chartInstance->c103_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c103_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm = 0U;
}

static void initialize_params_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c103_update_debugger_state_c103_ICARO3_Onda_bipe_controllonostro
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  const mxArray *c103_st;
  const mxArray *c103_y = NULL;
  int32_T c103_i0;
  real32_T c103_u[3];
  const mxArray *c103_b_y = NULL;
  int32_T c103_i1;
  real32_T c103_b_u[3];
  const mxArray *c103_c_y = NULL;
  uint8_T c103_hoistedGlobal;
  uint8_T c103_c_u;
  const mxArray *c103_d_y = NULL;
  real32_T (*c103_w)[3];
  real32_T (*c103_a)[3];
  c103_w = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c103_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c103_st = NULL;
  c103_st = NULL;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_createcellmatrix(3, 1), false);
  for (c103_i0 = 0; c103_i0 < 3; c103_i0++) {
    c103_u[c103_i0] = (*c103_a)[c103_i0];
  }

  c103_b_y = NULL;
  sf_mex_assign(&c103_b_y, sf_mex_create("y", c103_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c103_y, 0, c103_b_y);
  for (c103_i1 = 0; c103_i1 < 3; c103_i1++) {
    c103_b_u[c103_i1] = (*c103_w)[c103_i1];
  }

  c103_c_y = NULL;
  sf_mex_assign(&c103_c_y, sf_mex_create("y", c103_b_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c103_y, 1, c103_c_y);
  c103_hoistedGlobal =
    chartInstance->c103_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm;
  c103_c_u = c103_hoistedGlobal;
  c103_d_y = NULL;
  sf_mex_assign(&c103_d_y, sf_mex_create("y", &c103_c_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c103_y, 2, c103_d_y);
  sf_mex_assign(&c103_st, c103_y, false);
  return c103_st;
}

static void set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_st)
{
  const mxArray *c103_u;
  real32_T c103_fv0[3];
  int32_T c103_i2;
  real32_T c103_fv1[3];
  int32_T c103_i3;
  real32_T (*c103_a)[3];
  real32_T (*c103_w)[3];
  c103_w = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c103_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c103_doneDoubleBufferReInit = true;
  c103_u = sf_mex_dup(c103_st);
  c103_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c103_u, 0)),
                        "a", c103_fv0);
  for (c103_i2 = 0; c103_i2 < 3; c103_i2++) {
    (*c103_a)[c103_i2] = c103_fv0[c103_i2];
  }

  c103_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c103_u, 1)),
                        "w", c103_fv1);
  for (c103_i3 = 0; c103_i3 < 3; c103_i3++) {
    (*c103_w)[c103_i3] = c103_fv1[c103_i3];
  }

  chartInstance->c103_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm =
    c103_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c103_u, 2)),
    "is_active_c103_ICARO3_Onda_bipe_controllonostro40cm");
  sf_mex_destroy(&c103_u);
  c103_update_debugger_state_c103_ICARO3_Onda_bipe_controllonostro(chartInstance);
  sf_mex_destroy(&c103_st);
}

static void finalize_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  int32_T c103_i4;
  int32_T c103_i5;
  int32_T c103_i6;
  real32_T (*c103_w)[3];
  real32_T (*c103_a)[3];
  uint16_T (*c103_u)[6];
  c103_w = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c103_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c103_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c103_sfEvent);
  for (c103_i4 = 0; c103_i4 < 6; c103_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c103_u)[c103_i4], 0U);
  }

  chartInstance->c103_sfEvent = CALL_EVENT;
  c103_chartstep_c103_ICARO3_Onda_bipe_controllonostro40cm(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c103_i5 = 0; c103_i5 < 3; c103_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c103_a)[c103_i5], 1U);
  }

  for (c103_i6 = 0; c103_i6 < 3; c103_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c103_w)[c103_i6], 2U);
  }
}

static void c103_chartstep_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  int32_T c103_i7;
  uint16_T c103_u[6];
  uint32_T c103_debug_family_var_map[13];
  real32_T c103_ax;
  real32_T c103_ay;
  real32_T c103_az;
  real32_T c103_wx;
  real32_T c103_wy;
  real32_T c103_wz;
  real32_T c103_a_adis[3];
  real32_T c103_w_adis[3];
  real_T c103_nargin = 1.0;
  real_T c103_nargout = 2.0;
  real32_T c103_a[3];
  real32_T c103_w[3];
  real32_T c103_b_a;
  real32_T c103_y;
  real32_T c103_c_a;
  real32_T c103_b_y;
  real32_T c103_A;
  real32_T c103_x;
  real32_T c103_b_x;
  real32_T c103_c_x;
  real32_T c103_d_a;
  real32_T c103_c_y;
  real32_T c103_e_a;
  real32_T c103_d_y;
  real32_T c103_b_A;
  real32_T c103_d_x;
  real32_T c103_e_x;
  real32_T c103_f_x;
  real32_T c103_f_a;
  real32_T c103_e_y;
  real32_T c103_g_a;
  real32_T c103_f_y;
  real32_T c103_c_A;
  real32_T c103_g_x;
  real32_T c103_h_x;
  real32_T c103_i_x;
  real32_T c103_h_a;
  real32_T c103_g_y;
  real32_T c103_i_a;
  real32_T c103_h_y;
  real32_T c103_d_A;
  real32_T c103_j_x;
  real32_T c103_k_x;
  real32_T c103_l_x;
  real32_T c103_j_a;
  real32_T c103_i_y;
  real32_T c103_k_a;
  real32_T c103_j_y;
  real32_T c103_e_A;
  real32_T c103_m_x;
  real32_T c103_n_x;
  real32_T c103_o_x;
  real32_T c103_l_a;
  real32_T c103_k_y;
  real32_T c103_m_a;
  real32_T c103_l_y;
  real32_T c103_f_A;
  real32_T c103_p_x;
  real32_T c103_q_x;
  real32_T c103_r_x;
  int32_T c103_i8;
  real32_T c103_b[3];
  int32_T c103_i9;
  int32_T c103_i10;
  int32_T c103_i11;
  static real32_T c103_fv2[9] = { -1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 1.0F };

  int32_T c103_i12;
  int32_T c103_i13;
  int32_T c103_i14;
  int32_T c103_i15;
  static real32_T c103_fv3[9] = { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F,
    0.0F, -1.0F };

  int32_T c103_i16;
  int32_T c103_i17;
  real32_T (*c103_n_a)[3];
  real32_T (*c103_b_w)[3];
  uint16_T (*c103_b_u)[6];
  c103_b_w = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c103_n_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c103_b_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c103_sfEvent);
  for (c103_i7 = 0; c103_i7 < 6; c103_i7++) {
    c103_u[c103_i7] = (*c103_b_u)[c103_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c103_debug_family_names,
    c103_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_ax, 0U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_ay, 1U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_az, 2U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_wx, 3U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_wy, 4U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_wz, 5U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c103_a_adis, 6U, c103_sf_marshallOut,
    c103_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c103_w_adis, 7U, c103_sf_marshallOut,
    c103_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_nargin, 8U, c103_c_sf_marshallOut,
    c103_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_nargout, 9U, c103_c_sf_marshallOut,
    c103_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c103_u, 10U, c103_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c103_a, 11U, c103_sf_marshallOut,
    c103_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c103_w, 12U, c103_sf_marshallOut,
    c103_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 6);
  c103_b_a = c103_decomp(chartInstance, c103_u[0]);
  c103_y = c103_b_a * 2.522F;
  c103_c_a = c103_y;
  c103_b_y = c103_c_a * 9.81F;
  c103_A = c103_b_y;
  c103_x = c103_A;
  c103_b_x = c103_x;
  c103_c_x = c103_b_x;
  c103_ax = c103_c_x / 1000.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 7);
  c103_d_a = c103_decomp(chartInstance, c103_u[1]);
  c103_c_y = c103_d_a * 2.522F;
  c103_e_a = c103_c_y;
  c103_d_y = c103_e_a * 9.81F;
  c103_b_A = c103_d_y;
  c103_d_x = c103_b_A;
  c103_e_x = c103_d_x;
  c103_f_x = c103_e_x;
  c103_ay = c103_f_x / 1000.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 8);
  c103_f_a = c103_decomp(chartInstance, c103_u[2]);
  c103_e_y = c103_f_a * 2.522F;
  c103_g_a = c103_e_y;
  c103_f_y = c103_g_a * 9.81F;
  c103_c_A = c103_f_y;
  c103_g_x = c103_c_A;
  c103_h_x = c103_g_x;
  c103_i_x = c103_h_x;
  c103_az = c103_i_x / 1000.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 12);
  c103_h_a = c103_decomp(chartInstance, c103_u[3]);
  c103_g_y = c103_h_a * 0.07326F;
  c103_i_a = c103_g_y;
  c103_h_y = c103_i_a * 3.14159274F;
  c103_d_A = c103_h_y;
  c103_j_x = c103_d_A;
  c103_k_x = c103_j_x;
  c103_l_x = c103_k_x;
  c103_wx = c103_l_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 13);
  c103_j_a = c103_decomp(chartInstance, c103_u[4]);
  c103_i_y = c103_j_a * 0.07326F;
  c103_k_a = c103_i_y;
  c103_j_y = c103_k_a * 3.14159274F;
  c103_e_A = c103_j_y;
  c103_m_x = c103_e_A;
  c103_n_x = c103_m_x;
  c103_o_x = c103_n_x;
  c103_wy = c103_o_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 14);
  c103_l_a = c103_decomp(chartInstance, c103_u[5]);
  c103_k_y = c103_l_a * 0.07326F;
  c103_m_a = c103_k_y;
  c103_l_y = c103_m_a * 3.14159274F;
  c103_f_A = c103_l_y;
  c103_p_x = c103_f_A;
  c103_q_x = c103_p_x;
  c103_r_x = c103_q_x;
  c103_wz = c103_r_x / 180.0F;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 16);
  c103_a_adis[0] = c103_ax;
  c103_a_adis[1] = c103_ay;
  c103_a_adis[2] = c103_az;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 17);
  c103_w_adis[0] = c103_wx;
  c103_w_adis[1] = c103_wy;
  c103_w_adis[2] = c103_wz;
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 21);
  for (c103_i8 = 0; c103_i8 < 3; c103_i8++) {
    c103_b[c103_i8] = c103_a_adis[c103_i8];
  }

  for (c103_i9 = 0; c103_i9 < 3; c103_i9++) {
    c103_a[c103_i9] = 0.0F;
    c103_i10 = 0;
    for (c103_i11 = 0; c103_i11 < 3; c103_i11++) {
      c103_a[c103_i9] += c103_fv2[c103_i10 + c103_i9] * c103_b[c103_i11];
      c103_i10 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 22);
  for (c103_i12 = 0; c103_i12 < 3; c103_i12++) {
    c103_b[c103_i12] = c103_w_adis[c103_i12];
  }

  for (c103_i13 = 0; c103_i13 < 3; c103_i13++) {
    c103_w[c103_i13] = 0.0F;
    c103_i14 = 0;
    for (c103_i15 = 0; c103_i15 < 3; c103_i15++) {
      c103_w[c103_i13] += c103_fv3[c103_i14 + c103_i13] * c103_b[c103_i15];
      c103_i14 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c103_i16 = 0; c103_i16 < 3; c103_i16++) {
    (*c103_n_a)[c103_i16] = c103_a[c103_i16];
  }

  for (c103_i17 = 0; c103_i17 < 3; c103_i17++) {
    (*c103_b_w)[c103_i17] = c103_w[c103_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c103_sfEvent);
}

static void initSimStructsc103_ICARO3_Onda_bipe_controllonostro40cm
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c103_machineNumber, uint32_T
  c103_chartNumber, uint32_T c103_instanceNumber)
{
  (void)c103_machineNumber;
  (void)c103_chartNumber;
  (void)c103_instanceNumber;
}

static const mxArray *c103_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  int32_T c103_i18;
  real32_T c103_b_inData[3];
  int32_T c103_i19;
  real32_T c103_u[3];
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  for (c103_i18 = 0; c103_i18 < 3; c103_i18++) {
    c103_b_inData[c103_i18] = (*(real32_T (*)[3])c103_inData)[c103_i18];
  }

  for (c103_i19 = 0; c103_i19 < 3; c103_i19++) {
    c103_u[c103_i19] = c103_b_inData[c103_i19];
  }

  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", c103_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static void c103_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_w, const char_T *c103_identifier, real32_T c103_y[3])
{
  emlrtMsgIdentifier c103_thisId;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_w), &c103_thisId,
    c103_y);
  sf_mex_destroy(&c103_w);
}

static void c103_b_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId, real32_T
   c103_y[3])
{
  real32_T c103_fv4[3];
  int32_T c103_i20;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), c103_fv4, 1, 1, 0U, 1, 0U, 1,
                3);
  for (c103_i20 = 0; c103_i20 < 3; c103_i20++) {
    c103_y[c103_i20] = c103_fv4[c103_i20];
  }

  sf_mex_destroy(&c103_u);
}

static void c103_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData)
{
  const mxArray *c103_w;
  const char_T *c103_identifier;
  emlrtMsgIdentifier c103_thisId;
  real32_T c103_y[3];
  int32_T c103_i21;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_w = sf_mex_dup(c103_mxArrayInData);
  c103_identifier = c103_varName;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_w), &c103_thisId,
    c103_y);
  sf_mex_destroy(&c103_w);
  for (c103_i21 = 0; c103_i21 < 3; c103_i21++) {
    (*(real32_T (*)[3])c103_outData)[c103_i21] = c103_y[c103_i21];
  }

  sf_mex_destroy(&c103_mxArrayInData);
}

static const mxArray *c103_b_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  int32_T c103_i22;
  uint16_T c103_b_inData[6];
  int32_T c103_i23;
  uint16_T c103_u[6];
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  for (c103_i22 = 0; c103_i22 < 6; c103_i22++) {
    c103_b_inData[c103_i22] = (*(uint16_T (*)[6])c103_inData)[c103_i22];
  }

  for (c103_i23 = 0; c103_i23 < 6; c103_i23++) {
    c103_u[c103_i23] = c103_b_inData[c103_i23];
  }

  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", c103_u, 5, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static const mxArray *c103_c_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  real_T c103_u;
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  c103_u = *(real_T *)c103_inData;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", &c103_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static real_T c103_c_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId)
{
  real_T c103_y;
  real_T c103_d0;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), &c103_d0, 1, 0, 0U, 0, 0U, 0);
  c103_y = c103_d0;
  sf_mex_destroy(&c103_u);
  return c103_y;
}

static void c103_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData)
{
  const mxArray *c103_nargout;
  const char_T *c103_identifier;
  emlrtMsgIdentifier c103_thisId;
  real_T c103_y;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_nargout = sf_mex_dup(c103_mxArrayInData);
  c103_identifier = c103_varName;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_y = c103_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_nargout),
    &c103_thisId);
  sf_mex_destroy(&c103_nargout);
  *(real_T *)c103_outData = c103_y;
  sf_mex_destroy(&c103_mxArrayInData);
}

static const mxArray *c103_d_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  real32_T c103_u;
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  c103_u = *(real32_T *)c103_inData;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", &c103_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static real32_T c103_d_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId)
{
  real32_T c103_y;
  real32_T c103_f0;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), &c103_f0, 1, 1, 0U, 0, 0U, 0);
  c103_y = c103_f0;
  sf_mex_destroy(&c103_u);
  return c103_y;
}

static void c103_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData)
{
  const mxArray *c103_wz;
  const char_T *c103_identifier;
  emlrtMsgIdentifier c103_thisId;
  real32_T c103_y;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_wz = sf_mex_dup(c103_mxArrayInData);
  c103_identifier = c103_varName;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_y = c103_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_wz),
    &c103_thisId);
  sf_mex_destroy(&c103_wz);
  *(real32_T *)c103_outData = c103_y;
  sf_mex_destroy(&c103_mxArrayInData);
}

static const mxArray *c103_e_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  uint16_T c103_u;
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  c103_u = *(uint16_T *)c103_inData;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", &c103_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static uint16_T c103_e_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId)
{
  uint16_T c103_y;
  uint16_T c103_u0;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), &c103_u0, 1, 5, 0U, 0, 0U, 0);
  c103_y = c103_u0;
  sf_mex_destroy(&c103_u);
  return c103_y;
}

static void c103_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData)
{
  const mxArray *c103_u;
  const char_T *c103_identifier;
  emlrtMsgIdentifier c103_thisId;
  uint16_T c103_y;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_u = sf_mex_dup(c103_mxArrayInData);
  c103_identifier = c103_varName;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_y = c103_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_u),
    &c103_thisId);
  sf_mex_destroy(&c103_u);
  *(uint16_T *)c103_outData = c103_y;
  sf_mex_destroy(&c103_mxArrayInData);
}

const mxArray
  *sf_c103_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c103_nameCaptureInfo = NULL;
  c103_nameCaptureInfo = NULL;
  sf_mex_assign(&c103_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c103_info_helper(&c103_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c103_nameCaptureInfo);
  return c103_nameCaptureInfo;
}

static void c103_info_helper(const mxArray **c103_info)
{
  const mxArray *c103_rhs0 = NULL;
  const mxArray *c103_lhs0 = NULL;
  const mxArray *c103_rhs1 = NULL;
  const mxArray *c103_lhs1 = NULL;
  const mxArray *c103_rhs2 = NULL;
  const mxArray *c103_lhs2 = NULL;
  const mxArray *c103_rhs3 = NULL;
  const mxArray *c103_lhs3 = NULL;
  const mxArray *c103_rhs4 = NULL;
  const mxArray *c103_lhs4 = NULL;
  const mxArray *c103_rhs5 = NULL;
  const mxArray *c103_lhs5 = NULL;
  const mxArray *c103_rhs6 = NULL;
  const mxArray *c103_lhs6 = NULL;
  const mxArray *c103_rhs7 = NULL;
  const mxArray *c103_lhs7 = NULL;
  const mxArray *c103_rhs8 = NULL;
  const mxArray *c103_lhs8 = NULL;
  const mxArray *c103_rhs9 = NULL;
  const mxArray *c103_lhs9 = NULL;
  const mxArray *c103_rhs10 = NULL;
  const mxArray *c103_lhs10 = NULL;
  const mxArray *c103_rhs11 = NULL;
  const mxArray *c103_lhs11 = NULL;
  const mxArray *c103_rhs12 = NULL;
  const mxArray *c103_lhs12 = NULL;
  const mxArray *c103_rhs13 = NULL;
  const mxArray *c103_lhs13 = NULL;
  const mxArray *c103_rhs14 = NULL;
  const mxArray *c103_lhs14 = NULL;
  const mxArray *c103_rhs15 = NULL;
  const mxArray *c103_lhs15 = NULL;
  const mxArray *c103_rhs16 = NULL;
  const mxArray *c103_lhs16 = NULL;
  const mxArray *c103_rhs17 = NULL;
  const mxArray *c103_lhs17 = NULL;
  const mxArray *c103_rhs18 = NULL;
  const mxArray *c103_lhs18 = NULL;
  const mxArray *c103_rhs19 = NULL;
  const mxArray *c103_lhs19 = NULL;
  const mxArray *c103_rhs20 = NULL;
  const mxArray *c103_lhs20 = NULL;
  const mxArray *c103_rhs21 = NULL;
  const mxArray *c103_lhs21 = NULL;
  const mxArray *c103_rhs22 = NULL;
  const mxArray *c103_lhs22 = NULL;
  const mxArray *c103_rhs23 = NULL;
  const mxArray *c103_lhs23 = NULL;
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(""), "context", "context",
                  0);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("mpower"), "name", "name",
                  0);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363713878U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c103_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs0), "rhs",
                  "rhs", 0);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs0), "lhs",
                  "lhs", 0);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c103_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs1), "rhs",
                  "rhs", 1);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs1), "lhs",
                  "lhs", 1);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1331304858U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c103_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs2), "rhs",
                  "rhs", 2);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs2), "lhs",
                  "lhs", 2);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363713880U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c103_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs3), "rhs",
                  "rhs", 3);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs3), "lhs",
                  "lhs", 3);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c103_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs4), "rhs",
                  "rhs", 4);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs4), "lhs",
                  "lhs", 4);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c103_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs5), "rhs",
                  "rhs", 5);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs5), "lhs",
                  "lhs", 5);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c103_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs6), "rhs",
                  "rhs", 6);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs6), "lhs",
                  "lhs", 6);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_scalexp_alloc"),
                  "name", "name", 7);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c103_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs7), "rhs",
                  "rhs", 7);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs7), "lhs",
                  "lhs", 7);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.scalexpAlloc"), "name", "name", 8);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c103_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs8), "rhs",
                  "rhs", 8);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs8), "lhs",
                  "lhs", 8);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363713854U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c103_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs9), "rhs",
                  "rhs", 9);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs9), "lhs",
                  "lhs", 9);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c103_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs10), "rhs",
                  "rhs", 10);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs10), "lhs",
                  "lhs", 10);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1286818726U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c103_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs11), "rhs",
                  "rhs", 11);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs11), "lhs",
                  "lhs", 11);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c103_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs12), "rhs",
                  "rhs", 12);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs12), "lhs",
                  "lhs", 12);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(""), "context", "context",
                  13);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_mtimes_helper"),
                  "name", "name", 13);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1383877294U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c103_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs13), "rhs",
                  "rhs", 13);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs13), "lhs",
                  "lhs", 13);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 14);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c103_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs14), "rhs",
                  "rhs", 14);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs14), "lhs",
                  "lhs", 14);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 15);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c103_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs15), "rhs",
                  "rhs", 15);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs15), "lhs",
                  "lhs", 15);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(""), "context", "context",
                  16);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("mrdivide"), "name", "name",
                  16);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1388460096U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1370009886U),
                  "mFileTimeLo", "mFileTimeLo", 16);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c103_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs16), "rhs",
                  "rhs", 16);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs16), "lhs",
                  "lhs", 16);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c103_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs17), "rhs",
                  "rhs", 17);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs17), "lhs",
                  "lhs", 17);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 18);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("rdivide"), "name", "name",
                  18);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363713880U),
                  "fileTimeLo", "fileTimeLo", 18);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c103_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs18), "rhs",
                  "rhs", 18);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs18), "lhs",
                  "lhs", 18);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 19);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c103_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs19), "rhs",
                  "rhs", 19);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs19), "lhs",
                  "lhs", 19);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1363714556U),
                  "fileTimeLo", "fileTimeLo", 20);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c103_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs20), "rhs",
                  "rhs", 20);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs20), "lhs",
                  "lhs", 20);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 21);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1286818796U),
                  "fileTimeLo", "fileTimeLo", 21);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c103_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs21), "rhs",
                  "rhs", 21);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs21), "lhs",
                  "lhs", 21);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("eml_div"), "name", "name",
                  22);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1375980688U),
                  "fileTimeLo", "fileTimeLo", 22);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c103_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs22), "rhs",
                  "rhs", 22);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs22), "lhs",
                  "lhs", 22);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("coder.internal.div"),
                  "name", "name", 23);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c103_info, c103_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(1389307920U),
                  "fileTimeLo", "fileTimeLo", 23);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c103_info, c103_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c103_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c103_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_rhs23), "rhs",
                  "rhs", 23);
  sf_mex_addfield(*c103_info, sf_mex_duplicatearraysafe(&c103_lhs23), "lhs",
                  "lhs", 23);
  sf_mex_destroy(&c103_rhs0);
  sf_mex_destroy(&c103_lhs0);
  sf_mex_destroy(&c103_rhs1);
  sf_mex_destroy(&c103_lhs1);
  sf_mex_destroy(&c103_rhs2);
  sf_mex_destroy(&c103_lhs2);
  sf_mex_destroy(&c103_rhs3);
  sf_mex_destroy(&c103_lhs3);
  sf_mex_destroy(&c103_rhs4);
  sf_mex_destroy(&c103_lhs4);
  sf_mex_destroy(&c103_rhs5);
  sf_mex_destroy(&c103_lhs5);
  sf_mex_destroy(&c103_rhs6);
  sf_mex_destroy(&c103_lhs6);
  sf_mex_destroy(&c103_rhs7);
  sf_mex_destroy(&c103_lhs7);
  sf_mex_destroy(&c103_rhs8);
  sf_mex_destroy(&c103_lhs8);
  sf_mex_destroy(&c103_rhs9);
  sf_mex_destroy(&c103_lhs9);
  sf_mex_destroy(&c103_rhs10);
  sf_mex_destroy(&c103_lhs10);
  sf_mex_destroy(&c103_rhs11);
  sf_mex_destroy(&c103_lhs11);
  sf_mex_destroy(&c103_rhs12);
  sf_mex_destroy(&c103_lhs12);
  sf_mex_destroy(&c103_rhs13);
  sf_mex_destroy(&c103_lhs13);
  sf_mex_destroy(&c103_rhs14);
  sf_mex_destroy(&c103_lhs14);
  sf_mex_destroy(&c103_rhs15);
  sf_mex_destroy(&c103_lhs15);
  sf_mex_destroy(&c103_rhs16);
  sf_mex_destroy(&c103_lhs16);
  sf_mex_destroy(&c103_rhs17);
  sf_mex_destroy(&c103_lhs17);
  sf_mex_destroy(&c103_rhs18);
  sf_mex_destroy(&c103_lhs18);
  sf_mex_destroy(&c103_rhs19);
  sf_mex_destroy(&c103_lhs19);
  sf_mex_destroy(&c103_rhs20);
  sf_mex_destroy(&c103_lhs20);
  sf_mex_destroy(&c103_rhs21);
  sf_mex_destroy(&c103_lhs21);
  sf_mex_destroy(&c103_rhs22);
  sf_mex_destroy(&c103_lhs22);
  sf_mex_destroy(&c103_rhs23);
  sf_mex_destroy(&c103_lhs23);
}

static const mxArray *c103_emlrt_marshallOut(const char * c103_u)
{
  const mxArray *c103_y = NULL;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", c103_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c103_u)), false);
  return c103_y;
}

static const mxArray *c103_b_emlrt_marshallOut(const uint32_T c103_u)
{
  const mxArray *c103_y = NULL;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", &c103_u, 7, 0U, 0U, 0U, 0), false);
  return c103_y;
}

static real32_T c103_decomp
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   uint16_T c103_u)
{
  real32_T c103_y;
  uint32_T c103_debug_family_var_map[4];
  real32_T c103_b_u;
  real_T c103_nargin = 1.0;
  real_T c103_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c103_b_debug_family_names,
    c103_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_b_u, MAX_uint32_T,
    c103_d_sf_marshallOut, c103_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_nargin, 1U, c103_c_sf_marshallOut,
    c103_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_nargout, 2U, c103_c_sf_marshallOut,
    c103_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_u, 0U, c103_e_sf_marshallOut,
    c103_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c103_y, 3U, c103_d_sf_marshallOut,
    c103_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 28);
  c103_b_u = (real32_T)c103_u;
  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 30);
  c103_eml_scalar_eg(chartInstance);
  c103_eml_scalar_eg(chartInstance);
  if (CV_EML_IF(0, 1, 0, c103_b_u > 8191.0F)) {
    _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 31);
    c103_eml_scalar_eg(chartInstance);
    c103_eml_scalar_eg(chartInstance);
    c103_y = -16384.0F + c103_b_u;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, 33);
    c103_y = c103_b_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c103_sfEvent, -33);
  _SFD_SYMBOL_SCOPE_POP();
  return c103_y;
}

static void c103_eml_scalar_eg
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c103_f_sf_marshallOut(void *chartInstanceVoid, void
  *c103_inData)
{
  const mxArray *c103_mxArrayOutData = NULL;
  int32_T c103_u;
  const mxArray *c103_y = NULL;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_mxArrayOutData = NULL;
  c103_u = *(int32_T *)c103_inData;
  c103_y = NULL;
  sf_mex_assign(&c103_y, sf_mex_create("y", &c103_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c103_mxArrayOutData, c103_y, false);
  return c103_mxArrayOutData;
}

static int32_T c103_f_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId)
{
  int32_T c103_y;
  int32_T c103_i24;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), &c103_i24, 1, 6, 0U, 0, 0U, 0);
  c103_y = c103_i24;
  sf_mex_destroy(&c103_u);
  return c103_y;
}

static void c103_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c103_mxArrayInData, const char_T *c103_varName, void *c103_outData)
{
  const mxArray *c103_b_sfEvent;
  const char_T *c103_identifier;
  emlrtMsgIdentifier c103_thisId;
  int32_T c103_y;
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c103_b_sfEvent = sf_mex_dup(c103_mxArrayInData);
  c103_identifier = c103_varName;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_y = c103_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c103_b_sfEvent),
    &c103_thisId);
  sf_mex_destroy(&c103_b_sfEvent);
  *(int32_T *)c103_outData = c103_y;
  sf_mex_destroy(&c103_mxArrayInData);
}

static uint8_T c103_g_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_b_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c103_identifier)
{
  uint8_T c103_y;
  emlrtMsgIdentifier c103_thisId;
  c103_thisId.fIdentifier = c103_identifier;
  c103_thisId.fParent = NULL;
  c103_y = c103_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c103_b_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm), &c103_thisId);
  sf_mex_destroy(&c103_b_is_active_c103_ICARO3_Onda_bipe_controllonostro40cm);
  return c103_y;
}

static uint8_T c103_h_emlrt_marshallIn
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c103_u, const emlrtMsgIdentifier *c103_parentId)
{
  uint8_T c103_y;
  uint8_T c103_u1;
  (void)chartInstance;
  sf_mex_import(c103_parentId, sf_mex_dup(c103_u), &c103_u1, 1, 3, 0U, 0, 0U, 0);
  c103_y = c103_u1;
  sf_mex_destroy(&c103_u);
  return c103_y;
}

static void init_dsm_address_info
  (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
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

void sf_c103_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1147065735U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1153559712U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3783151925U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3418041944U);
}

mxArray *sf_c103_ICARO3_Onda_bipe_controllonostro40cm_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("22mv0JONUG4qpfjj3mv4hE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[0] = (double)(3);
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

mxArray *sf_c103_ICARO3_Onda_bipe_controllonostro40cm_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c103_ICARO3_Onda_bipe_controllonostro40cm_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c103_ICARO3_Onda_bipe_controllonostro40cm(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"a\",},{M[1],M[13],T\"w\",},{M[8],M[0],T\"is_active_c103_ICARO3_Onda_bipe_controllonostro40cm\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c103_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           103,
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
        init_script_number_translation
          (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a");
          _SFD_SET_DATA_PROPS(2,2,0,1,"w");
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
        _SFD_CV_INIT_EML(0,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,472);
        _SFD_CV_INIT_EML_FCN(0,1,"decomp",474,-1,591);
        _SFD_CV_INIT_EML_IF(0,1,0,514,531,559,586);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c103_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c103_sf_marshallOut,(MexInFcnForType)
            c103_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c103_sf_marshallOut,(MexInFcnForType)
            c103_sf_marshallIn);
        }

        {
          uint16_T (*c103_u)[6];
          real32_T (*c103_a)[3];
          real32_T (*c103_w)[3];
          c103_w = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c103_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c103_u = (uint16_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c103_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c103_a);
          _SFD_SET_DATA_VALUE_PTR(2U, *c103_w);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sNdcJhz2XfIfr32n5mOuBC";
}

static void sf_opaque_initialize_c103_ICARO3_Onda_bipe_controllonostro40cm(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
  initialize_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c103_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  enable_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c103_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  disable_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c103_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  sf_gateway_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c103_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
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

extern void sf_internal_set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
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
    sf_get_sim_state_info_c103_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm(SimStruct* S)
{
  return sf_internal_get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm(S);
}

static void sf_opaque_set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm(S, st);
}

static void sf_opaque_terminate_c103_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    }

    finalize_c103_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
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
  initSimStructsc103_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c103_ICARO3_Onda_bipe_controllonostro40cm
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
    initialize_params_c103_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c103_ICARO3_Onda_bipe_controllonostro40cm(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      103);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,103,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,103,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,103);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,103,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,103,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,103);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4166995737U));
  ssSetChecksum1(S,(2724417292U));
  ssSetChecksum2(S,(77983122U));
  ssSetChecksum3(S,(2932154518U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c103_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c103_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    utMalloc(sizeof(SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc103_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c103_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c103_ICARO3_Onda_bipe_controllonostro40cm;
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

void c103_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c103_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c103_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c103_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c103_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
