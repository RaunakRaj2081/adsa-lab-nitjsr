#include <stdio.h>
#include <stdlib.h>

void addressSort(int arr[], int n) 
{
    int min = arr[0], max = arr[0];

    // Find min and max
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *aux = (int*)calloc(range, sizeof(int)); // auxiliary array initialized to 0

    // Count occurrences
    for (int i = 0; i < n; i++)
        aux[arr[i]-min]++;

    // Reconstruct sorted array
    int idx = 0;
    for (int i = 0; i < range; i++) 
    {
        while (aux[i] > 0) 
        {
            arr[idx++] = i + min;
            aux[i]--;
        }
    }

    free(aux);
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    addressSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
