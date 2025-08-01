#include <stdio.h>
#include <stdlib.h>

void decToBin(int num, FILE *dest) {
    int original = num;
    char bin[17] = {0};
    for (int i = 15; i >= 0; i--) {
        bin[i] = (num % 2) + '0';
        num /= 2;
    }
    fprintf(dest, "The binary equivalent of %d is %s\n", original, bin);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s n input_file output_file\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *input = fopen(argv[2], "r");
    FILE *output = fopen(argv[3], "w");

    if (!input || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    int num;
    for (int i = 0; i < n && fscanf(input, "%d", &num) == 1; i++) {
        decToBin(num, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}