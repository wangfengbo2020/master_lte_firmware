#!/usr/bin/env bash
# Run from any working directory. This compiles the adjacent production C
# through mocks; it neither opens network sockets nor accesses a modem.
set -euo pipefail
test_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
test_binary=$(mktemp /tmp/lte-heartbeat-host-XXXXXX)
trap 'rm -f -- "$test_binary"' EXIT
"${CC:-gcc}" -std=c99 -Wall -Wextra -Werror -I "$test_dir/mocks" \
    "$test_dir/heartbeat_host_test.c" -o "$test_binary"
"$test_binary"
