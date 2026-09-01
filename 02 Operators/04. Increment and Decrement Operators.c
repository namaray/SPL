// 011222131
#include <stdio.h>

int main() {
    int X, x;
    scanf("%d", &X);

    x = X; printf("X++: %d\n", x++);
    x = X; printf("++X: %d\n", ++x);
    x = X; printf("X--: %d\n", x--);
    x = X; printf("--X: %d\n", --x);
    return 0;
}
