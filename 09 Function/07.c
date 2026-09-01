#include <stdio.h>

int sum(int a[], int n) {
    int i, s = 0;
    for (i = 0; i < n; i++) s += a[i];
    return s;
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int result = sum(a, n);
    printf("Sum In Function: %d\n", result);
    printf("Sum In Main: %d\n", result);
    return 0;
}
