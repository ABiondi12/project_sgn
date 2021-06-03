#ifndef __c126_ICARO3_Onda_bipe_controllonostro_mix_h__
#define __c126_ICARO3_Onda_bipe_controllonostro_mix_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc126_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct
#define typedef_SFc126_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c126_sfEvent;
  boolean_T c126_isStable;
  boolean_T c126_doneDoubleBufferReInit;
  uint8_T c126_is_active_c126_ICARO3_Onda_bipe_controllonostro_mix;
} SFc126_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct;

#endif                                 /*typedef_SFc126_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c126_ICARO3_Onda_bipe_controllonostro_mix_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c126_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(mxArray
  *plhs[]);
extern void c126_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif