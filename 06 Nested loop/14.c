#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i % 2 == 0)                 printf("*");   // full rows
            else if (j == 0 || j == n - 1)  printf("*");   // side walls
            else                            printf("_");
        }
        printf("\n");
    }
    return 0;
}
