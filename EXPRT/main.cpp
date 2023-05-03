#include <iostream>
#include <stack>
#define pp() s.top();s.pop()
#include <cctype>
using namespace std;
struct tree
{
    char data;
    tree *left=NULL,*right=NULL;
}*r=NULL;
int isop(char a)
{
    switch(a)
    {
    case '+':
    case '*':
    case '-':
    case '/':return 1;
    default :return 0;
    }
}
tree * ptet(char pe[])
{
    stack<tree *>s;
    tree *temp,*temp1,*temp2;
    for(int i=0;pe[i]!='\0';i++)
    {
        if(isop(pe[i]))
        {
            temp1=pp();
            temp2=pp();
            temp=new tree;
            temp->left=temp2;
            temp->right=temp1;
            temp->data=pe[i];
            s.push(temp);

        }
        else
            {
            temp=new tree;
            temp->data=pe[i];
            s.push(temp);
        }
    }
    return s.top();
}
void disp(tree *t=r)
{
    if(!t)
        return;
    cout<<t->data<<' ';
    disp(t->left);
    disp(t->right);
}
int main()
{
    r=ptet("abc*+d/");
    disp();
    return 0;
}
