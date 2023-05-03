#include <iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> q;
void rev()
{
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    for(int i=10;i>0;i--)
        q.push(i);
    rev();
    while(!q.empty())
    {cout<<q.front()<<' ';q.pop();}
    return 0;
}
