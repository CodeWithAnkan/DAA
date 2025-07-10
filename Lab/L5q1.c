#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float profit, weight, ratio;
} Item;

void heapify(Item arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l].ratio > arr[largest].ratio)
        largest = l;
    if (r < n && arr[r].ratio > arr[largest].ratio)
        largest = r;

    if (largest != i) {
        Item temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(Item arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        Item temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    float capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i+1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].id = i + 1;
        items[i].ratio = items[i].profit / items[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    heapSort(items, n);

    float maxProfit = 0.0;
    printf("\nItem No\tProfit\tWeight\tAmount Taken\n");
    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;
        float take = (items[i].weight <= capacity) ? 1.0 : capacity / items[i].weight;
        printf("%d\t%.2f\t%.2f\t%.6f\n", items[i].id, items[i].profit, items[i].weight, take);
        maxProfit += take * items[i].profit;
        capacity -= take * items[i].weight;
    }

    printf("Maximum Profit: %.6f\n", maxProfit);
    return 0;
}