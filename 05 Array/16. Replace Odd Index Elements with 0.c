//011222131
#include <stdio.h>

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 1; i < n; i += 2)   // odd indexes: 1, 3, 5 ...
        a[i] = 0;

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
