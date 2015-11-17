  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 26;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AR_Drone_Flight_Control_P)
    ;%
      section.nData     = 93;
      section.data(93)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.CompareToConstant_const
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.CompareToConstant_const_b
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.NormalizeVector_maxzero
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.NormalizeVector_maxzero_a
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation2_m
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation1_m
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.RotationMatrixtoVRMLRotation1_p
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.VRRot_0_Y0
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_P.Trace3Phi0_Value
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_P.VRRot_0_Y0_h
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 15;
	
	  ;% AR_Drone_Flight_Control_P.Trace3Phi0_Value_d
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 19;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 23;
	
	  ;% AR_Drone_Flight_Control_P.dt_Gain
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 24;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_e
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 25;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 26;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 27;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_g
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 28;
	
	  ;% AR_Drone_Flight_Control_P.HoldingValue_Value
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 29;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 30;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_o
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 31;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_a
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 32;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_j
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 33;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_p
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 34;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_i
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 35;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_h
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 36;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_a
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 37;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_k
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 38;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_e
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 39;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_g
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 40;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_h
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 41;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_a
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 42;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_c
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 43;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_n
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 44;
	
	  ;% AR_Drone_Flight_Control_P.Delay1_InitialCondition
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 45;
	
	  ;% AR_Drone_Flight_Control_P.Saturation1_UpperSat
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 46;
	
	  ;% AR_Drone_Flight_Control_P.Saturation1_LowerSat
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 47;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_o
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 48;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_f
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 49;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 50;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_p
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 51;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 52;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain
	  section.data(42).logicalSrcIdx = 43;
	  section.data(42).dtTransOffset = 53;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain
	  section.data(43).logicalSrcIdx = 44;
	  section.data(43).dtTransOffset = 54;
	
	  ;% AR_Drone_Flight_Control_P.VRRot_0_Y0_n
	  section.data(44).logicalSrcIdx = 45;
	  section.data(44).dtTransOffset = 55;
	
	  ;% AR_Drone_Flight_Control_P.Trace3Phi0_Value_h
	  section.data(45).logicalSrcIdx = 46;
	  section.data(45).dtTransOffset = 59;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_c
	  section.data(46).logicalSrcIdx = 47;
	  section.data(46).dtTransOffset = 63;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_e
	  section.data(47).logicalSrcIdx = 48;
	  section.data(47).dtTransOffset = 64;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_b
	  section.data(48).logicalSrcIdx = 49;
	  section.data(48).dtTransOffset = 65;
	
	  ;% AR_Drone_Flight_Control_P.Constant3_Value
	  section.data(49).logicalSrcIdx = 50;
	  section.data(49).dtTransOffset = 66;
	
	  ;% AR_Drone_Flight_Control_P.Constant1_Value_m
	  section.data(50).logicalSrcIdx = 51;
	  section.data(50).dtTransOffset = 67;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_gk
	  section.data(51).logicalSrcIdx = 52;
	  section.data(51).dtTransOffset = 68;
	
	  ;% AR_Drone_Flight_Control_P.Bias_Value
	  section.data(52).logicalSrcIdx = 53;
	  section.data(52).dtTransOffset = 69;
	
	  ;% AR_Drone_Flight_Control_P.NeutralBias_Value
	  section.data(53).logicalSrcIdx = 54;
	  section.data(53).dtTransOffset = 70;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_a
	  section.data(54).logicalSrcIdx = 55;
	  section.data(54).dtTransOffset = 73;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_n
	  section.data(55).logicalSrcIdx = 56;
	  section.data(55).dtTransOffset = 74;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_p
	  section.data(56).logicalSrcIdx = 57;
	  section.data(56).dtTransOffset = 75;
	
	  ;% AR_Drone_Flight_Control_P.Xwhenhorizontal_Value
	  section.data(57).logicalSrcIdx = 58;
	  section.data(57).dtTransOffset = 76;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_a
	  section.data(58).logicalSrcIdx = 59;
	  section.data(58).dtTransOffset = 77;
	
	  ;% AR_Drone_Flight_Control_P.Ywhenhorizontal_Value
	  section.data(59).logicalSrcIdx = 60;
	  section.data(59).dtTransOffset = 78;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_g
	  section.data(60).logicalSrcIdx = 61;
	  section.data(60).dtTransOffset = 79;
	
	  ;% AR_Drone_Flight_Control_P.Zwhenhorizontal_Value
	  section.data(61).logicalSrcIdx = 62;
	  section.data(61).dtTransOffset = 80;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_b
	  section.data(62).logicalSrcIdx = 63;
	  section.data(62).dtTransOffset = 81;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition
	  section.data(63).logicalSrcIdx = 64;
	  section.data(63).dtTransOffset = 82;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_i
	  section.data(64).logicalSrcIdx = 65;
	  section.data(64).dtTransOffset = 83;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_i4
	  section.data(65).logicalSrcIdx = 66;
	  section.data(65).dtTransOffset = 84;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_d
	  section.data(66).logicalSrcIdx = 67;
	  section.data(66).dtTransOffset = 87;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_k
	  section.data(67).logicalSrcIdx = 68;
	  section.data(67).dtTransOffset = 90;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain_m
	  section.data(68).logicalSrcIdx = 69;
	  section.data(68).dtTransOffset = 92;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_ai
	  section.data(69).logicalSrcIdx = 70;
	  section.data(69).dtTransOffset = 94;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_l
	  section.data(70).logicalSrcIdx = 71;
	  section.data(70).dtTransOffset = 95;
	
	  ;% AR_Drone_Flight_Control_P.Constant2_Value_m
	  section.data(71).logicalSrcIdx = 72;
	  section.data(71).dtTransOffset = 96;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_j
	  section.data(72).logicalSrcIdx = 73;
	  section.data(72).dtTransOffset = 99;
	
	  ;% AR_Drone_Flight_Control_P.Saturation_UpperSat
	  section.data(73).logicalSrcIdx = 74;
	  section.data(73).dtTransOffset = 101;
	
	  ;% AR_Drone_Flight_Control_P.Saturation_LowerSat
	  section.data(74).logicalSrcIdx = 75;
	  section.data(74).dtTransOffset = 102;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_n5
	  section.data(75).logicalSrcIdx = 76;
	  section.data(75).dtTransOffset = 103;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_e0
	  section.data(76).logicalSrcIdx = 77;
	  section.data(76).dtTransOffset = 104;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_o
	  section.data(77).logicalSrcIdx = 78;
	  section.data(77).dtTransOffset = 106;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_h
	  section.data(78).logicalSrcIdx = 79;
	  section.data(78).dtTransOffset = 109;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain_d
	  section.data(79).logicalSrcIdx = 80;
	  section.data(79).dtTransOffset = 111;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_d
	  section.data(80).logicalSrcIdx = 81;
	  section.data(80).dtTransOffset = 113;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_d
	  section.data(81).logicalSrcIdx = 82;
	  section.data(81).dtTransOffset = 114;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_f
	  section.data(82).logicalSrcIdx = 83;
	  section.data(82).dtTransOffset = 116;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_d
	  section.data(83).logicalSrcIdx = 84;
	  section.data(83).dtTransOffset = 117;
	
	  ;% AR_Drone_Flight_Control_P.Gain_Gain_ip
	  section.data(84).logicalSrcIdx = 85;
	  section.data(84).dtTransOffset = 118;
	
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_e
	  section.data(85).logicalSrcIdx = 86;
	  section.data(85).dtTransOffset = 119;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_hl
	  section.data(86).logicalSrcIdx = 87;
	  section.data(86).dtTransOffset = 120;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain_k
	  section.data(87).logicalSrcIdx = 88;
	  section.data(87).dtTransOffset = 121;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_b
	  section.data(88).logicalSrcIdx = 89;
	  section.data(88).dtTransOffset = 122;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain_b
	  section.data(89).logicalSrcIdx = 90;
	  section.data(89).dtTransOffset = 123;
	
	  ;% AR_Drone_Flight_Control_P.DataStoreMemory_InitialValue
	  section.data(90).logicalSrcIdx = 91;
	  section.data(90).dtTransOffset = 124;
	
	  ;% AR_Drone_Flight_Control_P.DataStoreMemory1_InitialValue
	  section.data(91).logicalSrcIdx = 92;
	  section.data(91).dtTransOffset = 127;
	
	  ;% AR_Drone_Flight_Control_P.DataStoreMemory2_InitialValue
	  section.data(92).logicalSrcIdx = 93;
	  section.data(92).dtTransOffset = 130;
	
	  ;% AR_Drone_Flight_Control_P.DataStoreMemory3_InitialValue
	  section.data(93).logicalSrcIdx = 94;
	  section.data(93).dtTransOffset = 132;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.DeciVoltstoVolts_Gain
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.FilterBattVoltage_NumCoef
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.FilterBattVoltage_DenCoef
	  section.data(3).logicalSrcIdx = 97;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.FilterBattVoltage_InitialStates
	  section.data(4).logicalSrcIdx = 98;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Constant_Value_oh
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_l
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_o4
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_a1
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_ad
	  section.data(5).logicalSrcIdx = 103;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_k
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_j
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_c
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_m
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_a
	  section.data(6).logicalSrcIdx = 109;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.Delay_DelayLength_ao
	  section.data(7).logicalSrcIdx = 110;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.Delay1_DelayLength
	  section.data(8).logicalSrcIdx = 111;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Constant_Value_b
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_a4
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Desired_Drone_StateMode_Initial
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.DontchangeDesiredDrone_StateMod
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.ChangeDesiredDrone_StateMode_Va
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_c
	  section.data(3).logicalSrcIdx = 117;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Constant_Value_ps
	  section.data(4).logicalSrcIdx = 118;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.Memory_X0
	  section.data(5).logicalSrcIdx = 119;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Memory_X0_c
	  section.data(6).logicalSrcIdx = 120;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_h
	  section.data(7).logicalSrcIdx = 121;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.NominalThrust_Value
	  section.data(8).logicalSrcIdx = 122;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_f
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Delay_InitialCondition_g
	  section.data(2).logicalSrcIdx = 124;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.BitwiseOperator_BitMask
	  section.data(3).logicalSrcIdx = 125;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.BitwiseOperator1_BitMask
	  section.data(4).logicalSrcIdx = 126;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Gain1_Gain_g
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Gain2_Gain_kk
	  section.data(2).logicalSrcIdx = 128;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Gain3_Gain_o
	  section.data(3).logicalSrcIdx = 129;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.HostCommandMissionCommand_Gain
	  section.data(4).logicalSrcIdx = 130;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.SwitchtochangethecurrentDroneSt
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.DonottouchoncethisSimulinkisrun
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_k
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_n
	  section.data(2).logicalSrcIdx = 134;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_h3
	  section.data(3).logicalSrcIdx = 135;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_d
	  section.data(4).logicalSrcIdx = 136;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.UnitDelay_InitialCondition_hi
	  section.data(5).logicalSrcIdx = 137;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.DataStoreMemory4_InitialValue
	  section.data(6).logicalSrcIdx = 138;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Generalcase_e.Constant_Value
	  section.data(1).logicalSrcIdx = 139;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase_e.Gain1_Gain
	  section.data(2).logicalSrcIdx = 140;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase_e.Gain_Gain
	  section.data(3).logicalSrcIdx = 141;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Shiftright_table
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Gain1_Gain
	  section.data(2).logicalSrcIdx = 143;
	  section.data(2).dtTransOffset = 24;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Pi1_Value
	  section.data(3).logicalSrcIdx = 144;
	  section.data(3).dtTransOffset = 25;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.VRRot_Pi_Y0
	  section.data(4).logicalSrcIdx = 145;
	  section.data(4).dtTransOffset = 28;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Constant_Value
	  section.data(5).logicalSrcIdx = 146;
	  section.data(5).dtTransOffset = 32;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Gain_Gain
	  section.data(6).logicalSrcIdx = 147;
	  section.data(6).dtTransOffset = 33;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Constant_Value_a
	  section.data(7).logicalSrcIdx = 148;
	  section.data(7).dtTransOffset = 34;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Switch_Threshold
	  section.data(8).logicalSrcIdx = 149;
	  section.data(8).dtTransOffset = 35;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_i.Pi_Value
	  section.data(9).logicalSrcIdx = 150;
	  section.data(9).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.Switch1_Threshold
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.MotorCommands_Y0
	  section.data(2).logicalSrcIdx = 152;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.Constant2_Value
	  section.data(3).logicalSrcIdx = 153;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.Constant1_Value
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.minThrottle_Value
	  section.data(2).logicalSrcIdx = 155;
	  section.data(2).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.Gain_Gain
	  section.data(3).logicalSrcIdx = 156;
	  section.data(3).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.Motor_Mixing.Constant_Value
	  section.data(4).logicalSrcIdx = 157;
	  section.data(4).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_D
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_I
	  section.data(2).logicalSrcIdx = 159;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DiscreteDerivative_ICPrevScaled
	  section.data(3).logicalSrcIdx = 160;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_LowerSaturationL
	  section.data(4).logicalSrcIdx = 161;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_N
	  section.data(5).logicalSrcIdx = 162;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_P
	  section.data(6).logicalSrcIdx = 163;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.PIDController1_UpperSaturationL
	  section.data(7).logicalSrcIdx = 164;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter2_NumCoef
	  section.data(8).logicalSrcIdx = 165;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter2_DenCoef
	  section.data(9).logicalSrcIdx = 166;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter2_InitialSt
	  section.data(10).logicalSrcIdx = 167;
	  section.data(10).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter1_NumCoef
	  section.data(11).logicalSrcIdx = 168;
	  section.data(11).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter1_DenCoef
	  section.data(12).logicalSrcIdx = 169;
	  section.data(12).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.DigitalLowPassFilter1_InitialSt
	  section.data(13).logicalSrcIdx = 170;
	  section.data(13).dtTransOffset = 14;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Integrator_gainval
	  section.data(14).logicalSrcIdx = 171;
	  section.data(14).dtTransOffset = 15;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Integrator_IC
	  section.data(15).logicalSrcIdx = 172;
	  section.data(15).dtTransOffset = 16;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Filter_gainval
	  section.data(16).logicalSrcIdx = 173;
	  section.data(16).dtTransOffset = 17;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Filter_IC
	  section.data(17).logicalSrcIdx = 174;
	  section.data(17).dtTransOffset = 18;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Gain_Gain
	  section.data(18).logicalSrcIdx = 175;
	  section.data(18).dtTransOffset = 19;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Constant_Value
	  section.data(19).logicalSrcIdx = 176;
	  section.data(19).dtTransOffset = 20;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.TSamp_WtEt
	  section.data(20).logicalSrcIdx = 177;
	  section.data(20).dtTransOffset = 21;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Constant_Value_d
	  section.data(21).logicalSrcIdx = 178;
	  section.data(21).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Gain4_Gain
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.OffsetConstants_Value
	  section.data(2).logicalSrcIdx = 180;
	  section.data(2).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Gain_Gain_n
	  section.data(3).logicalSrcIdx = 181;
	  section.data(3).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Saturation3_UpperSat
	  section.data(4).logicalSrcIdx = 182;
	  section.data(4).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Saturation3_LowerSat
	  section.data(5).logicalSrcIdx = 183;
	  section.data(5).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.InterChange_Axis_Gain
	  section.data(6).logicalSrcIdx = 184;
	  section.data(6).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.ToDegrees2_Gain
	  section.data(7).logicalSrcIdx = 185;
	  section.data(7).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Yaw_contribution_Gain
	  section.data(8).logicalSrcIdx = 186;
	  section.data(8).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.ToDegrees3_Gain
	  section.data(9).logicalSrcIdx = 187;
	  section.data(9).dtTransOffset = 13;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Yaw_contribution1_Gain
	  section.data(10).logicalSrcIdx = 188;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Saturation_UpperSat
	  section.data(1).logicalSrcIdx = 189;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.Saturation_LowerSat
	  section.data(2).logicalSrcIdx = 190;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Attitude_Control.controls_Y0
	  section.data(3).logicalSrcIdx = 191;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_D
	  section.data(1).logicalSrcIdx = 192;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_I
	  section.data(2).logicalSrcIdx = 193;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_LowerSaturationLimit
	  section.data(3).logicalSrcIdx = 194;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_N
	  section.data(4).logicalSrcIdx = 195;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_P
	  section.data(5).logicalSrcIdx = 196;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.PID_Smooth_UpperSaturationLimit
	  section.data(6).logicalSrcIdx = 197;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Constant_Value
	  section.data(7).logicalSrcIdx = 198;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.ReCalibrate_UpperSat
	  section.data(8).logicalSrcIdx = 199;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.ReCalibrate_LowerSat
	  section.data(9).logicalSrcIdx = 200;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Integrator_gainval
	  section.data(10).logicalSrcIdx = 201;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Integrator_IC
	  section.data(11).logicalSrcIdx = 202;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Filter_gainval
	  section.data(12).logicalSrcIdx = 203;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Filter_IC
	  section.data(13).logicalSrcIdx = 204;
	  section.data(13).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_P.Altitude_Control.Gain_Gain
	  section.data(14).logicalSrcIdx = 205;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Generalcase.Constant_Value
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase.Gain1_Gain
	  section.data(2).logicalSrcIdx = 207;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase.Gain_Gain
	  section.data(3).logicalSrcIdx = 208;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Phipi.Shiftright_table
	  section.data(1).logicalSrcIdx = 209;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Gain1_Gain
	  section.data(2).logicalSrcIdx = 210;
	  section.data(2).dtTransOffset = 24;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Pi1_Value
	  section.data(3).logicalSrcIdx = 211;
	  section.data(3).dtTransOffset = 25;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.VRRot_Pi_Y0
	  section.data(4).logicalSrcIdx = 212;
	  section.data(4).dtTransOffset = 28;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Constant_Value
	  section.data(5).logicalSrcIdx = 213;
	  section.data(5).dtTransOffset = 32;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Gain_Gain
	  section.data(6).logicalSrcIdx = 214;
	  section.data(6).dtTransOffset = 33;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Constant_Value_a
	  section.data(7).logicalSrcIdx = 215;
	  section.data(7).dtTransOffset = 34;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Switch_Threshold
	  section.data(8).logicalSrcIdx = 216;
	  section.data(8).dtTransOffset = 35;
	
	  ;% AR_Drone_Flight_Control_P.Phipi.Pi_Value
	  section.data(9).logicalSrcIdx = 217;
	  section.data(9).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Generalcase_m.Constant_Value
	  section.data(1).logicalSrcIdx = 218;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase_m.Gain1_Gain
	  section.data(2).logicalSrcIdx = 219;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_P.Generalcase_m.Gain_Gain
	  section.data(3).logicalSrcIdx = 220;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Shiftright_table
	  section.data(1).logicalSrcIdx = 221;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Gain1_Gain
	  section.data(2).logicalSrcIdx = 222;
	  section.data(2).dtTransOffset = 24;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Pi1_Value
	  section.data(3).logicalSrcIdx = 223;
	  section.data(3).dtTransOffset = 25;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.VRRot_Pi_Y0
	  section.data(4).logicalSrcIdx = 224;
	  section.data(4).dtTransOffset = 28;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Constant_Value
	  section.data(5).logicalSrcIdx = 225;
	  section.data(5).dtTransOffset = 32;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Gain_Gain
	  section.data(6).logicalSrcIdx = 226;
	  section.data(6).dtTransOffset = 33;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Constant_Value_a
	  section.data(7).logicalSrcIdx = 227;
	  section.data(7).dtTransOffset = 34;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Switch_Threshold
	  section.data(8).logicalSrcIdx = 228;
	  section.data(8).dtTransOffset = 35;
	
	  ;% AR_Drone_Flight_Control_P.Phipi_m.Pi_Value
	  section.data(9).logicalSrcIdx = 229;
	  section.data(9).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
	      
	    ;% Accelerometer_quick_calibration
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 0;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    paramMap.sections(23) = section;
	    clear section
	  
	      
	    ;% Gyrometer_quick_calibration
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 1;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    paramMap.sections(24) = section;
	    clear section
	  
	      
	    ;% Accelerometer_360deg_calibration
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 238;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    paramMap.sections(25) = section;
	    clear section
	  
	      
	    ;% Magnetometer_calibration
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 239;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    paramMap.sections(26) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 23;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AR_Drone_Flight_Control_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Desired_Roll_Pitch_Yaw
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.Merge
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_B.RateTransition
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_B.Merge_l
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 41;
	
	  ;% AR_Drone_Flight_Control_B.Merge_lg
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 45;
	
	  ;% AR_Drone_Flight_Control_B.RateTransition2
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 49;
	
	  ;% AR_Drone_Flight_Control_B.BodyFrame
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 53;
	
	  ;% AR_Drone_Flight_Control_B.BodyFrame_h
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 56;
	
	  ;% AR_Drone_Flight_Control_B.BodyFrame_o
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.FlightMission_o4
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.FlightMission_o5
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_B.HostCommandport7000_o1
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_B.TmpSignalConversionAtAttitudeVi
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_B.Gain
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_B.Multiply
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 9;
	
	  ;% AR_Drone_Flight_Control_B.Sum
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_B.Sum1
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 13;
	
	  ;% AR_Drone_Flight_Control_B.Sum2
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 14;
	
	  ;% AR_Drone_Flight_Control_B.Add
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 15;
	
	  ;% AR_Drone_Flight_Control_B.Sum_m
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 18;
	
	  ;% AR_Drone_Flight_Control_B.Sum1_p
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 19;
	
	  ;% AR_Drone_Flight_Control_B.Sum2_f
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 20;
	
	  ;% AR_Drone_Flight_Control_B.UltraSound
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 21;
	
	  ;% AR_Drone_Flight_Control_B.EulerAngles
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 23;
	
	  ;% AR_Drone_Flight_Control_B.ProcessedGyro
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 26;
	
	  ;% AR_Drone_Flight_Control_B.AccelNorm
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 29;
	
	  ;% AR_Drone_Flight_Control_B.Reshape
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 32;
	
	  ;% AR_Drone_Flight_Control_B.HoldingValue
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 41;
	
	  ;% AR_Drone_Flight_Control_B.IfTruewehavegooddataIffalseweha
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 42;
	
	  ;% AR_Drone_Flight_Control_B.MotorCmd
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 45;
	
	  ;% AR_Drone_Flight_Control_B.refHeight
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 49;
	
	  ;% AR_Drone_Flight_Control_B.HeightFeedback
	  section.data(23).logicalSrcIdx = 33;
	  section.data(23).dtTransOffset = 50;
	
	  ;% AR_Drone_Flight_Control_B.refHeight_d
	  section.data(24).logicalSrcIdx = 34;
	  section.data(24).dtTransOffset = 52;
	
	  ;% AR_Drone_Flight_Control_B.Desired_Attitude_Deg
	  section.data(25).logicalSrcIdx = 35;
	  section.data(25).dtTransOffset = 53;
	
	  ;% AR_Drone_Flight_Control_B.EulerAngle_Feedback_Deg
	  section.data(26).logicalSrcIdx = 36;
	  section.data(26).dtTransOffset = 56;
	
	  ;% AR_Drone_Flight_Control_B.RateGyro_Feedback_Deg
	  section.data(27).logicalSrcIdx = 37;
	  section.data(27).dtTransOffset = 59;
	
	  ;% AR_Drone_Flight_Control_B.Motor_Armed
	  section.data(28).logicalSrcIdx = 38;
	  section.data(28).dtTransOffset = 62;
	
	  ;% AR_Drone_Flight_Control_B.LandingPhase
	  section.data(29).logicalSrcIdx = 39;
	  section.data(29).dtTransOffset = 63;
	
	  ;% AR_Drone_Flight_Control_B.Motor_Armed_d
	  section.data(30).logicalSrcIdx = 40;
	  section.data(30).dtTransOffset = 64;
	
	  ;% AR_Drone_Flight_Control_B.Abs
	  section.data(31).logicalSrcIdx = 41;
	  section.data(31).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.FilterBattVoltage
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Drone_StateModeConversion
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.Drone_StateMode
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.RPYCmd
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.BatteryFault_Mode
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.SafeOrientation_Mode
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.DataTypeConversion4
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_B.throttle
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.HostCommandport7000_o2
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.ARDrone_Motor
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.DataTypeConversion5
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.Transition_Detect
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_B.Transition_Detect_d
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_B.Transition_Detect_b
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_B.Transition_Detect_l
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_B.Transition_Detect_lb
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_B.Compare
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_B.LogicalOperator1
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 9;
	
	  ;% AR_Drone_Flight_Control_B.Compare_l
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_B.LogicalOperator
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_MatrixReOrder_l.M_out
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_Chart_ci.output
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_Chart_m.output
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_Chart_k.output
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_Chart_c.output
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_Chart.output
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Motor_Mixing.Switch
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Attitude_Control.Sum
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.Attitude_Control.DataTypeConversion1
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_B.Attitude_Control.Saturation
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Altitude_Control.Error
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_B.Altitude_Control.Saturation
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.Altitude_Control.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_B.sf_MatrixReOrder.M_out
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 55;
    sectIdxOffset = 23;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AR_Drone_Flight_Control_DW)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_DW.Delay1_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_i
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_ir
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 136;
	
	  ;% AR_Drone_Flight_Control_DW.HostCommandport7000_NetworkLib
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 139;
	
	  ;% AR_Drone_Flight_Control_DW.Data_to_hostport25000_NetworkLi
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 276;
	
	  ;% AR_Drone_Flight_Control_DW.Drone_StateModeport24000_Networ
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 413;
	
	  ;% AR_Drone_Flight_Control_DW.Offset_Accel
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 550;
	
	  ;% AR_Drone_Flight_Control_DW.Offset_Gyro
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 553;
	
	  ;% AR_Drone_Flight_Control_DW.Input_ports
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 556;
	
	  ;% AR_Drone_Flight_Control_DW.Output_ports
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 558;
	
	  ;% AR_Drone_Flight_Control_DW.deltaThrottle
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 560;
	
	  ;% AR_Drone_Flight_Control_DW.height
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 561;
	
	  ;% AR_Drone_Flight_Control_DW.hoverHeight
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 562;
	
	  ;% AR_Drone_Flight_Control_DW.reset_offset_calc
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 563;
	
	  ;% AR_Drone_Flight_Control_DW.MotorArmed
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 564;
	
	  ;% AR_Drone_Flight_Control_DW.LandingPhase
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 565;
	
	  ;% AR_Drone_Flight_Control_DW.N
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 566;
	
	  ;% AR_Drone_Flight_Control_DW.Offset_Gyro_Current
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 567;
	
	  ;% AR_Drone_Flight_Control_DW.Offset_Value_Current
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 570;
	
	  ;% AR_Drone_Flight_Control_DW.Offset_Accel_Current
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 571;
	
	  ;% AR_Drone_Flight_Control_DW.BatteryFault
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 574;
	
	  ;% AR_Drone_Flight_Control_DW.OrientationFault
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 575;
	
	  ;% AR_Drone_Flight_Control_DW.Landing_Altitude
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 576;
	
	  ;% AR_Drone_Flight_Control_DW.Actual_Attitude
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 577;
	
	  ;% AR_Drone_Flight_Control_DW.A_x_sum
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 578;
	
	  ;% AR_Drone_Flight_Control_DW.A_y_sum
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 579;
	
	  ;% AR_Drone_Flight_Control_DW.A_z_sum
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 580;
	
	  ;% AR_Drone_Flight_Control_DW.Tick
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 581;
	
	  ;% AR_Drone_Flight_Control_DW.G_x_sum
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 582;
	
	  ;% AR_Drone_Flight_Control_DW.G_y_sum
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 583;
	
	  ;% AR_Drone_Flight_Control_DW.G_z_sum
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 584;
	
	  ;% AR_Drone_Flight_Control_DW.Tick_a
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 585;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.AttitudeView1_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.RecordThrustInput_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_DW.VRSink1_PWORK
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_DW.CompareCalibration_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 19;
	
	  ;% AR_Drone_Flight_Control_DW.CompareFilter_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 20;
	
	  ;% AR_Drone_Flight_Control_DW.CompareOffset_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 21;
	
	  ;% AR_Drone_Flight_Control_DW.BeforeAfter_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 22;
	
	  ;% AR_Drone_Flight_Control_DW.Scope1_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 23;
	
	  ;% AR_Drone_Flight_Control_DW.Scope3_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.FilterBattVoltage_states
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sfEvent
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Desired_Drone_StateMode
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_k
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_h
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_f
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Delay_DSTATE_l
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Memory_PreviousInput_i
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.throttle
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Thrust
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.Altitude_Thrust
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.temporalCounter_i3
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_p
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_f
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_j
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_kb
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.UnitDelay_DSTATE_e
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_k
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.Phi0_SubsysRanBC_n
	  section.data(3).logicalSrcIdx = 65;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckConv
	  section.data(4).logicalSrcIdx = 66;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.Drone_StateWaitForHostcheckMove
	  section.data(5).logicalSrcIdx = 67;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.is_active_c12_AR_Drone_Flight_C
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_Fault_Check
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_BatteryFault_Check
	  section.data(3).logicalSrcIdx = 70;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.is_BatteryNominal
	  section.data(4).logicalSrcIdx = 71;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.is_BatteryLow
	  section.data(5).logicalSrcIdx = 72;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_UltraSoundwarning_Che
	  section.data(6).logicalSrcIdx = 73;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_SafeOrientation_Check
	  section.data(7).logicalSrcIdx = 74;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_DW.is_GravityVectorCheck
	  section.data(8).logicalSrcIdx = 75;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_Drone_State
	  section.data(9).logicalSrcIdx = 76;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_DW.is_WaitForHost
	  section.data(10).logicalSrcIdx = 77;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AR_Drone_Flight_Control_DW.is_Controlled_Flight
	  section.data(11).logicalSrcIdx = 78;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_DW.is_Landing_Sequence
	  section.data(12).logicalSrcIdx = 79;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_Flight_Controls
	  section.data(13).logicalSrcIdx = 80;
	  section.data(13).dtTransOffset = 12;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_Attitude_Command
	  section.data(14).logicalSrcIdx = 81;
	  section.data(14).dtTransOffset = 13;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_Altitude_Command
	  section.data(15).logicalSrcIdx = 82;
	  section.data(15).dtTransOffset = 14;
	
	  ;% AR_Drone_Flight_Control_DW.is_active_MotorMixing_Command
	  section.data(16).logicalSrcIdx = 83;
	  section.data(16).dtTransOffset = 15;
	
	  ;% AR_Drone_Flight_Control_DW.temporalCounter_i2
	  section.data(17).logicalSrcIdx = 84;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Flight_Mission_On_Off
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.isStable
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.initDone
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.Converge_Flag
	  section.data(4).logicalSrcIdx = 88;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.Move
	  section.data(5).logicalSrcIdx = 89;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AR_Drone_Flight_Control_DW.A_x_sum_not_empty
	  section.data(6).logicalSrcIdx = 90;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AR_Drone_Flight_Control_DW.A_y_sum_not_empty
	  section.data(7).logicalSrcIdx = 91;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AR_Drone_Flight_Control_DW.A_z_sum_not_empty
	  section.data(8).logicalSrcIdx = 92;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AR_Drone_Flight_Control_DW.Tick_not_empty
	  section.data(9).logicalSrcIdx = 93;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AR_Drone_Flight_Control_DW.G_x_sum_not_empty
	  section.data(10).logicalSrcIdx = 94;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AR_Drone_Flight_Control_DW.G_y_sum_not_empty
	  section.data(11).logicalSrcIdx = 95;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AR_Drone_Flight_Control_DW.G_z_sum_not_empty
	  section.data(12).logicalSrcIdx = 96;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AR_Drone_Flight_Control_DW.Tick_not_empty_i
	  section.data(13).logicalSrcIdx = 97;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.FlightMission_DWORK1
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.KalmanFilterStateEstimation_DWO
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Generalcase_e.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Phipi_i.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.AxisRotDefault_d.AxisRotDefault_SubsysRanBC
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.AxisRotZeroR3_o.AxisRotZeroR3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_ci.sfEvent
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_ci.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_ci.is_active_c2_AR_Drone_Flight_Co
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_ci.is_c2_AR_Drone_Flight_Control
	  section.data(2).logicalSrcIdx = 107;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_ci.isStable
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_m.sfEvent
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_m.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_m.is_active_c2_AR_Drone_Flight_Co
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_m.is_c2_AR_Drone_Flight_Control
	  section.data(2).logicalSrcIdx = 112;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_m.isStable
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_k.sfEvent
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_k.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_k.is_active_c2_AR_Drone_Flight_Co
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_k.is_c2_AR_Drone_Flight_Control
	  section.data(2).logicalSrcIdx = 117;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_k.isStable
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_c.sfEvent
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_c.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_c.is_active_c2_AR_Drone_Flight_Co
	  section.data(1).logicalSrcIdx = 121;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_c.is_c2_AR_Drone_Flight_Control
	  section.data(2).logicalSrcIdx = 122;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart_c.isStable
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart.sfEvent
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart.is_active_c2_AR_Drone_Flight_Co
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.sf_Chart.is_c2_AR_Drone_Flight_Control
	  section.data(2).logicalSrcIdx = 127;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.sf_Chart.isStable
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Motor_Mixing.tempCmd
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Motor_Mixing.Motor_Mixing_SubsysRanBC
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.UD_DSTATE
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.DigitalLowPassFilter2_states
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.DigitalLowPassFilter1_states
	  section.data(3).logicalSrcIdx = 133;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Integrator_DSTATE
	  section.data(4).logicalSrcIdx = 134;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Filter_DSTATE
	  section.data(5).logicalSrcIdx = 135;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Recorded_Torque_Cmd_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.AttitudeCommand_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 137;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_ELAPS_T
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_PREV_T
	  section.data(2).logicalSrcIdx = 139;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Attitude_Control_SubsysRanBC
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Integrator_PrevResetState
	  section.data(2).logicalSrcIdx = 141;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AR_Drone_Flight_Control_DW.Attitude_Control.Filter_PrevResetState
	  section.data(3).logicalSrcIdx = 142;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.Integrator_DSTATE
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.Filter_DSTATE
	  section.data(2).logicalSrcIdx = 144;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.ControlEffort_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.HeightError_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 146;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_ELAPS_T
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_PREV_T
	  section.data(2).logicalSrcIdx = 148;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Altitude_Control.Altitude_Control_SubsysRanBC
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Generalcase.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(50) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Phipi.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(51) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Generalcase_m.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(52) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.Phipi_m.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(53) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.AxisRotDefault.AxisRotDefault_SubsysRanBC
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(54) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AR_Drone_Flight_Control_DW.AxisRotZeroR3.AxisRotZeroR3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(55) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 581685069;
  targMap.checksum1 = 2832571693;
  targMap.checksum2 = 2400547196;
  targMap.checksum3 = 314160428;

