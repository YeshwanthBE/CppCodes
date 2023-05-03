#include <iostream>

using namespace std;

int bsrchfo(int ar[],int n,int data)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(ar[mid]==data)
            if(mid==low||ar[mid-1]<data)
                return mid;
        if(ar[mid]>=data)
            high=mid-1;
        else
            low=mid+1;

    }
}
int bsrchlo(int ar[],int n,int data)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(ar[mid]==data)
            if(mid==high||ar[mid+1]>data)
                return mid;
        if(ar[mid]<=data)
            low=mid+1;
        else
            high=mid-1;

    }
}
void nofocr(int ar[],int n,int data)
{
    int fo=bsrchfo(ar,n,data);
    int lo=bsrchlo(ar,n,data);
    cout<<lo-fo+1;
}
void ano(int ar[],int n,int data)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(ar[mid]==data)
            break;
        else if(ar[mid]>data)
            high=mid-1;
        else
            low=mid+1;
    }
    int lc=0,rc=0;
    for(int i=mid-1;i>=0&&ar[i]==data;i--)
        lc++;
    for(int i=mid+1;i<n&&ar[i]==data;i++)
        rc++;
    cout<<lc+rc+1;
}
int main()
{
   int ar[5]={1,2,2,2,2};
   ano(ar,5,2);
    return 0;
}
