###########################################################################
## Makefile generated for Simulink model 'AR_Drone_Flight_Control'. 
## 
## Makefile     : AR_Drone_Flight_Control.mk
## Generated on : Tue Nov 17 10:18:18 2015
## MATLAB Coder version: 2.6 (R2014a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/AR_Drone_Flight_Control.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = AR_Drone_Flight_Control
MAKEFILE                  = AR_Drone_Flight_Control.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2014a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2014a/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2014a/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Simulink_AR_Drone/AR_Drone_Models/Flight_Models
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODELREF_LINK_RSPFILE_NAME = AR_Drone_Flight_Control_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
SHARED_SRC_DIR            = ../slprj/ert/_sharedutils
SHARED_SRC                = $(SHARED_SRC_DIR)/*.c*
SHARED_BIN_DIR            = ../slprj/ert/_sharedutils
SHARED_LIB                = $(SHARED_BIN_DIR)/rtwshared.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Code Sourcery v4.8 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2014a
# Specification Revision:  1.0
# 

-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk


#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_PKG_INSTALLDIR
# CODE_SOURCERY

#-----------
# MACROS
#-----------

CCOUTPUTFLAG          = --output_file=
LDOUTPUTFLAG          = --output_file=
COMPILER_PATH         = $(CODE_SOURCERY)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Code Sourcery Assembler
AS_PATH = $(CODE_SOURCERY)
AS = $(AS_PATH)/arm-none-linux-gnueabi-as

# C Compiler: Code Sourcery C Compiler
CC_PATH = $(COMPILER_PATH)
CC = $(CC_PATH)/arm-none-linux-gnueabi-gcc

# Linker: Code Sourcery Linker
LD_PATH = $(CODE_SOURCERY)
LD = $(LD_PATH)/arm-none-linux-gnueabi-gcc

# C++ Compiler: Code Sourcery C Compiler
CPP = arm-none-linux-gnueabi-g++

# C++ Linker: Code Sourcery C++ Linker
CPP_LD = arm-none-linux-gnueabi-gcc

# Archiver: Code Sourcery Archiver
AR = arm-none-linux-gnueabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD_PATH = $(TARGET_PKG_INSTALLDIR)
DOWNLOAD = $(DOWNLOAD_PATH)/ssh_download.bat

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -O0
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
LDFLAGS              = -lm    -lrt  -lpthread
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

OBJ_EXT             = .o
ASM_EXT             = .s
H_EXT               = .h
OBJ_EXT             = .o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
HPP_EXT             = .hpp
OBJ_EXT             = .o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/AR_Drone_Flight_Control.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(MATLAB_ROOT)/toolbox/shared/dspblks/extern/include -I$(START_DIR)/AR_Drone_Flight_Control_ert_rtw -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(START_DIR)/slprj/ert/_sharedutils -I./referenced_model_includes -IC:/Simulink_AR_Drone/AR_Drone_Target/blocks/. -IC:/Simulink_AR_Drone/AR_Drone_Target/blocks -IC:/Simulink_AR_Drone/AR_Drone_Target/include -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=AR_Drone_Flight_Control -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO -DON_TARGET_WAIT_FOR_START=0 -DONESTEPFCN=1 -DEXT_MODE=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DARM_PROJECT -DRT -DSTACK_SIZE=64 -D_USE_TARGET_UDP_
DEFINES_BUILD_ARGS = -DONESTEPFCN=1 -DEXT_MODE=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=0
DEFINES_STANDARD = -DMODEL=AR_Drone_Flight_Control -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/shared/dspblks/extern/src/HostLib_Network.c $(MATLAB_ROOT)/toolbox/shared/dspblks/extern/src/HostLib_rtw.c $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/AR_Drone_Flight_Control.c $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/AR_Drone_Flight_Control_data.c IMU_Navdata.c IMU_Navdata_wrapper.c BatteryMeasure.c BatteryMeasure_Wrapper.c motor.c Actuators.c GPIO.c act_init.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c rtiostream_interface.c rtiostream_tcpip.c AR_Drone_ext_work.c AR_Drone_ext_svr.c linuxinitialize.c C:/Simulink_AR_Drone/AR_Drone_Target/src/linuxUDP.c

MAIN_SRC = $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = HostLib_Network.o HostLib_rtw.o AR_Drone_Flight_Control.o AR_Drone_Flight_Control_data.o IMU_Navdata.o IMU_Navdata_wrapper.o BatteryMeasure.o BatteryMeasure_Wrapper.o motor.o Actuators.o GPIO.o act_init.o updown.o rtiostream_utils.o rtiostream_interface.o rtiostream_tcpip.o AR_Drone_ext_work.o AR_Drone_ext_svr.o linuxinitialize.o linuxUDP.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = ./AR_Drone_Mission_Height_rtwlib.lib ./Navigation_KF_Subsystem_child_rtwlib.lib

LIBS = $(SHARED_LIB)

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -ldl

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -ldl

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -ldl

LDFLAGS += $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -std=gnu99 -ldl

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(MODELREF_LIBS) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/shared/dspblks/extern/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/shared/dspblks/extern/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/shared/dspblks/extern/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/AR_Drone_Flight_Control_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/blocks/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/blocks/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/blocks/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/Simulink_AR_Drone/AR_Drone_Target/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


#-----------------------------
# BUILD-IN-PLACE LIBRARIES
#-----------------------------


$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"

$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS_NO_PATH = $(addsuffix .o, $(basename $(notdir $(SHARED_SRC))))
SHARED_OBJS = $(addprefix $(join $(SHARED_BIN_DIR),/), $(SHARED_OBJS_NO_PATH))

$(SHARED_LIB) : $(SHARED_OBJS)
	$(AR) $(ARFLAGS)  "$@" $(SHARED_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


