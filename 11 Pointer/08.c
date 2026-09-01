#include <stdio.h>

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int *p = a;
    for (i = n - 1; i >= 0; i--)
        printf("%d ", *(p + i));
    printf("\n");
    return 0;
}
