#include <iostream>

using namespace std;
void swp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void disp(int ar[],int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void twp(int ar[],int n)
{
    disp(ar,5);
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(ar[mid]==0)
        {
            swp(&ar[low],&ar[mid]);
            low++;mid++;
        }
        else if(ar[mid]==2)
        {
            swp(&ar[high],&ar[mid]);
            high--;
        }
        else
            mid++;

    }
    disp(ar,5);
}
int main()
{
    int ar[5]={1,0,2,1,0};
    twp(ar,5);
    return 0;
}
