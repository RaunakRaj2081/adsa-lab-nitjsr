// Implement the 0/1 knapsack problem using the backtracking method. 
#include <stdio.h>

int n, W;
int wt[20], val[20];
int maxProfit = 0;

void knapsack(int i, int curWeight, int curValue) {
    if(i == n) {  
        if(curValue > maxProfit)
            maxProfit = curValue;
        return;
    }

    // Exclude item i
    knapsack(i+1, curWeight, curValue);

    // Include item i (if weight allows)
    if(curWeight + wt[i] <= W)
        knapsack(i+1, curWeight + wt[i], curValue + val[i]);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values of items:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(0, 0, 0);

    printf("Maximum value in Knapsack = %d\n", maxProfit);
    return 0;
}
