#ifndef __c107_ICARO3_Onda_bipe_controllonostro_h__
#define __c107_ICARO3_Onda_bipe_controllonostro_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc107_ICARO3_Onda_bipe_controllonostroInstanceStruct
#define typedef_SFc107_ICARO3_Onda_bipe_controllonostroInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c107_sfEvent;
  boolean_T c107_isStable;
  boolean_T c107_doneDoubleBufferReInit;
  uint8_T c107_is_active_c107_ICARO3_Onda_bipe_controllonostro;
} SFc107_ICARO3_Onda_bipe_controllonostroInstanceStruct;

#endif                                 /*typedef_SFc107_ICARO3_Onda_bipe_controllonostroInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c107_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c107_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *
  plhs[]);
extern void c107_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
