# vim:syntax=make:
# -*- Mode: Makefile -*-

#WARNING COMPONENT_PATH is MANDATORY for Make.config and Make.rules
#-------------------------------
# Default Config
#-------------------------------
include make.ost_conf
include $(MM_MAKEFILES_DIR)/SharedConfig.mk

#----------------------------
# MY_MODULE would be set to imaging/hsmcamera
MY_MODULE= imaging/hsmcamera

# MY_BUILDGEN_DIR would be set to the top level directory which will contain all files generated by the build system
MY_BUILDGEN_DIR = $(TARGET_OUT_INTERMEDIATES)/$(MY_MODULE)/buildgen

#generate directory required
$(shell mkdir -p $(MY_BUILDGEN_DIR))
$(shell mkdir -p $(MY_BUILDGEN_DIR)/src)


ifeq ($(MMSYSTEM),symbian)
#CPPFLAGS += -DSTAB #disabled for symbian because of buffer size incompatibility with GfxSink 
else ifeq ($(MMSYSTEM),android)
#CPPFLAGS += -DSTAB #disabled for android because of stride related changes 
ifeq ($(MULTIMEDIA_SET_PLATFORM),u9540)
#CPPFLAGS += -DSTAB
else
CPPFLAGS += -DSTAB
endif
CPPFLAGS += -DFREQ_SCALING_ALLOWED
else 
#CPPFLAGS += -DSTAB #disabled for linux :- similar validation in linux env 
CPPFLAGS += -DSTAB
endif

#uncomment following line if you want to enable ISP low power when going to idle/pause/portdisa (after a timeout) 
CPPFLAGS += -DENABLE_LOWPOWER_ISP
#uncomment following line if you want to enable DSP fine low power (SIA clock gating) handling 
CPPFLAGS += -DENABLE_LOWPOWER_DSP

ifeq ($(MMIO_ENABLE_NEW_IF),true)
  CPPFLAGS += -DMMIO_ENABLE_NEW_IF
endif

ifeq ($(ENABLE_FEATURE_BUILD_HATS),true)
CPPFLAGS+= -DENABLE_FEATURE_BUILD_HATS
endif

#DEBUG=1
#export DEBUG

# Default customer
CUSTOMER=default

ifdef LATENCY_LOG_ENABLE
# enable latencies measurement
CPPFLAGS += -DLATENCY_LOG_ENABLE
endif

VPATH += src/sia_platform_manager \
		src/isp_features \
		src/opmode_transition  \
 		customer_specific/$(CUSTOMER)/src/

VPATH += $(MY_BUILDGEN_DIR)/src

ifdef DEBUG
CPPFLAGS += -DOSI_DEBUG -D__DEBUG
LIBNAME   = st_hsmcamera_debug
CFLAGS=-g -O0
INSTALL_LIB = libst_hsmcamera_debug.a
OBJ_EXT =odebug 
else
CPPFLAGS += -DRELEASE -D__RELEASE
LIBNAME   = st_hsmcamera
#CFLAGS=-g -O0
INSTALL_LIB = libst_hsmcamera.a
endif


ifeq ($(MYMMBOARD),svp8500_v1)
CPPFLAGS += -D_SVP_
endif


CPPFLAGS += -D_NTLM

# CR337836 Activate dynamic trace
CPPFLAGS += -DCONFIG_DEBUG -DDBGT_VAR=mDebugTraceVarHsmcamera -DCONFIG_DEBUG_AUTOVAR

ifeq ($(MYMMBOARD),href_ed_v1_0)
CPPFLAGS += -D__STN_8500 
endif


CPPFLAGS += -D__UI_REFERENCE
CPPFLAGS += -D__CAMERA_ALL

#CPPFLAGS+=-D__DBGLOG

LIBOBJ   = 	zoom \
			test_mode \
			tuning_loader_manager \
			controllingrate \
			sw3A_component_manager \
			sw3A_statemachine \
			zoom_statemachine \
			test_mode_statemachine \
			opmodemgr \
			preview_statemachine \
			rawcapture_statemachine \
			record_statemachine \
			sia_platform_manager \
			boot_statemachine \
			camera \
			hsmcam \
			grabctl \
			grab \
			omxcamera \
			isp_configuring_pipe \
			port_statemachine \
			tuning_statemachine \
			hostnmf_cb \
			camport \
			capture_context \
			mirroring_statemachine \
			cam_shared_memory \
			selftest \
			selftest_statemachine \
			flash \
			framerate \
			lowpower_statemachine\
			powerup_statemachine\
			omxmode_statemachine \
			states \
			extradata

