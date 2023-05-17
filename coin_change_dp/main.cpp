#include <iostream>
using namespace std;
int dp[11][4];
void disp()
{
    for(int i=0;i<11;i++,cout<<endl)
        for(int j=0;j<4;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
}
int mem_cc(int coins[],int n,int sm,int i=0)
{
    if(i==n||sm<0)
        return 0;
    if(sm==0)
        return 1;
    if(dp[i][sm])
        return dp[i][sm];
    dp[i][sm-coins[i]]=mem_cc(coins,n,sm-coins[i],i);
    dp[i+1][sm]=mem_cc(coins,n,sm,i+1);
    dp[i][sm]=dp[i][sm-coins[i]]+dp[i+1][sm];
    return dp[i][sm];
}
int tab_cc(int coins[],int n,int sm)
{
    for(int i=1;i<=sm;i++)
    {
        for(int j=0,x,y;j<n;j++)
        {
            x=(i-coins[j]>=0)?dp[i-coins[j]][j]:0;
            y=(j>0)?dp[i][j-1]:0;
            dp[i][j]=x+y;
        }
    }
    return dp[sm][n-1];
}
int main()
{
    int coins[]={2,3,5,6};
    for(int i=0;i<4;i++) dp[0][i]=1;
    cout<<tab_cc(coins,4,10);
    return 0;
}
