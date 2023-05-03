#include <iostream>

using namespace std;

void fnd(int ar[],int n)
{
    for(int i=1;i<n-1;i++)
        if(ar[i-1]<ar[i]&&ar[i]>ar[i+1])
            cout<<i<<' '<<ar[i]<<endl;
}
int main()
{
    int ar[5]={10,20,30,20,10};
    fnd(ar,5);
    return 0;
}
