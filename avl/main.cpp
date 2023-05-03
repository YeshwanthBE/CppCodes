#include <iostream>
#include <queue>
#define dq() q.front();q.pop()
using namespace std;
struct avl
{
    int data,height=0;
    avl *left=NULL,*right=NULL;
}*root=NULL;
int height(avl *r)
{
    if(r)
        return r->height;
    return -1;
}
avl* lr(avl *r)
{
    r->right->left=r;
    avl *temp=r->right;
    r->right=NULL;
    return temp;
}
avl * rr(avl *r)
{
    r->left->right=r;
    avl *temp=r->left;
    r->left=NULL;
    return temp;
}
avl* rlr(avl *r)
{
    r->right->left->right=r->right;
    r->right=r->right->left;
    r->right->right->left=NULL;
    return lr(r);
}
avl* lrr(avl *r)
{
    r->left->right->left=r->left;
    r->left=r->left->right;
    r->left->left->right=NULL;
    return rr(r);

}
avl* ct(int data,avl *r=root)
{
    if(!r)
    {
        r=new avl;
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
void disp(avl *t=root)
{
    queue<avl *>q;
    q.push(t);q.push(NULL);
    avl *temp;
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
int main()
{
    for(int i=1;i<10;i++)
    root=ct(i);
disp();
    return 0;
}
