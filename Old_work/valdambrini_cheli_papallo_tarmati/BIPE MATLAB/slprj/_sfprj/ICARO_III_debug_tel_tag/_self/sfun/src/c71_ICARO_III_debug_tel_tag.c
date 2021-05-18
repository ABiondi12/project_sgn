/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO_III_debug_tel_tag_sfun.h"
#include "c71_ICARO_III_debug_tel_tag.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ICARO_III_debug_tel_tag_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c71_debug_family_names[50] = { "mode", "q1", "q2", "q3",
  "q4", "gx", "gy", "gz", "ax", "ay", "az", "mx", "my", "mz", "Rt", "h", "bx",
  "bz", "norm_a", "e_a", "norm_m", "norm_b", "g", "dq1", "dq2", "dq3", "dq4",
  "norm_q", "psi", "theta", "phi", "nargin", "nargout", "gyro", "acc", "mag",
  "q", "e_int_a", "e_int_m", "Kp", "Ki", "T", "euler_out", "a_ned", "q_out",
  "e_int_out_a", "e_int_out_m", "biases", "e_m", "ini" };

static const char * c71_b_debug_family_names[18] = { "ib", "ir", "mb", "mr",
  "jb", "jr", "kb", "kr", "c", "q1", "q2", "q3", "q4", "nargin", "nargout",
  "acc", "mag", "q_out" };

/* Function Declarations */
static void initialize_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void initialize_params_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void enable_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void disable_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void c71_update_debugger_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void set_sim_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_st);
static void finalize_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void sf_gateway_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void c71_chartstep_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void initSimStructsc71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c71_machineNumber, uint32_T
  c71_chartNumber, uint32_T c71_instanceNumber);
static const mxArray *c71_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static real_T c71_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_b_ini, const char_T *c71_identifier);
static real_T c71_b_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId);
static void c71_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_b_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static void c71_c_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_e_m, const char_T *c71_identifier, real32_T
  c71_y[3]);
static void c71_d_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[3]);
static void c71_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_c_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static void c71_e_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_q_out, const char_T *c71_identifier,
  real32_T c71_y[4]);
static void c71_f_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[4]);
static void c71_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_d_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static real32_T c71_g_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId);
static void c71_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_e_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static real_T c71_h_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId);
static void c71_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_f_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static void c71_i_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[9]);
static void c71_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static const mxArray *c71_g_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static void c71_info_helper(const mxArray **c71_info);
static const mxArray *c71_emlrt_marshallOut(const char * c71_u);
static const mxArray *c71_b_emlrt_marshallOut(const uint32_T c71_u);
static void c71_b_info_helper(const mxArray **c71_info);
static real32_T c71_norm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x[3]);
static real32_T c71_eml_xnrm2(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x[3]);
static real32_T c71_abs(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x);
static void c71_qtriad(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_acc[3], real32_T c71_mag[3], real32_T c71_q_out[4]);
static real32_T c71_mpower(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_a);
static void c71_eml_scalar_eg(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance);
static real32_T c71_sqrt(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x);
static void c71_eml_error(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance);
static void c71_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance,
                      real32_T c71_a[3], real32_T c71_b[3], real32_T c71_c[3]);
static void c71_b_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real_T c71_a[3], real32_T c71_b[3], real32_T c71_c[3]);
static void c71_eps(SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance);
static void c71_b_eml_scalar_eg(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance);
static void c71_eml_xgemm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_A[9], real32_T c71_B[3], real32_T c71_C[3],
  real32_T c71_b_C[3]);
static void c71_c_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_a[3], real_T c71_b[3], real32_T c71_c[3]);
static real32_T c71_atan2(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_y, real32_T c71_x);
static const mxArray *c71_h_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData);
static int32_T c71_j_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId);
static void c71_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData);
static uint8_T c71_k_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_b_is_active_c71_ICARO_III_debug_tel_tag, const char_T *c71_identifier);
static uint8_T c71_l_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId);
static void c71_b_sqrt(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T *c71_x);
static void c71_b_eml_xgemm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_A[9], real32_T c71_B[3], real32_T c71_C[3]);
static void init_dsm_address_info(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  chartInstance->c71_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c71_ini_not_empty = false;
  chartInstance->c71_is_active_c71_ICARO_III_debug_tel_tag = 0U;
}

static void initialize_params_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  real_T c71_d0;
  real_T c71_d1;
  real_T c71_d2;
  sf_mex_import_named("Kp", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c71_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c71_Kp = (real32_T)c71_d0;
  sf_mex_import_named("Ki", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c71_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c71_Ki = (real32_T)c71_d1;
  sf_mex_import_named("T", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c71_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c71_T = (real32_T)c71_d2;
}

static void enable_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c71_update_debugger_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  const mxArray *c71_st;
  const mxArray *c71_y = NULL;
  int32_T c71_i0;
  real32_T c71_u[3];
  const mxArray *c71_b_y = NULL;
  int32_T c71_i1;
  real32_T c71_b_u[3];
  const mxArray *c71_c_y = NULL;
  int32_T c71_i2;
  real32_T c71_c_u[3];
  const mxArray *c71_d_y = NULL;
  int32_T c71_i3;
  real32_T c71_d_u[3];
  const mxArray *c71_e_y = NULL;
  int32_T c71_i4;
  real32_T c71_e_u[3];
  const mxArray *c71_f_y = NULL;
  int32_T c71_i5;
  real32_T c71_f_u[3];
  const mxArray *c71_g_y = NULL;
  int32_T c71_i6;
  real32_T c71_g_u[4];
  const mxArray *c71_h_y = NULL;
  real_T c71_hoistedGlobal;
  real_T c71_h_u;
  const mxArray *c71_i_y = NULL;
  uint8_T c71_b_hoistedGlobal;
  uint8_T c71_i_u;
  const mxArray *c71_j_y = NULL;
  real32_T (*c71_q_out)[4];
  real32_T (*c71_euler_out)[3];
  real32_T (*c71_e_m)[3];
  real32_T (*c71_e_int_out_m)[3];
  real32_T (*c71_e_int_out_a)[3];
  real32_T (*c71_biases)[3];
  real32_T (*c71_a_ned)[3];
  c71_e_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 7);
  c71_biases = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c71_e_int_out_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c71_e_int_out_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c71_q_out = (real32_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c71_a_ned = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c71_euler_out = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c71_st = NULL;
  c71_st = NULL;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_createcellmatrix(9, 1), false);
  for (c71_i0 = 0; c71_i0 < 3; c71_i0++) {
    c71_u[c71_i0] = (*c71_a_ned)[c71_i0];
  }

  c71_b_y = NULL;
  sf_mex_assign(&c71_b_y, sf_mex_create("y", c71_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c71_y, 0, c71_b_y);
  for (c71_i1 = 0; c71_i1 < 3; c71_i1++) {
    c71_b_u[c71_i1] = (*c71_biases)[c71_i1];
  }

  c71_c_y = NULL;
  sf_mex_assign(&c71_c_y, sf_mex_create("y", c71_b_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c71_y, 1, c71_c_y);
  for (c71_i2 = 0; c71_i2 < 3; c71_i2++) {
    c71_c_u[c71_i2] = (*c71_e_int_out_a)[c71_i2];
  }

  c71_d_y = NULL;
  sf_mex_assign(&c71_d_y, sf_mex_create("y", c71_c_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c71_y, 2, c71_d_y);
  for (c71_i3 = 0; c71_i3 < 3; c71_i3++) {
    c71_d_u[c71_i3] = (*c71_e_int_out_m)[c71_i3];
  }

  c71_e_y = NULL;
  sf_mex_assign(&c71_e_y, sf_mex_create("y", c71_d_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c71_y, 3, c71_e_y);
  for (c71_i4 = 0; c71_i4 < 3; c71_i4++) {
    c71_e_u[c71_i4] = (*c71_e_m)[c71_i4];
  }

  c71_f_y = NULL;
  sf_mex_assign(&c71_f_y, sf_mex_create("y", c71_e_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c71_y, 4, c71_f_y);
  for (c71_i5 = 0; c71_i5 < 3; c71_i5++) {
    c71_f_u[c71_i5] = (*c71_euler_out)[c71_i5];
  }

  c71_g_y = NULL;
  sf_mex_assign(&c71_g_y, sf_mex_create("y", c71_f_u, 1, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c71_y, 5, c71_g_y);
  for (c71_i6 = 0; c71_i6 < 4; c71_i6++) {
    c71_g_u[c71_i6] = (*c71_q_out)[c71_i6];
  }

  c71_h_y = NULL;
  sf_mex_assign(&c71_h_y, sf_mex_create("y", c71_g_u, 1, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c71_y, 6, c71_h_y);
  c71_hoistedGlobal = chartInstance->c71_ini;
  c71_h_u = c71_hoistedGlobal;
  c71_i_y = NULL;
  if (!chartInstance->c71_ini_not_empty) {
    sf_mex_assign(&c71_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c71_i_y, sf_mex_create("y", &c71_h_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c71_y, 7, c71_i_y);
  c71_b_hoistedGlobal = chartInstance->c71_is_active_c71_ICARO_III_debug_tel_tag;
  c71_i_u = c71_b_hoistedGlobal;
  c71_j_y = NULL;
  sf_mex_assign(&c71_j_y, sf_mex_create("y", &c71_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c71_y, 8, c71_j_y);
  sf_mex_assign(&c71_st, c71_y, false);
  return c71_st;
}

static void set_sim_state_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_st)
{
  const mxArray *c71_u;
  real32_T c71_fv0[3];
  int32_T c71_i7;
  real32_T c71_fv1[3];
  int32_T c71_i8;
  real32_T c71_fv2[3];
  int32_T c71_i9;
  real32_T c71_fv3[3];
  int32_T c71_i10;
  real32_T c71_fv4[3];
  int32_T c71_i11;
  real32_T c71_fv5[3];
  int32_T c71_i12;
  real32_T c71_fv6[4];
  int32_T c71_i13;
  real32_T (*c71_a_ned)[3];
  real32_T (*c71_biases)[3];
  real32_T (*c71_e_int_out_a)[3];
  real32_T (*c71_e_int_out_m)[3];
  real32_T (*c71_e_m)[3];
  real32_T (*c71_euler_out)[3];
  real32_T (*c71_q_out)[4];
  c71_e_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 7);
  c71_biases = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c71_e_int_out_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c71_e_int_out_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c71_q_out = (real32_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c71_a_ned = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c71_euler_out = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c71_doneDoubleBufferReInit = true;
  c71_u = sf_mex_dup(c71_st);
  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 0)),
    "a_ned", c71_fv0);
  for (c71_i7 = 0; c71_i7 < 3; c71_i7++) {
    (*c71_a_ned)[c71_i7] = c71_fv0[c71_i7];
  }

  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 1)),
    "biases", c71_fv1);
  for (c71_i8 = 0; c71_i8 < 3; c71_i8++) {
    (*c71_biases)[c71_i8] = c71_fv1[c71_i8];
  }

  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 2)),
    "e_int_out_a", c71_fv2);
  for (c71_i9 = 0; c71_i9 < 3; c71_i9++) {
    (*c71_e_int_out_a)[c71_i9] = c71_fv2[c71_i9];
  }

  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 3)),
    "e_int_out_m", c71_fv3);
  for (c71_i10 = 0; c71_i10 < 3; c71_i10++) {
    (*c71_e_int_out_m)[c71_i10] = c71_fv3[c71_i10];
  }

  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 4)),
    "e_m", c71_fv4);
  for (c71_i11 = 0; c71_i11 < 3; c71_i11++) {
    (*c71_e_m)[c71_i11] = c71_fv4[c71_i11];
  }

  c71_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 5)),
    "euler_out", c71_fv5);
  for (c71_i12 = 0; c71_i12 < 3; c71_i12++) {
    (*c71_euler_out)[c71_i12] = c71_fv5[c71_i12];
  }

  c71_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 6)),
    "q_out", c71_fv6);
  for (c71_i13 = 0; c71_i13 < 4; c71_i13++) {
    (*c71_q_out)[c71_i13] = c71_fv6[c71_i13];
  }

  chartInstance->c71_ini = c71_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c71_u, 7)), "ini");
  chartInstance->c71_is_active_c71_ICARO_III_debug_tel_tag =
    c71_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c71_u, 8)),
    "is_active_c71_ICARO_III_debug_tel_tag");
  sf_mex_destroy(&c71_u);
  c71_update_debugger_state_c71_ICARO_III_debug_tel_tag(chartInstance);
  sf_mex_destroy(&c71_st);
}

static void finalize_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  int32_T c71_i14;
  int32_T c71_i15;
  int32_T c71_i16;
  int32_T c71_i17;
  int32_T c71_i18;
  int32_T c71_i19;
  int32_T c71_i20;
  int32_T c71_i21;
  int32_T c71_i22;
  int32_T c71_i23;
  int32_T c71_i24;
  int32_T c71_i25;
  int32_T c71_i26;
  real32_T (*c71_e_m)[3];
  real32_T (*c71_biases)[3];
  real32_T (*c71_e_int_out_m)[3];
  real32_T (*c71_e_int_out_a)[3];
  real32_T (*c71_q_out)[4];
  real32_T (*c71_e_int_m)[3];
  real32_T (*c71_e_int_a)[3];
  real32_T (*c71_q)[4];
  real32_T (*c71_mag)[3];
  real32_T (*c71_acc)[3];
  real32_T (*c71_gyro)[3];
  real32_T (*c71_a_ned)[3];
  real32_T (*c71_euler_out)[3];
  c71_e_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 7);
  c71_biases = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c71_e_int_out_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c71_e_int_out_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c71_q_out = (real32_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c71_e_int_m = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c71_e_int_a = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c71_q = (real32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c71_mag = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c71_acc = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c71_gyro = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c71_a_ned = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c71_euler_out = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c71_sfEvent);
  chartInstance->c71_sfEvent = CALL_EVENT;
  c71_chartstep_c71_ICARO_III_debug_tel_tag(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ICARO_III_debug_tel_tagMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c71_i14 = 0; c71_i14 < 3; c71_i14++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_euler_out)[c71_i14], 0U);
  }

  for (c71_i15 = 0; c71_i15 < 3; c71_i15++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_a_ned)[c71_i15], 1U);
  }

  for (c71_i16 = 0; c71_i16 < 3; c71_i16++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_gyro)[c71_i16], 2U);
  }

  for (c71_i17 = 0; c71_i17 < 3; c71_i17++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_acc)[c71_i17], 3U);
  }

  for (c71_i18 = 0; c71_i18 < 3; c71_i18++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_mag)[c71_i18], 4U);
  }

  for (c71_i19 = 0; c71_i19 < 4; c71_i19++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_q)[c71_i19], 5U);
  }

  for (c71_i20 = 0; c71_i20 < 3; c71_i20++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_e_int_a)[c71_i20], 6U);
  }

  for (c71_i21 = 0; c71_i21 < 3; c71_i21++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_e_int_m)[c71_i21], 7U);
  }

  for (c71_i22 = 0; c71_i22 < 4; c71_i22++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_q_out)[c71_i22], 8U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c71_Kp, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c71_Ki, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c71_T, 11U);
  for (c71_i23 = 0; c71_i23 < 3; c71_i23++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_e_int_out_a)[c71_i23], 12U);
  }

  for (c71_i24 = 0; c71_i24 < 3; c71_i24++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_e_int_out_m)[c71_i24], 13U);
  }

  for (c71_i25 = 0; c71_i25 < 3; c71_i25++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_biases)[c71_i25], 14U);
  }

  for (c71_i26 = 0; c71_i26 < 3; c71_i26++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c71_e_m)[c71_i26], 15U);
  }
}

