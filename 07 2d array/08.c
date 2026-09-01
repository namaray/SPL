#include <stdio.h>

int main() {
    int m, n, i, j, a[50][50];
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    int max = a[0][0], maxi = 0, maxj = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > max) { max = a[i][j]; maxi = i; maxj = j; }

    printf("Max: %d\n", max);
    printf("Location: [%d][%d]\n", maxi, maxj);
    return 0;
}
