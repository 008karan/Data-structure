#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
void Insert(int data,int n)
{
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if (head==NULL){
        head=temp;
        return;
    }
    if (n==1){                    //INSERT AT BEGINING
     head->prev=temp;
     temp->next=head;
     head=temp;
     return;
    }
    Node*temp2=head;
    for(int i=1;i<n;i++)         // INSERT AT NTH POSITION
    {
        temp2=temp2->next;
    }
    temp->prev=temp2->prev;
    temp2->prev->next=temp;
    temp2->prev=temp->next;
    temp->next=temp2;
}
void Print()                              // PRINT THE LIST
{
    printf("list is:\n");
    Node*temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
    }
void Delete(int n)
{ Node*p=head;
  if (n==1)                                //IF FIRST NODE TO DELETE
     {
         head =p->next;
         head->prev=NULL;
         delete p;                         // FREE MEMORY OF DELETED NODE
         return;
     }
  for(int i=1;i<n;i++)
  {
      p=p->next;
  }
  p->prev->next=p->next;
  p->next->prev=p->prev;
  delete p;
}

int main()
{
Insert(3,1);
Print();
Insert(4,1);
Insert(2,1);
Print();
Insert(1,3);
Print();
Delete(3);
Print();
return 0;
}
