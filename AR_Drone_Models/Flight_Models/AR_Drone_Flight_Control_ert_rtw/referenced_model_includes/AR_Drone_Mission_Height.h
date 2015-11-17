/*
 * File: AR_Drone_Mission_Height.h
 *
 * Code generated for Simulink model 'AR_Drone_Mission_Height'.
 *
 * Model version                  : 1.1120
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:17:25 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AR_Drone_Mission_Height_h_
#define RTW_HEADER_AR_Drone_Mission_Height_h_
#include <string.h>
#ifndef AR_Drone_Mission_Height_COMMON_INCLUDES_
# define AR_Drone_Mission_Height_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AR_Drone_Mission_Height_COMMON_INCLUDES_ */

#include "AR_Drone_Mission_Height_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Block states (auto storage) for model 'AR_Drone_Mission_Height' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<Root>/Flight Mission' */
  uint16_T temporalCounter_i2;         /* '<Root>/Flight Mission' */
  uint8_T is_active_c10_AR_Drone_Mission_;/* '<Root>/Flight Mission' */
  uint8_T is_Algorithm_Choice;         /* '<Root>/Flight Mission' */
  uint8_T is_active_Algorithm_Choice;  /* '<Root>/Flight Mission' */
  uint8_T is_Flight_Mission;           /* '<Root>/Flight Mission' */
  uint8_T is_Launch_Mission;           /* '<Root>/Flight Mission' */
  uint8_T is_active_Launch_Mission;    /* '<Root>/Flight Mission' */
  boolean_T Mission_On_Off;            /* '<Root>/Data Store Memory' */
} DW_AR_Drone_Mission_Height_f_T;

/* Parameters (auto storage) */
struct P_AR_Drone_Mission_Height_T_ {
  real_T AutoCalibrationON_OFF_Value;  /* Expression: 0
                                        * Referenced by: '<Root>/Auto-Calibration ON_OFF'
                                        */
  real_T AltitudeON_OFF_Value;         /* Expression: 1
                                        * Referenced by: '<Root>/Altitude ON_OFF'
                                        */
  real_T DesiredRollPitchYaw_Value[3]; /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Desired Roll-Pitch-Yaw'
                                        */
  real_T DesiredHeight_Value;          /* Expression: 70
                                        * Referenced by: '<Root>/Desired Height'
                                        */
  boolean_T DataStoreMemory_InitialValue;/* Computed Parameter: DataStoreMemory_InitialValue
                                          * Referenced by: '<Root>/Data Store Memory'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_AR_Drone_Mission_Heig_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_AR_Drone_Mission_Height_f_T rtdw;
  RT_MODEL_AR_Drone_Mission_Hei_T rtm;
} MdlrefDW_AR_Drone_Mission_Hei_T;

/* Model reference registration function */
extern void AR_Drone_Mission_Hei_initialize(const char_T **rt_errorStatus,
  RT_MODEL_AR_Drone_Mission_Hei_T *const AR_Drone_Mission_Height_M,
  DW_AR_Drone_Mission_Height_f_T *localDW);
extern void AR_Drone_Mission_Height_Init(DW_AR_Drone_Mission_Height_f_T *localDW);
extern void AR_Drone_Mission_Height_Start(DW_AR_Drone_Mission_Height_f_T
  *localDW);
extern void AR_Drone_Mission_Height(const boolean_T *rtu_Flight_Mission_On_Off,
  real_T *rty_AutoCalibration_ON_OFF, real_T *rty_Altitude_ON_OFF, real_T
  rty_Desired_Roll_Pitch_Yaw[3], real_T *rty_refHeight, real_T *rty_TakeOffLand,
  DW_AR_Drone_Mission_Height_f_T *localDW);

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
 * '<Root>' : 'AR_Drone_Mission_Height'
 * '<S1>'   : 'AR_Drone_Mission_Height/Flight Mission'
 */
#endif                                 /* RTW_HEADER_AR_Drone_Mission_Height_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
