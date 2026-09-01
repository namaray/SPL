// 011222131
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    int stmt1 = ((a + b) <= 80 && b >= 0);
    int stmt2 = ((a + b) == 0 || c != 0);
    int stmt3 = (a != b || (b < a && c > 0));

    printf("1) %d\n", stmt1);
    printf("2) %d\n", stmt2);
    printf("3) %d\n", stmt3);

    return 0;
}
