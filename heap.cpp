#include<iostream>
#include<vector>
#include<algorithm>

class MaxHeap{
private:
    std::vector<int> heap;
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return 2*i+1;
    }
    int rightChild(int i){
        return 2*i+2;
    }

    void heapifyUp(int index){
        while (index > 0 && heap[index] > heap[parent(index)]){
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index){
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if (left<heap.size() && heap[left] > heap[maxIndex]){
            maxIndex = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIndex]){
            maxIndex = right;
        }

        if (index != maxIndex){
            std::swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
public:
    void insert(int key){
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");

        }
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()){
        heapifyDown(0);
    }
    return maxVal;
    }
    int peek() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Utility to print the heap
    void printHeap() {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap h;

    std::cout << "Inserting 10, 20, 5, 30, 15...\n";
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    std::cout << "Current Heap: ";
    h.printHeap(); // Expected roughly: 30 20 5 10 15

    std::cout << "Max value extracted: " << h.extractMax() << "\n";
    
    std::cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}