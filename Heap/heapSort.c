/*
Heap Sort
Time Complexity:

    Building the Heap (heapify):
        The heapify operation is performed for each non-leaf node in the heap.
        The number of non-leaf nodes in a binary heap is roughly n/2n/2, where nn is the number of elements in the array.
        The time complexity for building the heap is O(n).

    Extracting Max/Min and Heapify:
        After building the heap, the extractMax/extractMin and heapify operations are performed nn times.
        The time complexity for each extraction and heapify is O(log⁡n).
        Therefore, the overall time complexity for extracting and heapifying nn elements is O(nlog⁡n).

Space Complexity:

    The space complexity of Heap Sort is O(1) since the algorithm is an in-place sorting algorithm. 
    It doesn't require additional space proportional to the input size, except for a constant amount of extra space used for variables.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i in the array
void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // Compare with left child
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Compare with right child
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the current index, swap and recursively heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to the end
        heapify(arr, i, 0);     // Call heapify on the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
