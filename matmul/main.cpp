#include <iostream>

using namespace std;

void matmul(int ar[],int n)
{
    int c[n][n]={0},bk[n][n]={0};
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){c[i][j]=0;bk[i][j]=-1;}
    for(int d=1;d<n;d++)
    {
        for(int i=0,t,mn,j;i<n-d;i++)
        {
             j=i+d;t=mn=INT_MAX;
             for(int k=i;k<j;k++)
             {
                 t=c[i][k]+c[k+1][j]+ar[i]*ar[k+1]*ar[j+1];
                 if(t<mn)
                 {
                    mn=c[i][j]=t;
                    bk[i][j]=k;
                 }
             }
        }
    }
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
            cout<<c[i][j]<<'\t';

    for(int i=0,j=n-1;bk[i][j]!=-1;)
    {
        for(int t=j;j>bk[i][j];j--)
            cout<<"A"<<j;
        cout<<")";
        cout<<"A"<<bk[i][j];
        j=bk[i][j];
    }
}
int main()
{
    int ar[5]={2,2,3,2,5};
    matmul(ar,4);
    return 0;
}
