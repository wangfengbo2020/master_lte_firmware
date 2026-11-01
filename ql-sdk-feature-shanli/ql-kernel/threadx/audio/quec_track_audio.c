/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file	quec_track_audio.c
 * @author	pony.ma
 * @version V1.0.0
 * @date	2022/06/19
 * @brief	audio interface driver header file
 ******************************************************************************
 */

#include "quec_cust_feature.h"
#if QUEC_AUDIO_SUPPORT
#include <osa.h> 
#include "quec_audio.h"
#include "audio_bind.h"
#include "nvm_header.h"
#include "quec_track_audio.h"
#include "acm_calibration.h"
#include "audio_file.h"
#include "audio_file.h"

#ifdef QUECTEL_OPEN_CPU
#include "ql_fs.h"
#define QUEC_OPEN  1

ACM_Configuration 		 g_EarConfigTable = {0x18,1,0,{"Audio Configuration"}};
//Configure   Always_Print_PCM	  Disable_All_Modules

extern ACMCodec_GainT 			*g_pGainParamsTable;
extern unsigned short 			g_GainParamsCount;
extern ACM_Configuration 		g_AudioConfigTable;
extern ACMDSP_VEParametersT 	*g_pVEParamsTable;
extern ACMCP_MediaVEarametersT *g_pMediaVEParamsTable;
extern unsigned short 			g_MediaVEParamsCount;
extern unsigned short 			g_VEParamsCount;

extern ACMCodec_GainT 	*f_pGainParamsTable;
extern ACMDSP_VEParametersT 	*f_pVEParamsTable;
extern ACM_Configuration 		 f_AudioConfigTable;
ACMCP_MediaVEarametersT	*f_pMediaVEParamsTable  = NULL;


#define AUDIO_VE_NVM1_NAME 		"U:/audio_ve.nvm"
#define AUDIO_GAIN_NVM1_NAME 	"U:/audio_gain.nvm"
#define AUDIO_MEDIA_VE_NVM1_NAME 	"U:/audio_mediaVE.nvm"
#define MSA_AUDIO_VERSION1 		"MarvellModem_0001"
#define SINGLE_NVM_VERSION1 	"MarvellModem_Crane"

#define NEED_USE_OWEN_FS     do{if(!fops_inited){quec_register_audio_fops(&file_ops);fops_inited++;}}while(0);
#define quec_audio_log(format,...)  quec_log("[quau]%s:"format, __func__, ##__VA_ARGS__);
#define DTMF_VOLUME_MAX  (16)
#define DTMF_VOLUME_MIN  (-36)

#ifdef QL_NAND_YAFFS
struct l_list {
	unsigned int fp; 
	unsigned int fs_type;//1:nor flash;2:nand flash
	struct l_list *next;
};
static struct l_list Linklist;

static void list_insert(struct l_list *p)
{
	struct l_list *q = &Linklist;
	for(;q->next;) {
		q = q->next;
	}
	q->next = p;
	p->next = NULL;
}

static unsigned int list_check(unsigned int fp)
{
	struct l_list *q = &Linklist;
	struct l_list *p = NULL;
	while(q)
	{
		if(q->fp == fp){
			return q->fs_type;
		}else{
			q = q->next;
		}
	}
	return 0;
}

static unsigned int list_delet(unsigned int fp)
{
	struct l_list *q = &Linklist;
	struct l_list *p = NULL;
	p = q;
	while(q)
	{
		if(q->fp == fp){
			p->next = q->next;
			free(q);
			q = NULL;
			return q->fs_type;
		}else{
			p = q;
			q = q->next;
		}
	}
	return 0;
}

unsigned int quec_audio_fopen(const char *fname, const char *mode)
{
	struct l_list *fs_info = NULL;
	fs_info = (struct l_list *)malloc(sizeof(struct l_list));
	if(QUEC_OPEN == 1)
	{
		if(memcmp("N:/", fname, 3) && memcmp("n:/", fname, 3)){
			fs_info->fp = (unsigned int)(ql_fopen(fname, (const char * )mode));
			fs_info->fs_type = 1;
		}else{
			fs_info->fp = (unsigned int)(ql_nand_fopen((const char *)(fname+3), (const char * )mode));
			fs_info->fs_type = 2;
		}
	}
	list_insert(fs_info);
    return fs_info->fp;
}

int quec_audio_fclose(unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		if(list_check(fp) == 1){
			list_delet(fp);
			return ql_fclose((QFILE *)fp);
		}else if(list_check(fp) == 2){
			list_delet(fp);
			return ql_nand_fclose((File_Handle)fp);
		}
	}
	return 0;
}

size_t quec_audio_fread(void * buffer, size_t size, size_t num, unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		if(list_check(fp) == 1){
			return ql_fread(buffer, size, num, (QFILE *)fp);
		}else if(list_check(fp) == 2){
			return ql_nand_fread(buffer, size, num, (File_Handle)fp);
		}
	}
	return 0;
}

