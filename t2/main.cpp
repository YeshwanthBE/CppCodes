#include <iostream>

using namespace std;
struct a{

int a;
int br[10];
};
int main()
{
    a ob;
    for(int i=0;i<12;i++)
    ob.br[i]=i+1;
    for(int i=0;i<12;i++)
    cout<<ob.br[i]<<endl;
    return 0;
}
