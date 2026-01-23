/**************************************************************************************************
 * Copyright (c) 2019 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 **************************************************************************************************
 *
 * \file
 *
 * Purpose
 *   The J1939 Noregon stack has no knowledge of physical / logical CAN channels hence only unique
 *   source addresses are supported. It might be the case that several ECU are connected to the J1939
 *   master unit via different CAN channels and have the same source address, breaking the stack.
 *   Therefore, a design for multiplexing and de-multiplexing of the source address has been developed
 *   to allow such use case to be considered.
 *
 *   If the mapping is not found, then the source address is just passing through as-is.
 *   Optionally the mapping can be dynamically built based on what it is received from the network.
 *
 *   If the mux-demux layer is not required, then the services shall not be called and used.
 *
 * Revisions
 *
 *   18-Mar-2019   LMO     Creation
 *
 *************************************************************************************************/


#ifndef J1939_STACK_SRC_MUX_DEMUX_H_
#define J1939_STACK_SRC_MUX_DEMUX_H_

#include "stdtypes.h"       /* data types definitions */

#define MUX_DEMUX_SOURCE_ADDRESS_MAX            (0xFFU)     /**< Define the maximum source address value that has special
                                                                 meaning based on the operated service. Check documentation
                                                                 of the specific service. */

/** Enumeration of the logical CAN channels */
typedef enum
{
    CAN_CHANNEL_0,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_1,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_2,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_3,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_4,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_5,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_6,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_7,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_8,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_9,                          /**< Definition of the logical CAN channel */
    CAN_CHANNEL_MAX                         /**< Definition of the number of supported logical CAN channels */
} E_CAN_CHANNEL_T;

/** The structure represents a mux-demux mapping entry which stores the channel
 *  where the mapping is operated, the original source address to be mapped from-to
 *  the mapped source address for de-mux activities.                                        */
typedef struct
{
    E_CAN_CHANNEL_T can_channel;            /** CAN Channel associated with the mapping     */
    U8              source_address;         /** Source address associated with the mapping  */
} S_MUX_DEMUX_ITEM;

/**
 * Initialization function that prepares the mux-demux layer to be used.
 * Shall be called exactly once at initialization, even if the mux-demux module
 * is not in use.
 */
void mux_demux_init(void);

/**
 * This function shall be called when there is the need to mux a phyiscal pair
 * of CAN_CHANNEL and SOURCE_ADDRESS entities to a muxed (logical) SOURCE_ADDRESS
 * entity.
 * Optionally, a mapping can be dynamically added if the given can_channel and source_address
 * pair is not yet in the mapping list.
 *
 * @param can_channel       the physical CAN channel to be muxed
 * @param source_address    the physical source address to be muxed
 * @param add_if_missing    TRUE: the mapping is inserted into the list if the mapping is not yet
 *                                present.
 *                          FALSE: the mapping is not inserted and the physical source address is returned
 *                                as-is.
 *
 * @return  the logical source address (multiplexed)
 */
U8 mux_demux_physical_to_logical(E_CAN_CHANNEL_T can_channel, U8 source_address, BOOL add_if_missing);

/**
 * This function shall be called when there is the need to demux a logical SOURCE_ADDRESS
 * value previously muxed with @ref mux_demux_physical_to_logical.
 *
 * The function searches for the mapping and, if existing, it returns the CAN_CHANNEL and
 * SOURCE_ADDRESS physical entities to the caller.
 *
 * @param muxed_source_address      the multiplexed source address to be demultiplexed
 * @param can_channel               pointer to a storage variable where the CAN_CHANNEL is
 *                                  saved to
 *
 * @return  the physical source address (demultiplexed)
 */
U8 mux_demux_logical_to_physical(U8 muxed_source_address, E_CAN_CHANNEL_T *can_channel);

#endif /* J1939_STACK_SRC_MUX_DEMUX_H_ */
