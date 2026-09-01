// 011222131
#include <stdio.h>

int main() {
    float x, y;
    scanf("%f %f", &x, &y);

    printf("Max: %g\n", (x > y) ? x : y);
    return 0;
}
