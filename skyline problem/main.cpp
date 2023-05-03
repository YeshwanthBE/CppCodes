#include <iostream>
using namespace std;
void slbf(int ar[],int n)
{
    int br[1000]={0};
    for(int i=0;i<n;i+=3)
        {
            for(int j=ar[i];j<=ar[i+1];j++)
                br[j]=br[j]>ar[i+2]?br[j]:ar[i+2];
        }
    int cr[n]={0},prev=br[0],si=0;
    for(int i=1,k=0;i<=1000;i++)
        {
            if(prev!=br[i])
                {
                    cr[k++]=si;
                    cr[k++]=i-1;
                    cr[k++]=br[i-1];
                    si=i;
                }
            prev=br[i];
        }
    for(int i=0;i<n;i++)
    {
        cout<<cr[i]<<' ';
        if((i+1)%3==0)
            cout<<endl;
    }


}
int main()
{
    int ar[24]={1,7,14,3,10,9,5,12,17,14,18,11,15,27,6,20,22,19,23,30,15,26,29,14};
    slbf(ar,24);
    return 0;
}
