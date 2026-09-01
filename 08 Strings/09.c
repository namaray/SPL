#include <stdio.h>

int main() {
    char s[200], ch;
    fgets(s, 200, stdin);
    scanf(" %c", &ch);

    // make the searched character lowercase for a case-insensitive compare
    if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';

    int i = 0, count = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c == ch) count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
