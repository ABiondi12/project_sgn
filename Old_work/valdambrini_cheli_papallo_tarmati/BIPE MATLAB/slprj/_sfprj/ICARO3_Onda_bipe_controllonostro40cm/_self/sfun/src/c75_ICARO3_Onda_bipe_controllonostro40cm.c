/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_Onda_bipe_controllonostro40cm_sfun.h"
#include "c75_ICARO3_Onda_bipe_controllonostro40cm.h"
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
static const char * c75_debug_family_names[6] = { "distance_threshold", "nargin",
  "nargout", "distance", "startstop", "go" };

/* Function Declarations */
static void initialize_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initialize_params_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void enable_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void disable_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void c75_update_debugger_state_c75_ICARO3_Onda_bipe_controllonostro40
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_st);
static void finalize_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void sf_gateway_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void initSimStructsc75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c75_machineNumber, uint32_T
  c75_chartNumber, uint32_T c75_instanceNumber);
static const mxArray *c75_sf_marshallOut(void *chartInstanceVoid, void
  *c75_inData);
static real_T c75_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_go, const char_T *c75_identifier);
static real_T c75_b_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId);
static void c75_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c75_mxArrayInData, const char_T *c75_varName, void *c75_outData);
static const mxArray *c75_b_sf_marshallOut(void *chartInstanceVoid, void
  *c75_inData);
static int32_T c75_c_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId);
static void c75_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c75_mxArrayInData, const char_T *c75_varName, void *c75_outData);
static uint8_T c75_d_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_b_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c75_identifier);
static uint8_T c75_e_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId);
static void init_dsm_address_info
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  chartInstance->c75_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c75_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm = 0U;
}

static void initialize_params_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c75_update_debugger_state_c75_ICARO3_Onda_bipe_controllonostro40
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  const mxArray *c75_st;
  const mxArray *c75_y = NULL;
  real_T c75_hoistedGlobal;
  real_T c75_u;
  const mxArray *c75_b_y = NULL;
  uint8_T c75_b_hoistedGlobal;
  uint8_T c75_b_u;
  const mxArray *c75_c_y = NULL;
  real_T *c75_go;
  c75_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c75_st = NULL;
  c75_st = NULL;
  c75_y = NULL;
  sf_mex_assign(&c75_y, sf_mex_createcellmatrix(2, 1), false);
  c75_hoistedGlobal = *c75_go;
  c75_u = c75_hoistedGlobal;
  c75_b_y = NULL;
  sf_mex_assign(&c75_b_y, sf_mex_create("y", &c75_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c75_y, 0, c75_b_y);
  c75_b_hoistedGlobal =
    chartInstance->c75_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm;
  c75_b_u = c75_b_hoistedGlobal;
  c75_c_y = NULL;
  sf_mex_assign(&c75_c_y, sf_mex_create("y", &c75_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c75_y, 1, c75_c_y);
  sf_mex_assign(&c75_st, c75_y, false);
  return c75_st;
}

static void set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_st)
{
  const mxArray *c75_u;
  real_T *c75_go;
  c75_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c75_doneDoubleBufferReInit = true;
  c75_u = sf_mex_dup(c75_st);
  *c75_go = c75_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c75_u,
    0)), "go");
  chartInstance->c75_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm =
    c75_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c75_u, 1)),
    "is_active_c75_ICARO3_Onda_bipe_controllonostro40cm");
  sf_mex_destroy(&c75_u);
  c75_update_debugger_state_c75_ICARO3_Onda_bipe_controllonostro40(chartInstance);
  sf_mex_destroy(&c75_st);
}

static void finalize_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  real_T c75_hoistedGlobal;
  real_T c75_b_hoistedGlobal;
  real_T c75_distance;
  real_T c75_startstop;
  uint32_T c75_debug_family_var_map[6];
  real_T c75_distance_threshold;
  real_T c75_nargin = 2.0;
  real_T c75_nargout = 1.0;
  real_T c75_go;
  real_T *c75_b_distance;
  real_T *c75_b_go;
  real_T *c75_b_startstop;
  boolean_T guard1 = false;
  c75_b_startstop = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c75_b_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c75_b_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c75_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c75_b_distance, 0U);
  chartInstance->c75_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c75_sfEvent);
  c75_hoistedGlobal = *c75_b_distance;
  c75_b_hoistedGlobal = *c75_b_startstop;
  c75_distance = c75_hoistedGlobal;
  c75_startstop = c75_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c75_debug_family_names,
    c75_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c75_distance_threshold, 0U,
    c75_sf_marshallOut, c75_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c75_nargin, 1U, c75_sf_marshallOut,
    c75_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c75_nargout, 2U, c75_sf_marshallOut,
    c75_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c75_distance, 3U, c75_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c75_startstop, 4U, c75_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c75_go, 5U, c75_sf_marshallOut,
    c75_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c75_sfEvent, 15);
  c75_distance_threshold = 400.0;
  _SFD_EML_CALL(0U, chartInstance->c75_sfEvent, 16);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c75_distance < c75_distance_threshold)) {
    guard1 = true;
  } else if (CV_EML_COND(0, 1, 1, c75_startstop == 0.0)) {
    guard1 = true;
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c75_sfEvent, 19);
    c75_go = 1.0;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c75_sfEvent, 17);
    c75_go = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c75_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  *c75_b_go = c75_go;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c75_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c75_b_go, 1U);
  _SFD_DATA_RANGE_CHECK(*c75_b_startstop, 2U);
}

