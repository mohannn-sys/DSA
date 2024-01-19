class Node:
    def __init__(self, value):
        self.data = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning of the list
    def insert_at_beginning(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    # Function to insert a new node at the end of the list
    def insert_at_end(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = new_node

    # Function to delete a node with a given value
    def delete_node(self, value):
        temp = self.head
        if temp is not None and temp.data == value:
            self.head = temp.next
            del temp
            return
        prev = None
        while temp is not None and temp.data != value:
            prev = temp
            temp = temp.next
        if temp is None:
            print(f"Node with value {value} not found")
            return
        prev.next = temp.next
        del temp

    # Function to traverse and print the elements of the list
    def traverse(self):
        current = self.head
        print("Linked List:", end=" ")
        while current is not None:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    # Function to search for a value in the list
    def search(self, value):
        current = self.head
        position = 0
        while current is not None:
            if current.data == value:
                return position
            current = current.next
            position += 1
        return -1  # Value not found


# Example usage:
my_list = LinkedList()

# Insertion
my_list.insert_at_end(10)
my_list.insert_at_end(20)
my_list.insert_at_beginning(5)

# Traversal
my_list.traverse()

# Search
search_value = 20
position = my_list.search(search_value)
if position != -1:
    print(f"{search_value} found at position {position}")
else:
    print(f"{search_value} not found in the list")

# Deletion
my_list.delete_node(20)

# Traversal after deletion
my_list.traverse()
