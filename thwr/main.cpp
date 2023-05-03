#include <iostream>
#include <queue>
#include<stack>
using namespace std;
struct tree
{
    char data;
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
int th()
{
    queue<tree *>q;
    int level=0;
    q.push(r);
    q.push(NULL);
    tree *temp;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(temp)
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
            level++;
        }
    }
    return level;
}
int nl(int a)
{
    queue<tree *>q;
    q.push(r);
    tree *temp;int cnt=0;int hcnt=0;
    int fcnt=0;bool f3=0;int f=1;;
    while(!q.empty())
    {
        temp=q.front();q.pop();
        if(!temp->right&&!temp->left)
            cnt++;
        else
        {
            if(temp->left)
            {q.push(temp->left);f3=1;f=f<<1;}
            if(temp->right)
            {q.push(temp->right);f=f<<1;f3=!f3;}
            if(f==4)
                fcnt++;
            if(f3)
                hcnt++;
        }
        f=1;
    }
    if(a==1)
    return fcnt;
    if(a==2)
        return hcnt;
    return cnt;
}
void disp(tree *t)
{
    queue<tree *>q;
    q.push(t);q.push(NULL);
    tree *temp;
    while(!q.empty())
    {
        temp=q.front();q.pop();
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
int mx()
{
    queue <tree *>q;
    tree *t;
    q.push(r);q.push(NULL);int ms=0,cs=0;
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(t)
        {
            cs+=t->data;
        if(t->right)
            q.push(t->right);
        if(t->left)
            q.push(t->left);
        }
        else
        {
            if(!q.empty())
            q.push(NULL);
            ms=ms>cs?ms:cs;
            cs=0;
        }
    }
    return ms;
}
void rtl(tree *t,int ar[],int k)
{
    ar[k++]=t->data;
    if(!t->right&&!t->left)
        {
            for(int i=0;i<k-1;i++)
            cout<<ar[i]<<"->";
            cout<<ar[k-1]<<endl;
            k=0;
        }
    if(t->left)
        rtl(t->left,ar,k);
    if(t->right)
        rtl(t->right,ar,k);
}
int pe(tree *t,int sm)
{
    if(!t)
        return 0;
    sm-=t->data;
    if(sm==0)
        return 1;
    int i=0;
    if(t->right)
        i=pe(t->right,sm);
    if(t->left&&!i)
        i=pe(t->left,sm);
    return i;
}
int soe(tree *t,int sm)
{
    if(!t)
        return 0;
    sm+=t->data;
    if(t->left)
        sm=soe(t->left,sm);
    if(t->right)
        sm=soe(t->right,sm);
    return sm;
}
int soewr()
{
     queue <tree *>q;
    tree *t;
    q.push(r);int cs=0;
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(t)
        {
            cs+=t->data;
        if(t->right)
            q.push(t->right);
        if(t->left)
            q.push(t->left);
        }
    }
    return cs;
}
tree* mirror(tree *t)
{
    if(t)
    {
       // if(t->left)
            mirror(t->left);
        //if(t->right)
            mirror(t->right);
    tree *temp=t->right;
    t->right=t->left;
    t->left=temp;
    }
    return t;
}
int mc(tree * t1,tree *t2)
{
    if(!t1&&!t2)
        return 1;
    if(!t1||!t2)
        return NULL;
    if(t1->data!=t2->data)
        return 0;
    return(mc(t1->right,t2->left)&&mc(t1->left,t2->right));
}
tree * LCA(tree *t,int a,int b)
{
    if(!t)
        return NULL;
    if(t->data==a||t->data==b)
        return t;
    tree *l=NULL,*r=NULL;
    l=LCA(t->left,a,b);
    r=LCA(t->right,a,b);
    if(l&&r)
        return t;
    return l?l:r;
}
int pa(tree *t,int a)
{
    if(!t)
        return 0;
    if(t->data==a)
    {cout<<t->data<<' ';return 1;}
    int x;
    if(t->left)
        x=pa(t->left,a);
    if(t->right&&!x)
        x=pa(t->right,a);
    if(x)
        cout<<t->data<<' ';

    return x;
}
int pebv(tree *t,int data)
{
    if(!t)
        return 0;
    int x;
    if(t->data==data)
        x=1;
    if(t->left&&!x)
        x=pebv(t->left,data);
    if(t->right&&!x)
        x=pebv(t->right,data);
    if(x)
    cout<<t->data<<' ';
    return x;
}
void zz()
{
    stack<tree *>s1,s2;
    int i=0;
    s1.push(r);tree *temp;
    while(!s1.empty())
    {
        temp=s1.top();s1.pop();
        if(temp)
        {
            cout<<temp->data<<' ';
            if(i%2==0)
            {
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
            else
            {
                if(temp->right)
                    s2.push(temp->right);
                if(temp->left)
                    s2.push(temp->left);
            }
            if(s1.empty())
            {
                i++;
                stack<tree *> t;
                s1=s2;
                s2=t;
                cout<<endl;
            }
        }


    }
}
tree* cto(int par[],int iar[],int ii,int is)
{
    static int pi=0;
    tree *temp;
    if(ii==is)
    {
        temp=new tree;
        temp->data=iar[ii];
        pi++;
        return temp;
    }
    for(int k=ii;k<is;k++)
        if(iar[k]==par[pi])
            {
                temp=new tree;
                temp->data=iar[k];
                pi++;
                temp->left=cto(par,iar,ii,k-1);
                temp->right=cto(par,iar,k+1,is);
                break;
            }
    return temp;
}
tree * cp(tree *t,char ar[])
{
    static int i=0;
    if(!ar[i])
        return NULL;
    tree *temp=new tree;
    temp->data=ar[i];i++;
    if(temp->data=='L'||temp->data=='l')
        return temp;
    if(temp->data=='i'||temp->data=='I')
    {
        temp->left=cp(t,ar);
        temp->right=cp(t,ar);
    }
    return temp;
}
int main()
{
    char ar[]={'I','L','I','L','L'};
    tree *t=cp(t,ar);
    disp(t);
    return 0;
}