static void initSimStructsc75_ICARO3_Onda_bipe_controllonostro40cm
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c75_machineNumber, uint32_T
  c75_chartNumber, uint32_T c75_instanceNumber)
{
  (void)c75_machineNumber;
  (void)c75_chartNumber;
  (void)c75_instanceNumber;
}

static const mxArray *c75_sf_marshallOut(void *chartInstanceVoid, void
  *c75_inData)
{
  const mxArray *c75_mxArrayOutData = NULL;
  real_T c75_u;
  const mxArray *c75_y = NULL;
  SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c75_mxArrayOutData = NULL;
  c75_u = *(real_T *)c75_inData;
  c75_y = NULL;
  sf_mex_assign(&c75_y, sf_mex_create("y", &c75_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c75_mxArrayOutData, c75_y, false);
  return c75_mxArrayOutData;
}

static real_T c75_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_go, const char_T *c75_identifier)
{
  real_T c75_y;
  emlrtMsgIdentifier c75_thisId;
  c75_thisId.fIdentifier = c75_identifier;
  c75_thisId.fParent = NULL;
  c75_y = c75_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c75_go), &c75_thisId);
  sf_mex_destroy(&c75_go);
  return c75_y;
}

static real_T c75_b_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId)
{
  real_T c75_y;
  real_T c75_d0;
  (void)chartInstance;
  sf_mex_import(c75_parentId, sf_mex_dup(c75_u), &c75_d0, 1, 0, 0U, 0, 0U, 0);
  c75_y = c75_d0;
  sf_mex_destroy(&c75_u);
  return c75_y;
}

static void c75_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c75_mxArrayInData, const char_T *c75_varName, void *c75_outData)
{
  const mxArray *c75_go;
  const char_T *c75_identifier;
  emlrtMsgIdentifier c75_thisId;
  real_T c75_y;
  SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c75_go = sf_mex_dup(c75_mxArrayInData);
  c75_identifier = c75_varName;
  c75_thisId.fIdentifier = c75_identifier;
  c75_thisId.fParent = NULL;
  c75_y = c75_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c75_go), &c75_thisId);
  sf_mex_destroy(&c75_go);
  *(real_T *)c75_outData = c75_y;
  sf_mex_destroy(&c75_mxArrayInData);
}

const mxArray
  *sf_c75_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c75_nameCaptureInfo = NULL;
  c75_nameCaptureInfo = NULL;
  sf_mex_assign(&c75_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c75_nameCaptureInfo;
}

static const mxArray *c75_b_sf_marshallOut(void *chartInstanceVoid, void
  *c75_inData)
{
  const mxArray *c75_mxArrayOutData = NULL;
  int32_T c75_u;
  const mxArray *c75_y = NULL;
  SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c75_mxArrayOutData = NULL;
  c75_u = *(int32_T *)c75_inData;
  c75_y = NULL;
  sf_mex_assign(&c75_y, sf_mex_create("y", &c75_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c75_mxArrayOutData, c75_y, false);
  return c75_mxArrayOutData;
}

static int32_T c75_c_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId)
{
  int32_T c75_y;
  int32_T c75_i0;
  (void)chartInstance;
  sf_mex_import(c75_parentId, sf_mex_dup(c75_u), &c75_i0, 1, 6, 0U, 0, 0U, 0);
  c75_y = c75_i0;
  sf_mex_destroy(&c75_u);
  return c75_y;
}

