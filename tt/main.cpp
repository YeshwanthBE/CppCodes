#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct tree
{
    int data;
    tree *right=NULL;
    tree *left=NULL;
}*r=NULL;
void io()
{
    stack<tree *>s;
    tree *temp=r;
    while(1)
    {
        while(temp)
        {
                s.push(temp);
                temp=temp->left;
        }
        if(s.empty())
            break;
        temp=s.top();s.pop();
         cout<<temp->data<<' ';
        temp=temp->right;
    }
}
void po()
{
    stack<tree *>s;
    s.push(r);tree *temp;
    while(!s.empty())
    {
        temp=s.top();s.pop();
        cout<<temp->data<<' ';
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
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
void poo()
{
    stack<tree *>s;
    tree *temp=r;tree *p=NULL;
    do
    {
        while(temp)
        {
            s.push(temp);
            temp=temp->left;
        }
        while(!temp&&!s.empty())
        {
            temp=s.top();
            if(!temp->right||temp->right==p)
                {cout<<temp->data<<' ';
            s.pop();
            p=temp;
            temp=NULL;}
            else
                temp=temp->right;
        }

    }while(!s.empty());
}
int main()
{
    for(int i=1;i<16;ct(i),i++);
        //po();cout<<endl;
        io();cout<<endl;
        //poo();

    return 0;
}
