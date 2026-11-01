#include "secboot.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reg.h"
#include "secboot.h"
#include "ptable.h"
#include "loadtable.h"
#include "fip.h"
#include "mbtlib.h"


#if 0
extern int check_integrity(void *img, unsigned int img_len);
extern int get_auth_param(const auth_param_type_desc_t *type_desc,
		void *img, unsigned int img_len,
		void **param, unsigned int *param_len);
extern int verify_signature(void *data_ptr, unsigned int data_len,
			    void *sig_ptr, unsigned int sig_len,
			    void *sig_alg, unsigned int sig_alg_len,
			    void *pk_ptr, unsigned int pk_len
				);
extern int verify_hash(void *data_ptr, unsigned int data_len,
		       void *digest_info_ptr, unsigned int digest_info_len);
#else

#define MBEDTLS_IO_BUF_MAX (64 * 1024)

tls_handle g_tls_handle = NULL;
static fip_handle g_secboot_fh;
uint32_t my_pk_len = 0;

void *g_io_read_buf = NULL;

/*
 * boot33:
 * alloc big heap space for io read buffer, emmc will read use DMA.
 */
int
tls_io_read(uint64_t addr, void **data, size_t *size)
{
    int ret;
    /*image data total length */
    size_t ilen = *size;

    if (addr == 0 || data == NULL || size == NULL) {
        return -1;
    }

    /*alloc io buf <= 64K and aligned with 8 byte needed by dma*/
    uint32_t cnt = (ilen > MBEDTLS_IO_BUF_MAX) ? MBEDTLS_IO_BUF_MAX : ilen;
    if (g_io_read_buf == NULL) {
        g_io_read_buf = (void *)calloc(sizeof(uint64_t), cnt);
        memset(g_io_read_buf, 0, cnt);
    }

    if (!g_io_read_buf) {
        ret = 0;
        goto cleanup;
    }

    if (IOT_ERR_SUCCESS != read_data_from_memory(addr, cnt, g_io_read_buf)) {
        ret = 0;
        goto cleanup;
    }

    *data = g_io_read_buf;
    *size = cnt;
    ret = cnt;
cleanup:

    return ret;
}

/*
 * secboot:
 * Encapsulation of tls interfaces for transplantation.
 */
static int
check_integrity(void *img, unsigned int img_len)
{
    if (g_tls_handle == NULL) {
        return -1;
    }

    return tls_x509_check_integrity(g_tls_handle, img, img_len);
}

static int
get_auth_param(const tls_auth_param_type_desc_t *type_desc,
               void *img, unsigned int img_len,
               void **param, unsigned int *param_len)
{
    if (g_tls_handle == NULL) {
        return -1;
    }

    return tls_x509_get_auth_param(g_tls_handle, type_desc,
                                   img, img_len, param, param_len);
}

static int
verify_signature(void *data_ptr, unsigned int data_len,
                 void *sig_ptr, unsigned int sig_len,
                 void *sig_alg, unsigned int sig_alg_len,
                 void *pk_ptr, unsigned int pk_len)
{
    if (g_tls_handle == NULL) {
        return -1;
    }

    return tls_verify_signature(g_tls_handle, data_ptr, data_len, sig_ptr, sig_len, sig_alg, sig_alg_len,
                                pk_ptr, pk_len);
}

static int
verify_hash(void *data_ptr, unsigned int data_len,
            void *digest_info_ptr, unsigned int digest_info_len)
{
    int ret = 0;

    if (g_tls_handle == NULL) {
        return -1;
    }

	//uart_printf("[%s][%d]\r\n",__func__,__LINE__);
    ret = tls_verify_hash_from_io_dev(g_tls_handle, data_ptr, data_len,
                                      digest_info_ptr, digest_info_len, NULL);
    if (g_io_read_buf != NULL) {
        free(g_io_read_buf);
        g_io_read_buf = NULL;
    }

    return ret;
}

