#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void traversal(struct node *head,int s)
{ struct node *ptr = (struct node *)malloc(sizeof(struct node));
ptr=head;
for (int i = 0; i <s; i++)
{
   ptr=ptr->next;
}
for (int i = 0; i < 9; i++)
{
    printf("ELEMENT=%d\n",ptr->data);
    ptr=ptr->next;
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
int s;
printf("enter shift value");
scanf("%d",&s);
traversal(head,s);
return 0;
}