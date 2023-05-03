#include <iostream>
using namespace std;
struct graph
{
    int v;
    int e;
    int **adj=NULL;
}*g=NULL;
void cg(int v)
{
    if(!g)
        g=new graph();
    g->v=v;
    if(!g->adj)
        {
            g->adj=new int*[g->v];
            for(int i=0;i<v;i++)
                g->adj[i]=new int[g->v];
        }
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            g->adj[i][j]=0;
}
void insedge(int i,int j)
{
    if(i>g->v||j>g->v)
        return;
    g->adj[i][j]=1;
    g->e++;
}
void de()
{
    for(int i=0;i<g->v;i++)
        for(int j=0;j<g->v;j++)
            if(g->adj[i][j])
                cout<<i<<','<<j<<endl;
}
void dg()
{
    for(int i=0;i<g->v;i++,cout<<endl)
        for(int j=0;j<g->v;j++)
            cout<<g->adj[i][j]<<' ';
}
int main()
{
    cg(4);
    insedge(0,2);
    insedge(1,0);
    insedge(2,3);
    insedge(3,1);
    de();
    return 0;
}
