//011222131
#include <stdio.h>

int main() {
    int n, i, j, a[100], temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    // bubble sort (ascending)
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
