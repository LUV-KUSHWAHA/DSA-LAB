// factorial using recursion
#include <stdio.h>
int fact(int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    int n, f;
    printf("Enter n to find factorial: ");
    scanf("%d", &n);
    f = fact(n);
    printf("Factorial = %d ", f);
    return 0;
}
