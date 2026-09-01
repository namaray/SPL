#include <stdio.h>

int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) printf("1\n");          // 0 itself has 1 digit
    else        printf("%d\n", countDigits(n));
    return 0;
}
