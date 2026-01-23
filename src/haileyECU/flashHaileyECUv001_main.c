/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001_main.c
 *
 * Code generated for Simulink model 'flashHaileyECUv001'.
 *
 * Model version                  : 10.66
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec  9 19:15:42 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/**************************************************************************************************
 * Includes
 *************************************************************************************************/
#include "APDB.h"
#include "IO_Driver.h"
#include "IO_RTC.h"
#include "flashHaileyECUv001.h"
#include "flashHaileyECUv001_private.h"

/**************************************************************************************************
 * Defines
 *************************************************************************************************/
/* modify to adjust application version */
#define MAJOR_NUMBER                   0U
#define MINOR_NUMBER                   1U
#define REVISION_NUMBER                1U

/* modify to adjust application cycle time */
#define CYCLE_TIME_US                  (10U*1000U)

/* Type of ECU: on HY_TTC590 Read_Mirror/Write_Mirror needs to be adapted*/
#define HY_TTC580

/**************************************************************************************************
 * Static data
 *************************************************************************************************/
#ifdef HY_TTC590

ubyte1 EEPROM_mirror[32768U];

#else

ubyte1 EEPROM_mirror[65536U];

#endif

IO_ErrorType ErrorCode_EEPROM_mirror = IO_E_OK;

/**************************************************************************************************
 * Static prototypes
 *************************************************************************************************/
extern void flashHaileyECUv001_setup(void);//CAN_Init
extern ubyte2 flashHaileyECUv001_APPL_ErrorCb(ubyte1 diag_state,
  ubyte1 watchdog_state,
  DIAG_ERRORCODE * const error);
                 /* error reactions defined by diag_errorcode_for_CB_intern_s */

#ifdef FPU_HANDLER_ACTIVE

extern void FPU_Handler_CB(bool division_by_zero,
  bool input_denormal,
  bool invalid_operation,
  bool overflow,
  bool underflow);

#endif

/**************************************************************************************************
 * Application Database,
 * needed for TTC-Downloader
 *************************************************************************************************/

#pragma SET_DATA_SECTION (".APDB_SEC")

volatile const BL_APDB Apdb_t = {
  APDB_VERSION,        /* APDB version                                        */

  { 0 },               /* Flash date (provided by TTC-Downloader)             */

  /* Build date                                          */
  { ((((RTS_TTC_FLASH_DATE_YEAR) & 0x0FFF) << 0) |
     (((RTS_TTC_FLASH_DATE_MONTH) & 0x0F ) << 12) |
     (((RTS_TTC_FLASH_DATE_DAY) & 0x1F ) << 16) |
     (((RTS_TTC_FLASH_DATE_HOUR) & 0x1F ) << 21) |
     (((RTS_TTC_FLASH_DATE_MINUTE) & 0x3F ) << 26)) },
  0,                   /* Node type                                           */
  0,                   /* CRC start address (provided by TTC-Downloader)      */
  0,                   /* code size (provided by TTC-Downloader)              */
  0,                   /* Legacy application CRC (provided by TTC-Downloader) */
  0,                   /* Application CRC (provided by TTC-Downloader)        */
  1U,                  /* Node number                                         */
  0,                   /* CRC seed (provided by TTC-Downloader)               */
  0,                   /* Flags                                               */
  0,                   /* Hook 1                                              */
  0,                   /* Hook 2                                              */
  0,                   /* Hook 3                                              */
  APPL_START,          /* Main address, i.e., application entry point         */

  { 0, 1 },            /* CAN download ID (standard format, ID 0x1)           */

  { 0, 2 },            /* CAN upload ID (standard format, ID 0x2)             */
  0,                   /* Legacy header CRC (provided by TTC-Downloader)      */

  /* Application version (major.minor.revision)          */
  ((((ubyte4)REVISION_NUMBER) << 0) |
   (((ubyte4) MINOR_NUMBER) << 16) |
   (((ubyte4) MAJOR_NUMBER) << 24)),
  500,                 /* CAN baud rate in kbps                               */
  0,                   /* CAN channel                                         */
  0,                   /* Password (disable password protection)              */
  0,                   /* Magic seed                                          */

  { 10, 100, 30, 200 },/* Target IP address                                   */

  { 255, 255, 0, 0 },  /* Subnet mask                                         */

  { 239, 0, 0, 1 },    /* Multicast IP address                                */
  0,                   /* Debug key                                           */
  0,                   /* Automatic baud rate detection timeout               */
  0x00,                /* Manufacturer ID                                     */
  0x00,                /* Application ID                                      */

  { 0 },               /* Reserved, must be set to zero                       */
  0                    /* Header CRC (provided by TTC-Downloader)             */
};

