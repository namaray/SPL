#include <stdio.h>

/* Sum of first row, last row and both diagonals (each cell counted once). */
int main() {
    int n, i, j, a[50][50], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == 0 || i == n - 1 || i == j || i + j == n - 1)
                sum += a[i][j];

    printf("%d\n", sum);
    return 0;
}
