#include <stdio.h>

int main() {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int *p = a;                 // pointer to the first element
    for (i = 0; i < n; i++)
        printf("%d ", *(p + i)); // access without using a[i]
    printf("\n");
    return 0;
}
