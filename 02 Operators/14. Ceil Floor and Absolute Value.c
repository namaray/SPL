// 011222131
#include <stdio.h>
#include <math.h>

int main() {
    float x;
    scanf("%f", &x);

    printf("A = %.0f, B = %.0f, C = %g\n", ceil(fabs(x)), floor(fabs(x)), fabs(x));
    return 0;
}
