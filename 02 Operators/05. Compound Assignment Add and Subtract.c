// 011222131
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int inc = x, dec = x;
    inc += y;
    dec -= y;
    printf("Incremented Value:    %d\n", inc);
    printf("Decremented Value:   %d\n", dec);
    return 0;
}