size_t quec_audio_fwrite(const void * buffer, size_t size, size_t num, unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		if(list_check(fp) == 1){
			return ql_fwrite((void*)buffer, size, num, (QFILE *)fp);
		}else if(list_check(fp) == 2){
			return ql_nand_fwrite((void*)buffer, size, num, (File_Handle)fp);
		}
	}
	return 0;
}

int quec_audio_fseek(unsigned int fp, long offset, int whence)
{
    int ret = -1;
    int ret1 = -1;
	if(QUEC_OPEN == 1)
	{
		if(list_check(fp) == 1){
			ret1=ql_fseek((QFILE *)fp, offset, whence);
		}else if(list_check(fp) == 2){
			ret1=ql_nand_fseek((File_Handle)fp, offset, whence);
		}
        if(ret1>=0)
            ret=0;
        else
            ret=ret1;
	}
    return ret;
}

bool quec_audio_file_exist(const char *file_name)
{
    bool ret;
	if(QUEC_OPEN == 1)
	{
		if(memcmp("N:/", file_name, 3) && memcmp("n:/", file_name, 3)){
			if(ql_access(file_name, 0)<0)
	         ret=0;
	        else
	         ret=1;
		}else{
			ret = ql_nand_access((char *)(file_name+3));
		}
	}
    return ret;
}
#else
unsigned int quec_audio_fopen(const char *fname, const char *mode)
{
	int i = 0;
    unsigned int fp = 0;
	if(QUEC_OPEN == 1)
	{
		fp = (unsigned int)(ql_fopen(fname, (const char * )mode));
	}
    return fp;
}

int quec_audio_fclose(unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		return ql_fclose((QFILE *)fp);
	}
}

size_t quec_audio_fread(void * buffer, size_t size, size_t num, unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		return ql_fread(buffer, size, num, (QFILE *)fp);
	}
}

size_t quec_audio_fwrite(const void * buffer, size_t size, size_t num, unsigned int fp)
{
	if(QUEC_OPEN == 1)
	{
		return ql_fwrite((void*)buffer, size, num, (QFILE *)fp);
	}
}

int quec_audio_fseek(unsigned int fp, long offset, int whence)
{
    int ret = -1;
    int ret1 = -1;
	if(QUEC_OPEN == 1)
	{
		ret1=ql_fseek((QFILE *)fp, offset, whence);
        if(ret1>=0)
            ret=0;
        else
            ret=ret1;
	}
    return ret;
}

bool quec_audio_file_exist(const char *file_name)
{
    bool ret;
	if(QUEC_OPEN == 1)
	{
		if(ql_access(file_name, 0)<0)
         ret=0;
        else
         ret=1;
	}
    return ret;
}
#endif
static audio_file_ops_t file_ops = {
    .open = quec_audio_fopen,
    .close = quec_audio_fclose,
    .seek = quec_audio_fseek,
    .read = quec_audio_fread,
    .write = quec_audio_fwrite,
    .access = quec_audio_file_exist,
};
char fops_inited =0;
void quec_register_audio_fops(audio_file_ops_t* argv)
{
   register_audio_fops(argv);
}

// layer I
static const int kBitrateV1[] = {
	32, 64, 96, 128, 160, 192, 224, 256,
	288, 320, 352, 384, 416, 448
};
	
static const int kBitrateV2[] = {
	32, 48, 56, 64, 80, 96, 112, 128,
	144, 160, 176, 192, 224, 256
};


// layer II or III
static const int kBitrateV1L2[] = {
	32, 48, 56, 64, 80, 96, 112, 128,
	160, 192, 224, 256, 320, 384
};

static const int kBitrateV1L3[] = {
	32, 40, 48, 56, 64, 80, 96, 112,
	128, 160, 192, 224, 256, 320
};

static const int kBitrateV3[] = {
	8, 16, 24, 32, 40, 48, 56, 64,
	80, 96, 112, 128, 144, 160
};

static BOOL is_support_samplerate(unsigned int rate)
{
	switch(rate) {
		case 8000:
		case 11025:
		case 12000:
		case 16000:
		case 22050:
		case 24000:
		case 32000:
		case 44100:
		case 48000:
			return true;
	}
	return false;
}

static int g_audio_volume = 5;
void quec_set_volume(char vol)
{
	quec_debug_print_uart("quec_set_volume vol:%d\n", vol);
	if(vol >= 12)
	{
		vol = 11;
	}
	g_audio_volume = vol;
	AudioHAL_AifSetVolume(vol);
}

int quec_get_volume(void)
{
	return g_audio_volume;
}

int quec_get_audio_state()
{
	int ret;
	ret = isIPCControlInit();
	//quec_debug_print_uart("audio_state, status: %d\n", status);	

	return ret;//1-true;0-false
}

