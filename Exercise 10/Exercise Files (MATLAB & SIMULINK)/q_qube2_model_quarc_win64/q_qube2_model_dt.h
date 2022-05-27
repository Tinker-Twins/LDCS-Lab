/*
 * q_qube2_model_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&q_qube2_model_B.Sum), 0, 0, 5 }
  ,

  { (char_T *)(&q_qube2_model_DW.HILInitialize_FilterFrequency[0]), 0, 0, 2 },

  { (char_T *)(&q_qube2_model_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&q_qube2_model_DW.HILReadEncoderTimebase_Task), 15, 0, 1 },

  { (char_T *)(&q_qube2_model_DW.HILWriteAnalog_PWORK), 11, 0, 3 },

  { (char_T *)(&q_qube2_model_DW.HILInitialize_ClockModes), 6, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&q_qube2_model_P.Jeq), 0, 0, 24 },

  { (char_T *)(&q_qube2_model_P.HILReadEncoderTimebase_clock), 6, 0, 4 },

  { (char_T *)(&q_qube2_model_P.HILInitialize_analog_input_chan), 7, 0, 12 },

  { (char_T *)(&q_qube2_model_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&q_qube2_model_P.SignalGenerator_Amplitude), 0, 0, 9 },

  { (char_T *)(&q_qube2_model_P.HILReadEncoderTimebase_Active), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] q_qube2_model_dt.h */
