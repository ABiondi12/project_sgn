#ifndef __c103_ICARO3_orientation_controllo_BIPE_h__
#define __c103_ICARO3_orientation_controllo_BIPE_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc103_ICARO3_orientation_controllo_BIPEInstanceStruct
#define typedef_SFc103_ICARO3_orientation_controllo_BIPEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c103_sfEvent;
  boolean_T c103_isStable;
  boolean_T c103_doneDoubleBufferReInit;
  uint8_T c103_is_active_c103_ICARO3_orientation_controllo_BIPE;
} SFc103_ICARO3_orientation_controllo_BIPEInstanceStruct;

#endif                                 /*typedef_SFc103_ICARO3_orientation_controllo_BIPEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c103_ICARO3_orientation_controllo_BIPE_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c103_ICARO3_orientation_controllo_BIPE_get_check_sum(mxArray
  *plhs[]);
extern void c103_ICARO3_orientation_controllo_BIPE_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
