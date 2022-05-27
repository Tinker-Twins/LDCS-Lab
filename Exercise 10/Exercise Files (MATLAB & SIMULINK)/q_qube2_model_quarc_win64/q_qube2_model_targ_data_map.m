  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (q_qube2_model_P)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.Jeq
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.Rm
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_P.km
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_P.kt
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube2_model_P.HILInitialize_analog_input_maxi
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube2_model_P.HILInitialize_analog_input_mini
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube2_model_P.HILInitialize_analog_output_max
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_qube2_model_P.HILInitialize_analog_output_min
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_qube2_model_P.HILInitialize_final_analog_outp
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_qube2_model_P.HILInitialize_final_other_outpu
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_qube2_model_P.HILInitialize_initial_analog_ou
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% q_qube2_model_P.HILInitialize_initial_other_out
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% q_qube2_model_P.HILInitialize_set_other_outputs
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% q_qube2_model_P.HILInitialize_set_other_outpu_a
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% q_qube2_model_P.HILInitialize_set_other_outpu_c
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% q_qube2_model_P.HILInitialize_set_other_outpu_l
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% q_qube2_model_P.HILInitialize_watchdog_analog_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% q_qube2_model_P.HILInitialize_watchdog_other_ou
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_P.HILInitialize_watchdog_digital_
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_P.HILReadEncoderTimebase_channels
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube2_model_P.HILInitialize_digital_output_ch
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube2_model_P.HILInitialize_encoder_channels
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube2_model_P.HILInitialize_other_output_chan
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 7;
	
	  ;% q_qube2_model_P.HILInitialize_quadrature
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 10;
	
	  ;% q_qube2_model_P.HILReadEncoderTimebase_samples_
	  section.data(9).logicalSrcIdx = 30;
	  section.data(9).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_inpu_j
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 36;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_outp_j
	  section.data(7).logicalSrcIdx = 37;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_outp_c
	  section.data(8).logicalSrcIdx = 38;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_outp_b
	  section.data(9).logicalSrcIdx = 39;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_outp_p
	  section.data(10).logicalSrcIdx = 40;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_out_py
	  section.data(11).logicalSrcIdx = 41;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_qube2_model_P.HILInitialize_set_analog_outp_i
	  section.data(12).logicalSrcIdx = 42;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_qube2_model_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 43;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_qube2_model_P.HILInitialize_set_clock_frequ_b
	  section.data(14).logicalSrcIdx = 44;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_qube2_model_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 45;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_qube2_model_P.HILInitialize_set_clock_param_h
	  section.data(16).logicalSrcIdx = 46;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 47;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_out_i
	  section.data(18).logicalSrcIdx = 48;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_out_j
	  section.data(19).logicalSrcIdx = 49;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_out_e
	  section.data(20).logicalSrcIdx = 50;
	  section.data(20).dtTransOffset = 19;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_ou_il
	  section.data(21).logicalSrcIdx = 51;
	  section.data(21).dtTransOffset = 20;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_out_p
	  section.data(22).logicalSrcIdx = 52;
	  section.data(22).dtTransOffset = 21;
	
	  ;% q_qube2_model_P.HILInitialize_set_digital_out_a
	  section.data(23).logicalSrcIdx = 53;
	  section.data(23).dtTransOffset = 22;
	
	  ;% q_qube2_model_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 54;
	  section.data(24).dtTransOffset = 23;
	
	  ;% q_qube2_model_P.HILInitialize_set_encoder_cou_h
	  section.data(25).logicalSrcIdx = 55;
	  section.data(25).dtTransOffset = 24;
	
	  ;% q_qube2_model_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 56;
	  section.data(26).dtTransOffset = 25;
	
	  ;% q_qube2_model_P.HILInitialize_set_encoder_par_m
	  section.data(27).logicalSrcIdx = 57;
	  section.data(27).dtTransOffset = 26;
	
	  ;% q_qube2_model_P.HILInitialize_set_other_outpu_i
	  section.data(28).logicalSrcIdx = 58;
	  section.data(28).dtTransOffset = 27;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 59;
	  section.data(29).dtTransOffset = 28;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_outputs_m
	  section.data(30).logicalSrcIdx = 60;
	  section.data(30).dtTransOffset = 29;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_outputs_h
	  section.data(31).logicalSrcIdx = 61;
	  section.data(31).dtTransOffset = 30;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_outputs_k
	  section.data(32).logicalSrcIdx = 62;
	  section.data(32).dtTransOffset = 31;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 63;
	  section.data(33).dtTransOffset = 32;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 64;
	  section.data(34).dtTransOffset = 33;
	
	  ;% q_qube2_model_P.HILInitialize_set_pwm_params__a
	  section.data(35).logicalSrcIdx = 65;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.SignalGenerator_Amplitude
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.SignalGenerator_Frequency
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_P.Gain_Gain
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_P.Constant_Value
	  section.data(4).logicalSrcIdx = 69;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube2_model_P.countstorad_Gain
	  section.data(5).logicalSrcIdx = 70;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube2_model_P.QUBEServoHardware_A
	  section.data(6).logicalSrcIdx = 71;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube2_model_P.QUBEServoHardware_C
	  section.data(7).logicalSrcIdx = 72;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_qube2_model_P.QUBEServoHardware_D
	  section.data(8).logicalSrcIdx = 73;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_qube2_model_P.theta_dot_IC
	  section.data(9).logicalSrcIdx = 74;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% q_qube2_model_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (q_qube2_model_B)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% q_qube2_model_B.Sum
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_B.countstorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_B.QUBEServoHardware
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_B.theta_dot
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube2_model_B.Inertia
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 5;
    sectIdxOffset = 1;
    
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
    ;% Auto data (q_qube2_model_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube2_model_DW.HILInitialize_FilterFrequency
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube2_model_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube2_model_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_qube2_model_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_DW.VmV_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_DW.speedrads_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% q_qube2_model_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube2_model_DW.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube2_model_DW.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube2_model_DW.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 4;
	
	  ;% q_qube2_model_DW.HILReadEncoderTimebase_Buffer
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 2042064729;
  targMap.checksum1 = 3290556664;
  targMap.checksum2 = 1403699113;
  targMap.checksum3 = 3226941293;

