#include <stdio.h>
#include <limits.h>

void printParenthesis(int s[20][20], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, p[20], m[20][20] = {0}, s[20][20] = {0};
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int row[20], col[20];
    for (int i = 1; i <= n; i++) {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &row[i], &col[i]);
        if (i > 1 && col[i-1] != row[i]) {
            printf("Dimension mismatch!\n");
            return 1;
        }
    }

    p[0] = row[1];
    for (int i = 1; i <= n; i++) {
        p[i] = col[i];
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%5d ", m[i][j]);
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%5d ", s[i][j]);
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printParenthesis(s, 1, n);
    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);
    return 0;
}