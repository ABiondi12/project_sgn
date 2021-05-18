#ifndef __c4_ICARO_III_debug_tel_tag_h__
#define __c4_ICARO_III_debug_tel_tag_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_ICARO_III_debug_tel_tagInstanceStruct
#define typedef_SFc4_ICARO_III_debug_tel_tagInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_ICARO_III_debug_tel_tag;
} SFc4_ICARO_III_debug_tel_tagInstanceStruct;

#endif                                 /*typedef_SFc4_ICARO_III_debug_tel_tagInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_ICARO_III_debug_tel_tag_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_ICARO_III_debug_tel_tag_get_check_sum(mxArray *plhs[]);
extern void c4_ICARO_III_debug_tel_tag_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