//20200708 august.yang add set dtmp volume
extern void ACMAudioSetDTMFVolume(int v);
void quec_set_dtmf_volume(int vo)
{
    int dtmf_vol=0;
	if(vo < 0 || vo >10){
		quec_debug_print_uart("volume level error \n");
		return;
	}
    if(vo==0)
    {
        dtmf_vol = DTMF_VOLUME_MIN;
    }
    else if(vo==10)
    {
        dtmf_vol = DTMF_VOLUME_MAX;
    }
    else
    {
        dtmf_vol = DTMF_VOLUME_MIN + ((DTMF_VOLUME_MAX-DTMF_VOLUME_MIN)/10)*vo;
    }
    //quec_debug_print_uart("dtmf_vol %d \n",dtmf_vol);
	ACMAudioSetDTMFVolume(dtmf_vol);
}

#define SET_STRING(buf, str) strcpy((buf), (str))
void quec_codec_choose(codec_choose_state codec_choose, quec_codecpcm_config* pcm_config)
{
	if(codec_choose == QUEC_AUD_INTERNAL_CODEC)
	{
		AudioHAL_AifUseInternalCodec();
	}else if(codec_choose == QUEC_AUD_EXTERNAL_CODEC){
		if(pcm_config != NULL){
			AudioHAL_sspaSetBCLKType(pcm_config->pcmbclk);
			switch(pcm_config->sample)
			{
				case QUEC_PCM_CODEC_SAMPLE_8000:
					AudioHAL_AifUseSSPA_NB();
					break;
				case QUEC_PCM_CODEC_SAMPLE_16000:
					AudioHAL_AifUseSSPA();
					break;
				case QUEC_PCM_CODEC_SAMPLE_32000:
					AudioHAL_AifUseSSPA_32K();
					break;
				case QUEC_PCM_CODEC_SAMPLE_48000:
					AudioHAL_AifUseSSPA_48K();
					break;
				default : 
					AudioHAL_AifUseSSPA_NB();
					break;
			}
		}
	}
}


// tx dsp gain: -36~12
void quec_set_txdspgain(signed char gain)
{
	if(gain < -36) gain = -36;
    if(gain > 12) gain = 12;
	AudioHAL_AifSetTxDSPGain(gain);
}
signed char quec_get_txdspgain(void)
{
	return AudioHAL_AifGetTxDSPGain();
}
// tx codec gain: 0~4
static short txcodecgain = 0;
void quec_set_txcodecgain(short gain)
{
	 if(gain < 0) gain = 0;
    if(gain >= 4) gain = 4;
	txcodecgain = gain;
	AudioHAL_AifSetTxCodecGain(gain, gain);
}
short quec_get_txcodecgain(void)
{
	return txcodecgain;
}

/*==========================================================*/
/*                  quec_bind_speakerpa_cb                    */
/*==========================================================*/
void quec_bind_speakerpa_cb(cb_on_speakerpa cb)
{
	AudioHAL_AifBindSpeakerPA_CB((AUDIOHAL_SpeakerPA_T)cb);
}

//20210310 august add  loudspk pa cb
void quec_bind_loudspkpa_cb(cb_on_speakerpa cb)
{
	AudioHAL_AifBindSpeaker_CB(cb);
}


/*****************************************************************/
//add by 2020/07/08 august add update_audio_parameters
/*****************************************************************/
#ifdef QUECTEL_OPEN_CPU
static int ACMCheckHead(const char *fname, char *p)
{
	NVM_Header_ts header;
	int bytesRead = 0;
	bytesRead = ql_fread(&header, sizeof(NVM_Header_ts),1, fname);
	if(bytesRead != sizeof(NVM_Header_ts)){
		quec_debug_print_uart(" read NVM head error!!\n");
		return -1;
	}
	if (strcmp(header.Version, p) != 0){
		ql_fclose(fname);
		quec_debug_print_uart(" NVM file error!!\n");
		return -1;
	}
	return 0;
}

static int ACMReadFSTable(char *name, char *buff)
{
	QFILE *ACMTableFileID;
	int bytesRead = 0;
	int i = 0,retval = 0;
	int file_size = 0;

	ACMTableFileID = ql_fopen(name,"r");
	
	file_size = ql_fsize(ACMTableFileID);
	if(file_size <= sizeof(NVM_Header_ts)){
		ql_fclose(ACMTableFileID);
		quec_debug_print_uart(" NVM file head error, head size: %d!!\n", file_size);
		return -1;
	}
	if(!strcmp(AUDIO_GAIN_NVM1_NAME,name)){
		if(ACMCheckHead(ACMTableFileID, SINGLE_NVM_VERSION1) == -1){
			return -1;
		}
		bytesRead = ql_fread(buff, sizeof(ACMCodec_GainT)*10 ,1, ACMTableFileID);
		if(bytesRead != sizeof(ACMCodec_GainT)*10)
		{
			ql_fclose(ACMTableFileID);
			return -1;
		}
	}
	if(!strcmp(AUDIO_VE_NVM1_NAME,name)){
		if(ACMCheckHead(ACMTableFileID, SINGLE_NVM_VERSION1) == -1){
			return -1;
		}
		bytesRead = ql_fread(buff,sizeof(ACMDSP_VEParametersT)*10, 1,  ACMTableFileID);
		if(bytesRead != sizeof(ACMDSP_VEParametersT)*10)
		{
			ql_fclose(ACMTableFileID);
			return -1;
		}
	}
	if(!strcmp(AUDIO_MEDIA_VE_NVM1_NAME,name)){
		if(ACMCheckHead(ACMTableFileID, SINGLE_NVM_VERSION1) == -1){
			return -1;
		}
		bytesRead = ql_fread(buff,sizeof(ACMCP_MediaVEarametersT)*11, 1,  ACMTableFileID);
		if(bytesRead != sizeof(ACMCP_MediaVEarametersT)*11)
		{
			ql_fclose(ACMTableFileID);
			return -1;
		}	
	}
	ql_fclose(ACMTableFileID);
	return 0;
}

