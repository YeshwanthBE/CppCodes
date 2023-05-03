#include <iostream>
using namespace std;
struct ll
{
    int data;
    ll *next;
};
struct las
{
    ll *top;
    int siz=0;
}*h;
int pop()
{
    if(h->siz)
    {
        int t=h->top->data;
        ll *temp=h->top;
        h->top=h->top->next;
        delete temp;
        h->siz--;
        return t;
    }
   return 0;
}
void push(int a)
{
    ll *temp=new ll;
    temp->data=a;
    temp->next=h->top;
    h->top=temp;
    h->siz++;
    return;
}
void eval(char *p)
{
    h=new las;
    while(*p)
    {
        if(isdigit(*p))
            push(*p-'0');
        else
        {
           int a=pop();
           int b=pop();
           switch(*p)
           {
               case'+':push(a+b);break;
               case'-':push(a-b);break;
               case'*':push(a*b);break;
               case'/':push(a/b);break;
           }
        }
        p++;
    }
    cout<<pop();
}
int main()
{
    char *p="123*+";
    eval(p);
    return 0;
}
