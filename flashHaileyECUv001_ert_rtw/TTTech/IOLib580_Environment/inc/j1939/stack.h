/*******************************************************************************
*                                         
*                 Copyright 2000 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
*
* File name: stack.h
*
* Description: This is the specification file for the J1939 stack module. 
*    The stack module is responsible for maintaining an array of
*    valid network addresses and a table of valid PGN's. Also, 
*    this module contains functions that initialize the stack and
*    search the PGN table for valid PGN's.        
*
*           Notes:  None                          
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


#ifndef _STACK_H_
#define _STACK_H_

/*******************************
*       Header files
*******************************/
/* In Normal operation this file is included in tune.h */
#ifndef _TUNE_H_         /* if not included in tune.h */
#include "stdtypes.h"
#include "datalink.h"
#include "j1939.h"
#include "transpor.h"
#include "network.h"
#endif /* _TUNE_H_ */

/*********************************************************************
* Tunable Parameters
*
* Descripition:   These parameters are used to allow the user to 
*                 select which stack utitilties are to be included in
*                 the stack build. 
*      
*********************************************************************/



//#define PGN_FILTERING   /* allow PGN filtering */
#define PGN_NUM 3       /* table size */




/***********************
* Function Declarations
***********************/



#endif  //_STACK_H_