unsigned int
get_my_pk_len(void)
{
    SECBOOT_DBG("[SECBOOT][%s]=%d\r\n", __func__, (int)my_pk_len);
    return my_pk_len;
}
int
secboot_is_fuse_enabled(void)
{
	char *value = asr_property_get("bl1.secureboot");
	if(value && (strncmp("1",value,1)==0)){
		return 1;
	}else{
		return 0;
	}
    //return 1;
}
#endif

//static sb_issue_item_list
static const sb_issue_item_map_t sb_issue_item_list[] = {
	 {ITEM_CP   ,"CP"   ,ASR_OS_CP_KEY_CERT_ID     ,ASR_OS_CP_IMAGE_ID    ,NON_TRUSTED_CP_HASH_OID     }
	,{ITEM_DSP  ,"DSP"  ,ASR_OS_DSP_KEY_CERT_ID    ,ASR_OS_DSP_IMAGE_ID   ,NON_TRUSTED_DSP_HASH_OID    }
	,{ITEM_APP  ,"APP"  ,ASR_OS_APP_KEY_CERT_ID    ,ASR_OS_APP_IMAGE_ID   ,NON_TRUSTED_APP_HASH_OID    }
	,{ITEM_USER1,"USER1",ASR_OS_USER1_KEY_CERT_ID  ,ASR_OS_USER1_IMAGE_ID ,NON_TRUSTED_USER1_HASH_OID  }
	,{ITEM_USER2,"USER2",ASR_OS_USER2_KEY_CERT_ID  ,ASR_OS_USER2_IMAGE_ID ,NON_TRUSTED_USER2_HASH_OID  }
	,{ITEM_USER3,"USER3",ASR_OS_USER3_KEY_CERT_ID  ,ASR_OS_USER3_IMAGE_ID ,NON_TRUSTED_USER3_HASH_OID  }
	,{ITEM_LOGO ,"LOGO" ,ASR_OS_LOGO_KEY_CERT_ID   ,ASR_OS_LOGO_IMAGE_ID  ,NON_TRUSTED_LOGO_HASH_OID   }
	,{ITEM_UPDATER ,"UPDATER" ,ASR_OS_UPDATER_KEY_CERT_ID   ,ASR_OS_UPDATER_IMAGE_ID  ,NON_TRUSTED_UPDATER_HASH_OID   }
};


extern unsigned int Load$$IMG_END$$Base;
#define IMG_END_ADDR ((unsigned int)&(Load$$IMG_END$$Base))


extern unsigned int Image$$SEC_KEY_BUF$$Base;
#define SEC_KEY_ADDR ((unsigned int)&(Image$$SEC_KEY_BUF$$Base))

#define M_HEAP_SIZE 1024*16
static char m_heap[M_HEAP_SIZE]={0};

void secboot_init(const char *pname)
{
	//_rt_heap init
	_init_alloc(m_heap,m_heap+M_HEAP_SIZE);

    if (g_tls_handle == NULL) {
        SECBOOT_DBG("[SECBOOT]tls_init\r\n");
        g_tls_handle = tls_init(calloc, free);
        if (g_tls_handle == NULL) {
            SECBOOT_DBG("[SECBOOT]tls_init fail\r\n");
            goto secboot_fip_error;
        }
    }

	SECBOOT_DBG("[SECBOOT]SEC_KEY_ADDR=[%x]\r\n",SEC_KEY_ADDR);

	//parser the fwcerts.bin setup fip_image_t of image & certification contents
    struct ptentry *fipEntry = ptable_find_entry(pname);
    g_secboot_fh = fip_open((void *)(fipEntry->vstart));
    if (g_secboot_fh == NULL) {
        SECBOOT_DBG("[SECBOOT]fip_open fail\r\n");
        goto secboot_fip_error;
    }

    return 0;

secboot_fip_error:
    SECBOOT_DBG("[SECBOOT][%s]secboot fip open FAILED\r\n", pname);
    /*PMIC_PowerDown(); */
    return 1;
}

void secboot_deinit(void)
{
    if (g_tls_handle) {
        SECBOOT_DBG("[SECBOOT]secboot_deinit\r\n");
        tls_deinit(g_tls_handle);
		g_tls_handle = NULL;
    }

    return;
}


