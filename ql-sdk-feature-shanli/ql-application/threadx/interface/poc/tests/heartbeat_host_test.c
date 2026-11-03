/* Host-only state-machine test. No modem or real network calls are made.
 * Compile the actual product C in this translation unit so the infinite task
 * can be stopped by mocked sleep; do not duplicate its implementation here. */
#include <assert.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* The real sl_log.h lives beside the product C, which takes precedence over
 * -I mocks for quoted includes. Preload its guarded mock explicitly. */
#include "mocks/sl_log.h"
#include "../lte_tcpudp_heartbeat.c"

enum { MAX_STEPS = 12, MAX_FDS = 96 };
struct scenario {
    int iterations, pdp_ret[MAX_STEPS], state[MAX_STEPS], profile[MAX_STEPS];
    in_addr_t ip[MAX_STEPS];
    int bind_fail_type, connect_error, complete_at, completion_error;
    int callback_after, callback_profile, receive_eagain, receive_ack;
    int fionread_fail, udp_wrong_peer, tcp_fragmented;
};
struct fake_socket {
    int open, type, nonblocking, bound;
    in_addr_t local_ip;
};
static struct scenario cfg;
static struct fake_socket fds[MAX_FDS];
static jmp_buf task_done;
static int step, next_fd, created, closed, bound, udp_sends, tcp_sends;
static int connect_calls, completion_checks, write_polls, recv_calls, recvfrom_calls;
static int last_udp_read_step, last_tcp_read_step;
static int fionread_calls, tick_calls;
static unsigned int socket_error;
static char logs[32768];
static size_t log_used;
static size_t step_log_begin[MAX_STEPS + 1];
static const char *case_name;

static struct fake_socket *checked_fd(int fd)
{
    assert(fd >= 10 && fd < MAX_FDS);
    assert(fds[fd].open);
    return &fds[fd];
}

void test_log(const char *tag, const char *format, ...)
{
    int n;
    va_list ap;
    (void)tag;
    assert(log_used + 512 < sizeof(logs));
    va_start(ap, format);
    n = vsnprintf(logs + log_used, sizeof(logs) - log_used, format, ap);
    va_end(ap);
    assert(n >= 0 && (size_t)n < sizeof(logs) - log_used);
    log_used += (size_t)n;
    logs[log_used++] = '\n';
    logs[log_used] = 0;
}

int ql_get_data_call_info(int profile, int version, struct ql_data_call_info *info)
{
    assert(profile == 1 && version == 0);
    assert(step < cfg.iterations);
    info->profile_idx = cfg.profile[step];
    info->v4.state = cfg.state[step];
    info->v4.addr.ip.s_addr = cfg.ip[step];
    return cfg.pdp_ret[step];
}

void ql_rtos_task_sleep_s(unsigned int seconds)
{
    assert(seconds == 3);
    if (step == cfg.callback_after) {
        lte_tcpudp_heartbeat_network_changed(cfg.callback_profile, 0);
        lte_tcpudp_heartbeat_network_changed(cfg.callback_profile, 1);
    }
    step_log_begin[step + 1] = log_used;
    if (++step >= cfg.iterations)
        longjmp(task_done, 1);
}

unsigned int ql_rtos_get_systicks(void)
{
    ++tick_calls;
    /* Deliberately not milliseconds; diagnostics must report raw ticks. */
    return 10000U + (unsigned int)step * 137U;
}

int ql_rtos_task_create(ql_task_t *task, unsigned int stack, unsigned int priority,
                        const char *name, void (*entry)(void *), void *arg)
{
    (void)task; (void)stack; (void)priority; (void)name; (void)entry; (void)arg;
    assert(!"task creation is not part of this host harness");
    return -1;
}

unsigned int ql_get_soc_errno(void) { return socket_error; }

