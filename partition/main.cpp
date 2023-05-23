#include <iostream>
using namespace std;
bool dp[12][5];
void disp(int n=5,int k=12)
{
    for(int i=0;i<k;i++,cout<<endl)
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl<<endl<<endl;
}
bool spdp(int ar[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        k+=ar[i];
    if(k%2!=0)
        return false;
    k/=2;
    for(int i=0;i<=n;i++)
        dp[0][i]=true;
    for(int i=1;i<=k;i++)
        dp[i][0]=false;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i-ar[j-1]>=0)
                    dp[i][j]=dp[i][j]||dp[i-ar[j-1]][j-1];
            }

    disp();
    return dp[k][n];
}
int main()
{
    int ar[]={1,5,11,5};
    cout<<spdp(ar,4);
    return 0;
}