void secboot_item_get_img_addr_size(sb_issue_item_id_t item_id_idx,fip_image_handle item_fih)
{
    int rc = 0;
    uint32_t start = 0, offset = 0, size = 0;

	SECBOOT_DBG("[SECBOOT][%s][%d] \r\n",__func__,item_id_idx);

	//parse the sb_issue_item
	sb_issue_item_map_t * m_sb_item_ptr = sb_issue_item_list;
	do{
		if(m_sb_item_ptr->item_id >= ITEM_END)
			goto secboot_error_mark;
		if(m_sb_item_ptr->item_id == item_id_idx)
			break;

		m_sb_item_ptr++;
	}while(1);
	
    rc = fip_get_image_info(g_secboot_fh, m_sb_item_ptr->item_img_id, &start, &offset, &size);
	if (rc != FIP_SUCCEED){
		goto secboot_error_mark;
	}

    item_fih->id = m_sb_item_ptr->item_img_id;
    item_fih->start = start;
    item_fih->offset = offset;
    item_fih->size = size;
    item_fih->read = g_secboot_fh->read;
#if 0
	SECBOOT_DBG("[SECBOOT]item_fih->id        = [0x%0.8x]\r\n",item_fih->id);
	SECBOOT_DBG("[SECBOOT]item_fih->start     = [0x%0.8x]\r\n",item_fih->start);
	SECBOOT_DBG("[SECBOOT]item_fih->offset    = [0x%0.8x]\r\n",item_fih->offset);
	SECBOOT_DBG("[SECBOOT]item_fih->size      = [0x%0.8x]\r\n",item_fih->size);
#endif
	return;

secboot_error_mark:
	SECBOOT_DBG("[SECBOOT][%s][%s]FAILED\r\n",m_sb_item_ptr->item_name,__func__);
	PMIC_SW_RESET();
	return;
}

/*
 * secboot:
 * emmc need alloc new memory to store the cert, xip device read it address directly.
 *
 */
uint32_t
secboot_read_cert(uint32_t addr, uint32_t size)
{
    /*buffer aligned with 8 byte needed by dma read*/
    uint8_t *p_cert = (uint8_t *)calloc(sizeof(uint64_t), size);

    memset(p_cert, 0, size);
    if (read_data_from_memory(addr, size, p_cert) != IOT_ERR_SUCCESS) {
        free((void *)p_cert);
        return 0;
    }
    else {
        return (uint32_t)p_cert;
    }
}

void
secboot_free_cert(uint32_t cert_addr)
{
    free((void *)cert_addr);
}

/*
 * secboot_item_check:
 * verify signature of certificate and verify image by hash from certificate.
 *
 * input:
 * item_id_idx: index of image item
 *
 */
