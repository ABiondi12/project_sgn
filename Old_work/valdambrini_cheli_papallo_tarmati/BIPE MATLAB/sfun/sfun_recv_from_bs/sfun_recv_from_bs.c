#define S_FUNCTION_NAME  sfun_recv_from_bs
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


    if (!ssSetNumInputPorts(S,1)) return;
    //data: variable size
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);

    
    if (!ssSetNumOutputPorts(S,8)) return;
    //1° ports: operating mode
    ssSetOutputPortWidth(S,0,1);
    ssSetOutputPortDataType(S, 0, SS_UINT8);
	//2° ports: reference point ecef
    ssSetOutputPortWidth(S,1,3);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    //3° ports: waypoint
    ssSetOutputPortWidth(S,2,2);
    ssSetOutputPortDataType(S, 2, SS_INT8);
    //4° ports: motor command
    ssSetOutputPortWidth(S,3,4);
    ssSetOutputPortDataType(S, 3, SS_UINT8);
    //5° ports: guadagni PI
    ssSetOutputPortWidth(S,4,4);
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
    //6° port: packet from basestation valid
    ssSetOutputPortWidth(S,5,1);
    ssSetOutputPortDataType(S, 5, SS_UINT8);
    //7° ports: target position 
    ssSetOutputPortWidth(S,6,3);
    ssSetOutputPortDataType(S, 6, SS_DOUBLE);
	//8° ports: target velocity 
    ssSetOutputPortWidth(S,7,3);
    ssSetOutputPortDataType(S, 7, SS_DOUBLE);
    
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
        ssSetSampleTime(S,0,0.01);
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