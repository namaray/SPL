//011222131
#include <stdio.h>

int main() {
    float a, b;
    char op;
    scanf("%f %c %f", &a, &op, &b);

    if (op == '+')
        printf("Addition:  %g\n", a + b);
    else if (op == '-')
        printf("Subtraction:  %g\n", a - b);
    else if (op == '*')
        printf("Multiplication:  %g\n", a * b);
    else if (op == '/') {
        if (b != 0)
            printf("Division:   %f\n", a / b);
        else
            printf("Division:    Zero as divisor is not valid!\n");
    }
    return 0;
}
