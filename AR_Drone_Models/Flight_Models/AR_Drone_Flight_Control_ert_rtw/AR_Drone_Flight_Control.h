/*
 * File: AR_Drone_Flight_Control.h
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

#ifndef RTW_HEADER_AR_Drone_Flight_Control_h_
#define RTW_HEADER_AR_Drone_Flight_Control_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef AR_Drone_Flight_Control_COMMON_INCLUDES_
# define AR_Drone_Flight_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "IMU_Navdata.h"
#include "i2c-dev.h"
#include "motor.h"
#include "act_init.h"
#include "HostLib_Network.h"
#endif                                 /* AR_Drone_Flight_Control_COMMON_INCLUDES_ */

#include "AR_Drone_Flight_Control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Child system includes */
#include "Navigation_KF_Subsystem_child.h"
#include "AR_Drone_Mission_Height.h"
#include "div_s16s32_floor.h"
#include "rt_atan2d_snf.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (auto storage) for system '<S10>/AxisRotZeroR3' */
typedef struct {
  int8_T AxisRotZeroR3_SubsysRanBC;    /* '<S10>/AxisRotZeroR3' */
} DW_AxisRotZeroR3_AR_Drone_Fli_T;

/* Block states (auto storage) for system '<S10>/AxisRotDefault' */
typedef struct {
  int8_T AxisRotDefault_SubsysRanBC;   /* '<S10>/AxisRotDefault' */
} DW_AxisRotDefault_AR_Drone_Fl_T;

/* Block signals for system '<S9>/Matrix Re-Order' */
typedef struct {
  real_T M_out[9];                     /* '<S9>/Matrix Re-Order' */
} B_MatrixReOrder_AR_Drone_Flig_T;

/* Block states (auto storage) for system '<S18>/Phi == pi' */
typedef struct {
  int8_T Phipi_SubsysRanBC;            /* '<S18>/Phi == pi' */
} DW_Phipi_AR_Drone_Flight_Cont_T;

/* Block states (auto storage) for system '<S18>/General case' */
typedef struct {
  int8_T Generalcase_SubsysRanBC;      /* '<S18>/General case' */
} DW_Generalcase_AR_Drone_Fligh_T;

/* Block signals for system '<S39>/Altitude_Control' */
typedef struct {
  real_T Error;                        /* '<S40>/Sum' */
  real_T Saturation;                   /* '<S46>/Saturation' */
  int16_T DataTypeConversion1;         /* '<S40>/Data Type Conversion1' */
} B_Altitude_Control_AR_Drone_F_T;

/* Block states (auto storage) for system '<S39>/Altitude_Control' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S46>/Integrator' */
  real_T Filter_DSTATE;                /* '<S46>/Filter' */
  struct {
    void *LoggedData;
  } ControlEffort_PWORK;               /* '<S40>/Control Effort' */

  struct {
    void *LoggedData;
  } HeightError_PWORK;                 /* '<S40>/Height Error' */

  uint32_T Altitude_Control_ELAPS_T;   /* '<S39>/Altitude_Control' */
  uint32_T Altitude_Control_PREV_T;    /* '<S39>/Altitude_Control' */
  int8_T Altitude_Control_SubsysRanBC; /* '<S39>/Altitude_Control' */
} DW_Altitude_Control_AR_Drone__T;

/* Block signals for system '<S39>/Attitude_Control' */
typedef struct {
  real_T Sum[2];                       /* '<S51>/Sum' */
  real_T rtb_DeadZone_a_m;
  real_T rtb_FilterCoefficient_k_idx_0;
  real_T rtb_FilterCoefficient_k_idx_1;
  real_T rtb_DeadZone_a_idx_0;
  real_T rtb_DeadZone_a_idx_1;
  int16_T DataTypeConversion;          /* '<S52>/Data Type Conversion' */
  int16_T DataTypeConversion1[3];      /* '<S41>/Data Type Conversion1' */
  int16_T Saturation[2];               /* '<S51>/Saturation' */
} B_Attitude_Control_AR_Drone_F_T;

/* Block states (auto storage) for system '<S39>/Attitude_Control' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S60>/UD' */
  real_T DigitalLowPassFilter2_states; /* '<S54>/Digital Low Pass Filter2' */
  real_T DigitalLowPassFilter1_states; /* '<S54>/Digital Low Pass Filter1' */
  real_T Integrator_DSTATE[2];         /* '<S57>/Integrator' */
  real_T Filter_DSTATE[2];             /* '<S57>/Filter' */
  struct {
    void *LoggedData;
  } Recorded_Torque_Cmd_PWORK;         /* '<S41>/Recorded_Torque_Cmd' */

  struct {
    void *LoggedData;
  } AttitudeCommand_PWORK;             /* '<S51>/Attitude Command' */

  uint32_T Attitude_Control_ELAPS_T;   /* '<S39>/Attitude_Control' */
  uint32_T Attitude_Control_PREV_T;    /* '<S39>/Attitude_Control' */
  int8_T Attitude_Control_SubsysRanBC; /* '<S39>/Attitude_Control' */
  int8_T Integrator_PrevResetState;    /* '<S57>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S57>/Filter' */
} DW_Attitude_Control_AR_Drone__T;

/* Block signals for system '<S39>/Motor_Mixing' */
typedef struct {
  real_T Switch[4];                    /* '<S44>/Switch' */
} B_Motor_Mixing_AR_Drone_Fligh_T;

/* Block states (auto storage) for system '<S39>/Motor_Mixing' */
typedef struct {
  real_T tempCmd[4];                   /* '<S44>/RampDownInSpeed1' */
  int8_T Motor_Mixing_SubsysRanBC;     /* '<S39>/Motor_Mixing' */
} DW_Motor_Mixing_AR_Drone_Flig_T;

/* Block signals for system '<S81>/Chart' */
typedef struct {
  real_T output;                       /* '<S81>/Chart' */
} B_Chart_AR_Drone_Flight_Contr_T;

/* Block states (auto storage) for system '<S81>/Chart' */
typedef struct {
  int32_T sfEvent;                     /* '<S81>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S81>/Chart' */
  uint8_T is_active_c2_AR_Drone_Flight_Co;/* '<S81>/Chart' */
  uint8_T is_c2_AR_Drone_Flight_Control;/* '<S81>/Chart' */
  boolean_T isStable;                  /* '<S81>/Chart' */
} DW_Chart_AR_Drone_Flight_Cont_T;