static void c71_chartstep_c71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  real32_T c71_hoistedGlobal;
  real32_T c71_b_hoistedGlobal;
  real32_T c71_c_hoistedGlobal;
  int32_T c71_i27;
  real32_T c71_gyro[3];
  int32_T c71_i28;
  real32_T c71_acc[3];
  int32_T c71_i29;
  real32_T c71_mag[3];
  int32_T c71_i30;
  real32_T c71_q[4];
  int32_T c71_i31;
  real32_T c71_e_int_a[3];
  int32_T c71_i32;
  real32_T c71_e_int_m[3];
  real32_T c71_b_Kp;
  real32_T c71_b_Ki;
  real32_T c71_b_T;
  uint32_T c71_debug_family_var_map[50];
  real_T c71_mode;
  real32_T c71_q1;
  real32_T c71_q2;
  real32_T c71_q3;
  real32_T c71_q4;
  real32_T c71_gx;
  real32_T c71_gy;
  real32_T c71_gz;
  real32_T c71_ax;
  real32_T c71_ay;
  real32_T c71_az;
  real32_T c71_mx;
  real32_T c71_my;
  real32_T c71_mz;
  real32_T c71_Rt[9];
  real32_T c71_h[3];
  real32_T c71_bx;
  real32_T c71_bz;
  real32_T c71_norm_a;
  real32_T c71_e_a[3];
  real32_T c71_norm_m;
  real32_T c71_norm_b;
  real32_T c71_g[3];
  real32_T c71_dq1;
  real32_T c71_dq2;
  real32_T c71_dq3;
  real32_T c71_dq4;
  real32_T c71_norm_q;
  real32_T c71_psi;
  real32_T c71_theta;
  real32_T c71_phi;
  real_T c71_nargin = 9.0;
  real_T c71_nargout = 7.0;
  real32_T c71_euler_out[3];
  real32_T c71_a_ned[3];
  real32_T c71_q_out[4];
  real32_T c71_e_int_out_a[3];
  real32_T c71_e_int_out_m[3];
  real32_T c71_biases[3];
  real32_T c71_e_m[3];
  int32_T c71_i33;
  real32_T c71_b_acc[3];
  int32_T c71_i34;
  static real32_T c71_fv7[3] = { 0.0F, 0.0F, -9.81F };

  int32_T c71_i35;
  real32_T c71_b_mag[3];
  int32_T c71_i36;
  static real32_T c71_fv8[3] = { 0.0F, 0.5F, 0.0F };

  int32_T c71_i37;
  real32_T c71_c_acc[3];
  int32_T c71_i38;
  real32_T c71_c_mag[3];
  real32_T c71_fv9[4];
  int32_T c71_i39;
  real32_T c71_b;
  real32_T c71_y;
  real32_T c71_b_b;
  real32_T c71_b_y;
  real32_T c71_c_b;
  real32_T c71_c_y;
  real32_T c71_d_b;
  real32_T c71_d_y;
  real32_T c71_e_b;
  real32_T c71_e_y;
  real32_T c71_f_b;
  real32_T c71_f_y;
  real32_T c71_g_b;
  real32_T c71_g_y;
  real32_T c71_h_b;
  real32_T c71_h_y;
  real32_T c71_i_b;
  real32_T c71_i_y;
  real32_T c71_j_b;
  real32_T c71_j_y;
  real32_T c71_k_b;
  real32_T c71_k_y;
  real32_T c71_l_b;
  real32_T c71_l_y;
  real32_T c71_b_ax[3];
  int32_T c71_i40;
  real32_T c71_A[3];
  real32_T c71_B;
  real32_T c71_m_y;
  real32_T c71_n_y;
  real32_T c71_o_y;
  int32_T c71_i41;
  int32_T c71_i42;
  int32_T c71_i43;
  int32_T c71_i44;
  int32_T c71_i45;
  real32_T c71_a[9];
  int32_T c71_i46;
  real32_T c71_p_y[3];
  int32_T c71_i47;
  int32_T c71_i48;
  static real32_T c71_fv10[3] = { 0.0F, 0.0F, -1.0F };

  int32_T c71_i49;
  real32_T c71_b_A[3];
  int32_T c71_i50;
  real32_T c71_q_y[3];
  real32_T c71_fv11[3];
  int32_T c71_i51;
  int32_T c71_i52;
  int32_T c71_i53;
  int32_T c71_i54;
  int32_T c71_i55;
  real32_T c71_b_mx[3];
  int32_T c71_i56;
  real32_T c71_m_b[3];
  int32_T c71_i57;
  int32_T c71_i58;
  real32_T c71_b_a[9];
  int32_T c71_i59;
  real32_T c71_n_b[3];
  real32_T c71_b_B;
  real32_T c71_r_y;
  real32_T c71_s_y;
  real32_T c71_t_y;
  int32_T c71_i60;
  int32_T c71_i61;
  real32_T c71_u_y[3];
  int32_T c71_i62;
  static real_T c71_dv0[3] = { 1.0, 0.0, 0.0 };

  real_T c71_dv1[3];
  int32_T c71_i63;
  real32_T c71_c_a;
  int32_T c71_i64;
  int32_T c71_i65;
  int32_T c71_i66;
  real32_T c71_d_a;
  int32_T c71_i67;
  int32_T c71_i68;
  real32_T c71_f_a;
  int32_T c71_i69;
  int32_T c71_i70;
  real32_T c71_g_a;
  int32_T c71_i71;
  int32_T c71_i72;
  real32_T c71_b_gx[3];
  int32_T c71_i73;
  real32_T c71_c_A;
  real32_T c71_x;
  real32_T c71_b_x;
  real32_T c71_c_x;
  real32_T c71_d_A;
  real32_T c71_d_x;
  real32_T c71_e_x;
  real32_T c71_f_x;
  real32_T c71_e_A;
  real32_T c71_g_x;
  real32_T c71_h_x;
  real32_T c71_i_x;
  real32_T c71_f_A;
  real32_T c71_j_x;
  real32_T c71_k_x;
  real32_T c71_l_x;
  real32_T c71_g_A;
  real32_T c71_c_B;
  real32_T c71_m_x;
  real32_T c71_v_y;
  real32_T c71_n_x;
  real32_T c71_w_y;
  real32_T c71_o_x;
  real32_T c71_x_y;
  real32_T c71_h_A;
  real32_T c71_d_B;
  real32_T c71_p_x;
  real32_T c71_y_y;
  real32_T c71_q_x;
  real32_T c71_ab_y;
  real32_T c71_r_x;
  real32_T c71_bb_y;
  real32_T c71_i_A;
  real32_T c71_e_B;
  real32_T c71_s_x;
  real32_T c71_cb_y;
  real32_T c71_t_x;
  real32_T c71_db_y;
  real32_T c71_u_x;
  real32_T c71_eb_y;
  real32_T c71_j_A;
  real32_T c71_f_B;
  real32_T c71_v_x;
  real32_T c71_fb_y;
  real32_T c71_w_x;
  real32_T c71_gb_y;
  real32_T c71_x_x;
  real32_T c71_hb_y;
  real32_T c71_o_b;
  real32_T c71_ib_y;
  real32_T c71_p_b;
  real32_T c71_jb_y;
  real32_T c71_q_b;
  real32_T c71_kb_y;
  real32_T c71_r_b;
  real32_T c71_lb_y;
  real32_T c71_s_b;
  real32_T c71_mb_y;
  real32_T c71_t_b;
  real32_T c71_nb_y;
  real32_T c71_u_b;
  real32_T c71_ob_y;
  real32_T c71_v_b;
  real32_T c71_pb_y;
  real32_T c71_w_b;
  real32_T c71_qb_y;
  real32_T c71_x_b;
  real32_T c71_rb_y;
  real32_T c71_y_b;
  real32_T c71_sb_y;
  real32_T c71_ab_b;
  real32_T c71_tb_y;
  real32_T c71_bb_b;
  real32_T c71_ub_y;
  real32_T c71_cb_b;
  real32_T c71_vb_y;
  real32_T c71_db_b;
  real32_T c71_wb_y;
  real32_T c71_eb_b;
  real32_T c71_xb_y;
  real32_T c71_fb_b;
  real32_T c71_yb_y;
  real32_T c71_gb_b;
  real32_T c71_ac_y;
  real32_T c71_hb_b;
  real32_T c71_bc_y;
  real32_T c71_f0;
  real32_T c71_ib_b;
  real32_T c71_cc_y;
  real32_T c71_jb_b;
  real32_T c71_dc_y;
  real32_T c71_kb_b;
  real32_T c71_ec_y;
  int32_T c71_i74;
  int32_T c71_i75;
  int32_T c71_i76;
  int32_T c71_i77;
  int32_T c71_i78;
  real32_T c71_fv12[9];
  int32_T c71_i79;
  real32_T c71_fv13[3];
  int32_T c71_i80;
  real32_T c71_fv14[9];
  int32_T c71_i81;
  real32_T c71_fv15[3];
  real32_T c71_h_a;
  int32_T c71_i82;
  int32_T c71_i83;
  int32_T c71_i84;
  int32_T c71_i85;
  int32_T c71_i86;
  int32_T c71_i87;
  int32_T c71_i88;
  int32_T c71_i89;
  int32_T c71_i90;
  real32_T (*c71_b_euler_out)[3];
  real32_T (*c71_b_a_ned)[3];
  real32_T (*c71_b_q_out)[4];
  real32_T (*c71_b_e_int_out_a)[3];
  real32_T (*c71_b_e_int_out_m)[3];
  real32_T (*c71_b_biases)[3];
  real32_T (*c71_b_e_m)[3];
  real32_T (*c71_b_e_int_m)[3];
  real32_T (*c71_b_e_int_a)[3];
  real32_T (*c71_b_q)[4];
  real32_T (*c71_d_mag)[3];
  real32_T (*c71_d_acc)[3];
  real32_T (*c71_b_gyro)[3];
  c71_b_e_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 7);
  c71_b_biases = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c71_b_e_int_out_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c71_b_e_int_out_a = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c71_b_q_out = (real32_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c71_b_e_int_m = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c71_b_e_int_a = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c71_b_q = (real32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c71_d_mag = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c71_d_acc = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c71_b_gyro = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c71_b_a_ned = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c71_b_euler_out = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c71_sfEvent);
  c71_hoistedGlobal = chartInstance->c71_Kp;
  c71_b_hoistedGlobal = chartInstance->c71_Ki;
  c71_c_hoistedGlobal = chartInstance->c71_T;
  for (c71_i27 = 0; c71_i27 < 3; c71_i27++) {
    c71_gyro[c71_i27] = (*c71_b_gyro)[c71_i27];
  }

  for (c71_i28 = 0; c71_i28 < 3; c71_i28++) {
    c71_acc[c71_i28] = (*c71_d_acc)[c71_i28];
  }

  for (c71_i29 = 0; c71_i29 < 3; c71_i29++) {
    c71_mag[c71_i29] = (*c71_d_mag)[c71_i29];
  }

  for (c71_i30 = 0; c71_i30 < 4; c71_i30++) {
    c71_q[c71_i30] = (*c71_b_q)[c71_i30];
  }

  for (c71_i31 = 0; c71_i31 < 3; c71_i31++) {
    c71_e_int_a[c71_i31] = (*c71_b_e_int_a)[c71_i31];
  }

  for (c71_i32 = 0; c71_i32 < 3; c71_i32++) {
    c71_e_int_m[c71_i32] = (*c71_b_e_int_m)[c71_i32];
  }

  c71_b_Kp = c71_hoistedGlobal;
  c71_b_Ki = c71_b_hoistedGlobal;
  c71_b_T = c71_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 50U, 50U, c71_debug_family_names,
    c71_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c71_mode, 0U, c71_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q1, 1U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q2, 2U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q3, 3U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q4, 4U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_gx, 5U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_gy, 6U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_gz, 7U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_ax, 8U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_ay, 9U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_az, 10U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_mx, 11U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_my, 12U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_mz, 13U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_Rt, 14U, c71_f_sf_marshallOut,
    c71_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_h, 15U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_bx, 16U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_bz, 17U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_norm_a, 18U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_e_a, 19U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_norm_m, 20U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_norm_b, 21U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_g, 22U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_dq1, 23U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_dq2, 24U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_dq3, 25U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_dq4, 26U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_norm_q, 27U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_psi, 28U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_theta, 29U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_phi, 30U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_nargin, 31U, c71_e_sf_marshallOut,
    c71_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_nargout, 32U, c71_e_sf_marshallOut,
    c71_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_gyro, 33U, c71_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_acc, 34U, c71_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_mag, 35U, c71_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_q, 36U, c71_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_e_int_a, 37U, c71_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_e_int_m, 38U, c71_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_b_Kp, 39U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_b_Ki, 40U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_b_T, 41U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_euler_out, 42U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_a_ned, 43U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_q_out, 44U, c71_c_sf_marshallOut,
    c71_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_e_int_out_a, 45U,
    c71_b_sf_marshallOut, c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_e_int_out_m, 46U,
    c71_b_sf_marshallOut, c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_biases, 47U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_e_m, 48U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c71_ini, 49U,
    c71_sf_marshallOut, c71_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 9);
  c71_mode = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 15);
  for (c71_i33 = 0; c71_i33 < 3; c71_i33++) {
    c71_b_acc[c71_i33] = c71_acc[c71_i33];
  }

  if (CV_EML_IF(0, 1, 0, (real_T)c71_norm(chartInstance, c71_b_acc) < 0.0001)) {
    _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 16);
    for (c71_i34 = 0; c71_i34 < 3; c71_i34++) {
      c71_acc[c71_i34] = c71_fv7[c71_i34];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 19);
  for (c71_i35 = 0; c71_i35 < 3; c71_i35++) {
    c71_b_mag[c71_i35] = c71_mag[c71_i35];
  }

  if (CV_EML_IF(0, 1, 1, (real_T)c71_norm(chartInstance, c71_b_mag) < 0.0001)) {
    _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 21);
    for (c71_i36 = 0; c71_i36 < 3; c71_i36++) {
      c71_mag[c71_i36] = c71_fv8[c71_i36];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 28);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c71_ini_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 29);
    for (c71_i37 = 0; c71_i37 < 3; c71_i37++) {
      c71_c_acc[c71_i37] = c71_acc[c71_i37];
    }

    for (c71_i38 = 0; c71_i38 < 3; c71_i38++) {
      c71_c_mag[c71_i38] = c71_mag[c71_i38];
    }

    c71_qtriad(chartInstance, c71_c_acc, c71_c_mag, c71_fv9);
    for (c71_i39 = 0; c71_i39 < 4; c71_i39++) {
      c71_q[c71_i39] = c71_fv9[c71_i39];
    }

    _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 30);
    chartInstance->c71_ini = 1.0;
    chartInstance->c71_ini_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 33);
  c71_q1 = c71_q[0];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 34);
  c71_q2 = c71_q[1];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 35);
  c71_q3 = c71_q[2];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 36);
  c71_q4 = c71_q[3];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 39);
  c71_gx = c71_gyro[0];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 40);
  c71_gy = c71_gyro[1];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 41);
  c71_gz = c71_gyro[2];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 43);
  c71_ax = c71_acc[0];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 44);
  c71_ay = c71_acc[1];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 45);
  c71_az = c71_acc[2];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 47);
  c71_mx = c71_mag[0];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 48);
  c71_my = c71_mag[1];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 49);
  c71_mz = c71_mag[2];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 54);
  c71_b = c71_mpower(chartInstance, c71_q3);
  c71_y = 2.0F * c71_b;
  c71_b_b = c71_mpower(chartInstance, c71_q4);
  c71_b_y = 2.0F * c71_b_b;
  c71_c_b = c71_q2 * c71_q3 - c71_q1 * c71_q4;
  c71_c_y = 2.0F * c71_c_b;
  c71_d_b = c71_q2 * c71_q4 + c71_q1 * c71_q3;
  c71_d_y = 2.0F * c71_d_b;
  c71_e_b = c71_q2 * c71_q3 + c71_q1 * c71_q4;
  c71_e_y = 2.0F * c71_e_b;
  c71_f_b = c71_mpower(chartInstance, c71_q2);
  c71_f_y = 2.0F * c71_f_b;
  c71_g_b = c71_mpower(chartInstance, c71_q4);
  c71_g_y = 2.0F * c71_g_b;
  c71_h_b = c71_q3 * c71_q4 - c71_q1 * c71_q2;
  c71_h_y = 2.0F * c71_h_b;
  c71_i_b = c71_q2 * c71_q4 - c71_q1 * c71_q3;
  c71_i_y = 2.0F * c71_i_b;
  c71_j_b = c71_q3 * c71_q4 + c71_q1 * c71_q2;
  c71_j_y = 2.0F * c71_j_b;
  c71_k_b = c71_mpower(chartInstance, c71_q2);
  c71_k_y = 2.0F * c71_k_b;
  c71_l_b = c71_mpower(chartInstance, c71_q3);
  c71_l_y = 2.0F * c71_l_b;
  c71_Rt[0] = (1.0F - c71_y) - c71_b_y;
  c71_Rt[3] = c71_c_y;
  c71_Rt[6] = c71_d_y;
  c71_Rt[1] = c71_e_y;
  c71_Rt[4] = (1.0F - c71_f_y) - c71_g_y;
  c71_Rt[7] = c71_h_y;
  c71_Rt[2] = c71_i_y;
  c71_Rt[5] = c71_j_y;
  c71_Rt[8] = (1.0F - c71_k_y) - c71_l_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 61);
  c71_h[0] = c71_mx;
  c71_h[1] = c71_my;
  c71_h[2] = c71_mz;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 63);
  c71_bx = c71_mpower(chartInstance, c71_h[0]) + c71_mpower(chartInstance,
    c71_h[1]);
  c71_b_sqrt(chartInstance, &c71_bx);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 64);
  c71_bz = c71_abs(chartInstance, c71_h[2]);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 66);
  c71_eps(chartInstance);
  c71_norm_a = ((c71_mpower(chartInstance, c71_ax) + c71_mpower(chartInstance,
    c71_ay)) + c71_mpower(chartInstance, c71_az)) + 2.22044605E-16F;
  c71_b_sqrt(chartInstance, &c71_norm_a);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 67);
  c71_b_ax[0] = c71_ax;
  c71_b_ax[1] = c71_ay;
  c71_b_ax[2] = c71_az;
  for (c71_i40 = 0; c71_i40 < 3; c71_i40++) {
    c71_A[c71_i40] = c71_b_ax[c71_i40];
  }

  c71_B = c71_norm_a;
  c71_m_y = c71_B;
  c71_n_y = c71_m_y;
  c71_o_y = c71_n_y;
  for (c71_i41 = 0; c71_i41 < 3; c71_i41++) {
    c71_A[c71_i41] /= c71_o_y;
  }

  c71_i42 = 0;
  for (c71_i43 = 0; c71_i43 < 3; c71_i43++) {
    c71_i44 = 0;
    for (c71_i45 = 0; c71_i45 < 3; c71_i45++) {
      c71_a[c71_i45 + c71_i42] = c71_Rt[c71_i44 + c71_i43];
      c71_i44 += 3;
    }

    c71_i42 += 3;
  }

  for (c71_i46 = 0; c71_i46 < 3; c71_i46++) {
    c71_p_y[c71_i46] = 0.0F;
    c71_i47 = 0;
    for (c71_i48 = 0; c71_i48 < 3; c71_i48++) {
      c71_p_y[c71_i46] += c71_a[c71_i47 + c71_i46] * c71_fv10[c71_i48];
      c71_i47 += 3;
    }
  }

  for (c71_i49 = 0; c71_i49 < 3; c71_i49++) {
    c71_b_A[c71_i49] = c71_A[c71_i49];
  }

  for (c71_i50 = 0; c71_i50 < 3; c71_i50++) {
    c71_q_y[c71_i50] = c71_p_y[c71_i50];
  }

  c71_cross(chartInstance, c71_b_A, c71_q_y, c71_fv11);
  for (c71_i51 = 0; c71_i51 < 3; c71_i51++) {
    c71_e_a[c71_i51] = c71_fv11[c71_i51];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 69);
  c71_eps(chartInstance);
  c71_norm_m = (c71_mpower(chartInstance, c71_mx) + c71_mpower(chartInstance,
    c71_my)) + 2.22044605E-16F;
  c71_b_sqrt(chartInstance, &c71_norm_m);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 70);
  c71_eps(chartInstance);
  c71_norm_b = (c71_mpower(chartInstance, c71_bx) + c71_mpower(chartInstance,
    c71_bz)) + 2.22044605E-16F;
  c71_b_sqrt(chartInstance, &c71_norm_b);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 72);
  c71_i52 = 0;
  for (c71_i53 = 0; c71_i53 < 3; c71_i53++) {
    c71_i54 = 0;
    for (c71_i55 = 0; c71_i55 < 3; c71_i55++) {
      c71_a[c71_i55 + c71_i52] = c71_Rt[c71_i54 + c71_i53];
      c71_i54 += 3;
    }

    c71_i52 += 3;
  }

  c71_b_mx[0] = c71_mx;
  c71_b_mx[1] = c71_my;
  c71_b_mx[2] = 0.0F;
  for (c71_i56 = 0; c71_i56 < 3; c71_i56++) {
    c71_m_b[c71_i56] = c71_b_mx[c71_i56];
  }

  c71_b_eml_scalar_eg(chartInstance);
  c71_b_eml_scalar_eg(chartInstance);
  for (c71_i57 = 0; c71_i57 < 3; c71_i57++) {
    c71_p_y[c71_i57] = 0.0F;
  }

  for (c71_i58 = 0; c71_i58 < 9; c71_i58++) {
    c71_b_a[c71_i58] = c71_a[c71_i58];
  }

  for (c71_i59 = 0; c71_i59 < 3; c71_i59++) {
    c71_n_b[c71_i59] = c71_m_b[c71_i59];
  }

  c71_b_eml_xgemm(chartInstance, c71_b_a, c71_n_b, c71_p_y);
  c71_b_B = c71_norm_m;
  c71_r_y = c71_b_B;
  c71_s_y = c71_r_y;
  c71_t_y = c71_s_y;
  for (c71_i60 = 0; c71_i60 < 3; c71_i60++) {
    c71_p_y[c71_i60] /= c71_t_y;
  }

  for (c71_i61 = 0; c71_i61 < 3; c71_i61++) {
    c71_u_y[c71_i61] = c71_p_y[c71_i61];
  }

  for (c71_i62 = 0; c71_i62 < 3; c71_i62++) {
    c71_dv1[c71_i62] = c71_dv0[c71_i62];
  }

  c71_c_cross(chartInstance, c71_u_y, c71_dv1, c71_m_b);
  for (c71_i63 = 0; c71_i63 < 3; c71_i63++) {
    c71_e_m[c71_i63] = -c71_m_b[c71_i63];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 75);
  CV_EML_IF(0, 1, 3, c71_mode == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 77);
  c71_c_a = c71_b_T;
  for (c71_i64 = 0; c71_i64 < 2; c71_i64++) {
    c71_m_b[c71_i64] = c71_e_a[c71_i64];
  }

  c71_m_b[2] = 0.0F;
  for (c71_i65 = 0; c71_i65 < 3; c71_i65++) {
    c71_m_b[c71_i65] *= c71_c_a;
  }

  for (c71_i66 = 0; c71_i66 < 3; c71_i66++) {
    c71_e_int_out_a[c71_i66] = c71_e_int_a[c71_i66] + c71_m_b[c71_i66];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 78);
  c71_d_a = c71_b_T;
  c71_m_b[0] = 0.0F;
  c71_m_b[1] = 0.0F;
  c71_m_b[2] = c71_e_m[2];
  for (c71_i67 = 0; c71_i67 < 3; c71_i67++) {
    c71_m_b[c71_i67] *= c71_d_a;
  }

  for (c71_i68 = 0; c71_i68 < 3; c71_i68++) {
    c71_e_int_out_m[c71_i68] = c71_e_int_m[c71_i68] + c71_m_b[c71_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 84);
  c71_f_a = c71_b_Kp;
  for (c71_i69 = 0; c71_i69 < 2; c71_i69++) {
    c71_m_b[c71_i69] = c71_e_a[c71_i69];
  }

  c71_m_b[2] = c71_e_m[2];
  for (c71_i70 = 0; c71_i70 < 3; c71_i70++) {
    c71_m_b[c71_i70] *= c71_f_a;
  }

  c71_g_a = c71_b_Ki;
  for (c71_i71 = 0; c71_i71 < 3; c71_i71++) {
    c71_A[c71_i71] = c71_e_int_out_a[c71_i71] + c71_e_int_out_m[c71_i71];
  }

  for (c71_i72 = 0; c71_i72 < 3; c71_i72++) {
    c71_A[c71_i72] *= c71_g_a;
  }

  c71_b_gx[0] = c71_gx;
  c71_b_gx[1] = c71_gy;
  c71_b_gx[2] = c71_gz;
  for (c71_i73 = 0; c71_i73 < 3; c71_i73++) {
    c71_g[c71_i73] = (c71_b_gx[c71_i73] + c71_m_b[c71_i73]) + c71_A[c71_i73];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 95);
  c71_gx = c71_g[0];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 96);
  c71_gy = c71_g[1];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 97);
  c71_gz = c71_g[2];
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 101);
  c71_c_A = (-c71_q2 * c71_gx - c71_q3 * c71_gy) - c71_q4 * c71_gz;
  c71_x = c71_c_A;
  c71_b_x = c71_x;
  c71_c_x = c71_b_x;
  c71_dq1 = c71_c_x / 2.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 102);
  c71_d_A = (c71_q1 * c71_gx + c71_q3 * c71_gz) - c71_q4 * c71_gy;
  c71_d_x = c71_d_A;
  c71_e_x = c71_d_x;
  c71_f_x = c71_e_x;
  c71_dq2 = c71_f_x / 2.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 103);
  c71_e_A = (c71_q1 * c71_gy - c71_q2 * c71_gz) + c71_q4 * c71_gx;
  c71_g_x = c71_e_A;
  c71_h_x = c71_g_x;
  c71_i_x = c71_h_x;
  c71_dq3 = c71_i_x / 2.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 104);
  c71_f_A = (c71_q1 * c71_gz + c71_q2 * c71_gy) - c71_q3 * c71_gx;
  c71_j_x = c71_f_A;
  c71_k_x = c71_j_x;
  c71_l_x = c71_k_x;
  c71_dq4 = c71_l_x / 2.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 106);
  c71_q1 += c71_dq1 * c71_b_T;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 107);
  c71_q2 += c71_dq2 * c71_b_T;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 108);
  c71_q3 += c71_dq3 * c71_b_T;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 109);
  c71_q4 += c71_dq4 * c71_b_T;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 113);
  c71_norm_q = ((c71_q1 * c71_q1 + c71_q2 * c71_q2) + c71_q3 * c71_q3) + c71_q4 *
    c71_q4;
  c71_b_sqrt(chartInstance, &c71_norm_q);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 114);
  c71_g_A = c71_q1;
  c71_c_B = c71_norm_q;
  c71_m_x = c71_g_A;
  c71_v_y = c71_c_B;
  c71_n_x = c71_m_x;
  c71_w_y = c71_v_y;
  c71_o_x = c71_n_x;
  c71_x_y = c71_w_y;
  c71_q1 = c71_o_x / c71_x_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 115);
  c71_h_A = c71_q2;
  c71_d_B = c71_norm_q;
  c71_p_x = c71_h_A;
  c71_y_y = c71_d_B;
  c71_q_x = c71_p_x;
  c71_ab_y = c71_y_y;
  c71_r_x = c71_q_x;
  c71_bb_y = c71_ab_y;
  c71_q2 = c71_r_x / c71_bb_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 116);
  c71_i_A = c71_q3;
  c71_e_B = c71_norm_q;
  c71_s_x = c71_i_A;
  c71_cb_y = c71_e_B;
  c71_t_x = c71_s_x;
  c71_db_y = c71_cb_y;
  c71_u_x = c71_t_x;
  c71_eb_y = c71_db_y;
  c71_q3 = c71_u_x / c71_eb_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 117);
  c71_j_A = c71_q4;
  c71_f_B = c71_norm_q;
  c71_v_x = c71_j_A;
  c71_fb_y = c71_f_B;
  c71_w_x = c71_v_x;
  c71_gb_y = c71_fb_y;
  c71_x_x = c71_w_x;
  c71_hb_y = c71_gb_y;
  c71_q4 = c71_x_x / c71_hb_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 119);
  c71_q_out[0] = c71_q1;
  c71_q_out[1] = c71_q2;
  c71_q_out[2] = c71_q3;
  c71_q_out[3] = c71_q4;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 124);
  c71_o_b = c71_mpower(chartInstance, c71_q3);
  c71_ib_y = 2.0F * c71_o_b;
  c71_p_b = c71_mpower(chartInstance, c71_q4);
  c71_jb_y = 2.0F * c71_p_b;
  c71_q_b = c71_q2 * c71_q3 - c71_q1 * c71_q4;
  c71_kb_y = 2.0F * c71_q_b;
  c71_r_b = c71_q2 * c71_q4 + c71_q1 * c71_q3;
  c71_lb_y = 2.0F * c71_r_b;
  c71_s_b = c71_q2 * c71_q3 + c71_q1 * c71_q4;
  c71_mb_y = 2.0F * c71_s_b;
  c71_t_b = c71_mpower(chartInstance, c71_q2);
  c71_nb_y = 2.0F * c71_t_b;
  c71_u_b = c71_mpower(chartInstance, c71_q4);
  c71_ob_y = 2.0F * c71_u_b;
  c71_v_b = c71_q3 * c71_q4 - c71_q1 * c71_q2;
  c71_pb_y = 2.0F * c71_v_b;
  c71_w_b = c71_q2 * c71_q4 - c71_q1 * c71_q3;
  c71_qb_y = 2.0F * c71_w_b;
  c71_x_b = c71_q3 * c71_q4 + c71_q1 * c71_q2;
  c71_rb_y = 2.0F * c71_x_b;
  c71_y_b = c71_mpower(chartInstance, c71_q2);
  c71_sb_y = 2.0F * c71_y_b;
  c71_ab_b = c71_mpower(chartInstance, c71_q3);
  c71_tb_y = 2.0F * c71_ab_b;
  c71_Rt[0] = (1.0F - c71_ib_y) - c71_jb_y;
  c71_Rt[3] = c71_kb_y;
  c71_Rt[6] = c71_lb_y;
  c71_Rt[1] = c71_mb_y;
  c71_Rt[4] = (1.0F - c71_nb_y) - c71_ob_y;
  c71_Rt[7] = c71_pb_y;
  c71_Rt[2] = c71_qb_y;
  c71_Rt[5] = c71_rb_y;
  c71_Rt[8] = (1.0F - c71_sb_y) - c71_tb_y;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 130U);
  c71_bb_b = c71_q2 * c71_q3 + c71_q1 * c71_q4;
  c71_ub_y = 2.0F * c71_bb_b;
  c71_cb_b = c71_mpower(chartInstance, c71_q3);
  c71_vb_y = 2.0F * c71_cb_b;
  c71_db_b = c71_mpower(chartInstance, c71_q4);
  c71_wb_y = 2.0F * c71_db_b;
  c71_psi = c71_atan2(chartInstance, c71_ub_y, (1.0F - c71_vb_y) - c71_wb_y);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 131U);
  c71_eb_b = c71_q2 * c71_q4 - c71_q1 * c71_q3;
  c71_xb_y = -2.0F * c71_eb_b;
  c71_fb_b = c71_q3 * c71_q4 + c71_q1 * c71_q2;
  c71_yb_y = 2.0F * c71_fb_b;
  c71_gb_b = c71_mpower(chartInstance, c71_q2);
  c71_ac_y = 2.0F * c71_gb_b;
  c71_hb_b = c71_mpower(chartInstance, c71_q3);
  c71_bc_y = 2.0F * c71_hb_b;
  c71_f0 = c71_mpower(chartInstance, c71_yb_y) + c71_mpower(chartInstance, (1.0F
    - c71_ac_y) - c71_bc_y);
  c71_b_sqrt(chartInstance, &c71_f0);
  c71_theta = c71_atan2(chartInstance, c71_xb_y, c71_f0);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 132U);
  c71_ib_b = c71_q3 * c71_q4 + c71_q1 * c71_q2;
  c71_cc_y = 2.0F * c71_ib_b;
  c71_jb_b = c71_mpower(chartInstance, c71_q2);
  c71_dc_y = 2.0F * c71_jb_b;
  c71_kb_b = c71_mpower(chartInstance, c71_q3);
  c71_ec_y = 2.0F * c71_kb_b;
  c71_phi = c71_atan2(chartInstance, c71_cc_y, (1.0F - c71_dc_y) - c71_ec_y);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 136U);
  for (c71_i74 = 0; c71_i74 < 9; c71_i74++) {
    c71_a[c71_i74] = c71_Rt[c71_i74];
  }

  for (c71_i75 = 0; c71_i75 < 3; c71_i75++) {
    c71_m_b[c71_i75] = c71_acc[c71_i75];
  }

  c71_b_eml_scalar_eg(chartInstance);
  c71_b_eml_scalar_eg(chartInstance);
  for (c71_i76 = 0; c71_i76 < 3; c71_i76++) {
    c71_a_ned[c71_i76] = 0.0F;
  }

  for (c71_i77 = 0; c71_i77 < 3; c71_i77++) {
    c71_a_ned[c71_i77] = 0.0F;
  }

  for (c71_i78 = 0; c71_i78 < 9; c71_i78++) {
    c71_fv12[c71_i78] = c71_a[c71_i78];
  }

  for (c71_i79 = 0; c71_i79 < 3; c71_i79++) {
    c71_fv13[c71_i79] = c71_m_b[c71_i79];
  }

  for (c71_i80 = 0; c71_i80 < 9; c71_i80++) {
    c71_fv14[c71_i80] = c71_fv12[c71_i80];
  }

  for (c71_i81 = 0; c71_i81 < 3; c71_i81++) {
    c71_fv15[c71_i81] = c71_fv13[c71_i81];
  }

  c71_b_eml_xgemm(chartInstance, c71_fv14, c71_fv15, c71_a_ned);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 138U);
  c71_euler_out[0] = c71_phi;
  c71_euler_out[1] = c71_theta;
  c71_euler_out[2] = c71_psi;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 142U);
  c71_h_a = -c71_b_Ki;
  for (c71_i82 = 0; c71_i82 < 3; c71_i82++) {
    c71_m_b[c71_i82] = c71_e_int_out_a[c71_i82] + c71_e_int_out_m[c71_i82];
  }

  for (c71_i83 = 0; c71_i83 < 3; c71_i83++) {
    c71_biases[c71_i83] = c71_h_a * c71_m_b[c71_i83];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, -142);
  _SFD_SYMBOL_SCOPE_POP();
  for (c71_i84 = 0; c71_i84 < 3; c71_i84++) {
    (*c71_b_euler_out)[c71_i84] = c71_euler_out[c71_i84];
  }

  for (c71_i85 = 0; c71_i85 < 3; c71_i85++) {
    (*c71_b_a_ned)[c71_i85] = c71_a_ned[c71_i85];
  }

  for (c71_i86 = 0; c71_i86 < 4; c71_i86++) {
    (*c71_b_q_out)[c71_i86] = c71_q_out[c71_i86];
  }

  for (c71_i87 = 0; c71_i87 < 3; c71_i87++) {
    (*c71_b_e_int_out_a)[c71_i87] = c71_e_int_out_a[c71_i87];
  }

  for (c71_i88 = 0; c71_i88 < 3; c71_i88++) {
    (*c71_b_e_int_out_m)[c71_i88] = c71_e_int_out_m[c71_i88];
  }

  for (c71_i89 = 0; c71_i89 < 3; c71_i89++) {
    (*c71_b_biases)[c71_i89] = c71_biases[c71_i89];
  }

  for (c71_i90 = 0; c71_i90 < 3; c71_i90++) {
    (*c71_b_e_m)[c71_i90] = c71_e_m[c71_i90];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c71_sfEvent);
}

