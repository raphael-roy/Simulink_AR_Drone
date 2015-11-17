/*
 * File: AR_Drone_Flight_Control_data.c
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

/* Model block global parameters (auto storage) */
real_T rtP_Accelerometer_quick_calibration[3] = { 0.003485, 0.008674, -0.9985 } ;/* Variable: Accelerometer_quick_calibration
                                                                      * Referenced by: '<S4>/Supervisory Flight Controller'
                                                                      */

real_T rtP_Gyrometer_quick_calibration[3] = { -10.63, 2.778, -0.1868 } ;/* Variable: Gyrometer_quick_calibration
                                                                      * Referenced by: '<S4>/Supervisory Flight Controller'
                                                                      */

/* Block parameters (auto storage) */
P_AR_Drone_Flight_Control_T AR_Drone_Flight_Control_P = {
  1.0E-5,                              /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S61>/Constant'
                                        */
  50.0,                                /* Mask Parameter: CompareToConstant_const_b
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S115>/Switch'
                                        */
  0.0,                                 /* Mask Parameter: NormalizeVector_maxzero_a
                                        * Referenced by: '<S116>/Switch'
                                        */
  1.0E-12,                             /* Mask Parameter: RotationMatrixtoVRMLRotation2_m
                                        * Referenced by: '<S19>/Phi == pi'
                                        */
  1.0E-12,                             /* Mask Parameter: RotationMatrixtoVRMLRotation1_m
                                        * Referenced by: '<S18>/Phi == pi'
                                        */
  1.0E-12,                             /* Mask Parameter: RotationMatrixtoVRMLRotation1_p
                                        * Referenced by: '<S129>/Phi == pi'
                                        */

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S30>/VRRot_0'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S30>/Trace=3=>Phi=0'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S35>/VRRot_0'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S35>/Trace=3=>Phi=0'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S42>/Delay'
                                        */
  0.0025,                              /* Expression: 1/400
                                        * Referenced by: '<S42>/dt'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S43>/Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S83>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S70>/Holding Value'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S81>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S89>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S87>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S95>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S95>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S93>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S101>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S101>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S102>/Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S107>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S107>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S105>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S77>/Delay1'
                                        */
  100000.0,                            /* Expression: 100e3
                                        * Referenced by: '<S77>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S77>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S115>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S116>/Constant'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S127>/Gain'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S127>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S127>/Gain3'
                                        */

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S142>/VRRot_0'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /*  Expression: [0 1 0 0]
   * Referenced by: '<S142>/Trace=3=>Phi=0'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S65>/Constant1'
                                        */
  1.0,                                 /* Expression: +1
                                        * Referenced by: '<S65>/Constant2'
                                        */
  1.0,                                 /* Expression: +1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S69>/Constant1'
                                        */
  1.0,                                 /* Expression: +1
                                        * Referenced by: '<S69>/Constant2'
                                        */
  4096.0,                              /* Expression: [4096]
                                        * Referenced by: '<S111>/Bias'
                                        */

  /*  Expression: [2048 2048 2048]
   * Referenced by: '<S111>/Neutral Bias'
   */
  { 2048.0, 2048.0, 2048.0 },
  0.001953125,                         /* Expression: 1/512
                                        * Referenced by: '<S111>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S112>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/X when horizontal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/Y when horizontal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/Gain2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S113>/Z when horizontal'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S114>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S114>/Unit Delay'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S114>/Gain'
                                        */

  /*  Expression: [0.0609, 0.0609, 0.0609]
   * Referenced by: '<S121>/Gain'
   */
  { 0.0609, 0.0609, 0.0609 },

  /*  Expression: [-1 1 1]
   * Referenced by: '<S22>/Gain1'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [-1 1]
   * Referenced by: '<S22>/Gain2'
   */
  { -1.0, 1.0 },

  /*  Expression: [1 1]
   * Referenced by: '<S22>/Gain3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain1'
                                        */

  /*  Expression: [90 0 90]*pi/180*1
   * Referenced by: '<S9>/Constant2'
   */
  { 1.5707963267948966, 0.0, 1.5707963267948966 },

  /*  Expression: [maxzero 1]
   * Referenced by: '<S19>/Constant'
   */
  { 1.0E-12, 1.0 },
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S7>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  5.11,                                /* Expression: hex2dec('1FF')/100
                                        * Referenced by: '<S7>/Gain'
                                        */

  /*  Expression: [maxzero 1]
   * Referenced by: '<S18>/Constant'
   */
  { 1.0E-12, 1.0 },

  /*  Expression: [-1 1 1]
   * Referenced by: '<S132>/Gain1'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [-1 1]
   * Referenced by: '<S132>/Gain2'
   */
  { -1.0, 1.0 },

  /*  Expression: [1 1]
   * Referenced by: '<S132>/Gain3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S72>/Gain'
                                        */

  /*  Expression: [maxzero 1]
   * Referenced by: '<S129>/Constant'
   */
  { 1.0E-12, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S135>/Gain2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S135>/Gain'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S123>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S123>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S123>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S125>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S125>/Gain3'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Data Store Memory'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Data Store Memory1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Data Store Memory2'
   */
  { 0.0, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<Root>/Data Store Memory3'
   */
  { 0.0, 0.0 },
  0.1F,                                /* Computed Parameter: DeciVoltstoVolts_Gain
                                        * Referenced by: '<S8>/Deci-Volts to Volts'
                                        */
  0.07226F,                            /* Computed Parameter: FilterBattVoltage_NumCoef
                                        * Referenced by: '<S4>/FilterBattVoltage'
                                        */

  /*  Computed Parameter: FilterBattVoltage_DenCoef
   * Referenced by: '<S4>/FilterBattVoltage'
   */
  { 1.0F, -0.9277F },
  0.0F,                                /* Computed Parameter: FilterBattVoltage_InitialStates
                                        * Referenced by: '<S4>/FilterBattVoltage'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_oh
                                        * Referenced by: '<S80>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S86>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_o4
                                        * Referenced by: '<S92>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S98>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_ad
                                        * Referenced by: '<S104>/Constant'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S42>/Delay'
                                        */
  40U,                                 /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S43>/Delay'
                                        */
  3U,                                  /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S79>/Delay'
                                        */
  3U,                                  /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S84>/Delay'
                                        */
  3U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S90>/Delay'
                                        */
  3U,                                  /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S96>/Delay'
                                        */
  3U,                                  /* Computed Parameter: Delay_DelayLength_ao
                                        * Referenced by: '<S102>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S77>/Delay1'
                                        */
  Drone_StateModeType_Controlled_Flight,/* Expression: Drone_StateModeType.Controlled_Flight
                                         * Referenced by: '<S67>/Constant'
                                         */
  Drone_StateModeType_Landing_Sequence,/* Expression: Drone_StateModeType.Landing_Sequence
                                        * Referenced by: '<S68>/Constant'
                                        */
  Drone_StateModeType_Landing_Sequence,/* Expression: Drone_StateModeType.Landing_Sequence
                                        * Referenced by: '<S5>/Desired_Drone_StateMode'
                                        */
  0,                                   /* Computed Parameter: DontchangeDesiredDrone_StateMod
                                        * Referenced by: '<S65>/Don't change Desired Drone_StateMode'
                                        */
  1,                                   /* Computed Parameter: ChangeDesiredDrone_StateMode_Va
                                        * Referenced by: '<S65>/Change Desired Drone_StateMode'
                                        */
  0,                                   /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S84>/Delay'
                                        */
  2,                                   /* Computed Parameter: Constant_Value_ps
                                        * Referenced by: '<S66>/Constant'
                                        */
  -1,                                  /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S69>/Memory'
                                        */
  -1,                                  /* Computed Parameter: Memory_X0_c
                                        * Referenced by: '<S66>/Memory'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_h
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  55,                                  /* Computed Parameter: NominalThrust_Value
                                        * Referenced by: '<S4>/Nominal Thrust'
                                        */
  0U,                                  /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S79>/Delay'
                                        */
  0U,                                  /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S96>/Delay'
                                        */
  511U,                                /* Expression: BitMask
                                        * Referenced by: '<S7>/Bitwise Operator'
                                        */
  32U,                                 /* Expression: BitMask
                                        * Referenced by: '<S7>/Bitwise Operator1'
                                        */
  -32768,                              /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S111>/Gain1'
                                        */
  -32768,                              /* Computed Parameter: Gain2_Gain_kk
                                        * Referenced by: '<S111>/Gain2'
                                        */
  -32768,                              /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S111>/Gain3'
                                        */
  16384,                               /* Computed Parameter: HostCommandMissionCommand_Gain
                                        * Referenced by: '<S66>/Host Command > Mission Command'
                                        */
  0U,                                  /* Computed Parameter: SwitchtochangethecurrentDroneSt
                                        * Referenced by: '<S1>/Switch to change the current Drone State (it has to be down at the start)'
                                        */
  0U,                                  /* Computed Parameter: DonottouchoncethisSimulinkisrun
                                        * Referenced by: '<Root>/Do not touch once this Simulink is running'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_k
                                        * Referenced by: '<S83>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_n
                                        * Referenced by: '<S89>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_h3
                                        * Referenced by: '<S95>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_d
                                        * Referenced by: '<S101>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition_hi
                                        * Referenced by: '<S107>/Unit Delay'
                                        */
  0,                                   /* Expression: false
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */

  /* Start of '<S129>/General case' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S141>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S141>/Gain1'
                                        */
    2.0                                /* Expression: 2
                                        * Referenced by: '<S141>/Gain'
                                        */
  }
  /* End of '<S129>/General case' */
  ,

  /* Start of '<S129>/Phi == pi' */
  {
    /*  Expression: [1 1 1;-1 1 1;1 1 -1;1 1 1;1 -1 1;1 1 1;1 1 1;1 1 1]
     * Referenced by: '<S144>/Shift right'
     */
    { 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
    -1.0,                              /* Expression: -1
                                        * Referenced by: '<S144>/Gain1'
                                        */

    /*  Expression: [1 1 1]
     * Referenced by: '<S144>/Pi1'
     */
    { 1.0, 1.0, 1.0 },

    /*  Expression: [0 0 0 pi]
     * Referenced by: '<S143>/VRRot_Pi'
     */
    { 0.0, 0.0, 0.0, 3.1415926535897931 },
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S143>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S143>/Gain'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S145>/Constant'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S144>/Switch'
                                        */
    3.1415926535897931                 /* Expression: pi
                                        * Referenced by: '<S143>/Pi'
                                        */
  }
  /* End of '<S129>/Phi == pi' */
  ,

  /* Start of '<S39>/Motor_Mixing' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S44>/Switch1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S44>/MotorCommands'
                                        */

    /*  Expression: [55 55 55 55]*0.4
     * Referenced by: '<S44>/Constant2'
     */
    { 22.0, 22.0, 22.0, 22.0 },

    /*  Computed Parameter: Constant1_Value
     * Referenced by: '<S44>/Constant1'
     */
    { 0, 0, 0, 0 },
    10,                                /* Computed Parameter: minThrottle_Value
                                        * Referenced by: '<S44>/minThrottle'
                                        */

    /*  Computed Parameter: Gain_Gain
     * Referenced by: '<S44>/Gain'
     */
    { 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1 },
    100                                /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S44>/Constant'
                                        */
  }
  /* End of '<S39>/Motor_Mixing' */
  ,

  /* Start of '<S39>/Attitude_Control' */
  {
    -0.011755,                         /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S57>/Derivative Gain'
                                        */
    0.27262,                           /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S57>/Integral Gain'
                                        */
    0.0,                               /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S60>/UD'
                                        */
    -30.0,                             /* Mask Parameter: PIDController1_LowerSaturationL
                                        * Referenced by:
                                        *   '<S57>/Saturation'
                                        *   '<S59>/DeadZone'
                                        */
    5.0,                               /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S57>/Filter Coefficient'
                                        */
    0.20168,                           /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S57>/Proportional Gain'
                                        */
    30.0,                              /* Mask Parameter: PIDController1_UpperSaturationL
                                        * Referenced by:
                                        *   '<S57>/Saturation'
                                        *   '<S59>/DeadZone'
                                        */
    0.04877,                           /* Expression: [0.04877]
                                        * Referenced by: '<S54>/Digital Low Pass Filter2'
                                        */

    /*  Expression: [1 -0.9512]
     * Referenced by: '<S54>/Digital Low Pass Filter2'
     */
    { 1.0, -0.9512 },
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S54>/Digital Low Pass Filter2'
                                        */
    0.04877,                           /* Expression: [0.04877]
                                        * Referenced by: '<S54>/Digital Low Pass Filter1'
                                        */

    /*  Expression: [1 -0.9512]
     * Referenced by: '<S54>/Digital Low Pass Filter1'
     */
    { 1.0, -0.9512 },
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S54>/Digital Low Pass Filter1'
                                        */
    0.0025,                            /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S57>/Integrator'
                                        */
    0.0,                               /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S57>/Integrator'
                                        */
    0.0025,                            /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S57>/Filter'
                                        */
    0.0,                               /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S57>/Filter'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S59>/Gain'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
    1.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S60>/TSamp'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S41>/Constant'
                                        */

    /*  Computed Parameter: Gain4_Gain
     * Referenced by: '<S51>/Gain4'
     */
    { 5.2F, 5.2F },

    /*  Computed Parameter: OffsetConstants_Value
     * Referenced by: '<S50>/Offset Constants'
     */
    { 0.0F, 0.0F },

    /*  Computed Parameter: Gain_Gain_n
     * Referenced by: '<S41>/Gain'
     */
    { -1.0F, -1.0F },

    /*  Computed Parameter: Saturation3_UpperSat
     * Referenced by: '<S41>/Saturation3'
     */
    { 25.0F, 25.0F },

    /*  Computed Parameter: Saturation3_LowerSat
     * Referenced by: '<S41>/Saturation3'
     */
    { -25.0F, -25.0F },
    -1.0F,                             /* Computed Parameter: InterChange_Axis_Gain
                                        * Referenced by: '<S52>/InterChange_Axis'
                                        */
    57.2957802F,                       /* Computed Parameter: ToDegrees2_Gain
                                        * Referenced by: '<S52>/To Degrees2'
                                        */
    5.0F,                              /* Computed Parameter: Yaw_contribution_Gain
                                        * Referenced by: '<S52>/Yaw_contribution'
                                        */
    1.0F,                              /* Computed Parameter: ToDegrees3_Gain
                                        * Referenced by: '<S52>/To Degrees3'
                                        */
    0.06F,                             /* Computed Parameter: Yaw_contribution1_Gain
                                        * Referenced by: '<S52>/Yaw_contribution1'
                                        */
    250,                               /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
    -250,                              /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
    0                                  /* Computed Parameter: controls_Y0
                                        * Referenced by: '<S41>/controls'
                                        */
  }
  /* End of '<S39>/Attitude_Control' */
  ,

  /* Start of '<S39>/Altitude_Control' */
  {
    0.16384634555838382,               /* Mask Parameter: PID_Smooth_D
                                        * Referenced by: '<S46>/Derivative Gain'
                                        */
    0.072544,                          /* Mask Parameter: PID_Smooth_I
                                        * Referenced by: '<S46>/Integral Gain'
                                        */
    -20.0,                             /* Mask Parameter: PID_Smooth_LowerSaturationLimit
                                        * Referenced by:
                                        *   '<S46>/Saturation'
                                        *   '<S48>/DeadZone'
                                        */
    12.5907330811849,                  /* Mask Parameter: PID_Smooth_N
                                        * Referenced by: '<S46>/Filter Coefficient'
                                        */
    0.34863231226544278,               /* Mask Parameter: PID_Smooth_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
    20.0,                              /* Mask Parameter: PID_Smooth_UpperSaturationLimit
                                        * Referenced by:
                                        *   '<S46>/Saturation'
                                        *   '<S48>/DeadZone'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S46>/Constant'
                                        */
    200.0,                             /* Expression: 200
                                        * Referenced by: '<S40>/Re-Calibrate'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S40>/Re-Calibrate'
                                        */
    0.0025,                            /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S46>/Integrator'
                                        */
    0.0,                               /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S46>/Integrator'
                                        */
    0.0025,                            /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S46>/Filter'
                                        */
    0.0,                               /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S46>/Filter'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S48>/Gain'
                                        */
  }
  /* End of '<S39>/Altitude_Control' */
  ,

  /* Start of '<S19>/General case' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S34>/Gain1'
                                        */
    2.0                                /* Expression: 2
                                        * Referenced by: '<S34>/Gain'
                                        */
  }
  /* End of '<S19>/General case' */
  ,

  /* Start of '<S19>/Phi == pi' */
  {
    /*  Expression: [1 1 1;-1 1 1;1 1 -1;1 1 1;1 -1 1;1 1 1;1 1 1;1 1 1]
     * Referenced by: '<S37>/Shift right'
     */
    { 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
    -1.0,                              /* Expression: -1
                                        * Referenced by: '<S37>/Gain1'
                                        */

    /*  Expression: [1 1 1]
     * Referenced by: '<S37>/Pi1'
     */
    { 1.0, 1.0, 1.0 },

    /*  Expression: [0 0 0 pi]
     * Referenced by: '<S36>/VRRot_Pi'
     */
    { 0.0, 0.0, 0.0, 3.1415926535897931 },
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S36>/Gain'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S38>/Constant'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S37>/Switch'
                                        */
    3.1415926535897931                 /* Expression: pi
                                        * Referenced by: '<S36>/Pi'
                                        */
  }
  /* End of '<S19>/Phi == pi' */
  ,

  /* Start of '<S18>/General case' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S29>/Gain1'
                                        */
    2.0                                /* Expression: 2
                                        * Referenced by: '<S29>/Gain'
                                        */
  }
  /* End of '<S18>/General case' */
  ,

  /* Start of '<S18>/Phi == pi' */
  {
    /*  Expression: [1 1 1;-1 1 1;1 1 -1;1 1 1;1 -1 1;1 1 1;1 1 1;1 1 1]
     * Referenced by: '<S32>/Shift right'
     */
    { 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
    -1.0,                              /* Expression: -1
                                        * Referenced by: '<S32>/Gain1'
                                        */

    /*  Expression: [1 1 1]
     * Referenced by: '<S32>/Pi1'
     */
    { 1.0, 1.0, 1.0 },

    /*  Expression: [0 0 0 pi]
     * Referenced by: '<S31>/VRRot_Pi'
     */
    { 0.0, 0.0, 0.0, 3.1415926535897931 },
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
    0.5,                               /* Expression: 0.5
                                        * Referenced by: '<S31>/Gain'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S32>/Switch'
                                        */
    3.1415926535897931                 /* Expression: pi
                                        * Referenced by: '<S31>/Pi'
                                        */
  }
  /* End of '<S18>/Phi == pi' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
