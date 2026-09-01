//011222131
#include <stdio.h>

int main() {
    int n, m, i, j, a[100], b[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    // print all of A first
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    // then B elements that are not already in A
    for (i = 0; i < m; i++) {
        int inA = 0;
        for (j = 0; j < n; j++)
            if (b[i] == a[j]) inA = 1;
        if (!inA) printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}
