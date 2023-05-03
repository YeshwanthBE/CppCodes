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
            {
                Linkedlist *l=*Head;
                (*Head)=(new Linkedlist(data));
                (*Head)->next=l;
            }
        else
            {
                    Linkedlist *i=*Head;
                    for(;i->next!=NULL;i=i->next);
                    i->next=new Linkedlist(data);
                    i->next->next=NULL;
            }
    }
    static void traverse(Linkedlist *Head)
    {
        for(Linkedlist *i=Head;i!=NULL;i=i->next)
            cout<<i->data<<" ";
            cout<<endl;
    }
    static void rll(Linkedlist **Head)
    {
        Linkedlist *c,*n,*p;
        p=NULL;
        c=*Head;
        while(c!=NULL)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        *Head=p;

    }
    static


};
int main()
{
   Linkedlist *Head=NULL;
   for(int i=0;i<5;i++)
   Linkedlist::create(&Head,i);
   Linkedlist::traverse(Head);
   Linkedlist::rll(&Head);
   Linkedlist::traverse(Head);
    return 0;
}
