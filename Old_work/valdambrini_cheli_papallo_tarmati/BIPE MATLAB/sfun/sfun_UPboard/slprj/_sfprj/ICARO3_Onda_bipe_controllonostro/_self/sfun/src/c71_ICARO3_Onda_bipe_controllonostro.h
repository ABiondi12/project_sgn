#ifndef __c71_ICARO3_Onda_bipe_controllonostro_h__
#define __c71_ICARO3_Onda_bipe_controllonostro_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc71_ICARO3_Onda_bipe_controllonostroInstanceStruct
#define typedef_SFc71_ICARO3_Onda_bipe_controllonostroInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c71_sfEvent;
  boolean_T c71_isStable;
  boolean_T c71_doneDoubleBufferReInit;
  uint8_T c71_is_active_c71_ICARO3_Onda_bipe_controllonostro;
  real32_T c71_Kp;
  real32_T c71_Ki;
  real32_T c71_T;
  real_T c71_ini;
  boolean_T c71_ini_not_empty;
} SFc71_ICARO3_Onda_bipe_controllonostroInstanceStruct;

#endif                                 /*typedef_SFc71_ICARO3_Onda_bipe_controllonostroInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c71_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c71_ICARO3_Onda_bipe_controllonostro_get_check_sum(mxArray *plhs[]);
extern void c71_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
