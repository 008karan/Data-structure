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
void Findmin(Node*root)
{
    Node*t=root;
    while(t->left!=NULL)
    {
        t=t->left;
    }
    printf("minimum in binary tree is %d\n",t->data);
}
void Findmax(Node*root)
{
    Node*t=root;
    while(t->right!=NULL)
    {
        t=t->right;
    }
    printf("maximum in binary tree is %d\n",t->data);
}
bool  Search(Node*root,int key)// search the key in binary tree
{if(root==NULL) return false;
if (root->data==key) return true;
if (key<=root->data) return Search(root->left,key);
else return Search(root->right,key);

}
int Findhight(Node*root)// find hight of binary search tree
{
    if (root==NULL)
    {
        return -1;
    }
return std::max(Findhight(root->left),Findhight(root->right))+1;
}



int main(){
    Node* root = NULL;
	root=Insert(root,10);
	root=Insert(root,8);
	root=Insert(root,9);
	root=Insert(root,3);
	root=Insert(root,1);
	root=Insert(root,11);
	root=Insert(root,6);
	int key=3,h;
	printf("enter the key:\n");
	scanf("%d",&key);
	if(Search(root,key)==true) printf("%d is found in tree\n",key);
	else printf("%d is not found\n",key);
	Findmin(root);
	Findmax(root);
	h=Findhight(root);
	printf("Hight of binary tree is %d\n",h);
}


