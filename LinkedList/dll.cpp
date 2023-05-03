#include<iostream>
using namespace std;
class dll
{
    int data;
    dll *prev=NULL;
    dll *next=NULL;
    dll(int data)
    {
        this.data=data;
        this.prev=this.next=NULL;
    }
public:
    static void create(dll **Head,int data)
    {
        if(*Head==NULL)
            *Head=new dll(data);
        else
            {
                dll *temp=*head;
                for(;temp->next!=NULL;temp=temp->next);
                temp->next=new dll(data);
                temp->next->prev=temp;
            }
    }
    static void traverse(dll *Head)
    {
        for(;Head==NULL;Head=Head->next)
            cout<<Head<<" ";
    }
};
void main()
{
    dll *Head=NULL;
    for(int i=5;i>=0;i--)
        dll::create(&Head,i);

}
