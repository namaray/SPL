//011222131
#include <stdio.h>

int main() {
    int n, i;
    long term = 0, sum = 0;
    scanf("%d", &n);

    // 1, 12, 123, 1234 ...  each term = previous*10 + i
    for (i = 1; i <= n; i++) {
        term = term * 10 + i;
        sum += term;
    }
    printf("%ld\n", sum);
    return 0;
}
