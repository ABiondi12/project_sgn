#ifndef __c71_ICARO3_Onda_simple_v2_h__
#define __c71_ICARO3_Onda_simple_v2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc71_ICARO3_Onda_simple_v2InstanceStruct
#define typedef_SFc71_ICARO3_Onda_simple_v2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c71_sfEvent;
  boolean_T c71_isStable;
  boolean_T c71_doneDoubleBufferReInit;
  uint8_T c71_is_active_c71_ICARO3_Onda_simple_v2;
  real32_T c71_Kp;
  real32_T c71_Ki;
  real32_T c71_T;
  real_T c71_ini;
  boolean_T c71_ini_not_empty;
} SFc71_ICARO3_Onda_simple_v2InstanceStruct;

#endif                                 /*typedef_SFc71_ICARO3_Onda_simple_v2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c71_ICARO3_Onda_simple_v2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c71_ICARO3_Onda_simple_v2_get_check_sum(mxArray *plhs[]);
extern void c71_ICARO3_Onda_simple_v2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
