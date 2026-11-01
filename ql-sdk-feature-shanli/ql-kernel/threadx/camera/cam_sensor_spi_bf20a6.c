#include "cam_sensor.h"
#include "tuning/cam_asr_isp_tuningtab.h"
//#include "cam_util.h"


//raw8 640 * 486 spi 2 lan sdr crc  20fps
static struct regval_tab bf20a6_init_raw8_spi2lan_crc_sdr[] = {
	0
};

//yuv422 640 * 480 spi 2 lan sdr
static struct regval_tab bf20a6_init_yuv422_spi2lan_crc_sdr[] = {

	{0xf2, 0x01},
	{0x12, 0x80},
	{0x3a, 0x02},
	{0xe1, 0x92},
	{0xe3, 0x02},
	{0xe0, 0x00},
	{0x2a, 0x98},
	{0x0e, 0x47},
	{0x0f, 0x60},
	{0x10, 0x57},
	{0x11, 0x60},
	{0x30, 0x61},
	{0x62, 0xcd},
	{0x63, 0x1a},
	{0x64, 0x38},
	{0x65, 0x52},
	{0x66, 0x68},
	{0x67, 0xc2},
	{0x68, 0xa7},
	{0x69, 0xab},
	{0x6a, 0xad},
	{0x6b, 0xa9},
	{0x6c, 0xc4},
	{0x6d, 0xc5},
	{0x6e, 0x18},
	{0xc0, 0x20},
	{0xc1, 0x24},
	{0xc2, 0x29},
	{0xc3, 0x25},
	{0xc4, 0x28},
	{0xc5, 0x2a},
	{0xc6, 0x41},
	{0xca, 0x23},
	{0xcd, 0x34},
	{0xce, 0x32},
	{0xcf, 0x35},
	{0xd0, 0x6c},
	{0xd1, 0x6e},
	{0xd2, 0xcb},
	{0xe2, 0x09},
	{0xe4, 0x73},
	{0xe5, 0x22},
	{0xe6, 0x24},
	{0xe7, 0x64},
	{0xe8, 0xf6},
	{0x4a, 0x00},
	{0x00, 0x03},
	{0x1f, 0x02},
	{0x22, 0x02},
	{0x0c, 0x31},
	{0x00, 0x00},
	{0x60, 0x81},	
	{0x61, 0x81},		
	{0xa0, 0x08},
	{0x01, 0x1a},
	{0x01, 0x1a},
	{0x01, 0x1a},
	{0x02, 0x15},
	{0x02, 0x15},
	{0x02, 0x15},
	{0x13, 0x08},
	{0x8a, 0x96},
	{0x8b, 0x06},
	{0x87, 0x18},
	{0x34, 0x48},//lens
	{0x35, 0x40},
	{0x36, 0x40},
	{0x71, 0x40},	
	{0x72, 0x2b},
	{0x74, 0xa2},
	{0x75, 0xa9},
	{0x78, 0x02},
	{0x79, 0xa0},
	{0x7a, 0x94},
	{0x7c, 0x97},
	{0x40, 0x3f},
	{0x41, 0x30},
	{0x42, 0x28},
	{0x43, 0x1D},
	{0x44, 0x1A},
	{0x45, 0x16},
	{0x46, 0x13},
	{0x47, 0x10},
	{0x48, 0x0D},
	{0x49, 0x0C},
	{0x4B, 0x0A},
	{0x4C, 0x0B},
	{0x4E, 0x09},
	{0x4F, 0x08},
	{0x50, 0x08},
	{0x5f, 0x29},
	{0x23, 0x33},
	{0xa1, 0x10},//AWB
	{0xa2, 0x0d},
	{0xa3, 0x30},
	{0xa4, 0x06},
	{0xa5, 0x22},
	{0xa6, 0x56},
	{0xa7, 0x18},
	{0xa8, 0x1a},
	{0xa9, 0x12},
	{0xaa, 0x12},
	{0xab, 0x16},
	{0xac, 0xb1},
	{0xba, 0x12},
	{0xbb, 0x12},
	{0xad, 0x12},
	{0xae, 0x56},//56
	{0xaf, 0x0a},
	{0x3b, 0x30},
	{0x3c, 0x12},
	{0x3d, 0x22},
	{0x3e, 0x3f},
	{0x3f, 0x28},
	{0xb8, 0xc3},
	{0xb9, 0xA3},
	{0x39, 0x47},//pure color threshold
	{0x26, 0x13},
	{0x27, 0x16},
	{0x28, 0x14},
	{0x29, 0x18},
	{0xee, 0x0d}, 
	{0x13, 0x05},
	{0x24, 0x38},
	{0x81, 0x20},
	{0x82, 0x40},
	{0x83, 0x30},
	{0x84, 0x58},
	{0x85, 0x30},
	{0x92, 0x08},
	{0x86, 0xa0},
	{0x8a, 0x96},
	{0x91, 0xff},
	{0x94, 0x62},
	{0x9a, 0x18},//outdoor threshold
	{0xf0, 0x46},
	{0x51, 0x17},//color normal
	{0x52, 0x03},
	{0x53, 0x5f},
	{0x54, 0x47},
	{0x55, 0x66},
	{0x56, 0x0f},
	{0x7e, 0x14},
	{0x57, 0x36},//A光color
	{0x58, 0x2a},
	{0x59, 0xAa},
	{0x5a, 0xa8},
	{0x5b, 0x43},
	{0x5c, 0x10},
	{0x5d, 0x00},
	{0x7d, 0x36},
	{0x5e, 0x10},
	{0xd6, 0x98},//contrast
	{0xd5, 0x00},//低光加亮度
	{0xb0, 0x84},//灰色区域降饱和度
	{0xb5, 0x08},//低光降饱和度阈值
	{0xb1, 0xc8},//saturation
	{0xb2, 0xc0},
	{0xb3, 0xd0},
	{0xb4, 0xb0},
	{0x32, 0x00},
	{0xa0, 0x09},
	{0x00, 0x03},	
	{0x0b, 0x02},
/*1lan
	{0x12,0xa0},
	{0x3a,0x01},
	{0xe1,0xd3},
	{0xe3,0x02},
	{0x8a,0x4b},
*/
//2lan
	{0x12,0x80},
	{0x3a,0x02},
	{0xe1,0x92},
	{0xe3,0x02},
	{0x8a,0x96},



};

