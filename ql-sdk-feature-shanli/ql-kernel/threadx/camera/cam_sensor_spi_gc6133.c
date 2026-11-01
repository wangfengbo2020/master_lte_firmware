#include "cam_sensor.h"
#include "camera_common_log.h"
#include "cam_asr_isp_tuningtab.h"

#define IMAGE_NORMAL 
//#define IMAGE_H_MIRROR 
//#define IMAGE_V_MIRROR 
//#define IMAGE_HV_MIRROR 

#ifdef IMAGE_NORMAL
#define MIRROR 0x54
#define AD_NUM 0x04
#define BLK_VAL 0x46
#endif

#ifdef IMAGE_H_MIRROR
#define MIRROR 0x55
#define AD_NUM 0x08
#define BLK_VAL 0x46
#endif

#ifdef IMAGE_V_MIRROR
#define MIRROR 0x5e
#define AD_NUM 0x04
#define BLK_VAL 0x30
#endif

#ifdef IMAGE_HV_MIRROR
#define MIRROR 0x5f
#define AD_NUM 0x08
#define BLK_VAL 0x30
#endif




//yuv422 640 * 480 spi 2 lan sdr
static struct regval_tab gc6133_init_yuv422_spi1lan_crc_sdr[] = {


        /////////////////////////////////////////////////////
        //////////////////////   SYS   //////////////////////
        /////////////////////////////////////////////////////
        {0xfe, 0xa0},
        {0xfe, 0xa0},
        {0xfe, 0xa0},
        {0xfa, 0x11},
        {0xfc, 0x00},
		{0xf6, 0x00},
        {0xfc, 0x12}, //clock enable
        {0xfe, 0x00}, //Page select
        
        {0x49, 0x70},  //AWB r gain
        {0x4a, 0x40},  //AWB g gain
        {0x4b, 0x5d},  //AWB b gain
        /////////////////////////////////////////////////////
        ////////////////   ANALOG & CISCTL   ////////////////
        /////////////////////////////////////////////////////
        {0x03, 0x00},
        {0x04, 0xfa},
        {0x01, 0x41}, //hb
        {0x02, 0x12}, //vb
        {0x0f, 0x01},
        {0x0d, 0x30},
        {0x12, 0xc8},
        {0x14, MIRROR}, //dark CFA
        {0x15, 0x32}, //1:sdark 0:ndark
        {0x16, AD_NUM},
        {0x17, 0x19},
        {0x1d, 0xb9},
        {0x1f, 0x35}, //PAD_drv
        {0x7a, 0x00},
        {0x7b, 0x14},
        {0x7d, 0x36},
        {0xfe, 0x10}, //cisctl rst [4]

		{0xfe, 0x00},
		{0xfe, 0x00},
		{0xfe, 0x00},
		{0xfe, 0x00},
		{0xfe, 0x00},
		{0xfe, 0x10},  //add by 20160217 CISCTL rst [4]
        /////////////////////////////////////////////////////
        //////////////////////   ISP   //////////////////////
        /////////////////////////////////////////////////////
        {0x20, 0x7e},
        {0x22, 0xb8},
        //{0x24, 0x54}, //output_format
        {0xfe, 0x00},
		{0x39, 0x02}, 
		{0x3a, 0x80}, 
		{0x26, 0xa7}, //0x87
        /////////////////////////////////////////////////////
        //////////////////////   BLK   //////////////////////
        /////////////////////////////////////////////////////
        {0x2a, 0x2f},
        {0x37, BLK_VAL}, //[4:0]blk_select_row
    
        /////////////////////////////////////////////////////
        //////////////////////   GAIN   /////////////////////
        /////////////////////////////////////////////////////
        {0x3f, 0x18}, //global gain 20160901
    
        /////////////////////////////////////////////////////
        //////////////////////   DNDD   /////////////////////
        /////////////////////////////////////////////////////
        {0x50, 0x3c}, 
        {0x52, 0x4f}, 
        {0x53, 0x81},
        {0x54, 0x43},
        {0x56, 0x78}, 
        {0x57, 0xaa},//20160901 
        {0x58, 0xff},//20160901
    
        /////////////////////////////////////////////////////
        //////////////////////   ASDE   /////////////////////
        /////////////////////////////////////////////////////
        {0x5b, 0x60}, //dd&ee th
        {0x5c, 0x80}, //60/OT_th
        {0xab, 0x28}, 
        {0xac, 0xb5},
    
