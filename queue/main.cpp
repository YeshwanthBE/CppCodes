#include <iostream>
using namespace std;
struct q
{
    int r=-1;
    int f=-1;
    int *ar;
    int s=0;
    int c=0;
}*h;
void rs()
{
    h->c*=2;
    h->ar=(int *)realloc(h->ar,sizeof(int)*h->c);
}
void cq(int c)
{
  h=new q();
  h->c=c;
  h->ar=new int[c];
}
void enq(int data)
{
    if(h->c==h->s)
        rs();
    h->r=(h->r+1)%(h->c);
    h->ar[h->r]=data;
    h->s++;
    if(h->f==-1)
        h->f=h->r;
}
int deq()
{
    if(h->s==0)
        return 0;
    int t=h->ar[h->f];
    if(h->f==h->r)
        h->f=h->r=-1;
    else
        h->f=(h->f+1)%(h->c);
    h->s--;
    return t;
}
int main()
{
    cq(1);
    enq(5);
    enq(10);
    cout<<deq()<<' '<<deq();
    return 0;
}
