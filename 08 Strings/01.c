//011222131
#include <stdio.h>

int main()
{
    char s[200];
    fgets(s, 200, stdin);   // read the whole line

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') // \0 is the null character and \n is an extra space that exists at the end
    {
        len++;
    }

    printf("%d\n", len);
    return 0;
}
