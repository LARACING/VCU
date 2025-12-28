/*******************************************************************************
*
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
*     File name:  tune.h
* 
*     Description: This file contains the compile time constants needed to tune
*                  the data size and throughput performance of the J1939 
*                  protocol stack.
*                  
*
*     Notes:   For more a more detailed view of tunable parameters, see 
*              the J1939 Protocol Stack Reference Manual.
*
*
*
*   History:
*
* ________ ___ ___  ___________________________________________________________
*  DATE    Ver WHO  WHAT						       
* ________ ___ ___  ___________________________________________________________
* 08/17/00 1.0 JLD  created module for distribution
* 10/11/00 1.1 JLD  Changed ADDR_NUM to 2.
* 11/10/00 1.2 JLD  Added comments about IN_BUFFER_SIZE and OUT_BUFFER_SIZE.
* 01/15/04     CDM  Made changes for ANSI C conformance
* 03/31/15     LMO (TTControl) New configuration for TTC500
* 04/01/15     LMO (TTControl) max message size restored to 1785
*
*******************************************************************************/


#ifndef _TUNE_H_
#define _TUNE_H_

/****************************  
* Header Files
***************************/
#include "j1939.h"

/*
 * This parameter defines the size of the address
 * filter array.
 */
#define ADDR_NUM 2

/* LMO: NOTE address claim is disabled */
/* #define ADDRESS_CLAIM */

extern void J1939_TL_process(J1939_RX_MESSAGE_T *);
extern void J1939_NML_process(J1939_RX_MESSAGE_T *);
#define NEXT_PROCESS_DL   (J1939_TL_process)
#define NEXT_PROCESS_TL   (J1939_NML_process)
			

/* LMO: the timebase is set to 10ms that is the cycle time of the application */
//#define TICK 			10           /* This parameter defines the clock tick time base. */
/* Cycle time shall be configurable, hence the external reference for the app layer */
extern U32 TICK;

/* 
 * The next three parameters dimension the maximum number 
 * of TX state machines and RX buffers. Adjust as needed.
 */
 /* LMO: these parameters as in MUX-VBA */
#define NUMBER_TRANS_TX_MACHINES         10 
#define NUMBER_TRANS_RX_BUFFERS          10 //2    CDM 02-17-04
#define J1939_MAX_MESSAGE_LENGTH         1785 //CDM 02-17-04; LMO: previously 250
#define J1939_MAX_DATA_SIZE              8

/* This parameter is defined if the platform stores data 
 * using the "Big Endian" format   
 */

/* LMO: TTC500 is big endian
    gotcha: you also have to define this identifier in datafmt.h !!!
    failing to do so, makes the CAN ID reversed thus violating the protocol
*/
#define BIG_E
			 
			 
/* This parameter changes the datalink module's 
 * outbound buffer size. -- 16
 */
#define OUT_BUFFER_SIZE                 32 
/* NOTE: OUT_BUFFER_SIZE and IN_BUFFER_SIZE MUST be defined
 * to be the SAME value or the macros in ring.h will not work
 */   
			      
/* This parameter changes the datalink module's                               
 * inbound buffer size. Should be mod 16 or code 
 * will need to be changed also watch TICK count!
 */
#define IN_BUFFER_SIZE                  OUT_BUFFER_SIZE
					

/* This include file gives the stack access to the
 * stack utility functions.(Note: There are tunable
 * parameters in stack.h that allow various utilities
 * to be included -- SEE stack.h
 */
#include "stack.h"      
												

#endif //_TUNE_H_
