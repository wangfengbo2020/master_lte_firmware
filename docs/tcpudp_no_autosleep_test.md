# TCP/UDP test with automatic sleep disabled

This is a temporary single-variable comparison against commit `25448b5`
(`codex/tcpudp-ack-diagnostics`). The currently registered `ql_power_test2`
initialization now calls `ql_autosleep_enable(QL_NOT_ALLOW_SLEEP)` instead of
`QL_ALLOW_SLEEP`. SDK declarations specify a void return value; the startup log
records the request and does not prove a measured power state.

The SIM/APN setup, server `123.57.79.87:19000`, PDP profile 1, three-second
heartbeat interval, socket receive logic, diagnostics and Broad configuration
are unchanged. Broad kernel remains initialized and application login paused.

## Run the comparison

1. Use the same device, SIM, USB/power connection and server as the preceding
   v0.3-ack-diag test. This firmware deliberately prevents normal automatic
   low-power operation during the experiment; it is not a power-optimized release.
2. Start serial logging before reboot. Confirm both `v0.3-no-autosleep` and
   `[SL][POWER] ACK test: requested QL_NOT_ALLOW_SLEEP` in the startup output.
3. Keep the board running and retain the complete startup plus at least three
   minutes of TCPUDP/network logs. Compare TCP and UDP separately.
4. Correlate with the deployed server's received frames, queued replies and
   TCP_INFO `unacked`/`total_retrans`. `sent` is not proof of delivery.

If application ACKs return consistently, repeat the original diagnostic firmware
under the same conditions before concluding a sleep dependency. If the queues
remain empty and server replies still retransmit, continue with the current
card/APN policy and modem stack investigation; this does not by itself prove a
particular whitelist rule.

Return to `codex/tcpudp-ack-diagnostics` and rebuild (including version-bearing
objects), or flash the previously supplied v0.3-ack-diag package, to restore the
original sleep-allowed behavior. Do not change Broad, receive polling, endpoint
and sleep together when comparing results.

## Evidence motivating this test

The supplied November 3 device log has `select=0`, successful FIONREAD queries
with zero queued bytes, and no raw receive events through sequence 19. It covers
about 54 seconds at the configured interval. The server independently saw only
sequences 2, 27 and 52 on new connections around 75 seconds apart. For the latter
connection it recorded one received frame, one queued reply, `unacked=1`, and
`total_retrans=9` at age 90 seconds. No UDP application records were found for
that test source. These observations narrow the fault to delivery/stack behavior
but do not establish automatic sleep as the cause.
