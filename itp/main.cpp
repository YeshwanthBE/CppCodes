#include <iostream>
#include <cstring>
using namespace std;
struct s{
int siz=0;
char ar[18];
int top=-1;
};
void push(s *h,int data)
{
    h->top++;
    h->ar[h->top]=data;
    h->siz++;
}
char pop(s *h)
{
    char a=h->ar[h->top];
    h->ar[h->top]=0;
    h->top--;
    h->siz--;
    return a;
}
char peek(s h)
{
    if(h.top>=0)
    return h.ar[h.top];
    return NULL;
}
int pot(char a)
{
    if(a=='*'||a=='\\')
        return 2;
    if(a=='+'||a=='-')
        return 1;

        return 0;
}
void itp(char *p)
{
    s h;
    int i=0;char x;
    while(p[i])
    {
        if(isalnum(p[i]))
            cout<<p[i];
        else if(p[i]=='(')
                push(&h,p[i]);
        else if(p[i]==')')
                {
                    while((x=pop(&h))!='(')
                      cout<<x;
                        //pop(&h);
                }
        else
        {
            while(pot(p[i])<=pot(peek(h)))
                cout<<pop(&h);
            push(&h,p[i]);
        }

        i++;
    }
    while(h.top>=0)
           cout<<pop(&h);

}
int main()
{
    char *p="(a+b)*c";
    itp(p);
    return 0;
}
