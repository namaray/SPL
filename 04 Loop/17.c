//011222131
#include <stdio.h>

int main() {
    int n, i, isPrime = 1;
    scanf("%d", &n);

    if (n < 2) isPrime = 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            isPrime = 0;

    if (isPrime) printf("Prime\n");
    else         printf("Not prime\n");
    return 0;
}
