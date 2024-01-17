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
