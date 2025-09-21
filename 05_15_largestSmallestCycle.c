// Write a function to identify the largest and smallest cycles in a given directed or undirected graph. 
#include <stdio.h>
#include <string.h>

#define MAX 20
int graph[MAX][MAX], visited[MAX], path[MAX];
int n, minCycle = 1e9, maxCycle = -1;

void dfs(int start, int u, int depth) {
    visited[u] = 1;
    path[depth] = u;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v])
                dfs(start, v, depth + 1);
            else if (v == start && depth >= 2) { // found cycle
                int len = depth + 1;
                if (len < minCycle) minCycle = len;
                if (len > maxCycle) maxCycle = len;
            }
        }
    }
    visited[u] = 0; // backtrack
}

void findCycles() {
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i, 0);
    }
    if (maxCycle == -1)
        printf("No cycles found.\n");
    else
        printf("Smallest Cycle Length = %d\nLargest Cycle Length = %d\n", minCycle, maxCycle);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    findCycles();
    return 0;
}

