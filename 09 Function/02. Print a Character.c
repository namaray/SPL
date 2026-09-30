#include <stdio.h>

void printValue(char c) {
    printf("Value received from main:   %c\n", c);
}

int main() {
    char c;
    scanf("%c", &c);
    printValue(c);
    return 0;
}
