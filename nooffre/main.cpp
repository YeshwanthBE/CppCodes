#include <iostream>

using namespace std;
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
void swp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void nof(int ar[],int n)
{
    int ei=0;
    for(int i=0;i<n;)
    {
        ei=ar[i]-1;
        if(ar[i]>0&&ar[ei]>0)
        {
            swp(&ar[i],&ar[ei]);
            ar[ei]=-1;
        }
        else if(ar[i]>0)
            {ar[ei]--;i++;}
        else
            i++;
    }
    disp(ar,n);
}
int main()
{
    int ar[6]={1,2,2,4,5,6};
    nof(ar,6);
    return 0;
}
