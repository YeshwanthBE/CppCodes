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
dll* fm(dll *h=head)
{
    if(!h)
        return NULL;
    dll *h2=h;
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
    if(sh)
        sh->b=NULL;
    md->b=cbtfsl(h);
    md->f=cbtfsl(sh);
    return md;
}
void d2(dll *t)
{
    queue<dll *>q;
    q.push(t);q.push(NULL);
    dll *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            cout<<temp->data<<' ';
        if(temp->b)
            q.push(temp->b);
        if(temp->f)
            q.push(temp->f);
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
int main()
{
    for(int i=0,k;i<10;i++,k=rand(),cl(i));
    disp();
    head=cbtfsl();
    d2(head);
    return 0;
}
