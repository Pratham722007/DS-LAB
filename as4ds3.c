#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
int hasCycle(struct Node*head)
{
    struct Node* slow=head;
    struct Node* fast=head;

    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct Node*head=createNode(10);
    head->next=createNode(20);
    head->next->next=createNode(30);
    head->next->next->next=createNode(40);
    printf("Loop detected : %d\n",hasCycle(head));
    head->next->next->next=head->next->next;
    printf("Loop detected : %d\n",hasCycle(head));

}