#include <iostream>
#include <queue>
using namespace std;
struct tree
{
    int data;
    tree *right=NULL;
    tree *left=NULL;
}*r=NULL;
void ct(int d)
{
    if(!r)
       {
           r=new tree;
           r->data=d;
           return;
       }
    tree *t;
    queue<tree *>q;
    q.push(r);
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(!t->left)
        {
            t->left=new tree;
            t->left->data=d;
            break;
        }
        else
            q.push(t->left);
        if(!t->right)
        {
            t->right=new tree;
            t->right->data=d;
            return;
        }
        else
            q.push(t->right);
    }
}
void cd(tree *t)
{
    if(!t)
        return;
    cout<<t->data<<' ';
    cd(t->left);
    cd(t->right);
}
int fm(tree *t)
{
    int rt,l,r,mx=0;
    if(t)
    {
        rt=t->data;
        l=fm(t->left);
        r=fm(t->right);
        mx=l>r?(l>rt?l:rt):(r>rt?r:rt);
    }
    return mx;
}
int main()
{
    for(int i=1;i<8;ct(i++));
    cd(r);
    cout<<'\n'<<fm(r);
    return 0;
}
