/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/



/**********************************************************************
 *
 * Filename: wb_modem_features.h
 *
 * Programmer: Oren Fogel
 *
 * Description: 
 *	Define the Enabled Modem Features.
 *	
 *
 * Methodology:
 *	Add the new supported features.L1 should use those labels in order to activate the corresponding features. 
 *
 * --------------------------------------------------------------------
 * Revision History
 *
 * Date         Who        Version           Description
 * --------------------------------------------------------------------
 * 23-03-2011  dekelg        0.01              File Created
 **********************************************************************/
#ifndef WB_MODEM_FEATURES_H
#define WB_MODEM_FEATURES_H             
#define L1_FEATURE_DETECTED_INLCUDE_RRC 1
// CQ00080062 start
#define L1_FEATURE_INTRA_MEAS_IND_SERVING_ONLY 1 
// CQ00080062 end
#define L1_FEATURE_TX_POWER_IND_UPDATE         1
#define L1_FEATURE_BAND_SCAN 1
#define L1_FEATURE_BSIC_AND_BCCH_DECODE 1
#define L1_FEATURE_DETECTED_LONG_BG 1
#define L1_FEATURE_INTRA_TM_CELLS_INDICATION 1
#define L1_FEATURE_COMB_TR_AND_PHY_CH 1
//CQ00065169 start
#define L1_FEATURE_BEC_BOOST_THRESHOLD 1 
//CQ00065169 end
#define L1_UPGRADE_UL16QAM  1
#endif /* WB_MODEM_FEATURES_H */
