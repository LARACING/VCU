/**************************************************************************************************
 * Copyright (c) 2014 TTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@ttcontrol.com
 *************************************************************************************************/
/**********************************************************************************************//**
 * \file IO_MPU.h
 *
 * \latexonly \hypertarget{IO_MPU}{} \endlatexonly
 *
 * \brief IO Driver functions for the Memory Protection Unit (MPU)
 *
 * The MPU allows the user to set the access attributes of certain parts of the memory.
 *
 * If an address falls in more than one enabled regions, the one with the greater ID has the higher
 * priority, and that will set the access rights.
 *
 * If a region is disabled, it doesn't affect the access rights in any way.
 *
 * \section mpu_init_section MPU initialization
 *
 * MPU regions can be initialized only after \c IO_Driver_Init().
 *
 * Once a region is initialized, it cannot be deinitialized, or overwritten with different
 * configuration parameters.
 *
 * \section mpu_access_section MPU access settings
 *
 * An MPU region's access settings can be combined by setting the read, write or execute bits in
 * the \c attributes parameter of \c IO_MPU_Init(), with the exception that an area cannot be
 * write-only, without read access.
 *
 * \section mpu_fault_section MPU fault handling
 *
 * When an MPU violation happens, a data abort is raised. This will call the notify callback
 * specified in the safety configuration of the IO driver, with the device number being
 * #DIAG_DEV_MAIN_CPU and the error code being #DIAG_E_DATA_ABORT. The address where the data
 * abort took place can be seen in the faulty value parameter.
 *
 * As a consequence, the application will go into safe state and the program execution will not
 * continue.
 *
 * \section mpu_subregions_section Subregions
 *
 * Every region is divided into 8 equally-sized subregions. The integrator can freely choose which
 * subregions of a region should be enabled, but it is not possible to disable all subregions. After
 * a region has been initialized, the list of its enabled subregions cannot be changed.
 *
 * For example, to enable subregion 5 through 7, the following needs to be used as the
 * \c subregions parameter of \c IO_MPU_Init():
 * \code
 *   IO_MPU_ENABLE_SUBREGION_5 | IO_MPU_ENABLE_SUBREGION_6 | IO_MPU_ENABLE_SUBREGION_7
 * \endcode
 *
 * All regions are enabled using the macro #IO_MPU_ENABLE_ALL_SUBREGIONS.
 *
 * \section mcu_examples_section MPU code example
 *
 * \code
 *
 *    // Initialize HY-TTC 500 driver
 *    io_error = IO_Driver_Init(NULL);
 *
 *    // Configure MPU region 0 (32 kBytes) for I/O Driver RAM protection (read only).
 *    io_error = IO_MPU_Init(IO_MPU_REGION_0,
 *                           (ubyte4)(&_ProtectedRAM_),
 *                           IO_MPU_SIZE_32_KB,
 *                           IO_MPU_ENABLE_ALL_SUBREGIONS,
 *                           IO_MPU_ACCESS_READ);
 *
 *    // Initialize MPU region 1 with read-only access on some custom data location.
 *    // This region will be enabled before calling the function with limited access
 *    // and disabled after it returns.
 *    io_error = IO_MPU_Init(IO_MPU_REGION_1,
 *                           CUSTOM_DATA_LOCATION,
 *                           CUSTOM_REGION_SIZE,
 *                           IO_MPU_ENABLE_ALL_SUBREGIONS,
 *                           IO_MPU_ACCESS_READ);
 *
 *    // start the RTC
 *    IO_RTC_StartTime(&timestamp);
 *
 *    // loop forever
 *    while (1)
 *    {
 *        io_error = IO_Driver_TaskBegin();
 *
 *        // application begin
 *
 *        // call a function without any active access limitations
 *        any_safe_function();
 *
 *        IO_MPU_Enable(IO_MPU_REGION_1);
 *        {
 *            // protection begin
 *
 *            // call a function with limited access rights on the custom memory area
 *            limited_function();
 *
 *            // protection end
 *        }
 *        IO_MPU_Disable(IO_MPU_REGION_1);
 *
 *        // call a function without any active access limitations
 *        any_safe_function();
 *
 *        IO_MPU_Enable(IO_MPU_REGION_1);
 *        IO_MPU_Enable(IO_MPU_REGION_0);
 *        {
 *            // unsafe code begin
 *
 *            // call a unsafe function with (highly) limited access rights
 *            unsafe_function();
 *
 *            // unsafe code end
 *        }
 *        IO_MPU_Disable(IO_MPU_REGION_0);
 *        IO_MPU_Disable(IO_MPU_REGION_1);
 *
 *        // application end
 *        io_error = IO_Driver_TaskEnd();
 *
 *        while (IO_RTC_GetTimeUS(timestamp) < CYCLE_TIME); // wait until cycle time has passed
 *        timestamp += CYCLE_TIME;                          // increase time stamp by cycle time
 *    }
 * \endcode
 *
 *
 * \page iodrv_prot I/O Driver memory protection
 *
 * Whenever the MPU module is being used for isolating unsafe considered code parts, it needs to be
 * ensured, that this unsafe code is not able to write to the I/O Driver RAM area. In other
 * words:\n
 * The I/O Driver data sections need to be protected from faulty write accesses, caused by unsafe
 * code parts.
 *
 * \section iodrv_prot_concept Concept
 *
 * The global data of the I/O Driver is linked to dedicated data sections. Those sections are
 * placed at the end of the device's internal RAM. Per default, those data sections allow full
 * access, which means full read and write permissions.
 *
 * When unsafe code is being used in a software project, it's mandatory that all the safe
 * considered parts of the data are protected against faulty accesses. Therefore the I/O Driver
 * memory needs to be in write protected state during the execution of unsafe code.
 *
 * To ensure this write protection (allow read only access), a dedicated MPU region for the I/O
 * Driver's data sections is needed.
 *
 * #IO_MPU_REGION_0 is being used for protecting the I/O Driver RAM. As a cause of this, it is
 * assumed, that whenever #IO_MPU_REGION_0 has been configured, it has been setup for covering
 * the I/O Driver data sections.
 *
 * It's recommended to primarily use
 * - #IO_MPU_REGION_1
 * - #IO_MPU_REGION_2
 * - #IO_MPU_REGION_3
 *
 * for custom memory protection. Custom means that those regions can be used for everything which
 * is beyond the I/O Driver memory protection against unsafe code.
 *
 * In case three regions are not enough or the concept of the I/O Driver memory protection can be
 * applied to custom data sections, #IO_MPU_REGION_0 can be shared with other safe considered data.
 * In this case, several circumstances are needed to be taken into account.
 *
 * \attention
 * Please be aware that #IO_MPU_REGION_0 is automatically unlocked/restored in all the I/O
 * Driver's background mechanisms:
 * - Whenever an error callback (#DIAG_ERROR_CB) or notify callback (#DIAG_NOTIFY_CB) is issued,
 * #IO_MPU_REGION_0 is in unlocked state during the callback handling.
 * - Whenever an FPU exception is asserted and the FPU exception callback (#IO_DRIVER_FPU_HANDLER)
 * is called, #IO_MPU_REGION_0 is in unlocked state during the callback handling.
 * - Whenever an RTC periodic event handler (#IO_RTC_EVENT_HANDLER) is executed, #IO_MPU_REGION_0
 * is in unlocked state during the event handling.
 *
 * \section iodrv_prot_conf Configuration
 *
 * In the default linker file the I/O Driver memories are configured with 32 kBytes in size and
 * placed at the end of the internal RAM. If #IO_MPU_REGION_0 is being used together with other
 * data, this size can be adjusted.
 *
 * \attention
 * Please be aware, that the two memory sections <em>io_driver_data_common</em> and
 * <em>shared_mem</em> are not allowed to be modified in size or in location. This would break the
 * interface to the bootloader!
 *
 * The linker symbol <em>_ProtectedRAM_</em> must be located at the the beginning of the I/O Driver
 * RAM, which shall be protected (inside the linker script file).\n
 * The expression <em>(ubyte4)(&_ProtectedRAM_)</em> contains therefore the start address of the
 * protected I/O driver RAM region.
 *
 * To use this linker symbol in the code, the following external definition is needed:
 *
 * \code
 *    // External linker symbol, from which the I/O Driver RAM start address will be taken
 *    extern ubyte4 _ProtectedRAM_;
 * \endcode
 *
 * By default, the I/O Driver RAM area is configured for a size of 32 kBytes. This value needs to
 * be taken in account when configuring the MPU region for the I/O Driver memory protection. It's
 * mandatory to specify the attribute #IO_MPU_ACCESS_READ as parameter. Doing so, will lead to the
 * following described mechanism:
 *
 * - <b>When the MPU region is enabled, the data sections of the I/O Driver are only allowing read
 * accesses. A write access will cause a data abort</b>
 * - <b>When the MPU region is disabled, the data sections of the I/O Driver do allow full
 * access.</b>
 *
 * \code
 *    // configure MPU region 0 (32 kBytes) for I/O Driver RAM protection (read only)
 *    io_error = IO_MPU_Init(IO_MPU_REGION_0,
 *                           (ubyte4)(&_ProtectedRAM_),
 *                           IO_MPU_SIZE_32_KB,
 *                           IO_MPU_ENABLE_ALL_SUBREGIONS,
 *                           IO_MPU_ACCESS_READ);
 * \endcode
 *
 * \section iodrv_prot_usage Usage
 *
 * It is <b>NOT</b> sufficient to just initialize and configure the needed MPU region(s). Whenever
 * unsafe considered code is executed, the I/O Driver RAM needs to be protected from illegal
 * accesses among of some custom regions:
 *
 * \code
 *    // please note, that the curly braces below are not for functional purposes.
 *    // instead, those are only used for structural reasons.
 *
 *    // turn on protection of I/O Driver RAM
 *    io_error = IO_MPU_Enable(IO_MPU_REGION_0);
 *    {
 *        // unsafe code
 *
 *        // I/O Driver RAM is now configured for read only permissions
 *
 *        // write accesses to the I/O Driver memory sections will cause a data abort
 *
 *        // do not call any IO_*() functions in here!
 *    }
 *    // turn off protection of I/O Driver RAM
 *    io_error = IO_MPU_Disable(IO_MPU_REGION_0);
 * \endcode
 *
 *************************************************************************************************/

