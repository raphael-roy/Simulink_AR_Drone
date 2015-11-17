/*
 * File: AR_Drone_Mission_Height.c
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

#include "AR_Drone_Mission_Height.h"
#include "AR_Drone_Mission_Height_private.h"

/* Named constants for Chart: '<Root>/Flight Mission' */
#define AR_Drone_Mis_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AR_Drone_Miss_IN_Altitude_Climb ((uint8_T)1U)
#define AR_Drone_Miss_IN_Flight_Mission ((uint8_T)2U)
#define AR_Drone_Mission_He_IN_Take_Off ((uint8_T)2U)
#define AR_Drone_Mission_Height_IN_Land ((uint8_T)2U)
#define AR_Drone_Mission__IN_Do_Nothing ((uint8_T)1U)

P_AR_Drone_Mission_Height_T AR_Drone_Mission_Height_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Auto-Calibration ON_OFF'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Altitude ON_OFF'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Desired Roll-Pitch-Yaw'
   */
  { 0.0, 0.0, 0.0 },
  70.0,                                /* Expression: 70
                                        * Referenced by: '<Root>/Desired Height'
                                        */
  0                                    /* Computed Parameter: DataStoreMemory_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
};

/* Initial conditions for referenced model: 'AR_Drone_Mission_Height' */
void AR_Drone_Mission_Height_Init(DW_AR_Drone_Mission_Height_f_T *localDW)
{
  /* InitializeConditions for Chart: '<Root>/Flight Mission' */
  localDW->is_active_Algorithm_Choice = 0U;
  localDW->is_Algorithm_Choice = AR_Drone_Mis_IN_NO_ACTIVE_CHILD;
  localDW->is_Flight_Mission = AR_Drone_Mis_IN_NO_ACTIVE_CHILD;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_Launch_Mission = 0U;
  localDW->is_Launch_Mission = AR_Drone_Mis_IN_NO_ACTIVE_CHILD;
  localDW->temporalCounter_i2 = 0U;
  localDW->is_active_c10_AR_Drone_Mission_ = 0U;
}

/* Start for referenced model: 'AR_Drone_Mission_Height' */
void AR_Drone_Mission_Height_Start(DW_AR_Drone_Mission_Height_f_T *localDW)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  localDW->Mission_On_Off =
    AR_Drone_Mission_Height_P.DataStoreMemory_InitialValue;
}

