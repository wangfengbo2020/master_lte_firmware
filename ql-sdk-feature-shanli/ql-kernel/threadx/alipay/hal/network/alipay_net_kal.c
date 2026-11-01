#include <stdio.h>
#include <errno.h>
#include "alipay_net_kal.h"
#include "sockets.h"
#include "osa_old_api.h"
#include "hal_asr.h"


#include "UART.h"
#define alipay_log_debug(fmt,args...)  do {CPUartLogPrintf("[ali_net]"fmt, ##args);}while(0)
#define printf(fmt,args...)  do {CPUartLogPrintf("[ali_net]"fmt, ##args);}while(0)
//#define alipay_log_debug(...)

/*
 * Defined in header files in SDK, which have too many dependencies.
 * Compilation errors caused by directly include those header files
 * are difficult to resolve. Therefore, redefined here. 
 */
#define LWIP_SOCKET_OFFSET           (0) /*note: must set to 0*/
#define DEFAULT_SPREAD_FACTOR_DOUBLE (1)
//#define MEMP_NUM_NETCONN             (128 / DEFAULT_SPREAD_FACTOR_DOUBLE)
#define NUM_SOCKETS                  MEMP_NUM_NETCONN
#define NUM_EVENTS                   MEMP_NUM_NETCONN
#define LWIP_EVENT_OFFSET            (NUM_SOCKETS + LWIP_SOCKET_OFFSET)
#define FD_SETSIZE                   MEMP_NUM_NETCONN
#define FDSETSAFESET(n, code)        do {\
    if ((((int)(n) - LWIP_SOCKET_OFFSET) < (MEMP_NUM_NETCONN * 2)) \
       && (((int)(n) - LWIP_SOCKET_OFFSET) >= 0)) {code;}\
    } while(0)
#define FDSETSAFEGET(n, code)        (((((int)(n) - LWIP_SOCKET_OFFSET) < (MEMP_NUM_NETCONN * 2)) \
                                     && (((int)(n) - LWIP_SOCKET_OFFSET) >= 0)) ? (code) : 0)

#define FD_SET(n, p)                 FDSETSAFESET(n, (p)->fd_bits[((n) - LWIP_SOCKET_OFFSET)/8] |=  (1 << (((n) - LWIP_SOCKET_OFFSET) & 7)))
#define FD_CLR(n, p)                 FDSETSAFESET(n, (p)->fd_bits[((n) - LWIP_SOCKET_OFFSET)/8] &= ~(1 << (((n) - LWIP_SOCKET_OFFSET) & 7)))
#define FD_ISSET(n,p)                FDSETSAFEGET(n, (p)->fd_bits[((n) - LWIP_SOCKET_OFFSET)/8] &   (1 << (((n) - LWIP_SOCKET_OFFSET) & 7)))
//#define FD_ZERO(p)                   memset((void*)(p), 0, sizeof(*(p)))

#define PF_INET                      AF_INET
#define IP4ADDR_STRLEN_MAX           16
#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN              IP4ADDR_STRLEN_MAX
#endif

//typedef unsigned int                 socklen_t;
typedef unsigned char                u8_t;
typedef unsigned short               u16_t;
//typedef unsigned int                 u32_t;

#if 0
struct sockaddr {
  u8_t                  sa_len;
  u8_t                  sa_family;
#if LWIP_IPV6
  u8_t                  sa_data[22];
#else /* LWIP_IPV6 */
  u8_t                  sa_data[14];
#endif /* LWIP_IPV6 */
};
#endif

struct addrinfo {
    int                 ai_flags;      /* Input flags. */
    int                 ai_family;     /* Address family of socket. */
    int                 ai_socktype;   /* Socket type. */
    int                 ai_protocol;   /* Protocol of socket. */
    socklen_t           ai_addrlen;    /* Length of socket address. */
    struct sockaddr    *ai_addr;       /* Socket address of socket. */
    char               *ai_canonname;  /* Canonical name of service location. */
    struct addrinfo    *ai_next;       /* Pointer to next in list. */
};

#if 0
struct timeval
{
    int                 tv_sec;        /* seconds */
    int                 tv_usec;       /* and microseconds */
};

typedef struct fd_set {
  unsigned char         fd_bits [(FD_SETSIZE * 2 + 7)/8];
} fd_set;

/* the __cp_sockets.h depends on fd_set struct */
//#include "__cp_sockets.h"

struct ip_addr {
  u32_t                 addr;
};

