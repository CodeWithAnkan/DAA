#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n, double *time_taken);
void insertionSort(int arr[], int n, double *time_taken);
void mergeSort(int arr[], int l, int r, double *time_taken);
void merge(int arr[], int l, int m, int r);
void copyArray(int source[], int dest[], int n);

int main() {
    int choice, n, i;
    clock_t start, end;
    double time_taken;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    
    do {
        printf("\n--- Sorting Algorithm Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        copyArray(arr, temp, n);
        
        switch (choice) {
            case 1:
                printf("Original Array: ");
                printArray(temp, n);
                break;
                
            case 2:
                printf("\nSorting using Bubble Sort...\n");
                bubbleSort(temp, n, &time_taken);
                printf("Time taken: %f seconds\n", time_taken);
                printf("Sorted Array: ");
                printArray(temp, n);
                break;
                
            case 3:
                printf("\nSorting using Insertion Sort...\n");
                insertionSort(temp, n, &time_taken);
                printf("Time taken: %f seconds\n", time_taken);
                printf("Sorted Array: ");
                printArray(temp, n);
                break;
                
            case 4:
                printf("\nSorting using Merge Sort...\n");
                start = clock();
                mergeSort(temp, 0, n - 1, &time_taken);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time taken: %f seconds\n", time_taken);
                printf("Sorted Array: ");
                printArray(temp, n);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    free(arr);
    free(temp);
    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n && i < 20; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 20) {
        printf("... (and %d more)", n - 20);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n, double *time_taken) {
    int i, j, temp;
    clock_t start, end;
    
    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    *time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void insertionSort(int arr[], int n, double *time_taken) {
    int i, key, j;
    clock_t start, end;
    
    start = clock();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    end = clock();
    *time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void mergeSort(int arr[], int l, int r, double *time_taken) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, time_taken);
        mergeSort(arr, m + 1, r, time_taken);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}