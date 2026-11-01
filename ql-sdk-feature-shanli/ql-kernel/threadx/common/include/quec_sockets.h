/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_SOCKETS_H
#define QUEC_SOCKETS_H

#include "quec_common.h"
#include "ci_api_types.h"
#include "teldef.h"
#include "netdb.h"
#include "sockets.h"
#include "quec_net.h"

#ifdef QUEC_SOCKET_SUPPORT
#define QUEC_SOC_TCP   SOCK_STREAM
#define QUEC_SOC_UDP   SOCK_DGRAM
#define QUEC_SOC_RAW   SOCK_RAW

#define QUEC_AF_INET   AF_INET
#define QUEC_PF_INET   PF_INET
#define QUEC_AF_INET6  AF_INET6
#define QUEC_PF_INET6  PF_INET6


#define QUEC_IP_PROTOCOL   IPPROTO_IP
#define QUEC_TCP_PROTOCOL  IPPROTO_TCP
#define QUEC_UDP_PROTOCOL  IPPROTO_UDP


#define QUEC_SOC_READ_EVENT                  0x0001
#define QUEC_SOC_WRITE_EVENT                 0x0002
#define QUEC_SOC_ACCEPT_EVENT                0x0004
#define QUEC_SOC_CONNECT_EVENT               0x0008
#define QUEC_SOC_CLOSE_EVENT                 0x0010
#define QUEC_SOC_NET_DOWN_EVENT              0x0020
#define QUEC_SOC_SSL_HANDSHARK_TIMEOUT_EVENT 0x0040
#ifdef QUEC_TCP_NETCONN_EVT_SENDACKED_FEATURE
#define QUEC_SOC_SENDENDACK_EVENT            0x0080
#endif

#define QUEC_MAX_DNS_ENTEY_NUM               5
typedef void  (*quec_soc_event_cb) (int      sockfd, uint32  event_mask, int err_no, void *  user_data);


typedef enum 
{
	QUEC_SOC_OK = 0,
	QUEC_SOC_ERR_UNKNOWN = -1,
	QUEC_SOC_ERR_WODBLOCK = -2,
	QUEC_SOC_ERR_INVALID_PARAM = -3,
	QUEC_SOC_ERR_NOT_ALLOW = -4,
	QUEC_SOC_ERR_SOC_BIND_FAIL = -5,
	QUEC_SOC_ERR_SOC_CONNECT_FAIL = -6,
	QUEC_SOC_ERR_SOC_CLOSED = -7,
	QUEC_SOC_ERR_DNS_FAIL = -8,
	QUEC_SOC_ERR_TIMEOUT = -9,
}quec_sockets_err_code;

typedef enum 
{
	QUEC_SOC_NONE = 0,
	QUEC_SOC_CONNECTING,
	QUEC_SOC_CONNECT,
	QUEC_SOC_LISTEN,
	QUEC_SOC_CLOSING,
	QUEC_SOC_CLOSED = QUEC_SOC_NONE,
}quec_socket_state;

typedef enum{
	QUEC_SOC_SEND_BUF = 1,
	QUEC_SOC_RECV_BUF,
	QUEC_SOC_LINGER,
	QUEC_SOC_REUSE_ADDR,
	QUEC_SOC_REUSE_PORT,
	QUEC_SOC_TCP_NODELAY,
	QUEC_SOC_TCP_ACK,
	QUEC_SOC_TCP_UNACK,
	QUEC_SOC_TCP_REST,
	QUEC_SOC_TCP_KEEPALIVE,
	QUEC_SOC_TCP_RTO_VAL,
	QUEC_SOC_TCP_MSS_VAL,	
	QUEC_SOC_TCP_CLOSE_TIMEROUT,
	QUEC_SOC_TCP_KEEPIDLE,
	QUEC_SOC_TCP_KEEPINTVL,
	QUEC_SOC_TCP_KEEPCNT,
}quec_socket_opt_name;

typedef struct
{
    quec_timer_t timer_t;
}quec_soc_timer_t;

typedef struct
{
	quec_socket_state    state;
	int                  type;
	int                  family_type;
	int                  netid;
	int                  sockfd;
	quec_ip_addr         local_addr;
	uint16               local_port;
	quec_ip_addr         remote_addr;
	uint16               remote_port;
    uint32               event_set;
    uint8                sd_how;
	bool                 close_called;
	quec_soc_event_cb    event_cb;
	void*                user_data;
#ifdef QUEC_SSL_SUPPORT
    uint32               ssl_time_id;
#endif
}quec_socket;



