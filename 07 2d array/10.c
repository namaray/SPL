//011222131
#include <stdio.h>

/* Adds the boxed positions: the middle row, the middle column, and half of
   each edge (top row on the left, right column at the top, bottom row on the
   right, left column at the bottom). Together they make a pinwheel shape. */
int main() {
    int n, i, j, a[50][50], sum = 0, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    m = n / 2;                          /* the middle row and column */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == m || j == m ||
                (i == 0 && j <= m) || (j == n - 1 && i <= m) ||
                (i == n - 1 && j >= m) || (j == 0 && i >= m))
                sum += a[i][j];

    printf("%d\n", sum);
    return 0;
}
