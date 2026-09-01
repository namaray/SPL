#include <stdio.h>

int IsPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void GeneratePrime(int n) {
    int i, first = 1;
    printf("Prime less than %d:   ", n);
    for (i = 2; i < n; i++)
        if (IsPrime(i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    GeneratePrime(n);
    return 0;
}