static void initSimStructsc71_ICARO_III_debug_tel_tag
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c71_machineNumber, uint32_T
  c71_chartNumber, uint32_T c71_instanceNumber)
{
  (void)c71_machineNumber;
  (void)c71_chartNumber;
  (void)c71_instanceNumber;
}

static const mxArray *c71_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  real_T c71_u;
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  c71_u = *(real_T *)c71_inData;
  c71_y = NULL;
  if (!chartInstance->c71_ini_not_empty) {
    sf_mex_assign(&c71_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c71_y, sf_mex_create("y", &c71_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static real_T c71_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_b_ini, const char_T *c71_identifier)
{
  real_T c71_y;
  emlrtMsgIdentifier c71_thisId;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_b_ini),
    &c71_thisId);
  sf_mex_destroy(&c71_b_ini);
  return c71_y;
}

static real_T c71_b_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId)
{
  real_T c71_y;
  real_T c71_d3;
  if (mxIsEmpty(c71_u)) {
    chartInstance->c71_ini_not_empty = false;
  } else {
    chartInstance->c71_ini_not_empty = true;
    sf_mex_import(c71_parentId, sf_mex_dup(c71_u), &c71_d3, 1, 0, 0U, 0, 0U, 0);
    c71_y = c71_d3;
  }

  sf_mex_destroy(&c71_u);
  return c71_y;
}

