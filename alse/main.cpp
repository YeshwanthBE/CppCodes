#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <int> s;
queue<int> q;
void alse(int x)
{
    int t=q.size()/2;
    for(int i=0;i<t;i++,q.pop())
        s.push(q.front());
    for(;!s.empty();s.pop())
        q.push(s.top());
    for(int i=0;i<t;i++)
    {
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<t;i++,q.pop())
        s.push(q.front());
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
void alse()
{

}
int main()
{
    for(int i=0;i<10;i++)
        q.push(i);
    alse(1);
    for(;!q.empty();q.pop())
        cout << q.front() << ' ';
    return 0;
}
