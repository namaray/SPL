// 011222131
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    float d = b * b - 4 * a * c;
    if (d < 0) {
        printf("Imaginary\n");
    } else {
        float r1 = (-b + sqrt(d)) / (2 * a);
        float r2 = (-b - sqrt(d)) / (2 * a);
        printf("%.2f    %.2f\n", r1, r2);
    }
    return 0;
}
