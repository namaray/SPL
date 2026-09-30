//011222131
#include <stdio.h>

int main() {
    int n, i;
    float x, sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%f", &x);
        sum += x;
    }
    printf("Average of %d inputs:  %f\n", n, sum / n);

}
