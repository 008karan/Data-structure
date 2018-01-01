#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
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
Node* Findmin(Node*root)
{

    while(root->left!=NULL)
    {
        root=root->left;
    }
   return root;
}
Node* Findmax(Node*root)
{

    while(root->right!=NULL)

    {
        root=root->right;
    }

   return root;
}
Node* Search(Node*root,int key)// search the key in binary tree
{if(root==NULL) return root;
if (root->data==key) return root;
if (key<=root->data) return Search(root->left,key);
else return Search(root->right,key);

}



void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 struct Node* Getsuccessor(struct Node* root,int data) {
	// Search the Node - O(h)
	struct Node* current = Search(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  // the minimum value in right subtree is predecessor
		return Findmin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
 Node* Getpredecessor(struct Node* root,int data)
  {
	// Search the Node - O(h)
	struct Node* current = Search(root,data);
	if(current == NULL) return NULL;

	if(current->left != NULL)
        {  // the maximum value in left subtree is predecessor
		return Findmax(current->left); // O(h)
	}
else {   //parent node will be predecessor
		struct Node* predecessor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data > ancestor->data) {
				predecessor = ancestor; //
				ancestor = ancestor->right;
			}
			else
				ancestor = ancestor->left;
		}
		return predecessor;
	}



}

int main(){
    Node* root = NULL;
	root=Insert(root,10);
	root=Insert(root,8);
	root=Insert(root,12);
	root=Insert(root,3);
	root=Insert(root,1);
	root=Insert(root,15);
	root=Insert(root,6);
	Node*a;
	int key;
	Inorder(root);
	printf("\n");
	printf("enter key:");
	scanf("%d",&key);
	a=Getsuccessor(root,key);
	printf("successor of %d is %d\n",key,a->data);

	a=Getpredecessor(root,key);
	printf("predecessor of %d is %d\n",key,a->data);



}