/* Block signals (auto storage) */
typedef struct {
  Measurement_Calculation_Bus BusConversion_InsertedFor_K;
  real_T VectorConcatenate_k[9];       /* '<S28>/Vector Concatenate' */
  real_T VRML_Visuals[9];              /* '<S8>/Kalman Filter State Estimation' */
  real_T DCM[9];                       /* '<S8>/Kalman Filter State Estimation' */
  real_T VectorConcatenate_p[9];       /* '<S27>/Vector Concatenate' */
  real_T VectorConcatenate_l[9];       /* '<S140>/Vector Concatenate' */
  real_T Product[9];                   /* '<S9>/Product' */
  real_T MatrixConcatenate[9];         /* '<S127>/Matrix Concatenate' */
  IMU_Packets IMURead_o1;              /* '<S6>/IMU Read' */
  real_T VectorConcatenate[7];         /* '<S22>/Vector Concatenate' */
  real_T VectorConcatenate_c[7];       /* '<S132>/Vector Concatenate' */
  real_T Desired_Roll_Pitch_Yaw[3];    /* '<S5>/Flight Mission' */
  real_T Merge[4];                     /* '<S19>/Merge' */
  real_T RateTransition[34];           /* '<Root>/Rate Transition' */
  real_T Merge_l[4];                   /* '<S18>/Merge' */
  real_T Merge_lg[4];                  /* '<S129>/Merge' */
  real_T RateTransition2[4];           /* '<S72>/Rate Transition2' */
  real_T BodyFrame[3];                 /* '<S72>/Rate Transition1' */
  real_T BodyFrame_h[3];               /* '<S72>/Rate Transition3' */
  real_T BodyFrame_o[3];               /* '<S72>/Rate Transition4' */
  real_T Merge_m[3];                   /* '<S10>/Merge' */
  real_T Merge_a[3];                   /* '<S122>/Merge' */
  real_T FlightMission_o4;             /* '<S5>/Flight Mission' */
  real_T FlightMission_o5;             /* '<S5>/Flight Mission' */
  real_T HostCommandport7000_o1;       /* '<S2>/Host Command (port 7 000)' */
  real_T TmpSignalConversionAtAttitudeVi[3];/* '<Root>/Data decomposition to 3D Visualization' */
  real_T Gain[3];                      /* '<S111>/Gain' */
  real_T Multiply[3];                  /* '<S112>/Multiply' */
  real_T Sum;                          /* '<S113>/Sum' */
  real_T Sum1;                         /* '<S113>/Sum1' */
  real_T Sum2;                         /* '<S113>/Sum2' */
  real_T Add[3];                       /* '<S114>/Add' */
  real_T Sum_m;                        /* '<S110>/Sum' */
  real_T Sum1_p;                       /* '<S110>/Sum1' */
  real_T Sum2_f;                       /* '<S110>/Sum2' */
  real_T UltraSound[2];                /* '<S8>/Kalman Filter State Estimation' */
  real_T EulerAngles[3];               /* '<S8>/Kalman Filter State Estimation' */
  real_T ProcessedGyro[3];             /* '<S8>/Kalman Filter State Estimation' */
  real_T AccelNorm[3];                 /* '<S8>/Kalman Filter State Estimation' */
  real_T Reshape[9];                   /* '<S3>/Reshape' */
  real_T HoldingValue;                 /* '<S70>/Holding Value' */
  real_T IfTruewehavegooddataIffalseweha[3];/* '<S90>/If True, we have good data, If false, we have bad data,  With bad data, use previous good data from N samples ago and hold it on that value for M samples' */
  real_T MotorCmd[4];                  /* '<S4>/Supervisory Flight Controller' */
  real_T refHeight;                    /* '<S4>/Supervisory Flight Controller' */
  real_T HeightFeedback[2];            /* '<S4>/Supervisory Flight Controller' */
  real_T refHeight_d;                  /* '<S4>/Supervisory Flight Controller' */
  real_T Desired_Attitude_Deg[3];      /* '<S4>/Supervisory Flight Controller' */
  real_T EulerAngle_Feedback_Deg[3];   /* '<S4>/Supervisory Flight Controller' */
  real_T RateGyro_Feedback_Deg[3];     /* '<S4>/Supervisory Flight Controller' */
  real_T Motor_Armed;                  /* '<S4>/Supervisory Flight Controller' */
  real_T LandingPhase;                 /* '<S4>/Supervisory Flight Controller' */
  real_T Motor_Armed_d;                /* '<S4>/Supervisory Flight Controller' */
  real_T Abs[3];                       /* '<S43>/Abs' */
  real_T height;
  real_T Delay_o;                      /* '<S102>/Delay' */
  real_T rtb_Delay_g_idx_0;
  real_T rtb_Delay_g_idx_1;
  real_T rtb_Delay_g_idx_2;
  real_T rtb_sincos_o2_idx_2;
  real_T rtb_MathFunction_e_idx_0;
  real_T rtb_Divide_idx_2;
  real_T rtb_Divide_idx_1;
  real_T rtb_Divide_idx_0;
  real_T AutoCalibration_ON_OFF;       /* '<S5>/Flight Mission' */
  real_T Altitude_ON_OFF;              /* '<S5>/Flight Mission' */
  real_T SumofElements3;               /* '<S19>/Sum of Elements3' */
  real_T SumofElements3_o;             /* '<S18>/Sum of Elements3' */
  real_T SumofElements3_b;             /* '<S129>/Sum of Elements3' */
  uint8_T DataTypeConversion3_c[5];    /* '<S7>/Data Type Conversion3' */
  real32_T FilterBattVoltage;          /* '<S4>/FilterBattVoltage' */
  real32_T renorm1;                    /* '<S127>/Gain1' */
  real32_T renorm2;                    /* '<S127>/Gain2' */
  real32_T renorm3;                    /* '<S127>/Gain3' */
  real32_T DeciVoltstoVolts;
  real32_T BatteryVoltageMeasurement;  /* '<S8>/Battery Voltage Measurement' */
  int32_T samplesRead;
  int32_T Abs_k;                       /* '<S66>/Abs' */
  int32_T i0;
  int32_T IMURead_o2;                  /* '<S6>/IMU Read' */
  int32_T k;
  Drone_StateModeType Drone_StateModeConversion;/* '<S4>/Drone_State-Mode Conversion' */
  Drone_StateModeType Drone_StateMode; /* '<S4>/Supervisory Flight Controller' */
  int16_T RPYCmd[3];                   /* '<S4>/Supervisory Flight Controller' */
  Drone_StateModeType Desired_Drone_StateMode;/* '<S5>/Data Store Read2' */
  BatteryFault_ModeType BatteryFault_Mode;/* '<S4>/Supervisory Flight Controller' */
  SafeOrientation_ModeType SafeOrientation_Mode;/* '<S4>/Supervisory Flight Controller' */
  int16_T DataTypeConversion4;         /* '<S4>/Data Type Conversion4' */
  int16_T DataTypeConversion3;         /* '<S4>/Data Type Conversion3' */
  int16_T throttle;                    /* '<S4>/Supervisory Flight Controller' */
  int16_T Sum1_c;                      /* '<S66>/Sum1' */
  int16_T Switch1_g;                   /* '<S65>/Switch1' */
  int16_T DonottouchoncethisSimulinki; /* '<Root>/Do not touch once this Simulink is running' */
  int16_T Switch1;                     /* '<S69>/Switch1' */
  int16_T UnitDelay_h;                 /* '<S8>/Unit Delay' */
  uint16_T HostCommandport7000_o2;     /* '<S2>/Host Command (port 7 000)' */
  uint16_T ARDrone_Motor;              /* '<S7>/ARDrone_Motor' */
  uint16_T Delay_k;                    /* '<S96>/Delay' */
  uint16_T rtb_Delay_b_idx_0;
  uint16_T rtb_Delay_b_idx_1;
  uint16_T rtb_Delay_b_idx_2;
  int8_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  boolean_T DataTypeConversion5;       /* '<S4>/Data Type Conversion5' */
  boolean_T Transition_Detect;         /* '<S83>/Logical Operator' */
  boolean_T Transition_Detect_d;       /* '<S89>/Logical Operator' */
  boolean_T Transition_Detect_b;       /* '<S95>/Logical Operator' */
  boolean_T Transition_Detect_l;       /* '<S101>/Logical Operator' */
  boolean_T Transition_Detect_lb;      /* '<S107>/Logical Operator' */
  boolean_T Compare[3];                /* '<S62>/Compare' */
  boolean_T LogicalOperator1;          /* '<S43>/Logical Operator1' */
  boolean_T Compare_l[3];              /* '<S61>/Compare' */
  boolean_T LogicalOperator;           /* '<S42>/Logical Operator' */
  boolean_T LogicalOperator3;          /* '<S65>/Logical Operator3' */
  boolean_T LogicalOperator1_b;        /* '<S79>/Logical Operator1' */
  boolean_T LogicalOperator1_f;        /* '<S84>/Logical Operator1' */
  boolean_T LogicalOperator1_i;        /* '<S90>/Logical Operator1' */
  boolean_T LogicalOperator1_j;        /* '<S102>/Logical Operator1' */
  boolean_T Testsifdataequals1;        /* '<S69>/Tests if data equals -1' */
  boolean_T guard1;
  B_MatrixReOrder_AR_Drone_Flig_T sf_MatrixReOrder_l;/* '<S72>/Matrix Re-Order' */
  B_Chart_AR_Drone_Flight_Contr_T sf_Chart_ci;/* '<S105>/Chart' */
  B_Chart_AR_Drone_Flight_Contr_T sf_Chart_m;/* '<S99>/Chart' */
  B_Chart_AR_Drone_Flight_Contr_T sf_Chart_k;/* '<S93>/Chart' */
  B_Chart_AR_Drone_Flight_Contr_T sf_Chart_c;/* '<S87>/Chart' */
  B_Chart_AR_Drone_Flight_Contr_T sf_Chart;/* '<S81>/Chart' */
  B_Motor_Mixing_AR_Drone_Fligh_T Motor_Mixing;/* '<S39>/Motor_Mixing' */
  B_Attitude_Control_AR_Drone_F_T Attitude_Control;/* '<S39>/Attitude_Control' */
  B_Altitude_Control_AR_Drone_F_T Altitude_Control;/* '<S39>/Altitude_Control' */
  B_MatrixReOrder_AR_Drone_Flig_T sf_MatrixReOrder;/* '<S9>/Matrix Re-Order' */
} B_AR_Drone_Flight_Control_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[3];          /* '<S114>/Unit Delay' */
  real_T Delay_DSTATE[9];              /* '<S90>/Delay' */
  real_T Delay_DSTATE_a[3];            /* '<S102>/Delay' */
  real_T Delay1_DSTATE;                /* '<S77>/Delay1' */
  real_T Delay_DSTATE_i[120];          /* '<S43>/Delay' */
  real_T Delay_DSTATE_ir[3];           /* '<S42>/Delay' */
  real_T HostCommandport7000_NetworkLib[137];/* '<S2>/Host Command (port 7 000)' */
  real_T Data_to_hostport25000_NetworkLi[137];/* '<Root>/Data_to_host (port 25 000)' */
  real_T Drone_StateModeport24000_Networ[137];/* '<Root>/Drone_StateMode (port 24 000)' */
  real_T Offset_Accel[3];              /* '<Root>/Data Store Memory' */
  real_T Offset_Gyro[3];               /* '<Root>/Data Store Memory1' */
  real_T Input_ports[2];               /* '<Root>/Data Store Memory2' */
  real_T Output_ports[2];              /* '<Root>/Data Store Memory3' */
  real_T deltaThrottle;                /* '<S4>/Supervisory Flight Controller' */
  real_T height;                       /* '<S4>/Supervisory Flight Controller' */
  real_T hoverHeight;                  /* '<S4>/Supervisory Flight Controller' */
  real_T reset_offset_calc;            /* '<S4>/Supervisory Flight Controller' */
  real_T MotorArmed;                   /* '<S4>/Supervisory Flight Controller' */
  real_T LandingPhase;                 /* '<S4>/Supervisory Flight Controller' */
  real_T N;                            /* '<S4>/Supervisory Flight Controller' */
  real_T Offset_Gyro_Current[3];       /* '<S4>/Supervisory Flight Controller' */
  real_T Offset_Value_Current;         /* '<S4>/Supervisory Flight Controller' */
  real_T Offset_Accel_Current[3];      /* '<S4>/Supervisory Flight Controller' */
  real_T BatteryFault;                 /* '<S4>/Supervisory Flight Controller' */
  real_T OrientationFault;             /* '<S4>/Supervisory Flight Controller' */
  real_T Landing_Altitude;             /* '<S4>/Supervisory Flight Controller' */
  real_T Actual_Attitude;              /* '<S4>/Supervisory Flight Controller' */
  real_T A_x_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T A_y_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T A_z_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T Tick;                         /* '<S4>/Supervisory Flight Controller' */
  real_T G_x_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T G_y_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T G_z_sum;                      /* '<S4>/Supervisory Flight Controller' */
  real_T Tick_a;                       /* '<S4>/Supervisory Flight Controller' */
  void *AttitudeView1_PWORK[7];        /* '<Root>/Attitude View1' */
  struct {
    void *LoggedData;
  } RecordThrustInput_PWORK;           /* '<Root>/RecordThrustInput' */

  void *VRSink1_PWORK[11];             /* '<S72>/VR Sink1' */
  struct {
    void *LoggedData;
  } CompareCalibration_PWORK;          /* '<S108>/Compare Calibration' */

  struct {
    void *LoggedData;
  } CompareFilter_PWORK;               /* '<S108>/Compare Filter' */

  struct {
    void *LoggedData;
  } CompareOffset_PWORK;               /* '<S108>/Compare Offset' */

  struct {
    void *LoggedData;
  } BeforeAfter_PWORK;                 /* '<S110>/BeforeAfter' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S43>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S43>/Scope3' */

  real32_T FilterBattVoltage_states;   /* '<S4>/FilterBattVoltage' */
  int32_T sfEvent;                     /* '<S4>/Supervisory Flight Controller' */
  Drone_StateModeType Desired_Drone_StateMode;/* '<S5>/Desired_Drone_StateMode' */
  int16_T UnitDelay_DSTATE_k;          /* '<S8>/Unit Delay' */
  int16_T Delay_DSTATE_h[9];           /* '<S84>/Delay' */
  uint16_T Delay_DSTATE_f[9];          /* '<S79>/Delay' */
  uint16_T Delay_DSTATE_l[3];          /* '<S96>/Delay' */
  int16_T Memory_PreviousInput;        /* '<S69>/Memory' */
  int16_T Memory_PreviousInput_i;      /* '<S66>/Memory' */
  int16_T throttle;                    /* '<S4>/Supervisory Flight Controller' */
  int16_T Attitude_Thrust[3];          /* '<S4>/Supervisory Flight Controller' */
  int16_T Altitude_Thrust;             /* '<S4>/Supervisory Flight Controller' */
  uint16_T temporalCounter_i1;         /* '<S4>/Supervisory Flight Controller' */
  uint16_T temporalCounter_i3;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S83>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_f;        /* '<S89>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_j;        /* '<S95>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_kb;       /* '<S101>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S107>/Unit Delay' */
  int8_T Phi0_SubsysRanBC;             /* '<S19>/Phi == 0' */
  int8_T Phi0_SubsysRanBC_k;           /* '<S18>/Phi == 0' */
  int8_T Phi0_SubsysRanBC_n;           /* '<S129>/Phi == 0' */
  int8_T Drone_StateWaitForHostcheckConv;/* '<S39>/Drone_State.WaitForHost.checkConvergence' */
  int8_T Drone_StateWaitForHostcheckMove;/* '<S39>/Drone_State.WaitForHost.checkMove' */
  uint8_T is_active_c12_AR_Drone_Flight_C;/* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_Fault_Check;       /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_BatteryFault_Check;/* '<S4>/Supervisory Flight Controller' */
  uint8_T is_BatteryNominal;           /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_BatteryLow;               /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_UltraSoundwarning_Che;/* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_SafeOrientation_Check;/* '<S4>/Supervisory Flight Controller' */
  uint8_T is_GravityVectorCheck;       /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_Drone_State;       /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_WaitForHost;              /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_Controlled_Flight;        /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_Landing_Sequence;         /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_Flight_Controls;   /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_Attitude_Command;  /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_Altitude_Command;  /* '<S4>/Supervisory Flight Controller' */
  uint8_T is_active_MotorMixing_Command;/* '<S4>/Supervisory Flight Controller' */
  uint8_T temporalCounter_i2;          /* '<S4>/Supervisory Flight Controller' */
  boolean_T Flight_Mission_On_Off;     /* '<Root>/Data Store Memory4' */
  boolean_T isStable;                  /* '<S4>/Supervisory Flight Controller' */
  boolean_T initDone;                  /* '<S4>/Supervisory Flight Controller' */
  boolean_T Converge_Flag;             /* '<S4>/Supervisory Flight Controller' */
  boolean_T Move;                      /* '<S4>/Supervisory Flight Controller' */
  boolean_T A_x_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T A_y_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T A_z_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T Tick_not_empty;            /* '<S4>/Supervisory Flight Controller' */
  boolean_T G_x_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T G_y_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T G_z_sum_not_empty;         /* '<S4>/Supervisory Flight Controller' */
  boolean_T Tick_not_empty_i;          /* '<S4>/Supervisory Flight Controller' */
  MdlrefDW_AR_Drone_Mission_Hei_T FlightMission_DWORK1;/* '<S5>/Flight Mission' */
  MdlrefDW_Navigation_KF_Subsys_T KalmanFilterStateEstimation_DWO;/* '<S8>/Kalman Filter State Estimation' */
  DW_Generalcase_AR_Drone_Fligh_T Generalcase_e;/* '<S129>/General case' */
  DW_Phipi_AR_Drone_Flight_Cont_T Phipi_i;/* '<S129>/Phi == pi' */
  DW_AxisRotDefault_AR_Drone_Fl_T AxisRotDefault_d;/* '<S122>/AxisRotDefault' */
  DW_AxisRotZeroR3_AR_Drone_Fli_T AxisRotZeroR3_o;/* '<S122>/AxisRotZeroR3' */
  DW_Chart_AR_Drone_Flight_Cont_T sf_Chart_ci;/* '<S105>/Chart' */
  DW_Chart_AR_Drone_Flight_Cont_T sf_Chart_m;/* '<S99>/Chart' */
  DW_Chart_AR_Drone_Flight_Cont_T sf_Chart_k;/* '<S93>/Chart' */
  DW_Chart_AR_Drone_Flight_Cont_T sf_Chart_c;/* '<S87>/Chart' */
  DW_Chart_AR_Drone_Flight_Cont_T sf_Chart;/* '<S81>/Chart' */
  DW_Motor_Mixing_AR_Drone_Flig_T Motor_Mixing;/* '<S39>/Motor_Mixing' */
  DW_Attitude_Control_AR_Drone__T Attitude_Control;/* '<S39>/Attitude_Control' */
  DW_Altitude_Control_AR_Drone__T Altitude_Control;/* '<S39>/Altitude_Control' */
  DW_Generalcase_AR_Drone_Fligh_T Generalcase;/* '<S19>/General case' */
  DW_Phipi_AR_Drone_Flight_Cont_T Phipi;/* '<S19>/Phi == pi' */
  DW_Generalcase_AR_Drone_Fligh_T Generalcase_m;/* '<S18>/General case' */
  DW_Phipi_AR_Drone_Flight_Cont_T Phipi_m;/* '<S18>/Phi == pi' */
  DW_AxisRotDefault_AR_Drone_Fl_T AxisRotDefault;/* '<S10>/AxisRotDefault' */
  DW_AxisRotZeroR3_AR_Drone_Fli_T AxisRotZeroR3;/* '<S10>/AxisRotZeroR3' */
} DW_AR_Drone_Flight_Control_T;

