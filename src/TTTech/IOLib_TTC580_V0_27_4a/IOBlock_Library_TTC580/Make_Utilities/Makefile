###############################################################################
#                                                                             #
#  Makefile for building LIB                                                  #
#                                                                             #
###############################################################################

#where is Matlab installed. undefined check only for older version necessary
ifeq ($(origin MATLABROOT), undefined)
    MATLABROOT = C:\Program Files\MATLAB\R2020b
endif

#where is the Environment for TTC580 installed (eho) 
TTTECHROOT = C:/TTTech

#ROOT_DIR = ../../template
ROOT_DIR = $(TTTECHROOT)/Environment_TTC580
EXAMPLE_DIR = .

#TARGET=TTC580 : will be defined in Matlab-make(), but if for some reason not:
ifeq ($(origin TARGET), undefined)
    TARGET_NOT_SPECIFIED = TRUE
    TARGET = TTC580_GEN2
endif

#Settings for J1939 DM1 service
ROOT_IOLIB_DIR  = $(TTTECHROOT)\IOLib580_Environment
LIB_J1939_DIR   = $(subst \,/,$(ROOT_IOLIB_DIR)\lib)
J1939_LIB_NAME  = libj1939.a
APP_J1939_SDIR      = $(subst \,/,$(ROOT_IOLIB_DIR)\src)
APP_J1939_FILES     = $(basename $(wildcard $(APP_J1939_SDIR)/*.c))
APP_J1939_OBJ_FILES = $(addprefix build/appj1939_, $(notdir $(addsuffix .obj, $(APP_J1939_FILES))))

print_dir:
	echo $(APP_J1939_SDIR)
	echo $(APP_J1939_OBJ_FILES)

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
INCDIRS += -I"$(MATLABROOT)\rtw\c\src"
INCDIRS += -I"$(MATLABROOT)\extern\include"
INCDIRS += -I"$(MATLABROOT)\simulink\include"	
INCDIRS += -I"$(ROOT_IOLIB_DIR)\inc"
#INCDIRS += -I"C:\what_ever_you_want_to_include"

#eho TTC580
IOLIB580_OBJ = $(ROOT_IOLIB_DIR)\obj\IOLib500_utils.obj
#IOLIB580_OBJ += $"C:\where_ever_your_obj_are"

# Temporal linker command file
LINK_TMP_FILE = $(ROOT_DIR)/build/link_tmp.cmd

all : prebuild build/app.out postbuild clean_obj

build/app.out : $(LIB_DIR)/$(LIB_NAME) $(LIB_DIR)/$(BSP_LIB_NAME) $(APP_OBJ_FILES) $(APP_J1939_OBJ_FILES) clean_linktmp
	@echo linking $@
	$(foreach i,$(APP_OBJ_FILES),$(shell echo "$i"              >> $(LINK_TMP_FILE)))
	@echo $(IOLIB580_OBJ)  										>> $(LINK_TMP_FILE)
	@echo $(APP_J1939_OBJ_FILES) 								>> $(LINK_TMP_FILE)
	@echo -o $@                                                 >> $(LINK_TMP_FILE)
	@echo -l $(LIB_DIR)/$(LIB_NAME)                             >> $(LINK_TMP_FILE)
	@echo -l $(LIB_DIR)/$(BSP_LIB_NAME)                         >> $(LINK_TMP_FILE)
	@if exist $(LIB_J1939_DIR)/$(J1939_LIB_NAME) echo -l $(LIB_J1939_DIR)/$(J1939_LIB_NAME)                 >> $(LINK_TMP_FILE)
	@echo -l $(FPU_LIB)                                         >> $(LINK_TMP_FILE)
	@echo $(LINK_CMDFILE_BL)                                    >> $(LINK_TMP_FILE)
	@echo -m build/app.map                                      >> $(LINK_TMP_FILE)
	@echo $(L_OPTS)                                             >> $(LINK_TMP_FILE)
	@"$(LINK)" --run_linker $(LINK_TMP_FILE)
	@"$(HEX)" --quiet --intel --romwidth=32 --fill=0xFFFFFFFF build/app.out -o build/app.hex
	@echo  ---------
	@echo    done.
	@echo  ---------

# build application files
build/app_%.obj : $(APP_PATH)/%.c 
	@echo compiling application files: $<
 	#not real warning but output the actual command for later debugging possibility
	$(warning)"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build
	@"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build

# build application files
build/appj1939_%.obj : $(APP_J1939_SDIR)/%.c 
	@echo compiling application files: $<
 	#not real warning but output the actual command for later debugging possibility
	$(warning)"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build
	@"$(CC)" $< $(INCDIRS) $(C_OPTS) --output_file $@ --asm_directory ./build --obj_directory ./build

clean :
	@echo cleaning up application module files
	@del /F /Q build\*.*
	@if exist AddAPDB.html del /F /Q AddAPDB.html
	@if exist nowECC.log del /F /Q nowECC.log
	@echo done.

clean_obj :
	@echo cleaning up application object  files
	@del /F /Q build\*.obj
	@echo done.

clean_linktmp : 
	@echo cleaning up temporary linker files
	@echo "$(subst /,\,$(LINK_TMP_FILE))"
	@del /F /Q "$(subst /,\,$(LINK_TMP_FILE))"

# Debugging: Print the value of a variable.
print-%:
	@echo $*=$($*) 

#---------------------------------------------
# postbuild rule
#---------------------------------------------
postbuild:
	@echo  ----------------------------------------
	@echo   Creating APDB...
	@echo  ----------------------------------------
	@if exist build\app.hex.addAPDB del build\app.hex.addAPDB
	@"$(ROOT_DIR)"\\env\\AddAPDB.exe -t $(DOWNLOADER_HW_TYPE) -v $(BOOTLOADER_VERSION) -w 32 -f I -k "$(ROOT_DIR)"\\env\\public.key "$(ROOT_DIR)"\\env\\targets.xml build\app.hex build\app.hex.addAPDB
	@copy /Y build\app.hex.addAPDB build\app.hex
	@if exist build\app.hex.addAPDB del build\app.hex.addAPDB
	@echo  ----------------------------------------
	@echo   Creating files for JTAG programming...
	@echo  ----------------------------------------
	@"$(SREC)" build/app.hex -Intel -fill 0xFF 0xA0000 0x300000 -O build/app_jtag.hex -Intel
	@"$(ECC)" -i build/app_jtag.hex -o build/app_jtag_ecc.hex -F021 16M_ADD -r4 -d
	
#---------------------------------------------
# prebuild rule
#---------------------------------------------
prebuild:
	@echo  ----------------------------------------
	@echo   Checking CGT (compiler) version...
	@echo  ----------------------------------------
	@"$(LINK)" --help > "build\cgt_version.tmp"
	@call "$(ROOT_DIR)"\\env\\cgt_version_check.bat "build\cgt_version.tmp"
	@echo  ----------------------------------------
	@echo   Creating application...
	@echo  ----------------------------------------
	