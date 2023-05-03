#include <iostream>
#include<queue>
#define dq() q.front(); q.pop()
using namespace std;
struct tree
{
    int data, height;
    tree *left=NULL,*right=NULL;
}*root=NULL;
int height(tree *t)
{
    if(!t)
        return -1;
    return t->height;
}
tree* lr(tree *t)
{
    tree *temp=t->right;t->right=NULL;
    temp->left=t;
   return temp;
}
tree *rr(tree *t)
{
    tree *temp=t->left;t->left=NULL;
    temp->right=t;
    return temp;
}
tree *rlr(tree *t)
{
    tree *temp=t->right->left;
    temp->right=t->right;
    t->right=temp;
    temp->right->left=NULL;
    return lr(t);
}
tree *lrr(tree *t)
{
    tree *temp=t->left->right;
    temp->left=t->left;
    t->left=temp;
    temp->left->right=NULL;
    return rr(t);
}
tree* ct(int data,tree *r=root)
{
    if(!r)
    {
        r=new tree;
        r->data=data;
        return r;
    }
    if(data<r->data)
    {
        r->left=ct(data,r->left);
        if(height(r->left)-height(r->right)==2)
            if(data<r->left->data)
                r=rr(r);
            else
                r=lrr(r);
    }
    if(data>r->data)
    {
        r->right=ct(data,r->right);
        if(height(r->right)-height(r->left)==2)
            if(data>r->right->data)
                r=lr(r);
            else
                r=rlr(r);
    }
    r->height=max(height(r->left),height(r->right))+1;
    return r;
}
void disp(tree *t=root)
{
    queue<tree *>q;
    q.push(t);q.push(NULL);
    tree *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
           // if(temp->left)
             //   cout<<temp->left->data<<"<- ";
            cout<<temp->data<<' ';
           // if(temp->right)
             //   cout<<"->"<<temp->right->data<<endl;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
            cout<<endl;
        }
    }
    cout<<endl;
}
int h(tree *t)
{
    if(!t)
        return 0;
    return max(h(t->left),h(t->right))+1;

}
int isavl(tree *t)
{
    if(!t)
        return 1;
    int f1=isavl(t->left);
    if(abs(h(t->left)-h(t->right))>1)
    return 0;
    int f2=isavl(t->right);
    if(f1&&f2)
          return 1;
    else
        return 0;

}
int main()
{
    for(int i=1;i<10;i++)
    root=ct(i);
    disp();
    cout<<isavl(root);
    return 0;
}
