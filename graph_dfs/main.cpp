#include <iostream>
using namespace std;
struct lst
{
    int vtx;
    lst *nxt;
};
struct graph
{
    int tv;
    lst *adj;
}*grap=NULL;
void cg(int v,graph *g=grap)
{
    if(!g)
        g=new graph;
        g->tv=v;
        g->adj=new lst[g->tv];
}
void insedge(int f,int d,graph *g=grap)
{
    lst *ptr=g->adj[f];
}
int main()
{
    cout << "Hello world!" << endl;
    cg(0);
    return 0;
}
