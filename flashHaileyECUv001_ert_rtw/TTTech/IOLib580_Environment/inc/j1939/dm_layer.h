/******************************************************************************
* 
*                 Copyright 2008 Noregon Systems, inc.
*                         All rights reserved
*
*   The information contained herein is proprietary data and is not for 
*   dissemination or disclosure, in whole or in part, for any purpose
*   except as authorized in writing by Noregon Systems, inc.
*
* 
*  dm_layer.h
*
*  DESCRIPTION: Development of the Diagnostic Message Layer.
*
*  History:
* ________ ___ ___                   ___________________________________________________________
*  DATE    Ver WHO                   WHAT
* ________ ___ ___                   ___________________________________________________________
* 04/18/08     CDM (Noregon Systems) Initial
* 10/03/16     LMO (TTControl)       addition of NUMBER_DTC_MAX define
* 20/09/16     LMO (TTControl)       several improvements, see dm_layer.c
* 28/01/19     LMO (TTControl)       Library has been improved: reception of DM1 Faults has been added
*                                    (decoding and query functions)
* 19/03/19     LMO (TTControl)       Library improved with the mux-demux module: allow reception of
*                                    same source address on different CAN channels and adapted APIs
*                                    to handle the concept of CAN channels.
*                                    Added lamp query API and reworked some APIs.
*
******************************************************************************/

#ifndef _dm_layer_h
#define _dm_layer_h

/* J1939 includes (LMO: added them because they were missing)*/
#include "stdtypes.h"
#include "j1939.h"
#include "transpor.h"
#include "mux_demux.h"          /* multiplexing and demultiplexing module for enabling support to CAN channels */

#define J1939_73

/** Maximum number of supported DTCs
 *  1785 bytes supported by the J1939 protocol
 *  subtract 2 bytes for the lamps and divide by 4 bytes per DTC.
 */
#define DTC_SIZE            4U
#define NUMBER_DTC_MAX      ((J1939_MAX_MESSAGE_LENGTH - 2U) / DTC_SIZE)
#define DM1_OC_MAX          126U
#define DTC_NOT_FOUND       0xFFFFU

#define DTC_SPN_MAX         524287U     /**< 19 bits */
#define DTC_FMI_MAX         31U         /**< 5 bits */

#define DTC_FMI_JOLLY       0xFFU       /**< Used in the DM1 lookup function to indicate that whatever FMI is set, then it is a match */

#define DTC_FMI_MASK        0x1FU       /**< Mask bits for the FMI field */

#define DTC_DATA_TO_FMI(x,y)            ((((x)[((y) + 2U)]) & 0x1FU))
#define DTC_DATA_TO_OC(x,y)             ((((x)[((y) + 3U)]) & 0x7FU))
#define DTC_DATA_TO_SPN(x, y)           ((((U32)(x)[((y) + 0U)]) & 0xFFU) | (((U32)((x)[((y) + 1U)]) & 0xFFU) << 8U) | ((((U32)((x)[((y) + 2U)]) & 0xE0) >> 5) << 16))

#define DM1_LAMPS_SIZE                  ((2U))  /** The number of bytes that are composing the "Lamps" information in a DM1 Fault */

#define DM1_RX_NODE_NUM_MAX             (16U)   /**< This defines the number of maximum supported nodes for receiving DM1 data from */
#define DM1_RX_FAULT_NUM_MAX            (64U)   /**< This defines the number of maximum simultaneous supported DTCs Faults for receiving DM1 data, per ECU */

#define DM1_RX_NODE_ADDR_NOT_RECEIVED   (0xFFU)   /**< This defines the marker that indicates the node has not been received yet */

#define DTC_DATA_TO_FMI(x,y)            ((((x)[((y) + 2U)]) & 0x1FU))
#define DTC_DATA_TO_OC(x,y)             ((((x)[((y) + 3U)]) & 0x7FU))
#define DTC_DATA_TO_SPN(x, y)           ((((U32)(x)[((y) + 0U)]) & 0xFFU) | (((U32)((x)[((y) + 1U)]) & 0xFFU) << 8U) | ((((U32)((x)[((y) + 2U)]) & 0xE0) >> 5) << 16))

#define DM1_TIMEOUT_TIME_MS             (30000UL)                       /**< Timeout timer for DM1 timeout condition detection [ms] */
#define DM1_TIMEOUT_TIME_CYCLES         (DM1_TIMEOUT_TIME_MS / TICK)    /**< 1 Tick = the number of milliseconds between periodic calls */

