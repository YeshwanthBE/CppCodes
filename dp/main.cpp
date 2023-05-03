#include <iostream>

using namespace std;
long double fib1(long double k)
{
    if(k<=1)
        return k;
    return fib1(k-2)+fib1(k-1);
}
long double fib[1000]={0};
long double dpfib(int k)
{
    if(k<=1)
        return k;
    if(fib[k])
        return fib[k];
    if(fib[k-1]&&fib[k-2])
        return fib[k-1]+fib[k-2];
    if(fib[k-2])
        return fib[k-2]+dpfib(k-1);
    if(fib[k-1])
        return fib[k-1]+dpfib(k-2);
    return dpfib(k-2)+dpfib(k-1);
}
long double dpifib(int k)
{
    if(k<=1)
        return k;
    long double a=0,b=1,sum=0;;
    for(int i=3;i<=k;i++)
        {
            cout<<(sum=a+b)<<endl;
            a=b;
            b=sum;
        }
    return sum;
}
int main()
{
    dpifib(40);
    return 0;
}
