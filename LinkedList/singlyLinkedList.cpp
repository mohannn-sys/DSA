#include <iostream>

// Define a Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Class for Singly Linked List
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == value) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Node with value " << value << " not found" << std::endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Function to traverse and print the elements of the list
    void traverse() {
        Node* current = head;
        std::cout << "Linked List: ";
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Function to search for a value in the list
    int search(int value) {
        int position = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1; // Value not found
    }
};

int main() {
    LinkedList myList;

    // Insertion
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtBeginning(5);

    // Traversal
    myList.traverse();

    // Search
    int searchValue = 20;
    int position = myList.search(searchValue);
    if (position != -1) {
        std::cout << searchValue << " found at position " << position << std::endl;
    } else {
        std::cout << searchValue << " not found in the list" << std::endl;
    }

    // Deletion
    myList.deleteNode(20);

    // Traversal after deletion
    myList.traverse();

    return 0;
}
