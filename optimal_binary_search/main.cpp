#include <iostream>

using namespace std;
int disp(int kb[][5],int i,int j)
{
    if(kb[i][j]==-1)
        {cout<<" NULL ";return -1;}

    cout<<kb[i][j]<<endl;
    cout<<kb[i][j]<<"left ";disp(kb,i,kb[i][j]-1);
    cout<<kb[i][j]<<"right ";disp(kb,kb[i][j],j);
    cout<<endl;
}
void obst(int ar[],int w[],int n)
{
    int dpt[n][5];int kb[n][5];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){dpt[i][j]=0;kb[i][j]=-1;}
    for(int d=0;d<n;d++)
        for(int i=0,mxw=0,j;i<n-d;i++,mxw=0)
        {
            j=i+d;
            if(j-i==0)
                {dpt[i][j]=0;continue;}
                for(int k=i,t,mn=INT_MAX;k<j;k++,mxw+=w[k])
                {
                    t=dpt[i][k]+dpt[k+1][j];
                    if(mn>t)
                    {
                        mn=t;
                        dpt[i][j]=mn;
                        kb[i][j]=k+1;
                    }
                }
            dpt[i][j]+=mxw;
        }
    disp(kb,0,4);
}
int main()
{
    int ar[]={0,10,20,30,40};
    int w[]={0,4,2,6,3};
    obst(ar,w,5);
    return 0;
}
