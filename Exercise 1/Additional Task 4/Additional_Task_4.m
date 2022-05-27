%% Exercise 1(A) - Additional Task 4

%% Initial Setup

close all;
clear;
clc;

%% Field Controlled DC Motor

Vf = str2double(inputdlg('Enter field voltage value: ')); %12
Rf = str2double(inputdlg('Enter field resistance value: ')); %4.38
Lf = str2double(inputdlg('Enter field inductance value: ')); %2.15e-3
J = str2double(inputdlg('Enter inertia value: ')); %2.2e-4
B = str2double(inputdlg('Enter damping constant value: ')); %0.4
Kt = str2double(inputdlg('Enter torque constant value: ')); %1.94

s = tf('s');
G = Kt/(s*(Rf+(s*Lf))*(B+(s*J)));
System = Vf*G;

figure('Name','Response of Field Controlled DC Motor','NumberTitle','off');

% Impulse response
subplot(2,1,1);
impulse(System);
title('Impulse Response of Field Controlled DC Motor');
xlabel('Time');
ylabel('Angular Displacement');

% Step response
subplot(2,1,2);
step(System);
title('Step Response of Field Controlled DC Motor');
xlabel('Time');
ylabel('Angular Displacement');
