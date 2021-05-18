#ifndef __c129_ICARO3_Onda_bipe_yaw_h__
#define __c129_ICARO3_Onda_bipe_yaw_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc129_ICARO3_Onda_bipe_yawInstanceStruct
#define typedef_SFc129_ICARO3_Onda_bipe_yawInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c129_sfEvent;
  boolean_T c129_isStable;
  boolean_T c129_doneDoubleBufferReInit;
  uint8_T c129_is_active_c129_ICARO3_Onda_bipe_yaw;
} SFc129_ICARO3_Onda_bipe_yawInstanceStruct;

#endif                                 /*typedef_SFc129_ICARO3_Onda_bipe_yawInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c129_ICARO3_Onda_bipe_yaw_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c129_ICARO3_Onda_bipe_yaw_get_check_sum(mxArray *plhs[]);
extern void c129_ICARO3_Onda_bipe_yaw_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
