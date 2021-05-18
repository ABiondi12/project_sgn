#ifndef __c162_ICARO3_Onda_simple_v2_media_fun_h__
#define __c162_ICARO3_Onda_simple_v2_media_fun_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc162_ICARO3_Onda_simple_v2_media_funInstanceStruct
#define typedef_SFc162_ICARO3_Onda_simple_v2_media_funInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c162_sfEvent;
  boolean_T c162_isStable;
  boolean_T c162_doneDoubleBufferReInit;
  uint8_T c162_is_active_c162_ICARO3_Onda_simple_v2_media_fun;
  real_T c162_tag_old[100];
  boolean_T c162_tag_old_not_empty;
  real_T c162_tag_new[100];
  boolean_T c162_tag_new_not_empty;
} SFc162_ICARO3_Onda_simple_v2_media_funInstanceStruct;

#endif                                 /*typedef_SFc162_ICARO3_Onda_simple_v2_media_funInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c162_ICARO3_Onda_simple_v2_media_fun_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c162_ICARO3_Onda_simple_v2_media_fun_get_check_sum(mxArray *plhs[]);
extern void c162_ICARO3_Onda_simple_v2_media_fun_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
