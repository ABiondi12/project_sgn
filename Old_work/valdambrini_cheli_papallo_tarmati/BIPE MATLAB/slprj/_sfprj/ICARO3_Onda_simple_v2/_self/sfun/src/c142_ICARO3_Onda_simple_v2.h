#ifndef __c142_ICARO3_Onda_simple_v2_h__
#define __c142_ICARO3_Onda_simple_v2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc142_ICARO3_Onda_simple_v2InstanceStruct
#define typedef_SFc142_ICARO3_Onda_simple_v2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c142_sfEvent;
  boolean_T c142_isStable;
  boolean_T c142_doneDoubleBufferReInit;
  uint8_T c142_is_active_c142_ICARO3_Onda_simple_v2;
} SFc142_ICARO3_Onda_simple_v2InstanceStruct;

#endif                                 /*typedef_SFc142_ICARO3_Onda_simple_v2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c142_ICARO3_Onda_simple_v2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c142_ICARO3_Onda_simple_v2_get_check_sum(mxArray *plhs[]);
extern void c142_ICARO3_Onda_simple_v2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
