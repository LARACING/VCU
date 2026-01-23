/*******************************************************************************
*                                         
*                 Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
*
* File name: j1939.h
*
* DESCRIPTION:
*   This header file contains the function prototypes for use inconjunction
*   with the Noregon Systems J1939 protocol stack.
*              
*              
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
*****************************************************************************/


#ifndef _J1939_h
#define _J1939_h
#include "stdtypes.h"
#include "datafmt.h"

// J1939_16_BIT_PGN should be defined in stdtypes.h if it is to be used.

#ifndef J1939_16_BIT_PGN
typedef  unsigned long PGN_T ;
#else
typedef unsigned short PGN_T ;
#endif

typedef struct
{
   PGN_T PGN ;
   U8 * data_ptr ;
   U16 byte_count ;
   U8 priority ;
   U8 dest_addr ;
   S8 status;

} J1939_TX_MESSAGE_T ;

typedef struct
{
   PGN_T PGN ;
   U8 * data_ptr ;
   U16 byte_count ;
   U8 source_addr ;
   U8 dest_addr ;

} J1939_RX_MESSAGE_T ;

typedef void (*PROCESS)(J1939_RX_MESSAGE_T *);

/*
 * Stuff in Application
 */
//U8 J1939_address_conflict ( void ) ;
// J1939_address_conflict can be an application specific function
// if it is removed from the network layer.
void J1939_received_message ( J1939_RX_MESSAGE_T * ) ;
#endif /*  #define _J1939_h */
