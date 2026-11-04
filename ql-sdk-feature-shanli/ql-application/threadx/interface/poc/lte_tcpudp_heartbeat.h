#ifndef LTE_TCPUDP_HEARTBEAT_H
#define LTE_TCPUDP_HEARTBEAT_H

/* Change these for the test server and rebuild the firmware. */
#define LTE_HEARTBEAT_SERVER_HOST "sip.paitalk.com"
#define LTE_HEARTBEAT_SERVER_PORT 19000
#define LTE_HEARTBEAT_INTERVAL_S 3
#define LTE_HEARTBEAT_PROFILE_IDX 1
#define LTE_HEARTBEAT_CONNECT_TIMEOUT_S 15
#define LTE_HEARTBEAT_TEST_VERSION "v0.4-domain-no-autosleep"

/* Diagnostic-only queries; keep the socket and three-second send behaviour. */
#ifndef LTE_HEARTBEAT_DIAGNOSTICS
#define LTE_HEARTBEAT_DIAGNOSTICS 1
#endif

int lte_tcpudp_heartbeat_start(void);
void lte_tcpudp_heartbeat_network_changed(int profile_idx, int ready);

#endif
