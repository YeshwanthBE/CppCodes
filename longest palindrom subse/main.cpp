#include <iostream>
using namespace std;
void lps(char *p,int n)
{
    int dp[n][n];
    for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(p[i]==p[i+1])
                dp[i][i+1]=1;
            else
                dp[i][i+1]=0;
        }
    for(int k=2;k<n;k++)
    {
        for(int i=0,j;i<n-k;i++)
        {
            j=i+k;
            if(p[i]==p[j])
                dp[i][j]=2+dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    cout<<dp[0][n-1];
}
int main()
{
    lps("AGCTCBMAACTGGAM",15);
    return 0;
}
