#include <iostream>

using namespace std;
void sdi(int ar[],int n)
{
    int x=0;int y=0;
    for(int i=0;i<n;i++)
        x^=ar[i];
    for(int i=0;i<=n;i++)
        x^=i;
    cout<<x;
}
void xo(int ar[],int n)
{
    int xxor=0;
    for(int i=0;i<n;i++)
        xxor^=ar[i];
    for(int i=1;i<=n;i++)
        xxor^=i;
    int r=xxor &~(xxor-1);
    int x=0,y=0;
    for(int i=0;i<n;i++)
        if(ar[i]&r)
            x^=ar[i];
        else
            y^=ar[i];
    for(int i=1;i<=n;i++)
        if(ar[i]&r)
            x^=i;
        else
            y^=i;
    cout<<x<<' '<<y;
}
int main()
{
    int ar[5]={1,2,2,3,3};
    sdi(ar,5);
    return 0;
}