void ql_update_audio_parameters(void)
{
	int ret = 0;
	NVM_Header_ts header;
	char sVersion[32] = "";
	short a = 3,b = 0 ;	
	FILE_ID  ACMTableFileID;

	if(quec_audio_file_exist(AUDIO_GAIN_NVM1_NAME) && (g_pGainParamsTable != NULL)){	
		f_pGainParamsTable = (ACMCodec_GainT *)malloc(sizeof(ACMCodec_GainT)*10);
		if(ACMReadFSTable(AUDIO_GAIN_NVM1_NAME, f_pGainParamsTable) == -1){
			quec_debug_print_uart("fs: audio gain read error\n");
			free(f_pGainParamsTable);
			f_pGainParamsTable = NULL;
			return;
		}
		ret = memcmp(g_pGainParamsTable,f_pGainParamsTable,sizeof(ACMCodec_GainT)*10);
		if(ret){
			memcpy(g_pGainParamsTable,f_pGainParamsTable,sizeof(ACMCodec_GainT)*10);
			
			ACMTableFileID = FDI_fopen("audio_gain.nvm","wb");
			memset((unsigned char *)&header, 0, sizeof(NVM_Header_ts));
			sprintf(sVersion, "%d.%d", a, b);

			SET_STRING(header.Date, "");
			SET_STRING(header.time, "");
			SET_STRING(header.Version, "");
			//SET_STRING(header.HW_ID, GetSystemReleaseName());
		    strncpy(header.HW_ID,GetSystemReleaseName(), 31);
		    
			SET_STRING(header.CalibVersion, sVersion);
			SET_STRING(header.Version, "MarvellModem_Crane");
			SET_STRING(header.StructName, "ACMCodec_GainT");
			header.StructSize = sizeof(ACMCodec_GainT);
			header.NumofStructs = (int)10;
			
			g_GainParamsCount = header.NumofStructs;

			if (!FDI_fwrite(&header,sizeof(NVM_Header_ts),1, ACMTableFileID))
				ACM_ASSERT(0);

			if (!FDI_fwrite(g_pGainParamsTable, sizeof(ACMCodec_GainT)*10, 1, ACMTableFileID))
				ACM_ASSERT(0);

			if (FDI_fclose(ACMTableFileID))
				ACM_ASSERT(0);

			DIAG_FILTER(AUDIO, ACM, ACMCreateGainNvm, DIAG_INFORMATION)
		    diagPrintf("ql ACMCreateGainNvm API called: create or override existing files ");
			free(f_pGainParamsTable);
			f_pGainParamsTable = NULL;
		}
		else
		{
			free(f_pGainParamsTable);
			f_pGainParamsTable = NULL;
		}
	}
	
	if(quec_audio_file_exist(AUDIO_VE_NVM1_NAME) && (g_pVEParamsTable != NULL)){	
		f_pVEParamsTable = (ACMDSP_VEParametersT *)malloc(sizeof(ACMDSP_VEParametersT)*10);
		if(ACMReadFSTable(AUDIO_VE_NVM1_NAME, f_pVEParamsTable) == -1){
			quec_debug_print_uart("fs: audio ve read error\n");
			free(f_pVEParamsTable);
			f_pVEParamsTable = NULL;
			return;
		}
		ret = memcmp(g_pVEParamsTable,f_pVEParamsTable,sizeof(ACMDSP_VEParametersT)*10);
		if(ret){
			memcpy(g_pVEParamsTable,f_pVEParamsTable,sizeof(ACMDSP_VEParametersT)*10);
			
			ACMTableFileID = FDI_fopen("audio_ve.nvm","wb");

			memset((unsigned char *)&header, 0, sizeof(NVM_Header_ts));
			sprintf(sVersion, "%d.%d", a, b);

			SET_STRING(header.Date, "");
			SET_STRING(header.time, "");
			SET_STRING(header.Version, "");
			//SET_STRING(header.HW_ID, GetSystemReleaseName());
		    strncpy(header.HW_ID,GetSystemReleaseName(), 31);
		    
			SET_STRING(header.CalibVersion, sVersion);
			SET_STRING(header.Version, "MarvellModem_Crane");
			SET_STRING(header.StructName, "ACMDSP_VEParametersT");
			header.StructSize = sizeof(ACMDSP_VEParametersT);
			header.NumofStructs = 10;
			
			g_VEParamsCount = header.NumofStructs;

			if (!FDI_fwrite(&header,sizeof(NVM_Header_ts),1, ACMTableFileID))
				ACM_ASSERT(0);

			if (!FDI_fwrite(g_pVEParamsTable, sizeof(ACMDSP_VEParametersT)*10, 1, ACMTableFileID))
				ACM_ASSERT(0);

			if (FDI_fclose(ACMTableFileID))
				ACM_ASSERT(0);

			DIAG_FILTER(AUDIO, ACM, ACMCreateVENvm, DIAG_INFORMATION)
		    diagPrintf("ql ACMCreateVENvm API called: create or override existing files ");
			free(f_pVEParamsTable);
			f_pVEParamsTable = NULL;
		}
		else
		{
			free(f_pVEParamsTable);
			f_pVEParamsTable = NULL;
		}
	}
	if(quec_audio_file_exist(AUDIO_MEDIA_VE_NVM1_NAME)){
		f_pMediaVEParamsTable = (ACMCP_MediaVEarametersT *)malloc(sizeof(ACMCP_MediaVEarametersT)*11);
		if(ACMReadFSTable(AUDIO_MEDIA_VE_NVM1_NAME, f_pMediaVEParamsTable) == -1){
			quec_debug_print_uart("fs: audio config read error\n");
			free(f_pMediaVEParamsTable);
			f_pMediaVEParamsTable = NULL;
			return;
		}
		ret = memcmp(g_pMediaVEParamsTable,f_pMediaVEParamsTable,sizeof(ACMCP_MediaVEarametersT)*11);
		if(ret){
			memcpy(g_pMediaVEParamsTable,f_pMediaVEParamsTable,sizeof(ACMCP_MediaVEarametersT)*11);

			ACMTableFileID = FDI_fopen("audio_mediaVE.nvm","wb");

			memset((unsigned char *)&header, 0, sizeof(NVM_Header_ts));
			sprintf(sVersion, "%d.%d", a, b);

			SET_STRING(header.Date, "");
			SET_STRING(header.time, "");
			SET_STRING(header.Version, "");
			//SET_STRING(header.HW_ID, GetSystemReleaseName());
			strncpy(header.HW_ID,GetSystemReleaseName(), 31);

			SET_STRING(header.CalibVersion, sVersion);
			SET_STRING(header.Version, "MarvellModem_Crane");
			SET_STRING(header.StructName, "ACMCP_MediaVEarametersT");
			header.StructSize = sizeof(ACMCP_MediaVEarametersT);
			header.NumofStructs = 11;

			g_MediaVEParamsCount = header.NumofStructs;

			if (!FDI_fwrite(&header,sizeof(NVM_Header_ts),1, ACMTableFileID))
				ACM_ASSERT(0);

			if (!FDI_fwrite(g_pMediaVEParamsTable, sizeof(ACMCP_MediaVEarametersT)*11, 1, ACMTableFileID))
				ACM_ASSERT(0);

			if (FDI_fclose(ACMTableFileID))
				ACM_ASSERT(0);

			DIAG_FILTER(AUDIO, ACM, ACMCreateMediaVENvm, DIAG_INFORMATION)
			diagPrintf("ACMCreateMediaEQNvm API called: create or override existing files ");
			free(f_pMediaVEParamsTable);
			f_pMediaVEParamsTable = NULL;
		}
		else
		{
			free(f_pMediaVEParamsTable);
			f_pMediaVEParamsTable = NULL;
		}
	}
}
#endif

