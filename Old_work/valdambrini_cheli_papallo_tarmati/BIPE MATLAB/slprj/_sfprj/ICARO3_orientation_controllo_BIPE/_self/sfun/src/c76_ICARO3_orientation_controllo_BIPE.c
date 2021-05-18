/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ICARO3_orientation_controllo_BIPE_sfun.h"
#include "c76_ICARO3_orientation_controllo_BIPE.h"
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
static const char * c76_debug_family_names[6] = { "distance_threshold", "nargin",
  "nargout", "distance", "startstop", "go" };

/* Function Declarations */
static void initialize_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initialize_params_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void enable_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void disable_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void c76_update_debugger_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void set_sim_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_st);
static void finalize_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void sf_gateway_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void initSimStructsc76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c76_machineNumber, uint32_T
  c76_chartNumber, uint32_T c76_instanceNumber);
static const mxArray *c76_sf_marshallOut(void *chartInstanceVoid, void
  *c76_inData);
static real_T c76_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_go, const char_T *c76_identifier);
static real_T c76_b_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId);
static void c76_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c76_mxArrayInData, const char_T *c76_varName, void *c76_outData);
static const mxArray *c76_b_sf_marshallOut(void *chartInstanceVoid, void
  *c76_inData);
static int32_T c76_c_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId);
static void c76_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c76_mxArrayInData, const char_T *c76_varName, void *c76_outData);
static uint8_T c76_d_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_b_is_active_c76_ICARO3_orientation_controllo_BIPE, const char_T *
   c76_identifier);
static uint8_T c76_e_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId);
static void init_dsm_address_info
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  chartInstance->c76_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c76_is_active_c76_ICARO3_orientation_controllo_BIPE = 0U;
}

static void initialize_params_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c76_update_debugger_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  const mxArray *c76_st;
  const mxArray *c76_y = NULL;
  real_T c76_hoistedGlobal;
  real_T c76_u;
  const mxArray *c76_b_y = NULL;
  uint8_T c76_b_hoistedGlobal;
  uint8_T c76_b_u;
  const mxArray *c76_c_y = NULL;
  real_T *c76_go;
  c76_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c76_st = NULL;
  c76_st = NULL;
  c76_y = NULL;
  sf_mex_assign(&c76_y, sf_mex_createcellmatrix(2, 1), false);
  c76_hoistedGlobal = *c76_go;
  c76_u = c76_hoistedGlobal;
  c76_b_y = NULL;
  sf_mex_assign(&c76_b_y, sf_mex_create("y", &c76_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c76_y, 0, c76_b_y);
  c76_b_hoistedGlobal =
    chartInstance->c76_is_active_c76_ICARO3_orientation_controllo_BIPE;
  c76_b_u = c76_b_hoistedGlobal;
  c76_c_y = NULL;
  sf_mex_assign(&c76_c_y, sf_mex_create("y", &c76_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c76_y, 1, c76_c_y);
  sf_mex_assign(&c76_st, c76_y, false);
  return c76_st;
}

static void set_sim_state_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_st)
{
  const mxArray *c76_u;
  real_T *c76_go;
  c76_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c76_doneDoubleBufferReInit = true;
  c76_u = sf_mex_dup(c76_st);
  *c76_go = c76_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c76_u,
    0)), "go");
  chartInstance->c76_is_active_c76_ICARO3_orientation_controllo_BIPE =
    c76_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c76_u, 1)),
    "is_active_c76_ICARO3_orientation_controllo_BIPE");
  sf_mex_destroy(&c76_u);
  c76_update_debugger_state_c76_ICARO3_orientation_controllo_BIPE(chartInstance);
  sf_mex_destroy(&c76_st);
}

static void finalize_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  real_T c76_hoistedGlobal;
  real_T c76_b_hoistedGlobal;
  real_T c76_distance;
  real_T c76_startstop;
  uint32_T c76_debug_family_var_map[6];
  real_T c76_distance_threshold;
  real_T c76_nargin = 2.0;
  real_T c76_nargout = 1.0;
  real_T c76_go;
  real_T *c76_b_distance;
  real_T *c76_b_go;
  real_T *c76_b_startstop;
  boolean_T guard1 = false;
  c76_b_startstop = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c76_b_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c76_b_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c76_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c76_b_distance, 0U);
  chartInstance->c76_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c76_sfEvent);
  c76_hoistedGlobal = *c76_b_distance;
  c76_b_hoistedGlobal = *c76_b_startstop;
  c76_distance = c76_hoistedGlobal;
  c76_startstop = c76_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c76_debug_family_names,
    c76_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c76_distance_threshold, 0U,
    c76_sf_marshallOut, c76_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c76_nargin, 1U, c76_sf_marshallOut,
    c76_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c76_nargout, 2U, c76_sf_marshallOut,
    c76_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c76_distance, 3U, c76_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c76_startstop, 4U, c76_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c76_go, 5U, c76_sf_marshallOut,
    c76_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c76_sfEvent, 14);
  c76_distance_threshold = 250.0;
  _SFD_EML_CALL(0U, chartInstance->c76_sfEvent, 15);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c76_distance < c76_distance_threshold)) {
    guard1 = true;
  } else if (CV_EML_COND(0, 1, 1, c76_startstop == 0.0)) {
    guard1 = true;
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c76_sfEvent, 18);
    c76_go = 1.0;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c76_sfEvent, 16);
    c76_go = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c76_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c76_b_go = c76_go;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c76_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ICARO3_orientation_controllo_BIPEMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c76_b_go, 1U);
  _SFD_DATA_RANGE_CHECK(*c76_b_startstop, 2U);
}

