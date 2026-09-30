//011222131
#include <stdio.h>

int main() {
    int n, i, a[100], b[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        b[i] = a[n - 1 - i];   // copy in reverse order

    printf("Array A : ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("Array B : ");
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}
