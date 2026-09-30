#include <stdio.h>

// Fibonacci starting from 0, 1, 1, 2 ...
int fib(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fib(i - 1) + fib(i - 2);
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("%d", fib(i));
        if (i < n - 1) printf(",");
    }
    printf("\n");
    return 0;
}
