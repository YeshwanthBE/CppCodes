#include <iostream>
using namespace std;
int ssm2(int ar[],int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            mx=mx>(ar[j]-ar[i])?mx:ar[j]-ar[i];
    return mx;
}
int mn(int ar[],int l,int r)
{
    int mn=INT_MAX;
    while(l<=r)
    {mn=mn>ar[l]?ar[l]:mn;l++;}
    return mn;
}
int mx(int ar[],int l,int r)
{
    int mx=0;
    while(l<=r)
    {mx=mx<ar[l]?ar[l]:mx;l++;}
    return mx;
}
int ssm(int ar[],int l,int r)
{
    if(l+1==r)
        return 0;
    int mid=l+(r-l)/2;
    int lp=ssm(ar,l,mid);
    int rp=ssm(ar,mid,r);
    int lmin=mn(ar,l,mid);
    int rmx=mx(ar,mid,r);
    int p=rmx-lmin;
    if(lp>rp)
            return p>lp?p:lp;
    else
        return p>rp?p:rp;
}
int main()
{
    int ar[10]={9,2,3,4,5,6,7,8,9};
    cout<<ssm(ar,0,9);
    return 0;
}
