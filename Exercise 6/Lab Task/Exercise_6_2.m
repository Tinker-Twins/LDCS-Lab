%% Exercise 6

clc;
close all;
clear;

s = tf('s');

% Open Loop System
Go = 100/((s+1)*(s+2)*(s+10));
figure('Name','Open Loop System Response','NumberTitle','off');
step(Go);

% PID Controller
Kp = 1.79;
Ki = 0.34;
Kd = 0.239;
Gc = Kp+(Ki/s)+(Kd*s);
G = feedback(Go*Gc,1);
t = 0:0.01:2;
figure('Name','PID-Controlled System Response','NumberTitle','off');
step(G,t);