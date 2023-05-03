#include <iostream>

using namespace std;
void swp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void bsrt(int ar[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(ar[j]>ar[j+1])
                swp(&ar[j],&ar[j+1]);
    disp(ar,5);
}
void isrt(int ar[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
            if(ar[j]<ar[j+1])
                break;
            else
                swp(&ar[j],&ar[j+1]);
    }
    disp(ar,5);
}
void ssrt(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mn=i;
        for(int j=i+1;j<n;j++)
            mn=ar[mn]>ar[j]?j:mn;
        if(mn!=i)
        swp(&ar[i],&ar[mn]);
    }
    disp(ar,5);
}
void shsrt(int ar[],int n)
{
    for(int gap=n/2;gap>=1;gap/=2)
        for(int i=0,j=gap;j<n;i++,j++)
            if(ar[j]<ar[i])
                for(int k=i,l=j;k>=0;l=k,k-=gap)
                    if(ar[l]<ar[k])
                        swp(&ar[l],&ar[k]);
    disp(ar,n);
}
void jshsrt(int ar[],int n)
{
    for(int gap=n/3;gap>0;gap/=3)
        for(int j=gap;j<n;j++)
            for(int i=j-gap;i>=0;i-=gap)
                if(ar[i]>ar[i+gap])
                    swp(&ar[i],&ar[i+gap]);
                else
                    break;
    disp(ar,n);
}
int main()
{
   int ar[9]={23,29,15,19,31,7,9,5,2};
   disp(ar,9);
   jshsrt(ar,9);
    return 0;
}