/* Parameters for system: '<S18>/Phi == pi' */
struct P_Phipi_AR_Drone_Flight_Contr_T_ {
  real_T Shiftright_table[24];         /* Expression: [1 1 1;-1 1 1;1 1 -1;1 1 1;1 -1 1;1 1 1;1 1 1;1 1 1]
                                        * Referenced by: '<S32>/Shift right'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T Pi1_Value[3];                 /* Expression: [1 1 1]
                                        * Referenced by: '<S32>/Pi1'
                                        */
  real_T VRRot_Pi_Y0[4];               /* Expression: [0 0 0 pi]
                                        * Referenced by: '<S31>/VRRot_Pi'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S32>/Switch'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S31>/Pi'
                                        */
};

/* Parameters for system: '<S18>/General case' */
struct P_Generalcase_AR_Drone_Flight_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S29>/Gain'
                                        */
};

/* Parameters for system: '<S39>/Altitude_Control' */
struct P_Altitude_Control_AR_Drone_F_T_ {
  real_T PID_Smooth_D;                 /* Mask Parameter: PID_Smooth_D
                                        * Referenced by: '<S46>/Derivative Gain'
                                        */
  real_T PID_Smooth_I;                 /* Mask Parameter: PID_Smooth_I
                                        * Referenced by: '<S46>/Integral Gain'
                                        */
  real_T PID_Smooth_LowerSaturationLimit;/* Mask Parameter: PID_Smooth_LowerSaturationLimit
                                          * Referenced by:
                                          *   '<S46>/Saturation'
                                          *   '<S48>/DeadZone'
                                          */
  real_T PID_Smooth_N;                 /* Mask Parameter: PID_Smooth_N
                                        * Referenced by: '<S46>/Filter Coefficient'
                                        */
  real_T PID_Smooth_P;                 /* Mask Parameter: PID_Smooth_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
  real_T PID_Smooth_UpperSaturationLimit;/* Mask Parameter: PID_Smooth_UpperSaturationLimit
                                          * Referenced by:
                                          *   '<S46>/Saturation'
                                          *   '<S48>/DeadZone'
                                          */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T ReCalibrate_UpperSat;         /* Expression: 200
                                        * Referenced by: '<S40>/Re-Calibrate'
                                        */
  real_T ReCalibrate_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S40>/Re-Calibrate'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S46>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S46>/Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S48>/Gain'
                                        */
};

