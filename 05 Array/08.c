//011222131
#include <stdio.h>

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int max = a[0], min = a[0], maxi = 0, mini = 0;
    for (i = 1; i < n; i++) {
        if (a[i] > max) { max = a[i]; maxi = i; }
        if (a[i] < min) { min = a[i]; mini = i; }
    }
    printf("Max: %d, Index: %d\n", max, maxi);
    printf("Min: %d, Index: %d\n", min, mini);
    return 0;
}
