#include <iostream>
using namespace std;
struct element
{
    int data;
    int cnt=1;
};
struct bucket
{
    element* e;
    bucket *next=NULL;
};
struct htable
{
    int siz=0;
    int capacity;
    bucket **buckets=NULL;
};
int hf(htable *h,int key)
{
    return key%h->capacity;
}
htable* create(int capacity)
{
    htable *h=new htable;
    h->buckets=(bucket **)calloc(capacity,sizeof(bucket));
    h->capacity=capacity;
    return h;
}
int insrt(htable *h,int data)
{
    int key=hf(h,data);
    if(h->buckets[key]==NULL)
        {
            h->buckets[key]=new bucket;
            h->buckets[key]->e=new element;
            h->buckets[key]->e->data=data;
            return 1;
        }
    else
    {
        h->buckets[key]->e->cnt++;
    }
    return h->buckets[key]->e->cnt;
}
int scrh(htable *h,int key)
{
    int rkey=hf(h,key);
    if(h->buckets[rkey]==NULL)
        return -1;
    return 0;
}
int del(htable *h,int key)
{
    int rkey=hf(h,key);
    if(h->buckets[rkey]==NULL)
        return -1;
    bucket *t=h->buckets[rkey];
    if(t->e->cnt-1)
    {t->e->cnt--;return 0;}
    h->buckets[rkey]=NULL;
    delete(t);
    return 0;

}
int cmpdu(int ar[],int n)
{
    htable *h=create(n);
    int mx=0;int note=0;
    for(int i=0;i<n;i++)
    {
        int t=insrt(h,ar[i]);
        if(mx<t)
        {mx=t;note=i;}
    }
    cout<<ar[note]<<' '<<mx;
}
int main()
{
    int ar[101];
    for(int i=0;i<50;i++)
        ar[i]=i;
    for(int i=51,j=50;i<98;i+=2,j++)
        ar[i-1]=ar[i]=j;
    ar[98]=ar[99]=ar[100]=74;
    cmpdu(ar,101);
    return 0;
}
