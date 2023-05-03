#include <iostream>
using namespace std;
void t2(int *temp);
void t()
{
    int temp;
    t2(&temp
       );
}
void t2(int *temp)
{
    int temp2;
    cout<<temp<<endl<<&temp2;
    if(temp<&temp2)
        cout<<"\n stack is growing";
    else
        cout<<"\n stack is not growning";
}
int main()
{
    t();
    return 0;
}
