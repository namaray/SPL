#include <stdio.h>

void printReverse(int a[], int n) {
    int i;
    for (i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printReverse(a, n);
    return 0;
}
