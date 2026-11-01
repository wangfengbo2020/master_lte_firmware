/**********************************************************************************
* Copy right:    2012-2014, Marvell Tech Ltd.
* File name:     WbCapability.h
* Description:    WB L1 capability and constraint definition
* History:        04/03/2013    Originated by Liu Shi
**********************************************************************************/

#ifndef _WB_CAPABILITY_H
#define _WB_CAPABILITY_H


////////////////////////////////////////////////////////////////////////
// General feature
////////////////////////////////////////////////////////////////////////

// Access stratum release indicator
#define  WB_RELEASE_INDICATOR					9

// DL MIMO supported or not
#define  WB_DL_MIMO_SUPPORTED					0

// UL DC supported or not
#define  WB_UL_DC_SUPPORTED						0


////////////////////////////////////////////////////////////////////////
// Downlink capability
////////////////////////////////////////////////////////////////////////
//----------------------------
// radio links
//----------------------------
// maximum number of radio links
#define	 WB_MAX_DCH_RL_NUM						6

// maximum number of E-DCH radio links
#define	 WB_MAX_EDCH_RL_NUM						4

// maximum number of cell index can be allocated for channels except of NC BCH
#define	 WB_MAX_CELL_EXCEPT_NC_BCH				8

// maximum number of radio links including NC BCH
#if WB_UL_DC_SUPPORTED
#define	 WB_MAX_RL_NUM							(2*WB_MAX_EDCH_RL_NUM+1)
#else
#define	 WB_MAX_RL_NUM							(WB_MAX_DCH_RL_NUM+2)
#endif

// DL DPCH window scope in chips
// UE supports to receive, demodulate and combine the signal of DL DPCH (or FDPCH) only if 
// the receive timing is within a window of [-148 +148] chips. where the 148 is from 25.133
// Note: the scope can be a little bit larger due to the UE capability
#define  WB_DL_DPCH_WIN_SCOPE					148

//----------------------------
// number of path
//----------------------------
// maximum number of paths per cell
#define  WB_MAX_PATH_NUM_PER_CELL				4

// maximum  paths for DPCH
#define	 WB_MAX_PATH_NUM_DPCH					8



//----------------------------
// HS-DSCH category
//----------------------------
// HS-DSCH catergory for MAC-hs for single cell  and the corresponding IR buffer size
#define  WB_HS_DSCH_CATEGORY_MAC_HS				10
#define  WB_TOTAL_IR_BUF_SIZE_MAC_HS			172800

// HS-DSCH catergory extension for MAC-ehs for single cell  and the corresponding IR buffer size
#define  WB_HS_DSCH_CATEGORY_EXT_MAC_EHS		14
#define  WB_TOTAL_IR_BUF_SIZE_MAC_EHS			259200

// HS-DSCH catergory extesion2 for dual cell and the corresponding IR buffer size
#define  WB_HS_DSCH_CATEGORY_EXT2_DC			24
#define  WB_TOTAL_IR_BUF_SIZE_DC				518400

// HS-DSCH catergory extension3 for dual cell and the corresponding IR buffer size
#define  WB_HS_DSCH_CATEGORY_EXT3_DC_MIMO		28
#define  WB_TOTAL_IR_BUF_SIZE_DC_MIMO			1036800

// maximum number of HS-PDSCH channel
#define  WB_MAX_HS_PDSCH_CHAN_NUM				15

// maximum HS-DSCH TB size for MAC-hs
#define  WB_MAX_HS_DSCH_TB_SIZE_MAC_HS			27952

// maximum HS-DSCH TB size for MAC-ehs
#define  WB_MAX_HS_DSCH_TB_SIZE_MAC_EHS			42192
//maximum HS-DSCH buffer TB blocks

// maximum processe
#if WB_DL_MIMO_SUPPORTED
#define  WB_MAX_H_PROCESSES_NUM					16
#else
#define  WB_MAX_H_PROCESSES_NUM					8
#endif

//----------------------------
// TrCH (DCH) capabiltity
//----------------------------
// DL maximum number of bits received at aribitratory time instant,  without or with simultaneous HS-PDSCH
#define  WB_MAX_DL_BITS_NUM						6400
#define  WB_MAX_DL_BITS_NUM_WITH_HS_DSCH		3840

