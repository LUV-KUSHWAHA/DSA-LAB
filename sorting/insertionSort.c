// PROGRAM TO IMPLEMENT INSERTION SORT
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while( j >= 0 && arr[j] > key )
        {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int n, arr[] = {4, 2, 8, 9, 0};
    n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    display(arr, n);

    insertionSort(arr, n);

    printf("After sorting: ");
    display(arr, n);
    return 0;
}