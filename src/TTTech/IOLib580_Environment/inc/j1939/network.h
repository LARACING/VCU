/*******************************************************************************
*                          
*                 Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
*   File name: network.h
* 
*   Description: This is the specification file for the j1939 network management
*                module. The network management filters J1939_RX_MESSAGE_T
*                structures bound for the application. If the PGN is defined
*                as a network management message, the network management 
*                module will process the message according to the j1939
*                Document J1339/81. All network messages are handled except
*                the command address message. All non network management 
*                messages are filtered by PGN's. If a messages PGN is in the 
*                PGN table (See stack.c), the message is passed to the 
*                application.
*
*   Notes:  The PGN feature is optional. In order to include this feature,
*           the stack utility module must define PGN_FILTERING in stack.h      
*
*   History:
*
* ________ ___ ___  ___________________________________________________________
*  DATE    Ver WHO  WHAT						       
* ________ ___ ___  ___________________________________________________________
* 08/17/00 1.0 JLD  created module for distribution
* 10/10/00 1.1 JLD  Set MAX_NODES to the proper value of 255.
* 11/10/00 1.2 JLD  changed huge to HUGE for portability
* 01/15/04     CDM  Made changes for ANSI C conformance
*
*******************************************************************************/

#ifndef _NETWORK_H_
#define _NETWORK_H_

/*******************************
*       Header files
*******************************/


#include "stdtypes.h"                   
#include "tune.h"
#include "j1939.h" 
#include "transpor.h"
#include "dm_layer.h"


/*********************************
* Network Managment Messages
*********************************/

/* Request Message for Address Claim */
#define REQUEST_PDU_FORMAT_PGN     0xea00 

/* Address Claim */
#define CLAIM_PDU_FORMAT_PGN       0xee00 

/* Command Address message */
#define CMD_ADD_PDU_FORMAT_PGN     0xfe00 //0xfed8 CDM 02-17-04  


/* This function initializes the network management layer */
void J1939_NML_init(void);

/* This function is calles every 5ms. It processes the network management
 * messages
 */
void J1939_NML_periodic(void);

/* This function is called by the transport layer to filter network management
 * messages
 */

void J1939_NML_process(J1939_RX_MESSAGE_T *msg_ptr);


#ifdef ADDRESS_CLAIM

#define MAX_NODES    255 //50 CDM 02-17-04

//typedef U8 Node_Name[8];
typedef U8 Node_Name[8];

void J1939_ACT_init(void); 

void J1939_ACT_insert( U8 *Name, U8 Address);
U8 J1939_address_conflict(void);	 


#endif


#endif // _NETWORK_H_