static void c71_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_b_ini;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real_T c71_y;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_b_ini = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_b_ini),
    &c71_thisId);
  sf_mex_destroy(&c71_b_ini);
  *(real_T *)c71_outData = c71_y;
  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_b_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  int32_T c71_i91;
  real32_T c71_b_inData[3];
  int32_T c71_i92;
  real32_T c71_u[3];
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  for (c71_i91 = 0; c71_i91 < 3; c71_i91++) {
    c71_b_inData[c71_i91] = (*(real32_T (*)[3])c71_inData)[c71_i91];
  }

  for (c71_i92 = 0; c71_i92 < 3; c71_i92++) {
    c71_u[c71_i92] = c71_b_inData[c71_i92];
  }

  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 1, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static void c71_c_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_e_m, const char_T *c71_identifier, real32_T
  c71_y[3])
{
  emlrtMsgIdentifier c71_thisId;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_e_m), &c71_thisId, c71_y);
  sf_mex_destroy(&c71_e_m);
}

static void c71_d_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[3])
{
  real32_T c71_fv16[3];
  int32_T c71_i93;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), c71_fv16, 1, 1, 0U, 1, 0U, 1, 3);
  for (c71_i93 = 0; c71_i93 < 3; c71_i93++) {
    c71_y[c71_i93] = c71_fv16[c71_i93];
  }

  sf_mex_destroy(&c71_u);
}

static void c71_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_e_m;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real32_T c71_y[3];
  int32_T c71_i94;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_e_m = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_e_m), &c71_thisId, c71_y);
  sf_mex_destroy(&c71_e_m);
  for (c71_i94 = 0; c71_i94 < 3; c71_i94++) {
    (*(real32_T (*)[3])c71_outData)[c71_i94] = c71_y[c71_i94];
  }

  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_c_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  int32_T c71_i95;
  real32_T c71_b_inData[4];
  int32_T c71_i96;
  real32_T c71_u[4];
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  for (c71_i95 = 0; c71_i95 < 4; c71_i95++) {
    c71_b_inData[c71_i95] = (*(real32_T (*)[4])c71_inData)[c71_i95];
  }

  for (c71_i96 = 0; c71_i96 < 4; c71_i96++) {
    c71_u[c71_i96] = c71_b_inData[c71_i96];
  }

  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 1, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static void c71_e_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_q_out, const char_T *c71_identifier,
  real32_T c71_y[4])
{
  emlrtMsgIdentifier c71_thisId;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_q_out), &c71_thisId,
    c71_y);
  sf_mex_destroy(&c71_q_out);
}

static void c71_f_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[4])
{
  real32_T c71_fv17[4];
  int32_T c71_i97;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), c71_fv17, 1, 1, 0U, 1, 0U, 1, 4);
  for (c71_i97 = 0; c71_i97 < 4; c71_i97++) {
    c71_y[c71_i97] = c71_fv17[c71_i97];
  }

  sf_mex_destroy(&c71_u);
}

static void c71_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_q_out;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real32_T c71_y[4];
  int32_T c71_i98;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_q_out = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_q_out), &c71_thisId,
    c71_y);
  sf_mex_destroy(&c71_q_out);
  for (c71_i98 = 0; c71_i98 < 4; c71_i98++) {
    (*(real32_T (*)[4])c71_outData)[c71_i98] = c71_y[c71_i98];
  }

  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_d_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  real32_T c71_u;
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  c71_u = *(real32_T *)c71_inData;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", &c71_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static real32_T c71_g_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId)
{
  real32_T c71_y;
  real32_T c71_f1;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), &c71_f1, 1, 1, 0U, 0, 0U, 0);
  c71_y = c71_f1;
  sf_mex_destroy(&c71_u);
  return c71_y;
}

