#include <iostream>

using namespace std;
void pws(int ar[],int n)
{
    for(int i=1;i<n;i+=2)
        if(ar[i]<ar[i-1])
            {
                cout<<"Nope";return;
            }
    cout<<"Yep";
    return;
}
int main()
{
    int ar[6]={4,5,2,3,10,1};
    pws(ar,6);
    return 0;
}
