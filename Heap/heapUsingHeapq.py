'''
The heapq module provides functionality for implementing heaps. 
However, it only directly supports min heaps. 
To implement a max heap, you can negate the values when inserting and extracting from the heap. 
'''

import heapq

class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        heapq.heappush(self.heap, value)

    def extract_min(self):
        if not self.heap:
            return None  # Heap is empty
        return heapq.heappop(self.heap)

class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        heapq.heappush(self.heap, -value)

    def extract_max(self):
        if not self.heap:
            return None  # Heap is empty
        return -heapq.heappop(self.heap)

# Example usage:
min_heap = MinHeap()
min_heap.insert(10)
min_heap.insert(20)
min_heap.insert(15)
min_heap.insert(40)
min_heap.insert(50)
min_heap.insert(25)

print("Min Heap:", min_heap.heap)

min_value = min_heap.extract_min()
print("Extracted min value:", min_value)
print("Min Heap after extraction:", min_heap.heap)

max_heap = MaxHeap()
max_heap.insert(10)
max_heap.insert(20)
max_heap.insert(15)
max_heap.insert(40)
max_heap.insert(50)
max_heap.insert(25)

print("\nMax Heap:", max_heap.heap)

max_value = max_heap.extract_max()
print("Extracted max value:", max_value)
print("Max Heap after extraction:", max_heap.heap)
