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
bst* fmin(bst *t=r)
{
    while(t!=NULL)
    {
        if(t->left)
        t=t->left;
        else
        break;
    }
    return t;
}
bst* fmax(bst *t=r)
{
    while(t!=NULL)
    {
        if(t->right)
        t=t->right;
        else
        break;
    }
    return t;
}
bst* fnd(int data,bool flag=0,bst *t=r)
{
    if(t->data==data)
        return t;
    bst *temp;
    while(t)
    {
        if(t->data==data)
              return flag?t:temp;
        else if(data<t->data)
            {temp=t;t=t->left;}
        else
            {temp=t;t=t->right;}
    }
    return NULL;
}
bst * delwr(int data,bst *t=r)
{
    if(!t)
        return NULL;
    else if(data<t->data)
        t->left=delwr(data,t->left);
    else if(data>t->data)
        t->right=delwr(data,t->right);
    else
    {
     if(t->left&&t->right)
     {
         t->data=fmax(t->left)->data;
         t->left=delwr(t->data,t->left);
     }
     else
     {
         bst* temp=t;
         t=t->right?t->right:t->left;
         delete temp;
     }
    }
    return t;
}
void del(int data,bst *t=r)
{
    bst *prnt=fnd(data,t);
    if(prnt->data==data)
    {bst *temp;
        if(prnt->left||prnt->right)
        temp=prnt->left?fmax(t->left):fmin(t->right);
        else
        {delete prnt;return;}
        t->data=temp->data;
        prnt=fnd(temp->data);
        t=temp;
    }
    else
    {
        if(prnt->right&&prnt->right->data==data)
            t=prnt->right;
        else
            t=prnt->left;
    }
    if(t->left&&t->right)
    {
        bst *temp=fmax(t->left);
        prnt=fnd(temp->data);
        t->data=temp->data;
        t=temp;
    }
    if(t->left||t->right)
    {
        bst *tmp;
        tmp=t->left?t->left:t->right;
        if(prnt->right==t)
            prnt->right=tmp;
        else
            prnt->left=tmp;
        delete t;
    }
    else
    {
        if(prnt->right==t)
            prnt->right=NULL;
        else
            prnt->left=NULL;
        delete t;
    }

}
bst *lca(bst *x,bst *y,bst *t=r)
{
    if((x->data<=t->data&&y->data>=t->data)||(x->data>=t->data&&y->data<=t->data))
        return t;
    else if(t->data<x->data&&t->data<y->data)
        return lca(x,y,t->right);
    else
        return lca(x,y,t->left);

}
bool isbst(bst *t=r)
{
    if(!t||!t->left||!t->right)
        return 1;
    if(fmin(t->left)->data>t->data||fmax(t->right)->data<t->data)
        return 0;
    else if(t->left&&!isbst(t->left))
        return 0;
    else if(t->right&&!isbst(t->right))
        return 0;
    else
        return 1;
}
bool ib(int *prev,bst *t=r)
{
    if(!t)
        return 1;

    if(!ib(prev,t->left))
        return 0;
    if(t->data<*prev)
        return 0;
    *prev=t->data;
    return ib(prev,t->right);

}

int main()
{
    for(int i=0,k=0;i<10;i++,k=rand(),ct(k%100));
    disp2();
    int imin=INT_MIN;
    cout<<ib(&imin);
    //disp2();
    return 0;
}
