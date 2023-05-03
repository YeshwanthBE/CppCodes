#include <iostream>
#include <list>
#include<queue>
#define dq() q.front();q.pop()
using namespace std;
struct lst
{
    int src;
    int vtx;
    int cost;
    lst *nxt=NULL;
};
struct heap
{
    lst data[12];
    int cnt=0;
    int capacity=12;
}*head=NULL;
void plup(heap *h=head)
{
    lst temp;
    int i=h->cnt-1;
    while(i>-1&&(h->data[i].cost<h->data[(i-1)/2].cost))
    {
        temp=h->data[i];
        h->data[i]=h->data[(i-1)/2];
        h->data[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}
heap* ct(lst k,heap *h=head)
{
    if(!h)
        head=h=new heap;
    if(h->cnt+1>h->capacity)
        return h;
    h->data[h->cnt++]=k;
    plup(h);
    return h;
}
void pldw(heap *h=head)
{
    lst temp;
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i].cost>h->data[j].cost||h->data[j].cost>h->data[j+1].cost))
    {
        j=h->data[j].cost<h->data[j+1].cost?j:j+1;
        temp=h->data[i];
        h->data[i]=h->data[j];
        h->data[j]=temp;
        i=j;
        j=i*2+1;
    }
}
lst del(heap *h=head)
{
    lst temp;
    if(h->cnt)
    {
    temp=h->data[0];
    h->data[0]=h->data[h->cnt-1];
    h->cnt--;
    pldw(h);
    }
    return temp;
}
void disp(heap *h=head)
{
    if(!h)
        return;
    for(int i=0;i<h->cnt;i++)
        cout<<h->data[i].vtx<<' ';
    cout<<endl;
}
struct graph
{
    int v;
    lst **adj;
}*grap;
graph* cg(int v)
{
    graph *g=new graph;
    g->v=v;
   g->adj=new lst*[v];
   for(int i=0;i<v;i++)
    g->adj[i]=NULL;
    return g;
}
void insedge(int f,int d,int cost,graph *g=grap,int k=1)
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
    ptr->src=f;
    ptr->vtx=d;
    ptr->cost=cost;
    if(!prev)
        g->adj[f]=ptr;
    else
        prev->nxt=ptr;
    if(k)
        insedge(d,f,cost,g,0);
    return;
}
void dg(graph *g=grap)
{
    for(int i=0;i<g->v;i++)
    {
        lst *ptr=g->adj[i];
        while(ptr)
        {
            cout<<ptr->src<<" to "<<ptr->vtx<<" with cost of "<<ptr->cost<<endl;
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
void randg(int k=5)
{
    grap=cg(k);
    insedge(0,1,4);insedge(0,2,1);insedge(2,1,2);
    insedge(1,4,4);insedge(3,4,4);insedge(2,3,4);
    dg();
}
void prims(int k=0,graph *g=grap)
{
   int distance[g->v];
   for(int i=0;i<g->v;i++)
    distance[i]=-1;

   lst *ptr=g->adj[k];
   while(ptr)
   {
       ct(*ptr);
       ptr=ptr->nxt;
   }
   distance[k]=0;
   int visited[g->v]={0};
   visited[k]=1;
   lst temp;
   graph *g2=cg(g->v);
   while(head->cnt)
   {
       temp=del();
       if(visited[temp.vtx])
        continue;
        insedge(temp.src,temp.vtx,temp.cost,g2);
        visited[temp.vtx]=1;
        ptr=g->adj[temp.vtx];
        while(ptr)
        {
            if(visited[ptr->vtx]==0)
                ct(*ptr);
            ptr=ptr->nxt;

        }
   }
   dg(g2);
}
int main()
{
    randg();
    prims();
    return 0;
}
