clear all
for n=-10:30;
x(n+11)=cos(n);
end
n=-10:30;
stem(n,x(n+11),'r','o')