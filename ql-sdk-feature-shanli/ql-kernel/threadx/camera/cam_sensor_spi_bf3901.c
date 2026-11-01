#include "cam_sensor.h"
#include "cam_asr_isp_tuningtab.h"
//#include "cam_util.h"

static const struct regval_tab bf3901_init_yuv422_spi2lan_crc_sdr[] = {//1lan
        {0x15 , 0x10}, //Bit[1]: VSYNC option.Bit[0]: HSYNC option.Bit[4]:VCLK reverse
            {0x3a , 0x00},//YUV422 Sequence
            {0xbb , 0x21},
            {0x3e , 0x05},
        
            //====== Analog Setting ======
            {0x06 , 0x68},
        
            //====== Black Control ======
            {0x27 , 0x97},
        
            {0x13 , 0x00},
            {0x01 , 0x13},
            {0x02 , 0x20},
            {0x87 , 0x16},
            {0x8c , 0x01},
            {0x8d , 0xcc},
            {0x13 , 0x07},
        
            //====== Lens Shading =======
            {0x33 , 0x10},//value of lens shading auto offset{ black_aver)
            {0x34 , 0x1d},//value of lens shading manul offset
            {0x35 , 0x46},//lens shading gain of R
            {0x36 , 0x40},
            {0x37 , 0xa4},//Center Y coordinate LSB for B{vertical center)
            {0x38 , 0x7c},//Center X coordinate LSB for B{horizontal  center)
            {0x65 , 0x46},//lens shading gain of G
            {0x66 , 0x46},//lens shading gain of B
            {0x6e , 0x20},//the threshold of GLB_GAIN
            {0x9b , 0xa4},//Center Y coordinate LSB for G{vertical center)
            {0x9c , 0x7c},//Center X coordinate LSB for G{horizontal  center)
            {0xbc , 0x0c},
            {0xbd , 0xa4},//Center Y coordinate LSB for R{vertical center)
            {0xbe , 0x7c},//Center X coordinate LSB for R{horizontal  center)
        
            //====== De-noise =======
            {0x72 , 0x2f},//0x72[7:4]: The bigger, the smaller noise 
            {0x73 , 0x2f},//0x73[7:4]: The bigger, the smaller noise
            {0x74 , 0xa7},//0x74[3:0]: The smaller, the smaller noise
        
            //====== Edge Enhancement =======
            {0x75 , 0x12},//0x75[6:4]: Bright edge enhancement; 0x75[2:0]: Dark edge enhancement
        
            //====== De-noise in Low Light =======
            {0x79 , 0x8d},//0x79[3]: 0: Off, 1: On; 0x79[7:4]: Y_AVER threshold for de-noise
            {0x7a , 0x00},//0x7a[7]: 0: Choose luminance of current pixel for de-noise, 1: Choose Y_AVER
            {0x7e , 0xfa},//0x7e[7],0x7e[3:0]为了防止把黑色物体误判成低光造成黑色物体弱去噪，导致黑色物体噪声较大，0x7e[7]=1打开此功能，[3:0]值越小，黑色物体去噪越强，噪声越小
        
            //====== De-noise for Outdoor =======
            {0x70 , 0x0f},//0x70[7]: 0: Disable De-noise outdoor, 1: Enable De-noise outdoor
            {0x7c , 0x84},//0x7c[7:6]: The smaller, the smaller noise
            {0x7d , 0xba},//0x7d[7:6]: The bigger, the smaller noise
        
            //====== Color Fringe Correction =======
            {0x5b , 0xc2},
            {0x76 , 0x90},
            {0x7b , 0x55},
        
            {0x71 , 0x46},
            {0x77 , 0xdd},
        
            //==AE Gain Line,此小段不允许修改 ==
            {0x13 , 0x0f},//以下为AE gain曲线寄存器
            {0x8a , 0x10},
            {0x8b , 0x20},
            {0x8e , 0x21},
            {0x8f , 0x40},
            {0x94 , 0x41},
            {0x95 , 0x7e},
            {0x96 , 0x7f},
            {0x97 , 0xf3},
        
            //====== AE setting&Used to Modify Y_AVER  ========
            {0x13 , 0x07},
            {0x24 , 0x58},//Bit[6:0]: AE target. 0x51相当于原来的0xa2
            {0x97 , 0x48},//Y target value1 for F light.          
            {0x25 , 0x08},//Bit[7:4]: AE_LOC_INT; Bit[3:0]:AE_LOC_GLB
            {0x94 , 0xb5},//Bit[7:4]: Threshold for over exposure pixels, the smaller, the more over exposure pixels; Bit[3:0]: Control the start of AE.
            {0x95 , 0xc0},//modify the Y_AVER
            {0x80 , 0xf6},//Bit[3:2]: the bigger, Y_AVER_MODIFY is smaller
            {0x81 , 0xe0},//AE speed
        
            //====== Default Frame ======              
            {0x82 , 0x1b},//GLB_MIN1:minimum global gain
            {0x83 , 0x37},//GLB_MAX1
            {0x84 , 0x39},//GLB_MIN2
            {0x85 , 0x58},//GLB_MAX2
        
            /*//====== Frame Faster1 ======
            {0x82 , 0x25},
            {0x83 , 0x4a},
            {0x84 , 0x50},
            {0x85 , 0x5d},
        
            //====== Frame Faster2 ======
            {0x82 , 0x30},
            {0x83 , 0x55},
            {0x84 , 0x50},
            {0x85 , 0x6c},*/
        
            {0x86 , 0x77},//GLB_MAX3:maximum global gain
            {0x89 , 0x54},//INT_MAX_MID//76
            {0x8a , 0x5c},//50HZ Banding Filter step
            {0x8b , 0x4c},//60HZ Banding Filter step
            {0x98 , 0x1a},//AE window
            //====== Gamma Offset ======
            {0x39 , 0x98},
            {0x3f , 0x98},//bit[7]control 低光自适应 on/off,default on;
        
            //===Auto Offset in High & Low Light Scene=== 
            {0x90 , 0xa0},//Bit[6:0]: Int_time threshold for auto offset in high light scene
            {0x91 , 0xe0},//Bit[6:0]: Y_aver threshold for auto offset in low light scene
            //{0x90[7],0x91[7]}=01: offset is small, 1x: offset is bigger than 01, 00: offset is the biggest
        
            //====== Gamma Setting1 过爆过渡好======
            {0x40 , 0x20},
            {0x41 , 0x28},
            {0x42 , 0x26},
            {0x43 , 0x25},
            {0x44 , 0x1f},
            {0x45 , 0x1a},
            {0x46 , 0x16},
            {0x47 , 0x12},
            {0x48 , 0x0f},
            {0x49 , 0x0d},
            {0x4b , 0x0b},
            {0x4c , 0x0a},
            {0x4e , 0x08},
            {0x4f , 0x06},
            {0x50 , 0x06},
        
            /*//====== Gamma Setting2 噪声稍小======
            {0x40 , 0x1c},
            {0x41 , 0x27},
            {0x42 , 0x25},
            {0x43 , 0x23},
            {0x44 , 0x20},
            {0x45 , 0x18},
            {0x46 , 0x16},
            {0x47 , 0x13},
            {0x48 , 0x0f},
            {0x49 , 0x0c},
            {0x4b , 0x0b},
            {0x4c , 0x0a},
            {0x4e , 0x08},
            {0x4f , 0x08},
            {0x50 , 0x06},
        
            //====== Gamma Setting3 噪声小======
            {0x40, 0x18},
            {0x41, 0x25},
            {0x42, 0x22},
            {0x43, 0x1f},
            {0x44, 0x1c},
            {0x45, 0x1a},
            {0x46, 0x17},
            {0x47, 0x15},
            {0x48, 0x11},
            {0x49, 0x0e},
            {0x4b, 0x0b},
            {0x4c, 0x0a},
            {0x4e, 0x09},
            {0x4f, 0x08},
            {0x50, 0x06},
        
            //====== Gamma Setting4 清晰亮丽======
            {0x40, 0x1E},
            {0x41, 0x2f},
            {0x42, 0x2B},
            {0x43, 0x25},
            {0x44, 0x21},
            {0x45, 0x1d},
            {0x46, 0x16},
            {0x47, 0x12},
            {0x48, 0x0E},
            {0x49, 0x0a},
            {0x4b, 0x09},
            {0x4c, 0x08},
            {0x4e, 0x07},
            {0x4f, 0x06},
            {0x50, 0x06},*/       
        
            //==绿色植物效果好 for Outdoor Scene==
            {0x5a, 0x56},
            {0x51, 0x12},
            {0x52, 0x0d},
            {0x53, 0x92},
            {0x54, 0x7d},
            {0x57, 0x97},
            {0x58, 0x43},
        
            /*  
            //== Color Coefficient 1 for Outdoor Scene==
            {0x5a , 0x56},//测试盒上效果兼顾
            {0x51 , 0x1b},
            {0x52 , 0x04},
            {0x53 , 0x4a},
            {0x54 , 0x26},
            {0x57 , 0x75},
            {0x58 , 0x2b},
        
            //== Color Coefficient 2 for Outdoor Scene==
            {0x5a, 0x56},
            {0x51, 0x21},
            {0x52, 0x12},
            {0x53, 0x52},
            {0x54, 0x45},
            {0x57, 0x7f},
            {0x58, 0x35},   */
        
            //== Color Coefficient  for Indoor Scene==20122522
            {0x5a, 0xd6},
            {0x51, 0x21},
            {0x52, 0x1c},
            {0x53, 0x9a},
            {0x54, 0x6e},
            {0x57, 0x5c},
            {0x58, 0x14},
            
            /*//肤色和照其它物体彩色还比较好
            {0x5a, 0xd6},
            {0x51, 0x1f},
            {0x52, 0x0f},
            {0x53, 0x47},
            {0x54, 0x20},
            {0x57, 0x2f},
            {0x58, 0x24},
            
            //肤色好
            {0x5a, 0xd6},
            {0x51, 0x06},
            {0x52, 0x09},
            {0x53, 0x29},
            {0x54, 0x1d},
            {0x57, 0x18},
            {0x58, 0x03},
            
            //色彩艳丽   20120522
            {0x5a, 0xd6},
            {0x51, 0x20},
            {0x52, 0x2b},
            {0x53, 0x95},
            {0x54, 0x80},
            {0x57, 0x77},
            {0x58, 0x0d},*/
        
            //===== Color Saturation ======
            {0x5c, 0x28},//the smaller, the smaller color noise in low light scene
            {0xb0, 0xe0},//Saturation control. When bit[7]=1, the smaller, the smaller color noise in low light scene
            {0xb1, 0xc0},//Blue Coefficient
            {0xb2, 0xb0},//Red Coefficient
            {0xb3, 0x4f},
            {0xb4, 0x63},//Bit[6:5]: Gray region De-noise, 00: don't do de-noise; 11: the noise is smaller than 00; 01: depends on 0xb3[3:0], 0xb3[3:0] the smaller, the noise is smaller.
        
            //=====  A light Color Saturation =====
            {0xb4, 0xe3},
            {0xb1, 0xf0},
            {0xb2, 0xa0},
        
            //===== Contrast & Brightness ======
            {0x55, 0x00},
            {0x56, 0x40},
        
            //====== AWB Setting =======
            {0x96, 0x50},//outdoor brightness condition
            {0x9a, 0x30},//outdoor integration time condition
            {0x6a, 0x81},
            {0x23, 0x33},//GreenGain
            {0xa0, 0xd0},
            {0xa1, 0x31},//Bit[3:0]: AWB update speed, the smaller, the faster
            {0xa6, 0x04},
            {0xa2, 0x0f},//the low limit of blue gain for indoor scene
            {0xa3, 0x2b},//the upper limit of blue gain for indoor scene
            {0xa4, 0x0f},//the low limit of red gain for indoor scene
            {0xa5, 0x2b},//the upper limit of red gain for indoor scene
            {0xa7, 0x9a},//Base B gain不建议修改
            {0xa8, 0x1c},//Base R gain不建议修改
            {0xa9, 0x11},
            {0xaa, 0x16},
            {0xab, 0x16},
            {0xac, 0x3c},
            {0xad, 0xf0},
            {0xae, 0x57},
            {0xc6, 0xaa},//Pure color threshold
            {0xd2, 0x78},//bit[5]control indoor or outdoor on/off,default on;
            {0xd0, 0xb4},//F light offset
            {0xd1, 0x00},//Non-F light offset
        
            {0xc8, 0x10},//the low limit of blue gain for outdoor scene
            {0xc9, 0x12},//the upper limit of blue gain for outdoor scene
            {0xd3, 0x09},//the low limit of red gain for outdoor scene
            {0xd4, 0x2a},//the upper limit of red gain for outdoor scene
        
            {0xee, 0x4c},
        
            //====== Black Sun Correction =======   20120522
            {0x7e, 0xba},//Bit[6]: 1: Enable black sun correction, 0: Disable black sun correction
            
            //如果要去掉black sun，请将此段代码打开 20120522
            /*{0x7e, 0xfa},
            {0x74, 0xa7},
            {0x78, 0x4e},
            {0x60, 0xe5},
            {0x61, 0xc8},
            {0x6d, 0x70},
            {0x1e, 0x08},
            {0x16, 0xaf},*/
        
            {0x2b , 0x20},//Dummy Pixel Insert LSB     
        
            {0x1b, 0x06},//PLL setting
            {0x11, 0x30},//Mclk_div control 0x90-divided by 2;0xb0-divided by 4;0x30:divided by 8;
            {0x6b, 0x42},
            {0x62, 0x81},//bit[1:0] 01:output spi mode;10:output 2 bit mode;11:output 4 bit mode
            {0x12, 0x00},
            {0x08, 0xa0},   //bit[7]:serial mode select for vclk(0:nomal;1:serial mode)
                
            //===== Drive Capability======
            {0x20 , 0x09},//bit[6]:0-same drive capability 1-drive capability independently
            {0x09 , 0x02},//bit[4]:1-soft sleep mode
        
            //====== Switch Direction =======   
            {0x1e , 0x09},//09: Normal  19: IMAGE_V_MIRROR   29: IMAGE_H_MIRROR  39: IMAGE_HV_MIRROR



};