        /////////////////////////////////////////////////////
        /////////////////////   INTPEE   ////////////////////
        /////////////////////////////////////////////////////
        {0x60, 0x45},
        {0x62, 0x68}, //20160901
        {0x63, 0x13}, //edge effect
        {0x64, 0x43},
        /////////////////////////////////////////////////////
        //////////////////////   CC   ///////////////////////
        /////////////////////////////////////////////////////
        {0x65, 0x13}, //Y
        {0x66, 0x26},
        {0x67, 0x07},
        {0x68, 0xf5}, //Cb
        {0x69, 0xea},
        {0x6a, 0x21},
        {0x6b, 0x21}, //Cr
        {0x6c, 0xe4},
        {0x6d, 0xfb},
    
        /////////////////////////////////////////////////////
        //////////////////////   YCP   //////////////////////
        /////////////////////////////////////////////////////
        {0x81, 0x30}, //cb
        {0x82, 0x30}, //cr
        {0x83, 0x4a}, //luma contrast
        {0x85, 0x06}, //luma offset
        {0x8d, 0x78}, //edge dec sa
        {0x8e, 0x25}, //autogray
    
        /////////////////////////////////////////////////////
        //////////////////////   AEC   //////////////////////
        /////////////////////////////////////////////////////
        {0x90, 0x38},//20160901
        {0x92, 0x50}, //target
        {0x9d, 0x32}, //flicker step
        {0x9e, 0x61}, //[7:4]margin
        {0x9f, 0xf4}, //exp_level 3f2
        {0xa3, 0x28}, //pregain
        {0xa4, 0x01}, 
    
        /////////////////////////////////////////////////////
        //////////////////////   AWB   //////////////////////
        /////////////////////////////////////////////////////
#if 0//AWB2
        {0xb0, 0xf2}, //Y_to_C_diff
        {0xb1, 0x10}, //Y_to_C_diff
        {0xb2, 0x08}, //AWB_Y_to_C_diff_big
        {0xb3, 0x30}, //C_max   //20
        {0xb4, 0x40}, 
        {0xb5, 0x20}, //inter
        {0xb6, 0x34}, //inter2
        {0xb7, 0x48}, //AWB_C_inter3     18
        {0xba, 0x40},   // big c  20
        {0xbb, 0x71}, //62//AWB adjust   72
        {0xbd, 0x7a}, //R_limit  80
        {0xbe, 0x40}, //G_limit   58
        {0xbf, 0x80}, //B_limit    a0   
#else	
        {0xb1, 0x1e}, //Y_to_C_diff
        {0xb3, 0x20}, //C_max
        {0xbd, 0x70}, //R_limit
        {0xbe, 0x58}, //G_limit
        {0xbf, 0xa0}, //B_limit
    
        {0xfe, 0x00},//20160901 update for awb
        {0x43, 0xa8}, 
        {0xb0, 0xf2}, 
        {0xb5, 0x40}, 
        {0xb8, 0x05}, 
        {0xba, 0x60},       
#endif
    	{0xbb, 0x62},
		{0xbd, 0x78}, 
		{0xbe, 0x55},
		{0xbf, 0xa0}, 
	
		{0x22, 0xf8}, 
    /////////////////////////////////////////////////
        /////////////////////////////////////////////////////
        //////////////////////   SPI   //////////////////////
        /////////////////////////////////////////////////////
        {0xfe, 0x02},
        {0x01, 0x01}, //SPI MASTER enable
        {0x02, 0x82}, //ddr_mode
        {0x03, 0xa0},  		//one wire
        //SYNC code
    	{0x20, 0x01},//{0x20, 0xb6},		 //frame_start -- not need
		{0x21, 0x02}, //{0x21, 0x80},		 //line sync start
		{0x22, 0x40}, //{0x22, 0x9d},		//line sync end
		{0x23, 0x00}, //{0x23, 0xb6},		//frame end
		{0x25, 0xff},		 //head sync code
		{0x26, 0xff},//{0x26, 0x00},
		{0x27, 0xff},//{0x27, 0x00},
		
        {0x04, 0x20},  //[4] master_outformat
        //{0x09, 0x00},  
        {0x0a, 0x00},  //Data ID, 0x00-YUV422, 0x01-RGB565
        {0x13, 0x10},
    
        //{0x03, 0xA0},  //one wire CRC
        {0x24, 0x00},  //[1]sck_always [0]BT656
    
        {0x28, 0x03}, //clock_div_spi
    