static struct regval_tab bf20a6_id[] = {
	{0xfc, 0x20},
	{0xfd, 0xa6},
};
static struct regval_tab bf20a6_vts[] = {
	
	{0x00, 0x00},
};

static struct regval_tab bf20a6_stream_on[] = {
	{0xfe, 0x03},
	{0x51, 0x01},
};
static struct regval_tab bf20a6_stream_off[] = {
	{0xfe, 0x03},
	{0x51, 0x00},
};
static struct regval_tab bf20a6_expo[] = {
	{0xfe, 0x00},    //page select
	{0x03, 0x01},    //exp_high
	{0x04, 0x00},    //exp_low
};
static struct regval_tab bf20a6_gain[] = {
	{0xfe, 0x00},    //page select
	{0x48, 0x01},    //gain
};
static struct regval_tab bf20a6_vflip[] = {
	{0x00, 0x00},
};
static struct regval_tab bf20a6_hflip[] = {
	{0x00, 0x00},
};

static struct crane_sensor_i2c_attr bf20a6_i2c_attr[] = {
	{
		I2C_8BIT,
		I2C_8BIT,
		0x6e,
	}
};

static struct crane_sensor_module bf20a6_MODULE_INFO[] = {
	{
		0x01,
		"0x01",
		0,
	},
	{
		0xff,
		"0xff",
		0,
	},
};

static struct crane_sensor_resolution bf20a6_resolution[] = {
	/*{
		SENSOR_FMT_RAW8,
		MEDIA_BUS_FMT_SRGGB8_1X8,
		640,
		480 + EXTRA_LINES_RAW_SENSOR,
		0x0708,
		0x0d06,
		30,
		15,
		SENSOR_RES_BINING1,
		{
			bf20a6_init_raw8_spi2lan_crc_sdr,
			ARRAY_SIZE(bf20a6_init_raw8_spi2lan_crc_sdr),
		},
	},*/
	{
		SENSOR_FMT_YUV422,
		MEDIA_BUS_FMT_YVYU8_2X8,
		640,
		480,
		0x0708,
		0x0d06,
		30,
		15,
		SENSOR_RES_BINING1,
		{
			bf20a6_init_yuv422_spi2lan_crc_sdr,
			ARRAY_SIZE(bf20a6_init_yuv422_spi2lan_crc_sdr),
		},
	},
};

int bf20a6_get_pixelclock(uint_32 *rate, uint_32 mclk)
{
	return 0;
}
int bf20a6_get_dphy_desc(struct csi_dphy_desc *dphy_desc, uint_32 mclk)
{
	return 0;
}
int bf20a6_update_otp(struct crane_sensor_otp *opt)
{
	return 0;
}


int bf20a6_ata_open(struct crane_sensor_ata *ata)
{
	int ret = 0;


	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)bf20a6_i2c_attr;
	//fatal_printf("bf20a6_ata_open ata value is  %d!\n", ata->on);
	if(ata->on){
		
		//fatal_printf("bf20a6_ata_open open ata\n");
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb6,0x01);
	}else {
			//fatal_printf("bf20a6_ata_open close ata\n");	
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb6,0x00);
	}
/**/	
return ret;
}


