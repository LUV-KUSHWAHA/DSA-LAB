// stack implementation
#include <stdio.h>
#define size 5

int stack[size],top=-1,data;

void push(int data1)
    {
        top++;
        printf("\nPushing data = %d at top = %d\n\n",data1,top);
        stack[top]=data1;
    }

void isFull()
{
    if(top == size-1)
    {
        printf("\nstack full\n\n");;
    }
    else
    {
        printf("\nEnter data to push: ");
        scanf("%d",&data);
        push(data);
    }
}


void pop()
{
    printf("\nData=%d",stack[top]);
    top--;
    printf("\nData popped.\ntop = %d",top);
}
    void isEmpty()
    {
       if(top == -1)
       {
            printf("\nStack is empty.");
       } 
       else{
            pop();
       }
    }

int main()
{
    int x;
    while(1)
    {
        printf("\nWhat do you want to do?");
        printf("\n1.PUSH\n2.POP\n");
        scanf("%d",&x);
        switch(x)
    {
        case 1:
        isFull();
        break;

        case 2:
        isEmpty();
        break;

        default:
        printf("\nwrong choice!");
    }
}
    return 0;
}
