#include <stdio.h>

int main() {
    int m, n, i, j, k, a[50][50];
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    // give every cell a single number 0,1,2,... in row order.
    // a cell is a duplicate if the same value appeared at a smaller number.
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            int cur = i * n + j;                // this cell's order number
            int dup = 0;
            for (k = 0; k < cur; k++) {          // all earlier cells
                int r = k / n, c = k % n;
                if (a[r][c] == a[i][j]) dup = 1;
            }
            if (dup) a[i][j] = -1;
        }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
