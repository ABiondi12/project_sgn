#ifndef __c128_ICARO3_Onda_bipe_controllonostro_mix_2201_h__
#define __c128_ICARO3_Onda_bipe_controllonostro_mix_2201_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc128_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
#define typedef_SFc128_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c128_sfEvent;
  boolean_T c128_isStable;
  boolean_T c128_doneDoubleBufferReInit;
  uint8_T c128_is_active_c128_ICARO3_Onda_bipe_controllonostro_mix_2201;
} SFc128_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct;

#endif                                 /*typedef_SFc128_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c128_ICARO3_Onda_bipe_controllonostro_mix_2201_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c128_ICARO3_Onda_bipe_controllonostro_mix_2201_get_check_sum
  (mxArray *plhs[]);
extern void c128_ICARO3_Onda_bipe_controllonostro_mix_2201_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
