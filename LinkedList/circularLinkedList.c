#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the circular list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode; // Points to itself in a circular list
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
    *head = newNode;
}

// Function to insert a new node at the end of the circular list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode; // Points to itself in a circular list
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
}

// Function to delete a node with a given value from the circular list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Find the node to be deleted and its previous node
    while (temp->data != value) {
        if (temp->next == *head) {
            printf("Node with value %d not found\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is the only node in the list
    if (temp->next == *head && prev == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // If the node to be deleted is the first node
    if (temp == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to traverse and print the elements of the circular list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to search for a value in the circular list
int search(struct Node* head, int value) {
    if (head == NULL) {
        return -1; // Value not found
    }

    struct Node* temp = head;
    int position = 0;
    do {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

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
