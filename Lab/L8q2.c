#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }

void printLCS(int L[101][101], char X[], char Y[], int m, int n) {
    char lcs[101];
    int i = m, j = n, k = 0;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[k++] = X[i - 1];
            i--; j--;
        } else if (L[i - 1][j] > L[i][j - 1]) i--;
        else j--;
    }
    lcs[k] = '\0';
    strrev(lcs);  // reverse the string to correct LCS
    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", k);
}

int main() {
    char X[101], Y[101];
    int L[101][101];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X), n = strlen(Y);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            L[i][j] = (i == 0 || j == 0) ? 0 :
                      (X[i - 1] == Y[j - 1]) ? 1 + L[i - 1][j - 1] :
                                               max(L[i - 1][j], L[i][j - 1]);

    printLCS(L, X, Y, m, n);
    return 0;
}