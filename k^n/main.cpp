#include <iostream>

using namespace std;
int kpn(int k,int n)
{
    if(n==0)
        return 1;
    else
    {
        if(n%2==1)
        {
            int a=kpn(k,n-1);
            return a*k;
        }
        else
        {
            int a=kpn(k,n/2);
            return a*a;
        }
    }
}
int main()
{
    cout << kpn(9,4) << endl;
    return 0;
}
