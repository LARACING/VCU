/**************************************************************************************************
 * Copyright (c) 2014 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 *************************************************************************************************/
/**********************************************************************************************//**
 * \file ptypes_tms570.h
 *
 * \latexonly \hypertarget{ptypes_tms570}{} \endlatexonly
 *
 * \brief Primitive data types
 *
 *   This file defines the primitive data types used for the IO Driver
 *
 *************************************************************************************************/

#ifndef PTYPES_TMS570_H_
#define PTYPES_TMS570_H_

/**************************************************************************************************
 *
 * D E F I N I T I O N S
 *
 *************************************************************************************************/

/****************************************** Data Types *******************************************/

typedef unsigned char           ubyte1; /**< @brief unsigned  8bit integer */
typedef unsigned short int      ubyte2; /**< @brief unsigned 16bit integer */
typedef unsigned long           ubyte4; /**< @brief unsigned 32bit integer */
typedef unsigned long long      ubyte8; /**< @brief unsigned 64bit integer */

typedef signed char             sbyte1; /**< @brief signed  8bit integer */
typedef signed short int        sbyte2; /**< @brief signed 16bit integer */
typedef signed long             sbyte4; /**< @brief signed 32bit integer */
typedef signed long long        sbyte8; /**< @brief signed 64bit integer */

typedef float                   float4; /**< @brief 32bit float type */
typedef double                  float8; /**< @brief 64bit float type */

#ifndef bool
    typedef unsigned char       bool;   /**< @brief boolean type */
#endif

typedef unsigned char           BOOL;   /**< @brief boolean type, obsolete definition
                                             (for compatibility reasons only) */

/************************************** Common Definitions ***************************************/

/** @def NULL
*   @brief NULL definition
*/
#ifndef NULL
    #define NULL                ((void *)0U)
#endif

/** @def NULL_PTR
*   @brief NULL pointer definition
*/
#ifndef NULL_PTR
    #define NULL_PTR            ((void *)0U)
#endif

/** @def FALSE
*   @brief bool definition for FALSE
*/
#ifndef FALSE
    #define FALSE               ((bool)0U)
#endif

/** @def TRUE
*   @brief bool definition for TRUE
*/
#ifndef TRUE
    #define TRUE                ((bool)1U)
#endif

/** @def UBYTE4_MAX_VALUE
*   @brief maximum value of the ubyte4 type
*/
#define UBYTE4_MAX_VALUE        ((ubyte4)0xFFFFFFFFU)

/** @def UBYTE4_MIN_VALUE
*   @brief minimum value of the ubyte4 type
*/
#define UBYTE4_MIN_VALUE        ((ubyte4)0x00000000U)

/** @def UBYTE2_MAX_VALUE
*   @brief maximum value of the ubyte2 type
*/
#define UBYTE2_MAX_VALUE        ((ubyte2)0xFFFFU)

/** @def UBYTE2_MIN_VALUE
*   @brief minimum value of the ubyte2 type
*/
#define UBYTE2_MIN_VALUE        ((ubyte2)0x0000U)

/** @def UBYTE1_MAX_VALUE
*   @brief maximum value of the ubyte1 type
*/
#define UBYTE1_MAX_VALUE        ((ubyte1)0xFFU)

/** @def UBYTE1_MIN_VALUE
*   @brief minimum value of the ubyte1 type
*/
#define UBYTE1_MIN_VALUE        ((ubyte1)0x00U)

#endif /* PTYPES_TMS570_H_ */