#ifndef IO_MPU_H_
#define IO_MPU_H_

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

/** \defgroup mpu_macros MPU macro definitions
 * @{
 */

/** \defgroup mpu_regions User MPU regions
 * @{
 */
/** User MPU region 0 (lowest priority region) */
#define IO_MPU_REGION_0         0U

/** User MPU region 1 */
#define IO_MPU_REGION_1         1U

/** User MPU region 2 */
#define IO_MPU_REGION_2         2U

/** User MPU region 3 (highest priority region) */
#define IO_MPU_REGION_3         3U
/** @} mpu_regions */

/** \defgroup mpu_subregions MPU subregions
 * @{
 */
/** This MPU setting enables subregion 0 */
#define IO_MPU_ENABLE_SUBREGION_0         0x01U

/** This MPU setting enables subregion 1 */
#define IO_MPU_ENABLE_SUBREGION_1         0x02U

/** This MPU setting enables subregion 2 */
#define IO_MPU_ENABLE_SUBREGION_2         0x04U

/** This MPU setting enables subregion 3 */
#define IO_MPU_ENABLE_SUBREGION_3         0x08U

/** This MPU setting enables subregion 4 */
#define IO_MPU_ENABLE_SUBREGION_4         0x10U

/** This MPU setting enables subregion 5 */
#define IO_MPU_ENABLE_SUBREGION_5         0x20U

