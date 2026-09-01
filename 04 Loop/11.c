//011222131
#include <stdio.h>

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);

    // term i = i*i*(i+1)
    for (i = 1; i <= n; i++)
        sum += i * i * (i + 1);

    printf("Result: %d\n", sum);
    return 0;
}
