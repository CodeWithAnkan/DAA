#include <stdio.h>
#include <string.h>

void printFit(int fit[], int n) {
    for (int i = n - 1; i >= 0; i--)
        printf("%d", fit[i]);
    printf("\n");
}

void incrementFit(int fit[], int *n) {
    int i = 0;
    while (i < *n && fit[i]) {
        fit[i] = 0;
        i++;
    }
    if (i == *n)
        fit[(*n)++] = 1;
    else
        fit[i] = 1;
}

void decrementFit(int fit[], int *n) {
    int i = 0;
    while (i < *n && !fit[i]) {
        fit[i] = 1;
        i++;
    }
    if (i < *n)
        fit[i] = 0;
    while (*n > 0 && !fit[*n - 1]) (*n)--;
}

int main() {
    int fit[100] = {1, 1, 1, 0, 1, 0}; // 101110 (F6+F4+F3+F2=14)
    int n = 6;

    printf("Original Fitstring: ");
    printFit(fit, n);

    incrementFit(fit, &n);
    printf("After Increment: ");
    printFit(fit, n);

    decrementFit(fit, &n);
    printf("After Decrement: ");
    printFit(fit, n);

    return 0;
}