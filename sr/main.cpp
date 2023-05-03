#include <iostream>
using namespace std;
struct ll
{
    int data;
    ll* next;
};
struct las
{
    ll *top;
    int siz=0;
}*h1;
void push(las **hx,int data)
{
    las *h=*hx;
    if(!h)
    {
        *hx=new las;
        h=*hx;
        h->top=new ll;
        h->top->data=data;
        h->top->next=NULL;
    }
    else
    {
        ll *t=new ll;
        t->data=data;
        t->next=h->top;
        h->top=t;
    }
    h->siz++;
}
int pop(las *h,int a)
{
    if(h->siz==0)
        return 0;
    int data=h->top->data;
    ll *t=h->top->next;
    delete h->top;
    h->top=t;
    h->siz--;

    if(a)
        return data;
    else
        cout<<data<<' ';
        return NULL;
}
void rev()
{
    las *h2=new las;
    while(h1->siz)
    {
        push(&h2,pop(h1,1));
    }
    delete h1;
    h1=h2;
}
void iab(las *h,int data);
void r(las *h)
{
    if(h->siz==0)
    {
        return;
    }
        int t=pop(h,1);
        r(h);
        iab(h,t);
}
void iab(las *h,int data)
{
    if(h->siz==0)
    {
        push(&h,data);
        return;
    }
    int t=pop(h,1);
    iab(h,data);
    push(&h,t);
}
void disp(las *h)
{
    int i=h->siz;
    ll *h1=h->top;
    while(i--)
    {
        cout<<h1->data<<' ';
        h1=h1->next;
    }
    cout<<endl;
}
int main()
{
    for(int i=0;i<500;i++)
        push(&h1,i);
        disp(h1);
    r(h1);
    disp(h1);
    return 0;
}
