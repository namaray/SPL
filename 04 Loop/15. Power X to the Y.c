//011222131
#include <stdio.h>

int main() {
    int x, y, i;
    long p = 1;
    scanf("%d %d", &x, &y);

    for (i = 1; i <= y; i++)
        p *= x;

    printf("%ld\n", p);
    return 0;
}
