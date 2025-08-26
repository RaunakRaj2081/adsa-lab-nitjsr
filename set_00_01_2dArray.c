/*
write a c program that creates a 2D array initialized with 0's and allows the user to input a row , column
and  values to insert into the array.
*/ 

#include <stdio.h>
int main()
 {
    int rows, cols;
    
    // Ask for size of the array
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // Initialize with 0
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
         {
            arr[i][j] = 0;
        }
    }

    // Take input for each row and column
    printf("\nEnter values for the array:\n");
    for (int i = 0; i < rows; i++)
     {
        for (int j = 0; j < cols; j++) 
        {
            printf("Enter value for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the array
    printf("\nFinal Array:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}