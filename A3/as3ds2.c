#include<stdio.h>

#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("ELEMENT = %d\n", ptr->data);
        ptr = ptr->next;
    }
};
struct node *insertbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node *));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node *));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node *));
    struct node *fourth;
    fourth = (struct node *)malloc(sizeof(struct node *));
    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = fourth;
    fourth->data = 10;
    fourth->next = NULL;
    traverse(head);
    printf("\n");
    head = insertbeg(head, 6);
    traverse(head);
    return 0;
}