#include <iostream>
#include <queue>
using namespace std;
struct tree
{
    int data;
    tree *right=NULL,*left=NULL;
}*r=NULL;
void ct(int data)
{
    if(!r)
    {
        r=new tree;
        r->data=data;
        return;
    }
    tree *temp;
    queue<tree *>q;
    q.push(r);
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(temp->left)
            q.push(temp->left);
        else
        {
            temp->left=new tree;
            temp->left->data=data;
            return;
        }
        if(temp->right)
            q.push(temp->right);
        else
        {
            temp->right=new tree;
            temp->right->data=data;
            return;
        }
    }
}
int tsize(tree *t)
{
    if(!t)
        return 0;
    return (tsize(t->left)+1+tsize(t->right));
}
int tswr()
{
    queue<tree *>q;
    q.push(r);
    tree *temp;int siz=0;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(temp)
            siz++;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return siz;
}
void dt(tree *t)
{
    if(!t)
        return;
    dt(t->left);
    dt(t->right);
    delete t;
}
int th(tree *t)
{
    if(!t)
        return 0;
    int lh=th(t->left);
    int rh=th(t->right);
    return lh>rh?lh+1:rh+1;
}
int thwr()
{
    queue<tree *>q;
    tree *t;
    if(!r)
        return 0;
    int level=0;
    q.push(r);
    q.push(NULL);
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(!t)
        {
            if(!q.empty())
                q.push(NULL);
            level++;
        }
        else
        {
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    return level;
}
int main()
{
    for(int i=1;i<8;ct(i++));
    cout<<thwr();

    return 0;


}
