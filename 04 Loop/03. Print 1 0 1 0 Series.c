//011222131
#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
        printf("1");
        }
        else {
        printf("0");
        }
        if (i < n) printf(", ");
    }
    printf("\n");
    return 0;
}
