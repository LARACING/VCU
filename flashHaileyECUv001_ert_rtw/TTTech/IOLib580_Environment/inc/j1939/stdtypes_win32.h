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
* 08/09/16 1.0 LMO  initial version
*
*****************************************************************************/
#ifndef _STD_TYPES_STANDARD_H
#define _STD_TYPES_STANDARD_H

#include "stdint.h"

typedef   int8_t            S8;   /* signed    8-bit data type */
typedef   int16_t           S16;  /* signed   16-bit data type */
typedef   int32_t           S32;  /* signed   32-bit data type */
typedef   uint8_t           U8;   /* unsigned  8-bit data type */
typedef   uint16_t          U16;  /* unsigned 16-bit data type */
typedef   uint32_t          U32;  /* unsigned 32-bit data type */

/* For strict ANSI C compliancy on the Keil compiler, uncomment the line below:
 */
//#pragma NOEXTEND

/* Uncomment the line below if you are using the Keil uVision2 compiler:
 */
//#define KEIL_COMPILER

/* Some compilers put the "huge" keyword before the data type, 
 * others put it after:
 */
#ifdef KEIL_COMPILER    
	#include <reg167.h>
         
	typedef uint8_t huge HUGE_U8;     
	typedef int8_t  huge HUGE_S8;
#endif

/* Uncomment the line below if you are using the Tasking compiler:
 */
//#define TASKING_COMPILER

#ifdef TASKING_COMPILER
	#include <reg167cr.h>
	#include <c166.h>

	typedef huge uint8_t HUGE_U8;
	typedef huge int8_t  HUGE_S8;
#endif

/* Uncomment the line below if you are using the Keil MetroWerks CodeWarrior compiler:
 */
#define METROWERKS_COMPILER

/* For some compilers, we don't use the "huge" keyword at all:
 */
#ifdef METROWERKS_COMPILER    
	typedef uint8_t      HUGE_U8;     
	typedef int8_t       HUGE_S8;
#endif

typedef  U8 Boolean;     /* Holds a boolean truth value. This value
                          * can be TRUE or FALSE
			  */
typedef U8  BOOL;

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
