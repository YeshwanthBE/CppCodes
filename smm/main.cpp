#include <iostream>

using namespace std;
void disp(int ar[2][2])
{
    for(int i=0;i<2;i++,cout<<endl)
        for(int j=0;j<2;j++)
            cout<<ar[i][j]<<' ';
    cout<<endl;
}
void mul(int ar[2][2],int br[2][2],int n=2)
{
    disp(ar);disp(br);
    int cr[2][2]={0};
    disp(cr);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cr[i][j]+=ar[i][k]*br[k][j];
    disp(cr);
}
int main()
{
    int ar[2][2]={1,2,1,1},br[2][2]={2,1,2,2};
    mul(ar,br);
    return 0;
}