static void c71_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_b_T;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real32_T c71_y;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_b_T = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_b_T), &c71_thisId);
  sf_mex_destroy(&c71_b_T);
  *(real32_T *)c71_outData = c71_y;
  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_e_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  real_T c71_u;
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  c71_u = *(real_T *)c71_inData;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", &c71_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static real_T c71_h_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId)
{
  real_T c71_y;
  real_T c71_d4;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), &c71_d4, 1, 0, 0U, 0, 0U, 0);
  c71_y = c71_d4;
  sf_mex_destroy(&c71_u);
  return c71_y;
}

static void c71_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_nargout;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real_T c71_y;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_nargout = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_nargout),
    &c71_thisId);
  sf_mex_destroy(&c71_nargout);
  *(real_T *)c71_outData = c71_y;
  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_f_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  int32_T c71_i99;
  int32_T c71_i100;
  int32_T c71_i101;
  real32_T c71_b_inData[9];
  int32_T c71_i102;
  int32_T c71_i103;
  int32_T c71_i104;
  real32_T c71_u[9];
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  c71_i99 = 0;
  for (c71_i100 = 0; c71_i100 < 3; c71_i100++) {
    for (c71_i101 = 0; c71_i101 < 3; c71_i101++) {
      c71_b_inData[c71_i101 + c71_i99] = (*(real32_T (*)[9])c71_inData)[c71_i101
        + c71_i99];
    }

    c71_i99 += 3;
  }

  c71_i102 = 0;
  for (c71_i103 = 0; c71_i103 < 3; c71_i103++) {
    for (c71_i104 = 0; c71_i104 < 3; c71_i104++) {
      c71_u[c71_i104 + c71_i102] = c71_b_inData[c71_i104 + c71_i102];
    }

    c71_i102 += 3;
  }

  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 1, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static void c71_i_emlrt_marshallIn(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, const mxArray *c71_u, const emlrtMsgIdentifier *c71_parentId,
  real32_T c71_y[9])
{
  real32_T c71_fv18[9];
  int32_T c71_i105;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), c71_fv18, 1, 1, 0U, 1, 0U, 2, 3,
                3);
  for (c71_i105 = 0; c71_i105 < 9; c71_i105++) {
    c71_y[c71_i105] = c71_fv18[c71_i105];
  }

  sf_mex_destroy(&c71_u);
}

static void c71_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_Rt;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  real32_T c71_y[9];
  int32_T c71_i106;
  int32_T c71_i107;
  int32_T c71_i108;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_Rt = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_Rt), &c71_thisId, c71_y);
  sf_mex_destroy(&c71_Rt);
  c71_i106 = 0;
  for (c71_i107 = 0; c71_i107 < 3; c71_i107++) {
    for (c71_i108 = 0; c71_i108 < 3; c71_i108++) {
      (*(real32_T (*)[9])c71_outData)[c71_i108 + c71_i106] = c71_y[c71_i108 +
        c71_i106];
    }

    c71_i106 += 3;
  }

  sf_mex_destroy(&c71_mxArrayInData);
}

static const mxArray *c71_g_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  int32_T c71_i109;
  real_T c71_b_inData[3];
  int32_T c71_i110;
  real_T c71_u[3];
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  for (c71_i109 = 0; c71_i109 < 3; c71_i109++) {
    c71_b_inData[c71_i109] = (*(real_T (*)[3])c71_inData)[c71_i109];
  }

  for (c71_i110 = 0; c71_i110 < 3; c71_i110++) {
    c71_u[c71_i110] = c71_b_inData[c71_i110];
  }

  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

const mxArray *sf_c71_ICARO_III_debug_tel_tag_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c71_nameCaptureInfo = NULL;
  c71_nameCaptureInfo = NULL;
  sf_mex_assign(&c71_nameCaptureInfo, sf_mex_createstruct("structure", 2, 71, 1),
                false);
  c71_info_helper(&c71_nameCaptureInfo);
  c71_b_info_helper(&c71_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c71_nameCaptureInfo);
  return c71_nameCaptureInfo;
}

static void c71_info_helper(const mxArray **c71_info)
{
  const mxArray *c71_rhs0 = NULL;
  const mxArray *c71_lhs0 = NULL;
  const mxArray *c71_rhs1 = NULL;
  const mxArray *c71_lhs1 = NULL;
  const mxArray *c71_rhs2 = NULL;
  const mxArray *c71_lhs2 = NULL;
  const mxArray *c71_rhs3 = NULL;
  const mxArray *c71_lhs3 = NULL;
  const mxArray *c71_rhs4 = NULL;
  const mxArray *c71_lhs4 = NULL;
  const mxArray *c71_rhs5 = NULL;
  const mxArray *c71_lhs5 = NULL;
  const mxArray *c71_rhs6 = NULL;
  const mxArray *c71_lhs6 = NULL;
  const mxArray *c71_rhs7 = NULL;
  const mxArray *c71_lhs7 = NULL;
  const mxArray *c71_rhs8 = NULL;
  const mxArray *c71_lhs8 = NULL;
  const mxArray *c71_rhs9 = NULL;
  const mxArray *c71_lhs9 = NULL;
  const mxArray *c71_rhs10 = NULL;
  const mxArray *c71_lhs10 = NULL;
  const mxArray *c71_rhs11 = NULL;
  const mxArray *c71_lhs11 = NULL;
  const mxArray *c71_rhs12 = NULL;
  const mxArray *c71_lhs12 = NULL;
  const mxArray *c71_rhs13 = NULL;
  const mxArray *c71_lhs13 = NULL;
  const mxArray *c71_rhs14 = NULL;
  const mxArray *c71_lhs14 = NULL;
  const mxArray *c71_rhs15 = NULL;
  const mxArray *c71_lhs15 = NULL;
  const mxArray *c71_rhs16 = NULL;
  const mxArray *c71_lhs16 = NULL;
  const mxArray *c71_rhs17 = NULL;
  const mxArray *c71_lhs17 = NULL;
  const mxArray *c71_rhs18 = NULL;
  const mxArray *c71_lhs18 = NULL;
  const mxArray *c71_rhs19 = NULL;
  const mxArray *c71_lhs19 = NULL;
  const mxArray *c71_rhs20 = NULL;
  const mxArray *c71_lhs20 = NULL;
  const mxArray *c71_rhs21 = NULL;
  const mxArray *c71_lhs21 = NULL;
  const mxArray *c71_rhs22 = NULL;
  const mxArray *c71_lhs22 = NULL;
  const mxArray *c71_rhs23 = NULL;
  const mxArray *c71_lhs23 = NULL;
  const mxArray *c71_rhs24 = NULL;
  const mxArray *c71_lhs24 = NULL;
  const mxArray *c71_rhs25 = NULL;
  const mxArray *c71_lhs25 = NULL;
  const mxArray *c71_rhs26 = NULL;
  const mxArray *c71_lhs26 = NULL;
  const mxArray *c71_rhs27 = NULL;
  const mxArray *c71_lhs27 = NULL;
  const mxArray *c71_rhs28 = NULL;
  const mxArray *c71_lhs28 = NULL;
  const mxArray *c71_rhs29 = NULL;
  const mxArray *c71_lhs29 = NULL;
  const mxArray *c71_rhs30 = NULL;
  const mxArray *c71_lhs30 = NULL;
  const mxArray *c71_rhs31 = NULL;
  const mxArray *c71_lhs31 = NULL;
  const mxArray *c71_rhs32 = NULL;
  const mxArray *c71_lhs32 = NULL;
  const mxArray *c71_rhs33 = NULL;
  const mxArray *c71_lhs33 = NULL;
  const mxArray *c71_rhs34 = NULL;
  const mxArray *c71_lhs34 = NULL;
  const mxArray *c71_rhs35 = NULL;
  const mxArray *c71_lhs35 = NULL;
  const mxArray *c71_rhs36 = NULL;
  const mxArray *c71_lhs36 = NULL;
  const mxArray *c71_rhs37 = NULL;
  const mxArray *c71_lhs37 = NULL;
  const mxArray *c71_rhs38 = NULL;
  const mxArray *c71_lhs38 = NULL;
  const mxArray *c71_rhs39 = NULL;
  const mxArray *c71_lhs39 = NULL;
  const mxArray *c71_rhs40 = NULL;
  const mxArray *c71_lhs40 = NULL;
  const mxArray *c71_rhs41 = NULL;
  const mxArray *c71_lhs41 = NULL;
  const mxArray *c71_rhs42 = NULL;
  const mxArray *c71_lhs42 = NULL;
  const mxArray *c71_rhs43 = NULL;
  const mxArray *c71_lhs43 = NULL;
  const mxArray *c71_rhs44 = NULL;
  const mxArray *c71_lhs44 = NULL;
  const mxArray *c71_rhs45 = NULL;
  const mxArray *c71_lhs45 = NULL;
  const mxArray *c71_rhs46 = NULL;
  const mxArray *c71_lhs46 = NULL;
  const mxArray *c71_rhs47 = NULL;
  const mxArray *c71_lhs47 = NULL;
  const mxArray *c71_rhs48 = NULL;
  const mxArray *c71_lhs48 = NULL;
  const mxArray *c71_rhs49 = NULL;
  const mxArray *c71_lhs49 = NULL;
  const mxArray *c71_rhs50 = NULL;
  const mxArray *c71_lhs50 = NULL;
  const mxArray *c71_rhs51 = NULL;
  const mxArray *c71_lhs51 = NULL;
  const mxArray *c71_rhs52 = NULL;
  const mxArray *c71_lhs52 = NULL;
  const mxArray *c71_rhs53 = NULL;
  const mxArray *c71_lhs53 = NULL;
  const mxArray *c71_rhs54 = NULL;
  const mxArray *c71_lhs54 = NULL;
  const mxArray *c71_rhs55 = NULL;
  const mxArray *c71_lhs55 = NULL;
  const mxArray *c71_rhs56 = NULL;
  const mxArray *c71_lhs56 = NULL;
  const mxArray *c71_rhs57 = NULL;
  const mxArray *c71_lhs57 = NULL;
  const mxArray *c71_rhs58 = NULL;
  const mxArray *c71_lhs58 = NULL;
  const mxArray *c71_rhs59 = NULL;
  const mxArray *c71_lhs59 = NULL;
  const mxArray *c71_rhs60 = NULL;
  const mxArray *c71_lhs60 = NULL;
  const mxArray *c71_rhs61 = NULL;
  const mxArray *c71_lhs61 = NULL;
  const mxArray *c71_rhs62 = NULL;
  const mxArray *c71_lhs62 = NULL;
  const mxArray *c71_rhs63 = NULL;
  const mxArray *c71_lhs63 = NULL;
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("norm"), "name", "name", 0);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c71_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 1);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 1);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c71_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 2);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c71_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 3);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  3);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980692U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c71_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 4);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c71_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 5);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c71_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 6);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 6);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c71_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 7);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 7);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c71_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 8);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c71_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 9);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c71_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("realmin"), "name", "name",
                  10);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c71_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 11);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c71_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c71_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 13);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c71_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 14);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c71_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 15);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c71_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c71_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c71_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c71_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("abs"), "name", "name", 19);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c71_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c71_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 21);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c71_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("mrdivide"), "name", "name",
                  22);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c71_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 23);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 23);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c71_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("rdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c71_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c71_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 26);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c71_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_div"), "name", "name",
                  27);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c71_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 28);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c71_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("mpower"), "name", "name", 29);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c71_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c71_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c71_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("ismatrix"), "name", "name",
                  32);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c71_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("ismatrix"), "name", "name",
                  33);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c71_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("power"), "name", "name", 34);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c71_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c71_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c71_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 37);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c71_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 38);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c71_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 39);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 39);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c71_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 40);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c71_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 41);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("floor"), "name", "name", 41);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c71_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 42);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c71_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 43);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c71_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 44);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 44);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c71_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 45);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("sqrt"), "name", "name", 45);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c71_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_error"), "name", "name",
                  46);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c71_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 47);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c71_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 48);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("cross"), "name", "name", 48);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c71_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 49);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c71_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 50);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 50);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c71_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 51);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 51);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c71_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 52);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 52);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c71_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c71_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 54);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("abs"), "name", "name", 54);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c71_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 55);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eps"), "name", "name", 55);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c71_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_eps"), "name", "name",
                  56);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c71_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 57);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c71_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 58);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c71_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 59);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c71_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  60);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c71_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 61);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c71_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 62);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c71_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 63);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 63);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c71_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c71_rhs0);
  sf_mex_destroy(&c71_lhs0);
  sf_mex_destroy(&c71_rhs1);
  sf_mex_destroy(&c71_lhs1);
  sf_mex_destroy(&c71_rhs2);
  sf_mex_destroy(&c71_lhs2);
  sf_mex_destroy(&c71_rhs3);
  sf_mex_destroy(&c71_lhs3);
  sf_mex_destroy(&c71_rhs4);
  sf_mex_destroy(&c71_lhs4);
  sf_mex_destroy(&c71_rhs5);
  sf_mex_destroy(&c71_lhs5);
  sf_mex_destroy(&c71_rhs6);
  sf_mex_destroy(&c71_lhs6);
  sf_mex_destroy(&c71_rhs7);
  sf_mex_destroy(&c71_lhs7);
  sf_mex_destroy(&c71_rhs8);
  sf_mex_destroy(&c71_lhs8);
  sf_mex_destroy(&c71_rhs9);
  sf_mex_destroy(&c71_lhs9);
  sf_mex_destroy(&c71_rhs10);
  sf_mex_destroy(&c71_lhs10);
  sf_mex_destroy(&c71_rhs11);
  sf_mex_destroy(&c71_lhs11);
  sf_mex_destroy(&c71_rhs12);
  sf_mex_destroy(&c71_lhs12);
  sf_mex_destroy(&c71_rhs13);
  sf_mex_destroy(&c71_lhs13);
  sf_mex_destroy(&c71_rhs14);
  sf_mex_destroy(&c71_lhs14);
  sf_mex_destroy(&c71_rhs15);
  sf_mex_destroy(&c71_lhs15);
  sf_mex_destroy(&c71_rhs16);
  sf_mex_destroy(&c71_lhs16);
  sf_mex_destroy(&c71_rhs17);
  sf_mex_destroy(&c71_lhs17);
  sf_mex_destroy(&c71_rhs18);
  sf_mex_destroy(&c71_lhs18);
  sf_mex_destroy(&c71_rhs19);
  sf_mex_destroy(&c71_lhs19);
  sf_mex_destroy(&c71_rhs20);
  sf_mex_destroy(&c71_lhs20);
  sf_mex_destroy(&c71_rhs21);
  sf_mex_destroy(&c71_lhs21);
  sf_mex_destroy(&c71_rhs22);
  sf_mex_destroy(&c71_lhs22);
  sf_mex_destroy(&c71_rhs23);
  sf_mex_destroy(&c71_lhs23);
  sf_mex_destroy(&c71_rhs24);
  sf_mex_destroy(&c71_lhs24);
  sf_mex_destroy(&c71_rhs25);
  sf_mex_destroy(&c71_lhs25);
  sf_mex_destroy(&c71_rhs26);
  sf_mex_destroy(&c71_lhs26);
  sf_mex_destroy(&c71_rhs27);
  sf_mex_destroy(&c71_lhs27);
  sf_mex_destroy(&c71_rhs28);
  sf_mex_destroy(&c71_lhs28);
  sf_mex_destroy(&c71_rhs29);
  sf_mex_destroy(&c71_lhs29);
  sf_mex_destroy(&c71_rhs30);
  sf_mex_destroy(&c71_lhs30);
  sf_mex_destroy(&c71_rhs31);
  sf_mex_destroy(&c71_lhs31);
  sf_mex_destroy(&c71_rhs32);
  sf_mex_destroy(&c71_lhs32);
  sf_mex_destroy(&c71_rhs33);
  sf_mex_destroy(&c71_lhs33);
  sf_mex_destroy(&c71_rhs34);
  sf_mex_destroy(&c71_lhs34);
  sf_mex_destroy(&c71_rhs35);
  sf_mex_destroy(&c71_lhs35);
  sf_mex_destroy(&c71_rhs36);
  sf_mex_destroy(&c71_lhs36);
  sf_mex_destroy(&c71_rhs37);
  sf_mex_destroy(&c71_lhs37);
  sf_mex_destroy(&c71_rhs38);
  sf_mex_destroy(&c71_lhs38);
  sf_mex_destroy(&c71_rhs39);
  sf_mex_destroy(&c71_lhs39);
  sf_mex_destroy(&c71_rhs40);
  sf_mex_destroy(&c71_lhs40);
  sf_mex_destroy(&c71_rhs41);
  sf_mex_destroy(&c71_lhs41);
  sf_mex_destroy(&c71_rhs42);
  sf_mex_destroy(&c71_lhs42);
  sf_mex_destroy(&c71_rhs43);
  sf_mex_destroy(&c71_lhs43);
  sf_mex_destroy(&c71_rhs44);
  sf_mex_destroy(&c71_lhs44);
  sf_mex_destroy(&c71_rhs45);
  sf_mex_destroy(&c71_lhs45);
  sf_mex_destroy(&c71_rhs46);
  sf_mex_destroy(&c71_lhs46);
  sf_mex_destroy(&c71_rhs47);
  sf_mex_destroy(&c71_lhs47);
  sf_mex_destroy(&c71_rhs48);
  sf_mex_destroy(&c71_lhs48);
  sf_mex_destroy(&c71_rhs49);
  sf_mex_destroy(&c71_lhs49);
  sf_mex_destroy(&c71_rhs50);
  sf_mex_destroy(&c71_lhs50);
  sf_mex_destroy(&c71_rhs51);
  sf_mex_destroy(&c71_lhs51);
  sf_mex_destroy(&c71_rhs52);
  sf_mex_destroy(&c71_lhs52);
  sf_mex_destroy(&c71_rhs53);
  sf_mex_destroy(&c71_lhs53);
  sf_mex_destroy(&c71_rhs54);
  sf_mex_destroy(&c71_lhs54);
  sf_mex_destroy(&c71_rhs55);
  sf_mex_destroy(&c71_lhs55);
  sf_mex_destroy(&c71_rhs56);
  sf_mex_destroy(&c71_lhs56);
  sf_mex_destroy(&c71_rhs57);
  sf_mex_destroy(&c71_lhs57);
  sf_mex_destroy(&c71_rhs58);
  sf_mex_destroy(&c71_lhs58);
  sf_mex_destroy(&c71_rhs59);
  sf_mex_destroy(&c71_lhs59);
  sf_mex_destroy(&c71_rhs60);
  sf_mex_destroy(&c71_lhs60);
  sf_mex_destroy(&c71_rhs61);
  sf_mex_destroy(&c71_lhs61);
  sf_mex_destroy(&c71_rhs62);
  sf_mex_destroy(&c71_lhs62);
  sf_mex_destroy(&c71_rhs63);
  sf_mex_destroy(&c71_lhs63);
}

