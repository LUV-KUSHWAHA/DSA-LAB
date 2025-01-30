// fibonacci series upto n terms
#include <stdio.h>
int fib(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n, f;
    printf("Enter n to find n fibonacci series: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        f=fib(i);
        printf("\t%d",f);
    }
    
    return 0;
}