// DL maximum number of convolutionally coded bits received at aribitratory time instant
#define  WB_MAX_DL_CONV_BITS_NUM				640

// DL maximum number of turbo coded bits received at aribitratory time instant,  without or with simultaneous HS-PDSCH
#define  WB_MAX_DL_TURBO_BITS_NUM				6400
#define  WB_MAX_DL_TURBO_BITS_NUM_WITH_HS_DSCH	3840

// DL maximum number of simultaneous TrCH
#define  WB_MAX_DL_TRCH_NUM						8

// DL maximum number of CCTrCH
#define  WB_MAX_DL_CCTRCH_NUM					1

// DL maximum number of transport block (TB)
#define  WB_MAX_DL_TB_NUM						32

// DL maximum number of TFC without or with simultaneous HS-PDSCH
#define  WB_MAX_DL_TFC_NUM						128
#define  WB_MAX_DL_TFC_NUM_WITH_HS_DSCH			48

// DL maximum number of TF
#define  WB_MAX_DL_TF_NUM						64

//----------------------------
// PhyCH (PDCH/SCCPCH) capabiltity
//----------------------------
// DL maximum number of DPCH channels (codes)
#define  WB_MAX_DL_DPCH_CHAN_NUM				1

// DL DPCH maximum SF
#define  WB_MAX_DL_DPCH_SF						256

// DL DPCH maximum TTI length (ms)
#define  WB_MAX_DL_DPCH_TTI_LEN					40

//maxHSSCCHs,  10.3.10@ 331
//Maximum number of HSSCCH codes that can be assigned to a UE
#define  WB_MAX_HS_SCCH_NUM						4

// maxHS-SCCHLessTrBlk, 10.3.10@ 331
// Maximum number of HS-DSCH transport blcok sizes used for HS-SCCH-less operation
#define  WB_MAX_HS_SCCH_LESS_TB_SIZE_NUM		4

////////////////////////////////////////////////////////////////////////
// Uplink capability
////////////////////////////////////////////////////////////////////////

//----------------------------
// E-DCH category
//----------------------------
// E-DCH maximum number of bits of an transport block with 10ms and QPSK
#define WB_MAX_EDCH_BITS_NUM_10MS_QPSK			20000

// E-DCH maximum number of bits of an transport block with 2ms and QPSK
#define WB_MAX_EDCH_BITS_NUM_2MS_QPSK			11484

// E-DCH maximum number of bits of an transport block with 2ms and 16QAM
#define WB_MAX_EDCH_BITS_NUM_2MS_16QAM			22996

// E-DCH maximum number of harq process
#define WB_MAX_EDCH_HARQ_NUM_2MS                   8

// E-DCH maximum number of harq process
#define WB_MAX_EDCH_HARQ_NUM_10MS                  4

// E-DCH maximum number of ETFCI
#define WB_MAX_EDCH_ETFCI_NUM                  128 

// E-DCH maximum number of reference ETFCI
#define WB_MAX_EDCH_REF_ETFCI_NUM              8

// E-DCH maximum number of daltaT2TP, 4.2.1.3@213 
#define WB_MAX_EDCH_DELTA_T2TP_NUM             7

// E-DCH maximun number of deltaEdpdch, 4.2.1.3@213
#define WB_MAX_EDCH_DELTA_EDPDCH_NUM           32

// E-DCH maximum number of deltaEdpcch, 4.2.1.3@213
#define WB_MAX_EDCH_DELTA_EDPCCH_NUM           9

// E-DCH maximum number of deltaHarq 4.2.1.3@213
#define WB_MAX_EDCH_DELTA_HARQ_NUM             7

//----------------------------
// TrCH capabiltity
//----------------------------
// UL maximum number of bits received at aribitratory time instant
#define  WB_MAX_UL_BITS_NUM						6400

// UL maximum number of convolutionally coded bits received at aribitratory time instant
#define  WB_MAX_UL_CONV_BITS_NUM				640

// UL maximum number of turbo coded bits received at aribitratory time instant
#define  WB_MAX_UL_TURBO_BITS_NUM				6400

// UL maximum number of simultaneous TrCH
#define  WB_MAX_UL_TRCH_NUM						8

