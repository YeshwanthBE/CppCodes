#include <iostream>
using namespace std;
struct element
{
    int data;
    int bkey;
};
struct chain
{
    element* e;
    chain *next=NULL;
};
struct htable
{
    int siz=0;
    int capacity;
    chain **buckets=NULL;
};
int hf(htable *h,int element)
{
    return element%h->capacity;
}
htable* create(int capacity)
{
    htable *h=new htable;
    h->buckets=(chain **)calloc(capacity,sizeof(chain));
    h->capacity=capacity;
    return h;
}
int insrt(htable *h,int data)
{
    int key=hf(h,data);
    chain *t=h->buckets[key];
    if(t==NULL)
        {
            t=new chain;
            t->e=new element;
            t->e->data=data;
            t->e->bkey=0;
        }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->next=new chain;
        t->next->e=new element;
        t->next->e->data=data;
        t->next->e->bkey++;
    }
    h->buckets[key]=t;
}
int getd(htable *h,int ekey,int bkey)
{
    int key=hf(h,ekey);
    if(h->buckets[key]==NULL)
        return -1;
    chain *t=h->buckets[key];
    while(t)
    {if(t->e->bkey==bkey){cout<<t->e->data;return 0;}t=t->next;}
    return -1;
}
int del(htable *h,int ekey,int bkey)
{
    int key=hf(h,ekey);
    if(h->buckets[key]==NULL)
        return -1;
    chain *t=h->buckets[key];
    chain *temp;
    if(t->e->bkey==bkey)
    {
        temp=t->next;
        delete(t);
        h->buckets[key]=temp;
        return 0;
    }

    while(t->next)
    {
        if(t->next->e->bkey==bkey)
            {
                temp=t->next;
                t->next=temp->next;
                delete(temp);
                return 0;
            }
            t=t->next;
    }
    return -1;
}
int main()
{
    htable *h=create(10);
    insrt(h,10);insrt(h,10);
    getd(h,10,1);
    del(h,10,0);
    getd(h,10,1);
    del(h,10,1);
    return 0;
}
