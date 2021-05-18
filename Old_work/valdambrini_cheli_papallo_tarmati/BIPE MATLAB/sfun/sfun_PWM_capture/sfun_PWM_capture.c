#define S_FUNCTION_NAME  sfun_PWM_capture
#define S_FUNCTION_LEVEL 2


/* Questa s-function presenta 1 parametro e due uscite (uint32_T, uint8_T) di dimensione 1
 * Parametro: TS, uscite: ppmval, newmess */



//++++++++++++++++++++
//.h Simulink Includes
//++++++++++++++++++++
#include "simstruc.h"
//++++++++++++++++++++


/* Define Parameters */

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
    int i=0;
    
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



    if (!ssSetNumInputPorts(S,0)) return;

    if (!ssSetNumOutputPorts(S,4)) return;
    
    // Now only one PWM, will be two
	ssSetOutputPortWidth(S,0,2);
    ssSetOutputPortDataType(S, 0, SS_UINT16);

    ssSetOutputPortWidth(S,1,2);
    ssSetOutputPortDataType(S, 1, SS_UINT16);
    
    ssSetOutputPortWidth(S,2,2);
    ssSetOutputPortDataType(S, 2, SS_UINT16);

    ssSetOutputPortWidth(S,3,2);
    ssSetOutputPortDataType(S, 3, SS_UINT8);
    
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







#undef MDL_RTW                        /* Change to #undef to remove function */
#if defined(MDL_RTW) && (defined(MATLAB_MEX_FILE) || defined(NRT))
/* Function: mdlRTW ============================================================
 * Abstract:
 *    This function is called when the Real-Time Workshop is generating the
 *    model.rtw file. In this routine, you can call the following functions
 *    which add fields to the model.rtw file.
 *
 *    Important! Since this s-function has this mdlRTW method, it is required
 *    to have a correcponding .tlc file so as to work with RTW. You will find
 *    the sfun_directlook.tlc in <matlaroot>/toolbox/simulink/blocks/tlc_c/.
 */
static void mdlRTW(SimStruct *S)
{
    /*
     * Write out the [X,Y] data as parameters, i.e., these values can be
     * changed during execution.
     */
    {
        double ch1= mxGetPr(CH1(S))[0];
        double ch2= mxGetPr(CH2(S))[0];
        double ch3= mxGetPr(CH3(S))[0];
        double ch4= mxGetPr(CH4(S))[0];
        
        if (!ssWriteRTWParamSettings(S,4,
                                  SSWRITE_VALUE_NUM,"CH1",ch1,
                                  SSWRITE_VALUE_NUM,"CH2",ch2,
                                  SSWRITE_VALUE_NUM,"CH3",ch3,
                                  SSWRITE_VALUE_NUM,"CH4",ch4)) {
            return; /* An error occurred which will be reported by Simulink */
        }
    }
    /*
     * Write out the spacing setting as a param setting, i.e., this cannot be
     * changed during execution.
     */
}
#endif /* MDL_RTW */









//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif