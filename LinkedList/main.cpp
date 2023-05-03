#include <iostream>
using namespace std;
class Linkedlist
{
    int data;
    Linkedlist *next=NULL;
    Linkedlist(int dat)
    {
        data=dat;
    }
   public:
        static void create(Linkedlist **Head,int data)
    {
        if(*Head==NULL)
            strt(Head,data);
        else
            endd(*Head,data);
    }
    //static void mid(Linkedlist *Head,int data,int data)
    static inline void strt(Linkedlist **Head,int data)
    {
        Linkedlist *l=*Head;
        (*Head)=(new Linkedlist(data));
        (*Head)->next=l;
    }
    static inline void endd(Linkedlist *Head,int data)
    {   Linkedlist *i=Head;
        for(;i->next!=NULL;i=i->next);
        i->next=new Linkedlist(data);
        i->next->next=NULL;
    }
    static inline void mid(Linkedlist *Head,int data,int pos)
    {
        for(;--pos>0;Head=Head->next);
        Linkedlist *l=Head->next;
        Head->next=(new Linkedlist(data));
        Head->next->next=l;
    }
    static void traverse(Linkedlist *Head)
    {
        for(Linkedlist *i=Head;i!=NULL;i=i->next)
            cout<<i->data<<" ";
            cout<<endl;
    }
    static void  del(Linkedlist **Head,int data)
    {
        Linkedlist *i=*Head;
       Linkedlist *t=nullptr;
           if((*Head)->data==data)
           {
               t=*Head;
               *Head=(*Head)->next;
               free(t);
               return;
           }
           while(i->next!=NULL){
            if(i->next->data==data)
                {t=i->next;
               i->next=i->next->next;
               free(t);
                break;}
                i=i->next;
           }

    }
};
int main()
{
   Linkedlist *Head=NULL;
   for(int i=0;i<5;i++)
   Linkedlist::create(&Head,i);
   Linkedlist::mid(Head,30,3);
   Linkedlist::traverse(Head);
   Linkedlist::del(&Head,0);
   Linkedlist::traverse(Head);
    return 0;
}
