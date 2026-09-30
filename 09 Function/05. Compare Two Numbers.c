#include <stdio.h>

void compare(int a, int b) {
    if (a > b)      printf("%d is greater than %d\n", a, b);
    else if (a < b) printf("%d is less than %d\n", a, b);
    else            printf("%d is equal to %d\n", a, b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    compare(a, b);
    return 0;
}