int mock_socket(int domain, int type, int protocol)
{
    int fd = next_fd++;
    assert(domain == AF_INET && protocol == 0 && fd < MAX_FDS);
    assert(type == SOCK_STREAM || type == SOCK_DGRAM);
    fds[fd].open = 1;
    fds[fd].type = type;
    ++created;
    return fd;
}

int mock_close(int fd)
{
    checked_fd(fd)->open = 0;
    ++closed;
    return 0;
}

static const char *tcp_reply_chunk(void)
{
    if (cfg.tcp_fragmented)
        return step == 1 ? "ACK LTE heartbeat seq=" : "1\n";
    return "ACK LTE heartbeat seq=1\n";
}

int mock_ioctl(int fd, unsigned long request, unsigned long *value)
{
    struct fake_socket *s = checked_fd(fd);
    if (request == FIONBIO) {
        assert(*value == 1);
        s->nonblocking = 1;
        return 0;
    }
    assert(request == FIONREAD);
    ++fionread_calls;
    if (cfg.fionread_fail) {
        socket_error = EOPNOTSUPP;
        return -1;
    }
    *value = 0;
    if (cfg.receive_ack && step > 0) {
        if (s->type == SOCK_STREAM && last_tcp_read_step != step)
            *value = (unsigned long)strlen(tcp_reply_chunk());
        if (s->type == SOCK_DGRAM && last_udp_read_step != step)
            *value = (unsigned long)strlen("ACK LTE heartbeat seq=1\n");
    }
    return 0;
}

int mock_bind(int fd, const struct sockaddr *addr, socklen_t len)
{
    struct fake_socket *s = checked_fd(fd);
    const struct sockaddr_in *local = (const struct sockaddr_in *)addr;
    assert(s->nonblocking && !s->bound);
    assert(len == sizeof(*local) && local->sin_family == AF_INET);
    assert(local->sin_port == 0);
    assert(local->sin_addr.s_addr == cfg.ip[step]);
    if (s->type == cfg.bind_fail_type) {
        socket_error = EADDRNOTAVAIL;
        return -1;
    }
    s->bound = 1;
    s->local_ip = local->sin_addr.s_addr;
    ++bound;
    return 0;
}

int mock_getsockname(int fd, struct sockaddr *addr, socklen_t *len)
{
    struct fake_socket *s = checked_fd(fd);
    struct sockaddr_in *local = (struct sockaddr_in *)addr;
    assert(s->bound && *len == sizeof(*local));
    local->sin_addr.s_addr = s->local_ip;
    local->sin_port = htons((unsigned short)(40000 + fd));
    return 0;
}

static void check_destination(const struct sockaddr *addr, socklen_t len)
{
    const struct sockaddr_in *server = (const struct sockaddr_in *)addr;
    assert(len == sizeof(*server) && server->sin_family == AF_INET);
    assert(server->sin_addr.s_addr == inet_addr("123.57.79.87"));
    assert(ntohs(server->sin_port) == 19000);
}

int mock_connect(int fd, const struct sockaddr *addr, socklen_t len)
{
    struct fake_socket *s = checked_fd(fd);
    assert(s->type == SOCK_STREAM && s->bound && s->local_ip == cfg.ip[step]);
    check_destination(addr, len);
    ++connect_calls;
    if (cfg.connect_error) {
        socket_error = (unsigned int)cfg.connect_error;
        return -1;
    }
    return 0;
}

int mock_select(int nfds, fd_set *read_set, fd_set *write_set,
                fd_set *error_set, struct timeval *timeout)
{
    int fd = nfds - 1;
    struct fake_socket *s = checked_fd(fd);
    assert(s->bound && timeout->tv_sec == 0 && timeout->tv_usec == 0);
    if (write_set) {
        assert(s->type == SOCK_STREAM && FD_ISSET(fd, write_set));
        ++write_polls;
        if (read_set) FD_ZERO(read_set);
        if (error_set) FD_ZERO(error_set);
        if (cfg.complete_at >= 0 && step >= cfg.complete_at)
            return 1;
        FD_ZERO(write_set);
        return 0;
    }
    assert(read_set && FD_ISSET(fd, read_set));
    if (step > 0 && (cfg.receive_eagain || cfg.receive_ack)) {
        if (s->type == SOCK_STREAM && last_tcp_read_step != step) return 1;
        if (s->type == SOCK_DGRAM && last_udp_read_step != step) return 1;
    }
    FD_ZERO(read_set);
    return 0;
}

