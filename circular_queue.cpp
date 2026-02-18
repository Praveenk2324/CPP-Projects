#include<iostream>
#include<vector>

using namespace std;

class circularQueue{
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    circularQueue(int k){
        data.resize(k);
        capacity = k;
        head = -1;
        tail = -1;
        size = 0;
    }

    bool enQueue(int value){
        if (isFull()){
            cout<< "Failed to Enqueue" << value << " (Queue Full)\n";
            return false;
        }

        if(isEmpty()){
            head = 0;
        }

        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;

        cout << "Enqueued: " << value << "\n";
        return true;

    }

    bool deQueue(){
        if(isEmpty()){
            cout << "Failed to Dequeue (queue empty)\n";
            return false;
        }

        cout << "Dequeued: "<<data[head] << "\n";

        if(head == tail){
            head = -1;
            tail = -1;
        }else {
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        return size == 0; 
    }
    
    bool isFull() {
        return size == capacity;
    }

    void displayQueue() {
        if (isEmpty()) {
            std::cout << "Current Queue: [ EMPTY ]\n";
            return;
        }

        std::cout << "Current Queue: [ ";
        // We iterate exactly 'size' times
        for (int i = 0; i < size; i++) {
            // Calculate the actual index using modulo math
            int index = (head + i) % capacity;
            std::cout << data[index] << " ";
        }
        std::cout << "]\n";
        std::cout << "Head Index: " << head << ", Tail Index: " << tail << "\n";
        std::cout << "------------------------------\n";
    }
};

int main() {
    // 1. Create a queue of size 5
    std::cout << "--- Initializing Queue (Size 5) ---\n";
    circularQueue q(5);
    q.displayQueue();

    // 2. Add elements (Fill it partially)
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.displayQueue();

    // 3. Remove elements (Create space at the beginning of the array)
    q.deQueue(); // Removes 10
    q.deQueue(); // Removes 20
    q.displayQueue();

    // 4. Add more elements to force the "Wrap Around"
    // Since we removed 2 items, we have space. 
    // 60 should go to the end, 70 should wrap around to index 0.
    q.enQueue(50);
    q.enQueue(60); 
    q.enQueue(70); // This wraps to the start!
    q.displayQueue();

    // 5. Try to add to a full queue
    q.enQueue(80); // Should fail
    
    // 6. Check Front and Rear
    std::cout << "Front item: " << q.Front() << "\n"; // Should be 30
    std::cout << "Rear item: "  << q.Rear() << "\n";  // Should be 70

    return 0;
}