// Implement the 15-puzzle problem using the branch and bound method. 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

// Direction moves: up, down, left, right
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, 1, -1};

// A state of the puzzle
struct Node {
    int mat[N][N];
    int x, y;     // Blank tile position
    int level;    // Depth of the node
    int cost;     // Cost = level + heuristic
    struct Node* parent;
};

// Create new node by moving blank
struct Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, struct Node* parent) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            node->mat[i][j] = mat[i][j];
    
    int temp = node->mat[x][y];
    node->mat[x][y] = node->mat[newX][newY];
    node->mat[newX][newY] = temp;

    node->x = newX;
    node->y = newY;
    node->level = level;
    node->parent = parent;
    return node;
}

// Manhattan Distance heuristic
int calculateCost(int mat[N][N], int final[N][N]) {
    int cost = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(mat[i][j] && mat[i][j] != final[i][j]) {
                int val = mat[i][j];
                int targetX = (val-1)/N;
                int targetY = (val-1)%N;
                cost += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return cost;
}

// Print matrix
void printMatrix(int mat[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(mat[i][j] == 0) printf("   ");
            else printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Simple priority queue (array-based, for clarity)
#define MAX 10000
struct Node* pq[MAX];
int pqSize = 0;

void push(struct Node* node) {
    pq[pqSize++] = node;
}

struct Node* pop() {
    int best = 0;
    for(int i=1;i<pqSize;i++) {
        if(pq[i]->cost < pq[best]->cost)
            best = i;
    }
    struct Node* res = pq[best];
    for(int i=best;i<pqSize-1;i++)
        pq[i] = pq[i+1];
    pqSize--;
    return res;
}

int isSafe(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<N);
}

// Solve puzzle
void solve(int initial[N][N], int x, int y, int final[N][N]) {
    struct Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);
    push(root);

    while(pqSize) {
        struct Node* min = pop();

        if(min->cost - min->level == 0) { // Reached goal
            printf("Solved in %d moves:\n\n", min->level);
            while(min) {
                printMatrix(min->mat);
                min = min->parent;
            }
            return;
        }

        for(int i=0;i<4;i++) {
            int newX = min->x + row[i];
            int newY = min->y + col[i];
            if(isSafe(newX, newY)) {
                struct Node* child = newNode(min->mat, min->x, min->y, newX, newY, min->level+1, min);
                child->cost = child->level + calculateCost(child->mat, final);
                push(child);
            }
        }
    }
}

int main() {
    int initial[N][N], final[N][N];
    int x, y;

    printf("Enter initial state (use 0 for blank):\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            scanf("%d", &initial[i][j]);
            if(initial[i][j] == 0) { x=i; y=j; }
        }

    printf("Enter final state (use 0 for blank):\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &final[i][j]);

    solve(initial, x, y, final);
    return 0;
}
