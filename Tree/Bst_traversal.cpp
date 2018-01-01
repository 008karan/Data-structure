#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};


 Node* getnewnode(int data)  //get new node
{
    Node*temp=new Node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}
 Node* Insert(Node* root ,int data)// insert node at right place
{

    if (root==NULL)
    {
        root=getnewnode(data);
        return root;
    }
    if(data<=root->data)
    { root->left=Insert(root->left,data);

    }
    if(data>=root->data)
    { root->right=Insert(root->right,data);

    }
return root;

}
void preorder(Node* root)
{
    if(root== NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
void postorder(Node* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}
bool isBst(Node *node, int left, int right)
{
    if (node==NULL)
    {
        return true;
    }

    if (node->data < left || node->data > right)
    {
       return false;
    }
    return isBst(node->left, left, node->data)
               && isBst(node->right, node->data, right);
}
Node* Findmin(Node*root)
{
    Node*t=root;
    while(t->left!=NULL)
    {
        t=t->left;
    }
    return t;

}
 Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct Node *temp = Findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int main(){

  Node* root = NULL;
	root=Insert(root,10);
	root=Insert(root,8);
	root=Insert(root,9);
	root=Insert(root,30);
	root=Insert(root,1);
	root=Insert(root,11);
	root=Insert(root,22);

	 printf("preorder ");
   preorder(root);
   printf("\n");
   printf("inorder ");
   inorder(root);
   printf("\n");
   printf("postorder ");
   postorder(root);
   printf("\n");
   char k=isBst(root,-100,100) ;
   if (k==true)
    {
        printf("The given tree is BST\n");

    }
    else printf("Not BST");
    root=Delete(root,9);
    printf("after deletion inorder ");
    inorder(root);
    printf("\n");

}


