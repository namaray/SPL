#include <stdio.h>

int largest(int a[], int n) {
    if (n == 1) return a[0];            // one element left
    int rest = largest(a, n - 1);
    if (a[n - 1] > rest) return a[n - 1];
    return rest;
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d\n", largest(a, n));
    return 0;
}
