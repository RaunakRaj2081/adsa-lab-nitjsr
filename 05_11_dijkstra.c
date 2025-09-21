// Implement Dijkstra’s algorithm for the shortest path problem. 
#include <stdio.h>
#include <limits.h>

#define MAX 50

int minDist(int dist[], int vis[], int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++)
        if (!vis[i] && dist[i] < min)
            min = dist[i], idx = i;
    return idx;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX], vis[MAX] = {0};
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int c = 0; c < n - 1; c++) {
        int u = minDist(dist, vis, n);
        vis[u] = 1;
        for (int v = 0; v < n; v++)
            if (!vis[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex  Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int n, graph[MAX][MAX], src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);
    return 0;
}
