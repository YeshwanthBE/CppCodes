#include <iostream>
#include<queue>
#define dq() q.front();q.pop()
using namespace std;
struct tree
{
    int data;
    tree *left=NULL,*right=NULL,*ns=NULL;
}*r=NULL;
void ct(int data)
{
    if(!r)
    {
        r=new tree;
        r->data=data;
        return;
    }
    queue<tree *>q;
    q.push(r);
    while(!q.empty())
    {
        tree *temp=dq();
        if(temp->left)
            q.push(temp->left);
        else
        {temp->left=new tree;temp->left->data=data;break;}
        if(temp->right)
            q.push(temp->right);
        else
        {temp->right=new tree;temp->right->data=data;break;}
    }
    return;
}
void disp(tree *t=r)
{
    if(!t)
        return;
    queue<tree *>q;
    q.push(t);
    while(!q.empty())
    {
        tree *temp=dq();
        cout<<temp->data<<' ';
        if(temp->left)
            {
                q.push(temp->left);
                if(temp->left->ns)
                    q.push(temp->left->ns);
            }

    }
    return;
}
void ns()
{
    queue<tree *>q;
    q.push(r);q.push(NULL);
    while(!q.empty())
    {
        tree *temp=dq();
        if(!temp)
        {
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            temp->ns=q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
tree* nswr(tree *t)
{
    if(!t)
        return NULL;
    if(t->left)
        t->left->ns=t->right;
    if(t->right)
        t->right->ns=t->ns?t->ns->left:NULL;
    nswr(t->left);
    nswr(t->right);
}
void nsmv()
{
    queue<tree *>q;
    q.push(r);
    while(!q.empty())
    {
        tree *temp=dq();
        if(temp->left&&temp->right)
                temp->left->ns=temp->right;
        else if(temp->left)
            temp->left->ns=NULL;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
        {
            q.push(temp->right);
            if(temp->ns)
                    temp->right->ns=temp->ns->left;
        }
    }
}
int main()
{
        for(int i=1;i<8;ct(i++));

        nsmv();
        disp();
    return 0;
}
