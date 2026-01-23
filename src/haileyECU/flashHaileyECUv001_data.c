/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001_data.c
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

#include "flashHaileyECUv001.h"

/* Block parameters (default storage) */
Parameters_flashHaileyECUv001 flashHaileyECUv001_P = {
  /* Mask Parameter: Trigger_Block_trigger_offset
   * Referenced by: '<S385>/Constant'
   */
  0U,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S388>/FixPt Switch'
   */
  9U,

  /* Expression: 1
   * Referenced by: '<Root>/deltay1'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<Root>/100%Value 1'
   */
  50.0,

  /* Expression: 35
   * Referenced by: '<Root>/0%Value 1'
   */
  35.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/deltay2'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<Root>/100%Value 2'
   */
  50.0,

  /* Expression: 35
   * Referenced by: '<Root>/0%Value 2'
   */
  35.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/1'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S14>/deltay2'
   */
  100.0,

  /* Expression: 7080
   * Referenced by: '<S14>/100%Value 2'
   */
  7080.0,

  /* Expression: 7800
   * Referenced by: '<S14>/0%Value 2'
   */
  7800.0,

  /* Expression: 100
   * Referenced by: '<S14>/Saturation1'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S14>/Saturation1'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant11'
   */
  1000.0,

  /* Expression: 100
   * Referenced by: '<S14>/deltay1'
   */
  100.0,

  /* Expression: 9271
   * Referenced by: '<S14>/100%Value 1'
   */
  9271.0,

  /* Expression: 8570
   * Referenced by: '<S14>/0%Value 1'
   */
  8570.0,

  /* Expression: 100
   * Referenced by: '<S14>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S14>/Saturation'
   */
  0.0,

  /* Expression: 4000
   * Referenced by: '<Root>/revomax'
   */
  4000.0,

  /* Expression: 1000
   * Referenced by: '<Root>/mommax'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S55>/Constant'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S14>/dASGCheck'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S47>/Zero'
   */
  0.0,

  /* Expression: 650
   * Referenced by: '<S18>/br_light_border'
   */
  650.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant25'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant24'
   */
  1000.0,

  /* Computed Parameter: id_TX_Value
   * Referenced by: '<S9>/id_TX'
   */
  396U,

  /* Computed Parameter: id_TX_Value_p
   * Referenced by: '<S10>/id_TX'
   */
  388U,

  /* Computed Parameter: id_TX_Value_n
   * Referenced by: '<S21>/id_TX'
   */
  2046U,

  /* Computed Parameter: id_TX_Value_c
   * Referenced by: '<S22>/id_TX'
   */
  2045U,

  /* Computed Parameter: id_TX_Value_b
   * Referenced by: '<S52>/id_TX'
   */
  2044U,

  /* Computed Parameter: id_TX_Value_i
   * Referenced by: '<S15>/id_TX'
   */
  11U,

  /* Computed Parameter: id_TX_Value_d
   * Referenced by: '<S155>/id_TX'
   */
  0U,

  /* Computed Parameter: id_TX_Value_o
   * Referenced by: '<S156>/id_TX'
   */
  128U,

  /* Computed Parameter: id_TX_Value_g
   * Referenced by: '<S153>/id_TX'
   */
  786U,

  /* Computed Parameter: id_TX_Value_ok
   * Referenced by: '<S154>/id_TX'
   */
  1042U,

  /* Computed Parameter: u00Lfter_Value
   * Referenced by: '<Root>/100%Lüfter'
   */
  24U,

  /* Computed Parameter: u6Lfter_Value
   * Referenced by: '<Root>/76% Lüfter'
   */
  16U,

  /* Computed Parameter: u00Lfter1_Value
   * Referenced by: '<Root>/100%Lüfter1'
   */
  24U,

  /* Computed Parameter: u6Lfter1_Value
   * Referenced by: '<Root>/76% Lüfter1'
   */
  16U,

  /* Computed Parameter: u00Lfter2_Value
   * Referenced by: '<Root>/100%Lüfter2'
   */
  100U,

  /* Computed Parameter: Constant23_Value
   * Referenced by: '<Root>/Constant23'
   */
  1U,

  /* Computed Parameter: Constant27_Value
   * Referenced by: '<Root>/Constant27'
   */
  65535U,

  /* Computed Parameter: Constant28_Value
   * Referenced by: '<Root>/Constant28'
   */
  65535U,

  /* Expression: true
   * Referenced by: '<Root>/Constant21'
   */
  true,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S13>/Constant2'
   */
  false,

  /* Expression: true
   * Referenced by: '<Root>/Constant20'
   */
  true,

  /* Expression: true
   * Referenced by: '<Root>/Constant13'
   */
  true,

  /* Expression: true
   * Referenced by: '<Root>/Constant14'
   */
  true,

  /* Expression: true
   * Referenced by: '<Root>/Constant15'
   */
  true,

  /* Expression: true
   * Referenced by: '<Root>/Constant18'
   */
  true,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S388>/Constant'
   */
  0U,

  /* Computed Parameter: length_TX_Value
   * Referenced by: '<S9>/length_TX'
   */
  8U,

  /* Computed Parameter: id_format_TX_Value
   * Referenced by: '<S9>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_h
   * Referenced by: '<S10>/length_TX'
   */
  8U,

  /* Computed Parameter: id_format_TX_Value_l
   * Referenced by: '<S10>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_i
   * Referenced by: '<S21>/length_TX'
   */
  8U,

  /* Computed Parameter: id_format_TX_Value_o
   * Referenced by: '<S21>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_o
   * Referenced by: '<S22>/length_TX'
   */
  8U,

  /* Computed Parameter: id_format_TX_Value_l0
   * Referenced by: '<S22>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_n
   * Referenced by: '<S52>/length_TX'
   */
  8U,

  /* Computed Parameter: id_format_TX_Value_h
   * Referenced by: '<S52>/id_format_TX'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S386>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S387>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: length_TX_Value_os
   * Referenced by: '<S15>/length_TX'
   */
  1U,

  /* Computed Parameter: id_format_TX_Value_e
   * Referenced by: '<S15>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_o4
   * Referenced by: '<S155>/length_TX'
   */
  2U,

  /* Computed Parameter: id_format_TX_Value_m
   * Referenced by: '<S155>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_a
   * Referenced by: '<S156>/length_TX'
   */
  0U,

  /* Computed Parameter: id_format_TX_Value_l2
   * Referenced by: '<S156>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_k
   * Referenced by: '<S153>/length_TX'
   */
  3U,

  /* Computed Parameter: id_format_TX_Value_hf
   * Referenced by: '<S153>/id_format_TX'
   */
  0U,

  /* Computed Parameter: length_TX_Value_nv
   * Referenced by: '<S154>/length_TX'
   */
  6U,

  /* Computed Parameter: id_format_TX_Value_i
   * Referenced by: '<S154>/id_format_TX'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
