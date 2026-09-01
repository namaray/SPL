#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    // row i starts at i and prints i numbers
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++)
            printf("%d", i + j);
        printf("\n");
    }
    return 0;
}
