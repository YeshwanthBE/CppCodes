#include <iostream>

using namespace std;

int fk(int ar[],int k)
{
    int ed=1;
    while(ar[ed]!=0)
        ed*=2;
    int strt=0,endd=ed;
    while(strt<=ed)
    {
        int mid=(strt+endd)/2;cout<<strt<<' '<<mid<<' '<<endd<<endl;
        if(!ar[mid])
        {endd--;continue;}
        if(ar[mid]==k)
            return mid;
        if(ar[mid]>k)
            endd=mid-1;
        else
            strt=mid+1;
    }
    return -1;
}
int main()
{
    int ar[10]={1,2,3,4,5,6,0,0,0};
    cout<<fk(ar,6);
    return 0;
}
