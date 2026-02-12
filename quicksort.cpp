// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <chrono>
// int partition(std::vector<int>& A, int l, int h) {
//     int pivot = A[l];
//     int i = l;
//     int j = h;

//     while (i < j) {
//         // FIX 1: Use 'while' instead of 'do-while' to avoid skipping elements.
//         // FIX 2: Add boundary check (i < h) to prevent going out of bounds.
//         while (i < h && A[i] <= pivot) {
//             i++;
//         }
        
//         // FIX 3: Simply check A[j] > pivot. 
//         // We don't need 'j > l' check here because A[l] (the pivot) acts as a stopper.
//         while (A[j] > pivot) {
//             j--;
//         }

//         if (i < j) {
//             std::swap(A[i], A[j]);
//         }
//     }
    
//     // FIX 4: These lines must be OUTSIDE the main while(i<j) loop
//     std::swap(A[l], A[j]);
//     return j;
// }

// void quickSort(std::vector<int>& A, int l, int h) {
//     if (l < h) {
//         int j = partition(A, l, h);
        
//         // FIX 5: Since pivot is at 'j', we sort (l to j-1) and (j+1 to h)
//         quickSort(A, l, j - 1);
//         quickSort(A, j + 1, h);
//     }
// }

// int main() {
//     std::vector<int> A = {10, 31, 2, 43, 22, 12, 21, 8, 9, 4, 18};
//     int n = A.size();

//     std::cout << "Original: ";
//     for (int x : A) std::cout << x << " ";
//     std::cout << "\n";

//     quickSort(A, 0, n - 1);

//     std::cout << "Sorted:   ";
//     for (int x : A) std::cout << x << " ";
//     std::cout << "\n";
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Required for timing

int partition(std::vector<int>& A, int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (i < h && A[i] <= pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i < j) {
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[l], A[j]);
    return j;
}

void quickSort(std::vector<int>& A, int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j + 1, h);
    }
}

int main() {
    std::vector<int> A = {10, 31, 2, 43, 22, 12, 21, 8, 9, 4, 18};
    int n = A.size();

    std::cout << "Original: ";
    for (int x : A) std::cout << x << " ";
    std::cout << "\n";

    // --- START TIMER ---
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(A, 0, n - 1);

    // --- STOP TIMER ---
    auto stop = std::chrono::high_resolution_clock::now();

    // --- CALCULATE DURATION ---
    // Using nanoseconds because the array is small. 
    // For large arrays, use microseconds or milliseconds.
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Sorted:   ";
    for (int x : A) std::cout << x << " ";
    std::cout << "\n\n";

    std::cout << "Time taken: " << duration.count() << " nanoseconds" << std::endl;

    return 0;
}