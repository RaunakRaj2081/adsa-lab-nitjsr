//  Implement Kruskal’s algorithm for the minimum spanning tree problem
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xr = find(subsets, x);
    int yr = find(subsets, y);
    if (subsets[xr].rank < subsets[yr].rank)
        subsets[xr].parent = yr;
    else if (subsets[xr].rank > subsets[yr].rank)
        subsets[yr].parent = xr;
    else {
        subsets[yr].parent = xr;
        subsets[xr].rank++;
    }
}

int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void Kruskal(int V, int E, struct Edge edges[]) {
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), cmp);

    printf("Edge \tWeight\n");
    int e = 0, i = 0;
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.u);
        int y = find(subsets, next.v);

        if (x != y) {
            printf("%d - %d \t%d\n", next.u, next.v, next.w);
            Union(subsets, x, y);
            e++;
        }
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    Kruskal(V, E, edges);
    return 0;
}
