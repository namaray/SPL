#include <stdio.h>

struct player {
    char name[50];
    char country[50];
    int runs[3];
    int wickets[3];
    int points[3];
};

int calcPoints(int runs, int wickets) {
    int p = wickets * 12;
    if (runs <= 25)      p += 5;
    else if (runs <= 50) p += 10;
    else if (runs <= 75) p += 15;
    else                 p += 20;
    return p;
}

int main() {
    struct player p[2];
    int i, m;
    for (i = 0; i < 2; i++) {
        scanf(" %[^\n]", p[i].name);
        scanf(" %[^\n]", p[i].country);
        for (m = 0; m < 3; m++) scanf("%d", &p[i].runs[m]);
        for (m = 0; m < 3; m++) scanf("%d", &p[i].wickets[m]);
        for (m = 0; m < 3; m++) p[i].points[m] = calcPoints(p[i].runs[m], p[i].wickets[m]);
    }

    for (m = 0; m < 3; m++) {
        printf("Match %d:\n", m + 1);
        printf("%s points: %d\n", p[0].name, p[0].points[m]);
        printf("%s points: %d\n", p[1].name, p[1].points[m]);
        printf("\n");
    }
    return 0;
}
