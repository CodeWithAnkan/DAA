#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("inDup.dat", "r");
    int n, arr[1000], count[1000] = {0};
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    int duplicates = 0, maxFreq = 0, mostFreqElem;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 0; i < 1000; i++) {
        if (count[i] > 1)
            duplicates++;
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            mostFreqElem = i;
        }
    }

    printf("Total duplicate elements: %d\\n", duplicates);
    printf("Most frequent element: %d\\n", mostFreqElem);
    fclose(fp);
    return 0;