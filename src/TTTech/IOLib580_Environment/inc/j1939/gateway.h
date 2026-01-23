/**************************************************************************************************
 * Copyright (c) 2019 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 **************************************************************************************************
 *
 * \file
 *
 * Purpose
 *   The J1939 Noregon stack has no support for gateway of J1939 frames from one CAN channel to
 *   another.
 *
 *   This module implements the gateway functionality.
 *   The gateway functionality is implemented with a lookup table containing the routing rules
 *   for a given CAN channel (the user shall implement n tables for n CAN channels separately)
 *   and patching the Source Address (SA) of the CAN identifier.
 *
 * Revisions
 *
 *   21-Mar-2019   LMO     Creation
 *
 *************************************************************************************************/


#ifndef J1939_STACK_SRC_GATEWAY_H_
#define J1939_STACK_SRC_GATEWAY_H_

#include "stdtypes.h"                                   /* data types definitions */

/** Structure that represents information for a gateway item i.e. activity */
typedef struct
{
    U8              source_address_origin;              /**< The destination source address for the forwarding        */
    U8              source_address_destination;         /**< The destination source address for the forwarding        */
    U16             gw_handle;                          /**< The destination write handle for the forwarding of frame */
} t_J1939_CAN_GW_Item;

/** Enumeration of the result of a gateway operation */
typedef enum
{
    GATEWAY_RESULT_OK,                                  /**< The requested operation has successfully completed       */
    GATEWAY_RESULT_NO_SPACE_LEFT,                       /**< The requested setup operation could not be completed due to
                                                             insufficient buffer or rules size */
    GATEWAY_RESULT_CAN_INIT_ERROR,                      /**< The setup operation failed due to initialization error or
                                                             other hardware buffer issues e.g. no sufficient buffers */
    GATEWAY_RESULT_NO_ROUTE,                            /**< The routing does not exist for the given identifier */
    GATEWAY_RESULT_MAX
} E_GATEWAY_RESULT;

/**
 * Initialize a gateway forward rule list.
 *
 * @param rules         the rule table
 * @param rules_len     the length of the rule tables
 *
 * @return void
 */
void gateway_init(t_J1939_CAN_GW_Item *rules, U8 rules_len);

/**
 * Setup a gateway rule in the given rule array.
 *
 * This function shall be called when the driver buffer init function has been successfully
 * invoked and it has returned a handle value back to be associated with the mapping.
 *
 * @param rules                     the rules table
 * @param rules_len                 the length of the rules table
 * @param source_address_origin     the origin source address (received from the network)
 * @param source_address_target     the target source address (source address to be forwarded as)
 * @param write_handle              the associated write handle (can come e.g. from a driver invocation
 *                                  or other generic mapping...)
 *
 * @return  a @ref E_GATEWAY_RESULT value
 *              @ref GATEWAY_RESULT_NO_SPACE_LEFT: the rules table is already full. Enlarge the table.
 *              @ref GATEWAY_RESULT_OK           : association done correctly
 */
E_GATEWAY_RESULT gateway_setup_internal(t_J1939_CAN_GW_Item *rules, U8 rules_len, U8 source_address_origin, U8 source_address_target, U16 write_handle);

/**
 * Checks if a forwarding of the given CAN identifier has to be performed.
 * If so, the pointer parameters are filled with the required values.
 * If not, the result will indicate that.
 *
 * @param rules                     the rules table
 * @param rules_len                 the length of the rules table
 * @param can_identifier            the CAN identifier that has been received. This will be modified
 *                                  with the new CAN identifier to be forwarded in the specificed network
 *                                  (setup with @ref gateway_setup_internal)
 * @param handle                    the return value for the handle, if forward is required
 *
 * @return a @ref E_GATEWAY_RESULT value
 *              @ref GATEWAY_RESULT_NO_ROUTE     : the rules table does not contain the given source address
 *                                                 retrieved from the given CAN identifier. Do not use the
 *                                                 values (not set).
 *              @ref GATEWAY_RESULT_OK           : association done correctly
 */
E_GATEWAY_RESULT gateway_forward(t_J1939_CAN_GW_Item *rules, U8 rules_len, U32 *can_identifier, U16 *handle);

#endif /* J1939_STACK_SRC_GATEWAY_H_ */
