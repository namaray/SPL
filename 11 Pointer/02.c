#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int *pm = &m, *pn = &n;
    if (*pm > *pn) printf("%d\n", *pm);
    else           printf("%d\n", *pn);
    return 0;
}
