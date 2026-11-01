//#include <assert.h>
#include "fip.h"
//#include <fip_flash.h>
//#include "log.h"
#include <stdlib.h>
#include <string.h>
#include "tbbr_img_def.h"
#include "utils_def.h"
#include "ptable.h"

#define MAX_TOC_ENTRY_COUNT 12
fip_toc_entry_t m_fip_toc_entry_list[MAX_TOC_ENTRY_COUNT];
fip_info_t m_fip;

/* By default, ARM platforms load images from the FIP */
static const uuid_map_t image_uuid[] = {
#if 0
    { BL2_IMAGE_ID, UUID_TRUSTED_BOOT_FIRMWARE_BL2 },
    { SCP_BL2_IMAGE_ID, UUID_SCP_FIRMWARE_SCP_BL2 },
    { BL31_IMAGE_ID, UUID_EL3_RUNTIME_FIRMWARE_BL31 },
    { BL32_IMAGE_ID, UUID_SECURE_PAYLOAD_BL32 },
    { BL33_IMAGE_ID, UUID_NON_TRUSTED_FIRMWARE_BL33 },
    { TRUSTED_BOOT_FW_CERT_ID, UUID_TRUSTED_BOOT_FW_CERT },
    { TRUSTED_KEY_CERT_ID, UUID_TRUSTED_KEY_CERT },
    { SCP_FW_KEY_CERT_ID, UUID_SCP_FW_KEY_CERT },
    { SOC_FW_KEY_CERT_ID, UUID_SOC_FW_KEY_CERT },
    { TRUSTED_OS_FW_KEY_CERT_ID, UUID_TRUSTED_OS_FW_KEY_CERT },
    { NON_TRUSTED_FW_KEY_CERT_ID, UUID_NON_TRUSTED_FW_KEY_CERT },
    { SCP_FW_CONTENT_CERT_ID, UUID_SCP_FW_CONTENT_CERT },
    { SOC_FW_CONTENT_CERT_ID, UUID_SOC_FW_CONTENT_CERT },
    { TRUSTED_OS_FW_CONTENT_CERT_ID, UUID_TRUSTED_OS_FW_CONTENT_CERT },
    { NON_TRUSTED_FW_CONTENT_CERT_ID, UUID_NON_TRUSTED_FW_CONTENT_CERT },
    { BL32_EXTRA1_IMAGE_ID, UUID_SECURE_PAYLOAD_BL32_EXTRA1 },
    { BL32_EXTRA2_IMAGE_ID, UUID_SECURE_PAYLOAD_BL32_EXTRA2 },
#endif
    { ASR_OS_CP_IMAGE_ID, UUID_NON_TRUSTED_OS_CP },
    { ASR_OS_CP_KEY_CERT_ID, UUID_NON_TRUSTED_CP_CONTENT_CERT },
    { ASR_OS_DSP_IMAGE_ID, UUID_NON_TRUSTED_OS_DSP },
    { ASR_OS_DSP_KEY_CERT_ID, UUID_NON_TRUSTED_DSP_CONTENT_CERT },
    { ASR_OS_APP_IMAGE_ID, UUID_NON_TRUSTED_OS_APP },
    { ASR_OS_APP_KEY_CERT_ID, UUID_NON_TRUSTED_APP_CONTENT_CERT },
    { ASR_OS_USER1_IMAGE_ID, UUID_NON_TRUSTED_OS_USER1 },
    { ASR_OS_USER1_KEY_CERT_ID, UUID_NON_TRUSTED_USER1_CONTENT_CERT },
    { ASR_OS_USER2_IMAGE_ID, UUID_NON_TRUSTED_OS_USER2 },
    { ASR_OS_USER2_KEY_CERT_ID, UUID_NON_TRUSTED_USER2_CONTENT_CERT },
    { ASR_OS_USER3_IMAGE_ID, UUID_NON_TRUSTED_OS_USER3 },
    { ASR_OS_USER3_KEY_CERT_ID, UUID_NON_TRUSTED_USER3_CONTENT_CERT },
    { ASR_OS_LOGO_IMAGE_ID, UUID_NON_TRUSTED_OS_LOGO },
    { ASR_OS_LOGO_KEY_CERT_ID, UUID_NON_TRUSTED_LOGO_CONTENT_CERT },
    { ASR_OS_UPDATER_IMAGE_ID, UUID_NON_TRUSTED_OS_UPDATER },
    { ASR_OS_UPDATER_KEY_CERT_ID, UUID_NON_TRUSTED_UPDATER_CONTENT_CERT },
};

