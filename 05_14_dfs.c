// Implement DFS algorithms for graphs. Your function should be able to identify all the tree edges, back 
// edges, forward edges and cross edges. 
#include <stdio.h>
#include <string.h>

#define MAX 50

int graph[MAX][MAX], visited[MAX], start[MAX], finish[MAX], time = 0, n;

void dfsVisit(int u) {
    visited[u] = 1;
    start[u] = ++time;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                printf("Tree Edge: %d -> %d\n", u, v);
                dfsVisit(v);
            } else if (!finish[v])
                printf("Back Edge: %d -> %d\n", u, v);
            else if (start[u] < start[v])
                printf("Forward Edge: %d -> %d\n", u, v);
            else
                printf("Cross Edge: %d -> %d\n", u, v);
        }
    }
    finish[u] = ++time;
}

void DFS() {
    memset(visited, 0, sizeof(visited));
    memset(start, 0, sizeof(start));
    memset(finish, 0, sizeof(finish));
    time = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfsVisit(i);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    DFS();
    return 0;
}

