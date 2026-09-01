// 011222131
#include <stdio.h>

int main() {
    float x;
    scanf("%f", &x);

    printf("(a) Val:%20f\n", x);
    printf("(b) Val:%2f\n", x);
    printf("(c) Val:%.2f\n", x);
    printf("(d) Val:%.0f\n", x);
    printf("(e) Val: %e\n", x);
    return 0;
}
