/*
 * File: AR_Drone_Flight_Control_types.h
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

#ifndef RTW_HEADER_AR_Drone_Flight_Control_types_h_
#define RTW_HEADER_AR_Drone_Flight_Control_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#include "struct_J3crjymWSwWCQ8kQITIpr.h"
#include "IMU_Navdata.h"
#ifndef _DEFINED_TYPEDEF_FOR_Drone_StateModeType_
#define _DEFINED_TYPEDEF_FOR_Drone_StateModeType_

typedef enum {
  Drone_StateModeType_None = 0,        /* Default value */
  Drone_StateModeType_WaitForHost,
  Drone_StateModeType_Controlled_Flight,
  Drone_StateModeType_Landing_Sequence,
  Drone_StateModeType_Landing_Terminate
} Drone_StateModeType;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_BatteryFault_ModeType_
#define _DEFINED_TYPEDEF_FOR_BatteryFault_ModeType_

typedef enum {
  BatteryFault_ModeType_None = 0,      /* Default value */
  BatteryFault_ModeType_BatteryNominal,
  BatteryFault_ModeType_BatteryLow
} BatteryFault_ModeType;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SafeOrientation_ModeType_
#define _DEFINED_TYPEDEF_FOR_SafeOrientation_ModeType_

typedef enum {
  SafeOrientation_ModeType_None = 0,   /* Default value */
  SafeOrientation_ModeType_WaitForFlight,
  SafeOrientation_ModeType_GravityVectorCheck,
  SafeOrientation_ModeType_UnsafeOrientation
} SafeOrientation_ModeType;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Measurement_Calculation_Bus_
#define _DEFINED_TYPEDEF_FOR_Measurement_Calculation_Bus_

typedef struct {
  real_T UltraSound_Calculation;
  real_T AccelNorm_Calculation[3];
  real_T Gyro_Calculation[3];
  real_T Magnetometer_Calculation[3];
} Measurement_Calculation_Bus;

#endif

/* Parameters for system: '<S18>/Phi == pi' */
typedef struct P_Phipi_AR_Drone_Flight_Contr_T_ P_Phipi_AR_Drone_Flight_Contr_T;

/* Parameters for system: '<S18>/General case' */
typedef struct P_Generalcase_AR_Drone_Flight_T_ P_Generalcase_AR_Drone_Flight_T;

/* Parameters for system: '<S39>/Altitude_Control' */
typedef struct P_Altitude_Control_AR_Drone_F_T_ P_Altitude_Control_AR_Drone_F_T;

/* Parameters for system: '<S39>/Attitude_Control' */
typedef struct P_Attitude_Control_AR_Drone_F_T_ P_Attitude_Control_AR_Drone_F_T;

/* Parameters for system: '<S39>/Motor_Mixing' */
typedef struct P_Motor_Mixing_AR_Drone_Fligh_T_ P_Motor_Mixing_AR_Drone_Fligh_T;

/* Parameters (auto storage) */
typedef struct P_AR_Drone_Flight_Control_T_ P_AR_Drone_Flight_Control_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AR_Drone_Flight_Contr_T RT_MODEL_AR_Drone_Flight_Cont_T;

#endif                                 /* RTW_HEADER_AR_Drone_Flight_Control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
