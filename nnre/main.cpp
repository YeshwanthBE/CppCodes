#include <iostream>
#include<cmath>
using namespace std;
struct ll
{
    int data;
    ll* next;
};
struct las
{
    ll *top;
    int siz=0;
}*h;
void push(las *h,int data)
{
     ll *temp=h->top;
        h->top=new ll();
        h->top->data=data;
        h->top->next=temp;
        h->siz++;
}
int pop(las *h)
{
            int a=h->top->data;
            ll *temp=h->top->next;
            free(h->top);
            h->top=temp;
            h->siz--;
            return a;
}
void nnre(int ar[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(ar[i]<ar[j])
                {ar[i]=ar[j];
                    break;}
}
void sr(int ar[],int n)
{
    int i=0;
    h=new las;
    int e,nn;
    push(h,ar[0]);
    for(i=0;i<n;i++)
    {///1740948824
        nn=ar[i];
        if(h->top!=0)
        {
            e=pop(h);
            while(e<nn)
            {
                cout<<"for element "<<e<<"near greatest="<<nn<<endl;;
                if(h->top==0)
                    break;
                e=pop(h);
            }
            if(e>nn)
                push(h,e);
        }
        push(h,nn);
    }
}
int main()
{
    int ar[50];
    for(int i=0;i<10;i++)
        ar[i]=rand()%10;
    for(int i=0;i<10;i++)
        cout<<ar[i]<<' ';
    cout<<endl;

    sr(ar,10);
    return 0;
}
