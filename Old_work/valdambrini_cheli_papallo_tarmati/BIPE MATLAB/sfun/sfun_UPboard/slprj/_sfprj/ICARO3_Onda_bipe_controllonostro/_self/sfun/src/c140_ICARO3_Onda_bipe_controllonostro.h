#ifndef __c140_ICARO3_Onda_bipe_controllonostro_h__
#define __c140_ICARO3_Onda_bipe_controllonostro_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc140_ICARO3_Onda_bipe_controllonostroInstanceStruct
#define typedef_SFc140_ICARO3_Onda_bipe_controllonostroInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c140_sfEvent;
  boolean_T c140_isStable;
  boolean_T c140_doneDoubleBufferReInit;
  uint8_T c140_is_active_c140_ICARO3_Onda_bipe_controllonostro;
} SFc140_ICARO3_Onda_bipe_controllonostroInstanceStruct;

#endif                                 /*typedef_SFc140_ICARO3_Onda_bipe_controllonostroInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c140_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c140_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *
  plhs[]);
extern void c140_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