static void initSimStructsc76_ICARO3_orientation_controllo_BIPE
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c76_machineNumber, uint32_T
  c76_chartNumber, uint32_T c76_instanceNumber)
{
  (void)c76_machineNumber;
  (void)c76_chartNumber;
  (void)c76_instanceNumber;
}

static const mxArray *c76_sf_marshallOut(void *chartInstanceVoid, void
  *c76_inData)
{
  const mxArray *c76_mxArrayOutData = NULL;
  real_T c76_u;
  const mxArray *c76_y = NULL;
  SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c76_mxArrayOutData = NULL;
  c76_u = *(real_T *)c76_inData;
  c76_y = NULL;
  sf_mex_assign(&c76_y, sf_mex_create("y", &c76_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c76_mxArrayOutData, c76_y, false);
  return c76_mxArrayOutData;
}

static real_T c76_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_go, const char_T *c76_identifier)
{
  real_T c76_y;
  emlrtMsgIdentifier c76_thisId;
  c76_thisId.fIdentifier = c76_identifier;
  c76_thisId.fParent = NULL;
  c76_y = c76_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c76_go), &c76_thisId);
  sf_mex_destroy(&c76_go);
  return c76_y;
}

static real_T c76_b_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId)
{
  real_T c76_y;
  real_T c76_d0;
  (void)chartInstance;
  sf_mex_import(c76_parentId, sf_mex_dup(c76_u), &c76_d0, 1, 0, 0U, 0, 0U, 0);
  c76_y = c76_d0;
  sf_mex_destroy(&c76_u);
  return c76_y;
}

static void c76_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c76_mxArrayInData, const char_T *c76_varName, void *c76_outData)
{
  const mxArray *c76_go;
  const char_T *c76_identifier;
  emlrtMsgIdentifier c76_thisId;
  real_T c76_y;
  SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c76_go = sf_mex_dup(c76_mxArrayInData);
  c76_identifier = c76_varName;
  c76_thisId.fIdentifier = c76_identifier;
  c76_thisId.fParent = NULL;
  c76_y = c76_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c76_go), &c76_thisId);
  sf_mex_destroy(&c76_go);
  *(real_T *)c76_outData = c76_y;
  sf_mex_destroy(&c76_mxArrayInData);
}

const mxArray
  *sf_c76_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info(void)
{
  const mxArray *c76_nameCaptureInfo = NULL;
  c76_nameCaptureInfo = NULL;
  sf_mex_assign(&c76_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c76_nameCaptureInfo;
}

static const mxArray *c76_b_sf_marshallOut(void *chartInstanceVoid, void
  *c76_inData)
{
  const mxArray *c76_mxArrayOutData = NULL;
  int32_T c76_u;
  const mxArray *c76_y = NULL;
  SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c76_mxArrayOutData = NULL;
  c76_u = *(int32_T *)c76_inData;
  c76_y = NULL;
  sf_mex_assign(&c76_y, sf_mex_create("y", &c76_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c76_mxArrayOutData, c76_y, false);
  return c76_mxArrayOutData;
}

static int32_T c76_c_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId)
{
  int32_T c76_y;
  int32_T c76_i0;
  (void)chartInstance;
  sf_mex_import(c76_parentId, sf_mex_dup(c76_u), &c76_i0, 1, 6, 0U, 0, 0U, 0);
  c76_y = c76_i0;
  sf_mex_destroy(&c76_u);
  return c76_y;
}

static void c76_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c76_mxArrayInData, const char_T *c76_varName, void *c76_outData)
{
  const mxArray *c76_b_sfEvent;
  const char_T *c76_identifier;
  emlrtMsgIdentifier c76_thisId;
  int32_T c76_y;
  SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    chartInstanceVoid;
  c76_b_sfEvent = sf_mex_dup(c76_mxArrayInData);
  c76_identifier = c76_varName;
  c76_thisId.fIdentifier = c76_identifier;
  c76_thisId.fParent = NULL;
  c76_y = c76_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c76_b_sfEvent),
    &c76_thisId);
  sf_mex_destroy(&c76_b_sfEvent);
  *(int32_T *)c76_outData = c76_y;
  sf_mex_destroy(&c76_mxArrayInData);
}

