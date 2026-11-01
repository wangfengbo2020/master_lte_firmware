#include "cam_sensor.h"
#include "tuning/cam_bf20a2_tuningtab.h"
//#include "cam_util.h"

//raw8 640 * 486 spi 2 lan sdr crc  20fps
static struct regval_tab Bf20a2_init_raw8_spi2lan_crc_sdr[] = {0};

//yuv422 640 * 480 spi 2 lan sdr
static struct regval_tab Bf20a2_init_yuv422_spi2lan_crc_sdr[] = {

        {0x12,0x80},
        {0x3a,0xe2},
        {0xcd,0x82},
        {0xca,0x02},//02->12
        {0x6b,0x71},
        {0x15,0x10},
        {0xd6,0x07},
    
        {0x8a,0x96},//96->4b
        {0x8b,0x3e},//7d->3e
        
        {0xcb,0x09},//add 20180627  
        {0xd7,0x01},
        {0xcc,0xde},//20190314
        {0xce,0x3F},
        {0xcf,0x50},
        {0xd1,0x30},//20180627
        {0xd5,0x10},    
        {0x4a,0x40},//Bit[1]: Mirror,Bit[0]: Vertical Flip //20190314
        {0x32,0x02},//Dummy line insert before active line low 8 bits//add 20180627 
        {0x33,0x03},//Bit[7:4]:Dummy line insert before active line high 4 bits; Bit[3:0]: line length high 4 bits//add 20180627    
        {0x2a,0x20},//Bit[7:0]: line length low 8 bits//add 20180627    
        {0x1f,0x18},
        {0x22,0x18},
        {0x28,0x60},
        {0x00,0x3b},//20180627
        {0x0d,0x3b},//20180627
    
        {0x28,0x63},
        {0xa0,0x44},//add 20180627  
        {0x01,0x19},//add 20180627  
        {0x02,0x18},//add 20180627  
        {0x13,0x0a},//add 20180627  
        {0x87,0x20},//add 20180627  
        {0x8c,0x06},//add 20180627  
        {0x8d,0x72},//add 20180627  
    
        {0x34,0x30},//20190314
        {0x35,0x26},//20190314
        {0x36,0x24},//20190314
    
        {0x40,0x36},
        {0x41,0x28},
        {0x42,0x20},
        {0x43,0x1a},
        {0x44,0x18},
        {0x45,0x14},
        {0x46,0x12},
        {0x47,0x10},
        {0x48,0x0f},
        {0x49,0x0e},
        {0x4B,0x0d},
        {0x4C,0x0c},
        {0x4E,0x0b},
        {0x4F,0x0a},
        {0x50,0x09},
    
        {0x70,0x0f},//add 20180627
        {0x72,0x27},
        {0x73,0x68},//add 20180627
        {0x74,0x82},//20190314
        {0x75,0x89},//20190314
        {0x76,0x8a},//add 20180627
        {0x78,0x34},
        {0x79,0x00},//add 20180627
        {0x7a,0x83},
        {0x13,0x07},    
        {0x39,0x00},
    
        {0x24,0x45},
        {0x80,0x92},
        {0x82,0x14},
        {0x83,0x28},
        {0x84,0x38},
        {0x85,0x60},
        {0x86,0x70},
        {0x8f,0x82},//add 20180627
        {0x96,0xb5},
        {0x9a,0x50},
        {0xf0,0x83},
        {0xf7,0x8a},
        {0xa0,0x45},
        {0xa2,0x08},//add 20180627
        {0xa3,0x32},//add 20180627
        {0xa4,0x01},//add 20180627
        {0xa5,0x2c},//add 20180627
        {0xa7,0x80},
        {0xa8,0x7d},
        {0xa9,0x18},
        {0xaa,0x15},
        {0xab,0x18},
        {0xae,0x80},
        {0xc8,0x0d},
        {0xc9,0x14},
        {0xd3,0x09},
        {0xd4,0x24},
    
        {0x51,0x0b},//20180627
        {0x52,0x0e},
        {0x53,0x6e},//20180627
        {0x54,0x62},
        {0x57,0x86},//20180627
        {0x58,0x2d},//20180627
        {0x5a,0x16},
        {0x5C,0x20},    
    
        {0xb0,0x78},
        {0xb1,0xe0},
        {0xb2,0xd0},
        {0xb3,0x30},
        {0xEe,0x3C},
        {0x56,0x88},
        {0x55,0x8c},
        {0xbd,0x3f},//20190314


};

static struct regval_tab Bf20a2_id[] = {
	{0xfc, 0x20},
	{0xfd, 0xa2},
};
static struct regval_tab Bf20a2_vts[] = {0
};

