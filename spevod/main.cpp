#include <iostream>

using namespace std;
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
void seo(int ar[],int n)
{
    int l=0,r=n-1;
    while(l<r)
    {
        while(ar[l]%2==0&&l<r)
            l++;
        while(ar[r]%2!=0&&l<r)
            r--;
        if(l<r)
        {
            int t=ar[l];ar[l]=ar[r];ar[r]=t;
            l++;r--;
        }
    }
    disp(ar,5);
}
int main()
{
    int ar[5]={1,2,3,4,5};
    seo(ar,5);
    return 0;
}
