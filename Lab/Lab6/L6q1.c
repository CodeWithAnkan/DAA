#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Priority Queue (Min-Heap) structure
typedef struct {
    int vertex;
    int key;
} PQNode;

typedef struct {
    PQNode arr[MAX_VERTICES];
    int size;
} PriorityQueue;

// Function to swap two nodes
void swap(PQNode* a, PQNode* b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for min-heap
void minHeapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->arr[left].key < pq->arr[smallest].key)
        smallest = left;
    if (right < pq->size && pq->arr[right].key < pq->arr[smallest].key)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->arr[smallest], &pq->arr[idx]);
        minHeapify(pq, smallest);
    }
}

// Extract minimum from priority queue
PQNode extractMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        PQNode empty = {-1, INT_MAX};
        return empty;
    }
    if (pq->size == 1) {
        pq->size--;
        return pq->arr[0];
    }

    PQNode root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return root;
}

// Decrease key in priority queue (for updating distances)
void decreaseKey(PriorityQueue* pq, int vertex, int newKey) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (pq->arr[i].vertex == vertex) {
            pq->arr[i].key = newKey;
            break;
        }
    }
    // Bubble up
    while (i > 0 && pq->arr[(i-1)/2].key > pq->arr[i].key) {
        swap(&pq->arr[i], &pq->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Initialize priority queue with all vertices
void initPQ(PriorityQueue* pq, int n, int start) {
    pq->size = n;
    for (int i = 0; i < n; i++) {
        pq->arr[i].vertex = i;
        pq->arr[i].key = (i == start) ? 0 : INT_MAX;
    }
    // Build min-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(pq, i);
}

// Function to print the MST adjacency matrix
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int mstMatrix[MAX_VERTICES][MAX_VERTICES];
    int totalCost = 0;

    // Initialize MST matrix with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mstMatrix[i][j] = 0;
        }
    }

    // Set MST edges in the matrix
    for (int i = 1; i < n; i++) {
        int u = parent[i];
        int v = i;
        if (u != -1) {
            mstMatrix[u][v] = graph[u][v];
            mstMatrix[v][u] = graph[u][v];  // Since undirected
            totalCost += graph[u][v];
        }
    }

    // Print MST adjacency matrix
    printf("MST Cost Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mstMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

// Prim's algorithm using priority queue
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    int parent[MAX_VERTICES];
    int inMST[MAX_VERTICES];
    PriorityQueue pq;

    // Initialize
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        inMST[i] = 0;
    }

    initPQ(&pq, n, start);

    while (pq.size > 0) {
        PQNode minNode = extractMin(&pq);
        int u = minNode.vertex;
        inMST[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < pq.arr[v].key) {
                parent[v] = u;
                decreaseKey(&pq, v, graph[u][v]);
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    FILE* file = fopen("inUnAdjMat.dat", "r");
    if (!file) {
        printf("Error opening file inUnAdjMat.dat\n");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(file, "%d", &graph[i][j]) != 1) {
                printf("Error reading matrix from file\n");
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);

    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &start);
    start--;  // Convert to 0-based for internal use

    primMST(graph, n, start);
    return 0;
}