struct in_addr {
  u32_t                 s_addr;
};

struct sockaddr_in {
  u8_t                  sin_len;
  u8_t                  sin_family;
  u16_t                 sin_port;
  struct in_addr        sin_addr;
#define SIN_ZERO_LEN 8
  char                  sin_zero[SIN_ZERO_LEN];
};
#endif


struct hostent {
    char                *h_name;       /* Official name of the host. */
    char                **h_aliases;   /* A pointer to an array of pointers to alternative host names,
                                          terminated by a null pointer. */
    int                 h_addrtype;    /* Address type. */
    int                 h_length;      /* The length, in bytes, of the address. */
    char                **h_addr_list; /* A pointer to an array of pointers to network addresses (in
                                          network byte order) for the host, terminated by a null pointer. */
#define h_addr h_addr_list[0]          /* for backward compatibility */
};

/*
 * ip_addr_t uses a struct for convenience only, so that the same defines can
 * operate both on ip_addr_t as well as on ip_addr_p_t.
 */
typedef struct ip_addr ip_addr_t;

#if 0
static inline u16_t lwip_htons(u16_t n)
{
  return ((n & 0xff) << 8) | ((n & 0xff00) >> 8);
}
#endif


extern int lwip_bind(int s, const struct sockaddr *name, socklen_t namelen);
extern int lwip_fcntl(int s, int cmd, int val);
extern struct hostent *lwip_gethostbyname(const char *name);
extern char *ipaddr_ntoa(const ip_addr_t *addr);
extern const char *inet_ntop(int af, const void *src, char *dst, int size);


#define htons(x)                     lwip_htons(x)
#define fcntl(a,b,c)                 lwip_fcntl(a,b,c)
#define bind(a,b,c)                  lwip_bind(a,b,c)
#define close(s)                     lwip_close(s)
#define gethostbyname(name)          lwip_gethostbyname(name)
#define inet_ntoa(addr)              ipaddr_ntoa((ip_addr_t*)&(addr))




static OSASemaRef g_alipay_iot_socket_sema = NULL;
typedef void * alipay_iot_mutex;
static bool alipay_socket_init_flag = false;
static int32_t alipay_sockets[ALIPAY_IOT_MAX_IP_SOCKET_NUM] = {-1};

void alipay_iot_gettimeofday(alipay_iot_timeval *now)
{
    now->tv_sec = Hal_Rtc_Get_Utc_Sec();
    now->tv_usec = 0;
}

/*
 * ms must be the multiple of OSA_TICK_FREQ_IN_MILLISEC(which is 5 in crane series， except cranew)
 * eg:
 *    crane series: uos_sleep_ms(1) will sleep for 5ms, uos_sleep_ms(6) will sleep for 10ms
 *    cranew: uos_sleep_ms(1) will sleep for 1ms, uos_sleep_ms(6) will sleep for 6ms
*/
void alipay_task_sleep(uint32_t ms)
{
   // uos_sleep_ms(ms);
   OSATaskSleep(ms/5 + 1);
}

alipay_iot_mutex alipay_iot_mutex_create(const char* mutex_name)
{
    (void)mutex_name;

	if(g_alipay_iot_socket_sema == NULL)
	{
		OSASemaphoreCreate(&g_alipay_iot_socket_sema, 1, OSA_FIFO);
	}	

    return g_alipay_iot_socket_sema;
}

int alipay_iot_mutex_lock(alipay_iot_mutex mutex)
{
    if (!mutex) {
        printf("%s mutex is NULL\r\n", __func__);
        return -1;
    }

    OSASemaphoreAcquire(mutex, OS_SUSPEND);

    return 0;
}

int alipay_iot_mutex_unlock(alipay_iot_mutex mutex)
{
    if (!mutex) {
        printf("%s mutex is NULL\r\n", __func__);
        return -1;
    }

    OSASemaphoreRelease(mutex);

    return 0;
}

int alipay_iot_mutex_delete(alipay_iot_mutex mutex)
{
    if(!mutex) {
        printf("%s is NULL\r\n", __func__);
        return -1;
    }

    OSASemaphoreDelete(mutex);
    mutex = NULL;

    return 0;
}

/*************************socket adapt*************************/
static alipay_iot_mutex get_mtx(void)
{
    static alipay_iot_mutex s_mtx_socket;
    static bool s_isinitialized = false;

    if (!s_isinitialized) {
        s_mtx_socket = alipay_iot_mutex_create("socket_mutex");
        s_isinitialized = true;
    }

    return s_mtx_socket;
}

