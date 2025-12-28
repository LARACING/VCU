/**************************************************************************************************
 * Copyright (c) 2019 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 **************************************************************************************************
 *
 * \file
 *
 * Purpose
 *   The J1939 Noregon stack has no knowledge of persistence storage for DM2 / DM3 diagnostic
 *   service. This is a HAL implementing a generic access to such physical storage devices.
 *   The API function signatures are coming from the OH C API Standardization. They have a J1939
 *   prefix so to avoid type conflicts (when the library is used on products featuring these).
 *
 * Revisions
 *
 *   04-Oct-2019   LMO     Creation
 *
 *************************************************************************************************/

#ifndef J1939_STACK_SRC_STORAGE_HAL_H_
#define J1939_STACK_SRC_STORAGE_HAL_H_

#include "stdtypes.h"

typedef U32 J1939_IoStatusType;         /**< Definition of the return status of an operation */
typedef U32 J1939_IoRetType;            /**< Definition of the return code after function invocation */

/** The enumeration of the available status codes */
typedef enum
{
    J1939_STORAGE_STATUS_UNKNOWN,       /**< Status is not set                              */
    J1939_STORAGE_STATUS_READY,         /**< Status indicates Ready / All good              */
    J1939_STORAGE_STATUS_BUSY           /**< Status indicates Busy / Operation in progress  */
} E_J1939_STORAGE_STATUS;

/** The enumeration of the return codes of the IO functions */
typedef enum
{
    J1939_STORAGE_RET_TYPE_OK,                      /**< OK: no error encountered. Operation is successful and/or complete          */
    J1939_STORAGE_RET_TYPE_FAILURE,                 /**< Generic failure e.g. internal error of underlying driver                   */
    J1939_STORAGE_RET_TYPE_PARAMETER_OUT_OF_RANGE,  /**< Supplied Offset and/or Size is not in the range of the device or partition */
    J1939_STORAGE_RET_TYPE_OVERFLOW                 /**< Supplied parameter is outside specification e.g. software error            */
} E_J1939_STORAGE_RET_TYPE;

/** The enumeration of the available partitions */
typedef enum
{
    J1939_STORAGE_PARTITION_DIAG_DM2,              /**< This partition of data is reserved to store the DM2 data */
    J1939_STORAGE_PARTITION_NUM                    /**< This is the number of defined partitions                 */
} E_J1939_STORAGE_PARTITION;

/** This macro is useful to set a value to the status pointer including a null-pointer check */
#define SET_STATUS_WITH_NULLPTR_CHECK(x)    do {                                        \
                                                if (Status != NULL) *Status = x;         \
                                            } while(0);

J1939_IoRetType IoExtEepInit( J1939_IoStatusType * const Status );

J1939_IoRetType IoExtEepRangeCheck(U32 Offset, U32 Length);

/* Not implemented - J1939_IoRetType IoExtEepDeInit( void ); */

J1939_IoRetType IoExtEepRead( U32 Offset, U32 Length, U8 * const Data , J1939_IoStatusType * const Status );

/**
 * Start writing to the storage.
 * Please note: the supplied buffer cannot be modified until the write operation is complete (see: IoExtEepGetStatus)
 *
 * @param Offset    location to write to
 * @param Length    the size of the supplied buffer
 * @param Data      the supplied buffer to write
 * @param Status    the output status
 * @return          the return code of the operation
 */
J1939_IoRetType IoExtEepWrite( U32 Offset, U32 Length, const U8 * const Data, J1939_IoStatusType * const Status );

/* Not implemented - J1939_IoRetType IoExtEepErase( U32 Offset, U32 Length, J1939_IoStatusType * const Status ); */
/* Not implemented - J1939_IoRetType IoExtEepEraseAll( IoStatusType * const Status ); */

J1939_IoRetType IoExtEepGetStatus( J1939_IoStatusType * const Status );

/**
 * This function is used by J1939 logic to retrieve information about a partition:
 *  - retrieve the start offset to work with
 * The user shall call this function with the requested size and use the given offset only if the
 * returned value is equal to J1939_STORAGE_RET_TYPE_OK. In all other cases, using the offset
 * shall not be done.
 *
 * @param Partition     the requested partition e.g. for diagnostic data
 * @param Size          the requested size (must fit the partition)
 * @param Offset        the output offset for the logic to write to
 * @param Status        the status value (must be J1939_STORAGE_STATUS_READY if OK)
 *
 * @return              J1939_STORAGE_RET_TYPE_OVERFLOW     : partition does not have the requested size
 *                      J1939_STORAGE_RET_TYPE_OUT_OF_RANGE : unknown partition
 *                      J1939_STORAGE_RET_TYPE_OK           : partition request successful
 */
J1939_IoRetType IoExtEepPartitionGet( E_J1939_STORAGE_PARTITION Partition, U32 Size, U32 * const Offset, J1939_IoStatusType * const Status );

/**
 * This function is used to setup the storage partitions from IO-blockset based on user
 * design and configuration.
 *
 * @param Partition     the partition to be setup
 * @param Offset        the address where the partition of data starts
 * @param Size          the maximum allocated size
 */
J1939_IoRetType IoExtEepPartitionSetup( E_J1939_STORAGE_PARTITION Partition, U32 Offset, U32 Size );

#endif /* J1939_STACK_SRC_STORAGE_HAL_H_ */
