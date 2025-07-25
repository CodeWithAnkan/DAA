#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("students.dat", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int num, count[10001] = {0};  
    int totalNumbers = 0;
    
    while (fscanf(fp, "%d", &num) == 1) {
        count[num]++;
        totalNumbers++;
    }

    int duplicates = 0, maxFreq = 0, mostFreqElem = 0;
    
    for (int i = 1; i <= 10000; i++) {
        if (count[i] > 1) {
            duplicates++;
        }
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            mostFreqElem = i;
        }
    }

    printf("Total numbers processed: %d\n", totalNumbers);
    printf("Total duplicate elements: %d\n", duplicates);
    printf("Most frequent element: %d (appears %d times)\n", mostFreqElem, maxFreq);
    
    fclose(fp);
    return 0;
}