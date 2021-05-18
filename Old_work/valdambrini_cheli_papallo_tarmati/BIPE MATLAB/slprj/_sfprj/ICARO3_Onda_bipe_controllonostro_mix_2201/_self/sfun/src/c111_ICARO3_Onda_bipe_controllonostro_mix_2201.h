#ifndef __c111_ICARO3_Onda_bipe_controllonostro_mix_2201_h__
#define __c111_ICARO3_Onda_bipe_controllonostro_mix_2201_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc111_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct
#define typedef_SFc111_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c111_sfEvent;
  boolean_T c111_isStable;
  boolean_T c111_doneDoubleBufferReInit;
  uint8_T c111_is_active_c111_ICARO3_Onda_bipe_controllonostro_mix_2201;
} SFc111_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct;

#endif                                 /*typedef_SFc111_ICARO3_Onda_bipe_controllonostro_mix_2201InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c111_ICARO3_Onda_bipe_controllonostro_mix_2201_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c111_ICARO3_Onda_bipe_controllonostro_mix_2201_get_check_sum
  (mxArray *plhs[]);
extern void c111_ICARO3_Onda_bipe_controllonostro_mix_2201_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
