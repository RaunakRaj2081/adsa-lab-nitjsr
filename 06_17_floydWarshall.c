// Implement dynamic programming algorithm of Floyd–Warshall algorithm for the shortest path problem. 
#include <stdio.h>
#define INF 99999

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int dist[V][V];
    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            scanf("%d", &dist[i][j]);

    // Floyd-Warshall DP
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distance matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
