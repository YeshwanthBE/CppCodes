#include <iostream>
int z=1;
using namespace std;
struct sl{
    int data;
    sl *next[2];
};
void ins(sl **h,int data)
{
    sl *t=*h;
    if(t==NULL)
        {t=(sl*)malloc(sizeof(sl));
        t->data=data;
        t->next[0]=t->next[1]=NULL;
        *h=t;
        }
    else
    {
        if(t->next[1]!=NULL&&t->next[0]!=NULL){
        while(t->next[1]!=NULL&&t->next[1]->data<data)
            {
                t=t->next[1];
            }
        while(t->next[0]!=NULL&&t->next[0]->data<data)
            {

                t=t->next[0];
            }
        }
        sl *temp=(sl*)(malloc(sizeof(sl)));
        temp->data=data;
        temp->next[1]=NULL;
        if((*h)->data>data)
        {
            temp->next[0]=*h;
            *h=temp;
        }
        else
        {temp->next[0]=t->next[0];
        t->next[0]=temp;}

        sl *t2=*h;int k=1;
        for(sl *i=*h;i!=NULL;i=i->next[0],k++)
            if(k%3==0)
                {
                    sl *j=t2;
                    for(;j!=i;j=j->next[0])
                    j->next[1]=i;
                    t2=j;
                }
    }
}
void traverse(sl *h)
{
    while(h!=NULL)
    {
        cout<<h->data<<' ';
        h=h->next[0];
    }
}
int main()
{
    sl *Head=NULL;
    for(int i=700;i>3;i--)
    ins(&Head,i);
    ins(&Head,780);
    traverse(Head);
    return 0;
}
