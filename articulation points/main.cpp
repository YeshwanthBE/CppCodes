#include <iostream>
#include <list>
#include<stack>
#include<queue>
#define dq() q.front();q.pop()
#define mx 6
using namespace std;
struct lst
{
    int frm;
    int vtx;
    int cost;
    lst *nxt=NULL;
};
struct graph
{
    int v;
    lst **adj;
}*g;
graph* cg(int v,graph *gg=g)
{
   if(!gg)
        gg=new graph;
    gg->v=v;
   gg->adj=new lst*[v];
   for(int i=0;i<v;i++)
    gg->adj[i]=NULL;
    return gg;
}
void insedge(int f,int d,int cost=0,int k=1,graph *gg=g)
{
    if(f<0||d<0||f>=gg->v||d>=gg->v)
        return ;
    lst *ptr=gg->adj[f],*prev=NULL;
    while(ptr)
    {
        if(ptr->vtx==d)
            return;
        prev=ptr;
        ptr=ptr->nxt;
    }
    ptr=new lst;
    ptr->frm=f;
    ptr->vtx=d;
    ptr->cost=cost;
    if(!prev)
        gg->adj[f]=ptr;
    else
        prev->nxt=ptr;
    if(k)
        insedge(d,f,cost,0);
    return;
}
void dg(graph *gg=g)
{
    for(int i=0;i<gg->v;i++)
    {
        lst *ptr=gg->adj[i];
        while(ptr)
        {
            cout<<i+1<<" to "<<ptr->vtx+1<<endl;
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
void randg(int k=mx)
{
    g=cg(k);
    insedge(0,3);insedge(0,1);insedge(3,2);
    insedge(2,4);insedge(2,5);insedge(4,5);insedge(1,2);
   dg();
}
void dfs(graph *g=g)
{
    stack<lst *>s;
    lst *ptr=g->adj[0];
    int visited[g->v]={0};
    int dfsn[g->v]={1};
    int k=1;
    visited[0]=1;
    while(ptr)
    {
        s.push(ptr);
        visited[ptr->vtx]=1;
        ptr=ptr->nxt;
    }
    cout<<0<<" ";
    while(!s.empty())
    {
        ptr=s.top();s.pop();
        cout<<ptr->vtx<<' ';
        dfsn[ptr->vtx]=++k;
        ptr=g->adj[ptr->vtx];
        while(ptr)
        {
            if(visited[ptr->vtx]==0)
                {
                    s.push(ptr);
                    visited[ptr->vtx]=1;
                }
            ptr=ptr->nxt;
        }
    }
    //cout<<endl;
    //for(int i=0;i<g->v;i++)
      //  cout<<dfsn[i]<<' ';
    cout<<endl;
}
int visited[mx]={0};int num=0;int dfsno[mx];
int low[mx];
void sma()
{
    cout<<"dfsno:";
    for(int i=0;i<mx;i++)
        cout<<dfsno[i]<<" ";
        cout<<'\t';
    cout<<"low:";
    for(int i=0;i<mx;i++)
        cout<<low[i]<<" ";
    cout<<endl;
}
void dfsrec(int strt=0)
{
    low[strt]=dfsno[strt]=num++;
    visited[strt]=1;
    lst *ptr=g->adj[strt];
    while(ptr)
    {
        if(!visited[ptr->vtx])
            {
                dfsrec(ptr->vtx);
                if(low[ptr->vtx]<dfsno[strt])
                   cout<<"Cut Vertex:"<<ptr->vtx<<endl;
                low[strt]=low[strt]>low[ptr->vtx]?low[ptr->vtx]:low[strt];
            }
        else
            low[strt]=low[strt]>dfsno[ptr->vtx]?dfsno[ptr->vtx]:low[strt];
        ptr=ptr->nxt;
    }
}

int main()
{

    randg();
    dfsrec();
    //sma();
    return 0;
}
