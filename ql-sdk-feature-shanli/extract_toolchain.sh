#!/usr/bin/env bash
# Restore the Linux toolchain from the versioned Git LFS archive.
set -euo pipefail

SDK_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
TOOLCHAIN_NAME=gcc-arm-none-eabi-9-2019-q4-major
TOOLCHAIN_PARENT="${SDK_DIR}/ql-cross-tool/Linux"
TOOLCHAIN_DIR="${TOOLCHAIN_PARENT}/${TOOLCHAIN_NAME}"
ARCHIVE_REL="ql-cross-tool/Linux/${TOOLCHAIN_NAME}-x86_64-linux.tar.bz2"
ARCHIVE="${SDK_DIR}/${ARCHIVE_REL}"
ARCHIVE_SHA256=bcd840f839d5bf49279638e9f67890b2ef3a7c9c7a9b25271e83ec4ff41d177a
force=0
check_only=0
work_dir=

log() { printf '[toolchain] %s\n' "$*"; }
fail() { printf '[toolchain] ERROR: %s\n' "$*" >&2; exit 1; }

case "${1:-}" in
    '') ;;
    --force) force=1 ;;
    --check) check_only=1 ;;
    -h|--help)
        printf 'Usage: %s [--check | --force]\n' "$0"
        printf 'Default: reuse a valid toolchain, otherwise fetch/extract the archive.\n'
        printf -- '--check: validate only; do not download or extract.\n'
        printf -- '--force: extract again; preserve the old directory as a backup.\n'
        exit 0 ;;
    *) fail "Unknown option: $1 (use --help)" ;;
