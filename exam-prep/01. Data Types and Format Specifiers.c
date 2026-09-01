// Exam Prep Q1 - Data Types, Input & Format Specifiers
#include <stdio.h>
#define VAT 0.15

int main() {
    const float DISCOUNT = 0.05;

    int code;
    float price;
    char category;

    // the 2nd value (stock count) is read and discarded with %*d
    scanf("%d %*d %f %c", &code, &price, &category);

    double total = price + price * VAT - price * DISCOUNT;

    printf("Item Code: %d\n", code);
    printf("Category: %c\n", category);
    printf("Total: %.2f\n", total);
    printf("Total: %e\n", total);
    printf("Total: %15.2f\n", total);
    printf("Size of int = %d, float = %d, char = %d\n",
           (int)sizeof(int), (int)sizeof(float), (int)sizeof(char));

    return 0;
}
