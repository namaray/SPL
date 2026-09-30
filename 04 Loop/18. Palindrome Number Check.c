//011222131
#include <stdio.h>

int main() {
    int n, t, rev = 0;
    scanf("%d", &n);
    t = n;

    while (t != 0) {
        rev = rev * 10 + t % 10;
        t = t / 10;
    }

    if (rev == n) printf("Yes\n");
    else          printf("No\n");
    return 0;
}
