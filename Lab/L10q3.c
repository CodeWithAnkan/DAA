#include <stdio.h>

#define SIZE 5
int counter[SIZE];
int high = -1;

void increment() {
    int i = 0;
    while (i <= high && counter[i] == 1) {
        counter[i] = 0;
        i++;
    }
    if (i < SIZE) counter[i] = 1;
    if (i > high) high = i;
}

void reset() {
    for (int i = 0; i <= high; i++)
        counter[i] = 0;
    high = -1;
}

void printCounter() {
    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d ", counter[i]);
    printf("\n");
}

int main() {
    printf("Initial: ");
    printCounter();

    increment();
    printCounter();

    increment();
    printCounter();

    reset();
    printCounter();

    increment();
    printCounter();

    reset();
    printCounter();

    return 0;
}