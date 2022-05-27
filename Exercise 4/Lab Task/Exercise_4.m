%% Exercise 4 - System Compensation by Gain Tuning in Time Domain (Root Locus Technique)

clc;
clear;
close all;

z = input('Enter value of damping ratio: '); % 0.45594981
w = input('Enter value of natural frequency: '); % 1

s = tf('s');

Go = 1/((s^3)+(3*s^2)+(2*s)); % Open loop transfer function
Gc = feedback(Go,1); % Closed loop transfer function

figure('Name','Step Response of System Without Gain','NumberTitle','off');
step(Gc);

figure('Name','Root Locus','NumberTitle','off');
rlocus(Go);
sgrid(z,w); % Mark the dominant pole Sd

[k, poles] = rlocfind(Go);

G = feedback(Go*k,1); % Add gain to the system to make %Mp = 20%

figure('Name','Step Response of System With Gain','NumberTitle','off');
step(G);