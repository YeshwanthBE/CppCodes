#include <iostream>

using namespace std;
int dp[11][7];
void disp(int n,int k)
{
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<k;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl<<endl<<endl;
}
void subset(int ar[],int n,int k)
{
    k/=2;
    for(int i=0;i<=k;i++)
        dp[0][i]=1;
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            {
                dp[j][i]=dp[j-1][i];
                if(i-ar[j-1]>=0)
                    dp[j][i]=dp[j-1][i-ar[j-1]]||dp[j][i];
            }
    //cout<<dp[n-1][k];
    disp(11,11);
}
int main()
{
    int ar[]={3,2,4,19,3,7,13,10,6,11};
    subset(ar,10,12);
    return 0;
}
