#include <stdio.h>

int IsPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (IsPrime(n)) printf("Prime\n");
    else            printf("Not prime\n");
    return 0;
}
