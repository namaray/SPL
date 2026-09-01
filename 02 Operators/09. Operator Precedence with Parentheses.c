// 011222131
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("X = %d\n", a - b / 3 + c * 2 - 1);
    printf("Y = %d\n", a - (b / (3 + c) * 2) - 1);
    printf("Z = %d\n", a - ((b / 3) + c * 2) - 1);
    return 0;
}
