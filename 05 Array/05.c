//011222131
#include <stdio.h>

int main() {
    int n, i, a[100], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i += 2)   // even indexes: 0, 2, 4 ...
        sum += a[i];
    printf("%d\n", sum);
    return 0;
}
