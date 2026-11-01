/*	$OpenBSD: rdate.c,v 1.22 2004/02/18 20:10:53 jmc Exp $	*/
/*	$NetBSD: rdate.c,v 1.4 1996/03/16 12:37:45 pk Exp $	*/

/*
 * Copyright (c) 1994 Christos Zoulas
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Christos Zoulas.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * rdate.c: Set the date from the specified host
 *
 *	Uses the rfc868 time protocol at socket 37.
 *	Time is returned as the number of seconds since
 *	midnight January 1st 1900.
 */
#ifndef lint
#if 0
from: static char rcsid[] = "$NetBSD: rdate.c,v 1.3 1996/02/22 06:59:18 thorpej Exp $";
#else
static const char rcsid[] = "$OpenBSD: rdate.c,v 1.22 2004/02/18 20:10:53 jmc Exp $";
#endif
#endif				/* lint */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef TTPCOM_TCPIP
#define TTPCOM_TCPIP
#endif

#include <stdio.h>
#include <ctype.h>
#include <err.h>
#include <string.h>
#include <time.h>
#include <sockets.h>
#include <netdb.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <netdb.h>
#include <stdlib.h>

#include "ntpleaps.h"
#include "arc4random.h"
#include "ntp.h"
#include "saremo_RTC.h"
#ifdef PSM_ENABLE
#include "psm_wrapper.h"
#endif
#include "utltime.h"

/* there are systems without libutil; for portability */
#ifdef HAVE_UTIL_H
#include <util.h>
#else
#define logwtmp(a,b,c)
#endif

#include "quec_cust_feature.h"
typedef unsigned int size_t, ssize_t;
typedef	long	fd_mask;
#define	NBBY	8
#define	NFDBITS	(sizeof(fd_mask) * NBBY)	/* bits per mask */

#ifndef howmany
#define	howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

#ifdef MRVL_USE_POOL_MEM
#define duster_free(p) DusterFree(p)
#else
#define duster_free(p) free(p)
#endif

/*
 * NTP definitions.  Note that these assume 8-bit bytes - sigh.  There
 * is little point in parameterising everything, as it is neither
 * feasible nor useful.  It would be very useful if more fields could
 * be defined as unspecified.  The NTP packet-handling routines
 * contain a lot of extra assumptions.
 */

#define JAN_1970   2208988800.0		/* 1970 - 1900 in seconds */
#define NTP_SCALE  4294967296.0		/* 2^32, of course! */

#define NTP_MODE_CLIENT       3		/* NTP client mode */
#define NTP_MODE_SERVER       4		/* NTP server mode */
#define NTP_VERSION           4		/* The current version */
#define NTP_VERSION_MIN       1		/* The minum valid version */
#define NTP_VERSION_MAX       4		/* The maximum valid version */
#define NTP_STRATUM_MAX      14		/* The maximum valid stratum */
#define NTP_INSANITY     3600.0		/* Errors beyond this are hopeless */

#define NTP_PACKET_MIN       48		/* Without authentication */
#define NTP_PACKET_MAX       68		/* With authentication (ignored) */

#define NTP_DISP_FIELD        8		/* Offset of dispersion field */
#define NTP_REFERENCE        16		/* Offset of reference timestamp */
#define NTP_ORIGINATE        24		/* Offset of originate timestamp */
#define NTP_RECEIVE          32		/* Offset of receive timestamp */
#define NTP_TRANSMIT         40		/* Offset of transmit timestamp */

#define STATUS_NOWARNING      0		/* No Leap Indicator */
#define STATUS_LEAPHIGH       1		/* Last Minute Has 61 Seconds */
#define STATUS_LEAPLOW        2		/* Last Minute Has 59 Seconds */
#define STATUS_ALARM          3		/* Server Clock Not Synchronized */

#define MAX_QUERIES         25
#define MAX_DELAY           15

