//011222131
#include <stdio.h>

/* Adds the boxed positions: every odd row and every odd column
   (rows and columns 1, 3, 5 ... counting from 0). This makes a # grid. */
int main() {
    int n, i, j, a[50][50], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i % 2 == 1 || j % 2 == 1)
                sum += a[i][j];

    printf("%d\n", sum);
    return 0;
}