int mock_getsockopt(int fd, int level, int option, void *value, socklen_t *len)
{
    assert(checked_fd(fd)->type == SOCK_STREAM);
    assert(level == SOL_SOCKET && option == SO_ERROR && *len == sizeof(int));
    *(int *)value = cfg.completion_error;
    ++completion_checks;
    return 0;
}

static void check_packet(int fd, const void *buf, size_t len, int flags, int type)
{
    struct fake_socket *s = checked_fd(fd);
    assert(s->type == type && s->bound && s->local_ip == cfg.ip[step]);
    assert(flags == 0 && len > 0);
    assert(strncmp(buf, "LTE heartbeat seq=", 18) == 0);
    assert(((const char *)buf)[len - 1] == '\n');
}

ssize_t mock_send(int fd, const void *buf, size_t len, int flags)
{
    check_packet(fd, buf, len, flags, SOCK_STREAM);
    if (cfg.connect_error == EINPROGRESS)
        assert(completion_checks > 0 && !cfg.completion_error);
    ++tcp_sends;
    return (ssize_t)len;
}

ssize_t mock_sendto(int fd, const void *buf, size_t len, int flags,
                    const struct sockaddr *addr, socklen_t addrlen)
{
    check_packet(fd, buf, len, flags, SOCK_DGRAM);
    check_destination(addr, addrlen);
    ++udp_sends;
    return (ssize_t)len;
}

ssize_t mock_recv(int fd, void *buf, size_t len, int flags)
{
    const char *reply = tcp_reply_chunk();
    size_t reply_len = strlen(reply);
    assert(checked_fd(fd)->type == SOCK_STREAM && flags == 0);
    last_tcp_read_step = step;
    ++recv_calls;
    if (cfg.receive_eagain) {
        socket_error = EAGAIN;
        return -1;
    }
    assert(len >= reply_len);
    memcpy(buf, reply, reply_len);
    return (ssize_t)reply_len;
}

ssize_t mock_recvfrom(int fd, void *buf, size_t len, int flags,
                      struct sockaddr *addr, socklen_t *addrlen)
{
    const char reply[] = "ACK LTE heartbeat seq=1\n";
    struct sockaddr_in *peer = (struct sockaddr_in *)addr;
    assert(checked_fd(fd)->type == SOCK_DGRAM && flags == 0);
    last_udp_read_step = step;
    ++recvfrom_calls;
    if (cfg.receive_eagain) {
        socket_error = EAGAIN;
        return -1;
    }
    assert(len >= sizeof(reply) - 1 && *addrlen == sizeof(*peer));
    memset(peer, 0, sizeof(*peer));
    peer->sin_family = AF_INET;
    peer->sin_addr.s_addr = inet_addr("123.57.79.87");
    peer->sin_port = htons(19000);
    if (cfg.udp_wrong_peer == 1)
        peer->sin_addr.s_addr = inet_addr("192.0.2.1");
    else if (cfg.udp_wrong_peer == 2)
        peer->sin_port = htons(19001);
    memcpy(buf, reply, sizeof(reply) - 1);
    return sizeof(reply) - 1;
}

