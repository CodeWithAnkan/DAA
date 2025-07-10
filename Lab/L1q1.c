#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *fp = fopen("inArray.dat", "r");
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int second_smallest = INT_MAX, second_largest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            second_smallest = arr[i];
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != arr[n - 1]) {
            second_largest = arr[i];
            break;
        }
    }

    printf("Second Smallest: %d\\n", second_smallest);
    printf("Second Largest: %d\\n", second_largest);
    free(arr);
    fclose(fp);
    return 0;
}