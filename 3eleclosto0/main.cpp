#include <iostream>

using namespace std;

void sctz(int ar[],int n)
{
    int tsum=0;int sum=INT_MAX;
    int ci,cj,ck;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
            {
                tsum=ar[i]+ar[j]+ar[k];
                if(abs(tsum)<abs(sum))
                {
                    sum=tsum;
                    ci=i;cj=j;ck=k;
                }
            }
    cout<<sum<<ci<<cj<<ck;
}
void sctz2(int ar[],int n,int target)
{
    int i,j;int ci,cj,ck;
    int tsm=0;int sm=INT_MAX;
    for(int k=0;k<n;k++)
    {
        i=k+1;j=n-1;
        while(i<j)
            {
                tsm=ar[i]+ar[j]+ar[k];
                if(abs(tsm-target)<abs(sm-target))
                    {
                        sm=tsm;
                        ci=i;cj=j;ck=k;
                    }
                if(tsm<target)
                    i++;
                else
                    j--;
            }
    }
    cout<<sm<<endl<<ar[ci]<<' '<<ar[cj]<<' '<<ar[ck]<<endl;
}
int main()
{
    int ar[6]={-80,-10,1,60,70,85};
    sctz2(ar,6,0);
    return 0;
}
