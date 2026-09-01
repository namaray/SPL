//011222131
#include <stdio.h>

int main() {
    int n, i;
    float a, hw, ct, mt, tf, total;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%f %f %f %f %f", &a, &hw, &ct, &mt, &tf);
        // convert every mark to its weight, then add up (out of 100)
        total = a / 5 * 5 + hw / 10 * 10 + ct / 15 * 15 + mt / 50 * 30 + tf / 100 * 40;

        printf("Student %d : ", i);
        if (total >= 90)      printf("A\n");
        else if (total >= 86) printf("A-\n");
        else if (total >= 82) printf("B+\n");
        else if (total >= 78) printf("B\n");
        else if (total >= 74) printf("B-\n");
        else if (total >= 70) printf("C+\n");
        else if (total >= 66) printf("C\n");
        else if (total >= 62) printf("C-\n");
        else if (total >= 58) printf("D+\n");
        else if (total >= 55) printf("D\n");
        else                  printf("F\n");
    }
    return 0;
}
