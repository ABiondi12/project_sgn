#ifndef __c105_ICARO3_Onda_bipe_yaw_h__
#define __c105_ICARO3_Onda_bipe_yaw_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc105_ICARO3_Onda_bipe_yawInstanceStruct
#define typedef_SFc105_ICARO3_Onda_bipe_yawInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c105_sfEvent;
  boolean_T c105_isStable;
  boolean_T c105_doneDoubleBufferReInit;
  uint8_T c105_is_active_c105_ICARO3_Onda_bipe_yaw;
} SFc105_ICARO3_Onda_bipe_yawInstanceStruct;

#endif                                 /*typedef_SFc105_ICARO3_Onda_bipe_yawInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c105_ICARO3_Onda_bipe_yaw_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c105_ICARO3_Onda_bipe_yaw_get_check_sum(mxArray *plhs[]);
extern void c105_ICARO3_Onda_bipe_yaw_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
