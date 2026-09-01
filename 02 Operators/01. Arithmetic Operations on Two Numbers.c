// 011222131
#include <stdio.h>

int main() {
    float x, y;
    scanf("%f %f", &x, &y);

    printf("Addition: %g\n", x + y);
    printf("Subtraction: %g\n", x - y);
    printf("Multiplication: %g\n", x * y);
    printf("Quotient : %d\n", (int)x / (int)y);
    printf("Reminder: %d\n", (int)x % (int)y);
    return 0;
}
