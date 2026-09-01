//011222131
#include <stdio.h>

int main() {
    float a, b;
    int choice;
    scanf("%f %f", &a, &b);
    scanf("%d", &choice);

    if (choice == 1)
        printf("Addition: %g\n", a + b);
    else if (choice == 2)
        printf("Subtraction: %g\n", a - b);
    else if (choice == 3)
        printf("Multiplication: %g\n", a * b);
    else if (choice == 4) {
        if ((int)b != 0)
            printf("Quotient: %d\n", (int)a / (int)b);
        else
            printf("Error: Divisor is zero\n");
    }
    return 0;
}
