#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *stack, int data) {
    Node *new_node = createNode(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

void pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int peek(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void display(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = stack->top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack stack;
    stack.top = NULL;
    int choice, data;

    while (1) {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Top element: %d\n", peek(&stack));
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
