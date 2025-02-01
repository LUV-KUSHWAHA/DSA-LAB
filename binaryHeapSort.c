// PROGRAM TO IMPLEMENT HEAP SORT
#include <stdio.h>

#define SIZE 10

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
// n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (maximum) to the end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[SIZE] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 13};

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    heapSort(arr, SIZE);

    printf("The data in sorted (ascending) form are:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    return 0;
}
