/*****************************************************************************
* 
* 
*                 Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
*
*   stdtypes.h
*
* DESCRIPTION:
*   This header file contains the standard data types used by Noregon for
*   embedded software modules. These definitions provide standard data type 
*   sizes regardless of platform and compiler.
*              
*              
*   History:
*
* ________ ___ ___  ___________________________________________________________
*  DATE    Ver WHO  WHAT						       
* ________ ___ ___  ___________________________________________________________
* 09/24/00 1.0 JLD  created module
* 11/10/00 1.1 JLD  Added HUGE
* 01/15/04     CDM  Made changes for ANSI C conformance
* 03/31/15     LMO (TTControl) data types adapted to the TMS570 compiler
*
*****************************************************************************/
#ifndef _STD_TYPES_TMS570_H
#define _STD_TYPES_TMS570_H

#include "ptypes_tms570.h"

typedef   sbyte1            S8;   /* signed    8-bit data type */
typedef   sbyte2            S16;  /* signed   16-bit data type */
typedef   sbyte4            S32;  /* signed   32-bit data type */
typedef   ubyte1            U8;   /* unsigned  8-bit data type */
typedef   ubyte2            U16;  /* unsigned 16-bit data type */
typedef   ubyte4            U32;  /* unsigned 32-bit data type */

/* For strict ANSI C compliancy on the Keil compiler, uncomment the line below:
 */
//#pragma NOEXTEND

/* Uncomment the line below if you are using the Keil uVision2 compiler:
 */
//#define KEIL_COMPILER

/* Some compilers put the "huge" keyword before the data type, 
 * others put it after:
 */
//#ifdef KEIL_COMPILER
//	#include <reg167.h>
         
//	typedef unsigned char huge HUGE_U8;
//	typedef char huge          HUGE_S8;
//#endif

/* Uncomment the line below if you are using the Tasking compiler:
 */
//#define TASKING_COMPILER

//#ifdef TASKING_COMPILER
//	#include <reg167cr.h>
//	#include <c166.h>

//	typedef huge unsigned char HUGE_U8;
//	typedef huge char          HUGE_S8;
//#endif

/* Uncomment the line below if you are using the Keil MetroWerks CodeWarrior compiler:
 */
 /* LMO: conditional compilation removed */
//#define METROWERKS_COMPILER

/* For some compilers, we don't use the "huge" keyword at all:
 */
//#ifdef METROWERKS_COMPILER    
typedef ubyte1              HUGE_U8;
typedef sbyte1              HUGE_S8;
//#endif

typedef  bool Boolean;     /* Holds a boolean truth value. This value
                          * can be TRUE or FALSE
			  */

#ifndef FALSE
#define FALSE   0
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef NO
#define NO      0  /* Evaluates to NO */
#endif

#ifndef YES
#define YES     !NO  /* Evaluates to YES */
#endif

// J1939_16_BIT_PGN should be defined here if it is to be used by the stack.
#endif
