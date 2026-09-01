#include <stdio.h>

int gcd(int a, int b) {
    int i, g = 1;
    for (i = 1; i <= a && i <= b; i++)
        if (a % i == 0 && b % i == 0) g = i;
    return g;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int a, b;
    // infinite loop keeps processing inputs
    while (scanf("%d %d", &a, &b) == 2) {
        printf("GCD: %d\n", gcd(a, b));
        printf("LCM: %d\n", lcm(a, b));
    }
    return 0;
}
