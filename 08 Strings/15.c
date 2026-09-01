#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    // walk from the end; print each word when we find its start
    int i = len - 1, end = len - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            int k;
            for (k = i + 1; k <= end; k++) printf("%c", s[k]);
            printf(" ");
            end = i - 1;
        }
        i--;
    }
    // print the first word (from start to end)
    int k;
    for (k = 0; k <= end; k++) printf("%c", s[k]);
    printf("\n");
    return 0;
}
