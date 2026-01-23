/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001_error_callback.c
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
#include "IO_Driver.h"
#include "flashHaileyECUv001.h"

ubyte2 flashHaileyECUv001_APPL_ErrorCb(ubyte1 diag_state,
  ubyte1 watchdog_state,
  DIAG_ERRORCODE * const error)
{
  ubyte2 action;
  (void)diag_state;                    // no decision on this input
  (void)watchdog_state;                // no decision on this input
  (void)error;                    // avoid compiler warning if error is not used
  action = DIAG_ERR_NOACTION;
  return action;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
