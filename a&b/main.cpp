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
            return 0;
        }
    else
    {
        h->buckets[key]->e->cnt++;
    }
    return 0;
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
int cmpdu(int ar[],int br[],int n)
{
    htable *h=create(n);
    for(int i=0;i<n;i++)
        insrt(h,ar[i]);
    for(int i=0;i<n;i++)
        if(!scrh(h,br[i]))
            del(h,br[i]);
        else
            return -1;
    return 0;
}
int main()
{
    int ar[5]={1,2,3,4,4};int br[5]={3,4,4,2,1};
    cout<<cmpdu(ar,br,5);
    return 0;
}