        {0xfe, 0x00},
        //////////////////////////////////////////
        //////////////////////output////////////////
        /////////////////////////////////////////
        {0xf1, 0x03}, //output enable
        {0xfe, 0x00},
		{0xff, 0xff}
};


static struct regval_tab GC6133_id[] = {
    {0xf0, 0xba},
};



static struct regval_tab GC6133_vts[] = {
    {0x00, 0x00},
};


static struct regval_tab GC6133_stream_on[] = {
    {0xfe, 0x02},
    {0x01, 0x01},
};


static struct regval_tab GC6133_stream_off[] = {
    {0xfe, 0x02},
    {0x01, 0x00},
};



static struct regval_tab GC6133_expo[] = {
    {0xfe, 0x00},    //page select
    {0x03, 0x00},    //exp_high
    {0x04, 0x10},    //exp_low
};


static struct regval_tab GC6133_gain[] = {
    {0xfe, 0x00},    //page select
    {0x40, 0x20},    //gain
};




static struct regval_tab GC6133_vflip[] = {
    {0x00, 0x00},
};
static struct regval_tab GC6133_hflip[] = {
    {0x00, 0x00},
};



static struct crane_sensor_i2c_attr GC6133_i2c_attr[] = {
    {
        I2C_8BIT,
        I2C_8BIT,
        0x40,  //0x80
    }
};



static struct crane_sensor_module GC6133_MODULE_INFO[] = {
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




static struct crane_sensor_resolution GC6133_resolution[] = {
    {
        SENSOR_FMT_YUV422,
        MEDIA_BUS_FMT_YVYU8_2X8,
        240,
        320,
        0x0708,
        0x0d06,
        30,
        15,
        SENSOR_RES_BINING1,
        {
            gc6133_init_yuv422_spi1lan_crc_sdr,
            ARRAY_SIZE(gc6133_init_yuv422_spi1lan_crc_sdr),
        },
    },
};

int GC6133_get_pixelclock(uint_32 *rate, uint_32 mclk)
{
    return 0;
}
int GC6133_get_dphy_desc(struct csi_dphy_desc *dphy_desc, uint_32 mclk)
{
    return 0;
}
int GC6133_update_otp(struct crane_sensor_otp *opt)
{
    return 0;
}
int GC6133_ata_open(struct crane_sensor_ata *ata)
{
    return 0;
}
int GC6133_update_aec(struct crane_sensor_aec *aec)
{
    int ret = 0;

    struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)GC6133_i2c_attr;


    return ret;
}

int GC6133_s_power(int on)
{
	CAMLOGI("GC6133_s_power: %s CONFIG_CAM_HW_VERSION=0x%x", on?"on":"off",CONFIG_CAM_HW_VERSION);

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




struct crane_sensor_spec_ops GC6133_ops = {
    GC6133_get_pixelclock,
    GC6133_get_dphy_desc,
    GC6133_update_otp,
    GC6133_s_power,
    GC6133_ata_open,
    GC6133_update_aec,
};

struct crane_sensor_data crane_GC6133_spi = {
    "gc6133_spi",
    &GC6133_ops,
    CAMERA_BACK,
    GC6133_i2c_attr,
    ARRAY_SIZE(GC6133_i2c_attr),
    {
        GC6133_id,
        ARRAY_SIZE(GC6133_id),
    },
    NULL,
    0,
    GC6133_resolution,
    ARRAY_SIZE(GC6133_resolution),
    {
        GC6133_stream_on,
        ARRAY_SIZE(GC6133_stream_on),
    },
    {
        GC6133_stream_off,
        ARRAY_SIZE(GC6133_stream_off),
    },
    {
        GC6133_expo,
        ARRAY_SIZE(GC6133_expo),
    },
    {
        GC6133_vts,
        ARRAY_SIZE(GC6133_vts),
    },
    {
        GC6133_gain,
        ARRAY_SIZE(GC6133_gain),
    },
    {
        GC6133_hflip,
        ARRAY_SIZE(GC6133_hflip),
    },
    {
        GC6133_vflip,
        ARRAY_SIZE(GC6133_vflip),
    },
    GC6133_MODULE_INFO,
    ARRAY_SIZE(GC6133_MODULE_INFO),
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
    SPI_1_LAN,// .lane_num
    0,  //0x0:sdr  0x1:ddr 
    1,  //0x0:no crc  0x1:crc
    100,//.reset_delay
    0,  //auto set .cur_i2c_index
    0,  //int cur_res_index
};



