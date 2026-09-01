#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int i = 0, count = 0, inWord = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        if (s[i] != ' ') {
            if (inWord == 0) { count++; inWord = 1; }
        } else {
            inWord = 0;
        }
        i++;
    }
    printf("%d\n", count);
    return 0;
}