static const mxArray *c71_emlrt_marshallOut(const char * c71_u)
{
  const mxArray *c71_y = NULL;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c71_u)), false);
  return c71_y;
}

static const mxArray *c71_b_emlrt_marshallOut(const uint32_T c71_u)
{
  const mxArray *c71_y = NULL;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", &c71_u, 7, 0U, 0U, 0U, 0), false);
  return c71_y;
}

static void c71_b_info_helper(const mxArray **c71_info)
{
  const mxArray *c71_rhs64 = NULL;
  const mxArray *c71_lhs64 = NULL;
  const mxArray *c71_rhs65 = NULL;
  const mxArray *c71_lhs65 = NULL;
  const mxArray *c71_rhs66 = NULL;
  const mxArray *c71_lhs66 = NULL;
  const mxArray *c71_rhs67 = NULL;
  const mxArray *c71_lhs67 = NULL;
  const mxArray *c71_rhs68 = NULL;
  const mxArray *c71_lhs68 = NULL;
  const mxArray *c71_rhs69 = NULL;
  const mxArray *c71_lhs69 = NULL;
  const mxArray *c71_rhs70 = NULL;
  const mxArray *c71_lhs70 = NULL;
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 64);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 64);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c71_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 65);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 65);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c71_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 66);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 66);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1389307922U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c71_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(""), "context", "context", 67);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("atan2"), "name", "name", 67);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1343830372U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c71_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 68);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c71_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 69);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c71_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 70);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c71_info, c71_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c71_info, c71_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c71_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c71_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c71_info, sf_mex_duplicatearraysafe(&c71_lhs70), "lhs", "lhs",
                  70);
  sf_mex_destroy(&c71_rhs64);
  sf_mex_destroy(&c71_lhs64);
  sf_mex_destroy(&c71_rhs65);
  sf_mex_destroy(&c71_lhs65);
  sf_mex_destroy(&c71_rhs66);
  sf_mex_destroy(&c71_lhs66);
  sf_mex_destroy(&c71_rhs67);
  sf_mex_destroy(&c71_lhs67);
  sf_mex_destroy(&c71_rhs68);
  sf_mex_destroy(&c71_lhs68);
  sf_mex_destroy(&c71_rhs69);
  sf_mex_destroy(&c71_lhs69);
  sf_mex_destroy(&c71_rhs70);
  sf_mex_destroy(&c71_lhs70);
}

static real32_T c71_norm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x[3])
{
  int32_T c71_i111;
  real32_T c71_b_x[3];
  for (c71_i111 = 0; c71_i111 < 3; c71_i111++) {
    c71_b_x[c71_i111] = c71_x[c71_i111];
  }

  return c71_eml_xnrm2(chartInstance, c71_b_x);
}

static real32_T c71_eml_xnrm2(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x[3])
{
  real32_T c71_y;
  real32_T c71_scale;
  int32_T c71_k;
  int32_T c71_b_k;
  real32_T c71_b_x;
  real32_T c71_c_x;
  real32_T c71_absxk;
  real32_T c71_t;
  (void)chartInstance;
  c71_y = 0.0F;
  c71_scale = 1.17549435E-38F;
  for (c71_k = 1; c71_k < 4; c71_k++) {
    c71_b_k = c71_k;
    c71_b_x = c71_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c71_b_k), 1, 3, 1, 0) - 1];
    c71_c_x = c71_b_x;
    c71_absxk = muSingleScalarAbs(c71_c_x);
    if (c71_absxk > c71_scale) {
      c71_t = c71_scale / c71_absxk;
      c71_y = 1.0F + c71_y * c71_t * c71_t;
      c71_scale = c71_absxk;
    } else {
      c71_t = c71_absxk / c71_scale;
      c71_y += c71_t * c71_t;
    }
  }

  return c71_scale * muSingleScalarSqrt(c71_y);
}

static real32_T c71_abs(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x)
{
  real32_T c71_b_x;
  (void)chartInstance;
  c71_b_x = c71_x;
  return muSingleScalarAbs(c71_b_x);
}

