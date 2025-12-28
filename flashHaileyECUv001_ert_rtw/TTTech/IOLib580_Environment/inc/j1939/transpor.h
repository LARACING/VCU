/*****************************************************************************
* 
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
* transpor.h
*
* DESCRIPTION:
*   This header file contains the function prototypes for use inconjunction
*   with the transport layer of the J1939 protocol stack.
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
* 04/10/08     MBO  cast added to negative defines
*****************************************************************************/

#ifndef _TRANSPORT_H
#define _TRANSPORT_H

#include "stdtypes.h"
#include "j1939.h"
#include "can.h"
#include "tune.h"




/* 
--- This varaiable controls the RTS rate for each CM message.
    This variable is used when generating a CTS datagram and is
    placed in the "number of packets that can be sent" field.
	 Adjust as needed for processor speed (the slower the speed
    the lower the number).
*/
#define TRANSPORT_PACKET_COUNT            21
														

#define DEFAULT_TRANSPORT_PRIORITY        7

/* 
--- Defines used for transport routines TX
*/
#define J1939_TX_COMPLETE                 1
#define J1939_SENDING_TX_MESSAGE          2
#define BAM                            0xff

/*
--- Defines used in TRANSPORT section
*/
#define PACKET_NUMBER_OFFSET             0
#define TOTAL_SIZE_OFFSET                1
#define TOTAL_PACKET_OFFSET              3
#define RETRY_COUNT                      1
#define CONTROL_OFFSET                   0                                            
#define NUMBER_OFFSET                    (1+CONTROL_OFFSET)
#define NEXT_PACKET_OFFSET               (2+CONTROL_OFFSET)

#define J1939_RX_BUILDING                1
#define J1939_RX_VALID                   2
#define J1939_RX_BUFFER_IN_USE           4

/*
--- Transport Timing Requirements see J1939/21 sec 3.10.2.4
	 The transport inplements software timers assuming a time
    slice every TICK milliseconds. All time based calculations
    are based on this.  Change if system TICK is not five.
*/

#define T1_TRANSPORT                    (750/TICK)       /* Time between data packets        */
#define T2_TRANSPORT                    (1250/TICK)       /* Time between CTS and next packet */
#define T3_TRANSPORT                    (1250/TICK)       /* Time between packet and CTS      */
#define T4_TRANSPORT                    (1050/TICK)       /* Time between CTS 0 and CTS n     */

/*
--- The following time requirements are set by the 
    NUMBER_TRANS_TX_MACHINES. By making the BAM time a 
    function of this, we are can support all TX state
    machines sending BAMs at the same time and generate
    no timeouts on the receiver end.
*/
#define ACCELERATOR				5  /* LMO this is causing the problem : original value 20; changed to 10*/
#define BAM_WAIT_TIME           (250/(TICK*ACCELERATOR))  //(250/TICK)   CDM 02-17-04
#define CTS_WAIT_TIME           (1250/(TICK*ACCELERATOR)) //T3_TRANSPORT CDM 02-17-04

/*
--- Connection Management defines 
*/
#define RTS_CONTROL_BYTE            0x10
#define BAM_CONTROL_BYTE            32
#define CTS_CONTROL_BYTE            0x11
#define EOM_CONTROL_BYTE            0x13
#define ABORT_CONTROL_BYTE          0xFF
#define RESERVED_BYTE               0xFF
#define CM_PDU_FORMAT               0xEC
#define CM_PDU_DATA                 0xEB
#define CM_PDU_FORMAT_PGN           0xEC00
#define CM_PDU_DATA_PGN             0xEB00


#define PDU2_FORMAT                   240

#define MAX_NUM_ERRORS                  3

/*
--- Error Codes
*/
#define J1939_PROTOCOL_SEND_ERROR      -100
#define J1939_ERROR_RETRY_EXCEEDED     -101
#define J1939_ERROR_ABORTED            -102
#define J1939_TX_ERROR                 -103
#define J1939_MEMORY_ERROR             -104
#define J1939_TX_BUFFER_ERROR          -105
#define J1939_ERROR_NO_MORE_BUFFERS    -106
#define J1939_LENGTH_ERROR             -107
#define J1939_ERROR_DESTINATION        -108
#define J1939_TIMEOUT_ERROR            -109
#define J1939_NO_NETWORK_ADDRESS       -110
#define TX_STACK_ERROR                  -69


/*
--- J1939 protocol message structure; used to disassemble messages
*/
typedef struct 
{
	J1939_TX_MESSAGE_T      * tx_msg_ptr ;
	int  time ;
	S8   retry ;
	U8   packet_index ;
	U8   total_packets ;
	U8   state ;
	U8   packets_ok_to_send ;
} J1939_TRANSPORT_TX_INFO ;

/*
--- J1939 protocol message structure; used to reassemble messages
*/
typedef struct 
{
	int   message_index ;
	int   rx_timer ;
	S8    retry ;
	U8    packet_index ;
	U8    total_packets ;
	U8    flag ;
	J1939_RX_MESSAGE_T      rx_msg ;
	U8    msg_buffer[J1939_MAX_MESSAGE_LENGTH];
} J1939_MESSAGE ;

/*
--- TX State processor function pointer type
*/
typedef U8 (* PSTATES_T) (U8) ;


/*
--- TRANSPORT functions exported for other layers
*/
void get_CAN_packet ( void ) ;
void J1939_TL_process( J1939_RX_MESSAGE_T * pMsg ) ;
void J1939_TL_init( void ) ;
U8   J1939_transmit_message ( J1939_TX_MESSAGE_T * pMsg ) ;
U8   J1939_transmit_messagex ( J1939_TX_MESSAGE_T * pMsg ) ;
void J1939_TL_periodic ( void ) ;
void J1939_valid_network_address ( U8 state ) ;
void J1939_TL_flush ( void ) ;

/*
 --- State defines (see the definition of state table in TRANS_TX.C)
*/
#define BAM_WAIT_STATE          0
#define TIMER_RESETSTATE        1
#define BAM_START_STATE         2
#define BAM_NEXT_PACKET         3
#define CM_START_STATE          4
#define CM_WAIT_RESPONSE        5
#define ABORT_STATE             6
#define CM_NEXT_PACKET          7


#endif