static void c75_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c75_mxArrayInData, const char_T *c75_varName, void *c75_outData)
{
  const mxArray *c75_b_sfEvent;
  const char_T *c75_identifier;
  emlrtMsgIdentifier c75_thisId;
  int32_T c75_y;
  SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    chartInstanceVoid;
  c75_b_sfEvent = sf_mex_dup(c75_mxArrayInData);
  c75_identifier = c75_varName;
  c75_thisId.fIdentifier = c75_identifier;
  c75_thisId.fParent = NULL;
  c75_y = c75_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c75_b_sfEvent),
    &c75_thisId);
  sf_mex_destroy(&c75_b_sfEvent);
  *(int32_T *)c75_outData = c75_y;
  sf_mex_destroy(&c75_mxArrayInData);
}

static uint8_T c75_d_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_b_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm,
   const char_T *c75_identifier)
{
  uint8_T c75_y;
  emlrtMsgIdentifier c75_thisId;
  c75_thisId.fIdentifier = c75_identifier;
  c75_thisId.fParent = NULL;
  c75_y = c75_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c75_b_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm), &c75_thisId);
  sf_mex_destroy(&c75_b_is_active_c75_ICARO3_Onda_bipe_controllonostro40cm);
  return c75_y;
}

static uint8_T c75_e_emlrt_marshallIn
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance,
   const mxArray *c75_u, const emlrtMsgIdentifier *c75_parentId)
{
  uint8_T c75_y;
  uint8_T c75_u0;
  (void)chartInstance;
  sf_mex_import(c75_parentId, sf_mex_dup(c75_u), &c75_u0, 1, 3, 0U, 0, 0U, 0);
  c75_y = c75_u0;
  sf_mex_destroy(&c75_u);
  return c75_y;
}

static void init_dsm_address_info
  (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance)
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

void sf_c75_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3160094514U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4123969537U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1962686171U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2172761708U);
}

mxArray *sf_c75_ICARO3_Onda_bipe_controllonostro40cm_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5ZGGH8vgbhNXrB26iWGsiH");
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

mxArray *sf_c75_ICARO3_Onda_bipe_controllonostro40cm_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c75_ICARO3_Onda_bipe_controllonostro40cm_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c75_ICARO3_Onda_bipe_controllonostro40cm(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"go\",},{M[8],M[0],T\"is_active_c75_ICARO3_Onda_bipe_controllonostro40cm\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c75_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_Onda_bipe_controllonostro40cmMachineNumber_,
           75,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"distance");
          _SFD_SET_DATA_PROPS(1,2,0,1,"go");
          _SFD_SET_DATA_PROPS(2,1,1,0,"startstop");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,634);
        _SFD_CV_INIT_EML_IF(0,1,0,545,599,612,633);

        {
          static int condStart[] = { 550, 585 };

          static int condEnd[] = { 579, 597 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,549,598,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c75_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c75_sf_marshallOut,(MexInFcnForType)c75_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c75_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c75_distance;
          real_T *c75_go;
          real_T *c75_startstop;
          c75_startstop = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c75_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c75_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c75_distance);
          _SFD_SET_DATA_VALUE_PTR(1U, c75_go);
          _SFD_SET_DATA_VALUE_PTR(2U, c75_startstop);
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
  return "iCXd3d0VY3BklwGIk7S2fC";
}

static void sf_opaque_initialize_c75_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
  initialize_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c75_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  enable_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c75_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  disable_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c75_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  sf_gateway_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c75_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
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

extern void sf_internal_set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
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
    sf_get_sim_state_info_c75_ICARO3_Onda_bipe_controllonostro40cm();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm(SimStruct* S)
{
  return sf_internal_get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm(S);
}

static void sf_opaque_set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm(S, st);
}

static void sf_opaque_terminate_c75_ICARO3_Onda_bipe_controllonostro40cm(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    }

    finalize_c75_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
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
  initSimStructsc75_ICARO3_Onda_bipe_controllonostro40cm
    ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c75_ICARO3_Onda_bipe_controllonostro40cm
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
    initialize_params_c75_ICARO3_Onda_bipe_controllonostro40cm
      ((SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c75_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *
  S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_Onda_bipe_controllonostro40cm_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      75);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,75,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,75,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,75);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,75,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,75,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,75);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(235406026U));
  ssSetChecksum1(S,(2152247604U));
  ssSetChecksum2(S,(1021457866U));
  ssSetChecksum3(S,(991953677U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c75_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c75_ICARO3_Onda_bipe_controllonostro40cm(SimStruct *S)
{
  SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct *)
    utMalloc(sizeof(SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc75_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c75_ICARO3_Onda_bipe_controllonostro40cm;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c75_ICARO3_Onda_bipe_controllonostro40cm;
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

void c75_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c75_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c75_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c75_ICARO3_Onda_bipe_controllonostro40cm(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c75_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
