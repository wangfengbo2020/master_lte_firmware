/***********************************************************************************
*file: lwip_customer.h
*descrition: declare for lwip_customer
***********************************************************************************/
#ifndef  __LWIP_CUSTOMER_H__
#define __LWIP_CUSTOMER_H__

#include "lwipopts.h"
#include "ip4.h"
#include "tcp_impl.h"

/****************************************************************
*function macro switch define 
****************************************************************/
/*function switch macro
* if set to 1: enable module
* if set to 0: disable module, and not compiler .c code.
*/
#define LWIP_PING_APP                   (1)
#if defined(CRANE_MCU_DONGLE) || defined(CRANE_MODULE_SUPPORT)
#define LWIP_FTP_CLIENT                 (1)
#else
#define LWIP_FTP_CLIENT                 (0)
#endif

#ifdef LTEONLY_THIN
#undef LWIP_PING_APP
#undef LWIP_FTP_CLIENT
#define LWIP_PING_APP                   (0)
#if defined(CRANEL_4MRAM) || defined(QUEC_MINSYS_THIN)  //quectel add
#define LWIP_FTP_CLIENT                 (0)
#else
#define LWIP_FTP_CLIENT                 (1)
#endif
#endif

#ifdef LTEONLY_THIN
#define LWIP_RATE_RXACK_DEFAULT_SET         (16)
#define LWIP_MQ_NW_ACK_SIZE         (60) //LTE_ACK_MSG_SIZE (64)
#endif
/****************************************************************
*Macro define 
*****************************************************************/
enum lwip_rate_control_status_e 
{
    RATE_CONTROL_STATUS_FIRST,
    RATE_CONTROL_STATUS_SEND,
    RATE_CONTROL_STATUS_DROP,    
    RATE_CONTROL_STATUS_END
};

/****************************************************************
*structure define 
*****************************************************************/
typedef struct{
    /* defined in lwipopts.h
    #define LWIP_DL_DIRECTION       (0)
    #define LWIP_UL_DIRECTION       (1)
    */
	u32_t direction;

    /* defined in etharp.h
    #define ETHTYPE_ARP       0x0806U  //ethernet packet
    #define ETHTYPE_IP        0x0800U  //IPv4 packet
    #define ETHTYPE_IPV6      0x86DDU  //IPv6 packet
    */
    u16_t protocal;    /* kinds of protocal, payload header type changed*/
    u16_t payloadlen;  /* payload length */
    void * payload;    /* payload pointer */

    char * netifname;  /* netif host name */
} lwip_ip_packet_info;

typedef struct
{
    u8_t ctlFlg; /*0: disable; 1: enalbel; default disable*/
    u8_t status; /*refer to lwip_rate_control_status_e define*/
    u8_t proto; /*UDP: 17; TCP: 6*/
    u8_t period; /*rate evalulate period, defaul is 1s*/
    u32_t maxRate; /*bytes per period , if period set to 1s, Bps set*/
    u32_t tickStart;
    u32_t sendBytes;
    u32_t dropBytes;
}lwip_rate_control_t;

/****************************************************************
*Global Var declare 
*****************************************************************/


/****************************************************************
*function declare
*****************************************************************/
void lwip_server_init_defined_minis(void);
void lwip_packet_to_modem(int cid, int ip_type, int length);
void lwip_packet_from_modem(int cid, int ip_type, int length);
void lwip_parameters_customer_defined(void);
void lwip_netifapi_customer_defined(void);
void lwip_server_init_defined(void);
int lwip_mac_filter_forward_chain(char *mac_addr, struct pbuf *p, unsigned char direction);
int lwip_tcp_wan_access_defined(struct netif *inp, struct tcp_hdr *tcphdr);
int lwip_platform_mode_defined(int *mode);
int lwip_dnsr_hijack_defined(char* nameQuery);
int lwip_hook_packet_captuer(lwip_ip_packet_info * ip_info);
int lwip_hook_nat_persistant_port(u16_t port);
int lwip_hook_rate_control_process(int direction, int proto, u16_t plen, struct netif * inp);
void lwip_hook_for_tcpip_thread(void);
int lwip_lte_require_check_defined(void);

#endif