/* Output and update for referenced model: 'AR_Drone_Mission_Height' */
void AR_Drone_Mission_Height(const boolean_T *rtu_Flight_Mission_On_Off, real_T *
  rty_AutoCalibration_ON_OFF, real_T *rty_Altitude_ON_OFF, real_T
  rty_Desired_Roll_Pitch_Yaw[3], real_T *rty_refHeight, real_T *rty_TakeOffLand,
  DW_AR_Drone_Mission_Height_f_T *localDW)
{
  /* DataStoreWrite: '<Root>/Data Store Write' */
  localDW->Mission_On_Off = *rtu_Flight_Mission_On_Off;

  /* Constant: '<Root>/Auto-Calibration ON_OFF' */
  *rty_AutoCalibration_ON_OFF =
    AR_Drone_Mission_Height_P.AutoCalibrationON_OFF_Value;

  /* Constant: '<Root>/Altitude ON_OFF' */
  *rty_Altitude_ON_OFF = AR_Drone_Mission_Height_P.AltitudeON_OFF_Value;

  /* Constant: '<Root>/Desired Roll-Pitch-Yaw' */
  rty_Desired_Roll_Pitch_Yaw[0] =
    AR_Drone_Mission_Height_P.DesiredRollPitchYaw_Value[0];
  rty_Desired_Roll_Pitch_Yaw[1] =
    AR_Drone_Mission_Height_P.DesiredRollPitchYaw_Value[1];
  rty_Desired_Roll_Pitch_Yaw[2] =
    AR_Drone_Mission_Height_P.DesiredRollPitchYaw_Value[2];

  /* Chart: '<Root>/Flight Mission' incorporates:
   *  Constant: '<Root>/Desired Height'
   */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 2047U) {
    localDW->temporalCounter_i2++;
  }

  /* Gateway: Flight Mission */
  /* During: Flight Mission */
  if (localDW->is_active_c10_AR_Drone_Mission_ == 0U) {
    /* Entry: Flight Mission */
    localDW->is_active_c10_AR_Drone_Mission_ = 1U;

    /* Entry Internal: Flight Mission */
    localDW->is_active_Algorithm_Choice = 1U;

    /* Entry Internal 'Algorithm_Choice': '<S1>:648' */
    /* Transition: '<S1>:654' */
    localDW->is_Algorithm_Choice = AR_Drone_Mission__IN_Do_Nothing;

    /* Entry 'Do_Nothing': '<S1>:653' */
    *rty_refHeight = 0.0;
    localDW->is_active_Launch_Mission = 1U;

    /* Entry Internal 'Launch_Mission': '<S1>:704' */
    /* Transition: '<S1>:709' */
    localDW->is_Launch_Mission = AR_Drone_Mission__IN_Do_Nothing;
    localDW->temporalCounter_i2 = 0U;

    /* Entry 'Do_Nothing': '<S1>:711' */
    *rty_TakeOffLand = 0.0;
  } else {
    /* During 'Algorithm_Choice': '<S1>:648' */
    if (localDW->is_Algorithm_Choice == AR_Drone_Mission__IN_Do_Nothing) {
      /* During 'Do_Nothing': '<S1>:653' */
      if (localDW->Mission_On_Off) {
        /* Transition: '<S1>:693' */
        localDW->is_Algorithm_Choice = AR_Drone_Miss_IN_Flight_Mission;

        /* Entry 'Flight_Mission': '<S1>:685' */
        *rty_TakeOffLand = 0.0;

        /* Entry Internal 'Flight_Mission': '<S1>:685' */
        /* Transition: '<S1>:686' */
        localDW->is_Flight_Mission = AR_Drone_Miss_IN_Altitude_Climb;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Altitude_Climb': '<S1>:691' */
        *rty_refHeight = AR_Drone_Mission_Height_P.DesiredHeight_Value;
      }
    } else {
      /* During 'Flight_Mission': '<S1>:685' */
      if (!localDW->Mission_On_Off) {
        /* Transition: '<S1>:692' */
        /* Exit Internal 'Flight_Mission': '<S1>:685' */
        localDW->is_Flight_Mission = AR_Drone_Mis_IN_NO_ACTIVE_CHILD;
        localDW->is_Algorithm_Choice = AR_Drone_Mission__IN_Do_Nothing;

        /* Entry 'Do_Nothing': '<S1>:653' */
        *rty_refHeight = 0.0;
        *rty_TakeOffLand = 0.0;
      } else if (localDW->is_Flight_Mission == AR_Drone_Miss_IN_Altitude_Climb)
      {
        /* During 'Altitude_Climb': '<S1>:691' */
        if (localDW->temporalCounter_i1 >= 800U) {
          /* Transition: '<S1>:719' */
          localDW->is_Flight_Mission = AR_Drone_Mission_Height_IN_Land;

          /* Entry 'Land': '<S1>:718' */
          *rty_TakeOffLand = -1.0;
        } else {
          *rty_refHeight = AR_Drone_Mission_Height_P.DesiredHeight_Value;
        }
      } else {
        /* During 'Land': '<S1>:718' */
      }
    }

    /* During 'Launch_Mission': '<S1>:704' */
    if ((localDW->is_Launch_Mission == AR_Drone_Mission__IN_Do_Nothing) &&
        (localDW->temporalCounter_i2 >= 2000U)) {
      /* During 'Do_Nothing': '<S1>:711' */
      /* Transition: '<S1>:715' */
      localDW->is_Launch_Mission = AR_Drone_Mission_He_IN_Take_Off;

      /* Entry 'Take_Off': '<S1>:713' */
      *rty_TakeOffLand = 1.0;
    } else {
      /* During 'Take_Off': '<S1>:713' */
    }
  }

  /* End of Chart: '<Root>/Flight Mission' */
}

/* Model initialize function */
void AR_Drone_Mission_Hei_initialize(const char_T **rt_errorStatus,
  RT_MODEL_AR_Drone_Mission_Hei_T *const AR_Drone_Mission_Height_M,
  DW_AR_Drone_Mission_Height_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(AR_Drone_Mission_Height_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_AR_Drone_Mission_Height_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
