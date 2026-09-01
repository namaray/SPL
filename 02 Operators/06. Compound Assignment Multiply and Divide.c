#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int mul = x, div = x;
    mul *= y;
    div /= y;
    printf("Multiplication:    %d\n", mul);
    printf("Division:   %d\n", div);
    return 0;
}
