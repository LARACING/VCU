/**************************************************************************************************
 * Copyright (c) 2014 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 *************************************************************************************************/
/**********************************************************************************************//**
 * \file IO_UART.h
 *
 * \latexonly \hypertarget{IO_UART}{} \endlatexonly
 *
 * \brief IO Driver functions for UART communication.
 *
 * The UART driver uses the SCI module of the TMS570 CPU. The interface supports baud rates up to
 * 115.200 bit/s.
 *
 *  UART-API Usage:
 *    - \ref uart_examples "Examples for UART API functions"
 *
 * \section uart_examples UART Code Examples
 * \brief Examples for using the UART API
 * \subsection uart_init_examples Example for UART initialization
 * \code
 *
 *      // init UART driver
 *      IO_UART_Init(115200,                // baud rate
 *                   8,                     // 8 data bits
 *                   IO_UART_PARITY_NONE,   // no parity bit
 *                   1);                    // 1 stop bit
 *
 * \endcode
 *
 * \subsection uart_task_examples Example for UART task function call
 * \code
 *      char tx_data[20] = { '\0' };
 *      char rx_data[20] = { '\0' };
 *      ubyte2 tx_len = 0;
 *      ubyte2 rx_len = 0;
 *
 *      // get number of bytes in the transmit buffer
 *      IO_UART_GetTxStatus(&tx_len);
 *
 *      // check, if there's enough space in the transmit buffer
 *      if ((tx_len + sizeof(tx_data)) < IO_UART_BUFFER_LEN)
 *      {
 *          // transmit some data
 *          IO_UART_Write(tx_data,          // data buffer to be transmitted
 *                        sizeof(tx_data),  // size of the given data buffer
 *                        &tx_len);         // successfully queued data bytes
 *      }
 *
 *      // get number of bytes in the receive buffer
 *      IO_UART_GetRxStatus(&rx_len);
 *
 *      // check, if there's data in the receive buffer
 *      if (rx_len > 0)
 *      {
 *          // try to read some data
 *          IO_UART_Read(rx_data,           // destination data buffer
 *                       sizeof(rx_data),   // size of the given data buffer
 *                       &rx_len);          // number of read data bytes
 *      }
 *
 * \endcode
 *
 *************************************************************************************************/

#ifndef IO_UART_H_
#define IO_UART_H_

/**************************************************************************************************
 *
 * I N C L U D E S
 *
 *************************************************************************************************/

#include "IO_Driver.h"

/**************************************************************************************************
 *
 * D E F I N I T I O N S
 *
 *************************************************************************************************/

/**
 * \name Baudrate configuration
 *
 * Defines the minimum and maximum possible UART baudrate
 *
 * @{
 */
#define IO_UART_BAUDRATE_MIN     1200U  /**< Minimum UART baudrate */
#define IO_UART_BAUDRATE_MAX   115200U  /**< Maximum UART baudrate */
/** @} */

/**
 * \name UART buffer length
 *
 * Length (in bytes) of the internal buffers for transmission and reception
 *
 * @{
 */
#define IO_UART_BUFFER_LEN         512U  /**< 512 bytes   */
/** @} */

/**
 * \name Parity configuration
 *
 * Defines for the UART parity configuration
 *
 * @{
 */
#define IO_UART_PARITY_NONE        0x0U  /**< no parity   */
#define IO_UART_PARITY_EVEN        0x2U  /**< even parity */
#define IO_UART_PARITY_ODD         0x3U  /**< odd parity  */
/** @} */

/**************************************************************************************************
 *
 * F U N C T I O N S
 *
 *************************************************************************************************/

