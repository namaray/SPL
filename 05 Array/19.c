//011222131
#include <stdio.h>

int main() {
    int n, m, i, j, a[100], b[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    int count = 0;
    for (i = 0; i < n; i++) {
        int inB = 0;
        for (j = 0; j < m; j++)
            if (a[i] == b[j]) inB = 1;
        if (inB) { printf("%d ", a[i]); count++; }
    }
    if (count == 0) printf("Empty set");
    printf("\n");
    return 0;
}
