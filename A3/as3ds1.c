#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void traversal(struct node *ptr)
{   while (ptr!=NULL)
{
     printf("ELEMENT = %d\n",ptr->data);
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

head->data=7;
head->next=second;
second->data=8;
second->next=third;
third->data=9;
third->next=NULL;
traversal(head);
return 0;
}