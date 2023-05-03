#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct item
{
    char data;
    int freq;
    item *left=NULL,*right=NULL;
};
void ditem(item *a)
{
    cout<<a->data<<' '<<a->freq<<endl;
}
item* ctitm(char data,int freq)
{
        item *i=new item;
        i->data=data;
        i->freq=freq;
        return i;
}
void swp(item **a,item **b)
{
    item *temp=*a;
    *a=*b;
    *b=temp;
}
struct heap
{
    item* data[12];
    int cnt=0;
    int capacity=12;
}*head=NULL;
void plup(heap *h)
{
    int i=h->cnt-1;
    while(i>0&&(h->data[i]->freq<h->data[(i-1)/2]->freq))
    {
        swp(&h->data[i],&h->data[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pldw(heap *h)
{
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i]->freq>h->data[j]->freq||h->data[i]->freq>h->data[j+1]->freq))
    {
        j=h->data[j]->freq<h->data[j+1]->freq?j:j+1;
        swp(&h->data[i],&h->data[j]);
        i=j;
        j=i*2+1;
    }
}
heap* cthp(item *k,heap *h)
{
    if(!h)
        h=new heap;
    if(h->cnt+1>h->capacity)
        return h;
    h->data[h->cnt++]=k;
    plup(h);
    return h;
}
item* del(heap *h)
{
    item* temp=h->data[0];
    h->data[0]=h->data[h->cnt-1];
    if(--h->cnt<0)
        return NULL;
    pldw(h);
    return temp;
}
heap *heapcrete()
{
    heap *hh=NULL;
    hh=cthp(ctitm('a',1),hh);
    cthp(ctitm('b',2),hh);
    cthp(ctitm('c',3),hh);
    cthp(ctitm('d',4),hh);
    return hh;
}
item * merg(item *a,item *b)
{
    int mfreq=a->freq+b->freq;
    return ctitm(a->data,mfreq);
}
item* huffman(heap *hh)
{
    item *t1,*t2,*t3;int k=0;
    while(hh->cnt>1)
    {
        t1=del(hh);t2=del(hh);
        t3=merg(t1,t2);
        t3->left=t1;t3->right=t2;
        cthp(t3,hh);
    }
    return del(hh);
}
void iot(item *i,char a[10],int k=0)
{
    if(!i->left&&!i->right)
        {
            a[k]='\0';
            cout<<i->data<<' '<<a<<endl;
            return;
        }
    a[k]='0';
    iot(i->left,a,k+1);
    a[k]='1';
    iot(i->right,a,k+1);
    return;

}
int main()
{
     heap *hh=heapcrete();
     item *i=huffman(hh);
     char a[10];
     iot(i,a);
    return 0;
}
