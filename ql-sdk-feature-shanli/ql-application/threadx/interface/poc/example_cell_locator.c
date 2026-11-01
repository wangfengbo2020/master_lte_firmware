/**
  @file
  example_cell_locator.c

  @brief
  Cell locator module - provides init and single-shot query interface.
*/
/*============================================================================
  Copyright (c) 2017 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ql_rtos.h"
#include "ql_data_call.h"
#include "ql_http_client.h"
#include "ql_cell_locator.h"
#include "ql_log.h"
#include "ql_nw.h"
#include "sockets.h"
#include "netdb.h"

#define CELL_LOCATOR_SERVER_DOMAIN "www.queclocator.com"
#define CELL_DATACALL_CID         1
#define CELL_DATACALL_WAIT_S      15
#define CELL_DATACALL_POLL_MS     3000

static ql_cell_cfg *g_cell_cfg = NULL;
static int g_cell_inited = 0;

int cell_locator_init(void)
{
	int ret;
	char token[32] = "iDeV5n81yB0n97kW";
	int port = 80;
	int timeout = 30;

	if (g_cell_inited)
		return 0;

	g_cell_cfg = malloc(sizeof(ql_cell_cfg));
	if (g_cell_cfg == NULL) {
		printf("[CELL] malloc failed\n");
		return -1;
	}

	ret = ql_cell_locator_init(g_cell_cfg);
	if (ret) {
		printf("[CELL] init error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_set_server(g_cell_cfg, CELL_LOCATOR_SERVER_DOMAIN, port);
	if (ret) {
		printf("[CELL] set_server error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_set_cid(g_cell_cfg, 1);
	if (ret) {
		printf("[CELL] set_cid error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_set_timeout(g_cell_cfg, timeout);
	if (ret) {
		printf("[CELL] set_timeout error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_set_token(g_cell_cfg, token, strlen(token));
	if (ret) {
		printf("[CELL] set_token error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_setopt(g_cell_cfg, QL_CELL_OPT_ASYN, 0);
	if (ret) {
		printf("[CELL] set ASYN error: %d\n", ret);
		goto fail;
	}

	ret = ql_cell_locator_setopt(g_cell_cfg, QL_CELL_OPT_METHOD, QL_CELL_TYPE_CELL);
	if (ret) {
		printf("[CELL] set METHOD error: %d\n", ret);
		goto fail;
	}

	g_cell_inited = 1;
	printf("[CELL] init success\r\n");
	ql_app_log("[LOC][LBS] cell locator init OK, server=%s, timeout=%ds", CELL_LOCATOR_SERVER_DOMAIN, timeout);
	return 0;

fail:
	free(g_cell_cfg);
	g_cell_cfg = NULL;
	return -1;
}

static int cell_locator_test_connectivity(void)
{
	u32 t0, t1;
	struct addrinfo hints;
	struct addrinfo *res = NULL;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	t0 = ql_rtos_get_systicks();
	int dns_ret = getaddrinfo_with_pcid(CELL_LOCATOR_SERVER_DOMAIN, NULL, &hints, &res, CELL_DATACALL_CID);
	t1 = ql_rtos_get_systicks();
	if (dns_ret != 0 || res == NULL) {
		printf("[CELL-TEST] DNS FAILED for %s (CID=%d, %ums)\r\n",
			CELL_LOCATOR_SERVER_DOMAIN, CELL_DATACALL_CID, (t1 - t0) * 5);
		if (res) freeaddrinfo(res);
		return -1;
	}

	struct sockaddr_in *ip4_addr = (struct sockaddr_in *)res->ai_addr;
	unsigned char *ip = (unsigned char *)&ip4_addr->sin_addr.s_addr;
	printf("[CELL-TEST] DNS OK: %s -> %d.%d.%d.%d (CID=%d, %ums)\r\n",
		CELL_LOCATOR_SERVER_DOMAIN, ip[0], ip[1], ip[2], ip[3],
		CELL_DATACALL_CID, (t1 - t0) * 5);

	freeaddrinfo(res);
	return 0;
}

static void cell_locator_reinit(void)
{
	if (g_cell_cfg) {
		ql_cell_locator_release(g_cell_cfg);
		free(g_cell_cfg);
		g_cell_cfg = NULL;
	}
	g_cell_inited = 0;
	printf("[CELL] reinit after error\r\n");
	cell_locator_init();
}

static int cell_locator_wait_datacall(void)
{
	struct ql_data_call_info info;
	int waited = 0;

	while (waited < CELL_DATACALL_WAIT_S) {
		memset(&info, 0, sizeof(info));
		ql_get_data_call_info(CELL_DATACALL_CID, 0, &info);
		if (info.v4.addr.ip.s_addr != 0) {
			unsigned char *p = (unsigned char *)&info.v4.addr.ip.s_addr;
			printf("[CELL] datacall CID=%d ready, ip=%u.%u.%u.%u (waited %ds)\r\n",
				CELL_DATACALL_CID, p[0], p[1], p[2], p[3], waited);
			return 0;
		}
		printf("[CELL] datacall CID=%d not ready, waiting... (%d/%ds)\r\n",
			CELL_DATACALL_CID, waited, CELL_DATACALL_WAIT_S);
		ql_rtos_task_sleep_ms(CELL_DATACALL_POLL_MS);
		waited += CELL_DATACALL_POLL_MS / 1000;
	}

	printf("[CELL] datacall CID=%d not recovered after %ds\r\n",
		CELL_DATACALL_CID, CELL_DATACALL_WAIT_S);
	return -1;
}

int cell_locator_query(float *lng, float *lat)
{
	printf("[CELL] query called, inited=%d, cfg=%p\r\n", g_cell_inited, g_cell_cfg);
	ql_app_log("[LOC][LBS] cell_locator_query called, inited=%d", g_cell_inited);
	if (!g_cell_inited || g_cell_cfg == NULL) {
		printf("[CELL] query aborted: not initialized\r\n");
		return -1;
	}

	printf("[CELL] cfg: server=%s, port=%d, timeout=%d(s), method=%d, cid=%d, asyn=%d\r\n",
		g_cell_cfg->server, g_cell_cfg->sever_port, g_cell_cfg->timeout,
		g_cell_cfg->loc_method, g_cell_cfg->cid, g_cell_cfg->asyn_f);

	if (cell_locator_wait_datacall() < 0) {
		return -1;
	}

	{
		QL_NW_CELL_INFO_T cell_info;
		memset(&cell_info, 0, sizeof(cell_info));
		int nw_ret = ql_nw_get_cell_info(&cell_info);
		printf("[CELL] ql_nw_get_cell_info ret=%d\r\n", nw_ret);
		if (nw_ret == 0) {
			printf("[CELL] gsm_valid=%d num=%d, umts_valid=%d num=%d, lte_valid=%d num=%d\r\n",
				cell_info.gsm_info_valid, cell_info.gsm_info_num,
				cell_info.umts_info_valid, cell_info.umts_info_num,
				cell_info.lte_info_valid, cell_info.lte_info_num);
			if (cell_info.lte_info_valid && cell_info.lte_info_num > 0) {
				for (int i = 0; i < cell_info.lte_info_num; i++) {
					printf("[CELL] LTE[%d] flag=%u cid=%u mcc=%u mnc=%u tac=%u pci=%u earfcn=%u rssi=%d sinr=%d\r\n",
						i,
						cell_info.lte_info[i].flag,
						cell_info.lte_info[i].cid,
						cell_info.lte_info[i].mcc,
						cell_info.lte_info[i].mnc,
						cell_info.lte_info[i].tac,
						cell_info.lte_info[i].pci,
						cell_info.lte_info[i].earfcn,
						cell_info.lte_info[i].rssi,
						cell_info.lte_info[i].sinr);
				}
			}
			if (cell_info.gsm_info_valid && cell_info.gsm_info_num > 0) {
				for (int i = 0; i < cell_info.gsm_info_num; i++) {
					printf("[CELL] GSM[%d] flag=%d cid=%d mcc=%d mnc=%d lac=%d arfcn=%d rssi=%d\r\n",
						i,
						cell_info.gsm_info[i].flag,
						cell_info.gsm_info[i].cid,
						cell_info.gsm_info[i].mcc,
						cell_info.gsm_info[i].mnc,
						cell_info.gsm_info[i].lac,
						cell_info.gsm_info[i].arfcn,
						cell_info.gsm_info[i].rssi);
				}
			}
		}

		int csq = 0;
		if (ql_nw_get_csq(&csq) == 0) {
			printf("[CELL] CSQ=%d\r\n", csq);
		}
	}

	if (cell_locator_test_connectivity() < 0) {
		printf("[CELL] DNS unreachable via CID=%d, skipping perform\r\n", CELL_DATACALL_CID);
		return -1;
	}

	u32 t_start = ql_rtos_get_systicks();

	int ret = ql_cell_locator_perform(g_cell_cfg);

	u32 t_end = ql_rtos_get_systicks();
	u32 elapsed_ms = (t_end - t_start) * 5;
	printf("[CELL] perform returned %d, elapsed=%ums (timeout=%ds)\r\n",
		ret, elapsed_ms, g_cell_cfg->timeout);

	if (ret == 0) {
		printf("[CELL] OK lng:%.6f lat:%.6f acc:%d\r\n",
			g_cell_cfg->lng, g_cell_cfg->lat, g_cell_cfg->accuracy);
		ql_app_log("[LOC][LBS] query OK: lng=%.6f, lat=%.6f, acc=%d, elapsed=%ums",
			g_cell_cfg->lng, g_cell_cfg->lat, g_cell_cfg->accuracy, elapsed_ms);
		if (elapsed_ms > (u32)g_cell_cfg->timeout * 1000) {
			printf("[CELL] WARNING: elapsed %ums > timeout %ds, response may be stale or timeout not enforced\r\n",
				elapsed_ms, g_cell_cfg->timeout);
		}
		if (g_cell_cfg->lng == 0.0f && g_cell_cfg->lat == 0.0f) {
			printf("[CELL] ERROR: ret=0 but coords are zero, treating as failure\r\n");
			printf("[CELL] err_code=%d, err_msg=%s\r\n",
				g_cell_cfg->err.err_code, g_cell_cfg->err.err_msg);
			return -1;
		}
		if (lng) *lng = g_cell_cfg->lng;
		if (lat) *lat = g_cell_cfg->lat;
		return 0;
	}

	printf("[CELL] perform error: %d, err_code:%d, err_msg=%s\r\n",
		ret, g_cell_cfg->err.err_code, g_cell_cfg->err.err_msg);
	ql_app_log("[LOC][LBS] query FAIL: ret=%d, err_code=%d, elapsed=%ums",
		ret, g_cell_cfg->err.err_code, elapsed_ms);
	if (elapsed_ms > (u32)g_cell_cfg->timeout * 1000) {
		printf("[CELL] ERROR: query timed out (%ums > %ds), timeout may be too short\r\n",
			elapsed_ms, g_cell_cfg->timeout);
	}

	return -1;
}
