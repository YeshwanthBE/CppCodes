#include <iostream>
using namespace std;
struct element
{
    char data;
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
int insrt(htable *h,char data)
{
    int key=hf(h,data);
    if(h->buckets[key]==NULL)
        {
            h->buckets[key]=new bucket;
            h->buckets[key]->e=new element;
            h->buckets[key]->e->data=data;
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
void sfrc(char *str)
{
    htable *h=create(27);
    int j=0;
    for(int i=0;str[i];i++)
        if(scrh(h,str[i]))
            {
                str[j++]=str[i];
                insrt(h,str[i]);
            }
    str[j]='\0';
}
int main()
{
    char str[10]="abababac";
    cout<<str<<endl;
    sfrc(str);
    cout<<str<<endl;
    return 0;
}
