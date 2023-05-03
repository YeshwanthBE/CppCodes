#include <iostream>
using namespace std;
struct ll
{
    int a;
    ll *next=NULL;
};
struct s
{
    ll *top=NULL;
    int siz=-1;
};
void push(s *h,int data)
{
        ++h->siz;
        ll *temp=new ll;
        temp->a=data;
        temp->next=h->top;
        h->top=temp;
}
void peek(s h)
{
    while(h.siz--!=-1)
    {
        cout<<h.top->a<<' ';
        h.top=h.top->next;
    }cout<<endl;
}
void pop(s *h)
{
        ll *t=h->top;
        h->top=t->next;
        cout<<t->a;
        h->siz--;
        free(t);
        cout<<endl;
}

int main()
{
    s head;
    for(int i=0;i<5;i++)
    push(&head,i);
    peek(head);
    int i=3;
    while(i--)
    pop(&head);
    peek(head);
    return 0;
}
