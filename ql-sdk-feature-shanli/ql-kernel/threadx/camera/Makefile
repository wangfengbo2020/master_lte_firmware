
#-------------------------------------------------------------------------------
# Configure variable
#-------------------------------------------------------------------------------
TOP_DIR:=${TOP_DIR}
MAKEFILE_PATH :=$(subst $(strip \),/,$(abspath $(lastword $(MAKEFILE_LIST))))


#-------------------------------------------------------------------------------
# Configure source code files
#-------------------------------------------------------------------------------
SRC_FILES+= \
  cam-hal\camera_hal_core.c \
  cam-hal\media_clk.c \
  online_drv\pipeline\cam_pipeline_reg.c \
  cam_sensor.c \
  cam-hal\cam_hal_drv_interface.c \
  cam_sensor_spi_bf30a2.c \
  online_drv\pipeline\cam_tuning.c \
  offline_drv\cpp\scaler_rotation.c \
  online_drv\pipeline\cam_pipeline.c \
  cam_sensor_spi_bf3901.c \
  offline_drv\cpp\cam_offline.c \
  ql_camera.c \
  online_drv\pipeline\cam_fe.c \
  cam_sensor_spi_bf20a6.c \
  cam_sensor_spi_gc6133.c \
  quec_camera.c \
  cam_sensor_spi_gc032a.c \
  quec_qr_code.c \
  cam_sensor_spi_bf20a2.c \
  cam-hal\camera_hal_dev_ops.c \


#-------------------------------------------------------------------------------
# the include directories
#-------------------------------------------------------------------------------
INC_DIRS+= \
  -I${TOP_DIR}\ \
  -I${TOP_DIR}\common\include\tuning \
  -I${TOP_DIR}\common\include \


#-------------------------------------------------------------------------------
# Configure compile flag for C
#-------------------------------------------------------------------------------
U_FLAGS+= \

#-------------------------------------------------------------------------------
# Configure compile flag for C++
#-------------------------------------------------------------------------------
U_CPPFLAGS+=

#-------------------------------------------------------------------------------
# Configure default macro define
#-------------------------------------------------------------------------------
DFLAGS+= \
  -D"NO_APLP=0" \
  -D"GPRS_MULTISLOT_CLASS=12" \
  -D"EGPRS_MULTISLOT_CLASS=12" \


#-------------------------------------------------------------------------------
# Configure link library
#-------------------------------------------------------------------------------
U_LIBS:=

#-------------------------------------------------------------------------------
# include mk file
#-------------------------------------------------------------------------------
include ${TOP_DIR}\config\common\makefile.mk
