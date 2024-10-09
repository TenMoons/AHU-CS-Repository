function y=recur(a,b,n,x,x0,y0);
N=length(a);y=[y0 zeros(1,length(n))];
M=length(b)-1;x=[x0 x];
a1=a(length(a):-1:1);
b1=b(length(b):-1:1);
for i=N+1:N+length(n)
    y(i)=-a1*y(i-N:i-1)'+b1*x(i-N:i-N+M)';
end
y=y(N+1:N+length(n));