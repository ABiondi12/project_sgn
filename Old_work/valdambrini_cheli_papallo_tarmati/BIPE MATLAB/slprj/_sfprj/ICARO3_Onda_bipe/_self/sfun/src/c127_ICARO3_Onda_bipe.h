#ifndef __c127_ICARO3_Onda_bipe_h__
#define __c127_ICARO3_Onda_bipe_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc127_ICARO3_Onda_bipeInstanceStruct
#define typedef_SFc127_ICARO3_Onda_bipeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c127_sfEvent;
  boolean_T c127_isStable;
  boolean_T c127_doneDoubleBufferReInit;
  uint8_T c127_is_active_c127_ICARO3_Onda_bipe;
} SFc127_ICARO3_Onda_bipeInstanceStruct;

#endif                                 /*typedef_SFc127_ICARO3_Onda_bipeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c127_ICARO3_Onda_bipe_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c127_ICARO3_Onda_bipe_get_check_sum(mxArray *plhs[]);
extern void c127_ICARO3_Onda_bipe_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
