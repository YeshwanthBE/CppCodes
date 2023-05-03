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

int cmpdu(int ar[],int br[],int n,int k)
{
    htable *h=create(n);
    for(int i=0;i<n;i++)
        insrt(h,ar[i]);
    for(int i=0;i<n;i++)
        if(!scrh(h,(k-br[i])))
            cout<<k-br[i]<<'+'<<br[i]<<'='<<k<<endl;
    cout<<scrh(h,6);
}
int main()
{
    int ar[5]={0,1,2,3,4};int br[5]={0,1,2,3,4};
    cmpdu(ar,br,5,7);
    return 0;
}
