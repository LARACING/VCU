/*****************************************************************************
* 
*                  Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
*
*  
* datafmt.h
*
* DESCRIPTION:
*   This header file contains the function prototypes for use inconjunction
*   with the J1939 protocol stack.
*
*   This file contains data structures that allow byte
*   manipulation and data extraction from data stored as either
*  "Big Endian" or "Little Endian". Also, the structure will allow
*   the manipulation of j1939 identifiers store as unsigned longs.
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
#ifndef _DATAFMT_H_
#define _DATAFMT_H_

#define BIG_E /* used to define processors which use "Big Endian" machine
                 representation, also defined tune.h */

typedef struct
{
   unsigned char  P_R_DP;  // Priority, Reserve Bit, and data page fields
   unsigned char  PFF;      // PDU format field
   unsigned char  PS;      // PDU specific field
   unsigned char  source;
}Big_ID_T;

typedef struct
{
   unsigned char  source ;
   unsigned char  PS;      // PDU specific field
   unsigned char  PFF;      // PDU format field
   unsigned char  P_R_DP;  // Priority, Reserve Bit, and data page fields
}Little_ID_T;

typedef union
{
   unsigned long  whole;  // machine dependent unsigned long
#ifdef BIG_E
   Big_ID_T       CAN_ID;
#else
   Little_ID_T    CAN_ID;
#endif
}ID_T;




#endif // _DATAFMT_H_
