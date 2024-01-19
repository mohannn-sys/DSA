#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
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
    newNode->prev = current;
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to traverse and print the elements of the list
void traverse(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
int search(struct Node* head, int value) {
    int position = 0;
    while (head != NULL) {
        if (head->data == value) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1; // Value not found
}

int main() {
    struct Node* head = NULL;

    // Insertion
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    // Traversal
    traverse(head);

    // Search
    int searchValue = 20;
    int position = search(head, searchValue);
    if (position != -1) {
        printf("%d found at position %d\n", searchValue, position);
    } else {
        printf("%d not found in the list\n", searchValue);
    }

    // Deletion
    deleteNode(&head, 20);

    // Traversal after deletion
    traverse(head);

    return 0;
}
