# Linked List
A linked list is a linear data structure where the data is stored in **nodes** that are connected by **links**. Each node consists of two parts:

1. **Data:** This can be any type of data, such as an integer, a string, or a complex object.
2. **Link:** This is a reference to the next node in the list. The last node in the list has a `null` link to indicate the end of the list.

Here's an image to illustrate the structure of a linked list:

**Types of Linked Lists:**

There are several different types of linked lists, each with its own advantages and disadvantages. The most common types are:

* **Singly linked list:** The most basic type of linked list, where each node only has one link, pointing to the next node.
  ![](https://media.geeksforgeeks.org/wp-content/uploads/20220816144425/LLdrawio.png)
* **Doubly linked list:** Each node has two links, one pointing to the next node and one pointing to the previous node.
![Image of Doubly linked list data structure](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png)
* **Circular linked list:** The last node in the list is linked back to the first node, forming a loop.
![Image of Circular linked list data structure](https://media.geeksforgeeks.org/wp-content/uploads/CircularLinkeList.png)

**Operations on Linked Lists:**

You can perform several operations on linked lists, such as:

* **Insertion:** Adding a new node to the list.
* **Deletion:** Removing a node from the list.
* **Traversal:** Visiting each node in the list.
* **Searching:** Finding a specific node in the list.

**Advantages of Linked Lists:**

* **Dynamic size:** Linked lists can grow and shrink as needed, unlike arrays which have a fixed size.
* **Efficient insertion and deletion:** Inserting or deleting a node in the middle of a linked list is faster than doing the same in an array.
* **Memory allocation:** Linked lists only use the memory they need, whereas arrays may waste memory if they are not full.

**Disadvantages of Linked Lists:**

* **Random access:** Accessing a specific node in a linked list is slower than accessing an element in an array, as you need to traverse the list from the beginning until you find the node.
* **Memory overhead:** Each node in a linked list stores a link, which takes up additional memory compared to an array.
