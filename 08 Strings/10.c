#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;

    int i = 0, j = len - 1, palindrome = 1;
    while (i < j) {
        if (s[i] != s[j]) palindrome = 0;
        i++;
        j--;
    }
    if (palindrome) printf("yes\n");
    else            printf("no\n");
    return 0;
}
