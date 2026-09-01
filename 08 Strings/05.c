#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    int i;
    for (i = len - 1; i >= 0; i--)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}
