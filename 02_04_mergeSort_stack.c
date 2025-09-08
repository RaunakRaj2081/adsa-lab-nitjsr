// Implement merge sort without using recursion. You may use a stack data structure in order to keep track 
// of dividing and conquering the task. This will be a top-down approach of solving the problem.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for stack frame
typedef struct {
    int left;
    int right;
    int stage; // 0 = divide, 1 = merge
} Frame;

int stackTop = -1;
Frame stack[MAX];

// Push function
void push(int left, int right, int stage) 
{
    stack[++stackTop].left = left;
    stack[stackTop].right = right;
    stack[stackTop].stage = stage;
}

// Pop function
Frame pop() {
    return stack[stackTop--];
}

// Merge function
void merge(int arr[], int l, int m, int r) 
{
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

// Iterative Merge Sort using stack
void mergeSortIterative(int arr[], int n) 
{
    push(0, n - 1, 0);

    while (stackTop != -1) {
        Frame curr = pop();

        int l = curr.left;
        int r = curr.right;

        if (curr.stage == 0 && l < r) {
            int m = (l + r) / 2;

            // Push merge step for this range
            push(l, r, 1);

            // Push right half (divide first)
            push(m + 1, r, 0);

            // Push left half (divide next)
            push(l, m, 0);
        } 
        else if (curr.stage == 1) {
            int m = (l + r) / 2;
            merge(arr, l, m, r);
        }
    }
}

// Print array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main
int main() {
    int n, arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

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
