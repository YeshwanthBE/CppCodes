#include <iostream>
using namespace std;
struct graph
{
    int v;
    int e;
    int **adj=NULL;
}*g=NULL;
graph* cg(int v)
{
    graph *gg=new graph();
    gg->v=v;
    if(!gg->adj)
        {
            gg->adj=new int*[gg->v];
            for(int i=0;i<v;i++)
                gg->adj[i]=new int[gg->v];
        }
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
           gg->adj[i][j]=0;
    return gg;
}
void insedge(int i,int j)
{
    if(i>g->v||j>g->v)
        return;
    g->adj[i][j]=1;
    g->e++;
}
void de(graph *g=g)
{
    for(int i=0;i<g->v;i++)
        for(int j=0;j<g->v;j++)
            if(g->adj[i][j])
                cout<<i<<','<<j<<endl;
}
void dg(graph *g=g)
{
    for(int i=0;i<g->v;i++,cout<<endl)
        for(int j=0;j<g->v;j++)
            cout<<g->adj[i][j]<<' ';
}
void dfs(int pon[],int strt=0)
{
    int ar[g->v]={0};
    int top=-1;int i;int k=g->v;
    ar[++top]=strt;int visited[g->v]={0};
    visited[strt]=1;
    while(top>-1)
    {
        i=ar[top--];
        pon[i]=--k;
        for(int j=0;j<g->v;j++)
           if(g->adj[i][j]&&!visited[j])
            {ar[++top]=j;visited[j]=1;}
    }
}
int vstd[4]={0};
void dfs2(graph *gg,int strt=0)
{
    int ar[g->v]={0};
    int top=-1;int i;
    ar[++top]=strt;int visited[g->v]={0};
    visited[strt]=1;
    while(top>-1)
    {
        i=ar[top--];
        for(int j=0;j<gg->v;j++)
           if(gg->adj[i][j]&&!visited[j])
            {ar[++top]=j;visited[j]=1;}
    }
    cout<<"Strongly Connected Components are:";
    for(int i=0;i<g->v;i++)
        if(visited[i])
            cout<<i<<' ';
    for(int i=0;i<g->v;i++)
        vstd[i]=visited[i];
}
graph* revgr(graph *g)
{
    graph *g2=cg(g->v);
    for(int i=0;i<g2->v;i++)
        for(int j=0;j<g2->v;j++)
            if(g->adj[i][j])
                g2->adj[j][i]=1;
    de(g2);
    return g2;
}

void scc()
{
    int pon[g->v]={0};
    dfs(pon);
    graph *g2=revgr(g);int k=0;
    for(int i=1;i<g->v;i++)
        k=pon[k]>pon[i]?k:i;
    dfs2(g2,k);cout<<endl;
    for(int i=0;i<g->v;i++)
        if(vstd[i]==0)
            dfs2(g2,i);
}
int main()
{
    g=cg(4);
    insedge(0,1);
    insedge(1,2);
    insedge(2,3);
    insedge(2,0);
    insedge(0,3);
    de();
    scc();
    return 0;
}
