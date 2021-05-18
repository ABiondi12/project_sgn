#define S_FUNCTION_NAME  sfun_raw_float_downlink
#define S_FUNCTION_LEVEL 2


//++++++++++++++++++++
//.h Simulink Includes
//++++++++++++++++++++
#include "simstruc.h"
//++++++++++++++++++++

// Tempo di campionamento
#define TS(S)  ssGetSFcnParam(S, 0)  
#define NPARAMS 1

//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//S-Function Implementation
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
    
    if (mxGetNumberOfElements(TS(S)) != 1 || mxGetPr(TS(S))[0] <= 0.0) {
          ssSetErrorStatus(S,"Invalid sample time specified");
          return;
      }
    
  }   
  #endif /* MDL_CHECK_PARAMETERS */
  
    
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumContStates(S,0);
    ssSetNumDiscStates(S,0);

     /* s-function parameters */
        ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters. */
#if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) {
            return;
        }
    } else {
        return; /* Parameter mismatch will be reported by Simulink. */
    }
#endif
  {

    int iParam = 0;
    int nParam = ssGetNumSFcnParams(S);

        for ( iParam = 0; iParam < nParam; iParam++ )
            ssSetSFcnParamNotTunable( S, iParam);
            
  }   
//     ssSetNumSFcnParams(S, 0);
//     if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
//         return;
//     }


    if (!ssSetNumInputPorts(S,1)) return;
    ssSetInputPortDimensionInfo(S, 0, DYNAMIC_DIMENSION);
    ssSetInputPortRequiredContiguous(S,0,true);
    ssSetInputPortDirectFeedThrough(S,0,1);
    ssSetInputPortDataType(S, 0, SS_SINGLE);

    
    if (!ssSetNumOutputPorts(S,0)) return;

    
    ssSetNumSampleTimes(S,1);
    
    
    ssSetNumRWork(S,0);
    ssSetNumIWork(S,0);
    ssSetNumPWork(S,0);
    ssSetNumModes(S,0);
    ssSetNumNonsampledZCs(S,0);
    ssSetOptions(S, 0);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
        ssSetSampleTime(S,0,mxGetPr(TS(S))[0]);
        ssSetOffsetTime(S,0,0.0);
}

#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_DIMENSION_INFO
static void mdlSetInputPortDimensionInfo(SimStruct *S,
                                          int_T port,
                                          const DimsInfo_T *dimsInfo)
{
    /* Set input port dimension */
    if(!ssSetInputPortDimensionInfo(S, port, dimsInfo)) return;
}
#endif


#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START) 
static void mdlStart(SimStruct *S)
{
}
#endif


static void mdlOutputs(SimStruct *S, int_T tid)
{
}


static void mdlTerminate(SimStruct *S)
{
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif