//011222131
#include <stdio.h>

int main()
{
    char s[200];
    fgets(s, 200, stdin);           // reads the whole line, spaces included

    char *p = s;
    int vowel = 0, cons = 0;
    while (*p != '\0' && *p != '\n')   // fgets keeps the Enter key, stop there
    {
        char c = *p;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - 'A' + 'a';
        }
        if (c >= 'a' && c <= 'z')
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vowel++;
            }
            else
            {
                cons++;
            }
        }
        p++;
    }
    printf("vowel: %d, Consonant: %d\n", vowel, cons);
    return 0;
}
