/*
 * File: Navigation_KF_Subsystem_child.h
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

#ifndef RTW_HEADER_Navigation_KF_Subsystem_child_h_
#define RTW_HEADER_Navigation_KF_Subsystem_child_h_
#include <math.h>
#include <string.h>
#ifndef Navigation_KF_Subsystem_child_COMMON_INCLUDES_
# define Navigation_KF_Subsystem_child_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Navigation_KF_Subsystem_child_COMMON_INCLUDES_ */

#include "Navigation_KF_Subsystem_child_types.h"

/* Shared type includes */
#include "model_reference_types.h"
#include "fkngnophecjebaai_norm.h"
#include "rt_atan2d_snf.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block signals for model 'Navigation_KF_Subsystem_child' */
typedef struct {
  real_T dv0[9];
  real_T VectorConcatenate_h[9];       /* '<S13>/Vector Concatenate' */
  real_T dv1[9];
  real_T covariance_prediction[4];
  real_T covariance_prediction_m[4];
  real_T covariance_prediction_[4];
  real_T a[4];
  real_T I[4];
  real_T I_c[4];
  real_T I_k[4];
  real_T Gain2_f[3];                   /* '<S1>/Gain2' */
  real_T Rad2deg[3];                   /* '<S3>/Rad2deg' */
  real_T dv2[3];
  real_T rot_axis[2];
  real_T rtb_Gain2_f_c[2];
  real_T y;
  real_T Roll;                         /* '<S4>/MATLAB Function' */
  real_T Pitch;                        /* '<S4>/MATLAB Function' */
  real_T MathFunction1;                /* '<S27>/Math Function1' */
  real_T rtb_state_correction_i_b;
  real_T rtb_state_correction_c_p;
  real_T rtb_state_correction_i_idx_0;
  real_T rtb_state_correction_c_idx_0;
  real_T rtb_Gain1_c_idx_2;
  real_T rtb_Merge_idx_0;
  real_T rtb_VectorConcatenate_idx_3;
  real_T rtb_VectorConcatenate_idx_4;
  real_T rtb_state_correction_i_idx_1;
} B_Navigation_KF_Subsystem_c_c_T;

/* Block states (auto storage) for model 'Navigation_KF_Subsystem_child' */
typedef struct {
  real_T UnitDelay1_DSTATE[2];         /* '<S7>/Unit Delay1' */
  real_T UnitDelay_DSTATE[4];          /* '<S7>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b[2];       /* '<S6>/Unit Delay1' */
  real_T UnitDelay_DSTATE_m[4];        /* '<S6>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S1>/Unit Delay1' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S1>/Discrete-Time Integrator1' */
  real_T UnitDelay2_DSTATE[4];         /* '<S10>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_f[2];       /* '<S10>/Unit Delay1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S1>/Discrete-Time Integrator1' */
} DW_Navigation_KF_Subsystem__f_T;

/* Parameters (auto storage) */
struct P_Navigation_KF_Subsystem_chi_T_ {
  real_T NormalizeVector1_maxzero;     /* Mask Parameter: NormalizeVector1_maxzero
                                        * Referenced by: '<S27>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition[2];/* Expression: [0 0]'
                                         * Referenced by: '<S7>/Unit Delay1'
                                         */
  real_T UnitDelay_InitialCondition[4];/* Expression: eye(2)
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T UnitDelay1_InitialCondition_a[2];/* Expression: [0 0]'
                                           * Referenced by: '<S6>/Unit Delay1'
                                           */
  real_T UnitDelay_InitialCondition_c[4];/* Expression: eye(2)
                                          * Referenced by: '<S6>/Unit Delay'
                                          */
  real_T Gain5_Gain;                   /* Expression: -180/pi
                                        * Referenced by: '<S4>/Gain5'
                                        */
  real_T UnitDelay1_InitialCondition_f;/* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S1>/Discrete-Time Integrator1'
                                          */
  real_T ChangeSign_Gain;              /* Expression: -1
                                        * Referenced by: '<S3>/Change Sign'
                                        */
  real_T Rad2deg_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S3>/Rad2deg'
                                        */
  real_T Gain1_Gain[3];                /* Expression: [-1 1 1]
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real_T Gain2_Gain[2];                /* Expression: [-1 1]
                                        * Referenced by: '<S20>/Gain2'
                                        */
  real_T Gain3_Gain[2];                /* Expression: [1 1]
                                        * Referenced by: '<S20>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 5
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T deg_Value;                    /* Expression: 67
                                        * Referenced by: '<S26>/deg'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 5
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T UnitDelay2_InitialCondition[4];/* Expression: eye(2)
                                         * Referenced by: '<S10>/Unit Delay2'
                                         */
  real_T UnitDelay1_InitialCondition_d[2];/* Expression: [0 0 ]
                                           * Referenced by: '<S10>/Unit Delay1'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Navigation_KF_Subsyst_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Navigation_KF_Subsystem_c_c_T rtb;
  DW_Navigation_KF_Subsystem__f_T rtdw;
  RT_MODEL_Navigation_KF_Subsys_T rtm;
} MdlrefDW_Navigation_KF_Subsys_T;

/* Model reference registration function */
extern void Navigation_KF_Subsys_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Navigation_KF_Subsys_T *const Navigation_KF_Subsystem_chil_M,
  DW_Navigation_KF_Subsystem__f_T *localDW);