static int alipay_iot_fd_init(void)
{
    if (alipay_socket_init_flag == true) {
        printf("alipay fd have already inited, should be called twice\n");
        return -1;
    }

    memset(alipay_sockets, -1, sizeof(alipay_sockets));
    alipay_socket_init_flag = true;

    return 0;
}

static int alloc_alipay_socket(int origin_fd)
{
    int i;

    if (alipay_socket_init_flag != true) {
        alipay_iot_fd_init();
    }

    alipay_iot_mutex_lock(get_mtx());
    for (i = 0; i < ALIPAY_IOT_MAX_IP_SOCKET_NUM; i++) {
        if (alipay_sockets[i] == -1) {
            alipay_sockets[i] = origin_fd;
            alipay_iot_mutex_unlock(get_mtx());
            return i;
        }
    }
    alipay_iot_mutex_unlock(get_mtx());

    return -1;
}

static int free_alipay_socket(int s)
{
    if (alipay_socket_init_flag != true) {
        alipay_iot_fd_init();
    }

    if (s >= ALIPAY_IOT_MAX_IP_SOCKET_NUM || s < 0) {
        return -1;
    }

    alipay_iot_mutex_lock(get_mtx());
    alipay_sockets[s] = -1;
    alipay_iot_mutex_unlock(get_mtx());

    return 0;
}

static int get_origin_fd_by_alipay_socket(int socket)
{
    int fd = -1;

    if (alipay_socket_init_flag != true) {
        alipay_iot_fd_init();
    }

    if (socket >= ALIPAY_IOT_MAX_IP_SOCKET_NUM || socket < 0) {
        printf("invalid input socket %d\n", socket);
        return -1;
    }

    alipay_iot_mutex_lock(get_mtx());
    fd = alipay_sockets[socket];
    alipay_iot_mutex_unlock(get_mtx());

    return fd;
}

static void alipay_iot_fd_setResultbit(int fd, alipay_iot_fd_set* fdset)
{
    if (fdset != NULL && fd >=0 && fd < ALIPAY_IOT_MAX_IP_SOCKET_NUM ) {
        fdset->fds_bits[fd] |= 0x02;
    }
}

int alipay_iot_fd_isset(int fd, alipay_iot_fd_set* fdset)
{
    if(fdset != NULL && fd >=0 && fd < ALIPAY_IOT_MAX_IP_SOCKET_NUM ) {
        return fdset->fds_bits[fd] & 0x02;
    }

    return 0;
}

static int alipay_iot_fd_check(int fd, alipay_iot_fd_set* fdset)
{
    if(fdset != NULL && fd >=0 && fd < ALIPAY_IOT_MAX_IP_SOCKET_NUM )
    {
        return fdset->fds_bits[fd] & 0x01;
    }

    return 0;
}

void alipay_iot_fd_setbit(int fd, alipay_iot_fd_set* fdset)
{
    if(fdset != NULL && fd >=0 && fd < ALIPAY_IOT_MAX_IP_SOCKET_NUM )
    {
        fdset->fds_bits[fd] |= 0x01;
    }
}

void alipay_iot_fd_zero(alipay_iot_fd_set* fdset)
{
    if(fdset != NULL)
    {
        memset(fdset, 0, sizeof(alipay_iot_fd_set));
    }
}

