#ifndef LTE_TCPUDP_HEARTBEAT_H
#define LTE_TCPUDP_HEARTBEAT_H

/* Change these for the test server and rebuild the firmware. */
#define LTE_HEARTBEAT_SERVER_IP "123.57.79.87"
#define LTE_HEARTBEAT_SERVER_PORT 19000
#define LTE_HEARTBEAT_INTERVAL_S 3

int lte_tcpudp_heartbeat_start(void);
void lte_tcpudp_heartbeat_network_changed(int ready);

#endif
