%% Initial Setup

close all;
clear;
clc;

%% First Order Mechanical System

M = input('Enter mass value: '); %1000
B = input('Enter damping coefficient value: '); %50
F = input('Enter force value: '); %500

s = tf('s');
G = 1/((M*s)+B);
System = F*G;

ltiview(System);

%% First Order Electrical System

R = input('Enter resistance value: '); %2e3
C = input('Enter capacitance value: '); %0.01
V = input('Enter voltage value: '); %12

s = tf('s');
G = 1/((R*C*s)+1);
System = V*G;

ltiview(System);

%% Second Order Mechanical System

M = input('Enter mass value: '); %1000
B = input('Enter damping coefficient value: '); %50
K = input('Enter spring constant value: '); %10
F = input('Enter force value: '); %500

s = tf('s');
G = 1/((M*(s^2))+(B*s)+K);
System = F*G;

ltiview(System);

%% Second Order Electrical System

R = input('Enter resistance value: '); %2e3
L = input('Enter inductance value: '); %50e-3
C = input('Enter capacitance value: '); %0.01
V = input('Enter voltage value: '); %12

s = tf('s');
G = 1/((L*C*(s^2))+(R*C*s)+1);
System = V*G;

ltiview(System);

%% Effect of Damping Ratio Variation

Wn = 1; %Natural frequency
z = input('Enter damping ratio value: '); %Damping ratio: 0.1, 0.4, 0.7, 1.0, 2.0

s = tf('s');
System = (Wn^2)/((s^2)+(2*z*Wn*s)+(Wn^2));

ltiview(System);