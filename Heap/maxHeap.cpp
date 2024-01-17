#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Compare with left child
        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        // Compare with right child
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        // If the largest is not the current index, swap and recursively heapify
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int value) {
        // Insert the new element at the end
        heap.push_back(value);

        // Fix the max heap property
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    int extractMax() {
        if (heap.empty()) {
            std::cout << "Heap underflow: Cannot extract from an empty heap." << std::endl;
            return -1; // Some sentinel value indicating an error
        }

        // The maximum element is at the root
        int max = heap[0];

        // Replace the root with the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Fix the max heap property by calling heapify
        heapify(0);

        return max;
    }

    int findMax() const {
        if (heap.empty()) {
            std::cout << "Heap is empty: Cannot find maximum element." << std::endl;
            return -1; // Some sentinel value indicating an error
        }

        // The maximum element is at the root
        return heap[0];
    }

    int getHeapSize() const {
        return heap.size();
    }

    void printHeap() const {
        std::cout << "Max Heap: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(40);
    maxHeap.insert(50);
    maxHeap.insert(25);

    maxHeap.printHeap();

    std::cout << "Max element: " << maxHeap.findMax() << std::endl;

    int max = maxHeap.extractMax();
    std::cout << "Extracted max element: " << max << std::endl;

    maxHeap.printHeap();

    std::cout << "Heap size: " << maxHeap.getHeapSize() << std::endl;

    return 0;
}
