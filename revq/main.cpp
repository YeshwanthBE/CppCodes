#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> s;
queue<int> q;
void rev(int k)
{
    int t=q.size()-k;
    while(k--)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(t--)
        {q.push(q.front());
        q.pop();}

}
int main()
{
    for(int i=10;i<100;i+=10)
        q.push(i);
    rev(4);
    while(!q.empty())
    {cout<<q.front()<<' ';q.pop();}
    return 0;
}
