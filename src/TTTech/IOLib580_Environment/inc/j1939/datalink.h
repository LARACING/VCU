/*******************************************************************************
*                                            
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
*   File name: datalink.h
* 
*   Description:  This is the specification file for the j1939 datalink module.
*        The module exports functions to interface to the transport
*        layer module and the hardware abstraction layer module.
*        The datalink layer is used in the J1939 stack.
*        
*
*   Notes:      Hardware abstraction layer will be commented as HAL             
*
*   History:
*
* ________ ___ ___  ___________________________________________________________
*  DATE    Ver WHO  WHAT						       
* ________ ___ ___  ___________________________________________________________
* 08/17/00 1.0 JLD  created module for distribution
* 01/15/04     CDM  Made changes for ANSI C conformance
* 21/10/19     LMO (TTControl) Added DataLink (J1939-21) definitions for the NACK response
*
*******************************************************************************/

#ifndef _DATALINK_H_
#define _DATALINK_H_

/*******************************
*       Header files
*******************************/

#include "stdtypes.h"
#include "tune.h"
#include "can.h"
#include "j1939.h"

#define J1939_NACK_POSITIVE_ACKNOWLEDGEMENT         (0x00U)
#define J1939_NACK_NEGATIVE_ACKNOWLEDGEMENT         (0x01U)
#define J1939_NACK_ACCESS_DENIED_ACKNOWLEDGEMENT    (0x02U)
#define J1939_NACK_CANNOT_RESPOND_ACKNOWLEDGEMENT   (0x03U)

#define MIN_PDU2  240   /* this defines the lowest PDU format that does not
			 * contain a destination address
			 */

/*
--- This function is called to initialize the datalink layer.
 */                
void J1939_DL_init(void);

/*
--- This function flushes the datalink outbound buffers 
 */
void J1939_DL_flush(void);

/************************************************
*CAN Device Driver Interface Function Prototypes
*************************************************/

/*
--- This function is called by the HAL when it has recieved a CAN packet. 
 */
void CAN_receive_packet( CAN_PACKET_T* pkt_ptr );

/*
--- This function is called by the HAL when it's transmitter buffer is empty. 
 */
CAN_PACKET_T* CAN_transmitter_empty( void );

/************************************************
* Transport Module Interface Function Prototypes
************************************************/

/*
--- This function is called by the transport layer when a J1939_TX_MESSAGE_T 
--- structure is available to be packetized into a CAN packet.  
 */
void build_CAN_packet(J1939_TX_MESSAGE_T *msg_ptr, U8 tflag);

/*
--- This function is called by a timer every 5ms. It drives the internal 
--- datalink filtering and buffer management.
 */
void J1939_DL_periodic(void); 


#endif //_DATALINK_H_
