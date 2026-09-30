//011222131
#include <stdio.h>

int main() {
    int n, i;
    long f = 1;
    scanf("%d", &n);

    printf("%d! = ", n);
    for (i = n; i >= 1; i--) {
        printf("%d", i);
        if (i > 1) printf(" X ");
        f *= i;
    }
    printf(" = %ld\n", f);
    return 0;
}
