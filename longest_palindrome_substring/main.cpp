#include <iostream>
using namespace std;
void lps(char *p,int n)
{
    n--;int mx=1;
    int dp[11][11];
    for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(p[i]==p[i+1])
                {dp[i][i+1]=1;mx=2;}
            else
                dp[i][i+1]=0;
        }
    for(int k=2;k<n;k++)
    {
        for(int i=0,j;i<n-k;i++)
        {
            j=i+k;
            if(p[i]==p[j]&&dp[i+1][j-1])
                dp[i][j]=2+dp[i+1][j-1];
            else
                dp[i][j]=0;
            mx=mx>dp[i][j]?mx:dp[i][j];
        }
    }
    cout<<mx    ;
}
int main()
{
    lps("MZALAYALAM",11);
    return 0;
}
