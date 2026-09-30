#include <stdio.h>

int findMin(int a[], int n) {
    int i, min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Minimum Value:  %d\n", findMin(a, n));
    return 0;
}