//Mute uplink or downlink dsp data during a call
QUEC_Mute_Err quec_mute_voicecall(QUEC_Mute_VoiceCall direction, unsigned char mute, unsigned char time)
{
	unsigned char count = 0;
	if((direction > MODULE_TO_PHONE) || (mute > 1)){
		quec_debug_print_uart("ql_mute_voicecall:direction:%d ,mute:%d\n", direction, mute);
		return MUTE_ERR_PARAMETER;
	}
	if(time != 0){
		while((isVoiceEnabled() == 0) && (count < (time * 1000 / 50))){
			quec_rtos_task_sleep_ms(50);
			count++;
		}
		quec_debug_print_uart("ql_mute_voicecall:%d ,count:%d\n",isVoiceEnabled(), count);
		if(count > (time * 1000 / 50)){
			return MUTE_ERR_TIMEOUT;
		}
	}else{
		if(isVoiceEnabled() == 0){
			return MUTE_ERR_NO_VOICECALL;
		}
	}
	
	switch(direction)
	{
		case TWO_WAY:
			AudioHAL_AifSetDspRxMute(mute);
			AudioHAL_AifSetMute(mute);
			break;
		case PHONE_TO_MODULE:
			AudioHAL_AifSetDspRxMute(mute);
			break;
		case MODULE_TO_PHONE:
			AudioHAL_AifSetMute(mute);
			break;
		default:
			break;
	}
	return MUTE_ERR_NO;
}
//Mute ringback tone
void quec_mute_ringtone(unsigned char on_off)
{
	extern unsigned char mute_ringtone_flag;
	if(on_off > 1){
		mute_ringtone_flag = 0;
	}else{
		mute_ringtone_flag = on_off;
	}
}



