/* Include files */

#include "ICARO_III_debug_tel_tag_sfun.h"
#include "ICARO_III_debug_tel_tag_sfun_debug_macros.h"
#include "c71_ICARO_III_debug_tel_tag.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ICARO_III_debug_tel_tagMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ICARO_III_debug_tel_tag_initializer(void)
{
}

void ICARO_III_debug_tel_tag_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ICARO_III_debug_tel_tag_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==71) {
    c71_ICARO_III_debug_tel_tag_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ICARO_III_debug_tel_tag_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2751769644U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1793614963U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1060490277U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1707328506U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1893340192U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2326071057U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1213915825U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1223564165U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 71:
        {
          extern void sf_c71_ICARO_III_debug_tel_tag_get_check_sum(mxArray *
            plhs[]);
          sf_c71_ICARO_III_debug_tel_tag_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2863243922U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1116608874U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3072423689U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2720754U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3040063269U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1243356972U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2125670933U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(754777974U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ICARO_III_debug_tel_tag_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 71:
      {
        if (strcmp(aiChksum, "EAR6u4XKLcHKWyROoirOe") == 0) {
          extern mxArray
            *sf_c71_ICARO_III_debug_tel_tag_get_autoinheritance_info(void);
          plhs[0] = sf_c71_ICARO_III_debug_tel_tag_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ICARO_III_debug_tel_tag_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 71:
      {
        extern const mxArray
          *sf_c71_ICARO_III_debug_tel_tag_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c71_ICARO_III_debug_tel_tag_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ICARO_III_debug_tel_tag_third_party_uses_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 71:
      {
        if (strcmp(tpChksum, "Ge0PaMVbfZmsMZEvC1i9ZC") == 0) {
          extern mxArray *sf_c71_ICARO_III_debug_tel_tag_third_party_uses_info
            (void);
          plhs[0] = sf_c71_ICARO_III_debug_tel_tag_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_ICARO_III_debug_tel_tag_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 71:
      {
        if (strcmp(tpChksum, "Ge0PaMVbfZmsMZEvC1i9ZC") == 0) {
          extern mxArray
            *sf_c71_ICARO_III_debug_tel_tag_updateBuildInfo_args_info(void);
          plhs[0] = sf_c71_ICARO_III_debug_tel_tag_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ICARO_III_debug_tel_tag_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _ICARO_III_debug_tel_tagMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"ICARO_III_debug_tel_tag","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ICARO_III_debug_tel_tagMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ICARO_III_debug_tel_tagMachineNumber_,0);
}

void ICARO_III_debug_tel_tag_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ICARO_III_debug_tel_tag_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ICARO_III_debug_tel_tag", "ICARO_III_debug_tel_tag");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ICARO_III_debug_tel_tag_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
