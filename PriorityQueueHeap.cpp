/*
    - std::priority_queue<int> is used to create a max heap of integers. By default, priority_queue in C++ is a max heap.
    - std::priority_queue<int, std::vector<int>, std::greater<int>> is used to create a min heap of integers. The third template 
      argument std::greater<int> specifies the comparator for the priority queue, ensuring that the smallest elements have the highest priority.
    - push() is used to insert elements.
    - top() retrieves the maximum element.
    - pop() removes the maximum element.
*/

#include <iostream>
#include <queue> // include the priority_queue header

int main() {
    // Create a max heap
    std::priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(40);
    maxHeap.push(50);
    maxHeap.push(25);

    // Print the max heap (note: priority_queue does not provide direct access to elements)
    std::cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // Create a min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(40);
    minHeap.push(50);
    minHeap.push(25);

    // Print the min heap (note: priority_queue does not provide direct access to elements)
    std::cout << "Min Heap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
