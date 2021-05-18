#ifndef __c140_ICARO3_Onda_simple_v2_media_fun_h__
#define __c140_ICARO3_Onda_simple_v2_media_fun_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc140_ICARO3_Onda_simple_v2_media_funInstanceStruct
#define typedef_SFc140_ICARO3_Onda_simple_v2_media_funInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c140_sfEvent;
  boolean_T c140_isStable;
  boolean_T c140_doneDoubleBufferReInit;
  uint8_T c140_is_active_c140_ICARO3_Onda_simple_v2_media_fun;
} SFc140_ICARO3_Onda_simple_v2_media_funInstanceStruct;

#endif                                 /*typedef_SFc140_ICARO3_Onda_simple_v2_media_funInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c140_ICARO3_Onda_simple_v2_media_fun_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c140_ICARO3_Onda_simple_v2_media_fun_get_check_sum(mxArray *plhs[]);
extern void c140_ICARO3_Onda_simple_v2_media_fun_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
