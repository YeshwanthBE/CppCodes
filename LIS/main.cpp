#include <iostream>
using namespace std;
int TAB_LIS(int ar[],int n)
{
    int dp[n];int mx=INT_MIN;
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(ar[i]>ar[j]&&dp[i]<dp[j]+1)
                {dp[i]=dp[j]+1;
                mx=mx>dp[i]?mx:dp[i];}
    cout<<mx;
}
int dp[8][8];
int MEM_LIS(int ar[], int n,int i=-1,int j=0)
{
    if(j==n)
        return 0;
    int t=0;
    if(dp[i+1][j])
        return dp[i+1][j];
    if(i==-1||ar[j]>ar[i])
            t=1+MEM_LIS(ar,n,j,j+1);
    dp[i+1][j]=max(t,MEM_LIS(ar,n,i,j+1));
    return dp[i+1][j];
}

int main()
{
    int ar[]={1,2,5,5,4,5,10};
    TAB_LIS(ar,7);
    return 0;
}