extern void Navigation_KF_Subsystem_ch_Init(DW_Navigation_KF_Subsystem__f_T
  *localDW);
extern void Navigation_KF_Subsystem_child(const Measurement_Calculation_Bus
  *rtu_IMU_Calculation_Data_Bus, real_T rty_Ultrasound_ctrl[2], real_T
  rty_Euler_Ctrl_deg[3], real_T rty_Gyro_Ctrl_deg[3], real_T rty_Accel_Norm[3],
  real_T rty_VRML_Visuals[9], real_T rty_DCM[9], B_Navigation_KF_Subsystem_c_c_T
  *localB, DW_Navigation_KF_Subsystem__f_T *localDW);

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
 * '<Root>' : 'Navigation_KF_Subsystem_child'
 * '<S1>'   : 'Navigation_KF_Subsystem_child/Kalman Filter'
 * '<S2>'   : 'Navigation_KF_Subsystem_child/Sensor Fusion1'
 * '<S3>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/Calculate DCM'
 * '<S4>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/Calculate Roll - Pitch'
 * '<S5>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert'
 * '<S6>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_PITCH'
 * '<S7>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_ROLL'
 * '<S8>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/Re-Align Yaw Axis'
 * '<S9>'   : 'Navigation_KF_Subsystem_child/Kalman Filter/Seperate Data'
 * '<S10>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Ultrasound Estimator'
 * '<S11>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations'
 * '<S12>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Calculate DCM/Rotation Angles to Direction Cosine Matrix'
 * '<S13>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Calculate DCM/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S14>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Calculate Roll - Pitch/MATLAB Function'
 * '<S15>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles'
 * '<S16>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles'
 * '<S17>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles/EulerAnglesCalculation'
 * '<S18>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/AxisRotDefault'
 * '<S19>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3'
 * '<S20>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/Get DCM Values'
 * '<S21>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_PITCH/Kalman Tracker'
 * '<S22>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_PITCH/Subsystem'
 * '<S23>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_ROLL/Kalman Tracker'
 * '<S24>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/KF_ROLL/Subsystem'
 * '<S25>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/Ultrasound Estimator/Kalman Tracker'
 * '<S26>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Magnetometer Heading Calculation'
 * '<S27>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Normalize Vector1'
 * '<S28>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Re-align X-axis'
 * '<S29>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Magnetometer Heading Calculation/Compensate  for Magnetic Declination  (~60 degrees in Boston)_'
 * '<S30>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Magnetometer Heading Calculation/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2'
 * '<S31>'  : 'Navigation_KF_Subsystem_child/Kalman Filter/VRML_Calculations/Magnetometer Heading Calculation/Transpose2'
 * '<S32>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate DCM'
 * '<S33>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector'
 * '<S34>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Roll - Pitch'
 * '<S35>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert'
 * '<S36>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_PITCH'
 * '<S37>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_ROLL'
 * '<S38>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing'
 * '<S39>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Process Raw Rate Gyro Data'
 * '<S40>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Re-Align Yaw Axis'
 * '<S41>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Remove Offset'
 * '<S42>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Seperate Data'
 * '<S43>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Ultrasound Estimator'
 * '<S44>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate DCM/Rotation Angles to Direction Cosine Matrix'
 * '<S45>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate DCM/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S46>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector/Accelerometer Neutral Gain and Offset'
 * '<S47>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector/Calibration_GainOffset'
 * '<S48>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector/InitialCondition_Offset'
 * '<S49>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector/Low Pass Filter'
 * '<S50>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Gravity Vector/Normalize Vector'
 * '<S51>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Calculate Roll - Pitch/MATLAB Function'
 * '<S52>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles'
 * '<S53>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles'
 * '<S54>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles/EulerAnglesCalculation'
 * '<S55>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/AxisRotDefault'
 * '<S56>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/AxisRotZeroR3'
 * '<S57>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Convert/DCM to Euler Angles/Direction Cosine Matrix to Rotation Angles/Get DCM Values'
 * '<S58>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_PITCH/Kalman Tracker'
 * '<S59>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_PITCH/Subsystem'
 * '<S60>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_ROLL/Kalman Tracker'
 * '<S61>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/KF_ROLL/Subsystem'
 * '<S62>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Magnetometer Heading Calculation'
 * '<S63>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Normalize Vector'
 * '<S64>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Normalize Vector1'
 * '<S65>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Process Raw Mag Data'
 * '<S66>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Re-align X-axis'
 * '<S67>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Magnetometer Heading Calculation/Compensate  for Magnetic Declination  (~60 degrees in Boston)_'
 * '<S68>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Magnetometer Heading Calculation/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2'
 * '<S69>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Magnetometer Heading Calculation/Transpose2'
 * '<S70>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Process Raw Mag Data/Process Raw Mag Data (Home_330453)'
 * '<S71>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Process Raw Mag Data/Process Raw Mag Data (Work_255725)'
 * '<S72>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Magnetometer Processing/Process Raw Mag Data/Process Raw Mag Data (Work_255725)/Low Pass Filter1'
 * '<S73>'  : 'Navigation_KF_Subsystem_child/Sensor Fusion1/Ultrasound Estimator/Kalman Tracker'
 */
#endif                                 /* RTW_HEADER_Navigation_KF_Subsystem_child_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
