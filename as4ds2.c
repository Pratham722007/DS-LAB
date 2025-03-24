#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10; head->next = first;
    first->data = 10; first->next = second;
    second->data = 10; second->next = third;
    third->data = 40; third->next = fourth;
    fourth->data = 50; fourth->next = fifth;
    fifth->data = 60; fifth->next = sixth;
    sixth->data = 60; sixth->next = seventh;
    seventh->data = 30; seventh->next = NULL;

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
