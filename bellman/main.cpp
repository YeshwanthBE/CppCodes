#include <iostream>
#include<queue>
#define dq() q.front();q.pop()
using namespace std;
struct lst
{
    int vtx;
    int cost=0;
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
    {g->adj[i]=new lst;g->adj[i]->vtx=i;}
}
void insedge(int f,int d,int cost,int k=1)
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
    ptr->cost=cost;
    if(!prev)
        g->adj[f]=ptr;
    else
        prev->nxt=ptr;
    //if(k)
      //  insedge(d,f,cost,0);
    return;
}
void dg()
{
    for(int i=0;i<g->v;i++)
    {
        lst *ptr=g->adj[i];
        while(ptr=ptr->nxt)
            cout<<i<<" to "<<ptr->vtx<<" with cost of "<<ptr->cost<<endl;
    }
    cout<<endl;
}
void randg(int k=7)
{
    cg(k);
    insedge(0,1,6);insedge(0,2,5);insedge(0,3,5);
    insedge(1,4,-1);insedge(2,4,1);insedge(2,1,-2);
    insedge(3,2,-2);insedge(3,5,-1);insedge(4,6,3);insedge(5,6,3);
    //insedge(6,3,2);
    dg();
}
void bmfa(int prev=0)
{
    int distance[g->v];
    for(int i=0;i<g->v;i++)
        distance[i]=INT_MAX;
    queue<lst *>q;
    distance[prev]=0;
    q.push(g->adj[prev]);
    lst *ptr=NULL;
    while(!q.empty())
    {
        ptr=dq();
        prev=ptr->vtx;
        while(ptr=ptr->nxt)
        {
            q.push(g->adj[ptr->vtx]);
            int temp=distance[prev]+ptr->cost;
            if(distance[ptr->vtx]>temp)
                distance[ptr->vtx]=temp;
        }
    }
    for(int i=0;i<g->v;i++)
        cout<<distance[i]<<' ';
    cout<<endl;
}
void bmfa2(int prev=0)
{
    int distance[g->v];
    for(int i=0;i<g->v;i++)
        distance[i]=INT_MAX;
    queue<lst *>q;
    distance[prev]=0;
    q.push(g->adj[prev]);
    lst *ptr=NULL;
    int visited[g->v]={0};
    visited[0]++;
    while(!q.empty())
    {
        ptr=dq();
        prev=ptr->vtx;
        visited[prev]++;
        while(ptr=ptr->nxt)
        {
            if(visited[ptr->vtx]>=g->v-1)
                continue;
            q.push(g->adj[ptr->vtx]);
            int temp=distance[prev]+ptr->cost;
            if(distance[ptr->vtx]>temp)
                distance[ptr->vtx]=temp;
        }
    }
    for(int i=0;i<g->v;i++)
        cout<<distance[i]<<' ';
    cout<<endl;
}
void bmfa3(int prev=0)
{
    int distance[g->v];
    for(int i=0;i<g->v;i++)
        distance[i]=INT_MAX;
    queue<lst *>q;
    distance[prev]=0;
    q.push(g->adj[prev]);
    lst *ptr=NULL;
    int visited[g->v]={0};
    visited[0]=1;
    while(!q.empty())
    {
        ptr=dq();
        prev=ptr->vtx;
        visited[prev]=0;
        while(ptr=ptr->nxt)
        {
            if(visited[ptr->vtx])
                continue;
            q.push(g->adj[ptr->vtx]);
            visited[ptr->vtx]=1;
            int temp=distance[prev]+ptr->cost;
            if(distance[ptr->vtx]>temp)
                distance[ptr->vtx]=temp;
        }
    }
    for(int i=0;i<g->v;i++)
        cout<<distance[i]<<' ';
    cout<<endl;
}
int main()
{
   randg();
   //bmfa3();
   bmfa2();
   //bmfa();
    return 0;
}
