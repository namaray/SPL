//011222131
#include <stdio.h>

int main() {
    int x, n, i, g, won = 0;
    scanf("%d %d", &x, &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &g);
        if (g == x) {
            printf("Right, Player-2 wins!\n");
            won = 1;
            break;
        }
        printf("Wrong, %d Choice(s) Left!\n", n - i - 1);
    }
    if (!won)
        printf("Player-1 wins!\n");
    return 0;
}
