#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int *px = &x, *py = &y;
    int t = *px;
    *px = *py;
    *py = t;

    printf("X = %d y = %d\n", x, y);
    return 0;
}
