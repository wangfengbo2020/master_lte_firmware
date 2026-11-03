# TCP/UDP ACK diagnosis (v0.3-ack-diag)

This version adds observation to the v0.2 PDP-bound client. It keeps the server
123.57.79.87:19000, profile 1, three-second send interval, nonblocking sockets,
existing receive path and reconnection behaviour. Broad application login remains
paused, while its kernel stays initialized. Autosleep configuration is unchanged.

## Device capture

Start the serial logger before resetting the board and keep at least 180 seconds
of output. Include the startup version/branch, PDP address, all TCPUDP lines, and
any network-down events. Do not send just the successful-send lines.

The test marker must be `v0.3-ack-diag`. `tick` is the SDK's raw tick count since
reset; it is not labelled milliseconds. Correlate the two endpoints using the
heartbeat sequence and socket endpoint/session, not equal wall-clock timestamps.

| Device log | Interpretation |
| --- | --- |
| `TCP/UDP session=... fd=...` | New socket lifetime; a descriptor may be reused. |
| `sent seq=... bytes=...` | The local socket accepted these bytes; delivery is not established. |
| `poll ... select=0 pending_bytes=0` | At this poll the application socket reported no queued receive bytes. This does not locate a network loss. |
| `poll ... pending_ret=-1` | The optional FIONREAD diagnostic failed; normal select/receive handling continues. |
| `poll ... select=0 pending_bytes>0` | Potential receive readiness discrepancy; correlate subsequent polls and raw receives. |
| `rx_raw ... bytes>0 first_hex=...` | The application actually read bytes, before newline parsing or UDP source checks. The hex preview is limited to 24 bytes. |
| `UDP rx_peer ... accepted=0` | The reply source differs from the configured IP or port and is ignored. |
| `TCP rx_buffer ... remaining>0` | Partial data is retained awaiting a newline. |
| `summary ...` | Counters accumulated since the heartbeat task started, across reconnects; receive frames are not asserted to be valid ACKs. |

The diagnostics do not bypass select, change its zero timeout, disable sleep,
change TCP_NODELAY, or trigger new ACK timeouts. Changing several of those at
once would make the existing fault harder to isolate.

## Server correlation

Use service logs together with a packet capture covering an entire new connection
and its eventual failure/reconnect. Limit capture to this test port (and the LTE
public source address once identified). Save the capture securely on the ECS.

The server's application `ACK queued` is different from a TCP acknowledgment.
Check whether the server emits the reply, whether its TCP sequence range is
acknowledged by the peer, and whether that same range is retransmitted. Where
available, server TCP_INFO unacked/retransmission counters add corroborating
evidence; they do not prove the LTE application read the reply.

- Server reply repeatedly unacknowledged: investigate the return path, card/APN
  policy and modem TCP/IP stack. Do not attribute this to select alone.
- Reply acknowledged at TCP level but no device raw receive: investigate the
  module's receive queue/readiness and application scheduling.
- Raw receive exists but no normal received log: inspect framing or UDP source
  filtering using the preceding diagnostic lines.
- No LTE UDP in the server capture: the packet did not reach that capture point;
  this alone cannot separate module transmission from upstream filtering.

If needed, compare the same firmware/server using a known unrestricted test SIM
with its correct APN. Test autosleep separately only after collecting the baseline;
leave Broad kernel and the other settings unchanged during each comparison.

## Validation and build

From `ql-sdk-feature-shanli`, run:

```sh
bash ql-application/threadx/interface/poc/tests/run_host_tests.sh
./build.sh
```

The host tests mock the SDK and are not a board/4G test. After a new commit, ensure
the version-bearing sources `example_poc.c` and `fota_version_check.c` are rebuilt:
the existing Makefile computes Git defines but does not track changes in those
defines as object dependencies. Touch those two sources before the final build,
or force an application rebuild. This avoids old/new Git strings in one image.

Changing `LTE_HEARTBEAT_DIAGNOSTICS` to 0 removes detailed poll/raw preview queries
but keeps connection, receive and summary logs. Disable it only for a separate
comparison; the supplied diagnostic image uses the default value 1.
