// RADIX SORT IMLEMENTATION
// this program does not imply efficient radix sort
#include <stdio.h>
#include <math.h>
#define SIZE 20

void radixSort( int arr[], int n) {
    int ndig = 0, maxdig = 0, dig = 1;
    int val, i, j, div;
    int radix_i, radix_j, temp;
    for ( i = 0 ; i < n ; i++) {
        val = arr[i];
        while(val != 0) {
            val /= 10;
            ndig++;
        }
        if( ndig > maxdig)
            maxdig = ndig;
        ndig = 0;
    }
    while (dig <= maxdig)
    {
        div = pow(10, dig);
        for(i=0; i<n-1; i++)
        {
            for(j = i+1; j<n ; j++)
            {
                radix_i = arr[i] % div;
                radix_j = arr[j] % div;
                if( radix_i > radix_j)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        dig++;
    }
    return;
}

int main(){
    int arr[SIZE], i, n;
    printf("Enter number of data: ");
    scanf("%d", &n);

    printf("Enter each element: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("The data in sorted (ascending) form are: ");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    return 0;
}