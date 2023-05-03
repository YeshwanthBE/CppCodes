#include <iostream>
#include<queue>
using namespace std;
struct graph
{
    int v;
    int **adj;
}*g=NULL;
void cg(int v)
{
    if(!g)
        g=new graph;
    g->adj=new int*[g->v];
    g->v=v;
    for(int i=0;i<g->v;i++)
        g->adj[i]=new int[g->v];
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            g->adj[i][j]=0;
}
void insedge(int f ,int d)
{
    if(f>g->v||d>g->v||f==d)
        return;
    g->adj[f][d]=1;
}
int indeg(int node)
{
    int temp=0;
   for(int i=0;i<g->v;i++)
        temp+=g->adj[i][node];
   return temp;
}
void dg()
{
    for(int i=0;i<g->v;i++)
        for(int j=0;j<g->v;j++)
            if(g->adj[i][j])
                cout<<i<<"---"<<j<<endl;
}
void randg(int k=3)
{
    cg(k);
    for(int i=0;i<k+3;i++)
        insedge(rand()%k,rand()%k);
    dg();
}
void tsrt()
{
    queue<int>q;
    int ar[g->v]={0};
    int tsr[g->v];int k=0;
    for(int i=0;i<g->v;i++)
        {
            ar[i]=indeg(i);
            if(!ar[i])
                q.push(i);
        }
    int temp;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        tsr[k++]=temp;
        for(int i=0;i<g->v;i++)
            if(g->adj[temp][i]==1)
                if(!--ar[i])
                    q.push(i);

    }
    bool flag=0;
    for(int i=0;i<g->v;i++)
        if(ar[i])
            {flag=1;break;}
    if(flag)
        cout<<"There is no solution";
    else
        for(int i=0;i<g->v;i++)
            cout<<tsr[i]<<"--";
}
int main()
{
    randg(5);
    tsrt();
    return 0;
}
