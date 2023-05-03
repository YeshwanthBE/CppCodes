#include <iostream>
using namespace std;
struct tree
{
    int data;
    tree *left=NULL,*right=NULL;
    bool lt=0,rt=0;
}*dr=NULL,*r=NULL;
void it()
{
    dr->right=dr;
    dr->rt=1;
}
void ct(int data)
{
    if(!r)
    {
        r=new tree;
        r->data=data;
        r->right=dr;
        dr->lt=1;
        dr->left=r;
        return;
    }
    tree *temp=r;
    while(temp->lt&&temp->rt)
    {

    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
