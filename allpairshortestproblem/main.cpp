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
void randg(int k=4)
{
    g=cg(k);
    insedge(0,1,3);insedge(0,3,7);
    insedge(1,0,8);insedge(1,2,2);
    insedge(2,0,5);insedge(2,3,1);
    insedge(3,0,2);
    dg();
}
void matcal(int ar[4][4])
{
    for(int i=0;i<g->v;i++)
    {
        lst *ptr=g->adj[i];
        while(ptr)
        {
            ar[i][ptr->vtx]=ptr->cost;
            ptr=ptr->nxt;
        }
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(ar[i][j]==0&&i!=j)
                ar[i][j]=32676;
}
void disp(int ar[][4],int k=4)
{
    for(int i=0;i<k;i++,cout<<endl)
        for(int j=0;j<k;j++)
            cout<<ar[i][j]<<' ';
}
void alsp()
{
    int ar[4][4]={0};
    matcal(ar);
    for(int k=0;k<g->v;k++)
    {
        for(int i=0;i<g->v;i++)
        {
            if(i==k) continue;
            for(int j=0,temp;j<g->v;j++)
            {
                //if(j==k) continue;
                temp=ar[i][k]+ar[k][j];
                if(temp<ar[i][j])
                    ar[i][j]=temp;
            }
        }
    }
    disp(ar);
}
int main()
{
    randg();
    alsp();
    return 0;
}
