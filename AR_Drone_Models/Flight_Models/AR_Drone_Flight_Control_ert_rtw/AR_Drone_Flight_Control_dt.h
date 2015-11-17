/*
 * AR_Drone_Flight_Control_dt.h
 *
 * Code generation for model "AR_Drone_Flight_Control".
 *
 * Model version              : 1.1216
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Nov 17 10:18:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
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
  sizeof(Drone_StateModeType),
  sizeof(BatteryFault_ModeType),
  sizeof(SafeOrientation_ModeType),
  sizeof(IMU_Packets),
  sizeof(struct_J3crjymWSwWCQ8kQITIpr),
  sizeof(Measurement_Calculation_Bus),
  sizeof(int16_T),
  sizeof(int16_T),
  sizeof(int32_T),
  sizeof(MdlrefDW_AR_Drone_Mission_Hei_T),
  sizeof(MdlrefDW_Navigation_KF_Subsys_T)
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
  "Drone_StateModeType",
  "BatteryFault_ModeType",
  "SafeOrientation_ModeType",
  "IMU_Packets",
  "struct_J3crjymWSwWCQ8kQITIpr",
  "Measurement_Calculation_Bus",
  "int16_T",
  "int16_T",
  "int32_T",
  "MdlrefDW_AR_Drone_Mission_Hei_T",
  "MdlrefDW_Navigation_KF_Subsys_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw[0]), 0, 0, 62 },

  { (char_T *)(&AR_Drone_Flight_Control_B.FlightMission_o4), 0, 0, 68 },

  { (char_T *)(&AR_Drone_Flight_Control_B.FilterBattVoltage), 1, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Drone_StateModeConversion), 14, 0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_B.RPYCmd[0]), 4, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_B.BatteryFault_Mode), 15, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.SafeOrientation_Mode), 16, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.DataTypeConversion4), 4, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_B.HostCommandport7000_o2), 5, 0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_B.DataTypeConversion), 2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.DataTypeConversion5), 8, 0, 14 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out[0]), 0, 0, 9
  },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_Chart_ci.output), 0, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_Chart_m.output), 0, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_Chart_k.output), 0, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_Chart_c.output), 0, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_Chart.output), 0, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Motor_Mixing.Switch[0]), 0, 0, 4 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Attitude_Control.Sum[0]), 0, 0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion),
    4, 0, 6 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Altitude_Control.Error), 0, 0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_B.Altitude_Control.DataTypeConversion1),
    4, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out[0]), 0, 0, 9 }
  ,

  { (char_T *)(&AR_Drone_Flight_Control_DW.UnitDelay_DSTATE[0]), 0, 0, 586 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.AttitudeView1_PWORK[0]), 11, 0, 25 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.FilterBattVoltage_states), 1, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Desired_Drone_StateMode), 14, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_k), 4, 0, 10 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Delay_DSTATE_f[0]), 5, 0, 12 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Memory_PreviousInput), 4, 0, 7 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.temporalCounter_i1), 5, 0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_p), 8, 0, 5 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC), 2, 0, 5 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.is_active_c12_AR_Drone_Flight_C), 3,
    0, 17 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Flight_Mission_On_Off), 8, 0, 13 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.FlightMission_DWORK1), 23, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO), 24,
    0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Generalcase_e.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.AxisRotDefault_d.AxisRotDefault_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.AxisRotZeroR3_o.AxisRotZeroR3_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_ci.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_ci.temporalCounter_i1), 7, 0,
    1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.sf_Chart_ci.is_active_c2_AR_Drone_Flight_Co), 3,
    0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_ci.isStable), 8, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_m.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_m.temporalCounter_i1), 7, 0,
    1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.sf_Chart_m.is_active_c2_AR_Drone_Flight_Co), 3,
    0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_m.isStable), 8, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_k.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_k.temporalCounter_i1), 7, 0,
    1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.sf_Chart_k.is_active_c2_AR_Drone_Flight_Co), 3,
    0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_k.isStable), 8, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_c.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_c.temporalCounter_i1), 7, 0,
    1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.sf_Chart_c.is_active_c2_AR_Drone_Flight_Co), 3,
    0, 2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart_c.isStable), 8, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart.sfEvent), 6, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart.temporalCounter_i1), 7, 0, 1
  },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.sf_Chart.is_active_c2_AR_Drone_Flight_Co), 3, 0,
    2 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.sf_Chart.isStable), 8, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Motor_Mixing.tempCmd[0]), 0, 0, 4 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Attitude_Control.UD_DSTATE), 0, 0, 7
  },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Attitude_Control.Recorded_Torque_Cmd_PWORK.LoggedData),
    11, 0, 2 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_ELAPS_T), 7,
    0, 2 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC),
    2, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Altitude_Control.Integrator_DSTATE),
    0, 0, 2 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Altitude_Control.ControlEffort_PWORK.LoggedData),
    11, 0, 2 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_ELAPS_T), 7,
    0, 2 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Generalcase.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Generalcase_m.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.AxisRotDefault.AxisRotDefault_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&AR_Drone_Flight_Control_DW.AxisRotZeroR3.AxisRotZeroR3_SubsysRanBC), 2, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  78U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AR_Drone_Flight_Control_P.CompareToConstant_const), 0, 0, 134 },

  { (char_T *)(&AR_Drone_Flight_Control_P.DeciVoltstoVolts_Gain), 1, 0, 5 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Constant_Value_oh), 6, 0, 5 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Delay_DelayLength), 7, 0, 8 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Constant_Value_b), 14, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_P.DontchangeDesiredDrone_StateMod), 4, 0,
    8 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Delay_InitialCondition_f), 5, 0, 4 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Gain1_Gain_g), 4, 0, 4 },

  { (char_T *)(&AR_Drone_Flight_Control_P.SwitchtochangethecurrentDroneSt), 3, 0,
    2 },

  { (char_T *)(&AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_k), 8, 0, 6
  },

  { (char_T *)(&AR_Drone_Flight_Control_P.Generalcase_e.Constant_Value), 0, 0, 3
  },

  { (char_T *)(&AR_Drone_Flight_Control_P.Phipi_i.Shiftright_table[0]), 0, 0, 37
  },

  { (char_T *)(&AR_Drone_Flight_Control_P.Motor_Mixing.Switch1_Threshold), 0, 0,
    6 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Motor_Mixing.Constant1_Value[0]), 4, 0,
    22 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_D), 0,
    0, 23 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Attitude_Control.Gain4_Gain[0]), 1, 0,
    15 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Attitude_Control.Saturation_UpperSat),
    4, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_D), 0, 0,
    14 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Generalcase.Constant_Value), 0, 0, 3 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Phipi.Shiftright_table[0]), 0, 0, 37 },

  { (char_T *)(&AR_Drone_Flight_Control_P.Generalcase_m.Constant_Value), 0, 0, 3
  },

  { (char_T *)(&AR_Drone_Flight_Control_P.Phipi_m.Shiftright_table[0]), 0, 0, 37
  }
  ,

  { (char_T *)(rtP_Accelerometer_quick_calibration), 0, 0, 3 }
  ,

  { (char_T *)(rtP_Gyrometer_quick_calibration), 0, 0, 3 }
  ,

  { (char_T *)(&Accelerometer_360deg_calibration), 18, 0, 1 }
  ,

  { (char_T *)(&Magnetometer_calibration), 18, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  26U,
  rtPTransitions
};

/* [EOF] AR_Drone_Flight_Control_dt.h */
