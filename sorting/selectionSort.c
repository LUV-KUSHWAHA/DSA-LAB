// SELECTION SORT IMPLEMENTAIION
#include <stdio.h>
#define size 20

int n, i, j, arr[size], temp, minIndex;

void selectionSort(int n, int arr[])
{
    for(j=0; j<n-1; j++)
    {
        minIndex = j;
        for(i=j+1; i<n; i++)
        {
            if(arr[i] < arr[minIndex])
            {
                minIndex = i;
            }    
        }
        
        if(minIndex != j)
        {
            temp = arr[j];
            arr[j] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    printf("Enter number of data: ");
    scanf("%d", &n);

    printf("Enter each element: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    selectionSort(n, arr);

    printf("The data in sorted (ascending) form are: ");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    
    return 0;
}
