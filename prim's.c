
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print MST
void printMST(int parent[], int graph, int V) {
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim's Algorithm
void primMST(int graph, int V) {
    int *parent = (int *)malloc(V * sizeof(int));
    int *key = (int *)malloc(V * sizeof(int));
    int *mstSet = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);

    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph = (int )malloc(V * sizeof(int ));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        // Undirected graph
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(graph, V);

    // Free memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
