#include <stdio.h>

int main() {
    int n, i, j, mid, d;
    scanf("%d", &n);
    mid = n / 2;

    for (i = 0; i < n; i++) {
        d = (i <= mid) ? i : n - 1 - i;   // distance from middle row
        for (j = 0; j < n; j++) {
            if (i == mid)                              printf("$");   // middle full row
            else if (j == mid || j == mid - d || j == mid + d) printf("$");
            else                                       printf("_");
        }
        printf("\n");
    }
    return 0;
}