/** This MPU setting enables subregion 6 */
#define IO_MPU_ENABLE_SUBREGION_6         0x40U

/** This MPU setting enables subregion 7 */
#define IO_MPU_ENABLE_SUBREGION_7         0x80U

/** This MPU setting enables all subregions */
#define IO_MPU_ENABLE_ALL_SUBREGIONS      0xFFU
/** @} mpu_subregions */

/** \defgroup mpu_sizes MPU region sizes
 * @{
 */
/** This size setting defines the memory region size to be 32 bytes */
#define IO_MPU_SIZE_32_B        0x00000020UL

/** This size setting defines the memory region size to be 64 bytes */
#define IO_MPU_SIZE_64_B        0x00000040UL

/** This size setting defines the memory region size to be 128 bytes */
#define IO_MPU_SIZE_128_B       0x00000080UL

/** This size setting defines the memory region size to be 256 bytes */
#define IO_MPU_SIZE_256_B       0x00000100UL

/** This size setting defines the memory region size to be 512 bytes */
#define IO_MPU_SIZE_512_B       0x00000200UL

/** This size setting defines the memory region size to be 1 KB (1024 bytes) */
#define IO_MPU_SIZE_1_KB        0x00000400UL

/** This size setting defines the memory region size to be 2 KB (2048 bytes) */
#define IO_MPU_SIZE_2_KB        0x00000800UL

/** This size setting defines the memory region size to be 4 KB (4096 bytes) */
#define IO_MPU_SIZE_4_KB        0x00001000UL

/** This size setting defines the memory region size to be 8 KB (8192 bytes) */
#define IO_MPU_SIZE_8_KB        0x00002000UL

