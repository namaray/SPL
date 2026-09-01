#include <stdio.h>

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int *p = a, sum = 0;
    for (i = 0; i < n; i++)
        sum += *(p + i);
    printf("%d\n", sum);
    return 0;
}