/** Enumeration of the errors that can happen in the DM1 reception phase */
typedef enum {
    DM1_RX_ERROR_OK,                        /**< No error encountere */
    DM1_RX_ERROR_NODE_OVERFLOW,             /**< The reception of the last DM1 stream for source_address cannot be stored due to
                                                 maximum number of nodes already received */
    DM1_RX_ERROR_FAULT_OVERFLOW,            /**< The decoding of the last received DM1 stream has generated more faults
                                                 than the maximum configured number of storable faults per node */
    DM1_RX_ERROR_UNDERFLOW,                 /**< The received DM1 stream contains unaligned data e.g. incomplete Fault or too-small message */
    DM1_RX_ERROR_MAX                        /**< Placeholder for maximum entry */
} DM1_RX_ERROR_T;

typedef enum {
    DM2_SYNC_STATE_IDLE,
    DM2_SYNC_STATE_READ_DATA,
    DM2_SYNC_STATE_WRITE_DATA,
    DM2_SYNC_STATE_WAIT
} E_DM2_SYNC_STATE;

typedef struct {
	U32 SPN;
	U8  FMI;
	U8  count;
/*	U32 operation_at_cycle;  */
} FAULT_T;

typedef struct {
	U8 engine_torque_mode;
	U8 boost;
	U16 engine_speed;
	U8 engine_percent_load;
	U8 engine_coolant_temp;
	U16 vehicle_speed;
	U8* manufacturer_info;
	U8 manufacturer_info_length;
} FREEZE_FRAME_T;

typedef struct {
	FAULT_T fault;
	FREEZE_FRAME_T freeze_frame;
} ACTIVE_FAULT_T;
	
typedef struct {
	U8 malfunction_indicator;
	U8 red_stop;
	U8 amber_warning;
	U8 protect;
	U8 flash_malfunction_indicator;
	U8 flash_red_stop;
	U8 flash_amber_warning;
	U8 flash_protect;
} LAMP_STATUS_T;

/** Structure that holds information on a J1939 node about its active faults */
typedef struct {
    E_CAN_CHANNEL_T   channel;                        /**< The logical CAN channel where the ECU is lying   */
    U8                source_address;                 /**< The source address that describes the node       */
    FAULT_T           faults[DM1_RX_FAULT_NUM_MAX];   /**< The faults that are associated to the node       */
    U16               fault_iteration_index;          /**< The iteration index for the @ref DM1_RX_next API */
    LAMP_STATUS_T     lamps;                          /**< The status of the received lamps                 */
    U32               timeout_timer;                  /**< Timeout timer counter [periodic layer cycles]    */
} DM1_RX_FAULTS_T;

/* Fault Action */


#define     UPDATE      0
#define     CREATE      1
#define     DELETE      2

extern HUGE_U8 node_addr[];  /* Array of valid node address. The first 
				              * element contains the preferred node address.
				              * The last element contains the global address.
				              */  
				  
void dm_init(U32 cycle_time);
void send_DM1(U8 da);

/**
 * This function initiates DM2 transmission.
 * On function call the current DM2 data is stored in the ougoing buffer and BAM transmission
 * is started on the network, if possible, and no other BAM on the same channel is in progress.
 */
void send_DM2(U8 da);
void send_DM4(U8 da);

/**
 * This function encapsulates the periodic logic that is done into the DM layer (J1939-21).
 * This function shall be periodically called, usually every 10 milliseconds.
 *
 * @param DM2_storage_cycle_time    0 : do not automatically synchronize the DM2 data with the storage
 *                                  >0: on DM2 change, wait this amount of cycles before checking if DM2
 *                                      data has changed and to possibly write on the storage
 */
void dm_periodic(U32 DM2_storage_cycle_time);

U16 get_number_active_faults(void);

/**
 * Get the number of currently stored DM2 DTCs
 * @return  the number of active DM2 DTCs
 */
U16 DM2_fault_number(void);

void get_freeze_frame(U16 index, FREEZE_FRAME_T* ff);
void get_freeze_frame_manufacturer_info(U16 index, U8* m_info);

/**
 * This function is used to either insert (CREATE) or update (UPDATE) a fault.
 * @param fault     the fault to be inserted or updated
 */
void set_fault_active(FAULT_T *fault);

/**
 * The function is used to delete the given fault (looked up by SPN)
 * @param fault     the fault (SPN) to be deleted
 */
void set_fault_inactive(const FAULT_T * const fault);

/**
 * Return the fault at the given index of the DM2 data.
 * @param index     the index of the fault
 * @param fault     the copied fault data
 * @return  TRUE : index is valid
 *          FALSE: index is out of range
 */
bool DM2_get_fault(U16 index, FAULT_T * const fault);

/**
 * This function is used to either insert (CREATE) or update (UPDATE) a fault.
 * @param fault     the fault to be inserted or updated
 */
void DM2_fault_create_or_update(FAULT_T *fault);

/**
 * The function is used to delete the given fault (looked up by SPN)
 * @param fault     the fault (SPN) to be deleted
 */
void DM2_fault_delete(const FAULT_T * const fault);

