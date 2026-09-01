#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int i = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        char c = s[i];
        if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';   // lower -> upper
        printf("%c", c);
        i++;
    }
    printf("\n");
    return 0;
}
