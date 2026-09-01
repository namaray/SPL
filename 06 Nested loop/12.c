#include <stdio.h>

int main() {
    int n, i, j, h;
    scanf("%d", &n);
    h = (n + 1) / 2;   // number of rows in the top half

    // top half (growing)
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++)     printf("_");
        for (j = 0; j < 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    // bottom half (shrinking)
    for (i = h - 1; i >= 1; i--) {
        for (j = 0; j < h - i; j++)     printf("_");
        for (j = 0; j < 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
