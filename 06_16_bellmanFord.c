// Implement Bellman Ford algorithm for the shortest path problem. 
#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];
    printf("Enter edges (u v w):\n");
    for(int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[V];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V-1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative cycle
    for(int j = 0; j < E; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }

    printf("Vertex   Distance from Source\n");
    for(int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);

    return 0;
}
