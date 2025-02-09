// Queue implementation
#include <stdio.h>
#define size 4

int data, arr[size], front = -1, rear = -1;

void enqueue(int data);
void dequeue();
void DisplayAll();
void isFull();
void isEmpty();

int main()
{
    int n;
    printf("\nQueue Data Structure\n");
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.DisplayAll");
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                isFull();               
            break;

            case 2:
                isEmpty();
            break;

            case 3:
                DisplayAll();
                break;

            default:
            printf("\nWrong choice !!!!");
        }
    }
    return 0;
}

void enqueue(int data)
{
    if(front == -1)
        front++;
    rear++;
    arr[rear] = data;
    printf("\nData entered, arr[%d] = %d", rear, arr[rear]);
}

void dequeue()
{
    printf("\nBefore Dequeue:");
    printf("\nfront = %d rear = %d",front,rear);
    front++;
    printf("\nAfter Dequeue:");
    printf("\nfront = %d rear = %d",front,rear);
}

void DisplayAll()
{
    if( front == -1 || rear == -1)
    {
        printf("\nQueue is empty...");
    }
    else
    {
        printf("\nThe queue data are:");
        for(int i = front; i <= rear; i++)
        {
            printf("\nArr[%d] = %d", i, arr[i]);
        }
    }
}

void isFull()
{
    if(rear == size -1)
        printf("\nQueue is Full...");

    else
    {
        printf("Enter the data you want to enter: ");
        scanf("%d",&data);
        enqueue(data); 
    }
}

void isEmpty()
{
    if( front == -1 || rear == -1)
    {
        printf("\nQueue is empty...");
    }
    else
    {
        dequeue();
    }
    if( front >= size)
    {
        rear = -1;
        front = -1;
    }
}