/**********************************************************************************************//**
 *
 * \brief Initialization of the UART communication driver.
 *
 *   Initialization of UART Serial Communication Driver
 *      - Enables module
 *      - Configures module for ASC
 *      - Initializes SW queue
 *
 * \param   baudrate        Baud rate in baud/s (1200 ... 115200)
 * \param   dbits           Number of data bits per frame (1 ... 8)
 * \param   par             Parity configuration, one of:
 *                              - \c #IO_UART_PARITY_NONE
 *                              - \c #IO_UART_PARITY_EVEN
 *                              - \c #IO_UART_PARITY_ODD
 * \param   sbits           Number of stop bits per frame (1 .. 2)
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                      everything fine
 * \retval #IO_E_INVALID_CHANNEL_ID      the given channel id does not exist or is not available on
 *                                       the used ECU variant
 * \retval #IO_E_CH_CAPABILITY           UART is not supported by the used ECU variant
 * \retval #IO_E_INVALID_PARAMETER       a given parameter is out of range
 * \retval #IO_E_CHANNEL_BUSY            the channel is already initialized
 * \retval #IO_E_DRIVER_NOT_INITIALIZED  the common driver init function has not been called before
 *
 **************************************************************************************************
 *
 * \remarks
 *   Module is initialized only once. To re-initialize the module, the function IO_UART_DeInit()
 *   needs to be called.
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_Init(ubyte4 baudrate,
                          ubyte1 dbits,
                          ubyte1 par,
                          ubyte1 sbits);

/**********************************************************************************************//**
 *
 * \brief Deinitialization of the UART
 *
 *   Allows re-initialization by \c IO_UART_Init()
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED channel has not been initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_DeInit(void);

/**********************************************************************************************//**
 *
 * \brief Read data from serial interface
 *
 *   Reads the data from the SW buffer.
 *
 * \param[out] data         Address where the read data shall be stored
 * \param len               Maximum size of data array
 * \param[out] rx_len       Actually read bytes
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_UART_BUFFER_FULL       SW receive queue is full and data has been lost
 * \retval #IO_E_UART_FRAMING           a framing error has been detected
 * \retval #IO_E_UART_OVERFLOW          HW receive buffer overrun
 * \retval #IO_E_UART_PARITY            parity check failed
 * \retval #IO_E_NULL_POINTER           null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED channel has not been initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_Read(ubyte1 * const data,
                          ubyte2 len,
                          ubyte2 * const rx_len);

/**********************************************************************************************//**
 *
 * \brief Write data to serial interface
 *
 *   Writes the data to the SW buffer and starts the transmission.
 *
 * \param[in] data          Address to the data which shall be written
 * \param len               Number of bytes in data array
 * \param[out] tx_len       Actually written bytes
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_UART_BUFFER_FULL       SW transmit queue is full, no data has been written
 * \retval #IO_E_NULL_POINTER           null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED channel has not been initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_Write(const ubyte1 * const data,
                           ubyte2 len,
                           ubyte2 * const tx_len);

/**********************************************************************************************//**
 *
 * \brief Retrieve the status of the receive buffer
 *
 *   Returns the current status of the receive buffer: new data available, error has occurred...
 *
 * \param[out] rx_len       Number of received data bytes in receive buffer
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_UART_BUFFER_FULL       SW receive queue is full and data has been lost
 * \retval #IO_E_UART_FRAMING           framing error detected
 * \retval #IO_E_UART_OVERFLOW          HW receive buffer overrun
 * \retval #IO_E_UART_PARITY            parity check failed
 * \retval #IO_E_NULL_POINTER           null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED channel has not been initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_GetRxStatus(ubyte2 * const rx_len);

/**********************************************************************************************//**
 *
 * \brief Retrieve the status of the transmit buffer
 *
 *
 * \param[out] tx_len       Number of remaining data bytes in transmit buffer
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     everything fine
 * \retval #IO_E_NULL_POINTER           null pointer has been passed
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED channel has not been initialized
 *
 *************************************************************************************************/
IO_ErrorType IO_UART_GetTxStatus(ubyte2 * const tx_len);

#endif /* IO_UART_H_ */
