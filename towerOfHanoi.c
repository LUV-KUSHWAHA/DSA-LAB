// tower of hanoi puzzle solution
#include <stdio.h>
int count = 0;
void TOH(int n, char A,  char B, char C)
{
    
    if(n==1)
    {
        
        printf("\n %d moved from %c to %c",++ count, A, C );
        return;
    }
    TOH(n-1,A,C,B);
    printf("\n %d moved from %c to %c",++ count, A, C );
    TOH(n-1,B,A,C);
}

int main()
{
    int n;
    printf("Enter no. of disks: ");
    scanf("%d", &n);
    TOH(n,'A','B','C');
    return 0;
}