static void reset_case(const char *name, int iterations)
{
    int i;
    case_name = name;
    memset(&cfg, 0, sizeof(cfg));
    memset(fds, 0, sizeof(fds));
    memset(logs, 0, sizeof(logs));
    memset(step_log_begin, 0, sizeof(step_log_begin));
    cfg.iterations = iterations;
    cfg.complete_at = -1;
    cfg.callback_after = -1;
    for (i = 0; i < MAX_STEPS; ++i) {
        cfg.state[i] = 1;
        cfg.profile[i] = 1;
        cfg.ip[i] = inet_addr("10.161.24.143");
    }
    step = created = closed = bound = udp_sends = tcp_sends = 0;
    connect_calls = completion_checks = write_polls = recv_calls = recvfrom_calls = 0;
    fionread_calls = tick_calls = 0;
    next_fd = 10;
    last_tcp_read_step = last_udp_read_step = -1;
    log_used = socket_error = network_epoch = 0;
    heartbeat_task = NULL;
}

static void run_case(void)
{
    if (setjmp(task_done) == 0)
        heartbeat_main(NULL);
}

static int logged_in_step(int iteration, const char *text)
{
    const char *match;
    assert(iteration >= 0 && iteration < cfg.iterations);
    match = strstr(logs + step_log_begin[iteration], text);
    return match != NULL && (size_t)(match - logs) < step_log_begin[iteration + 1];
}

static void passed(void) { printf("PASS %s\n", case_name); }

