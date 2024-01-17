# Heap
A heap is a tree-based data structure that satisfies a specific ordering property.

## There are two main types of heaps:
- Max heap: In a max heap, the value of a parent node is always greater than or equal to the values of its children. The largest element in the heap is always at the root (top) node.
- Min heap: In a min heap, the value of a parent node is always less than or equal to the values of its children. The smallest element in the heap is always at the root node.

## Here are some key characteristics of heaps:
- Complete binary tree: A heap is a complete binary tree, meaning all levels of the tree are filled as much as possible, except for the last level.
- Ordering property: Each element in the heap satisfies the specific ordering property (greater than or equal for max heap, less than or equal for min heap).
- Efficient operations: Heaps allow for efficient insertion and deletion of elements, especially compared to other data structures like sorted arrays. This is because of the ordering property and the structure of the tree.

## Applications of Heaps
Heaps are used in many different applications because of their efficient operations:
- Priority queues: Heaps are commonly used to implement priority queues, where elements with higher priority are served first. For example, a hospital might use a min-heap to prioritize patients based on the severity of their injuries.
- Sorting algorithms: Heap sort is a sorting algorithm that uses a heap to sort a list of elements. It is more efficient than bubble sort or selection sort, especially for large datasets.
- Graph algorithms: Some graph algorithms, such as Dijkstra's shortest path algorithm, use heaps to efficiently find the shortest path between two nodes in a graph.

## Implementation
There are two main ways to implement a max heap: using an array or using a linked list.

**1. Using an Array:**
- We can represent the heap as a simple array where the ith element is the child of the element at (i-1)/2. 
- This makes it easy to find the parent and children of any node:
    - Left child: 2i + 1
    - Right child: 2i + 2
    - Parent: (i-1)/2
- Operations like insertion and deletion can be efficiently implemented using this representation. However, there are limitations:
    - Fixed size: The size of the heap is limited by the size of the array. Expanding the array requires copying all elements, which can be expensive.
    - Wasted space: If the heap is not nearly full, there can be a lot of unused space in the array.

**2. Using a Linked List:**
- Each node in the linked list stores the value and pointers to its left and right children.
- This eliminates the fixed size limitation of arrays but makes finding parent and children slightly more complex.
- Operations like insertion and deletion require traversing the linked list, which can be slower than with an array for large heaps.

Here are some additional details about the implementation:

**1. Maintaining the Max Heap Property:**

- After an insertion or deletion, the heap might not satisfy the max heap property. To fix this, a process called "heapify" is performed.
- Heapify recursively compares a node with its children and swaps them if the child is larger. This continues until the node reaches the bottom of the heap or becomes larger than both its children.

**2. Operations:**

- **Insertion:**
    1. Add the new element to the bottom of the linked list or array.
    2. Heapify the subtree rooted at the newly added element.
- **Deletion:**
    1. Remove the element at the root (usually the largest).
    2. Move the last element in the linked list or array to the root.
    3. Heapify the subtree rooted at the root.
- **Other operations:**
    - Finding the maximum element: Simply access the element at the root.
    - Finding the size of the heap: Maintain a separate counter or use the length of the linked list or array.


