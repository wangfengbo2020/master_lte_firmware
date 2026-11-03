#ifndef TEST_SOCKETS_H
#define TEST_SOCKETS_H
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <unistd.h>
int mock_socket(int domain, int type, int protocol);
int mock_close(int fd);
int mock_ioctl(int fd, unsigned long request, unsigned long *enabled);
int mock_bind(int fd, const struct sockaddr *addr, socklen_t len);
int mock_getsockname(int fd, struct sockaddr *addr, socklen_t *len);
int mock_connect(int fd, const struct sockaddr *addr, socklen_t len);
int mock_select(int nfds, fd_set *read_set, fd_set *write_set,
                fd_set *error_set, struct timeval *timeout);
int mock_getsockopt(int fd, int level, int option, void *value, socklen_t *len);
ssize_t mock_send(int fd, const void *buf, size_t len, int flags);
ssize_t mock_sendto(int fd, const void *buf, size_t len, int flags,
                    const struct sockaddr *addr, socklen_t addrlen);
ssize_t mock_recv(int fd, void *buf, size_t len, int flags);
ssize_t mock_recvfrom(int fd, void *buf, size_t len, int flags,
                      struct sockaddr *addr, socklen_t *addrlen);
unsigned int ql_get_soc_errno(void);
#define socket mock_socket
#define close mock_close
#define ioctl mock_ioctl
#define bind mock_bind
#define getsockname mock_getsockname
#define connect mock_connect
#define select mock_select
#define getsockopt mock_getsockopt
#define send mock_send
#define sendto mock_sendto
#define recv mock_recv
#define recvfrom mock_recvfrom
#endif
