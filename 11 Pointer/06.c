#include <stdio.h>

int main() {
    char s[200];
    scanf("%s", s);

    char *p = s;
    int vowel = 0, cons = 0;
    while (*p != '\0') {
        char c = *p;
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowel++;
            else
                cons++;
        }
        p++;
    }
    printf("vowel: %d, Consonant: %d\n", vowel, cons);
    return 0;
}
