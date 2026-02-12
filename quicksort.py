import time

def partition(A, l, h):
    pivot = A[l]
    i = l
    j = h

    while i < j:
        # Move i to the right
        while i < h and A[i] <= pivot:
            i += 1
        
        # Move j to the left
        while A[j] > pivot:
            j -= 1

        # Swap if pointers haven't crossed
        if i < j:
            A[i], A[j] = A[j], A[i]

    # Swap pivot into correct position
    A[l], A[j] = A[j], A[l]
    return j

def quick_sort(A, l, h):
    if l < h:
        j = partition(A, l, h)
        quick_sort(A, l, j - 1)
        quick_sort(A, j + 1, h)

if __name__ == "__main__":
    A = [10, 31, 2, 43, 22, 12, 21, 8, 9, 4, 18]
    n = len(A)

    print("Original:", A)

    # --- START TIMER ---
    # perf_counter_ns() returns time in nanoseconds
    start_time = time.perf_counter_ns()

    quick_sort(A, 0, n - 1)

    # --- STOP TIMER ---
    end_time = time.perf_counter_ns()

    # --- CALCULATE DURATION ---
    duration_ns = end_time - start_time
    # Convert to microseconds for readability (optional)
    duration_us = duration_ns / 1000.0 

    print("Sorted:  ", A)
    print(f"\nTime taken: {duration_ns} nanoseconds ({duration_us:.3f} microseconds)")