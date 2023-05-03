#include <iostream>
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
void insedge(int f,int d,int cost,int k=0,graph *gg=g)
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
            cout<<i+1<<" to "<<ptr->vtx+1<<" with cost of "<<ptr->cost<<endl;
            ptr=ptr->nxt;
        }
    }
    cout<<endl;
}
int ar[2][12];
void randg(int k=12)
{
    g=cg(k);
    insedge(0,1,9);insedge(0,2,7);insedge(0,3,3);insedge(0,4,2);
    insedge(1,5,4);insedge(1,6,2);insedge(1,7,1);
    insedge(2,5,2);insedge(2,6,7);
    insedge(3,7,11);insedge(4,6,11);insedge(4,7,8);
    insedge(5,8,6);insedge(5,9,5);insedge(6,8,4);
    insedge(6,9,3);insedge(7,9,5);insedge(7,10,6);
    insedge(8,11,4);insedge(9,11,2);insedge(10,11,5);
    //dg();
    for(int i=0;i<2;i++)
        for(int j=0;j<12;j++)
            ar[i][j]=-1;
}
int msac(int i=0)
{
    if(g->adj[i]==NULL)
        {
            ar[0][i]=0;
            ar[1][i]=i;
            return 0;
        }
    if(ar[0][i]>=0)
        return ar[0][i];
    int mn=INT_MAX,cost=0;
    for(lst *ptr=g->adj[i];ptr;ptr=ptr->nxt)
    {
        cost=ptr->cost+msac(ptr->vtx);
        if(mn>cost)
        {
            ar[0][i]=cost;
            ar[1][i]=ptr->vtx;
            mn=cost;
        }
    }
    return mn;
}
void disp()
{
    for(int i=0;i<2;i++,cout<<endl)
        for(int j=0;j<12;j++)
            cout<<ar[i][j]<<' ';
}
void mstage()
{
    int i=0;
    while(i!=11)
    {
        cout<<i+1<<" to "<<ar[1][i]+1<<endl;
        i=ar[1][i];
    }
    cout<<"with a cost of:"<<ar[0][0];
}
int main()
{
    randg();
    msac();
    //disp();
    mstage();
    return 0;
}
