/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001_private.h
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

#ifndef RTW_HEADER_flashHaileyECUv001_private_h_
#define RTW_HEADER_flashHaileyECUv001_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "flashHaileyECUv001.h"
#include "flashHaileyECUv001_types.h"

/* entry from POWER_Set_Init_s begin */
#include "IO_POWER.h"

/* entry from POWER_Set_Init_s end */
/* entry from compare2error_s begin */
#include "IO_Error.h"

/* entry from compare2error_s end */
extern void fla_IO_DO_ResetProtection_Start(rtB_IO_DO_ResetProtection_flash
  *localB);
extern void flashHail_IO_DO_ResetProtection(boolean_T rtu_Trigger,
  rtB_IO_DO_ResetProtection_flash *localB, rtZCE_IO_DO_ResetProtection_fla
  *localZCE);

#endif                            /* RTW_HEADER_flashHaileyECUv001_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
