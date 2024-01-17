#include <iostream>
#include <vector>
#include <queue>

// Function to perform Heap Sort using priority queue
void heapSort(std::vector<int>& arr) {
    // Create a max heap (default behavior of std::priority_queue)
    std::priority_queue<int> maxHeap;

    // Push all elements into the max heap
    for (int value : arr) {
        maxHeap.push(value);
    }

    // Pop elements from the max heap and update the array
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = maxHeap.top();
        maxHeap.pop();
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
