// Implement merge sort without using recursion and without using any stack. You need to use only two 
// nested loops to complete your task. You do not need any stack. You do not need dividing and 
// conquering the task. This will be a bottom-up approach of solving the problem. 

#include <stdio.h>
#include <stdlib.h>

// Merge function
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Bottom-up Merge Sort (no recursion, no stack)
void mergeSortIterative(int arr[], int n) {
    int curr_size;   // Current size of subarrays to merge (1, 2, 4, 8, ...)
    int left_start;  // Starting index of left subarray

    // Merge subarrays in bottom-up manner
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) 
    {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) 
        {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1)
                                ? (left_start + 2 * curr_size - 1)
                                : (n - 1);

            if (mid < right_end)  // Only merge if two halves exist
                merge(arr, left_start, mid, right_end);
        }
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array:\n");
    printArray(arr, n);

    mergeSortIterative(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