#define QUEC_SOCKET_MAX_NUM     20

int  quec_sockets_init(void);

int  quec_soc_create(int       family_type, int soc_type, int protocol_type, int  pdp_cid);

int  quec_soc_select(int socket, int event_mask, quec_soc_event_cb event_cb, void *user_data);

int  quec_soc_bind(int socket, quec_ip_addr *local_addr, uint16 local_port);

int  quec_soc_listen(int socket, int backlog);

int  quec_soc_connect(int socket, quec_ip_addr *remote_addr, uint16 remote_port);

int  quec_soc_accept(int socket, quec_ip_addr *remote_addr, uint16 *remote_port);

int  quec_soc_send(int socket, uint8 *data_ptr, uint32 data_len);

int  quec_soc_recv(int socket, uint8 *data_ptr, uint32 data_len);

int  quec_soc_sendto(int socket,  uint8 *data_ptr, uint32 data_len, quec_ip_addr *to_addr, uint16 to_port);

int  quec_soc_recvfrom(int socket, uint8 *data_ptr, uint32 data_len, quec_ip_addr *from_addr, uint16 *from_port);

int  quec_soc_getopt(int socket, uint32 optname, void *opt_val_ptr, uint32 *opt_len);

int  quec_soc_setopt(int socket, uint32 optname, void *opt_val_ptr, uint32 opt_len);

int  quec_soc_getpeername(int sockfd, quec_ip_addr *remote_addr, uint16 *remote_port, int family_type);

int  quec_soc_getlocalname(int socket, quec_ip_addr *local_addr, uint16 *local_port);

int  quec_soc_shutdown(int socket, int how);
	
int  quec_soc_close(int socket);

int  quec_gethostbyname(char *hostname, quec_ip_addr *addrlist, int  *addr_cnt);

uint16  quec_soc_generate_port(void);

int quec_soc_get_ipv4v6_local_addr(int pdp_cid, int ai_family, struct sockaddr * _sockaddr);

int quec_soc_get_ipv4v6_pri_dns_addr(int pdp_cid, int ai_family, struct sockaddr * _sockaddr);

int quec_soc_get_ipv4v6_sec_dns_addr(int pdp_cid, int ai_family, struct sockaddr * _sockaddr);

int quec_soc_get_ipv6_global_addr(int pdp_cid, struct sockaddr_in6 * _sockaddr);

int quec_soc_local_bind(int pdp_cid, int sock_fd, int ai_family, uint16 local_port);

uint32 quec_soc_apptcpip_timer_create(void);

QuecOSStatus quec_soc_apptcpip_timer_start(uint32 timer_id,uint32 init_time,bool cyclical_enable,
                                                            void(* callback_routine)(uint32),uint32 timer_argc);
                                                            
QuecOSStatus quec_soc_apptcpip_timer_stop(uint32 timer_id);

QuecOSStatus quec_soc_apptcpip_timer_delete(uint32 timer_id);

bool quec_soc_apptcpip_timer_is_running(uint32 timer_id);

#ifdef QUECTEL_OPEN_CPU 
  /*function£ºflash dns_table*/
 void quec_dns_tables_flush(void);

 
#endif



#ifdef QUEC_SSL_SUPPORT
int  quec_soc_recv_ex(int sockfd, uint8 *data_ptr, uint32 data_len);
int  quec_soc_send_ex(int socket, uint8 *data_ptr, uint32 data_len);


int  quec_soc_ssl_recv(int ssl_session_handle, int socket, uint8 *data_ptr, uint32 data_len);

int quec_soc_ip_is_equal(quec_ip_addr   *ip_addr1,quec_ip_addr   *ip_addr2);

int quec_wolfssl_set_select(int sockfd,int event_mask, void *error);

int  quec_soc_start_ssl_handshark_timer(int qsockfd,int32  timeout);

int  quec_soc_stop_ssl_handshark_timer(int qsockfd);


int quec_soc_get_socket_fd(int s);

#endif /* QUEC_SSL_SUPPORT */

#endif
#endif
