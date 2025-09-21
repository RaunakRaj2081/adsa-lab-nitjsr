//  Implement Prim’s algorithm for the minimum spanning tree problem.
#include <stdio.h>
#include <limits.h>

#define MAX 50

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], idx = v;
    return idx;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX], key[MAX], mstSet[MAX] = {0};

    for (int i = 0; i < n; i++) key[i] = INT_MAX;
    key[0] = 0; parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n, graph[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);
    return 0;
}