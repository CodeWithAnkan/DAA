#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // dynamic array
    int maxElement = 0;

    // Taking array input and finding maximum element
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Now create hash array dynamically based on maximum element
    int *hash = (int *)malloc((maxElement + 1) * sizeof(int));

    // Initialize hash array with 0
    for (int i = 0; i <= maxElement; i++) {
        hash[i] = 0;
    }

    // Precompute
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int number;
        scanf("%d", &number);
        if (number <= maxElement) {
            printf("%d\n", hash[number]);
        } else {
            printf("0\n");
        }
    }

    // Free the dynamically allocated memory
    free(arr);
    free(hash);

    return 0;
}