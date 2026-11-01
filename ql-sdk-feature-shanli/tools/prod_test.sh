#!/bin/bash
# E02T Production AT command test script
# Usage: ./prod_test.sh [/dev/ttyACM0]

PORT="${1:-/dev/ttyACM0}"
TIMEOUT=5
PASS=0
FAIL=0
SKIP=0

if [ ! -e "$PORT" ]; then
    echo "ERROR: $PORT not found. Is the device connected?"
    exit 1
fi

# Configure serial port
stty -F "$PORT" 115200 raw -echo -echoe -echok -echoctl -echoke

# Open port for read/write
exec 3<>"$PORT"

send_cmd() {
    local cmd="$1"
    local expect="$2"
    local timeout="${3:-$TIMEOUT}"
    local response=""
    local line=""

    # Flush input
    while read -r -t 0.1 line <&3 2>/dev/null; do :; done

    # Send command
    printf "%s\r\n" "$cmd" >&3

    # Read response lines until OK/ERROR or timeout
    local start=$(date +%s)
    while true; do
        if read -r -t 1 line <&3 2>/dev/null; then
            line=$(echo "$line" | tr -d '\r')
            [ -z "$line" ] && continue
            if [ -z "$response" ]; then
                response="$line"
            else
                response="$response | $line"
            fi
            # Stop on OK or ERROR
            case "$line" in
                OK|ERROR) break ;;
            esac
        fi
        local now=$(date +%s)
        if [ $((now - start)) -ge "$timeout" ]; then
            response="${response:-(timeout)}"
            break
        fi
    done

    # Check result
    local status="?"
    case "$response" in
        *OK*)
            if [ -n "$expect" ]; then
                if echo "$response" | grep -q "$expect"; then
                    status="PASS"
                    PASS=$((PASS + 1))
                else
                    status="FAIL(expect:$expect)"
                    FAIL=$((FAIL + 1))
                fi
            else
                status="PASS"
                PASS=$((PASS + 1))
            fi
            ;;
        *ERROR*|*timeout*)
            status="FAIL"
            FAIL=$((FAIL + 1))
            ;;
        *)
            status="FAIL(unexpected)"
            FAIL=$((FAIL + 1))
            ;;
    esac

    printf "  %-25s %-6s %s\n" "$cmd" "$status" "$response"
}

send_cmd_skip() {
    local cmd="$1"
    local reason="$2"
    printf "  %-25s %-6s %s\n" "$cmd" "SKIP" "$reason"
    SKIP=$((SKIP + 1))
}

echo "========================================"
echo " E02T Production Test"
echo " Port: $PORT"
echo " Date: $(date)"
echo "========================================"
echo ""

# ---- Always-allowed commands (no PROD mode needed) ----
echo "[1/5] Always-allowed commands"
echo "----------------------------------------"
send_cmd "AT+CAP?" "+CAP:"
send_cmd "AT+VER?" "+VER:"
send_cmd "AT+DEV?" "+DEV:"
echo ""

# ---- Enter production mode ----
echo "[2/5] Enter production mode"
echo "----------------------------------------"
send_cmd "AT+PROD=1" "+PROD:OK" 10
echo ""

# ---- Config commands ----
echo "[3/5] Config commands"
echo "----------------------------------------"
send_cmd "AT+CFGINFO?" "+CFGINFO:"
send_cmd "AT+CFGSTART" "+CFGSTART:OK"
send_cmd 'AT+CFGSET="gps_enable=0"' "+CFGSET:OK"
send_cmd 'AT+CFGSET="version=test1"' "+CFGSET:OK"
send_cmd "AT+CFGSAVE" "+CFGSAVE:OK"
send_cmd "AT+CFGREAD?" "+CFGREAD:"
send_cmd "AT+CFGINFO?" "VERSION=test1"
send_cmd "AT+CFGDEF" "+CFGDEF:OK"
send_cmd "AT+CFGINFO?" "EXIST=0"
# Restore original config
send_cmd "AT+CFGSTART" "+CFGSTART:OK"
send_cmd 'AT+CFGSET="gps_enable=0"' "+CFGSET:OK"
send_cmd "AT+CFGSAVE" "+CFGSAVE:OK"
echo ""

# ---- Modem self-test commands ----
echo "[4/5] Modem self-test commands"
echo "----------------------------------------"
send_cmd "AT+MDINFO?" "+MDINFO:" 10
send_cmd "AT+MDSIM?" "+MDSIM:" 5
send_cmd "AT+MDREG?" "+MDREG:" 5
send_cmd "AT+MDSIG?" "+MDSIG:" 5
send_cmd "AT+MDDATA?" "+MDDATA:" 15
send_cmd 'AT+MDDNS="www.baidu.com"' "+MDDNS:" 15
send_cmd 'AT+MDPING="8.8.8.8",2' "+MDPING:" 20
# AT+MDALL takes a while (includes ping)
send_cmd "AT+MDALL?" "+MDALL:" 30
echo ""

# ---- MCU bridge commands ----
echo "[5/5] MCU bridge commands (need MCU connected)"
echo "----------------------------------------"
send_cmd "AT+MCUBVER?" "" 5
send_cmd "AT+MCUMAC?" "" 5
send_cmd "AT+MCUCHG?" "" 5
send_cmd "AT+MCUVBAT?" "" 5
echo ""

# ---- Exit production mode ----
echo "[EXIT] Exit production mode"
echo "----------------------------------------"
send_cmd "AT+PROD=0" "+PROD:OK" 10
echo ""

# ---- Verify mode-gating works ----
echo "[GATE] Verify commands blocked outside PROD mode"
echo "----------------------------------------"
send_cmd "AT+MDINFO?" ""
# Should get ERR,MODE - check for ERROR in response
printf "  %-25s " "(expect ERR,MODE)"
if echo "$response" 2>/dev/null | grep -q "MODE"; then
    echo "PASS   Mode gating works"
    PASS=$((PASS + 1))
else
    echo "OK     (already counted above)"
fi
echo ""

# ---- Summary ----
exec 3>&-
echo "========================================"
echo " Results: PASS=$PASS  FAIL=$FAIL  SKIP=$SKIP"
echo "========================================"

if [ "$FAIL" -gt 0 ]; then
    exit 1
fi
exit 0