static const uuid_t uuid_null = {{0}, {0}, {0}, 0, 0, {0, 0, 0, 0, 0, 0}};

extern int uart_printf(const char *fmt, ...);

#define LOG_ERR(fmt, ...) uart_printf(fmt, ## __VA_ARGS__)

static inline int compare_uuids(const uuid_t *uuid1, const uuid_t *uuid2)
{
    return memcmp(uuid1, uuid2, sizeof(uuid_t));
}

uint32_t read_data_from_memory(uint32_t from, uint32_t size, uint8_t *to)
{
    uint8_t *start = (uint8_t *)from;

    if (start + size < to || to + size < start) {
        memcpy(to, start, size);
    }
    else if (to != start) {
        memmove(to, start, size);
    }
    return IOT_ERR_SUCCESS;
}

static uint32_t fip_read_data(uint32_t from, uint32_t size, uint8_t *to)
{
   return read_data_from_memory(from, size, to);
}

/*
 * See if a Firmware Image Package is available,
 * by checking if TOC is valid or not.
 */
int is_valid_fip(void *address)
{
    fip_toc_header_t header;

    read_data_from_memory((uint32_t)(uintptr_t)address, sizeof(header), (uint8_t *)&header);

    return header.name == TOC_HEADER_NAME;
}

int fip_get_plat_flag(void *address, uint16_t *flag)
{
    fip_toc_header_t header;

    read_data_from_memory((uint32_t)(uintptr_t)address, sizeof(header), (uint8_t *)&header);

    if (header.name == TOC_HEADER_NAME) {
        *flag = (header.flags >> 32) & 0xFFFF;
        return 0;
    }
    else {
        LOG_ERR("Not a valid FIP");
        return -1;
    }
}


//==============================================
//DESC:
//	initial the static m_fip ,for FIP parse ToC struct
//
//PARAM:
//	address	- the address of fwcert.bin
//
//RETURN:
// fip_handle
//==============================================

fip_handle fip_open(void *address)
{
    fip_handle fh = calloc(1, sizeof(*fh));

    if (!fh) {
        LOG_ERR("Out of memory!");
        return NULL;
    }

    fh->read = fip_read_data;
    fh->address = (uint32_t)(uintptr_t)address;

    if (fh->read(fh->address, sizeof(fh->toc), (uint8_t *)&fh->toc) != IOT_ERR_SUCCESS) {
        LOG_ERR("Read fail!");
        free(fh);
        return NULL;
    }

#if 0
	LOG_ERR("[SECBOOT]fh->address          = [0x%0.8x]\r\n",fh->address);
	LOG_ERR("[SECBOOT]fh->toc.name         = [0x%0.8x]\r\n",fh->toc.name);
	LOG_ERR("[SECBOOT]fh->toc.serial_number= [0x%0.8x]\r\n",fh->toc.serial_number);
	LOG_ERR("[SECBOOT]fh->toc.flags        = [0x%0.8x]\r\n",fh->toc.flags);
#endif

    if (fh->toc.name != TOC_HEADER_NAME) {
        LOG_ERR("fh->address:[%08x] fh->toc:[%08x]", ((uint32_t *)(fh->address))[0], fh->toc.name);
        LOG_ERR("Not a fip!");
        free(fh);
        return NULL;
    }

    fip_toc_entry_t entry;
    uint32_t entry_address = fh->address + sizeof(fh->toc);

//      PARSER THE FIP STRUCT
//
//      ----------------- 
//      | ToC Header     |
//      |----------------|
//      | ToC Entry 0    |
//      |----------------|
//      | ToC Entry 1    |
//      |----------------|
//      | ToC End Marker |
//      |----------------|
//      | Data 0         |
//      |----------------|
//      | Data 1         |
//      |----------------|
//
 
	do {
        if (fh->read(entry_address, sizeof(entry), (uint8_t *)&entry) != IOT_ERR_SUCCESS) {
            LOG_ERR("Read fail!");
            free(fh);
            return NULL;
        }

        entry_address += sizeof(entry);
		if(!compare_uuids(&entry.uuid, &uuid_null) || fh->entry_count >= MAX_TOC_ENTRY_COUNT)
			break;

#if 0
	LOG_ERR("[SECBOOT]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n");
	LOG_ERR("[SECBOOT]entry.num              = [0x%0.8x]\r\n",fh->entry_count);
	LOG_ERR("[SECBOOT]entry.start            = [0x%0.8x]\r\n",(uint32_t)fh->address);
	LOG_ERR("[SECBOOT]entry.offset_address   = [0x%0.8x]\r\n",(uint32_t)entry.offset_address);
	LOG_ERR("[SECBOOT]entry.size             = [0x%0.8x]\r\n",(uint32_t)entry.size);
#endif


        fh->entry_count++;
    } while (1);

	LOG_ERR("[SECBOOT]fh->entry_count = [%d]\r\n",fh->entry_count);

    fh->entry = calloc(1, fh->entry_count * sizeof(*fh->entry));
    if (!fh->entry) {
        LOG_ERR("Out of memory");
        free(fh);
        return NULL;
    }

    entry_address = fh->address + sizeof(fh->toc);
    if (fh->read(entry_address, fh->entry_count * sizeof(entry), (uint8_t *)fh->entry) != IOT_ERR_SUCCESS) {
        LOG_ERR("Read fail!");
        free(fh->entry);
        free(fh);
        return NULL;
    }

    return fh;
}

