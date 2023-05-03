#include <iostream>
#include <cmath>
#include<queue>
#define dq() q.front(); q.pop()
using namespace std;
struct tree
{
    int data;
    tree *left=NULL,*right=NULL;
}*root=NULL;
tree * ct(int h=0,tree *t=root)
{
    if(h<0)
        return NULL;
    t=new tree;
    t->left=ct(h-1,t->left);
    t->data=rand()%100;
    t->right=ct(h-2,t->right);
    return t;
}
void disp2(tree *t=root)
{
    if(!t)
        return;
    disp2(t->left);
    cout<<t->data<<' ';
    disp2(t->right);
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
int main()
{
   root=ct(4);
   disp();
    return 0;
}