/*Fias 2021.11.16  增加开机检测耳机状态接口*/
/***********************************************************************
 *
 * Name:		ql_get_headset_state
 *
 * Description: 开机检测耳机状态
 *
 * Parameters:		无
 *
 * Returns:	-1表示检测接口busy没有执行检测；1表示检测到耳机已插入；0表示检测到耳机未插入
 *
 * Notes:			无
 *
 ***********************************************************************/
extern int quec_get_headset_flag(void);
int quec_get_headset_state(void)
{
	return  quec_get_headset_flag();
}

int quec_set_dtmf_detect(DTMFDetectionHandler_t cb, int onoff)
{
	DTMFDetectionControl_t DTMFDetectionControl;
	
	memset(&DTMFDetectionControl, 0x00, sizeof(DTMFDetectionControl));

	if(onoff == 0){
		DTMFDetectionControl.dtmfType = AUDIO_DTMF_RX;
        DTMFDetectionControl.onoff = AUDIO_DTMF_OFF;
		OEMAudio_UnBindDTMFDetectionHandler(cb, &DTMFDetectionControl); 
	} else {
		DTMFDetectionControl.dtmfType = AUDIO_DTMF_RX;
		DTMFDetectionControl.onoff = AUDIO_DTMF_ON;
		DTMFDetectionControl.dialToneToOthersTones = 25;
		DTMFDetectionControl.dialTonesToOthersDialTones = dialTonesToOthersDialTones_DEFAULT;
		DTMFDetectionControl.dialVadDuration = dialVadDuration_DEFAULT;
		OEMAudio_BindDTMFDetectionHandler(cb, &DTMFDetectionControl);    
	}
	return 0;
}

/*pcm play start*/
audio_track_handle quec_audio_track_open(unsigned int rate, unsigned int channels, int64_t option, audio_track_callback event_cb)
{
    return audio_track_open(rate,channels,option,event_cb);
}
int quec_audio_track_write(audio_track_handle handle, uint8_t* data, unsigned int size)
{
    return audio_track_write(handle,  data, size);
}
int quec_audio_track_close(audio_track_handle handle,int force)
{
    return  audio_track_close(handle,force); 
}
int quec_audio_track_ctrl(audio_track_handle handle, enum audio_track_control ctrl_type, int ctrl_value)
{
    return  audio_track_ctrl(handle,ctrl_type,ctrl_value); 
}
/*pcm play end*/

/*pcm record start*/
#ifdef QUEC_AUDIO_DENOISE
#include "ql_audio_denoise.h"
#include "ql_platform.h"

#define NOT_SET_DENOISE_VAD  0 
static void *denoise_memory = NULL;
static void *denoise_inst_handle = NULL;
static void *pcm_data_temp = NULL;
static void *pcm_data_send_denoise = NULL;//送入算法处理的数据
bool ql_denoise_enabled = 0;
int32_t denoise_count = 0; //每次要取出的长度，同时也是算法每次处理的长度


void ql_set_denoise_flag(bool onoff)
{
    ql_denoise_enabled = onoff;
}

