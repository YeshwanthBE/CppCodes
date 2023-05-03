#include <iostream>
#include <cctype>
using namespace std;
struct ll
{
    char data;
    ll *next;
};
struct las
{
    ll *top=NULL;
    int siz=0;
}*h;
char pop()
    {
        if(h->top)
        {
            char a=h->top->data;
            ll *temp=h->top->next;
            free(h->top);
            h->top=temp;
            h->siz--;
            return a;
        }
        return NULL;
    }
void push(char data)
    {
        ll *temp=h->top;
        h->top=new ll();
        h->top->data=data;
        h->top->next=temp;
        h->siz++;
    }
void rrd(char *p)
{
    while(*p)
    {
        if(h->siz==0||h->top->data!=*p)
            push(*p);
        else
            {while(h->top->data==*p)
            {pop();p++;}
             push(*p);}
        p++;
    }
}
int main()
{
    char *p="mississippi\0";
    h=new las;
    rrd(p);
    while(h->top>0)
        cout<<pop();
    return 0;
}
