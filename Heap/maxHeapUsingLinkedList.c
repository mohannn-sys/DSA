#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the max heap
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure to represent the max heap
struct MaxHeap {
    struct Node* root;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the given root
void heapify(struct Node* root) {
    struct Node* largest = root;
    struct Node* leftChild = root->left;
    struct Node* rightChild = root->right;

    // Compare with left child
    if (leftChild != NULL && leftChild->data > largest->data)
        largest = leftChild;

    // Compare with right child
    if (rightChild != NULL && rightChild->data > largest->data)
        largest = rightChild;

    // If the largest is not the root, swap and recursively heapify
    if (largest != root) {
        swap(&root->data, &largest->data);
        heapify(largest);
    }
}

// Function to insert a value into the max heap
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value > root->data) {
        // If the value is greater than the root, swap values
        swap(&value, &root->data);
    }

    // Recursively insert into left and right subtrees
    if (value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to extract the maximum element from the max heap
struct Node* extractMax(struct Node* root) {
    if (root == NULL)
        return NULL;

    // Find the rightmost node in the last level
    struct Node* lastNode = root;
    struct Node* parent = NULL;

    while (lastNode->right != NULL) {
        parent = lastNode;
        lastNode = lastNode->right;
    }

    // If the lastNode is not the root, replace root's data with lastNode's data
    if (parent != NULL) {
        root->data = lastNode->data;

        // Remove the lastNode
        if (parent->left == lastNode)
            parent->left = NULL;
        else
            parent->right = NULL;

        // Heapify to maintain the heap property
        heapify(root);
    } else {
        // If the lastNode is the root, set the root to NULL
        free(root);
        root = NULL;
    }

    return root;
}

// Function to find the maximum element in the max heap
int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Heap is empty: Cannot find maximum element.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The maximum element is at the root
    return root->data;
}

// Function to get the size of the max heap
int getHeapSize(struct Node* root) {
    if (root == NULL)
        return 0;

    // Recursively calculate size
    return 1 + getHeapSize(root->left) + getHeapSize(root->right);
}

// Function to print the elements of the max heap using an in-order traversal
void printHeap(struct Node* root) {
    if (root != NULL) {
        printHeap(root->left);
        printf("%d ", root->data);
        printHeap(root->right);
    }
}

int main() {
    struct MaxHeap heap;
    heap.root = NULL;

    heap.root = insert(heap.root, 10);
    insert(heap.root, 20);
    insert(heap.root, 15);
    insert(heap.root, 40);
    insert(heap.root, 50);
    insert(heap.root, 25);

    printf("Max Heap: ");
    printHeap(heap.root);
    printf("\n");

    printf("Max element: %d\n", findMax(heap.root));

    heap.root = extractMax(heap.root);
    printf("Extracted max element.\n");

    printf("Max Heap after extraction: ");
    printHeap(heap.root);
    printf("\n");

    printf("Heap size: %d\n", getHeapSize(heap.root));

    return 0;
}
