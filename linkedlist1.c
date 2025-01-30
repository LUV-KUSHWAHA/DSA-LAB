#include <stdio.h>
#include <stdlib.h>

int data;
void insertAtB();
void insertAtE();
void insertAtK();
void display();
void deleteAtB();
void deleteAtE();
void deleteAtK();

struct node 
{
    int info;
    struct node* next;
} *ptr, *head = NULL, *newnode, *temp;

int main() {
    int ch;
    while (1) {
        printf("\nWhat do you want to do?");
        printf("\n1. insertion 2. display 3. deletion\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nWhere do you want to insert? 1. beginning, 2. end, or 3. mid\n");
                int ch1;
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1:
                        insertAtB();
                        break;
                    case 2:
                        insertAtE();
                        break;
                    case 3:
                        insertAtK();
                        break;
                    default:
                        printf("\nWrong choice..");
                }
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nWhere do you want to delete? 1. beginning, 2. end, or 3. mid\n");
                int ch2;
                scanf("%d", &ch2);
                switch (ch2) {
                    case 1:
                        deleteAtB();
                        break;
                    case 2:
                        deleteAtE();
                        break;
                    case 3:
                        deleteAtK();
                        break;
                    default:
                        printf("\nWrong choice..");
                }
                break;
            default:
                printf("\nWrong choice...");
        }
    }
    return 0;
}

void insertAtB() {
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &data);
    newnode->info = data;
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertAtE() {
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void insertAtK() {
    int k;
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("\nAt what position do you want to enter? ");
    scanf("%d", &k);
    printf("\nEnter data: ");
    scanf("%d", &data);
    newnode->info = data;
    if (head == NULL || k == 0) {
        insertAtB(); // If list is empty or k is 0, insert at beginning
    } else {
        ptr = head;
        for (int i = 0; i < k - 1 && ptr->next != NULL; i++) {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}

void display() {
    ptr = head;
    if (head == NULL) {
        printf("\nList is empty..");
    } else {
        while (ptr != NULL) {
            printf("\n%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}

void deleteAtB() {
    if (head == NULL) {
        printf("\nNo node to delete...");
    } else {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void deleteAtE() {
    if (head == NULL) {
        printf("\nNo node to delete...");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        ptr = head;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}

void deleteAtK() {
    int k;
    printf("\nAt what position do you want to delete? ");
    scanf("%d", &k);
    if (head == NULL) {
        printf("\nNo node to delete...");
    } else if (k == 0) {
        deleteAtB();
    } else {
        ptr = head;
        for (int i = 0; i < k - 1 && ptr->next != NULL; i++) {
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == NULL) {
            printf("\nPosition out of bounds...");
        } else {
            temp->next = ptr->next;
            free(ptr);
        }
    }
