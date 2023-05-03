#include <iostream>
#include <stack>
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
void disp(tree *t=r)
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
tree* pos(tree *t=r)
{
   static stack<tree *>s;
    if(!t)
        return NULL;
    if(t->left)
    {
        s.push(t);
        return t->left;
    }
    else
    {
        while(!t->right&&!s.empty())
            {t=s.top();s.pop();}
            if(t->right)
                return t->right;
            else
                return NULL;
    }


}
static bool flag=1;
tree* tios(tree *t=r)
{
    static stack<tree *>s;
    tree* temp;
    if(flag&&t->left)
    {
        while(t&&t->left)
            {s.push(t);t=t->left;}
            flag=0;
        return t;
    }
    else
    {
        temp=s.top();
        if(temp->left==t)
        {
            return temp;
        }
        else if(temp==t)
        {
            if(temp->right->left||temp->right->right)
            {s.pop();flag=1;}
            return temp->right;
        }
        else if(temp->right==t)
        {
            s.pop();
            if(!s.empty())
                return s.top();
            else
                return NULL;
        }
    }

}
void disp2()
{
    tree *temp=tios();
    while(temp)
    {
        if(!flag)
        cout<<temp->data<<' ';
        temp=tios(temp);
    }

}
int main()
{
    for(int i=1;i<8;ct(i++));
    disp();
    disp2();
    return 0;
}
