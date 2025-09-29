// Implement the n-queens problem using the backtracking method.
#include <stdio.h>

int N;

// Check if placing queen at board[row][col] is safe
int isSafe(int board[N][N], int row, int col) {
    for(int i = 0; i < col; i++)
        if(board[row][i]) return 0;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j]) return 0;

    for(int i=row, j=col; i<N && j>=0; i++, j--)
        if(board[i][j]) return 0;

    return 1;
}

// Solve N-Queens recursively
int solveNQUtil(int board[N][N], int col) {
    if(col >= N) {
        // Print solution
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return 1;
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0; // backtrack
        }
    }
    return res;
}

int main() {
    printf("Enter value of N: ");
    scanf("%d", &N);

    int board[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            board[i][j] = 0;

    if(!solveNQUtil(board, 0))
        printf("No solution exists\n");

    return 0;
}
