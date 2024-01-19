#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a Min Heap Node structure
struct MinHeapNode {
    struct Node* listNode;
    int index; // Index of the list to which the node belongs
};

// Define a Min Heap structure
struct MinHeap {
    struct MinHeapNode* heapArray;
    int size;
};

// Function to create a new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to create a Min Heap with given capacity
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if (minHeap == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    minHeap->size = 0;
    minHeap->heapArray = (struct MinHeapNode*)malloc(capacity * sizeof(struct MinHeapNode));
    if (minHeap->heapArray == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return minHeap;
}

// Function to swap two Min Heap Nodes
void swapMinHeapNodes(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at given index
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->heapArray[left].listNode->data < minHeap->heapArray[smallest].listNode->data)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->heapArray[right].listNode->data < minHeap->heapArray[smallest].listNode->data)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNodes(&minHeap->heapArray[smallest], &minHeap->heapArray[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a new Min Heap Node
void insertMinHeap(struct MinHeap* minHeap, struct Node* listNode, int index) {
    int i = minHeap->size;
    minHeap->size++;
    minHeap->heapArray[i].listNode = listNode;
    minHeap->heapArray[i].index = index;

    while (i > 0 && minHeap->heapArray[(i - 1) / 2].listNode->data > minHeap->heapArray[i].listNode->data) {
        swapMinHeapNodes(&minHeap->heapArray[i], &minHeap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to merge k sorted linked lists
struct Node* mergeKLists(struct Node** lists, int k) {
    // Create a Min Heap and initialize it with the heads of all lists
    struct MinHeap* minHeap = createMinHeap(k);
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            insertMinHeap(minHeap, lists[i], i);
        }
    }

    struct Node* dummy = createNode(0); // Dummy node to simplify the code
    struct Node* current = dummy;

    // Continue until Min Heap is not empty
    while (minHeap->size > 0) {
        // Get the minimum element from the Min Heap
        struct MinHeapNode minNode = minHeap->heapArray[0];
        current->next = minNode.listNode;
        current = current->next;

        // Move the current pointer in the list
        lists[minNode.index] = lists[minNode.index]->next;

        // Insert the next node from the same list into the Min Heap
        if (lists[minNode.index] != NULL) {
            insertMinHeap(minHeap, lists[minNode.index], minNode.index);
        } else {
            // If the list is exhausted, reduce the size of the Min Heap
            minHeap->size--;
            if (minHeap->size > 0) {
                minHeap->heapArray[0] = minHeap->heapArray[minHeap->size];
                minHeapify(minHeap, 0);
            }
        }
    }

    return dummy->next; // The merged list starts from the next of the dummy node
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Example usage with 3 sorted linked lists
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* list3 = NULL;

    // Insertion in sorted order
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 4);
    insertAtEnd(&list1, 5);

    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);

    insertAtEnd(&list3, 2);
    insertAtEnd(&list3, 6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    printf("List 3: ");
    printList(list3);

    // Merge k sorted lists
    int k = 3;
    struct Node* mergedList = mergeKLists((struct Node*[]){list1, list2, list3}, k);

    printf("Merged List: ");
    printList(mergedList);

    // Free allocated memory for the lists
    freeList(list1);
    freeList(list2);
    freeList(list3);
    freeList(mergedList);

    return 0;
}
