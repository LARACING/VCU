/*******************************************************************************
* 							
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
* 
*   File name: ring.h
* 
*    Description:  This is the specification file a ring buffer data structure.
*                  The object code exports functions to initialize a circular
*                  FIFO queue.
*
*          Notes:  The buffer size is initial set to RSIZE = 16. If a larger
*                  buffer is required the mask must be changed. The current 
*                  mask is 0xf. 
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


/*******************************
*	Header files
*******************************/

#include "stdtypes.h"
#include "tune.h"
#include "can.h" /* for CAN_PACKET_T structure */


#define exp2(X)   (1L << X)         /* This Macro calculates 2 exp X */

#define RSIZE IN_BUFFER_SIZE           /* Default size of the ring buffer */

/* This Macro calculates the multiple need to calculate RMASK.
 * (SEE Note 1)
 */

#define MLTP   ((IN_BUFFER_SIZE % 16)?((IN_BUFFER_SIZE/16) + 1):(IN_BUFFER_SIZE/16))

/* This Macro calculates RMASK. (SEE Note 1) */

#define RMASK  ((exp2(4+(MLTP-1))) - 1)

/* Note 1: if a larger buffer is needed, RSIZE must be changed by a multiple of 
 *       16. Also the RMASK value must be recalculated by 
 *
 *       			(4 + (m - 1))
 *      RMASK = [ 2					-    1]
 *
 *       where m is equal to the multiplier, m * 16 = RSIZE.
 */

/*******************************************************************************
* RING_T Structure
*
* Description: This structure is declared by the importer of the ring buffer.
*              It is used to allow multiple importers to use the object code. 
*              The importer allocates an array of CAN_PACKET_T structures
*              and passes a pointer to the array along with a pointer to it's
*              RING_T structure to rng_init. Once this is done, the importer
*              can use the ring structures rng_enqueue and rng_dequeue funtions.
*
*******************************************************************************/

typedef struct {

	CAN_PACKET_T *buffer;	/* pointer to array of CAN_PACKET_T structures */
	U32  head;					/* index to head of ring */
	U32  tail;					/* index to tail of ring */

}RING_T;

/********************************
* Ring Buffer Export Functions
********************************/

/* This function takes a pointer to a CAN_PACKET_T array and a pointer to the
 * importers RING_T structure and initialize the the ring buffer data structure.
 */
void rng_init(CAN_PACKET_T *buffer, RING_T *ring);

/* This function enqueues a CAN_PACKET_T structure onto the tail of the importers 
 * ring buffer.
 */
void rng_enqueue(CAN_PACKET_T msg ,RING_T *ring);

/* This function dequeues a CAN_PACKET_T structure and passes a pointer to the 
 * dequeued CAN_PACKET_T structure to the importer.
 */
CAN_PACKET_T *rng_dequeue(RING_T *ring);


/* debug ring buffer function */
#ifdef RING_DEBUG
#include <stdio.h>
void Print_Macro(void);
void Print_ring(RING_T *ring);
#endif
