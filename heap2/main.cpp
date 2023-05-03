#include <iostream>

using namespace std;
void swp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
struct heap
{
    int data[12];
    int cnt=0;
    int capacity=12;
}*head=NULL;
void plup(heap *h=head)
{
    int temp;
    int i=h->cnt-1;
    while(i>-1&&(h->data[i]>h->data[(i-1)/2]))
    {
        swp(&h->data[i],&h->data[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pldw(heap *h=head)
{
    int temp;
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i]<h->data[j]||h->data[j]<h->data[j+1]))
    {
        j=h->data[j]>h->data[j+1]?j:j+1;
        swp(&h->data[i],&h->data[j]);
        i=j;
        j=i*2+1;
    }
}
heap* ct(int k,heap *h=head)
{
    if(!h)
        h=new heap;
    if(h->cnt+1>h->capacity)
        return h;
    h->data[h->cnt++]=k;
    plup(h);
    return h;
}
int del(heap *h=head)
{
    int temp=h->data[0];
    h->data[0]=h->data[h->cnt-1];
    h->cnt--;
    pldw(h);
    return temp;
}
void disp(heap *h=head)
{
    if(!h)
        return;
    for(int i=0;i<h->cnt;i++)
        cout<<h->data[i]<<' ';
    cout<<endl;
}
void mxpr(int ar[12],int br[12],int n)
{
    heap *h1=NULL,*h2=NULL;
    for(int i=0;i<12;i++)
        h1=ct(ar[i],h1);
    for(int i=0;i<12;i++)
        h2=ct(br[i],h2);
    for(int j=0;j<n;j++)
    cout<<del(h1)<<','<<del(h2)<<endl;
}
int main()
{
    int ar[12],br[12];
    for(int i=0,k=rand();i<12;k=rand(),i++)
        {ar[i]=k%100;
         br[i]=(rand()+k)%100;
        }


    mxpr(ar,br,12);
    disp();
    return 0;
}