static struct regval_tab Bf20a2_stream_on[] = {0
};
static struct regval_tab Bf20a2_stream_off[] = {0
};
static struct regval_tab Bf20a2_expo[] = {0
};
static struct regval_tab Bf20a2_gain[] = {0
};
static struct regval_tab Bf20a2_vflip[] = {0
};
static struct regval_tab Bf20a2_hflip[] = {0
};

static struct crane_sensor_i2c_attr Bf20a2_i2c_attr[] = {
	{
		I2C_8BIT,
		I2C_8BIT,
		0x6e,
	}
};

static struct crane_sensor_module Bf20a2_MODULE_INFO[] = {
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

static struct crane_sensor_resolution Bf20a2_resolution[] = {
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
			Bf20a2_init_raw8_spi2lan_crc_sdr,
			ARRAY_SIZE(Bf20a2_init_raw8_spi2lan_crc_sdr),
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
			Bf20a2_init_yuv422_spi2lan_crc_sdr,
			ARRAY_SIZE(Bf20a2_init_yuv422_spi2lan_crc_sdr),
		},
	},
};

int Bf20a2_get_pixelclock(uint_32 *rate, uint_32 mclk)
{
	return 0;
}
int Bf20a2_get_dphy_desc(struct csi_dphy_desc *dphy_desc, uint_32 mclk)
{
	return 0;
}
int Bf20a2_update_otp(struct crane_sensor_otp *opt)
{
	return 0;
}


int Bf20a2_ata_open(struct crane_sensor_ata *ata)
{
	int ret = 0;
	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)Bf20a2_i2c_attr;
//	fatal_printf("Bf20a2_ata_open ata value is  %d!\n", ata->on);
	if(ata->on){
		
		//fatal_printf("Bf20a2_ata_open open ata\n");
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb6,0x80);
	}else {
			//fatal_printf("Bf20a2_ata_open close ata\n");	
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb6,0x00);
	}
	return ret;
}


int Bf20a2_update_aec(struct crane_sensor_aec *aec)
{
	int ret = 0;
//	uint_32 val1,val2,val3 = 0;
/*
	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)Bf20a2_i2c_attr;

//	CAMLOGI("Bf20a2_update_aec: exp= 0x%x 0x%x! gain =0x%x",aec->exp_high,aec->exp_low,aec->gain);
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


int Bf20a2_s_power(int on)
{
	CAMLOGI("Bf20a2_s_power: value = %d", on);
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
		camera_ldo_cfg(POWER_ON,CAMERA_IOVDD,CAM_VDD_1V80);// IO 口线先上电
		msleep(1);
		camera_ldo_cfg(POWER_ON,CAMERA_AVDD,CAM_VDD_2V80);// AVDD 电源上电
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

struct crane_sensor_spec_ops Bf20a2_ops = {
	Bf20a2_get_pixelclock,
	Bf20a2_get_dphy_desc,
	Bf20a2_update_otp,
	Bf20a2_s_power,
	Bf20a2_ata_open,
	Bf20a2_update_aec,
};

struct crane_sensor_data crane_bf20a2_spi = {
	"Bf20a2_spi",
	&Bf20a2_ops,
	CAMERA_BACK,
	Bf20a2_i2c_attr,
	ARRAY_SIZE(Bf20a2_i2c_attr),
	{
		Bf20a2_id,
		ARRAY_SIZE(Bf20a2_id),
	},
	NULL,
	0,
	Bf20a2_resolution,
	ARRAY_SIZE(Bf20a2_resolution),
	{
		Bf20a2_stream_on,
		ARRAY_SIZE(Bf20a2_stream_on),
	},
	{
		Bf20a2_stream_off,
		ARRAY_SIZE(Bf20a2_stream_off),
	},
	{
		Bf20a2_expo,
		ARRAY_SIZE(Bf20a2_expo),
	},
	{
		Bf20a2_vts,
		ARRAY_SIZE(Bf20a2_vts),
	},
	{
		Bf20a2_gain,
		ARRAY_SIZE(Bf20a2_gain),
	},
	{
		Bf20a2_hflip,
		ARRAY_SIZE(Bf20a2_hflip),
	},
	{
		Bf20a2_vflip,
		ARRAY_SIZE(Bf20a2_vflip),
	},
	Bf20a2_MODULE_INFO,
	ARRAY_SIZE(Bf20a2_MODULE_INFO),
	Bf20a2_tuning_tab,
	ARRAY_SIZE(Bf20a2_tuning_tab),
	{
		{
			Bf20a2_50hz_banding_tab,
			ARRAY_SIZE(Bf20a2_50hz_banding_tab),
		},
		{
			Bf20a2_60hz_banding_tab,
			ARRAY_SIZE(Bf20a2_60hz_banding_tab),
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

