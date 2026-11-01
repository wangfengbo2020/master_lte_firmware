/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


#ifndef IPCComm_H
#define IPCComm_H


#include "WS_IPCComm.h"

#define IPC_RC_available    IPC_RC_AVAILABLE

#define IPC_HANDSHAKE_FINISHED_EVENT 0x1

/* Legacy Command Parameters */
typedef struct
{
    UINT16  opCode;
    UINT16  cmdLength; // in word !!! (16bits)
    UINT16  *cmdData;
} IPC_Command;

// HERMON APLP Configuration:
//---------------------------
// Drop the CSW group definition for IPCCommCommandSend:
#undef IPCCommCommandSend
// Declare the APLP group definition for IPCCommCommandSend:
IPC_ReturnCode IPCCommCommandSend (IPC_Command  *cmdToSend, ApplicationID sourceID);
void IPCSetMSAHandshakeEvent(void);
void IPCCreateEvent(void);


#endif // IPCComm_H