/** This size setting defines the memory region size to be 16 KB (16,384 bytes) */
#define IO_MPU_SIZE_16_KB       0x00004000UL

/** This size setting defines the memory region size to be 32 KB (32,768 bytes) */
#define IO_MPU_SIZE_32_KB       0x00008000UL

/** This size setting defines the memory region size to be 64 KB (65,536 bytes) */
#define IO_MPU_SIZE_64_KB       0x00010000UL

/** This size setting defines the memory region size to be 128 KB (131,072 bytes) */
#define IO_MPU_SIZE_128_KB      0x00020000UL

/** This size setting defines the memory region size to be 256 KB (262,144 bytes) */
#define IO_MPU_SIZE_256_KB      0x00040000UL

/** This size setting defines the memory region size to be 512 KB (524,288 bytes) */
#define IO_MPU_SIZE_512_KB      0x00080000UL

/** This size setting defines the memory region size to be 1 MB (1,048,576 bytes) */
#define IO_MPU_SIZE_1_MB        0x00100000UL

/** This size setting defines the memory region size to be 2 MB (2,097,152 bytes) */
#define IO_MPU_SIZE_2_MB        0x00200000UL

/** This size setting defines the memory region size to be 4 MB (4,194,304 bytes) */
#define IO_MPU_SIZE_4_MB        0x00400000UL

/** This size setting defines the memory region size to be 8 MB (8,388,608 bytes) */
#define IO_MPU_SIZE_8_MB        0x00800000UL

/** This size setting defines the memory region size to be 16 MB (16,777,216 bytes) */
#define IO_MPU_SIZE_16_MB       0x01000000UL

/** This size setting defines the memory region size to be 32 MB (33,554,432 bytes) */
#define IO_MPU_SIZE_32_MB       0x02000000UL

/** This size setting defines the memory region size to be 64 MB (67,108,864 bytes) */
#define IO_MPU_SIZE_64_MB       0x04000000UL
/** @} mpu_sizes */

/** \defgroup mpu_attributes MPU region access attributes
 * @{
 */
/** This access setting doesn't allow any access to the memory region. */
#define IO_MPU_ACCESS_NONE              0x0U

/** This access setting allows only read access to the memory region. */
#define IO_MPU_ACCESS_READ              0x1U

/** This access setting allows read and write accesses to the memory region. */
#define IO_MPU_ACCESS_READ_WRITE        0x3U

/** This access setting allows read and execute accesses to the memory region. */
#define IO_MPU_ACCESS_READ_EXECUTE      0x5U

/** This access setting allows any access to the memory region (read, write and execute). */
#define IO_MPU_ACCESS_ANY               0x7U
/** @} mpu_attributes */

/** \defgroup mpu_policies MPU protection policies
 * @{
 */

/** I/O Driver deactivates #IO_MPU_REGION_0 for its internal tasks.
 *  This is the behavior of I/O Driver version 3.0.0 and earlier.
 *  This setting is the default (i.e. it will be used if \c IO_MPU_Policy() is never called)
 *  to maintain backwards compatibility.
 */
#define IO_MPU_POLICY_REGION0           0x0U

/** I/O Driver does not make any changes to the MPU configuration in its internal tasks.
 *  This setting is used when the MPU is fully controlled by an external software component, e.g. SafeRTOS or CODESYS.
 *  User applications can use this setting if their configuration of the \ref mpu_regions "User MPU regions"
 *  does not obstruct the execution of the I/O Driver internal tasks.
 */
#define IO_MPU_POLICY_OFF               0x1U

/** I/O Driver deactivates all \ref mpu_regions "User MPU regions" for its internal tasks.
 *  With this setting, users can use all \ref mpu_regions "User MPU regions" freely as the necessary protection
 *  to implement the Freedom from Interference in the application.
 */
#define IO_MPU_POLICY_ALLREGIONS        0x2U
/** @} mpu_policies */

/** @} mpu_macros */

/**************************************************************************************************
 *
 * F U N C T I O N S
 *
 *************************************************************************************************/

