//011222131
#include <stdio.h>


int main() {
    int x, g, flag = 0;
    scanf("%d", &x);

    scanf("%d", &g);
    if (g == x) {
    printf("Right, Player-2 wins!\n"); flag = 1;
    }
    else{
    printf("Wrong, 2 Chance(s) Left!\n");
    }


    if (flag == 0) {
        scanf("%d", &g);
        if (g == x) {
        printf("Right, Player-2 wins!\n"); flag = 1;
        }
        else {
        printf("Wrong, 1 Chance(s) Left!\n");
        }
    }
    if (flag == 0) {
        scanf("%d", &g);
        if (g == x) {
        printf("Right, Player-2 wins!\n"); flag = 1;
        }
        else {
        printf("Wrong, 0 Chance(s) Left!\n");
        }
    }
    if (flag == 0){
        printf("Player-1 wins!\n");
        }
    return 0;
}