int bf20a6_update_aec(struct crane_sensor_aec *aec)
{
	int ret = 0;
//	uint_32 val1,val2,val3 = 0;
/*
	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)bf20a6_i2c_attr;

//	CAMLOGI("bf20a6_update_aec: exp= 0x%x 0x%x! gain =0x%x",aec->exp_high,aec->exp_low,aec->gain);
	ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
	if (ret < 0)
		CAMLOGE("sensor update_aec: error!");
	ret = crane_i2c_write_single(i2c_attr, 0x03,aec->exp_high);
	if (ret < 0)
		CAMLOGE("sensor update_aec exp: error!");
	ret = crane_i2c_write_single(i2c_attr, 0x04,aec->exp_low);
	if (ret < 0)
		CAMLOGE("sensor update_aec exp: error!");
	ret = crane_i2c_write_single(i2c_attr, 0x48,aec->gain);
	if (ret < 0)
		CAMLOGE("sensor update_aec gain: error!");
#if 0
	ret = crane_i2c_read(i2c_attr,0x03,&val1);
	ret = crane_i2c_read(i2c_attr,0x04,&val2);
	ret = crane_i2c_read(i2c_attr,0x48,&val3);
	CAMLOGI("sensor read exp = 0x%x 0x%x gain=0x%x",val1,val2,val3);
	ret = crane_i2c_read(i2c_attr,0xf0,&val2);
	ret = crane_i2c_read(i2c_attr,0xf1,&val3);
	CAMLOGI("sensor read ID = 0x%x 0x%x ",val2,val3);
#endif
*/
	return ret;
}


int bf20a6_s_power(int on)
{
	CAMLOGI("bf20a6_s_power: value = %d", on);
	gpio_direction_output(CAMERA_PWDN1);
	gpio_set_value(CAMERA_PWDN1, 0);

	if (on > 0) {
		gpio_set_value(CAMERA_PWDN1, 0);
		msleep(2);
		camera_ldo_cfg(POWER_OFF,CAMERA_AVDD,CAM_VDD_2V80);
		msleep(2);
		camera_ldo_cfg(POWER_OFF,CAMERA_IOVDD,CAM_VDD_1V80);
		msleep(2);

		disable_MCLK();
		UOS_Sleep(1); //delay 5ms
		camera_ldo_cfg(POWER_ON,CAMERA_IOVDD,CAM_VDD_1V80);// IO �������ϵ�
		msleep(1);
		camera_ldo_cfg(POWER_ON,CAMERA_AVDD,CAM_VDD_2V80);// AVDD ��Դ�ϵ�
		msleep(1);
		enable_MCLK();
		msleep(1);
		gpio_set_value(CAMERA_PWDN1, 1);
		msleep(2);
		gpio_set_value(CAMERA_PWDN1, 0);
		msleep(2);

	} else {
		gpio_set_value(CAMERA_PWDN1, 1);
		msleep(1);
		disable_MCLK();
		msleep(1);
		camera_ldo_cfg(POWER_OFF,CAMERA_AVDD,CAM_VDD_2V80);
		msleep(2);
		camera_ldo_cfg(POWER_OFF,CAMERA_IOVDD,CAM_VDD_1V80);
		msleep(1);
		gpio_set_value(CAMERA_PWDN1, 0);
	}
	return 0;

}

struct crane_sensor_spec_ops bf20a6_ops = {
	bf20a6_get_pixelclock,
	bf20a6_get_dphy_desc,
	bf20a6_update_otp,
	bf20a6_s_power,
	bf20a6_ata_open,
	bf20a6_update_aec,
};

struct crane_sensor_data crane_bf20a6_spi = {
	"bf20a6_spi",
	&bf20a6_ops,
	CAMERA_BACK,
	bf20a6_i2c_attr,
	ARRAY_SIZE(bf20a6_i2c_attr),
	{
		bf20a6_id,
		ARRAY_SIZE(bf20a6_id),
	},
	NULL,
	0,
	bf20a6_resolution,
	ARRAY_SIZE(bf20a6_resolution),
	{
		bf20a6_stream_on,
		ARRAY_SIZE(bf20a6_stream_on),
	},
	{
		bf20a6_stream_off,
		ARRAY_SIZE(bf20a6_stream_off),
	},
	{
		bf20a6_expo,
		ARRAY_SIZE(bf20a6_expo),
	},
	{
		bf20a6_vts,
		ARRAY_SIZE(bf20a6_vts),
	},
	{
		bf20a6_gain,
		ARRAY_SIZE(bf20a6_gain),
	},
	{
		bf20a6_hflip,
		ARRAY_SIZE(bf20a6_hflip),
	},
	{
		bf20a6_vflip,
		ARRAY_SIZE(bf20a6_vflip),
	},
	bf20a6_MODULE_INFO,
	ARRAY_SIZE(bf20a6_MODULE_INFO),
	asr_isp_tuning_tab,
	ARRAY_SIZE(asr_isp_tuning_tab),
	{
		{
			asr_isp_50hz_banding_tab,
			ARRAY_SIZE(asr_isp_50hz_banding_tab),
		},
		{
			asr_isp_60hz_banding_tab,
			ARRAY_SIZE(asr_isp_60hz_banding_tab),
		},
	},
	CAM_INF_SPI,  //CAM_SPI: spi    CAM_MIPI: mipi
	SPI_2_LAN,// .lane_num
	0,  //0x0:sdr   0x1:ddr spi_sdr
	1,  //0x0:no crc   0x1:crc,.spi_crc
	100,//.reset_delay
	0,  //auto set .cur_i2c_index
	0, //int cur_res_index
};

