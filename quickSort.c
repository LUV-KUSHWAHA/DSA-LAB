// IMPLEMENTATION OF QUICK SORT
#include <stdio.h>
#define size 20

void quickSort(int arr[], int l, int h)
{
    int temp, key, low, high;
    low = l;
    high = h;
    key = arr[(low+high)/2] ;
    do {
        while (key > arr[low])
            low++;
        while (key < arr[high])
            high--;
        if( low <= high ) {
            temp = arr[low];
            arr[low++] = arr[high];
            arr[high--] = temp;
        }
    }while(low <= high);
    if(l < high)
        quickSort(arr, l, high);
    if(low < h)
        quickSort(arr, low, h);
}

int main()
{
    int arr[size], n, i;
    printf("Enter number of data: ");
    scanf("%d", &n);

    printf("Enter each element: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n-1);

    printf("The data in sorted (ascending) form are: ");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    
    return 0;
}
