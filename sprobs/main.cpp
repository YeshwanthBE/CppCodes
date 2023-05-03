#include <iostream>
using namespace std;
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void countsrt(int ar[],int n,int mx,int pos=1)
{
    if(mx/pos==0)
        return;
    int cr[10]={0};int tr[n];
    for(int i=0;i<n;i++)
        cr[((ar[i]/pos)%10)]++;
    for(int i=1;i<10;i++)
        cr[i]+=cr[i-1];
    for(int i=n-1;i>=0;i--)
        tr[--cr[(ar[i]/pos)%10]]=ar[i];
    for(int i=0;i<n;i++)
        ar[i]=tr[i];

    countsrt(ar,n,mx,pos*10);
}
int getmx(int ar[],int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
        mx=mx>ar[i]?mx:ar[i];
    return mx;
}
int main()
{
    int ar[10]={432,8,530,90,88,231,11,45,677,199};
    countsrt(ar,10,getmx(ar,10));
    disp(ar,10);
    return 0;
}
