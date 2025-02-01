// IMPLEMENTATION OF QUICK SORT
#include <stdio.h>
#define size 20

int arr[size], n, i, l, h ;

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
    printf("Enter number of data: ");
    scanf("%d", &n);

    printf("Enter each element: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    l = 0;
    h = n-1;
    quickSort(arr, l, h);

    printf("The data in sorted (ascending) form are: ");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    
    return 0;
}