int main(void)
{
    int i;
    reset_case("PDP inactive/query failure/wrong profile/invalid IP do not send", 5);
    cfg.state[0] = 0;
    cfg.pdp_ret[1] = -1;
    cfg.profile[2] = 2;
    cfg.ip[3] = 0;
    cfg.ip[4] = INADDR_NONE;
    run_case();
    assert(created == 0 && udp_sends == 0 && tcp_sends == 0); passed();

    reset_case("recovery is polled; bind both sockets before traffic; ACKs logged", 3);
    cfg.state[0] = 0;
    cfg.receive_ack = 1;
    run_case();
    assert(created == 2 && bound == 2 && tcp_sends == 2 && udp_sends == 2);
    assert(strstr(logs, "TCP received: ACK") && strstr(logs, "UDP received: ACK")); passed();

    reset_case("UDP bind failure closes UDP and prevents UDP send", 1);
    cfg.bind_fail_type = SOCK_DGRAM;
    run_case();
    assert(created == 2 && closed == 1 && udp_sends == 0 && tcp_sends == 1); passed();

    reset_case("TCP bind failure prevents connect and TCP send", 1);
    cfg.bind_fail_type = SOCK_STREAM;
    run_case();
    assert(closed == 1 && connect_calls == 0 && tcp_sends == 0 && udp_sends == 1); passed();

    reset_case("PDP address change recreates and rebinds both sockets", 3);
    cfg.ip[1] = cfg.ip[2] = inet_addr("10.161.24.144");
    run_case();
    assert(created == 4 && closed == 2 && bound == 4 && tcp_sends == 3 && udp_sends == 3); passed();

    reset_case("profile 1 down/up with same IP recreates both sockets", 3);
    cfg.callback_after = 0;
    cfg.callback_profile = 1;
    run_case();
    assert(created == 4 && closed == 2 && bound == 4); passed();

    reset_case("other profile down/up does not disrupt sockets", 3);
    cfg.callback_after = 0;
    cfg.callback_profile = 2;
    run_case();
    assert(created == 2 && closed == 0 && tcp_sends == 3 && udp_sends == 3); passed();

    reset_case("PDP outage closes sockets; same-IP recovery rebinds", 3);
    cfg.state[1] = 0;
    run_case();
    assert(created == 4 && closed == 2 && tcp_sends == 2 && udp_sends == 2); passed();

    reset_case("EHOSTUNREACH closes immediately and never becomes connecting", 3);
    cfg.connect_error = EHOSTUNREACH;
    run_case();
    assert(connect_calls == 3 && closed == 3 && write_polls == 0 && tcp_sends == 0);
    assert(strstr(logs, "err=113") && !strstr(logs, "TCP connecting")); passed();

    reset_case("EINPROGRESS waits for writable and SO_ERROR before sending", 3);
    cfg.connect_error = EINPROGRESS;
    cfg.complete_at = 1;
    run_case();
    assert(connect_calls == 1 && completion_checks == 1 && tcp_sends == 2 && closed == 0); passed();

    reset_case("nonzero SO_ERROR rejects async connection", 2);
    cfg.connect_error = EINPROGRESS;
    cfg.complete_at = 0;
    cfg.completion_error = ECONNREFUSED;
    run_case();
    assert(completion_checks == 2 && tcp_sends == 0 && closed == 2); passed();

    reset_case("async timeout occurs after five actual three-second sleeps", 6);
    cfg.connect_error = EINPROGRESS;
    run_case();
    assert(write_polls == 6 && completion_checks == 0 && closed == 1 && tcp_sends == 0);
    assert(strstr(logs, "timed out after 15s") != NULL); passed();

    reset_case("EAGAIN on TCP and UDP receive preserves sockets", 3);
    cfg.receive_eagain = 1;
    run_case();
    assert(recv_calls == 2 && recvfrom_calls == 2 && created == 2 && closed == 0);
    assert(tcp_sends == 3 && udp_sends == 3 && !strstr(logs, "TCP disconnected")); passed();

    reset_case("FIONREAD diagnostic failure does not prevent ACKs or close sockets", 3);
    cfg.receive_ack = 1;
    cfg.fionread_fail = 1;
    run_case();
    assert(fionread_calls > 0 && tick_calls > 0);
    assert(recv_calls == 2 && recvfrom_calls == 2 && created == 2 && closed == 0);
    assert(tcp_sends == 3 && udp_sends == 3);
    assert(strstr(logs, "pending_ret=-1"));
    assert(strstr(logs, "TCP received: ACK") && strstr(logs, "UDP received: ACK")); passed();

    reset_case("UDP reply from wrong IP is observable but is not an accepted reply", 5);
    cfg.receive_ack = 1;
    cfg.udp_wrong_peer = 1;
    run_case();
    assert(recvfrom_calls == 4 && closed == 0 && udp_sends == 5 && tcp_sends == 5);
    assert(strstr(logs, "UDP rx_raw") && strstr(logs, "peer=192.0.2.1:19000"));
    assert(strstr(logs, "accepted=0") && strstr(logs, "UDP reply ignored: unexpected source"));
    assert(!strstr(logs, "UDP received:") && strstr(logs, "TCP received: ACK"));
    assert(strstr(logs, "rx_packets=0 rx_bytes=0")); passed();

    reset_case("UDP reply from wrong port is rejected without disrupting TCP", 2);
    cfg.receive_ack = 1;
    cfg.udp_wrong_peer = 2;
    run_case();
    assert(recvfrom_calls == 1 && recv_calls == 1 && closed == 0);
    assert(strstr(logs, "peer=123.57.79.87:19001") && strstr(logs, "accepted=0"));
    assert(!strstr(logs, "UDP received:") && strstr(logs, "TCP received: ACK")); passed();

    reset_case("TCP fragment is logged raw before newline and is reassembled exactly once", 3);
    cfg.receive_ack = 1;
    cfg.tcp_fragmented = 1;
    run_case();
    assert(recv_calls == 2 && closed == 0 && tcp_sends == 3 && udp_sends == 3);
    assert(logged_in_step(1, "TCP rx_raw") && !logged_in_step(1, "TCP received:"));
    assert(logged_in_step(1, "remaining=22 completed_frames=0"));
    assert(logged_in_step(1, "first_hex=41434b204c544520686561727462656174207365713d"));
    assert(logged_in_step(2, "TCP rx_raw") && logged_in_step(2, "first_hex=310a"));
    assert(logged_in_step(2, "TCP received: ACK LTE heartbeat seq=1\n"));
    assert(logged_in_step(2, "remaining=0 completed_frames=1")); passed();

    /* No real descriptors were opened; fd table is entirely simulated. */
    for (i = 0; i < next_fd; ++i)
        fds[i].open = 0;
    puts("All 17 host mock scenarios passed (not a modem/hardware test).");
    return 0;
}
