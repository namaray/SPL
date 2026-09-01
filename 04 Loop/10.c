//011222131
#include <stdio.h>

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
        sum += i;
        }           // odd position -> +
        else {
        sum -= i;   // even position -> -
        }
    }
    printf("Result: %d\n", sum);
    return 0;
}
