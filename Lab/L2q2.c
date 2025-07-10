#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        printf("File error.\\n");
        return 1;
    }

    int a, b;
    while (fscanf(input, "%d %d", &a, &b) == 2) {
        fprintf(output, "The GCD of %d and %d is %d\\n", a, b, gcd(a, b));
    }

    fclose(input);
    fclose(output);
    return 0;
}