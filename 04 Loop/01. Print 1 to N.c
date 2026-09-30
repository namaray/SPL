//011222131
#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) printf(", ");
    }
    printf("\n");
    return 0;
}
