//011222131
#include <stdio.h>

int main() {
    int n, r, i;
    long num = 1, den = 1;
    scanf("%d %d", &n, &r);

    // nCr = (n * (n-1) * ... r terms) / r!
    for (i = 1; i <= r; i++) {
        num *= (n - i + 1);
        den *= i;
    }
    printf("%ld\n", num / den);
    return 0;
}
