#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    FILE *fp = fopen("inRand.dat", "r");
    FILE *fo = fopen("outMergeRand.dat", "w");
    int arr[1000], n = 0;

    while (fscanf(fp, "%d", &arr[n]) != EOF) n++;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    for (int i = 0; i < n; i++) fprintf(fo, "%d ", arr[i]);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;

    printf("Sorted successfully.\\n");
    printf("Number of comparisons: %d\\n", comparisons);
    printf("Execution time (ns): %.0lf\\n", time_taken);

    fclose(fp);
    fclose(fo);
    return 0;
}
