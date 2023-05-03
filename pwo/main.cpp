#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <int> s;
queue <int> q;
int sp(int a)
{
    if(a)
    {int t=s.top();
    s.pop();
    return t;}
    else
    {
        int t=q.front();
        q.pop();
        return t;
    }
}
bool pwo()
{
    bool pwo=true;
    while(!s.empty())
        q.push(sp(1));
    while(!q.empty())
        s.push(sp(0));
    while(!s.empty())
    {
        int x=sp(1);
        q.push(x);
        if(!s.empty())
        {
            int y=sp(1);
            q.push(y);
            if((x-y)!=-1&&(x-y)!=1)
                {pwo=false;break;}
        }
    }
    while(!s.empty())
        q.push(sp(1));
    while(!q.empty())
        s.push(sp(0));
    return pwo;
}
int main()
{
    for(int i=0;i<10;i++)
        s.push(i);
    if(pwo())
        cout<<"pairwise ordered";
    else
        cout<<"!pairwise ordered";
    return 0;
}