int alipay_iot_select(int maxfdp1,
                      alipay_iot_fd_set* readset,
                      alipay_iot_fd_set* writeset,
                      alipay_iot_fd_set* exceptset,
                      alipay_iot_timeval* timeout)
{
    fd_set  set_r, set_w, set_e;
    int i = 0;
    int origin_fd = -1;
    int origin_max = -1;
    int count = 0;

    FD_ZERO(&set_r);
    FD_ZERO(&set_w);
    FD_ZERO(&set_e);

    if(maxfdp1 < 0) {
        printf("maxfdp1 error %d\n", maxfdp1);
        return -1;
    }

    alipay_log_debug("maxfdp1 is %d, timeout sec %d, usec %d\r\n ", maxfdp1, timeout->tv_sec, timeout->tv_usec);
    for(i = 0; i < maxfdp1; i++) {
        origin_fd = get_origin_fd_by_alipay_socket(i);
        if (origin_fd == -1) {
            continue;
        }

        if (origin_fd > origin_max - 1) {
            origin_max = origin_fd + 1;
        }

        if(alipay_iot_fd_check(i, readset)) {
            alipay_log_debug("set fd %d read\n", origin_fd);
            FD_SET(origin_fd, &set_r);
        }

        if(alipay_iot_fd_check(i, writeset)) {
            alipay_log_debug("set fd %d write\n", origin_fd);
            FD_SET(origin_fd, &set_w);
        }

        if(alipay_iot_fd_check(i, exceptset)) {
            alipay_log_debug("set fd %d except\n", origin_fd);
            FD_SET(origin_fd, &set_e);
        }

        alipay_log_debug("maxfp1 is %d , i is %d, fd is %d maxfd is %d\n",maxfdp1, i, origin_fd, origin_max);
    }

    struct timeval iTimeout = {0};
    if (timeout != NULL) {
        iTimeout.tv_sec = timeout->tv_sec;
        iTimeout.tv_usec = timeout->tv_usec;
    }

    count = select(origin_max, &set_r, &set_w, &set_e, &iTimeout);
    alipay_log_debug("select return count is 0x%x\n", count);

    for(i = 0; i < maxfdp1; i++) {
        origin_fd = get_origin_fd_by_alipay_socket(i);
        if (origin_fd == -1) {
            continue;
        }

        if(FD_ISSET(origin_fd, &set_r)) {
            alipay_iot_fd_setResultbit(i, readset);
        }
        if(FD_ISSET(origin_fd, &set_w)) {
            alipay_iot_fd_setResultbit(i, writeset);
        }
        if(FD_ISSET(origin_fd, &set_e)) {
            alipay_iot_fd_setResultbit(i, exceptset);
        }
    }

    return count;
}

int alipay_iot_dns(const char *name, unsigned char ip[4])
{
    struct hostent *host_entry;
    struct in_addr **addr_list;

    alipay_log_debug("%s name = %s\r\n", __func__, name);
    if ((host_entry = gethostbyname(name)) == NULL) {
        printf("%s gethostbyname failed\r\n", __func__);
        return -1;
    }

    addr_list = (struct in_addr **)host_entry->h_addr_list;
    if (addr_list[0] == NULL) {
        printf("%s addr_list[0] is NULL\r\n", __func__);
        return -1;
    }

    char *p_tmp = inet_ntoa(*addr_list[0]);
    sscanf(p_tmp, "%hhd.%hhd.%hhd.%hhd", &ip[0], &ip[1], &ip[2], &ip[3]);
    alipay_log_debug("%s p_tmp = %s\r\n", __func__, p_tmp);

    return 0;
}

int alipay_iot_socket_create(int domain, alipay_socket_type_enum type, int protocol)
{
    int socket_type = -1;
    int fd = -1;

    switch (type) {
        case ALIPAY_IOT_SOC_SOCK_STREAM: {
            socket_type = SOCK_STREAM;
            break;
        }
        case ALIPAY_IOT_SOC_SOCK_DGRAM: {
            socket_type = SOCK_DGRAM;
            break;
        }
        default: {
            printf("%s unknown type\r\n", __func__);
            return -1;
        }
    }

    int socket_fd = -1;
    if ((socket_fd = socket(PF_INET, socket_type, 0)) < 0) {
        return -1;
    }

    alipay_log_debug("socket_fd: %d\n", socket_fd);
    fd = alloc_alipay_socket(socket_fd);
    if (fd == -1) {
        printf("fail to create alipay socket 0x%x\n", fd);
        close(socket_fd);
        return -1;
    }

    alipay_log_debug("fd: %d\n", fd);
    return fd;
}

int alipay_iot_socket_close(int s)
{
    int fd = -1;
    int ret  = -1;

    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("%s get_origin_fd_by_alipay_socket failed\n", __func__);
        return -1;
    }

    ret = close(fd);

    free_alipay_socket(s);

    alipay_log_debug("close socket %d origin is %d ret %d\n", s, fd, ret);

    return ret;
}

int alipay_iot_socket_bind(int s, const struct alipay_iot_sockaddr *name,
                           unsigned int namelen)
{
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = PF_INET;
    serv_addr.sin_port = htons(name->data.sin_data.port);
    memcpy(&serv_addr.sin_addr, name->data.sin_data.ip,
           sizeof(serv_addr.sin_addr));

    int fd = -1;
    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("%s get_origin_fd_by_alipay_socket failed\n", __func__);
        return -1;
    }

    if (bind(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("alipay_iot_socket_bind failed");
        return -1;
    }

    return 0;
}

