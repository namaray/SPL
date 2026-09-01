#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1) printf("Z");   // top and bottom line
            else if (j == n - 1 - i)  printf("Z");   // the diagonal
            else                      printf(" ");
        }
        printf("\n");
    }
    return 0;
}
