#include <stdio.h>

struct triangle {
    int triangle_id;
    float base;
    float height;
};

float area(struct triangle t) {
    return (t.base * t.height) / 2;
}

int main() {
    struct triangle t[3];
    int i;
    for (i = 0; i < 3; i++)
        scanf("%d %f %f", &t[i].triangle_id, &t[i].base, &t[i].height);

    int maxi = 0;
    for (i = 1; i < 3; i++)
        if (area(t[i]) > area(t[maxi])) maxi = i;

    printf("Area of %d = %g\n", t[maxi].triangle_id, area(t[maxi]));
    return 0;
}
