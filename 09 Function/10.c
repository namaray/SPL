#include <stdio.h>

long power(int x, int y) {
    long p = 1;
    int i;
    for (i = 1; i <= y; i++) p *= x;
    return p;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d to the power %d is %ld\n", x, y, power(x, y));
    return 0;
}
