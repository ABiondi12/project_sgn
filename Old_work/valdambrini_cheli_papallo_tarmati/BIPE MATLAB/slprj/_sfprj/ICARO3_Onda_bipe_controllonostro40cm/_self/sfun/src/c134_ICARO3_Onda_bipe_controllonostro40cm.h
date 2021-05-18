#ifndef __c134_ICARO3_Onda_bipe_controllonostro40cm_h__
#define __c134_ICARO3_Onda_bipe_controllonostro40cm_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc134_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct
#define typedef_SFc134_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c134_sfEvent;
  boolean_T c134_isStable;
  boolean_T c134_doneDoubleBufferReInit;
  uint8_T c134_is_active_c134_ICARO3_Onda_bipe_controllonostro40cm;
} SFc134_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct;

#endif                                 /*typedef_SFc134_ICARO3_Onda_bipe_controllonostro40cmInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c134_ICARO3_Onda_bipe_controllonostro40cm_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c134_ICARO3_Onda_bipe_controllonostro40cm_get_check_sum(mxArray
  *plhs[]);
extern void c134_ICARO3_Onda_bipe_controllonostro40cm_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
