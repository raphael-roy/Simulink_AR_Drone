/*
 * File: AR_Drone_Flight_Control.c
 *
 * Code generated for Simulink model 'AR_Drone_Flight_Control'.
 *
 * Model version                  : 1.1216
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:18:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AR_Drone_Flight_Control.h"
#include "AR_Drone_Flight_Control_private.h"
#include "AR_Drone_Flight_Control_dt.h"

/* Named constants for Chart: '<S81>/Chart' */
#define AR_Drone_Fli_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AR_Drone_Flight_Co_CALL_EVENT_l (-1)
#define AR_Drone_Flight_Co_IN_End_State ((uint8_T)3U)
#define AR_Drone_Flight_IN_Begin_State0 ((uint8_T)2U)
#define AR_Drone_Flight__IN_Begin_State ((uint8_T)1U)

/* Named constants for Chart: '<S4>/Supervisory Flight Controller' */
#define AR_Dro_IN_Auto_Calibration_Done ((uint8_T)2U)
#define AR_Dro_IN_EvaluateGravityVector ((uint8_T)2U)
#define AR_Dron_IN_EvaluateVoltageLevel ((uint8_T)2U)
#define AR_Drone_F_IN_NO_ACTIVE_CHILD_b ((uint8_T)0U)
#define AR_Drone_Fli_IN_Wait_For_Flight ((uint8_T)4U)
#define AR_Drone_Flig_IN_Altitude_Climb ((uint8_T)1U)
#define AR_Drone_Flight_C_IN_Initialize ((uint8_T)2U)
#define AR_Drone_Flight_Co_CALL_EVENT_j (-1)
#define AR_Drone_Flight_Cont_IN_Nominal ((uint8_T)3U)
#define AR_Drone_Flight_IN_Climb_down_1 ((uint8_T)1U)
#define AR_Drone_Flight_IN_Climb_down_2 ((uint8_T)2U)
#define AR_Drone_Flight_IN_Climb_down_3 ((uint8_T)3U)
#define AR_Drone_Flight_IN_ForceLanding ((uint8_T)1U)
#define AR_Drone_Flight__IN_ChangeState ((uint8_T)1U)
#define AR_IN_Attitude_Convergence_Wait ((uint8_T)1U)
#define AR_IN_Calculate_Attitude_Offset ((uint8_T)3U)

/* Exported block parameters */
struct_J3crjymWSwWCQ8kQITIpr Accelerometer_360deg_calibration = {
  { -0.9954, -1.0068, -1.0323 },

  { -0.0056, 0.0633, 0.0367 }
} ;                                    /* Variable: Accelerometer_360deg_calibration
                                        * Referenced by:
                                        *   '<S112>/Accel_Calib_Gain'
                                        *   '<S112>/Accel_Calib_Offset'
                                        */

struct_J3crjymWSwWCQ8kQITIpr Magnetometer_calibration = {
  { 0.0, 0.0, 0.00971 },

  { -0.702, 0.7059, -0.1563 }
} ;                                    /* Variable: Magnetometer_calibration
                                        * Referenced by:
                                        *   '<S118>/Constant'
                                        *   '<S118>/Constant1'
                                        */

/* Block signals (auto storage) */
B_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_B;

/* Block states (auto storage) */
DW_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_DW;

/* Real-time model */
RT_MODEL_AR_Drone_Flight_Cont_T AR_Drone_Flight_Control_M_;
RT_MODEL_AR_Drone_Flight_Cont_T *const AR_Drone_Flight_Control_M =
  &AR_Drone_Flight_Control_M_;

/* Forward declaration for local functions */
static void AR_Dro_Accel_Offset_Calculation(const real_T OffsetMeasure[3],
  real_T Reset, real_T Y[3]);
static void AR_Dron_Gyro_Offset_Calculation(const real_T OffsetMeasure[3],
  real_T Reset, real_T Y[3]);
static void AR_D_Accel_Offset_Calculation_f(const real_T OffsetMeasure[3],
  real_T Reset);
static void AR_Dr_Gyro_Offset_Calculation_c(const real_T OffsetMeasure[3],
  real_T Reset);
