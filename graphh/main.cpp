#include <iostream>
using namespace std;
struct lst
{
    int vtx;
    lst *nxt=NULL;
};
struct edge
{
    int frm;
    int dest;
};
struct graph
{
    int v;
    int e;
    lst *ll[];
}*grph=NULL;
edge* ce(int f,int d,graph *g=grph)
{
    if(f>g->v||d>g->v)
        return NULL;
    edge *e=new edge;
    e->frm=f;
    e->dest=d;
    return e;
}
void cg(int v,graph *g=grph)
{
    if(!g)
        grph=g=new graph;
    g->v=v;g->e=0;
    for(int i=0;i<v;i++)
        g->ll[i]=new lst;
}
void insedge(edge *e,graph *g=grph)
{
    lst *ptr=g->ll[e->frm];
    lst *prev;
    while(ptr)
    {
        if(ptr==g->ll[e->dest])
            return;
        else
        {

            prev=ptr;
            ptr=ptr->nxt;
        }
        if(!ptr)
        {
            ptr=new lst;
            ptr->vtx=e->dest;
            ptr->nxt=NULL;
            prev->nxt=ptr;
            return;
        }
    }
}
void disp(graph *g=grph)
{
    for(int i=0;i<g->v;i++,cout<<endl)
            for(lst *ptr=g->ll[i];ptr;ptr=ptr->nxt)
                cout<<ptr->vtx<<' ';
}
int main()
{
    cg(10);
    ce(0,1);
    insedge(ce(0,1));
    insedge(ce(0,2));
    disp();
    return 0;
}