static uint8_T c76_d_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_b_is_active_c76_ICARO3_orientation_controllo_BIPE, const char_T *
   c76_identifier)
{
  uint8_T c76_y;
  emlrtMsgIdentifier c76_thisId;
  c76_thisId.fIdentifier = c76_identifier;
  c76_thisId.fParent = NULL;
  c76_y = c76_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c76_b_is_active_c76_ICARO3_orientation_controllo_BIPE), &c76_thisId);
  sf_mex_destroy(&c76_b_is_active_c76_ICARO3_orientation_controllo_BIPE);
  return c76_y;
}

static uint8_T c76_e_emlrt_marshallIn
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance, const
   mxArray *c76_u, const emlrtMsgIdentifier *c76_parentId)
{
  uint8_T c76_y;
  uint8_T c76_u0;
  (void)chartInstance;
  sf_mex_import(c76_parentId, sf_mex_dup(c76_u), &c76_u0, 1, 3, 0U, 0, 0U, 0);
  c76_y = c76_u0;
  sf_mex_destroy(&c76_u);
  return c76_y;
}

static void init_dsm_address_info
  (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance)
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

void sf_c76_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1492873465U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2055930586U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2046917033U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(952846982U);
}

mxArray *sf_c76_ICARO3_orientation_controllo_BIPE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nuzanF4wjRbyls39aNfu1E");
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

mxArray *sf_c76_ICARO3_orientation_controllo_BIPE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c76_ICARO3_orientation_controllo_BIPE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c76_ICARO3_orientation_controllo_BIPE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"go\",},{M[8],M[0],T\"is_active_c76_ICARO3_orientation_controllo_BIPE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c76_ICARO3_orientation_controllo_BIPE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ICARO3_orientation_controllo_BIPEMachineNumber_,
           76,
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
          (MexFcnForType)c76_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c76_sf_marshallOut,(MexInFcnForType)c76_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c76_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c76_distance;
          real_T *c76_go;
          real_T *c76_startstop;
          c76_startstop = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c76_go = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c76_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c76_distance);
          _SFD_SET_DATA_VALUE_PTR(1U, c76_go);
          _SFD_SET_DATA_VALUE_PTR(2U, c76_startstop);
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
  return "O8OA0czzYpsc75gPboV9MH";
}

static void sf_opaque_initialize_c76_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
  initialize_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c76_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  enable_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c76_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  disable_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c76_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  sf_gateway_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c76_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c76_ICARO3_orientation_controllo_BIPE();/* state var info */
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

extern void sf_internal_set_sim_state_c76_ICARO3_orientation_controllo_BIPE
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
    sf_get_sim_state_info_c76_ICARO3_orientation_controllo_BIPE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c76_ICARO3_orientation_controllo_BIPE(SimStruct* S)
{
  return sf_internal_get_sim_state_c76_ICARO3_orientation_controllo_BIPE(S);
}

static void sf_opaque_set_sim_state_c76_ICARO3_orientation_controllo_BIPE
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c76_ICARO3_orientation_controllo_BIPE(S, st);
}

static void sf_opaque_terminate_c76_ICARO3_orientation_controllo_BIPE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ICARO3_orientation_controllo_BIPE_optimization_info();
    }

    finalize_c76_ICARO3_orientation_controllo_BIPE
      ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc76_ICARO3_orientation_controllo_BIPE
    ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c76_ICARO3_orientation_controllo_BIPE(SimStruct
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
    initialize_params_c76_ICARO3_orientation_controllo_BIPE
      ((SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c76_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ICARO3_orientation_controllo_BIPE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      76);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,76,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,76,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,76);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,76,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,76,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,76);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3204627171U));
  ssSetChecksum1(S,(1716385487U));
  ssSetChecksum2(S,(1646635279U));
  ssSetChecksum3(S,(2784477453U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c76_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c76_ICARO3_orientation_controllo_BIPE(SimStruct *S)
{
  SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct *)
    utMalloc(sizeof(SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc76_ICARO3_orientation_controllo_BIPEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c76_ICARO3_orientation_controllo_BIPE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c76_ICARO3_orientation_controllo_BIPE;
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

void c76_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c76_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c76_ICARO3_orientation_controllo_BIPE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c76_ICARO3_orientation_controllo_BIPE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c76_ICARO3_orientation_controllo_BIPE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
