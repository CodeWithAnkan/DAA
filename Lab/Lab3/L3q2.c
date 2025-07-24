#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

int partition(int arr[], int low, int high, int *posDiff) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;

    *posDiff = abs(((i+1) - low) - (high - (i+1)));
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *maxDiff) {
    if (low < high) {
        int diff = 0;
        int pi = partition(arr, low, high, &diff);
        if (diff > *maxDiff) *maxDiff = diff;

        quickSort(arr, low, pi - 1, maxDiff);
        quickSort(arr, pi + 1, high, maxDiff);
    }
}

int main() {
    FILE *fp = fopen("inRand.dat", "r");
    FILE *fo = fopen("outQuickRand.dat", "w");
    int arr[1000], n = 0;

    while (fscanf(fp, "%d", &arr[n]) != EOF) n++;

    int maxDiff = 0;
    clock_t start = clock();
    quickSort(arr, 0, n - 1, &maxDiff);
    clock_t end = clock();

    for (int i = 0; i < n; i++) fprintf(fo, "%d ", arr[i]);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;

    printf("Sorted successfully.\\n");
    printf("Number of comparisons: %d\\n", comparisons);
    printf("Execution time (ns): %.0lf\\n", time_taken);
    printf("Partitioning scenario: %s-case\\n", maxDiff > n/2 ? "Worst" : "Best");

    fclose(fp);
    fclose(fo);
    return 0;
}
