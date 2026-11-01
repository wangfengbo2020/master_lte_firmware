#!/bin/bash
# flash.sh - Script to extract firmware and flash using QDLoader

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TOOLS_DIR="${SCRIPT_DIR}/tools"
TARGET_DIR="${SCRIPT_DIR}/target"
QDLOADER="${TOOLS_DIR}/QDloader"

set -e

# Check if QDloader exists
if [ ! -f "$QDLOADER" ]; then
    echo "Error: QDloader tool not found at $QDLOADER"
    exit 1
fi

# Ensure QDloader is executable
if [ ! -x "$QDLOADER" ]; then
    chmod +x "$QDLOADER"
fi

# Find the latest zip in target directory
ZIP_FILE=$(find "${TARGET_DIR}" -type f -name "*.zip" | head -n 1)

if [ -z "$ZIP_FILE" ]; then
    echo "Error: No firmware zip file found in ${TARGET_DIR}"
    exit 1
fi

echo "Found firmware package: $ZIP_FILE"

# Extract directory (same as zip name without extension)
EXTRACT_DIR="${ZIP_FILE%.*}"

echo "Extracting firmware to $EXTRACT_DIR..."
unzip -q -o "$ZIP_FILE" -d "$EXTRACT_DIR"

# Find firmware.bin
FIRMWARE_BIN=$(find "$EXTRACT_DIR" -type f -name "firmware.bin" | head -n 1)

if [ -z "$FIRMWARE_BIN" ]; then
    echo "Error: firmware.bin not found after extracting."
    exit 1
fi

echo "Found firmware.bin: $FIRMWARE_BIN"

# Execute QDloader
echo "=================================================="
echo "Starting QDloader to flash firmware.bin"
echo "Command: $QDLOADER -f $FIRMWARE_BIN"
echo "=================================================="

# It may require root permissions to access the USB port, so we use sudo if not root
if [ "$EUID" -ne 0 ]; then
    echo "Requesting sudo privileges for flashing..."
    sudo "$QDLOADER" -f "$FIRMWARE_BIN"
else
    "$QDLOADER" -f "$FIRMWARE_BIN"
fi

echo "Flashing process finished."
