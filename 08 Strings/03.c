#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int i = 0, count = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
