/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001_setup.c
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
#include "IO_CAN.h"
#include "flashHaileyECUv001.h"

void flashHaileyECUv001_setup(void)
{
  /* initialize all CAN channel */
  IO_CAN_Init( IO_CAN_CHANNEL_0 , 500 , 6 , 2 , 1 ,1);
  IO_CAN_Init( IO_CAN_CHANNEL_1 , 500 , 6 , 2 , 1 ,1);
  IO_CAN_Init( IO_CAN_CHANNEL_2 , 500 , 6 , 2 , 1 ,1);
  IO_CAN_Init( IO_CAN_CHANNEL_3 , 500 , 6 , 2 , 1 ,0);
  IO_CAN_Init( IO_CAN_CHANNEL_4 , 500 , 6 , 2 , 1 ,0);
  IO_CAN_Init( IO_CAN_CHANNEL_5 , 500 , 6 , 2 , 1 ,0);
  IO_CAN_Init( IO_CAN_CHANNEL_6 , 500 , 6 , 2 , 1 ,0);
  return;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
