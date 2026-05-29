#include <stdio.h>

#define MAX 20
#define INF 9999


// Function to find minimum distance vertex
int findMinVertex(int dist[], int visited[], int n)
{
    int min = INF;
    int minIndex = -1;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}


// Function to perform Dijkstra
void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX], visited[MAX], parent[MAX];

    // Initialization
    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;


    // Main logic
    for(int count = 0; count < n - 1; count++)
    {
        int u = findMinVertex(dist, visited, n);

        visited[u] = 1;

        // Update adjacent vertices
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == 0 &&
               graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }


    // Display result
    printf("\nShortest distances from vertex %d:\n", source);

    for(int i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}


// Function to input graph
void readGraph(int graph[MAX][MAX], int n)
{
    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 if no edge)\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
}


int main()
{
    int n, source;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readGraph(graph, n);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
