clear all
R=1;C=1;T=0.2;
a=-(1-T/R/C);b=[0 T/C];
y0=0;x0=1
n=1:40;
x=ones(1,length(n));
y1=recur(a,b,n,x,x0,y0);
t=0:0.04:8;
y2=1-exp(-t);
y1=[y0 y1];
n=0:40;
plot(n*T,y1,'o',t,y2,'r-');