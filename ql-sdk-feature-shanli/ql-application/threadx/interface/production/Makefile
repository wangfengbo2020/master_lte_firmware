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
  production_test.c \

#-------------------------------------------------------------------------------
# the include directories
#-------------------------------------------------------------------------------
INC_DIRS+= \
  -I${TOP_DIR}/ \
  -I${TOP_DIR}/common/include \
  -I${TOP_DIR}/common/include/lwipv4v6 \
  -I${TOP_DIR}/interface/poc \

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
  -DENABLE_PRODUCTION_TEST \
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
