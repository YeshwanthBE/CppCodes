#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int data[10];
    int mxs;
};
item* ctitm(int ar[],int mxs)
{
        item *i=new item;
        i->data[mxs];
        for(int j=0;j<mxs;j++)
            i->data[j]=ar[j];
        i->mxs=mxs;
        return i;
}
void ditem(item *a)
{
    for(int i=0;i<a->mxs;i++)
        cout<<a->data[i]<<' ';
    cout<<endl;
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
    while(i>0&&(h->data[i]->mxs<h->data[(i-1)/2]->mxs))
    {
        swp(&h->data[i],&h->data[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pldw(heap *h)
{
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i]->mxs>h->data[j]->mxs||h->data[j]->mxs<h->data[j+1]->mxs))
    {
        j=h->data[j]->mxs<h->data[j+1]->mxs?j:j+1;
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
    int ar[4]={1,2,3,4},br[1]={5},cr[8]={6,7,8,9,10,11,12,13},dr[2]={14,15};
    heap *hh=NULL;
    hh=cthp(ctitm(ar,4),hh);
    cthp(ctitm(br,1),hh);
    cthp(ctitm(cr,8),hh);
    cthp(ctitm(dr,2),hh);
    return hh;
}
item * merg(item *a,item *b)
{
    int mmxs=a->mxs+b->mxs;
    int ar[mmxs];
    int i,j,k;
    for(i=j=k=0;i<a->mxs&&j<b->mxs;k++)
    {
        if(a->data[i]>b->data[j])
            ar[k]=b->data[j++];
        else
            ar[k]=a->data[i++];
    }
    while(i<a->mxs)
        ar[k++]=a->data[i++];
    while(j<b->mxs)
        ar[k++]=b->data[j++];
    return ctitm(ar,mmxs);
}
item* optimalmerge(heap *hh)
{
    item *t1,*t2;int k=0;
    while(hh->cnt>1)
    {
        t1=del(hh);t2=del(hh);
        cout<<"Iteration "<<++k<<endl;
        ditem(t1);ditem(t2);
        cthp(merg(t1,t2),hh);
    }
    return del(hh);
}
int main()
{
     heap *hh=heapcrete();
     optimalmerge(hh);
    return 0;
}
