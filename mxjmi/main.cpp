#include <iostream>
using namespace std;
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void mxjid(int ar[],int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
        for(int j=n-1;j>0;j--)
            if(ar[j]>ar[i])
                mx=mx>(j-i)?mx:j-i;
    cout<<mx;
}
void mem(int ar[],int n)
{
    int mxdif=0;
    int lmin[n],rmax[n];
    lmin[0]=ar[0];rmax[n-1]=ar[n-1];
    for(int i=1;i<n;i++)
        lmin[i]=min(lmin[i-1],ar[i]);
    for(int i=n-2;i>=0;i--)
        rmax[i]=max(rmax[i+1],ar[i]);
    int i=0,j=0;
    while(j<n&&i<n)
        if (lmin[i] <= rmax[j])
        {
            mxdif = max(mxdif,j - i);
            j++;
        }
        else
            i++;
    cout<<mxdif;
}
int main()
{
    int ar[9]={34,8,10,3,2,80,30,33,1};
    mem(ar,9);
    return 0;
}
