#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure to represent the min heap
struct MinHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void heapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if left child is smaller than the current smallest
    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest])
        smallest = leftChild;

    // Check if right child is smaller than the current smallest
    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest])
        smallest = rightChild;

    // If the smallest is not the current index, swap and recursively heapify
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Function to initialize a min heap
void initializeHeap(struct MinHeap* heap) {
    heap->size = 0;
}

// Function to insert a new element into the min heap
void insert(struct MinHeap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap overflow: Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    // Fix the min heap property
    while (index > 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract the minimum element from the min heap
int extractMin(struct MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow: Cannot extract from an empty heap.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The minimum element is at the root
    int min = heap->arr[0];

    // Replace the root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Fix the min heap property
    heapify(heap, 0);

    return min;
}

// Function to find the minimum element in the min heap
int findMin(struct MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty: Cannot find minimum element.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The minimum element is at the root
    return heap->arr[0];
}

// Function to get the size of the min heap
int getHeapSize(struct MinHeap* heap) {
    return heap->size;
}

// Function to print the elements of the min heap
void printHeap(struct MinHeap* heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap heap;
    initializeHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 40);
    insert(&heap, 50);
    insert(&heap, 25);

    printHeap(&heap);

    printf("Min element: %d\n", findMin(&heap));

    int min = extractMin(&heap);
    printf("Extracted min element: %d\n", min);

    printHeap(&heap);

    printf("Heap size: %d\n", getHeapSize(&heap));

    return 0;
}
