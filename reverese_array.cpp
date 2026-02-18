#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to reverse vector in-place
void reverseArray(std::vector<int>& arr) {
    // int start = 0;
    // int end = arr.size() - 1;

    // while (start < end) {
    //     // --- MANUAL SWAP START ---
    //     int temp = arr[start];  // 1. Store the value at start
    //     arr[start] = arr[end];  // 2. Overwrite start with value at end
    //     arr[end] = temp;        // 3. Put the stored value into end
    //     // --- MANUAL SWAP END ---

    //     start++;
    //     end--;
    // }

    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        // Swap elements at start and end
        std::swap(arr[start], arr[end]);

        // Move pointers towards the center
        start++;
        end--;
    }
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    std::cout << "Original: ";
    printArray(numbers);

    reverseArray(numbers);

    std::cout << "Reversed: ";
    printArray(numbers);

    return 0;
}