bool ql_get_denoise_flag(void)
{
    return ql_denoise_enabled;
}
#endif
audio_record_handle  quec_audio_record_open(unsigned int rate, unsigned int channels, int64_t option, audio_record_callback event_cb)
{
    //quec_debug_print_uart("in open");
#ifdef QUEC_AUDIO_DENOISE
    if (ql_denoise_enabled)
    {
        if (denoise_inst_handle == NULL)
        {
            unsigned int mem_needed = ql_denoise_dsp_get_memory_needed();
            quec_debug_print_uart("mem_needed %d ...\r\n", mem_needed);
            if (mem_needed<=0)
            {
                quec_debug_print_uart("ql_denoise_dsp_get_memory_needed error\n");
                goto exit;
            }
            denoise_memory = malloc(mem_needed);
            if (denoise_memory == NULL)
            {
                quec_debug_print_uart("denoise_memory malloc error\n");
                goto exit;
            }
            quec_debug_print_uart("OK ql_memory 0x%x ...\r\n", denoise_memory);
            ql_denoise_set_memory_base(denoise_memory, mem_needed);

            int32_t sample_rate = rate;
            int32_t denoise_lvl = 1;        // 0.2 - 4.0
            int32_t drc_gain = 3;           // drc post gain
            denoise_count = (sample_rate == 8000)?320:640;
            pcm_data_temp = malloc(denoise_count);
            pcm_data_send_denoise = malloc(denoise_count);
            if(pcm_data_send_denoise == NULL || pcm_data_temp == NULL)
            {
                quec_debug_print_uart("pcm_data_send_denoise or pcm_data_temp malloc error\n");
                if (pcm_data_temp)
                {
                    free(pcm_data_temp);
                    pcm_data_temp = NULL;
                }
                if (pcm_data_send_denoise)
                {
                    free(pcm_data_send_denoise);
                    pcm_data_send_denoise = NULL;
                }
                if(denoise_memory)
                {
                    free(denoise_memory);
                    denoise_memory = NULL;
                }
                goto exit;
            }
            denoise_inst_handle = ql_denoise_init(sample_rate, denoise_lvl, drc_gain, 20);
            if (denoise_inst_handle == NULL)
            {
                quec_debug_print_uart("denoise_inst_handle init error\n");
                if (pcm_data_temp)
                {
                    free(pcm_data_temp);
                    pcm_data_temp = NULL;
                }
                if (pcm_data_send_denoise)
                {
                    free(pcm_data_send_denoise);
                    pcm_data_send_denoise = NULL;
                }
                if(denoise_memory)
                {
                    free(denoise_memory);
                    denoise_memory = NULL;
                }
                goto exit;
            }
            ql_denoise_set_vad_lvl(denoise_inst_handle, NOT_SET_DENOISE_VAD, NOT_SET_DENOISE_VAD);
        }
    }
#endif
exit:
    return audio_record_open(rate, channels, option,event_cb);
}
int quec_audio_record_read(audio_record_handle handle, uint8_t*data, unsigned int* count)
{   
    
	int ret = -1;
    int record_ret = -1;
    int cur_len = 0;    
#ifdef QUEC_AUDIO_DENOISE
    ql_cpu_fre_set(QL_PP5);
	if (ql_denoise_enabled)
	{
		if (denoise_inst_handle == NULL || denoise_memory == NULL || pcm_data_temp == NULL || pcm_data_send_denoise == NULL)
		{
            quec_debug_print_uart("denoise_inst_handle or denoise_memory or pcm_data_temp NULL\n");	
            if (denoise_inst_handle)
            {
                ql_denoise_cleanup(denoise_inst_handle);
                denoise_inst_handle = NULL;
            }
            if (denoise_memory)
            {
                free(denoise_memory);
                denoise_memory = NULL;
            }
            if (pcm_data_temp)
            {
                free(pcm_data_temp);
                pcm_data_temp = NULL;
            }
            if (pcm_data_send_denoise)
            {
                free(pcm_data_send_denoise);
                pcm_data_send_denoise = NULL;
            }
            goto exit; //一旦发生其他情况，清除资源，走源接口
		}
        //一帧20ms
		if (denoise_count != *count)
		{
            quec_debug_print_uart("denoise_count %d < *count %d\n",denoise_count,*count);
            if (denoise_inst_handle)
            {
                ql_denoise_cleanup(denoise_inst_handle);
                denoise_inst_handle = NULL;
            }
            if (denoise_memory)
            {
                free(denoise_memory);
                denoise_memory = NULL;
            }
            if (pcm_data_temp)
            {
                free(pcm_data_temp);
                pcm_data_temp = NULL;
            }
            if (pcm_data_send_denoise)
            {
                free(pcm_data_send_denoise);
                pcm_data_send_denoise = NULL;
            }
			goto exit;
		}
              
        //读取数据
        cur_len = denoise_count;        
        record_ret = audio_record_read(handle,pcm_data_send_denoise,&cur_len);         
        memcpy(pcm_data_temp,pcm_data_send_denoise,sizeof(pcm_data_temp));
        if(record_ret == 0 &&cur_len == denoise_count )
        {      
            ret = ql_denoise_process(denoise_inst_handle, pcm_data_send_denoise, data);
            if(ret >= 0)
            {
                //处理成功直接返回
                *count = denoise_count;
                return record_ret;
            }
            else
            {
                //处理失败复制缓存中的数据，进行下一次读取
                memcpy(data, pcm_data_temp, *count);
                *count = denoise_count;
                return record_ret;
            }
        }
        else
        {
            *count = 0;
            //quec_debug_print_uart("record_ret error or cur_len != denoise_count ,record_ret=%d,cur_len=%d,\n",record_ret,cur_len);
            return record_ret;
        }
	}
   
#endif

exit:
    record_ret = audio_record_read(handle,data,count);   
    return record_ret;
}

int quec_audio_record_close(audio_record_handle handle,int force)
{
#ifdef QUEC_AUDIO_DENOISE
    if(ql_denoise_enabled)
    {
        //quec_debug_print_uart("over close \n");
        if (denoise_inst_handle)
        {
            ql_denoise_cleanup(denoise_inst_handle);
            denoise_inst_handle = NULL;
        }
        if (denoise_memory)
        {
            free(denoise_memory);
            denoise_memory = NULL;
        }
        if (pcm_data_temp)
        {
            free(pcm_data_temp);
            pcm_data_temp = NULL;
        }
        if (pcm_data_send_denoise)
        {
            free(pcm_data_send_denoise);
            pcm_data_send_denoise = NULL;
        }    
    }
#endif
    return  audio_record_close(handle,force);
}

