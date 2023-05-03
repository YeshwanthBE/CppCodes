#include <iostream>

using namespace std;
int bsrch(int ar[],int n,int k)
{
    int low=0,high=n-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ar[mid]==k)
            return mid;
        else if(ar[mid]<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int ar[3]={1,2,3};
    cout<<bsrch(ar,3,34);
    return 0;
}
