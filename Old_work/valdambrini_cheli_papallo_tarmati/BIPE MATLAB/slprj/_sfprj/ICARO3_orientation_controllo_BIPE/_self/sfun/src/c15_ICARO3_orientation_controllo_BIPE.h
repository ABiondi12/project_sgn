#ifndef __c15_ICARO3_orientation_controllo_BIPE_h__
#define __c15_ICARO3_orientation_controllo_BIPE_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_ICARO3_orientation_controllo_BIPEInstanceStruct
#define typedef_SFc15_ICARO3_orientation_controllo_BIPEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_ICARO3_orientation_controllo_BIPE;
  real_T c15_THROTTLE_IDX;
  real_T c15_ROLL_IDX;
  real_T c15_PITCH_IDX;
  real_T c15_YAW_IDX;
  real_T c15_THROTTLE_DOWN;
  real_T c15_ROLL_MID;
  real_T c15_PITCH_MID;
  real_T c15_YAW_MID;
  real_T c15_INV_THROTTLE_RANGE;
  real_T c15_INV_ROLL_RANGE;
  real_T c15_INV_PITCH_RANGE;
  real_T c15_INV_YAW_RANGE;
  real_T c15_THROTTLE_LOW_THRES;
} SFc15_ICARO3_orientation_controllo_BIPEInstanceStruct;

#endif                                 /*typedef_SFc15_ICARO3_orientation_controllo_BIPEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray *
  plhs[]);
extern void c15_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
