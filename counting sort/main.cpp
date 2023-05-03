#include <iostream>

using namespace std;
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i];
    cout<<endl;
}
void csrt(int ar[],int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
        mx=ar[i]>mx?ar[i]:mx;
    int tar[++mx]={0};
    for(int i=0;i<n;i++)
        tar[ar[i]]++;
    for(int i=1;i<n;i++)
        tar[i]+=tar[i-1];
    int t2ar[n];
    for(int i=0;i<n;i++)
        t2ar[--tar[ar[i]]]=ar[i];
    disp(t2ar,n);
}
int main()
{
    int ar[15]={0,1,0,1,2,2,2,2,1,2,0,1,2,9,7};
    csrt(ar,15);
    return 0;
}
