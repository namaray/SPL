//011222131
#include <stdio.h>

/* Calculates sin(x) using its Taylor series:
   sin(x) = x - x^3/3! + x^5/5! - ...  (x is in radians) */
int main() {
    double x, term, sum;
    int i;
    scanf("%lf", &x);

    term = x;
    sum = x;
    for (i = 1; i < 10; i++) {
        term = term * (-1) * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    printf("%.3f\n", sum);
    return 0;
}
