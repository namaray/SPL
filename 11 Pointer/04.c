#include <stdio.h>

int main() {
    char s[200];
    scanf("%s", s);

    char *p = s;
    int len = 0;
    while (*p != '\0') { len++; p++; }
    printf("%d\n", len);
    return 0;
}
