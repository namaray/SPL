//011222131
#include <stdio.h>

int main() {
    int n, i, a = 1, b = 1, t;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d", a);
        if (i < n) printf(", ");
        t = a + b;
        a = b;
        b = t;
    }
    printf("\n");
    return 0;
}
