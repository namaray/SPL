#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    int i, j;
    for (i = 0; i < len; i++) {
        // check if s[i] already appeared earlier
        int seen = 0;
        for (j = 0; j < i; j++)
            if (s[j] == s[i]) seen = 1;
        if (!seen) printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
