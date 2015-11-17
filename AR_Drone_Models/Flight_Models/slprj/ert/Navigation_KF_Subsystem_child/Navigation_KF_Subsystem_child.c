/*
 * File: Navigation_KF_Subsystem_child.c
 *
 * Code generated for Simulink model 'Navigation_KF_Subsystem_child'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:17:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Navigation_KF_Subsystem_child.h"
#include "Navigation_KF_Subsystem_child_private.h"

P_Navigation_KF_Subsystem_chi_T Navigation_KF_Subsystem_child_P = {
  0.0,                                 /* Mask Parameter: NormalizeVector1_maxzero
                                        * Referenced by: '<S27>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */

  /*  Expression: [0 0]'
   * Referenced by: '<S7>/Unit Delay1'
   */
  { 0.0, 0.0 },

  /*  Expression: eye(2)
   * Referenced by: '<S7>/Unit Delay'
   */
  { 1.0, 0.0, 0.0, 1.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain4'
                                        */

  /*  Expression: [0 0]'
   * Referenced by: '<S6>/Unit Delay1'
   */
  { 0.0, 0.0 },

  /*  Expression: eye(2)
   * Referenced by: '<S6>/Unit Delay'
   */
  { 1.0, 0.0, 0.0, 1.0 },
  -57.295779513082323,                 /* Expression: -180/pi
                                        * Referenced by: '<S4>/Gain5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  0.0025,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Change Sign'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S3>/Rad2deg'
                                        */

  /*  Expression: [-1 1 1]
   * Referenced by: '<S20>/Gain1'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [-1 1]
   * Referenced by: '<S20>/Gain2'
   */
  { -1.0, 1.0 },

  /*  Expression: [1 1]
   * Referenced by: '<S20>/Gain3'
   */
  { 1.0, 1.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S1>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S28>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain'
                                        */
  67.0,                                /* Expression: 67
                                        * Referenced by: '<S26>/deg'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S1>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain3'
                                        */

  /*  Expression: eye(2)
   * Referenced by: '<S10>/Unit Delay2'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /*  Expression: [0 0 ]
   * Referenced by: '<S10>/Unit Delay1'
   */
  { 0.0, 0.0 }
};

/* Initial conditions for referenced model: 'Navigation_KF_Subsystem_child' */
void Navigation_KF_Subsystem_ch_Init(DW_Navigation_KF_Subsystem__f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition[0];
  localDW->UnitDelay1_DSTATE[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition[1];

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition[0];
  localDW->UnitDelay_DSTATE[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition[1];
  localDW->UnitDelay_DSTATE[2] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition[2];
  localDW->UnitDelay_DSTATE[3] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition[3];

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE_b[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition_a[0];
  localDW->UnitDelay1_DSTATE_b[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition_a[1];

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  localDW->UnitDelay_DSTATE_m[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition_c[0];
  localDW->UnitDelay_DSTATE_m[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition_c[1];
  localDW->UnitDelay_DSTATE_m[2] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition_c[2];
  localDW->UnitDelay_DSTATE_m[3] =
    Navigation_KF_Subsystem_child_P.UnitDelay_InitialCondition_c[3];

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE_g =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition_f;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay2' */
  localDW->UnitDelay2_DSTATE[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay2_InitialCondition[0];
  localDW->UnitDelay2_DSTATE[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay2_InitialCondition[1];
  localDW->UnitDelay2_DSTATE[2] =
    Navigation_KF_Subsystem_child_P.UnitDelay2_InitialCondition[2];
  localDW->UnitDelay2_DSTATE[3] =
    Navigation_KF_Subsystem_child_P.UnitDelay2_InitialCondition[3];

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE_f[0] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition_d[0];
  localDW->UnitDelay1_DSTATE_f[1] =
    Navigation_KF_Subsystem_child_P.UnitDelay1_InitialCondition_d[1];
}

/* Output and update for referenced model: 'Navigation_KF_Subsystem_child' */
void Navigation_KF_Subsystem_child(const Measurement_Calculation_Bus
  *rtu_IMU_Calculation_Data_Bus, real_T rty_Ultrasound_ctrl[2], real_T
  rty_Euler_Ctrl_deg[3], real_T rty_Gyro_Ctrl_deg[3], real_T rty_Accel_Norm[3],
  real_T rty_VRML_Visuals[9], real_T rty_DCM[9], B_Navigation_KF_Subsystem_c_c_T
  *localB, DW_Navigation_KF_Subsystem__f_T *localDW)
{
  static const real_T Q[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  static const real_T a[4] = { 1.0, 0.0, -0.0025, 1.0 };

  static const real_T Q_0[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  static const real_T a_0[4] = { 1.0, 0.0, -0.0025, 1.0 };

  static const real_T Q_1[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  static const real_T a_1[4] = { 1.0, 0.0, 0.0025, 1.0 };

  int32_T i;
  real_T Kalman_Gain_idx_0;
  real_T Kalman_Gain_idx_1;
  real_T Kalman_Gain_idx_0_0;
  real_T Kalman_Gain_idx_1_0;

  /* SignalConversion: '<Root>/BusConversion_InsertedFor_IMU_Calculation_Data_Bus_at_outport_0' */
  rty_Accel_Norm[0] = rtu_IMU_Calculation_Data_Bus->AccelNorm_Calculation[0];
  rty_Accel_Norm[1] = rtu_IMU_Calculation_Data_Bus->AccelNorm_Calculation[1];
  rty_Accel_Norm[2] = rtu_IMU_Calculation_Data_Bus->AccelNorm_Calculation[2];

  /* SignalConversion: '<Root>/BusConversion_InsertedFor_IMU_Calculation_Data_Bus_at_outport_0' */
  rty_Gyro_Ctrl_deg[0] = rtu_IMU_Calculation_Data_Bus->Gyro_Calculation[0];
  rty_Gyro_Ctrl_deg[1] = rtu_IMU_Calculation_Data_Bus->Gyro_Calculation[1];
  rty_Gyro_Ctrl_deg[2] = rtu_IMU_Calculation_Data_Bus->Gyro_Calculation[2];

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'Kalman Filter/Calculate Roll - Pitch/MATLAB Function': '<S14>:1' */
  /* '<S14>:1:3' */
  /* '<S14>:1:4' */
  /* '<S14>:1:5' */
  /* '<S14>:1:7' */
  /* '<S14>:1:8' */
  localB->Roll = atan(-rty_Accel_Norm[1] / sqrt(-rty_Accel_Norm[0] *
    -rty_Accel_Norm[0] + rty_Accel_Norm[2] * rty_Accel_Norm[2]));
  localB->Pitch = atan(-rty_Accel_Norm[0] / sqrt(-rty_Accel_Norm[1] *
    -rty_Accel_Norm[1] + rty_Accel_Norm[2] * rty_Accel_Norm[2]));

  /* MATLAB Function: '<S7>/Kalman Tracker' incorporates:
   *  Gain: '<S4>/Gain4'
   *  UnitDelay: '<S7>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  /* MATLAB Function 'Kalman Filter/KF_ROLL/Kalman Tracker': '<S23>:1' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /*  pix_value = 5; */
  /* Process Noise */
  /* '<S23>:1:13' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S23>:1:21' */
  localB->rtb_state_correction_i_idx_1 = rty_Gyro_Ctrl_deg[0];
  localB->rtb_state_correction_i_idx_0 = (-0.0025 * localDW->UnitDelay1_DSTATE[1]
    + localDW->UnitDelay1_DSTATE[0]) + 0.0025 *
    localB->rtb_state_correction_i_idx_1;
  localB->rtb_state_correction_i_idx_1 = (0.0 * localDW->UnitDelay1_DSTATE[0] +
    localDW->UnitDelay1_DSTATE[1]) + 0.0 * localB->rtb_state_correction_i_idx_1;

  /* '<S23>:1:22' */
  for (i = 0; i < 2; i++) {
    localB->a[i] = 0.0;
    localB->a[i] += a[i] * localDW->UnitDelay_DSTATE[0];
    localB->a[i] += a[i + 2] * localDW->UnitDelay_DSTATE[1];
    localB->a[i + 2] = 0.0;
    localB->a[i + 2] += a[i] * localDW->UnitDelay_DSTATE[2];
    localB->a[i + 2] += a[i + 2] * localDW->UnitDelay_DSTATE[3];
  }

  for (i = 0; i < 2; i++) {
    localB->covariance_prediction[i] = (localB->a[i + 2] * -0.0025 + localB->a[i])
      + Q[i];
    localB->covariance_prediction[i + 2] = (localB->a[i] * 0.0 + localB->a[i + 2])
      + Q[i + 2];
  }

  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise from accelerometer angle measurement */
  /*      m_var_r = 1; */
  /* '<S23>:1:37' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S23>:1:43' */
  localB->y = 1.0 / (((0.0 * localB->covariance_prediction[3] +
                       localB->covariance_prediction[2]) * 0.0 + (0.0 *
    localB->covariance_prediction[1] + localB->covariance_prediction[0])) + 0.25);
  Kalman_Gain_idx_0 = (localB->covariance_prediction[2] * 0.0 +
                       localB->covariance_prediction[0]) * localB->y;
  Kalman_Gain_idx_1 = (localB->covariance_prediction[3] * 0.0 +
                       localB->covariance_prediction[1]) * localB->y;

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S23>:1:46' */
  localB->Roll = Navigation_KF_Subsystem_child_P.Gain4_Gain * localB->Roll -
    (0.0 * localB->rtb_state_correction_i_idx_1 +
     localB->rtb_state_correction_i_idx_0);

  /* 4x1 vector of states */
  /* compute covariance correction */
  /* '<S23>:1:49' */
  /* 2x2 covariance matrix */
  /*      corrected_angle_measure = state_correction(1) - Ts*state_correction(2); */
  localB->rtb_state_correction_i_idx_0 += Kalman_Gain_idx_0 * localB->Roll;
  localB->rtb_state_correction_i_b = Kalman_Gain_idx_1 * localB->Roll +
    localB->rtb_state_correction_i_idx_1;

  /* MATLAB Function: '<S6>/Kalman Tracker' incorporates:
   *  Gain: '<S4>/Gain5'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  /* MATLAB Function 'Kalman Filter/KF_PITCH/Kalman Tracker': '<S21>:1' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /*  pix_value = 5; */
  /* Process Noise */
  /* '<S21>:1:13' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S21>:1:21' */
  localB->rtb_state_correction_i_idx_1 = rty_Gyro_Ctrl_deg[1];
  localB->rtb_state_correction_c_idx_0 = (-0.0025 * localDW->
    UnitDelay1_DSTATE_b[1] + localDW->UnitDelay1_DSTATE_b[0]) + 0.0025 *
    localB->rtb_state_correction_i_idx_1;
  localB->rtb_state_correction_i_idx_1 = (0.0 * localDW->UnitDelay1_DSTATE_b[0]
    + localDW->UnitDelay1_DSTATE_b[1]) + 0.0 *
    localB->rtb_state_correction_i_idx_1;

  /* '<S21>:1:22' */
  for (i = 0; i < 2; i++) {
    localB->a[i] = 0.0;
    localB->a[i] += a_0[i] * localDW->UnitDelay_DSTATE_m[0];
    localB->a[i] += a_0[i + 2] * localDW->UnitDelay_DSTATE_m[1];
    localB->a[i + 2] = 0.0;
    localB->a[i + 2] += a_0[i] * localDW->UnitDelay_DSTATE_m[2];
    localB->a[i + 2] += a_0[i + 2] * localDW->UnitDelay_DSTATE_m[3];
  }

  for (i = 0; i < 2; i++) {
    localB->covariance_prediction_m[i] = (localB->a[i + 2] * -0.0025 + localB->
      a[i]) + Q_0[i];
    localB->covariance_prediction_m[i + 2] = (localB->a[i] * 0.0 + localB->a[i +
      2]) + Q_0[i + 2];
  }

  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise from accelerometer angle measurement */
  /*      m_var_r = 1; */
  /* '<S21>:1:37' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S21>:1:43' */
  localB->y = 1.0 / (((0.0 * localB->covariance_prediction_m[3] +
                       localB->covariance_prediction_m[2]) * 0.0 + (0.0 *
    localB->covariance_prediction_m[1] + localB->covariance_prediction_m[0])) +
                     1.0);
  Kalman_Gain_idx_0_0 = (localB->covariance_prediction_m[2] * 0.0 +
    localB->covariance_prediction_m[0]) * localB->y;
  Kalman_Gain_idx_1_0 = (localB->covariance_prediction_m[3] * 0.0 +
    localB->covariance_prediction_m[1]) * localB->y;

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S21>:1:46' */
  localB->Roll = Navigation_KF_Subsystem_child_P.Gain5_Gain * localB->Pitch -
    (0.0 * localB->rtb_state_correction_i_idx_1 +
     localB->rtb_state_correction_c_idx_0);

  /* 4x1 vector of states */
  /* compute covariance correction */
  /* '<S21>:1:49' */
  /* 2x2 covariance matrix */
  /*      corrected_angle_measure = state_correction(1) - Ts*state_correction(2); */
  localB->rtb_state_correction_c_idx_0 += Kalman_Gain_idx_0_0 * localB->Roll;
  localB->rtb_state_correction_c_p = Kalman_Gain_idx_1_0 * localB->Roll +
    localB->rtb_state_correction_i_idx_1;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = localDW->UnitDelay1_DSTATE_g;
  }

  /* Gain: '<S3>/Rad2deg' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
   *  Gain: '<S3>/Change Sign'
   */
  localB->Rad2deg[0] = Navigation_KF_Subsystem_child_P.ChangeSign_Gain *
    localB->rtb_state_correction_i_idx_0 *
    Navigation_KF_Subsystem_child_P.Rad2deg_Gain;
  localB->Rad2deg[1] = Navigation_KF_Subsystem_child_P.ChangeSign_Gain *
    localB->rtb_state_correction_c_idx_0 *
    Navigation_KF_Subsystem_child_P.Rad2deg_Gain;
  localB->Rad2deg[2] = Navigation_KF_Subsystem_child_P.ChangeSign_Gain *
    localDW->DiscreteTimeIntegrator1_DSTATE *
    Navigation_KF_Subsystem_child_P.Rad2deg_Gain;

  /* Trigonometry: '<S12>/sincos' */
  localB->Gain2_f[0] = sin(localB->Rad2deg[0]);
  localB->rtb_state_correction_i_idx_1 = cos(localB->Rad2deg[0]);
  localB->Gain2_f[1] = sin(localB->Rad2deg[1]);
  localB->Pitch = cos(localB->Rad2deg[1]);
  localB->Gain2_f[2] = sin(localB->Rad2deg[2]);
  localB->rtb_Gain1_c_idx_2 = cos(localB->Rad2deg[2]);

  /* Fcn: '<S12>/Fcn11' */
  localB->VectorConcatenate_h[0] = localB->Pitch * localB->rtb_Gain1_c_idx_2;

  /* Fcn: '<S12>/Fcn21' */
  localB->VectorConcatenate_h[1] = -localB->Pitch * localB->Gain2_f[2];

  /* Fcn: '<S12>/Fcn31' */
  localB->VectorConcatenate_h[2] = localB->Gain2_f[1];

  /* Fcn: '<S12>/Fcn12' */
  localB->VectorConcatenate_h[3] = localB->Gain2_f[0] * localB->Gain2_f[1] *
    localB->rtb_Gain1_c_idx_2 + localB->rtb_state_correction_i_idx_1 *
    localB->Gain2_f[2];

  /* Fcn: '<S12>/Fcn22' */
  localB->VectorConcatenate_h[4] = -localB->Gain2_f[0] * localB->Gain2_f[1] *
    localB->Gain2_f[2] + localB->rtb_state_correction_i_idx_1 *
    localB->rtb_Gain1_c_idx_2;

  /* Fcn: '<S12>/Fcn32' */
  localB->VectorConcatenate_h[5] = -localB->Gain2_f[0] * localB->Pitch;

  /* Fcn: '<S12>/Fcn13' */
  localB->VectorConcatenate_h[6] = -localB->rtb_state_correction_i_idx_1 *
    localB->Gain2_f[1] * localB->rtb_Gain1_c_idx_2 + localB->Gain2_f[0] *
    localB->Gain2_f[2];

  /* Fcn: '<S12>/Fcn23' */
  localB->VectorConcatenate_h[7] = localB->rtb_state_correction_i_idx_1 *
    localB->Gain2_f[1] * localB->Gain2_f[2] + localB->Gain2_f[0] *
    localB->rtb_Gain1_c_idx_2;

  /* Fcn: '<S12>/Fcn33' */
  localB->VectorConcatenate_h[8] = localB->rtb_state_correction_i_idx_1 *
    localB->Pitch;

  /* Reshape: '<S13>/Reshape (9) to [3x3] column-major' */
  memcpy(&rty_DCM[0], &localB->VectorConcatenate_h[0], 9U * sizeof(real_T));

  /* Selector: '<S20>/Selector1' */
  localB->Gain2_f[0] = rty_DCM[5];
  localB->Gain2_f[1] = rty_DCM[8];
  localB->Gain2_f[2] = rty_DCM[2];

  /* Gain: '<S20>/Gain1' */
  localB->rtb_Gain1_c_idx_2 = Navigation_KF_Subsystem_child_P.Gain1_Gain[2] *
    localB->Gain2_f[2];

  /* Selector: '<S20>/Selector2' */
  localB->rtb_state_correction_i_idx_1 = rty_DCM[1];
  localB->Pitch = rty_DCM[0];

  /* Gain: '<S20>/Gain2' */
  localB->rtb_VectorConcatenate_idx_3 =
    Navigation_KF_Subsystem_child_P.Gain2_Gain[0] *
    localB->rtb_state_correction_i_idx_1;
  localB->rtb_VectorConcatenate_idx_4 =
    Navigation_KF_Subsystem_child_P.Gain2_Gain[1] * localB->Pitch;

  /* Selector: '<S20>/Selector3' */
  localB->rtb_state_correction_i_idx_1 = rty_DCM[7];
  localB->Pitch = rty_DCM[4];

  /* If: '<S16>/If' */
  if ((localB->rtb_Gain1_c_idx_2 >= 1.0) || (localB->rtb_Gain1_c_idx_2 <= -1.0))
  {
    /* Outputs for IfAction SubSystem: '<S16>/AxisRotZeroR3' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Fcn: '<S19>/Fcn1' incorporates:
     *  Gain: '<S20>/Gain3'
     */
    localB->rtb_Merge_idx_0 = rt_atan2d_snf
      (Navigation_KF_Subsystem_child_P.Gain3_Gain[0] *
       localB->rtb_state_correction_i_idx_1,
       Navigation_KF_Subsystem_child_P.Gain3_Gain[1] * localB->Pitch);

    /* Fcn: '<S19>/Fcn2' */
    if (localB->rtb_Gain1_c_idx_2 > 1.0) {
      localB->rtb_Gain1_c_idx_2 = 1.0;
    } else {
      if (localB->rtb_Gain1_c_idx_2 < -1.0) {
        localB->rtb_Gain1_c_idx_2 = -1.0;
      }
    }

    localB->Pitch = asin(localB->rtb_Gain1_c_idx_2);

    /* End of Fcn: '<S19>/Fcn2' */

    /* Fcn: '<S19>/Fcn3' */
    localB->rtb_state_correction_i_idx_1 = 0.0;

    /* End of Outputs for SubSystem: '<S16>/AxisRotZeroR3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S16>/AxisRotDefault' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Fcn: '<S18>/Fcn1' incorporates:
     *  Gain: '<S20>/Gain1'
     */
    localB->rtb_Merge_idx_0 = rt_atan2d_snf
      (Navigation_KF_Subsystem_child_P.Gain1_Gain[0] * localB->Gain2_f[0],
       Navigation_KF_Subsystem_child_P.Gain1_Gain[1] * localB->Gain2_f[1]);

    /* Fcn: '<S18>/Fcn2' */
    localB->Pitch = asin(localB->rtb_Gain1_c_idx_2);

    /* Fcn: '<S18>/Fcn3' */
    localB->rtb_state_correction_i_idx_1 = rt_atan2d_snf
      (localB->rtb_VectorConcatenate_idx_3, localB->rtb_VectorConcatenate_idx_4);

    /* End of Outputs for SubSystem: '<S16>/AxisRotDefault' */
  }

  /* End of If: '<S16>/If' */

  /* Gain: '<S5>/Gain' */
  rty_Euler_Ctrl_deg[0] = Navigation_KF_Subsystem_child_P.Gain_Gain *
    localB->rtb_Merge_idx_0;
  rty_Euler_Ctrl_deg[1] = Navigation_KF_Subsystem_child_P.Gain_Gain *
    localB->Pitch;
  rty_Euler_Ctrl_deg[2] = Navigation_KF_Subsystem_child_P.Gain_Gain *
    localB->rtb_state_correction_i_idx_1;

  /* Math: '<S31>/Math Function' */
  for (i = 0; i < 3; i++) {
    localB->VectorConcatenate_h[3 * i] = rty_DCM[i];
    localB->VectorConcatenate_h[1 + 3 * i] = rty_DCM[i + 3];
    localB->VectorConcatenate_h[2 + 3 * i] = rty_DCM[i + 6];
  }

  /* End of Math: '<S31>/Math Function' */

  /* Gain: '<S28>/Gain' */
  localB->MathFunction1 = Navigation_KF_Subsystem_child_P.Gain_Gain_d *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[2];

  /* Product: '<S26>/Transform MagVector from Body Frame to World Frame' */
  for (i = 0; i < 9; i++) {
    localB->dv0[i] = rty_DCM[i];
  }

  /* SignalConversion: '<S26>/TmpSignal ConversionAtTransform MagVector from Body Frame to World FrameInport2' incorporates:
   *  Gain: '<S28>/Gain1'
   *  Gain: '<S28>/Gain2'
   */
  localB->rtb_state_correction_i_idx_1 =
    Navigation_KF_Subsystem_child_P.Gain1_Gain_l *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[0];
  localB->Pitch = Navigation_KF_Subsystem_child_P.Gain2_Gain_b *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[1];

  /* Product: '<S26>/Transform MagVector from Body Frame to World Frame' incorporates:
   *  SignalConversion: '<S26>/TmpSignal ConversionAtTransform MagVector from Body Frame to World FrameInport2'
   */
  for (i = 0; i < 3; i++) {
    localB->Gain2_f[i] = localB->dv0[i + 6] * localB->MathFunction1 +
      (localB->dv0[i + 3] * localB->Pitch + localB->dv0[i] *
       localB->rtb_state_correction_i_idx_1);
  }

  /* MATLAB Function: '<S26>/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2' incorporates:
   *  Product: '<S26>/Transform compensated magnetic vector into the  body frame'
   */
  /* MATLAB Function 'Kalman Filter/VRML_Calculations/Magnetometer Heading Calculation/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2': '<S30>:1' */
  /* '<S30>:1:3' */
  /* '<S30>:1:4' */
  /* '<S30>:1:6' */
  localB->rtb_Gain2_f_c[0] = localB->Gain2_f[0];
  localB->rtb_Gain2_f_c[1] = localB->Gain2_f[1];
  localB->y = rt_atan2d_snf(localB->Gain2_f[2], fkngnophecjebaai_norm
    (localB->rtb_Gain2_f_c));

  /*  Declination_Angle = declination_ang*pi/180; */
  /* '<S30>:1:11' */
  localB->rot_axis[0] = localB->Gain2_f[1];
  localB->rot_axis[1] = -localB->Gain2_f[0];

  /* find a vector perpindicular to the XY vector, such that we can pitch around it */
  /* '<S30>:1:12' */
  localB->Roll = fkngnophecjebaai_norm(localB->rot_axis);
  localB->rot_axis[0] = localB->Gain2_f[1] / localB->Roll;
  localB->rtb_state_correction_i_idx_1 = -localB->Gain2_f[0] / localB->Roll;

  /* rotate by this amount */
  /*  for i=1:1:45; */
  /*  rot_angle = i*(pi/180) ; */
  /* Define new rotation matrix */
  /* '<S30>:1:18' */
  localB->Pitch = cos(-localB->y);

  /* '<S30>:1:19' */
  localB->Roll = sin(-localB->y);

  /* '<S30>:1:20' */
  /* '<S30>:1:21' */
  /* '<S30>:1:22' */
  /* '<S30>:1:25' */
  /* '<S30>:1:30' */
  localB->dv1[0] = (1.0 - localB->Pitch) * (localB->rot_axis[0] *
    localB->rot_axis[0]) + localB->Pitch;
  localB->dv1[3] = (1.0 - localB->Pitch) * localB->rot_axis[0] *
    localB->rtb_state_correction_i_idx_1 - localB->Roll * 0.0;
  localB->dv1[6] = (1.0 - localB->Pitch) * localB->rot_axis[0] * 0.0 +
    localB->Roll * localB->rtb_state_correction_i_idx_1;
  localB->dv1[1] = (1.0 - localB->Pitch) * localB->rot_axis[0] *
    localB->rtb_state_correction_i_idx_1 + localB->Roll * 0.0;
  localB->dv1[4] = (1.0 - localB->Pitch) * (localB->rtb_state_correction_i_idx_1
    * localB->rtb_state_correction_i_idx_1) + localB->Pitch;
  localB->dv1[7] = (1.0 - localB->Pitch) * localB->rtb_state_correction_i_idx_1 *
    0.0 - localB->Roll * localB->rot_axis[0];
  localB->dv1[2] = (1.0 - localB->Pitch) * localB->rot_axis[0] * 0.0 -
    localB->Roll * localB->rtb_state_correction_i_idx_1;
  localB->dv1[5] = (1.0 - localB->Pitch) * localB->rtb_state_correction_i_idx_1 *
    0.0 + localB->Roll * localB->rot_axis[0];
  localB->dv1[8] = (1.0 - localB->Pitch) * 0.0 + localB->Pitch;
  for (i = 0; i < 3; i++) {
    localB->dv2[i] = localB->dv1[i + 6] * localB->Gain2_f[2] + (localB->dv1[i +
      3] * localB->Gain2_f[1] + localB->dv1[i] * localB->Gain2_f[0]);
  }

  /* End of MATLAB Function: '<S26>/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2' */

  /* Product: '<S26>/Transform compensated magnetic vector into the  body frame' */
  for (i = 0; i < 3; i++) {
    localB->Rad2deg[i] = localB->VectorConcatenate_h[i + 6] * localB->dv2[2] +
      (localB->VectorConcatenate_h[i + 3] * localB->dv2[1] +
       localB->VectorConcatenate_h[i] * localB->dv2[0]);
  }

  /* Sum: '<S27>/Sum of Elements' incorporates:
   *  Math: '<S27>/Math Function'
   */
  localB->MathFunction1 = (localB->Rad2deg[0] * localB->Rad2deg[0] +
    localB->Rad2deg[1] * localB->Rad2deg[1]) + localB->Rad2deg[2] *
    localB->Rad2deg[2];

  /* Math: '<S27>/Math Function1'
   *
   * About '<S27>/Math Function1':
   *  Operator: sqrt
   */
  if (localB->MathFunction1 < 0.0) {
    localB->MathFunction1 = -sqrt(fabs(localB->MathFunction1));
  } else {
    localB->MathFunction1 = sqrt(localB->MathFunction1);
  }

  /* End of Math: '<S27>/Math Function1' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Product: '<S27>/Product'
   */
  if (localB->MathFunction1 >
      Navigation_KF_Subsystem_child_P.NormalizeVector1_maxzero) {
    localB->rtb_Gain1_c_idx_2 = localB->Rad2deg[0];
    localB->rtb_Merge_idx_0 = localB->Rad2deg[1];
    localB->Pitch = localB->Rad2deg[2];
  } else {
    localB->rtb_Gain1_c_idx_2 = localB->Rad2deg[0] * 0.0;
    localB->rtb_Merge_idx_0 = localB->Rad2deg[1] * 0.0;
    localB->Pitch = localB->Rad2deg[2] * 0.0;
    localB->MathFunction1 = Navigation_KF_Subsystem_child_P.Constant_Value;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Gain: '<S1>/Gain3' */
  localB->Gain2_f[0] = Navigation_KF_Subsystem_child_P.Gain3_Gain_n *
    rty_Accel_Norm[0];
  localB->Gain2_f[1] = Navigation_KF_Subsystem_child_P.Gain3_Gain_n *
    rty_Accel_Norm[1];
  localB->Gain2_f[2] = Navigation_KF_Subsystem_child_P.Gain3_Gain_n *
    rty_Accel_Norm[2];

  /* MATLAB Function: '<S10>/Kalman Tracker' incorporates:
   *  SignalConversion: '<Root>/BusConversion_InsertedFor_IMU_Calculation_Data_Bus_at_outport_0'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  /* MATLAB Function 'Kalman Filter/Re-Align Yaw Axis': '<S8>:1' */
  /* MotorArmed = 1 in this state */
  /* '<S8>:1:11' */
  /* MATLAB Function 'Kalman Filter/Ultrasound Estimator/Kalman Tracker': '<S25>:1' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /* our states: */
  /*   [Wx Wy Wz Bx By Bz   ] */
  /*  */
  /* Process Noise */
  /* '<S25>:1:18' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S25>:1:26' */
  localB->rtb_VectorConcatenate_idx_3 = 0.0 * localDW->UnitDelay1_DSTATE_f[0] +
    localDW->UnitDelay1_DSTATE_f[1];

  /* '<S25>:1:27' */
  for (i = 0; i < 2; i++) {
    localB->a[i] = 0.0;
    localB->a[i] += a_1[i] * localDW->UnitDelay2_DSTATE[0];
    localB->a[i] += a_1[i + 2] * localDW->UnitDelay2_DSTATE[1];
    localB->a[i + 2] = 0.0;
    localB->a[i + 2] += a_1[i] * localDW->UnitDelay2_DSTATE[2];
    localB->a[i + 2] += a_1[i + 2] * localDW->UnitDelay2_DSTATE[3];
  }

  for (i = 0; i < 2; i++) {
    localB->covariance_prediction_[i] = (localB->a[i + 2] * 0.0025 + localB->a[i])
      + Q_1[i];
    localB->covariance_prediction_[i + 2] = (localB->a[i] * 0.0 + localB->a[i +
      2]) + Q_1[i + 2];
  }

  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise */
  /*      m_var_r = 1; */
  /* '<S25>:1:41' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S25>:1:47' */
  localB->y = 1.0 / (((0.0 * localB->covariance_prediction_[3] +
                       localB->covariance_prediction_[2]) * 0.0 + (0.0 *
    localB->covariance_prediction_[1] + localB->covariance_prediction_[0])) +
                     1.0);
  localB->rtb_VectorConcatenate_idx_4 = (localB->covariance_prediction_[2] * 0.0
    + localB->covariance_prediction_[0]) * localB->y;
  localB->rtb_state_correction_i_idx_1 = (localB->covariance_prediction_[3] *
    0.0 + localB->covariance_prediction_[1]) * localB->y;

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S25>:1:50' */
  localB->Roll = rtu_IMU_Calculation_Data_Bus->UltraSound_Calculation - ((0.0025
    * localDW->UnitDelay1_DSTATE_f[1] + localDW->UnitDelay1_DSTATE_f[0]) + 0.0 *
    localB->rtb_VectorConcatenate_idx_3);

  /* SignalConversion: '<Root>/TmpSignal ConversionAtUltrasound_ctrlInport1' incorporates:
   *  SignalConversion: '<Root>/BusConversion_InsertedFor_IMU_Calculation_Data_Bus_at_outport_0'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  /* 2x1 vector of states */
  /* compute covariance correction */
  /* '<S25>:1:53' */
  /* 2x2 covariance matrix */
  rty_Ultrasound_ctrl[0] = rtu_IMU_Calculation_Data_Bus->UltraSound_Calculation;
  rty_Ultrasound_ctrl[1] = localDW->UnitDelay1_DSTATE_f[1];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtVRML_VisualsInport1' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Product: '<S27>/Divide'
   */
  rty_VRML_Visuals[0] = localB->Gain2_f[0];
  rty_VRML_Visuals[1] = localB->Gain2_f[1];
  rty_VRML_Visuals[2] = localB->Gain2_f[2];
  rty_VRML_Visuals[3] = localB->rtb_Gain1_c_idx_2 / localB->MathFunction1 *
    Navigation_KF_Subsystem_child_P.Gain2_Gain_n;
  rty_VRML_Visuals[4] = localB->rtb_Merge_idx_0 / localB->MathFunction1 *
    Navigation_KF_Subsystem_child_P.Gain2_Gain_n;
  rty_VRML_Visuals[5] = localB->Pitch / localB->MathFunction1 *
    Navigation_KF_Subsystem_child_P.Gain2_Gain_n;
  rty_VRML_Visuals[6] = Navigation_KF_Subsystem_child_P.Gain1_Gain_f *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[0];
  rty_VRML_Visuals[7] = Navigation_KF_Subsystem_child_P.Gain1_Gain_f *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[1];
  rty_VRML_Visuals[8] = Navigation_KF_Subsystem_child_P.Gain1_Gain_f *
    rtu_IMU_Calculation_Data_Bus->Magnetometer_Calculation[2];

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE[0] = localB->rtb_state_correction_i_idx_0;
  localDW->UnitDelay1_DSTATE[1] = localB->rtb_state_correction_i_b;

  /* MATLAB Function: '<S7>/Kalman Tracker' */
  localB->I[0] = 1.0 - Kalman_Gain_idx_0;
  localB->I[2] = 0.0 - Kalman_Gain_idx_0 * 0.0;
  localB->I[1] = 0.0 - Kalman_Gain_idx_1;
  localB->I[3] = 1.0 - Kalman_Gain_idx_1 * 0.0;

  /* Update for UnitDelay: '<S7>/Unit Delay' incorporates:
   *  MATLAB Function: '<S7>/Kalman Tracker'
   */
  for (i = 0; i < 2; i++) {
    localDW->UnitDelay_DSTATE[i] = 0.0;
    localDW->UnitDelay_DSTATE[i] += localB->I[i] * localB->
      covariance_prediction[0];
    localDW->UnitDelay_DSTATE[i] += localB->I[i + 2] *
      localB->covariance_prediction[1];
    localDW->UnitDelay_DSTATE[i + 2] = 0.0;
    localDW->UnitDelay_DSTATE[i + 2] += localB->I[i] *
      localB->covariance_prediction[2];
    localDW->UnitDelay_DSTATE[i + 2] += localB->I[i + 2] *
      localB->covariance_prediction[3];
  }

  /* End of Update for UnitDelay: '<S7>/Unit Delay' */

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE_b[0] = localB->rtb_state_correction_c_idx_0;
  localDW->UnitDelay1_DSTATE_b[1] = localB->rtb_state_correction_c_p;

  /* MATLAB Function: '<S6>/Kalman Tracker' */
  localB->I_c[0] = 1.0 - Kalman_Gain_idx_0_0;
  localB->I_c[2] = 0.0 - Kalman_Gain_idx_0_0 * 0.0;
  localB->I_c[1] = 0.0 - Kalman_Gain_idx_1_0;
  localB->I_c[3] = 1.0 - Kalman_Gain_idx_1_0 * 0.0;

  /* Update for UnitDelay: '<S6>/Unit Delay' incorporates:
   *  MATLAB Function: '<S6>/Kalman Tracker'
   */
  for (i = 0; i < 2; i++) {
    localDW->UnitDelay_DSTATE_m[i] = 0.0;
    localDW->UnitDelay_DSTATE_m[i] += localB->I_c[i] *
      localB->covariance_prediction_m[0];
    localDW->UnitDelay_DSTATE_m[i] += localB->I_c[i + 2] *
      localB->covariance_prediction_m[1];
    localDW->UnitDelay_DSTATE_m[i + 2] = 0.0;
    localDW->UnitDelay_DSTATE_m[i + 2] += localB->I_c[i] *
      localB->covariance_prediction_m[2];
    localDW->UnitDelay_DSTATE_m[i + 2] += localB->I_c[i + 2] *
      localB->covariance_prediction_m[3];
  }

  /* End of Update for UnitDelay: '<S6>/Unit Delay' */

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  MATLAB Function: '<S1>/Re-Align Yaw Axis'
   */
  localDW->UnitDelay1_DSTATE_g = 0.0;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE +=
    Navigation_KF_Subsystem_child_P.DiscreteTimeIntegrator1_gainval *
    rty_Gyro_Ctrl_deg[2];

  /* MATLAB Function: '<S10>/Kalman Tracker' */
  localB->I_k[0] = 1.0 - localB->rtb_VectorConcatenate_idx_4;
  localB->I_k[2] = 0.0 - localB->rtb_VectorConcatenate_idx_4 * 0.0;
  localB->I_k[1] = 0.0 - localB->rtb_state_correction_i_idx_1;
  localB->I_k[3] = 1.0 - localB->rtb_state_correction_i_idx_1 * 0.0;

  /* Update for UnitDelay: '<S10>/Unit Delay2' incorporates:
   *  MATLAB Function: '<S10>/Kalman Tracker'
   */
  for (i = 0; i < 2; i++) {
    localDW->UnitDelay2_DSTATE[i] = 0.0;
    localDW->UnitDelay2_DSTATE[i] += localB->I_k[i] *
      localB->covariance_prediction_[0];
    localDW->UnitDelay2_DSTATE[i] += localB->I_k[i + 2] *
      localB->covariance_prediction_[1];
    localDW->UnitDelay2_DSTATE[i + 2] = 0.0;
    localDW->UnitDelay2_DSTATE[i + 2] += localB->I_k[i] *
      localB->covariance_prediction_[2];
    localDW->UnitDelay2_DSTATE[i + 2] += localB->I_k[i + 2] *
      localB->covariance_prediction_[3];
  }

  /* End of Update for UnitDelay: '<S10>/Unit Delay2' */

  /* Update for UnitDelay: '<S10>/Unit Delay1' incorporates:
   *  MATLAB Function: '<S10>/Kalman Tracker'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE_f[0] = (0.0025 * localDW->UnitDelay1_DSTATE_f[1] +
    localDW->UnitDelay1_DSTATE_f[0]) + localB->rtb_VectorConcatenate_idx_4 *
    localB->Roll;
  localDW->UnitDelay1_DSTATE_f[1] = localB->rtb_state_correction_i_idx_1 *
    localB->Roll + localB->rtb_VectorConcatenate_idx_3;
}

/* Model initialize function */
void Navigation_KF_Subsys_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Navigation_KF_Subsys_T *const Navigation_KF_Subsystem_chil_M,
  DW_Navigation_KF_Subsystem__f_T *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(Navigation_KF_Subsystem_chil_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_Navigation_KF_Subsystem__f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