#define MILLION_L    1000000l		/* For conversion to/from timeval */
#define MILLION_D       1.0e6		/* Must be equal to MILLION_L */

//#ifdef __GLIBC__
#define SA_LEN(x)	sizeof(*x)
//#endif

//#define DEBUG

struct ntp_data {
	u_char		status;
	u_char		version;
	u_char		mode;
	u_char		stratum;
	double		receive;
	double		transmit;
	double		current;
	u_int64_t	recvck;

	/* Local State */
	double		originate;
	u_int64_t	xmitck;
};

int ntp_client (const char *, int, struct timeval *, struct timeval *, int);
int	sync_ntp(int, const struct sockaddr *, double *, double *);
int	write_packet(int, struct ntp_data *);
int	read_packet(int, struct ntp_data *, double *, double *);
void	unpack_ntp(struct ntp_data *, u_char *);
double	current_time(double);
void	create_timeval(double, struct timeval *, struct timeval *);

#ifdef DEBUG
void	print_packet(const struct ntp_data *);
#endif

extern char    *__progname;

//#ifdef NTP
#ifdef QUEC_GNSS_NTP
#define NTP_TASK_PRIORITY    90
#define NTP_STACK_SIZE (3*1024)
#else 
#define NTP_TASK_PRIORITY    160
#define NTP_STACK_SIZE (2*1024)
#endif

OSTaskRef       NTPTaskRef;
UINT8*          NTPTaskStack=NULL;
//UINT32 NTPTaskStack[NTP_STACK_SIZE>>2] = {0x55555555};

static OSAFlagRef NtpFlagRef = NULL;
static time_t NtpResult = 0;
extern char *GetNTPServer(void);
extern int GetTimeZone(void);
extern char *psm_get_wrapper(char *mod_name, char *subspace, char *variable);
extern UINT8 getDefaultCidNum(void);
extern char get_linkstas(char cid);
extern int	 gettimeofday(struct timeval *tv, void* dummy);



int NTP_SYNC_SUCCESS = 0;

void SetNTPStatus(int flag)
{
	NTP_SYNC_SUCCESS = flag;
}

int GetNTPStatus(void)
{
	return NTP_SYNC_SUCCESS;
}

static unsigned int ntp_retry_timer[] = {
    (1 * 1000 / 5),         /*2 sec*/
	(10 * 1000 / 5),        /*10 sec*/
	(60 * 1000 / 5),        /*1 min*/
	(600 * 1000 / 5),       /*10 min*/
	(1800 * 1000 / 5),      /*30 min*/
	(3600 * 1000 / 5),      /*1 hour*/
	(18000 * 1000 / 5),     /*5 hour*/
	(36000 * 1000 / 5),     /*10 hour*/
};
static int ntp_retry_index = 0;
#define NTP_MAX_RETRY_COUNT (sizeof(ntp_retry_timer)/sizeof(unsigned int))

