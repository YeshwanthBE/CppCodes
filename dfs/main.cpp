#include<iostream>
#include<stack>
using namespace std;
struct lst
{
    int vtx=0;
    lst *nxt=NULL;
};
struct graph
{
    int v;
    lst *adj[];
}*grap=NULL;
void cg(int v,graph *g=grap)
{
    if(!grap)
        g=grap=new graph;
    g->v=v;
    for(int i=0;i<g->v;i++)
    {
        g->adj[i]=new lst;
        g->adj[i]->vtx=i;
    }

    return;
}
void insedge(int frm,int dest,graph* g=grap)
{
    int n=g->v;
    int f=frm;
    int d=dest;
    if(f>n||d>n||f<0||d<0)
        return;
    lst *ptr=g->adj[f];
    lst *prev=NULL;
    while(ptr)
    {
        if(ptr->vtx==d)
            return;
        else
        {
            prev=ptr;
        ptr=ptr->nxt;
        }
    }
    if(!ptr)
        {
            lst *temp=new lst;
            temp->vtx=d;
    if(!prev)
    g->adj[f]=temp;
    else
        prev->nxt=temp;
        }
}
void dg(graph *g=grap)
{
    for(int i=0;i<g->v;i++)
    {
        lst *ptr=g->adj[i];
        while(ptr)
        {
            cout<<i<<"->"<<ptr->vtx<<endl;
            ptr=ptr->nxt;
        }
        cout<<endl;
    }
}
void randg(int k=4)
{
    cg(k);
    for(int i=0;i<k;i++)
        {
           insedge(rand()%k,rand()%k);
        }
    dg();
}
void dfs(graph *g=grap)
{
    stack<lst *>s;
    s.push(g->adj[0]);
    bool vstd[10]={0};
    vstd[0]=1;
    lst *ptr;
    while(!s.empty())
    {
        ptr=s.top();s.pop();
        cout<<ptr->vtx;
        while(ptr)
        {
            if(vstd[ptr->vtx]==0)
            {
                s.push(ptr);
                vstd[ptr->vtx]=1;
            }
            ptr=ptr->nxt;
        }
    }
}
int main()
{
    randg(5);
    grap->adj[0]->vtx=0;
    dfs();

    return 0;
}
