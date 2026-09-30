#include <stdio.h>

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n') i++;
    return i;
}

int main() {
    char s[200];
    fgets(s, 200, stdin);
    printf("%d\n", length(s));
    return 0;
}
