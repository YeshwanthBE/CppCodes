#include <iostream>
using namespace std;
int bfilter[10]={0};
int hf1(int key)
{
    return key%10;
}
int hf2(int key)
{
    return key%11;
}
void bf(int ar[],int n)
{
    for(int i=0;i<n;i++)
        bfilter[hf1(ar[i])]=bfilter[hf2(ar[i])]=1;
}
int isther(int key)
{
    if(bfilter[hf1(key)]&&bfilter[hf2(key)])
        return 1;
    return 0;
}
int main()
{
    int ar[5]={1,2,3,4,5};
    bf(ar,5);
    cout<<isther();
    return 0;
}
