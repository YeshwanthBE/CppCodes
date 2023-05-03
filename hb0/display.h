#include<queue>
#define q.front();q.pop()
void display(tree *t=root,int levelflag=0,int leftrightflag=0)
{
    queue<tree *>q;
    q.push(t);if(levelflag) q.push(NULL);
    tree *temp;
    while(!q.empty())
    {
        temp=dq();
        if(temp)
        {
            if(temp->left&&leftrightflag)
                cout<<temp->left->data<<"<- ";
            cout<<temp->data<<' ';
            if(temp->right&&leftrightflag)
                cout<<"->"<<temp->right->data<<endl;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
        else if(levelflag)
        {
            if(!q.empty())
                q.push(NULL);
            cout<<endl;
        }
    }
    cout<<endl;
}
