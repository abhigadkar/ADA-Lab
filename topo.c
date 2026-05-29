#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int main() {
    int n, e, i, j;
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Add all sources to queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;
    int topo[MAX];

    while(front < rear) {
        int u = queue[front++];
        topo[count++] = u;

        for(i = 0; i < n; i++) {
            if(adj[u][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Check for cycle
    if(count != n) {
        printf("Graph is NOT a DAG (cycle detected)\n");
    } else {
        printf("Topological Order:\n");
        for(i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}
