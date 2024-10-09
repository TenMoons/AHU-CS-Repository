clear all
T=0.1;R=2;L=1;C=1;
vc0=[1 1-T]; x0=[0 sin(T)];
n=2:80;
c=[R*T/L-2 1-R*T/L+T^2/L/C];
d=[0 0 T^2/L/C];
x=sin(T*n);
vc1=recur(c,d,n,x,x0,vc0);
vc1=[vc0 vc1];
t=0:0.04:8;
vc2=0.5*((3+t).*exp(-t)-cos(t));
%y1=[y0 y1];
figure
n=0:80;
plot(n*T,vc1,'o',t,vc2,'r-');