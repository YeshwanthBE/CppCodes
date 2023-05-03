#include <iostream>
using namespace std;
struct element
{
    int data;
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
int insrt(htable *h,int key,int value)
{
    int rkey=hf(h,key);
    if(h->buckets[rkey]==NULL)
        {
            h->buckets[rkey]=new bucket;
            h->buckets[rkey]->e=new element;
            h->buckets[rkey]->e->data=value;
            return 0;
        }
    return -1;
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
    h->buckets[rkey]=NULL;
    delete(t);
    return 0;

}
int cmpdu(int ar[],int n)
{
    htable *h=create(n);
    for(int i=1;i<n;i+=2)
    {
        if(scrh(h,ar[i])==0)
            cout<<ar[i]<<' '<<ar[i-1]<<' '<<ar[i-1]<<' '<<ar[i]<<endl;
        insrt(h,ar[i-1],ar[i]);
    }
}
int main()
{
    int ar[8]={1,2,2,1,4,3,3,4};
    cmpdu(ar,8);
    return 0;
}
