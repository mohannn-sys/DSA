#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the min heap
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure to represent the min heap
struct MinHeap {
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

// Function to heapify a subtree with the given root for min heap
void heapify(struct Node* root) {
    struct Node* smallest = root;
    struct Node* leftChild = root->left;
    struct Node* rightChild = root->right;

    // Compare with left child
    if (leftChild != NULL && leftChild->data < smallest->data)
        smallest = leftChild;

    // Compare with right child
    if (rightChild != NULL && rightChild->data < smallest->data)
        smallest = rightChild;

    // If the smallest is not the root, swap and recursively heapify
    if (smallest != root) {
        swap(&root->data, &smallest->data);
        heapify(smallest);
    }
}

// Function to insert a value into the min heap
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data) {
        // If the value is smaller than the root, swap values
        swap(&value, &root->data);
    }

    // Recursively insert into left and right subtrees
    if (value >= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to extract the minimum element from the min heap
struct Node* extractMin(struct Node* root) {
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

// Function to find the minimum element in the min heap
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Heap is empty: Cannot find minimum element.\n");
        return -1; // Some sentinel value indicating an error
    }

    // The minimum element is at the root
    return root->data;
}

// Function to get the size of the min heap
int getHeapSize(struct Node* root) {
    if (root == NULL)
        return 0;

    // Recursively calculate size
    return 1 + getHeapSize(root->left) + getHeapSize(root->right);
}

// Function to print the elements of the min heap using an in-order traversal
void printHeap(struct Node* root) {
    if (root != NULL) {
        printHeap(root->left);
        printf("%d ", root->data);
        printHeap(root->right);
    }
}

int main() {
    struct MinHeap heap;
    heap.root = NULL;

    heap.root = insert(heap.root, 10);
    insert(heap.root, 20);
    insert(heap.root, 15);
    insert(heap.root, 40);
    insert(heap.root, 50);
    insert(heap.root, 25);

    printf("Min Heap: ");
    printHeap(heap.root);
    printf("\n");

    printf("Min element: %d\n", findMin(heap.root));

    heap.root = extractMin(heap.root);
    printf("Extracted min element.\n");

    printf("Min Heap after extraction: ");
    printHeap(heap.root);
    printf("\n");

    printf("Heap size: %d\n", getHeapSize(heap.root));

    return 0;
}