/* Parameters for system: '<S39>/Attitude_Control' */
struct P_Attitude_Control_AR_Drone_F_T_ {
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S57>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S57>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S60>/UD'
                                          */
  real_T PIDController1_LowerSaturationL;/* Mask Parameter: PIDController1_LowerSaturationL
                                          * Referenced by:
                                          *   '<S57>/Saturation'
                                          *   '<S59>/DeadZone'
                                          */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S57>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S57>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;/* Mask Parameter: PIDController1_UpperSaturationL
                                          * Referenced by:
                                          *   '<S57>/Saturation'
                                          *   '<S59>/DeadZone'
                                          */
  real_T DigitalLowPassFilter2_NumCoef;/* Expression: [0.04877]
                                        * Referenced by: '<S54>/Digital Low Pass Filter2'
                                        */
  real_T DigitalLowPassFilter2_DenCoef[2];/* Expression: [1 -0.9512]
                                           * Referenced by: '<S54>/Digital Low Pass Filter2'
                                           */
  real_T DigitalLowPassFilter2_InitialSt;/* Expression: 0
                                          * Referenced by: '<S54>/Digital Low Pass Filter2'
                                          */
  real_T DigitalLowPassFilter1_NumCoef;/* Expression: [0.04877]
                                        * Referenced by: '<S54>/Digital Low Pass Filter1'
                                        */
  real_T DigitalLowPassFilter1_DenCoef[2];/* Expression: [1 -0.9512]
                                           * Referenced by: '<S54>/Digital Low Pass Filter1'
                                           */
  real_T DigitalLowPassFilter1_InitialSt;/* Expression: 0
                                          * Referenced by: '<S54>/Digital Low Pass Filter1'
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S57>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S57>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S57>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S57>/Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S60>/TSamp'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S41>/Constant'
                                        */
  real32_T Gain4_Gain[2];              /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S51>/Gain4'
                                        */
  real32_T OffsetConstants_Value[2];   /* Computed Parameter: OffsetConstants_Value
                                        * Referenced by: '<S50>/Offset Constants'
                                        */
  real32_T Gain_Gain_n[2];             /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S41>/Gain'
                                        */
  real32_T Saturation3_UpperSat[2];    /* Computed Parameter: Saturation3_UpperSat
                                        * Referenced by: '<S41>/Saturation3'
                                        */
  real32_T Saturation3_LowerSat[2];    /* Computed Parameter: Saturation3_LowerSat
                                        * Referenced by: '<S41>/Saturation3'
                                        */
  real32_T InterChange_Axis_Gain;      /* Computed Parameter: InterChange_Axis_Gain
                                        * Referenced by: '<S52>/InterChange_Axis'
                                        */
  real32_T ToDegrees2_Gain;            /* Computed Parameter: ToDegrees2_Gain
                                        * Referenced by: '<S52>/To Degrees2'
                                        */
  real32_T Yaw_contribution_Gain;      /* Computed Parameter: Yaw_contribution_Gain
                                        * Referenced by: '<S52>/Yaw_contribution'
                                        */
  real32_T ToDegrees3_Gain;            /* Computed Parameter: ToDegrees3_Gain
                                        * Referenced by: '<S52>/To Degrees3'
                                        */
  real32_T Yaw_contribution1_Gain;     /* Computed Parameter: Yaw_contribution1_Gain
                                        * Referenced by: '<S52>/Yaw_contribution1'
                                        */
  int16_T Saturation_UpperSat;         /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
  int16_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
  int16_T controls_Y0;                 /* Computed Parameter: controls_Y0
                                        * Referenced by: '<S41>/controls'
                                        */
};

