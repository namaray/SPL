// 011222131
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // a) (a+b) <= 80
    int resultA = (a + b <= 80) ? 1 : 0;

    // b) !(a+c)
    int resultB = !(a + c);

    // c) a != 0
    int resultC = (a != 0) ? 1 : 0;

    printf("a) %d\n", resultA);
    printf("b) %d\n", resultB);
    printf("c) %d\n", resultC);

    return 0;
}
