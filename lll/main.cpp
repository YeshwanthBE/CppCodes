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
    static inline void ld(Linkedlist *Head,int data)
    {   Linkedlist *i=Head;
        for(;i->next!=NULL;i=i->next);
        i->next=new Linkedlist(data);
        i->next->next=Head->next->next;
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
        int k=10;
        for(Linkedlist *i=Head;i!=NULL;i=i->next)
            if(k--==0) break;else cout<<i->data<<" ";
            cout<<endl;
    }
    static void fl(Linkedlist *Head)
    {
        Linkedlist *i,*j;
        i=j=Head;
        while(i!=NULL&&j!=NULL)
        {
            i=i->next;
            j=j->next->next;
                    if(i==j)
                    {
                        if(i==Head)
                        cout<<"Snake Loop Found"<<endl;
                        else
                        cout<<"Snail Loop Found"<<endl;

                        break;
                    }
        }
    }
    static void lr(Linkedlist *Head)
    {
        Linkedlist *i,*j;
        i=j=Head;bool loop=false;
        while(i!=NULL&&j!=NULL)
        {
            i=i->next;
            j=j->next->next;
             if(i==j)
                {loop=true;break;}

        }
        if(loop)
        {
            i=Head;
            while(i!=j)
            {
                i=i->next;
                j=j->next;
            }
            cout<<"Loop Found at :"<<j->data<<endl;
        }
    }
};
int main()
{
   Linkedlist *Head=NULL;
   for(int i=0;i<7;i++)
   Linkedlist::create(&Head,i);
   Linkedlist::ld(Head,8);
   Linkedlist::traverse(Head);
   Linkedlist::fl(Head);
   Linkedlist::lr(Head);
    return 0;
}

