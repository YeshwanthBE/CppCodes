#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
stack<int> s;
void nne(int ar[])
{
    s.push(ar[0]);
    for(int i=1;i<10;i++)
    {
        if(!s.empty()&&s.top()<ar[i])
           {
             while(!s.empty()&&s.top()<ar[i])
             {cout<<s.top()<<" -> "<<ar[i]<<endl;
             s.pop();}
           }

            s.push(ar[i]);
    }
    while(!s.empty())
    {cout<<s.top()<<" -> "<<-1<<endl;s.pop();}
}
int main()
{
    int ar[10];
    for(int i=0;i<10;i++)
        ar[i]=rand()%10;
    for(int i=0;i<10;i++)
        cout<<ar[i]<<' ';
    cout<<endl;
    nne(ar);
    return 0;
}
