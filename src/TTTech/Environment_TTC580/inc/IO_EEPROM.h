/**************************************************************************************************
 * Copyright (c) 2014 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 *************************************************************************************************/
/**********************************************************************************************//**
 * \file IO_EEPROM.h
 *
 * \latexonly \hypertarget{IO_EEPROM}{} \endlatexonly
 *
 * \brief IO Driver functions for external EEPROM/FRAM.
 *
 *  The EEPROM driver functions allow writing to and reading from the external SPI EEPROM or FRAM
 *  (depending on the product variant) 
 *
 *  The communication with the EEPROM/FRAM is handled in a cyclic manner. EEPROM/FRAM operations take
 *  multiple cycles. A write as well as a read process is only triggered by calling the respective
 *  function. A status function is provided which returns whether the driver has finished the last
 *  task or not.
 *
 *  EEPROM-API Usage:
 *   - \ref eep_examples "Examples for EEPROM API functions"
 *
 * \section eep_examples EEPROM Code Examples
 * \brief Examples for using the EEPROM API
 * \subsection eeprom_init_example Example for EEPROM initialization
 * \details EEPROM needs to be initialized after \c IO_Driver_Init().
 * \code
 *      // initialize driver
 *      IO_Driver_Init(NULL);
 *
 *      // initialize EEPROM module
 *      IO_EEPROM_Init();
 * \endcode
 *
 * \subsection eeprom_write_example Example for EEPROM write
 * \code
 *      ubyte1 data[6] = {0, 1, 2, 3, 4, 5};
 *
 *      // check if EEPROM is busy
 *      if (IO_EEPROM_GetStatus() == IO_E_OK)
 *      {
 *          // if not busy write data
 *          IO_EEPROM_Write(0,      // offset
 *                          6,      // length
 *                          data);  // data buffer
 *      }
 *
 *      // write is complete when IO_EEPROM_GetStatus() returns IO_E_OK again.
 * \endcode
 *
 * \subsection eeprom_read_example Example for EEPROM read
 * \code
 *      ubyte1 data[2000] = {0};
 *
 *      // check if EEPROM is busy
 *      if (IO_EEPROM_GetStatus() == IO_E_OK)
 *      {
 *          // if not busy start reading
 *          IO_EEPROM_Read(0,       // offset
 *                         2000,    // length
 *                         data);   // data buffer
 *      }
 *
 *      // data is not yet available!!
 *      // data is available when IO_EEPROM_GetStatus() returns IO_E_OK again.
 * \endcode
 *
 *************************************************************************************************/

#ifndef IO_EEPROM_H_
#define IO_EEPROM_H_

/**************************************************************************************************
 *
 * I N C L U D E S
 *
 *************************************************************************************************/

#include "IO_Driver.h"

/**************************************************************************************************
 *
 * F U N C T I O N S
 *
 *************************************************************************************************/

/**********************************************************************************************//**
 *
 * \brief Initialization of the EEPROM driver.
 *
 *   This function initializes the EEPROM driver by performing the following tasks:
 *      - Initialization of all internal data structures
 *      - Initialization of all internal buffers
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_INVALID_CHANNEL_ID     EEPROM/FRAM is not supported by the used ECU variant
 * \retval #IO_E_CHANNEL_BUSY           module has been initialized before
 * \retval #IO_E_DRIVER_NOT_INITIALIZED the common driver init function has not been called before
 *
 **************************************************************************************************
 *
 * \remarks
 *   Module is initialized only once.\n
 *   To re-initialize the module, the function \c IO_EEPROM_DeInit() needs to be called.
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_Init(void);

/**********************************************************************************************//**
 *
 * \brief Deinitializes the EEPROM driver.
 *
 *   Deinitializes the module.\n
 *   Allows re-initialization by \c IO_EEPROM_Init()
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED the module is not initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_DeInit(void);

/**********************************************************************************************//**
 *
 * \brief Read data from the EEPROM/FRAM
 *
 *   The function only triggers a read operation.\n
 *   The read operation can take several cycles to be completed, depending on the SPI load and the
 *   amount of data to be read.
 *
 *   The read data is available on the address where the data parameter points to as soon as the
 *   read operation is finished. The state can be polled using the \c IO_EEPROM_GetStatus()
 *   function.
 *
 * \param offset            EEPROM/FRAM memory offset (0..65535 for EEPROM, 0..32767 for FRAM)
 * \param length            Length of data to be read (1..65536 for EEPROM, 1..32768 for FRAM)
 * \param[out] data         Pointer to the address where the data shall be stored to
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_BUSY                   EEPROM module is still busy
 * \retval #IO_E_INVALID_PARAMETER      length is zero
 * \retval #IO_E_EEPROM_RANGE           invalid address offset or range
 * \retval #IO_E_NULL_POINTER           a null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED the module is not initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_Read(ubyte2 offset,
                            ubyte4 length,
                            ubyte1 * const data);

/**********************************************************************************************//**
 *
 * \brief Write data to the EEPROM/FRAM
 *
 *   The function triggers a write operation.\n
 *   The write operation can take several cycles to be completed, depending on the SPI load and the
 *   amount of data to be written.
 *
 *   The write operation is completed as soon as the SPI communication has been finished. The state
 *   can be polled using the \c IO_EEPROM_GetStatus() function.
 *
 * \param offset            EEPROM/FRAM memory offset (0..65535 for EEPROM, 0..32767 for FRAM)
 * \param length            Length of the data to be written (1..65536 for EEPROM, 1..32768 for FRAM)
 * \param[in] data          Pointer to the data to be written
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_BUSY                   EEPROM module is still busy
 * \retval #IO_E_INVALID_PARAMETER      length is zero
 * \retval #IO_E_EEPROM_RANGE           invalid address offset or range
 * \retval #IO_E_NULL_POINTER           a null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED the module is not initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_Write(ubyte2 offset,
                             ubyte4 length,
                             const ubyte1 * const data);

/**********************************************************************************************//**
 *
 * \brief Returns the status of the EEPROM driver
 *
 *   Returns whether the EEPROM/FRAM is idle or if a read or write operation is ongoing.
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine, driver is idle
 * \retval #IO_E_BUSY                   a read or a write operation is
 *                                      ongoing, driver is busy.
 *
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED the module is not initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_GetStatus(void);

/**********************************************************************************************//**
 *
 * \brief Triggers the internal processing and gets status of EEPROM device.
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine, driver is idle
 * \retval #IO_E_BUSY                   a read or a write operation is
 *                                      ongoing, driver is busy.
 * \retval #IO_E_INTERNAL_CSM           an internal error occurred
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED the module is not initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_EEPROM_Process(void);

#endif /* IO_EEPROM_H_ */
