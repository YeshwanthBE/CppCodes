#include<iostream>
using namespace std;
class dll
{
    int data;
    dll *prev=NULL;
    dll *next=NULL;
    dll(int data)
    {
        this->data=data;
        this->prev=this->next=NULL;
    }
public:
    static void create(dll **Head,int data)
    {
        if(*Head==NULL)
           *Head=new dll(data);
        else
            {
                dll *temp=*Head;
                for(;temp->next!=NULL;temp=temp->next);
                temp->next=new dll(data);
                temp->next->prev=temp;
            }
    }
    static void traverse(dll *Head)
    {
        for(;Head->next!=NULL;Head=Head->next)
            cout<<Head->data<<"  ";
            cout<<Head->data;
        cout<<endl;
        for(;Head->prev!=NULL;Head=Head->prev)
            cout<<Head->data<<"  ";
            cout<<Head->data;
            cout<<endl;
    }
    static void del(dll **Head,int data)
    {
        if((*Head)->data==data)
        {
          (*Head)=(*Head)->next;
          free((*Head)->prev)  ;
          (*Head)->prev=NULL;
        }
        else
        {
            dll *t=*Head;
            for(;t->next->data!=data;t=t->next);
            t->next=t->next->next;
            free(t->next->prev);
            t->next->prev=t;
        }
    }
    static void ins(dll **Head,int data,int pos)
    {
        if(pos==1)
        {
            (*Head)->prev=new dll(data);
            (*Head)->prev->next=*Head;
            *Head=(*Head)->prev;
        }
        else
        {
            dll *t=*Head;
            for(int p=1;(p<pos-1)&&t==NULL;p++,t=t->next)
                if(t==NULL)
                return;
                dll *t2=t->next;
                t->next=new dll(data);
                t->next->prev=t;
                t->next->next=t2;
                t2->prev=t->next;


        }

    }
};
int main()
{
    dll *Head=NULL;
    for(int i=5;i>0;i--)
        dll::create(&Head,i);
    dll::traverse(Head);
    //dll::del(&Head,4);
    //dll::traverse(Head);
    dll::ins(&Head,9,6);
    dll::traverse(Head);
    return 0;
}
