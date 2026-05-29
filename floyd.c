#include <stdio.h>
#include <time.h>

#define INF 999

void floydWarshall(int graph[][20], int n) {

    int dist[20][20];

    // Copy graph into distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd's algorithm
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] =
                    dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    printf("\nAll Pair Shortest Path Matrix:\n");

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }

        printf("\n");
    }
}


int main() {

    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[20][20];

    printf("Enter adjacency matrix:\n");
    printf("(Use %d for infinity)\n", INF);

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);
        }
    }

    clock_t start = clock();

    floydWarshall(graph, n);

    clock_t end = clock();

    double time_taken =
    (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n",
           time_taken);

    return 0;
}
