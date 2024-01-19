#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertAtEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertAtEnd(&mergedList, list2->data);
            list2 = list2->next;
        }

        // Move the 'current' pointer to the last node of the merged list
        if (current == NULL) {
            current = mergedList;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
        }
    }

    // Append the remaining nodes from list1, if any
    while (list1 != NULL) {
        insertAtEnd(&mergedList, list1->data);
        list1 = list1->next;
    }

    // Append the remaining nodes from list2, if any
    while (list2 != NULL) {
        insertAtEnd(&mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insertion in sorted order
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    traverse(list1);
    printf("List 2: ");
    traverse(list2);

    // Merge the two sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    traverse(mergedList);

    return 0;
}
