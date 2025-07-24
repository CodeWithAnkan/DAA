#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--; // 0-based index
        edges[i].v--;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(Edge), compare);

    int total = 0;
    printf("Edge\tCost\n");
    for (int i = 0, count = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            printf("%d--%d\t%d\n", u + 1, v + 1, w);
            unionSet(u, v);
            total += w;
            count++;
        }
    }

    printf("Total Weight of MST: %d\n", total);
    return 0;
}