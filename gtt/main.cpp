#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int info;

	// False if left pointer points to predecessor
	// in Inorder Traversal
	bool lthread;

	// False if right pointer points to successor
	// in Inorder Traversal
	bool rthread;
};
// Insert a Node in Binary Threaded Tree
struct Node *insert(struct Node *root, int ikey)
{
	// Searching for a Node with given value
	Node *ptr = root;
	Node *par = NULL; // Parent of key to be inserted
	while (ptr != NULL)
	{
		// If key already exists, return
		if (ikey == (ptr->info))
		{
			printf("Duplicate Key !\n");
			return root;
		}

		par = ptr; // Update parent pointer

		// Moving on left subtree.
		if (ikey < ptr->info)
		{
			if (ptr -> lthread == false)
				ptr = ptr -> left;
			else
				break;
		}

		// Moving on right subtree.
		else
		{
			if (ptr->rthread == false)
				ptr = ptr -> right;
			else
				break;
		}
	}

	// Create a new node
	Node *tmp = new Node;
	tmp -> info = ikey;
	tmp -> lthread = true;
	tmp -> rthread = true;

	if (par == NULL)
	{
		root = tmp;
		tmp -> left = NULL;
		tmp -> right = NULL;
	}
	else if (ikey < (par -> info))
	{
		tmp -> left = par -> left;
		tmp -> right = par;
		par -> lthread = false;
		par -> left = tmp;
	}
	else
	{
		tmp -> left = par;
		tmp -> right = par -> right;
		par -> rthread = false;
		par -> right = tmp;
	}

	return root;
}

// Returns inorder successor using rthread
struct Node *inorderSuccessor(struct Node *ptr)
{
	// If rthread is set, we can quickly find
	if (ptr -> rthread == true)
		return ptr->right;

	// Else return leftmost child of right subtree
	ptr = ptr -> right;
	while (ptr -> lthread == false)
		ptr = ptr -> left;
	return ptr;
}

// Printing the threaded tree
void inorder(struct Node *root)
{
	if (root == NULL)
		printf("Tree is empty");

	// Reach leftmost node
	struct Node *ptr = root;
	while (ptr -> lthread == false)
		ptr = ptr -> left;

	// One by one print successors
	while (ptr != NULL)
	{
		//cout<<ptr->lthread<<" -> "<<ptr -> info<<" -> "<<ptr->rthread<<endl;
		cout<<ptr -> info<<' ';
		ptr = inorderSuccessor(ptr);
	}
	cout<<endl;
}
Node* is(Node *t)
{
    Node *temp=t;
    if(temp->rthread)
        return temp->right;
    else
    {
        temp=temp->right;
        while(temp->lthread==0)
        {
            temp=temp->left;
            //cout<<temp->info;
            //<<' '<<temp->lthread<<endl;
        }
        return temp;
    }
}
void iot(Node *t)
{
    Node *dr=new Node;
    dr->right=dr;
    dr->rthread=0;
    dr->lthread=0;
    dr->left=t;
    Node *temp=is(dr);
    while(1)
    {
        cout<<temp->info<<' ';
        if(temp->info==30)
            break;

        temp=is(temp);
    }

    cout<<endl;
}
Node* ps(Node * t)
{Node * temp=t;
    if(temp->lthread==0)
        return temp ->left;

    else
    {
        while(temp->rthread==1)
            temp=temp->right;
    }
    return temp->right;
}
void pot(Node *t)
{
    Node *dr=new Node;
    dr->right=dr;
    dr->rthread=0;
    dr->lthread=0;
    dr->left=t;
    Node *temp=ps(dr);
    while(1)
    {
        cout<<temp->info<<' ';
        if(temp->info==30)
            break;

        temp=ps(temp);
    }

    cout<<endl;
}
Node * ins(Node *root)
{
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);

}
int main()
{
    Node *root=NULL;
        root = ins(root);
        inorder(root);
        pot(root);

    return 0;
}
