%% Exercise 5

clc;
close all;
clear;

s = tf('s');
System = 1/(s*(s+1)*(s+5));
W = logspace(-1,2,400);

for k = 1:50
    [magnitude,phase,W] = bode(k*System,W); % Bode Plot
    [GM,PM,Wgc,Wpc] = margin(magnitude,phase,W); % Margin Values
    if round(Wgc,3) == round(Wpc,3)
        fprintf('MARGINALLY STABLE CONDITION\n\n');
        fprintf('System Gain: %0.3f\n',k);
        fprintf('Gain Crossover Frequency: %0.3f\n',Wgc);
        fprintf('Phase Crossover Frequency: %0.3f\n\n',Wpc);
    end
end

fprintf('EXPERIMENT WITH GAIN VALUES\n\n');

k1 = str2double(inputdlg('Enter Stable K: ')); % K for which Wgc > Wpc
figure('Name','1. Bode Plot for Stable K','NumberTitle','off');
bode(k1*System,W);
System1 = feedback(k1*System,1);
figure('Name','2. Step Response for Stable K','NumberTitle','off');
step(System1);
[magnitude,phase,W] = bode(k1*System,W);
[GM,PM,Wgc,Wpc] = margin(magnitude,phase,W);
fprintf('Gain: %0.3f\n',k1);
fprintf('Gain Margin: %0.3f\n',GM);
fprintf('Phase Margin: %0.3f\n',PM);
fprintf('Gain Crossover Frequency: %0.3f\n',Wgc);
fprintf('Phase Crossover Frequency: %0.3f\n\n',Wpc);

k2 = str2double(inputdlg('Enter Unstable K: ')); % K for which Wgc < Wpc
figure('Name','3. Bode Plot for Unstable K','NumberTitle','off');
bode(k2*System,W);
System2 = feedback(k2*System,1);
figure('Name','4. Step Response for Unstable K','NumberTitle','off');
step(System2);
[magnitude,phase,W] = bode(k2*System,W);
[GM,PM,Wgc,Wpc] = margin(magnitude,phase,W);
fprintf('Gain: %0.3f\n',k2);
fprintf('Gain Margin: %0.3f\n',GM);
fprintf('Phase Margin: %0.3f\n',PM);
fprintf('Gain Crossover Frequency: %0.3f\n',Wgc);
fprintf('Phase Crossover Frequency: %0.3f\n\n',Wpc);

k3 = str2double(inputdlg('Enter Marginally Stable K: ')); % K for which Wgc = Wpc
figure('Name','5. Bode Plot for Marginally Stable K','NumberTitle','off');
bode(k3*System,W);
System3 = feedback(k3*System,1);
figure('Name','6. Step Response for Marginally Stable K','NumberTitle','off');
step(System3);
[magnitude,phase,W] = bode(k3*System,W);
[GM,PM,Wgc,Wpc] = margin(magnitude,phase,W);
fprintf('Gain: %0.3f\n',k3);
fprintf('Gain Margin: %0.3f\n',GM);
fprintf('Phase Margin: %0.3f\n',PM);
fprintf('Gain Crossover Frequency: %0.3f\n',Wgc);
fprintf('Phase Crossover Frequency: %0.3f\n\n',Wpc);