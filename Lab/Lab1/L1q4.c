#include <stdio.h>

void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int arr[], int n) {
    for (int i = n - 1; i > 0; i--)
        exchange(&arr[i], &arr[i - 1]);
}

int main() {
    int A[100], N, p2;
    printf("Enter size of array: ");
    scanf("%d", &N);
    printf("Enter elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Enter number of elements to rotate from front: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for (int i = 0; i < N; i++) printf("%d ", A[i]);

    rotate_right(A, p2);

    printf("\\nAfter ROTATE: ");
    for (int i = 0; i < N; i++) printf("%d ", A[i]);
    printf("\\n");
    return 0;
}