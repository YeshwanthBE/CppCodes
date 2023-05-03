#include <iostream>
#include <cmath>
#include <queue>
#define dq() q.front();q.pop()
using namespace std;
struct bst
{
    int data;
    bst *left=NULL,*right=NULL;
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
int ckey(int k,bst *t=r)
{
    int t1,t2;t1=t2=INT_MIN;
    if(!t)
        return INT_MIN;
    if(k<t->data)
        t1=ckey(k,t->left);
    if(k>t->data)
        t2=ckey(k,t->right);
    if(abs(t1-k)>abs(t2-k))
        return abs(t->data-k)>abs(t2-k)?t2:t->data;
    else
        return abs(t->data-k)>abs(t1-k)?t1:t->data;
}
bst *rmn(bst *t=r)
{
    if(!t)
        return NULL;
    t->left=rmn(t->left);
    t->right=rmn(t->right);
    if(!t->left&&!t->right)
        return t;
    else if(!t->left)
        return t->right;
    else if(!t->right)
        return t->left;
    return t;
}
bst *rl(bst *t=r)
{
    if(!t)
        return NULL;
    if(!t->left&&!t->right)
    {delete t;return NULL;}
    t->left=rl(t->left);
    t->right=rl(t->right);
}
bst *pe(int p,int e,bst *t=NULL)
{
    if(!t)
        return NULL;
    t->left=pe(p,e,t->left);
    t->right=pe(p,e,t->right);
    if(t->data>=p&&t->data<=e)
        return t;
     if(t->data<=p)
     return t->right;
     if(t->data>=e)
        return t->left;
}
int main()
{
    for(int i=0,k=0;i<10;i++,k=rand(),ct(k%100));
    disp2();
    r=pe(25,100,r);
    disp2();
    return 0;
}
