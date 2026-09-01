#include <stdio.h>

int main() {
    int n, i, p;
    scanf("%d", &n);

    int width = 2 * n - 1;           // each line is this wide
    for (i = 1; i <= n; i++) {
        for (p = 0; p < width; p++) {
            // "ring" value: 1 at the edges, growing to n at the centre
            int left = p + 1;
            int right = width - p;
            int v = (left < right) ? left : right;

            if (v <= i) printf("%d", v);
            else        printf("_");
        }
        printf("\n");
    }
    return 0;
}