static struct regval_tab bf3901_id[] = {
	{0xfc, 0x39},
	{0xfd, 0x01},
};
	
static struct regval_tab bf3901_vts[] = {
	{0x00, 0x00},
};

static struct regval_tab bf3901_stream_on[] = {
	{0xfe, 0x03},
	{0x51, 0x01},
};
static struct regval_tab bf3901_stream_off[] = {
	
	{0xfe, 0x03},
	{0x51, 0x00},
};
static struct regval_tab bf3901_expo[] = {
	
	{0xfe, 0x00},    //page select
	{0x03, 0x01},    //exp_high
	{0x04, 0x00},    //exp_low
};
static struct regval_tab bf3901_gain[] = {
	
	{0xfe, 0x00},    //page select
	{0x48, 0x01},    //gain
};
static struct regval_tab bf3901_vflip[] = {
	
	{0x00, 0x00},
};
static struct regval_tab bf3901_hflip[] = {
	
	{0x00, 0x00},
};

static struct crane_sensor_i2c_attr bf3901_i2c_attr[] = {
	{
		I2C_8BIT,
		I2C_8BIT,
		0x6e,
	}
};

static struct crane_sensor_module bf3901_MODULE_INFO[] = {
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

static struct crane_sensor_resolution bf3901_resolution[] = {
	{
		SENSOR_FMT_YUV422,
		// Lisiqiang 20190827 +++
		#if 1 
		MEDIA_BUS_FMT_YVYU8_2X8,  
		#else 
		MEDIA_BUS_FMT_YUYV8_2X8,
		#endif // 
		// Lisiqiang20190827 --- 
		240,
		320, 
		0x0708,
		0x0d06,
		30,
		15,
		SENSOR_RES_BINING1,
		{
			bf3901_init_yuv422_spi2lan_crc_sdr,
			ARRAY_SIZE(bf3901_init_yuv422_spi2lan_crc_sdr),
		},
	},
};

int bf3901_get_pixelclock(uint32_t *rate, uint32_t mclk)
{
	return 0;
}
int bf3901_get_dphy_desc(struct csi_dphy_desc *dphy_desc, uint32_t mclk)
{
	return 0;
}

int bf3901_update_otp(struct crane_sensor_otp *opt)
{
	return 0;
}

int bf3901_ata_open(struct crane_sensor_ata *ata)
{
	int ret = 0;
	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)bf3901_i2c_attr;
	CAMLOGE("bf3901_ata_open ata value is  %d!\n", ata->on);
	if(ata->on){
		
		CAMLOGE("bf3901_ata_open open ata\n");
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb9,0x80);
	} else {
			CAMLOGE("bf3901_ata_open close ata\n");	
		//ret = crane_i2c_write_single(i2c_attr, 0xfe,0x00);
		ret = crane_i2c_write_single(i2c_attr, 0xb9,0x00);
	}
	return ret;
}


