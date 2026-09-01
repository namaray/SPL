#include <stdio.h>

void InputMatrix(int a[50][50], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void ShowMatrix(int a[50][50], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void ScalarMultiply(int a[50][50], int m, int n, int k) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            a[i][j] *= k;
}

int main() {
    int a[50][50], m, n, k;
    scanf("%d %d", &m, &n);
    InputMatrix(a, m, n);
    scanf("%d", &k);

    printf("Original:\n");
    ShowMatrix(a, m, n);
    ScalarMultiply(a, m, n, k);
    printf("Multiplied by %d:\n", k);
    ShowMatrix(a, m, n);
    return 0;
}