esac
[[ $# -le 1 ]] || fail 'Only one option is supported (use --help).'
[[ "$(uname -s)" == Linux && "$(uname -m)" == x86_64 ]] ||
    fail 'This archive requires x86_64 Linux/WSL. Run it inside an x86_64 Ubuntu/WSL environment.'

toolchain_ready()
{
    local dir="$1"
    local gcc_lib="${dir}/lib/gcc/arm-none-eabi/9.2.1"
    [[ -x "${dir}/bin/arm-none-eabi-gcc" &&
       -x "${dir}/bin/arm-none-eabi-as" &&
       -x "${dir}/bin/arm-none-eabi-ld" &&
       -x "${gcc_lib}/cc1" &&
       -s "${gcc_lib}/libgcc.a" &&
       -s "${dir}/arm-none-eabi/include/stdio.h" &&
       -s "${dir}/arm-none-eabi/lib/libc.a" ]] || return 1
    [[ "$("${dir}/bin/arm-none-eabi-gcc" -dumpmachine 2>/dev/null)" == arm-none-eabi ]] || return 1
    [[ "$("${dir}/bin/arm-none-eabi-gcc" -dumpfullversion 2>/dev/null)" == 9.2.1 ]] || return 1
    "${dir}/bin/arm-none-eabi-as" --version >/dev/null 2>&1 || return 1
    "${dir}/bin/arm-none-eabi-ld" --version >/dev/null 2>&1 || return 1
    "${gcc_lib}/cc1" --version >/dev/null 2>&1 || return 1
}

if toolchain_ready "$TOOLCHAIN_DIR"; then
    if [[ $force == 0 ]]; then
        log "Ready: ${TOOLCHAIN_DIR}"
        "${TOOLCHAIN_DIR}/bin/arm-none-eabi-gcc" --version
        exit 0
    fi
elif [[ $check_only == 1 ]]; then
    fail "Toolchain is missing, incomplete, or cannot run. Execute: bash ${SDK_DIR}/extract_toolchain.sh"
fi

is_lfs_pointer()
{
    [[ -f "$ARCHIVE" ]] &&
        head -c 128 -- "$ARCHIVE" | LC_ALL=C grep -q '^version https://git-lfs.github.com/spec/v1'
}

if [[ ! -f "$ARCHIVE" ]] || is_lfs_pointer; then
    log 'The archive is missing or is only a Git LFS pointer; attempting a targeted LFS download.'
    command -v git >/dev/null 2>&1 || fail 'Install Git and Git LFS, then clone this repository with git clone.'
    git_root="$(git -C "$SDK_DIR" rev-parse --show-toplevel 2>/dev/null)" ||
        fail 'No Git checkout found. A source ZIP may contain only LFS pointers. Clone the repository with Git and run git lfs pull.'
    git_prefix="$(git -C "$SDK_DIR" rev-parse --show-prefix)"
    git_archive="${git_prefix}${ARCHIVE_REL}"
    git -C "$git_root" ls-files --error-unmatch -- "$git_archive" >/dev/null 2>&1 ||
        fail 'This archive is not tracked by the enclosing Git repository. Use a complete clone of master_lte_firmware.'
    git -C "$git_root" lfs version >/dev/null 2>&1 ||
        fail 'Git LFS is unavailable. On Ubuntu: sudo apt-get install git-lfs; then git lfs install, and rerun this script.'
    git -C "$git_root" lfs pull --include="$git_archive" --exclude='' ||
        fail 'Git LFS download failed. Check repository access/network and rerun; no existing toolchain was replaced.'
fi

[[ -f "$ARCHIVE" ]] || fail "Archive still missing: ${ARCHIVE}"
if is_lfs_pointer; then
    fail 'The archive is still a Git LFS pointer. Complete git lfs pull before extracting.'
fi
for dependency in tar bzip2 sha256sum mktemp; do
    command -v "$dependency" >/dev/null 2>&1 || fail "Missing ${dependency}; install it before extracting."
done

log 'Verifying the toolchain archive SHA256...'
actual_sha="$(sha256sum -- "$ARCHIVE")"
[[ "${actual_sha%% *}" == "$ARCHIVE_SHA256" ]] ||
    fail 'Archive SHA256 mismatch: it is incomplete, corrupted, or not the expected release. Restore it from Git LFS.'

cleanup()
{
    if [[ -n "$work_dir" && "$work_dir" == "${TOOLCHAIN_PARENT}/.toolchain-extract."* && -d "$work_dir" ]]; then
        rm -rf -- "$work_dir"
    fi
}
trap cleanup EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
mkdir -p -- "$TOOLCHAIN_PARENT"
work_dir="$(mktemp -d "${TOOLCHAIN_PARENT}/.toolchain-extract.XXXXXX")"
log "Extracting ${ARCHIVE_REL}..."
tar --extract --bzip2 --file="$ARCHIVE" --directory="$work_dir" --no-same-owner
extracted="${work_dir}/${TOOLCHAIN_NAME}"
toolchain_ready "$extracted" ||
    fail 'Extracted compiler is incomplete or cannot run on this host. Check x86_64 Linux runtime dependencies; the old directory is untouched.'

# Exercise headers, cc1 and the assembler before replacing any old directory.
printf '#include <stdint.h>\n#include <stdio.h>\nint toolchain_probe(void) { return sizeof(uint32_t) + sizeof(FILE); }\n' |
    "${extracted}/bin/arm-none-eabi-gcc" -mcpu=cortex-r4 -mthumb -mfloat-abi=soft \
        -x c -c -o "${work_dir}/probe.o" - || fail 'The extracted compiler failed its ARM compilation check.'

backup_dir=
if [[ -e "$TOOLCHAIN_DIR" || -L "$TOOLCHAIN_DIR" ]]; then
    backup_dir="$(mktemp -d "${TOOLCHAIN_PARENT}/.toolchain-backup.XXXXXX")"
    mv -- "$TOOLCHAIN_DIR" "${backup_dir}/${TOOLCHAIN_NAME}"
    log "Previous directory preserved at: ${backup_dir}/${TOOLCHAIN_NAME}"
fi
if ! mv -- "$extracted" "$TOOLCHAIN_DIR"; then
    if [[ -n "$backup_dir" ]]; then
        mv -- "${backup_dir}/${TOOLCHAIN_NAME}" "$TOOLCHAIN_DIR"
    fi
    fail 'Could not install the extracted toolchain.'
fi
log "Ready: ${TOOLCHAIN_DIR}"
"${TOOLCHAIN_DIR}/bin/arm-none-eabi-gcc" --version
