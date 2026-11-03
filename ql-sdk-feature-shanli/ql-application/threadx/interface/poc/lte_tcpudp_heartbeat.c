#include <stdio.h>
#include <string.h>

#include "inet.h"
#include "ql_data_call.h"
#include "ql_rtos.h"
#include "sl_log.h"
#include "sockets.h"
#include "lte_tcpudp_heartbeat.h"

/* The callback only records disconnects. Only this task owns the sockets.
 * Query the PDP on every iteration: an UP callback can precede a usable IPv4.
 * The epoch also catches a down/up cycle which reuses the same local address. */
static volatile unsigned int network_epoch;
static ql_task_t heartbeat_task;

void lte_tcpudp_heartbeat_network_changed(int profile_idx, int ready)
{
    if (profile_idx == LTE_HEARTBEAT_PROFILE_IDX && !ready)
        ++network_epoch;
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

static int would_block(unsigned int error)
{
    return error == EAGAIN || error == EWOULDBLOCK || error == EINTR;
}

/* Ticks are deliberately not labelled milliseconds: the SDK only promises
 * ticks since reset. FIONREAD is observational and must not change flow. */
static void log_read_state(const char *name, int fd, unsigned int session,
                           int selected, int readable)
{
#if LTE_HEARTBEAT_DIAGNOSTICS
    unsigned long available = 0;
    int result = ioctl(fd, FIONREAD, &available);
    unsigned int error = result < 0 ? ql_get_soc_errno() : 0;
    SL_LOG("TCPUDP", "%s poll tick=%lu session=%u fd=%d select=%d readable=%d pending_ret=%d pending_bytes=%lu err=%u",
           name, (unsigned long)ql_rtos_get_systicks(), session, fd,
           selected, readable, result, available, error);
#else
    (void)name; (void)fd; (void)session; (void)selected; (void)readable;
#endif
}

static void log_raw_receive(const char *name, int fd, unsigned int session,
                            int bytes, unsigned int error, const char *data)
{
#if LTE_HEARTBEAT_DIAGNOSTICS
    static const char digits[] = "0123456789abcdef";
    char prefix[49];
    int i, preview = bytes > 24 ? 24 : bytes;
    if (preview < 0)
        preview = 0;
    for (i = 0; i < preview; ++i)
    {
        unsigned char value = (unsigned char)data[i];
        prefix[2 * i] = digits[value >> 4];
        prefix[2 * i + 1] = digits[value & 15];
    }
    prefix[2 * preview] = '\0';
    SL_LOG("TCPUDP", "%s rx_raw tick=%lu session=%u fd=%d bytes=%d err=%u first_hex=%s",
           name, (unsigned long)ql_rtos_get_systicks(), session, fd, bytes, error, prefix);
#else
    (void)name; (void)fd; (void)session; (void)bytes; (void)error; (void)data;
#endif
}

/* Match Broad's route selection: bind to the active profile's IPv4, port 0. */
static int create_bound_socket(int type, const struct in_addr *ip)
{
    const char *name = type == SOCK_STREAM ? "TCP" : "UDP";
    struct sockaddr_in local;
    socklen_t local_len = sizeof(local);
    char ip_text[16];
    int fd = socket(AF_INET, type, 0);
    int ret;
    unsigned int error;
    if (fd < 0)
    {
        error = ql_get_soc_errno();
        SL_LOG("TCPUDP", "%s socket failed err=%u", name, error);
        return -1;
    }
    if (make_nonblocking(fd) != 0)
    {
        error = ql_get_soc_errno();
        SL_LOG("TCPUDP", "%s nonblocking failed err=%u", name, error);
        close_socket(&fd);
        return -1;
    }
    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr = *ip;
    local.sin_port = htons(0);
    inet_ntop(AF_INET, ip, ip_text, sizeof(ip_text));
    ret = bind(fd, (struct sockaddr *)&local, sizeof(local));
    if (ret != 0)
    {
        error = ql_get_soc_errno();
        SL_LOG("TCPUDP", "%s bind failed profile=%d ip=%s ret=%d err=%u",
               name, LTE_HEARTBEAT_PROFILE_IDX, ip_text, ret, error);
        close_socket(&fd);
        return -1;
    }
    if (getsockname(fd, (struct sockaddr *)&local, &local_len) == 0)
        SL_LOG("TCPUDP", "%s bound profile=%d local=%s:%u fd=%d", name,
               LTE_HEARTBEAT_PROFILE_IDX, ip_text, (unsigned int)ntohs(local.sin_port), fd);
    else
        SL_LOG("TCPUDP", "%s bound profile=%d ip=%s fd=%d (port unavailable)",
               name, LTE_HEARTBEAT_PROFILE_IDX, ip_text, fd);
    return fd;
}

static void heartbeat_main(void *arg)
{
    struct sockaddr_in server;
    int tcp = -1, udp = -1, connected = 0, connecting = 0;
    unsigned int seq = 0, connect_ticks = 0;
    unsigned int seen_epoch = 0, wait_ticks = 0;
    unsigned int tcp_session = 0, udp_session = 0;
    unsigned int tcp_tx = 0, udp_tx = 0, tcp_frames = 0, udp_replies = 0;
    unsigned int tcp_rx_bytes = 0, udp_rx_bytes = 0;
    struct in_addr bound_ip = {0};
    char tcp_rx[512];
    size_t tcp_rx_used = 0;
    (void)arg;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(LTE_HEARTBEAT_SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(LTE_HEARTBEAT_SERVER_IP);
    SL_LOG("TCPUDP", "%s server=%s:%d profile=%d interval=%ds", LTE_HEARTBEAT_TEST_VERSION, LTE_HEARTBEAT_SERVER_IP,
           LTE_HEARTBEAT_SERVER_PORT, LTE_HEARTBEAT_PROFILE_IDX, LTE_HEARTBEAT_INTERVAL_S);
    SL_LOG("TCPUDP", "diagnostics=%d; tick unit=SDK ticks; sent means socket accepted, not peer ACK",
           LTE_HEARTBEAT_DIAGNOSTICS);

    while (1)
    {
        char packet[96];
        struct ql_data_call_info info = {0};
        unsigned int current_epoch = network_epoch;
        int length, sent;
        int pdp_ret = ql_get_data_call_info(LTE_HEARTBEAT_PROFILE_IDX, 0, &info);
        if (pdp_ret != 0 || info.profile_idx != LTE_HEARTBEAT_PROFILE_IDX ||
            !info.v4.state || info.v4.addr.ip.s_addr == 0 ||
            info.v4.addr.ip.s_addr == INADDR_NONE)
        {
            if (wait_ticks++ % 10 == 0)
                SL_LOG("TCPUDP", "waiting PDP profile=%d query_ret=%d reported_profile=%d v4_state=%d",
                       LTE_HEARTBEAT_PROFILE_IDX, pdp_ret, info.profile_idx, info.v4.state);
            if (tcp >= 0 || udp >= 0)
                SL_LOG("TCPUDP", "network down; closing sockets");
            close_socket(&tcp);
            close_socket(&udp);
            connected = connecting = 0;
            connect_ticks = 0;
            tcp_rx_used = 0;
            bound_ip.s_addr = 0;
            ql_rtos_task_sleep_s(LTE_HEARTBEAT_INTERVAL_S);
            continue;
        }
        wait_ticks = 0;
        if (bound_ip.s_addr != info.v4.addr.ip.s_addr || seen_epoch != current_epoch)
        {
            char ip_text[16], dns1[16], dns2[16];
            close_socket(&tcp);
            close_socket(&udp);
            connected = connecting = 0;
            connect_ticks = 0;
            tcp_rx_used = 0;
            bound_ip = info.v4.addr.ip;
            seen_epoch = current_epoch;
            inet_ntop(AF_INET, &bound_ip, ip_text, sizeof(ip_text));
            inet_ntop(AF_INET, &info.v4.addr.pri_dns, dns1, sizeof(dns1));
            inet_ntop(AF_INET, &info.v4.addr.sec_dns, dns2, sizeof(dns2));
            SL_LOG("TCPUDP", "PDP ready profile=%d ip=%s dns=%s,%s epoch=%u; rebinding sockets",
                   LTE_HEARTBEAT_PROFILE_IDX, ip_text, dns1, dns2, seen_epoch);
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
                int n, selected;
                FD_ZERO(&read_set);
                FD_SET(udp, &read_set);
                selected = select(udp + 1, &read_set, NULL, NULL, &timeout);
                if (selected < 0)
                {
                    unsigned int error = ql_get_soc_errno();
                    if (!would_block(error))
                    {
                        SL_LOG("TCPUDP", "UDP select failed err=%u", error);
                        close_socket(&udp);
                    }
                    break;
                }
                if (i == 0 || selected > 0)
                    log_read_state("UDP", udp, udp_session, selected, FD_ISSET(udp, &read_set) != 0);
                if (selected == 0)
                    break;
                memset(&peer, 0, sizeof(peer));
                n = recvfrom(udp, reply, sizeof(reply) - 1, 0, (struct sockaddr *)&peer, &peer_len);
                {
                    unsigned int receive_error = n < 0 ? ql_get_soc_errno() : 0;
                    log_raw_receive("UDP", udp, udp_session, n, receive_error, reply);
                    if (n < 0)
                    {
                        if (!would_block(receive_error))
                        {
                            SL_LOG("TCPUDP", "UDP receive failed err=%u", receive_error);
                            close_socket(&udp);
                        }
                        break;
                    }
                }
                {
                    char peer_ip[16] = "unknown";
                    inet_ntop(AF_INET, &peer.sin_addr, peer_ip, sizeof(peer_ip));
                    SL_LOG("TCPUDP", "UDP rx_peer session=%u peer=%s:%u bytes=%d accepted=%d",
                           udp_session, peer_ip, (unsigned int)ntohs(peer.sin_port), n,
                           peer.sin_addr.s_addr == server.sin_addr.s_addr && peer.sin_port == server.sin_port);
                }
                if (peer.sin_addr.s_addr != server.sin_addr.s_addr || peer.sin_port != server.sin_port)
                {
                    SL_LOG("TCPUDP", "UDP reply ignored: unexpected source");
                    continue;
                }
                ++udp_replies;
                udp_rx_bytes += (unsigned int)n;
                reply[n] = '\0';
                SL_LOG("TCPUDP", "UDP received: %s", reply);
            }
        }
        if (tcp >= 0 && connected)
        {
            fd_set read_set;
            struct timeval timeout = {0, 0};
            int selected;
            FD_ZERO(&read_set);
            FD_SET(tcp, &read_set);
            selected = select(tcp + 1, &read_set, NULL, NULL, &timeout);
            if (selected < 0)
            {
                unsigned int error = ql_get_soc_errno();
                if (!would_block(error))
                {
                    SL_LOG("TCPUDP", "TCP select failed err=%u; reconnecting", error);
                    close_socket(&tcp);
                    connected = 0;
                    tcp_rx_used = 0;
                }
            }
            else
            {
                log_read_state("TCP", tcp, tcp_session, selected, FD_ISSET(tcp, &read_set) != 0);
            }
            if (selected > 0)
            {
                int n = recv(tcp, tcp_rx + tcp_rx_used, sizeof(tcp_rx) - 1 - tcp_rx_used, 0);
                unsigned int error = n < 0 ? ql_get_soc_errno() : 0;
                log_raw_receive("TCP", tcp, tcp_session, n, error, tcp_rx + tcp_rx_used);
                if (n == 0 || (n < 0 && !would_block(error)))
                {
                    SL_LOG("TCPUDP", "TCP disconnected recv=%d err=%u; reconnecting", n, error);
                    close_socket(&tcp);
                    connected = 0;
                    tcp_rx_used = 0;
                }
                else if (n > 0)
                {
                    char *newline;
                    tcp_rx_bytes += (unsigned int)n;
                    tcp_rx_used += (size_t)n;
                    while ((newline = memchr(tcp_rx, '\n', tcp_rx_used)) != NULL)
                    {
                        size_t frame = (size_t)(newline - tcp_rx) + 1;
                        ++tcp_frames;
                        SL_LOG("TCPUDP", "TCP received: %.*s", (int)frame, tcp_rx);
                        memmove(tcp_rx, tcp_rx + frame, tcp_rx_used - frame);
                        tcp_rx_used -= frame;
                    }
                    SL_LOG("TCPUDP", "TCP rx_buffer session=%u remaining=%u completed_frames=%u",
                           tcp_session, (unsigned int)tcp_rx_used, tcp_frames);
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
            udp = create_bound_socket(SOCK_DGRAM, &bound_ip);
            if (udp >= 0)
            {
                ++udp_session;
                SL_LOG("TCPUDP", "UDP session=%u fd=%d start_tick=%lu", udp_session, udp,
                       (unsigned long)ql_rtos_get_systicks());
            }
        }
        if (udp >= 0)
        {
            sent = sendto(udp, packet, length, 0, (struct sockaddr *)&server, sizeof(server));
            if (sent == length)
            {
                ++udp_tx;
                SL_LOG("TCPUDP", "UDP sent seq=%u bytes=%d session=%u tick=%lu", seq, sent,
                       udp_session, (unsigned long)ql_rtos_get_systicks());
            }
            else
            {
                SL_LOG("TCPUDP", "UDP send failed seq=%u ret=%d err=%u", seq, sent, ql_get_soc_errno());
                close_socket(&udp);
            }
        }
        if (tcp < 0)
        {
            tcp = create_bound_socket(SOCK_STREAM, &bound_ip);
            if (tcp >= 0)
            {
                int result;
                unsigned int error;
                ++tcp_session;
                SL_LOG("TCPUDP", "TCP session=%u fd=%d start_tick=%lu", tcp_session, tcp,
                       (unsigned long)ql_rtos_get_systicks());
                result = connect(tcp, (struct sockaddr *)&server, sizeof(server));
                error = result < 0 ? ql_get_soc_errno() : 0;
                if (result == 0)
                {
                    connected = 1;
                    SL_LOG("TCPUDP", "TCP connected");
                }
                else if (error == EINPROGRESS)
                {
                    connecting = 1;
                    connect_ticks = 0;
                    SL_LOG("TCPUDP", "TCP connecting ret=%d err=%u", result, error);
                }
                else
                {
                    SL_LOG("TCPUDP", "TCP connect failed immediately ret=%d err=%u", result, error);
                    close_socket(&tcp);
                    connected = connecting = 0;
                }
            }
        }
        if (tcp >= 0 && connecting)
        {
            fd_set read_set, write_set, error_set;
            struct timeval timeout = {0, 0};
            int result, error = 0, failed = 0;
            socklen_t error_len = sizeof(error);
            FD_ZERO(&write_set);
            FD_ZERO(&read_set);
            FD_ZERO(&error_set);
            FD_SET(tcp, &write_set);
            FD_SET(tcp, &read_set);
            FD_SET(tcp, &error_set);
            result = select(tcp + 1, &read_set, &write_set, &error_set, &timeout);
            if (result < 0)
            {
                unsigned int select_error = ql_get_soc_errno();
                if (!would_block(select_error))
                {
                    SL_LOG("TCPUDP", "TCP connect select failed err=%u", select_error);
                    failed = 1;
                }
            }
            else if (result > 0)
            {
                if (getsockopt(tcp, SOL_SOCKET, SO_ERROR, &error, &error_len) != 0)
                {
                    unsigned int option_error = ql_get_soc_errno();
                    SL_LOG("TCPUDP", "TCP SO_ERROR query failed err=%u", option_error);
                    failed = 1;
                }
                else if (error != 0 || FD_ISSET(tcp, &error_set) || !FD_ISSET(tcp, &write_set))
                {
                    SL_LOG("TCPUDP", "TCP connect completion failed so_error=%d read=%d write=%d except=%d",
                           error, FD_ISSET(tcp, &read_set) != 0, FD_ISSET(tcp, &write_set) != 0,
                           FD_ISSET(tcp, &error_set) != 0);
                    failed = 1;
                }
                else
                {
                    connecting = 0;
                    connected = 1;
                    SL_LOG("TCPUDP", "TCP connected");
                }
            }
            if (connecting && !failed &&
                connect_ticks >= LTE_HEARTBEAT_CONNECT_TIMEOUT_S / LTE_HEARTBEAT_INTERVAL_S)
            {
                SL_LOG("TCPUDP", "TCP connect timed out after %us (no completion)",
                       connect_ticks * LTE_HEARTBEAT_INTERVAL_S);
                failed = 1;
            }
            if (failed)
            {
                close_socket(&tcp);
                connecting = connected = 0;
                tcp_rx_used = 0;
            }
        }
        if (tcp >= 0 && connected)
        {
            sent = send(tcp, packet, length, 0);
            if (sent == length)
            {
                ++tcp_tx;
                SL_LOG("TCPUDP", "TCP sent seq=%u bytes=%d session=%u tick=%lu", seq, sent,
                       tcp_session, (unsigned long)ql_rtos_get_systicks());
            }
            else
            {
                /* A partial frame must not be followed by another frame. */
                SL_LOG("TCPUDP", "TCP send incomplete seq=%u ret=%d err=%u; reconnecting", seq, sent, ql_get_soc_errno());
                close_socket(&tcp);
                connected = 0;
                tcp_rx_used = 0;
            }
        }
        if (seq % 5 == 0)
            SL_LOG("TCPUDP", "summary tick=%lu seq=%u epoch=%u tcp_fd=%d session=%u connected=%d tx=%u rx_frames=%u rx_bytes=%u buffered=%u udp_fd=%d session=%u tx=%u rx_packets=%u rx_bytes=%u (task totals)",
                   (unsigned long)ql_rtos_get_systicks(), seq, seen_epoch, tcp, tcp_session, connected,
                   tcp_tx, tcp_frames, tcp_rx_bytes, (unsigned int)tcp_rx_used,
                   udp, udp_session, udp_tx, udp_replies, udp_rx_bytes);
        if (connecting)
            ++connect_ticks;
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