// UL maximum number of CCTrCH
#define  WB_MAX_UL_CCTRCH_NUM					2

// UL maximum number of transport block (TB)
#define  WB_MAX_UL_TB_NUM						16

// UL maximum number of TFC
#define  WB_MAX_UL_TFC_NUM						64

// UL maximum number of TF
#define  WB_MAX_UL_TF_NUM						32

//----------------------------
// PhyCH (PDCH) capabiltity
//----------------------------
// WB UL DPDCH minimum SF index
#define WB_MIN_DPDCH_SF_INDEX					6

// WB UL maximum  DPDCH channels (codes)
#define WB_MAX_DPDCH_CHAN_NUM					1

// WB UL maximum E-DPCCH channels (codes)
#define WB_MAX_EDPDCH_CHAN_NUM					4


////////////////////////////////////////////////////////////////////////
// RF capabiltity
////////////////////////////////////////////////////////////////////////
// UE maximum Tx Power, in dBm, which correspinds to power class 3
#define  WB_UE_MAX_TX_POWER						24

// UE minimum Tx Power, in dBm, TBD
#define  WB_UE_MIN_TX_POWER						(-45)

// number of UE RX antenna
#define  WB_UE_RX_ANT_NUM						2


////////////////////////////////////////////////////////////////////////
// Measurement capability
////////////////////////////////////////////////////////////////////////
//Max number of freq list in FreqScan comd durring WB freq scan period
#define WB_RF_SCAN_MAX_FREQ_NUM							32

//Max number of band list in FreqScan comd durring WB band scan period
#define WB_RF_SCAN_MAX_BAND_NUM							1

//Max number of freq in FreqScan report durring WB freq scan period
#define WB_RF_SCAN_MAX_REPORT_FREQS						110

//Max cell number in PLMN search 
#define WB_PLMN_SEARCH_MAX_CELL_NUM						4

//Max detected cell number in intra measurement 
#define WB_MEAS_MAX_DETECTED_CELL_NUM					10

//Max meas cell number in one freq 
#define WB_MEAS_MAX_CELL_NUM_PER_FREQ					32

//Max meas cell number in one MPS cmd report period
#define WB_MEAS_MAX_MPS_REQ_CELL_NUM				    16

//Max meas cell number in one MPS cmd report period
#define WB_MEAS_MAX_MPS_REPORT_CELL_NUM					4

// Max path number of one cell in cpich search reply
#define WB_MEAS_MAX_MPS_REPORT_PATH_NUM					6

//Max meas freq number in intra meas 
#define WB_MEAS_MAX_INTRA_FREQ_NUM						2

//Max meas freq number in inter meas 
#define WB_MEAS_MAX_INTER_FREQ_NUM						2

//IRAT GSM MEAS DEF
//Max meas GSM FREQ number in WB 
#define WB_MAX_GERAN_ARFCN_NUM							32

//Max meas GSM BSIC cell number in WB
#define WB_MAX_GERAN_BSIC_CELL_NUM						8

//IRAT LTE MEAS DEF
//Max meas LTE freq number in WB irat plmn search
#define WB_MAX_LTE_PLMN_FREQ_NUM						8

//Max meas LTE band number in WB irat plmn search
#define WB_MAX_LTE_PLMN_BAND_NUM						1

//Max meas LTE freq number in WB irat measurement
#define WB_MAX_LTE_MEAS_FREQ_NUM						8

//Max meas LTE cell number per freq in WB irat measurement
#define WB_MAX_LTE_MEAS_CELL_NUM_PER_FREQ				8

////////////////////////////////////////////////////////////////////////
// Initial Cell Search capability
////////////////////////////////////////////////////////////////////////
//support large Freq offset or not. 1: support;		0:not support
#define WB_ICS_AFC_MODE									1

// High and low values of configured parameters (for valid check)
////////////////////////////////////////////////////////////////////////
// high value of rate matching attribute
#define  WB_HIGH_RM_VALIE						256

// low value of rate matching attribute
#define  WB_LOW_RM_VALIE						1

// high value of DL DPCH slot format
#define  WB_HIGH_DL_DPCH_SLOT_FORMAT			16

// low value of DL DPCH slot format
#define  WB_LOW_DL_DPCH_SLOT_FORMAT				2



#endif

