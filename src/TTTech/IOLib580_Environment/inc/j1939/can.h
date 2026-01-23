/*******************************************************************************
*                                            
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
*   File name: can.h
* 
*   Description:    This is the specification file for the J1939 protocol stack
*        Hardware abstraction interface. This interface is used by the stack to 
*        send CAN_PACKET_T structures to the HAL. 
*        
*
*   Notes:      Hardware abstraction layer will be commented as HAL             
*
*
*   History:
*
* ________ ___ ___  ___________________________________________________________
*  DATE    Ver WHO  WHAT						       
* ________ ___ ___  ___________________________________________________________
* 08/17/00 1.0 JLD  created module for distribution
* 01/15/04     CDM  Made changes for ANSI C conformance
*
*******************************************************************************/
#ifndef _CAN_H_
#define _CAN_H_
#include "stdtypes.h"

/* CAN port states */
#define OFF_LINE                 (0)
#define ON_LINE_PRIMED           (1)
#define ON_LINE_UPRIMED          (3)


#define CAN_MAX_BYTE_COUNT (8)

typedef struct
{
   U32     identifier ;
   U8      data[CAN_MAX_BYTE_COUNT] ;
   U8      byte_count ;
} CAN_PACKET_T, *PCAN_PACKET_T ;

void CAN_transmit_packet(CAN_PACKET_T *pPacket);

#endif