#pragma SET_DATA_SECTION()

/**************************************************************************************************
 * Global functions
 *************************************************************************************************/
extern IO_ErrorType IO_INT_WD_SoftReset(void);

/* ============================================================================================= */
/* Function Name:          main                                                                  */
/* ============================================================================================= */
#pragma TASK( main );

void main(void)
{
  volatile IO_ErrorType io_error = IO_E_OK;
  ubyte4 timestamp = 0UL;
  bool request_reset_ttc_downloader = FALSE;
  ubyte2 handle_read_downloader = 0U;
  IO_CAN_DATA_FRAME frame_read = { 0 };

  /* safety configuration */
  IO_DRIVER_SAFETY_CONF safety_conf;
  safety_conf.command_period = CYCLE_TIME_US;/* cycle period: 50 ms      */
  safety_conf.window_size = SAFETY_CONF_WINDOW_SIZE_100_PERCENT;/* window size       */
  safety_conf.reset_behavior = SAFETY_CONF_RESETS_DISABLED;/* resets       */
  safety_conf.glitch_filter_time = 180;/* ms deglitch            */
  safety_conf.error_callback = flashHaileyECUv001_APPL_ErrorCb;/* error callback        */
  safety_conf.notify_callback = NULL;  /*no notification callback    */

  /* initialize IO driver with safety configuration */
  flashHaileyECUv001_B.MainDlg_basic_s_o1 = IO_Driver_Init(&safety_conf);

#ifdef FPU_HANDLER_ACTIVE

  io_error = IO_Driver_SetFPUHandler(&FPU_Handler_CB);

#endif

  flashHaileyECUv001_setup();          // Basic Setup
  flashHaileyECUv001_initialize();     // Initialization

  /* configure CAN to read in possible TTC-Downloader message */
  frame_read.id_format = IO_CAN_STD_FRAME;
  frame_read.length = 8;
  frame_read.id = 0x600 + 1U;
  IO_CAN_ConfigMsg(&handle_read_downloader,
                   IO_CAN_CHANNEL_0,
                   IO_CAN_MSG_READ,
                   frame_read.id_format,
                   frame_read.id,
                   0x7FF);

  /* start the RTC */
  IO_RTC_StartTime(&timestamp);

  /* loop forever */
  while (1) {
    io_error = IO_Driver_TaskBegin();

    /* check for correct TTC-Downloader message */
    if (IO_CAN_MsgStatus(handle_read_downloader) == IO_E_OK) {
      IO_CAN_ReadMsg(handle_read_downloader,
                     &frame_read);
      if ((frame_read.data[0] == 0x2BU) &&
          (frame_read.data[1] == 0x25U) &&
          (frame_read.data[2] == 0x10U) &&
          (frame_read.data[3] == 0x01U) &&
          (frame_read.data[4] == 0x13U) &&
          (frame_read.data[5] == 0x03U) &&
          (frame_read.data[6] == 0x00U) &&
          (frame_read.data[7] == 0x00U) ) {
        request_reset_ttc_downloader = TRUE;
      }
    }

    /* check for condition of reset */
    if (request_reset_ttc_downloader) {
      (void)IO_INT_WD_SoftReset();
    } else {
      /* application code */
      flashHaileyECUv001_step();       // Application

      /* application end */
    }

    io_error = IO_Driver_TaskEnd();
    flashHaileyECUv001_B.MainDlg_basic_s_o2 = IO_RTC_GetTimeUS(timestamp);
                           // save execution time for output of Standalone-block
    while (IO_RTC_GetTimeUS(timestamp) < CYCLE_TIME_US) ;/* wait until cycle time has passed */
    timestamp += CYCLE_TIME_US;        /* increase time stamp by cycle time */
  }

  // not executed: flashHaileyECUv001_terminate();      // Terminate
}                                      /* END OF main */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
