
#-------------------------------------------------------------------------------
# Configure variable
#-------------------------------------------------------------------------------
TOP_DIR:=${TOP_DIR}
MAKEFILE_PATH :=$(subst $(strip \),/,$(abspath $(lastword $(MAKEFILE_LIST))))


#-------------------------------------------------------------------------------
# Configure source code files
#-------------------------------------------------------------------------------
SRC_FILES+= \
  quec_iic.c \
  quec_atcmd_general.c \
  quec_audio.c \
  quec_led_task.c \
  platform_shim_api.c \
  usim.c \
  ps_api.c \
  gps_app.c \
  quec_uart_at.c \
  ql_nand_fs.c \
  ReliableData.c \
  telps_mini.c \
  quec_atcmd_network.c \
  quec_atcmd_sim.c \
  quec_atcmd_slas.c \
  quec_gpio.c \
  usim_hw.c \
  quec_siolib.c \
  quec_iot_app.c \
  dev_api.c \
  quec_atcmd_camera.c \
  ntp.c \


#-------------------------------------------------------------------------------
# the include directories
#-------------------------------------------------------------------------------
INC_DIRS+= \
  -I${TOP_DIR}\ \
  -I${TOP_DIR}\common\include \


#-------------------------------------------------------------------------------
# Configure compile flag for C
#-------------------------------------------------------------------------------
U_FLAGS+= \
  -DENV_XSCALE \

#-------------------------------------------------------------------------------
# Configure compile flag for C++
#-------------------------------------------------------------------------------
U_CPPFLAGS+=

#-------------------------------------------------------------------------------
# Configure default macro define
#-------------------------------------------------------------------------------
DFLAGS+= \
  -D"NO_APLP=0" \
  -DCCI_DAT_CONTIGUOUS \
  -DCCI_PB_CONTIGUOUS \
  -DCCI_DEV_CONTIGUOUS \
  -DUPGRADE_R99 \
  -DGPC_NO_CHANNEL_PROTECTION \
  -DENV_MANITOBA \
  -D"GPRS_MULTISLOT_CLASS=12" \
  -DCCI_PS_CONTIGUOUS \
  -DMSL_ICAT_TRACE \
  -DCCI_SS_CONTIGUOUS \
  -DCCI_SIM_CONTIGUOUS \
  -DCCI_POSITION_LOCATION \
  -DCCI_CC_CONTIGUOUS \
  -DGPIO_TRACE \
  -D"EGPRS_MULTISLOT_CLASS=12" \
  -DCCI_MSG_CONTIGUOUS \
  -DCCI_MM_CONTIGUOUS \
  -DCCI_CMN_CONTIGUOUS \


#-------------------------------------------------------------------------------
# Configure link library
#-------------------------------------------------------------------------------
U_LIBS:=

#-------------------------------------------------------------------------------
# include mk file
#-------------------------------------------------------------------------------
include ${TOP_DIR}\config\common\makefile.mk
