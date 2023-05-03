#include <iostream>
#include <cmath>
#include <queue>
#define dq() q.front();q.pop()
using namespace std;
struct bst
{
    int data;
    bst *left=NULL,*right=NULL,*nxt=NULL;
}*r=NULL;
void ct(int data,bst *t=r)
{
    bst *temp=new bst;
    temp->data=data;
    if(!t)
    r=temp;
    else
        while(t!=NULL)
            if(t->data==data)
                return;
            else if(t->data>data)
                if(t->left)
                    t=t->left;
                else
                    {t->left=temp;return;}
            else if(t->data<data)
                if(t->right)
                t=t->right;
                else
                {t->right=temp;return;}
}
void disp(bst *t=r)
{
   if(!t)
    return;
   disp(t->left);
   cout<<t->data<<' ';
   disp(t->right);
   return;
}
void disp2(bst *t=r)
{
    queue<bst *>q;
    q.push(t);q.push(NULL);
    bst *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            cout<<temp->data<<' ';
            /*if(temp->left)cout<<"left-> "<<temp->left->data<<' ';
            if(temp->right)cout<<"right-> "<<temp->right->data;
            cout<<endl;*/
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
void lknt(bst *t)
{
    queue<bst *> q;q.push(t);q.push(NULL);
    bst * temp,*prev;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(prev)
                prev->nxt=temp;
            prev=temp;
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
            prev=NULL;
        }
    }
}
void disp3(bst *t=r)
{
    while(t)
    {
        bst *temp=t;
        do{cout<<temp->data<<' ';temp=temp->nxt;}while(temp);

        if(t->left)
            t=t->left;
        else
            t=t->right;
    }
}
int nofl(bst *t=r)
{
    if(!t)
        return 0;
    else
    {
        int a=nofl(t->left);
        int b=nofl(t->right);
        if(!a&&!b)
            return 1;
        return 0;
    }
}
int main()
{
    for(int i=0,k=0;i<3;i++,k=rand(),ct(k%100));
    disp2();
    cout<<nofl();
    return 0;
}
