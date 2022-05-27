clc;
clear;
close all;

n = input('Enter Time Interval Value: '); % Time Interval Extreme Value
a = input('Enter Signal Amplitude Value: '); % Signal Amplitude

% IMPULSE SIGNAL
t = -n:1:n; % Time Steps
u_i = a*[zeros(1,n) ones(1,1) zeros(1,n)];
figure()
stem(t,u_i);
xlabel('Time');
ylabel('Amplitude');
title('Impulse Signal');

% STEP SIGNAL
t = -n:1:n; % Time Steps
u_s = a*[zeros(1,n) ones(1,n+1)];
figure()
plot(t,u_s);
xlabel('Time');
ylabel('Amplitude');
title('Step Signal');

% RAMP SIGNAL
t = 0:1:n; % Time Steps
u_r = a*t;
figure()
plot(t,u_r);
xlabel('Time');
ylabel('Amplitude');
title('Ramp Signal');

% PARABOLIC SIGNAL
t = 0:0.0001:n; % Time Steps
u_p = a*(t.^2)/2;
figure()
plot(t,u_p);
xlabel('Time');
ylabel('Amplitude');
title('Parabolic Signal');

% EXPONENTIAL SIGNAL
t = 0:0.0001:n; % Time Steps
u_e = exp(-a*t);
figure()
plot(t,u_e);
xlabel('Time');
ylabel('Amplitude');
title('Exponential Signal');

% SINE SIGNAL
t = 0:0.0001:n; % Time Steps
u_s = a*sin(t);
figure()
plot(t,u_s);
xlabel('Time');
ylabel('Amplitude');
title('Sine Signal');