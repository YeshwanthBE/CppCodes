#include <iostream>
using namespace std;
struct ll
{
    int data;
    ll *next;
};
struct q
{
    ll* f=NULL;
    ll* r=NULL;
}*h;
void enq(int data)
{
    if(!h)
        h=new q;
    ll *t=new ll;
    t->data=data;
    t->next=NULL;
    if(h->r)
    {h->r->next=t;
    h->r=t;}
    else
        h->f=h->r=t;
}
int deq()
{
    if(!h->f)
        return NULL;
    ll* t=h->f;
    h->f=h->f->next;
    if(!h->f)
        h->r=h->f;
    int td=t->data;
    delete t;
    return td;
}
int main()
{
    enq(5);
    cout << deq() << endl;
    return 0;
}
