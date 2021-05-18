/* Include files */

#include "ICARO3_Onda_bipe_controllonostro_sfun.h"
#include "ICARO3_Onda_bipe_controllonostro_sfun_debug_macros.h"
#include "c1_ICARO3_Onda_bipe_controllonostro.h"
#include "c2_ICARO3_Onda_bipe_controllonostro.h"
#include "c3_ICARO3_Onda_bipe_controllonostro.h"
#include "c4_ICARO3_Onda_bipe_controllonostro.h"
#include "c15_ICARO3_Onda_bipe_controllonostro.h"
#include "c71_ICARO3_Onda_bipe_controllonostro.h"
#include "c72_ICARO3_Onda_bipe_controllonostro.h"
#include "c73_ICARO3_Onda_bipe_controllonostro.h"
#include "c74_ICARO3_Onda_bipe_controllonostro.h"
#include "c75_ICARO3_Onda_bipe_controllonostro.h"
#include "c76_ICARO3_Onda_bipe_controllonostro.h"
#include "c77_ICARO3_Onda_bipe_controllonostro.h"
#include "c94_ICARO3_Onda_bipe_controllonostro.h"
#include "c95_ICARO3_Onda_bipe_controllonostro.h"
#include "c96_ICARO3_Onda_bipe_controllonostro.h"
#include "c97_ICARO3_Onda_bipe_controllonostro.h"
#include "c98_ICARO3_Onda_bipe_controllonostro.h"
#include "c99_ICARO3_Onda_bipe_controllonostro.h"
#include "c100_ICARO3_Onda_bipe_controllonostro.h"
#include "c102_ICARO3_Onda_bipe_controllonostro.h"
#include "c103_ICARO3_Onda_bipe_controllonostro.h"
#include "c104_ICARO3_Onda_bipe_controllonostro.h"
#include "c105_ICARO3_Onda_bipe_controllonostro.h"
#include "c106_ICARO3_Onda_bipe_controllonostro.h"
#include "c107_ICARO3_Onda_bipe_controllonostro.h"
#include "c108_ICARO3_Onda_bipe_controllonostro.h"
#include "c111_ICARO3_Onda_bipe_controllonostro.h"
#include "c126_ICARO3_Onda_bipe_controllonostro.h"
#include "c127_ICARO3_Onda_bipe_controllonostro.h"
#include "c128_ICARO3_Onda_bipe_controllonostro.h"
#include "c129_ICARO3_Onda_bipe_controllonostro.h"
#include "c130_ICARO3_Onda_bipe_controllonostro.h"
#include "c131_ICARO3_Onda_bipe_controllonostro.h"
#include "c132_ICARO3_Onda_bipe_controllonostro.h"
#include "c133_ICARO3_Onda_bipe_controllonostro.h"
#include "c134_ICARO3_Onda_bipe_controllonostro.h"
#include "c135_ICARO3_Onda_bipe_controllonostro.h"
#include "c136_ICARO3_Onda_bipe_controllonostro.h"
#include "c137_ICARO3_Onda_bipe_controllonostro.h"
#include "c138_ICARO3_Onda_bipe_controllonostro.h"
#include "c139_ICARO3_Onda_bipe_controllonostro.h"
#include "c140_ICARO3_Onda_bipe_controllonostro.h"
#include "c141_ICARO3_Onda_bipe_controllonostro.h"
#include "c142_ICARO3_Onda_bipe_controllonostro.h"
#include "c143_ICARO3_Onda_bipe_controllonostro.h"
#include "c144_ICARO3_Onda_bipe_controllonostro.h"
#include "c145_ICARO3_Onda_bipe_controllonostro.h"
#include "c146_ICARO3_Onda_bipe_controllonostro.h"
#include "c147_ICARO3_Onda_bipe_controllonostro.h"
#include "c159_ICARO3_Onda_bipe_controllonostro.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ICARO3_Onda_bipe_controllonostroMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ICARO3_Onda_bipe_controllonostro_initializer(void)
{
}

