//011222131
#include <stdio.h>

int main() {
    int n, m, i, a[100], b[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    // after swapping, A holds B's values and B holds A's values
    printf("Array A : ");
    for (i = 0; i < m; i++) printf("%d ", b[i]);
    printf("\n");
    printf("Array B : ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
