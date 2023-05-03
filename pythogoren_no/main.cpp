#include <iostream>

using namespace std;

void pno(int ar[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(ar[i]*ar[i]+ar[j]*ar[j]==ar[k]*ar[k])
                    cout<<ar[i]<<' '<<ar[j]<<' '<<ar[k]<<endl<<ar[i]*ar[i]<<' '<<ar[j]*ar[j]<<' '<<ar[k]*ar[k]<<endl;
}
int main()
{
    int ar[17]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    pno(ar,17);
    return 0;
}
