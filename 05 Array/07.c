//011222131
#include <stdio.h>

int main() {
    int n, i, a[100], temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    // reverse inside the same array by swapping ends
    for (i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
