#include <stdio.h>

#define SIZE 5
int counter[SIZE];
int high = -1;
int total_cost = 0;  // Track cumulative cost across all operations

// Increment operation: flip bits until we find a 0
int increment() {
    int cost = 0;
    int i = 0;
    
    // Flip all 1s to 0s until we find a 0
    while (i <= high && counter[i] == 1) {
        counter[i] = 0;
        cost++;  // Cost for flipping bit from 1 to 0
        i++;
    }
    
    // Set the first 0 to 1
    if (i < SIZE) {
        counter[i] = 1;
        cost++;  // Cost for flipping bit from 0 to 1
        if (i > high) high = i;  // Update high pointer
    }
    
    return cost;
}

// Reset operation: set all bits to 0 using the high pointer
int reset() {
    int cost = 0;
    
    // Only reset bits up to the high pointer
    for (int i = 0; i <= high; i++) {
        if (counter[i] == 1) {
            counter[i] = 0;
            cost++;  // Cost for flipping bit from 1 to 0
        }
    }
    high = -1;  // Reset high pointer
    
    return cost;
}

// Print current state in table format
void printRow(const char* operation) {
    // Print bits from Bit 4 to Bit 0
    printf("  %d\t  %d\t  %d\t  %d\t  %d\t%-12s\t%d\n", 
           counter[4], counter[3], counter[2], counter[1], counter[0],
           operation, total_cost);
}

void printHeader() {
    printf("Bit 4\tBit 3\tBit 2\tBit 1\tBit 0\tOperation\tCost\n");
    printf("=====\t=====\t=====\t=====\t=====\t============\t====\n");
}

int main() {
    printHeader();
    
    // Initial state
    printRow("Initial");
    
    // First increment: 00000 -> 00001
    total_cost += increment();
    printRow("Increment");
    
    // Second increment: 00001 -> 00010
    total_cost += increment();
    printRow("Increment");
    
    // First reset: 00010 -> 00000
    total_cost += reset();
    printRow("Reset");
    
    // Third increment: 00000 -> 00001
    total_cost += increment();
    printRow("Increment");
    
    // Second reset: 00001 -> 00000
    total_cost += reset();
    printRow("Reset");
    
    return 0;
}