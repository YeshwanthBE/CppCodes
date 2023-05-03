#include <iostream>
#include<stack>
#include <queue>
#define dq() q.front();q.pop()
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
void disp(tree *t)
{
    queue<tree *>q;
    q.push(t);//q.push(NULL);
    tree *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            cout<<temp->data<<' ';
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
        /*else
        {
            if(!q.empty())
                q.push(NULL);
            cout<<endl;
        }*/
    }
    cout<<endl;
}
int mind()
{
    queue<tree *>q;
    q.push(r);bool flag=0;int level=0;
    while(!q.empty())
    {
        tree *temp=dq();
        if(temp->left)
            {q.push(temp->left);flag=1;}
        if(temp->right)
            {q.push(temp->right);flag=1;}
        if(flag)
            {level++;flag=0;}
        else
            return level;
    }
    return level;
}
int mdr(tree *t=r,int level=1)
{
    if(!t)
        return 0;
    if(!t->left&&!t->right)
        return level;
    int l1,l2;
        level++;
    if (t->left)
        l1=mdr(t->left,level);
    if(t->right)
        l2=mdr(t->right,level);
    level=l1>l2?l2:l1;
    return level;
}
int cbt()
{
  queue<tree *>q;
    q.push(r);q.push(NULL);
    tree *temp;bool flag=0;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            if(temp->left&&temp->right)
                flag=1;
            else
                flag=0;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
            if(!flag&&!q.empty())
                return 0;
            else
                flag=0;
        }
    }
    return 1;
}
int main()
{
    for(int i=1;i<4;ct(i++));
    disp(r);
    cout<<cbt();
    return 0;
}
