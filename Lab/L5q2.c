#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

Node* createNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

typedef struct {
    Node* arr[100];
    int size;
} MinHeap;

void swap(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < h->size && h->arr[l]->freq < h->arr[smallest]->freq)
        smallest = l;
    if (r < h->size && h->arr[r]->freq < h->arr[smallest]->freq)
        smallest = r;
    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void insertHeap(MinHeap* h, Node* node) {
    int i = h->size++;
    h->arr[i] = node;
    while (i && h->arr[i]->freq < h->arr[(i-1)/2]->freq) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

Node* extractMin(MinHeap* h) {
    Node* temp = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h, 0);
    return temp;
}

Node* buildHuffman(char chars[], int freq[], int n) {
    MinHeap h = {.size = 0};
    for (int i = 0; i < n; i++)
        insertHeap(&h, createNode(chars[i], freq[i]));

    while (h.size > 1) {
        Node* left = extractMin(&h);
        Node* right = extractMin(&h);
        Node* merged = createNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        insertHeap(&h, merged);
    }
    return extractMin(&h);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        if (root->data != '$') printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    printf("Enter number of alphabets: ");
    scanf("%d", &n);
    char chars[n];
    int freq[n];
    printf("Enter the characters: ");
    for (int i = 0; i < n; i++) scanf(" %c", &chars[i]);
    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) scanf("%d", &freq[i]);

    Node* root = buildHuffman(chars, freq, n);
    printf("In-order traversal of the Huffman tree: ");
    inorder(root);
    printf("\n");
    return 0;
}