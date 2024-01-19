#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

// Function to detect a cycle in the linked list
int detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If the two pointers meet, there is a cycle
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle detected
}

int main() {
    struct Node* head = NULL;

    // Insertion
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Create a cycle (comment this line to test without a cycle)
    head->next->next->next = head;

    // Detect cycle
    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}
