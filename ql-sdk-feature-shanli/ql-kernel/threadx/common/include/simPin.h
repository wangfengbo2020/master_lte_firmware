/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
 *               MODULE IMPLEMENTATION FILE
 *******************************************************************************
 * Filename: simPin.h
 ******************************************************************************/

#ifndef _SIM_PIN_H_
// The SIM PIN code is saved in the special area, which is
//   - non cleared upon the COMM restart
//   - visible by COMM but not visible by the APPS
// COMM "knows" to reset this area on it's "first start of life" but keep it on every Silent-Reset
// ------------
// The PIN code is given as ROW-BYTE-BUFFER with specified byte-lenght.
// The PIN encoding is the caller procedure responsibility!!! The buffer is ROW-DATA for the Platform-Service!!!
// If the given lenght is bigger than AREA, the number of really saved bytes (less than required) would be returned.
// The user must provide the correct LENGHT to be read or saved
//   and should check the Required LEN is equal to returned LENGHT bytes to be sure the operation succeed.
// LEGHT=0 means "no PIN code saved".
// The usimPin_validInside() provided to check-only the PIN is saved or not.

//Modify for LTG_DS PS_Unify
#define SIM_PIN_CODE_SIZE               16
#define DUAL_SIM_PIN_CODE_SIZE          2*SIM_PIN_CODE_SIZE


int  simPin_save(unsigned char* pinBuf, int len, int cardNo);
int  simPin_read(unsigned char* pinBuf, int len, int cardNo);
void simPin_invalidate (int cardNo);
UINT8 *sim_pin_fota_save(void);
void sim_pin_fota_clear(void);



UINT32 NonCacheWrite(void *ptr, UINT32 len, UINT32 offset);
UINT32 NonCacheRead(void *ptr, UINT32 len, UINT32 offset);
#endif  /* _SIM_PIN_H_ */