ifeq ($(MM_BUILD_CAM_OMX_3A_EXTENSION),true)
CPPFLAGS += -DCAMERA_ENABLE_OMX_3A_EXTENSION
LIBOBJ += \
	sw3A_component_manager_extension \
	framerate_ext
endif
ifeq ($(MM_BUILD_CAM_OMX_STATS_PORT),true)
CPPFLAGS += -DCAMERA_ENABLE_OMX_STATS_PORT
LIBOBJ += \
	camportstats
endif
INSTALL_HEADER = $(subst include/,,$(shell find include -type f -name "*.h" ))

CPPFLAGS+= -I ${MEDIUM_DIR}/$(BASE_REPOSITORY) 
CPPFLAGS+= -I ${MM_NMF_COMP_SRC_HOSTEE_DIR}/asyncflash/inc

CPPFLAGS+= -I$(OST_COMPONENT_INC)/autogentraces

# Generation of solibs
ifneq ($(findstring symbian,$(PLATFORM)),symbian)
ifneq ($(PLATFORM),x86-linux)
IS_OMX_COMPONENT_LIB=true
include $(MM_MAKEFILES_DIR)/STEOMXLoaderConfig.mk

SOLIBNAMES = ste_camera
LIBOBJ_$(SOLIBNAMES) = ste_omx_ens_component
IMAGE_LIBS = $(LIBNAME) st_stab st_nmx ste3a

ifeq ($(DEBUG),1)
	IMAGE_LIBS += host_trace
endif

IMAGING_NMF_HOST_COMPONENTS = img_network tuningloader_wrp asyncflash_wrp sw_3A_wrp

SOLIBS_$(SOLIBNAMES) += $(IMAGING_NMF_HOST_COMPONENTS_LIBS)
EXTRALIBS_$(SOLIBNAMES) = $(IMAGE_LIBS)

FLAGS_$(SOLIBNAMES) += -lste_ens_image_common -lste_ens_image_tuningdatabase
FLAGS_$(SOLIBNAMES) += $(LDFLAGS_STE_ENS_OMX_COMPONENTS) -llos -lnmftimer

FLAGS_$(SOLIBNAMES) += -lals
ifdef VENDOR_CAMERA_FLASH_LIBRARY
FLAGS_$(SOLIBNAMES) += -l$(VENDOR_CAMERA_FLASH_LIBRARY)
else
FLAGS_$(SOLIBNAMES) += -lcamera_flash
endif

ifdef VENDOR_CURRENT_CALCULATION_LIBRARY
FLAGS_$(SOLIBNAMES) += -l$(VENDOR_CURRENT_CALCULATION_LIBRARY)
else
FLAGS_$(SOLIBNAMES) += -lflash_current_calculation
endif

FLAGS_$(SOLIBNAMES) += -lste_isp8500_firmware_primary -lste_isp8500_firmware_secondary
INSTALL_SOLIB = $(SOLIBNAMES)

endif
endif

todo: lib solib 

src/hsmcam.cpp: $(MY_BUILDGEN_DIR)/src/states.cpp

$(MY_BUILDGEN_DIR)/src/states.cpp: include/hsmcam.h
	echo "/* Autogenerated file of states */" > $@
	echo "/* Regenerate with make $@ */" >> $@
	echo "" >> $@
	echo "#include \"hsmcam.h\"" >> $@
	echo "" >> $@
	echo "const char *CAM_SM::get_state_str(const SCF_PSTATE state) {" >> $@
	echo "  const char *str;" >> $@
	echo "  if (!state) {" >> $@
	echo "    str = \"NULL\";" >> $@
	cpp $(CPPFLAGS) $^ | sed "s/virtual//" | grep "^[[:blank:]]*ScfOneState" | grep "(s_scf_event const \*e)" | grep -v "SHARED_" | grep -v "ControlingISPState_WaitPrepared" | sed "s/(/ /" | awk '{print "  } else if (state == SCF_STATE_PTR(&CAM_SM::"$$3")) {\n    str = \""$$3"\";"}' >> $@
	echo "  } else {" >> $@
	echo "    str = \"UNKNOWN\";" >> $@
	echo "  }" >> $@
	echo "  return str;" >> $@
	echo "}" >> $@

TOBECLEAN =

#-------------------------------
# Generic Rules
#-------------------------------
include $(MM_MAKEFILES_DIR)/SharedRules.mk

ifeq ($(MMSYSTEM),symbian) 
NO_VARIANT=true
include ${MEDIUM_DIR}/symbian_makerules/mmh.mk
endif

