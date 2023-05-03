#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
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
struct dll
{
    int data;
    dll *fr=NULL,*bk=NULL;
}*ll=NULL;
dll* btll(bst *t=r)
{
    if(!t)
        return NULL;
    dll *temp=new dll;
    btll(t->left);

}
void ld(dll *t)
{
    dll* t2=t;
    while(t)
    {
        cout<<t->data<<' ';
        t=t->bk;
    }
    cout<<endl;
    while(t2)
    {
        cout<<t2->data<<' ';
        t2=t2->fr;
    }
}
int main()
{
    for(int i=0,k=0;i<10;i++,k=rand(),ct(k%100));
    disp2();
    //dll* t=btll();
    //ld(t);
    cout<<endl;
    ll=new dll;
    disp3();
    return 0;
}
