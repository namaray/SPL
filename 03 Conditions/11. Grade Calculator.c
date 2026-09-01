//011222131
#include <stdio.h>

int main() {
    float m;
    scanf("%f", &m);

    printf("Grade: ");
    if (m >= 90)      printf("A\n");
    else if (m >= 86) printf("A-\n");
    else if (m >= 82) printf("B+\n");
    else if (m >= 78) printf("B\n");
    else if (m >= 74) printf("B-\n");
    else if (m >= 70) printf("C+\n");
    else if (m >= 66) printf("C\n");
    else if (m >= 62) printf("C-\n");
    else if (m >= 58) printf("D+\n");
    else if (m >= 55) printf("D\n");
    else              printf("F\n");
    return 0;
}
