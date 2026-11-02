#include <stdio.h>
#include <string.h>

#include "inet.h"
#include "ql_rtos.h"
#include "sl_log.h"
#include "sockets.h"
#include "lte_tcpudp_heartbeat.h"

/* Only the data-call callback writes this flag; the heartbeat task reads it. */
static volatile int network_ready;
static ql_task_t heartbeat_task;

void lte_tcpudp_heartbeat_network_changed(int ready)
{
    network_ready = ready != 0;
}

static void close_socket(int *fd)
{
    if (*fd >= 0)
    {
        close(*fd);
        *fd = -1;
    }
}

static int make_nonblocking(int fd)
{
    unsigned long enabled = 1;
    return ioctl(fd, FIONBIO, &enabled);
}

static void heartbeat_main(void *arg)
{
    struct sockaddr_in server;
    int tcp = -1, udp = -1, connected = 0, connecting = 0;
    unsigned int seq = 0, connect_ticks = 0;
    char tcp_rx[512];
    size_t tcp_rx_used = 0;
    (void)arg;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(LTE_HEARTBEAT_SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(LTE_HEARTBEAT_SERVER_IP);
    SL_LOG("TCPUDP", "v0.1 server=%s:%d interval=%ds", LTE_HEARTBEAT_SERVER_IP,
           LTE_HEARTBEAT_SERVER_PORT, LTE_HEARTBEAT_INTERVAL_S);

    while (1)
    {
        char packet[96];
        int length, sent;
        if (!network_ready)
        {
            if (tcp >= 0 || udp >= 0)
                SL_LOG("TCPUDP", "network down; closing sockets");
            close_socket(&tcp);
            close_socket(&udp);
            connected = connecting = 0;
            connect_ticks = 0;
            tcp_rx_used = 0;
            ql_rtos_task_sleep_s(LTE_HEARTBEAT_INTERVAL_S);
            continue;
        }

        /* Poll for replies without blocking the existing three-second loop. */
        if (udp >= 0)
        {
            int i;
            for (i = 0; i < 4; ++i)
            {
                fd_set read_set;
                struct timeval timeout = {0, 0};
                struct sockaddr_in peer;
                socklen_t peer_len = sizeof(peer);
                char reply[512];
                int n;
                FD_ZERO(&read_set);
                FD_SET(udp, &read_set);
                if (select(udp + 1, &read_set, NULL, NULL, &timeout) <= 0)
                    break;
                n = recvfrom(udp, reply, sizeof(reply) - 1, 0, (struct sockaddr *)&peer, &peer_len);
                if (n <= 0)
                    break;
                if (peer.sin_addr.s_addr != server.sin_addr.s_addr || peer.sin_port != server.sin_port)
                    continue;
                reply[n] = '\0';
                SL_LOG("TCPUDP", "UDP received: %s", reply);
            }
        }
        if (tcp >= 0 && connected)
        {
            fd_set read_set;
            struct timeval timeout = {0, 0};
            FD_ZERO(&read_set);
            FD_SET(tcp, &read_set);
            if (select(tcp + 1, &read_set, NULL, NULL, &timeout) > 0)
            {
                int n = recv(tcp, tcp_rx + tcp_rx_used, sizeof(tcp_rx) - 1 - tcp_rx_used, 0);
                if (n <= 0)
                {
                    SL_LOG("TCPUDP", "TCP disconnected; reconnecting");
                    close_socket(&tcp);
                    connected = 0;
                    tcp_rx_used = 0;
                }
                else
                {
                    char *newline;
                    tcp_rx_used += (size_t)n;
                    while ((newline = memchr(tcp_rx, '\n', tcp_rx_used)) != NULL)
                    {
                        size_t frame = (size_t)(newline - tcp_rx) + 1;
                        SL_LOG("TCPUDP", "TCP received: %.*s", (int)frame, tcp_rx);
                        memmove(tcp_rx, tcp_rx + frame, tcp_rx_used - frame);
                        tcp_rx_used -= frame;
                    }
                    if (tcp_rx_used == sizeof(tcp_rx) - 1)
                    {
                        SL_LOG("TCPUDP", "TCP reply too long; reconnecting");
                        close_socket(&tcp);
                        connected = 0;
                        tcp_rx_used = 0;
                    }
                }
            }
        }
        ++seq;
        length = snprintf(packet, sizeof(packet), "LTE heartbeat seq=%u\n", seq);
        if (udp < 0)
        {
            udp = socket(AF_INET, SOCK_DGRAM, 0);
            if (udp >= 0 && make_nonblocking(udp) != 0)
                close_socket(&udp);
        }
        if (udp >= 0)
        {
            sent = sendto(udp, packet, length, 0, (struct sockaddr *)&server, sizeof(server));
            if (sent == length)
                SL_LOG("TCPUDP", "UDP sent seq=%u bytes=%d", seq, sent);
            else
            {
                SL_LOG("TCPUDP", "UDP send failed seq=%u ret=%d err=%u", seq, sent, ql_get_soc_errno());
                close_socket(&udp);
            }
        }
        else
            SL_LOG("TCPUDP", "UDP socket creation failed err=%u", ql_get_soc_errno());

        if (tcp < 0)
        {
            tcp = socket(AF_INET, SOCK_STREAM, 0);
            if (tcp < 0 || make_nonblocking(tcp) != 0)
            {
                SL_LOG("TCPUDP", "TCP socket setup failed err=%u", ql_get_soc_errno());
                close_socket(&tcp);
            }
            else
            {
                int result = connect(tcp, (struct sockaddr *)&server, sizeof(server));
                if (result == 0)
                {
                    connected = 1;
                    SL_LOG("TCPUDP", "TCP connected");
                }
                else
                {
                    connecting = 1;
                    connect_ticks = 0;
                    SL_LOG("TCPUDP", "TCP connecting ret=%d err=%u", result, ql_get_soc_errno());
                }
            }
        }
        if (tcp >= 0 && connecting)
        {
            fd_set write_set, error_set;
            struct timeval timeout = {0, 0};
            int result, error = 0;
            socklen_t error_len = sizeof(error);
            FD_ZERO(&write_set);
            FD_ZERO(&error_set);
            FD_SET(tcp, &write_set);
            FD_SET(tcp, &error_set);
            result = select(tcp + 1, NULL, &write_set, &error_set, &timeout);
            if (result > 0 && getsockopt(tcp, SOL_SOCKET, SO_ERROR, &error, &error_len) == 0 &&
                error == 0 && FD_ISSET(tcp, &write_set) && !FD_ISSET(tcp, &error_set))
            {
                connecting = 0;
                connected = 1;
                SL_LOG("TCPUDP", "TCP connected");
            }
            else if (result != 0 || ++connect_ticks >= 5)
            {
                SL_LOG("TCPUDP", "TCP connect failed/timed out select=%d err=%d", result, error);
                close_socket(&tcp);
                connecting = connected = 0;
            }
        }
        if (tcp >= 0 && connected)
        {
            sent = send(tcp, packet, length, 0);
            if (sent == length)
                SL_LOG("TCPUDP", "TCP sent seq=%u bytes=%d", seq, sent);
            else
            {
                /* A partial frame must not be followed by another frame. */
                SL_LOG("TCPUDP", "TCP send incomplete seq=%u ret=%d err=%u; reconnecting", seq, sent, ql_get_soc_errno());
                close_socket(&tcp);
                connected = 0;
                tcp_rx_used = 0;
            }
        }
        ql_rtos_task_sleep_s(LTE_HEARTBEAT_INTERVAL_S);
    }
}

int lte_tcpudp_heartbeat_start(void)
{
    int result;
    if (heartbeat_task != NULL)
        return 0;
    result = ql_rtos_task_create(&heartbeat_task, 4096, 50, "tcpudp_heartbeat", heartbeat_main, NULL);
    if (result != 0)
        SL_LOG("TCPUDP", "task creation failed ret=%d", result);
    return result;
}
