//011222131
#include <stdio.h>

int main()
{
    char s[200];
    fgets(s, 200, stdin);           // reads the whole line, spaces included

    char *p = s;
    int len = 0;
    while (*p != '\0' && *p != '\n')   // fgets keeps the Enter key, stop there
    {
        len++;
        p++;
    }
    printf("%d\n", len);
    return 0;
}
