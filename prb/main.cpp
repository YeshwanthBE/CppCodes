#include <iostream>

using namespace std;
void stre(int ar[],int siz,int n)
{
    int xxor=0;
    for(int i=0;i<siz;i++)
        xxor^=ar[i];
    for(int i=1;i<=n;i++)
        xxor^=i;
    int sbit=xxor & ~(xxor-1);
    int x=0,y=0;
    for(int i=0;i<siz;i++)
    {
        if(ar[i]&sbit)
            x^=ar[i];
        else
            y^=ar[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i&sbit)
            x^=i;
        else
            y^=i;
    }
    cout<<x<<' '<<y;
}
int main()
{
    int ar[5]{1,2,2,3,3};
    stre(ar,5,3);
    return 0;
}
