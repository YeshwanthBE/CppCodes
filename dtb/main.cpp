#include <iostream>
#include <queue>
#include<stack>
#define dq() q.front();q.pop()
using namespace std;
struct dll
{
    int data;
    dll *f=NULL,*b=NULL;
}*head=NULL;
struct bst
{
    int data;
    bst *left=NULL,*right=NULL;
}*root=NULL;
void cl(int data,dll *h=head)
{
    dll *temp=new dll;
    temp->data=data;
    if(!head)
        head=temp;
    else
    {
        while(h->f)
            h=h->f;
        h->f=temp;
        temp->b=h;
    }
    return;
}
void disp(dll *h=head)
{
    while(h)
        {cout<<h->data<<' ';h=h->f;}
    cout<<endl;
}
void cbfl(dll *h=head,bst *r=root)
{
    if(!h)
        return;
    if(!r)
    {
        root=new bst;
        root->data=h->data;
        h=h->f;
        r=root;
    }
    while(h)
    {
        bst *temp=new bst;
        temp->data=h->data;
        while(r)
        {
            if(h->data<r->data)
            if(r->left)
                r=r->left;
            else
                {r->left=temp;break;}
        else
            if(r->right)
                r=r->right;
            else
                {r->right=temp;break;}
        }
        h=h->f;
        r=root;
    }
}
dll* fm(dll *h=head,int i=0)
{
    if(!h)
        return NULL;
    dll *h2=head;
    while(h2&&h2->f)
    {h=h->f;h2=h2->f->f;}
    return h;
}
dll * cbtfsl(dll *h=head)
{
    if(!h||!h->f)
        return h;
    dll *fh,*sh,*md;
    md=fm(h);
    fh=h;
    while(fh->f!=md)
        fh=fh->f;
    fh->f=NULL;
    sh=md->f;
    md->f=NULL;
    md->b=cbtfsl(h);
    md->f=cbtfsl(sh);
    return md;
}
void btdisp(dll *r=head)
{
    //cout<<r->data;
    if(!r)
        return;
    btdisp(r->b);
    cout<<r->data<<' ';
    btdisp(r->f);
}

int main()
{
    for(int i=0,k;i<5;i++,k=rand(),cl(i));
    disp();
    head=cbtfsl();
    //cout<<head->f->f<<' '<<head->f->b<<' '<<head->f->data;
    //btdisp(head);
    return 0;
}
