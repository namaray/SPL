// Exam Prep Q2 - Operators, Type Casting & math.h
// compile with: gcc "02. Operators and Math Functions.c" -o 02 -lm
#include <stdio.h>
#include <math.h>

int main() {
    float a, b;
    scanf("%f %f", &a, &b);

    printf("Sum: %g\n", a + b);
    printf("Difference: %g\n", a - b);
    printf("Product: %g\n", a * b);

    if (b != 0)
        printf("Quotient: %d, Remainder: %d\n", (int)a / (int)b, (int)a % (int)b);
    else
        printf("Error: division by zero\n");

    printf("Max: %g\n", (a > b) ? a : b);

    double p = (2.5 * pow(a, 2) + sqrt(fabs(b))) / (1 + sin(a));
    printf("P = %.4f\n", p);

    if (b != 0)
        printf("Ceil: %g, Floor: %g, Abs Diff: %g\n",
               ceil(a / b), floor(a / b), fabs(a - b));

    return 0;
}
