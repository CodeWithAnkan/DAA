#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double insertion_sort(int arr[], int n) {
    clock_t start = clock();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    clock_t end = clock();
    return ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void generate_best_case_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generate_worst_case_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    double time_taken;
    
    srand(time(0));
    
    generate_random_array(arr, n);
    printf("\nAverage Case (Random Array):\n");
    printf("Before sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    
    time_taken = insertion_sort(arr, n);
    
    printf("After sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    printf("Time taken: %.6f milliseconds\n", time_taken);
    
    generate_best_case_array(arr, n);
    printf("\nBest Case (Already Sorted):\n");
    printf("Before sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    
    time_taken = insertion_sort(arr, n);
    
    printf("After sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    printf("Time taken: %.6f milliseconds\n", time_taken);
    
    generate_worst_case_array(arr, n);
    printf("\nWorst Case (Reverse Sorted):\n");
    printf("Before sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    
    time_taken = insertion_sort(arr, n);
    
    printf("After sorting (first 10 elements): ");
    print_array(arr, n > 10 ? 10 : n);
    printf("Time taken: %.6f milliseconds\n", time_taken);
    
    free(arr);
    return 0;
}
