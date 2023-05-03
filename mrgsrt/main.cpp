#include <iostream>
using namespace std;

void mrge(int ar[],int m,int br[],int n,int cr[])
{
    int i=0,j=0,k=0;
    for(;i<m&&j<n;k++)
        cr[k]=(ar[i]<br[j])?ar[i++]:br[j++];
    while(i<m)
        cr[k++]=ar[i++];
    while(j<n)
        cr[k++]=br[j++];
}
int * mgsrt(int ar[],int n)
{
    n--;
    if(n>0)
    {
        int mid=n/2;
        int p[mid+1], q[n-mid];
        for(int i=0;i<=mid;i++)
            p[i]=ar[i];
       for(int i=0,j=mid+1;j<=n;j++,i++)
            q[i]=ar[j];
        mgsrt(p,mid+1);
        mgsrt(q,n-mid);
        mrge(p,mid+1,q,n-mid,ar);
    }
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
int main()
{
    int ar[7]={38,27,48,50,3,9,82};
    mgsrt(ar,7);
    disp(ar,7);
    return 0;
}
