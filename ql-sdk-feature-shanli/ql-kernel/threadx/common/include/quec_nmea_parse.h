/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef QUEC_NMEA_PARSE_H_
#define QUEC_NMEA_PARSE_H_
#ifdef __cplusplus 
extern "C" {
#endif

#include <time.h>
#include "quec_hx_gps.h"

#define ARRAY_LENGTH(a) (sizeof a / sizeof (a[0]))
#define NMEA_MIN_LENGTH  (9)
#define NMEA_MAX_LENGTH  (82)


#define KNOTS_CONVERSION_FACTOR         (1.852)
#define GNSS_CMD_MAX_LENGTH  128

#define jmin(a, b) (((a) > (b)) ? (b) : (a))
#define jmax(a, b) (((a) > (b)) ? (a) : (b))

#define NMEA_END_CHAR_1 '\r'
#define NMEA_END_CHAR_2 '\n'


/** Number of item types; unsigned integer. */
typedef unsigned int dsat_num_item_type;

typedef unsigned long long loc_position_valid_mask_type;


typedef enum {
	NMEA_UNKNOWN,
	NMEA_RMC,
    NMEA_GGA,
    NMEA_GSA,
    NMEA_GSV,
    NMEA_VTG,
    NMEA_GLL,
    NMEA_TXT,
    NMEA_GST,
} nmea_type;

typedef enum {
	SAT_UNKNOWN,
	SAT_GPS,	//GP
    SAT_GLONASS,//GL
    SAT_GALILEO,
    SAT_BDS,	//GB
    SAT_MULTISYS,	//GN
    SAT_MAX,	
} satellite_type;

typedef char nmea_cardinal_t;
#define NMEA_CARDINAL_DIR_NORTH		(nmea_cardinal_t) 'N'
#define NMEA_CARDINAL_DIR_EAST		(nmea_cardinal_t) 'E'
#define NMEA_CARDINAL_DIR_SOUTH		(nmea_cardinal_t) 'S'
#define NMEA_CARDINAL_DIR_WEST		(nmea_cardinal_t) 'W'
#define NMEA_CARDINAL_DIR_UNKNOWN	(nmea_cardinal_t) '\0'

#define NMEA_PREFIX_LENGTH          (5)
#define NMEA_TIME_FORMAT	"%H%M%S"
#define NMEA_TIME_FORMAT_LEN	6

#define NMEA_DATE_FORMAT	"%d%m%y"
#define NMEA_DATE_FORMAT_LEN	6

struct nmea_s{
	satellite_type sat_type;
    nmea_type type;
    void *data;
};

/* GPS position struct */
struct nmea_position{
	double minutes;
	int degrees;
	nmea_cardinal_t cardinal;
};

/* nmea rmc packet define */
/* Value indexes */
#define NMEA_GPRMC_TIME			            0
#define NMEA_GPRMC_STATUS                   1
#define NMEA_GPRMC_LATITUDE		            2
#define NMEA_GPRMC_LATITUDE_CARDINAL	    3
#define NMEA_GPRMC_LONGITUDE		        4
#define NMEA_GPRMC_LONGITUDE_CARDINAL	    5
#define NMEA_GPRMC_SPEED		            6
#define NMEA_GPRMC_COURSE                   7
#define NMEA_GPRMC_DATE			            8

struct nmea_gprmc_s{
    /*1: valid, 0: invalid*/
    int valid;
	struct nmea_position longitude;
	struct nmea_position latitude;
    double course;
	double speed;
	struct tm time;
} ;


/* nmea gsv packet define */
#define NMEA_GPGSV_TOTAL_MSGS               0
#define NMEA_GPGSV_MSG_NR                   1
#define NMEA_GPGSV_SATS                     2
#define NMEA_GPGSV_SAT_INFO_NR1             3
#define NMEA_GPGSV_SAT_INFO_ELEV1           4
#define NMEA_GPGSV_SAT_INFO_AZIMUTH1        5
#define NMEA_GPGSV_SAT_INFO_SNR1            6
#define NMEA_GPGSV_SAT_INFO_NR2             7
#define NMEA_GPGSV_SAT_INFO_ELEV2           8
#define NMEA_GPGSV_SAT_INFO_AZIMUTH2        9
#define NMEA_GPGSV_SAT_INFO_SNR2            10
#define NMEA_GPGSV_SAT_INFO_NR3             11
#define NMEA_GPGSV_SAT_INFO_ELEV3           12
#define NMEA_GPGSV_SAT_INFO_AZIMUTH3        13
#define NMEA_GPGSV_SAT_INFO_SNR3            14
#define NMEA_GPGSV_SAT_INFO_NR4             15
#define NMEA_GPGSV_SAT_INFO_ELEV4           16
#define NMEA_GPGSV_SAT_INFO_AZIMUTH4        17
#define NMEA_GPGSV_SAT_INFO_SNR4            18
#define NMEA_GPGSV_SAT_INFO_SIGID           19

struct nmea_sat_info {
    /* PRN */
    int nr;
    /*elevation of satellite*/
    int elevation;
    /*azimuth of satellite*/
    int azimuth;
    /*Signal Noise Ratio*/
    int snr;
};

struct nmea_gpgsv_s {
	int cur_sats;
	int sig_id;
    /*total msg count*/
    int total_msgs;
    /*current msg index*/
    int msg_nr;
    /*total satellite count*/
    int total_sats;
    /*satellites info*/
    struct nmea_sat_info sats[4];
};

/*nmea gga packet define*/
//2,3,4,5,6,7
#define NMEA_GPGGA_UTC  0

#define NMEA_GPGGA_LATITUDE                     1
#define NMEA_GPGGA_LATITUDE_CARDINAL            2
#define NMEA_GPGGA_LONGITUDE                    3
#define NMEA_GPGGA_LONGITUDE_CARDINAL           4
#define NMEA_GPGGA_QUALITY                       5
#define NMEA_GPGGA_SATELLITES_TRACKED           6
#define NMEA_GPGGA_HDOP                         7
#define NMEA_GPGGA_ALTITUDE                     8

struct nmea_gpgga_s{

    struct nmea_position longitude;
	struct nmea_position latitude;
	unsigned char quality;
	unsigned int satellites_tracked;
	double hdop;
	double altitude;
	unsigned int  time;
} ;


/*nmea gsa packet define*/
#define NMEA_GPGSA_MODE                         0
#define NMEA_GPGSA_NAVMODE                      1
#define NMEA_GPGSA_PDOP                         14
#define NMEA_GPGSA_HDOP                         15
#define NMEA_GPGSA_VDOP                         16

struct nmea_gpgsa_s {
	unsigned char mode;
	unsigned char navmode;
	double pdop;
	double hdop;
	double vdop;
};


/*nmea vtg packet define*/
#define NMEA_GPVTG_COGT                         	0
#define NMEA_GPVTG_COGT_CARDINAL                    1
#define NMEA_GPVTG_COGM                         	2
#define NMEA_GPVTG_COGM_CARDINA                     3
#define NMEA_GPVTG_SOG                         		4
#define NMEA_GPVTG_SOG_CARDINA 						5
#define NMEA_GPVTG_KPH                         		6
#define NMEA_GPVTG_KPH_CARDINA						7

struct nmea_gpvtg_s {
	double cogt;
	unsigned char cogt_flag;
	double cogm;
	unsigned char cogm_flag;
	double sog;
	unsigned char sog_flag;
	double kph;
	unsigned char kph_flag;
};


#define NMEA_GPGLL_LATITUDE		            0
#define NMEA_GPGLL_LATITUDE_CARDINAL	    1
#define NMEA_GPGLL_LONGITUDE		        2
#define NMEA_GPGLL_LONGITUDE_CARDINAL	    3
#define NMEA_GPGLL_TIME			            4
#define NMEA_GPGLL_STATUS                   5

struct nmea_gpgll_s {
	int valid;
	struct nmea_position longitude;
	struct nmea_position latitude;
	struct tm time;
	
};

#define NMEA_GPS_SATE                         	0
#define NMEA_GPS_SATE_VALID                     1
#define NMEA_BDS_SATE                         	2
#define NMEA_BDS_SATE_VALID                     3
#define NMEA_GAL_SATE                         	4
#define NMEA_GAL_SATE_VALID 					5
#define NMEA_GLO_SATE                         	6
#define NMEA_GLO_SATE_VALID                     7




#define PDAPI_NMEA_GGA 0x0001
#define PDAPI_NMEA_RMC 0x0002
#define PDAPI_NMEA_GSV 0x0004
#define PDAPI_NMEA_GSA 0x0008
#define PDAPI_NMEA_VTG 0x0010

typedef enum {
	QGPS_START_COLD,
	QGPS_START_HOT,
	QGPS_START_WARM,
	QGPS_START_XTRA
} qgps_start_e_type;

typedef struct
{
   unsigned short        year;
   unsigned char month;
   unsigned char day_of_week;
   unsigned char day;
   unsigned char hour;
   unsigned char minute;
   unsigned char second;
   unsigned short        millisecond;
} loc_calendar_time_s_type;


typedef struct
{
	dsat_num_item_type gnssmode;   // 
	dsat_num_item_type fixmaxtime; //最大超时重�?
	dsat_num_item_type fixmaxdist; // 定位精度
	dsat_num_item_type b_fixcount_flag;
	dsat_num_item_type fixcount;   // count of fs
	dsat_num_item_type fixrate;    //fs  per/s
}quec_gps_config;

typedef struct
{
    char agpsflag;
    char agps_assist_data_valid;
    unsigned long long local_last_time_min;
    char profile_inx;
    char agps_url[100];
    char agpsvendorID[30];
    char agpsmodelID[30];
    char agpspassWord[30];
}quec_agps;

#define GNSS_SYSCONFGE_ENABLE 	(0x01 << 1)
#define GNSS_NMEATYPE_ENABLE 	(0x01 << 2)



/*nmea txt packet define*/
#define NMEA_GNTXT_FWVER                        3
struct nmea_gntxt_s {
	char fwver[32];
};

int quec_gnss_nmea_cnf(void);
int quec_gnss_nmea_parse(char* buf, int len);
struct nmea_s* nmea_parse(char *sentence, int length, int check_checksum);
nmea_type nmea_get_type(const char *sentence);
satellite_type nmea_satellite_check(char *sentence);
int _split_string_by_comma(char *string, char **values, int max_values);




#ifdef __cplusplus 
}
#endif
#endif /* !NMEA_PARSE_H_ */

