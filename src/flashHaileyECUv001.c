/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001.c
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
#include "rtwtypes.h"
#include "flashHaileyECUv001_private.h"
#include <math.h>
#include "zero_crossing_types.h"
#include <string.h>

/* Named constants for Chart: '<Root>/Chart' */
#define flashHaileyECUv001_IN_an       ((uint8_T)1U)
#define flashHaileyECUv001_IN_aus      ((uint8_T)2U)
#define flashHaileyE_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<Root>/State_of_the_Cart' */
#define flashHaileyECUv001_IN_AMK_start ((uint8_T)1U)
#define flashHaileyECUv001_IN_HV_off   ((uint8_T)2U)
#define flashHaileyECUv001_IN_HV_on    ((uint8_T)3U)
#define flashHaileyECUv001_IN_HV_onctrl ((uint8_T)4U)
#define flashHaileyECUv001_IN_MCRname  ((uint8_T)1U)
#define flashHaileyECUv001_IN_SGR_time ((uint8_T)5U)
#define flashHaileyECUv001_IN_dASG_time ((uint8_T)7U)
#define flashHaileyECUv001_IN_enable   ((uint8_T)2U)
#define flashHaileyECUv001_IN_err      ((uint8_T)1U)
#define flashHaileyECUv001_IN_ok       ((uint8_T)2U)
#define flashHaileyECUv001_IN_state    ((uint8_T)3U)
#define flashHaileyECUv001_IN_state_1  ((uint8_T)8U)
#define flashHaileyECUv00_IN_dASG_state ((uint8_T)6U)

/* Named constants for Chart: '<S47>/action chart' */
#define flashHaileyECUv001_IN_action   ((uint8_T)1U)
#define flashHaileyECUv001_IN_noaction ((uint8_T)2U)

/* Block signals (default storage) */
BlockIO_flashHaileyECUv001 flashHaileyECUv001_B;

/* Block states (default storage) */
D_Work_flashHaileyECUv001 flashHaileyECUv001_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_flashHaileyECUv flashHaileyECUv0_PrevZCSigState;

/* Real-time model */
static RT_MODEL_flashHaileyECUv001 flashHaileyECUv001_M_;
RT_MODEL_flashHaileyECUv001 *const flashHaileyECUv001_M = &flashHaileyECUv001_M_;

/* Forward declaration for local functions */
static void flashHaileyE_enter_atomic_HV_on(void);
static void flashHaileyECUv001_AMK_start(const boolean_T *RelationalOperator);
static void flashHaileyECUv001_dASG_time(const boolean_T *RelationalOperator_h);
static void flashHaileyECUv001_ok(const boolean_T *RelationalOperator, const
  boolean_T *RelationalOperator_h);
static void flashHaileyEC_enter_internal_ok(void);

/*
 * Start for trigger system:
 *    '<S202>/IO_DO_ResetProtection'
 *    '<S203>/IO_DO_ResetProtection'
 */
void fla_IO_DO_ResetProtection_Start(rtB_IO_DO_ResetProtection_flash *localB)
{
  /* Start for S-Function (IO_DO_ResetProtection_s): '<S206>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */
}

/*
 * Output and update for trigger system:
 *    '<S202>/IO_DO_ResetProtection'
 *    '<S203>/IO_DO_ResetProtection'
 */
void flashHail_IO_DO_ResetProtection(boolean_T rtu_Trigger,
  rtB_IO_DO_ResetProtection_flash *localB, rtZCE_IO_DO_ResetProtection_fla
  *localZCE)
{
  /* Outputs for Triggered SubSystem: '<S202>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S206>/Trigger'
   */
  if (rtu_Trigger && (localZCE->IO_DO_ResetProtection_Trig_Z_m3 != POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S206>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      localB->IO_DO_ResetProtection_s_o1 = IO_DO_ResetProtection( IO_DO_08 ,
        &localB->IO_DO_ResetProtection_s_o2 );
    }
  }

  localZCE->IO_DO_ResetProtection_Trig_Z_m3 = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S202>/IO_DO_ResetProtection' */
}

/* Function for Chart: '<Root>/State_of_the_Cart' */
static void flashHaileyE_enter_atomic_HV_on(void)
{
  /* Entry 'HV_on': '<S46>:11' */
  flashHaileyECUv001_B.staten = 11.0;
  flashHaileyECUv001_B.RTDLED = false;
  flashHaileyECUv001_B.MCR = false;
  flashHaileyECUv001_B.inv_on1 = false;
  flashHaileyECUv001_B.inv_on2 = false;
  flashHaileyECUv001_B.enable1 = false;
  flashHaileyECUv001_B.enable2 = false;
  flashHaileyECUv001_B.action = false;
}

