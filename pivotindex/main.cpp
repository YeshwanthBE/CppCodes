#include <iostream>

using namespace std;
void pi(int ar[],int n)
{
    int sm=0;int lsm=0;
    for(int i=0;i<n;sm+=ar[i],i++);
    for(int i=0;i<n;i++)
    {
        sm-=ar[i];
        if(sm==lsm)
        {cout<<i;return;}
        lsm+=ar[i];
    }
    cout<<"Not Found!!";
}
int main()
{
    int ar[3]={4,3,4};
    pi(ar,3);
    return 0;
}
