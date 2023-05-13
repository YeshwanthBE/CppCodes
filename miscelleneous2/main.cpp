#include <iostream>

using namespace std;
void swpi(int *a,int *b)
{
    int x=*a;
    *a=*b;
    *b=x;
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void mzte(int ar[],int n)
{
    for(int i=0,j=0;j<n;j++)
        if(ar[j]<=0)
            swpi(&ar[i++],&ar[j]);
}
void fc(char *p,char *q,int n)
{
    char r=0;
    for(int i=0;p[i];i++)
        r^=p[i];
    for(int i=0;q[i];i++)
        r^=q[i];
        cout<<r;
}
void fb(int ar[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(!ar[i]&&((i==0||i==n-1)||(!ar[i-1]&&!ar[i+1])))
        {k--;ar[k]=1;}
    }
    if(k)
        cout<<"False";
    else
        cout<<"True";
}
int main()
{
   int ar[]={1,0,0,0,1};
   fb(ar,5,2);
    return 0;
}