void NTPTask(void *argv)
{
	int pr = 0, silent = 0, ntp = 0, verbose = 0;
	int slidetime = 0, corrleaps = 0;
	char hname_default[32] = "202.112.31.197";
	char hname[32] = {'\0'};
	char *ntp_server = NULL;
	int c = 0;
	int family = PF_UNSPEC;
	struct tm	   *ltm = NULL;
	struct timeval new, adjust;
	char		buf[80];
	time_t		tim = 0;
	double		adjsec;

	UINT32 flag_value = 0;
	int ret = 0;
	OSA_STATUS status;

	while(1)
	{
		int try_times = 3;
		int count = 0;
		OSATaskSleep(50);
		status = OSAFlagWait(NtpFlagRef, NTP_FLAG_BIT, OSA_FLAG_OR_CLEAR, &flag_value, OSA_SUSPEND);
		ASSERT(status == OS_SUCCESS);
		SetNTPStatus(0);
		CPUartLogPrintf("%s status %u", __FUNCTION__, GetNTPStatus());
#ifndef QUEC_GNSS_NTP	
        while(!get_linkstas(getDefaultCidNum() - 1) && count < 8)
		{
			OSATaskSleep(200 * pow(2, count));
			++count;
		}
		ntp_server = GetNTPServer();
		if(ntp_server)
		{
			strncpy(hname, ntp_server, 32);
		}
#ifdef NO_EXTEND_MY_Q_AT
		if(bspGetBoardType() == TIGX_MIFI){

            if(ntp_retry_index >= NTP_MAX_RETRY_COUNT){
                ntp_retry_index = NTP_MAX_RETRY_COUNT - 1;
            }
            OSATaskSleep(ntp_retry_timer[ntp_retry_index]);
            ntp_retry_index++;
            strncpy(hname, hname_default, 32);

		}
#endif
#endif
#ifdef QUEC_GNSS_NTP
extern char *get_ntp_server_ip(void);
        strncpy(hname,get_ntp_server_ip(),32);
        RTI_LOG("NTP SRVER is %s", hname);
#endif
		while(try_times > 0 && count < 8)
		{
			--try_times;
			if(strlen(hname) > 0)
				ret = ntp_client(hname, family, &new, &adjust, corrleaps);
			else
				ret = ntp_client(hname_default, family, &new, &adjust, corrleaps);

			if(ret != 0)
			{
				continue;
			}
			tim = new.tv_sec;
			NtpResult = tim;

			ltm = localtime(&tim);
			(void) strftime(buf, sizeof buf, "%a %b %e %H:%M:%S %Z %Y\n", ltm);
			CPUartLogPrintf("NTPTask time is %s", buf);

			if (new.tv_sec > 60 * 60 * 24 * 365)
			{
				SaveNTPParameters(ltm);
				break;
			}
			OSATaskSleep(200);

        }
		if(try_times > 0)
		{
			SetNTPStatus(1);//successful
		}
		else
		{

			SetNTPStatus(2);//failed
		}

	}

}

void NTP_Init_Internal(void)
{
	OSA_STATUS  status;
	char *str = NULL;

#ifdef NTP
	str = psm_get_wrapper("Debug", NULL, "debug_ntp_disable");
	if (str && strcmp(str, "1") == 0)
	{
		free(str);
		return;
	}
	if (str)
		free(str);

	/* Ntp Flag initialize. */
    status = OSAFlagCreate(&NtpFlagRef);
    ASSERT(status == OS_SUCCESS);
    
	NTPTaskStack = malloc(NTP_STACK_SIZE);
	if(NTPTaskStack != NULL)
		memset(NTPTaskStack,0x55,NTP_STACK_SIZE);
	else
		return;

    status = OSATaskCreate(&NTPTaskRef, (void *)NTPTaskStack, NTP_STACK_SIZE,
                        NTP_TASK_PRIORITY, "NTPTask", NTPTask, NULL);
    ASSERT(status == OS_SUCCESS);
#endif
}

void SyncNTP(void)
{
#ifdef NTP
	OSA_STATUS	status;
	if(NtpFlagRef != NULL)
	{
		status = OSAFlagSet(NtpFlagRef, NTP_FLAG_BIT, OSA_FLAG_OR);
		ASSERT(status == OS_SUCCESS);
	}
#endif
}

time_t GetNtpResult(void)
{
	return NtpResult;
}
//#endif

int
ntp_client(const char *hostname, int family, struct timeval *new,
    struct timeval *adjust, int leapflag)
{
	struct addrinfo hints, *res0 = NULL, *res = NULL;
	double offset = 0, error = 0;
	int accept = 0, ret, s, ierror;

#if 0
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(123);

	if(inet_aton(hostname, &servaddr.sin_addr) < 0)
	{
		CPUartLogPrintf("convert ip error %s\n", strerror(errno));
		return -1;
	}
	s = socket(AF_INET, SOCK_DGRAM, 0);

