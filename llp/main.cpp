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
    if(data>=5)
        disp();
}
inline void disp()
{
    ll *head=h;
    while(head){
        cout<<head->data<<" ";
        head=head->next;}
    cout<<endl;
}
void fmid(){
    ll *h1=h;
    ll *h2=h;
while(h2)
{
    h1=h1->next;
    h2=h2->next->next;
}
cout<<h1->data;

}
int rt(ll *head)
{
    if(head->next==NULL)
        return head->data;
    cout<<rt(head->next)<<' ';
    return head->data;
}
void ise(){
ll *h1=h;
while(h1!=NULL&&h1->next!=NULL)
    h1=h1->next->next;
if(h1==NULL)
    cout<<"eve";
else
    cout<<"odd";

}
void rev(){
    ll *h1,*h2;
    h1=h;
    h2=h1->next;
    int temp;
    while(h1&&h1->next)
    {
        temp=h1->data;
        h1->data=h2->data;
        h2->data=temp;
        h1=h2->next;
        if(h1)
        h2=h1->next;
    }
}
void rp(ll **head)
{
    ll *h=*head;
    ll *n=h->next;
    {
        h->next=n->next;
        n->next=h;
        *head=n;
        n=h->next;
    }
    while(h&&n)
    {
        h->next=n->next;
        n->next=h->next->next;
        h->next->next=n;
        h=n;
        n=n->next;
    }
}

int main()
{
    h=NULL;
    for(int i=0;i<6;i++)
    add(i,h);
    //fmid();
    //rt(h);
    rp(&h);
    disp();
    return 0;
}