static void c71_qtriad(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_acc[3], real32_T c71_mag[3], real32_T c71_q_out[4])
{
  uint32_T c71_debug_family_var_map[18];
  real32_T c71_ib[3];
  real_T c71_ir[3];
  real32_T c71_mb[3];
  real32_T c71_mr[3];
  real32_T c71_jb[3];
  real32_T c71_jr[3];
  real32_T c71_kb[3];
  real32_T c71_kr[3];
  real32_T c71_c[9];
  real32_T c71_q1;
  real32_T c71_q2;
  real32_T c71_q3;
  real32_T c71_q4;
  real_T c71_nargin = 2.0;
  real_T c71_nargout = 1.0;
  int32_T c71_i112;
  real32_T c71_x[3];
  int32_T c71_i113;
  real32_T c71_b_x[3];
  real32_T c71_y;
  int32_T c71_i114;
  real32_T c71_B;
  real32_T c71_b_y;
  real32_T c71_c_y;
  real32_T c71_d_y;
  int32_T c71_i115;
  int32_T c71_i116;
  static real_T c71_dv2[3] = { 0.0, 0.0, -1.0 };

  real32_T c71_c_x;
  real32_T c71_d_x;
  int32_T c71_i117;
  int32_T c71_i118;
  real32_T c71_b[3];
  real32_T c71_c1;
  real32_T c71_c2;
  real32_T c71_c3;
  int32_T c71_i119;
  int32_T c71_i120;
  real32_T c71_e_x[3];
  real32_T c71_e_y;
  int32_T c71_i121;
  real32_T c71_b_B;
  real32_T c71_f_y;
  real32_T c71_g_y;
  real32_T c71_h_y;
  int32_T c71_i122;
  int32_T c71_i123;
  real_T c71_dv3[3];
  int32_T c71_i124;
  real32_T c71_b_mr[3];
  real32_T c71_fv19[3];
  int32_T c71_i125;
  int32_T c71_i126;
  int32_T c71_i127;
  real32_T c71_f_x[3];
  real32_T c71_i_y;
  int32_T c71_i128;
  real32_T c71_c_B;
  real32_T c71_j_y;
  real32_T c71_k_y;
  real32_T c71_l_y;
  int32_T c71_i129;
  int32_T c71_i130;
  int32_T c71_i131;
  real32_T c71_b_c1;
  real32_T c71_b_c2;
  real32_T c71_b_c3;
  int32_T c71_i132;
  real_T c71_dv4[3];
  int32_T c71_i133;
  real32_T c71_b_jr[3];
  real32_T c71_fv20[3];
  int32_T c71_i134;
  int32_T c71_i135;
  int32_T c71_i136;
  int32_T c71_i137;
  int32_T c71_i138;
  static real32_T c71_fv21[3] = { 0.0F, 0.0F, -1.0F };

  real32_T c71_m_y[9];
  int32_T c71_i139;
  int32_T c71_i140;
  real32_T c71_b_b[3];
  int32_T c71_i141;
  int32_T c71_i142;
  int32_T c71_i143;
  real32_T c71_n_y[9];
  int32_T c71_i144;
  int32_T c71_i145;
  int32_T c71_i146;
  int32_T c71_i147;
  int32_T c71_i148;
  real32_T c71_o_y[9];
  int32_T c71_i149;
  int32_T c71_i150;
  int32_T c71_i151;
  int32_T c71_i152;
  real32_T c71_g_x;
  real32_T c71_h_x;
  real32_T c71_c_b;
  real32_T c71_d_B;
  real32_T c71_p_y;
  real32_T c71_q_y;
  real32_T c71_r_y;
  real32_T c71_s_y;
  real32_T c71_e_B;
  real32_T c71_t_y;
  real32_T c71_u_y;
  real32_T c71_v_y;
  real32_T c71_w_y;
  real32_T c71_f_B;
  real32_T c71_x_y;
  real32_T c71_y_y;
  real32_T c71_ab_y;
  real32_T c71_bb_y;
  real32_T c71_b_q1[4];
  int32_T c71_i153;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c71_b_debug_family_names,
    c71_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_ib, 0U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c71_ir, 1U, c71_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_mb, 2U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_mr, 3U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_jb, 4U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_jr, 5U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_kb, 6U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_kr, 7U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_c, 8U, c71_f_sf_marshallOut,
    c71_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q1, 9U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q2, 10U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q3, 11U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_q4, 12U, c71_d_sf_marshallOut,
    c71_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_nargin, 13U, c71_e_sf_marshallOut,
    c71_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c71_nargout, 14U, c71_e_sf_marshallOut,
    c71_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_acc, 15U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_mag, 16U, c71_b_sf_marshallOut,
    c71_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c71_q_out, 17U, c71_c_sf_marshallOut,
    c71_c_sf_marshallIn);
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 162U);
  for (c71_i112 = 0; c71_i112 < 3; c71_i112++) {
    c71_x[c71_i112] = c71_acc[c71_i112];
  }

  for (c71_i113 = 0; c71_i113 < 3; c71_i113++) {
    c71_b_x[c71_i113] = c71_x[c71_i113];
  }

  c71_y = c71_eml_xnrm2(chartInstance, c71_b_x);
  for (c71_i114 = 0; c71_i114 < 3; c71_i114++) {
    c71_x[c71_i114] = c71_acc[c71_i114];
  }

  c71_B = c71_y;
  c71_b_y = c71_B;
  c71_c_y = c71_b_y;
  c71_d_y = c71_c_y;
  for (c71_i115 = 0; c71_i115 < 3; c71_i115++) {
    c71_ib[c71_i115] = c71_x[c71_i115] / c71_d_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 163U);
  for (c71_i116 = 0; c71_i116 < 3; c71_i116++) {
    c71_ir[c71_i116] = c71_dv2[c71_i116];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 167U);
  c71_c_x = c71_mpower(chartInstance, c71_mag[0]) + c71_mpower(chartInstance,
    c71_mag[1]);
  c71_d_x = c71_c_x;
  if (c71_d_x < 0.0F) {
    c71_eml_error(chartInstance);
  }

  c71_d_x = muSingleScalarSqrt(c71_d_x);
  c71_mb[0] = 0.0F;
  c71_mb[1] = c71_d_x;
  c71_mb[2] = 0.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 168U);
  c71_mr[0] = c71_mag[0];
  c71_mr[1] = c71_mag[1];
  c71_mr[2] = 0.0F;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 169U);
  for (c71_i117 = 0; c71_i117 < 3; c71_i117++) {
    c71_x[c71_i117] = c71_ib[c71_i117];
  }

  for (c71_i118 = 0; c71_i118 < 3; c71_i118++) {
    c71_b[c71_i118] = c71_mb[c71_i118];
  }

  c71_c1 = c71_x[1] * c71_b[2] - c71_x[2] * c71_b[1];
  c71_c2 = c71_x[2] * c71_b[0] - c71_x[0] * c71_b[2];
  c71_c3 = c71_x[0] * c71_b[1] - c71_x[1] * c71_b[0];
  c71_jb[0] = c71_c1;
  c71_jb[1] = c71_c2;
  c71_jb[2] = c71_c3;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 170U);
  for (c71_i119 = 0; c71_i119 < 3; c71_i119++) {
    c71_x[c71_i119] = c71_jb[c71_i119];
  }

  for (c71_i120 = 0; c71_i120 < 3; c71_i120++) {
    c71_e_x[c71_i120] = c71_x[c71_i120];
  }

  c71_e_y = c71_eml_xnrm2(chartInstance, c71_e_x);
  for (c71_i121 = 0; c71_i121 < 3; c71_i121++) {
    c71_x[c71_i121] = c71_jb[c71_i121];
  }

  c71_b_B = c71_e_y;
  c71_f_y = c71_b_B;
  c71_g_y = c71_f_y;
  c71_h_y = c71_g_y;
  for (c71_i122 = 0; c71_i122 < 3; c71_i122++) {
    c71_jb[c71_i122] = c71_x[c71_i122] / c71_h_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 171U);
  for (c71_i123 = 0; c71_i123 < 3; c71_i123++) {
    c71_dv3[c71_i123] = c71_dv2[c71_i123];
  }

  for (c71_i124 = 0; c71_i124 < 3; c71_i124++) {
    c71_b_mr[c71_i124] = c71_mr[c71_i124];
  }

  c71_b_cross(chartInstance, c71_dv3, c71_b_mr, c71_fv19);
  for (c71_i125 = 0; c71_i125 < 3; c71_i125++) {
    c71_jr[c71_i125] = c71_fv19[c71_i125];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 172U);
  for (c71_i126 = 0; c71_i126 < 3; c71_i126++) {
    c71_x[c71_i126] = c71_jr[c71_i126];
  }

  for (c71_i127 = 0; c71_i127 < 3; c71_i127++) {
    c71_f_x[c71_i127] = c71_x[c71_i127];
  }

  c71_i_y = c71_eml_xnrm2(chartInstance, c71_f_x);
  for (c71_i128 = 0; c71_i128 < 3; c71_i128++) {
    c71_x[c71_i128] = c71_jr[c71_i128];
  }

  c71_c_B = c71_i_y;
  c71_j_y = c71_c_B;
  c71_k_y = c71_j_y;
  c71_l_y = c71_k_y;
  for (c71_i129 = 0; c71_i129 < 3; c71_i129++) {
    c71_jr[c71_i129] = c71_x[c71_i129] / c71_l_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 173U);
  for (c71_i130 = 0; c71_i130 < 3; c71_i130++) {
    c71_x[c71_i130] = c71_ib[c71_i130];
  }

  for (c71_i131 = 0; c71_i131 < 3; c71_i131++) {
    c71_b[c71_i131] = c71_jb[c71_i131];
  }

  c71_b_c1 = c71_x[1] * c71_b[2] - c71_x[2] * c71_b[1];
  c71_b_c2 = c71_x[2] * c71_b[0] - c71_x[0] * c71_b[2];
  c71_b_c3 = c71_x[0] * c71_b[1] - c71_x[1] * c71_b[0];
  c71_kb[0] = c71_b_c1;
  c71_kb[1] = c71_b_c2;
  c71_kb[2] = c71_b_c3;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 174U);
  for (c71_i132 = 0; c71_i132 < 3; c71_i132++) {
    c71_dv4[c71_i132] = c71_dv2[c71_i132];
  }

  for (c71_i133 = 0; c71_i133 < 3; c71_i133++) {
    c71_b_jr[c71_i133] = c71_jr[c71_i133];
  }

  c71_b_cross(chartInstance, c71_dv4, c71_b_jr, c71_fv20);
  for (c71_i134 = 0; c71_i134 < 3; c71_i134++) {
    c71_kr[c71_i134] = c71_fv20[c71_i134];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 175U);
  for (c71_i135 = 0; c71_i135 < 3; c71_i135++) {
    c71_x[c71_i135] = c71_ib[c71_i135];
  }

  for (c71_i136 = 0; c71_i136 < 3; c71_i136++) {
    c71_i137 = 0;
    for (c71_i138 = 0; c71_i138 < 3; c71_i138++) {
      c71_m_y[c71_i137 + c71_i136] = c71_x[c71_i136] * c71_fv21[c71_i138];
      c71_i137 += 3;
    }
  }

  for (c71_i139 = 0; c71_i139 < 3; c71_i139++) {
    c71_x[c71_i139] = c71_jb[c71_i139];
  }

  for (c71_i140 = 0; c71_i140 < 3; c71_i140++) {
    c71_b_b[c71_i140] = c71_jr[c71_i140];
  }

  for (c71_i141 = 0; c71_i141 < 3; c71_i141++) {
    c71_i142 = 0;
    for (c71_i143 = 0; c71_i143 < 3; c71_i143++) {
      c71_n_y[c71_i142 + c71_i141] = c71_x[c71_i141] * c71_b_b[c71_i143];
      c71_i142 += 3;
    }
  }

  for (c71_i144 = 0; c71_i144 < 3; c71_i144++) {
    c71_x[c71_i144] = c71_kb[c71_i144];
  }

  for (c71_i145 = 0; c71_i145 < 3; c71_i145++) {
    c71_b_b[c71_i145] = c71_kr[c71_i145];
  }

  for (c71_i146 = 0; c71_i146 < 3; c71_i146++) {
    c71_i147 = 0;
    for (c71_i148 = 0; c71_i148 < 3; c71_i148++) {
      c71_o_y[c71_i147 + c71_i146] = c71_x[c71_i146] * c71_b_b[c71_i148];
      c71_i147 += 3;
    }
  }

  c71_i149 = 0;
  for (c71_i150 = 0; c71_i150 < 3; c71_i150++) {
    c71_i151 = 0;
    for (c71_i152 = 0; c71_i152 < 3; c71_i152++) {
      c71_c[c71_i152 + c71_i149] = (c71_m_y[c71_i151 + c71_i150] +
        c71_n_y[c71_i151 + c71_i150]) + c71_o_y[c71_i151 + c71_i150];
      c71_i151 += 3;
    }

    c71_i149 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 177U);
  c71_g_x = ((1.0F + c71_c[0]) + c71_c[4]) + c71_c[8];
  c71_h_x = c71_g_x;
  if (c71_h_x < 0.0F) {
    c71_eml_error(chartInstance);
  }

  c71_h_x = muSingleScalarSqrt(c71_h_x);
  c71_c_b = c71_h_x;
  c71_q1 = 0.5F * c71_c_b;
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 178U);
  c71_d_B = c71_q1;
  c71_p_y = c71_d_B;
  c71_q_y = c71_p_y;
  c71_r_y = c71_q_y;
  c71_s_y = 0.25F / c71_r_y;
  c71_q2 = c71_s_y * (c71_c[5] - c71_c[7]);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 179U);
  c71_e_B = c71_q1;
  c71_t_y = c71_e_B;
  c71_u_y = c71_t_y;
  c71_v_y = c71_u_y;
  c71_w_y = 0.25F / c71_v_y;
  c71_q3 = c71_w_y * (c71_c[6] - c71_c[2]);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 180U);
  c71_f_B = c71_q1;
  c71_x_y = c71_f_B;
  c71_y_y = c71_x_y;
  c71_ab_y = c71_y_y;
  c71_bb_y = 0.25F / c71_ab_y;
  c71_q4 = c71_bb_y * (c71_c[1] - c71_c[3]);
  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, 182U);
  c71_b_q1[0] = c71_q1;
  c71_b_q1[1] = c71_q2;
  c71_b_q1[2] = c71_q3;
  c71_b_q1[3] = c71_q4;
  for (c71_i153 = 0; c71_i153 < 4; c71_i153++) {
    c71_q_out[c71_i153] = c71_b_q1[c71_i153];
  }

  _SFD_EML_CALL(0U, chartInstance->c71_sfEvent, -182);
  _SFD_SYMBOL_SCOPE_POP();
}

static real32_T c71_mpower(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_a)
{
  real32_T c71_b_a;
  real32_T c71_c_a;
  real32_T c71_ak;
  real32_T c71_d_a;
  c71_b_a = c71_a;
  c71_c_a = c71_b_a;
  c71_eml_scalar_eg(chartInstance);
  c71_ak = c71_c_a;
  c71_d_a = c71_ak;
  c71_eml_scalar_eg(chartInstance);
  return c71_d_a * c71_d_a;
}

static void c71_eml_scalar_eg(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real32_T c71_sqrt(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_x)
{
  real32_T c71_b_x;
  c71_b_x = c71_x;
  c71_b_sqrt(chartInstance, &c71_b_x);
  return c71_b_x;
}

static void c71_eml_error(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance)
{
  int32_T c71_i154;
  static char_T c71_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c71_u[30];
  const mxArray *c71_y = NULL;
  int32_T c71_i155;
  static char_T c71_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c71_b_u[4];
  const mxArray *c71_b_y = NULL;
  (void)chartInstance;
  for (c71_i154 = 0; c71_i154 < 30; c71_i154++) {
    c71_u[c71_i154] = c71_cv0[c71_i154];
  }

  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", c71_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c71_i155 = 0; c71_i155 < 4; c71_i155++) {
    c71_b_u[c71_i155] = c71_cv1[c71_i155];
  }

  c71_b_y = NULL;
  sf_mex_assign(&c71_b_y, sf_mex_create("y", c71_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c71_y, 14, c71_b_y));
}

static void c71_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance,
                      real32_T c71_a[3], real32_T c71_b[3], real32_T c71_c[3])
{
  real32_T c71_c1;
  real32_T c71_c2;
  real32_T c71_c3;
  (void)chartInstance;
  c71_c1 = c71_a[1] * c71_b[2] - c71_a[2] * c71_b[1];
  c71_c2 = c71_a[2] * c71_b[0] - c71_a[0] * c71_b[2];
  c71_c3 = c71_a[0] * c71_b[1] - c71_a[1] * c71_b[0];
  c71_c[0] = c71_c1;
  c71_c[1] = c71_c2;
  c71_c[2] = c71_c3;
}

static void c71_b_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real_T c71_a[3], real32_T c71_b[3], real32_T c71_c[3])
{
  real_T c71_b_a;
  real32_T c71_b_b;
  real32_T c71_y;
  real_T c71_c_a;
  real32_T c71_c_b;
  real32_T c71_b_y;
  real32_T c71_c1;
  real_T c71_d_a;
  real32_T c71_d_b;
  real32_T c71_c_y;
  real_T c71_e_a;
  real32_T c71_e_b;
  real32_T c71_d_y;
  real32_T c71_c2;
  real_T c71_f_a;
  real32_T c71_f_b;
  real32_T c71_e_y;
  real_T c71_g_a;
  real32_T c71_g_b;
  real32_T c71_f_y;
  real32_T c71_c3;
  (void)chartInstance;
  c71_b_a = c71_a[1];
  c71_b_b = c71_b[2];
  c71_y = (real32_T)c71_b_a * c71_b_b;
  c71_c_a = c71_a[2];
  c71_c_b = c71_b[1];
  c71_b_y = (real32_T)c71_c_a * c71_c_b;
  c71_c1 = c71_y - c71_b_y;
  c71_d_a = c71_a[2];
  c71_d_b = c71_b[0];
  c71_c_y = (real32_T)c71_d_a * c71_d_b;
  c71_e_a = c71_a[0];
  c71_e_b = c71_b[2];
  c71_d_y = (real32_T)c71_e_a * c71_e_b;
  c71_c2 = c71_c_y - c71_d_y;
  c71_f_a = c71_a[0];
  c71_f_b = c71_b[1];
  c71_e_y = (real32_T)c71_f_a * c71_f_b;
  c71_g_a = c71_a[1];
  c71_g_b = c71_b[0];
  c71_f_y = (real32_T)c71_g_a * c71_g_b;
  c71_c3 = c71_e_y - c71_f_y;
  c71_c[0] = c71_c1;
  c71_c[1] = c71_c2;
  c71_c[2] = c71_c3;
}

