#include <iostream>
#include <list>
#include<queue>
#define dq() q.front();q.pop()
using namespace std;
struct lst
{
    int frm;
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
void insedge(int f,int d,int cost,int k=1,graph *gg=g)
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
            cout<<i<<" to "<<ptr->vtx<<" with cost of "<<ptr->cost<<endl;
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
void randg(int k=5)
{
    g=cg(k);
    insedge(0,1,4);insedge(0,2,1);insedge(2,1,2);
    insedge(1,4,4);insedge(3,4,4);insedge(2,3,4);
    //dg();
}
void dijkstra(int prev=0)
{
    int distance[g->v];
    for(int i=0;i<g->v;i++)
        distance[i]=-1;
    int visited[g->v]={0};
    lst *ptr=g->adj[0];int k=4;
    distance[0]=0;
    visited[0]=1;
    while(1)
    {
        while(ptr)
            {
                if(visited[ptr->vtx]==0)
                {ptr->cost+=distance[prev];
                ct(*ptr);}
                ptr=ptr->nxt;
            }
        if(!head->cnt)
            break;
        lst temp=del();
        visited[temp.vtx]=1;
        if(distance[temp.vtx]==-1)
            distance[temp.vtx]=temp.cost;
        else
            distance[temp.vtx]=distance[temp.vtx]>temp.cost?temp.cost:distance[temp.vtx];
        ptr=g->adj[temp.vtx];
        prev=temp.vtx;
    }
    for(int i=0;i<g->v;i++)
            cout<<"from a to "<<i<<" cost="<<distance[i]<<endl;
        cout<<endl;
}
void kruskal()
{
     lst *ptr;
     int visited[g->v]={0};
     for(int i=0;i<g->v;i++)
        for(ptr=g->adj[i];ptr;ptr=ptr->nxt)
            ct(*ptr);
    heap *h=head;
    graph *g1=cg(g->v);
    lst temp=del();
    while(h->cnt)
    {
        if(!visited[temp.vtx]||!visited[temp.frm])
        {
            visited[temp.vtx]=1;visited[temp.frm]=1;
            insedge(temp.frm,temp.vtx,temp.cost,0,g1);
        }
        temp=del();
    }
dg(g1);

}
int main()
{
    randg();
    //dg();
    kruskal();
    //dijkstra();
    return 0;
}
