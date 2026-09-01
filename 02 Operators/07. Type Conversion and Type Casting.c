// 011222131
#include <stdio.h>

int main() {
    int i;
    float f;
    scanf("%d %f", &i, &f);

    int fromFloat = f;
    float fromInt = i;

    printf("Assignment: %f assigned to an int produces %d\n", f, fromFloat);
    printf("Assignment: %d assigned to a float produces %f\n", i, fromInt);
    printf("Type Casting: (float) %d produces %f\n", i, (float)i);
    printf("Type Casting: (int) %g produces %d\n", f, (int)f);
    return 0;
}