/* Parameters for system: '<S39>/Motor_Mixing' */
struct P_Motor_Mixing_AR_Drone_Fligh_T_ {
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S44>/Switch1'
                                        */
  real_T MotorCommands_Y0;             /* Expression: 0
                                        * Referenced by: '<S44>/MotorCommands'
                                        */
  real_T Constant2_Value[4];           /* Expression: [55 55 55 55]*0.4
                                        * Referenced by: '<S44>/Constant2'
                                        */
  int16_T Constant1_Value[4];          /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S44>/Constant1'
                                        */
  int16_T minThrottle_Value;           /* Computed Parameter: minThrottle_Value
                                        * Referenced by: '<S44>/minThrottle'
                                        */
  int16_T Gain_Gain[16];               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S44>/Gain'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S44>/Constant'
                                        */
};

/* Parameters (auto storage) */
struct P_AR_Drone_Flight_Control_T_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T CompareToConstant_const_b;    /* Mask Parameter: CompareToConstant_const_b
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S115>/Switch'
                                        */
  real_T NormalizeVector_maxzero_a;    /* Mask Parameter: NormalizeVector_maxzero_a
                                        * Referenced by: '<S116>/Switch'
                                        */
  real_T RotationMatrixtoVRMLRotation2_m;/* Mask Parameter: RotationMatrixtoVRMLRotation2_m
                                          * Referenced by: '<S19>/Phi == pi'
                                          */
  real_T RotationMatrixtoVRMLRotation1_m;/* Mask Parameter: RotationMatrixtoVRMLRotation1_m
                                          * Referenced by: '<S18>/Phi == pi'
                                          */
  real_T RotationMatrixtoVRMLRotation1_p;/* Mask Parameter: RotationMatrixtoVRMLRotation1_p
                                          * Referenced by: '<S129>/Phi == pi'
                                          */
  real_T VRRot_0_Y0[4];                /* Expression: [0 1 0 0]
                                        * Referenced by: '<S30>/VRRot_0'
                                        */
  real_T Trace3Phi0_Value[4];          /* Expression: [0 1 0 0]
                                        * Referenced by: '<S30>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_h[4];              /* Expression: [0 1 0 0]
                                        * Referenced by: '<S35>/VRRot_0'
                                        */
  real_T Trace3Phi0_Value_d[4];        /* Expression: [0 1 0 0]
                                        * Referenced by: '<S35>/Trace=3=>Phi=0'
                                        */
  real_T Delay_InitialCondition;       /* Expression: inf
                                        * Referenced by: '<S42>/Delay'
                                        */
  real_T dt_Gain;                      /* Expression: 1/400
                                        * Referenced by: '<S42>/dt'
                                        */
  real_T Delay_InitialCondition_e;     /* Expression: inf
                                        * Referenced by: '<S43>/Delay'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T HoldingValue_Value;           /* Expression: 50
                                        * Referenced by: '<S70>/Holding Value'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S81>/Constant2'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S89>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S87>/Constant2'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0
                                        * Referenced by: '<S90>/Delay'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S95>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S95>/Constant'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S93>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S99>/Constant2'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S102>/Delay'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S107>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S107>/Constant'
                                        */
  real_T Constant2_Value_n;            /* Expression: 1
                                        * Referenced by: '<S105>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S77>/Delay1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100e3
                                        * Referenced by: '<S77>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S77>/Saturation1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -0.5
                                        * Referenced by: '<S127>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 3
                                        * Referenced by: '<S127>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain3'
                                        */
  real_T VRRot_0_Y0_n[4];              /* Expression: [0 1 0 0]
                                        * Referenced by: '<S142>/VRRot_0'
                                        */
  real_T Trace3Phi0_Value_h[4];        /* Expression: [0 1 0 0]
                                        * Referenced by: '<S142>/Trace=3=>Phi=0'
                                        */
  real_T Constant1_Value_c;            /* Expression: -1
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: +1
                                        * Referenced by: '<S65>/Constant2'
                                        */
  real_T Constant2_Value_b;            /* Expression: +1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: -1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant1_Value_m;            /* Expression: -1
                                        * Referenced by: '<S69>/Constant1'
                                        */
  real_T Constant2_Value_gk;           /* Expression: +1
                                        * Referenced by: '<S69>/Constant2'
                                        */
  real_T Bias_Value;                   /* Expression: [4096]
                                        * Referenced by: '<S111>/Bias'
                                        */
  real_T NeutralBias_Value[3];         /* Expression: [2048 2048 2048]
                                        * Referenced by: '<S111>/Neutral Bias'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/512
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S112>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 1
                                        * Referenced by: '<S113>/Gain'
                                        */
  real_T Xwhenhorizontal_Value;        /* Expression: 0
                                        * Referenced by: '<S113>/X when horizontal'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S113>/Gain1'
                                        */
  real_T Ywhenhorizontal_Value;        /* Expression: 0
                                        * Referenced by: '<S113>/Y when horizontal'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S113>/Gain2'
                                        */
  real_T Zwhenhorizontal_Value;        /* Expression: -1
                                        * Referenced by: '<S113>/Z when horizontal'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 0.2
                                        * Referenced by: '<S114>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S114>/Unit Delay'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 0.8
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T Gain_Gain_i4[3];              /* Expression: [0.0609, 0.0609, 0.0609]
                                        * Referenced by: '<S121>/Gain'
                                        */
  real_T Gain1_Gain_d[3];              /* Expression: [-1 1 1]
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Gain2_Gain_k[2];              /* Expression: [-1 1]
                                        * Referenced by: '<S22>/Gain2'
                                        */
  real_T Gain3_Gain_m[2];              /* Expression: [1 1]
                                        * Referenced by: '<S22>/Gain3'
                                        */
  real_T Gain_Gain_ai;                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Constant2_Value_m[3];         /* Expression: [90 0 90]*pi/180*1
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant_Value_j[2];          /* Expression: [maxzero 1]
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Gain_Gain_n5;                 /* Expression: hex2dec('1FF')/100
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant_Value_e0[2];         /* Expression: [maxzero 1]
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain1_Gain_o[3];              /* Expression: [-1 1 1]
                                        * Referenced by: '<S132>/Gain1'
                                        */
  real_T Gain2_Gain_h[2];              /* Expression: [-1 1]
                                        * Referenced by: '<S132>/Gain2'
                                        */
  real_T Gain3_Gain_d[2];              /* Expression: [1 1]
                                        * Referenced by: '<S132>/Gain3'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T Constant_Value_d[2];          /* Expression: [maxzero 1]
                                        * Referenced by: '<S129>/Constant'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain1'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain2'
                                        */
  real_T Gain_Gain_ip;                 /* Expression: -1
                                        * Referenced by: '<S135>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 3
                                        * Referenced by: '<S123>/Gain1'
                                        */
  real_T Gain2_Gain_hl;                /* Expression: 1
                                        * Referenced by: '<S123>/Gain2'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 1
                                        * Referenced by: '<S123>/Gain3'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S125>/Gain2'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S125>/Gain3'
                                        */
  real_T DataStoreMemory_InitialValue[3];/* Expression: [0 0 0]
                                          * Referenced by: '<Root>/Data Store Memory'
                                          */
  real_T DataStoreMemory1_InitialValue[3];/* Expression: [0 0 0]
                                           * Referenced by: '<Root>/Data Store Memory1'
                                           */
  real_T DataStoreMemory2_InitialValue[2];/* Expression: [0 0]
                                           * Referenced by: '<Root>/Data Store Memory2'
                                           */
  real_T DataStoreMemory3_InitialValue[2];/* Expression: [0 0]
                                           * Referenced by: '<Root>/Data Store Memory3'
                                           */
  real32_T DeciVoltstoVolts_Gain;      /* Computed Parameter: DeciVoltstoVolts_Gain
                                        * Referenced by: '<S8>/Deci-Volts to Volts'
                                        */
  real32_T FilterBattVoltage_NumCoef;  /* Computed Parameter: FilterBattVoltage_NumCoef
                                        * Referenced by: '<S4>/FilterBattVoltage'
                                        */
  real32_T FilterBattVoltage_DenCoef[2];/* Computed Parameter: FilterBattVoltage_DenCoef
                                         * Referenced by: '<S4>/FilterBattVoltage'
                                         */
  real32_T FilterBattVoltage_InitialStates;/* Computed Parameter: FilterBattVoltage_InitialStates
                                            * Referenced by: '<S4>/FilterBattVoltage'
                                            */
  int32_T Constant_Value_oh;           /* Computed Parameter: Constant_Value_oh
                                        * Referenced by: '<S80>/Constant'
                                        */
  int32_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S86>/Constant'
                                        */
  int32_T Constant_Value_o4;           /* Computed Parameter: Constant_Value_o4
                                        * Referenced by: '<S92>/Constant'
                                        */
  int32_T Constant_Value_a1;           /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S98>/Constant'
                                        */
  int32_T Constant_Value_ad;           /* Computed Parameter: Constant_Value_ad
                                        * Referenced by: '<S104>/Constant'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S42>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S43>/Delay'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S79>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S84>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S90>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S96>/Delay'
                                        */
  uint32_T Delay_DelayLength_ao;       /* Computed Parameter: Delay_DelayLength_ao
                                        * Referenced by: '<S102>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S77>/Delay1'
                                        */
  Drone_StateModeType Constant_Value_b;/* Expression: Drone_StateModeType.Controlled_Flight
                                        * Referenced by: '<S67>/Constant'
                                        */
  Drone_StateModeType Constant_Value_a4;/* Expression: Drone_StateModeType.Landing_Sequence
                                         * Referenced by: '<S68>/Constant'
                                         */
  Drone_StateModeType Desired_Drone_StateMode_Initial;/* Expression: Drone_StateModeType.Landing_Sequence
                                                       * Referenced by: '<S5>/Desired_Drone_StateMode'
                                                       */
  int16_T DontchangeDesiredDrone_StateMod;/* Computed Parameter: DontchangeDesiredDrone_StateMod
                                           * Referenced by: '<S65>/Don't change Desired Drone_StateMode'
                                           */
  int16_T ChangeDesiredDrone_StateMode_Va;/* Computed Parameter: ChangeDesiredDrone_StateMode_Va
                                           * Referenced by: '<S65>/Change Desired Drone_StateMode'
                                           */
  int16_T Delay_InitialCondition_c;    /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S84>/Delay'
                                        */
  int16_T Constant_Value_ps;           /* Computed Parameter: Constant_Value_ps
                                        * Referenced by: '<S66>/Constant'
                                        */
  int16_T Memory_X0;                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S69>/Memory'
                                        */
  int16_T Memory_X0_c;                 /* Computed Parameter: Memory_X0_c
                                        * Referenced by: '<S66>/Memory'
                                        */
  int16_T UnitDelay_InitialCondition_h;/* Computed Parameter: UnitDelay_InitialCondition_h
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  int16_T NominalThrust_Value;         /* Computed Parameter: NominalThrust_Value
                                        * Referenced by: '<S4>/Nominal Thrust'
                                        */
  uint16_T Delay_InitialCondition_f;   /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S79>/Delay'
                                        */
  uint16_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S96>/Delay'
                                        */
  uint16_T BitwiseOperator_BitMask;    /* Expression: BitMask
                                        * Referenced by: '<S7>/Bitwise Operator'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Expression: BitMask
                                        * Referenced by: '<S7>/Bitwise Operator1'
                                        */
  int16_T Gain1_Gain_g;                /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S111>/Gain1'
                                        */
  int16_T Gain2_Gain_kk;               /* Computed Parameter: Gain2_Gain_kk
                                        * Referenced by: '<S111>/Gain2'
                                        */
  int16_T Gain3_Gain_o;                /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S111>/Gain3'
                                        */
  int16_T HostCommandMissionCommand_Gain;/* Computed Parameter: HostCommandMissionCommand_Gain
                                          * Referenced by: '<S66>/Host Command > Mission Command'
                                          */
  uint8_T SwitchtochangethecurrentDroneSt;/* Computed Parameter: SwitchtochangethecurrentDroneSt
                                           * Referenced by: '<S1>/Switch to change the current Drone State (it has to be down at the start)'
                                           */
  uint8_T DonottouchoncethisSimulinkisrun;/* Computed Parameter: DonottouchoncethisSimulinkisrun
                                           * Referenced by: '<Root>/Do not touch once this Simulink is running'
                                           */
  boolean_T UnitDelay_InitialCondition_k;/* Computed Parameter: UnitDelay_InitialCondition_k
                                          * Referenced by: '<S83>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_n;/* Computed Parameter: UnitDelay_InitialCondition_n
                                          * Referenced by: '<S89>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_h3;/* Computed Parameter: UnitDelay_InitialCondition_h3
                                           * Referenced by: '<S95>/Unit Delay'
                                           */
  boolean_T UnitDelay_InitialCondition_d;/* Computed Parameter: UnitDelay_InitialCondition_d
                                          * Referenced by: '<S101>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_hi;/* Computed Parameter: UnitDelay_InitialCondition_hi
                                           * Referenced by: '<S107>/Unit Delay'
                                           */
  boolean_T DataStoreMemory4_InitialValue;/* Expression: false
                                           * Referenced by: '<Root>/Data Store Memory4'
                                           */
  P_Generalcase_AR_Drone_Flight_T Generalcase_e;/* '<S129>/General case' */
  P_Phipi_AR_Drone_Flight_Contr_T Phipi_i;/* '<S129>/Phi == pi' */
  P_Motor_Mixing_AR_Drone_Fligh_T Motor_Mixing;/* '<S39>/Motor_Mixing' */
  P_Attitude_Control_AR_Drone_F_T Attitude_Control;/* '<S39>/Attitude_Control' */
  P_Altitude_Control_AR_Drone_F_T Altitude_Control;/* '<S39>/Altitude_Control' */
  P_Generalcase_AR_Drone_Flight_T Generalcase;/* '<S19>/General case' */
  P_Phipi_AR_Drone_Flight_Contr_T Phipi;/* '<S19>/Phi == pi' */
  P_Generalcase_AR_Drone_Flight_T Generalcase_m;/* '<S18>/General case' */
  P_Phipi_AR_Drone_Flight_Contr_T Phipi_m;/* '<S18>/Phi == pi' */
};

