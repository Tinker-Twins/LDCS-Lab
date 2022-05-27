%% Exercise 1(A) - In-Lab Task

%% Initial Setup

close all;
clear;
clc;

%% 1. Mechanical System

F = str2double(inputdlg('Enter force value: ')); %300
M = str2double(inputdlg('Enter mass value: ')); %750
B = str2double(inputdlg('Enter dashpot constant value: ')); %30
K = str2double(inputdlg('Enter spring constant value: ')); %0

s = tf('s');
G = 1/((M*s^2)+(B*s)+K);
System = F*G;

figure('Name','Response of Mechanical System','NumberTitle','off');

% Impulse response
subplot(2,1,1);
impulse(System);
title('Impulse Response of Mechanical System');
xlabel('Time');
ylabel('Displacement');

% Step response
subplot(2,1,2);
step(System);
title('Step Response of Mechanical System');
xlabel('Time');
ylabel('Displacement');

%% 2. Electrical System

V = str2double(inputdlg('Enter voltage value: ')); %12
R = str2double(inputdlg('Enter resistance value: ')); %1e3
C = str2double(inputdlg('Enter capacitance value: ')); %160e-6

s = tf('s');
G = 1/(((R^2)*(C^2)*(s^2))+(3*R*C*s)+1);
System = V*G;

figure('Name','Response of Electrical System','NumberTitle','off');

% Impulse response
subplot(2,1,1);
impulse(System);
title('Impulse Response of Electrical System');
xlabel('Time');
ylabel('Voltage');

% Step response
subplot(2,1,2);
step(System);
title('Step Response of Electrical System');
xlabel('Time');
ylabel('Voltage');

%% 3. Electromechanical System

Va = str2double(inputdlg('Enter armature voltage value: ')); %12
Ra = str2double(inputdlg('Enter armature resistance value: ')); %4.38
La = str2double(inputdlg('Enter armature inductance value: ')); %2.15e-3
J = str2double(inputdlg('Enter inertia value: ')); %2.2e-4
B = str2double(inputdlg('Enter damping constant value: ')); %0.4
Kt = str2double(inputdlg('Enter torque constant value: ')); %1.94
Kb = str2double(inputdlg('Enter back e.m.f. constant value: ')); %1.43

s = tf('s');
G = Kt/(((Ra+(La*s))*((J*s^2)+(B*s)))+(Kt*Kb*s));
System = Va*G;

figure('Name','Response of Electromechanical System','NumberTitle','off');

% Impulse response
subplot(2,1,1);
impulse(System);
title('Impulse Response of Electromechanical System');
xlabel('Time');
ylabel('Angular Displacement');

% Step response
subplot(2,1,2);
step(System);
title('Step Response of Electromechanical System');
xlabel('Time');
ylabel('Angular Displacement');
