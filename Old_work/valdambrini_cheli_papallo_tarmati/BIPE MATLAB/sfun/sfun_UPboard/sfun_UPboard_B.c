#define S_FUNCTION_NAME  sfun_UPboard
#define S_FUNCTION_LEVEL 2


//++++++++++++++++++++
//.h Simulink Includes
//++++++++++++++++++++
#include "simstruc.h"
//++++++++++++++++++++


//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//S-Function Implementation
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumContStates(S,0);
    ssSetNumDiscStates(S,0);

    
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }


    if (!ssSetNumInputPorts(S,0)) return;
//     ssSetInputPortWidth(S,0,1); /* input byte */
//     ssSetInputPortRequiredContiguous(S,0,true);
//     ssSetInputPortDirectFeedThrough(S,0,1);
//     ssSetInputPortDataType(S, 0, SS_UINT8);

    
    if (!ssSetNumOutputPorts(S,2)) return;
 	ssSetOutputPortWidth(S,0,6);
   // ssSetOutputPortWidth(S,0,57);
    ssSetOutputPortWidth(S,1,1);

    
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
//        ssSetSampleTime(S,0,0.1);
            ssSetSampleTime(S,0,0.01); //variato da B
        ssSetOffsetTime(S,0,0.0);
}


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