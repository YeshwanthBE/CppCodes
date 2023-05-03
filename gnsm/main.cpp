#include <iostream>

using namespace std;

void gnsm(int ar[],int n,int sum)
{
    for(int low=0,high=n-1,k;low<=high;)
        {
           k=ar[low]+ar[high];
            if(k==sum)
                {cout<<ar[low]<<' '<<ar[high]<<endl;return;}
            else if(k<sum)
                low++;
            else
                high--;
        }
    cout<<"negative";
}
int main()
{
    int ar[10]={-1,0,2,3,4,5,6,7,8,9};
    gnsm(ar,10,8);
    return 0;
}
