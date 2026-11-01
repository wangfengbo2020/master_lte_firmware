/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2001
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: FDI_OS.H - This file defines prototypes for fdi_os.c
###
###  $Archive: /FDI/SRC/INCLUDE/FDI_OS.H $
###  $Revision: 30 $ 
###  $Date: 8/05/01 1:13p $
###  $Author: Leonid Rosenblat, Intel CCDi $
###  $NoKeywords $
########################################################################### */

/****************************************************************************
INTEL OEM SOFTWARE LICENSE AGREEMENT (LICENSE.TXT)

BY USING THIS SOFTWARE, YOU ("You" or "Licensee") ARE AGREEING TO BE
BOUND BY THE TERMS OF THIS AGREEMENT.  DO NOT USE THE SOFTWARE UNTIL
YOU HAVE CAREFULLY READ AND AGREED TO THE FOLLOWING TERMS AND
CONDITIONS.  IF YOU DO NOT AGREE TO THE TERMS OF THIS AGREEMENT,
PROMPTLY RETURN THE SOFTWARE, PACKAGING, AND ANY ACCOMPANYING ITEMS.
YOU MUST BE AN ORIGINAL EQUIPMENT MANUFACTURER ("OEM") SYSTEM DEVELOPER
TO ACQUIRE ANY RIGHTS IN THE SOFTWARE UNDER THIS LICENSE AGREEMENT.

"Source Code" means source code that you receive from Intel under this
Agreement.  "Derived Object Code" means executable code derived from
Intel Source Code.  "Software" means the Intel Source Code and object
code (unmodified by you) and related documentation that You receive
from Intel under this Agreement.

LICENSE: Intel Corporation ("Intel") grants You the non-exclusive,
nontransferable, royalty free right under Intel copyright to:

 1. Reproduce and modify the Software, only for your own development
    and maintenance, provided that You may not modify the Software for
    use with flash products other than Intel Flash memory products;
 2. Install, use, reproduce and distribute Derived Object Code
    internally, only for Your own development and maintenance purposes;
 3. Allow authorized contractors ("Subcontractors") engaged by You for
    the sole purpose of product development work to have access to the
    Software and any modified Source Code solely for that purpose.
    Subcontractors do NOT acquire any of Your rights to the Software or
    any modified Source Code provided in this Agreement;
 4. Distribute Derived Object Code externally to Your bona fide customers
    ("Customers"), provided that You may not distribute Derived Object
    Code for use with flash products other than Intel Flash memory
    products;  and
 5. Copy the Software for Your support, backup or archival purposes.

RESTRICTIONS:

YOU ARE NOT ALLOWED TO:
 1. Use, copy, modify, rent, sell, license, transfer, disclose or
    distribute the Software, in whole or in part, except as provided for
    in this Agreement;
 2. Remove or modify the "Compatibility" module, if any, in the Software
    or in any Derived Object Code;
 3. Decompile or reverse engineer any Software delivered in object code
    form.

THIS ROYALTY FREE LICENSE ALLOWS YOU TO USE THE SOFTWARE WITH INTEL FLASH
PRODUCTS ONLY.  YOUR USE OF THE SOFTWARE WITH ANY OTHER FLASH PRODUCTS IS
EXPRESSLY PROHIBITED UNLESS AND UNTIL YOU APPLY FOR, AND ARE GRANTED IN
INTEL'S SOLE DISCRETION, A SEPARATE WRITTEN SOFTWARE LICENSE FROM INTEL
LICENSING ANY SUCH USE

YOU MUST execute the "Compatibility" module if provided with the Software.

TRANSFER:  Except as provided above, You may not transfer or disclose the
Software to any other party.

OWNERSHIP AND COPYRIGHT OF SOFTWARE: Title to the Software and all copies
thereof remain with Intel.  The Software is copyrighted and is protected
by United States and international copyright laws.  You will not remove
the copyright notice from the Software.  You agree to prevent the
unauthorized copying of the Software.  You are not required to provide
Intel with a copy of any modified Source Code or Derived Object Code
created by You. Title to modified Source Code, other than the portion(s)
of the modified code consisting of any portion of the Software, shall
remain with You.

Your sale or distribution of Derived Object Code is at Your own risk and
expense.

CONFIDENTIALITY. Source Code may include trade secrets of Intel.  You will
not disclose or otherwise make any part of Source Code (whether or not
modified by You) available, in any form, to any person other than Your
employees whose job performance requires such access.  You agree to
instruct all such employees on these obligations with respect to use,
copying, protection, and confidentiality of Source Code.  Even after this
Agreement terminates, the obligations of this section shall remain in
effect until the Source Code rightfully becomes publicly known.  You may
not disclose the terms or existence of this Agreement or use Intel's name
in any publications, advertisements, or other announcements without Intel's
prior written consent.  You do not have any rights to use Intel's trademarks.
Any Subcontractors to whom You disclose the Source Code must sign a written
confidentiality agreement which contains terms regarding the Software no
less restrictive than those set forth in this Agreement.

NO WARRANTY.  INTEL MAKES NO WARRANTY OF ANY KIND REGARDING THE SOFTWARE.
THE SOFTWARE IS PROVIDED "AS IS".  INTEL SPECIFICALLY DISCLAIMS ANY OTHER
WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WARRANTIES OF MERCHANTABILITY,
NONINFRINGEMENT OR FITNESS FOR ANY PARTICULAR PURPOSE.

LIMITATION OF LIABILITY.  INTEL SHALL NOT BE LIABLE FOR ANY INDIRECT,
SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGE, NOR ANY LOSS OF PROFITS, LOSS
OF USE, LOSS OF DATA, INTERRUPTION OF BUSINESS, OF ANY KIND, EVEN IF ADVISED
OF THE POSSIBILITY OF SUCH DAMAGES.

TERMINATION OF THIS LICENSE.  You may terminate this Agreement and the
license granted herein at any time by notifying Intel in writing. Intel
reserves the right to conduct or have conducted audits to verify Your
compliance with this Agreement.  Intel may terminate this Agreement at any
time if You are in breach of any of its terms and conditions.  If this
Agreement is terminated for any reason, You will cease distribution of
Derived Object Code and, at Intel's option and within thirty (30) days
following termination, either return to Intel or destroy the original and
all copies of the Software and undistributed copies of Derived Object Code,
and certify to Intel that they have been destroyed.

U.S. GOVERNMENT RESTRICTED RIGHTS.  The Software and documentation were
developed at private expense and are provided with "RESTRICTED RIGHTS".
If You distribute Derived Object Code to the U.S. Government or contractor
You must include the following legend on the distributed copy(ies):  "Use,
duplication, and disclosure by the Government is subject to restrictions
set forth in FAR 52.227-14, DFARS 252.227-7013 or their successors."

EXPORT LAWS.  Source Code and Derived Object Code may be controlled for
export purposes by the U.S. Government.  You will not export, either
directly or indirectly, any Derived Object Code without first obtaining
any required license or other approval from the U.S. Department of
Commerce or any other agency or department of the United States
Government as required.

ENTIRE AGREEMENT.  This is the entire agreement between You and Intel
relating to this subject matter, and no amendments will be effective
unless in a writing signed by both parties.

APPLICABLE LAW. This Agreement is governed by the laws of the State of
Delaware and the United States, including patent and copyright laws.
Any claim arising out of this Agreement will be brought in Delaware.

AGREEMENT ACCEPTANCE AND FILE PASSWORD ACCESS:  The archive file that
contains the code included with this license agreement is encrypted and
password protected.  In entering the password I_AGREE and by opening the
archive file You indicate Your acceptance of the terms of the above
agreement.  Please see the accompanying "read me" (READxxxx.TXT) file
for detailed instructions on how to use the password.


PRODUCT REGISTRATION

To register your product, please print out this document, fill out the
following and return the entire document to Intel as indicated below.


Intel Flash Software_________________________________
                    (fill in software type, PSM, FDI, etc.)

Version___________________
       (fill in version number)


LICENSEE

__________________________________________________
Company Name

__________________________________________________
Printed Name

__________________________________________________
Signature

__________________________________________________
Title

__________________________________________________
Date

__________________________________________________
Address

__________________________________________________
City

__________________________________________________
State/province

ZIP/postal code___________________________________


Country___________________________________________

EMAIL _________________________

Phone __________________________ Ext______
(Please include your area code or country/city code as
 appropriate)

FAX   _________________________


 Application Details (please tell us about your product,
 the flash use, and software  use):

 _______________________________________________________

 _______________________________________________________

 _______________________________________________________

  Please return COMPLETELY filled out to:

    Intel Corporation         FAX: 916-356-2803
    Intel Flash Software Marketing
    FM3-163
    1900 Prairie City Road
    Folsom, CA 95630

    Atten: Flash S/W License

Intel reserves the right to use and/or include Your name in
public relations activities and marketing material and may
request You to submit endorsements for the Software.  If You
wish to discuss participation in this program, please send a
fax to 916-356-2803 attn: "Software Marketing" with contact
information and an Intel representative will contact You.

Revised: 02/16/01
***************************************************************************/

#ifndef FDI_OS_H
#define FDI_OS_H

#include "FDI_TYPE.h"

#if !defined( FDI_COMMON_PORTING )

#error ERROR: FDI_COMMON_PORTING macro should be defined !

#endif /* !defined( FDI_COMMON_PORTING ) */

extern ERR_CODE FDI_OsInit(void);
extern VOID *FDI_MemMalloc(UNSIGNED size);
extern VOID FDI_MemFree(VOID *block);
extern SEM_ID FDI_SemBinCreate(VOID);
extern SEM_STATUS FDI_SemDestroy(SEM_ID semId);
extern SEM_STATUS FDI_SemPost(SEM_ID semId);
extern SEM_STATUS FDI_SemWait(SEM_ID semId, UNSIGNED suspend);
extern int FDI_TaskSpawn(CHAR *name, OPTION priority, UNSIGNED option, UNSIGNED stackSize, VOID (*taskEntry)( UNSIGNED, VOID * ));
extern VOID FDI_TaskDelayTicks(UNSIGNED numTicks);
extern VOID FDI_TaskDelayMsec(UNSIGNED mSec);
extern VOID FDI_TaskDestroy(int taskId);

#endif /* FDI_OS_H */

