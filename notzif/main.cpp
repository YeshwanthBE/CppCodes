#include <iostream>

using namespace std;
void notzin(int n)
{
    int cnt=0;
    for(int i=5;n/i!=0;i*=5)
        cnt+=n/i;
    cout<<cnt;
}
int main()
{
    notzin(100);
    return 0;
}
