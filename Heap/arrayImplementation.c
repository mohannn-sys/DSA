#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure to represent a max heap
struct MaxHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// Function to initialize a max heap
void initializeHeap(struct MaxHeap* heap) {
    heap->size = 0;
}

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max heap property
void heapify(struct MaxHeap* heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if left child is larger than the current largest
    if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest])
        largest = leftChild;

    // Check if right child is larger than the current largest
    if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest])
        largest = rightChild;

    // If the largest is not the current index, swap and recursively heapify
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

// Function to insert a new element into the max heap
void insert(struct MaxHeap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap overflow: Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    // Fix the max heap property
    while (index > 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract the maximum element from the max heap
int extractMax(struct MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow: Cannot extract from an empty heap.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The maximum element is at the root
    int max = heap->arr[0];

    // Replace the root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Fix the max heap property
    heapify(heap, 0);

    return max;
}

// Function to print the elements of the max heap
void printHeap(struct MaxHeap* heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap heap;
    initializeHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 40);
    insert(&heap, 50);
    insert(&heap, 25);

    printHeap(&heap);

    int max = extractMax(&heap);
    printf("Extracted max element: %d\n", max);

    printHeap(&heap);

    return 0;
}
