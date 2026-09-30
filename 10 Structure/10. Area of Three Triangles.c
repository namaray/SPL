#include <stdio.h>

struct triangle {
    int triangle_id;
    float base;
    float height;
};

int main() {
    struct triangle t[3];
    int i;
    for (i = 0; i < 3; i++)
        scanf("%d %f %f", &t[i].triangle_id, &t[i].base, &t[i].height);

    for (i = 0; i < 3; i++)
        printf("Area of %d = %g\n", t[i].triangle_id, (t[i].base * t[i].height) / 2);
    return 0;
}
