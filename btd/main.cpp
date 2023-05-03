#include <iostream>
#include <stack>
#include<cctype>
#include <queue>
#define dq() q.front();q.pop()
#define tp() s.top();s.pop();
using namespace std;
struct dll
{
    int data;
    dll *fnt=NULL,*bk=NULL;
}*head;
struct tree
{
    int data;
    tree *left=NULL,*right=NULL;
}*root=NULL;
void ct(int data,tree *r=root)
{
    tree *temp=new tree;
    temp->data=data;
    if(!r)
    {root=temp;return;}
    while(r)
    {
        if(!r->left&&data<r->data)
        {r->left=temp;return;}
        if(!r->right&&data>r->data)
        {r->right=temp;return;}
        if(data<r->data)
            r=r->left;
        else
            r=r->right;
    }
}
void iot(tree *r=root)
{
    stack<tree *>s;
    while(1)
    {
        while(r)
        {
            s.push(r);
            r=r->left;
        }
        if(s.empty())
        {
            cout<<endl;return;
        }
        r=tp();
        cout<<r->data<<' ';
        r=r->right;
    }

}
dll* bd(tree *t)
{
    dll *temp=new dll;
    temp->data=t->data;
    return temp;
}
void btd(tree *r=root,dll* h=head)
{
    stack<tree *>s;
    dll *prev=NULL;
    while(1)
    {
        while(r)
        {
            s.push(r);
            r=r->left;
        }
        if(s.empty())
            return;
        r=tp();
        dll* temp=bd(r);
        if(!prev)
        {
            head=temp;
            prev=head;
        }
        else
        {
            prev->fnt=temp;
            temp->bk=prev;
            prev=temp;
        }
            r=r->right;
    }
}
void dip(dll* h=head)
{
    while(1)
    {
        cout<<h->data<<' ';
        if(!h->fnt)
            break;
        h=h->fnt;
    }
    cout<<endl;
    while(h)
    {
        cout<<h->data<<' ';
        h=h->bk;
    }
    cout<<endl;
}
void disp3(tree *t=root)
{
    queue<tree *>q;
    q.push(t);q.push(NULL);
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
        else
        {
            if(!q.empty())
                q.push(NULL);
            cout<<endl;
        }
    }
    //cout<<endl;
}
void btdr(dll **prev,tree* t=root)
{
    if(!t)
        return;
    btdr(prev,t->left);
    dll *h=bd(t);
    if(!*prev)
    {*prev=head=bd(t);}
    else
    {h=bd(t);h->bk=*prev;(*prev)->fnt=h;*prev=h;}
    btdr(prev,t->right);
}
tree * btdr2(tree **ltail,tree* t=root)
{
    tree *left,*right,*rtail;
    if(!t)
    {
     *ltail=NULL;return NULL;
    }
    left=btdr2(ltail,t->left);
    right=btdr2(&rtail,t->right);
    if(!right)
    *ltail=t;
    else
    {right->left=t;
    *ltail=rtail;}
    if(!left)
    return t;
    else
    {
        (*ltail)->right=t;
        return left;    }
}
int main()
{
    for(int i=0,k=0;i<10;i++,k=rand(),ct(k%100));
    //ct(2);ct(1);ct(3);
    //iot();
    disp3();
    tree *prev=NULL;
    btdr2(&prev);
    dip();
    return 0;
}
