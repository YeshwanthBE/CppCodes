#include<iostream>
using namespace std;
void sctz2(int ar[],int n,int target)
{
    int i=0,j=n-1;
    int tsm=0;int sm=INT_MAX;
    while(i<j)
    {
        tsm=ar[i]+ar[j];
        if(tsm<target)
            i++;
        else
            j--;
        sm=abs(target-sm)>abs(target-tsm)?tsm:sm;
    }
    cout<<sm;
}
int main()
{
    int ar[6]={-80,-10,1,60,70,85};
    sctz2(ar,6,65);
    return 0;
}
