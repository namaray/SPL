//011222131
#include <stdio.h>

int main() {
    char c;
    int i = 1;

    while (1) {
        scanf(" %c", &c);
        if (c == 'A') {
        break;
        }
        printf("Input %d: %c\n", i, c);
        i++;
    }
    return 0;
}
