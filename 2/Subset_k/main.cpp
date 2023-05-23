#include <iostream>
using namespace std;
bool dp[19];
void sehk(int ar[],int n,int k,int i)
{
    if(i+1<0||k<0)
        return;
    dp[k]=1;
    sehk(ar,n,k,i-1);
    sehk(ar,n,k-ar[i],i-1);
    return;
}

int main()
{
    int ar[5]={1,7,3,3,5};
    sehk(ar,5,19,4);
    for(int i=1;i<=19;i++)
        cout<<dp[i]<<' ';
    return 0;
}
