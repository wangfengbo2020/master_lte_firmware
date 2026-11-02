
#-------------------------------------------------------------------------------
# Configure variable
#-------------------------------------------------------------------------------
TOP_DIR:=$(TOP_DIR)
ROOT_DIR:=$(TOP_DIR)/../..
MAKEFILE_PATH :=$(subst $(strip \),/,$(abspath $(lastword $(MAKEFILE_LIST))))


#-------------------------------------------------------------------------------
# Configure source code files
#-------------------------------------------------------------------------------
SRC_FILES+= \
  example_poc.c \
  lte_tcpudp_heartbeat.c \
  e02t_uart_mcu.c \
  e02t_config.c \
  tts_gbk.c \
  fota_test.c \
  fota_version_check.c \
  mqtt_remote_control.c \
  cJSON.c \
  base64.c \
  example_cell_locator.c \


#-------------------------------------------------------------------------------
# the include directories
#-------------------------------------------------------------------------------
INC_DIRS+= \
  -I${TOP_DIR}/ \
  -I${TOP_DIR}/interface/log/inc \
  -I${TOP_DIR}/common/include \
  -I${TOP_DIR}/common/include/lwipv4v6 \
  -I${TOP_DIR}/common/include/mqtt \




#-------------------------------------------------------------------------------
# Configure compile flag for C
#-------------------------------------------------------------------------------
U_FLAGS:=

#-------------------------------------------------------------------------------
# Configure compile flag for C++
#-------------------------------------------------------------------------------
U_CPPFLAGS:=

#-------------------------------------------------------------------------------
# Configure default macro define
#-------------------------------------------------------------------------------
# Auto-generate version info from git (based on tags)
# NOTE: $(shell ...) runs under sh on Linux but cmd.exe on the Windows/ARMCC
# build (gnumake, no PLATFORM=linux). cmd has no /dev/null and echoes quotes
# literally, so the redirect target must differ and echo must stay unquoted.
ifeq ($(PLATFORM),linux)
GIT_VERSION := $(shell git describe --tags --always --dirty 2>/dev/null || echo unknown)
GIT_COMMIT_DATE := $(shell git log -1 --format=%cd --date=short 2>/dev/null || echo unknown)
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null || echo unknown)
else
GIT_VERSION := $(shell git describe --tags --always --dirty 2>NUL || echo unknown)
GIT_COMMIT_DATE := $(shell git log -1 --format=%%cd --date=short 2>NUL || echo unknown)
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>NUL || echo unknown)
endif

DFLAGS+= \
  -DGIT_VERSION=\"$(GIT_VERSION)\" \
  -DGIT_COMMIT_DATE=\"$(GIT_COMMIT_DATE)\" \
  -DGIT_BRANCH=\"$(GIT_BRANCH)\" \


#-------------------------------------------------------------------------------
# Configure link library
#-------------------------------------------------------------------------------
U_LIBS:=

#-------------------------------------------------------------------------------
# include mk file
#-------------------------------------------------------------------------------
include ${TOP_DIR}/config/common/makefile.mk
