#!/bin/bash
#===============================================================================
# QL-SDK Linux 一键编译打包脚本
# 用法:
#   ./build.sh              # 编译App + 打包固件 (等同于 ./build.sh all)
#   ./build.sh app          # 仅编译App层
#   ./build.sh firmware     # 仅打包固件 (需先编译App)
#   ./build.sh clean        # 清理所有编译产物
#   ./build.sh rebuild      # 清理后重新编译+打包
#===============================================================================

set -e

# 获取脚本所在目录（即 ql-sdk 根目录）
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
APP_DIR="${SCRIPT_DIR}/ql-application/threadx"
TARGET_DIR="${SCRIPT_DIR}/target"

# 颜色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

print_step() {
    echo -e "${CYAN}======================================${NC}"
    echo -e "${CYAN}  $1${NC}"
    echo -e "${CYAN}======================================${NC}"
}

print_ok() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warn() {
    echo -e "${YELLOW}⚠️  $1${NC}"
}

print_err() {
    echo -e "${RED}❌ $1${NC}"
}

#-------------------------------------------------------------------------------
# 清理编译产物
#-------------------------------------------------------------------------------
do_clean() {
    print_step "清理编译产物..."

    # 清理 App 层 build 目录
    if [ -d "${APP_DIR}/build" ]; then
        rm -rf "${APP_DIR}/build"
        echo "  已清理: ql-application/threadx/build/"
    fi

    # 清理各子模块 build 目录
    find "${APP_DIR}/interface" -type d -name "build" -exec rm -rf {} + 2>/dev/null || true
    echo "  已清理: interface/*/build/"

    # 清理 App 层 target 输出目录
    if [ -d "${APP_DIR}/target" ]; then
        rm -rf "${APP_DIR}/target"
        echo "  已清理: ql-application/threadx/target/"
    fi

    # 清理根目录 target
    if [ -d "${TARGET_DIR}" ]; then
        rm -rf "${TARGET_DIR}"
        echo "  已清理: ql-sdk/target/"
    fi

    print_ok "清理完成"
}

#-------------------------------------------------------------------------------
# 编译 App 层
#-------------------------------------------------------------------------------
do_compile_app() {
    bash "${SCRIPT_DIR}/extract_toolchain.sh"
    print_step "编译 App 层 (GCC arm-none-eabi)..."

    cd "${APP_DIR}"
    make -f Makefile PLATFORM=linux

    # 检查编译结果
    if [ -f "${APP_DIR}/build/app.bin" ]; then
        local size=$(stat -c%s "${APP_DIR}/build/app.bin")
        print_ok "App 编译成功! (app.bin: ${size} bytes)"
    else
        print_err "App 编译失败: app.bin 未生成"
        exit 1
    fi

    cd "${SCRIPT_DIR}"
}

#-------------------------------------------------------------------------------
# 打包固件 (make 的 Linux 分支已包含打包步骤)
# 如果 make PLATFORM=linux 已经自动打包，则这里只做结果搬运
#-------------------------------------------------------------------------------
do_firmware() {
    print_step "打包固件..."

    # make PLATFORM=linux 的 Linux 分支会自动调用 arelease.sh 打包
    # 固件生成在 ql-application/threadx/target/ 下
    local FW_DIR="${APP_DIR}/target"

    if [ ! -d "${FW_DIR}" ]; then
        print_err "未找到固件输出目录: ${FW_DIR}"
        print_warn "请先执行 ./build.sh app 编译"
        exit 1
    fi

    # 查找生成的 .zip 固件包
    local ZIP_FILE=$(find "${FW_DIR}" -maxdepth 2 -name "*.zip" -type f | head -1)

    if [ -z "${ZIP_FILE}" ]; then
        print_err "未找到固件包 (.zip)"
        exit 1
    fi

    # 将固件复制到 ql-sdk 根目录的 target/ 下（方便查找）
    mkdir -p "${TARGET_DIR}"
    cp -r "${FW_DIR}"/* "${TARGET_DIR}/"

    local FW_NAME=$(basename "${ZIP_FILE}")
    print_ok "固件打包成功!"
    echo ""
    echo -e "  固件位置 (原始): ${YELLOW}${ZIP_FILE}${NC}"
    echo -e "  固件位置 (副本): ${YELLOW}${TARGET_DIR}/${NC}"
    echo -e "  固件文件名:      ${GREEN}${FW_NAME}${NC}"
    echo ""
}

#-------------------------------------------------------------------------------
# 显示帮助信息
#-------------------------------------------------------------------------------
do_help() {
    echo ""
    echo "QL-SDK Linux 编译脚本"
    echo ""
    echo "用法: ./build.sh [命令]"
    echo ""
    echo "命令:"
    echo "  all       编译 App + 打包固件 (默认)"
    echo "  app       仅编译 App 层"
    echo "  firmware  仅打包固件 (需先编译 App)"
    echo "  clean     清理所有编译产物"
    echo "  rebuild   清理后重新编译 + 打包"
    echo "  help      显示帮助信息"
    echo ""
    echo "示例:"
    echo "  ./build.sh              # 完整编译+打包"
    echo "  ./build.sh clean        # 清理"
    echo "  ./build.sh rebuild      # 清理后重新编译"
    echo ""
}

#-------------------------------------------------------------------------------
# 主入口
#-------------------------------------------------------------------------------
BUILD_TARGET="${1:-all}"

echo ""
echo -e "${GREEN}╔══════════════════════════════════════╗${NC}"
echo -e "${GREEN}║   QL-SDK Linux Build System          ║${NC}"
echo -e "${GREEN}╚══════════════════════════════════════╝${NC}"
echo ""

case "${BUILD_TARGET}" in
    clean)
        do_clean
        ;;
    app)
        do_compile_app
        ;;
    firmware)
        do_firmware
        ;;
    all)
        do_compile_app
        do_firmware
        ;;
    rebuild)
        do_clean
        do_compile_app
        do_firmware
        ;;
    help|-h|--help)
        do_help
        ;;
    *)
        print_err "未知命令: ${BUILD_TARGET}"
        do_help
        exit 1
        ;;
esac

echo ""
print_ok "完成!"
echo ""
