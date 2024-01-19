class Node {
    constructor(value) {
        this.data = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    // Function to insert a new node at the beginning of the list
    insertAtBeginning(value) {
        const newNode = new Node(value);
        newNode.next = this.head;
        this.head = newNode;
    }

    // Function to insert a new node at the end of the list
    insertAtEnd(value) {
        const newNode = new Node(value);
        if (this.head === null) {
            this.head = newNode;
            return;
        }
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Function to delete a node with a given value
    deleteNode(value) {
        let temp = this.head;
        if (temp !== null && temp.data === value) {
            this.head = temp.next;
            return;
        }
        let prev = null;
        while (temp !== null && temp.data !== value) {
            prev = temp;
            temp = temp.next;
        }
        if (temp === null) {
            console.log(`Node with value ${value} not found`);
            return;
        }
        prev.next = temp.next;
    }

    // Function to traverse and print the elements of the list
    traverse() {
        let current = this.head;
        process.stdout.write("Linked List: ");
        while (current !== null) {
            process.stdout.write(`${current.data} -> `);
            current = current.next;
        }
        console.log("null");
    }

    // Function to search for a value in the list
    search(value) {
        let current = this.head;
        let position = 0;
        while (current !== null) {
            if (current.data === value) {
                return position;
            }
            current = current.next;
            position++;
        }
        return -1; // Value not found
    }
}

// Example usage:
const myList = new LinkedList();

// Insertion
myList.insertAtEnd(10);
myList.insertAtEnd(20);
myList.insertAtBeginning(5);

// Traversal
myList.traverse();

// Search
const searchValue = 20;
const searchPosition = myList.search(searchValue);
if (searchPosition !== -1) {
    console.log(`${searchValue} found at position ${searchPosition}`);
} else {
    console.log(`${searchValue} not found in the list`);
}

// Deletion
myList.deleteNode(20);

// Traversal after deletion
myList.traverse();