/**********************************************************************************************//**
 *
 * \brief Initializes an MPU region.
 *
 * \param region_id         Region ID. One of the macros in the
 *                          \ref mpu_regions "MPU regions group".
 *
 * \param start_address     Start address of the region. Must be a multiple of the region size.
 *
 * \param size              Size of the region. One of the macros in the
 *                          \ref mpu_sizes "MPU region sizes group".
 *
 * \param subregions        Defines which subregions of this region are enabled, where the
 *                          N-th least significant bit denotes the N-th subregion.
 *                          For code examples see \ref mpu_subregions_section
 *                          "Example of using MPU subregions".
 *
 * \param attributes        Access attributes of the region. One of the macros in the
 *                          \ref mpu_attributes "MPU region attributes group".
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                      Everything went fine.
 * \retval #IO_E_BUSY                    The MPU region has already been initialized once.
 * \retval #IO_E_INVALID_PARAMETER       An invalid parameter was given.
 * \retval #IO_E_DRIVER_NOT_INITIALIZED  The common driver init function has not been called before
 *
 **************************************************************************************************
 *
 * \remarks
 * The region must lie entirely (including its beginning and end):
 *  - between 0x0000.0000 and 0x002F.FFFF for code regions (internal flash memory),
 *  - between 0x0800.0000 and 0x0803.FFFF for regions in the internal RAM,
 *  - between 0x6000.0000 and 0x601F.FFFF for regions in the external RAM,
 *  - between 0x6400.0000 and 0x647F.FFFF for regions in the external flash memory.
 *  - between 0xF000.0000 and 0xF07F.FFFF for regions in the OTP, ECC, and application configuration data region
 *    (internal flash memory).
 *  - between 0xFC00.0000 and 0xFFFF.FFFF for regions in the peripherals address space.
 *
 *************************************************************************************************/
IO_ErrorType IO_MPU_Init(ubyte1 region_id,
                         ubyte4 start_address,
                         ubyte4 size,
                         ubyte1 subregions,
                         ubyte1 attributes);

/**********************************************************************************************//**
 *
 * \brief Enables (activates) the given MPU region configuration
 *
 * \param region_id         Region ID. One of the macros in the
 *                          \ref mpu_regions "MPU regions group".
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     Everything went fine.
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED The given region has not been initialized.
 * \retval #IO_E_MPU_REGION_ENABLED     The given region is already enabled.
 * \retval #IO_E_INVALID_PARAMETER      An invalid region ID was given.
 *
 *************************************************************************************************/
IO_ErrorType IO_MPU_Enable(ubyte1 region_id);

/**********************************************************************************************//**
 *
 * \brief Disables (deactivates) the given MPU region configuration
 *
 * \param region_id         Region ID. One of the macros in the
 *                          \ref mpu_regions "MPU regions group".
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                     Everything went fine.
 * \retval #IO_E_CHANNEL_NOT_CONFIGURED The given region has not been initialized.
 * \retval #IO_E_MPU_REGION_DISABLED    The given region is already disabled.
 * \retval #IO_E_INVALID_PARAMETER      An invalid region ID was given.
 *
 *************************************************************************************************/
IO_ErrorType IO_MPU_Disable(ubyte1 region_id);

/**********************************************************************************************//**
 *
 * \brief Configures the MPU protection policy.
 *
 * \param policy            The policy that will be used for handling the \ref mpu_regions "User MPU regions"
 *                          in the I/O Driver internal tasks:
 *                              - \c #IO_MPU_POLICY_REGION0
 *                              - \c #IO_MPU_POLICY_OFF
 *                              - \c #IO_MPU_POLICY_ALLREGIONS
 * \note
 * The I/O Driver defaults to use the \c #IO_MPU_POLICY_REGION0 setting if this function is not called.
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                      Operation successful.
 * \retval #IO_E_INVALID_PARAMETER       The specified policy is not valid.
 *
 *************************************************************************************************/
IO_ErrorType IO_MPU_Policy (ubyte4 policy);

/**********************************************************************************************//**
 *
 * \brief Enables (activates) all initialized User MPU regions
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                      Operation successful.
 * \retval #IO_E_MPU_REGION_ENABLED      One of the regions is already enabled.
 * \retval #IO_E_DRIVER_NOT_INITIALIZED  The common driver initialization function has not been called before.
 *
*************************************************************************************************/
IO_ErrorType IO_MPU_EnableAll (void);

/**********************************************************************************************//**
 *
 * \brief Disables (deactivates) all initialized User MPU regions
 *
 * \return #IO_ErrorType
 * \retval #IO_E_OK                      Operation successful.
 * \retval #IO_E_MPU_REGION_DISABLED     One of the regions is already disabled.
 * \retval #IO_E_DRIVER_NOT_INITIALIZED  The common driver initialization function has not been called before.
 *
*************************************************************************************************/
IO_ErrorType IO_MPU_DisableAll (void);

#endif /* IO_MPU_H_ */
