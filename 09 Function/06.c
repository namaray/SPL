#include <stdio.h>

int sum(int n) {
    int i, x, s = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        s += x;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    int result = sum(n);
    printf("Sum In Function: %d\n", result);
    printf("Sum In Main: %d\n", result);
    return 0;
}
