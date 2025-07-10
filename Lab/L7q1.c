#include <stdio.h>
#include <limits.h>

#define V 100

int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] < min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) return;
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V], sptSet[V], parent[V];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX, sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Source\tDest\tCost\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", src + 1, i + 1);
        if (dist[i] == INT_MAX) {
            printf("INF\tNot reachable\n");
        } else {
            printf("%d\t%d", dist[i], src + 1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int graph[V][V], n, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (1-based index): ");
    scanf("%d", &src);

    dijkstra(graph, src - 1, n);
    return 0;
}