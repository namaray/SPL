#include <stdio.h>

long factorial(int n) {
    long f = 1;
    int i;
    for (i = 1; i <= n; i++) f *= i;
    return f;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%ld\n", factorial(n));
    return 0;
}
