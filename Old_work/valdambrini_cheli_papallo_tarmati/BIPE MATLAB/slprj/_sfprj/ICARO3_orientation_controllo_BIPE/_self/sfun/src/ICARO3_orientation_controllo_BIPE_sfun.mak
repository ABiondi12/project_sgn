# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MACHINE     = ICARO3_orientation_controllo_BIPE
TARGET      = sfun
CHART_SRCS   = c1_ICARO3_orientation_controllo_BIPE.c c2_ICARO3_orientation_controllo_BIPE.c c3_ICARO3_orientation_controllo_BIPE.c c4_ICARO3_orientation_controllo_BIPE.c c15_ICARO3_orientation_controllo_BIPE.c c71_ICARO3_orientation_controllo_BIPE.c c73_ICARO3_orientation_controllo_BIPE.c c74_ICARO3_orientation_controllo_BIPE.c c75_ICARO3_orientation_controllo_BIPE.c c76_ICARO3_orientation_controllo_BIPE.c c77_ICARO3_orientation_controllo_BIPE.c c94_ICARO3_orientation_controllo_BIPE.c c95_ICARO3_orientation_controllo_BIPE.c c96_ICARO3_orientation_controllo_BIPE.c c97_ICARO3_orientation_controllo_BIPE.c c98_ICARO3_orientation_controllo_BIPE.c c99_ICARO3_orientation_controllo_BIPE.c c100_ICARO3_orientation_controllo_BIPE.c c102_ICARO3_orientation_controllo_BIPE.c c103_ICARO3_orientation_controllo_BIPE.c c104_ICARO3_orientation_controllo_BIPE.c c105_ICARO3_orientation_controllo_BIPE.c c106_ICARO3_orientation_controllo_BIPE.c c107_ICARO3_orientation_controllo_BIPE.c c108_ICARO3_orientation_controllo_BIPE.c c111_ICARO3_orientation_controllo_BIPE.c c126_ICARO3_orientation_controllo_BIPE.c c127_ICARO3_orientation_controllo_BIPE.c c128_ICARO3_orientation_controllo_BIPE.c c129_ICARO3_orientation_controllo_BIPE.c c130_ICARO3_orientation_controllo_BIPE.c c131_ICARO3_orientation_controllo_BIPE.c c132_ICARO3_orientation_controllo_BIPE.c c133_ICARO3_orientation_controllo_BIPE.c c134_ICARO3_orientation_controllo_BIPE.c c135_ICARO3_orientation_controllo_BIPE.c c136_ICARO3_orientation_controllo_BIPE.c c137_ICARO3_orientation_controllo_BIPE.c c138_ICARO3_orientation_controllo_BIPE.c c139_ICARO3_orientation_controllo_BIPE.c c140_ICARO3_orientation_controllo_BIPE.c c141_ICARO3_orientation_controllo_BIPE.c c142_ICARO3_orientation_controllo_BIPE.c c143_ICARO3_orientation_controllo_BIPE.c c144_ICARO3_orientation_controllo_BIPE.c c145_ICARO3_orientation_controllo_BIPE.c c146_ICARO3_orientation_controllo_BIPE.c c147_ICARO3_orientation_controllo_BIPE.c c159_ICARO3_orientation_controllo_BIPE.c
MACHINE_SRC  = ICARO3_orientation_controllo_BIPE_sfun.c
MACHINE_REG = ICARO3_orientation_controllo_BIPE_sfun_registry.c
MAKEFILE    = ICARO3_orientation_controllo_BIPE_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2014a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2014a\extern\include" \
    /I "C:\Program Files\MATLAB\R2014a\simulink\include" \
    /I "C:\Program Files\MATLAB\R2014a\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2014a\rtw\c\src" \
    /I "C:\Users\ivald\Desktop\BIPE MATLAB\slprj\_sfprj\ICARO3_orientation_controllo_BIPE\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = ICARO3_orientation_controllo_BIPE_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\sf_runtime.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmx.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmat.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libfixedpoint.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libut.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmwmathutil.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libemlrt.lib" "C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft\libmwsl_log_load_blocks.lib" "C:\Program Files\MATLAB\R2014a\lib\win64\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


