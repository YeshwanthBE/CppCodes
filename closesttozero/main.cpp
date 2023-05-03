#include <iostream>

using namespace std;

void sctz(int ar[],int n)
{
    int tsum=0;int sum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            tsum=ar[i]+ar[j];
            sum=abs(tsum)>abs(sum)?sum:tsum;
        }
    }
    cout<<sum;
}
void sctz2(int ar[],int n)
{
    int i=0,j=n-1;
    int tsm=0;int psm=INT_MAX,nsm=INT_MIN;
    while(i<j)
    {
        tsm=ar[i]+ar[j];
        if(tsm<0)
            {nsm=nsm<tsm?tsm:nsm;i++;}
        else if(tsm>0)
            {psm=psm>tsm?tsm:psm;j--;}
        else
            cout<<i<<' '<<j<<endl;
    }
    int fsm=abs(nsm)>psm?psm:nsm;
    cout<<fsm;
}
int main()
{
    int ar[6]={-80,-10,1,60,70,85};
    sctz2(ar,6);
    return 0;
}
