#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    // bubble sort the characters
    int i, j;
    char t;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (s[j] > s[j + 1]) { t = s[j]; s[j] = s[j + 1]; s[j + 1] = t; }

    for (i = 0; i < len; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
}
