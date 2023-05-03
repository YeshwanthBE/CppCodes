#include <iostream>
using namespace std;
void disp();
struct ll{
    ll *next;
    int data;
}*h;
void add(int data,ll *head){
    if(head==NULL)
        {h=new ll;
        h->data=data;
        h->next=NULL;
        }
    else{
        while(head->next!=NULL)
            head=head->next;
        head->next=new ll;
        head->next->next=NULL;
        head->next->data=data;
    }
    if(data==9)
        disp();
}
inline void disp()
{
    ll *h1=h;
    while(h1){
        cout<<h1->data<<" ";
        h1=h1->next;}
    cout<<endl;
}
void swp()
{
    int i=0;
    ll *c=h;ll *p,*n;
    p=NULL;n=c->next;
    while(c->next&&c->next->next)
    {
        if(p==NULL)
        {
        c->next=n->next;
        n->next=c;
        h=n;
        }
        p=c;
        c=p->next;
        n=c->next;
        if(i++%3==0){
        c->next=n->next;
        n->next=c;
        p->next=n;
        }
    }
    disp();
}
ll * rev(ll *hr)
{
    if(hr->next==NULL)
        {
            h=hr;
            return hr;
        }
        ll *t=hr->next;
        hr->next=NULL;
    rev(t)->next=hr;
    return hr;
}
void swp2()
{


}
int main()
{
    h=NULL;
    for(int i=0;i<10;i++)
        add(i,h);
    h->next=rev(h);
    disp();
    //swp();
    return 0;
}
