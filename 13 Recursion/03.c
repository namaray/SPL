#include <stdio.h>

void printArray(int a[], int i, int n) {
    if (i == n) return;        // stop at the end
    printf("%d ", a[i]);
    printArray(a, i + 1, n);
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printArray(a, 0, n);
    printf("\n");
    return 0;
}
