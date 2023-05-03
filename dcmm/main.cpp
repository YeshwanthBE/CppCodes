#include <iostream>

using namespace std;
void disp(int**ar,int m=2,int n=2)
{
    for(int i=0;i<m;i++,cout<<endl)
        for(int j=0;j<n;j++)
            cout<<ar[i][j]<<' ';
}
int **tbtmm(int ar[2][2],int br[2][2],int n)
{
    int i=n-2,j=n-1;
    int **cr=new int*[2];
    cr[0]=new int[2];cr[1]=new int[2];
    cr[0][0]=ar[i][i]*br[i][i]+ar[i][j]*br[j][i];
    cr[0][1]=ar[i][i]*br[i][j]+ar[i][j]*br[j][j];
    cr[1][0]=ar[j][i]*br[i][i]+ar[j][j]*br[j][i];
    cr[1][1]=ar[j][i]*br[i][j]+ar[j][j]*br[j][j];
    return cr;
}
int **tbtma(int ar**,int br**,int n)
{
    int **cr=new int*[n];
    for(int k=0;k<n;k++)
        cr[k]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cr[i][j]=ar[i][j]+br[i][j];
    return cr;
}
int **dcmm(int ar**,int br**,int n,int siz)
{
    if(n<=2)
    {
        return tbtmm(ar,br,n);
    }
    int wr**=dcmm(ar,br,m/2,siz/2);
}
int main()
{
    int ar[2][2]={7,5,6,3},br[2][2]={2,1,5,1};
    disp(tbtmm(ar,br));
    return 0;
}
