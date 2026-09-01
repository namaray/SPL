#include <stdio.h>

/* NOTE: the exact "boxed" positions were shown as an image in the original
   document and could not be extracted. This uses the border + center as a
   placeholder pattern -- replace the condition with your actual pattern. */
int main() {
    int n, i, j, a[50][50], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1 ||
                (i == n / 2 && j == n / 2))
                sum += a[i][j];

    printf("%d\n", sum);
    return 0;
}
