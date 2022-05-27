%% Exercise 6

clc;
close all;
clear;

s = tf('s');

% Open Loop System
Go = 1/(s^2+10*s+20);
figure('Name','Open Loop System Response','NumberTitle','off');
step(Go);

% P Controller
Kp = 300;
Gc = Kp;
G = feedback(Go*Gc,1);
t = 0:0.01:2;
figure('Name','P-Controlled System Response','NumberTitle','off');
step(G,t);

% PI Controller
Kp = 30;
Ki = 70;
Gc = Kp+(Ki/s);
G = feedback(Go*Gc,1);
t = 0:0.01:2;
figure('Name','PI-Controlled System Response','NumberTitle','off');
step(G,t);

% PD Controller
Kp = 300;
Kd = 10;
Gc = Kp+(Kd*s);
G = feedback(Go*Gc,1);
t = 0:0.01:2;
figure('Name','PD-Controlled System Response','NumberTitle','off');
step(G,t);

% PID Controller
Kp = 350;
Ki = 300;
Kd = 50;
Gc = Kp+(Ki/s)+(Kd*s);
G = feedback(Go*Gc,1);
t = 0:0.01:2;
figure('Name','PID-Controlled System Response','NumberTitle','off');
step(G,t);