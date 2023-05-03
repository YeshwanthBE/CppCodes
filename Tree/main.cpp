#include <iostream>
#include <queue>
using namespace std;
struct t;
queue<t*>q;
struct t
{
    t *left=NULL;
    t *right=NULL;
    int data;
}*r;
t* dq()
{
    t *t1=q.front();
    q.pop();
    return t1;
}
void ct(int d)
{
    t *temp;
    if(!r)
        {r=new t;r->data=d;return;}
    q.push(r);
    while(1)
    {
        temp=dq();
        if(temp->left)
            q.push(temp->left);
        else
            {
            temp->left=new t;
            temp->left->data=d;
            break;
            }
        if(temp->right)
            q.push(temp->right);
        else
            {
            temp->right=new t;
            temp->right->data=d;
            break;
            }
    }
    for(;!q.empty();q.pop());
}
void disp2(t *t1)
{
    if(t1)
    {
        cout<<t1->data<<' ';
        disp2(t1->left);
        disp2(t1->right);
    }

}
void disp()
{
    q.push(r);t *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
            cout<<temp->data<<' ';
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);


    }
}
void disp3(t *r)
{
   if(!r)
    return
   disp3(r->left);
   cout<<r->data<<' ';
   disp3(r->right);
   return;
}
int main()
{
    for(int i=1;i<8;i++)
        ct(i);
    disp();
    cout<<endl;
    disp3(r);
    return 0;
}