/**
 * The function can be invoked when the DM2 data is required to be
 * cleared, regardless of engine speed state.
 * The function does not clear DM2 data until the initial read phase of the
 * storage has completed (i.e. storage data is synchronized to RAM).
 *
 * @return TRUE  : DM2 data could be erased
 *         FALSE : DM2 data could not be erased now, try later.
 */
bool DM2_fault_clear(void);

/**
 * Set the current engine speed. Engine speed value is used by DM3 logic
 * to prevent DM2 clear action if engine is running.
 * Note: engine is considered OFF if the value is 0.
 * @param es    the current engine speed
 */
void set_engine_speed(U16 es);

/**
 * Set the lamps status of the DM1 data
 * @param lamps the requested lamps status
 */
void set_active_lamp_status(LAMP_STATUS_T lamps);

/**
 * Set the lamps status of the DM2 data
 * @param lamps the requested lamps status
 */
void DM2_set_lamp_status(LAMP_STATUS_T lamps);

/**
 * This function is invoked externally on the reception of a J1939 message.
 * The message can be either a DM layer (J1939-21) request or other requests.
 * Unrelevant / Invalid requests are silently discarded.
 *
 * @param rx_m  the incoming J1939 messages
 */
void check_for_DM_message(J1939_RX_MESSAGE_T *rx_m);

/**
 * This function forces the synchronization with the persistent
 * storage. This function shall be called until the return value
 * is equal to "TRUE" which means synchronization is now done i.e.
 * the DM2 data is now persistently stored and the ECU for
 * example can be shutdown safely without losing data.
 *
 * Please note: once the function returns TRUE it shall not be called
 *              again. Calling it again makes (possibly) another synchronization
 *              to start.
 *
 * @return  TRUE : the synchronization has been performed
 *          FALSE: the synchronization is in progress
 */
BOOL DM2_synchronize(void);

/**
 * Query the DM layer for initialization state.
 * @return  TRUE : the layer is fully initialized and can be used
 *          FALSE: the layer is being initialized
 */
BOOL DM_initialized(void);

/* Functions for the DM1 RX (reception) from remote nodes */

/**
 * Return the currently detected error while processing DM1 the
 * data stream.
 * The function shall be called cyclically if required.
 * Not required for functionality, but useful for diagnostics.
 * A call to the function resets the internal error till the
 * occurrence of a new error condition.
 * This function can be called after the periodic function.
 *
 * @return DM1_RX_ERROR_T value
 */
DM1_RX_ERROR_T DM1_RX_get_error(void);

/**
 * Received DM1 faults query function to query for a specific SPN,
 * getting information if the fault is either active or non-active
 * and the additional fault data, if specified.
 *
 * @param can_channel       the logical CAN channel where the requested source address is lying
 * @param source_address    the source address of the node to be queried
 * @param SPN               the Suspect Parameter Number of the fault to be queried
 *
 * @return  the FAULT_T data if fault is active (includes SPN, FMI, OC)
 *          NULL : fault not found and therefore not active currently
 */
const FAULT_T* DM1_RX_query(E_CAN_CHANNEL_T can_channel, U8 source_address, U16 SPN);

/**
 *
 * The function is used to iterate the received (and therefore, active) faults from
 * a given node (identified by its source address).
 *
 * The function returns a NULL pointer when:
 * - fault list is empty
 * - DM1 message never received for selected node
 * - once the list has been completely iterated (next iteration will restart from the first fault)
 *
 * NOTE: the returned data pointer shall not be modified nor used directly in the application
 * code, since it can change its value if faults are changing. A copy of the structure shall
 * be done.
 * Though, it can be considered valid until the next J1939 periodic call execution.
 *
 * @param can_channel       the CAN channel where the node is present
 * @param source_address    the source address of the node whose faults are to be iterated
 *
 * @return  pointer to the current iterated fault or NULL pointer as described above.
 */
const FAULT_T* DM1_RX_next(E_CAN_CHANNEL_T can_channel, U8 source_address);

/**
 *
 * The function is used to get the lamp status that has been recently received by the
 * remote ECU defined by the given source address on the given CAN channel.
 *
 * The function returns a NULL pointer when:
 * - lamp status has never been received for the selected node
 *
 * NOTE: the returned data pointer shall not be modified nor used directly in the application
 * code, since it can change its value if faults are changing. A copy of the structure shall
 * be done.
 * Though, it can be considered valid until the next J1939 periodic call execution.
 *
 * @param can_channel       the CAN channel where the node is present
 * @param source_address    the source address of the node whose faults are to be iterated
 *
 * @return  pointer to the lamp status or NULL pointer as described above.
 */
const LAMP_STATUS_T* DM1_RX_lamp_status(E_CAN_CHANNEL_T can_channel, U8 source_address);

#endif
