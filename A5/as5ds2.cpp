#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} CList;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(CList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(head)\n");
}

void insertPos(CList *list, int pos, int data) {
    Node *newNode = createNode(data);
    if (list->head == NULL) {
        if (pos == 1) {
            list->head = newNode;
            newNode->next = list->head;
        } else {
            printf("Invalid position.\n");
        }
        return;
    }
    if (pos == 1) {
        Node *temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == list->head) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeg(CList *list, int data) {
    insertPos(list, 1, data);
}

void insertEnd(CList *list, int data) {
    Node *newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
        return;
    }
    Node *temp = list->head;
    while (temp->next != list->head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = list->head;
}

void deletePos(CList *list, int pos) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        Node *temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        if (temp == list->head) {
            free(list->head);
            list->head = NULL;
            return;
        }
        temp->next = list->head->next;
        free(list->head);
        list->head = temp->next;
        return;
    }
    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == list->head) {
            printf("Invalid position.\n");
            return;
        }
    }
       Node *delNode = temp->next;
      if (delNode == list->head) {
        printf("Invalid position.\n");
        return;
    }
    temp->next = delNode->next;
    free(delNode);
}

void deleteFirst(CList *list) {
    deletePos(list, 1);
}

void deleteLast(CList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = list->head;
    while (temp->next->next != list->head) {
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = list->head;
    free(delNode);
}

int main() {
    CList list;
    list.head = NULL;
    int choice, data, pos;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert at a specific position\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from a specific position\n");
        printf("5. Delete the first element\n");
        printf("6. Delete the last element\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertPos(&list, pos, data);
                break;
            case 2:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                insertBeg(&list, data);
                break;
            case 3:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insertEnd(&list, data);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deletePos(&list, pos);
                break;
            case 5:
                deleteFirst(&list);
                break;
            case 6:
                deleteLast(&list);
                break;
            case 7:
                display(&list);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
