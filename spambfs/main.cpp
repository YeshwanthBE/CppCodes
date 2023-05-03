#include <iostream>
#include <list>
#include<queue>
#define dq() q.front();q.pop()
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
    if(f<0||d<0||f>=g->v||d>=g->v)
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
    //for(int i=0;i<k;i++)
     //   insedge(rand()%k,rand()%k);
    insedge(0,1);insedge(0,2);insedge(0,3);
    insedge(1,3);insedge(1,4);insedge(4,6);
    insedge(3,6);insedge(3,5);insedge(5,6);insedge(5,2);
    dg();
}
void sbfs(int start=2)
{
    int path[g->v];
    int distance[g->v];
    for(int i=0;i<g->v;i++)
        distance[i]=-1;
    queue<int>q;
    q.push(start);
    distance[start]=0;
    path[start]=-1;
    int temp;
    while(!q.empty())
    {
        temp=dq();
        lst *ptr=g->adj[temp];
        while(ptr)
        {if(distance[ptr->vtx]==-1)
        {
            path[ptr->vtx]=temp;
            distance[ptr->vtx]=distance[temp]+1;
            q.push(ptr->vtx);
        }ptr=ptr->nxt;}
    }
    for(int i=0;i<g->v;i++)
        cout<<start<<" to "<<i<<" = "<<distance[i]<<endl;
    for(int i=0,j;i<g->v;i++)
    {
        j=path[i];
        cout<<i;
        while(j!=-1)
        {
            cout<<"->"<<j;
            j=path[j];
        }
        cout<<endl;
    }
}
int main()
{
    randg(7);
    sbfs();
    return 0;
}
