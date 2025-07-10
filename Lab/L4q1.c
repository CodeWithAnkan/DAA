#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age, height, weight;
} Person;

Person heap[100];
int heapSize = 0;
char mode[10]; // "min" or "max"

int compare(Person a, Person b) {
    if (strcmp(mode, "min") == 0)
        return a.age - b.age; // Min-heap by age
    else
        return b.weight - a.weight; // Max-heap by weight
}

void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < heapSize && compare(heap[l], heap[smallest]) < 0)
        smallest = l;
    if (r < heapSize && compare(heap[r], heap[smallest]) < 0)
        smallest = r;

    if (smallest != i) {
        Person temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(smallest);
    }
}

void buildHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapify(i);
}

void insert(Person p) {
    heap[heapSize] = p;
    int i = heapSize;
    heapSize++;
    while (i && compare(heap[i], heap[(i-1)/2]) < 0) {
        Person temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void deleteRoot() {
    if (heapSize == 0) return;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);
}

void displayHeap() {
    for (int i = 0; i < heapSize; i++)
        printf("%d %s %d %d %d\n", heap[i].id, heap[i].name, heap[i].age, heap[i].height, heap[i].weight);
}

int main() {
    FILE *fp = fopen("students.dat", "r");
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %s %d %d %d", &heap[i].id, heap[i].name, &heap[i].age, &heap[i].height, &heap[i].weight);
    }
    heapSize = n;
    fclose(fp);

    int choice;
    do {
        printf("\\nMAIN MENU (HEAP)\\n");
        printf("1. Display Students\\n2. Create Min-heap (age)\\n3. Create Max-heap (weight)\\n");
        printf("4. Display weight of youngest\\n5. Insert new person\\n6. Delete oldest\\n7. Exit\\n");
        scanf("%d", &choice);

        if (choice == 1) displayHeap();
        else if (choice == 2) {
            strcpy(mode, "min");
            buildHeap();
            printf("Min-heap created based on age.\\n");
        }
        else if (choice == 3) {
            strcpy(mode, "max");
            buildHeap();
            printf("Max-heap created based on weight.\\n");
        }
        else if (choice == 4) {
            if (heapSize > 0) {
                printf("Weight of youngest person: %d pounds\\n", heap[0].weight);
            }
        }
        else if (choice == 5) {
            Person p;
            printf("Enter ID Name Age Height Weight: ");
            scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
            insert(p);
        }
        else if (choice == 6) {
            deleteRoot();
            printf("Oldest person removed.\\n");
        }

    } while (choice != 7);

    return 0;
}