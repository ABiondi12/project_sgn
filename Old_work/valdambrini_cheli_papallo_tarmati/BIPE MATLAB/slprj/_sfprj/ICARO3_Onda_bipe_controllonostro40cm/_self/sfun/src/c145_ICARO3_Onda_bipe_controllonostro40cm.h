#ifndef __c145_ICARO3_Onda_bipe_controllonostro40cm_h__
#define __c145_ICARO3_Onda_bipe_controllonostro40cm_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc145_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct
#define typedef_SFc145_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c145_sfEvent;
  boolean_T c145_isStable;
  boolean_T c145_doneDoubleBufferReInit;
  uint8_T c145_is_active_c145_ICARO3_Onda_bipe_controllonostro40cm;
} SFc145_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct;

#endif                                 /*typedef_SFc145_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c145_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c145_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray
  *plhs[]);
extern void c145_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
