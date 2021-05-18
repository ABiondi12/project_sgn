#define S_FUNCTION_NAME  sfun_show_GPS
#define S_FUNCTION_LEVEL 2


/* Simulink includes */
#include "simstruc.h"

static void mdlInitializeSizes(SimStruct *S)
{
    /* Continuos and discrete states */
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    /* s-function parameters */
    ssSetNumSFcnParams(S, 0);
    if(ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
        return;
    
    /* Set number of input ports */
    if(!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 10);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);

    /* Set number of output ports, their dimension and data type */
    if(!ssSetNumOutputPorts(S, 0)) return;
	
    /* Set number of sample times */
    ssSetNumSampleTimes(S, 1);
    
    /* Specify the size of block's floating-point work vector */
    ssSetNumRWork(S, 0);
    
    /* Specify the size of block's integer work vector */
    ssSetNumIWork(S, 0);
    
    /* Specify the size of block's pointer work vector */
    ssSetNumPWork(S, 0);
    
    /* Specify the size of block's mode vector */
    ssSetNumModes(S, 0);
    
    /* Specify the number of states for which the block detects zero 
     * crossings that occur between sample points */
    ssSetNumNonsampledZCs(S, 0);
    
    /* Specify s-function options */
    ssSetOptions(S, 0);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Set period of sample time 0 */
    ssSetSampleTime(S, 0, -1);
    
    /* Set offset time of sample time 0 */
    ssSetOffsetTime(S, 0, 0.0);
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


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif