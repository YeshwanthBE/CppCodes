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
        Linkedlist *l=*Head;
        if(*Head==NULL)
            {
                (*Head)=(new Linkedlist(data));
                (*Head)->next=l;
            }
        else
            {
                for(;l->next!=NULL;l=l->next);
                l->next=new Linkedlist(data);
                l->next->next=NULL;
            }
    }
    //static void mid(Linkedlist *Head,int data,int data)
    static inline void strt(Linkedlist *h1,Linkedlist *h2)
    {
        Linkedlist *t1=h1;Linkedlist *t2=h2;
        for(;t1->next->next->next->next!=NULL;t1=t1->next);
        for(;t2->next!=NULL;t2=t2->next);
        t2->next=t1->next->next;

    }
    static void traverse(Linkedlist *Head)
    {
        for(Linkedlist *i=Head;i!=NULL;i=i->next)
            cout<<i->data<<" ";
            cout<<endl;
    }
    static void fidi(Linkedlist *h1,Linkedlist *h)
    {
        while(h1->next!=NULL)
            {for(Linkedlist *h2=h;h2->next!=NULL;h2=h2->next)
                if(h1==h2->next)
                {h2->next=NULL;return;}
                h1=h1->next;
            }
    }
};
int main()
{
   Linkedlist *h1,*h2;
   h1=h2=NULL;
   for(int i=5;i<9;i++)
   Linkedlist::create(&h1,i);
   Linkedlist::traverse(h1);
   for(int i=1;i<2;i++)
   Linkedlist::create(&h2,i);
   Linkedlist::traverse(h2);
   Linkedlist::strt(h1,h2);
   Linkedlist::traverse(h1);
   Linkedlist::traverse(h2);
   Linkedlist::fidi(h1,h2);
   cout<<endl<<endl;
   Linkedlist::traverse(h1);
   Linkedlist::traverse(h2);
    return 0;
}
