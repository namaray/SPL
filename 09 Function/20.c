#include <stdio.h>

int IsPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int GenNthPrime(int n) {
    int count = 0, num = 1;
    while (count < n) {
        num++;
        if (IsPrime(num)) count++;
    }
    return num;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%dth Prime:  %d\n", n, GenNthPrime(n));
    return 0;
}
