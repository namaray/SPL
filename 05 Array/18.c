//011222131
#include <stdio.h>

int main() {
    int n, i, j, a[100], b[100], bn = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        int dup = 0;
        for (j = 0; j < bn; j++)
            if (b[j] == a[i]) dup = 1;
        if (!dup) b[bn++] = a[i];
    }

    for (i = 0; i < bn; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}
