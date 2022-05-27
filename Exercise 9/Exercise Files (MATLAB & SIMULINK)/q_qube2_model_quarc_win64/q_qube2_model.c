/*
 * q_qube2_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_qube2_model".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Feb 21 15:18:17 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_qube2_model.h"
#include "q_qube2_model_private.h"
#include "q_qube2_model_dt.h"

/* Block signals (auto storage) */
B_q_qube2_model_T q_qube2_model_B;

/* Continuous states */
X_q_qube2_model_T q_qube2_model_X;

/* Block states (auto storage) */
DW_q_qube2_model_T q_qube2_model_DW;

/* Real-time model */
RT_MODEL_q_qube2_model_T q_qube2_model_M_;
RT_MODEL_q_qube2_model_T *const q_qube2_model_M = &q_qube2_model_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_qube2_model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void q_qube2_model_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase;
  real_T temp;
  if (rtmIsMajorTimeStep(q_qube2_model_M)) {
    /* set solver stop time */
    if (!(q_qube2_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_qube2_model_M->solverInfo,
                            ((q_qube2_model_M->Timing.clockTickH0 + 1) *
        q_qube2_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_qube2_model_M->solverInfo,
                            ((q_qube2_model_M->Timing.clockTick0 + 1) *
        q_qube2_model_M->Timing.stepSize0 + q_qube2_model_M->Timing.clockTickH0 *
        q_qube2_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_qube2_model_M)) {
    q_qube2_model_M->Timing.t[0] = rtsiGetT(&q_qube2_model_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_qube2_model_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_qube2_model/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_qube2_model_DW.HILReadEncoderTimebase_Task, 1,
         &q_qube2_model_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase =
          q_qube2_model_DW.HILReadEncoderTimebase_Buffer;
      }
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = q_qube2_model_P.SignalGenerator_Frequency * q_qube2_model_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = q_qube2_model_P.SignalGenerator_Amplitude;
  } else {
    temp = -q_qube2_model_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  q_qube2_model_B.Sum = q_qube2_model_P.Gain_Gain * temp +
    q_qube2_model_P.Constant_Value;
  if (rtmIsMajorTimeStep(q_qube2_model_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: q_qube2_model/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_qube2_model_DW.HILInitialize_Card,
        &q_qube2_model_P.HILWriteAnalog_channels, 1, &q_qube2_model_B.Sum);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
      }
    }

    /* Gain: '<Root>/counts to rad' */
    q_qube2_model_B.countstorad = q_qube2_model_P.countstorad_Gain *
      rtb_HILReadEncoderTimebase;
  }

  /* TransferFcn: '<Root>/QUBE-Servo Hardware' */
  q_qube2_model_B.QUBEServoHardware = 0.0;
  q_qube2_model_B.QUBEServoHardware += q_qube2_model_P.QUBEServoHardware_C *
    q_qube2_model_X.QUBEServoHardware_CSTATE;
  q_qube2_model_B.QUBEServoHardware += q_qube2_model_P.QUBEServoHardware_D *
    q_qube2_model_B.countstorad;

  /* Integrator: '<S1>/theta_dot' */
  q_qube2_model_B.theta_dot = q_qube2_model_X.theta_dot_CSTATE;
  if (rtmIsMajorTimeStep(q_qube2_model_M)) {
  }

  /* Gain: '<S1>/Inertia' incorporates:
   *  Gain: '<S1>/Back EMF'
   *  Gain: '<S1>/Torque Constant'
   *  Gain: '<S1>/Voltage to  Current'
   *  Sum: '<S1>/Sum'
   */
  q_qube2_model_B.Inertia = (q_qube2_model_B.Sum - q_qube2_model_P.km *
    q_qube2_model_B.theta_dot) * (1.0 / q_qube2_model_P.Rm) * q_qube2_model_P.kt
    * (1.0 / q_qube2_model_P.Jeq);
}

/* Model update function */
void q_qube2_model_update(void)
{
  if (rtmIsMajorTimeStep(q_qube2_model_M)) {
    rt_ertODEUpdateContinuousStates(&q_qube2_model_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++q_qube2_model_M->Timing.clockTick0)) {
    ++q_qube2_model_M->Timing.clockTickH0;
  }

  q_qube2_model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_qube2_model_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_qube2_model_M->Timing.clockTick1)) {
      ++q_qube2_model_M->Timing.clockTickH1;
    }

    q_qube2_model_M->Timing.t[1] = q_qube2_model_M->Timing.clockTick1 *
      q_qube2_model_M->Timing.stepSize1 + q_qube2_model_M->Timing.clockTickH1 *
      q_qube2_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_qube2_model_derivatives(void)
{
  XDot_q_qube2_model_T *_rtXdot;
  _rtXdot = ((XDot_q_qube2_model_T *) q_qube2_model_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/QUBE-Servo Hardware' */
  _rtXdot->QUBEServoHardware_CSTATE = 0.0;
  _rtXdot->QUBEServoHardware_CSTATE += q_qube2_model_P.QUBEServoHardware_A *
    q_qube2_model_X.QUBEServoHardware_CSTATE;
  _rtXdot->QUBEServoHardware_CSTATE += q_qube2_model_B.countstorad;

  /* Derivatives for Integrator: '<S1>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = q_qube2_model_B.Inertia;
}

/* Model initialize function */
void q_qube2_model_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube2_model/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &q_qube2_model_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(q_qube2_model_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
      return;
    }

    if ((q_qube2_model_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_analog_inpu_j && is_switching)) {
      result = hil_set_analog_input_ranges(q_qube2_model_DW.HILInitialize_Card,
        &q_qube2_model_P.HILInitialize_analog_input_chan, 1U,
        &q_qube2_model_P.HILInitialize_analog_input_mini,
        &q_qube2_model_P.HILInitialize_analog_input_maxi);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_model_P.HILInitialize_set_analog_output && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_analog_outp_j && is_switching)) {
      result = hil_set_analog_output_ranges(q_qube2_model_DW.HILInitialize_Card,
        &q_qube2_model_P.HILInitialize_analog_output_cha, 1U,
        &q_qube2_model_P.HILInitialize_analog_output_min,
        &q_qube2_model_P.HILInitialize_analog_output_max);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_model_P.HILInitialize_set_analog_outp_c && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_analog_outp_b && is_switching)) {
      result = hil_write_analog(q_qube2_model_DW.HILInitialize_Card,
        &q_qube2_model_P.HILInitialize_analog_output_cha, 1U,
        &q_qube2_model_P.HILInitialize_initial_analog_ou);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_model_P.HILInitialize_set_analog_outp_i) {
      result = hil_watchdog_set_analog_expiration_state
        (q_qube2_model_DW.HILInitialize_Card,
         &q_qube2_model_P.HILInitialize_analog_output_cha, 1U,
         &q_qube2_model_P.HILInitialize_watchdog_analog_o);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(q_qube2_model_DW.HILInitialize_Card,
      NULL, 0U, &q_qube2_model_P.HILInitialize_digital_output_ch, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
      return;
    }

    if ((q_qube2_model_P.HILInitialize_set_digital_out_j && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_digital_out_e && is_switching)) {
      result = hil_write_digital(q_qube2_model_DW.HILInitialize_Card,
        &q_qube2_model_P.HILInitialize_digital_output_ch, 1U, (t_boolean *)
        &q_qube2_model_P.HILInitialize_initial_digital_o);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_model_P.HILInitialize_set_digital_out_a) {
      result = hil_watchdog_set_digital_expiration_state
        (q_qube2_model_DW.HILInitialize_Card,
         &q_qube2_model_P.HILInitialize_digital_output_ch, 1U, (const
          t_digital_state *) &q_qube2_model_P.HILInitialize_watchdog_digital_);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_model_P.HILInitialize_set_encoder_param && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_encoder_par_m && is_switching)) {
      q_qube2_model_DW.HILInitialize_QuadratureModes[0] =
        q_qube2_model_P.HILInitialize_quadrature;
      q_qube2_model_DW.HILInitialize_QuadratureModes[1] =
        q_qube2_model_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (q_qube2_model_DW.HILInitialize_Card,
         q_qube2_model_P.HILInitialize_encoder_channels, 2U,
         (t_encoder_quadrature_mode *)
         &q_qube2_model_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_model_P.HILInitialize_set_encoder_count && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_encoder_cou_h && is_switching)) {
      q_qube2_model_DW.HILInitialize_InitialEICounts[0] =
        q_qube2_model_P.HILInitialize_initial_encoder_c;
      q_qube2_model_DW.HILInitialize_InitialEICounts[1] =
        q_qube2_model_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(q_qube2_model_DW.HILInitialize_Card,
        q_qube2_model_P.HILInitialize_encoder_channels, 2U,
        &q_qube2_model_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_model_P.HILInitialize_set_other_outputs && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_other_outpu_a && is_switching)) {
      result = hil_write_other(q_qube2_model_DW.HILInitialize_Card,
        q_qube2_model_P.HILInitialize_other_output_chan, 3U,
        q_qube2_model_P.HILInitialize_initial_other_out);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_model_P.HILInitialize_set_other_outpu_i) {
      result = hil_watchdog_set_other_expiration_state
        (q_qube2_model_DW.HILInitialize_Card,
         q_qube2_model_P.HILInitialize_other_output_chan, 3U,
         q_qube2_model_P.HILInitialize_watchdog_other_ou);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_qube2_model/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(q_qube2_model_DW.HILInitialize_Card,
      q_qube2_model_P.HILReadEncoderTimebase_samples_,
      &q_qube2_model_P.HILReadEncoderTimebase_channels, 1,
      &q_qube2_model_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/QUBE-Servo Hardware' */
  q_qube2_model_X.QUBEServoHardware_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/theta_dot' */
  q_qube2_model_X.theta_dot_CSTATE = q_qube2_model_P.theta_dot_IC;
}

/* Model terminate function */
void q_qube2_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube2_model/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(q_qube2_model_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_qube2_model_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_qube2_model_P.HILInitialize_set_analog_out_py && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_analog_outp_p && is_switching)) {
      num_final_analog_outputs = 1U;
    }

    if ((q_qube2_model_P.HILInitialize_set_digital_out_p && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_digital_ou_il && is_switching)) {
      num_final_digital_outputs = 1U;
    }

    if ((q_qube2_model_P.HILInitialize_set_other_outpu_l && !is_switching) ||
        (q_qube2_model_P.HILInitialize_set_other_outpu_c && is_switching)) {
      num_final_other_outputs = 3U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(q_qube2_model_DW.HILInitialize_Card
                         , &q_qube2_model_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , NULL, 0
                         , &q_qube2_model_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         , q_qube2_model_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , &q_qube2_model_P.HILInitialize_final_analog_outp
                         , NULL
                         , (t_boolean *)
                         &q_qube2_model_P.HILInitialize_final_digital_out
                         , q_qube2_model_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(q_qube2_model_DW.HILInitialize_Card,
            &q_qube2_model_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &q_qube2_model_P.HILInitialize_final_analog_outp);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(q_qube2_model_DW.HILInitialize_Card,
            &q_qube2_model_P.HILInitialize_digital_output_ch,
            num_final_digital_outputs, (t_boolean *)
            &q_qube2_model_P.HILInitialize_final_digital_out);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(q_qube2_model_DW.HILInitialize_Card,
            q_qube2_model_P.HILInitialize_other_output_chan,
            num_final_other_outputs,
            q_qube2_model_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_qube2_model_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_qube2_model_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_qube2_model_DW.HILInitialize_Card);
    hil_close(q_qube2_model_DW.HILInitialize_Card);
    q_qube2_model_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  q_qube2_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_qube2_model_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  q_qube2_model_initialize();
}

void MdlTerminate(void)
{
  q_qube2_model_terminate();
}

/* Registration function */
RT_MODEL_q_qube2_model_T *q_qube2_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_qube2_model_M, 0,
                sizeof(RT_MODEL_q_qube2_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_qube2_model_M->solverInfo,
                          &q_qube2_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_qube2_model_M->solverInfo, &rtmGetTPtr(q_qube2_model_M));
    rtsiSetStepSizePtr(&q_qube2_model_M->solverInfo,
                       &q_qube2_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_qube2_model_M->solverInfo,
                 &q_qube2_model_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_qube2_model_M->solverInfo, (real_T **)
                         &q_qube2_model_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_qube2_model_M->solverInfo,
      &q_qube2_model_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&q_qube2_model_M->solverInfo, (&rtmGetErrorStatus
      (q_qube2_model_M)));
    rtsiSetRTModelPtr(&q_qube2_model_M->solverInfo, q_qube2_model_M);
  }

  rtsiSetSimTimeStep(&q_qube2_model_M->solverInfo, MAJOR_TIME_STEP);
  q_qube2_model_M->ModelData.intgData.f[0] = q_qube2_model_M->ModelData.odeF[0];
  q_qube2_model_M->ModelData.contStates = ((real_T *) &q_qube2_model_X);
  rtsiSetSolverData(&q_qube2_model_M->solverInfo, (void *)
                    &q_qube2_model_M->ModelData.intgData);
  rtsiSetSolverName(&q_qube2_model_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_qube2_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    q_qube2_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_qube2_model_M->Timing.sampleTimes =
      (&q_qube2_model_M->Timing.sampleTimesArray[0]);
    q_qube2_model_M->Timing.offsetTimes =
      (&q_qube2_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_qube2_model_M->Timing.sampleTimes[0] = (0.0);
    q_qube2_model_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_qube2_model_M->Timing.offsetTimes[0] = (0.0);
    q_qube2_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_qube2_model_M, &q_qube2_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_qube2_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_qube2_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_qube2_model_M, -1);
  q_qube2_model_M->Timing.stepSize0 = 0.002;
  q_qube2_model_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_qube2_model_M->Sizes.checksums[0] = (2042064729U);
  q_qube2_model_M->Sizes.checksums[1] = (3290556664U);
  q_qube2_model_M->Sizes.checksums[2] = (1403699113U);
  q_qube2_model_M->Sizes.checksums[3] = (3226941293U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    q_qube2_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_qube2_model_M->extModeInfo,
      &q_qube2_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_qube2_model_M->extModeInfo,
                        q_qube2_model_M->Sizes.checksums);
    rteiSetTPtr(q_qube2_model_M->extModeInfo, rtmGetTPtr(q_qube2_model_M));
  }

  q_qube2_model_M->solverInfoPtr = (&q_qube2_model_M->solverInfo);
  q_qube2_model_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_qube2_model_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_qube2_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_qube2_model_M->ModelData.blockIO = ((void *) &q_qube2_model_B);
  (void) memset(((void *) &q_qube2_model_B), 0,
                sizeof(B_q_qube2_model_T));

  /* parameters */
  q_qube2_model_M->ModelData.defaultParam = ((real_T *)&q_qube2_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_qube2_model_X;
    q_qube2_model_M->ModelData.contStates = (x);
    (void) memset((void *)&q_qube2_model_X, 0,
                  sizeof(X_q_qube2_model_T));
  }

  /* states (dwork) */
  q_qube2_model_M->ModelData.dwork = ((void *) &q_qube2_model_DW);
  (void) memset((void *)&q_qube2_model_DW, 0,
                sizeof(DW_q_qube2_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_qube2_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_qube2_model_M->Sizes.numContStates = (2);/* Number of continuous states */
  q_qube2_model_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  q_qube2_model_M->Sizes.numY = (0);   /* Number of model outputs */
  q_qube2_model_M->Sizes.numU = (0);   /* Number of model inputs */
  q_qube2_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_qube2_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_qube2_model_M->Sizes.numBlocks = (17);/* Number of blocks */
  q_qube2_model_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  q_qube2_model_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return q_qube2_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
