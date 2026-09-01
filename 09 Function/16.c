#include <stdio.h>

void doubleArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) a[i] = a[i] * 2;
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    doubleArray(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
