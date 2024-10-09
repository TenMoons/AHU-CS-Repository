num=[0 1];
den=[1 -0.5];
OMEGA=-pi:pi/150:pi;
H=freqz(num,den,OMEGA);
subplot(211),plot(OMEGA,abs(H));
subplot(212),plot(OMEGA,180/pi*unwrap(angle(H)))