	ret = sync_ntp(s, (struct sockaddr *)&servaddr, &offset, &error);
	if (ret < 0) {
#ifdef DEBUG
		CPUartLogPrintf("try the next address\n");
#endif
		close(s);
		s = -1;
		return -1;
	}
#endif

#if 1
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = family;
	hints.ai_socktype = SOCK_DGRAM;
	ierror = getaddrinfo(hostname, "123", &hints, &res0);
	if (ierror) {
		CPUartLogPrintf("%s: %d", hostname, ierror);
		return -1;
		/*NOTREACHED*/
	}

	s = -1;
	for (res = res0; res; res = res->ai_next) {
		s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (s < 0)
			continue;
#ifdef QUEC_GNSS_NTP
   struct sockaddr_in	ip4_local_addr = {0};
extern struct in_addr quec_get_gps_ip4_addr(void);
        ip4_local_addr.sin_family = AF_INET;
		ip4_local_addr.sin_port = htons(0);
		ip4_local_addr.sin_addr = quec_get_gps_ip4_addr();
        ret = bind(s, (struct sockaddr *)&ip4_local_addr, sizeof(ip4_local_addr));
#endif
		ret = sync_ntp(s, res->ai_addr, &offset, &error);
		if (ret < 0) {
#ifdef DEBUG
			CPUartLogPrintf("%s: try the next address\n", __func__);
#endif
			close(s);
			s = -1;
			continue;
		}

		accept++;
		close(s);
		s = -1;
		break;
	}
	freeaddrinfo(res0);
#endif

#ifdef DEBUG
	CPUartLogPrintf("%s: Correction %.6f +/- %.6f\n", __func__, offset, error);
#endif

	if (accept < 1)
	{
		CPUartLogPrintf("%s: Unable to get a reasonable time estimate", __func__);
		return -1;
	}

	create_timeval(offset, new, adjust);

	return 0;
}

int
sync_ntp(int fd, const struct sockaddr *peer, double *offset, double *error)
{
	int attempts = 0, accepts = 0, rejects = 0, retry_num=0;
	int delay = MAX_DELAY, ret;
	double deadline;
	double a, b, x, y;
	double minerr = 0.1;		/* Maximum ignorable variation */
	struct ntp_data data;

	deadline = current_time(JAN_1970) + delay;
	*offset = 0.0;
	*error = NTP_INSANITY;

	if (connect(fd, peer, SA_LEN(peer)) < 0) {
		CPUartLogPrintf("Failed to connect to server");
		return (-1);
	}
    if(bspGetBoardType() == TIGX_MIFI){
        retry_num = 2;
    }else{
        retry_num = MAX_QUERIES;
    }

	while (accepts < retry_num && attempts < 2 * retry_num) {
		memset(&data, 0, sizeof(data));

		if (current_time(JAN_1970) > deadline) {
			CPUartLogPrintf("Not enough valid responses received in time");
			return (-1);
		}

		if (write_packet(fd, &data) < 0)
			return (-1);

		ret = read_packet(fd, &data, &x, &y);

		if (ret < 0)
			return (-1);
		else if (ret > 0) {
#ifdef DEBUG
			print_packet(&data);
#endif

			if (++rejects > retry_num) {
				CPUartLogPrintf("Too many bad or lost packets");
				return (-1);
			} else{
				continue;
			}
		} else
			++accepts;

#ifdef DEBUG
		CPUartLogPrintf("Offset: %.6f +/- %.6f\n", x, y);
#endif

		if ((a = x - *offset) < 0.0)
			a = -a;
		if (accepts <= 1)
			a = 0.0;
		b = *error + y;
		if (y < *error) {
			*offset = x;
			*error = y;
		}

#ifdef DEBUG
		CPUartLogPrintf("Best: %.6f +/- %.6f\n", *offset, *error);
#endif

		if (a > b) {
			CPUartLogPrintf("Inconsistent times received from NTP server");
			return (-1);
		}

		if ((data.status & STATUS_ALARM) == STATUS_ALARM) {
			CPUartLogPrintf("Ignoring NTP server with alarm flag set");
			return (-1);
		}

		if (*error <= minerr)
			break;
	}

	return (accepts);
}