/* Function for Chart: '<Root>/State_of_the_Cart' */
static void flashHaileyECUv001_AMK_start(const boolean_T *RelationalOperator)
{
  /* During 'AMK_start': '<S46>:17' */
  if ((flashHaileyECUv001_B.ADC_Get_s_o2_n > 650U) && (*RelationalOperator) &&
      flashHaileyECUv001_DWork.amkkk && (!flashHaileyECUv001_DWork.rtr)) {
    /* Transition: '<S46>:29' */
    /* Exit Internal 'AMK_start': '<S46>:17' */
    flashHaileyECUv001_DWork.is_AMK_start = flashHaileyE_IN_NO_ACTIVE_CHILD;
    flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_SGR_time;
    flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

    /* Entry 'SGR_time': '<S46>:26' */
    flashHaileyECUv001_B.staten = 13.0;
    flashHaileyECUv001_B.RTDSGR = true;
    flashHaileyECUv001_B.RTDLED = true;
  } else if (flashHaileyECUv001_DWork.amkkk && flashHaileyECUv001_DWork.rtr) {
    /* Transition: '<S46>:32' */
    /* Exit Internal 'AMK_start': '<S46>:17' */
    flashHaileyECUv001_DWork.is_AMK_start = flashHaileyE_IN_NO_ACTIVE_CHILD;
    flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_onctrl;

    /* Entry 'HV_onctrl': '<S46>:30' */
    flashHaileyECUv001_B.staten = 20.0;
    flashHaileyECUv001_B.inv_on1 = true;
    flashHaileyECUv001_B.inv_on2 = true;
  } else if (flashHaileyECUv001_DWork.temporalCounter_i2 >= 5000U) {
    /* Transition: '<S46>:55' */
    /* Exit Internal 'AMK_start': '<S46>:17' */
    flashHaileyECUv001_DWork.is_AMK_start = flashHaileyE_IN_NO_ACTIVE_CHILD;
    flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_off;
    flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

    /* Entry 'HV_off': '<S46>:9' */
    flashHaileyECUv001_B.staten = 1.0;
    flashHaileyECUv001_B.MCR = false;
    flashHaileyECUv001_B.inv_on1 = false;
    flashHaileyECUv001_B.inv_on2 = false;
    flashHaileyECUv001_B.enable1 = false;
    flashHaileyECUv001_B.enable2 = false;
    flashHaileyECUv001_B.action = false;
    flashHaileyECUv001_DWork.rtr = false;
  } else {
    switch (flashHaileyECUv001_DWork.is_AMK_start) {
     case flashHaileyECUv001_IN_MCRname:
      flashHaileyECUv001_B.MCR = true;

      /* During 'MCRname': '<S46>:22' */
      if (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 10U) {
        /* Transition: '<S46>:25' */
        flashHaileyECUv001_DWork.is_AMK_start = flashHaileyECUv001_IN_enable;

        /* Entry 'enable': '<S46>:24' */
        flashHaileyECUv001_B.enable1 = true;
        flashHaileyECUv001_B.enable2 = true;
        flashHaileyECUv001_DWork.amkkk = true;
      }
      break;

     case flashHaileyECUv001_IN_enable:
      flashHaileyECUv001_B.enable1 = true;
      flashHaileyECUv001_B.enable2 = true;

      /* During 'enable': '<S46>:24' */
      break;

     default:
      flashHaileyECUv001_B.DC_on = true;
      flashHaileyECUv001_B.staten = 12.0;

      /* During 'state': '<S46>:20' */
      if (flashHaileyECUv001_B.LogicalOperator_k) {
        /* Transition: '<S46>:23' */
        flashHaileyECUv001_DWork.is_AMK_start = flashHaileyECUv001_IN_MCRname;
        flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

        /* Entry 'MCRname': '<S46>:22' */
        flashHaileyECUv001_B.MCR = true;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/State_of_the_Cart' */
static void flashHaileyECUv001_dASG_time(const boolean_T *RelationalOperator_h)
{
  boolean_T guard1;
  flashHaileyECUv001_B.staten = 21.0;

  /* During 'dASG_time': '<S46>:35' */
  guard1 = false;
  if ((flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) ||
      (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0)) {
    /* Transition: '<S46>:46' */
    if (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0) {
      /* Transition: '<S46>:52' */
      flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_state_1;

      /* Entry 'state_1': '<S46>:50' */
    } else if (flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) {
      /* Transition: '<S46>:56' */
      flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
      flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
      flashHaileyE_enter_atomic_HV_on();
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 20U) {
      /* Transition: '<S46>:38' */
      flashHaileyECUv001_DWork.is_ok = flashHaileyECUv00_IN_dASG_state;

      /* Entry 'dASG_state': '<S46>:37' */
      flashHaileyECUv001_B.staten = 31.0;
    } else if (!*RelationalOperator_h) {
      /* Transition: '<S46>:49' */
      flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_onctrl;

      /* Entry 'HV_onctrl': '<S46>:30' */
      flashHaileyECUv001_B.staten = 20.0;
      flashHaileyECUv001_B.inv_on1 = true;
      flashHaileyECUv001_B.inv_on2 = true;
    } else {
      flashHaileyECUv001_B.action = true;
    }
  }
}

/* Function for Chart: '<Root>/State_of_the_Cart' */
static void flashHaileyECUv001_ok(const boolean_T *RelationalOperator, const
  boolean_T *RelationalOperator_h)
{
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;

  /* Constant: '<S13>/Constant2' incorporates:
   *  Constant: '<Root>/Constant20'
   */
  /* During 'ok': '<S46>:1' */
  if (flashHaileyECUv001_P.Constant2_Value ||
      flashHaileyECUv001_B.LogicalOperator) {
    /* Transition: '<S46>:4' */
    /* Exit Internal 'ok': '<S46>:1' */
    switch (flashHaileyECUv001_DWork.is_ok) {
     case flashHaileyECUv001_IN_SGR_time:
      /* Exit 'SGR_time': '<S46>:26' */
      flashHaileyECUv001_DWork.is_ok = flashHaileyE_IN_NO_ACTIVE_CHILD;
      break;

     case flashHaileyECUv001_IN_state_1:
      /* Exit 'state_1': '<S46>:50' */
      flashHaileyECUv001_DWork.rtr = true;
      flashHaileyECUv001_DWork.is_ok = flashHaileyE_IN_NO_ACTIVE_CHILD;
      break;

     default:
      /* Exit Internal 'AMK_start': '<S46>:17' */
      flashHaileyECUv001_DWork.is_AMK_start = flashHaileyE_IN_NO_ACTIVE_CHILD;
      flashHaileyECUv001_DWork.is_ok = flashHaileyE_IN_NO_ACTIVE_CHILD;
      break;
    }

    flashHaileyECUv001_DWork.is_c1_flashHaileyECUv001 =
      flashHaileyECUv001_IN_err;
    flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

    /* Entry 'err': '<S46>:3' */
    flashHaileyECUv001_B.staten = 30.0;
    flashHaileyECUv001_B.RTDLED = false;
    flashHaileyECUv001_B.RTDSGR = false;
    flashHaileyECUv001_B.inv_on1 = false;
    flashHaileyECUv001_B.inv_on2 = false;
    flashHaileyECUv001_B.enable1 = false;
    flashHaileyECUv001_B.enable2 = false;
    flashHaileyECUv001_B.erdel1 = true;
    flashHaileyECUv001_B.erdel2 = true;
    flashHaileyECUv001_B.action = false;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (flashHaileyECUv001_DWork.is_ok) {
     case flashHaileyECUv001_IN_AMK_start:
      flashHaileyECUv001_AMK_start(RelationalOperator);
      break;

     case flashHaileyECUv001_IN_HV_off:
      flashHaileyECUv001_B.staten = 1.0;
      flashHaileyECUv001_B.MCR = false;
      flashHaileyECUv001_B.inv_on1 = false;
      flashHaileyECUv001_B.inv_on2 = false;
      flashHaileyECUv001_B.enable1 = false;
      flashHaileyECUv001_B.enable2 = false;

      /* Constant: '<Root>/Constant20' */
      /* During 'HV_off': '<S46>:9' */
      if (flashHaileyECUv001_P.Constant20_Value &&
          (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 200U)) {
        /* Transition: '<S46>:12' */
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
        flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
        flashHaileyE_enter_atomic_HV_on();
      }
      break;

     case flashHaileyECUv001_IN_HV_on:
      flashHaileyECUv001_B.staten = 11.0;
      flashHaileyECUv001_B.RTDLED = false;
      flashHaileyECUv001_B.MCR = false;
      flashHaileyECUv001_B.inv_on1 = false;
      flashHaileyECUv001_B.inv_on2 = false;
      flashHaileyECUv001_B.enable1 = false;
      flashHaileyECUv001_B.enable2 = false;

      /* During 'HV_on': '<S46>:11' */
      if (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 30U) {
        /* Transition: '<S46>:18' */
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_AMK_start;
        flashHaileyECUv001_DWork.temporalCounter_i2 = 0U;

        /* Entry Internal 'AMK_start': '<S46>:17' */
        /* Transition: '<S46>:21' */
        flashHaileyECUv001_DWork.is_AMK_start = flashHaileyECUv001_IN_state;

        /* Entry 'state': '<S46>:20' */
        flashHaileyECUv001_B.DC_on = true;
        flashHaileyECUv001_B.staten = 12.0;
        flashHaileyECUv001_DWork.amkkk = false;
      } else if (!flashHaileyECUv001_P.Constant20_Value) {
        /* Transition: '<S46>:13' */
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_off;
        flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

        /* Entry 'HV_off': '<S46>:9' */
        flashHaileyECUv001_B.staten = 1.0;
        flashHaileyECUv001_B.action = false;
        flashHaileyECUv001_DWork.rtr = false;
      }
      break;

     case flashHaileyECUv001_IN_HV_onctrl:
      flashHaileyECUv001_B.staten = 20.0;
      flashHaileyECUv001_B.inv_on1 = true;
      flashHaileyECUv001_B.inv_on2 = true;

      /* During 'HV_onctrl': '<S46>:30' */
      if ((flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) ||
          (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0)) {
        /* Transition: '<S46>:45' */
        if (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0) {
          /* Transition: '<S46>:52' */
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_state_1;

          /* Entry 'state_1': '<S46>:50' */
        } else if (flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) {
          /* Transition: '<S46>:56' */
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
          flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
          flashHaileyE_enter_atomic_HV_on();
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case flashHaileyECUv001_IN_SGR_time:
      flashHaileyECUv001_B.staten = 13.0;
      flashHaileyECUv001_B.RTDLED = true;

      /* During 'SGR_time': '<S46>:26' */
      if ((flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) ||
          (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0)) {
        /* Transition: '<S46>:43' */
        if (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0) {
          /* Transition: '<S46>:52' */
          /* Exit 'SGR_time': '<S46>:26' */
          flashHaileyECUv001_B.RTDSGR = false;
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_state_1;

          /* Entry 'state_1': '<S46>:50' */
        } else if (flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) {
          /* Transition: '<S46>:56' */
          /* Exit 'SGR_time': '<S46>:26' */
          flashHaileyECUv001_B.RTDSGR = false;
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
          flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
          flashHaileyE_enter_atomic_HV_on();
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      break;

     case flashHaileyECUv00_IN_dASG_state:
      flashHaileyECUv001_B.staten = 31.0;

      /* During 'dASG_state': '<S46>:37' */
      if ((flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) ||
          (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0)) {
        /* Transition: '<S46>:47' */
        if (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0) {
          /* Transition: '<S46>:52' */
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_state_1;

          /* Entry 'state_1': '<S46>:50' */
        } else if (flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) {
          /* Transition: '<S46>:56' */
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
          flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
          flashHaileyE_enter_atomic_HV_on();
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
      break;

     case flashHaileyECUv001_IN_dASG_time:
      flashHaileyECUv001_dASG_time(RelationalOperator_h);
      break;

     default:
      /* During 'state_1': '<S46>:50' */
      if (flashHaileyECUv001_B.bit_unpacking_s_nk != 15.0) {
        /* Transition: '<S46>:53' */
        if (flashHaileyECUv001_B.bit_unpacking_s_nk == 15.0) {
          /* Transition: '<S46>:52' */
          /* Exit 'state_1': '<S46>:50' */
          flashHaileyECUv001_DWork.rtr = true;
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_state_1;

          /* Entry 'state_1': '<S46>:50' */
        } else if (flashHaileyECUv001_B.bit_unpacking_s_nk == 25.0) {
          /* Transition: '<S46>:56' */
          /* Exit 'state_1': '<S46>:50' */
          flashHaileyECUv001_DWork.rtr = true;
          flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_on;
          flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
          flashHaileyE_enter_atomic_HV_on();
        }
      }
      break;
    }

    if (guard3) {
      if (!*RelationalOperator_h) {
        /* Transition: '<S46>:48' */
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_onctrl;

        /* Entry 'HV_onctrl': '<S46>:30' */
        flashHaileyECUv001_B.staten = 20.0;
        flashHaileyECUv001_B.inv_on1 = true;
        flashHaileyECUv001_B.inv_on2 = true;
      } else {
        flashHaileyECUv001_B.action = false;
      }
    }

    if (guard2) {
      if (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 200U) {
        /* Transition: '<S46>:34' */
        /* Exit 'SGR_time': '<S46>:26' */
        flashHaileyECUv001_B.RTDSGR = false;
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_onctrl;

        /* Entry 'HV_onctrl': '<S46>:30' */
        flashHaileyECUv001_B.staten = 20.0;
        flashHaileyECUv001_B.inv_on1 = true;
        flashHaileyECUv001_B.inv_on2 = true;
      }
    }

    if (guard1) {
      if (*RelationalOperator_h) {
        /* Transition: '<S46>:36' */
        flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_dASG_time;
        flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

        /* Entry 'dASG_time': '<S46>:35' */
        flashHaileyECUv001_B.staten = 21.0;
      } else {
        flashHaileyECUv001_B.action = true;
      }
    }
  }

  /* End of Constant: '<S13>/Constant2' */
}

/* Function for Chart: '<Root>/State_of_the_Cart' */
static void flashHaileyEC_enter_internal_ok(void)
{
  /* Entry Internal 'ok': '<S46>:1' */
  /* Transition: '<S46>:10' */
  flashHaileyECUv001_DWork.is_ok = flashHaileyECUv001_IN_HV_off;
  flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;

  /* Entry 'HV_off': '<S46>:9' */
  flashHaileyECUv001_B.staten = 1.0;
  flashHaileyECUv001_B.MCR = false;
  flashHaileyECUv001_B.inv_on1 = false;
  flashHaileyECUv001_B.inv_on2 = false;
  flashHaileyECUv001_B.enable1 = false;
  flashHaileyECUv001_B.enable2 = false;
  flashHaileyECUv001_B.action = false;
  flashHaileyECUv001_DWork.rtr = false;
}

/* Model step function */
void flashHaileyECUv001_step(void)
{
  real_T Saturation1;
  real_T rtb_Divide8;
  real_T rtb_Saturation;
  real_T rtb_t6;
  uint8_T rtb_FixPtSum1;
  boolean_T RelationalOperator;
  boolean_T RelationalOperator_h;

  /* S-Function (IO_CAN_ConfigMsg_s): '<S89>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S90>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1 = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2 ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3 = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4 = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5 = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S91>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s , 2U , 2U , 0U , 0U ,
                  16U , 0.1 , 0.0 );
  }

  /* Product: '<Root>/m1' incorporates:
   *  Constant: '<Root>/0%Value 1'
   *  Constant: '<Root>/100%Value 1'
   *  Constant: '<Root>/deltay1'
   *  Sum: '<Root>/deltax1'
   */
  rtb_Saturation = flashHaileyECUv001_P.deltay1_Value /
    (flashHaileyECUv001_P.u00Value1_Value - flashHaileyECUv001_P.uValue1_Value);

  /* Sum: '<Root>/-t1' incorporates:
   *  Constant: '<Root>/0%Value 1'
   *  Product: '<Root>/m1*x1'
   *  Product: '<Root>/y(0)=m*x10'
   */
  rtb_Saturation = flashHaileyECUv001_B.bit_unpacking_s * rtb_Saturation -
    rtb_Saturation * flashHaileyECUv001_P.uValue1_Value;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > flashHaileyECUv001_P.Saturation_UpperSat) {
    rtb_Saturation = flashHaileyECUv001_P.Saturation_UpperSat;
  } else if (rtb_Saturation < flashHaileyECUv001_P.Saturation_LowerSat) {
    rtb_Saturation = flashHaileyECUv001_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/-t3' incorporates:
   *  Constant: '<Root>/100%Lüfter'
   *  Constant: '<Root>/76% Lüfter'
   *  Product: '<Root>/Product12'
   *  Sum: '<Root>/-t2'
   */
  flashHaileyECUv001_B.t3 = (real_T)(uint16_T)
    (flashHaileyECUv001_P.u00Lfter_Value - flashHaileyECUv001_P.u6Lfter_Value) *
    rtb_Saturation + (real_T)flashHaileyECUv001_P.u6Lfter_Value;

  /* S-Function (IO_CAN_ConfigMsg_s): '<S95>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S96>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_h = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_f ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_o = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_d = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_c = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S97>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_e , 2U , 2U , 0U , 0U ,
                  16U , 0.1 , 0.0 );
  }

  /* Product: '<Root>/m2' incorporates:
   *  Constant: '<Root>/0%Value 2'
   *  Constant: '<Root>/100%Value 2'
   *  Constant: '<Root>/deltay2'
   *  Sum: '<Root>/deltax2'
   */
  rtb_t6 = flashHaileyECUv001_P.deltay2_Value /
    (flashHaileyECUv001_P.u00Value2_Value - flashHaileyECUv001_P.uValue2_Value);

  /* S-Function (ADC_Get_s): '<S60>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1 = IO_ADC_Get( IO_ADC_UBAT ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2 , &flashHaileyECUv001_B.ADC_Get_s_o3 );
  }

  /* S-Function (ADC_ChannelInit_s): '<S59>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (ADC_Get_s): '<S62>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_n = IO_ADC_Get( IO_ADC_UBAT ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_a ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_g );
  }

  /* S-Function (ADC_ChannelInit_s): '<S61>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (IO_CAN_ConfigMsg_s): '<S63>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S64>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_c = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_a ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_n = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_j = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_a = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S68>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_d , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S76>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S77>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_j = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_j ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_f = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_l = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_e = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S81>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_m , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/1'
   *  RelationalOperator: '<S4>/GreaterThan'
   *  RelationalOperator: '<S4>/GreaterThan1'
   */
  flashHaileyECUv001_B.LogicalOperator =
    ((flashHaileyECUv001_B.bit_unpacking_s_d > flashHaileyECUv001_P.u_Value) ||
     (flashHaileyECUv001_B.bit_unpacking_s_m > flashHaileyECUv001_P.u_Value));

  /* S-Function (bit_unpacking_s): '<S65>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dj , 2U , 1U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S66>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_b , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S67>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_i , 2U , 2U , 0U , 48U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S69>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dr , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S70>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_a , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S71>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_g , 2U , 1U , 0U , 12U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S72>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_p , 2U , 1U , 0U , 13U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S73>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_k , 2U , 1U , 0U , 14U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S74>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_o , 2U , 1U , 0U , 15U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S75>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_h[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_i5 , 2U , 2U , 0U , 16U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S78>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_kt , 2U , 1U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S79>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_px , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S80>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dn , 2U , 2U , 0U , 48U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S82>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pj , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S83>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_j , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S84>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_gj , 2U , 1U , 0U , 12U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S85>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_l , 2U , 1U , 0U , 13U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S86>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_bt , 2U , 1U , 0U , 14U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S87>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ac , 2U , 1U , 0U , 15U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S88>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_ku[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_jw , 2U , 2U , 0U , 16U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S92>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_bd , 2U , 2U , 0U , 16U ,
                  16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S93>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ep , 2U , 1U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S94>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ie , 2U , 2U , 0U , 48U ,
                  16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S98>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_bm , 2U , 2U , 0U , 16U ,
                  16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S99>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_c , 2U , 1U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S100>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_mt , 2U , 2U , 0U , 48U ,
                  16U , 0.1 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S101>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ConfigMsg_s): '<S256>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S257>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_g = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_k ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_g[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_l = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_b = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_f = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S258>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_g[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_n , 2U , 2U , 0U , 0U ,
                  32U , 1.0 , 0.0 );
  }

  /* Product: '<S14>/m2' incorporates:
   *  Constant: '<S14>/0%Value 2'
   *  Constant: '<S14>/100%Value 2'
   *  Constant: '<S14>/deltay2'
   *  Sum: '<S14>/deltax2'
   */
  rtb_Divide8 = flashHaileyECUv001_P.deltay2_Value_j /
    (flashHaileyECUv001_P.u00Value2_Value_d -
     flashHaileyECUv001_P.uValue2_Value_h);

  /* Sum: '<S14>/-t2' incorporates:
   *  Constant: '<S14>/0%Value 2'
   *  Product: '<S14>/m2*x2'
   *  Product: '<S14>/y(0)=m*x20'
   */
  Saturation1 = flashHaileyECUv001_B.bit_unpacking_s_n * rtb_Divide8 -
    rtb_Divide8 * flashHaileyECUv001_P.uValue2_Value_h;

  /* Saturate: '<S14>/Saturation1' */
  if (Saturation1 > flashHaileyECUv001_P.Saturation1_UpperSat_e) {
    /* Saturate: '<S14>/Saturation1' */
    Saturation1 = flashHaileyECUv001_P.Saturation1_UpperSat_e;
  } else if (Saturation1 < flashHaileyECUv001_P.Saturation1_LowerSat_o) {
    /* Saturate: '<S14>/Saturation1' */
    Saturation1 = flashHaileyECUv001_P.Saturation1_LowerSat_o;
  }

  /* End of Saturate: '<S14>/Saturation1' */

  /* S-Function (ADC_Get_s): '<S295>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_l = IO_ADC_Get( IO_ADC_05 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_k ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_p );
  }

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  RelationalOperator = (flashHaileyECUv001_B.ADC_Get_s_o2_k <
                        flashHaileyECUv001_P.Constant11_Value);

  /* S-Function (IO_CAN_ConfigMsg_s): '<S252>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S253>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_m = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_g ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k5[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_ob = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_o = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_g = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S254>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k5[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ky , 2U , 2U , 0U , 0U ,
                  32U , 1.0 , 0.0 );
  }

  /* Product: '<S14>/m1' incorporates:
   *  Constant: '<S14>/0%Value 1'
   *  Constant: '<S14>/100%Value 1'
   *  Constant: '<S14>/deltay1'
   *  Sum: '<S14>/deltax1'
   */
  rtb_Divide8 = flashHaileyECUv001_P.deltay1_Value_c /
    (flashHaileyECUv001_P.u00Value1_Value_p -
     flashHaileyECUv001_P.uValue1_Value_b);

  /* Sum: '<S14>/-t1' incorporates:
   *  Constant: '<S14>/0%Value 1'
   *  Product: '<S14>/m1*x1'
   *  Product: '<S14>/y(0)=m*x10'
   */
  rtb_Divide8 = flashHaileyECUv001_B.bit_unpacking_s_ky * rtb_Divide8 -
    rtb_Divide8 * flashHaileyECUv001_P.uValue1_Value_b;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Divide8 > flashHaileyECUv001_P.Saturation_UpperSat_g) {
    /* Saturate: '<S14>/Saturation' */
    flashHaileyECUv001_B.Saturation = flashHaileyECUv001_P.Saturation_UpperSat_g;
  } else if (rtb_Divide8 < flashHaileyECUv001_P.Saturation_LowerSat_m) {
    /* Saturate: '<S14>/Saturation' */
    flashHaileyECUv001_B.Saturation = flashHaileyECUv001_P.Saturation_LowerSat_m;
  } else {
    /* Saturate: '<S14>/Saturation' */
    flashHaileyECUv001_B.Saturation = rtb_Divide8;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* S-Function (ADC_Get_s): '<S141>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_o = IO_ADC_Get( IO_ADC_08 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_n ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_j );
  }

  /* Logic: '<S55>/Logical Operator' incorporates:
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S55>/Relational Operator'
   *  RelationalOperator: '<S55>/Relational Operator1'
   */
  flashHaileyECUv001_B.LogicalOperator_k =
    ((flashHaileyECUv001_B.bit_unpacking_s_a >
      flashHaileyECUv001_P.Constant_Value) &&
     (flashHaileyECUv001_B.bit_unpacking_s_j >
      flashHaileyECUv001_P.Constant_Value));

  /* S-Function (IO_CAN_ConfigMsg_s): '<S223>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S224>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_f = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_n ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_lg = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_li = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_d = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S225>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_nk , 2U , 1U , 0U , 0U ,
                  8U , 1.0 , 0.0 );
  }

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S14>/dASGCheck'
   *  Sum: '<S14>/dASGcalc'
   */
  RelationalOperator_h = (fabs(flashHaileyECUv001_B.Saturation - Saturation1) >
    flashHaileyECUv001_P.dASGCheck_Value);

  /* Chart: '<Root>/State_of_the_Cart' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  if (flashHaileyECUv001_DWork.temporalCounter_i1_b < 255U) {
    flashHaileyECUv001_DWork.temporalCounter_i1_b++;
  }

  if (flashHaileyECUv001_DWork.temporalCounter_i2 < 8191U) {
    flashHaileyECUv001_DWork.temporalCounter_i2++;
  }

  /* Gateway: State_of_the_Cart */
  /* During: State_of_the_Cart */
  if (flashHaileyECUv001_DWork.is_active_c1_flashHaileyECUv001 == 0U) {
    /* Entry: State_of_the_Cart */
    flashHaileyECUv001_DWork.is_active_c1_flashHaileyECUv001 = 1U;

    /* Entry Internal: State_of_the_Cart */
    /* Transition: '<S46>:2' */
    flashHaileyECUv001_DWork.is_c1_flashHaileyECUv001 = flashHaileyECUv001_IN_ok;
    flashHaileyEC_enter_internal_ok();
  } else if (flashHaileyECUv001_DWork.is_c1_flashHaileyECUv001 ==
             flashHaileyECUv001_IN_err) {
    flashHaileyECUv001_B.staten = 30.0;
    flashHaileyECUv001_B.RTDLED = false;
    flashHaileyECUv001_B.inv_on1 = false;
    flashHaileyECUv001_B.inv_on2 = false;
    flashHaileyECUv001_B.enable1 = false;
    flashHaileyECUv001_B.enable2 = false;
    flashHaileyECUv001_B.erdel1 = true;
    flashHaileyECUv001_B.erdel2 = true;

    /* During 'err': '<S46>:3' */
    if (((!flashHaileyECUv001_P.Constant2_Value) ||
         (!flashHaileyECUv001_B.LogicalOperator)) &&
        (flashHaileyECUv001_DWork.temporalCounter_i1_b >= 50U)) {
      /* Transition: '<S46>:5' */
      flashHaileyECUv001_DWork.is_c1_flashHaileyECUv001 =
        flashHaileyECUv001_IN_ok;
      flashHaileyEC_enter_internal_ok();
    }
  } else {
    flashHaileyECUv001_ok(&RelationalOperator, &RelationalOperator_h);
  }

  /* End of Chart: '<Root>/State_of_the_Cart' */

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant21'
   */
  flashHaileyECUv001_B.LogicalOperator_m =
    (flashHaileyECUv001_P.Constant21_Value && flashHaileyECUv001_B.inv_on1);

  /* S-Function (bit_packing_s): '<S103>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.LogicalOperator_m ,
                &flashHaileyECUv001_B.bit_packing_s[0] , 2U , 1U , 0U , 8U , 1U ,
                1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S104>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.DC_on ,
                &flashHaileyECUv001_B.bit_packing_s_h[0] , 2U , 1U , 0U , 9U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S105>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.enable1 ,
                &flashHaileyECUv001_B.bit_packing_s_e[0] , 2U , 1U , 0U , 10U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S106>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.erdel1 ,
                &flashHaileyECUv001_B.bit_packing_s_g[0] , 2U , 1U , 0U , 11U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S119>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S120>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_a = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_p ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_i = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_k = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_l = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S125>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pa , 2U , 2U , 0U , 16U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S107>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_pa ,
                &flashHaileyECUv001_B.bit_packing_s_c[0] , 2U , 2U , 0U , 16U ,
                16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S126>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_mz , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S108>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_mz ,
                &flashHaileyECUv001_B.bit_packing_s_d[0] , 2U , 2U , 0U , 32U ,
                16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S109>/bit_packing_s' incorporates:
   *  Constant: '<S47>/Zero'
   */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_P.Zero_Value ,
                &flashHaileyECUv001_B.bit_packing_s_dm[0] , 2U , 2U , 0U , 48U ,
                16U , 0.01 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S9>/OR_TX' */
  flashHaileyECUv001_B.OR_TX[0] = flashHaileyECUv001_B.bit_packing_s[0] |
    flashHaileyECUv001_B.bit_packing_s_h[0] |
    flashHaileyECUv001_B.bit_packing_s_e[0] |
    flashHaileyECUv001_B.bit_packing_s_g[0] |
    flashHaileyECUv001_B.bit_packing_s_c[0] |
    flashHaileyECUv001_B.bit_packing_s_d[0] |
    flashHaileyECUv001_B.bit_packing_s_dm[0];
  flashHaileyECUv001_B.OR_TX[1] = flashHaileyECUv001_B.bit_packing_s[1] |
    flashHaileyECUv001_B.bit_packing_s_h[1] |
    flashHaileyECUv001_B.bit_packing_s_e[1] |
    flashHaileyECUv001_B.bit_packing_s_g[1] |
    flashHaileyECUv001_B.bit_packing_s_c[1] |
    flashHaileyECUv001_B.bit_packing_s_d[1] |
    flashHaileyECUv001_B.bit_packing_s_dm[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S102>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S9>/id_TX'
   *  Constant: '<S9>/id_format_TX'
   *  Constant: '<S9>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_b ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S110>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/Constant21'
   */
  flashHaileyECUv001_B.LogicalOperator1 = (flashHaileyECUv001_P.Constant21_Value
    && flashHaileyECUv001_B.inv_on2);

  /* S-Function (bit_packing_s): '<S112>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.LogicalOperator1 ,
                &flashHaileyECUv001_B.bit_packing_s_f[0] , 2U , 1U , 0U , 8U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S113>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.DC_on ,
                &flashHaileyECUv001_B.bit_packing_s_l[0] , 2U , 1U , 0U , 9U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S114>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.enable2 ,
                &flashHaileyECUv001_B.bit_packing_s_m[0] , 2U , 1U , 0U , 10U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S115>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.erdel2 ,
                &flashHaileyECUv001_B.bit_packing_s_o[0] , 2U , 1U , 0U , 11U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S128>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S129>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_a5 = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_kh ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_lj = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_n = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_b = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S134>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_jp , 2U , 2U , 0U , 16U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S116>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_jp ,
                &flashHaileyECUv001_B.bit_packing_s_j[0] , 2U , 2U , 0U , 16U ,
                16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S135>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_el , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S117>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_el ,
                &flashHaileyECUv001_B.bit_packing_s_du[0] , 2U , 2U , 0U , 32U ,
                16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S118>/bit_packing_s' incorporates:
   *  Constant: '<S47>/Zero'
   */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_P.Zero_Value ,
                &flashHaileyECUv001_B.bit_packing_s_p[0] , 2U , 2U , 0U , 48U ,
                16U , 0.01 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S10>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_a[0] = flashHaileyECUv001_B.bit_packing_s_f[0] |
    flashHaileyECUv001_B.bit_packing_s_l[0] |
    flashHaileyECUv001_B.bit_packing_s_m[0] |
    flashHaileyECUv001_B.bit_packing_s_o[0] |
    flashHaileyECUv001_B.bit_packing_s_j[0] |
    flashHaileyECUv001_B.bit_packing_s_du[0] |
    flashHaileyECUv001_B.bit_packing_s_p[0];
  flashHaileyECUv001_B.OR_TX_a[1] = flashHaileyECUv001_B.bit_packing_s_f[1] |
    flashHaileyECUv001_B.bit_packing_s_l[1] |
    flashHaileyECUv001_B.bit_packing_s_m[1] |
    flashHaileyECUv001_B.bit_packing_s_o[1] |
    flashHaileyECUv001_B.bit_packing_s_j[1] |
    flashHaileyECUv001_B.bit_packing_s_du[1] |
    flashHaileyECUv001_B.bit_packing_s_p[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S111>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S10>/id_TX'
   *  Constant: '<S10>/id_format_TX'
   *  Constant: '<S10>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_a[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_h;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_l;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_p;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_k = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_c ,&tmp_struct_1);
  }

  /* S-Function (bit_unpacking_s): '<S121>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_cx , 2U , 1U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S122>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_bm0 , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S123>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_lc , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S124>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_h , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S127>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_i[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_br , 2U , 2U , 0U , 48U ,
                  16U , 0.01 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S130>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_gjh , 2U , 1U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S131>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_nks , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S132>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ef , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S133>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_nf , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S136>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_hx[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_po , 2U , 2U , 0U , 48U ,
                  16U , 0.01 , 0.0 );
  }

  /* S-Function (ADC_ChannelInit_s): '<S140>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (POWER_Set_Init_s): '<S142>/POWER_Set_Init_s' */

  /* function call of POWER_Set_Init */

  /* RelationalOperator: '<S18>/GreaterThan' incorporates:
   *  Constant: '<S18>/br_light_border'
   */
  flashHaileyECUv001_B.GreaterThan = (flashHaileyECUv001_B.ADC_Get_s_o2_n >
    flashHaileyECUv001_P.br_light_border_Value);

  /* S-Function (IO_DO_Set_s): '<S147>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s = IO_DO_Set( IO_DO_00 ,
      flashHaileyECUv001_B.GreaterThan );
  }

  /* S-Function (compare2error_s): '<S148>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s = (flashHaileyECUv001_B.IO_DO_Set_s ==
      IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S17>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S146>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_a !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S146>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_h = IO_DO_ResetProtection(
        IO_DO_00 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_mg );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_a =
    flashHaileyECUv001_B.compare2error_s;

  /* End of Outputs for SubSystem: '<S17>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S144>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1 = IO_DO_GetVoltage( IO_DO_00 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3 );
  }

  /* S-Function (IO_DO_GetCur_s): '<S143>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1 = IO_DO_GetCur( IO_DO_00 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3 );
  }

  /* S-Function (IO_DO_Init_s): '<S145>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant27'
   *  Product: '<Root>/Divide7'
   *  Product: '<Root>/Product11'
   */
  Saturation1 = fmod(floor(flashHaileyECUv001_B.t3 * (real_T)
    flashHaileyECUv001_P.Constant27_Value / (real_T)
    flashHaileyECUv001_B.ADC_Get_s_o2), 65536.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  flashHaileyECUv001_B.DataTypeConversion7 = (uint16_T)(Saturation1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Saturation1 : (int32_T)(uint16_T)
    Saturation1);

  /* Sum: '<Root>/-t4' incorporates:
   *  Constant: '<Root>/0%Value 2'
   *  Product: '<Root>/m1*x2'
   *  Product: '<Root>/y(0)=m*x1'
   */
  rtb_Divide8 = flashHaileyECUv001_B.bit_unpacking_s_e * rtb_t6 - rtb_t6 *
    flashHaileyECUv001_P.uValue2_Value;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Divide8 > flashHaileyECUv001_P.Saturation1_UpperSat) {
    rtb_Divide8 = flashHaileyECUv001_P.Saturation1_UpperSat;
  } else if (rtb_Divide8 < flashHaileyECUv001_P.Saturation1_LowerSat) {
    rtb_Divide8 = flashHaileyECUv001_P.Saturation1_LowerSat;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Constant: '<Root>/100%Lüfter1'
   *  Constant: '<Root>/76% Lüfter1'
   *  Constant: '<Root>/Constant28'
   *  Product: '<Root>/Divide8'
   *  Product: '<Root>/Product13'
   *  Product: '<Root>/Product14'
   *  Saturate: '<Root>/Saturation1'
   *  Sum: '<Root>/-t5'
   *  Sum: '<Root>/-t6'
   */
  Saturation1 = fmod(floor(((real_T)(uint16_T)
    (flashHaileyECUv001_P.u00Lfter1_Value - flashHaileyECUv001_P.u6Lfter1_Value)
    * rtb_Divide8 + (real_T)flashHaileyECUv001_P.u6Lfter1_Value) * (real_T)
    flashHaileyECUv001_P.Constant28_Value / (real_T)
    flashHaileyECUv001_B.ADC_Get_s_o2_a), 65536.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  flashHaileyECUv001_B.DataTypeConversion8 = (uint16_T)(Saturation1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Saturation1 : (int32_T)(uint16_T)
    Saturation1);

  /* S-Function (IO_CAN_ConfigMsg_s): '<S187>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (bit_packing_s): '<S189>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_g ,
                &flashHaileyECUv001_B.bit_packing_s_hd[0] , 2U , 2U , 0U , 0U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S190>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.Saturation ,
                &flashHaileyECUv001_B.bit_packing_s_p4[0] , 2U , 2U , 0U , 8U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S191>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_nk ,
                &flashHaileyECUv001_B.bit_packing_s_fv[0] , 2U , 2U , 0U , 16U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S192>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.LogicalOperator ,
                &flashHaileyECUv001_B.bit_packing_s_fy[0] , 2U , 2U , 0U , 24U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S193>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.LogicalOperator_k ,
                &flashHaileyECUv001_B.bit_packing_s_i[0] , 2U , 2U , 0U , 32U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S194>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_p ,
                &flashHaileyECUv001_B.bit_packing_s_om[0] , 2U , 2U , 0U , 40U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S195>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_d ,
                &flashHaileyECUv001_B.bit_packing_s_a[0] , 2U , 2U , 0U , 48U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S21>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_d[0] = flashHaileyECUv001_B.bit_packing_s_hd[0] |
    flashHaileyECUv001_B.bit_packing_s_p4[0] |
    flashHaileyECUv001_B.bit_packing_s_fv[0] |
    flashHaileyECUv001_B.bit_packing_s_fy[0] |
    flashHaileyECUv001_B.bit_packing_s_i[0] |
    flashHaileyECUv001_B.bit_packing_s_om[0] |
    flashHaileyECUv001_B.bit_packing_s_a[0];
  flashHaileyECUv001_B.OR_TX_d[1] = flashHaileyECUv001_B.bit_packing_s_hd[1] |
    flashHaileyECUv001_B.bit_packing_s_p4[1] |
    flashHaileyECUv001_B.bit_packing_s_fv[1] |
    flashHaileyECUv001_B.bit_packing_s_fy[1] |
    flashHaileyECUv001_B.bit_packing_s_i[1] |
    flashHaileyECUv001_B.bit_packing_s_om[1] |
    flashHaileyECUv001_B.bit_packing_s_a[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S188>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S21>/id_TX'
   *  Constant: '<S21>/id_format_TX'
   *  Constant: '<S21>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_d[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_i;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_o;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_n;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_a = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_n4 ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S196>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* Product: '<Root>/Product10' incorporates:
   *  Constant: '<Root>/Constant23'
   */
  flashHaileyECUv001_B.Product10 = flashHaileyECUv001_B.ADC_Get_s_o2_n *
    flashHaileyECUv001_P.Constant23_Value;

  /* S-Function (bit_packing_s): '<S198>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.Product10 ,
                &flashHaileyECUv001_B.bit_packing_s_es[0] , 2U , 3U , 0U , 0U ,
                32U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S199>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.staten ,
                &flashHaileyECUv001_B.bit_packing_s_pz[0] , 2U , 1U , 0U , 34U ,
                6U , 1.0 , 0.0 );
  }

  /* Product: '<Root>/Product9' incorporates:
   *  Constant: '<Root>/100%Lüfter2'
   */
  flashHaileyECUv001_B.Product9 = rtb_Saturation * (real_T)
    flashHaileyECUv001_P.u00Lfter2_Value;

  /* S-Function (bit_packing_s): '<S200>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.Product9 ,
                &flashHaileyECUv001_B.bit_packing_s_ce[0] , 2U , 2U , 0U , 40U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S201>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.t3 ,
                &flashHaileyECUv001_B.bit_packing_s_k[0] , 2U , 2U , 0U , 48U ,
                8U , 1.0 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S22>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_l[0] = flashHaileyECUv001_B.bit_packing_s_es[0] |
    flashHaileyECUv001_B.bit_packing_s_pz[0] |
    flashHaileyECUv001_B.bit_packing_s_ce[0] |
    flashHaileyECUv001_B.bit_packing_s_k[0];
  flashHaileyECUv001_B.OR_TX_l[1] = flashHaileyECUv001_B.bit_packing_s_es[1] |
    flashHaileyECUv001_B.bit_packing_s_pz[1] |
    flashHaileyECUv001_B.bit_packing_s_ce[1] |
    flashHaileyECUv001_B.bit_packing_s_k[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S197>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S22>/id_TX'
   *  Constant: '<S22>/id_format_TX'
   *  Constant: '<S22>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_l[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_o;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_l0;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_c;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_p = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_f1 ,&tmp_struct_1);
  }

  /* S-Function (bit_unpacking_s): '<S226>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_mw , 2U , 2U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S227>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_eu , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S228>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pw , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S229>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_i0 , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S230>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_a[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ci , 2U , 1U , 0U , 12U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_PWM_SetDuty_s): '<S234>/IO_PWM_SetDuty_s' */

  /* function call of IO_PWM_SetDuty */
  {
    flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1 = IO_PWM_SetDuty( IO_PWM_00 ,
      flashHaileyECUv001_B.DataTypeConversion7 ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o2 ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o3 );
  }

  /* S-Function (compare2error_s): '<S235>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_i =
      (flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1 == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S29>/IO_PWM_ResetProtection' incorporates:
   *  TriggerPort: '<S233>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_i &&
      (flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_f !=
       POS_ZCSIG)) {
    /* S-Function (IO_PWM_ResetProtection_s): '<S233>/IO_PWM_ResetProtection_s' */

    /* function call of IO_PWM_ResetProtection */
    {
      flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o1_e =
        IO_PWM_ResetProtection( IO_PWM_00 ,
        &flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o2_f );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_f =
    flashHaileyECUv001_B.compare2error_s_i;

  /* End of Outputs for SubSystem: '<S29>/IO_PWM_ResetProtection' */

  /* S-Function (IO_PWM_GetCur_s): '<S231>/IO_PWM_GetCur_s' */

  /* function call of IO_PWM_GetCur */
  {
    flashHaileyECUv001_B.IO_PWM_GetCur_s_o1 = IO_PWM_GetCur( IO_PWM_00 ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o2 ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o3 );
  }

  /* S-Function (IO_PWM_Init_s): '<S232>/IO_PWM_Init_s' */

  /* function call of IO_PWM_Init */

  /* S-Function (IO_PWM_SetDuty_s): '<S239>/IO_PWM_SetDuty_s' */

  /* function call of IO_PWM_SetDuty */
  {
    flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_c = IO_PWM_SetDuty( IO_PWM_02 ,
      flashHaileyECUv001_B.DataTypeConversion7 ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o2_j ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o3_n );
  }

  /* S-Function (compare2error_s): '<S240>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_k =
      (flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_c == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S30>/IO_PWM_ResetProtection' incorporates:
   *  TriggerPort: '<S238>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_k &&
      (flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_g !=
       POS_ZCSIG)) {
    /* S-Function (IO_PWM_ResetProtection_s): '<S238>/IO_PWM_ResetProtection_s' */

    /* function call of IO_PWM_ResetProtection */
    {
      flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o1_b =
        IO_PWM_ResetProtection( IO_PWM_02 ,
        &flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o2_k );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_g =
    flashHaileyECUv001_B.compare2error_s_k;

  /* End of Outputs for SubSystem: '<S30>/IO_PWM_ResetProtection' */

  /* S-Function (IO_PWM_GetCur_s): '<S236>/IO_PWM_GetCur_s' */

  /* function call of IO_PWM_GetCur */
  {
    flashHaileyECUv001_B.IO_PWM_GetCur_s_o1_o = IO_PWM_GetCur( IO_PWM_02 ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o2_o ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o3_f );
  }

  /* S-Function (IO_PWM_Init_s): '<S237>/IO_PWM_Init_s' */

  /* function call of IO_PWM_Init */

  /* S-Function (IO_PWM_SetDuty_s): '<S244>/IO_PWM_SetDuty_s' */

  /* function call of IO_PWM_SetDuty */
  {
    flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_p = IO_PWM_SetDuty( IO_PWM_04 ,
      flashHaileyECUv001_B.DataTypeConversion8 ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o2_f ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o3_na );
  }

  /* S-Function (compare2error_s): '<S245>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_j =
      (flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_p == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S31>/IO_PWM_ResetProtection' incorporates:
   *  TriggerPort: '<S243>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_j &&
      (flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_k !=
       POS_ZCSIG)) {
    /* S-Function (IO_PWM_ResetProtection_s): '<S243>/IO_PWM_ResetProtection_s' */

    /* function call of IO_PWM_ResetProtection */
    {
      flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o1_c =
        IO_PWM_ResetProtection( IO_PWM_04 ,
        &flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o2_o );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_k =
    flashHaileyECUv001_B.compare2error_s_j;

  /* End of Outputs for SubSystem: '<S31>/IO_PWM_ResetProtection' */

  /* S-Function (IO_PWM_GetCur_s): '<S241>/IO_PWM_GetCur_s' */

  /* function call of IO_PWM_GetCur */
  {
    flashHaileyECUv001_B.IO_PWM_GetCur_s_o1_f = IO_PWM_GetCur( IO_PWM_04 ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o2_k ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o3_d );
  }

  /* S-Function (IO_PWM_Init_s): '<S242>/IO_PWM_Init_s' */

  /* function call of IO_PWM_Init */

  /* S-Function (IO_PWM_SetDuty_s): '<S249>/IO_PWM_SetDuty_s' */

  /* function call of IO_PWM_SetDuty */
  {
    flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_l = IO_PWM_SetDuty( IO_PWM_06 ,
      flashHaileyECUv001_B.DataTypeConversion8 ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o2_l ,
      &flashHaileyECUv001_B.IO_PWM_SetDuty_s_o3_d );
  }

  /* S-Function (compare2error_s): '<S250>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_g =
      (flashHaileyECUv001_B.IO_PWM_SetDuty_s_o1_l == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S32>/IO_PWM_ResetProtection' incorporates:
   *  TriggerPort: '<S248>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_g &&
      (flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_ZCE !=
       POS_ZCSIG)) {
    /* S-Function (IO_PWM_ResetProtection_s): '<S248>/IO_PWM_ResetProtection_s' */

    /* function call of IO_PWM_ResetProtection */
    {
      flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o1 = IO_PWM_ResetProtection(
        IO_PWM_06 , &flashHaileyECUv001_B.IO_PWM_ResetProtection_s_o2 );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_ZCE =
    flashHaileyECUv001_B.compare2error_s_g;

  /* End of Outputs for SubSystem: '<S32>/IO_PWM_ResetProtection' */

  /* S-Function (IO_PWM_GetCur_s): '<S246>/IO_PWM_GetCur_s' */

  /* function call of IO_PWM_GetCur */
  {
    flashHaileyECUv001_B.IO_PWM_GetCur_s_o1_k = IO_PWM_GetCur( IO_PWM_06 ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o2_i ,
      &flashHaileyECUv001_B.IO_PWM_GetCur_s_o3_l );
  }

  /* S-Function (IO_PWM_Init_s): '<S247>/IO_PWM_Init_s' */

  /* function call of IO_PWM_Init */

  /* MinMax: '<Root>/Max1' */
  if (flashHaileyECUv001_B.bit_unpacking_s_bd >=
      flashHaileyECUv001_B.bit_unpacking_s_bm) {
    /* MinMax: '<Root>/Max1' */
    flashHaileyECUv001_B.Max1 = flashHaileyECUv001_B.bit_unpacking_s_bd;
  } else {
    /* MinMax: '<Root>/Max1' */
    flashHaileyECUv001_B.Max1 = flashHaileyECUv001_B.bit_unpacking_s_bm;
  }

  /* End of MinMax: '<Root>/Max1' */

  /* MinMax: '<Root>/Max2' */
  if (flashHaileyECUv001_B.bit_unpacking_s_ie >=
      flashHaileyECUv001_B.bit_unpacking_s_mt) {
    /* MinMax: '<Root>/Max2' */
    flashHaileyECUv001_B.Max2 = flashHaileyECUv001_B.bit_unpacking_s_ie;
  } else {
    /* MinMax: '<Root>/Max2' */
    flashHaileyECUv001_B.Max2 = flashHaileyECUv001_B.bit_unpacking_s_mt;
  }

  /* End of MinMax: '<Root>/Max2' */

  /* S-Function (bit_unpacking_s): '<S255>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_k5[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_lj , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S259>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_g[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_d2 , 2U , 2U , 0U , 32U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (IO_DO_Set_s): '<S286>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_p = IO_DO_Set( IO_DO_02 ,
      flashHaileyECUv001_B.RTDLED );
  }

  /* S-Function (compare2error_s): '<S287>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_e = (flashHaileyECUv001_B.IO_DO_Set_s_p
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S40>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S285>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_e &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_j !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S285>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_o = IO_DO_ResetProtection(
        IO_DO_02 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_o );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_j =
    flashHaileyECUv001_B.compare2error_s_e;

  /* End of Outputs for SubSystem: '<S40>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S283>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_d = IO_DO_GetVoltage( IO_DO_02 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_j ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_d );
  }

  /* S-Function (IO_DO_GetCur_s): '<S282>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_g = IO_DO_GetCur( IO_DO_02 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_c ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_f );
  }

  /* S-Function (IO_DO_Init_s): '<S284>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S292>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_b = IO_DO_Set( IO_DO_01 ,
      flashHaileyECUv001_B.RTDSGR );
  }

  /* S-Function (compare2error_s): '<S293>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_c = (flashHaileyECUv001_B.IO_DO_Set_s_b
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S41>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S291>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_c &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_g !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S291>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_a = IO_DO_ResetProtection(
        IO_DO_01 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_n );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_g =
    flashHaileyECUv001_B.compare2error_s_c;

  /* End of Outputs for SubSystem: '<S41>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S289>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_g = IO_DO_GetVoltage( IO_DO_01 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_a ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_o );
  }

  /* S-Function (IO_DO_GetCur_s): '<S288>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_d = IO_DO_GetCur( IO_DO_01 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_l ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_o );
  }

  /* S-Function (IO_DO_Init_s): '<S290>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (ADC_ChannelInit_s): '<S294>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* Chart: '<S47>/action chart' */
  /* Gateway: Subsystem/action chart */
  /* During: Subsystem/action chart */
  if (flashHaileyECUv001_DWork.is_active_c2_flashHaileyECUv001 == 0U) {
    /* Entry: Subsystem/action chart */
    flashHaileyECUv001_DWork.is_active_c2_flashHaileyECUv001 = 1U;

    /* Entry Internal: Subsystem/action chart */
    /* Transition: '<S302>:8' */
    flashHaileyECUv001_DWork.is_c2_flashHaileyECUv001 =
      flashHaileyECUv001_IN_noaction;

    /* Entry 'noaction': '<S302>:7' */
  } else if (flashHaileyECUv001_DWork.is_c2_flashHaileyECUv001 ==
             flashHaileyECUv001_IN_action) {
    /* During 'action': '<S302>:9' */
    if (!flashHaileyECUv001_B.action) {
      /* Transition: '<S302>:11' */
      flashHaileyECUv001_DWork.is_c2_flashHaileyECUv001 =
        flashHaileyECUv001_IN_noaction;

      /* Entry 'noaction': '<S302>:7' */
    }

    /* During 'noaction': '<S302>:7' */
  } else if (flashHaileyECUv001_B.action) {
    /* Transition: '<S302>:10' */
    flashHaileyECUv001_DWork.is_c2_flashHaileyECUv001 =
      flashHaileyECUv001_IN_action;

    /* Entry 'action': '<S302>:9' */
  }

  /* End of Chart: '<S47>/action chart' */

  /* S-Function (IO_DO_Set_s): '<S315>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_n = IO_DO_Set( IO_DO_05 ,
      flashHaileyECUv001_B.MCR );
  }

  /* S-Function (compare2error_s): '<S316>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_n = (flashHaileyECUv001_B.IO_DO_Set_s_n
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S50>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S314>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_n &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_n !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S314>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_f = IO_DO_ResetProtection(
        IO_DO_05 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_c );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_n =
    flashHaileyECUv001_B.compare2error_s_n;

  /* End of Outputs for SubSystem: '<S50>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S312>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_k = IO_DO_GetVoltage( IO_DO_05 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_c ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_dj );
  }

  /* S-Function (IO_DO_GetCur_s): '<S311>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_gb = IO_DO_GetCur( IO_DO_05 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_g ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_c );
  }

  /* S-Function (IO_DO_Init_s): '<S313>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S321>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_k = IO_DO_Set( IO_DO_04 ,
      flashHaileyECUv001_B.MCR );
  }

  /* S-Function (compare2error_s): '<S322>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_a = (flashHaileyECUv001_B.IO_DO_Set_s_k
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S51>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S320>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_a &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_m !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S320>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_i = IO_DO_ResetProtection(
        IO_DO_04 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_m );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_m =
    flashHaileyECUv001_B.compare2error_s_a;

  /* End of Outputs for SubSystem: '<S51>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S318>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_l = IO_DO_GetVoltage( IO_DO_04 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_k ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_p );
  }

  /* S-Function (IO_DO_GetCur_s): '<S317>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_o = IO_DO_GetCur( IO_DO_04 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_h ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_k );
  }

  /* S-Function (IO_DO_Init_s): '<S319>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_CAN_ConfigMsg_s): '<S323>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (bit_packing_s): '<S325>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.Max2 ,
                &flashHaileyECUv001_B.bit_packing_s_jr[0] , 2U , 2U , 0U , 0U ,
                16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S326>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.Max1 ,
                &flashHaileyECUv001_B.bit_packing_s_ch[0] , 2U , 2U , 0U , 16U ,
                16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S327>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s ,
                &flashHaileyECUv001_B.bit_packing_s_gi[0] , 2U , 2U , 0U , 32U ,
                16U , 0.1 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S328>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.bit_unpacking_s_e ,
                &flashHaileyECUv001_B.bit_packing_s_lu[0] , 2U , 2U , 0U , 48U ,
                16U , 0.1 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S52>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_f[0] = flashHaileyECUv001_B.bit_packing_s_jr[0] |
    flashHaileyECUv001_B.bit_packing_s_ch[0] |
    flashHaileyECUv001_B.bit_packing_s_gi[0] |
    flashHaileyECUv001_B.bit_packing_s_lu[0];
  flashHaileyECUv001_B.OR_TX_f[1] = flashHaileyECUv001_B.bit_packing_s_jr[1] |
    flashHaileyECUv001_B.bit_packing_s_ch[1] |
    flashHaileyECUv001_B.bit_packing_s_gi[1] |
    flashHaileyECUv001_B.bit_packing_s_lu[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S324>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S52>/id_TX'
   *  Constant: '<S52>/id_format_TX'
   *  Constant: '<S52>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_f[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_n;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_h;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_b;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_j = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_h ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S337>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* Outputs for Enabled SubSystem: '<S56>/IO_CAN_ReadMsg' incorporates:
   *  EnablePort: '<S338>/Enable'
   */
  /* RelationalOperator: '<S385>/Compare' incorporates:
   *  Constant: '<S385>/Constant'
   *  UnitDelay: '<S386>/Output'
   */
  if (flashHaileyECUv001_DWork.Output_DSTATE ==
      flashHaileyECUv001_P.Trigger_Block_trigger_offset) {
    /* S-Function (IO_CAN_ReadMsg_s): '<S384>/IO_CAN_ReadMsg_s' */

    /* function call of IO_CAN_ReadMsg */
    {
      IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

      flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_p = IO_CAN_ReadMsg
        ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_hc ,&tmp_struct_1);
      memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0],tmp_struct_1.data,2*
             sizeof(uint32_T));
      flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_ho = tmp_struct_1.length;
      flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_a = tmp_struct_1.id_format;
      flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_i = tmp_struct_1.id;
    }
  }

  /* End of RelationalOperator: '<S385>/Compare' */
  /* End of Outputs for SubSystem: '<S56>/IO_CAN_ReadMsg' */

  /* Sum: '<S387>/FixPt Sum1' incorporates:
   *  Constant: '<S387>/FixPt Constant'
   *  UnitDelay: '<S386>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)flashHaileyECUv001_DWork.Output_DSTATE +
    flashHaileyECUv001_P.FixPtConstant_Value);

  /* S-Function (bit_unpacking_s): '<S340>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_j1 , 2U , 1U , 0U , 0U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S341>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_n3 , 2U , 1U , 0U , 9U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S342>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_mp , 2U , 1U , 0U , 10U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S343>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_cc , 2U , 1U , 0U , 11U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S344>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_iy , 2U , 1U , 0U , 12U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S345>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ng , 2U , 1U , 0U , 13U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S346>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ae , 2U , 1U , 0U , 14U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S347>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_lf , 2U , 1U , 0U , 15U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S348>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_n1 , 2U , 1U , 0U , 16U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S349>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_jb , 2U , 1U , 0U , 17U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S350>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_no , 2U , 1U , 0U , 18U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S351>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_hr , 2U , 1U , 0U , 1U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S352>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_hc , 2U , 1U , 0U , 19U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S353>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pt , 2U , 1U , 0U , 20U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S354>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_lg , 2U , 1U , 0U , 21U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S355>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dt , 2U , 1U , 0U , 22U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S356>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_i1 , 2U , 1U , 0U , 23U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S357>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_cr , 2U , 1U , 0U , 24U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S358>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_hr0 , 2U , 1U , 0U , 25U
                  , 1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S359>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_a2 , 2U , 1U , 0U , 26U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S360>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_je , 2U , 1U , 0U , 27U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S361>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_jv , 2U , 1U , 0U , 28U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S362>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_as , 2U , 1U , 0U , 2U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S363>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pf , 2U , 1U , 0U , 29U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S364>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dd , 2U , 1U , 0U , 30U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S365>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ed , 2U , 1U , 0U , 31U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S366>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ou , 2U , 1U , 0U , 32U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S367>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_dg , 2U , 1U , 0U , 33U ,
                  3U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S368>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_p2 , 2U , 1U , 0U , 36U ,
                  4U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S369>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_iyi , 2U , 1U , 0U , 40U
                  , 16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S370>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_pm , 2U , 1U , 0U , 56U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S371>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_oc , 2U , 1U , 0U , 57U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S372>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_a0 , 2U , 1U , 0U , 58U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S373>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_h0 , 2U , 1U , 0U , 3U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S374>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_m3 , 2U , 1U , 0U , 59U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S375>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_hd , 2U , 1U , 0U , 60U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S376>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_gz , 2U , 1U , 0U , 61U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S377>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_lq , 2U , 1U , 0U , 62U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S378>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_f , 2U , 1U , 0U , 63U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S379>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_au , 2U , 1U , 0U , 4U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S380>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ja , 2U , 1U , 0U , 5U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S381>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_e4 , 2U , 1U , 0U , 6U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S382>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_fy , 2U , 1U , 0U , 7U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S383>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_n[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_fh , 2U , 1U , 0U , 8U ,
                  1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S137>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (ADC_Get_s): '<S304>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_k = IO_ADC_Get( IO_ADC_07 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_h ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_k );
  }

  /* RelationalOperator: '<Root>/Relational Operator3' incorporates:
   *  Constant: '<Root>/Constant25'
   */
  flashHaileyECUv001_B.RelationalOperator3 =
    (flashHaileyECUv001_B.ADC_Get_s_o2_h < flashHaileyECUv001_P.Constant25_Value);

  /* S-Function (bit_packing_s): '<S139>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( flashHaileyECUv001_B.RelationalOperator3 ,
                &flashHaileyECUv001_B.bit_packing_s_hf[0] , 2U , 1U , 0U , 0U ,
                1U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_WriteMsg_s): '<S138>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S15>/id_TX'
   *  Constant: '<S15>/id_format_TX'
   *  Constant: '<S15>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.bit_packing_s_hf[0],2*sizeof
           (uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_os;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_e;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_i;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_o = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_e ,&tmp_struct_1);
  }

  /* S-Function (ADC_ChannelInit_s): '<S303>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (ADC_Get_s): '<S58>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_a = IO_ADC_Get( IO_ADC_UBAT ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_p ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_h );
  }

  /* S-Function (ADC_ChannelInit_s): '<S57>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* Chart: '<Root>/Chart' */
  if (flashHaileyECUv001_DWork.temporalCounter_i1 < 511U) {
    flashHaileyECUv001_DWork.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (flashHaileyECUv001_DWork.is_active_c3_flashHaileyECUv001 == 0U) {
    /* Entry: Chart */
    flashHaileyECUv001_DWork.is_active_c3_flashHaileyECUv001 = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S19>:2' */
    flashHaileyECUv001_DWork.is_c3_flashHaileyECUv001 =
      flashHaileyECUv001_IN_aus;
    flashHaileyECUv001_DWork.temporalCounter_i1 = 0U;

    /* Entry 'aus': '<S19>:1' */
    RelationalOperator = false;
  } else if (flashHaileyECUv001_DWork.is_c3_flashHaileyECUv001 ==
             flashHaileyECUv001_IN_an) {
    RelationalOperator = true;

    /* During 'an': '<S19>:3' */
  } else {
    RelationalOperator = false;

    /* During 'aus': '<S19>:1' */
    if (flashHaileyECUv001_DWork.temporalCounter_i1 >= 500U) {
      /* Transition: '<S19>:4' */
      flashHaileyECUv001_DWork.is_c3_flashHaileyECUv001 =
        flashHaileyECUv001_IN_an;

      /* Entry 'an': '<S19>:3' */
      RelationalOperator = true;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* DataTypeConversion: '<S39>/Data Type Conversion' */
  flashHaileyECUv001_B.DataTypeConversion = RelationalOperator;

  /* S-Function (IO_POWER_Set_s): '<S278>/IO_POWER_Set_s' */

  /* function call of IO_POWER_Set */
  {
    flashHaileyECUv001_B.IO_POWER_Set_s = IO_POWER_Set( IO_INT_POWERSTAGE_ENABLE
      , flashHaileyECUv001_B.DataTypeConversion );
  }

  /* S-Function (IO_POWER_Set_s): '<S279>/IO_POWER_Set_s' */

  /* function call of IO_POWER_Set */
  {
    flashHaileyECUv001_B.IO_POWER_Set_s_e = IO_POWER_Set( IO_INT_SAFETY_SW_0 ,
      flashHaileyECUv001_B.DataTypeConversion );
  }

  /* S-Function (IO_POWER_Set_s): '<S280>/IO_POWER_Set_s' */

  /* function call of IO_POWER_Set */
  {
    flashHaileyECUv001_B.IO_POWER_Set_s_f = IO_POWER_Set( IO_INT_SAFETY_SW_1 ,
      flashHaileyECUv001_B.DataTypeConversion );
  }

  /* S-Function (IO_POWER_Set_s): '<S281>/IO_POWER_Set_s' */

  /* function call of IO_POWER_Set */
  {
    flashHaileyECUv001_B.IO_POWER_Set_s_o = IO_POWER_Set( IO_INT_SAFETY_SW_2 ,
      flashHaileyECUv001_B.DataTypeConversion );
  }

  /* S-Function (IO_DO_Set_s): '<S309>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant13'
   */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_h = IO_DO_Set( IO_DO_03 ,
      flashHaileyECUv001_P.Constant13_Value );
  }

  /* S-Function (compare2error_s): '<S310>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_kb =
      (flashHaileyECUv001_B.IO_DO_Set_s_h == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S49>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S308>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_kb &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_i !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S308>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_gf = IO_DO_ResetProtection
        ( IO_DO_03 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_cu );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_i =
    flashHaileyECUv001_B.compare2error_s_kb;

  /* End of Outputs for SubSystem: '<S49>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S306>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_gn = IO_DO_GetVoltage( IO_DO_03 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_g ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_l );
  }

  /* S-Function (IO_DO_GetCur_s): '<S305>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_c = IO_DO_GetCur( IO_DO_03 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_d ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_e );
  }

  /* S-Function (IO_DO_Init_s): '<S307>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S276>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant14'
   */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_d = IO_DO_Set( IO_DO_55 ,
      flashHaileyECUv001_P.Constant14_Value );
  }

  /* S-Function (compare2error_s): '<S277>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_o = (flashHaileyECUv001_B.IO_DO_Set_s_d
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S38>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S275>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_o &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_k !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S275>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_p = IO_DO_ResetProtection(
        IO_DO_55 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_d );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_k =
    flashHaileyECUv001_B.compare2error_s_o;

  /* End of Outputs for SubSystem: '<S38>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S273>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_n = IO_DO_GetVoltage( IO_DO_55 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_gt ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_n );
  }

  /* S-Function (IO_DO_GetCur_s): '<S272>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_i = IO_DO_GetCur( IO_DO_55 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_b ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_b );
  }

  /* S-Function (IO_DO_Init_s): '<S274>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S264>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant15'
   */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_i = IO_DO_Set( IO_DO_52 ,
      flashHaileyECUv001_P.Constant15_Value );
  }

  /* S-Function (compare2error_s): '<S265>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_oz =
      (flashHaileyECUv001_B.IO_DO_Set_s_i == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S36>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S263>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_oz &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_Z_nn !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S263>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_l = IO_DO_ResetProtection(
        IO_DO_52 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_o2 );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_Z_nn =
    flashHaileyECUv001_B.compare2error_s_oz;

  /* End of Outputs for SubSystem: '<S36>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S261>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_dy = IO_DO_GetVoltage( IO_DO_52 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_d ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_j );
  }

  /* S-Function (IO_DO_GetCur_s): '<S260>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_ch = IO_DO_GetCur( IO_DO_52 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_n ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_eb );
  }

  /* S-Function (IO_DO_Init_s): '<S262>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S270>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant18'
   */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_g = IO_DO_Set( IO_DO_54 ,
      flashHaileyECUv001_P.Constant18_Value );
  }

  /* S-Function (compare2error_s): '<S271>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_cy =
      (flashHaileyECUv001_B.IO_DO_Set_s_g == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S37>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S269>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_cy &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_p !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S269>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_pm = IO_DO_ResetProtection
        ( IO_DO_54 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_e );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_p =
    flashHaileyECUv001_B.compare2error_s_cy;

  /* End of Outputs for SubSystem: '<S37>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_GetVoltage_s): '<S267>/IO_DO_GetVoltage_s' */

  /* function call of IO_DO_GetVoltage */
  {
    flashHaileyECUv001_B.IO_DO_GetVoltage_s_o1_c = IO_DO_GetVoltage( IO_DO_54 ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o2_b ,
      &flashHaileyECUv001_B.IO_DO_GetVoltage_s_o3_f );
  }

  /* S-Function (IO_DO_GetCur_s): '<S266>/IO_DO_GetCur_s' */

  /* function call of IO_DO_GetCur */
  {
    flashHaileyECUv001_B.IO_DO_GetCur_s_o1_l = IO_DO_GetCur( IO_DO_54 ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o2_e ,
      &flashHaileyECUv001_B.IO_DO_GetCur_s_o3_os );
  }

  /* S-Function (IO_DO_Init_s): '<S268>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (ADC_Get_s): '<S301>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_p = IO_ADC_Get( IO_ADC_01 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_i ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_d );
  }

  /* S-Function (ADC_ChannelInit_s): '<S300>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/Constant24'
   */
  flashHaileyECUv001_B.RelationalOperator1 =
    (flashHaileyECUv001_B.ADC_Get_s_o2_i < flashHaileyECUv001_P.Constant24_Value);

  /* S-Function (IO_DO_Set_s): '<S331>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_c = IO_DO_Set( IO_DO_24 ,
      flashHaileyECUv001_B.RelationalOperator1 );
  }

  /* S-Function (compare2error_s): '<S332>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_ed =
      (flashHaileyECUv001_B.IO_DO_Set_s_c == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S53>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S330>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_ed &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_l !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S330>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1_g = IO_DO_ResetProtection(
        IO_DO_24 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2_p );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_l =
    flashHaileyECUv001_B.compare2error_s_ed;

  /* End of Outputs for SubSystem: '<S53>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_Init_s): '<S329>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S335>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_cd = IO_DO_Set( IO_DO_26 ,
      flashHaileyECUv001_B.RelationalOperator1 );
  }

  /* S-Function (compare2error_s): '<S336>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_kh =
      (flashHaileyECUv001_B.IO_DO_Set_s_cd == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S54>/IO_DO_ResetProtection' incorporates:
   *  TriggerPort: '<S334>/Trigger'
   */
  if (flashHaileyECUv001_B.compare2error_s_kh &&
      (flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZCE !=
       POS_ZCSIG)) {
    /* S-Function (IO_DO_ResetProtection_s): '<S334>/IO_DO_ResetProtection_s' */

    /* function call of IO_DO_ResetProtection */
    {
      flashHaileyECUv001_B.IO_DO_ResetProtection_s_o1 = IO_DO_ResetProtection
        ( IO_DO_26 , &flashHaileyECUv001_B.IO_DO_ResetProtection_s_o2 );
    }
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZCE =
    flashHaileyECUv001_B.compare2error_s_kh;

  /* End of Outputs for SubSystem: '<S54>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_Init_s): '<S333>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_CAN_ConfigMsg_s): '<S181>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (bit_packing_s): '<S183>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_ax[0] , 2U , 1U , 0U ,
                0U , 8U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S184>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_mz[0] , 2U , 1U , 0U ,
                8U , 8U , 1.0 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S155>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_n[0] = flashHaileyECUv001_B.bit_packing_s_ax[0] |
    flashHaileyECUv001_B.bit_packing_s_mz[0];
  flashHaileyECUv001_B.OR_TX_n[1] = flashHaileyECUv001_B.bit_packing_s_ax[1] |
    flashHaileyECUv001_B.bit_packing_s_mz[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S182>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S155>/id_TX'
   *  Constant: '<S155>/id_format_TX'
   *  Constant: '<S155>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_n[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_o4;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_m;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_d;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_m = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_d ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S157>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S158>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_gg = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_ke ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_d[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_h = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_oa = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_m = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S159>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_d[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_i5p , 2U , 1U , 0U , 0U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S185>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* SignalConversion generated from: '<S186>/IO_CAN_WriteMsg_s' */
  flashHaileyECUv001_B.TmpSignalConversionAtIO_CAN_Wri[0] = 0U;
  flashHaileyECUv001_B.TmpSignalConversionAtIO_CAN_Wri[1] = 0U;

  /* S-Function (IO_CAN_WriteMsg_s): '<S186>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S156>/id_TX'
   *  Constant: '<S156>/id_format_TX'
   *  Constant: '<S156>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,
           &flashHaileyECUv001_B.TmpSignalConversionAtIO_CAN_Wri[0],2*sizeof
           (uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_a;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_l2;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_o;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_l = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_cn ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S173>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (bit_packing_s): '<S175>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_b[0] , 2U , 1U , 0U ,
                0U , 16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S176>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_dv[0] , 2U , 2U , 0U ,
                16U , 8U , 1.0 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S153>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_lp[0] = flashHaileyECUv001_B.bit_packing_s_b[0] |
    flashHaileyECUv001_B.bit_packing_s_dv[0];
  flashHaileyECUv001_B.OR_TX_lp[1] = flashHaileyECUv001_B.bit_packing_s_b[1] |
    flashHaileyECUv001_B.bit_packing_s_dv[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S174>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S153>/id_TX'
   *  Constant: '<S153>/id_format_TX'
   *  Constant: '<S153>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_lp[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_k;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_hf;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_g;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_d = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_o ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S160>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S161>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_l = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_eu ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_e[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_iu = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_f = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_f2 = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S162>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_e[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_an , 2U , 1U , 0U , 0U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S163>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_e[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_nr , 2U , 2U , 0U , 16U ,
                  8U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S177>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (bit_packing_s): '<S179>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_oo[0] , 2U , 1U , 0U ,
                0U , 16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_packing_s): '<S180>/bit_packing_s' */

  /* function call of bit_packing */
  {
    bit_packing( 0U , &flashHaileyECUv001_B.bit_packing_s_la[0] , 2U , 2U , 0U ,
                16U , 32U , 1.0 , 0.0 );
  }

  /* S-Function (sfix_bitop): '<S154>/OR_TX' */
  flashHaileyECUv001_B.OR_TX_j[0] = flashHaileyECUv001_B.bit_packing_s_oo[0] |
    flashHaileyECUv001_B.bit_packing_s_la[0];
  flashHaileyECUv001_B.OR_TX_j[1] = flashHaileyECUv001_B.bit_packing_s_oo[1] |
    flashHaileyECUv001_B.bit_packing_s_la[1];

  /* S-Function (IO_CAN_WriteMsg_s): '<S178>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S154>/id_TX'
   *  Constant: '<S154>/id_format_TX'
   *  Constant: '<S154>/length_TX'
   */

  /* function call of IO_CAN_WriteMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    memcpy(tmp_struct_1.data,&flashHaileyECUv001_B.OR_TX_j[0],2*sizeof(uint32_T));
    tmp_struct_1.length = flashHaileyECUv001_P.length_TX_Value_nv;
    tmp_struct_1.id_format = flashHaileyECUv001_P.id_format_TX_Value_i;
    tmp_struct_1.id = flashHaileyECUv001_P.id_TX_Value_ok;
    flashHaileyECUv001_B.IO_CAN_WriteMsg_s_o5 = IO_CAN_WriteMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_pn ,&tmp_struct_1);
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S164>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S165>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_k = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_dp ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_m[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_lk = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_dw = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_ca = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S166>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_m[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_h4 , 2U , 1U , 0U , 0U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S167>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_m[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_fp , 2U , 2U , 0U , 16U ,
                  32U , 1.0 , 0.0 );
  }

  /* S-Function (IO_CAN_ConfigMsg_s): '<S168>/IO_CAN_ConfigMsg_s' */

  /* function call of IO_CAN_ConfigMsg */

  /* S-Function (IO_CAN_ReadMsg_s): '<S169>/IO_CAN_ReadMsg_s' */

  /* function call of IO_CAN_ReadMsg */
  {
    IO_CAN_DATA_FRAME tmp_struct_1= { 0 };

    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o1_hm = IO_CAN_ReadMsg
      ( flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_m ,&tmp_struct_1);
    memcpy(&flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_f[0],tmp_struct_1.data,2*
           sizeof(uint32_T));
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o3_g = tmp_struct_1.length;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o4_dp = tmp_struct_1.id_format;
    flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o5_gl = tmp_struct_1.id;
  }

  /* S-Function (bit_unpacking_s): '<S170>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_f[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_ct , 2U , 1U , 0U , 0U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S171>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_f[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_fz , 2U , 2U , 0U , 16U ,
                  32U , 1.0 , 0.0 );
  }

  /* S-Function (bit_unpacking_s): '<S172>/bit_unpacking_s' */

  /* function call of bit_unpacking */
  {
    bit_unpacking( &flashHaileyECUv001_B.IO_CAN_ReadMsg_s_o2_f[0] ,
                  &flashHaileyECUv001_B.bit_unpacking_s_hs , 2U , 2U , 0U , 48U ,
                  16U , 1.0 , 0.0 );
  }

  /* S-Function (ADC_Get_s): '<S214>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_av = IO_ADC_Get( IO_ADC_08 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_e ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_n );
  }

  /* S-Function (ADC_ChannelInit_s): '<S213>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (IO_DO_Set_s): '<S207>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_m = IO_DO_Set( IO_DO_08 , false );
  }

  /* S-Function (compare2error_s): '<S208>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_og =
      (flashHaileyECUv001_B.IO_DO_Set_s_m == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S202>/IO_DO_ResetProtection' */
  flashHail_IO_DO_ResetProtection(flashHaileyECUv001_B.compare2error_s_og,
    &flashHaileyECUv001_B.IO_DO_ResetProtection_o,
    &flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_o);

  /* End of Outputs for SubSystem: '<S202>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_Init_s): '<S205>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (IO_DO_Set_s): '<S211>/IO_DO_Set_s' */

  /* function call of IO_DO_Set */
  {
    flashHaileyECUv001_B.IO_DO_Set_s_f = IO_DO_Set( IO_DO_08 , false );
  }

  /* S-Function (compare2error_s): '<S212>/compare2error_s' */

  /* function call of compare2error */
  {
    flashHaileyECUv001_B.compare2error_s_p = (flashHaileyECUv001_B.IO_DO_Set_s_f
      == IO_E_FET_PROT_REENABLE) ;
  }

  /* Outputs for Triggered SubSystem: '<S203>/IO_DO_ResetProtection' */
  flashHail_IO_DO_ResetProtection(flashHaileyECUv001_B.compare2error_s_p,
    &flashHaileyECUv001_B.IO_DO_ResetProtection_f,
    &flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_f);

  /* End of Outputs for SubSystem: '<S203>/IO_DO_ResetProtection' */

  /* S-Function (IO_DO_Init_s): '<S209>/IO_DO_Init_s' */

  /* function call of IO_DO_Init */

  /* S-Function (ADC_Get_s): '<S216>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_d = IO_ADC_Get( IO_ADC_06 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_o ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_o );
  }

  /* S-Function (ADC_ChannelInit_s): '<S215>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (ADC_Get_s): '<S218>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_c = IO_ADC_Get( IO_ADC_04 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_ek ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_nf );
  }

  /* S-Function (ADC_ChannelInit_s): '<S217>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (ADC_Get_s): '<S220>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_lw = IO_ADC_Get( IO_ADC_02 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_j ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_e );
  }

  /* S-Function (ADC_ChannelInit_s): '<S219>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (ADC_Get_s): '<S222>/ADC_Get_s' */

  /* function call of ADC_Get */
  {
    flashHaileyECUv001_B.ADC_Get_s_o1_cg = IO_ADC_Get( IO_ADC_00 ,(ubyte4*)
      &flashHaileyECUv001_B.ADC_Get_s_o2_hn ,
      &flashHaileyECUv001_B.ADC_Get_s_o3_pk );
  }

  /* S-Function (ADC_ChannelInit_s): '<S221>/ADC_ChannelInit_s' */

  /* function call of ADC_ChannelInit */

  /* S-Function (IO_PWD_ComplexGet_s): '<S296>/IO_PWD_ComplexGet_s' */

  /* function call of IO_PWD_ComplexGet */
  {
    flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o1 = IO_PWD_ComplexGet( IO_PWD_08 ,
      (ubyte4*) &flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o2 ,(ubyte4*)
      &flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o3 , NULL , NULL );
  }

  /* S-Function (PWD_ComplexInit_s): '<S297>/PWD_ComplexInit_s' */

  /* function call of PWD_ComplexInit */

  /* S-Function (IO_PWD_ComplexGet_s): '<S298>/IO_PWD_ComplexGet_s' */

  /* function call of IO_PWD_ComplexGet */
  {
    flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o1_d = IO_PWD_ComplexGet( IO_PWD_10
      ,(ubyte4*) &flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o2_h ,(ubyte4*)
      &flashHaileyECUv001_B.IO_PWD_ComplexGet_s_o3_h , NULL , NULL );
  }

  /* S-Function (PWD_ComplexInit_s): '<S299>/PWD_ComplexInit_s' */

  /* function call of PWD_ComplexInit */

  /* Switch: '<S388>/FixPt Switch' */
  if (rtb_FixPtSum1 > flashHaileyECUv001_P.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S386>/Output' incorporates:
     *  Constant: '<S388>/Constant'
     */
    flashHaileyECUv001_DWork.Output_DSTATE =
      flashHaileyECUv001_P.Constant_Value_o;
  } else {
    /* Update for UnitDelay: '<S386>/Output' */
    flashHaileyECUv001_DWork.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S388>/FixPt Switch' */
}

/* Model initialize function */
void flashHaileyECUv001_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(flashHaileyECUv001_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &flashHaileyECUv001_B), 0,
                sizeof(BlockIO_flashHaileyECUv001));

  {
    flashHaileyECUv001_B.bit_unpacking_s = 0.0;
    flashHaileyECUv001_B.t3 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_e = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_d = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_m = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dj = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_b = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_i = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dr = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_a = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_g = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_p = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_k = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_o = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_i5 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_kt = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_px = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dn = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pj = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_j = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_gj = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_l = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_bt = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ac = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_jw = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_bd = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ep = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ie = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_bm = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_c = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_mt = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_n = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ky = 0.0;
    flashHaileyECUv001_B.Saturation = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_nk = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pa = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_mz = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_jp = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_el = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_cx = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_bm0 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_lc = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_h = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_br = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_gjh = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_nks = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ef = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_nf = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_po = 0.0;
    flashHaileyECUv001_B.Product9 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_mw = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_eu = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pw = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_i0 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ci = 0.0;
    flashHaileyECUv001_B.Max1 = 0.0;
    flashHaileyECUv001_B.Max2 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_lj = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_d2 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_j1 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_n3 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_mp = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_cc = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_iy = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ng = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ae = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_lf = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_n1 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_jb = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_no = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_hr = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_hc = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pt = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_lg = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dt = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_i1 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_cr = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_hr0 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_a2 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_je = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_jv = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_as = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pf = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dd = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ed = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ou = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_dg = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_p2 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_iyi = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_pm = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_oc = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_a0 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_h0 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_m3 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_hd = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_gz = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_lq = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_f = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_au = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ja = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_e4 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_fy = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_fh = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_i5p = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_an = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_nr = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_h4 = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_fp = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_ct = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_fz = 0.0;
    flashHaileyECUv001_B.bit_unpacking_s_hs = 0.0;
    flashHaileyECUv001_B.staten = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&flashHaileyECUv001_DWork, 0,
                sizeof(D_Work_flashHaileyECUv001));

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S89>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1 = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2 , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x28D , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S90>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S91>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S95>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_d = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_f , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x285 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S96>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S97>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (ADC_Get_s): '<S60>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S59>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s = IO_ADC_ChannelInit( IO_ADC_UBAT ,
      IO_ADC_ABSOLUTE , IO_ADC_RANGE_32V , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S62>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S61>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_f = IO_ADC_ChannelInit( IO_ADC_UBAT ,
      IO_ADC_ABSOLUTE , IO_ADC_RANGE_32V , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S63>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_o = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_a , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x28B , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S64>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S68>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S76>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_m = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_j , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x283 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S77>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S81>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S65>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S66>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S67>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S69>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S70>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S71>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S72>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S73>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S74>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S75>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S78>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S79>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S80>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S82>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S83>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S84>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S85>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S86>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S87>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S88>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S92>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S93>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S94>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S98>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S99>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S100>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S101>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_md = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_b , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x18C , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S256>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_p = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_k , IO_CAN_CHANNEL_2 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x1EF , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S257>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S258>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (ADC_Get_s): '<S295>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S252>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_dr = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_g , IO_CAN_CHANNEL_2 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x1EE , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S253>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S254>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (ADC_Get_s): '<S141>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S223>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_d0 = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_n , IO_CAN_CHANNEL_3 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x06D , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S224>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S225>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_packing_s): '<S103>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S104>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S105>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S106>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S119>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_g = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_p , IO_CAN_CHANNEL_0 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x18C , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S120>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S125>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_packing_s): '<S107>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_unpacking_s): '<S126>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_packing_s): '<S108>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S109>/bit_packing_s' incorporates:
   *  Constant: '<S47>/Zero'
   */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S102>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S9>/id_TX'
   *  Constant: '<S9>/id_format_TX'
   *  Constant: '<S9>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S110>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_gc = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_c , IO_CAN_CHANNEL_1 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x184 , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S112>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S113>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S114>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S115>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S128>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_px = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_kh , IO_CAN_CHANNEL_0 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x184 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S129>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S134>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_packing_s): '<S116>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_unpacking_s): '<S135>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_packing_s): '<S117>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S118>/bit_packing_s' incorporates:
   *  Constant: '<S47>/Zero'
   */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S111>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S10>/id_TX'
   *  Constant: '<S10>/id_format_TX'
   *  Constant: '<S10>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (bit_unpacking_s): '<S121>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S122>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S123>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S124>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S127>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S130>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S131>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S132>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S133>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S136>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (ADC_ChannelInit_s): '<S140>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_j = IO_ADC_ChannelInit( IO_ADC_08 ,
      IO_ADC_RATIOMETRIC , IO_ADC_RANGE_5V , IO_ADC_NO_PULL , IO_SENSOR_SUPPLY_1
      , NULL );
  }

  /* Start for S-Function (POWER_Set_Init_s): '<S142>/POWER_Set_Init_s' */

  /* init_function call POWER_Set_Init */
  {
    flashHaileyECUv001_B.POWER_Set_Init_s = IO_POWER_Set( IO_SENSOR_SUPPLY_1 ,
      IO_POWER_ON );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S147>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S148>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S17>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S146>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S17>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S144>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S143>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S145>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s = IO_DO_Init( IO_DO_00 , 0 , NULL );
  }

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S187>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_h = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_n4 , IO_CAN_CHANNEL_0 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x7FE , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S189>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S190>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S191>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S192>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S193>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S194>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S195>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S188>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S21>/id_TX'
   *  Constant: '<S21>/id_format_TX'
   *  Constant: '<S21>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S196>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_ph = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_f1 , IO_CAN_CHANNEL_0 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x7FD , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S198>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S199>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S200>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S201>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S197>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S22>/id_TX'
   *  Constant: '<S22>/id_format_TX'
   *  Constant: '<S22>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (bit_unpacking_s): '<S226>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S227>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S228>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S229>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S230>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_PWM_SetDuty_s): '<S234>/IO_PWM_SetDuty_s' */

  /* init_function call IO_PWM_SetDuty */

  /* Start for S-Function (compare2error_s): '<S235>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S29>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_ResetProtection_s): '<S233>/IO_PWM_ResetProtection_s' */

  /* init_function call IO_PWM_ResetProtection */

  /* End of Start for SubSystem: '<S29>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_GetCur_s): '<S231>/IO_PWM_GetCur_s' */

  /* init_function call IO_PWM_GetCur */

  /* Start for S-Function (IO_PWM_Init_s): '<S232>/IO_PWM_Init_s' */

  /* init_function call IO_PWM_Init */
  {
    flashHaileyECUv001_B.IO_PWM_Init_s = IO_PWM_Init( IO_PWM_00 , 50 , 1 , 1 ,
      NULL );
  }

  /* Start for S-Function (IO_PWM_SetDuty_s): '<S239>/IO_PWM_SetDuty_s' */

  /* init_function call IO_PWM_SetDuty */

  /* Start for S-Function (compare2error_s): '<S240>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S30>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_ResetProtection_s): '<S238>/IO_PWM_ResetProtection_s' */

  /* init_function call IO_PWM_ResetProtection */

  /* End of Start for SubSystem: '<S30>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_GetCur_s): '<S236>/IO_PWM_GetCur_s' */

  /* init_function call IO_PWM_GetCur */

  /* Start for S-Function (IO_PWM_Init_s): '<S237>/IO_PWM_Init_s' */

  /* init_function call IO_PWM_Init */
  {
    flashHaileyECUv001_B.IO_PWM_Init_s_o = IO_PWM_Init( IO_PWM_02 , 50 , 1 , 1 ,
      NULL );
  }

  /* Start for S-Function (IO_PWM_SetDuty_s): '<S244>/IO_PWM_SetDuty_s' */

  /* init_function call IO_PWM_SetDuty */

  /* Start for S-Function (compare2error_s): '<S245>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S31>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_ResetProtection_s): '<S243>/IO_PWM_ResetProtection_s' */

  /* init_function call IO_PWM_ResetProtection */

  /* End of Start for SubSystem: '<S31>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_GetCur_s): '<S241>/IO_PWM_GetCur_s' */

  /* init_function call IO_PWM_GetCur */

  /* Start for S-Function (IO_PWM_Init_s): '<S242>/IO_PWM_Init_s' */

  /* init_function call IO_PWM_Init */
  {
    flashHaileyECUv001_B.IO_PWM_Init_s_n = IO_PWM_Init( IO_PWM_04 , 50 , 1 , 1 ,
      NULL );
  }

  /* Start for S-Function (IO_PWM_SetDuty_s): '<S249>/IO_PWM_SetDuty_s' */

  /* init_function call IO_PWM_SetDuty */

  /* Start for S-Function (compare2error_s): '<S250>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S32>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_ResetProtection_s): '<S248>/IO_PWM_ResetProtection_s' */

  /* init_function call IO_PWM_ResetProtection */

  /* End of Start for SubSystem: '<S32>/IO_PWM_ResetProtection' */

  /* Start for S-Function (IO_PWM_GetCur_s): '<S246>/IO_PWM_GetCur_s' */

  /* init_function call IO_PWM_GetCur */

  /* Start for S-Function (IO_PWM_Init_s): '<S247>/IO_PWM_Init_s' */

  /* init_function call IO_PWM_Init */
  {
    flashHaileyECUv001_B.IO_PWM_Init_s_i = IO_PWM_Init( IO_PWM_06 , 50 , 1 , 1 ,
      NULL );
  }

  /* Start for S-Function (bit_unpacking_s): '<S255>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S259>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_DO_Set_s): '<S286>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S287>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S40>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S285>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S40>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S283>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S282>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S284>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_m = IO_DO_Init( IO_DO_02 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S292>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S293>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S41>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S291>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S41>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S289>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S288>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S290>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_l = IO_DO_Init( IO_DO_01 , 0 , NULL );
  }

  /* Start for S-Function (ADC_ChannelInit_s): '<S294>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_a = IO_ADC_ChannelInit( IO_ADC_05 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S315>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S316>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S50>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S314>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S50>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S312>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S311>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S313>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_j = IO_DO_Init( IO_DO_05 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S321>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S322>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S51>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S320>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S51>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S318>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S317>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S319>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_p = IO_DO_Init( IO_DO_04 , 0 , NULL );
  }

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S323>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_c = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_h , IO_CAN_CHANNEL_0 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x7FC , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S325>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S326>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S327>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S328>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S324>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S52>/id_TX'
   *  Constant: '<S52>/id_format_TX'
   *  Constant: '<S52>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S337>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_i = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_hc , IO_CAN_CHANNEL_3 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x101 , 0x7FF );
  }

  /* Start for Enabled SubSystem: '<S56>/IO_CAN_ReadMsg' */

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S384>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* End of Start for SubSystem: '<S56>/IO_CAN_ReadMsg' */

  /* Start for S-Function (bit_unpacking_s): '<S340>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S341>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S342>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S343>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S344>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S345>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S346>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S347>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S348>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S349>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S350>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S351>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S352>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S353>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S354>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S355>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S356>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S357>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S358>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S359>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S360>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S361>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S362>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S363>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S364>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S365>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S366>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S367>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S368>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S369>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S370>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S371>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S372>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S373>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S374>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S375>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S376>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S377>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S378>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S379>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S380>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S381>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S382>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S383>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S137>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_k = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_e , IO_CAN_CHANNEL_3 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x00B , 0x7FF );
  }

  /* Start for S-Function (ADC_Get_s): '<S304>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (bit_packing_s): '<S139>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S138>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S15>/id_TX'
   *  Constant: '<S15>/id_format_TX'
   *  Constant: '<S15>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (ADC_ChannelInit_s): '<S303>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_l = IO_ADC_ChannelInit( IO_ADC_07 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S58>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S57>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_b = IO_ADC_ChannelInit( IO_ADC_UBAT ,
      IO_ADC_ABSOLUTE , IO_ADC_RANGE_32V , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_POWER_Set_s): '<S278>/IO_POWER_Set_s' */

  /* init_function call IO_POWER_Set */

  /* Start for S-Function (IO_POWER_Set_s): '<S279>/IO_POWER_Set_s' */

  /* init_function call IO_POWER_Set */

  /* Start for S-Function (IO_POWER_Set_s): '<S280>/IO_POWER_Set_s' */

  /* init_function call IO_POWER_Set */

  /* Start for S-Function (IO_POWER_Set_s): '<S281>/IO_POWER_Set_s' */

  /* init_function call IO_POWER_Set */

  /* Start for S-Function (IO_DO_Set_s): '<S309>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant13'
   */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S310>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S49>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S308>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S49>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S306>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S305>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S307>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_c = IO_DO_Init( IO_DO_03 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S276>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant14'
   */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S277>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S38>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S275>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S38>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S273>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S272>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S274>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_p5 = IO_DO_Init( IO_DO_55 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S264>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant15'
   */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S265>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S36>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S263>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S36>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S261>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S260>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S262>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_o = IO_DO_Init( IO_DO_52 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S270>/IO_DO_Set_s' incorporates:
   *  Constant: '<Root>/Constant18'
   */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S271>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S37>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S269>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S37>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_GetVoltage_s): '<S267>/IO_DO_GetVoltage_s' */

  /* init_function call IO_DO_GetVoltage */

  /* Start for S-Function (IO_DO_GetCur_s): '<S266>/IO_DO_GetCur_s' */

  /* init_function call IO_DO_GetCur */

  /* Start for S-Function (IO_DO_Init_s): '<S268>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_c5 = IO_DO_Init( IO_DO_54 , 0 , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S301>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S300>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_i = IO_ADC_ChannelInit( IO_ADC_01 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S331>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S332>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S53>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S330>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S53>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_Init_s): '<S329>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_lc = IO_DO_Init( IO_DO_24 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S335>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S336>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S54>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_ResetProtection_s): '<S334>/IO_DO_ResetProtection_s' */

  /* init_function call IO_DO_ResetProtection */

  /* End of Start for SubSystem: '<S54>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_Init_s): '<S333>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_b = IO_DO_Init( IO_DO_26 , 0 , NULL );
  }

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S181>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_kp = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_d , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x000 , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S183>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S184>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S182>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S155>/id_TX'
   *  Constant: '<S155>/id_format_TX'
   *  Constant: '<S155>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S157>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_b = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_ke , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x192 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S158>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S159>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S185>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_ba = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_cn , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x080 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S186>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S156>/id_TX'
   *  Constant: '<S156>/id_format_TX'
   *  Constant: '<S156>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S173>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_pt = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_o , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x312 , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S175>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S176>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S174>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S153>/id_TX'
   *  Constant: '<S153>/id_format_TX'
   *  Constant: '<S153>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S160>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_n = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_eu , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x292 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S161>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S162>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S163>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S177>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_g2 = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_pn , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_WRITE , IO_CAN_STD_FRAME , 0x412 , 0x7FF );
  }

  /* Start for S-Function (bit_packing_s): '<S179>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (bit_packing_s): '<S180>/bit_packing_s' */

  /* init_function call bit_packing */

  /* Start for S-Function (IO_CAN_WriteMsg_s): '<S178>/IO_CAN_WriteMsg_s' incorporates:
   *  Constant: '<S154>/id_TX'
   *  Constant: '<S154>/id_format_TX'
   *  Constant: '<S154>/length_TX'
   */

  /* init_function call IO_CAN_WriteMsg */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S164>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_kl = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_dp , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x392 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S165>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S166>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S167>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (IO_CAN_ConfigMsg_s): '<S168>/IO_CAN_ConfigMsg_s' */

  /* init_function call IO_CAN_ConfigMsg */
  {
    flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o1_ka = IO_CAN_ConfigMsg
      ( &flashHaileyECUv001_B.IO_CAN_ConfigMsg_s_o2_m , IO_CAN_CHANNEL_4 ,
       IO_CAN_MSG_READ , IO_CAN_STD_FRAME , 0x492 , 0x7FF );
  }

  /* Start for S-Function (IO_CAN_ReadMsg_s): '<S169>/IO_CAN_ReadMsg_s' */

  /* init_function call IO_CAN_ReadMsg */

  /* Start for S-Function (bit_unpacking_s): '<S170>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S171>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (bit_unpacking_s): '<S172>/bit_unpacking_s' */

  /* init_function call bit_unpacking */

  /* Start for S-Function (ADC_Get_s): '<S214>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S213>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_e = IO_ADC_ChannelInit( IO_ADC_08 ,
      IO_ADC_ABSOLUTE , IO_ADC_RANGE_10V , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S207>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S208>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S202>/IO_DO_ResetProtection' */
  fla_IO_DO_ResetProtection_Start(&flashHaileyECUv001_B.IO_DO_ResetProtection_o);

  /* End of Start for SubSystem: '<S202>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_Init_s): '<S205>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_c4 = IO_DO_Init( IO_DO_08 , 0 , NULL );
  }

  /* Start for S-Function (IO_DO_Set_s): '<S211>/IO_DO_Set_s' */

  /* init_function call IO_DO_Set */

  /* Start for S-Function (compare2error_s): '<S212>/compare2error_s' */

  /* init_function call compare2error */

  /* Start for Triggered SubSystem: '<S203>/IO_DO_ResetProtection' */
  fla_IO_DO_ResetProtection_Start(&flashHaileyECUv001_B.IO_DO_ResetProtection_f);

  /* End of Start for SubSystem: '<S203>/IO_DO_ResetProtection' */

  /* Start for S-Function (IO_DO_Init_s): '<S209>/IO_DO_Init_s' */

  /* init_function call IO_DO_Init */
  {
    flashHaileyECUv001_B.IO_DO_Init_s_i = IO_DO_Init( IO_DO_08 , 0 , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S216>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S215>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_m = IO_ADC_ChannelInit( IO_ADC_06 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S218>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S217>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_id = IO_ADC_ChannelInit( IO_ADC_04 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S220>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S219>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_i1 = IO_ADC_ChannelInit( IO_ADC_02 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (ADC_Get_s): '<S222>/ADC_Get_s' */

  /* init_function call ADC_Get */

  /* Start for S-Function (ADC_ChannelInit_s): '<S221>/ADC_ChannelInit_s' */

  /* init_function call ADC_ChannelInit */
  {
    flashHaileyECUv001_B.ADC_ChannelInit_s_lh = IO_ADC_ChannelInit( IO_ADC_00 ,
      IO_ADC_RESISTIVE , IO_ADC_NO_RANGE , IO_ADC_NO_PULL , IO_PIN_NONE , NULL );
  }

  /* Start for S-Function (IO_PWD_ComplexGet_s): '<S296>/IO_PWD_ComplexGet_s' */

  /* init_function call IO_PWD_ComplexGet */

  /* Start for S-Function (PWD_ComplexInit_s): '<S297>/PWD_ComplexInit_s' */

  /* init_function call PWD_ComplexInit */
  {
    flashHaileyECUv001_B.PWD_ComplexInit_s = IO_PWD_ComplexInit( IO_PWD_08 ,
      IO_PWD_PERIOD_TIME , IO_PWD_RISING_VAR , 1 , IO_PWD_PU_10K , NULL );
  }

  /* Start for S-Function (IO_PWD_ComplexGet_s): '<S298>/IO_PWD_ComplexGet_s' */

  /* init_function call IO_PWD_ComplexGet */

  /* Start for S-Function (PWD_ComplexInit_s): '<S299>/PWD_ComplexInit_s' */

  /* init_function call PWD_ComplexInit */
  {
    flashHaileyECUv001_B.PWD_ComplexInit_s_p = IO_PWD_ComplexInit( IO_PWD_10 ,
      IO_PWD_PERIOD_TIME , IO_PWD_RISING_VAR , 1 , IO_PWD_PU_10K , NULL );
  }

  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_a = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_f = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_g = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_Z_k = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_PWM_ResetProtection_Trig_ZCE = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_Z_nn = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_p = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_k = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_j = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_g = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_i = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_n = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_m = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZC_l = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_Trig_ZCE = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_f.IO_DO_ResetProtection_Trig_Z_m3
    = POS_ZCSIG;
  flashHaileyECUv0_PrevZCSigState.IO_DO_ResetProtection_o.IO_DO_ResetProtection_Trig_Z_m3
    = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S386>/Output' */
  flashHaileyECUv001_DWork.Output_DSTATE =
    flashHaileyECUv001_P.Output_InitialCondition;

  /* SystemInitialize for Chart: '<Root>/State_of_the_Cart' */
  flashHaileyECUv001_DWork.is_ok = flashHaileyE_IN_NO_ACTIVE_CHILD;
  flashHaileyECUv001_DWork.is_AMK_start = flashHaileyE_IN_NO_ACTIVE_CHILD;
  flashHaileyECUv001_DWork.temporalCounter_i2 = 0U;
  flashHaileyECUv001_DWork.temporalCounter_i1_b = 0U;
  flashHaileyECUv001_DWork.is_active_c1_flashHaileyECUv001 = 0U;
  flashHaileyECUv001_DWork.is_c1_flashHaileyECUv001 =
    flashHaileyE_IN_NO_ACTIVE_CHILD;
  flashHaileyECUv001_DWork.rtr = false;
  flashHaileyECUv001_DWork.amkkk = false;
  flashHaileyECUv001_B.RTDLED = false;
  flashHaileyECUv001_B.inv_on1 = false;
  flashHaileyECUv001_B.enable1 = false;
  flashHaileyECUv001_B.inv_on2 = false;
  flashHaileyECUv001_B.enable2 = false;
  flashHaileyECUv001_B.MCR = false;
  flashHaileyECUv001_B.DC_on = false;
  flashHaileyECUv001_B.erdel2 = false;
  flashHaileyECUv001_B.erdel1 = false;
  flashHaileyECUv001_B.RTDSGR = false;
  flashHaileyECUv001_B.action = false;
  flashHaileyECUv001_B.staten = 0.0;

  /* SystemInitialize for Chart: '<S47>/action chart' */
  flashHaileyECUv001_DWork.is_active_c2_flashHaileyECUv001 = 0U;
  flashHaileyECUv001_DWork.is_c2_flashHaileyECUv001 =
    flashHaileyE_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  flashHaileyECUv001_DWork.temporalCounter_i1 = 0U;
  flashHaileyECUv001_DWork.is_active_c3_flashHaileyECUv001 = 0U;
  flashHaileyECUv001_DWork.is_c3_flashHaileyECUv001 =
    flashHaileyE_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void flashHaileyECUv001_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