int quec_audio_record_ctrl(audio_record_handle handle, enum audio_record_control ctrl_type, int ctrl_value) 
{
    return  audio_record_ctrl(handle,ctrl_type,ctrl_value);
}

/*pcm record END*/

/*WAV PALY START*/
int quec_wav_play(const char* file_name, struct audio_track_config* track_config, audio_track_handle* handle)
{
    NEED_USE_OWEN_FS;
    return wave_playback_start( file_name,  track_config, handle);
}

int quec_wav_play_stop(audio_track_handle handle,char force)
{
    return wave_playback_stop(handle, force);
}
/*WAV PLAY END*/

/*mp3 play start*/
#ifdef QUEC_MP3_FUNC
int quec_mp3_play(char *file_name,Mp3PlaybackHandle* handle,Mp3PlayConfigInfo* mp3_configInfo) 
{
    NEED_USE_OWEN_FS;
    return mp3PlayStart(file_name,mp3_configInfo,handle);
}

int quec_mp3_stream_play_buffer(Mp3PlaybackHandle handle,unsigned char *mp3_buff, int mp3_size)
{
    Mp3StreamDataInfo dataInfo;
    dataInfo.handle = handle;
    dataInfo.buf = mp3_buff;
    dataInfo.size = mp3_size;
    return mp3StreamPlayBuffer(&dataInfo);
}
int quec_mp3_play_stop(Mp3PlaybackHandle handle,int drain)
{
	NEED_USE_OWEN_FS;
	return mp3PlayStop(handle,drain);
}
int quec_mp3_get_pcm_handle(Mp3PlaybackHandle handle, unsigned int* pcm_handle)
{
	NEED_USE_OWEN_FS;
	return mp3GetPCMOutHandle(handle,pcm_handle);
}

int quec_mp3_play_get_duration(const char* file_name, int* duration)
{
	NEED_USE_OWEN_FS;
	return mp3PlayGetDuration(file_name,duration);
}
int quec_mp3_stream_get_duration(Mp3PlaybackHandle handle, Mp3PlayInfoType type, int* value)
{
	NEED_USE_OWEN_FS
	return mp3PlayGetInfo(handle, type, value);
	
}

#endif 
/*mp3 play end*/

/*amr play start*/
#ifdef  QUEC_AMR_FUNC
int quec_amr_play(char* file_name,AmrPlaybackHandle* handle,AmrPlaybackConfigInfo* amr_config)
{
    NEED_USE_OWEN_FS;
    return amrPlayStart(file_name,amr_config,handle);
}
int quec_amr_stream_play_buffer(AmrPlaybackHandle handle,unsigned char *amr_buff, int amr_size)
{
    return amrPlayBuffer(handle,amr_buff,amr_size);
}
int quec_amr_play_stop(AmrPlaybackHandle handle,int drain)
{
     NEED_USE_OWEN_FS;
     return amrPlayStop(handle, drain);
}
int quec_amr_get_pcm_handle(AmrPlaybackHandle handle, unsigned int* track_handle)
{
    NEED_USE_OWEN_FS;
    return amrGetPCMOutHandle(handle,track_handle);
}
/*amr play end*/

/*amr record start*/
int quec_amr_record(char* file_name,AmrEncodeHandle* handle,AmrEncConfigInfo* config)
{
    NEED_USE_OWEN_FS;
    return amrEncStart(file_name,config,handle);
}

int quec_amr_record_stop(AmrEncodeHandle handle)
{
    NEED_USE_OWEN_FS;
    return amrEncStop(handle);
}
#endif
/*amr record end*/

int quec_aud_dtmf_play(QUEC_AUDIOHAL_TONE_TYPE tone, int onoff)
{
     int ret = -1;
     unsigned int asiic_tone = 0;
     if(tone > 15)
	{
		quec_debug_print_uart("param error\n");
		return -1;
	}
     if(tone<=QUEC_AUDIOHAL_DTMF_9)
     {
        asiic_tone =tone+48;
     }
     if(tone>=QUEC_AUDIOHAL_DTMF_A && tone<=QUEC_AUDIOHAL_DTMF_D) 
     {
        asiic_tone =tone+55;
     }
     if(tone==QUEC_AUDIOHAL_DTMF_S) 
     {
        asiic_tone ='*';
     }
     if(tone==QUEC_AUDIOHAL_DTMF_P) 
     {
        asiic_tone ='#';
     }
     if( onoff){
        return audio_tone_start_ascii(asiic_tone);
     }
     else 
     {
        return audio_tone_stop();
     }
}

int quec_aud_tone_play(int f1, int f2, int onoff)
{
    int ret = -1;
     if( onoff){
        return audio_tone_start_frequency(f1, f2);
     }
     else 
     {
        return audio_tone_stop();
     }
}

#endif
#endif
