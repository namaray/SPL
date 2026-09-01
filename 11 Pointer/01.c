#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int *pa = &a, *pb = &b;
    printf("%d\n", *pa + *pb);
    return 0;
}