static void c71_eps(SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c71_b_eml_scalar_eg(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c71_eml_xgemm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_A[9], real32_T c71_B[3], real32_T c71_C[3],
  real32_T c71_b_C[3])
{
  int32_T c71_i156;
  int32_T c71_i157;
  real32_T c71_b_A[9];
  int32_T c71_i158;
  real32_T c71_b_B[3];
  for (c71_i156 = 0; c71_i156 < 3; c71_i156++) {
    c71_b_C[c71_i156] = c71_C[c71_i156];
  }

  for (c71_i157 = 0; c71_i157 < 9; c71_i157++) {
    c71_b_A[c71_i157] = c71_A[c71_i157];
  }

  for (c71_i158 = 0; c71_i158 < 3; c71_i158++) {
    c71_b_B[c71_i158] = c71_B[c71_i158];
  }

  c71_b_eml_xgemm(chartInstance, c71_b_A, c71_b_B, c71_b_C);
}

static void c71_c_cross(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_a[3], real_T c71_b[3], real32_T c71_c[3])
{
  real32_T c71_b_a;
  real_T c71_b_b;
  real32_T c71_y;
  real32_T c71_c_a;
  real_T c71_c_b;
  real32_T c71_b_y;
  real32_T c71_c1;
  real32_T c71_d_a;
  real_T c71_d_b;
  real32_T c71_c_y;
  real32_T c71_e_a;
  real_T c71_e_b;
  real32_T c71_d_y;
  real32_T c71_c2;
  real32_T c71_f_a;
  real_T c71_f_b;
  real32_T c71_e_y;
  real32_T c71_g_a;
  real_T c71_g_b;
  real32_T c71_f_y;
  real32_T c71_c3;
  (void)chartInstance;
  c71_b_a = c71_a[1];
  c71_b_b = c71_b[2];
  c71_y = c71_b_a * (real32_T)c71_b_b;
  c71_c_a = c71_a[2];
  c71_c_b = c71_b[1];
  c71_b_y = c71_c_a * (real32_T)c71_c_b;
  c71_c1 = c71_y - c71_b_y;
  c71_d_a = c71_a[2];
  c71_d_b = c71_b[0];
  c71_c_y = c71_d_a * (real32_T)c71_d_b;
  c71_e_a = c71_a[0];
  c71_e_b = c71_b[2];
  c71_d_y = c71_e_a * (real32_T)c71_e_b;
  c71_c2 = c71_c_y - c71_d_y;
  c71_f_a = c71_a[0];
  c71_f_b = c71_b[1];
  c71_e_y = c71_f_a * (real32_T)c71_f_b;
  c71_g_a = c71_a[1];
  c71_g_b = c71_b[0];
  c71_f_y = c71_g_a * (real32_T)c71_g_b;
  c71_c3 = c71_e_y - c71_f_y;
  c71_c[0] = c71_c1;
  c71_c[1] = c71_c2;
  c71_c[2] = c71_c3;
}

static real32_T c71_atan2(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_y, real32_T c71_x)
{
  real32_T c71_b_y;
  real32_T c71_b_x;
  (void)chartInstance;
  c71_b_y = c71_y;
  c71_b_x = c71_x;
  return muSingleScalarAtan2(c71_b_y, c71_b_x);
}

static const mxArray *c71_h_sf_marshallOut(void *chartInstanceVoid, void
  *c71_inData)
{
  const mxArray *c71_mxArrayOutData = NULL;
  int32_T c71_u;
  const mxArray *c71_y = NULL;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_mxArrayOutData = NULL;
  c71_u = *(int32_T *)c71_inData;
  c71_y = NULL;
  sf_mex_assign(&c71_y, sf_mex_create("y", &c71_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c71_mxArrayOutData, c71_y, false);
  return c71_mxArrayOutData;
}

static int32_T c71_j_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId)
{
  int32_T c71_y;
  int32_T c71_i159;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), &c71_i159, 1, 6, 0U, 0, 0U, 0);
  c71_y = c71_i159;
  sf_mex_destroy(&c71_u);
  return c71_y;
}

static void c71_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c71_mxArrayInData, const char_T *c71_varName, void *c71_outData)
{
  const mxArray *c71_b_sfEvent;
  const char_T *c71_identifier;
  emlrtMsgIdentifier c71_thisId;
  int32_T c71_y;
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
    chartInstanceVoid;
  c71_b_sfEvent = sf_mex_dup(c71_mxArrayInData);
  c71_identifier = c71_varName;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c71_b_sfEvent),
    &c71_thisId);
  sf_mex_destroy(&c71_b_sfEvent);
  *(int32_T *)c71_outData = c71_y;
  sf_mex_destroy(&c71_mxArrayInData);
}

static uint8_T c71_k_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_b_is_active_c71_ICARO_III_debug_tel_tag, const char_T *c71_identifier)
{
  uint8_T c71_y;
  emlrtMsgIdentifier c71_thisId;
  c71_thisId.fIdentifier = c71_identifier;
  c71_thisId.fParent = NULL;
  c71_y = c71_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c71_b_is_active_c71_ICARO_III_debug_tel_tag), &c71_thisId);
  sf_mex_destroy(&c71_b_is_active_c71_ICARO_III_debug_tel_tag);
  return c71_y;
}

static uint8_T c71_l_emlrt_marshallIn
  (SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance, const mxArray
   *c71_u, const emlrtMsgIdentifier *c71_parentId)
{
  uint8_T c71_y;
  uint8_T c71_u0;
  (void)chartInstance;
  sf_mex_import(c71_parentId, sf_mex_dup(c71_u), &c71_u0, 1, 3, 0U, 0, 0U, 0);
  c71_y = c71_u0;
  sf_mex_destroy(&c71_u);
  return c71_y;
}

static void c71_b_sqrt(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T *c71_x)
{
  if (*c71_x < 0.0F) {
    c71_eml_error(chartInstance);
  }

  *c71_x = muSingleScalarSqrt(*c71_x);
}

static void c71_b_eml_xgemm(SFc71_ICARO_III_debug_tel_tagInstanceStruct
  *chartInstance, real32_T c71_A[9], real32_T c71_B[3], real32_T c71_C[3])
{
  int32_T c71_i160;
  int32_T c71_i161;
  int32_T c71_i162;
  (void)chartInstance;
  for (c71_i160 = 0; c71_i160 < 3; c71_i160++) {
    c71_C[c71_i160] = 0.0F;
    c71_i161 = 0;
    for (c71_i162 = 0; c71_i162 < 3; c71_i162++) {
      c71_C[c71_i160] += c71_A[c71_i161 + c71_i160] * c71_B[c71_i162];
      c71_i161 += 3;
    }
  }
}

static void init_dsm_address_info(SFc71_ICARO_III_debug_tel_tagInstanceStruct
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

void sf_c71_ICARO_III_debug_tel_tag_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(583037976U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2416175387U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2421395014U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3084124552U);
}

mxArray *sf_c71_ICARO_III_debug_tel_tag_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EAR6u4XKLcHKWyROoirOe");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c71_ICARO_III_debug_tel_tag_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c71_ICARO_III_debug_tel_tag_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c71_ICARO_III_debug_tel_tag(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[20],T\"a_ned\",},{M[1],M[14],T\"biases\",},{M[1],M[13],T\"e_int_out_a\",},{M[1],M[23],T\"e_int_out_m\",},{M[1],M[24],T\"e_m\",},{M[1],M[19],T\"euler_out\",},{M[1],M[8],T\"q_out\",},{M[4],M[0],T\"ini\",S'l','i','p'{{M1x2[150 153],M[0],}}},{M[8],M[0],T\"is_active_c71_ICARO_III_debug_tel_tag\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c71_ICARO_III_debug_tel_tag_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO_III_debug_tel_tagMachineNumber_,
           71,
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
        init_script_number_translation(_ICARO_III_debug_tel_tagMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ICARO_III_debug_tel_tagMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ICARO_III_debug_tel_tagMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"euler_out");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a_ned");
          _SFD_SET_DATA_PROPS(2,1,1,0,"gyro");
          _SFD_SET_DATA_PROPS(3,1,1,0,"acc");
          _SFD_SET_DATA_PROPS(4,1,1,0,"mag");
          _SFD_SET_DATA_PROPS(5,1,1,0,"q");
          _SFD_SET_DATA_PROPS(6,1,1,0,"e_int_a");
          _SFD_SET_DATA_PROPS(7,1,1,0,"e_int_m");
          _SFD_SET_DATA_PROPS(8,2,0,1,"q_out");
          _SFD_SET_DATA_PROPS(9,10,0,0,"Kp");
          _SFD_SET_DATA_PROPS(10,10,0,0,"Ki");
          _SFD_SET_DATA_PROPS(11,10,0,0,"T");
          _SFD_SET_DATA_PROPS(12,2,0,1,"e_int_out_a");
          _SFD_SET_DATA_PROPS(13,2,0,1,"e_int_out_m");
          _SFD_SET_DATA_PROPS(14,2,0,1,"biases");
          _SFD_SET_DATA_PROPS(15,2,0,1,"e_m");
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
        _SFD_CV_INIT_EML(0,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3425);
        _SFD_CV_INIT_EML_FCN(0,1,"rotz",3427,-1,3507);
        _SFD_CV_INIT_EML_FCN(0,2,"rotx",3509,-1,3589);
        _SFD_CV_INIT_EML_FCN(0,3,"roty",3591,-1,3673);
        _SFD_CV_INIT_EML_FCN(0,4,"qtriad",3694,-1,4210);
        _SFD_CV_INIT_EML_IF(0,1,0,548,569,-1,606);
        _SFD_CV_INIT_EML_IF(0,1,1,608,629,-1,711);
        _SFD_CV_INIT_EML_IF(0,1,2,811,828,-1,871);
        _SFD_CV_INIT_EML_IF(0,1,3,1841,1855,2152,2317);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_c_sf_marshallOut,(MexInFcnForType)
            c71_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c71_d_sf_marshallOut,(MexInFcnForType)
          c71_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c71_d_sf_marshallOut,(MexInFcnForType)
          c71_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c71_d_sf_marshallOut,(MexInFcnForType)
          c71_d_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c71_b_sf_marshallOut,(MexInFcnForType)
            c71_b_sf_marshallIn);
        }

        {
          real32_T (*c71_euler_out)[3];
          real32_T (*c71_a_ned)[3];
          real32_T (*c71_gyro)[3];
          real32_T (*c71_acc)[3];
          real32_T (*c71_mag)[3];
          real32_T (*c71_q)[4];
          real32_T (*c71_e_int_a)[3];
          real32_T (*c71_e_int_m)[3];
          real32_T (*c71_q_out)[4];
          real32_T (*c71_e_int_out_a)[3];
          real32_T (*c71_e_int_out_m)[3];
          real32_T (*c71_biases)[3];
          real32_T (*c71_e_m)[3];
          c71_e_m = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 7);
          c71_biases = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            6);
          c71_e_int_out_m = (real32_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 5);
          c71_e_int_out_a = (real32_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 4);
          c71_q_out = (real32_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
          c71_e_int_m = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            5);
          c71_e_int_a = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            4);
          c71_q = (real32_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c71_mag = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c71_acc = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c71_gyro = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c71_a_ned = (real32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c71_euler_out = (real32_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c71_euler_out);
          _SFD_SET_DATA_VALUE_PTR(1U, *c71_a_ned);
          _SFD_SET_DATA_VALUE_PTR(2U, *c71_gyro);
          _SFD_SET_DATA_VALUE_PTR(3U, *c71_acc);
          _SFD_SET_DATA_VALUE_PTR(4U, *c71_mag);
          _SFD_SET_DATA_VALUE_PTR(5U, *c71_q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c71_e_int_a);
          _SFD_SET_DATA_VALUE_PTR(7U, *c71_e_int_m);
          _SFD_SET_DATA_VALUE_PTR(8U, *c71_q_out);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c71_Kp);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c71_Ki);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c71_T);
          _SFD_SET_DATA_VALUE_PTR(12U, *c71_e_int_out_a);
          _SFD_SET_DATA_VALUE_PTR(13U, *c71_e_int_out_m);
          _SFD_SET_DATA_VALUE_PTR(14U, *c71_biases);
          _SFD_SET_DATA_VALUE_PTR(15U, *c71_e_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ICARO_III_debug_tel_tagMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Ge0PaMVbfZmsMZEvC1i9ZC";
}

static void sf_opaque_initialize_c71_ICARO_III_debug_tel_tag(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc71_ICARO_III_debug_tel_tagInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
  initialize_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c71_ICARO_III_debug_tel_tag(void *chartInstanceVar)
{
  enable_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c71_ICARO_III_debug_tel_tag(void *chartInstanceVar)
{
  disable_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c71_ICARO_III_debug_tel_tag(void *chartInstanceVar)
{
  sf_gateway_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c71_ICARO_III_debug_tel_tag
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c71_ICARO_III_debug_tel_tag();/* state var info */
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

extern void sf_internal_set_sim_state_c71_ICARO_III_debug_tel_tag(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c71_ICARO_III_debug_tel_tag();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c71_ICARO_III_debug_tel_tag
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c71_ICARO_III_debug_tel_tag(S);
}

static void sf_opaque_set_sim_state_c71_ICARO_III_debug_tel_tag(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c71_ICARO_III_debug_tel_tag(S, st);
}

static void sf_opaque_terminate_c71_ICARO_III_debug_tel_tag(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO_III_debug_tel_tag_optimization_info();
    }

    finalize_c71_ICARO_III_debug_tel_tag
      ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc71_ICARO_III_debug_tel_tag
    ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c71_ICARO_III_debug_tel_tag(SimStruct *S)
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
    initialize_params_c71_ICARO_III_debug_tel_tag
      ((SFc71_ICARO_III_debug_tel_tagInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c71_ICARO_III_debug_tel_tag(SimStruct *S)
{
  /* Actual parameters from chart:
     Ki Kp T
   */
  const char_T *rtParamNames[] = { "Ki", "Kp", "T" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Ki*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_SINGLE);

  /* registration for Kp*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_SINGLE);

  /* registration for T*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_SINGLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ICARO_III_debug_tel_tag_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      71);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,71,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,71,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,71);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,71,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,71,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,71);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1579397570U));
  ssSetChecksum1(S,(3759489685U));
  ssSetChecksum2(S,(4251448543U));
  ssSetChecksum3(S,(948688777U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c71_ICARO_III_debug_tel_tag(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c71_ICARO_III_debug_tel_tag(SimStruct *S)
{
  SFc71_ICARO_III_debug_tel_tagInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc71_ICARO_III_debug_tel_tagInstanceStruct *)utMalloc(sizeof
    (SFc71_ICARO_III_debug_tel_tagInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc71_ICARO_III_debug_tel_tagInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.mdlStart = mdlStart_c71_ICARO_III_debug_tel_tag;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c71_ICARO_III_debug_tel_tag;
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

void c71_ICARO_III_debug_tel_tag_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c71_ICARO_III_debug_tel_tag(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c71_ICARO_III_debug_tel_tag(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c71_ICARO_III_debug_tel_tag(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c71_ICARO_III_debug_tel_tag_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
