#include <stdio.h>

int main() {
    int arr[100], prefixSum[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", prefixSum[i]);
    printf("\\n");
    return 0;
}