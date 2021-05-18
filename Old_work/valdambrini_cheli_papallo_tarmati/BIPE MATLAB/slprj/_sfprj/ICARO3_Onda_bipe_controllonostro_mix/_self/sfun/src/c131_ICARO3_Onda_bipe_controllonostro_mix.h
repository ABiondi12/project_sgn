#ifndef __c131_ICARO3_Onda_bipe_controllonostro_mix_h__
#define __c131_ICARO3_Onda_bipe_controllonostro_mix_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc131_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct
#define typedef_SFc131_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c131_sfEvent;
  boolean_T c131_isStable;
  boolean_T c131_doneDoubleBufferReInit;
  uint8_T c131_is_active_c131_ICARO3_Onda_bipe_controllonostro_mix;
} SFc131_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct;

#endif                                 /*typedef_SFc131_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c131_ICARO3_Onda_bipe_controllonostro_mix_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c131_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(mxArray
  *plhs[]);
extern void c131_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
