#ifndef __c98_ICARO3_Onda_bipe_controllonostro_mix_h__
#define __c98_ICARO3_Onda_bipe_controllonostro_mix_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc98_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct
#define typedef_SFc98_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c98_sfEvent;
  boolean_T c98_isStable;
  boolean_T c98_doneDoubleBufferReInit;
  uint8_T c98_is_active_c98_ICARO3_Onda_bipe_controllonostro_mix;
} SFc98_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct;

#endif                                 /*typedef_SFc98_ICARO3_Onda_bipe_controllonostro_mixInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c98_ICARO3_Onda_bipe_controllonostro_mix_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c98_ICARO3_Onda_bipe_controllonostro_mix_get_check_sum(mxArray
  *plhs[]);
extern void c98_ICARO3_Onda_bipe_controllonostro_mix_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
