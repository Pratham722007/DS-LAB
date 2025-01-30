#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void traversal(struct node *head)
{ struct node *ptr = (struct node *)malloc(sizeof(struct node));
ptr=head;
int a[9];
for (int i = 0; i <9; i++)
{
    a[i]=ptr;
    ptr->next;

}
ptr=head;

 int count=0;
while(ptr!=NULL)
{
   if(a[count])

}


};

int main(){
    //so i allocated my memory of linked list in heap
    struct node*head;
    head=( struct node*)malloc(sizeof( struct node));
     struct node*second;
    second=( struct node*)malloc(sizeof( struct node));
     struct node*third;
    third=( struct node*)malloc(sizeof( struct node));
struct node*fourth;
    fourth=( struct node*)malloc(sizeof( struct node));
    struct node*fifth;
    fifth=( struct node*)malloc(sizeof( struct node));
struct node*sixth;
    sixth=( struct node*)malloc(sizeof( struct node));
    struct node*seventh;
    seventh=( struct node*)malloc(sizeof( struct node));
    struct node*eighth;
    eighth=( struct node*)malloc(sizeof( struct node));
head->data=7;
head->next=second;
second->data=8;
second->next=third;
third->data=9;
third->next=fourth;
fourth->data=10;
fourth->next=fifth;
fifth->data=11;
fifth->next=sixth;
sixth->data=12;
sixth->next=seventh;
seventh->data=13;
seventh->next=eighth;
eighth->data=14;
eighth->next=head;
traversal(head);
return 0;
}