int bf3901_update_aec(struct crane_sensor_aec *aec)
{
	int ret = 0;
//	uint32_t val1,val2,val3 = 0;
/*
	struct crane_sensor_i2c_attr *i2c_attr = (struct crane_sensor_i2c_attr *)bf3901_i2c_attr;

//	CAMLOGV"bf3901_update_aec: exp= 0x%x 0x%x! gain =0x%x",aec->exp_high,aec->exp_low,aec->gain);
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


static int bf3901_s_power(int on)
{
	CAMLOGI("bf3901_s_power: %s CONFIG_CAM_HW_VERSION=0x%x", on?"on":"off",CONFIG_CAM_HW_VERSION);
    gpio_direction_output(CAMERA_PWDN1);
    gpio_set_value(CAMERA_PWDN1, 0);
    
    if (on > 0) 
	{
        gpio_set_value(CAMERA_PWDN1, 0);
        msleep(2);
        camera_ldo_cfg(POWER_OFF,CAMERA_AVDD,CAM_VDD_2V80);
        msleep(2);
        camera_ldo_cfg(POWER_OFF,CAMERA_IOVDD,CAM_VDD_1V80);
        msleep(2);

        disable_MCLK();
        UOS_Sleep(1); //delay 5ms
        camera_ldo_cfg(POWER_ON,CAMERA_IOVDD,CAM_VDD_1V80);// IO 鍙ｇ嚎鍏堜笂鐢?
        msleep(1);
        camera_ldo_cfg(POWER_ON,CAMERA_AVDD,CAM_VDD_2V80);// AVDD 鐢垫簮涓婄數
        msleep(1);
        enable_MCLK();
        msleep(1);
        gpio_set_value(CAMERA_PWDN1, 1);
        msleep(2);
        gpio_set_value(CAMERA_PWDN1, 0);
        msleep(2);

    } 
	else 
	{
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

struct crane_sensor_spec_ops bf3901_ops = {
	bf3901_get_pixelclock,
	bf3901_get_dphy_desc,
	bf3901_update_otp,
	bf3901_s_power,
	bf3901_ata_open,
	bf3901_update_aec,
};

struct crane_sensor_data crane_bf3901_spi = {
	"bf3901_spi",
	&bf3901_ops,
	CAMERA_BACK,
	bf3901_i2c_attr,
	ARRAY_SIZE(bf3901_i2c_attr),
	{
		bf3901_id,
		ARRAY_SIZE(bf3901_id),
	},
	NULL,
	0,
	bf3901_resolution,
	ARRAY_SIZE(bf3901_resolution),
	{
		bf3901_stream_on,
		ARRAY_SIZE(bf3901_stream_on),
	},
	{
		bf3901_stream_off,
		ARRAY_SIZE(bf3901_stream_off),
	},
	{
		bf3901_expo,
		ARRAY_SIZE(bf3901_expo),
	},
	{
		bf3901_vts,
		ARRAY_SIZE(bf3901_vts),
	},
	{
		bf3901_gain,
		ARRAY_SIZE(bf3901_gain),
	},
	{
		bf3901_hflip,
		ARRAY_SIZE(bf3901_hflip),
	},
	{
		bf3901_vflip,
		ARRAY_SIZE(bf3901_vflip),
	},
	bf3901_MODULE_INFO,
	ARRAY_SIZE(bf3901_MODULE_INFO),
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
	0,  //0x0:sdr   0x1:ddr spi_sdr
	1,  //0x0:no crc   0x1:crc,.spi_crc
	100,//.reset_delay
	0,  //auto set .cur_i2c_index
	0, //int cur_res_index
};

