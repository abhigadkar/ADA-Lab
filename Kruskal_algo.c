#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

Edge edge[MAX], temp;

int parent[MAX];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, k, a, b, u, v, n, e;
    int mincost = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &e);

    printf("Enter edges (u v w):\n");
    for(i = 0; i < e; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    // Sorting edges by weight
    for(i = 0; i < e - 1; i++) {
        for(j = 0; j < e - i - 1; j++) {
            if(edge[j].w > edge[j + 1].w) {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in MST:\n");

    for(i = 0; i < e; i++) {
        u = find(edge[i].u);
        v = find(edge[i].v);

        if(uni(u, v)) {
            printf("%d -- %d == %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);

            mincost += edge[i].w;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
