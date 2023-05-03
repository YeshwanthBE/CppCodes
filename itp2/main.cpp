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
    }
char peek()
    {
        if(h->top)
            return h->top->data;
        return NULL;
    }
int pot(char x)
{
    if(x=='*'||x=='/')
        return 2;
    if(x=='+'||x=='-')
        return 1;
    return 0;
}
las *itp(char *p)
{
    char x;
    h=new las();
    while(*p)
    {
        if(isalnum(*p))
            cout<<*p;
        else if(*p=='(')
            push(*p);
        else if(*p==')')
            while((x=pop())!='(')
                    cout<<x;
        else
        {
            while(pot(*p)<=pot(peek()))
            cout<<pop();
            push(*p);
        }
        p++;
    }
    while(h->top)
        cout<<pop();
}
int main()
{
    char *p="(a+b)+c*d\0";
    itp(p);
    return 0;
}
