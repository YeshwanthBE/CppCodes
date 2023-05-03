#include <iostream>
#include<queue>
#include<stack>
#define dq() q.front();q.pop();
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
void revo()
{
    tree *temp;
    stack<int>s;
    queue<tree *>q;
    q.push(r);
    while(!q.empty())
    {
        temp=dq();
        s.push(temp->data);
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }
    while(!s.empty())
       {
         cout<<s.top()<<' ';
         s.pop();
       }
}
int main()
{
    for(int i=1;i<8;ct(i++));
    revo();
    return 0;
}