void secboot_item_check(sb_issue_item_id_t item_id_idx)
{
    unsigned long startTime,endTime;
	int rc = 0;
    uint32_t start = 0, offset = 0, size = 0;
    startTime = GetTimer0CNT(); 
    uint32_t cert_addr = 0;
	SECBOOT_DBG("[SECBOOT]sb_item item_id = [%d] check\r\n",item_id_idx);

	//parse the sb_issue_item
	sb_issue_item_map_t * m_sb_item_ptr = sb_issue_item_list;
	do{
		if(m_sb_item_ptr->item_id >= ITEM_END){
			SECBOOT_DBG("[SECBOOT]sb_item [%d][%d][%d] index error \r\n",
					item_id_idx,m_sb_item_ptr->item_id,ITEM_END);
            goto secboot_error;
		}
		if(m_sb_item_ptr->item_id == item_id_idx){
			//bingo
			SECBOOT_DBG("[SECBOOT]sb_item [%d][%s][%d][%d][%s]\r\n",
					m_sb_item_ptr->item_id,
					m_sb_item_ptr->item_name,
					m_sb_item_ptr->item_cert_id,
					m_sb_item_ptr->item_img_id,
					m_sb_item_ptr->item_hash_oid
					);
			break;
		}

		m_sb_item_ptr++;
	}while(1);
	
	//certification fip image parser setup
	fip_image_t cert_toc_fip;
	fip_image_handle cert_toc_fih = &cert_toc_fip;
    rc = fip_get_image_info(g_secboot_fh, m_sb_item_ptr->item_cert_id, &start, &offset, &size);
    if (rc == FIP_ERR_IMG_MISS) {
        SECBOOT_DBG("[SECBOOT]fip_get_image_info [%d] with FIP_ERR_IMG_MISS, just skip", m_sb_item_ptr->item_cert_id);
        return;
	}else if (rc != FIP_SUCCEED){
		goto secboot_error;
	}

    cert_toc_fih->id = m_sb_item_ptr->item_img_id;
    cert_toc_fih->start = (uint32_t)start;
    cert_toc_fih->offset = (uint32_t)offset;
    cert_toc_fih->size = (uint32_t)size;
    cert_toc_fih->read = g_secboot_fh->read;
	//image fip image parser setup
	fip_image_t img_toc_fip;
	fip_image_handle img_toc_fih = &img_toc_fip;

    rc = fip_get_image_info(g_secboot_fh, m_sb_item_ptr->item_img_id, &start, &offset, &size);
    if (rc != FIP_SUCCEED) {
        goto secboot_error;
    }
	
    img_toc_fip.id = m_sb_item_ptr->item_img_id;
    img_toc_fip.start = (uint32_t)start;
    img_toc_fip.offset = (uint32_t)offset;
    img_toc_fip.size = (uint32_t)size;
    img_toc_fip.read = g_secboot_fh->read;
    cert_addr = secboot_read_cert((cert_toc_fih->start + cert_toc_fih->offset), cert_toc_fih->size);
    if (cert_addr == 0) {
        goto secboot_error;
    }
	
#if 0
	SECBOOT_DBG("[SECBOOT]cert_toc_fih->id       = [0x%0.8x]\r\n",cert_toc_fih->id);
	SECBOOT_DBG("[SECBOOT]cert_toc_fih->start    = [0x%0.8x]\r\n",cert_toc_fih->start);
	SECBOOT_DBG("[SECBOOT]cert_toc_fih->offset   = [0x%0.8x]\r\n",cert_toc_fih->offset);
	SECBOOT_DBG("[SECBOOT]cert_toc_fih->size     = [0x%0.8x]\r\n",cert_toc_fih->size);
	SECBOOT_DBG("[SECBOOT]img_toc_fih->id        = [0x%0.8x]\r\n",img_toc_fih->id);
	SECBOOT_DBG("[SECBOOT]img_toc_fih->start     = [0x%0.8x]\r\n",img_toc_fih->start);
	SECBOOT_DBG("[SECBOOT]img_toc_fih->offset    = [0x%0.8x]\r\n",img_toc_fih->offset);
	SECBOOT_DBG("[SECBOOT]img_toc_fih->size      = [0x%0.8x]\r\n",img_toc_fih->size);
#endif

	//STEP2
	//check integrity of the certification content
	SECBOOT_DBG("[SECBOOT][%s]cert check_integrity start\r\n",m_sb_item_ptr->item_name);
    rc = check_integrity((void *)cert_addr,
                         cert_toc_fih->size);

	SECBOOT_DBG("[SECBOOT][%s]cert check_integrity done rc = %d\r\n",m_sb_item_ptr->item_name,rc);
	if(rc)
		goto secboot_error;


	//STEP3
    /*verify signature */
    tls_auth_param_type_desc_t sig_param_desc = { AROM_TLS_AUTH_PARAM_SIG, 0 };
    char *sig_ptr;
    unsigned int sig_len;
    get_auth_param(&sig_param_desc, NULL, 0, (void **)&sig_ptr, &sig_len);

#if 0
	SECBOOT_DBG("[SECBOOT]DUMP SIG\r\n");
	display_binary(sig_ptr,sig_len);
#endif

    tls_auth_param_type_desc_t sig_alg_param_desc = { AROM_TLS_AUTH_PARAM_SIG_ALG, 0 };
    char *sig_alg_ptr;
    unsigned int sig_alg_len;
    get_auth_param(&sig_alg_param_desc, NULL, 0, (void **)&sig_alg_ptr, &sig_alg_len);

#if 0
	SECBOOT_DBG("[SECBOOT]DUMP SIG_ALG\r\n");
	display_binary(sig_alg_ptr,sig_alg_len);
#endif

    tls_auth_param_type_desc_t pk_param_desc = { AROM_TLS_AUTH_PARAM_PUB_KEY, 0 };
    char *pk_ptr;
    unsigned int pk_len;
    get_auth_param(&pk_param_desc, NULL, 0, (void **)&pk_ptr, &pk_len);

	//20201204. for fwcert auth workaround
	if(memcmp(pk_ptr,SEC_KEY_ADDR,pk_len) != 0)
	{
		SECBOOT_DBG("[SECBOOT]PK UNMATCH \r\n");
        my_pk_len = pk_len;
		goto secboot_error;
	}
    else {
        /*for PK passby to updater to append */
        SECBOOT_DBG("[SECBOOT]PK MATCH!pk_len=%d\r\n", pk_len);
        my_pk_len = pk_len;
    }

    tls_auth_param_type_desc_t tbs_param_desc = { AROM_TLS_AUTH_PARAM_RAW_DATA, 0 };
    char *tbs_ptr;
    unsigned int tbs_len;
    get_auth_param(&tbs_param_desc, NULL, 0, (void **)&tbs_ptr, &tbs_len);
#if 0
	SECBOOT_DBG("[SECBOOT]DUMP TBS\r\n");
	display_binary(tbs_ptr,tbs_len);
#endif


	rc = verify_signature((void*)tbs_ptr,tbs_len,
			sig_ptr,sig_len,
			sig_alg_ptr,sig_alg_len,
			pk_ptr,pk_len
			);
    if (rc) {
        SECBOOT_DBG("[SECBOOT] verify_signature failed with rc=[%d]\r\n", rc);
        goto secboot_error;
    }

	//STEP4
	//verify image
    tls_auth_param_type_desc_t img_auth_param_desc = { AROM_TLS_AUTH_PARAM_HASH, (void *)m_sb_item_ptr->item_hash_oid };
    char *img_hash_ptr;
    unsigned int img_hash_len;
    get_auth_param(&img_auth_param_desc, NULL, 0, (void **)&img_hash_ptr, &img_hash_len);

#if 0
	SECBOOT_DBG("[SECBOOT]DUMP EXT hash_oid[]\r\n");
	display_binary(img_hash_ptr,img_hash_len);
#endif


	SECBOOT_DBG("[SECBOOT][%s]img_content verify_hash start\r\n",m_sb_item_ptr->item_name);
	rc = verify_hash((void*)(img_toc_fih->start+img_toc_fih->offset),img_toc_fih->size,
			img_hash_ptr,img_hash_len);
	SECBOOT_DBG("[SECBOOT][%s]img_content verify_hash done rc = %d\r\n",m_sb_item_ptr->item_name,rc);
	if(rc)
		goto secboot_error;

    endTime = GetTimer0CNT(); 
	SECBOOT_DBG("[SECBOOT][%s]secboot check done SUCCEED\r\n",m_sb_item_ptr->item_name);
	SECBOOT_DBG("[SECBOOT][%s]secboot time consumption = %ld ms\r\n",
			m_sb_item_ptr->item_name,Timer0IntervalInMilli(startTime,endTime));

    if (cert_addr != 0) {
        secboot_free_cert(cert_addr);
    }

	return;

secboot_error:
    if (cert_addr != 0) {
        secboot_free_cert(cert_addr);
    }
    endTime = GetTimer0CNT(); 
	SECBOOT_DBG("[SECBOOT][%s]secboot check done FAILED\r\n",m_sb_item_ptr->item_name);
	SECBOOT_DBG("[SECBOOT][%s]secboot time consumption = %ld ms\r\n",
			m_sb_item_ptr->item_name,Timer0IntervalInMilli(startTime,endTime));
	PMIC_SW_RESET();
	return;
}

