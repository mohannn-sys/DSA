#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure to represent a binary heap
struct PriorityQueue {
    int heap[MAX_HEAP_SIZE];
    int size;
};

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void heapifyUp(struct PriorityQueue* pq, int index) {
    int parent = (index - 1) / 2;

    // Compare with the parent and swap if necessary
    while (index > 0 && pq->heap[index] < pq->heap[parent]) {
        swap(&pq->heap[index], &pq->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to maintain the min heap property
void heapifyDown(struct PriorityQueue* pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    // Compare with left child
    if (leftChild < pq->size && pq->heap[leftChild] < pq->heap[smallest])
        smallest = leftChild;

    // Compare with right child
    if (rightChild < pq->size && pq->heap[rightChild] < pq->heap[smallest])
        smallest = rightChild;

    // If the smallest is not the current index, swap and recursively heapify
    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to initialize a priority queue
void initializePriorityQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Function to insert a new element into the priority queue
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == MAX_HEAP_SIZE) {
        printf("Priority Queue overflow: Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    int index = pq->size;
    pq->heap[index] = value;
    pq->size++;

    // Fix the min heap property
    heapifyUp(pq, index);
}

// Function to extract the minimum element from the priority queue
int extractMin(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue underflow: Cannot extract from an empty queue.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The minimum element is at the root
    int min = pq->heap[0];

    // Replace the root with the last element
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    // Fix the min heap property by calling heapifyDown
    heapifyDown(pq, 0);

    return min;
}

// Function to get the size of the priority queue
int getPriorityQueueSize(struct PriorityQueue* pq) {
    return pq->size;
}

// Function to print the elements of the priority queue
void printPriorityQueue(struct PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);

    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 15);
    insert(&pq, 40);
    insert(&pq, 50);
    insert(&pq, 25);

    printPriorityQueue(&pq);

    int min = extractMin(&pq);
    printf("Extracted min element: %d\n", min);

    printPriorityQueue(&pq);

    printf("Priority Queue size: %d\n", getPriorityQueueSize(&pq));

    return 0;
}
