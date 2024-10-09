clear all
for n=0:30;
x(n+1)=exp(-0.08*n)*sin(2*pi*n/15);
end
n=0:30
plot(n,x(n+1))
hold on
stem(n,x(n+1),'r','o')