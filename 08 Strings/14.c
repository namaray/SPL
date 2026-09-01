#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    int i, j, best = 0, bestCount = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') continue;
        char ci = s[i];
        if (ci >= 'A' && ci <= 'Z') ci = ci - 'A' + 'a';   // ignore case

        int count = 0;
        for (j = 0; j < len; j++) {
            char cj = s[j];
            if (cj >= 'A' && cj <= 'Z') cj = cj - 'A' + 'a';
            if (cj == ci) count++;
        }
        if (count > bestCount) { bestCount = count; best = ci; }
    }
    // print in uppercase like the samples (E, D ...)
    if (best >= 'a' && best <= 'z') best = best - 'a' + 'A';
    printf("%c\n", best);
    return 0;
}