/* Real-time Model Data Structure */
struct tag_RTM_AR_Drone_Flight_Contr_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint32_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_P;

/* Block signals (auto storage) */
extern B_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_B;

/* Block states (auto storage) */
extern DW_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_DW;

/* Model block global parameters (auto storage) */
extern real_T rtP_Accelerometer_quick_calibration[3];/* Variable: Accelerometer_quick_calibration
                                                      * Referenced by: '<S4>/Supervisory Flight Controller'
                                                      */
extern real_T rtP_Gyrometer_quick_calibration[3];/* Variable: Gyrometer_quick_calibration
                                                  * Referenced by: '<S4>/Supervisory Flight Controller'
                                                  */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_J3crjymWSwWCQ8kQITIpr Accelerometer_360deg_calibration;/* Variable: Accelerometer_360deg_calibration
                                                                      * Referenced by:
                                                                      *   '<S112>/Accel_Calib_Gain'
                                                                      *   '<S112>/Accel_Calib_Offset'
                                                                      */
extern struct_J3crjymWSwWCQ8kQITIpr Magnetometer_calibration;/* Variable: Magnetometer_calibration
                                                              * Referenced by:
                                                              *   '<S118>/Constant'
                                                              *   '<S118>/Constant1'
                                                              */

/* External function called from main */
extern void AR_Drone_Flight_Control_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void AR_Drone_Flight_Control_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void AR_Drone_Flight_Control_initialize(void);
extern void AR_Drone_Flight_Control_step0(void);
extern void AR_Drone_Flight_Control_step1(void);
extern void AR_Drone_Flight_Control_step2(void);
extern void AR_Drone_Flight_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AR_Drone_Flight_Cont_T *const AR_Drone_Flight_Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AR_Drone_Flight_Control'
 * '<S1>'   : 'AR_Drone_Flight_Control/<External Mode>'
 * '<S2>'   : 'AR_Drone_Flight_Control/<Normal Mode>'
 * '<S3>'   : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization'
 * '<S4>'   : 'AR_Drone_Flight_Control/Flight Controller'
 * '<S5>'   : 'AR_Drone_Flight_Control/Flight Mission'
 * '<S6>'   : 'AR_Drone_Flight_Control/Inertial Measurement'
 * '<S7>'   : 'AR_Drone_Flight_Control/Motor Input'
 * '<S8>'   : 'AR_Drone_Flight_Control/Navigation'
 * '<S9>'   : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1'
 * '<S10>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Direction Cosine Matrix to Rotation Angles1'
 * '<S11>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Accel for SL3D '
 * '<S12>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Mag for SL3D '
 * '<S13>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axis Mag Project for SL3D'
 * '<S14>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Matrix Re-Order'
 * '<S15>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Normalize SL3D-DCM'
 * '<S16>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Angles to Direction Cosine Matrix'
 * '<S17>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Angles to Direction Cosine Matrix1'
 * '<S18>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1'
 * '<S19>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2'
 * '<S20>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Direction Cosine Matrix to Rotation Angles1/AxisRotDefault'
 * '<S21>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Direction Cosine Matrix to Rotation Angles1/AxisRotZeroR3'
 * '<S22>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Direction Cosine Matrix to Rotation Angles1/Get DCM Values'
 * '<S23>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Mag for SL3D /Home Drone'
 * '<S24>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Mag for SL3D /Subsystem'
 * '<S25>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Mag for SL3D /Work Drone'
 * '<S26>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Interchange Axes Mag for SL3D /Work Drone - supposed work drone .. not really'
 * '<S27>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S28>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Angles to Direction Cosine Matrix1/Create 3x3 Matrix'
 * '<S29>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1/General case'
 * '<S30>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1/Phi == 0'
 * '<S31>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1/Phi == pi'
 * '<S32>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1/Phi == pi/Logic for flipping axis signs'
 * '<S33>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation1/Phi == pi/Logic for flipping axis signs/Compare To Zero'
 * '<S34>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2/General case'
 * '<S35>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2/Phi == 0'
 * '<S36>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2/Phi == pi'
 * '<S37>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2/Phi == pi/Logic for flipping axis signs'
 * '<S38>'  : 'AR_Drone_Flight_Control/Data decomposition to 3D Visualization/SL3D Visualization1/Rotation Matrix to VRML Rotation2/Phi == pi/Logic for flipping axis signs/Compare To Zero'
 * '<S39>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller'
 * '<S40>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Altitude_Control'
 * '<S41>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control'
 * '<S42>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Drone_State.WaitForHost.checkConvergence'
 * '<S43>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Drone_State.WaitForHost.checkMove'
 * '<S44>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Motor_Mixing'
 * '<S45>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Altitude_Control/Discrete PID Controller _ WORKING1'
 * '<S46>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Altitude_Control/PID_Smooth'
 * '<S47>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Altitude_Control/Discrete PID Controller _ WORKING1/Clamping circuit'
 * '<S48>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Altitude_Control/PID_Smooth/Clamping circuit'
 * '<S49>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/MATLAB Function'
 * '<S50>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Offset'
 * '<S51>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller'
 * '<S52>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Yaw Counter-Active Control'
 * '<S53>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Yaw Signal Builder '
 * '<S54>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Low Pass Filter'
 * '<S55>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Outer Loop Euler Angle Control Loop'
 * '<S56>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Outer Loop Euler Angle Control Loop/PID Controller'
 * '<S57>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Outer Loop Euler Angle Control Loop/PID Controller1'
 * '<S58>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Outer Loop Euler Angle Control Loop/PID Controller/Clamping circuit'
 * '<S59>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Roll Pitch Controller/Outer Loop Euler Angle Control Loop/PID Controller1/Clamping circuit'
 * '<S60>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Attitude_Control/Yaw Counter-Active Control/Discrete Derivative'
 * '<S61>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Drone_State.WaitForHost.checkConvergence/Compare To Constant'
 * '<S62>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Drone_State.WaitForHost.checkMove/Compare To Constant'
 * '<S63>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Motor_Mixing/RampDownInSpeed1'
 * '<S64>'  : 'AR_Drone_Flight_Control/Flight Controller/Supervisory Flight Controller/Motor_Mixing/Saturation Dynamic'
 * '<S65>'  : 'AR_Drone_Flight_Control/Flight Mission/Data Correction'
 * '<S66>'  : 'AR_Drone_Flight_Control/Flight Mission/Desired Drone_StateMode Management'
 * '<S67>'  : 'AR_Drone_Flight_Control/Flight Mission/Data Correction/Enumerated Constant'
 * '<S68>'  : 'AR_Drone_Flight_Control/Flight Mission/Data Correction/Enumerated Constant1'
 * '<S69>'  : 'AR_Drone_Flight_Control/Flight Mission/Desired Drone_StateMode Management/Data Correction'
 * '<S70>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing'
 * '<S71>'  : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation'
 * '<S72>'  : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization'
 * '<S73>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing'
 * '<S74>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer'
 * '<S75>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing'
 * '<S76>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter'
 * '<S77>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing'
 * '<S78>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/Calculate Accel Data'
 * '<S79>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction'
 * '<S80>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Compare To Zero'
 * '<S81>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse'
 * '<S82>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart'
 * '<S83>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Accelerometer Processing/CheckSum Correction/Generate Sample Holding Pulse/Transition Logic Detection'
 * '<S84>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/CheckSum Correction'
 * '<S85>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/Process Raw Mag Data'
 * '<S86>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/CheckSum Correction/Compare To Zero'
 * '<S87>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/CheckSum Correction/Generate Sample Holding Pulse'
 * '<S88>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/CheckSum Correction/Generate Sample Holding Pulse/Chart'
 * '<S89>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Magnetometer/CheckSum Correction/Generate Sample Holding Pulse/Transition Logic Detection'
 * '<S90>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/CheckSum Correction'
 * '<S91>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/Process Data'
 * '<S92>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/CheckSum Correction/Compare To Zero'
 * '<S93>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/CheckSum Correction/Generate Sample Holding Pulse'
 * '<S94>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart'
 * '<S95>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/RateGyro Processing/CheckSum Correction/Generate Sample Holding Pulse/Transition Logic Detection'
 * '<S96>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/CheckSum Correction'
 * '<S97>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/Process Raw Mag Data'
 * '<S98>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/CheckSum Correction/Compare To Zero'
 * '<S99>'  : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/CheckSum Correction/Generate Sample Holding Pulse'
 * '<S100>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/CheckSum Correction/Generate Sample Holding Pulse/Chart'
 * '<S101>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/TempFilter/CheckSum Correction/Generate Sample Holding Pulse/Transition Logic Detection'
 * '<S102>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/CheckSum Correction'
 * '<S103>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/Height Calculation'
 * '<S104>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/CheckSum Correction/Compare To Zero'
 * '<S105>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/CheckSum Correction/Generate Sample Holding Pulse'
 * '<S106>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/CheckSum Correction/Generate Sample Holding Pulse/Chart'
 * '<S107>' : 'AR_Drone_Flight_Control/Navigation/CheckSum Pre-Processing/Ultrasound Processing/CheckSum Correction/Generate Sample Holding Pulse/Transition Logic Detection'
 * '<S108>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector'
 * '<S109>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset'
 * '<S110>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Remove Offset'
 * '<S111>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector/Accelerometer Neutral Gain and Offset'
 * '<S112>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector/Calibration_GainOffset'
 * '<S113>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector/InitialCondition_Offset'
 * '<S114>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector/Low Pass Filter'
 * '<S115>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calculate Gravity Vector/Normalize Vector'
 * '<S116>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset/Normalize Vector'
 * '<S117>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset/Process Raw Mag Data'
 * '<S118>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset/Process Raw Mag Data/Process Raw Mag Data (Home_330453)'
 * '<S119>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset/Process Raw Mag Data/Process Raw Mag Data (Work_255725)'
 * '<S120>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Calibration_Scale_and_Offset/Process Raw Mag Data/Process Raw Mag Data (Work_255725)/Low Pass Filter1'
 * '<S121>' : 'AR_Drone_Flight_Control/Navigation/Data Conversion and Measurement Calculation/Remove Offset/Process Raw Rate Gyro Data'
 * '<S122>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Direction Cosine Matrix to Rotation Angles1'
 * '<S123>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Accel for SL3D '
 * '<S124>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Mag for SL3D '
 * '<S125>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axis Mag Project for SL3D'
 * '<S126>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Matrix Re-Order'
 * '<S127>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Normalize SL3D-DCM'
 * '<S128>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Angles to Direction Cosine Matrix'
 * '<S129>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1'
 * '<S130>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Direction Cosine Matrix to Rotation Angles1/AxisRotDefault'
 * '<S131>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Direction Cosine Matrix to Rotation Angles1/AxisRotZeroR3'
 * '<S132>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Direction Cosine Matrix to Rotation Angles1/Get DCM Values'
 * '<S133>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Mag for SL3D /Home Drone'
 * '<S134>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Mag for SL3D /Subsystem'
 * '<S135>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Mag for SL3D /Work Drone'
 * '<S136>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Interchange Axes Mag for SL3D /Work Drone - supposed work drone .. not really'
 * '<S137>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Normalize SL3D-DCM/3x3 Cross Product'
 * '<S138>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Normalize SL3D-DCM/3x3 Cross Product/Subsystem'
 * '<S139>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Normalize SL3D-DCM/3x3 Cross Product/Subsystem1'
 * '<S140>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S141>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1/General case'
 * '<S142>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1/Phi == 0'
 * '<S143>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1/Phi == pi'
 * '<S144>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1/Phi == pi/Logic for flipping axis signs'
 * '<S145>' : 'AR_Drone_Flight_Control/Navigation/SL3D Visualization/Rotation Matrix to VRML Rotation1/Phi == pi/Logic for flipping axis signs/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_AR_Drone_Flight_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