int alipay_iot_socket_connect(int s, const struct alipay_iot_sockaddr *name,
                              unsigned int namelen)
{
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = PF_INET;
    serv_addr.sin_port = htons(name->data.sin_data.port);
    memcpy(&serv_addr.sin_addr, name->data.sin_data.ip, sizeof(serv_addr.sin_addr));

    char str[100] = {0};
    inet_ntop(PF_INET, &(serv_addr.sin_addr), str, INET_ADDRSTRLEN);
    alipay_log_debug("ip address: %s\n", str);
    alipay_log_debug("port: %d - %d\n", serv_addr.sin_port, name->data.sin_data.port);

    int fd = -1;
    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("%s get_origin_fd_by_alipay_socket failed\n", __func__);
        return -1;
    }

    int val = connect(fd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (val < 0) {
        printf("fail to connect alipay sock %d\n", fd);
        return -1;
    }

    return val;
}

int alipay_iot_socket_sendto(int s,
                             const void *dataptr,
                             int size,
                             int flags,
                             const struct alipay_iot_sockaddr *to,
                             unsigned int tolen)
{
    alipay_log_debug("send socket fd: %d\n", s);
    struct sockaddr_in server_addr;

    server_addr.sin_family = to->sa_family;
    server_addr.sin_port = htons(to->data.sin_data.port);
    alipay_log_debug("[test]sin_port %d\n",server_addr.sin_port);
    memcpy(&server_addr.sin_addr, to->data.sin_data.ip, 4);

    int fd = -1;
    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("%s get_origin_fd_by_alipay_socket failed\n", __func__);
        return -1;
    }

    int bytes_send = sendto(fd, dataptr, size, 0,
                            (const struct sockaddr *)&server_addr,
                            sizeof(server_addr));
    if (bytes_send < 0) {
        printf("fail to sendto alipay sock %d\n", fd);
        return -1;
    }
    alipay_log_debug("bytes send: %d\n", bytes_send);

    return bytes_send;
}

int alipay_iot_socket_write(int s, const void *dataptr, int len)
{
    int fd = -1;
    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("%s get_origin_fd_by_alipay_socket failed\n", __func__);
        return -1;
    }
    int size = send(fd, dataptr, len, 0);
    if (size < 0) {
        printf("%s\n", strerror(errno));
    }
    alipay_log_debug("send fd: %d - len: %d\n", fd, len);

    return size;
}

int alipay_iot_socket_recvfrom(int s,
                               void *mem,
                               int len,
                               int flags,
                               struct alipay_iot_sockaddr *from,
                               unsigned int *fromlen)
{
    int bytes_received = -1;

    int fd = -1;
    fd = get_origin_fd_by_alipay_socket(s);
    if (fd == -1) {
        printf("fail to connect alipay sock %d\n", s);
        return -1;
    }
    alipay_log_debug("socket recvfrom fd: %d\n", fd);

    if (from) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = from->sa_family;
            /* server_addr.sin_port = htons(443); */
        server_addr.sin_port = htons(from->data.sin_data.port);
        memcpy(&server_addr.sin_addr, from->data.sin_data.ip, 4);

        int addrlen = sizeof(server_addr);
        bytes_received = recvfrom(fd, mem, len, flags,
                                 (struct sockaddr *)&server_addr,
                                 (socklen_t *)&addrlen);
    } else {
        fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
        bytes_received = recv(fd, mem, len, flags);
    }
    alipay_log_debug("bytes_received: %d\n", bytes_received);
    if (bytes_received < 0) {
        printf("%s\n", strerror(errno));
    }

    return bytes_received;
}

int alipay_iot_socket_read(int s, void *mem, int len)
{
    alipay_log_debug("read fd: %d - len: %d\n", s, len);
    int n = alipay_iot_socket_recvfrom(s, mem, len, 0, NULL, NULL);
    alipay_log_debug("socket read %d\n", n);
    if (n <= 0 || n > len) {
        printf("%s failed\r\n", __func__);
        return -2;
    }

    return n;
}


int alipay_iot_socket_setsockopt(int s,
                                 int level,
                                 int optname,
                                 const void  *opval,
                                 unsigned int optlen)
{
    return 0;
}

int alipay_iot_socket_getsockopt(int s,
                                 int level,
                                 int optname,
                                 void *opval,
                                 unsigned int *optlen)
{
    return 0;
}