/* Send out NTP packet. */
int
write_packet(int fd, struct ntp_data *data)
{
	u_char	packet[NTP_PACKET_MIN];
	ssize_t	length;

	memset(packet, 0, sizeof(packet));

	packet[0] = (NTP_VERSION << 3) | (NTP_MODE_CLIENT);

	data->xmitck = (u_int64_t)arc4random() << 32 | arc4random();

	/*
	 * Send out a random 64-bit number as our transmit time.  The NTP
	 * server will copy said number into the originate field on the
	 * response that it sends us.  This is totally legal per the SNTP spec.
	 *
	 * The impact of this is two fold: we no longer send out the current
	 * system time for the world to see (which may aid an attacker), and
	 * it gives us a (not very secure) way of knowing that we're not
	 * getting spoofed by an attacker that can't capture our traffic
	 * but can spoof packets from the NTP server we're communicating with.
	 *
	 * No endian concerns here.  Since we're running as a strict
	 * unicast client, we don't have to worry about anyone else finding
	 * the transmit field intelligible.
	 */

	*(u_int64_t *)(packet + NTP_TRANSMIT) = data->xmitck;

	data->originate = current_time(JAN_1970);

	length = write(fd, packet, sizeof(packet));

	if (length != sizeof(packet)) {
		CPUartLogPrintf("Unable to send NTP packet to server");
		return (-1);
	}

	return (0);
}

/*
 * Check the packet and work out the offset and optionally the error.
 * Note that this contains more checking than xntp does. Return 0 for
 * success, 1 for failure. Note that it must not change its arguments
 * if it fails.
 */
int
read_packet(int fd, struct ntp_data *data, double *off, double *error)
{
	u_char	receive[NTP_PACKET_MAX];
	struct	timeval tv;
	double	x, y;
	int	length, r;
	fd_set	rfds;

	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

retry:
	tv.tv_sec = 0;
	tv.tv_usec = 1000000 * MAX_DELAY / MAX_QUERIES;

	r = select(fd + 1, &rfds, NULL, NULL, &tv);

	if (r < 0) {
		if (errno == EINTR)
			goto retry;
		else
			CPUartLogPrintf("%s: select" ,__FUNCTION__);

		return (r);
	}

	if (r != 1 || !FD_ISSET(fd, &rfds)) {
		CPUartLogPrintf("%s: no event ready after timeout" ,__FUNCTION__);
		return (1);
	}

	length = read(fd, receive, NTP_PACKET_MAX);

	if (length < 0) {
		CPUartLogPrintf(" %s: Unable to receive NTP packet from server", __FUNCTION__);
		return (-1);
	}

	if (length < NTP_PACKET_MIN || length > NTP_PACKET_MAX) {
		CPUartLogPrintf("%s: Invalid NTP packet size, packet rejected", __FUNCTION__);
		return (1);
	}

	unpack_ntp(data, receive);

	if (data->recvck != data->xmitck) {
		CPUartLogPrintf("%s: Invalid cookie received, packet rejected", __FUNCTION__);
		return (1);
	}

	if (data->version < NTP_VERSION_MIN ||
	    data->version > NTP_VERSION_MAX) {
	    CPUartLogPrintf("%s: Received NTP version %u, need %u or lower", __FUNCTION__,\
			data->version, NTP_VERSION);
		return (1);
	}

	if (data->mode != NTP_MODE_SERVER) {
		CPUartLogPrintf("%s: Invalid NTP server mode, packet rejected", __FUNCTION__);
		return (1);
	}

	if (data->stratum > NTP_STRATUM_MAX) {
		CPUartLogPrintf("%s: Invalid stratum received, packet rejected", __FUNCTION__);
		return (1);
	}

	if (data->transmit == 0.0) {
		CPUartLogPrintf("%s: Server clock invalid, packet rejected", __FUNCTION__);
		return (1);
	}

	x = data->receive - data->originate;
	y = data->transmit - data->current;

	*off = (x + y) / 2;
	*error = x - y;

	x = (data->current - data->originate) / 2;

	if (x > *error)
		*error = x;

	return (0);
}

