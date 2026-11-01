#!/bin/bash

CUR_DIR="$( cd "$( dirname ${BASH_SOURCE[0]} )" && pwd )"
TOP_DIR=${CUR_DIR}/..
_7Z=${CUR_DIR}/7za
DIFF=${CUR_DIR}/diff 

if [[ ! -e ${TOP_DIR}/tools/aboot-x64/images/system.img ]];then
    exit 0
fi

VERSION="FIRMWARE_PACKAGE"
if [ -e $TOP_DIR/config/profile/version ]; then
    VERSION=$(grep "VERSION:" $TOP_DIR/config/profile/version | sed 's/VERSION://g' | xargs echo -n)
fi

${_7Z} x ${TOP_DIR}/target/${VERSION}/${VERSION}.zip -o${TOP_DIR}/target/tmp > /dev/null

RET=$(${DIFF} ${TOP_DIR}/target/tmp/system.img  ${TOP_DIR}/tools/aboot-x64/images/system.img)
rm -rf ${TOP_DIR}/target/tmp

if [[ ${RET} != "" ]];then
    echo -e "\033[31;1mWARNING:System.img has been changed! \033[0m"
    exit 1
fi



