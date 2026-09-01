// 011222131
#include <stdio.h>
#include <math.h>

int main() {
    int x;
    scanf("%d", &x);

    double rad = x * 3.1416 / 180.0;
    double result = 2 * pow(cos(rad), 2) - sqrt(3) * sin(rad) + sin(rad / 2);

    printf("%.10g\n", result);

    return 0;
}
