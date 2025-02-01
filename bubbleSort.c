// BUBBLE SORT IMPLEMENTATION
#include <stdio.h>
#define size 20

int n,i,j, arr[size], temp;

void bubbleSort(int n, int arr[])
{
    for(i=0; i<n-1; i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter no. of data: ");
    scanf("%d", &n);

    printf("Enter each: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    bubbleSort(n,arr);

    printf("The data in sorted (ascending) form are: ");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}
