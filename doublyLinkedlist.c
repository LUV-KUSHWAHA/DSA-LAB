// DOUBLY LINKED LIST
#include <stdlib.h> 
#include <stdio.h>
typedef struct node
{
    int info;
    struct node* prev;
    struct node* next;
} Node; 

Node* head = NULL;

void insAtBeg(int data)
{
    Node* newnode = (Node*) malloc(sizeof(Node)); 
    newnode->prev = NULL;
    newnode->info = data;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}

void delFrBeg()
{
    if (head == NULL)
    {
        printf("\nVoid deletion...");
        return;
    }

    Node* ptr = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(ptr);
}

void insAtEnd(int data)
{
    Node* newnode = (Node*) malloc(sizeof(Node)); 
    newnode->info = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;
}

void delFrEnd()
{
    if (head == NULL)
    {
        printf("\nVoid deletion...");
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL)
    {
        ptr->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    free(ptr);
}

void insAtK(int data, int k)
{
    if (k <= 0 || head == NULL)
    {
        printf("\nInvalid position...");
        return;
    }

    Node* newnode = (Node*) malloc(sizeof(Node)); 
    newnode->info = data;

    Node* ptr = head;
    for (int i = 1; i < k-1 && ptr->next != NULL; i++)
    {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    newnode->prev = ptr;

    if (ptr->next != NULL)
    {
        ptr->next->prev = newnode;
    }

    ptr->next = newnode;
}

void delFrK(int k)
{
    if (k <= 0 || head == NULL)
    {
        printf("\nInvalid position...");
        return;
    }

    Node* ptr = head;
    for (int i = 1; i < k && ptr->next != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }

    if (ptr->prev != NULL)
    {
        ptr->prev->next = ptr->next;
    }
    else
    {
        head = ptr->next;
    }

    free(ptr);
}

void display()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void update(int data, int k)
{
    if (k <= 0 || head == NULL)
    {
        printf("\nInvalid position...");
        return;
    }

    Node* ptr = head;
    for (int i = 1; i < k; i++)
    {
        if (ptr == NULL)
        {
            printf("\nPosition not found...");
            return;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("\nPosition not found...");
        return;
    }

    ptr->info = data;
}


int main()
{
    insAtBeg(4);
    // display();
    insAtBeg(5);
    display();
    // insAtBeg(6);
    // display();
    insAtEnd(6);
    // display();
    insAtEnd(7);
    display();
    insAtK(8, 3);
    display();
    insAtK(11, 5);
    display();

    update(20,4);
    display();

    delFrBeg();
    display();
    delFrEnd();
    display();
    delFrK(3);
    display();
    return 0;
}
