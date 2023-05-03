#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int item_no=-1;
    float weight=0;
    float profit=0;
    float pbw=0;
    item *nxt=NULL;
};
item* ctitm(float p,float w,int ino)
{
        item *i=new item;
        i->weight=w;
        i->profit=p;
        i->pbw=p/w;
        i->item_no=ino;
        return i;
}
item* iapnd(item *head,float p,float w)
{
    if(!head)
        head=ctitm(p,w,1);
    else
    {
        while(head->nxt)
            head=head->nxt;
    head->nxt=ctitm(p,w,head->item_no+1);
    }
    return head;
}
void ditem(item *a)
{
    cout<<a->weight<<' '<<a->profit;
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
    while(i>0&&(h->data[i]->pbw>h->data[(i-1)/2]->pbw))
    {
        swp(&h->data[i],&h->data[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pldw(heap *h)
{
    int i=0,j=i*2+1;
    while(j<h->cnt&&(h->data[i]->pbw<h->data[j]->pbw||h->data[j]->pbw<h->data[j+1]->pbw))
    {
        j=h->data[j]->pbw>h->data[j+1]->pbw?j:j+1;
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
    h->cnt--;
    pldw(h);
    return temp;
}
item * itemcrete()
{
    item*i=iapnd(NULL,10,2);
    iapnd(i,5,3);iapnd(i,15,5);iapnd(i,7,7);
    iapnd(i,6,1);iapnd(i,18,4);iapnd(i,3,1);
    return i;
}
heap *heapcrete(item *ih)
{
    heap *hh=NULL;
    while(ih)
    {
        hh=cthp(ih,hh);
        ih=ih->nxt;
    }
    return hh;
}
void hdisp(heap *hh)
{
   cout<<"itemno pbw  profit  weight\n";
    while(hh->cnt)
    {
        item *t=del(hh);
        cout<<t->item_no<<'\t'<<t->pbw<<'\t'<<t->profit<<'\t'<<t->weight<<endl;
    }

}
void kpdisp(item *i)
{
    cout<<i->item_no<<'\t'<<i->pbw<<'\t'<<i->profit<<'\t'<<i->weight<<endl;
}
int kp(heap *hh,int capacity)
{
    item *ar[10]={NULL};int k=0;
    while(capacity>0)
    {
        item *t=del(hh);
        if(capacity-t->weight>=0)
            {ar[k++]=t;capacity-=t->weight;}
        else
            {
                float wbc=t->weight/capacity;
                item *t2=ctitm(t->profit/wbc,t->weight/wbc,t->item_no);
                ar[k++]=t2;
                capacity-=wbc;
            }
    }
    cout<<"itemno pbw  profit  weight\n";
    float mxp=0,tw=0;
    for(int i=0;ar[i];i++)
        {
            kpdisp(ar[i]);
            mxp+=ar[i]->pbw*ar[i]->weight;
            tw+=ar[i]->weight;
        }
    cout<<endl<<"maxmimum profit="<<mxp<<"\ntotal weight="<<tw<<endl;
}
int main()
{
     item *ih=itemcrete();
     heap *hh=heapcrete(ih);
     kp(hh,15);
    return 0;
}
