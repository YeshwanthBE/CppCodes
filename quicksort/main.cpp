#include <iostream>
using namespace std;
void swp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void quicksort(int ar[],int st,int endd)
{
    if(st>endd)
        return;
    int lb=st,ub=endd;
    int pivot=lb;
    while(lb<ub)
    {
        while(ar[lb]<=ar[pivot])
            lb++;
        while(ar[ub]>ar[pivot])
            ub--;
        if(lb<ub)
            swp(&ar[lb],&ar[ub]);
    }
    swp(&ar[ub],&ar[pivot]);
    quicksort(ar,st,ub-1);
    quicksort(ar,ub+1,endd);
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
int main()
{
    int ar[15]={9,7,5,4,91,5,965,94,84,98,46,4,65,0,3};
    quicksort(ar,0,14);
    disp(ar,15);
    return 0;
}
