#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node*head;

void Insert(int data,int n) //INSERT AT BEGINING
{ Node* temp=new Node();
  temp->data=data;
  temp->next=NULL;
  if (n==1){
    temp->next=head;
    head=temp;
    return;
    }
    Node* t=head;
    for(int i=1;i<n-1;i++)
    {
        t=t->next;

    }
   temp->next=t->next;
   t->next=temp;

}
void Print()
{   printf("list is:\n");
    Node*temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}
 void Append(int data)    // INSERT AT TAIL
 {
     Node* temp=new Node();
     temp->data=data;
     temp->next=NULL;
     Node* temp2= head;
     while(temp2->next!=NULL)
     temp2=temp2->next;
     temp2->next=temp;


 }
 void Delete(int n)// DELETE NTH NODE
 { Node *temp=head;
   Node * prev;
     if (n==1)//IF FIRST NODE TO DELETE
     {
         head =temp->next;
         delete temp;// FREE MEMORY OF DELETED NODE
         return;
     }
    for (int i =1;i<n-1;i++) // GOTO (N-1)th NODE
     {
        temp=temp->next;
    }
    prev=temp;
    temp=temp->next;
    prev->next=temp->next;
    delete temp;// FREE MEMORY OF DELETED NODE
 }

void Reverse()// REVERSE THE LINKED LIST
{Node*prev,*current,*next;
 prev=NULL;
 current=head;
 while(current!=NULL)
 {
     next=current->next;
     current->next=prev;
     prev=current;
     current=next;
 }
    head=prev;
}
void recursion_print(struct Node*p)//REVERSE PRINT USING RECURSION
{

    if (p==NULL)
        return;

    recursion_print(p->next);
     printf("%d ",p->data);

}
void recursion_reverse(struct Node*p)//REVERSE THE LINKED LIST USING RECURSION
{
    if (p->next==NULL)
    {
          head=p;
          return ;
    }
    recursion_reverse(p->next);

    p->next->next=p;
    p->next=NULL;

}
int main()
{head=NULL;
Insert(1,1);
Print();
Insert(2,1);
Print();
Insert(3,2);
Print();
Insert(4,3);
Print();
Insert(5,1);
Print();
Insert(6,4);
Print();
Append(10);
Print();
Delete(3);
Print();
Reverse();
Print();
recursion_print(head);
recursion_reverse(head);
Print();
return 0;
}

