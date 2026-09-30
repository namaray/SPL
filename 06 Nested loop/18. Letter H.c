//011222131
#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > 0) printf(" ");        // a space between columns
            if (j == 0 || j == n - 1 || i == n / 2) printf("H");
            else                                    printf(" ");
        }
        printf("\n");
    }
    return 0;
}
