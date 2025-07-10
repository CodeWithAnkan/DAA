#include <stdio.h>
#include <limits.h>

#define V 100
#define INF 99999

void printPath(int path[V][V], int u, int v) {
    if (path[u][v] == -1) return;
    printPath(path, u, path[u][v]);
    printf("-->%d", path[u][v] + 1);
    printPath(path, path[u][v], v);
}

void floydWarshall(int graph[V][V], int n, int src, int dest) {
    int dist[V][V], path[V][V];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            path[i][j] = (graph[i][j] != INF && i != j) ? i : -1;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }

    printf("Shortest path weight matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest Path from vertex %d to %d: ", src + 1, dest + 1);
    if (dist[src][dest] == INF) {
        printf("No path exists.\n");
    } else {
        printf("%d", src + 1);
        printPath(path, src, dest);
        printf("-->%d\n", dest + 1);
        printf("Path weight: %d\n", dist[src][dest]);
    }
}

int main() {
    int n, src, dest;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (use 99999 for INF):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }

    printf("Enter source and destination (1-based index): ");
    scanf("%d %d", &src, &dest);

    floydWarshall(graph, n, src - 1, dest - 1);
    return 0;
}