int fip_close(fip_handle fh)
{
    if (fh) {
        free(fh->entry);
        free(fh);
    }

    return 0;
}

static int find_uuid_by_id(unsigned int image_id)
{
	int i;
    for (i = 0; i < (int)ARRAY_SIZE(image_uuid); i++) {
        if (image_uuid[i].id == image_id) {
            return i;
        }
    }

    LOG_ERR("Can't find uuid by id %d", image_id);
    return -1;
}

int fip_get_image_info_by_uuid(fip_handle fh, const uuid_t *puuid, unsigned int image_id, uint32_t *pstart, uint32_t *poffset, uint32_t *psize)
{
    int index = 0;

    if (!fh) {
        LOG_ERR("Fip handle is empty");
        return -1;
    }

    if (!fh->entry_count) {
        LOG_ERR("Fip has no any images!");
        return -1;
    }

    if (puuid == NULL) {
        index = find_uuid_by_id(image_id);
        if (index < 0) {
            return -1;
        }

        puuid = &image_uuid[index].uuid;
    }

    int entry_index = -1;
	int i;
    for (i = 0; i < fh->entry_count; i++) {
        if (!compare_uuids(&fh->entry[i].uuid, puuid)) {
            entry_index = i;
            break;
        }
    }

    if (entry_index < 0) {
        LOG_ERR("Fip doesn't contain image(id=%u)", image_id);
        return -1;
    }

    if (pstart) {
        *pstart = fh->address;
    }

    if (poffset) {
        *poffset = fh->entry[entry_index].offset_address;
    }

    if (psize) {
        *psize = fh->entry[entry_index].size;
    }

    return 0;
}

int fip_get_image_info(fip_handle fh, unsigned int image_id, uint32_t *pstart, uint32_t *poffset, uint32_t *psize)
{
    return fip_get_image_info_by_uuid(fh, NULL, image_id, pstart, poffset, psize);
}

int fip_close_image(fip_image_handle fih)
{
    free(fih);
    return 0;
}

int32_t fip_read_image(fip_image_handle fih, uint8_t *data, uint32_t size)
{
    if (!fih) {
        LOG_ERR("Can't read empty fip img");
        return 0;
    }

    if (!data) {
        LOG_ERR("Can't store to empty buffer");
        return 0;
    }

    uint32_t real_size = MIN(size, fih->size);

    if (!real_size) {
        return 0;
    }

    int32_t ret = fih->read(fih->start + fih->offset, real_size, data);

    if (ret < 0) {
        LOG_ERR("Read fail!");
    }

    return ret;
}