void ICARO3_Onda_bipe_controllonostro_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ICARO3_Onda_bipe_controllonostro_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==71) {
    c71_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==72) {
    c72_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==73) {
    c73_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==74) {
    c74_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==75) {
    c75_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==76) {
    c76_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==77) {
    c77_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==94) {
    c94_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==95) {
    c95_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==96) {
    c96_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==97) {
    c97_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==98) {
    c98_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==99) {
    c99_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==100) {
    c100_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==102) {
    c102_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==103) {
    c103_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==104) {
    c104_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==105) {
    c105_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==106) {
    c106_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==107) {
    c107_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==108) {
    c108_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==111) {
    c111_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==126) {
    c126_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==127) {
    c127_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==128) {
    c128_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==129) {
    c129_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==130) {
    c130_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==131) {
    c131_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==132) {
    c132_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==133) {
    c133_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==134) {
    c134_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==135) {
    c135_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==136) {
    c136_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==137) {
    c137_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==138) {
    c138_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==139) {
    c139_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==140) {
    c140_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==141) {
    c141_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==142) {
    c142_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==143) {
    c143_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==144) {
    c144_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==145) {
    c145_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==146) {
    c146_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==147) {
    c147_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==159) {
    c159_ICARO3_Onda_bipe_controllonostro_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_ICARO3_Onda_bipe_controllonostro_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3809514009U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1189943312U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1846271499U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1535742663U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2038829572U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3202956629U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1547035288U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3734139759U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c1_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c2_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c3_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c4_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c15_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 71:
        {
          extern void sf_c71_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c71_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 72:
        {
          extern void sf_c72_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c72_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 73:
        {
          extern void sf_c73_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c73_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 74:
        {
          extern void sf_c74_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c74_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 75:
        {
          extern void sf_c75_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c75_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 76:
        {
          extern void sf_c76_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c76_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 77:
        {
          extern void sf_c77_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c77_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 94:
        {
          extern void sf_c94_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c94_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 95:
        {
          extern void sf_c95_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c95_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 96:
        {
          extern void sf_c96_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c96_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 97:
        {
          extern void sf_c97_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c97_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 98:
        {
          extern void sf_c98_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c98_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 99:
        {
          extern void sf_c99_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c99_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 100:
        {
          extern void sf_c100_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c100_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 102:
        {
          extern void sf_c102_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c102_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 103:
        {
          extern void sf_c103_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c103_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 104:
        {
          extern void sf_c104_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c104_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 105:
        {
          extern void sf_c105_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c105_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 106:
        {
          extern void sf_c106_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c106_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 107:
        {
          extern void sf_c107_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c107_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 108:
        {
          extern void sf_c108_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c108_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 111:
        {
          extern void sf_c111_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c111_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 126:
        {
          extern void sf_c126_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c126_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 127:
        {
          extern void sf_c127_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c127_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 128:
        {
          extern void sf_c128_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c128_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 129:
        {
          extern void sf_c129_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c129_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 130:
        {
          extern void sf_c130_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c130_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 131:
        {
          extern void sf_c131_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c131_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 132:
        {
          extern void sf_c132_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c132_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 133:
        {
          extern void sf_c133_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c133_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 134:
        {
          extern void sf_c134_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c134_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 135:
        {
          extern void sf_c135_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c135_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 136:
        {
          extern void sf_c136_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c136_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 137:
        {
          extern void sf_c137_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c137_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 138:
        {
          extern void sf_c138_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c138_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 139:
        {
          extern void sf_c139_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c139_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 140:
        {
          extern void sf_c140_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c140_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 141:
        {
          extern void sf_c141_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c141_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 142:
        {
          extern void sf_c142_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c142_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 143:
        {
          extern void sf_c143_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c143_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 144:
        {
          extern void sf_c144_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c144_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 145:
        {
          extern void sf_c145_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c145_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 146:
        {
          extern void sf_c146_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c146_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 147:
        {
          extern void sf_c147_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c147_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       case 159:
        {
          extern void sf_c159_ICARO3_Onda_bipe_controllonostro_get_check_sum
            (mxArray *plhs[]);
          sf_c159_ICARO3_Onda_bipe_controllonostro_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(41246040U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3291840947U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2025115240U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3269906337U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1179386399U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2648849836U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2660399376U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(17157307U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ICARO3_Onda_bipe_controllonostro_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(aiChksum, "veGJENudqgUvcaXUssDIYF") == 0) {
          extern mxArray
            *sf_c1_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "rsJiCs9FdoPTrxyDazOn0E") == 0) {
          extern mxArray
            *sf_c2_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "rsJiCs9FdoPTrxyDazOn0E") == 0) {
          extern mxArray
            *sf_c3_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "ies247orudw6kH9Wo65rvE") == 0) {
          extern mxArray
            *sf_c4_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "sj2jf7X0Z4mftEfUYtggoE") == 0) {
          extern mxArray
            *sf_c15_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c15_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 71:
      {
        if (strcmp(aiChksum, "EAR6u4XKLcHKWyROoirOe") == 0) {
          extern mxArray
            *sf_c71_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c71_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 72:
      {
        if (strcmp(aiChksum, "V0074mVK2JvY0uDlfVjc3G") == 0) {
          extern mxArray
            *sf_c72_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c72_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 73:
      {
        if (strcmp(aiChksum, "HvbDTZvK6UoVsqSgPp3idE") == 0) {
          extern mxArray
            *sf_c73_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c73_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 74:
      {
        if (strcmp(aiChksum, "YsGVWlkTesVlZCfLinpN6B") == 0) {
          extern mxArray
            *sf_c74_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c74_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 75:
      {
        if (strcmp(aiChksum, "cjk4ksze7uKjyRmkzHKzSE") == 0) {
          extern mxArray
            *sf_c75_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c75_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 76:
      {
        if (strcmp(aiChksum, "FzwnuLggSwpjTPamuX34W") == 0) {
          extern mxArray
            *sf_c76_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c76_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 77:
      {
        if (strcmp(aiChksum, "hXVnCQBNlAdLZa4MpoePYB") == 0) {
          extern mxArray
            *sf_c77_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c77_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 94:
      {
        if (strcmp(aiChksum, "sIEjzZYhWGac1BwuYKX6LH") == 0) {
          extern mxArray
            *sf_c94_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c94_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 95:
      {
        if (strcmp(aiChksum, "1n0dOR2gqX3cOmQHv8IGbH") == 0) {
          extern mxArray
            *sf_c95_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c95_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 96:
      {
        if (strcmp(aiChksum, "HGw6JxblLekhRJUnRx7OcF") == 0) {
          extern mxArray
            *sf_c96_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c96_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 97:
      {
        if (strcmp(aiChksum, "weE4U3gemlZgduLCkgE2u") == 0) {
          extern mxArray
            *sf_c97_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c97_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 98:
      {
        if (strcmp(aiChksum, "YjkLFGOD9sbht5HufE2hkF") == 0) {
          extern mxArray
            *sf_c98_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c98_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 99:
      {
        if (strcmp(aiChksum, "QhVDyZECL6qKkgQEWN4Bx") == 0) {
          extern mxArray
            *sf_c99_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c99_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 100:
      {
        if (strcmp(aiChksum, "MlifVmpEWMc9wBtaBC8PnH") == 0) {
          extern mxArray
            *sf_c100_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c100_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 102:
      {
        if (strcmp(aiChksum, "wQketIGMq6D4CYDTa0ZdbF") == 0) {
          extern mxArray
            *sf_c102_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c102_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 103:
      {
        if (strcmp(aiChksum, "22mv0JONUG4qpfjj3mv4hE") == 0) {
          extern mxArray
            *sf_c103_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c103_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 104:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c104_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c104_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 105:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c105_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c105_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 106:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c106_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c106_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 107:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c107_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c107_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 108:
      {
        if (strcmp(aiChksum, "0dnJ8Y284mVkSbhLfNZA9B") == 0) {
          extern mxArray
            *sf_c108_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c108_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 111:
      {
        if (strcmp(aiChksum, "0dnJ8Y284mVkSbhLfNZA9B") == 0) {
          extern mxArray
            *sf_c111_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c111_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 126:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c126_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c126_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 127:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c127_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c127_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 128:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c128_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c128_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 129:
      {
        if (strcmp(aiChksum, "TFhVhoeD2Wq2p2Z7tMYnnC") == 0) {
          extern mxArray
            *sf_c129_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c129_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 130:
      {
        if (strcmp(aiChksum, "ktvHqBbqhH40zEmAtg0cdC") == 0) {
          extern mxArray
            *sf_c130_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c130_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 131:
      {
        if (strcmp(aiChksum, "ktvHqBbqhH40zEmAtg0cdC") == 0) {
          extern mxArray
            *sf_c131_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c131_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 132:
      {
        if (strcmp(aiChksum, "ktvHqBbqhH40zEmAtg0cdC") == 0) {
          extern mxArray
            *sf_c132_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c132_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 133:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c133_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c133_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 134:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c134_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c134_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 135:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c135_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c135_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 136:
      {
        if (strcmp(aiChksum, "6ioYYHHv4D3Rx4NuebSW0") == 0) {
          extern mxArray
            *sf_c136_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c136_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 137:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c137_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c137_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 138:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c138_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c138_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 139:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c139_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c139_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 140:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c140_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c140_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 141:
      {
        if (strcmp(aiChksum, "6ioYYHHv4D3Rx4NuebSW0") == 0) {
          extern mxArray
            *sf_c141_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c141_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 142:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c142_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c142_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 143:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c143_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c143_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 144:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c144_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c144_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 145:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c145_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c145_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 146:
      {
        if (strcmp(aiChksum, "6ioYYHHv4D3Rx4NuebSW0") == 0) {
          extern mxArray
            *sf_c146_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c146_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 147:
      {
        if (strcmp(aiChksum, "PTeAXQkPPRs6cwlTQ4rGDD") == 0) {
          extern mxArray
            *sf_c147_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c147_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 159:
      {
        if (strcmp(aiChksum, "qbuVtwPsrp5BqNjMtNvAVD") == 0) {
          extern mxArray
            *sf_c159_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c159_ICARO3_Onda_bipe_controllonostro_get_autoinheritance_info();
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

unsigned int sf_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        extern const mxArray
          *sf_c1_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 71:
      {
        extern const mxArray
          *sf_c71_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c71_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 72:
      {
        extern const mxArray
          *sf_c72_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c72_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 73:
      {
        extern const mxArray
          *sf_c73_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c73_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 74:
      {
        extern const mxArray
          *sf_c74_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c74_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 75:
      {
        extern const mxArray
          *sf_c75_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c75_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 76:
      {
        extern const mxArray
          *sf_c76_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c76_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 77:
      {
        extern const mxArray
          *sf_c77_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c77_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 94:
      {
        extern const mxArray
          *sf_c94_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c94_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 95:
      {
        extern const mxArray
          *sf_c95_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c95_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 96:
      {
        extern const mxArray
          *sf_c96_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c96_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 97:
      {
        extern const mxArray
          *sf_c97_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c97_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 98:
      {
        extern const mxArray
          *sf_c98_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c98_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 99:
      {
        extern const mxArray
          *sf_c99_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c99_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 100:
      {
        extern const mxArray
          *sf_c100_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c100_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 102:
      {
        extern const mxArray
          *sf_c102_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c102_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 103:
      {
        extern const mxArray
          *sf_c103_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c103_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 104:
      {
        extern const mxArray
          *sf_c104_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c104_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 105:
      {
        extern const mxArray
          *sf_c105_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c105_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 106:
      {
        extern const mxArray
          *sf_c106_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c106_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 107:
      {
        extern const mxArray
          *sf_c107_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c107_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 108:
      {
        extern const mxArray
          *sf_c108_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c108_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 111:
      {
        extern const mxArray
          *sf_c111_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c111_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 126:
      {
        extern const mxArray
          *sf_c126_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c126_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 127:
      {
        extern const mxArray
          *sf_c127_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c127_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 128:
      {
        extern const mxArray
          *sf_c128_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c128_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 129:
      {
        extern const mxArray
          *sf_c129_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c129_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 130:
      {
        extern const mxArray
          *sf_c130_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c130_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 131:
      {
        extern const mxArray
          *sf_c131_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c131_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 132:
      {
        extern const mxArray
          *sf_c132_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c132_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 133:
      {
        extern const mxArray
          *sf_c133_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c133_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 134:
      {
        extern const mxArray
          *sf_c134_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c134_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 135:
      {
        extern const mxArray
          *sf_c135_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c135_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 136:
      {
        extern const mxArray
          *sf_c136_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c136_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 137:
      {
        extern const mxArray
          *sf_c137_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c137_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 138:
      {
        extern const mxArray
          *sf_c138_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c138_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 139:
      {
        extern const mxArray
          *sf_c139_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c139_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 140:
      {
        extern const mxArray
          *sf_c140_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c140_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 141:
      {
        extern const mxArray
          *sf_c141_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c141_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 142:
      {
        extern const mxArray
          *sf_c142_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c142_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 143:
      {
        extern const mxArray
          *sf_c143_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c143_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 144:
      {
        extern const mxArray
          *sf_c144_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c144_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 145:
      {
        extern const mxArray
          *sf_c145_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c145_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 146:
      {
        extern const mxArray
          *sf_c146_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c146_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 147:
      {
        extern const mxArray
          *sf_c147_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c147_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 159:
      {
        extern const mxArray
          *sf_c159_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c159_ICARO3_Onda_bipe_controllonostro_get_eml_resolved_functions_info
          ();
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

unsigned int sf_ICARO3_Onda_bipe_controllonostro_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "aVp5Wg6luCi9Jkb62gUiz") == 0) {
          extern mxArray
            *sf_c1_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] = sf_c1_ICARO3_Onda_bipe_controllonostro_third_party_uses_info
            ();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "kzq7wmR37bkfx3xHlcOvwD") == 0) {
          extern mxArray
            *sf_c2_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] = sf_c2_ICARO3_Onda_bipe_controllonostro_third_party_uses_info
            ();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "kzq7wmR37bkfx3xHlcOvwD") == 0) {
          extern mxArray
            *sf_c3_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] = sf_c3_ICARO3_Onda_bipe_controllonostro_third_party_uses_info
            ();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "uY1vOOgcPZZRi96IqwoE2E") == 0) {
          extern mxArray
            *sf_c4_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] = sf_c4_ICARO3_Onda_bipe_controllonostro_third_party_uses_info
            ();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "rz3TPjmGLxgiZEIQUdypJG") == 0) {
          extern mxArray
            *sf_c15_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c15_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 71:
      {
        if (strcmp(tpChksum, "Ge0PaMVbfZmsMZEvC1i9ZC") == 0) {
          extern mxArray
            *sf_c71_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c71_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 72:
      {
        if (strcmp(tpChksum, "ct28WR52DkpPp1A3x5BM5G") == 0) {
          extern mxArray
            *sf_c72_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c72_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 73:
      {
        if (strcmp(tpChksum, "LBxY3dqaQCQxQvNXUHagEF") == 0) {
          extern mxArray
            *sf_c73_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c73_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 74:
      {
        if (strcmp(tpChksum, "JSDsNSAj7vNxFylC68AlmC") == 0) {
          extern mxArray
            *sf_c74_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c74_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 75:
      {
        if (strcmp(tpChksum, "BckTSgiXCMxiIJAJFVtD4") == 0) {
          extern mxArray
            *sf_c75_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c75_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 76:
      {
        if (strcmp(tpChksum, "pOe0dFpwLcI41zOo8ESha") == 0) {
          extern mxArray
            *sf_c76_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c76_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 77:
      {
        if (strcmp(tpChksum, "XbD1cPPhDGPfNfqaCYFEN") == 0) {
          extern mxArray
            *sf_c77_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c77_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 94:
      {
        if (strcmp(tpChksum, "atOUxWXKZFIACs8CSaWMU") == 0) {
          extern mxArray
            *sf_c94_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c94_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 95:
      {
        if (strcmp(tpChksum, "DQaB4RHsc2M7nzUw5aR9cC") == 0) {
          extern mxArray
            *sf_c95_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c95_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 96:
      {
        if (strcmp(tpChksum, "I6ujCSVLmUs6yrsYWq7CTF") == 0) {
          extern mxArray
            *sf_c96_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c96_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 97:
      {
        if (strcmp(tpChksum, "ypn7bWcbhprfGcbJXHsGG") == 0) {
          extern mxArray
            *sf_c97_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c97_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 98:
      {
        if (strcmp(tpChksum, "hdsIUO1GvTlIhlXoDjCG9F") == 0) {
          extern mxArray
            *sf_c98_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c98_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 99:
      {
        if (strcmp(tpChksum, "XUAIeI5VJdAUOlF1MyXTW") == 0) {
          extern mxArray
            *sf_c99_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c99_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 100:
      {
        if (strcmp(tpChksum, "sYfUG5pHzY6jPBRSraCyXH") == 0) {
          extern mxArray
            *sf_c100_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c100_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 102:
      {
        if (strcmp(tpChksum, "y4ZUNA9Y6lGwmZxUDuTzKF") == 0) {
          extern mxArray
            *sf_c102_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c102_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 103:
      {
        if (strcmp(tpChksum, "sNdcJhz2XfIfr32n5mOuBC") == 0) {
          extern mxArray
            *sf_c103_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c103_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 104:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c104_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c104_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 105:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c105_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c105_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 106:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c106_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c106_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 107:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c107_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c107_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 108:
      {
        if (strcmp(tpChksum, "VS1eVFj5oLHYCVJmmkYpEG") == 0) {
          extern mxArray
            *sf_c108_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c108_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 111:
      {
        if (strcmp(tpChksum, "VS1eVFj5oLHYCVJmmkYpEG") == 0) {
          extern mxArray
            *sf_c111_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c111_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 126:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c126_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c126_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 127:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c127_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c127_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 128:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c128_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c128_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 129:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c129_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c129_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 130:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c130_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c130_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 131:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c131_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c131_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 132:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c132_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c132_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 133:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c133_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c133_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 134:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c134_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c134_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 135:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c135_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c135_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 136:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c136_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c136_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 137:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c137_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c137_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 138:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c138_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c138_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 139:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c139_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c139_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 140:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c140_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c140_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 141:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c141_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c141_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 142:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c142_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c142_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 143:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c143_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c143_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 144:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c144_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c144_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 145:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c145_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c145_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 146:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c146_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c146_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 147:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c147_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c147_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     case 159:
      {
        if (strcmp(tpChksum, "6RxLcrApRE7G0A0Cwj9pCH") == 0) {
          extern mxArray
            *sf_c159_ICARO3_Onda_bipe_controllonostro_third_party_uses_info(void);
          plhs[0] =
            sf_c159_ICARO3_Onda_bipe_controllonostro_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "aVp5Wg6luCi9Jkb62gUiz") == 0) {
          extern mxArray
            *sf_c1_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c1_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "kzq7wmR37bkfx3xHlcOvwD") == 0) {
          extern mxArray
            *sf_c2_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c2_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "kzq7wmR37bkfx3xHlcOvwD") == 0) {
          extern mxArray
            *sf_c3_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c3_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "uY1vOOgcPZZRi96IqwoE2E") == 0) {
          extern mxArray
            *sf_c4_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c4_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "rz3TPjmGLxgiZEIQUdypJG") == 0) {
          extern mxArray
            *sf_c15_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c15_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 71:
      {
        if (strcmp(tpChksum, "Ge0PaMVbfZmsMZEvC1i9ZC") == 0) {
          extern mxArray
            *sf_c71_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c71_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 72:
      {
        if (strcmp(tpChksum, "ct28WR52DkpPp1A3x5BM5G") == 0) {
          extern mxArray
            *sf_c72_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c72_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 73:
      {
        if (strcmp(tpChksum, "LBxY3dqaQCQxQvNXUHagEF") == 0) {
          extern mxArray
            *sf_c73_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c73_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 74:
      {
        if (strcmp(tpChksum, "JSDsNSAj7vNxFylC68AlmC") == 0) {
          extern mxArray
            *sf_c74_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c74_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 75:
      {
        if (strcmp(tpChksum, "BckTSgiXCMxiIJAJFVtD4") == 0) {
          extern mxArray
            *sf_c75_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c75_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 76:
      {
        if (strcmp(tpChksum, "pOe0dFpwLcI41zOo8ESha") == 0) {
          extern mxArray
            *sf_c76_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c76_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 77:
      {
        if (strcmp(tpChksum, "XbD1cPPhDGPfNfqaCYFEN") == 0) {
          extern mxArray
            *sf_c77_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c77_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 94:
      {
        if (strcmp(tpChksum, "atOUxWXKZFIACs8CSaWMU") == 0) {
          extern mxArray
            *sf_c94_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c94_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 95:
      {
        if (strcmp(tpChksum, "DQaB4RHsc2M7nzUw5aR9cC") == 0) {
          extern mxArray
            *sf_c95_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c95_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 96:
      {
        if (strcmp(tpChksum, "I6ujCSVLmUs6yrsYWq7CTF") == 0) {
          extern mxArray
            *sf_c96_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c96_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 97:
      {
        if (strcmp(tpChksum, "ypn7bWcbhprfGcbJXHsGG") == 0) {
          extern mxArray
            *sf_c97_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c97_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 98:
      {
        if (strcmp(tpChksum, "hdsIUO1GvTlIhlXoDjCG9F") == 0) {
          extern mxArray
            *sf_c98_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c98_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 99:
      {
        if (strcmp(tpChksum, "XUAIeI5VJdAUOlF1MyXTW") == 0) {
          extern mxArray
            *sf_c99_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c99_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 100:
      {
        if (strcmp(tpChksum, "sYfUG5pHzY6jPBRSraCyXH") == 0) {
          extern mxArray
            *sf_c100_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c100_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 102:
      {
        if (strcmp(tpChksum, "y4ZUNA9Y6lGwmZxUDuTzKF") == 0) {
          extern mxArray
            *sf_c102_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c102_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 103:
      {
        if (strcmp(tpChksum, "sNdcJhz2XfIfr32n5mOuBC") == 0) {
          extern mxArray
            *sf_c103_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c103_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 104:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c104_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c104_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 105:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c105_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c105_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 106:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c106_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c106_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 107:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c107_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c107_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 108:
      {
        if (strcmp(tpChksum, "VS1eVFj5oLHYCVJmmkYpEG") == 0) {
          extern mxArray
            *sf_c108_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c108_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 111:
      {
        if (strcmp(tpChksum, "VS1eVFj5oLHYCVJmmkYpEG") == 0) {
          extern mxArray
            *sf_c111_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c111_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 126:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c126_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c126_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 127:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c127_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c127_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 128:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c128_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c128_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 129:
      {
        if (strcmp(tpChksum, "Yf1P9MepgOLabHJvS3ddEH") == 0) {
          extern mxArray
            *sf_c129_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c129_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 130:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c130_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c130_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 131:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c131_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c131_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 132:
      {
        if (strcmp(tpChksum, "t9iO4rfJdENQAK9g08k0OG") == 0) {
          extern mxArray
            *sf_c132_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c132_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 133:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c133_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c133_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 134:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c134_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c134_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 135:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c135_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c135_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 136:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c136_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c136_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 137:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c137_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c137_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 138:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c138_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c138_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 139:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c139_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c139_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 140:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c140_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c140_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 141:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c141_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c141_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 142:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c142_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c142_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 143:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c143_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c143_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 144:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c144_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c144_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 145:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c145_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c145_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 146:
      {
        if (strcmp(tpChksum, "gqXZOAzeuxEazoJ7TcegDC") == 0) {
          extern mxArray
            *sf_c146_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c146_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 147:
      {
        if (strcmp(tpChksum, "OKgHVAxfXXohUd0vXJBpe") == 0) {
          extern mxArray
            *sf_c147_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c147_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     case 159:
      {
        if (strcmp(tpChksum, "6RxLcrApRE7G0A0Cwj9pCH") == 0) {
          extern mxArray
            *sf_c159_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c159_ICARO3_Onda_bipe_controllonostro_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ICARO3_Onda_bipe_controllonostro_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _ICARO3_Onda_bipe_controllonostroMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"ICARO3_Onda_bipe_controllonostro","sfun",0,50,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ICARO3_Onda_bipe_controllonostroMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ICARO3_Onda_bipe_controllonostroMachineNumber_,0);
}

void ICARO3_Onda_bipe_controllonostro_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ICARO3_Onda_bipe_controllonostro_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ICARO3_Onda_bipe_controllonostro", "ICARO3_Onda_bipe_controllonostro");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ICARO3_Onda_bipe_controllonostro_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
