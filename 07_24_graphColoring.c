// Implement the graph coloring problem using the backtracking method.
#include <stdio.h>
#define V 10   // max vertices

int graph[V][V], color[V], n, m;

int isSafe(int v, int c) {
    for(int i = 0; i < n; i++) {
        if(graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int solve(int v) {
    if(v == n) return 1; // all vertices colored

    for(int c = 1; c <= m; c++) {
        if(isSafe(v, c)) {
            color[v] = c;
            if(solve(v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(int i = 0; i < n; i++)
        color[i] = 0;

    if(solve(0)) {
        for(int i = 0; i < n; i++)
            printf("%d ", color[i]);
    } else {
        printf("No solution");
    }
    return 0;
}
