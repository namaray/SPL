#include <stdio.h>

int sum(int n) {
    if (n == 0) return 0;      // base case
    return n + sum(n - 1);     // recursive step
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
