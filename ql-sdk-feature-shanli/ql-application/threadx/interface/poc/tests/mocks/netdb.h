#ifndef TEST_NETDB_H
#define TEST_NETDB_H
#include <sys/socket.h>

/* Keep the harness independent of glibc feature-test macros under -std=c99. */
struct addrinfo {
    int ai_flags, ai_family, ai_socktype, ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};

#define EAI_AGAIN (-3)
int getaddrinfo_with_pcid(const char *node, const char *service,
                         const struct addrinfo *hints, struct addrinfo **result,
                         int profile);
void freeaddrinfo(struct addrinfo *result);
#endif
