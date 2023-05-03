#include <iostream>

using namespace std;
struct htable
{
    char *buckets;
    int capacity=0;
};
htable * cte(int capacity)
{
    htable *h=new htable;
    h->buckets=new char[capacity];
    h->capacity=capacity;
}
int hf(htable *h,int key)
{
    return key%h->capacity;
}
int ins(htable *h,char data)
{
    int key=hf(h,data);
    if(h->buckets[key]!=NULL)
        return -1;
    h->buckets[key]=data;
    return 0;
}
int srh(htable *h,char data)
{
    int key=hf(h,data);
    if(h->buckets[key]!=NULL)
        return 1;
    return 0;
}
void rm(char *a,char *b)
{
    htable *h=cte(256);char p[10];
    for(int i=0;b[i];i++)
        ins(h,b[i]);
    int j=0;
    for(int i=0;a[i];i++)
        if(!srh(h,a[i]))
            p[j++]=a[i];
        p[j]='\0';
    for(int i=0;p[i];i++)
        cout<<p[i];

}
char frc(char *a)
{
    htable *h=cte(256);
    for(int i=0;a[i];i++)
    {
        if(!srh(h,a[i]))
            ins(h,a[i]);
        else
            return a[i];
    }
}
int main()
{
    char a[8]="abzddab";
    cout<<frc(a);
    return 0;
}
