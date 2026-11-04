#!/bin/bash
# burn.sh - 解压固件包到 image4burn 目录

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

ZIP_FILE="./target/LTE01R06A16_C_SDK_A/LTE01R06A16_C_SDK_A.zip"
DEST_DIR="./image4burn"

if [ ! -f "$ZIP_FILE" ]; then
    echo "Error: firmware package not found: $ZIP_FILE" >&2
    exit 1
fi

# 清空并重建输出目录
rm -rf "$DEST_DIR"
mkdir -p "$DEST_DIR"

# 复制固件包并解压到输出目录
cp "$ZIP_FILE" "$DEST_DIR/"
unzip -o "$DEST_DIR/$(basename "$ZIP_FILE")" -d "$DEST_DIR"

echo "Extracted firmware to $DEST_DIR"

sudo ./tools/QDloader -f ./image4burn/firmware.bin