/*
 * secboot_get_signature:
 * get signature from fip content
 *
 * input:
 * item_id_idx: index of image item corresponding to the signature.
 * psig_ptr: pointer to signature content pointer,
 * the signature memory allocated in this function and should be relased after used.
 * psig_len: pointer to store signature length.
 *
 * return:
 * if success return 0, else return -1
 */
static int
secboot_get_signature(sb_issue_item_id_t item_id_idx, char **psig_ptr, uint32_t *psig_len)
{
    int rc = 0;
    uint32_t start = 0, offset = 0, size = 0;
    const sb_issue_item_map_t *m_sb_item_ptr = sb_issue_item_list;
    uint32_t cert_addr = 0;

    if (item_id_idx > ITEM_END) {
        return -1;
    }

    if (psig_ptr == NULL) {
        return -1;
    }

    if (psig_len == NULL) {
        return -1;
    }

    /*find sb_issue_item by item_id */
    do {
        if (m_sb_item_ptr->item_id >= ITEM_END) {
            SECBOOT_DBG("[SECBOOT]sb_item [%d][%d][%d] index error ",
                        item_id_idx, m_sb_item_ptr->item_id, ITEM_END);
            goto error;
        }

        if (m_sb_item_ptr->item_id == item_id_idx) {
            /*bingo */
            SECBOOT_DBG("[SECBOOT]sb_item [%d][%s][%d][%d][%s]",
                        m_sb_item_ptr->item_id,
                        m_sb_item_ptr->item_name,
                        m_sb_item_ptr->item_cert_id,
                        m_sb_item_ptr->item_img_id,
                        m_sb_item_ptr->item_hash_oid);
            break;
        }

        m_sb_item_ptr++;
    } while (1);

    /*read cert from fip */
    static fip_image_t cert_toc_fip;
    static fip_image_handle cert_toc_fih = &cert_toc_fip;
    rc = fip_get_image_info(g_secboot_fh, m_sb_item_ptr->item_cert_id, &start, &offset, &size);
    if (rc == FIP_ERR_IMG_MISS) {
        SECBOOT_DBG("[SECBOOT]fip_get_image_info [%d] with FIP_ERR_IMG_MISS, just skip", m_sb_item_ptr->item_cert_id);
        return rc;
    }
    else if (rc != FIP_SUCCEED) {
        goto error;
    }

    cert_toc_fih->id = m_sb_item_ptr->item_img_id;
    cert_toc_fih->start = (uint32_t)start; /*not use */
    cert_toc_fih->offset = (uint32_t)offset;
    cert_toc_fih->size = (uint32_t)size;
    cert_toc_fih->read = g_secboot_fh->read;

    cert_addr = secboot_read_cert((cert_toc_fih->start + cert_toc_fih->offset), cert_toc_fih->size);
    if (cert_addr == 0) {
        goto error;
    }

    /*parse certification content */
    rc = check_integrity((void *)(cert_addr), cert_toc_fih->size);
    if (rc) {
        goto error;
    }

    /*get signature */
    tls_auth_param_type_desc_t sig_param_desc = { AROM_TLS_AUTH_PARAM_SIG, 0 };
    char *sig_ptr;
    unsigned int sig_len;
    get_auth_param(&sig_param_desc, NULL, 0, (void **)&sig_ptr, &sig_len); /*get sig_ptr */

    *psig_len = sig_len;
    *psig_ptr = calloc(1, sig_len);
    if (*psig_ptr == NULL) {
        goto error;
    }

    memcpy(*psig_ptr, sig_ptr, sig_len);

    if (cert_addr != 0) {
        secboot_free_cert(cert_addr);
    }

    return rc;

error:

    if (cert_addr != 0) {
        secboot_free_cert(cert_addr);
    }
    return -1;
}
