/**************************************************************************************************
 * Copyright (c) 2015 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 **************************************************************************************************
 *
 * Name
 *    stdtypes.h
 *
 * Purpose
 *   J1939 adaption on different targets (e.g. TTC500).
 *      This include will include the proper data types definition file.
 *
 * Revisions
 *
 *    31-Mar-2015   LMO     Creation
 *************************************************************************************************/

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#if defined(__TI_ARM__)
    /* TMS compiler defines */
    #include "stdtypes_tms570.h"
#elif defined(_WIN32)
    /* WIN32 Compiler */
    #include "stdtypes_win32.h"
#else
    #error You have to define a suitable platform data types definition
#endif

#endif
