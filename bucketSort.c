// RADIX/BUCKET SORT IMPLEMENTATION
#include <stdio.h>
#define MAX 50

void radixSort(int a[], int n) {
    int bucket[10][MAX];  // Buckets for digits 0-9 (max capacity = n)
    int buck[10];         // Track the count of elements in each bucket
    int i, j, k, l, num = 0, div = 1, large = a[0], passes;

    // Find the largest number to determine the number of passes
    for (i = 1; i < n; i++) {
        if (a[i] > large)
            large = a[i];
    }

    // Determine the number of digits in the largest number
    while (large > 0) {
        num++;
        large /= 10;
    }

    // Perform radix sort for each digit position
    for (passes = 0; passes < num; passes++) {
        // Initialize bucket counters to 0
        for (k = 0; k < 10; k++)
            buck[k] = 0;

        // Distribute elements into buckets based on current digit
        for (i = 0; i < n; i++) {
            l = (a[i] / div) % 10;
            bucket[l][buck[l]++] = a[i];
        }

        // Collect elements from buckets and copy back to array
        i = 0;
        for (k = 0; k < 10; k++) {
            for (j = 0; j < buck[k]; j++)
                a[i++] = bucket[k][j];
        }

        div *= 10;  // Move to the next digit place
    }
}

int main() {
    int a[MAX], n, i;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("The data in sorted (ascending) form are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\n");
    return 0;
}
