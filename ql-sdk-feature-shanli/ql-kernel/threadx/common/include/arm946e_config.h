/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************
 *
 *    DESCRIPTION:
 *
 *    AUTHOR: shirleye
 *
 *    Date Created :12/05/2007
 *
 *    HISTORY:
 *******************************************************************/

#if !defined (ARM946E_CONFIG_H)
#define ARM946E_CONFIG_H


 /* CORE mini switchs for TTC mega switch */
#if defined(SILICON_TTC)
#if !defined(TTC_CORE_ARM946_CP15)
#define TTC_CORE_ARM946_CP15
#endif
#else
#undef TTC_CORE_ARM946_CP15
#endif
#endif //ARM946E_SCP15_H
