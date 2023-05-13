#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void disp(int ar[][3])
{
    for(int i=0;i<3;i++,cout<<endl)
        for(int j=0;j<3;j++)
            cout<<ar[i][j]<<' ';
        cout<<endl<<endl;
}
void spiralmat()
{
    int ar[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    disp(ar);
    int rs=0,cs=0,re=2,ce=2,i,j;
    while(rs<=re&&cs<=ce)
    {
        i=rs;j=cs;
        for(;j<=ce;j++)
            cout<<ar[i][j]<<' ';
        cout<<endl;
        for(i=i+1,j=j-1;i<=re;i++)
            cout<<ar[i][j]<<' ';
        cout<<endl;
        for(j=j-1,i=i-1;j>=cs;j--)
            cout<<ar[i][j]<<' ';
        cout<<endl;
        for(i=i-1,j=j+1;i>rs;i--)
            cout<<ar[i][j]<<' ';
        cout<<endl;
        rs++;cs++;
        re--;ce--;
    }
    cout<<endl;
}
void d(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void rev(int ar[],int s,int e)
{
    int t;
    while(s<e)
    {
        t=ar[s];
        ar[s]=ar[e];
        ar[e]=t;
        s++;e--;
    }
}
void arrt(int ar[],int n,int k)
{

    rev(ar,0,k-1);
    rev(ar,k,n-1);
    rev(ar,0,n-1);
    d(ar,6);
}
void swpc(char *a,char *b)
{
    char x=*a;
    *a=*b;
    *b=x;
}
void mstb(char *p,int n)
{
    int i=n-1,j=i;
    for(;i>=0;i--)
        if(!isspace(p[i]))
            swpc(&p[i],&p[j--]);
}
void mstbo(char *p,int n)
{
    for(int i=n-2,j=i+1;i>=0;i--,j--)
    {
        if(isspace(p[j]))
        {
            while(isspace(p[i]))
                i--;
            if(i>-1)
            swpc(&p[i],&p[j]);
        }
    }

}
void mstba(char *p,int n)
{
    for(int i=0,j=1;i<n;i++,j++)
    {
        if(p[i]=='-')
        {
            while(p[j]=='-')
                j++;
            if(i<n)
                if(p[j]=='\0')
                    {
                        for(;i<j;i++)
                            p[i]='-';
                        break;
                    }
                else
                    swpc(&p[i],&p[j]);
        }
    }
}
void swpi(int *a,int *b)
{
    int x=*a;
    *a=*b;
    *b=x;
}
void mzte(int ar[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        while(ar[i]!=0)
            i++;
        while(ar[j]==0)
            j--;
        swpi(&ar[i],&ar[j]);
        i++;j--;
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
    int ar[]={0,1,1,0,0,5,5,0,1,2,0,22,0};
    mzte(ar,13);
    disp(ar,13);
    return 0;
}
