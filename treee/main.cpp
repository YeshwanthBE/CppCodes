#include <iostream>
#include <cmath>
#include <queue>
#define dq() q.front();q.pop()
using namespace std;
struct bst
{
    int data;
    bst *left=NULL,*right=NULL;
}*root=NULL;
void ct(int data,bst *t=root)
{
    bst *temp=new bst;
    temp->data=data;
    if(!t)
       root=temp;
    else
    {
        while(t)
        {
            if(data<t->data)
                if(!t->left)
                    {t->left=temp;return;}
                else
                    t=t->left;
            else
                if(!t->right)
                    {t->right=temp;return;}
                else
                    t=t->right;
        }

    }
}
void disp(bst *t=root)
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
void iot(bst *t=root)
{
    if(!t)
        return;
    iot(t->left);
    cout<<t->data<<' ';
    iot(t->right);
}
bst* kse(int *k,bst *t=root)
{
    if(!t)
        return NULL;
    bst *temp=kse(k,t->left);
    if(temp!=NULL)
        return temp;
    if(!--*k)
        return t;
    return kse(k,t->right);
}
bst* fr(int data,bst **prev=NULL,bst*t=root)
{
    if(!t)
        return NULL;
    bst * temp=fr(data,prev,t->right);
    if(temp) return temp;
    if(t->data==data)
        return t;
    else if(t->data<data)
        return *prev;
    *prev=t;
        return fr(data,prev,t->left);
}
void rg(int k1,int k2,bst *t=root)
{
    if(!t)
        return ;
    if(t->data>=k1)
        rg(k1,k2,t->left);
    if(t->data>=k1&&t->data<=k2)
        cout<<t->data<<' ';
    if(t->data<=k2)
        rg(k1,k2,t->right);
}
int main()
{
    for(int k,i=0;i<10;i++,k=rand(),ct(k%100));
    disp();
    rg(57,58);
    return 0;
}
