#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct lst
{
    int vtx;
    lst *nxt=NULL;
};
struct graph
{
    int v;
    lst **adj;
}*g;
void cg(int v)
{
   if(!g)
        g=new graph;
    g->v=v;
   g->adj=new lst*[v];
   for(int i=0;i<v;i++)
    g->adj[i]=NULL;
}
void insedge(int f,int d,int k=1)
{
    if(f<0||d<0||f>g->v||d>g->v)
        return ;
    lst *ptr=g->adj[f],*prev=NULL;
    while(ptr)
    {
        if(ptr->vtx==d)
            return;
        prev=ptr;
        ptr=ptr->nxt;
    }
    ptr=new lst;
    ptr->vtx=d;
    if(!prev)
        g->adj[f]=ptr;
    else
        prev->nxt=ptr;
    if(k)
        insedge(d,f,0);
    return;
}
void dg()
{
    for(int i=0;i<g->v;i++)
    {
        lst *ptr=g->adj[i];
        while(ptr)
        {
            cout<<i<<" to "<<ptr->vtx<<endl;
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
void randg(int k=5)
{
    cg(k);
    for(int i=0;i<k;i++)
        insedge(rand()%k,rand()%k);
    insedge(1,3);
    dg();
}
void dfs(int k=0)
{
    stack<lst *>s;
    bool visited[g->v]={0};
    s.push(g->adj[k]);
    visited[k]=1;
    lst *ptr;
    cout<<k;
    while(!s.empty())
    {
        ptr=s.top();s.pop();
        while(ptr)
        {
            if(visited[ptr->vtx]==0)
            {
                 cout<<"->"<<ptr->vtx;
                s.push(g->adj[ptr->vtx]);
                visited[ptr->vtx]=1;
            }
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
void bfs(int k=0)
{
    queue<lst*>q;
    bool visited[g->v]={0};
    q.push(g->adj[k]);
    visited[k]=1;
    cout<<k;
    lst *ptr;
    while(!q.empty())
    {
        ptr=q.front();q.pop();
        while(ptr)
        {
            if(!visited[ptr->vtx])
            {
                cout<<"->"<<ptr->vtx;
                q.push(g->adj[ptr->vtx]);
                visited[ptr->vtx]=1;
            }
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
int main()
{
    randg(7);
    dfs(5);
    bfs(5);
    return 0;
}