/*
 * Unpack the essential data from an NTP packet, bypassing struct
 * layout and endian problems.  Note that it ignores fields irrelevant
 * to SNTP.
 */
void
unpack_ntp(struct ntp_data *data, u_char *packet)
{
	int i;
	double d;

	data->current = current_time(JAN_1970);

	data->status = (packet[0] >> 6);
	data->version = (packet[0] >> 3) & 0x07;
	data->mode = packet[0] & 0x07;
	data->stratum = packet[1];

	for (i = 0, d = 0.0; i < 8; ++i)
	    d = 256.0*d+packet[NTP_RECEIVE+i];

	data->receive = d / NTP_SCALE;

	for (i = 0, d = 0.0; i < 8; ++i)
	    d = 256.0*d+packet[NTP_TRANSMIT+i];

	data->transmit = d / NTP_SCALE;

	/* See write_packet for why this isn't an endian problem. */
	data->recvck = *(u_int64_t *)(packet + NTP_ORIGINATE);
}

/*
 * Get the current UTC time in seconds since the Epoch plus an offset
 * (usually the time from the beginning of the century to the Epoch)
 */
double
current_time(double offset)
{
	struct timeval current;
	u_int64_t t;

	if (gettimeofday(&current, NULL))
		CPUartLogPrintf("Could not get local time of day");

	/*
	 * At this point, current has the current TAI time.
	 * Now subtract leap seconds to set the posix tick.
	 */

	t = SEC_TO_TAI64(current.tv_sec);
	//if (corrleaps)
		//ntpleaps_sub(&t);

	return (offset + TAI64_TO_SEC(t) + 1.0e-6 * current.tv_usec);
}

/*
 * Change offset into current UTC time. This is portable, even if
 * struct timeval uses an unsigned long for tv_sec.
 */
void
create_timeval(double difference, struct timeval *new, struct timeval *adjust)
{
	struct timeval old;
	long n;

	/* Start by converting to timeval format. Note that we have to
	 * cater for negative, unsigned values. */
	if ((n = (long) difference) > difference)
		--n;
	adjust->tv_sec = n;
	adjust->tv_usec = (long) (MILLION_D * (difference-n));
	errno = 0;
	if (gettimeofday(&old, NULL))
		CPUartLogPrintf("%s: Could not get local time of day", __func__);
	new->tv_sec = old.tv_sec + adjust->tv_sec;
	new->tv_usec = (n = (long) old.tv_usec + (long) adjust->tv_usec);

	if (n < 0) {
		new->tv_usec += MILLION_L;
		--new->tv_sec;
	} else if (n >= MILLION_L) {
		new->tv_usec -= MILLION_L;
		++new->tv_sec;
	}
}

#ifdef DEBUG
void
print_packet(const struct ntp_data *data)
{
	CPUartLogPrintf("%s: start");
	CPUartLogPrintf("status:      %u\n", data->status);
	CPUartLogPrintf("version:     %u\n", data->version);
	CPUartLogPrintf("mode:        %u\n", data->mode);
	CPUartLogPrintf("stratum:     %u\n", data->stratum);
	CPUartLogPrintf("originate:   %f\n", data->originate);
	CPUartLogPrintf("receive:     %f\n", data->receive);
	CPUartLogPrintf("transmit:    %f\n", data->transmit);
	CPUartLogPrintf("current:     %f\n", data->current);
	CPUartLogPrintf("xmitck:      0x%0llX\n", data->xmitck);
	CPUartLogPrintf("recvck:      0x%0llX\n", data->recvck);
	CPUartLogPrintf("%s: end");
};
#endif

