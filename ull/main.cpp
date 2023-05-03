#include <iostream>

using namespace std;
struct node{
    node *nxt;
    int cur= 0;
    int ar[3];
};
node* Head=NULL;
node * create()
{
    node *t=(node *)(malloc(sizeof(node)));
    t->cur=0;
    return t;
}
void trav(node *h){
    while(h!=NULL)
    {
        for (int i=0;i<h->cur;i++)
        {
            cout<<h->ar[i]<<' ';
        }
        cout<<'\n';
        h=h->nxt;
    }
    cout<<endl;
}
void ins(node **h,int data)
{
    if(*h==NULL)
    {
        *h=create();
        (*h)->ar[0]=data;
        (*h)->nxt=NULL;
        (*h)->cur++;
    }
    else
    {
        node *t=*h;
        while(t->cur==3&&t->nxt!=NULL)
           t=t->nxt;
        if(t->nxt==NULL&&t->cur==3)
        {
            t->nxt=create();
            t=t->nxt;
            t->nxt=NULL;
        }

          t->ar[t->cur]=data;
          t->cur++;
    }

}
void del(node **hd,int data){
    node *h,*j;
    h=j=*hd;
    while(h!=NULL)
    {
        for(int i=0;i<h->cur;i++)
            if(h->ar[i]==data)
               {while(i++<h->cur-1)
                h->ar[i-1]=h->ar[i];
                h->ar[i-1]=0;
                h->cur--;
                }
    h=h->nxt;
    }
    if(j->cur==0)
    {
        *hd=(*hd)->nxt;
        free(j);
        j=*hd;
    }
    while(j->nxt!=NULL)
    {
        if(j->nxt->cur==0)
        {node *t=j->nxt;
        j->nxt=t->nxt;
        free(t);
        break;
        }
        j=j->nxt;
    }
    if(j->nxt==NULL&&j->cur==0)
    {
     node *t=*hd;
    while(t->nxt==j)
        t=t->nxt;
        free(j);
    t->nxt=NULL;
    }
}
int main()
{
    for(int i=0;i<10;i++)
    ins(&Head,i);
    trav(Head);
    for(int i=1;i<10;i++)
    {del(&Head,i);
    trav(Head);
    }
    trav(Head);
    return 0;
}
