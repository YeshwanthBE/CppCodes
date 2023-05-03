#include <iostream>
using namespace std;
struct gt
{
    int data;
    gt *fc=NULL,*ns=NULL;
};
int dfa(int ar[],int n)
{
    int cd=0,md=0;
    for(int i=0;i<n;i++,cd=0)
    {
        for(int j=i;ar[j]!=-1;cd++,j=ar[j]);
        md=cd>md?cd:md;
    }
    return md;
}
int main()
{
   int ar[]={-1,0,1,6,6,0,0,2,7};
   cout<<dfa(ar,9);
    return 0;
}
