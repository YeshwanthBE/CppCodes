#include <iostream>

using namespace std;
void disp(int ar[],int n)
{
        for(int j=0;j<n;j++)
            cout<<ar[j]<<' ';
        cout<<endl;
}
void kp01(int p[],int w[],int n,int c)
{
    int t[5][9];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if(!i||!j)
                t[i][j]=0;
            else if (j<w[i])
                t[i][j]=t[i-1][j];
            else
                 t[i][j]=max(p[i]+t[i-1][j-w[i]],t[i-1][j]);
        }
    }
    int tp=t[n][c];int fo[4]={0};
    for(int i=4;tp>0;i--)
    {
        bool flag=true;
        for(int j=0;j<=c;j++)
            if(tp==t[i-1][j])
                flag=false;
        if(flag)
        {
             fo[i]=1;
             tp-=p[i];
        }
    }
    disp(fo,4);
}
int main()
{
    int p[]={0,2,3,4,1};
    int w[]={0,3,4,5,6};
    kp01(p,w,4,8);
    return 0;
}
