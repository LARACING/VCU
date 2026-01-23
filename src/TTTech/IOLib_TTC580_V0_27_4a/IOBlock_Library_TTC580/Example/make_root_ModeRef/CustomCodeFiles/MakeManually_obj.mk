###############################################################################
#                                                                             #
#  Makefile for building LIB                                                  #
#                                                                             #
###############################################################################

#where is Matlab installed
MATLABROOT = C:\Program Files\MATLAB\R2018a

#where is the Environment for TTC580 installed (eho) 
TTTECHROOT = C:/TTTech

#ROOT_DIR = ../../template
ROOT_DIR = $(TTTECHROOT)/Environment_TTC580
EXAMPLE_DIR = .

#TARGET=TTC580 : will be defined in Matlab-make(), but if for some reason not:
ifeq ($(origin TARGET), undefined)
    TARGET_NOT_SPECIFIED = TRUE
    TARGET = TTC580
endif

#Settings for J1939 DM1 service
ROOT_IOLIB_DIR  = $(TTTECHROOT)\IOLib580_Environment
LIB_J1939_DIR   = $(subst \,/,$(ROOT_IOLIB_DIR)\lib)
J1939_LIB_NAME  = libj1939.a

ifneq ($(MAKECMDGOALS), clean)
    ifeq ($(origin TARGET), undefined)
        $(info *****************************************************)
        $(info *)
        $(info * Please specify the TARGET which shall be compiled)
        $(info * use:)
        $(info * TARGET=TTC580      for HY-TTC 580, 1st generation)
        $(info * TARGET=TTC540      for HY-TTC 540, 1st generation)
        $(info * TARGET=TTC520      for HY-TTC 520, 1st generation)
        $(info * TARGET=TTC510      for HY-TTC 510, 1st generation)
        $(info * TARGET=TTC580_GEN2 for HY-TTC 580, 2nd generation)
        $(info * TARGET=TTC540_GEN2 for HY-TTC 540, 2nd generation)
        $(info * TARGET=TTC520_GEN2 for HY-TTC 520, 2nd generation)
        $(info * TARGET=TTC510_GEN2 for HY-TTC 510, 2nd generation)
        $(info * TARGET=TTC590      for HY-TTC 590)
        $(info * TARGET=TTC590E     for HY-TTC 590E)
        $(info * TARGET=TTC508      for HY-TTC 508)
        $(info *)
        $(info * Example: make all TARGET=TTC580_GEN2)
        $(info *****************************************************)
        $(warning WARNING: Using default TARGET=$(TARGET))
    endif
    ifdef TARGET_UNKNOWN
        $(warning WARNING: Specified target unknown, using generic!)
    endif
endif

#
# Includes
#
include $(ROOT_DIR)/env/settings.mk

#
# list of source, and object files
#
# application module files
APP_PATH      = $(subst \,/,$(EXAMPLE_DIR))
APP_SDIR      = $(subst \,/,$(APP_PATH))
APP_FILES     = $(basename $(wildcard $(APP_SDIR)/*.c))
APP_OBJ_FILES = $(addprefix build/app_, $(notdir $(addsuffix .obj, $(APP_FILES))))

#
# Path settings
#
INCDIRS  = -I "$(ROOT_DIR)\inc"
INCDIRS += -I "$(C_COMP_PATH)\..\include"
INCDIRS += -I "$(APP_PATH)"
#eho
INCDIRS += -I"$(MATLABROOT)\rtw\c\libsrc"
INCDIRS += -I"$(MATLABROOT)\extern\include"
INCDIRS += -I"$(MATLABROOT)\simulink\include"	
INCDIRS += -I"$(ROOT_IOLIB_DIR)\inc"
#INCDIRS += -I"C:\what_ever_you_want_to_include"

# Temporal linker command file
LINK_TMP_FILE = $(ROOT_DIR)/build/link_tmp.cmd

compile : $(APP_OBJ_FILES)

# build application files
build/app_%.obj : $(APP_PATH)/%.c
	@echo compiling application files: $<
 	#not real warning but output the actual command for later debugging possibility
	$(warning)"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build
	@"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build