static void AR_Drone_Flight_Con_Drone_State(void);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void AR_Drone_Flight_Control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(AR_Drone_Flight_Control_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(AR_Drone_Flight_Control_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  AR_Drone_Flight_Control_M->Timing.RateInteraction.TID0_1 =
    (AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[1] == 0);
  AR_Drone_Flight_Control_M->Timing.RateInteraction.TID0_2 =
    (AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[1])++;
  if ((AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.005s, 0.0s] */
    AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[1] = 0;
  }

  (AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[2])++;
  if ((AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.02s, 0.0s] */
    AR_Drone_Flight_Control_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S10>/AxisRotZeroR3'
 *    '<S122>/AxisRotZeroR3'
 */
void AR_Drone_Flig_AxisRotZeroR3(const real_T rtu_In1[7], real_T *rty_1, real_T *
  rty_2, real_T *rty_3)
{
  real_T rtu_In1_0;

  /* Fcn: '<S21>/Fcn1' */
  *rty_1 = rt_atan2d_snf(rtu_In1[5], rtu_In1[6]);

  /* Fcn: '<S21>/Fcn2' */
  if (rtu_In1[2] > 1.0) {
    rtu_In1_0 = 1.0;
  } else if (rtu_In1[2] < -1.0) {
    rtu_In1_0 = -1.0;
  } else {
    rtu_In1_0 = rtu_In1[2];
  }

  *rty_2 = asin(rtu_In1_0);

  /* End of Fcn: '<S21>/Fcn2' */

  /* Fcn: '<S21>/Fcn3' */
  *rty_3 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S10>/AxisRotDefault'
 *    '<S122>/AxisRotDefault'
 */
void AR_Drone_Fli_AxisRotDefault(const real_T rtu_In1[7], real_T *rty_1, real_T *
  rty_2, real_T *rty_3)
{
  real_T rtu_In1_0;

  /* Fcn: '<S20>/Fcn1' */
  *rty_1 = rt_atan2d_snf(rtu_In1[0], rtu_In1[1]);

  /* Fcn: '<S20>/Fcn2' */
  if (rtu_In1[2] > 1.0) {
    rtu_In1_0 = 1.0;
  } else if (rtu_In1[2] < -1.0) {
    rtu_In1_0 = -1.0;
  } else {
    rtu_In1_0 = rtu_In1[2];
  }

  *rty_2 = asin(rtu_In1_0);

  /* End of Fcn: '<S20>/Fcn2' */

  /* Fcn: '<S20>/Fcn3' */
  *rty_3 = rt_atan2d_snf(rtu_In1[3], rtu_In1[4]);
}

/*
 * Output and update for atomic system:
 *    '<S9>/Matrix Re-Order'
 *    '<S72>/Matrix Re-Order'
 */
void AR_Drone_Flig_MatrixReOrder(const real_T rtu_M_in[9],
  B_MatrixReOrder_AR_Drone_Flig_T *localB)
{
  /* MATLAB Function 'Data decomposition to 3D Visualization/SL3D Visualization1/Matrix Re-Order': '<S14>:1' */
  /*  SL3D coordinate system is different. This EML block is responsible for */
  /*  re-ordering the matrix in a format that SL3D can understand */
  /* '<S14>:1:7' */
  memcpy(&localB->M_out[0], &rtu_M_in[0], 9U * sizeof(real_T));

  /* set size */
  /* re-order diagonal */
  /* '<S14>:1:10' */
  localB->M_out[0] = rtu_M_in[4];

  /* '<S14>:1:11' */
  localB->M_out[4] = rtu_M_in[8];

  /* '<S14>:1:12' */
  localB->M_out[8] = rtu_M_in[0];

  /* re-order bottom half */
  /* '<S14>:1:15' */
  localB->M_out[1] = rtu_M_in[5];

  /* '<S14>:1:16' */
  localB->M_out[2] = rtu_M_in[3];

  /* '<S14>:1:17' */
  localB->M_out[5] = rtu_M_in[6];

  /* re-order upper half */
  /* '<S14>:1:20' */
  localB->M_out[3] = rtu_M_in[7];

  /* '<S14>:1:21' */
  localB->M_out[6] = rtu_M_in[1];

  /* '<S14>:1:22' */
  localB->M_out[7] = rtu_M_in[2];
}

/*
 * Start for action system:
 *    '<S18>/Phi == pi'
 *    '<S19>/Phi == pi'
 *    '<S129>/Phi == pi'
 */
void AR_Drone_Flight_Phipi_Start(real_T rty_VRRot_Pi[3], real_T *rty_VRRot_Pi_d,
  P_Phipi_AR_Drone_Flight_Contr_T *localP)
{
  /* VirtualOutportStart for Outport: '<S31>/VRRot_Pi' */
  rty_VRRot_Pi[0] = localP->VRRot_Pi_Y0[0];
  rty_VRRot_Pi[1] = localP->VRRot_Pi_Y0[1];
  rty_VRRot_Pi[2] = localP->VRRot_Pi_Y0[2];
  *rty_VRRot_Pi_d = localP->VRRot_Pi_Y0[3];
}

/*
 * Output and update for action system:
 *    '<S18>/Phi == pi'
 *    '<S19>/Phi == pi'
 *    '<S129>/Phi == pi'
 */
void AR_Drone_Flight_Contr_Phipi(const real_T rtu_u[9], real_T rty_VRRot_Pi[3],
  real_T *rty_VRRot_Pi_d, P_Phipi_AR_Drone_Flight_Contr_T *localP, real_T
  rtp_maxzero)
{
  int32_T rowIdx;
  real_T rtb_Sign1;
  real_T rtb_Sign1_idx_0;
  real_T rtb_Sign1_idx_1;
  real_T rtb_Sign1_idx_2;
  real_T rtb_Shiftright_idx_0;
  real_T rtb_Shiftright_idx_1;
  real_T rtb_Shiftright_idx_2;

  /* DeadZone: '<S32>/Dead Zone' */
  if (rtu_u[7] > rtp_maxzero) {
    rtb_Sign1_idx_0 = rtu_u[7] - rtp_maxzero;
  } else if (rtu_u[7] >= -rtp_maxzero) {
    rtb_Sign1_idx_0 = 0.0;
  } else {
    rtb_Sign1_idx_0 = rtu_u[7] - (-rtp_maxzero);
  }

  /* Signum: '<S32>/Sign1' */
  if (rtb_Sign1_idx_0 < 0.0) {
    rtb_Sign1_idx_0 = -1.0;
  } else if (rtb_Sign1_idx_0 > 0.0) {
    rtb_Sign1_idx_0 = 1.0;
  } else {
    if (rtb_Sign1_idx_0 == 0.0) {
      rtb_Sign1_idx_0 = 0.0;
    }
  }

  /* DeadZone: '<S32>/Dead Zone' */
  if (rtu_u[6] > rtp_maxzero) {
    rtb_Sign1_idx_1 = rtu_u[6] - rtp_maxzero;
  } else if (rtu_u[6] >= -rtp_maxzero) {
    rtb_Sign1_idx_1 = 0.0;
  } else {
    rtb_Sign1_idx_1 = rtu_u[6] - (-rtp_maxzero);
  }

  /* Signum: '<S32>/Sign1' */
  if (rtb_Sign1_idx_1 < 0.0) {
    rtb_Sign1_idx_1 = -1.0;
  } else if (rtb_Sign1_idx_1 > 0.0) {
    rtb_Sign1_idx_1 = 1.0;
  } else {
    if (rtb_Sign1_idx_1 == 0.0) {
      rtb_Sign1_idx_1 = 0.0;
    }
  }

  /* DeadZone: '<S32>/Dead Zone' */
  if (rtu_u[3] > rtp_maxzero) {
    rtb_Sign1_idx_2 = rtu_u[3] - rtp_maxzero;
  } else if (rtu_u[3] >= -rtp_maxzero) {
    rtb_Sign1_idx_2 = 0.0;
  } else {
    rtb_Sign1_idx_2 = rtu_u[3] - (-rtp_maxzero);
  }

  /* Signum: '<S32>/Sign1' */
  if (rtb_Sign1_idx_2 < 0.0) {
    rtb_Sign1_idx_2 = -1.0;
  } else if (rtb_Sign1_idx_2 > 0.0) {
    rtb_Sign1_idx_2 = 1.0;
  } else {
    if (rtb_Sign1_idx_2 == 0.0) {
      rtb_Sign1_idx_2 = 0.0;
    }
  }

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Pi1'
   *  Product: '<S32>/Product of Elements'
   *  Sum: '<S32>/Sum of Elements3'
   *  Switch: '<S32>/Switch1'
   */
  if ((rtb_Sign1_idx_0 + rtb_Sign1_idx_1) + rtb_Sign1_idx_2 >=
      localP->Switch_Threshold) {
    rtb_Shiftright_idx_0 = localP->Pi1_Value[0];
    rtb_Shiftright_idx_1 = localP->Pi1_Value[1];
    rtb_Shiftright_idx_2 = localP->Pi1_Value[2];
  } else if (rtb_Sign1_idx_0 * rtb_Sign1_idx_1 * rtb_Sign1_idx_2 != 0.0) {
    /* Switch: '<S32>/Switch1' incorporates:
     *  Gain: '<S32>/Gain1'
     */
    rtb_Shiftright_idx_0 = localP->Gain1_Gain * rtb_Sign1_idx_0;
    rtb_Shiftright_idx_1 = localP->Gain1_Gain * rtb_Sign1_idx_1;
    rtb_Shiftright_idx_2 = localP->Gain1_Gain * rtb_Sign1_idx_2;
  } else {
    /* CombinatorialLogic: '<S32>/Shift right' incorporates:
     *  Constant: '<S33>/Constant'
     *  RelationalOperator: '<S33>/Compare'
     *  Switch: '<S32>/Switch1'
     */
    rowIdx = (int32_T)(((((uint32_T)(rtb_Sign1_idx_0 != localP->Constant_Value_a)
                          << 1) + (rtb_Sign1_idx_1 != localP->Constant_Value_a))
                        << 1) + (rtb_Sign1_idx_2 != localP->Constant_Value_a));
    rtb_Shiftright_idx_0 = localP->Shiftright_table[(uint32_T)rowIdx];
    rtb_Shiftright_idx_1 = localP->Shiftright_table[rowIdx + 8U];
    rtb_Shiftright_idx_2 = localP->Shiftright_table[rowIdx + 16U];
  }

  /* End of Switch: '<S32>/Switch' */

  /* Gain: '<S31>/Gain' incorporates:
   *  Constant: '<S31>/Constant'
   *  Sum: '<S31>/Sum'
   */
  rtb_Sign1_idx_2 = (localP->Constant_Value + rtu_u[0]) * localP->Gain_Gain;

  /* MinMax: '<S31>/MinMax' */
  if (!((rtb_Sign1_idx_2 >= 0.0) || rtIsNaN(0.0))) {
    rtb_Sign1_idx_2 = 0.0;
  }

  /* Math: '<S31>/Math Function'
   *
   * About '<S31>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Sign1_idx_2 < 0.0) {
    rtb_Sign1_idx_0 = -sqrt(fabs(rtb_Sign1_idx_2));
  } else {
    rtb_Sign1_idx_0 = sqrt(rtb_Sign1_idx_2);
  }

  /* Gain: '<S31>/Gain' incorporates:
   *  Constant: '<S31>/Constant'
   *  Sum: '<S31>/Sum'
   */
  rtb_Sign1_idx_2 = (localP->Constant_Value + rtu_u[4]) * localP->Gain_Gain;

  /* MinMax: '<S31>/MinMax' */
  if (!((rtb_Sign1_idx_2 >= 0.0) || rtIsNaN(0.0))) {
    rtb_Sign1_idx_2 = 0.0;
  }

  /* Math: '<S31>/Math Function'
   *
   * About '<S31>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Sign1_idx_2 < 0.0) {
    rtb_Sign1_idx_1 = -sqrt(fabs(rtb_Sign1_idx_2));
  } else {
    rtb_Sign1_idx_1 = sqrt(rtb_Sign1_idx_2);
  }

  /* Gain: '<S31>/Gain' incorporates:
   *  Constant: '<S31>/Constant'
   *  Sum: '<S31>/Sum'
   */
  rtb_Sign1_idx_2 = (localP->Constant_Value + rtu_u[8]) * localP->Gain_Gain;

  /* MinMax: '<S31>/MinMax' */
  if (!((rtb_Sign1_idx_2 >= 0.0) || rtIsNaN(0.0))) {
    rtb_Sign1_idx_2 = 0.0;
  }

  /* Math: '<S31>/Math Function'
   *
   * About '<S31>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Sign1_idx_2 < 0.0) {
    rtb_Sign1_idx_2 = -sqrt(fabs(rtb_Sign1_idx_2));
  } else {
    rtb_Sign1_idx_2 = sqrt(rtb_Sign1_idx_2);
  }

  /* Constant: '<S31>/Pi' */
  *rty_VRRot_Pi_d = localP->Pi_Value;

  /* Switch: '<S31>/Switch' */
  rtb_Sign1 = rtb_Sign1_idx_0;
  if (!(rtb_Sign1_idx_0 > rtp_maxzero)) {
    rtb_Sign1 = 0.0;
  }

  rtb_Sign1_idx_0 = rtb_Sign1;

  /* Switch: '<S31>/Switch' */
  rtb_Sign1 = rtb_Sign1_idx_1;
  if (!(rtb_Sign1_idx_1 > rtp_maxzero)) {
    rtb_Sign1 = 0.0;
  }

  rtb_Sign1_idx_1 = rtb_Sign1;

  /* Switch: '<S31>/Switch' */
  rtb_Sign1 = rtb_Sign1_idx_2;
  if (!(rtb_Sign1_idx_2 > rtp_maxzero)) {
    rtb_Sign1 = 0.0;
  }

  /* Product: '<S31>/Product' */
  rty_VRRot_Pi[0] = rtb_Sign1_idx_0 * rtb_Shiftright_idx_0;
  rty_VRRot_Pi[1] = rtb_Sign1_idx_1 * rtb_Shiftright_idx_1;
  rty_VRRot_Pi[2] = rtb_Sign1 * rtb_Shiftright_idx_2;
}

/*
 * Output and update for action system:
 *    '<S18>/General case'
 *    '<S19>/General case'
 *    '<S129>/General case'
 */
void AR_Drone_Flight_Generalcase(real_T rtu_Traceu, const real_T rtu_u[9],
  real_T rty_VRRot_General[3], real_T *rty_VRRot_General_c,
  P_Generalcase_AR_Drone_Flight_T *localP)
{
  real_T rtb_TrigonometricFunction1;

  /* Gain: '<S29>/Gain1' incorporates:
   *  Constant: '<S29>/Constant'
   *  Sum: '<S29>/Subtract'
   */
  rtb_TrigonometricFunction1 = (rtu_Traceu - localP->Constant_Value) *
    localP->Gain1_Gain;

  /* Trigonometry: '<S29>/Trigonometric Function1' */
  if (rtb_TrigonometricFunction1 > 1.0) {
    rtb_TrigonometricFunction1 = 1.0;
  } else {
    if (rtb_TrigonometricFunction1 < -1.0) {
      rtb_TrigonometricFunction1 = -1.0;
    }
  }

  rtb_TrigonometricFunction1 = acos(rtb_TrigonometricFunction1);

  /* End of Trigonometry: '<S29>/Trigonometric Function1' */

  /* DataTypeConversion: '<S29>/Data Type Conversion' */
  *rty_VRRot_General_c = rtb_TrigonometricFunction1;

  /* Gain: '<S29>/Gain' incorporates:
   *  Trigonometry: '<S29>/Trigonometric Function'
   */
  rtb_TrigonometricFunction1 = localP->Gain_Gain * sin
    (rtb_TrigonometricFunction1);

  /* Product: '<S29>/Divide' incorporates:
   *  Sum: '<S29>/Sum'
   */
  rty_VRRot_General[0] = (rtu_u[5] - rtu_u[7]) / rtb_TrigonometricFunction1;
  rty_VRRot_General[1] = (rtu_u[6] - rtu_u[2]) / rtb_TrigonometricFunction1;
  rty_VRRot_General[2] = (rtu_u[1] - rtu_u[3]) / rtb_TrigonometricFunction1;
}

/* Initial conditions for function-call system: '<S39>/Altitude_Control' */
void AR_Dr_Altitude_Control_Init(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, DW_Altitude_Control_AR_Drone__T *localDW,
  P_Altitude_Control_AR_Drone_F_T *localP)
{
  localDW->Altitude_Control_PREV_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  localDW->Integrator_DSTATE = localP->Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Filter' */
  localDW->Filter_DSTATE = localP->Filter_IC;
}

/* Output and update for function-call system: '<S39>/Altitude_Control' */
void AR_Drone_F_Altitude_Control(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, const real_T rtu_HeightFeedback[2], real_T
  rtu_refHeight, B_Altitude_Control_AR_Drone_F_T *localB,
  DW_Altitude_Control_AR_Drone__T *localDW, P_Altitude_Control_AR_Drone_F_T
  *localP)
{
  real_T rtb_DeadZone;
  real_T rtb_IntegralGain;
  real_T rtb_FilterCoefficient;
  real_T rtb_Gain_f;
  real_T rtb_DeadZone_0;
  real_T rtb_IntegralGain_0;
  localDW->Altitude_Control_ELAPS_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0 -
    localDW->Altitude_Control_PREV_T;
  localDW->Altitude_Control_PREV_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0;

  /* Saturate: '<S40>/Re-Calibrate' */
  if (rtu_HeightFeedback[0] > localP->ReCalibrate_UpperSat) {
    rtb_Gain_f = localP->ReCalibrate_UpperSat;
  } else if (rtu_HeightFeedback[0] < localP->ReCalibrate_LowerSat) {
    rtb_Gain_f = localP->ReCalibrate_LowerSat;
  } else {
    rtb_Gain_f = rtu_HeightFeedback[0];
  }

  /* Sum: '<S40>/Sum' incorporates:
   *  Saturate: '<S40>/Re-Calibrate'
   */
  localB->Error = rtu_refHeight - rtb_Gain_f;

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S46>/Filter'
   *  Gain: '<S46>/Derivative Gain'
   *  Sum: '<S46>/SumD'
   */
  rtb_FilterCoefficient = (localP->PID_Smooth_D * localB->Error -
    localDW->Filter_DSTATE) * localP->PID_Smooth_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S46>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   */
  rtb_DeadZone = (localP->PID_Smooth_P * localB->Error +
                  localDW->Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S46>/Saturation' */
  if (rtb_DeadZone > localP->PID_Smooth_UpperSaturationLimit) {
    localB->Saturation = localP->PID_Smooth_UpperSaturationLimit;
  } else if (rtb_DeadZone < localP->PID_Smooth_LowerSaturationLimit) {
    localB->Saturation = localP->PID_Smooth_LowerSaturationLimit;
  } else {
    localB->Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S46>/Saturation' */

  /* DataTypeConversion: '<S40>/Data Type Conversion1' */
  rtb_Gain_f = floor(localB->Saturation);
  if (rtIsNaN(rtb_Gain_f) || rtIsInf(rtb_Gain_f)) {
    rtb_Gain_f = 0.0;
  } else {
    rtb_Gain_f = fmod(rtb_Gain_f, 65536.0);
  }

  localB->DataTypeConversion1 = (int16_T)(rtb_Gain_f < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Gain_f : (int32_T)(int16_T)(uint16_T)rtb_Gain_f);

  /* End of DataTypeConversion: '<S40>/Data Type Conversion1' */

  /* Gain: '<S48>/Gain' */
  rtb_Gain_f = localP->Gain_Gain * rtb_DeadZone;

  /* DeadZone: '<S48>/DeadZone' */
  if (rtb_DeadZone > localP->PID_Smooth_UpperSaturationLimit) {
    rtb_DeadZone -= localP->PID_Smooth_UpperSaturationLimit;
  } else if (rtb_DeadZone >= localP->PID_Smooth_LowerSaturationLimit) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= localP->PID_Smooth_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S48>/DeadZone' */

  /* Gain: '<S46>/Integral Gain' */
  rtb_IntegralGain = localP->PID_Smooth_I * localB->Error;

  /* Signum: '<S48>/SignPreSat' */
  if (rtb_DeadZone < 0.0) {
    rtb_DeadZone_0 = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    rtb_DeadZone_0 = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    rtb_DeadZone_0 = 0.0;
  } else {
    rtb_DeadZone_0 = rtb_DeadZone;
  }

  /* Signum: '<S48>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0) {
    rtb_IntegralGain_0 = -1.0;
  } else if (rtb_IntegralGain > 0.0) {
    rtb_IntegralGain_0 = 1.0;
  } else if (rtb_IntegralGain == 0.0) {
    rtb_IntegralGain_0 = 0.0;
  } else {
    rtb_IntegralGain_0 = rtb_IntegralGain;
  }

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Constant'
   *  Logic: '<S48>/AND'
   *  RelationalOperator: '<S48>/Equal'
   *  RelationalOperator: '<S48>/NotEqual'
   *  Signum: '<S48>/SignPreIntegrator'
   *  Signum: '<S48>/SignPreSat'
   */
  if ((rtb_Gain_f != rtb_DeadZone) && (rtb_DeadZone_0 == rtb_IntegralGain_0)) {
    rtb_IntegralGain = localP->Constant_Value;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Update for DiscreteIntegrator: '<S46>/Integrator' */
  localDW->Integrator_DSTATE += localP->Integrator_gainval * (real_T)
    localDW->Altitude_Control_ELAPS_T * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S46>/Filter' */
  localDW->Filter_DSTATE += localP->Filter_gainval * (real_T)
    localDW->Altitude_Control_ELAPS_T * rtb_FilterCoefficient;
  localDW->Altitude_Control_SubsysRanBC = 4;
}

/* Initial conditions for function-call system: '<S39>/Attitude_Control' */
void AR_Dr_Attitude_Control_Init(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, DW_Attitude_Control_AR_Drone__T *localDW,
  P_Attitude_Control_AR_Drone_F_T *localP)
{
  localDW->Attitude_Control_PREV_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0;

  /* InitializeConditions for Atomic SubSystem: '<S41>/Roll Pitch Controller' */
  /* InitializeConditions for DiscreteTransferFcn: '<S54>/Digital Low Pass Filter2' */
  localDW->DigitalLowPassFilter2_states =
    localP->DigitalLowPassFilter2_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<S54>/Digital Low Pass Filter1' */
  localDW->DigitalLowPassFilter1_states =
    localP->DigitalLowPassFilter1_InitialSt;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE[0] = localP->Integrator_IC;
  localDW->Integrator_DSTATE[1] = localP->Integrator_IC;
  localDW->Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Filter' */
  localDW->Filter_DSTATE[0] = localP->Filter_IC;
  localDW->Filter_DSTATE[1] = localP->Filter_IC;
  localDW->Filter_PrevResetState = 0;

  /* End of InitializeConditions for SubSystem: '<S41>/Roll Pitch Controller' */

  /* InitializeConditions for UnitDelay: '<S60>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;
}

/* Start for function-call system: '<S39>/Attitude_Control' */
void AR_D_Attitude_Control_Start(B_Attitude_Control_AR_Drone_F_T *localB,
  P_Attitude_Control_AR_Drone_F_T *localP)
{
  /* VirtualOutportStart for Outport: '<S41>/controls' */
  localB->DataTypeConversion1[0] = localP->controls_Y0;
  localB->DataTypeConversion1[1] = localP->controls_Y0;
  localB->DataTypeConversion1[2] = localP->controls_Y0;
}

/* Output and update for function-call system: '<S39>/Attitude_Control' */
void AR_Drone_F_Attitude_Control(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, const real_T rtu_EulerAngle_Feedback_Deg[3], const
  real_T rtu_Desired_Attitude_Deg[3], const real_T rtu_RateGyro_Feedback_Deg[3],
  real_T rtu_Motor_Armed, B_Attitude_Control_AR_Drone_F_T *localB,
  DW_Attitude_Control_AR_Drone__T *localDW, P_Attitude_Control_AR_Drone_F_T
  *localP)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator_m;
  int16_T rtb_DataTypeConversion_c_idx_0;
  int16_T rtb_DataTypeConversion_c_idx_1;
  real_T rtb_Gain_n_idx_0;
  real_T rtb_IntegralGain_h_idx_0;
  real_T rtb_IntegralGain_h_idx_1;
  real_T tmp;
  real32_T u0;
  real_T rtb_DeadZone_a_idx_0;
  real_T rtb_IntegralGain_h_idx_0_0;
  localDW->Attitude_Control_ELAPS_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0 -
    localDW->Attitude_Control_PREV_T;
  localDW->Attitude_Control_PREV_T =
    AR_Drone_Flight_Control_M->Timing.clockTick0;

  /* Gain: '<S41>/Gain' incorporates:
   *  Constant: '<S50>/Offset Constants'
   *  Sum: '<S41>/Add'
   *  Sum: '<S50>/Sum'
   */
  /* MATLAB Function 'Flight Controller/Supervisory Flight Controller/Attitude_Control/MATLAB Function': '<S49>:1' */
  /* '<S49>:1:4' */
  /*  limit the yaw component to +/- 180 degrees */
  /*  if (error(3) > 180)    % Normalize to -180,180 */
  /*      err_normalized(3) = error(3) - 360; */
  /*  elseif(error(3) < -180) */
  /*      err_normalized(3) = error(3) + 360; */
  /*  end */
  u0 = ((real32_T)rtu_Desired_Attitude_Deg[0] - (real32_T)
        (rtu_EulerAngle_Feedback_Deg[0] + localP->OffsetConstants_Value[0])) *
    localP->Gain_Gain_n[0];

  /* Saturate: '<S41>/Saturation3' */
  if (u0 > localP->Saturation3_UpperSat[0]) {
    u0 = localP->Saturation3_UpperSat[0];
  } else {
    if (u0 < localP->Saturation3_LowerSat[0]) {
      u0 = localP->Saturation3_LowerSat[0];
    }
  }

  /* Outputs for Atomic SubSystem: '<S41>/Roll Pitch Controller' */
  /* Sum: '<S51>/Sum' incorporates:
   *  DiscreteTransferFcn: '<S54>/Digital Low Pass Filter2'
   *  Gain: '<S51>/Gain4'
   *  Saturate: '<S41>/Saturation3'
   */
  localB->Sum[0] = localP->Gain4_Gain[0] * u0 -
    localP->DigitalLowPassFilter2_NumCoef *
    localDW->DigitalLowPassFilter2_states;

  /* End of Outputs for SubSystem: '<S41>/Roll Pitch Controller' */

  /* Gain: '<S41>/Gain' incorporates:
   *  Constant: '<S50>/Offset Constants'
   *  Sum: '<S41>/Add'
   *  Sum: '<S50>/Sum1'
   */
  u0 = ((real32_T)rtu_Desired_Attitude_Deg[1] - (real32_T)
        (rtu_EulerAngle_Feedback_Deg[1] + localP->OffsetConstants_Value[1])) *
    localP->Gain_Gain_n[1];

  /* Saturate: '<S41>/Saturation3' */
  if (u0 > localP->Saturation3_UpperSat[1]) {
    u0 = localP->Saturation3_UpperSat[1];
  } else {
    if (u0 < localP->Saturation3_LowerSat[1]) {
      u0 = localP->Saturation3_LowerSat[1];
    }
  }

  /* Outputs for Atomic SubSystem: '<S41>/Roll Pitch Controller' */
  /* Sum: '<S51>/Sum' incorporates:
   *  DiscreteTransferFcn: '<S54>/Digital Low Pass Filter1'
   *  Gain: '<S51>/Gain4'
   *  Saturate: '<S41>/Saturation3'
   */
  localB->Sum[1] = localP->Gain4_Gain[1] * u0 -
    localP->DigitalLowPassFilter1_NumCoef *
    localDW->DigitalLowPassFilter1_states;

  /* Logic: '<S55>/Logical Operator' */
  rtb_LogicalOperator_m = !(rtu_Motor_Armed != 0.0);

  /* DiscreteIntegrator: '<S57>/Integrator' */
  if (rtb_LogicalOperator_m || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE[0] = localP->Integrator_IC;
    localDW->Integrator_DSTATE[1] = localP->Integrator_IC;
  }

  /* DiscreteIntegrator: '<S57>/Filter' */
  if (rtb_LogicalOperator_m || (localDW->Filter_PrevResetState != 0)) {
    localDW->Filter_DSTATE[0] = localP->Filter_IC;
    localDW->Filter_DSTATE[1] = localP->Filter_IC;
  }

  /* Gain: '<S57>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S57>/Filter'
   *  Gain: '<S57>/Derivative Gain'
   *  Sum: '<S57>/SumD'
   */
  localB->rtb_FilterCoefficient_k_idx_0 = (localP->PIDController1_D *
    localB->Sum[0] - localDW->Filter_DSTATE[0]) * localP->PIDController1_N;
  localB->rtb_FilterCoefficient_k_idx_1 = (localP->PIDController1_D *
    localB->Sum[1] - localDW->Filter_DSTATE[1]) * localP->PIDController1_N;

  /* Sum: '<S57>/Sum' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Gain: '<S57>/Proportional Gain'
   */
  localB->rtb_DeadZone_a_idx_0 = (localP->PIDController1_P * localB->Sum[0] +
    localDW->Integrator_DSTATE[0]) + localB->rtb_FilterCoefficient_k_idx_0;
  localB->rtb_DeadZone_a_idx_1 = (localP->PIDController1_P * localB->Sum[1] +
    localDW->Integrator_DSTATE[1]) + localB->rtb_FilterCoefficient_k_idx_1;

  /* Saturate: '<S57>/Saturation' */
  if (localB->rtb_DeadZone_a_idx_0 > localP->PIDController1_UpperSaturationL) {
    rtb_Gain_n_idx_0 = localP->PIDController1_UpperSaturationL;
  } else if (localB->rtb_DeadZone_a_idx_0 <
             localP->PIDController1_LowerSaturationL) {
    rtb_Gain_n_idx_0 = localP->PIDController1_LowerSaturationL;
  } else {
    rtb_Gain_n_idx_0 = localB->rtb_DeadZone_a_idx_0;
  }

  /* DataTypeConversion: '<S51>/Data Type Conversion' incorporates:
   *  Saturate: '<S57>/Saturation'
   */
  rtb_IntegralGain_h_idx_0 = fabs(rtb_Gain_n_idx_0);
  if (rtb_IntegralGain_h_idx_0 < 4.503599627370496E+15) {
    if (rtb_IntegralGain_h_idx_0 >= 0.5) {
      rtb_Gain_n_idx_0 = floor(rtb_Gain_n_idx_0 + 0.5);
    } else {
      rtb_Gain_n_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Gain_n_idx_0) || rtIsInf(rtb_Gain_n_idx_0)) {
    tmp = 0.0;
  } else {
    tmp = fmod(rtb_Gain_n_idx_0, 65536.0);
  }

  rtb_DataTypeConversion_c_idx_0 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Saturate: '<S57>/Saturation' */
  if (localB->rtb_DeadZone_a_idx_1 > localP->PIDController1_UpperSaturationL) {
    rtb_Gain_n_idx_0 = localP->PIDController1_UpperSaturationL;
  } else if (localB->rtb_DeadZone_a_idx_1 <
             localP->PIDController1_LowerSaturationL) {
    rtb_Gain_n_idx_0 = localP->PIDController1_LowerSaturationL;
  } else {
    rtb_Gain_n_idx_0 = localB->rtb_DeadZone_a_idx_1;
  }

  /* DataTypeConversion: '<S51>/Data Type Conversion' incorporates:
   *  Saturate: '<S57>/Saturation'
   */
  rtb_IntegralGain_h_idx_0 = fabs(rtb_Gain_n_idx_0);
  if (rtb_IntegralGain_h_idx_0 < 4.503599627370496E+15) {
    if (rtb_IntegralGain_h_idx_0 >= 0.5) {
      rtb_Gain_n_idx_0 = floor(rtb_Gain_n_idx_0 + 0.5);
    } else {
      rtb_Gain_n_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Gain_n_idx_0) || rtIsInf(rtb_Gain_n_idx_0)) {
    tmp = 0.0;
  } else {
    tmp = fmod(rtb_Gain_n_idx_0, 65536.0);
  }

  rtb_DataTypeConversion_c_idx_1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S59>/Gain' */
  rtb_Gain_n_idx_0 = localP->Gain_Gain * localB->rtb_DeadZone_a_idx_0;

  /* DeadZone: '<S59>/DeadZone' */
  if (localB->rtb_DeadZone_a_idx_0 > localP->PIDController1_UpperSaturationL) {
    localB->rtb_DeadZone_a_idx_0 -= localP->PIDController1_UpperSaturationL;
  } else if (localB->rtb_DeadZone_a_idx_0 >=
             localP->PIDController1_LowerSaturationL) {
    localB->rtb_DeadZone_a_idx_0 = 0.0;
  } else {
    localB->rtb_DeadZone_a_idx_0 -= localP->PIDController1_LowerSaturationL;
  }

  if (localB->rtb_DeadZone_a_idx_1 > localP->PIDController1_UpperSaturationL) {
    localB->rtb_DeadZone_a_m = localB->rtb_DeadZone_a_idx_1 -
      localP->PIDController1_UpperSaturationL;
  } else if (localB->rtb_DeadZone_a_idx_1 >=
             localP->PIDController1_LowerSaturationL) {
    localB->rtb_DeadZone_a_m = 0.0;
  } else {
    localB->rtb_DeadZone_a_m = localB->rtb_DeadZone_a_idx_1 -
      localP->PIDController1_LowerSaturationL;
  }

  /* End of DeadZone: '<S59>/DeadZone' */

  /* Gain: '<S57>/Integral Gain' */
  rtb_IntegralGain_h_idx_0 = localP->PIDController1_I * localB->Sum[0];
  rtb_IntegralGain_h_idx_1 = localP->PIDController1_I * localB->Sum[1];

  /* Saturate: '<S51>/Saturation' */
  if (rtb_DataTypeConversion_c_idx_0 > localP->Saturation_UpperSat) {
    localB->Saturation[0] = localP->Saturation_UpperSat;
  } else if (rtb_DataTypeConversion_c_idx_0 < localP->Saturation_LowerSat) {
    localB->Saturation[0] = localP->Saturation_LowerSat;
  } else {
    localB->Saturation[0] = rtb_DataTypeConversion_c_idx_0;
  }

  if (rtb_DataTypeConversion_c_idx_1 > localP->Saturation_UpperSat) {
    localB->Saturation[1] = localP->Saturation_UpperSat;
  } else if (rtb_DataTypeConversion_c_idx_1 < localP->Saturation_LowerSat) {
    localB->Saturation[1] = localP->Saturation_LowerSat;
  } else {
    localB->Saturation[1] = rtb_DataTypeConversion_c_idx_1;
  }

  /* End of Saturate: '<S51>/Saturation' */

  /* Update for DiscreteTransferFcn: '<S54>/Digital Low Pass Filter2' */
  localDW->DigitalLowPassFilter2_states = (rtu_RateGyro_Feedback_Deg[0] -
    localP->DigitalLowPassFilter2_DenCoef[1] *
    localDW->DigitalLowPassFilter2_states) /
    localP->DigitalLowPassFilter2_DenCoef[0];

  /* Update for DiscreteTransferFcn: '<S54>/Digital Low Pass Filter1' */
  localDW->DigitalLowPassFilter1_states = (rtu_RateGyro_Feedback_Deg[1] -
    localP->DigitalLowPassFilter1_DenCoef[1] *
    localDW->DigitalLowPassFilter1_states) /
    localP->DigitalLowPassFilter1_DenCoef[0];

  /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
   *  Signum: '<S59>/SignPreIntegrator'
   *  Signum: '<S59>/SignPreSat'
   */
  if (!rtb_LogicalOperator_m) {
    tmp = localP->Integrator_gainval * (real_T)localDW->Attitude_Control_ELAPS_T;
    if (localB->rtb_DeadZone_a_idx_0 < 0.0) {
      rtb_DeadZone_a_idx_0 = -1.0;
    } else if (localB->rtb_DeadZone_a_idx_0 > 0.0) {
      rtb_DeadZone_a_idx_0 = 1.0;
    } else if (localB->rtb_DeadZone_a_idx_0 == 0.0) {
      rtb_DeadZone_a_idx_0 = 0.0;
    } else {
      rtb_DeadZone_a_idx_0 = localB->rtb_DeadZone_a_idx_0;
    }

    if (rtb_IntegralGain_h_idx_0 < 0.0) {
      rtb_IntegralGain_h_idx_0_0 = -1.0;
    } else if (rtb_IntegralGain_h_idx_0 > 0.0) {
      rtb_IntegralGain_h_idx_0_0 = 1.0;
    } else if (rtb_IntegralGain_h_idx_0 == 0.0) {
      rtb_IntegralGain_h_idx_0_0 = 0.0;
    } else {
      rtb_IntegralGain_h_idx_0_0 = rtb_IntegralGain_h_idx_0;
    }

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Constant'
     *  Logic: '<S59>/AND'
     *  RelationalOperator: '<S59>/Equal'
     *  RelationalOperator: '<S59>/NotEqual'
     *  Signum: '<S59>/SignPreIntegrator'
     *  Signum: '<S59>/SignPreSat'
     */
    if ((rtb_Gain_n_idx_0 != localB->rtb_DeadZone_a_idx_0) &&
        (rtb_DeadZone_a_idx_0 == rtb_IntegralGain_h_idx_0_0)) {
      rtb_IntegralGain_h_idx_0 = localP->Constant_Value;
    }

    localDW->Integrator_DSTATE[0] += tmp * rtb_IntegralGain_h_idx_0;
    if (localB->rtb_DeadZone_a_m < 0.0) {
      rtb_Gain_n_idx_0 = -1.0;
    } else if (localB->rtb_DeadZone_a_m > 0.0) {
      rtb_Gain_n_idx_0 = 1.0;
    } else if (localB->rtb_DeadZone_a_m == 0.0) {
      rtb_Gain_n_idx_0 = 0.0;
    } else {
      rtb_Gain_n_idx_0 = localB->rtb_DeadZone_a_m;
    }

    if (rtb_IntegralGain_h_idx_1 < 0.0) {
      rtb_IntegralGain_h_idx_0 = -1.0;
    } else if (rtb_IntegralGain_h_idx_1 > 0.0) {
      rtb_IntegralGain_h_idx_0 = 1.0;
    } else if (rtb_IntegralGain_h_idx_1 == 0.0) {
      rtb_IntegralGain_h_idx_0 = 0.0;
    } else {
      rtb_IntegralGain_h_idx_0 = rtb_IntegralGain_h_idx_1;
    }

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Constant'
     *  Gain: '<S59>/Gain'
     *  Logic: '<S59>/AND'
     *  RelationalOperator: '<S59>/Equal'
     *  RelationalOperator: '<S59>/NotEqual'
     *  Signum: '<S59>/SignPreIntegrator'
     */
    if ((localP->Gain_Gain * localB->rtb_DeadZone_a_idx_1 !=
         localB->rtb_DeadZone_a_m) && (rtb_Gain_n_idx_0 ==
         rtb_IntegralGain_h_idx_0)) {
      rtb_IntegralGain_h_idx_1 = localP->Constant_Value;
    }

    localDW->Integrator_DSTATE[1] += tmp * rtb_IntegralGain_h_idx_1;
  }

  if (rtb_LogicalOperator_m) {
    localDW->Integrator_PrevResetState = 1;
  } else {
    localDW->Integrator_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S57>/Integrator' */

  /* Update for DiscreteIntegrator: '<S57>/Filter' */
  if (!rtb_LogicalOperator_m) {
    tmp = localP->Filter_gainval * (real_T)localDW->Attitude_Control_ELAPS_T;
    localDW->Filter_DSTATE[0] += tmp * localB->rtb_FilterCoefficient_k_idx_0;
    localDW->Filter_DSTATE[1] += tmp * localB->rtb_FilterCoefficient_k_idx_1;
  }

  if (rtb_LogicalOperator_m) {
    localDW->Filter_PrevResetState = 1;
  } else {
    localDW->Filter_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S57>/Filter' */
  /* End of Outputs for SubSystem: '<S41>/Roll Pitch Controller' */

  /* SampleTimeMath: '<S60>/TSamp' incorporates:
   *  Gain: '<S52>/InterChange_Axis'
   *
   * About '<S60>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Gain_n_idx_0 = (real32_T)(localP->InterChange_Axis_Gain *
    rtu_EulerAngle_Feedback_Deg[2]) / ((real_T)localDW->Attitude_Control_ELAPS_T
    * 0.0025 * localP->TSamp_WtEt);

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  Constant: '<S41>/Constant'
   *  Gain: '<S52>/To Degrees2'
   *  Gain: '<S52>/To Degrees3'
   *  Gain: '<S52>/Yaw_contribution'
   *  Gain: '<S52>/Yaw_contribution1'
   *  Sum: '<S52>/Add1'
   *  Sum: '<S52>/Add2'
   *  Sum: '<S60>/Diff'
   *  UnitDelay: '<S60>/UD'
   */
  u0 = (real32_T)floor((((real32_T)(rtb_Gain_n_idx_0 - localDW->UD_DSTATE) -
    (real32_T)(localP->ToDegrees2_Gain * localP->Constant_Value_d)) *
                        localP->Yaw_contribution_Gain - (real32_T)
                        (localP->ToDegrees3_Gain * rtu_RateGyro_Feedback_Deg[2]))
                       * localP->Yaw_contribution1_Gain);
  if (rtIsNaNF(u0) || rtIsInfF(u0)) {
    u0 = 0.0F;
  } else {
    u0 = (real32_T)fmod(u0, 65536.0F);
  }

  localB->DataTypeConversion = (int16_T)(u0 < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

  /* End of DataTypeConversion: '<S52>/Data Type Conversion' */

  /* DataTypeConversion: '<S41>/Data Type Conversion1' */
  localB->DataTypeConversion1[0] = localB->Saturation[0];
  localB->DataTypeConversion1[1] = localB->Saturation[1];
  localB->DataTypeConversion1[2] = localB->DataTypeConversion;

  /* Update for UnitDelay: '<S60>/UD' */
  localDW->UD_DSTATE = rtb_Gain_n_idx_0;
  localDW->Attitude_Control_SubsysRanBC = 4;
}

/* Initial conditions for function-call system: '<S39>/Motor_Mixing' */
void AR_Drone__Motor_Mixing_Init(DW_Motor_Mixing_AR_Drone_Flig_T *localDW)
{
  /* InitializeConditions for MATLAB Function: '<S44>/RampDownInSpeed1' */
  localDW->tempCmd[0] = 0.0;
  localDW->tempCmd[1] = 0.0;
  localDW->tempCmd[2] = 0.0;
  localDW->tempCmd[3] = 0.0;
}

/* Start for function-call system: '<S39>/Motor_Mixing' */
void AR_Drone_Motor_Mixing_Start(B_Motor_Mixing_AR_Drone_Fligh_T *localB,
  P_Motor_Mixing_AR_Drone_Fligh_T *localP)
{
  /* VirtualOutportStart for Outport: '<S44>/MotorCommands' */
  localB->Switch[0] = localP->MotorCommands_Y0;
  localB->Switch[1] = localP->MotorCommands_Y0;
  localB->Switch[2] = localP->MotorCommands_Y0;
  localB->Switch[3] = localP->MotorCommands_Y0;
}

/* Output and update for function-call system: '<S39>/Motor_Mixing' */
void AR_Drone_Fligh_Motor_Mixing(real_T rtu_LandingPhase, real_T rtu_Motor_Armed,
  int16_T rtu_throttle, const int16_T rtu_RPYCmd[3],
  B_Motor_Mixing_AR_Drone_Fligh_T *localB, DW_Motor_Mixing_AR_Drone_Flig_T
  *localDW, P_Motor_Mixing_AR_Drone_Fligh_T *localP)
{
  int16_T rtb_Gain_b[4];
  int32_T i;
  real_T rtb_motorCmd;
  int16_T rtb_Gain_k;
  real_T rtb_motorCmd_idx_0;
  real_T rtb_motorCmd_idx_1;
  real_T rtb_motorCmd_idx_2;
  real_T rtb_motorCmd_idx_3;

  /* MATLAB Function: '<S44>/RampDownInSpeed1' incorporates:
   *  Constant: '<S44>/Constant2'
   */
  /* MATLAB Function 'Flight Controller/Supervisory Flight Controller/Motor_Mixing/RampDownInSpeed1': '<S63>:1' */
  if (rtu_LandingPhase != 0.0) {
    /* '<S63>:1:8' */
    localDW->tempCmd[0] += 0.0375;
    localDW->tempCmd[1] += 0.0375;
    localDW->tempCmd[2] += 0.0375;
    localDW->tempCmd[3] += 0.0375;

    /* '<S63>:1:9' */
    rtb_motorCmd_idx_0 = localP->Constant2_Value[0] - localDW->tempCmd[0];
    rtb_motorCmd_idx_1 = localP->Constant2_Value[1] - localDW->tempCmd[1];
    rtb_motorCmd_idx_2 = localP->Constant2_Value[2] - localDW->tempCmd[2];
    rtb_motorCmd_idx_3 = localP->Constant2_Value[3] - localDW->tempCmd[3];
  } else {
    /* '<S63>:1:12' */
    localDW->tempCmd[0] = 0.0;
    localDW->tempCmd[1] = 0.0;
    localDW->tempCmd[2] = 0.0;
    localDW->tempCmd[3] = 0.0;

    /* '<S63>:1:13' */
    rtb_motorCmd_idx_0 = localP->Constant2_Value[0];
    rtb_motorCmd_idx_1 = localP->Constant2_Value[1];
    rtb_motorCmd_idx_2 = localP->Constant2_Value[2];
    rtb_motorCmd_idx_3 = localP->Constant2_Value[3];
  }

  /*  if (motorCmd(1) <=0) */
  /*          motorCmd = ([0;0;0;0]); */
  /*  end */
  /* apply lower bounding */
  /* '<S63>:1:21' */
  rtb_motorCmd = rtb_motorCmd_idx_0;

  /* '<S63>:1:21' */
  if (rtb_motorCmd_idx_0 < 0.0) {
    /* '<S63>:1:23' */
    /* '<S63>:1:24' */
    rtb_motorCmd = 0.0;
  }

  /* '<S63>:1:21' */
  rtb_motorCmd_idx_0 = rtb_motorCmd;
  rtb_motorCmd = rtb_motorCmd_idx_1;

  /* '<S63>:1:21' */
  if (rtb_motorCmd_idx_1 < 0.0) {
    /* '<S63>:1:23' */
    /* '<S63>:1:24' */
    rtb_motorCmd = 0.0;
  }

  /* '<S63>:1:21' */
  rtb_motorCmd_idx_1 = rtb_motorCmd;
  rtb_motorCmd = rtb_motorCmd_idx_2;

  /* '<S63>:1:21' */
  if (rtb_motorCmd_idx_2 < 0.0) {
    /* '<S63>:1:23' */
    /* '<S63>:1:24' */
    rtb_motorCmd = 0.0;
  }

  /* '<S63>:1:21' */
  rtb_motorCmd_idx_2 = rtb_motorCmd;
  rtb_motorCmd = rtb_motorCmd_idx_3;

  /* '<S63>:1:21' */
  if (rtb_motorCmd_idx_3 < 0.0) {
    /* '<S63>:1:23' */
    /* '<S63>:1:24' */
    rtb_motorCmd = 0.0;
  }

  /* End of MATLAB Function: '<S44>/RampDownInSpeed1' */

  /* Switch: '<S44>/Switch' incorporates:
   *  Logic: '<S44>/Logical Operator1'
   */
  /* '<S63>:1:21' */
  if (!(rtu_LandingPhase != 0.0)) {
    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Constant1'
     *  RelationalOperator: '<S64>/LowerRelop1'
     *  Switch: '<S64>/Switch2'
     */
    if (rtu_Motor_Armed > localP->Switch1_Threshold) {
      /* Gain: '<S44>/Gain' incorporates:
       *  SignalConversion: '<S44>/TmpSignal ConversionAtGainInport1'
       */
      for (i = 0; i < 4; i++) {
        rtb_Gain_k = (int16_T)((int16_T)(localP->Gain_Gain[i + 12] * rtu_RPYCmd
          [2]) + (int16_T)((int16_T)(localP->Gain_Gain[i + 8] * rtu_RPYCmd[1]) +
                           (int16_T)((int16_T)(localP->Gain_Gain[i + 4] *
          rtu_RPYCmd[0]) + (int16_T)(localP->Gain_Gain[i] * rtu_throttle))));
        rtb_Gain_b[i] = rtb_Gain_k;
      }

      /* End of Gain: '<S44>/Gain' */
      rtb_Gain_k = rtb_Gain_b[0];

      /* Switch: '<S64>/Switch2' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/minThrottle'
       *  RelationalOperator: '<S64>/LowerRelop1'
       *  RelationalOperator: '<S64>/UpperRelop'
       *  Switch: '<S64>/Switch'
       */
      if (rtb_Gain_b[0] > localP->Constant_Value) {
        rtb_Gain_k = localP->Constant_Value;
      } else {
        if (rtb_Gain_b[0] < localP->minThrottle_Value) {
          /* Switch: '<S64>/Switch' incorporates:
           *  Constant: '<S44>/minThrottle'
           */
          rtb_Gain_k = localP->minThrottle_Value;
        }
      }

      rtb_Gain_b[0] = rtb_Gain_k;
      rtb_Gain_k = rtb_Gain_b[1];

      /* Switch: '<S64>/Switch2' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/minThrottle'
       *  RelationalOperator: '<S64>/LowerRelop1'
       *  RelationalOperator: '<S64>/UpperRelop'
       *  Switch: '<S64>/Switch'
       */
      if (rtb_Gain_b[1] > localP->Constant_Value) {
        rtb_Gain_k = localP->Constant_Value;
      } else {
        if (rtb_Gain_b[1] < localP->minThrottle_Value) {
          /* Switch: '<S64>/Switch' incorporates:
           *  Constant: '<S44>/minThrottle'
           */
          rtb_Gain_k = localP->minThrottle_Value;
        }
      }

      rtb_Gain_b[1] = rtb_Gain_k;
      rtb_Gain_k = rtb_Gain_b[2];

      /* Switch: '<S64>/Switch2' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/minThrottle'
       *  RelationalOperator: '<S64>/LowerRelop1'
       *  RelationalOperator: '<S64>/UpperRelop'
       *  Switch: '<S64>/Switch'
       */
      if (rtb_Gain_b[2] > localP->Constant_Value) {
        rtb_Gain_k = localP->Constant_Value;
      } else {
        if (rtb_Gain_b[2] < localP->minThrottle_Value) {
          /* Switch: '<S64>/Switch' incorporates:
           *  Constant: '<S44>/minThrottle'
           */
          rtb_Gain_k = localP->minThrottle_Value;
        }
      }

      rtb_Gain_b[2] = rtb_Gain_k;
      rtb_Gain_k = rtb_Gain_b[3];

      /* Switch: '<S64>/Switch2' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/minThrottle'
       *  RelationalOperator: '<S64>/LowerRelop1'
       *  RelationalOperator: '<S64>/UpperRelop'
       *  Switch: '<S64>/Switch'
       */
      if (rtb_Gain_b[3] > localP->Constant_Value) {
        rtb_Gain_k = localP->Constant_Value;
      } else {
        if (rtb_Gain_b[3] < localP->minThrottle_Value) {
          /* Switch: '<S64>/Switch' incorporates:
           *  Constant: '<S44>/minThrottle'
           */
          rtb_Gain_k = localP->minThrottle_Value;
        }
      }

      rtb_Gain_b[3] = rtb_Gain_k;
    } else {
      rtb_Gain_b[0] = localP->Constant1_Value[0];
      rtb_Gain_b[1] = localP->Constant1_Value[1];
      rtb_Gain_b[2] = localP->Constant1_Value[2];
      rtb_Gain_b[3] = localP->Constant1_Value[3];
    }

    /* End of Switch: '<S44>/Switch1' */
    localB->Switch[0] = rtb_Gain_b[0];
    localB->Switch[1] = rtb_Gain_b[1];
    localB->Switch[2] = rtb_Gain_b[2];
    localB->Switch[3] = rtb_Gain_b[3];
  } else {
    localB->Switch[0] = rtb_motorCmd_idx_0;
    localB->Switch[1] = rtb_motorCmd_idx_1;
    localB->Switch[2] = rtb_motorCmd_idx_2;
    localB->Switch[3] = rtb_motorCmd;
  }

  /* End of Switch: '<S44>/Switch' */
  localDW->Motor_Mixing_SubsysRanBC = 4;
}

/*
 * Initial conditions for atomic system:
 *    '<S81>/Chart'
 *    '<S87>/Chart'
 *    '<S93>/Chart'
 *    '<S99>/Chart'
 *    '<S105>/Chart'
 */
void AR_Drone_Flight__Chart_Init(DW_Chart_AR_Drone_Flight_Cont_T *localDW)
{
  localDW->sfEvent = AR_Drone_Flight_Co_CALL_EVENT_l;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_AR_Drone_Flight_Co = 0U;
  localDW->is_c2_AR_Drone_Flight_Control = AR_Drone_Fli_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S81>/Chart'
 *    '<S87>/Chart'
 *    '<S93>/Chart'
 *    '<S99>/Chart'
 *    '<S105>/Chart'
 */
void AR_Drone_Flight_Contr_Chart(boolean_T rtu_if_transition, real_T
  rtu_HoldDataTicks, B_Chart_AR_Drone_Flight_Contr_T *localB,
  DW_Chart_AR_Drone_Flight_Cont_T *localDW)
{
  /* Gateway: Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart */
  localDW->sfEvent = AR_Drone_Flight_Co_CALL_EVENT_l;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* During: Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart */
  if (localDW->is_active_c2_AR_Drone_Flight_Co == 0U) {
    /* Entry: Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart */
    localDW->is_active_c2_AR_Drone_Flight_Co = 1U;

    /* Entry Internal: Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart */
    /* Transition: '<S82>:3' */
    localDW->is_c2_AR_Drone_Flight_Control = AR_Drone_Flight_IN_Begin_State0;

    /* Entry 'Begin_State0': '<S82>:15' */
    localB->output = 0.0;
  } else {
    switch (localDW->is_c2_AR_Drone_Flight_Control) {
     case AR_Drone_Flight__IN_Begin_State:
      /* During 'Begin_State': '<S82>:2' */
      if (localDW->temporalCounter_i1 >= (uint32_T)rtu_HoldDataTicks) {
        /* Transition: '<S82>:5' */
        localDW->is_c2_AR_Drone_Flight_Control = AR_Drone_Flight_Co_IN_End_State;

        /* Entry 'End_State': '<S82>:4' */
        localB->output = 0.0;
      } else {
        if (rtu_if_transition == 1) {
          /* Transition: '<S82>:12' */
          localDW->is_c2_AR_Drone_Flight_Control =
            AR_Drone_Flight__IN_Begin_State;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Begin_State': '<S82>:2' */
          localB->output = 1.0;
        }
      }
      break;

     case AR_Drone_Flight_IN_Begin_State0:
      /* During 'Begin_State0': '<S82>:15' */
      if (rtu_if_transition == 1) {
        /* Transition: '<S82>:16' */
        localDW->is_c2_AR_Drone_Flight_Control = AR_Drone_Flight__IN_Begin_State;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Begin_State': '<S82>:2' */
        localB->output = 1.0;
      }
      break;

     default:
      /* During 'End_State': '<S82>:4' */
      if (rtu_if_transition == 1) {
        /* Transition: '<S82>:13' */
        localDW->is_c2_AR_Drone_Flight_Control = AR_Drone_Flight__IN_Begin_State;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Begin_State': '<S82>:2' */
        localB->output = 1.0;
      }
      break;
    }
  }
}

/* Function for Chart: '<S4>/Supervisory Flight Controller' */
static void AR_Dro_Accel_Offset_Calculation(const real_T OffsetMeasure[3],
  real_T Reset, real_T Y[3])
{
  /* MATLAB Function 'Accel_Offset_Calculation': '<S39>:603' */
  /* Compute running average while in this state. Assumed inputs */
  /* are accelerometer offset values. These values are accumulated over time */
  /* and divided by the total time increment to return an average values */
  /* '<S39>:603:6' */
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  if ((!AR_Drone_Flight_Control_DW.A_x_sum_not_empty) || (Reset == 1.0)) {
    /* '<S39>:603:12' */
    /* '<S39>:603:13' */
    AR_Drone_Flight_Control_DW.A_x_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_x_sum_not_empty = true;

    /* '<S39>:603:14' */
    AR_Drone_Flight_Control_DW.A_y_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_y_sum_not_empty = true;

    /* '<S39>:603:15' */
    AR_Drone_Flight_Control_DW.A_z_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_z_sum_not_empty = true;

    /* '<S39>:603:16' */
    AR_Drone_Flight_Control_DW.Tick = 1.0;
    AR_Drone_Flight_Control_DW.Tick_not_empty = true;
  } else {
    /* '<S39>:603:20' */
    /* '<S39>:603:21' */
    /* '<S39>:603:22' */
    /* '<S39>:603:24' */
    AR_Drone_Flight_Control_DW.A_x_sum += OffsetMeasure[0];

    /* '<S39>:603:25' */
    AR_Drone_Flight_Control_DW.A_y_sum += OffsetMeasure[1];

    /* '<S39>:603:26' */
    AR_Drone_Flight_Control_DW.A_z_sum += OffsetMeasure[2];

    /* '<S39>:603:29' */
    Y[0] = AR_Drone_Flight_Control_DW.A_x_sum / AR_Drone_Flight_Control_DW.Tick;
    Y[1] = AR_Drone_Flight_Control_DW.A_y_sum / AR_Drone_Flight_Control_DW.Tick;
    Y[2] = AR_Drone_Flight_Control_DW.A_z_sum / AR_Drone_Flight_Control_DW.Tick;

    /* '<S39>:603:32' */
    AR_Drone_Flight_Control_DW.Tick++;
  }
}

/* Function for Chart: '<S4>/Supervisory Flight Controller' */
static void AR_Dron_Gyro_Offset_Calculation(const real_T OffsetMeasure[3],
  real_T Reset, real_T Y[3])
{
  /* MATLAB Function 'Gyro_Offset_Calculation': '<S39>:592' */
  /* Compute running average while in this state. Assumed inputs */
  /* are gyro offset values when drone is perfectly stationary on the ground. These values are accumulated over time */
  /* and divided by the total time increment to return an average values */
  /* '<S39>:592:6' */
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  if ((!AR_Drone_Flight_Control_DW.G_x_sum_not_empty) || (Reset == 1.0)) {
    /* '<S39>:592:12' */
    /* '<S39>:592:13' */
    AR_Drone_Flight_Control_DW.G_x_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_x_sum_not_empty = true;

    /* '<S39>:592:14' */
    AR_Drone_Flight_Control_DW.G_y_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_y_sum_not_empty = true;

    /* '<S39>:592:15' */
    AR_Drone_Flight_Control_DW.G_z_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_z_sum_not_empty = true;

    /* '<S39>:592:17' */
    AR_Drone_Flight_Control_DW.Tick_a = 1.0;
    AR_Drone_Flight_Control_DW.Tick_not_empty_i = true;
  } else {
    /* '<S39>:592:21' */
    /* '<S39>:592:22' */
    /* '<S39>:592:23' */
    /* '<S39>:592:25' */
    AR_Drone_Flight_Control_DW.G_x_sum += OffsetMeasure[0];

    /* '<S39>:592:26' */
    AR_Drone_Flight_Control_DW.G_y_sum += OffsetMeasure[1];

    /* '<S39>:592:27' */
    AR_Drone_Flight_Control_DW.G_z_sum += OffsetMeasure[2];

    /* '<S39>:592:30' */
    Y[0] = AR_Drone_Flight_Control_DW.G_x_sum /
      AR_Drone_Flight_Control_DW.Tick_a;
    Y[1] = AR_Drone_Flight_Control_DW.G_y_sum /
      AR_Drone_Flight_Control_DW.Tick_a;
    Y[2] = AR_Drone_Flight_Control_DW.G_z_sum /
      AR_Drone_Flight_Control_DW.Tick_a;

    /* '<S39>:592:33' */
    AR_Drone_Flight_Control_DW.Tick_a++;
  }
}

/* Function for Chart: '<S4>/Supervisory Flight Controller' */
static void AR_D_Accel_Offset_Calculation_f(const real_T OffsetMeasure[3],
  real_T Reset)
{
  /* MATLAB Function 'Accel_Offset_Calculation': '<S39>:603' */
  /* Compute running average while in this state. Assumed inputs */
  /* are accelerometer offset values. These values are accumulated over time */
  /* and divided by the total time increment to return an average values */
  if ((!AR_Drone_Flight_Control_DW.A_x_sum_not_empty) || (Reset == 1.0)) {
    /* '<S39>:603:12' */
    /* '<S39>:603:13' */
    AR_Drone_Flight_Control_DW.A_x_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_x_sum_not_empty = true;

    /* '<S39>:603:14' */
    AR_Drone_Flight_Control_DW.A_y_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_y_sum_not_empty = true;

    /* '<S39>:603:15' */
    AR_Drone_Flight_Control_DW.A_z_sum = 0.0;
    AR_Drone_Flight_Control_DW.A_z_sum_not_empty = true;

    /* '<S39>:603:16' */
    AR_Drone_Flight_Control_DW.Tick = 1.0;
    AR_Drone_Flight_Control_DW.Tick_not_empty = true;
  } else {
    /* '<S39>:603:20' */
    /* '<S39>:603:21' */
    /* '<S39>:603:22' */
    /* '<S39>:603:24' */
    AR_Drone_Flight_Control_DW.A_x_sum += OffsetMeasure[0];

    /* '<S39>:603:25' */
    AR_Drone_Flight_Control_DW.A_y_sum += OffsetMeasure[1];

    /* '<S39>:603:26' */
    AR_Drone_Flight_Control_DW.A_z_sum += OffsetMeasure[2];

    /* '<S39>:603:32' */
    AR_Drone_Flight_Control_DW.Tick++;
  }
}

/* Function for Chart: '<S4>/Supervisory Flight Controller' */
static void AR_Dr_Gyro_Offset_Calculation_c(const real_T OffsetMeasure[3],
  real_T Reset)
{
  /* MATLAB Function 'Gyro_Offset_Calculation': '<S39>:592' */
  /* Compute running average while in this state. Assumed inputs */
  /* are gyro offset values when drone is perfectly stationary on the ground. These values are accumulated over time */
  /* and divided by the total time increment to return an average values */
  if ((!AR_Drone_Flight_Control_DW.G_x_sum_not_empty) || (Reset == 1.0)) {
    /* '<S39>:592:12' */
    /* '<S39>:592:13' */
    AR_Drone_Flight_Control_DW.G_x_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_x_sum_not_empty = true;

    /* '<S39>:592:14' */
    AR_Drone_Flight_Control_DW.G_y_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_y_sum_not_empty = true;

    /* '<S39>:592:15' */
    AR_Drone_Flight_Control_DW.G_z_sum = 0.0;
    AR_Drone_Flight_Control_DW.G_z_sum_not_empty = true;

    /* '<S39>:592:17' */
    AR_Drone_Flight_Control_DW.Tick_a = 1.0;
    AR_Drone_Flight_Control_DW.Tick_not_empty_i = true;
  } else {
    /* '<S39>:592:21' */
    /* '<S39>:592:22' */
    /* '<S39>:592:23' */
    /* '<S39>:592:25' */
    AR_Drone_Flight_Control_DW.G_x_sum += OffsetMeasure[0];

    /* '<S39>:592:26' */
    AR_Drone_Flight_Control_DW.G_y_sum += OffsetMeasure[1];

    /* '<S39>:592:27' */
    AR_Drone_Flight_Control_DW.G_z_sum += OffsetMeasure[2];

    /* '<S39>:592:33' */
    AR_Drone_Flight_Control_DW.Tick_a++;
  }
}

/* Function for Chart: '<S4>/Supervisory Flight Controller' */
static void AR_Drone_Flight_Con_Drone_State(void)
{
  static const boolean_T guard1InitVal = false;
  AR_Drone_Flight_Control_B.guard1 = guard1InitVal;

  /* During 'Drone_State': '<S39>:272' */
  switch (AR_Drone_Flight_Control_B.Drone_StateMode) {
   case Drone_StateModeType_WaitForHost:
    /* During 'WaitForHost': '<S39>:381' */
    if ((AR_Drone_Flight_Control_B.Drone_StateModeConversion ==
         Drone_StateModeType_Controlled_Flight) &&
        (AR_Drone_Flight_Control_DW.is_BatteryNominal ==
         AR_Drone_Flight_Cont_IN_Nominal) &&
        (AR_Drone_Flight_Control_DW.initDone == 1)) {
      /* Transition: '<S39>:397' */
      /* Exit Internal 'WaitForHost': '<S39>:381' */
      AR_Drone_Flight_Control_DW.is_WaitForHost =
        AR_Drone_F_IN_NO_ACTIVE_CHILD_b;

      /* Exit 'WaitForHost': '<S39>:381' */
      AR_Drone_Flight_Control_B.Drone_StateMode =
        Drone_StateModeType_Controlled_Flight;

      /* Entry 'Controlled_Flight': '<S39>:252' */
      AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
      AR_Drone_Flight_Control_DW.MotorArmed = 1.0;

      /* Entry Internal 'Controlled_Flight': '<S39>:252' */
      /* Transition: '<S39>:655' */
      AR_Drone_Flight_Control_DW.is_Controlled_Flight =
        AR_Drone_Flight_C_IN_Initialize;
      AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

      /* Entry 'Initialize': '<S39>:654' */
      AR_Drone_Flight_Control_B.refHeight = 0.0;
    } else {
      switch (AR_Drone_Flight_Control_DW.is_WaitForHost) {
       case AR_IN_Attitude_Convergence_Wait:
        /* During 'Attitude_Convergence_Wait': '<S39>:598' */
        if ((AR_Drone_Flight_Control_DW.Converge_Flag == 1) &&
            (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
          /* Transition: '<S39>:595' */
          if (AR_Drone_Flight_Control_B.DataTypeConversion5) {
            /* Transition: '<S39>:629' */
            AR_Drone_Flight_Control_DW.is_WaitForHost =
              AR_IN_Calculate_Attitude_Offset;
            AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

            /* Entry 'Calculate_Attitude_Offset': '<S39>:599' */
            AR_Drone_Flight_Control_DW.reset_offset_calc = 0.0;
            AR_Drone_Flight_Control_DW.Move = false;
          } else {
            /* Transition: '<S39>:634' */
            AR_Drone_Flight_Control_DW.is_WaitForHost =
              AR_Drone_Fli_IN_Wait_For_Flight;

            /* Entry 'Wait_For_Flight': '<S39>:633' */
            AR_Drone_Flight_Control_DW.Offset_Accel[0] =
              rtP_Accelerometer_quick_calibration[0];
            AR_Drone_Flight_Control_DW.Offset_Accel[1] =
              rtP_Accelerometer_quick_calibration[1];
            AR_Drone_Flight_Control_DW.Offset_Accel[2] =
              rtP_Accelerometer_quick_calibration[2];
            AR_Drone_Flight_Control_DW.Offset_Gyro[0] =
              rtP_Gyrometer_quick_calibration[0];
            AR_Drone_Flight_Control_DW.Offset_Gyro[1] =
              rtP_Gyrometer_quick_calibration[1];
            AR_Drone_Flight_Control_DW.Offset_Gyro[2] =
              rtP_Gyrometer_quick_calibration[2];
          }
        } else {
          AR_Drone_Flight_Control_B.guard1 = true;
        }
        break;

       case AR_Dro_IN_Auto_Calibration_Done:
        /* During 'Auto_Calibration_Done': '<S39>:610' */
        if ((AR_Drone_Flight_Control_DW.initDone == 1) &&
            (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
          /* Transition: '<S39>:611' */
          AR_Drone_Flight_Control_DW.is_WaitForHost =
            AR_IN_Calculate_Attitude_Offset;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Calculate_Attitude_Offset': '<S39>:599' */
          AR_Drone_Flight_Control_DW.reset_offset_calc = 0.0;
          AR_Drone_Flight_Control_DW.Move = false;
        } else if (!AR_Drone_Flight_Control_B.DataTypeConversion5) {
          /* Transition: '<S39>:637' */
          AR_Drone_Flight_Control_DW.is_WaitForHost =
            AR_IN_Attitude_Convergence_Wait;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Attitude_Convergence_Wait': '<S39>:598' */
          AR_Drone_Flight_Control_DW.initDone = false;
        } else {
          AR_Drone_Flight_Control_DW.initDone = true;
        }
        break;

       case AR_IN_Calculate_Attitude_Offset:
        /* During 'Calculate_Attitude_Offset': '<S39>:599' */
        if ((AR_Drone_Flight_Control_DW.Move == 0) &&
            (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 1200U)) {
          /* Transition: '<S39>:593' */
          AR_Drone_Flight_Control_DW.is_WaitForHost =
            AR_Dro_IN_Auto_Calibration_Done;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Auto_Calibration_Done': '<S39>:610' */
          AR_Drone_Flight_Control_DW.Offset_Accel[0] =
            AR_Drone_Flight_Control_DW.Offset_Accel_Current[0];
          AR_Drone_Flight_Control_DW.Offset_Accel[1] =
            AR_Drone_Flight_Control_DW.Offset_Accel_Current[1];
          AR_Drone_Flight_Control_DW.Offset_Accel[2] =
            AR_Drone_Flight_Control_DW.Offset_Accel_Current[2];
          AR_Drone_Flight_Control_DW.Offset_Gyro[0] =
            AR_Drone_Flight_Control_DW.Offset_Gyro_Current[0];
          AR_Drone_Flight_Control_DW.Offset_Gyro[1] =
            AR_Drone_Flight_Control_DW.Offset_Gyro_Current[1];
          AR_Drone_Flight_Control_DW.Offset_Gyro[2] =
            AR_Drone_Flight_Control_DW.Offset_Gyro_Current[2];
          AR_Drone_Flight_Control_DW.reset_offset_calc = 1.0;
          AR_D_Accel_Offset_Calculation_f(AR_Drone_Flight_Control_B.Multiply,
            AR_Drone_Flight_Control_DW.reset_offset_calc);
          AR_Dr_Gyro_Offset_Calculation_c
            (AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha,
             AR_Drone_Flight_Control_DW.reset_offset_calc);
        } else if ((AR_Drone_Flight_Control_DW.Move == 1) &&
                   (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
          /* Transition: '<S39>:605' */
          AR_Drone_Flight_Control_DW.reset_offset_calc = 1.0;
          AR_D_Accel_Offset_Calculation_f(AR_Drone_Flight_Control_B.Multiply,
            AR_Drone_Flight_Control_DW.reset_offset_calc);
          AR_Dr_Gyro_Offset_Calculation_c
            (AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha,
             AR_Drone_Flight_Control_DW.reset_offset_calc);
          AR_Drone_Flight_Control_DW.is_WaitForHost =
            AR_IN_Attitude_Convergence_Wait;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Attitude_Convergence_Wait': '<S39>:598' */
          AR_Drone_Flight_Control_DW.initDone = false;
        } else {
          AR_Dro_Accel_Offset_Calculation(AR_Drone_Flight_Control_B.Multiply,
            AR_Drone_Flight_Control_DW.reset_offset_calc,
            AR_Drone_Flight_Control_DW.Offset_Accel_Current);
          AR_Dron_Gyro_Offset_Calculation
            (AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha,
             AR_Drone_Flight_Control_DW.reset_offset_calc,
             AR_Drone_Flight_Control_DW.Offset_Gyro_Current);

          /* Outputs for Function Call SubSystem: '<S39>/Drone_State.WaitForHost.checkMove' */
          /* Abs: '<S43>/Abs' incorporates:
           *  Delay: '<S43>/Delay'
           *  Sum: '<S43>/Sum'
           */
          /* Simulink Function 'checkMove': '<S39>:608' */
          AR_Drone_Flight_Control_B.Abs[0] = fabs
            (AR_Drone_Flight_Control_DW.Delay_DSTATE_i[0] -
             AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0]);
          AR_Drone_Flight_Control_B.Abs[1] = fabs
            (AR_Drone_Flight_Control_DW.Delay_DSTATE_i[1] -
             AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1]);
          AR_Drone_Flight_Control_B.Abs[2] = fabs
            (AR_Drone_Flight_Control_DW.Delay_DSTATE_i[2] -
             AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2]);

          /* RelationalOperator: '<S62>/Compare' incorporates:
           *  Constant: '<S62>/Constant'
           */
          AR_Drone_Flight_Control_B.Compare[0] = (AR_Drone_Flight_Control_B.Abs
            [0] < AR_Drone_Flight_Control_P.CompareToConstant_const_b);
          AR_Drone_Flight_Control_B.Compare[1] = (AR_Drone_Flight_Control_B.Abs
            [1] < AR_Drone_Flight_Control_P.CompareToConstant_const_b);
          AR_Drone_Flight_Control_B.Compare[2] = (AR_Drone_Flight_Control_B.Abs
            [2] < AR_Drone_Flight_Control_P.CompareToConstant_const_b);

          /* Logic: '<S43>/Logical Operator1' incorporates:
           *  Logic: '<S43>/Logical Operator'
           */
          AR_Drone_Flight_Control_B.LogicalOperator1 =
            !(AR_Drone_Flight_Control_B.Compare[0] &&
              AR_Drone_Flight_Control_B.Compare[1] &&
              AR_Drone_Flight_Control_B.Compare[2]);

          /* Update for Delay: '<S43>/Delay' */
          for (AR_Drone_Flight_Control_B.k = 0; AR_Drone_Flight_Control_B.k < 39;
               AR_Drone_Flight_Control_B.k++) {
            AR_Drone_Flight_Control_DW.Delay_DSTATE_i[AR_Drone_Flight_Control_B.k
              * 3] = AR_Drone_Flight_Control_DW.Delay_DSTATE_i
              [(AR_Drone_Flight_Control_B.k + 1) * 3];
            AR_Drone_Flight_Control_DW.Delay_DSTATE_i[AR_Drone_Flight_Control_B.k
              * 3 + 1] = AR_Drone_Flight_Control_DW.Delay_DSTATE_i
              [(AR_Drone_Flight_Control_B.k + 1) * 3 + 1];
            AR_Drone_Flight_Control_DW.Delay_DSTATE_i[AR_Drone_Flight_Control_B.k
              * 3 + 2] = AR_Drone_Flight_Control_DW.Delay_DSTATE_i
              [(AR_Drone_Flight_Control_B.k + 1) * 3 + 2];
          }

          AR_Drone_Flight_Control_DW.Delay_DSTATE_i[117] =
            AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0];
          AR_Drone_Flight_Control_DW.Delay_DSTATE_i[118] =
            AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1];
          AR_Drone_Flight_Control_DW.Delay_DSTATE_i[119] =
            AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2];

          /* End of Update for Delay: '<S43>/Delay' */
          AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckMove = 4;

          /* End of Outputs for SubSystem: '<S39>/Drone_State.WaitForHost.checkMove' */
          AR_Drone_Flight_Control_DW.Move =
            AR_Drone_Flight_Control_B.LogicalOperator1;
        }
        break;

       default:
        /* During 'Wait_For_Flight': '<S39>:633' */
        if (AR_Drone_Flight_Control_B.DataTypeConversion5) {
          /* Transition: '<S39>:636' */
          AR_Drone_Flight_Control_DW.is_WaitForHost =
            AR_IN_Attitude_Convergence_Wait;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Attitude_Convergence_Wait': '<S39>:598' */
          AR_Drone_Flight_Control_DW.initDone = false;
        } else {
          AR_Drone_Flight_Control_DW.initDone = true;
        }
        break;
      }
    }
    break;

   case Drone_StateModeType_Controlled_Flight:
    /* During 'Controlled_Flight': '<S39>:252' */
    if ((AR_Drone_Flight_Control_B.Drone_StateModeConversion ==
         Drone_StateModeType_Landing_Sequence) ||
        (AR_Drone_Flight_Control_B.BatteryFault_Mode ==
         BatteryFault_ModeType_BatteryLow)) {
      /* Transition: '<S39>:270' */
      /* Exit Internal 'Controlled_Flight': '<S39>:252' */
      AR_Drone_Flight_Control_DW.is_Controlled_Flight =
        AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
      AR_Drone_Flight_Control_B.Drone_StateMode =
        Drone_StateModeType_Landing_Sequence;

      /* Entry 'Landing_Sequence': '<S39>:255' */
      if (!(AR_Drone_Flight_Control_B.refHeight <= 40.0)) {
        AR_Drone_Flight_Control_B.refHeight = 40.0;
      }

      AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = false;

      /* Entry Internal 'Landing_Sequence': '<S39>:255' */
      /* Transition: '<S39>:411' */
      AR_Drone_Flight_Control_DW.is_Landing_Sequence =
        AR_Drone_Flight_IN_Climb_down_1;
      AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

      /* Entry 'Climb_down_1': '<S39>:414' */
      AR_Drone_Flight_Control_B.refHeight -= 2.0;
    } else if (AR_Drone_Flight_Control_B.SafeOrientation_Mode ==
               SafeOrientation_ModeType_UnsafeOrientation) {
      /* Transition: '<S39>:534' */
      /* Exit Internal 'Controlled_Flight': '<S39>:252' */
      AR_Drone_Flight_Control_DW.is_Controlled_Flight =
        AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
      AR_Drone_Flight_Control_B.Drone_StateMode =
        Drone_StateModeType_Landing_Terminate;

      /* Entry 'Landing_Terminate': '<S39>:305' */
      AR_Drone_Flight_Control_DW.MotorArmed = 0.0;
      AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
      AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = false;

      /* Catch any last state action we need to do here */
    } else if (AR_Drone_Flight_Control_DW.is_Controlled_Flight ==
               AR_Drone_Flig_IN_Altitude_Climb) {
      /* During 'Altitude_Climb': '<S39>:657' */
      AR_Drone_Flight_Control_DW.Input_ports[0] = 0.0;
      AR_Drone_Flight_Control_DW.Input_ports[1] = 0.0;
      AR_Drone_Flight_Control_B.refHeight =
        AR_Drone_Flight_Control_DW.Output_ports[1];
    } else {
      /* During 'Initialize': '<S39>:654' */
      if (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 200U) {
        /* Transition: '<S39>:659' */
        AR_Drone_Flight_Control_DW.is_Controlled_Flight =
          AR_Drone_Flig_IN_Altitude_Climb;

        /* Entry 'Altitude_Climb': '<S39>:657' */
        AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = true;
      }
    }
    break;

   case Drone_StateModeType_Landing_Sequence:
    /* During 'Landing_Sequence': '<S39>:255' */
    if (((AR_Drone_Flight_Control_B.MotorCmd[0] +
          AR_Drone_Flight_Control_B.MotorCmd[1]) +
         AR_Drone_Flight_Control_B.MotorCmd[2]) +
        AR_Drone_Flight_Control_B.MotorCmd[3] == 0.0) {
      /* Transition: '<S39>:306' */
      /* Exit Internal 'Landing_Sequence': '<S39>:255' */
      AR_Drone_Flight_Control_DW.is_Landing_Sequence =
        AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
      AR_Drone_Flight_Control_B.Drone_StateMode =
        Drone_StateModeType_Landing_Terminate;

      /* Entry 'Landing_Terminate': '<S39>:305' */
      AR_Drone_Flight_Control_DW.MotorArmed = 0.0;
      AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
      AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = false;

      /* Catch any last state action we need to do here */
    } else {
      switch (AR_Drone_Flight_Control_DW.is_Landing_Sequence) {
       case AR_Drone_Flight_IN_Climb_down_1:
        /* During 'Climb_down_1': '<S39>:414' */
        if ((AR_Drone_Flight_Control_B.UltraSound[0] <=
             AR_Drone_Flight_Control_B.refHeight) &&
            (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 20U)) {
          /* Transition: '<S39>:413' */
          AR_Drone_Flight_Control_DW.is_Landing_Sequence =
            AR_Drone_Flight_IN_Climb_down_1;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Climb_down_1': '<S39>:414' */
          AR_Drone_Flight_Control_B.refHeight -= 2.0;
        } else {
          if ((AR_Drone_Flight_Control_B.UltraSound[0] <= 10.0) &&
              (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
            /* Transition: '<S39>:617' */
            AR_Drone_Flight_Control_DW.is_Landing_Sequence =
              AR_Drone_Flight_IN_Climb_down_2;
            AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

            /* Entry 'Climb_down_2': '<S39>:616' */
            AR_Drone_Flight_Control_B.refHeight--;
          }
        }
        break;

       case AR_Drone_Flight_IN_Climb_down_2:
        /* During 'Climb_down_2': '<S39>:616' */
        if ((AR_Drone_Flight_Control_B.UltraSound[0] <=
             AR_Drone_Flight_Control_B.refHeight) &&
            (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
          /* Transition: '<S39>:615' */
          AR_Drone_Flight_Control_DW.is_Landing_Sequence =
            AR_Drone_Flight_IN_Climb_down_2;
          AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

          /* Entry 'Climb_down_2': '<S39>:616' */
          AR_Drone_Flight_Control_B.refHeight--;
        } else {
          if ((AR_Drone_Flight_Control_B.UltraSound[0] <= 0.5) &&
              (AR_Drone_Flight_Control_DW.temporalCounter_i3 >= 40U)) {
            /* Transition: '<S39>:614' */
            AR_Drone_Flight_Control_DW.is_Landing_Sequence =
              AR_Drone_Flight_IN_Climb_down_3;

            /* Entry 'Climb_down_3': '<S39>:417' */
            AR_Drone_Flight_Control_DW.LandingPhase = 1.0;
          }
        }
        break;

       default:
        /* During 'Climb_down_3': '<S39>:417' */
        break;
      }
    }
    break;

   default:
    /* During 'Landing_Terminate': '<S39>:305' */
    if (((AR_Drone_Flight_Control_B.MotorCmd[0] +
          AR_Drone_Flight_Control_B.MotorCmd[1]) +
         AR_Drone_Flight_Control_B.MotorCmd[2]) +
        AR_Drone_Flight_Control_B.MotorCmd[3] == 0.0) {
      /* Transition: '<S39>:303' */
      AR_Drone_Flight_Control_B.Drone_StateMode =
        Drone_StateModeType_WaitForHost;

      /* Entry 'WaitForHost': '<S39>:381' */
      AR_Drone_Flight_Control_DW.reset_offset_calc = 0.0;
      AR_Drone_Flight_Control_DW.MotorArmed = 0.0;
      AR_Drone_Flight_Control_B.refHeight = 0.0;
      AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
      AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = false;

      /* Entry Internal 'WaitForHost': '<S39>:381' */
      /* Transition: '<S39>:597' */
      AR_Drone_Flight_Control_DW.is_WaitForHost =
        AR_IN_Attitude_Convergence_Wait;
      AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

      /* Entry 'Attitude_Convergence_Wait': '<S39>:598' */
      AR_Drone_Flight_Control_DW.initDone = false;
    }
    break;
  }

  if (AR_Drone_Flight_Control_B.guard1) {
    /* Outputs for Function Call SubSystem: '<S39>/Drone_State.WaitForHost.checkConvergence' */
    /* RelationalOperator: '<S61>/Compare' incorporates:
     *  Constant: '<S61>/Constant'
     *  Delay: '<S42>/Delay'
     *  Gain: '<S42>/dt'
     *  Sum: '<S42>/Sum'
     */
    /* Simulink Function 'checkConvergence': '<S39>:588' */
    AR_Drone_Flight_Control_B.Compare_l[0] =
      ((AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[0] -
        AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0]) *
       AR_Drone_Flight_Control_P.dt_Gain <
       AR_Drone_Flight_Control_P.CompareToConstant_const);
    AR_Drone_Flight_Control_B.Compare_l[1] =
      ((AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[1] -
        AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1]) *
       AR_Drone_Flight_Control_P.dt_Gain <
       AR_Drone_Flight_Control_P.CompareToConstant_const);
    AR_Drone_Flight_Control_B.Compare_l[2] =
      ((AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[2] -
        AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2]) *
       AR_Drone_Flight_Control_P.dt_Gain <
       AR_Drone_Flight_Control_P.CompareToConstant_const);

    /* Logic: '<S42>/Logical Operator' */
    AR_Drone_Flight_Control_B.LogicalOperator =
      (AR_Drone_Flight_Control_B.Compare_l[0] &&
       AR_Drone_Flight_Control_B.Compare_l[1] &&
       AR_Drone_Flight_Control_B.Compare_l[2]);

    /* Update for Delay: '<S42>/Delay' */
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[0] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[1] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[2] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2];
    AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckConv = 4;

    /* End of Outputs for SubSystem: '<S39>/Drone_State.WaitForHost.checkConvergence' */
    AR_Drone_Flight_Control_DW.Converge_Flag =
      AR_Drone_Flight_Control_B.LogicalOperator;
  }
}

/* Model step function for TID0 */
void AR_Drone_Flight_Control_step0(void) /* Sample time: [0.0025s, 0.0s] */
{
  char_T *sErr;
  char_T *sErr_0;

  {                                    /* Sample time: [0.0025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.AxisRotZeroR3.AxisRotZeroR3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.AxisRotDefault.AxisRotDefault_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_k);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Generalcase_m.Generalcase_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckConv);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckMove);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_n);

  /* DataStoreRead: '<S5>/Data Store Read3' */
  AR_Drone_Flight_Control_B.Testsifdataequals1 =
    AR_Drone_Flight_Control_DW.Flight_Mission_On_Off;

  /* ModelReference: '<S5>/Flight Mission' */
  AR_Drone_Mission_Height(&AR_Drone_Flight_Control_B.Testsifdataequals1,
    &AR_Drone_Flight_Control_B.AutoCalibration_ON_OFF,
    &AR_Drone_Flight_Control_B.Altitude_ON_OFF,
    &AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[0],
    &AR_Drone_Flight_Control_B.FlightMission_o4,
    &AR_Drone_Flight_Control_B.FlightMission_o5,
    &(AR_Drone_Flight_Control_DW.FlightMission_DWORK1.rtdw));

  /* DataStoreRead: '<S5>/Data Store Read1' */
  AR_Drone_Flight_Control_B.Testsifdataequals1 =
    AR_Drone_Flight_Control_DW.Flight_Mission_On_Off;

  /* Switch: '<S5>/Switch' */
  if (AR_Drone_Flight_Control_B.Testsifdataequals1) {
    /* DataStoreWrite: '<S5>/Data Store Write' incorporates:
     *  Constant: '<S5>/Constant'
     */
    AR_Drone_Flight_Control_DW.Output_ports[0] =
      AR_Drone_Flight_Control_P.Constant_Value;
  } else {
    /* DataStoreWrite: '<S5>/Data Store Write' */
    AR_Drone_Flight_Control_DW.Output_ports[0] = 0.0;
  }

  if (AR_Drone_Flight_Control_B.Testsifdataequals1) {
    /* DataStoreWrite: '<S5>/Data Store Write' */
    AR_Drone_Flight_Control_DW.Output_ports[1] =
      AR_Drone_Flight_Control_B.FlightMission_o4;
  } else {
    /* DataStoreWrite: '<S5>/Data Store Write' */
    AR_Drone_Flight_Control_DW.Output_ports[1] = 0.0;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S66>/ 5' incorporates:
   *  DataStoreRead: '<S66>/Data Store Read3'
   */
  AR_Drone_Flight_Control_B.Sum1_c = (int16_T)
    AR_Drone_Flight_Control_DW.Desired_Drone_StateMode;

  /* DataTypeConversion: '<S5>/ 7' */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_B.FlightMission_o5);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  AR_Drone_Flight_Control_B.Switch1_g = (int16_T)
    (AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(int16_T)(uint16_T)
     AR_Drone_Flight_Control_B.Delay_o);

  /* End of DataTypeConversion: '<S5>/ 7' */

  /* RelationalOperator: '<S65>/Tests if data equals -1' incorporates:
   *  Constant: '<S65>/Constant1'
   */
  AR_Drone_Flight_Control_B.Testsifdataequals1 =
    (AR_Drone_Flight_Control_P.Constant1_Value_c ==
     AR_Drone_Flight_Control_B.Switch1_g);

  /* Logic: '<S65>/Logical Operator3' incorporates:
   *  Constant: '<S67>/Constant'
   *  DataStoreRead: '<S65>/Data Store Read1'
   *  RelationalOperator: '<S65>/Tests if Desired_Drone_StateMode is Contrelled_Flight'
   */
  AR_Drone_Flight_Control_B.LogicalOperator3 =
    ((AR_Drone_Flight_Control_P.Constant_Value_b ==
      AR_Drone_Flight_Control_DW.Desired_Drone_StateMode) &&
     AR_Drone_Flight_Control_B.Testsifdataequals1);

  /* RelationalOperator: '<S65>/Tests if data equals +1' incorporates:
   *  Constant: '<S65>/Constant2'
   */
  AR_Drone_Flight_Control_B.Testsifdataequals1 =
    (AR_Drone_Flight_Control_B.Switch1_g ==
     AR_Drone_Flight_Control_P.Constant2_Value_e);

  /* Switch: '<S65>/Switch1' incorporates:
   *  Constant: '<S65>/Change Desired Drone_StateMode'
   *  Constant: '<S65>/Don't change Desired Drone_StateMode'
   *  Constant: '<S68>/Constant'
   *  DataStoreRead: '<S65>/Data Store Read3'
   *  Logic: '<S65>/Logical Operator'
   *  Logic: '<S65>/Logical Operator2'
   *  RelationalOperator: '<S65>/Tests if Desired_Drone_StateMode is Landing_Sequence'
   */
  if (AR_Drone_Flight_Control_B.LogicalOperator3 ||
      (AR_Drone_Flight_Control_B.Testsifdataequals1 &&
       (AR_Drone_Flight_Control_P.Constant_Value_a4 ==
        AR_Drone_Flight_Control_DW.Desired_Drone_StateMode))) {
    AR_Drone_Flight_Control_B.Switch1_g =
      AR_Drone_Flight_Control_P.ChangeDesiredDrone_StateMode_Va;
  } else {
    AR_Drone_Flight_Control_B.Switch1_g =
      AR_Drone_Flight_Control_P.DontchangeDesiredDrone_StateMod;
  }

  /* End of Switch: '<S65>/Switch1' */

  /* S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */
  sErr = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
  AR_Drone_Flight_Control_B.samplesRead = 1;
  LibOutputs_Network(&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib
                     [0U], &AR_Drone_Flight_Control_B.HostCommandport7000_o1,
                     &AR_Drone_Flight_Control_B.samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  AR_Drone_Flight_Control_B.HostCommandport7000_o2 = (uint16_T)
    AR_Drone_Flight_Control_B.samplesRead;
  if (AR_Drone_Flight_Control_B.samplesRead == 0) {
    AR_Drone_Flight_Control_B.HostCommandport7000_o1 = 0.0;
  }

  /* End of S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */

  /* DataTypeConversion: '<S2>/ 1' */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_B.HostCommandport7000_o1);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki = (int16_T)
    (AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(int16_T)(uint16_T)
     AR_Drone_Flight_Control_B.Delay_o);

  /* End of DataTypeConversion: '<S2>/ 1' */

  /* ManualSwitch: '<Root>/Do not touch once this Simulink is running' */
  if (AR_Drone_Flight_Control_P.DonottouchoncethisSimulinkisrun != 1) {
    /* ManualSwitch: '<S1>/Switch to change the current Drone State (it has to be down at the start)' incorporates:
     *  DataTypeConversion: '<S1>/ 1'
     */
    if (AR_Drone_Flight_Control_P.SwitchtochangethecurrentDroneSt == 1) {
      /* DataTypeConversion: '<S1>/ 1' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      AR_Drone_Flight_Control_B.Delay_o = floor
        (AR_Drone_Flight_Control_P.Constant2_Value_b);
      if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
          (AR_Drone_Flight_Control_B.Delay_o)) {
        AR_Drone_Flight_Control_B.Delay_o = 0.0;
      } else {
        AR_Drone_Flight_Control_B.Delay_o = fmod
          (AR_Drone_Flight_Control_B.Delay_o, 65536.0);
      }

      AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki = (int16_T)
        (AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(int16_T)-(int16_T)
         (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(int16_T)
         (uint16_T)AR_Drone_Flight_Control_B.Delay_o);
    } else {
      /* DataTypeConversion: '<S1>/ 1' incorporates:
       *  Constant: '<S1>/Constant3'
       */
      AR_Drone_Flight_Control_B.Delay_o = floor
        (AR_Drone_Flight_Control_P.Constant3_Value);
      if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
          (AR_Drone_Flight_Control_B.Delay_o)) {
        AR_Drone_Flight_Control_B.Delay_o = 0.0;
      } else {
        AR_Drone_Flight_Control_B.Delay_o = fmod
          (AR_Drone_Flight_Control_B.Delay_o, 65536.0);
      }

      AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki = (int16_T)
        (AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(int16_T)-(int16_T)
         (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(int16_T)
         (uint16_T)AR_Drone_Flight_Control_B.Delay_o);
    }

    /* End of ManualSwitch: '<S1>/Switch to change the current Drone State (it has to be down at the start)' */
  }

  /* End of ManualSwitch: '<Root>/Do not touch once this Simulink is running' */

  /* RelationalOperator: '<S69>/Tests if data equals -1' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  AR_Drone_Flight_Control_B.Testsifdataequals1 =
    (AR_Drone_Flight_Control_P.Constant1_Value_m ==
     AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki);

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S69>/Constant2'
   *  Logic: '<S69>/Logical Operator'
   *  Memory: '<S69>/Memory'
   *  RelationalOperator: '<S69>/Tests if data equals +1'
   */
  if (AR_Drone_Flight_Control_B.Testsifdataequals1 ||
      (AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki ==
       AR_Drone_Flight_Control_P.Constant2_Value_gk)) {
    AR_Drone_Flight_Control_B.Switch1 =
      AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki;
  } else {
    AR_Drone_Flight_Control_B.Switch1 =
      AR_Drone_Flight_Control_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<S69>/Switch1' */

  /* Sum: '<S66>/Sum4' incorporates:
   *  Gain: '<S66>/Host Command > Mission Command'
   *  Memory: '<S66>/Memory'
   *  Sum: '<S66>/Sum'
   */
  AR_Drone_Flight_Control_B.Abs_k = (int16_T)(AR_Drone_Flight_Control_B.Switch1
    - AR_Drone_Flight_Control_DW.Memory_PreviousInput_i) *
    AR_Drone_Flight_Control_P.HostCommandMissionCommand_Gain +
    (AR_Drone_Flight_Control_B.Switch1_g << 13);

  /* Abs: '<S66>/Abs' */
  if (AR_Drone_Flight_Control_B.Abs_k < 0) {
    AR_Drone_Flight_Control_B.Abs_k = -AR_Drone_Flight_Control_B.Abs_k;
  }

  /* End of Abs: '<S66>/Abs' */

  /* Sum: '<S66>/Sum2' incorporates:
   *  DataTypeConversion: '<S66>/ 2'
   *  DataTypeConversion: '<S66>/ 4'
   */
  AR_Drone_Flight_Control_B.Sum1_c += ((int16_T)(AR_Drone_Flight_Control_B.Abs_k
    >> 13) != 0);

  /* Math: '<S66>/Math Function' incorporates:
   *  Constant: '<S66>/Constant'
   */
  if (AR_Drone_Flight_Control_P.Constant_Value_ps != 0) {
    AR_Drone_Flight_Control_B.Sum1_c -= (int16_T)(div_s16s32_floor
      (AR_Drone_Flight_Control_B.Sum1_c,
       AR_Drone_Flight_Control_P.Constant_Value_ps) *
      AR_Drone_Flight_Control_P.Constant_Value_ps);
  }

  /* End of Math: '<S66>/Math Function' */

  /* Sum: '<S66>/Sum1' incorporates:
   *  Constant: '<S66>/Constant'
   */
  AR_Drone_Flight_Control_B.Sum1_c +=
    AR_Drone_Flight_Control_P.Constant_Value_ps;

  /* DataStoreWrite: '<S66>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S66>/Drone_State-Mode Conversion'
   */
  AR_Drone_Flight_Control_DW.Desired_Drone_StateMode = (Drone_StateModeType)
    AR_Drone_Flight_Control_B.Sum1_c;

  /* DataStoreRead: '<S5>/Data Store Read2' */
  AR_Drone_Flight_Control_B.Desired_Drone_StateMode =
    AR_Drone_Flight_Control_DW.Desired_Drone_StateMode;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtAttitude View1Inport2' */
  AR_Drone_Flight_Control_B.TmpSignalConversionAtAttitudeVi[0] = 0.0;
  AR_Drone_Flight_Control_B.TmpSignalConversionAtAttitudeVi[1] = 0.0;
  AR_Drone_Flight_Control_B.TmpSignalConversionAtAttitudeVi[2] = 0.0;

  /* S-Function (IMU_Sfcn_mex): '<S6>/IMU Read' */
  MDL_IMU_step( &AR_Drone_Flight_Control_B.IMURead_o1,
               &AR_Drone_Flight_Control_B.IMURead_o2);

  /* Outputs for Atomic SubSystem: '<S8>/CheckSum Pre-Processing' */
  /* Delay: '<S79>/Delay' */
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[0];
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[1];
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[2];

  /* Logic: '<S79>/Logical Operator1' incorporates:
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S80>/Compare'
   */
  AR_Drone_Flight_Control_B.LogicalOperator1_b =
    !(AR_Drone_Flight_Control_B.IMURead_o2 >
      AR_Drone_Flight_Control_P.Constant_Value_oh);

  /* Logic: '<S83>/Logical Operator' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S83>/Constant1'
   *  RelationalOperator: '<S83>/Relational Operator'
   *  RelationalOperator: '<S83>/Relational Operator1'
   *  UnitDelay: '<S83>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Transition_Detect =
    ((AR_Drone_Flight_Control_P.Constant1_Value ==
      AR_Drone_Flight_Control_B.LogicalOperator1_b) &&
     (AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_p ==
      AR_Drone_Flight_Control_P.Constant_Value_g));

  /* Constant: '<S70>/Holding Value' */
  AR_Drone_Flight_Control_B.HoldingValue =
    AR_Drone_Flight_Control_P.HoldingValue_Value;

  /* Chart: '<S81>/Chart' */
  AR_Drone_Flight_Contr_Chart(AR_Drone_Flight_Control_B.Transition_Detect,
    AR_Drone_Flight_Control_B.HoldingValue, &AR_Drone_Flight_Control_B.sf_Chart,
    &AR_Drone_Flight_Control_DW.sf_Chart);

  /* Switch: '<S79>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' incorporates:
   *  Constant: '<S81>/Constant2'
   *  Logic: '<S79>/Invert Logic'
   *  Logic: '<S81>/Logical Operator1'
   */
  if (!((AR_Drone_Flight_Control_P.Constant2_Value != 0.0) &&
        (AR_Drone_Flight_Control_B.sf_Chart.output != 0.0))) {
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 =
      AR_Drone_Flight_Control_B.IMURead_o1.ax;
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 =
      AR_Drone_Flight_Control_B.IMURead_o1.ay;
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 =
      AR_Drone_Flight_Control_B.IMURead_o1.az;
  }

  /* End of Switch: '<S79>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */

  /* Delay: '<S84>/Delay' */
  AR_Drone_Flight_Control_B.Sum1_c = AR_Drone_Flight_Control_DW.Delay_DSTATE_h[0];
  AR_Drone_Flight_Control_B.Switch1_g =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_h[1];
  AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_h[2];

  /* Logic: '<S84>/Logical Operator1' incorporates:
   *  Constant: '<S86>/Constant'
   *  RelationalOperator: '<S86>/Compare'
   */
  AR_Drone_Flight_Control_B.LogicalOperator1_f =
    !(AR_Drone_Flight_Control_B.IMURead_o2 >
      AR_Drone_Flight_Control_P.Constant_Value_l);

  /* Logic: '<S89>/Logical Operator' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S89>/Constant1'
   *  RelationalOperator: '<S89>/Relational Operator'
   *  RelationalOperator: '<S89>/Relational Operator1'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Transition_Detect_d =
    ((AR_Drone_Flight_Control_P.Constant1_Value_o ==
      AR_Drone_Flight_Control_B.LogicalOperator1_f) &&
     (AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_f ==
      AR_Drone_Flight_Control_P.Constant_Value_a));

  /* Chart: '<S87>/Chart' */
  AR_Drone_Flight_Contr_Chart(AR_Drone_Flight_Control_B.Transition_Detect_d,
    AR_Drone_Flight_Control_B.HoldingValue,
    &AR_Drone_Flight_Control_B.sf_Chart_c,
    &AR_Drone_Flight_Control_DW.sf_Chart_c);

  /* Switch: '<S84>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' incorporates:
   *  Constant: '<S87>/Constant2'
   *  Logic: '<S84>/Invert Logic'
   *  Logic: '<S87>/Logical Operator1'
   */
  if (!((AR_Drone_Flight_Control_P.Constant2_Value_j != 0.0) &&
        (AR_Drone_Flight_Control_B.sf_Chart_c.output != 0.0))) {
    AR_Drone_Flight_Control_B.Sum1_c = AR_Drone_Flight_Control_B.IMURead_o1.mx;
    AR_Drone_Flight_Control_B.Switch1_g =
      AR_Drone_Flight_Control_B.IMURead_o1.my;
    AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki =
      AR_Drone_Flight_Control_B.IMURead_o1.mz;
  }

  /* End of Switch: '<S84>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */

  /* Delay: '<S90>/Delay' */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE[0];
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE[1];
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 =
    AR_Drone_Flight_Control_DW.Delay_DSTATE[2];

  /* Logic: '<S90>/Logical Operator1' incorporates:
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S92>/Compare'
   */
  AR_Drone_Flight_Control_B.LogicalOperator1_i =
    !(AR_Drone_Flight_Control_B.IMURead_o2 >
      AR_Drone_Flight_Control_P.Constant_Value_o4);

  /* Logic: '<S95>/Logical Operator' incorporates:
   *  Constant: '<S95>/Constant'
   *  Constant: '<S95>/Constant1'
   *  RelationalOperator: '<S95>/Relational Operator'
   *  RelationalOperator: '<S95>/Relational Operator1'
   *  UnitDelay: '<S95>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Transition_Detect_b =
    ((AR_Drone_Flight_Control_P.Constant1_Value_i ==
      AR_Drone_Flight_Control_B.LogicalOperator1_i) &&
     (AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_j ==
      AR_Drone_Flight_Control_P.Constant_Value_h));

  /* Chart: '<S93>/Chart' */
  AR_Drone_Flight_Contr_Chart(AR_Drone_Flight_Control_B.Transition_Detect_b,
    AR_Drone_Flight_Control_B.HoldingValue,
    &AR_Drone_Flight_Control_B.sf_Chart_k,
    &AR_Drone_Flight_Control_DW.sf_Chart_k);

  /* Switch: '<S90>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' incorporates:
   *  Constant: '<S93>/Constant2'
   *  Logic: '<S90>/Invert Logic'
   *  Logic: '<S93>/Logical Operator1'
   */
  if (!((AR_Drone_Flight_Control_P.Constant2_Value_a != 0.0) &&
        (AR_Drone_Flight_Control_B.sf_Chart_k.output != 0.0))) {
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0] =
      AR_Drone_Flight_Control_B.IMURead_o1.vx;
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1] =
      AR_Drone_Flight_Control_B.IMURead_o1.vy;
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2] =
      AR_Drone_Flight_Control_B.IMURead_o1.vz;
  } else {
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0] =
      AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0;
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1] =
      AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1;
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2] =
      AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2;
  }

  /* End of Switch: '<S90>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */

  /* Delay: '<S96>/Delay' */
  AR_Drone_Flight_Control_B.Delay_k = AR_Drone_Flight_Control_DW.Delay_DSTATE_l
    [0];

  /* Logic: '<S96>/Logical Operator1' incorporates:
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S98>/Compare'
   */
  AR_Drone_Flight_Control_B.LogicalOperator3 =
    !(AR_Drone_Flight_Control_B.IMURead_o2 >
      AR_Drone_Flight_Control_P.Constant_Value_a1);

  /* Logic: '<S101>/Logical Operator' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S101>/Constant1'
   *  RelationalOperator: '<S101>/Relational Operator'
   *  RelationalOperator: '<S101>/Relational Operator1'
   *  UnitDelay: '<S101>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Transition_Detect_l =
    ((AR_Drone_Flight_Control_P.Constant1_Value_k ==
      AR_Drone_Flight_Control_B.LogicalOperator3) &&
     (AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_kb ==
      AR_Drone_Flight_Control_P.Constant_Value_e));

  /* Chart: '<S99>/Chart' */
  AR_Drone_Flight_Contr_Chart(AR_Drone_Flight_Control_B.Transition_Detect_l,
    AR_Drone_Flight_Control_B.HoldingValue,
    &AR_Drone_Flight_Control_B.sf_Chart_m,
    &AR_Drone_Flight_Control_DW.sf_Chart_m);

  /* Switch: '<S96>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Logic: '<S96>/Invert Logic'
   *  Logic: '<S99>/Logical Operator1'
   */
  if (!((AR_Drone_Flight_Control_P.Constant2_Value_g != 0.0) &&
        (AR_Drone_Flight_Control_B.sf_Chart_m.output != 0.0))) {
    AR_Drone_Flight_Control_B.Delay_k =
      AR_Drone_Flight_Control_B.IMURead_o1.temperature_gyro;
  }

  /* End of Switch: '<S96>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */

  /* Delay: '<S102>/Delay' */
  AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_DW.Delay_DSTATE_a
    [0];

  /* Logic: '<S102>/Logical Operator1' incorporates:
   *  Constant: '<S104>/Constant'
   *  RelationalOperator: '<S104>/Compare'
   */
  AR_Drone_Flight_Control_B.LogicalOperator1_j =
    !(AR_Drone_Flight_Control_B.IMURead_o2 >
      AR_Drone_Flight_Control_P.Constant_Value_ad);

  /* Logic: '<S107>/Logical Operator' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S107>/Constant1'
   *  RelationalOperator: '<S107>/Relational Operator'
   *  RelationalOperator: '<S107>/Relational Operator1'
   *  UnitDelay: '<S107>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Transition_Detect_lb =
    ((AR_Drone_Flight_Control_P.Constant1_Value_a ==
      AR_Drone_Flight_Control_B.LogicalOperator1_j) &&
     (AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_e ==
      AR_Drone_Flight_Control_P.Constant_Value_c));

  /* Chart: '<S105>/Chart' */
  AR_Drone_Flight_Contr_Chart(AR_Drone_Flight_Control_B.Transition_Detect_lb,
    AR_Drone_Flight_Control_B.HoldingValue,
    &AR_Drone_Flight_Control_B.sf_Chart_ci,
    &AR_Drone_Flight_Control_DW.sf_Chart_ci);

  /* MATLAB Function: '<S77>/Height Calculation' incorporates:
   *  DataTypeConversion: '<S77>/Data Type Conversion1'
   *  Delay: '<S77>/Delay1'
   */
  /* MATLAB Function 'Navigation/CheckSum Pre-Processing/Ultrasound Processing/Height Calculation': '<S103>:1' */
  if (AR_Drone_Flight_Control_B.IMURead_o1.ultrasound < 10000) {
    /* '<S103>:1:6' */
    /* '<S103>:1:8' */
    AR_Drone_Flight_Control_B.height = ((real_T)
      AR_Drone_Flight_Control_B.IMURead_o1.ultrasound - 880.0) / 26.553;

    /* Update for Delay: '<S77>/Delay1' */
    /* '<S103>:1:9' */
    AR_Drone_Flight_Control_DW.Delay1_DSTATE = AR_Drone_Flight_Control_B.height;
  } else {
    /*      height = u; */
    /*      prev_good_height = height; */
    /* '<S103>:1:14' */
    AR_Drone_Flight_Control_B.height = AR_Drone_Flight_Control_DW.Delay1_DSTATE;

    /* '<S103>:1:15' */
  }

  /* Switch: '<S102>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' incorporates:
   *  Constant: '<S105>/Constant2'
   *  Logic: '<S102>/Invert Logic'
   *  Logic: '<S105>/Logical Operator1'
   *  MATLAB Function: '<S77>/Height Calculation'
   */
  /* '<S103>:1:18' */
  if (!((AR_Drone_Flight_Control_P.Constant2_Value_n != 0.0) &&
        (AR_Drone_Flight_Control_B.sf_Chart_ci.output != 0.0))) {
    AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_B.height;
  }

  /* End of Switch: '<S102>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */

  /* Update for Delay: '<S79>/Delay' */
  for (AR_Drone_Flight_Control_B.Abs_k = 0; AR_Drone_Flight_Control_B.Abs_k < 2;
       AR_Drone_Flight_Control_B.Abs_k++) {
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[AR_Drone_Flight_Control_B.Abs_k *
      3] = AR_Drone_Flight_Control_DW.Delay_DSTATE_f
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[AR_Drone_Flight_Control_B.Abs_k *
      3 + 1] = AR_Drone_Flight_Control_DW.Delay_DSTATE_f
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 1];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_f[AR_Drone_Flight_Control_B.Abs_k *
      3 + 2] = AR_Drone_Flight_Control_DW.Delay_DSTATE_f
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 2];
  }

  AR_Drone_Flight_Control_DW.Delay_DSTATE_f[6] =
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0;
  AR_Drone_Flight_Control_DW.Delay_DSTATE_f[7] =
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1;
  AR_Drone_Flight_Control_DW.Delay_DSTATE_f[8] =
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2;

  /* End of Update for Delay: '<S79>/Delay' */

  /* Update for UnitDelay: '<S83>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_p =
    AR_Drone_Flight_Control_B.LogicalOperator1_b;

  /* Update for Delay: '<S84>/Delay' */
  for (AR_Drone_Flight_Control_B.Abs_k = 0; AR_Drone_Flight_Control_B.Abs_k < 2;
       AR_Drone_Flight_Control_B.Abs_k++) {
    AR_Drone_Flight_Control_DW.Delay_DSTATE_h[AR_Drone_Flight_Control_B.Abs_k *
      3] = AR_Drone_Flight_Control_DW.Delay_DSTATE_h
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_h[AR_Drone_Flight_Control_B.Abs_k *
      3 + 1] = AR_Drone_Flight_Control_DW.Delay_DSTATE_h
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 1];
    AR_Drone_Flight_Control_DW.Delay_DSTATE_h[AR_Drone_Flight_Control_B.Abs_k *
      3 + 2] = AR_Drone_Flight_Control_DW.Delay_DSTATE_h
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 2];
  }

  AR_Drone_Flight_Control_DW.Delay_DSTATE_h[6] =
    AR_Drone_Flight_Control_B.Sum1_c;
  AR_Drone_Flight_Control_DW.Delay_DSTATE_h[7] =
    AR_Drone_Flight_Control_B.Switch1_g;
  AR_Drone_Flight_Control_DW.Delay_DSTATE_h[8] =
    AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki;

  /* End of Update for Delay: '<S84>/Delay' */

  /* Update for UnitDelay: '<S89>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_f =
    AR_Drone_Flight_Control_B.LogicalOperator1_f;

  /* Update for Delay: '<S90>/Delay' */
  for (AR_Drone_Flight_Control_B.Abs_k = 0; AR_Drone_Flight_Control_B.Abs_k < 2;
       AR_Drone_Flight_Control_B.Abs_k++) {
    AR_Drone_Flight_Control_DW.Delay_DSTATE[AR_Drone_Flight_Control_B.Abs_k * 3]
      = AR_Drone_Flight_Control_DW.Delay_DSTATE[(AR_Drone_Flight_Control_B.Abs_k
      + 1) * 3];
    AR_Drone_Flight_Control_DW.Delay_DSTATE[AR_Drone_Flight_Control_B.Abs_k * 3
      + 1] = AR_Drone_Flight_Control_DW.Delay_DSTATE
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 1];
    AR_Drone_Flight_Control_DW.Delay_DSTATE[AR_Drone_Flight_Control_B.Abs_k * 3
      + 2] = AR_Drone_Flight_Control_DW.Delay_DSTATE
      [(AR_Drone_Flight_Control_B.Abs_k + 1) * 3 + 2];
  }

  AR_Drone_Flight_Control_DW.Delay_DSTATE[6] =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0];
  AR_Drone_Flight_Control_DW.Delay_DSTATE[7] =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1];
  AR_Drone_Flight_Control_DW.Delay_DSTATE[8] =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2];

  /* End of Update for Delay: '<S90>/Delay' */

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_j =
    AR_Drone_Flight_Control_B.LogicalOperator1_i;

  /* Update for Delay: '<S96>/Delay' */
  AR_Drone_Flight_Control_DW.Delay_DSTATE_l[0] =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_l[1];
  AR_Drone_Flight_Control_DW.Delay_DSTATE_l[1] =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_l[2];
  AR_Drone_Flight_Control_DW.Delay_DSTATE_l[2] =
    AR_Drone_Flight_Control_B.Delay_k;

  /* Update for UnitDelay: '<S101>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_kb =
    AR_Drone_Flight_Control_B.LogicalOperator3;

  /* Update for Delay: '<S102>/Delay' */
  AR_Drone_Flight_Control_DW.Delay_DSTATE_a[0] =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_a[1];
  AR_Drone_Flight_Control_DW.Delay_DSTATE_a[1] =
    AR_Drone_Flight_Control_DW.Delay_DSTATE_a[2];
  AR_Drone_Flight_Control_DW.Delay_DSTATE_a[2] =
    AR_Drone_Flight_Control_B.Delay_o;

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_e =
    AR_Drone_Flight_Control_B.LogicalOperator1_j;

  /* End of Outputs for SubSystem: '<S8>/CheckSum Pre-Processing' */

  /* Gain: '<S111>/Gain' incorporates:
   *  Constant: '<S111>/Bias'
   *  Constant: '<S111>/Neutral Bias'
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   *  Gain: '<S111>/Gain1'
   *  Gain: '<S111>/Gain2'
   *  Gain: '<S111>/Gain3'
   *  Sum: '<S111>/Sum'
   *  Sum: '<S111>/Sum1'
   *  Sum: '<S111>/Sum2'
   *  Sum: '<S111>/Sum3'
   */
  AR_Drone_Flight_Control_B.Gain[0] = (((real_T)
    AR_Drone_Flight_Control_P.Gain1_Gain_g * 3.0517578125E-5 * (real_T)(int16_T)
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 +
    AR_Drone_Flight_Control_P.Bias_Value) -
    AR_Drone_Flight_Control_P.NeutralBias_Value[0]) *
    AR_Drone_Flight_Control_P.Gain_Gain_a;
  AR_Drone_Flight_Control_B.Gain[1] = (((real_T)
    AR_Drone_Flight_Control_P.Gain2_Gain_kk * 3.0517578125E-5 * (real_T)(int16_T)
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 +
    AR_Drone_Flight_Control_P.Bias_Value) -
    AR_Drone_Flight_Control_P.NeutralBias_Value[1]) *
    AR_Drone_Flight_Control_P.Gain_Gain_a;
  AR_Drone_Flight_Control_B.Gain[2] = (((real_T)
    AR_Drone_Flight_Control_P.Gain3_Gain_o * 3.0517578125E-5 * (real_T)(int16_T)
    AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 +
    AR_Drone_Flight_Control_P.Bias_Value) -
    AR_Drone_Flight_Control_P.NeutralBias_Value[2]) *
    AR_Drone_Flight_Control_P.Gain_Gain_a;

  /* Product: '<S112>/Multiply' incorporates:
   *  Constant: '<S112>/Accel_Calib_Gain'
   *  Constant: '<S112>/Accel_Calib_Offset'
   *  Gain: '<S112>/Gain'
   *  Sum: '<S112>/Sum'
   */
  AR_Drone_Flight_Control_B.Multiply[0] = (AR_Drone_Flight_Control_B.Gain[0] -
    Accelerometer_360deg_calibration.Offsets[0]) /
    (AR_Drone_Flight_Control_P.Gain_Gain_n *
     Accelerometer_360deg_calibration.Gains[0]);
  AR_Drone_Flight_Control_B.Multiply[1] = (AR_Drone_Flight_Control_B.Gain[1] -
    Accelerometer_360deg_calibration.Offsets[1]) /
    (AR_Drone_Flight_Control_P.Gain_Gain_n *
     Accelerometer_360deg_calibration.Gains[1]);
  AR_Drone_Flight_Control_B.Multiply[2] = (AR_Drone_Flight_Control_B.Gain[2] -
    Accelerometer_360deg_calibration.Offsets[2]) /
    (AR_Drone_Flight_Control_P.Gain_Gain_n *
     Accelerometer_360deg_calibration.Gains[2]);

  /* Sum: '<S113>/Sum' incorporates:
   *  Constant: '<S113>/X when horizontal'
   *  DataStoreRead: '<S71>/Data Store Read2'
   *  Gain: '<S113>/Gain'
   *  Sum: '<S113>/Sum5'
   */
  AR_Drone_Flight_Control_B.Sum = AR_Drone_Flight_Control_B.Multiply[0] -
    (AR_Drone_Flight_Control_P.Gain_Gain_p *
     AR_Drone_Flight_Control_DW.Offset_Accel[0] -
     AR_Drone_Flight_Control_P.Xwhenhorizontal_Value);

  /* Sum: '<S113>/Sum1' incorporates:
   *  Constant: '<S113>/Y when horizontal'
   *  DataStoreRead: '<S71>/Data Store Read2'
   *  Gain: '<S113>/Gain1'
   *  Sum: '<S113>/Sum4'
   */
  AR_Drone_Flight_Control_B.Sum1 = AR_Drone_Flight_Control_B.Multiply[1] -
    (AR_Drone_Flight_Control_P.Gain1_Gain_a *
     AR_Drone_Flight_Control_DW.Offset_Accel[1] -
     AR_Drone_Flight_Control_P.Ywhenhorizontal_Value);

  /* Sum: '<S113>/Sum2' incorporates:
   *  Constant: '<S113>/Z when horizontal'
   *  DataStoreRead: '<S71>/Data Store Read2'
   *  Gain: '<S113>/Gain2'
   *  Sum: '<S113>/Sum3'
   */
  AR_Drone_Flight_Control_B.Sum2 = AR_Drone_Flight_Control_B.Multiply[2] -
    (AR_Drone_Flight_Control_P.Gain2_Gain_g *
     AR_Drone_Flight_Control_DW.Offset_Accel[2] -
     AR_Drone_Flight_Control_P.Zwhenhorizontal_Value);

  /* Sum: '<S114>/Add' incorporates:
   *  Gain: '<S114>/Gain'
   *  Gain: '<S114>/Gain1'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  AR_Drone_Flight_Control_B.Add[0] = AR_Drone_Flight_Control_P.Gain1_Gain_b *
    AR_Drone_Flight_Control_B.Sum + AR_Drone_Flight_Control_P.Gain_Gain_i *
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[0];
  AR_Drone_Flight_Control_B.Add[1] = AR_Drone_Flight_Control_P.Gain1_Gain_b *
    AR_Drone_Flight_Control_B.Sum1 + AR_Drone_Flight_Control_P.Gain_Gain_i *
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[1];
  AR_Drone_Flight_Control_B.Add[2] = AR_Drone_Flight_Control_P.Gain1_Gain_b *
    AR_Drone_Flight_Control_B.Sum2 + AR_Drone_Flight_Control_P.Gain_Gain_i *
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[2];

  /* Sum: '<S115>/Sum of Elements' incorporates:
   *  Math: '<S115>/Math Function'
   */
  AR_Drone_Flight_Control_B.height = (AR_Drone_Flight_Control_B.Add[0] *
    AR_Drone_Flight_Control_B.Add[0] + AR_Drone_Flight_Control_B.Add[1] *
    AR_Drone_Flight_Control_B.Add[1]) + AR_Drone_Flight_Control_B.Add[2] *
    AR_Drone_Flight_Control_B.Add[2];

  /* Math: '<S115>/Math Function1'
   *
   * About '<S115>/Math Function1':
   *  Operator: sqrt
   */
  if (AR_Drone_Flight_Control_B.height < 0.0) {
    AR_Drone_Flight_Control_B.height = -sqrt(fabs
      (AR_Drone_Flight_Control_B.height));
  } else {
    AR_Drone_Flight_Control_B.height = sqrt(AR_Drone_Flight_Control_B.height);
  }

  /* End of Math: '<S115>/Math Function1' */

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Product: '<S115>/Product'
   */
  if (AR_Drone_Flight_Control_B.height >
      AR_Drone_Flight_Control_P.NormalizeVector_maxzero) {
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 = AR_Drone_Flight_Control_B.Add[0];
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 = AR_Drone_Flight_Control_B.Add[1];
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 = AR_Drone_Flight_Control_B.Add[2];
  } else {
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 = AR_Drone_Flight_Control_B.Add[0]
      * 0.0;
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 = AR_Drone_Flight_Control_B.Add[1]
      * 0.0;
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 = AR_Drone_Flight_Control_B.Add[2]
      * 0.0;
    AR_Drone_Flight_Control_B.height =
      AR_Drone_Flight_Control_P.Constant_Value_o;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Product: '<S115>/Divide' */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 /
    AR_Drone_Flight_Control_B.height;
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 /
    AR_Drone_Flight_Control_B.height;
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 /
    AR_Drone_Flight_Control_B.height;

  /* Sum: '<S110>/Sum' incorporates:
   *  DataStoreRead: '<S71>/Data Store Read1'
   */
  AR_Drone_Flight_Control_B.Sum_m =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0] -
    AR_Drone_Flight_Control_DW.Offset_Gyro[0];

  /* Sum: '<S110>/Sum1' incorporates:
   *  DataStoreRead: '<S71>/Data Store Read1'
   */
  AR_Drone_Flight_Control_B.Sum1_p =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1] -
    AR_Drone_Flight_Control_DW.Offset_Gyro[1];

  /* Sum: '<S110>/Sum2' incorporates:
   *  DataStoreRead: '<S71>/Data Store Read1'
   */
  AR_Drone_Flight_Control_B.Sum2_f =
    AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2] -
    AR_Drone_Flight_Control_DW.Offset_Gyro[2];

  /* Product: '<S118>/Divide' incorporates:
   *  Constant: '<S118>/Constant'
   *  Constant: '<S118>/Constant1'
   *  Sum: '<S118>/Sum'
   */
  AR_Drone_Flight_Control_B.rtb_Divide_idx_0 = 1.0 /
    Magnetometer_calibration.Gains[0] * ((real_T)
    AR_Drone_Flight_Control_B.Sum1_c - Magnetometer_calibration.Offsets[0]);
  AR_Drone_Flight_Control_B.rtb_Divide_idx_1 = 1.0 /
    Magnetometer_calibration.Gains[1] * ((real_T)
    AR_Drone_Flight_Control_B.Switch1_g - Magnetometer_calibration.Offsets[1]);
  AR_Drone_Flight_Control_B.rtb_Divide_idx_2 = 1.0 /
    Magnetometer_calibration.Gains[2] * ((real_T)
    AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki -
    Magnetometer_calibration.Offsets[2]);

  /* Sum: '<S116>/Sum of Elements' incorporates:
   *  Math: '<S116>/Math Function'
   */
  AR_Drone_Flight_Control_B.height = (AR_Drone_Flight_Control_B.rtb_Divide_idx_0
    * AR_Drone_Flight_Control_B.rtb_Divide_idx_0 +
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1) +
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2;

  /* Math: '<S116>/Math Function1'
   *
   * About '<S116>/Math Function1':
   *  Operator: sqrt
   */
  if (AR_Drone_Flight_Control_B.height < 0.0) {
    AR_Drone_Flight_Control_B.height = -sqrt(fabs
      (AR_Drone_Flight_Control_B.height));
  } else {
    AR_Drone_Flight_Control_B.height = sqrt(AR_Drone_Flight_Control_B.height);
  }

  /* End of Math: '<S116>/Math Function1' */

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S116>/Constant'
   *  Product: '<S116>/Product'
   */
  if (!(AR_Drone_Flight_Control_B.height >
        AR_Drone_Flight_Control_P.NormalizeVector_maxzero_a)) {
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 *= 0.0;
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 *= 0.0;
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 *= 0.0;
    AR_Drone_Flight_Control_B.height =
      AR_Drone_Flight_Control_P.Constant_Value_f;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Outputs for Atomic SubSystem: '<S8>/CheckSum Pre-Processing' */
  /* Saturate: '<S77>/Saturation1' */
  if (AR_Drone_Flight_Control_B.Delay_o >
      AR_Drone_Flight_Control_P.Saturation1_UpperSat) {
    /* BusCreator: '<S8>/BusConversion_InsertedFor_Kalman Filter State Estimation_at_inport_0' */
    AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.UltraSound_Calculation
      = AR_Drone_Flight_Control_P.Saturation1_UpperSat;
  } else if (AR_Drone_Flight_Control_B.Delay_o <
             AR_Drone_Flight_Control_P.Saturation1_LowerSat) {
    /* BusCreator: '<S8>/BusConversion_InsertedFor_Kalman Filter State Estimation_at_inport_0' */
    AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.UltraSound_Calculation
      = AR_Drone_Flight_Control_P.Saturation1_LowerSat;
  } else {
    /* BusCreator: '<S8>/BusConversion_InsertedFor_Kalman Filter State Estimation_at_inport_0' */
    AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.UltraSound_Calculation
      = AR_Drone_Flight_Control_B.Delay_o;
  }

  /* End of Saturate: '<S77>/Saturation1' */
  /* End of Outputs for SubSystem: '<S8>/CheckSum Pre-Processing' */

  /* BusCreator: '<S8>/BusConversion_InsertedFor_Kalman Filter State Estimation_at_inport_0' incorporates:
   *  Gain: '<S121>/Gain'
   *  Product: '<S116>/Divide'
   */
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.AccelNorm_Calculation[0]
    = AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.AccelNorm_Calculation[1]
    = AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.AccelNorm_Calculation[2]
    = AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Gyro_Calculation[0] =
    AR_Drone_Flight_Control_P.Gain_Gain_i4[0] * AR_Drone_Flight_Control_B.Sum_m;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Gyro_Calculation[1] =
    AR_Drone_Flight_Control_P.Gain_Gain_i4[1] * AR_Drone_Flight_Control_B.Sum1_p;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Gyro_Calculation[2] =
    AR_Drone_Flight_Control_P.Gain_Gain_i4[2] * AR_Drone_Flight_Control_B.Sum2_f;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Magnetometer_Calculation[
    0] = AR_Drone_Flight_Control_B.rtb_Divide_idx_0 /
    AR_Drone_Flight_Control_B.height;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Magnetometer_Calculation[
    1] = AR_Drone_Flight_Control_B.rtb_Divide_idx_1 /
    AR_Drone_Flight_Control_B.height;
  AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K.Magnetometer_Calculation[
    2] = AR_Drone_Flight_Control_B.rtb_Divide_idx_2 /
    AR_Drone_Flight_Control_B.height;

  /* UnitDelay: '<S8>/Unit Delay' */
  AR_Drone_Flight_Control_B.UnitDelay_h =
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_k;

  /* ModelReference: '<S8>/Kalman Filter State Estimation' */
  Navigation_KF_Subsystem_child
    (&AR_Drone_Flight_Control_B.BusConversion_InsertedFor_K,
     &AR_Drone_Flight_Control_B.UltraSound[0],
     &AR_Drone_Flight_Control_B.EulerAngles[0],
     &AR_Drone_Flight_Control_B.ProcessedGyro[0],
     &AR_Drone_Flight_Control_B.AccelNorm[0],
     &AR_Drone_Flight_Control_B.VRML_Visuals[0], &AR_Drone_Flight_Control_B.DCM
     [0], &(AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO.rtb),
     &(AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO.rtdw));

  /* Reshape: '<S3>/Reshape' */
  AR_Drone_Flight_Control_B.Reshape[0] = AR_Drone_Flight_Control_B.UltraSound[0];
  AR_Drone_Flight_Control_B.Reshape[1] = AR_Drone_Flight_Control_B.UltraSound[1];
  for (AR_Drone_Flight_Control_B.Abs_k = 0; AR_Drone_Flight_Control_B.Abs_k < 7;
       AR_Drone_Flight_Control_B.Abs_k++) {
    AR_Drone_Flight_Control_B.Reshape[AR_Drone_Flight_Control_B.Abs_k + 2] =
      AR_Drone_Flight_Control_B.VRML_Visuals[AR_Drone_Flight_Control_B.Abs_k];
  }

  /* End of Reshape: '<S3>/Reshape' */

  /* Gain: '<S22>/Gain1' incorporates:
   *  Selector: '<S22>/Selector1'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate[0] =
    AR_Drone_Flight_Control_P.Gain1_Gain_d[0] *
    AR_Drone_Flight_Control_B.Reshape[5];
  AR_Drone_Flight_Control_B.VectorConcatenate[1] =
    AR_Drone_Flight_Control_P.Gain1_Gain_d[1] *
    AR_Drone_Flight_Control_B.Reshape[8];
  AR_Drone_Flight_Control_B.VectorConcatenate[2] =
    AR_Drone_Flight_Control_P.Gain1_Gain_d[2] *
    AR_Drone_Flight_Control_B.Reshape[2];

  /* Gain: '<S22>/Gain2' incorporates:
   *  Selector: '<S22>/Selector2'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate[3] =
    AR_Drone_Flight_Control_P.Gain2_Gain_k[0] *
    AR_Drone_Flight_Control_B.Reshape[1];
  AR_Drone_Flight_Control_B.VectorConcatenate[4] =
    AR_Drone_Flight_Control_P.Gain2_Gain_k[1] *
    AR_Drone_Flight_Control_B.Reshape[0];

  /* Gain: '<S22>/Gain3' incorporates:
   *  Selector: '<S22>/Selector3'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate[5] =
    AR_Drone_Flight_Control_P.Gain3_Gain_m[0] *
    AR_Drone_Flight_Control_B.Reshape[7];
  AR_Drone_Flight_Control_B.VectorConcatenate[6] =
    AR_Drone_Flight_Control_P.Gain3_Gain_m[1] *
    AR_Drone_Flight_Control_B.Reshape[4];

  /* If: '<S10>/If' */
  if ((AR_Drone_Flight_Control_B.VectorConcatenate[2] >= 1.0) ||
      (AR_Drone_Flight_Control_B.VectorConcatenate[2] <= -1.0)) {
    /* Outputs for IfAction SubSystem: '<S10>/AxisRotZeroR3' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    AR_Drone_Flig_AxisRotZeroR3(AR_Drone_Flight_Control_B.VectorConcatenate,
      &AR_Drone_Flight_Control_B.Merge_m[0], &AR_Drone_Flight_Control_B.Merge_m
      [1], &AR_Drone_Flight_Control_B.Merge_m[2]);

    /* End of Outputs for SubSystem: '<S10>/AxisRotZeroR3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/AxisRotDefault' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    AR_Drone_Fli_AxisRotDefault(AR_Drone_Flight_Control_B.VectorConcatenate,
      &AR_Drone_Flight_Control_B.Merge_m[0], &AR_Drone_Flight_Control_B.Merge_m
      [1], &AR_Drone_Flight_Control_B.Merge_m[2]);

    /* End of Outputs for SubSystem: '<S10>/AxisRotDefault' */
  }

  /* End of If: '<S10>/If' */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtsincosInport1' incorporates:
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 =
    AR_Drone_Flight_Control_P.Gain_Gain_ai * AR_Drone_Flight_Control_B.Merge_m[2];
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 =
    AR_Drone_Flight_Control_P.Gain1_Gain_l * AR_Drone_Flight_Control_B.Merge_m[0];

  /* Trigonometry: '<S16>/sincos' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtsincosInport1'
   */
  AR_Drone_Flight_Control_B.Delay_o = cos
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 = sin
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0);
  AR_Drone_Flight_Control_B.height = cos
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 = sin
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1);
  AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 = sin
    (AR_Drone_Flight_Control_B.Merge_m[1]);
  AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 = cos
    (AR_Drone_Flight_Control_B.Merge_m[1]);

  /* Fcn: '<S16>/Fcn11' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[0] =
    AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S16>/Fcn21' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[1] =
    -AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S16>/Fcn31' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[2] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1;

  /* Fcn: '<S16>/Fcn12' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[3] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S16>/Fcn22' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[4] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S16>/Fcn32' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[5] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.height;

  /* Fcn: '<S16>/Fcn13' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[6] =
    -AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S16>/Fcn23' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[7] =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S16>/Fcn33' */
  AR_Drone_Flight_Control_B.VectorConcatenate_p[8] =
    AR_Drone_Flight_Control_B.Delay_o * AR_Drone_Flight_Control_B.height;

  /* MATLAB Function: '<S9>/Matrix Re-Order' */
  AR_Drone_Flig_MatrixReOrder(AR_Drone_Flight_Control_B.VectorConcatenate_p,
    &AR_Drone_Flight_Control_B.sf_MatrixReOrder);

  /* Trigonometry: '<S17>/sincos' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 = sin
    (AR_Drone_Flight_Control_P.Constant2_Value_m[0]);
  AR_Drone_Flight_Control_B.Delay_o = cos
    (AR_Drone_Flight_Control_P.Constant2_Value_m[0]);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 = sin
    (AR_Drone_Flight_Control_P.Constant2_Value_m[1]);
  AR_Drone_Flight_Control_B.height = cos
    (AR_Drone_Flight_Control_P.Constant2_Value_m[1]);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 = sin
    (AR_Drone_Flight_Control_P.Constant2_Value_m[2]);
  AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 = cos
    (AR_Drone_Flight_Control_P.Constant2_Value_m[2]);

  /* Fcn: '<S17>/Fcn11' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[0] =
    AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S17>/Fcn21' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[1] =
    -AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2;

  /* Fcn: '<S17>/Fcn31' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[2] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1;

  /* Fcn: '<S17>/Fcn12' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[3] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2;

  /* Fcn: '<S17>/Fcn22' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[4] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S17>/Fcn32' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[5] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.height;

  /* Fcn: '<S17>/Fcn13' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[6] =
    -AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2;

  /* Fcn: '<S17>/Fcn23' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[7] =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S17>/Fcn33' */
  AR_Drone_Flight_Control_B.VectorConcatenate_k[8] =
    AR_Drone_Flight_Control_B.Delay_o * AR_Drone_Flight_Control_B.height;

  /* Product: '<S9>/Product' incorporates:
   *  Math: '<S9>/Math Function1'
   */
  for (AR_Drone_Flight_Control_B.Abs_k = 0; AR_Drone_Flight_Control_B.Abs_k < 3;
       AR_Drone_Flight_Control_B.Abs_k++) {
    for (AR_Drone_Flight_Control_B.i0 = 0; AR_Drone_Flight_Control_B.i0 < 3;
         AR_Drone_Flight_Control_B.i0++) {
      AR_Drone_Flight_Control_B.Product[AR_Drone_Flight_Control_B.Abs_k + 3 *
        AR_Drone_Flight_Control_B.i0] = 0.0;
      AR_Drone_Flight_Control_B.Product[AR_Drone_Flight_Control_B.Abs_k + 3 *
        AR_Drone_Flight_Control_B.i0] +=
        AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[3 *
        AR_Drone_Flight_Control_B.Abs_k] *
        AR_Drone_Flight_Control_B.VectorConcatenate_k[3 *
        AR_Drone_Flight_Control_B.i0];
      AR_Drone_Flight_Control_B.Product[AR_Drone_Flight_Control_B.Abs_k + 3 *
        AR_Drone_Flight_Control_B.i0] +=
        AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[3 *
        AR_Drone_Flight_Control_B.Abs_k + 1] *
        AR_Drone_Flight_Control_B.VectorConcatenate_k[3 *
        AR_Drone_Flight_Control_B.i0 + 1];
      AR_Drone_Flight_Control_B.Product[AR_Drone_Flight_Control_B.Abs_k + 3 *
        AR_Drone_Flight_Control_B.i0] +=
        AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[3 *
        AR_Drone_Flight_Control_B.Abs_k + 2] *
        AR_Drone_Flight_Control_B.VectorConcatenate_k[3 *
        AR_Drone_Flight_Control_B.i0 + 2];
    }
  }

  /* End of Product: '<S9>/Product' */

  /* Sum: '<S19>/Sum of Elements3' */
  AR_Drone_Flight_Control_B.SumofElements3 = (AR_Drone_Flight_Control_B.Product
    [0] + AR_Drone_Flight_Control_B.Product[4]) +
    AR_Drone_Flight_Control_B.Product[8];

  /* If: '<S19>/If' incorporates:
   *  Abs: '<S19>/Abs'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S35>/Trace=3=>Phi=0'
   *  Sum: '<S19>/Sum'
   */
  if (AR_Drone_Flight_Control_B.SumofElements3 +
      AR_Drone_Flight_Control_P.Constant_Value_j[0] >= 3.0) {
    /* Outputs for IfAction SubSystem: '<S19>/Phi == 0' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    AR_Drone_Flight_Control_B.Merge[0] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_d[0];
    AR_Drone_Flight_Control_B.Merge[1] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_d[1];
    AR_Drone_Flight_Control_B.Merge[2] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_d[2];
    AR_Drone_Flight_Control_B.Merge[3] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_d[3];

    /* End of Outputs for SubSystem: '<S19>/Phi == 0' */

    /* Update for IfAction SubSystem: '<S19>/Phi == 0' incorporates:
     *  Update for ActionPort: '<S35>/Action Port'
     */
    /* Update for If: '<S19>/If' incorporates:
     *  Constant: '<S35>/Trace=3=>Phi=0'
     */
    srUpdateBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC);

    /* End of Update for SubSystem: '<S19>/Phi == 0' */
  } else if (fabs(AR_Drone_Flight_Control_B.SumofElements3 +
                  AR_Drone_Flight_Control_P.Constant_Value_j[1]) <= 1.0E-12) {
    /* Outputs for IfAction SubSystem: '<S19>/Phi == pi' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    AR_Drone_Flight_Contr_Phipi(AR_Drone_Flight_Control_B.Product,
      &AR_Drone_Flight_Control_B.Merge[0], &AR_Drone_Flight_Control_B.Merge[3],
                                (P_Phipi_AR_Drone_Flight_Contr_T *)
      &AR_Drone_Flight_Control_P.Phipi,
      AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation2_m);

    /* End of Outputs for SubSystem: '<S19>/Phi == pi' */
  } else {
    /* Outputs for IfAction SubSystem: '<S19>/General case' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    AR_Drone_Flight_Generalcase(AR_Drone_Flight_Control_B.SumofElements3,
      AR_Drone_Flight_Control_B.Product, &AR_Drone_Flight_Control_B.Merge[0],
      &AR_Drone_Flight_Control_B.Merge[3], (P_Generalcase_AR_Drone_Flight_T *)
      &AR_Drone_Flight_Control_P.Generalcase);

    /* End of Outputs for SubSystem: '<S19>/General case' */
  }

  /* End of If: '<S19>/If' */

  /* S-Function (Battery_Sfcn_mex): '<S8>/Battery Voltage Measurement' */
  BatteryMeasure_step( &AR_Drone_Flight_Control_B.BatteryVoltageMeasurement);

  /* Gain: '<S8>/Deci-Volts to Volts' */
  AR_Drone_Flight_Control_B.DeciVoltstoVolts =
    AR_Drone_Flight_Control_P.DeciVoltstoVolts_Gain *
    AR_Drone_Flight_Control_B.BatteryVoltageMeasurement;

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   *  DataTypeConversion: '<S8>/Data Type Conversion5'
   */
  if (AR_Drone_Flight_Control_M->Timing.RateInteraction.TID0_1) {
    AR_Drone_Flight_Control_B.RateTransition[0] =
      AR_Drone_Flight_Control_B.Sum1_c;
    AR_Drone_Flight_Control_B.RateTransition[1] =
      AR_Drone_Flight_Control_B.Switch1_g;
    AR_Drone_Flight_Control_B.RateTransition[2] =
      AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki;
    AR_Drone_Flight_Control_B.RateTransition[3] =
      AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0;
    AR_Drone_Flight_Control_B.RateTransition[4] =
      AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1;
    AR_Drone_Flight_Control_B.RateTransition[5] =
      AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2;
    AR_Drone_Flight_Control_B.RateTransition[6] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[0];
    AR_Drone_Flight_Control_B.RateTransition[7] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[1];
    AR_Drone_Flight_Control_B.RateTransition[8] =
      AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha[2];
    AR_Drone_Flight_Control_B.RateTransition[9] =
      AR_Drone_Flight_Control_B.Delay_k;
    AR_Drone_Flight_Control_B.RateTransition[10] =
      AR_Drone_Flight_Control_B.EulerAngles[0];
    AR_Drone_Flight_Control_B.RateTransition[11] =
      AR_Drone_Flight_Control_B.EulerAngles[1];
    AR_Drone_Flight_Control_B.RateTransition[12] =
      AR_Drone_Flight_Control_B.EulerAngles[2];
    AR_Drone_Flight_Control_B.RateTransition[13] =
      AR_Drone_Flight_Control_B.UltraSound[0];
    AR_Drone_Flight_Control_B.RateTransition[14] =
      AR_Drone_Flight_Control_B.UltraSound[1];
    memcpy(&AR_Drone_Flight_Control_B.RateTransition[15],
           &AR_Drone_Flight_Control_B.VRML_Visuals[0], 9U * sizeof(real_T));
    memcpy(&AR_Drone_Flight_Control_B.RateTransition[24],
           &AR_Drone_Flight_Control_B.DCM[0], 9U * sizeof(real_T));
    AR_Drone_Flight_Control_B.RateTransition[33] =
      AR_Drone_Flight_Control_B.DeciVoltstoVolts;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* DataTypeConversion: '<S4>/Drone_State-Mode Conversion' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   */
  AR_Drone_Flight_Control_B.Drone_StateModeConversion = (Drone_StateModeType)
    (int16_T)AR_Drone_Flight_Control_B.Desired_Drone_StateMode;

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  AR_Drone_Flight_Control_B.DataTypeConversion5 =
    (AR_Drone_Flight_Control_B.AutoCalibration_ON_OFF != 0.0);

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_B.Altitude_ON_OFF);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  AR_Drone_Flight_Control_B.DataTypeConversion4 = (int16_T)
    (AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(int16_T)(uint16_T)
     AR_Drone_Flight_Control_B.Delay_o);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion4' */

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  Constant: '<S4>/Nominal Thrust'
   */
  AR_Drone_Flight_Control_B.DataTypeConversion3 =
    AR_Drone_Flight_Control_P.NominalThrust_Value;

  /* DiscreteTransferFcn: '<S4>/FilterBattVoltage' */
  AR_Drone_Flight_Control_B.FilterBattVoltage =
    AR_Drone_Flight_Control_P.FilterBattVoltage_NumCoef *
    AR_Drone_Flight_Control_DW.FilterBattVoltage_states;

  /* Chart: '<S4>/Supervisory Flight Controller' */
  if (AR_Drone_Flight_Control_DW.temporalCounter_i1 < 2047U) {
    AR_Drone_Flight_Control_DW.temporalCounter_i1++;
  }

  if (AR_Drone_Flight_Control_DW.temporalCounter_i2 < 7U) {
    AR_Drone_Flight_Control_DW.temporalCounter_i2++;
  }

  if (AR_Drone_Flight_Control_DW.temporalCounter_i3 < 2047U) {
    AR_Drone_Flight_Control_DW.temporalCounter_i3++;
  }

  /* Gateway: Flight Controller/Supervisory Flight Controller */
  AR_Drone_Flight_Control_DW.sfEvent = AR_Drone_Flight_Co_CALL_EVENT_j;

  /* During: Flight Controller/Supervisory Flight Controller */
  if (AR_Drone_Flight_Control_DW.is_active_c12_AR_Drone_Flight_C == 0U) {
    /* Entry: Flight Controller/Supervisory Flight Controller */
    AR_Drone_Flight_Control_DW.is_active_c12_AR_Drone_Flight_C = 1U;

    /* Entry Internal: Flight Controller/Supervisory Flight Controller */
    AR_Drone_Flight_Control_DW.is_active_Drone_State = 1U;

    /* Entry Internal 'Drone_State': '<S39>:272' */
    /* Transition: '<S39>:249' */
    AR_Drone_Flight_Control_B.Drone_StateMode = Drone_StateModeType_WaitForHost;

    /* Entry 'WaitForHost': '<S39>:381' */
    AR_Drone_Flight_Control_DW.reset_offset_calc = 0.0;
    AR_Drone_Flight_Control_DW.MotorArmed = 0.0;
    AR_Drone_Flight_Control_B.refHeight = 0.0;
    AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
    AR_Drone_Flight_Control_DW.Flight_Mission_On_Off = false;

    /* Entry Internal 'WaitForHost': '<S39>:381' */
    /* Transition: '<S39>:597' */
    AR_Drone_Flight_Control_DW.is_WaitForHost = AR_IN_Attitude_Convergence_Wait;
    AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;

    /* Entry 'Attitude_Convergence_Wait': '<S39>:598' */
    AR_Drone_Flight_Control_DW.initDone = false;
    AR_Drone_Flight_Control_DW.is_active_Flight_Controls = 1U;

    /* Entry Internal 'Flight_Controls': '<S39>:273' */
    AR_Drone_Flight_Control_DW.is_active_Attitude_Command = 1U;

    /* Entry 'Attitude_Command': '<S39>:291' */
    /* Simulink Function 'Attitude_Control': '<S39>:283' */
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[0] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[0];
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[1] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[1];
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[2] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[2];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[0] =
      AR_Drone_Flight_Control_B.EulerAngles[0];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[1] =
      AR_Drone_Flight_Control_B.EulerAngles[1];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[2] =
      AR_Drone_Flight_Control_B.EulerAngles[2];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[0] =
      AR_Drone_Flight_Control_B.ProcessedGyro[0];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[1] =
      AR_Drone_Flight_Control_B.ProcessedGyro[1];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[2] =
      AR_Drone_Flight_Control_B.ProcessedGyro[2];
    AR_Drone_Flight_Control_B.Motor_Armed =
      AR_Drone_Flight_Control_DW.MotorArmed;

    /* Outputs for Function Call SubSystem: '<S39>/Attitude_Control' */
    AR_Drone_F_Attitude_Control(AR_Drone_Flight_Control_M,
      AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg,
      AR_Drone_Flight_Control_B.Desired_Attitude_Deg,
      AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg,
      AR_Drone_Flight_Control_B.Motor_Armed,
      &AR_Drone_Flight_Control_B.Attitude_Control,
      &AR_Drone_Flight_Control_DW.Attitude_Control,
      (P_Attitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Attitude_Control);

    /* End of Outputs for SubSystem: '<S39>/Attitude_Control' */
    AR_Drone_Flight_Control_DW.Attitude_Thrust[0] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[0];
    AR_Drone_Flight_Control_DW.Attitude_Thrust[1] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[1];
    AR_Drone_Flight_Control_DW.Attitude_Thrust[2] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[2];
    AR_Drone_Flight_Control_DW.is_active_Altitude_Command = 1U;

    /* Entry 'Altitude_Command': '<S39>:292' */
    /* Simulink Function 'Altitude_Control': '<S39>:287' */
    AR_Drone_Flight_Control_B.HeightFeedback[0] =
      AR_Drone_Flight_Control_B.UltraSound[0];
    AR_Drone_Flight_Control_B.HeightFeedback[1] =
      AR_Drone_Flight_Control_B.UltraSound[1];
    AR_Drone_Flight_Control_B.refHeight_d = AR_Drone_Flight_Control_B.refHeight;

    /* Outputs for Function Call SubSystem: '<S39>/Altitude_Control' */
    AR_Drone_F_Altitude_Control(AR_Drone_Flight_Control_M,
      AR_Drone_Flight_Control_B.HeightFeedback,
      AR_Drone_Flight_Control_B.refHeight_d,
      &AR_Drone_Flight_Control_B.Altitude_Control,
      &AR_Drone_Flight_Control_DW.Altitude_Control,
      (P_Altitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Altitude_Control);

    /* End of Outputs for SubSystem: '<S39>/Altitude_Control' */
    AR_Drone_Flight_Control_DW.Altitude_Thrust =
      AR_Drone_Flight_Control_B.Altitude_Control.DataTypeConversion1;
    AR_Drone_Flight_Control_DW.is_active_MotorMixing_Command = 1U;

    /* Entry 'MotorMixing_Command': '<S39>:293' */
    AR_Drone_Flight_Control_B.Abs_k =
      AR_Drone_Flight_Control_B.DataTypeConversion4 *
      AR_Drone_Flight_Control_DW.Altitude_Thrust;
    if (AR_Drone_Flight_Control_B.Abs_k > 32767) {
      AR_Drone_Flight_Control_B.Abs_k = 32767;
    } else {
      if (AR_Drone_Flight_Control_B.Abs_k < -32768) {
        AR_Drone_Flight_Control_B.Abs_k = -32768;
      }
    }

    AR_Drone_Flight_Control_B.Abs_k +=
      AR_Drone_Flight_Control_B.DataTypeConversion3;
    if (AR_Drone_Flight_Control_B.Abs_k > 32767) {
      AR_Drone_Flight_Control_B.Abs_k = 32767;
    } else {
      if (AR_Drone_Flight_Control_B.Abs_k < -32768) {
        AR_Drone_Flight_Control_B.Abs_k = -32768;
      }
    }

    AR_Drone_Flight_Control_DW.throttle = (int16_T)
      AR_Drone_Flight_Control_B.Abs_k;

    /* Simulink Function 'Motor_Mixing': '<S39>:277' */
    AR_Drone_Flight_Control_B.throttle = AR_Drone_Flight_Control_DW.throttle;
    AR_Drone_Flight_Control_B.RPYCmd[0] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[0];
    AR_Drone_Flight_Control_B.RPYCmd[1] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[1];
    AR_Drone_Flight_Control_B.RPYCmd[2] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[2];
    AR_Drone_Flight_Control_B.LandingPhase =
      AR_Drone_Flight_Control_DW.LandingPhase;
    AR_Drone_Flight_Control_B.Motor_Armed_d =
      AR_Drone_Flight_Control_DW.MotorArmed;

    /* Outputs for Function Call SubSystem: '<S39>/Motor_Mixing' */
    AR_Drone_Fligh_Motor_Mixing(AR_Drone_Flight_Control_B.LandingPhase,
      AR_Drone_Flight_Control_B.Motor_Armed_d,
      AR_Drone_Flight_Control_B.throttle, AR_Drone_Flight_Control_B.RPYCmd,
      &AR_Drone_Flight_Control_B.Motor_Mixing,
      &AR_Drone_Flight_Control_DW.Motor_Mixing, (P_Motor_Mixing_AR_Drone_Fligh_T
      *)&AR_Drone_Flight_Control_P.Motor_Mixing);

    /* End of Outputs for SubSystem: '<S39>/Motor_Mixing' */
    AR_Drone_Flight_Control_B.MotorCmd[0] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[0];
    AR_Drone_Flight_Control_B.MotorCmd[1] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[1];
    AR_Drone_Flight_Control_B.MotorCmd[2] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[2];
    AR_Drone_Flight_Control_B.MotorCmd[3] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[3];
    AR_Drone_Flight_Control_DW.is_active_Fault_Check = 1U;

    /* Entry Internal 'Fault_Check': '<S39>:443' */
    AR_Drone_Flight_Control_DW.is_active_BatteryFault_Check = 1U;

    /* Entry Internal 'BatteryFault_Check': '<S39>:453' */
    /* Transition: '<S39>:487' */
    AR_Drone_Flight_Control_B.BatteryFault_Mode =
      BatteryFault_ModeType_BatteryNominal;

    /* Entry 'BatteryNominal': '<S39>:467' */
    AR_Drone_Flight_Control_DW.BatteryFault = 0.0;

    /* Entry Internal 'BatteryNominal': '<S39>:467' */
    /* Transition: '<S39>:488' */
    AR_Drone_Flight_Control_DW.is_BatteryNominal =
      AR_Dron_IN_EvaluateVoltageLevel;
    AR_Drone_Flight_Control_DW.temporalCounter_i1 = 0U;
    AR_Drone_Flight_Control_DW.is_active_UltraSoundwarning_Che = 1U;
    AR_Drone_Flight_Control_DW.is_active_SafeOrientation_Check = 1U;

    /* Entry Internal 'SafeOrientation_Check': '<S39>:548' */
    /* Transition: '<S39>:547' */
    AR_Drone_Flight_Control_B.SafeOrientation_Mode =
      SafeOrientation_ModeType_WaitForFlight;
  } else {
    AR_Drone_Flight_Con_Drone_State();

    /* During 'Flight_Controls': '<S39>:273' */
    /* During 'Attitude_Command': '<S39>:291' */
    /* Simulink Function 'Attitude_Control': '<S39>:283' */
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[0] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[0];
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[1] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[1];
    AR_Drone_Flight_Control_B.Desired_Attitude_Deg[2] =
      AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[2];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[0] =
      AR_Drone_Flight_Control_B.EulerAngles[0];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[1] =
      AR_Drone_Flight_Control_B.EulerAngles[1];
    AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg[2] =
      AR_Drone_Flight_Control_B.EulerAngles[2];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[0] =
      AR_Drone_Flight_Control_B.ProcessedGyro[0];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[1] =
      AR_Drone_Flight_Control_B.ProcessedGyro[1];
    AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg[2] =
      AR_Drone_Flight_Control_B.ProcessedGyro[2];
    AR_Drone_Flight_Control_B.Motor_Armed =
      AR_Drone_Flight_Control_DW.MotorArmed;

    /* Outputs for Function Call SubSystem: '<S39>/Attitude_Control' */
    AR_Drone_F_Attitude_Control(AR_Drone_Flight_Control_M,
      AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg,
      AR_Drone_Flight_Control_B.Desired_Attitude_Deg,
      AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg,
      AR_Drone_Flight_Control_B.Motor_Armed,
      &AR_Drone_Flight_Control_B.Attitude_Control,
      &AR_Drone_Flight_Control_DW.Attitude_Control,
      (P_Attitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Attitude_Control);

    /* End of Outputs for SubSystem: '<S39>/Attitude_Control' */
    AR_Drone_Flight_Control_DW.Attitude_Thrust[0] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[0];
    AR_Drone_Flight_Control_DW.Attitude_Thrust[1] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[1];
    AR_Drone_Flight_Control_DW.Attitude_Thrust[2] =
      AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1[2];

    /* During 'Altitude_Command': '<S39>:292' */
    /* Simulink Function 'Altitude_Control': '<S39>:287' */
    AR_Drone_Flight_Control_B.HeightFeedback[0] =
      AR_Drone_Flight_Control_B.UltraSound[0];
    AR_Drone_Flight_Control_B.HeightFeedback[1] =
      AR_Drone_Flight_Control_B.UltraSound[1];
    AR_Drone_Flight_Control_B.refHeight_d = AR_Drone_Flight_Control_B.refHeight;

    /* Outputs for Function Call SubSystem: '<S39>/Altitude_Control' */
    AR_Drone_F_Altitude_Control(AR_Drone_Flight_Control_M,
      AR_Drone_Flight_Control_B.HeightFeedback,
      AR_Drone_Flight_Control_B.refHeight_d,
      &AR_Drone_Flight_Control_B.Altitude_Control,
      &AR_Drone_Flight_Control_DW.Altitude_Control,
      (P_Altitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Altitude_Control);

    /* End of Outputs for SubSystem: '<S39>/Altitude_Control' */
    AR_Drone_Flight_Control_DW.Altitude_Thrust =
      AR_Drone_Flight_Control_B.Altitude_Control.DataTypeConversion1;

    /* During 'MotorMixing_Command': '<S39>:293' */
    AR_Drone_Flight_Control_B.Abs_k =
      AR_Drone_Flight_Control_B.DataTypeConversion4 *
      AR_Drone_Flight_Control_DW.Altitude_Thrust;
    if (AR_Drone_Flight_Control_B.Abs_k > 32767) {
      AR_Drone_Flight_Control_B.Abs_k = 32767;
    } else {
      if (AR_Drone_Flight_Control_B.Abs_k < -32768) {
        AR_Drone_Flight_Control_B.Abs_k = -32768;
      }
    }

    AR_Drone_Flight_Control_B.Abs_k +=
      AR_Drone_Flight_Control_B.DataTypeConversion3;
    if (AR_Drone_Flight_Control_B.Abs_k > 32767) {
      AR_Drone_Flight_Control_B.Abs_k = 32767;
    } else {
      if (AR_Drone_Flight_Control_B.Abs_k < -32768) {
        AR_Drone_Flight_Control_B.Abs_k = -32768;
      }
    }

    AR_Drone_Flight_Control_DW.throttle = (int16_T)
      AR_Drone_Flight_Control_B.Abs_k;

    /* Simulink Function 'Motor_Mixing': '<S39>:277' */
    AR_Drone_Flight_Control_B.throttle = AR_Drone_Flight_Control_DW.throttle;
    AR_Drone_Flight_Control_B.RPYCmd[0] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[0];
    AR_Drone_Flight_Control_B.RPYCmd[1] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[1];
    AR_Drone_Flight_Control_B.RPYCmd[2] =
      AR_Drone_Flight_Control_DW.Attitude_Thrust[2];
    AR_Drone_Flight_Control_B.LandingPhase =
      AR_Drone_Flight_Control_DW.LandingPhase;
    AR_Drone_Flight_Control_B.Motor_Armed_d =
      AR_Drone_Flight_Control_DW.MotorArmed;

    /* Outputs for Function Call SubSystem: '<S39>/Motor_Mixing' */
    AR_Drone_Fligh_Motor_Mixing(AR_Drone_Flight_Control_B.LandingPhase,
      AR_Drone_Flight_Control_B.Motor_Armed_d,
      AR_Drone_Flight_Control_B.throttle, AR_Drone_Flight_Control_B.RPYCmd,
      &AR_Drone_Flight_Control_B.Motor_Mixing,
      &AR_Drone_Flight_Control_DW.Motor_Mixing, (P_Motor_Mixing_AR_Drone_Fligh_T
      *)&AR_Drone_Flight_Control_P.Motor_Mixing);

    /* End of Outputs for SubSystem: '<S39>/Motor_Mixing' */
    AR_Drone_Flight_Control_B.MotorCmd[0] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[0];
    AR_Drone_Flight_Control_B.MotorCmd[1] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[1];
    AR_Drone_Flight_Control_B.MotorCmd[2] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[2];
    AR_Drone_Flight_Control_B.MotorCmd[3] =
      AR_Drone_Flight_Control_B.Motor_Mixing.Switch[3];

    /* During 'Fault_Check': '<S39>:443' */
    /* During 'BatteryFault_Check': '<S39>:453' */
    if (AR_Drone_Flight_Control_B.BatteryFault_Mode ==
        BatteryFault_ModeType_BatteryNominal) {
      /* During 'BatteryNominal': '<S39>:467' */
      if (AR_Drone_Flight_Control_DW.BatteryFault == 1.0) {
        /* Transition: '<S39>:469' */
        /* Exit Internal 'BatteryNominal': '<S39>:467' */
        AR_Drone_Flight_Control_DW.is_BatteryNominal =
          AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
        AR_Drone_Flight_Control_B.BatteryFault_Mode =
          BatteryFault_ModeType_BatteryLow;

        /* Entry Internal 'BatteryLow': '<S39>:468' */
        /* Transition: '<S39>:490' */
        AR_Drone_Flight_Control_DW.is_BatteryLow =
          AR_Drone_Flight_IN_ForceLanding;

        /* Entry 'ForceLanding': '<S39>:489' */
      } else {
        switch (AR_Drone_Flight_Control_DW.is_BatteryNominal) {
         case AR_Drone_Flight__IN_ChangeState:
          /* During 'ChangeState': '<S39>:472' */
          break;

         case AR_Dron_IN_EvaluateVoltageLevel:
          /* During 'EvaluateVoltageLevel': '<S39>:477' */
          if (AR_Drone_Flight_Control_B.FilterBattVoltage >= 10.1) {
            /* Transition: '<S39>:478' */
            AR_Drone_Flight_Control_DW.is_BatteryNominal =
              AR_Drone_Flight_Cont_IN_Nominal;
          } else {
            if (AR_Drone_Flight_Control_DW.temporalCounter_i1 >= 2000U) {
              /* Transition: '<S39>:479' */
              AR_Drone_Flight_Control_DW.is_BatteryNominal =
                AR_Drone_Flight__IN_ChangeState;

              /* Entry 'ChangeState': '<S39>:472' */
              AR_Drone_Flight_Control_DW.BatteryFault = 1.0;
            }
          }
          break;

         default:
          /* During 'Nominal': '<S39>:471' */
          if (AR_Drone_Flight_Control_B.FilterBattVoltage < 10.1) {
            /* Transition: '<S39>:473' */
            AR_Drone_Flight_Control_DW.is_BatteryNominal =
              AR_Dron_IN_EvaluateVoltageLevel;
            AR_Drone_Flight_Control_DW.temporalCounter_i1 = 0U;
          }
          break;
        }
      }
    } else {
      /* During 'BatteryLow': '<S39>:468' */
      /* During 'ForceLanding': '<S39>:489' */
    }

    /* During 'UltraSoundwarning_Check': '<S39>:454' */
    /* During 'SafeOrientation_Check': '<S39>:548' */
    switch (AR_Drone_Flight_Control_B.SafeOrientation_Mode) {
     case SafeOrientation_ModeType_WaitForFlight:
      /* During 'WaitForFlight': '<S39>:544' */
      if (AR_Drone_Flight_Control_B.Drone_StateMode ==
          Drone_StateModeType_Controlled_Flight) {
        /* Transition: '<S39>:546' */
        AR_Drone_Flight_Control_B.SafeOrientation_Mode =
          SafeOrientation_ModeType_GravityVectorCheck;

        /* Entry 'GravityVectorCheck': '<S39>:551' */
        AR_Drone_Flight_Control_DW.OrientationFault = 0.0;

        /* Entry Internal 'GravityVectorCheck': '<S39>:551' */
        /* Transition: '<S39>:554' */
        AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
          AR_Dro_IN_EvaluateGravityVector;
        AR_Drone_Flight_Control_DW.temporalCounter_i2 = 0U;
      }
      break;

     case SafeOrientation_ModeType_GravityVectorCheck:
      /* During 'GravityVectorCheck': '<S39>:551' */
      if (AR_Drone_Flight_Control_DW.OrientationFault == 1.0) {
        /* Transition: '<S39>:550' */
        /* Exit Internal 'GravityVectorCheck': '<S39>:551' */
        AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
          AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
        AR_Drone_Flight_Control_B.SafeOrientation_Mode =
          SafeOrientation_ModeType_UnsafeOrientation;
      } else if (AR_Drone_Flight_Control_B.Drone_StateMode ==
                 Drone_StateModeType_WaitForHost) {
        /* Transition: '<S39>:566' */
        /* Exit Internal 'GravityVectorCheck': '<S39>:551' */
        AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
          AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
        AR_Drone_Flight_Control_B.SafeOrientation_Mode =
          SafeOrientation_ModeType_WaitForFlight;
      } else {
        switch (AR_Drone_Flight_Control_DW.is_GravityVectorCheck) {
         case AR_Drone_Flight__IN_ChangeState:
          /* During 'ChangeState': '<S39>:559' */
          break;

         case AR_Dro_IN_EvaluateGravityVector:
          /* During 'EvaluateGravityVector': '<S39>:558' */
          if (AR_Drone_Flight_Control_B.AccelNorm[2] < -0.05) {
            /* Transition: '<S39>:552' */
            AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
              AR_Drone_Flight_Cont_IN_Nominal;
          } else {
            if (AR_Drone_Flight_Control_DW.temporalCounter_i2 >= 4U) {
              /* Transition: '<S39>:555' */
              AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
                AR_Drone_Flight__IN_ChangeState;

              /* Entry 'ChangeState': '<S39>:559' */
              AR_Drone_Flight_Control_DW.OrientationFault = 1.0;
            }
          }
          break;

         default:
          /* During 'Nominal': '<S39>:557' */
          if (AR_Drone_Flight_Control_B.AccelNorm[2] >= 0.05) {
            /* Transition: '<S39>:553' */
            AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
              AR_Dro_IN_EvaluateGravityVector;
            AR_Drone_Flight_Control_DW.temporalCounter_i2 = 0U;
          }
          break;
        }
      }
      break;

     default:
      /* During 'UnsafeOrientation': '<S39>:549' */
      AR_Drone_Flight_Control_DW.MotorArmed = 0.0;
      AR_Drone_Flight_Control_DW.LandingPhase = 0.0;
      break;
    }
  }

  /* End of Chart: '<S4>/Supervisory Flight Controller' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  AR_Drone_Flight_Control_B.DataTypeConversion = (int8_T)
    AR_Drone_Flight_Control_B.Drone_StateMode;

  /* Saturate: '<S7>/Saturation' */
  if (AR_Drone_Flight_Control_B.MotorCmd[0] >
      AR_Drone_Flight_Control_P.Saturation_UpperSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_UpperSat;
  } else if (AR_Drone_Flight_Control_B.MotorCmd[0] <
             AR_Drone_Flight_Control_P.Saturation_LowerSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_LowerSat;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_B.MotorCmd[0];
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_P.Gain_Gain_n5 * AR_Drone_Flight_Control_B.Delay_o);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 = (uint16_T)
    ((AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(uint16_T)
      AR_Drone_Flight_Control_B.Delay_o) &
     AR_Drone_Flight_Control_P.BitwiseOperator_BitMask);

  /* Saturate: '<S7>/Saturation' */
  if (AR_Drone_Flight_Control_B.MotorCmd[1] >
      AR_Drone_Flight_Control_P.Saturation_UpperSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_UpperSat;
  } else if (AR_Drone_Flight_Control_B.MotorCmd[1] <
             AR_Drone_Flight_Control_P.Saturation_LowerSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_LowerSat;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_B.MotorCmd[1];
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_P.Gain_Gain_n5 * AR_Drone_Flight_Control_B.Delay_o);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 = (uint16_T)
    ((AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(uint16_T)
      AR_Drone_Flight_Control_B.Delay_o) &
     AR_Drone_Flight_Control_P.BitwiseOperator_BitMask);

  /* Saturate: '<S7>/Saturation' */
  if (AR_Drone_Flight_Control_B.MotorCmd[2] >
      AR_Drone_Flight_Control_P.Saturation_UpperSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_UpperSat;
  } else if (AR_Drone_Flight_Control_B.MotorCmd[2] <
             AR_Drone_Flight_Control_P.Saturation_LowerSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_LowerSat;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_B.MotorCmd[2];
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_P.Gain_Gain_n5 * AR_Drone_Flight_Control_B.Delay_o);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 = (uint16_T)
    ((AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(uint16_T)
      AR_Drone_Flight_Control_B.Delay_o) &
     AR_Drone_Flight_Control_P.BitwiseOperator_BitMask);

  /* Saturate: '<S7>/Saturation' */
  if (AR_Drone_Flight_Control_B.MotorCmd[3] >
      AR_Drone_Flight_Control_P.Saturation_UpperSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_UpperSat;
  } else if (AR_Drone_Flight_Control_B.MotorCmd[3] <
             AR_Drone_Flight_Control_P.Saturation_LowerSat) {
    AR_Drone_Flight_Control_B.Delay_o =
      AR_Drone_Flight_Control_P.Saturation_LowerSat;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = AR_Drone_Flight_Control_B.MotorCmd[3];
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  AR_Drone_Flight_Control_B.Delay_o = floor
    (AR_Drone_Flight_Control_P.Gain_Gain_n5 * AR_Drone_Flight_Control_B.Delay_o);
  if (rtIsNaN(AR_Drone_Flight_Control_B.Delay_o) || rtIsInf
      (AR_Drone_Flight_Control_B.Delay_o)) {
    AR_Drone_Flight_Control_B.Delay_o = 0.0;
  } else {
    AR_Drone_Flight_Control_B.Delay_o = fmod(AR_Drone_Flight_Control_B.Delay_o,
      65536.0);
  }

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  AR_Drone_Flight_Control_B.Delay_k = (uint16_T)
    ((AR_Drone_Flight_Control_B.Delay_o < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-AR_Drone_Flight_Control_B.Delay_o : (int32_T)(uint16_T)
      AR_Drone_Flight_Control_B.Delay_o) &
     AR_Drone_Flight_Control_P.BitwiseOperator_BitMask);

  /* DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
   *  ArithShift: '<S7>/Shift Arithmetic'
   *  ArithShift: '<S7>/Shift Arithmetic1'
   *  ArithShift: '<S7>/Shift Arithmetic2'
   *  ArithShift: '<S7>/Shift Arithmetic3'
   *  ArithShift: '<S7>/Shift Arithmetic4'
   *  ArithShift: '<S7>/Shift Arithmetic5'
   *  ArithShift: '<S7>/Shift Arithmetic6'
   *  ArithShift: '<S7>/Shift Arithmetic7'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator3'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator4'
   */
  AR_Drone_Flight_Control_B.DataTypeConversion3_c[0] = (uint8_T)((uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 >> 4) |
    AR_Drone_Flight_Control_P.BitwiseOperator1_BitMask);
  AR_Drone_Flight_Control_B.DataTypeConversion3_c[1] = (uint8_T)((uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_0 << 4) | (uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 >> 5));
  AR_Drone_Flight_Control_B.DataTypeConversion3_c[2] = (uint8_T)((uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_1 << 3) | (uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 >> 6));
  AR_Drone_Flight_Control_B.DataTypeConversion3_c[3] = (uint8_T)((uint16_T)
    (AR_Drone_Flight_Control_B.rtb_Delay_b_idx_2 << 2) | (uint16_T)
    (AR_Drone_Flight_Control_B.Delay_k >> 7));
  AR_Drone_Flight_Control_B.DataTypeConversion3_c[4] = (uint8_T)
    (AR_Drone_Flight_Control_B.Delay_k << 1);

  /* S-Function (ARDrone_Motor): '<S7>/ARDrone_Motor' */
  AR_Drone_Flight_Control_B.ARDrone_Motor = Motor_Set( (uint8_T*)
    &AR_Drone_Flight_Control_B.DataTypeConversion3_c[0]);

  /* Sum: '<S18>/Sum of Elements3' */
  AR_Drone_Flight_Control_B.SumofElements3_o =
    (AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[0] +
     AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[4]) +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[8];

  /* If: '<S18>/If' incorporates:
   *  Abs: '<S18>/Abs'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S30>/Trace=3=>Phi=0'
   *  Sum: '<S18>/Sum'
   */
  if (AR_Drone_Flight_Control_B.SumofElements3_o +
      AR_Drone_Flight_Control_P.Constant_Value_e0[0] >= 3.0) {
    /* Outputs for IfAction SubSystem: '<S18>/Phi == 0' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    AR_Drone_Flight_Control_B.Merge_l[0] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value[0];
    AR_Drone_Flight_Control_B.Merge_l[1] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value[1];
    AR_Drone_Flight_Control_B.Merge_l[2] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value[2];
    AR_Drone_Flight_Control_B.Merge_l[3] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value[3];

    /* End of Outputs for SubSystem: '<S18>/Phi == 0' */

    /* Update for IfAction SubSystem: '<S18>/Phi == 0' incorporates:
     *  Update for ActionPort: '<S30>/Action Port'
     */
    /* Update for If: '<S18>/If' incorporates:
     *  Constant: '<S30>/Trace=3=>Phi=0'
     */
    srUpdateBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_k);

    /* End of Update for SubSystem: '<S18>/Phi == 0' */
  } else if (fabs(AR_Drone_Flight_Control_B.SumofElements3_o +
                  AR_Drone_Flight_Control_P.Constant_Value_e0[1]) <= 1.0E-12) {
    /* Outputs for IfAction SubSystem: '<S18>/Phi == pi' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    AR_Drone_Flight_Contr_Phipi(AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out,
      &AR_Drone_Flight_Control_B.Merge_l[0], &AR_Drone_Flight_Control_B.Merge_l
      [3], (P_Phipi_AR_Drone_Flight_Contr_T *)&AR_Drone_Flight_Control_P.Phipi_m,
      AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation1_m);

    /* End of Outputs for SubSystem: '<S18>/Phi == pi' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/General case' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    AR_Drone_Flight_Generalcase(AR_Drone_Flight_Control_B.SumofElements3_o,
      AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out,
      &AR_Drone_Flight_Control_B.Merge_l[0], &AR_Drone_Flight_Control_B.Merge_l
      [3], (P_Generalcase_AR_Drone_Flight_T *)
      &AR_Drone_Flight_Control_P.Generalcase_m);

    /* End of Outputs for SubSystem: '<S18>/General case' */
  }

  /* End of If: '<S18>/If' */

  /* Gain: '<S132>/Gain1' incorporates:
   *  Selector: '<S132>/Selector1'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate_c[0] =
    AR_Drone_Flight_Control_P.Gain1_Gain_o[0] * AR_Drone_Flight_Control_B.DCM[5];
  AR_Drone_Flight_Control_B.VectorConcatenate_c[1] =
    AR_Drone_Flight_Control_P.Gain1_Gain_o[1] * AR_Drone_Flight_Control_B.DCM[8];
  AR_Drone_Flight_Control_B.VectorConcatenate_c[2] =
    AR_Drone_Flight_Control_P.Gain1_Gain_o[2] * AR_Drone_Flight_Control_B.DCM[2];

  /* Gain: '<S132>/Gain2' incorporates:
   *  Selector: '<S132>/Selector2'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate_c[3] =
    AR_Drone_Flight_Control_P.Gain2_Gain_h[0] * AR_Drone_Flight_Control_B.DCM[1];
  AR_Drone_Flight_Control_B.VectorConcatenate_c[4] =
    AR_Drone_Flight_Control_P.Gain2_Gain_h[1] * AR_Drone_Flight_Control_B.DCM[0];

  /* Gain: '<S132>/Gain3' incorporates:
   *  Selector: '<S132>/Selector3'
   */
  AR_Drone_Flight_Control_B.VectorConcatenate_c[5] =
    AR_Drone_Flight_Control_P.Gain3_Gain_d[0] * AR_Drone_Flight_Control_B.DCM[7];
  AR_Drone_Flight_Control_B.VectorConcatenate_c[6] =
    AR_Drone_Flight_Control_P.Gain3_Gain_d[1] * AR_Drone_Flight_Control_B.DCM[4];

  /* If: '<S122>/If' */
  if ((AR_Drone_Flight_Control_B.VectorConcatenate_c[2] >= 1.0) ||
      (AR_Drone_Flight_Control_B.VectorConcatenate_c[2] <= -1.0)) {
    /* Outputs for IfAction SubSystem: '<S122>/AxisRotZeroR3' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    AR_Drone_Flig_AxisRotZeroR3(AR_Drone_Flight_Control_B.VectorConcatenate_c,
      &AR_Drone_Flight_Control_B.Merge_a[0], &AR_Drone_Flight_Control_B.Merge_a
      [1], &AR_Drone_Flight_Control_B.Merge_a[2]);

    /* End of Outputs for SubSystem: '<S122>/AxisRotZeroR3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S122>/AxisRotDefault' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    AR_Drone_Fli_AxisRotDefault(AR_Drone_Flight_Control_B.VectorConcatenate_c,
      &AR_Drone_Flight_Control_B.Merge_a[0], &AR_Drone_Flight_Control_B.Merge_a
      [1], &AR_Drone_Flight_Control_B.Merge_a[2]);

    /* End of Outputs for SubSystem: '<S122>/AxisRotDefault' */
  }

  /* End of If: '<S122>/If' */

  /* SignalConversion: '<S128>/TmpSignal ConversionAtsincosInport1' incorporates:
   *  Gain: '<S72>/Gain'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 =
    AR_Drone_Flight_Control_P.Gain_Gain_d * AR_Drone_Flight_Control_B.Merge_a[2];

  /* Trigonometry: '<S128>/sincos' incorporates:
   *  SignalConversion: '<S128>/TmpSignal ConversionAtsincosInport1'
   */
  AR_Drone_Flight_Control_B.Delay_o = cos(AR_Drone_Flight_Control_B.Merge_a[0]);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 = sin
    (AR_Drone_Flight_Control_B.Merge_a[0]);
  AR_Drone_Flight_Control_B.height = cos(AR_Drone_Flight_Control_B.Merge_a[1]);
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 = sin
    (AR_Drone_Flight_Control_B.Merge_a[1]);
  AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 = sin
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2);
  AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 = cos
    (AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2);

  /* Fcn: '<S128>/Fcn11' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[0] =
    AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S128>/Fcn21' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[1] =
    -AR_Drone_Flight_Control_B.height *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S128>/Fcn31' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[2] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1;

  /* Fcn: '<S128>/Fcn12' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[3] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S128>/Fcn22' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[4] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 +
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S128>/Fcn32' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[5] =
    -AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.height;

  /* Fcn: '<S128>/Fcn13' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[6] =
    -AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0;

  /* Fcn: '<S128>/Fcn23' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[7] =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 +
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2;

  /* Fcn: '<S128>/Fcn33' */
  AR_Drone_Flight_Control_B.VectorConcatenate_l[8] =
    AR_Drone_Flight_Control_B.Delay_o * AR_Drone_Flight_Control_B.height;

  /* MATLAB Function: '<S72>/Matrix Re-Order' */
  AR_Drone_Flig_MatrixReOrder(AR_Drone_Flight_Control_B.VectorConcatenate_l,
    &AR_Drone_Flight_Control_B.sf_MatrixReOrder_l);

  /* Outputs for Atomic SubSystem: '<S72>/Normalize SL3D-DCM' */
  /* Gain: '<S127>/Gain' incorporates:
   *  DotProduct: '<S127>/Dot Product'
   *  Selector: '<S127>/row0'
   *  Selector: '<S127>/row1'
   */
  AR_Drone_Flight_Control_B.Delay_o =
    ((AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[0] *
      AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[1] +
      AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[3] *
      AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[4]) +
     AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[6] *
     AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[7]) *
    AR_Drone_Flight_Control_P.Gain_Gain;

  /* Sum: '<S127>/Add1' incorporates:
   *  Product: '<S127>/Product1'
   *  Selector: '<S127>/row0'
   *  Selector: '<S127>/row1'
   */
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[1] +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[0];
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[4] +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[3];
  AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 =
    AR_Drone_Flight_Control_B.Delay_o *
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[7] +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[6];

  /* Sum: '<S127>/Add' incorporates:
   *  Product: '<S127>/Product'
   *  Selector: '<S127>/row0'
   *  Selector: '<S127>/row1'
   */
  AR_Drone_Flight_Control_B.rtb_Divide_idx_0 =
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[0] *
    AR_Drone_Flight_Control_B.Delay_o +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[1];
  AR_Drone_Flight_Control_B.rtb_Divide_idx_1 =
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[3] *
    AR_Drone_Flight_Control_B.Delay_o +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[4];
  AR_Drone_Flight_Control_B.rtb_Divide_idx_2 =
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[6] *
    AR_Drone_Flight_Control_B.Delay_o +
    AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[7];

  /* Sum: '<S137>/Sum' incorporates:
   *  Product: '<S138>/i x j'
   *  Product: '<S138>/j x k'
   *  Product: '<S138>/k x i'
   *  Product: '<S139>/i x k'
   *  Product: '<S139>/j x i'
   *  Product: '<S139>/k x j'
   */
  AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 -
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1;
  AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 -
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2;
  AR_Drone_Flight_Control_B.Delay_o =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 -
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0;

  /* Gain: '<S127>/Gain1' incorporates:
   *  Constant: '<S127>/Constant'
   *  DotProduct: '<S127>/Dot Product1'
   *  Sum: '<S127>/Add2'
   */
  AR_Drone_Flight_Control_B.renorm1 = (real32_T)
    ((AR_Drone_Flight_Control_P.Constant_Value_p -
      ((AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
        AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 +
        AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
        AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1) +
       AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 *
       AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2)) *
     AR_Drone_Flight_Control_P.Gain1_Gain);

  /* Gain: '<S127>/Gain2' incorporates:
   *  Constant: '<S127>/Constant'
   *  DotProduct: '<S127>/Dot Product2'
   *  Sum: '<S127>/Add3'
   */
  AR_Drone_Flight_Control_B.renorm2 = (real32_T)
    ((AR_Drone_Flight_Control_P.Constant_Value_p -
      ((AR_Drone_Flight_Control_B.rtb_Divide_idx_0 *
        AR_Drone_Flight_Control_B.rtb_Divide_idx_0 +
        AR_Drone_Flight_Control_B.rtb_Divide_idx_1 *
        AR_Drone_Flight_Control_B.rtb_Divide_idx_1) +
       AR_Drone_Flight_Control_B.rtb_Divide_idx_2 *
       AR_Drone_Flight_Control_B.rtb_Divide_idx_2)) *
     AR_Drone_Flight_Control_P.Gain2_Gain);

  /* Gain: '<S127>/Gain3' incorporates:
   *  Constant: '<S127>/Constant'
   *  DotProduct: '<S127>/Dot Product3'
   *  Sum: '<S127>/Add4'
   */
  AR_Drone_Flight_Control_B.renorm3 = (real32_T)
    ((AR_Drone_Flight_Control_P.Constant_Value_p -
      ((AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 *
        AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 +
        AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 *
        AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2) +
       AR_Drone_Flight_Control_B.Delay_o * AR_Drone_Flight_Control_B.Delay_o)) *
     AR_Drone_Flight_Control_P.Gain3_Gain);

  /* Concatenate: '<S127>/Matrix Concatenate' incorporates:
   *  Product: '<S127>/Product2'
   *  Product: '<S127>/Product3'
   *  Product: '<S127>/Product4'
   */
  AR_Drone_Flight_Control_B.MatrixConcatenate[0] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_0 *
    AR_Drone_Flight_Control_B.renorm1;
  AR_Drone_Flight_Control_B.MatrixConcatenate[3] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_1 *
    AR_Drone_Flight_Control_B.renorm1;
  AR_Drone_Flight_Control_B.MatrixConcatenate[6] =
    AR_Drone_Flight_Control_B.rtb_Delay_g_idx_2 *
    AR_Drone_Flight_Control_B.renorm1;
  AR_Drone_Flight_Control_B.MatrixConcatenate[1] =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_0 *
    AR_Drone_Flight_Control_B.renorm2;
  AR_Drone_Flight_Control_B.MatrixConcatenate[4] =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_1 *
    AR_Drone_Flight_Control_B.renorm2;
  AR_Drone_Flight_Control_B.MatrixConcatenate[7] =
    AR_Drone_Flight_Control_B.rtb_Divide_idx_2 *
    AR_Drone_Flight_Control_B.renorm2;
  AR_Drone_Flight_Control_B.MatrixConcatenate[2] =
    AR_Drone_Flight_Control_B.rtb_MathFunction_e_idx_0 *
    AR_Drone_Flight_Control_B.renorm3;
  AR_Drone_Flight_Control_B.MatrixConcatenate[5] =
    AR_Drone_Flight_Control_B.rtb_sincos_o2_idx_2 *
    AR_Drone_Flight_Control_B.renorm3;
  AR_Drone_Flight_Control_B.MatrixConcatenate[8] =
    AR_Drone_Flight_Control_B.Delay_o * AR_Drone_Flight_Control_B.renorm3;

  /* End of Outputs for SubSystem: '<S72>/Normalize SL3D-DCM' */

  /* Sum: '<S129>/Sum of Elements3' */
  AR_Drone_Flight_Control_B.SumofElements3_b =
    (AR_Drone_Flight_Control_B.MatrixConcatenate[0] +
     AR_Drone_Flight_Control_B.MatrixConcatenate[4]) +
    AR_Drone_Flight_Control_B.MatrixConcatenate[8];

  /* If: '<S129>/If' incorporates:
   *  Abs: '<S129>/Abs'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S142>/Trace=3=>Phi=0'
   *  Sum: '<S129>/Sum'
   */
  if (AR_Drone_Flight_Control_B.SumofElements3_b +
      AR_Drone_Flight_Control_P.Constant_Value_d[0] >= 3.0) {
    /* Outputs for IfAction SubSystem: '<S129>/Phi == 0' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    AR_Drone_Flight_Control_B.Merge_lg[0] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_h[0];
    AR_Drone_Flight_Control_B.Merge_lg[1] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_h[1];
    AR_Drone_Flight_Control_B.Merge_lg[2] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_h[2];
    AR_Drone_Flight_Control_B.Merge_lg[3] =
      AR_Drone_Flight_Control_P.Trace3Phi0_Value_h[3];

    /* End of Outputs for SubSystem: '<S129>/Phi == 0' */

    /* Update for IfAction SubSystem: '<S129>/Phi == 0' incorporates:
     *  Update for ActionPort: '<S142>/Action Port'
     */
    /* Update for If: '<S129>/If' incorporates:
     *  Constant: '<S142>/Trace=3=>Phi=0'
     */
    srUpdateBC(AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_n);

    /* End of Update for SubSystem: '<S129>/Phi == 0' */
  } else if (fabs(AR_Drone_Flight_Control_B.SumofElements3_b +
                  AR_Drone_Flight_Control_P.Constant_Value_d[1]) <= 1.0E-12) {
    /* Outputs for IfAction SubSystem: '<S129>/Phi == pi' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    AR_Drone_Flight_Contr_Phipi(AR_Drone_Flight_Control_B.MatrixConcatenate,
      &AR_Drone_Flight_Control_B.Merge_lg[0],
      &AR_Drone_Flight_Control_B.Merge_lg[3], (P_Phipi_AR_Drone_Flight_Contr_T *)
      &AR_Drone_Flight_Control_P.Phipi_i,
      AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation1_p);

    /* End of Outputs for SubSystem: '<S129>/Phi == pi' */
  } else {
    /* Outputs for IfAction SubSystem: '<S129>/General case' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    AR_Drone_Flight_Generalcase(AR_Drone_Flight_Control_B.SumofElements3_b,
      AR_Drone_Flight_Control_B.MatrixConcatenate,
      &AR_Drone_Flight_Control_B.Merge_lg[0],
      &AR_Drone_Flight_Control_B.Merge_lg[3], (P_Generalcase_AR_Drone_Flight_T *)
      &AR_Drone_Flight_Control_P.Generalcase_e);

    /* End of Outputs for SubSystem: '<S129>/General case' */
  }

  /* End of If: '<S129>/If' */

  /* RateTransition: '<S72>/Rate Transition2' incorporates:
   *  Gain: '<S123>/Gain1'
   *  Gain: '<S123>/Gain2'
   *  Gain: '<S123>/Gain3'
   *  Gain: '<S125>/Gain2'
   *  Gain: '<S125>/Gain3'
   *  Gain: '<S135>/Gain'
   *  Gain: '<S135>/Gain1'
   *  Gain: '<S135>/Gain2'
   *  RateTransition: '<S72>/Rate Transition1'
   *  RateTransition: '<S72>/Rate Transition3'
   *  RateTransition: '<S72>/Rate Transition4'
   */
  if (AR_Drone_Flight_Control_M->Timing.RateInteraction.TID0_2) {
    AR_Drone_Flight_Control_B.RateTransition2[0] =
      AR_Drone_Flight_Control_B.Merge_lg[0];
    AR_Drone_Flight_Control_B.RateTransition2[1] =
      AR_Drone_Flight_Control_B.Merge_lg[1];
    AR_Drone_Flight_Control_B.RateTransition2[2] =
      AR_Drone_Flight_Control_B.Merge_lg[2];
    AR_Drone_Flight_Control_B.RateTransition2[3] =
      AR_Drone_Flight_Control_B.Merge_lg[3];
    AR_Drone_Flight_Control_B.BodyFrame[0] =
      AR_Drone_Flight_Control_P.Gain1_Gain_f *
      AR_Drone_Flight_Control_B.VRML_Visuals[7];
    AR_Drone_Flight_Control_B.BodyFrame[1] =
      AR_Drone_Flight_Control_P.Gain2_Gain_d *
      AR_Drone_Flight_Control_B.VRML_Visuals[8];
    AR_Drone_Flight_Control_B.BodyFrame[2] =
      AR_Drone_Flight_Control_P.Gain_Gain_ip *
      AR_Drone_Flight_Control_B.VRML_Visuals[6];
    AR_Drone_Flight_Control_B.BodyFrame_h[0] =
      AR_Drone_Flight_Control_P.Gain1_Gain_e *
      AR_Drone_Flight_Control_B.VRML_Visuals[1] *
      AR_Drone_Flight_Control_P.Gain2_Gain_hl;
    AR_Drone_Flight_Control_B.BodyFrame_h[1] =
      AR_Drone_Flight_Control_P.Gain1_Gain_e *
      AR_Drone_Flight_Control_B.VRML_Visuals[2];
    AR_Drone_Flight_Control_B.BodyFrame_h[2] =
      AR_Drone_Flight_Control_P.Gain1_Gain_e *
      AR_Drone_Flight_Control_B.VRML_Visuals[0] *
      AR_Drone_Flight_Control_P.Gain3_Gain_k;
    AR_Drone_Flight_Control_B.BodyFrame_o[0] =
      AR_Drone_Flight_Control_P.Gain2_Gain_b *
      AR_Drone_Flight_Control_B.VRML_Visuals[4];
    AR_Drone_Flight_Control_B.BodyFrame_o[1] =
      AR_Drone_Flight_Control_B.VRML_Visuals[5];
    AR_Drone_Flight_Control_B.BodyFrame_o[2] =
      AR_Drone_Flight_Control_P.Gain3_Gain_b *
      AR_Drone_Flight_Control_B.VRML_Visuals[3];
  }

  /* End of RateTransition: '<S72>/Rate Transition2' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki = (int16_T)
    AR_Drone_Flight_Control_B.Drone_StateMode;

  /* Update for Memory: '<S69>/Memory' */
  AR_Drone_Flight_Control_DW.Memory_PreviousInput =
    AR_Drone_Flight_Control_B.Switch1;

  /* Update for Memory: '<S66>/Memory' */
  AR_Drone_Flight_Control_DW.Memory_PreviousInput_i =
    AR_Drone_Flight_Control_B.Switch1;

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[0] =
    AR_Drone_Flight_Control_B.Add[0];
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[1] =
    AR_Drone_Flight_Control_B.Add[1];
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[2] =
    AR_Drone_Flight_Control_B.Add[2];

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_k =
    AR_Drone_Flight_Control_B.DonottouchoncethisSimulinki;

  /* Update for DiscreteTransferFcn: '<S4>/FilterBattVoltage' */
  AR_Drone_Flight_Control_DW.FilterBattVoltage_states =
    (AR_Drone_Flight_Control_B.DeciVoltstoVolts -
     AR_Drone_Flight_Control_P.FilterBattVoltage_DenCoef[1] *
     AR_Drone_Flight_Control_DW.FilterBattVoltage_states) /
    AR_Drone_Flight_Control_P.FilterBattVoltage_DenCoef[0];

  /* Update for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */
  sErr_0 = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
  LibUpdate_Network(&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ
                    [0U], &AR_Drone_Flight_Control_B.DataTypeConversion, 1);
  if (*sErr_0 != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr_0);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(0, AR_Drone_Flight_Control_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0025s, 0.0s] */
    if ((rtmGetTFinal(AR_Drone_Flight_Control_M)!=-1) &&
        !((rtmGetTFinal(AR_Drone_Flight_Control_M)-
           AR_Drone_Flight_Control_M->Timing.taskTime0) >
          AR_Drone_Flight_Control_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AR_Drone_Flight_Control_M, "Simulation finished");
    }

    if (rtmGetStopRequested(AR_Drone_Flight_Control_M)) {
      rtmSetErrorStatus(AR_Drone_Flight_Control_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  AR_Drone_Flight_Control_M->Timing.taskTime0 =
    (++AR_Drone_Flight_Control_M->Timing.clockTick0) *
    AR_Drone_Flight_Control_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void AR_Drone_Flight_Control_step1(void) /* Sample time: [0.005s, 0.0s] */
{
  char_T *sErr;

  /* Update for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */
  sErr = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
  LibUpdate_Network(&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi
                    [0U], &AR_Drone_Flight_Control_B.RateTransition[0U], 34);
  if (*sErr != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */
  rtExtModeUpload(1, ((AR_Drone_Flight_Control_M->Timing.clockTick1) * 0.005));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AR_Drone_Flight_Control_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void AR_Drone_Flight_Control_step2(void) /* Sample time: [0.02s, 0.0s] */
{
  rtExtModeUpload(2, ((AR_Drone_Flight_Control_M->Timing.clockTick2) * 0.02));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AR_Drone_Flight_Control_M->Timing.clockTick2++;
}

/* Model initialize function */
void AR_Drone_Flight_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  AR_Drone_Flight_Control_P.Delay_InitialCondition = rtInf;
  AR_Drone_Flight_Control_P.Delay_InitialCondition_e = rtInf;

  /* initialize real-time model */
  (void) memset((void *)AR_Drone_Flight_Control_M, 0,
                sizeof(RT_MODEL_AR_Drone_Flight_Cont_T));
  rtmSetTFinal(AR_Drone_Flight_Control_M, -1);
  AR_Drone_Flight_Control_M->Timing.stepSize0 = 0.0025;

  /* External mode info */
  AR_Drone_Flight_Control_M->Sizes.checksums[0] = (581685069U);
  AR_Drone_Flight_Control_M->Sizes.checksums[1] = (2832571693U);
  AR_Drone_Flight_Control_M->Sizes.checksums[2] = (2400547196U);
  AR_Drone_Flight_Control_M->Sizes.checksums[3] = (314160428U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[54];
    AR_Drone_Flight_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.AxisRotDefault.AxisRotDefault_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.AxisRotZeroR3.AxisRotZeroR3_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Generalcase_m.Generalcase_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_k;
    systemRan[6] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Generalcase.Generalcase_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckConv;
    systemRan[24] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckMove;
    systemRan[25] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.AxisRotDefault_d.AxisRotDefault_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.AxisRotZeroR3_o.AxisRotZeroR3_SubsysRanBC;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Generalcase_e.Generalcase_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_n;
    systemRan[49] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC;
    rteiSetModelMappingInfoPtr(AR_Drone_Flight_Control_M->extModeInfo,
      &AR_Drone_Flight_Control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AR_Drone_Flight_Control_M->extModeInfo,
                        AR_Drone_Flight_Control_M->Sizes.checksums);
    rteiSetTPtr(AR_Drone_Flight_Control_M->extModeInfo, rtmGetTPtr
                (AR_Drone_Flight_Control_M));
  }

  /* block I/O */
  (void) memset(((void *) &AR_Drone_Flight_Control_B), 0,
                sizeof(B_AR_Drone_Flight_Control_T));

  {
    AR_Drone_Flight_Control_B.Drone_StateModeConversion =
      Drone_StateModeType_None;
    AR_Drone_Flight_Control_B.Drone_StateMode = Drone_StateModeType_None;
    AR_Drone_Flight_Control_B.BatteryFault_Mode = BatteryFault_ModeType_None;
    AR_Drone_Flight_Control_B.SafeOrientation_Mode =
      SafeOrientation_ModeType_None;
  }

  /* states (dwork) */
  (void) memset((void *)&AR_Drone_Flight_Control_DW, 0,
                sizeof(DW_AR_Drone_Flight_Control_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AR_Drone_Flight_Control_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model Initialize fcn for ModelReference Block: '<S5>/Flight Mission' */
  AR_Drone_Mission_Hei_initialize(rtmGetErrorStatusPointer
    (AR_Drone_Flight_Control_M),
    &(AR_Drone_Flight_Control_DW.FlightMission_DWORK1.rtm),
    &(AR_Drone_Flight_Control_DW.FlightMission_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S8>/Kalman Filter State Estimation' */
  Navigation_KF_Subsys_initialize(rtmGetErrorStatusPointer
    (AR_Drone_Flight_Control_M),
    &(AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO.rtm),
    &(AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO.rtdw));

  {
    char_T *sErr;
    char_T *sErr_0;
    char_T *sErr_1;

    /* Start for ModelReference: '<S5>/Flight Mission' */
    AR_Drone_Mission_Height_Start
      (&(AR_Drone_Flight_Control_DW.FlightMission_DWORK1.rtdw));

    /* Start for S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */
    sErr = GetErrorBuffer
      (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
    CreateUDPInterface
      (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network
        (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U], 0,
         "0.0.0.0", 6000, "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr);
        rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */

    /* Start for DataStoreMemory: '<S5>/Desired_Drone_StateMode' */
    AR_Drone_Flight_Control_DW.Desired_Drone_StateMode =
      AR_Drone_Flight_Control_P.Desired_Drone_StateMode_Initial;

    /* Start for Atomic SubSystem: '<S8>/CheckSum Pre-Processing' */
    /* Start for Constant: '<S70>/Holding Value' */
    AR_Drone_Flight_Control_B.HoldingValue =
      AR_Drone_Flight_Control_P.HoldingValue_Value;

    /* End of Start for SubSystem: '<S8>/CheckSum Pre-Processing' */

    /* Start for IfAction SubSystem: '<S19>/Phi == 0' */
    /* VirtualOutportStart for Outport: '<S35>/VRRot_0' */
    AR_Drone_Flight_Control_B.Merge[0] = AR_Drone_Flight_Control_P.VRRot_0_Y0_h
      [0];
    AR_Drone_Flight_Control_B.Merge[1] = AR_Drone_Flight_Control_P.VRRot_0_Y0_h
      [1];
    AR_Drone_Flight_Control_B.Merge[2] = AR_Drone_Flight_Control_P.VRRot_0_Y0_h
      [2];
    AR_Drone_Flight_Control_B.Merge[3] = AR_Drone_Flight_Control_P.VRRot_0_Y0_h
      [3];

    /* End of Start for SubSystem: '<S19>/Phi == 0' */

    /* Start for IfAction SubSystem: '<S19>/Phi == pi' */
    AR_Drone_Flight_Phipi_Start(&AR_Drone_Flight_Control_B.Merge[0],
      &AR_Drone_Flight_Control_B.Merge[3], (P_Phipi_AR_Drone_Flight_Contr_T *)
      &AR_Drone_Flight_Control_P.Phipi);

    /* End of Start for SubSystem: '<S19>/Phi == pi' */

    /* Start for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */
    sErr_0 = GetErrorBuffer
      (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
    CreateUDPInterface
      (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
    if (*sErr_0 == 0) {
      LibCreate_Network
        (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U], 1,
         "0.0.0.0", -1, "192.168.1.5", 25000, 8192, 8, 0);
    }

    if (*sErr_0 == 0) {
      LibStart(&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
    }

    if (*sErr_0 != 0) {
      DestroyUDPInterface
        (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
      if (*sErr_0 != 0) {
        rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr_0);
        rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */

    /* Start for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  Start for SubSystem: '<S39>/Attitude_Control'
     */
    AR_D_Attitude_Control_Start(&AR_Drone_Flight_Control_B.Attitude_Control,
      (P_Attitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Attitude_Control);

    /* Start for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  Start for SubSystem: '<S39>/Motor_Mixing'
     */
    AR_Drone_Motor_Mixing_Start(&AR_Drone_Flight_Control_B.Motor_Mixing,
      (P_Motor_Mixing_AR_Drone_Fligh_T *)&AR_Drone_Flight_Control_P.Motor_Mixing);

    /* Start for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */
    sErr_1 = GetErrorBuffer
      (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
    CreateUDPInterface
      (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
    if (*sErr_1 == 0) {
      LibCreate_Network
        (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U], 1,
         "0.0.0.0", -1, "192.168.1.5", 24000, 8192, 1, 0);
    }

    if (*sErr_1 == 0) {
      LibStart(&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
    }

    if (*sErr_1 != 0) {
      DestroyUDPInterface
        (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
      if (*sErr_1 != 0) {
        rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr_1);
        rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */
    /* Start for IfAction SubSystem: '<S18>/Phi == 0' */
    /* VirtualOutportStart for Outport: '<S30>/VRRot_0' */
    AR_Drone_Flight_Control_B.Merge_l[0] = AR_Drone_Flight_Control_P.VRRot_0_Y0
      [0];
    AR_Drone_Flight_Control_B.Merge_l[1] = AR_Drone_Flight_Control_P.VRRot_0_Y0
      [1];
    AR_Drone_Flight_Control_B.Merge_l[2] = AR_Drone_Flight_Control_P.VRRot_0_Y0
      [2];
    AR_Drone_Flight_Control_B.Merge_l[3] = AR_Drone_Flight_Control_P.VRRot_0_Y0
      [3];

    /* End of Start for SubSystem: '<S18>/Phi == 0' */

    /* Start for IfAction SubSystem: '<S18>/Phi == pi' */
    AR_Drone_Flight_Phipi_Start(&AR_Drone_Flight_Control_B.Merge_l[0],
      &AR_Drone_Flight_Control_B.Merge_l[3], (P_Phipi_AR_Drone_Flight_Contr_T *)
      &AR_Drone_Flight_Control_P.Phipi_m);

    /* End of Start for SubSystem: '<S18>/Phi == pi' */

    /* Start for IfAction SubSystem: '<S129>/Phi == 0' */
    /* VirtualOutportStart for Outport: '<S142>/VRRot_0' */
    AR_Drone_Flight_Control_B.Merge_lg[0] =
      AR_Drone_Flight_Control_P.VRRot_0_Y0_n[0];
    AR_Drone_Flight_Control_B.Merge_lg[1] =
      AR_Drone_Flight_Control_P.VRRot_0_Y0_n[1];
    AR_Drone_Flight_Control_B.Merge_lg[2] =
      AR_Drone_Flight_Control_P.VRRot_0_Y0_n[2];
    AR_Drone_Flight_Control_B.Merge_lg[3] =
      AR_Drone_Flight_Control_P.VRRot_0_Y0_n[3];

    /* End of Start for SubSystem: '<S129>/Phi == 0' */

    /* Start for IfAction SubSystem: '<S129>/Phi == pi' */
    AR_Drone_Flight_Phipi_Start(&AR_Drone_Flight_Control_B.Merge_lg[0],
      &AR_Drone_Flight_Control_B.Merge_lg[3], (P_Phipi_AR_Drone_Flight_Contr_T *)
      &AR_Drone_Flight_Control_P.Phipi_i);

    /* End of Start for SubSystem: '<S129>/Phi == pi' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    AR_Drone_Flight_Control_DW.Offset_Accel[0] =
      AR_Drone_Flight_Control_P.DataStoreMemory_InitialValue[0];
    AR_Drone_Flight_Control_DW.Offset_Accel[1] =
      AR_Drone_Flight_Control_P.DataStoreMemory_InitialValue[1];
    AR_Drone_Flight_Control_DW.Offset_Accel[2] =
      AR_Drone_Flight_Control_P.DataStoreMemory_InitialValue[2];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    AR_Drone_Flight_Control_DW.Offset_Gyro[0] =
      AR_Drone_Flight_Control_P.DataStoreMemory1_InitialValue[0];
    AR_Drone_Flight_Control_DW.Offset_Gyro[1] =
      AR_Drone_Flight_Control_P.DataStoreMemory1_InitialValue[1];
    AR_Drone_Flight_Control_DW.Offset_Gyro[2] =
      AR_Drone_Flight_Control_P.DataStoreMemory1_InitialValue[2];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    AR_Drone_Flight_Control_DW.Input_ports[0] =
      AR_Drone_Flight_Control_P.DataStoreMemory2_InitialValue[0];
    AR_Drone_Flight_Control_DW.Input_ports[1] =
      AR_Drone_Flight_Control_P.DataStoreMemory2_InitialValue[1];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    AR_Drone_Flight_Control_DW.Output_ports[0] =
      AR_Drone_Flight_Control_P.DataStoreMemory3_InitialValue[0];
    AR_Drone_Flight_Control_DW.Output_ports[1] =
      AR_Drone_Flight_Control_P.DataStoreMemory3_InitialValue[1];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    AR_Drone_Flight_Control_DW.Flight_Mission_On_Off =
      AR_Drone_Flight_Control_P.DataStoreMemory4_InitialValue;

    /* S-Function (Init_Actuator): <Root>/Init_Actuator */
    Actuator_Initialization();
  }

  {
    int32_T i;

    /* InitializeConditions for ModelReference: '<S5>/Flight Mission' */
    AR_Drone_Mission_Height_Init
      (&(AR_Drone_Flight_Control_DW.FlightMission_DWORK1.rtdw));

    /* InitializeConditions for Memory: '<S69>/Memory' */
    AR_Drone_Flight_Control_DW.Memory_PreviousInput =
      AR_Drone_Flight_Control_P.Memory_X0;

    /* InitializeConditions for Memory: '<S66>/Memory' */
    AR_Drone_Flight_Control_DW.Memory_PreviousInput_i =
      AR_Drone_Flight_Control_P.Memory_X0_c;

    /* S-Function (IMU_Sfcn_mex): <S6>/IMU Read */
    MDL_IMU_start();

    /* InitializeConditions for Atomic SubSystem: '<S8>/CheckSum Pre-Processing' */
    /* InitializeConditions for Delay: '<S79>/Delay' */
    for (i = 0; i < 9; i++) {
      AR_Drone_Flight_Control_DW.Delay_DSTATE_f[i] =
        AR_Drone_Flight_Control_P.Delay_InitialCondition_f;
    }

    /* End of InitializeConditions for Delay: '<S79>/Delay' */

    /* InitializeConditions for UnitDelay: '<S83>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_p =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for Chart: '<S81>/Chart' */
    AR_Drone_Flight__Chart_Init(&AR_Drone_Flight_Control_DW.sf_Chart);

    /* InitializeConditions for Delay: '<S84>/Delay' */
    for (i = 0; i < 9; i++) {
      AR_Drone_Flight_Control_DW.Delay_DSTATE_h[i] =
        AR_Drone_Flight_Control_P.Delay_InitialCondition_c;
    }

    /* End of InitializeConditions for Delay: '<S84>/Delay' */

    /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_f =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_n;

    /* InitializeConditions for Chart: '<S87>/Chart' */
    AR_Drone_Flight__Chart_Init(&AR_Drone_Flight_Control_DW.sf_Chart_c);

    /* InitializeConditions for Delay: '<S90>/Delay' */
    for (i = 0; i < 9; i++) {
      AR_Drone_Flight_Control_DW.Delay_DSTATE[i] =
        AR_Drone_Flight_Control_P.Delay_InitialCondition_p;
    }

    /* End of InitializeConditions for Delay: '<S90>/Delay' */

    /* InitializeConditions for UnitDelay: '<S95>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_j =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_h3;

    /* InitializeConditions for Chart: '<S93>/Chart' */
    AR_Drone_Flight__Chart_Init(&AR_Drone_Flight_Control_DW.sf_Chart_k);

    /* InitializeConditions for Delay: '<S96>/Delay' */
    AR_Drone_Flight_Control_DW.Delay_DSTATE_l[0] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_g;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_l[1] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_g;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_l[2] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_kb =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_d;

    /* InitializeConditions for Chart: '<S99>/Chart' */
    AR_Drone_Flight__Chart_Init(&AR_Drone_Flight_Control_DW.sf_Chart_m);

    /* InitializeConditions for Delay: '<S102>/Delay' */
    AR_Drone_Flight_Control_DW.Delay_DSTATE_a[0] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_h;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_a[1] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_h;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_a[2] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition_h;

    /* InitializeConditions for UnitDelay: '<S107>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_e =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_hi;

    /* InitializeConditions for Chart: '<S105>/Chart' */
    AR_Drone_Flight__Chart_Init(&AR_Drone_Flight_Control_DW.sf_Chart_ci);

    /* InitializeConditions for Delay: '<S77>/Delay1' */
    AR_Drone_Flight_Control_DW.Delay1_DSTATE =
      AR_Drone_Flight_Control_P.Delay1_InitialCondition;

    /* End of InitializeConditions for SubSystem: '<S8>/CheckSum Pre-Processing' */

    /* InitializeConditions for UnitDelay: '<S114>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[0] =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition;
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[1] =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition;
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[2] =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_k =
      AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_h;

    /* InitializeConditions for ModelReference: '<S8>/Kalman Filter State Estimation' */
    Navigation_KF_Subsystem_ch_Init
      (&(AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO.rtdw));

    /* S-Function (Battery_Sfcn_mex): <S8>/Battery Voltage Measurement */
    BatteryMeasure_start();

    /* InitializeConditions for DiscreteTransferFcn: '<S4>/FilterBattVoltage' */
    AR_Drone_Flight_Control_DW.FilterBattVoltage_states =
      AR_Drone_Flight_Control_P.FilterBattVoltage_InitialStates;
    AR_Drone_Flight_Control_DW.sfEvent = AR_Drone_Flight_Co_CALL_EVENT_j;
    AR_Drone_Flight_Control_DW.A_x_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.A_y_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.A_z_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.Tick_not_empty = false;
    AR_Drone_Flight_Control_DW.G_x_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.G_y_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.G_z_sum_not_empty = false;
    AR_Drone_Flight_Control_DW.Tick_not_empty_i = false;
    AR_Drone_Flight_Control_DW.is_active_Drone_State = 0U;
    AR_Drone_Flight_Control_DW.is_Controlled_Flight =
      AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.is_Landing_Sequence =
      AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.is_WaitForHost = AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.temporalCounter_i3 = 0U;
    AR_Drone_Flight_Control_DW.is_active_Fault_Check = 0U;
    AR_Drone_Flight_Control_DW.is_active_BatteryFault_Check = 0U;
    AR_Drone_Flight_Control_DW.is_BatteryLow = AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.is_BatteryNominal =
      AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.temporalCounter_i1 = 0U;
    AR_Drone_Flight_Control_DW.is_active_SafeOrientation_Check = 0U;
    AR_Drone_Flight_Control_DW.is_GravityVectorCheck =
      AR_Drone_F_IN_NO_ACTIVE_CHILD_b;
    AR_Drone_Flight_Control_DW.temporalCounter_i2 = 0U;
    AR_Drone_Flight_Control_DW.is_active_UltraSoundwarning_Che = 0U;
    AR_Drone_Flight_Control_DW.is_active_Flight_Controls = 0U;
    AR_Drone_Flight_Control_DW.is_active_Altitude_Command = 0U;
    AR_Drone_Flight_Control_DW.is_active_Attitude_Command = 0U;
    AR_Drone_Flight_Control_DW.is_active_MotorMixing_Command = 0U;
    AR_Drone_Flight_Control_DW.is_active_c12_AR_Drone_Flight_C = 0U;
    AR_Drone_Flight_Control_B.Drone_StateMode = Drone_StateModeType_None;
    AR_Drone_Flight_Control_B.BatteryFault_Mode = BatteryFault_ModeType_None;
    AR_Drone_Flight_Control_B.SafeOrientation_Mode =
      SafeOrientation_ModeType_None;

    /* InitializeConditions for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  InitializeConditions for SubSystem: '<S39>/Drone_State.WaitForHost.checkConvergence'
     */
    /* InitializeConditions for Delay: '<S42>/Delay' */
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[0] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[1] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition;
    AR_Drone_Flight_Control_DW.Delay_DSTATE_ir[2] =
      AR_Drone_Flight_Control_P.Delay_InitialCondition;

    /* InitializeConditions for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  InitializeConditions for SubSystem: '<S39>/Drone_State.WaitForHost.checkMove'
     */
    for (i = 0; i < 120; i++) {
      /* InitializeConditions for Delay: '<S43>/Delay' */
      AR_Drone_Flight_Control_DW.Delay_DSTATE_i[i] =
        AR_Drone_Flight_Control_P.Delay_InitialCondition_e;
    }

    /* InitializeConditions for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  InitializeConditions for SubSystem: '<S39>/Altitude_Control'
     */
    AR_Dr_Altitude_Control_Init(AR_Drone_Flight_Control_M,
      &AR_Drone_Flight_Control_DW.Altitude_Control,
      (P_Altitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Altitude_Control);

    /* InitializeConditions for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  InitializeConditions for SubSystem: '<S39>/Attitude_Control'
     */
    AR_Dr_Attitude_Control_Init(AR_Drone_Flight_Control_M,
      &AR_Drone_Flight_Control_DW.Attitude_Control,
      (P_Attitude_Control_AR_Drone_F_T *)
      &AR_Drone_Flight_Control_P.Attitude_Control);

    /* InitializeConditions for Chart: '<S4>/Supervisory Flight Controller' incorporates:
     *  InitializeConditions for SubSystem: '<S39>/Motor_Mixing'
     */
    AR_Drone__Motor_Mixing_Init(&AR_Drone_Flight_Control_DW.Motor_Mixing);
  }
}

/* Model terminate function */
void AR_Drone_Flight_Control_terminate(void)
{
  char_T *sErr;
  char_T *sErr_0;
  char_T *sErr_1;

  /* Terminate for S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */
  sErr = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
  LibTerminate(&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  LibDestroy(&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U], 0);
  DestroyUDPInterface
    (&AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<S2>/Host Command (port 7 000)' */

  /* S-Function (IMU_Sfcn_mex): <S6>/IMU Read */
  MDL_IMU_term();

  /* S-Function (Battery_Sfcn_mex): <S8>/Battery Voltage Measurement */
  BatteryMeasure_term();

  /* Terminate for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */
  sErr_0 = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
  LibTerminate(&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);
  if (*sErr_0 != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr_0);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  LibDestroy(&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U], 1);
  DestroyUDPInterface
    (&AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/Data_to_host (port 25 000)' */

  /* Terminate for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */
  sErr_1 = GetErrorBuffer
    (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
  LibTerminate(&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);
  if (*sErr_1 != 0) {
    rtmSetErrorStatus(AR_Drone_Flight_Control_M, sErr_1);
    rtmSetStopRequested(AR_Drone_Flight_Control_M, 1);
  }

  LibDestroy(&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U], 1);
  DestroyUDPInterface
    (&AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/Drone_StateMode (port 24 000)' */

  /* S-Function (Init_Actuator): <Root>/Init_Actuator */
  Actuator_Stop();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
