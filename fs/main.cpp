#include <iostream>
#include <stack>
using namespace std;
int* fs(int ar[],int br[],int sr[])
{
    sr[0]={1};int k;
    for(int i=1;i<5;i++)
        {   k=0;
            for(int j=i;j>=0;j--)
            if(br[j]>br[i])
                break;
            else k++;
        sr[i]=k;
        }
    return sr;
}
int main()
{
    int ar[6]={0,1,2,3,4};
    int br[6]={6,3,4,5,5};int sr[6];
    fs(ar,br,sr);
    for(int i=0;i<5;i++)
        cout<<ar[i]<<' '<<br[i]<<' '<<sr[i]<<endl;
    return 0;
}
