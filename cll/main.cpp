#include <iostream>
using namespace std;
struct cll{
int data;
cll *next;
};
void traverse(cll *Head);
void create(cll **Head,int data)
{
    if(*Head==NULL)
        {*Head=(cll*)malloc(sizeof(cll));
        (*Head)->data=data; (*Head)->next=*Head;}
    else
        {
            cll *cur=(*Head);
            do{
                cur=cur->next;
            }while(cur->next!=(*Head));
            cur->next=(cll*)malloc(sizeof(cll));
            cur->next->data=data;
            cur->next->next=*Head;
        }
}
void traverse(cll *Head)
{
    cll *cur=Head;
    do
    {cout<<cur->data<<" ";;cur=cur->next;}while(cur!=Head);
    cout<<'\n';
}
void del(cll **Head,int data)
{
    if((*Head)->data==data)
    {
        cll *cur=*Head;
        do{
            cur=cur->next;
        }while(cur->next!=*Head);
        cur->next=(*Head)->next;
        free(*Head);
        *Head=cur->next;
    }
    else
    {
        cll *cur=*Head;
        do{
            cur=cur->next;
        }while(cur->next->data!=data);
        cll *t=cur->next;
        cur->next=t->next;
        free(t);

    }
traverse(*Head);
}
void ins(cll **Head,int data,int pd){
    if((*Head)->data==pd)
    {
        cll *t=(cll *)malloc(sizeof(cll));
        t->data=data;
        t->next=*Head;
        cll *i=*Head;
        for(;i->next!=(*Head);i=i->next);
        i->next=t;
        *Head=t;
    }
    else{
    cll *cur=(*Head)->next;
    for(;(cur!=(*Head))&&(cur->data!=pd);cur=cur->next);
    cll *t=(cll *)malloc(sizeof(cll));
    t->data=data;
        t->next=cur->next;
        cur->next=t;

    }
    traverse(*Head);
}
int main()
{
    cll *Head=NULL;
    for(int i=10;i<30;i+=4)
    create(&Head,i);
    traverse(Head);
    del(&Head,10);
    del(&Head,18);
    del(&Head,26);
    ins(&Head,1,22);
    ins(&Head,2,22);
    ins(&Head,10,14);
    ins(&Head,1,10);
    return 0;
}
