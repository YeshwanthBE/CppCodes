#include <iostream>
using namespace std;
int dp[4][11];
void disp()
{
    for(int i=0;i<4;i++,cout<<endl)
        for(int j=0;j<11;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
}
int cc(int coins[],int n,int sm,int i=0)
{
    if(i==n||sm<0)
        return 0;
    if(sm==0)
        return 1;
    if(dp[i][sm])
        return dp[i][sm];
    dp[i][sm-coins[i]]=cc(coins,n,sm-coins[i],i);
    dp[i+1][sm]=cc(coins,n,sm,i+1);
   dp[i][sm]=dp[i][sm-coins[i]]+dp[i+1][sm];
   return dp[i][sm];
}
int main()
{
    int coins[]={2,3,5,6};
    cc(coins,4,10);
    disp();
    return 0;
}
