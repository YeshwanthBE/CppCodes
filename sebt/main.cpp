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
int st(tree *t,int d)
{
    if(!t)
        return 0;
    if(t->data==d)
        return 1;
    else if(st(t->left,d))
        return 1;
    else
        return st(t->right,d);

}
int stwr(int d)
{
    queue<tree *> q;
    q.push(r);
    tree *temp;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(temp->data==d)
            return 1;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return 0;
}
int main()
{
    for(int i=1;i<8;ct(i++));
    cout<<stwr(3);
    return 0;
}
